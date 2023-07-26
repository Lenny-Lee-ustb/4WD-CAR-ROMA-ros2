import rclpy
from rclpy.node import Node
import math
from dynamixel_sdk import * # Uses Dynamixel SDK library 

from geometry_msgs.msg import PolygonStamped, Point
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
        self.__left_min_position = self.declare_parameter("left_min_position",0)
        self.__left_mid_position = self.declare_parameter("left_mid_position",2047)
        self.__left_max_position = self.declare_parameter("left_max_position",4095)
        self.__right_ID = 2
        self.__right_min_position = self.declare_parameter("right_min_position",0)
        self.__right_mid_position = self.declare_parameter("right_mid_position",2047)
        self.__right_max_position = self.declare_parameter("right_max_position",4095)
        self.__baud_rate = self.declare_parameter("baud_rate", 1000000)
        self.__device_name = self.declare_parameter("device_name",'/dev/servo')
        self.__moving_threshold = self.declare_parameter("moving_threshold", 10)
        self.servo_cmd = [self.__left_mid_position, self.__right_mid_position]
        self.servo_cmd_sub = PolygonStamped()

        self.dxl_communication_init()


        self.publisher_ = self.create_publisher(PolygonStamped, 'servo_state', qos_profile_pub)
        self.publisher_
        self.subscriber_ = self.create_subscription(PolygonStamped, 'servo_cmd', self.cmd_callback, qos_profile_sub)
        self.subscriber_
        self.pubTimer_ = self.create_timer(0.01, self.control_loop_timer)

    def dxl_communication_init(self):
        self.portHandler = PortHandler(self.__device_name)
        self.packetHandler = PacketHandler(self.__protocol_version)
        self.groupBulkWrite = GroupBulkWrite(self.portHandler, self.packetHandler)
        self.groupBulkRead = GroupBulkRead(self.portHandler, self.packetHandler)
        # Open port
        if self.portHandler.openPort():
            self.get_logger().info("Succeeded to open the port")
        else:
            self.get_logger().info("Failed to open the port")
            quit()

        # Set port baudrate
        if self.portHandler.setBaudRate(self.__baud_rate):
            self.get_logger().info("Succeeded to change the baudrate")
        else:
            self.get_logger().info("Failed to change the baudrate")

        # Enable Left servo Torque
        dxl_comm_result, dxl_error = self.packetHandler.write1ByteTxRx(self.portHandler, 
                                                                       self.__left_ID, 
                                                                       self.__addr_torque_enable, 
                                                                       self.__torque_enable)
        if dxl_comm_result != COMM_SUCCESS:
            self.get_logger().info("%s" % self.packetHandler.getTxRxResult(dxl_comm_result))
        elif dxl_error != 0:
            self.get_logger().info("%s" % self.packetHandler.getRxPacketError(dxl_error))
        else:
            self.get_logger().info("Dynamixel#%d has been successfully connected" % self.__left_ID)
        # Enable Right servo Torque
        dxl_comm_result, dxl_error = self.packetHandler.write1ByteTxRx(self.portHandler, 
                                                                       self.__right_ID, 
                                                                       self.__addr_torque_enable, 
                                                                       self.__torque_enable)
        if dxl_comm_result != COMM_SUCCESS:
            self.get_logger().info("%s" % self.packetHandler.getTxRxResult(dxl_comm_result))
        elif dxl_error != 0:
            self.get_logger().info("%s" % self.packetHandler.getRxPacketError(dxl_error))
        else:
            self.get_logger().info("Dynamixel#%d has been successfully connected" % self.__right_ID)

        # Add parameter storage for Left servo present position
        dxl_addparam_result = self.groupBulkRead.addParam(self.__left_ID, 
                                                          self.__addr_present_position, 
                                                          self.__len_present_position)
        if dxl_addparam_result != True:
            self.get_logger().info("[ID:%03d] groupBulkRead addparam failed" % self.__left_ID)
        # Add parameter storage for Left servo present position
        dxl_addparam_result = self.groupBulkRead.addParam(self.__right_ID, 
                                                          self.__addr_present_position, 
                                                          self.__len_present_position)
        if dxl_addparam_result != True:
            self.get_logger().info("[ID:%03d] groupBulkRead addparam failed" % self.__right_ID)

    def cmd_callback(self, msg):
        self.servo_cmd_sub = msg
        self.servo_cmd[0] = self.servo_cmd_sub.polygon.point[0].x
        self.servo_cmd[1] = self.servo_cmd_sub.polygon.point[1].x

    def control_loop_timer(self):
        self.servo_state_pub = PolygonStamped()

def main(args=None):
    rclpy.init(args=args) # 初始化rclpy

    qos_profile_publisher = QoSProfile(depth=10)
    qos_profile_publisher.reliability = QoSReliabilityPolicy.RELIABLE
    # Options  QoSDurabilityPolicy.VOLATILE, QoSDurabilityPolicy.TRANSIENT_LOCAL,
    qos_profile_publisher.durability = QoSDurabilityPolicy.VOLATILE
    qos_profile_publisher.deadline = Duration(seconds=1)
    # Options QoSLivelinessPolicy.MANUAL_BY_TOPIC, QoSLivelinessPolicy.AUTOMATIC
    qos_profile_publisher.liveliness = QoSLivelinessPolicy.AUTOMATIC

    qos_profile_subscriber = QoSProfile(depth=10)
    qos_profile_subscriber.reliability = QoSReliabilityPolicy.BEST_EFFORT
    qos_profile_subscriber.durability = QoSDurabilityPolicy.VOLATILE

    ServoSubPubNode = ServoNode("servo_rs485_node", qos_profile_publisher, qos_profile_subscriber)  # 新建一个节点

    rclpy.spin(ServoSubPubNode) # 保持节点运行，检测是否收到退出指令（Ctrl+C）
    ServoSubPubNode.destroy_node()
    rclpy.shutdown() # 关闭rclpy

if __name__ == '__main__':
    main()
