import rclpy
from rclpy.node import Node
import math
from dynamixel_sdk import * # Uses Dynamixel SDK library 

from geometry_msgs.msg import PolygonStamped, Point32
from custom_interfaces.msg import ActuatorState, ActuatorCommand, Actuator
from rclpy.qos import QoSProfile
from rclpy.duration import Duration
from rclpy.qos import QoSDurabilityPolicy
from rclpy.qos import QoSLivelinessPolicy
from rclpy.qos import QoSReliabilityPolicy

class ServoNode(Node):
    def __init__(self, nodeName, qos_profile_pub, qos_profile_sub) -> None:
        super().__init__(node_name=nodeName)
        self.__addr_torque_enable = 64
        self.__addr_goal_position = 116
        self.__addr_present_position = 132
        self.__protocol_version = 2.0
        self.__torque_enable = 1
        self.__torque_disable = 0
        self.__len_present_position = 4
        self.__len_goal_position = 4
        self.__left_ID = 1
        self.__left_min_position = self.declare_parameter("left_min_position",0).value
        self.__left_mid_position = self.declare_parameter("left_mid_position",2047).value
        self.__left_max_position = self.declare_parameter("left_max_position",4095).value
        self.__right_ID = 2
        self.__right_min_position = self.declare_parameter("right_min_position",0).value
        self.__right_mid_position = self.declare_parameter("right_mid_position",2047).value
        self.__right_max_position = self.declare_parameter("right_max_position",4095).value
        self.__baud_rate = self.declare_parameter("baud_rate", 1000000).value
        self.__device_name = self.declare_parameter("device_name",'/dev/servo').value
        self.servo_cmd = [self.__left_mid_position, self.__right_mid_position]

        # Init handle , open port, set baudrate
        self.dxl_communication_init()
        # Enable Left servo Torque
        self.dxl_enable_torque(self.__left_ID)
        # Enable Right servo Torque
        self.dxl_enable_torque(self.__right_ID)
        # Add parameter storage for Left servo present position
        self.dxl_read_add_param_pos(self.__left_ID)
        # Add parameter storage for Right servo present position
        self.dxl_read_add_param_pos(self.__right_ID)
        # Add parameter storage for Left servo target position
        self.dxl_write_set_param_pos(self.__left_ID, self.__left_mid_position)
        # Add parameter storage for Right servo target position
        self.dxl_write_set_param_pos(self.__right_ID, self.__right_mid_position)

        self.publisher_ = self.create_publisher(ActuatorState, 'servo_state', qos_profile_pub)
        self.publisher_
        self.subscriber_ = self.create_subscription(ActuatorCommand, 'servo_cmd', self.cmd_callback, qos_profile_sub)
        self.subscriber_
        self.pubTimer_ = self.create_timer(0.01, self.control_loop_timer)

    def dxl_communication_init(self):
        self.portHandler = PortHandler(self.__device_name)
        self.packetHandler = PacketHandler(self.__protocol_version)
        self.groupBulkWrite = GroupBulkWrite(self.portHandler, self.packetHandler)
        self.groupBulkRead = GroupBulkRead(self.portHandler, self.packetHandler)
        # Open port
        self.dxl_open_port()
        # Set port baudrate
        self.dxl_set_baudrate(self.__baud_rate)

    def cmd_callback(self, msg):
        self.servo_cmd[0] = self.cal_goal_pos(self.__left_min_position,self.__left_mid_position,self.__left_max_position, msg.actuator_command[0].position)
        self.servo_cmd[1] = self.cal_goal_pos(self.__right_min_position,self.__right_mid_position,self.__right_max_position, -msg.actuator_command[1].position)

    def control_loop_timer(self):
        self.dxl_write_change_param_pos(self.__left_ID,self.servo_cmd[0])
        self.dxl_write_change_param_pos(self.__right_ID,self.servo_cmd[1])
        self.dxl_write_txPacket()

        servo_state_pub = ActuatorState()
        servo_left = Actuator()
        servo_right = Actuator()
        self.dxl_read_rxPacket()
        servo_left.name = 'Front Left'
        servo_right.name = 'Front Right'
        servo_left.position = float(self.dxl_get_data(self.__left_ID))
        servo_right.position = float(self.dxl_get_data(self.__right_ID))
        servo_state_pub.actuator_state.append(servo_left)
        servo_state_pub.actuator_state.append(servo_right)
        self.publisher_.publish(servo_state_pub)
        
    def cal_goal_pos(self, min_pos, mid_pos, max_pos, goal):
        angle = int(goal/(2*math.pi)*4096)
        goal_pos = mid_pos + angle
        goal_pos = min(max(goal_pos, min_pos), max_pos)
        return int(goal_pos)
    
    def dxl_open_port(self):
        if self.portHandler.openPort():
            self.get_logger().info("Succeeded to open the port")
        else:
            self.get_logger().info("Failed to open the port")
            quit()

    def dxl_set_baudrate(self, baudrate):
        if self.portHandler.setBaudRate(baudrate):
            self.get_logger().info("Succeeded to change the baudrate")
        else:
            self.get_logger().info("Failed to change the baudrate")

    def dxl_enable_torque(self, ID):
        dxl_comm_result, dxl_error = self.packetHandler.write1ByteTxRx(self.portHandler, 
                                                                       ID, 
                                                                       self.__addr_torque_enable, 
                                                                       self.__torque_enable)
        if dxl_comm_result != COMM_SUCCESS:
            self.get_logger().info("%s" % self.packetHandler.getTxRxResult(dxl_comm_result))
        elif dxl_error != 0:
            self.get_logger().info("%s" % self.packetHandler.getRxPacketError(dxl_error))
        else:
            self.get_logger().info("Dynamixel#%d has been successfully connected" % ID)

    def dxl_disable_torque(self, ID):
        dxl_comm_result, dxl_error = self.packetHandler.write1ByteTxRx(self.portHandler, 
                                                                       ID, 
                                                                       self.__addr_torque_enable, 
                                                                       self.__torque_disable)
        if dxl_comm_result != COMM_SUCCESS:
            self.get_logger().info("%s" % self.packetHandler.getTxRxResult(dxl_comm_result))
        elif dxl_error != 0:
            self.get_logger().info("%s" % self.packetHandler.getRxPacketError(dxl_error))
        else:
            self.get_logger().info("Dynamixel#%d has been successfully closed" % ID)

    def dxl_read_add_param_pos(self, ID):
        dxl_addparam_result = self.groupBulkRead.addParam(ID, 
                                                          self.__addr_present_position, 
                                                          self.__len_present_position)
        if dxl_addparam_result != True:
            self.get_logger().info("[ID:%03d] groupBulkRead addparam failed" % ID)

    def dxl_write_set_param_pos(self, ID, pos):
        pos = int(pos)
        goal_pos = [DXL_LOBYTE(DXL_LOWORD(pos)), DXL_HIBYTE(DXL_LOWORD(pos)), DXL_LOBYTE(DXL_HIWORD(pos)), DXL_HIBYTE(DXL_HIWORD(pos))]
        dxl_addparam_result = self.groupBulkWrite.addParam(ID, self.__addr_goal_position, self.__len_goal_position, goal_pos)
        if dxl_addparam_result != True:
            print("[ID:%03d] groupBulkRead addparam failed" % ID)
            quit()

    def dxl_write_change_param_pos(self, ID, pos):
        pos = int(pos)
        goal_pos = [DXL_LOBYTE(DXL_LOWORD(pos)), DXL_HIBYTE(DXL_LOWORD(pos)), DXL_LOBYTE(DXL_HIWORD(pos)), DXL_HIBYTE(DXL_HIWORD(pos))]
        dxl_addparam_result = self.groupBulkWrite.changeParam(ID, self.__addr_goal_position, self.__len_goal_position, goal_pos)
        if dxl_addparam_result != True:
            print("[ID:%03d] groupBulkRead addparam failed" % ID)
            quit()

    def dxl_write_txPacket(self):
        dxl_comm_result = self.groupBulkWrite.txPacket()
        if dxl_comm_result != COMM_SUCCESS:
            print("%s" % self.packetHandler.getTxRxResult(dxl_comm_result))

    def dxl_read_rxPacket(self):
        dxl_comm_result = self.groupBulkRead.txRxPacket()
        if dxl_comm_result != COMM_SUCCESS:
            print("%s" % self.packetHandler.getTxRxResult(dxl_comm_result))

    def dxl_get_data(self, ID):
        dxl_getdata_result = self.groupBulkRead.isAvailable(ID, self.__addr_present_position, self.__len_present_position)
        if dxl_getdata_result != True:
            print("[ID:%03d] groupBulkRead getdata failed" % ID)
            quit()
        return self.groupBulkRead.getData(ID, self.__addr_present_position, self.__len_present_position)



