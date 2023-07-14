import rclpy
import serial
import math
import dynamixel_functions as dynamixel  

from rclpy.qos import QoSProfile
from rclpy.duration import Duration
from rclpy.qos import QoSDurabilityPolicy
from rclpy.qos import QoSLivelinessPolicy
from rclpy.qos import QoSReliabilityPolicy

class ImuNode(Node):
    def __init__(self, nodeName, nameSpace, qos_profile) -> None:
        pass


def main(args=None):
    rclpy.init(args=args) # 初始化rclpy

    nameSpace = "car01"
    nodeName = "wt906_imu_serial_node"

    qos_profile_publisher = QoSProfile(depth=100)
    # Options  QoSDurabilityPolicy.VOLATILE, QoSDurabilityPolicy.TRANSIENT_LOCAL,
    qos_profile_publisher.durability = QoSDurabilityPolicy.VOLATILE
    qos_profile_publisher.deadline = Duration(seconds=1)
    # Options QoSLivelinessPolicy.MANUAL_BY_TOPIC, QoSLivelinessPolicy.AUTOMATIC
    qos_profile_publisher.liveliness = QoSLivelinessPolicy.AUTOMATIC
    qos_profile_publisher.reliability = QoSReliabilityPolicy.BEST_EFFORT
    
    ImuTopicPubNode = ImuNode(nodeName, nameSpace, qos_profile_publisher)  # 新建一个节点
    ImuTopicPubNode.start_reading() # start read serial

    rclpy.spin(ImuTopicPubNode) # 保持节点运行，检测是否收到退出指令（Ctrl+C）
    ImuTopicPubNode.destroy_node()
    rclpy.shutdown() # 关闭rclpy

if __name__ == '__main__':
    main()
