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
import threading

class ServoNode(Node):
    def __init__(self, nodeName, qos_profile_pub, qos_profile_sub) -> None:
        super().__init__(node_name=nodeName)
        self.__addr_torque_enable = 64
        self.__addr_goal_position = 116
        self.__addr_present_current = 126
        self.__addr_present_position = 132
        self.__protocol_version = 2.0
        self.__torque_enable = 1
        self.__torque_disable = 0
        self.__len_present_current = 2
        self.__len_present_position = 4
        self.__len_goal_position = 4

        self.__forward_left_ID = 1
        self.__forward_left_min_position = self.declare_parameter("left_min_position_f",0).value
        self.__forward_left_mid_position = self.declare_parameter("left_mid_position_f",2047).value
        self.__forward_left_max_position = self.declare_parameter("left_max_position_f",4095).value

        self.__forward_right_ID = 2
        self.__forward_right_min_position = self.declare_parameter("right_min_position_f",0).value
        self.__forward_right_mid_position = self.declare_parameter("right_mid_position_f",2047).value
        self.__forward_right_max_position = self.declare_parameter("right_max_position_f",4095).value

        self.__backward_right_ID = 3
        self.__backward_right_min_position = self.declare_parameter("right_min_position_r",0).value
        self.__backward_right_mid_position = self.declare_parameter("right_mid_position_r",2047).value
        self.__backward_right_max_position = self.declare_parameter("right_max_position_r",4095).value

        self.__backward_left_ID = 4
        self.__backward_left_min_position = self.declare_parameter("left_min_position_r",0).value
        self.__backward_left_mid_position = self.declare_parameter("left_mid_position_r",2047).value
        self.__backward_left_max_position = self.declare_parameter("left_max_position_r",4095).value

        self.__baud_rate = self.declare_parameter("baud_rate", 1000000).value
        self.__device_name = self.declare_parameter("device_name",'/dev/servo').value
        self.servo_cmd = [self.__forward_left_mid_position, self.__forward_right_mid_position, self.__backward_left_mid_position, self.__backward_right_mid_position]

        # Init handle , open port, set baudrate
        self.dxl_communication_init()
        # Enable Forward Left servo Torque
        self.dxl_enable_torque(self.__forward_left_ID)
        # Enable Forward Right servo Torque
        self.dxl_enable_torque(self.__forward_right_ID)
        # Enable Backward Left servo Torque
        self.dxl_enable_torque(self.__backward_left_ID)
        # Enable Backward Right servo Torque
        self.dxl_enable_torque(self.__backward_right_ID)
        # Add parameter storage for Forward Left servo target position
        self.dxl_write_set_param_pos(self.__forward_left_ID, self.__forward_left_mid_position)
        # Add parameter storage for Forward Right servo target position
        self.dxl_write_set_param_pos(self.__forward_right_ID, self.__forward_right_mid_position)
        # Add parameter storage for Backward Left servo target position
        self.dxl_write_set_param_pos(self.__backward_left_ID, self.__backward_left_mid_position)
        # Add parameter storage for Backward Right servo target position
        self.dxl_write_set_param_pos(self.__backward_right_ID, self.__backward_right_mid_position)

        self.publisher_ = self.create_publisher(ActuatorState, 'servo_state', qos_profile_pub)
        self.publisher_
        self.subscriber_ = self.create_subscription(ActuatorCommand, 'servo_cmd', self.cmd_callback, qos_profile_sub)
        self.subscriber_
        self.pubTimer_ = self.create_timer(0.01, self.control_loop_timer)

    def dxl_communication_init(self):
        self.portHandler = PortHandler(self.__device_name)
        self.packetHandler = PacketHandler(self.__protocol_version)
        self.groupBulkWrite = GroupBulkWrite(self.portHandler, self.packetHandler)

        # Open port
        self.dxl_open_port()
        # Set port baudrate
        self.dxl_set_baudrate(self.__baud_rate)

    def cmd_callback(self, msg):
        self.servo_cmd[0] = self.cal_goal_pos(self.__forward_left_min_position,self.__forward_left_mid_position,self.__forward_left_max_position, msg.actuator_command[0].position)
        self.servo_cmd[1] = self.cal_goal_pos(self.__forward_right_min_position,self.__forward_right_mid_position,self.__forward_right_max_position, -msg.actuator_command[1].position)
        self.servo_cmd[2] = self.cal_goal_pos(self.__backward_right_min_position,self.__backward_right_mid_position,self.__backward_right_max_position, msg.actuator_command[2].position)
        self.servo_cmd[3] = self.cal_goal_pos(self.__backward_left_min_position,self.__backward_left_mid_position,self.__backward_left_max_position, -msg.actuator_command[3].position) ## ! minus?
        # self.servo_cmd[0] = self.cal_goal_pos(self.__forward_left_min_position,self.__forward_left_mid_position,self.__forward_left_max_position, 0.0)
        # self.servo_cmd[1] = self.cal_goal_pos(self.__forward_right_min_position,self.__forward_right_mid_position,self.__forward_right_max_position, 0.0)
        # self.servo_cmd[2] = self.cal_goal_pos(self.__backward_right_min_position,self.__backward_right_mid_position,self.__backward_right_max_position, 0.0)
        # self.servo_cmd[3] = self.cal_goal_pos(self.__backward_left_min_position,self.__backward_left_mid_position,self.__backward_left_max_position, 0.0) ## ! minus?

    def control_loop_timer(self):
        # def update_servo_position_FL(self, result_container):
        #     with threading.Lock():
        #         # result_container['FL'] = self.cal_present_pos_left(self.__forward_left_mid_position,float(self.dxl_get_pos_data(self.__forward_left_ID)))
        #         data = 0#float(self.dxl_get_pos_data(self.__forward_left_ID))
        #         self.get_logger().warn(f"data1: {data}")

        # def update_servo_position_FR(self, result_container):
        #     with threading.Lock():
        #         # result_container['FR'] = self.cal_present_pos_right(self.__forward_right_mid_position,float(self.dxl_get_pos_data(self.__forward_right_ID)))
        #         data = float(self.dxl_get_pos_data(self.__forward_right_ID))
        #         self.get_logger().warn(f"data2: {data}")

        # def update_servo_position_RL(self, result_container):
        #     with threading.Lock():
        #         result_container['RL'] = -self.cal_present_pos_left(self.__backward_left_mid_position,float(self.dxl_get_pos_data(self.__backward_left_ID)))

        # def update_servo_position_RR(self, result_container):
        #     with threading.Lock():
        #         result_container['RR'] = -self.cal_present_pos_right(self.__backward_right_mid_position,float(self.dxl_get_pos_data(self.__backward_right_ID)))

        self.dxl_write_change_param_pos(self.__forward_left_ID,self.servo_cmd[0])
        self.dxl_write_change_param_pos(self.__forward_right_ID,self.servo_cmd[1])
        self.dxl_write_change_param_pos(self.__backward_right_ID,self.servo_cmd[2])
        self.dxl_write_change_param_pos(self.__backward_left_ID,self.servo_cmd[3])
        self.dxl_write_txPacket()

        servo_state_pub = ActuatorState()
        servo_state_pub.header.stamp = self.get_clock().now().to_msg()
        servo_forward_left = Actuator()
        servo_forward_right = Actuator()
        servo_backward_left = Actuator()
        servo_backward_right = Actuator()  
        servo_forward_left.name = 'Forward Left'
        servo_forward_right.name = 'Forward Right'
        servo_backward_left.name = 'Backward Left'
        servo_backward_right.name = 'Backward Right'

        servo_forward_left.position = self.cal_present_pos_left(self.__forward_left_mid_position,float(self.dxl_get_pos_data(self.__forward_left_ID)))
        servo_forward_right.position = self.cal_present_pos_right(self.__forward_right_mid_position,float(self.dxl_get_pos_data(self.__forward_right_ID)))
        servo_backward_left.position = -self.cal_present_pos_left(self.__backward_left_mid_position,float(self.dxl_get_pos_data(self.__backward_left_ID)))
        servo_backward_right.position = -self.cal_present_pos_right(self.__backward_right_mid_position,float(self.dxl_get_pos_data(self.__backward_right_ID)))

        # servo_forward_left.effort = float(self.dxl_get_cur_data(self.__forward_left_ID))
        # servo_forward_right.effort = float(self.dxl_get_cur_data(self.__forward_right_ID))
        # servo_backward_left.effort = float(self.dxl_get_cur_data(self.__backward_left_ID))
        # servo_backward_right.effort = float(self.dxl_get_cur_data(self.__backward_right_ID))
        # 创建线程
        # result_container = {}
        # thread_FL = threading.Thread(target=update_servo_position_FL, args=(self, result_container))
        # thread_FR = threading.Thread(target=update_servo_position_FR, args=(self, result_container))
        # thread_RL = threading.Thread(target=update_servo_position_RL, args=(self, result_container))
        # thread_RR = threading.Thread(target=update_servo_position_RR, args=(self, result_container))

        # # 启动线程
        # thread_FL.start()
        # thread_FR.start()
        # thread_RL.start()
        # thread_RR.start()

        # # 等待线程执行完毕
        # thread_FL.join()
        # thread_FR.join()
        # thread_RL.join()
        # thread_RR.join()

        # servo_forward_left.position = result_container.get('FL')
        # servo_forward_right.position = result_container.get('FR')
        # servo_backward_left.position = result_container.get('RL')
        # servo_backward_right.position = result_container.get('RR')

        servo_state_pub.actuator_state.append(servo_forward_left)
        servo_state_pub.actuator_state.append(servo_forward_right)
        servo_state_pub.actuator_state.append(servo_backward_right)
        servo_state_pub.actuator_state.append(servo_backward_left)

        self.publisher_.publish(servo_state_pub)
        
    def cal_goal_pos(self, min_pos, mid_pos, max_pos, goal):
        angle = int(goal/(2.0*math.pi)*4096)
        goal_pos = mid_pos + angle
        goal_pos = min(max(goal_pos, min_pos), max_pos)
        return goal_pos
    
    def cal_present_pos_left(self, mid_pos,pre_pos):
        angle = (pre_pos - mid_pos)/4096 * (2*math.pi)
        return angle

    def cal_present_pos_right(self, mid_pos,pre_pos): ## ! Is the function adapted to the 4WD?
        angle = -(pre_pos - mid_pos)/4096 * (2*math.pi)
        return angle
    
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
            print("[ID:%03d] groupBulkWrite addparam failed" % ID)
            quit()

    def dxl_write_txPacket(self):
        dxl_comm_result = self.groupBulkWrite.txPacket()
        if dxl_comm_result != COMM_SUCCESS:
            print("%s" % self.packetHandler.getTxRxResult(dxl_comm_result))

    def dxl_get_pos_data(self, ID):
        dxl_getdata_result = self.packetHandler.read4ByteTxRx(self.portHandler, 
                                                              ID, 
                                                              self.__addr_present_position)
        return dxl_getdata_result[0]

    def dxl_get_cur_data(self, ID):
        dxl_getdata_result = self.packetHandler.read2ByteTxRx(self.portHandler, 
                                                              ID, 
                                                              self.__addr_present_current)
        # print(dxl_getdata_result[0])
        curr = int(dxl_getdata_result[0])
        if dxl_getdata_result[0]>32768:
            curr = dxl_getdata_result[0] - 65536
        return curr * 2.69

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