def main(args=None):
    rclpy.init(args=args) # 初始化rclpy

    qos_profile_publisher = QoSProfile(depth=10)
    qos_profile_publisher.reliability = QoSReliabilityPolicy.RELIABLE
    # # Options  QoSDurabilityPolicy.VOLATILE, QoSDurabilityPolicy.TRANSIENT_LOCAL,
    # qos_profile_publisher.durability = QoSDurabilityPolicy.VOLATILE
    qos_profile_publisher.deadline = Duration(seconds=1)
    # Options QoSLivelinessPolicy.MANUAL_BY_TOPIC, QoSLivelinessPolicy.AUTOMATIC
    qos_profile_publisher.liveliness = QoSLivelinessPolicy.AUTOMATIC

    qos_profile_subscriber = QoSProfile(depth=10)
    # qos_profile_subscriber.reliability = QoSReliabilityPolicy.BEST_EFFORT
    qos_profile_subscriber.durability = QoSDurabilityPolicy.VOLATILE

    ServoSubPubNode = ServoNode("servo_rs485_node", qos_profile_publisher, qos_profile_subscriber)  # 新建一个节点

    rclpy.spin(ServoSubPubNode) # 保持节点运行，检测是否收到退出指令（Ctrl+C）
    ServoSubPubNode.destroy_node()
    rclpy.shutdown() # 关闭rclpy

if __name__ == '__main__':
    main()
