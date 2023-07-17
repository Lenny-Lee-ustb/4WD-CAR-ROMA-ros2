import rclpy
from rclpy.node import Node
import serial
import math
import dynamixel_functions as dynamixel  

from rclpy.qos import QoSProfile
from rclpy.duration import Duration
from rclpy.qos import QoSDurabilityPolicy
from rclpy.qos import QoSLivelinessPolicy
from rclpy.qos import QoSReliabilityPolicy

class ServoNode(Node):
    def __init__(self, nodeName, nameSpace, qos_profile_pub, qos_profile_sub) -> None:
        super().__init__(node_name=nodeName, namespace=nameSpace)
        self.publisher_ = self.create_publisher(msg_type=Imu, topic='servo_state', qos_profile=qos_profile_pub)
        self.subscriber_ = self.create_subscription()
        self.pubTimer_ = self.create_timer()

        

def main(args=None):
    rclpy.init(args=args) # 初始化rclpy

    nameSpace = "car01"
    nodeName = "servo_rs485_node"

    qos_profile_publisher = QoSProfile(depth=100)
    qos_profile_publisher.reliability = QoSReliabilityPolicy.BEST_EFFORT
    # Options  QoSDurabilityPolicy.VOLATILE, QoSDurabilityPolicy.TRANSIENT_LOCAL,
    qos_profile_publisher.durability = QoSDurabilityPolicy.VOLATILE
    qos_profile_publisher.deadline = Duration(seconds=1)
    # Options QoSLivelinessPolicy.MANUAL_BY_TOPIC, QoSLivelinessPolicy.AUTOMATIC
    qos_profile_publisher.liveliness = QoSLivelinessPolicy.AUTOMATIC

    qos_profile_subscriber = QoSProfile(depth=100)
    qos_profile_subscriber.reliability = QoSReliabilityPolicy.BEST_EFFORT
    qos_profile_subscriber.durability = QoSDurabilityPolicy.VOLATILE
    
    ServoSubPubNode = ServoNode(nodeName, nameSpace, qos_profile_publisher, qos_profile_subscriber)  # 新建一个节点
    # ServoSubPubNode.start_reading() # start read serial

    rclpy.spin(ServoSubPubNode) # 保持节点运行，检测是否收到退出指令（Ctrl+C）
    ServoSubPubNode.destroy_node()
    rclpy.shutdown() # 关闭rclpy

if __name__ == '__main__':
    main()
