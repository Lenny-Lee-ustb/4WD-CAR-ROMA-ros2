import rclpy
from rclpy.node import Node
from rclpy.qos import QoSProfile
from rclpy.duration import Duration
from rclpy.qos import QoSDurabilityPolicy
from rclpy.qos import QoSLivelinessPolicy
from rclpy.qos import QoSReliabilityPolicy
from sensor_msgs.msg import Imu
from nav_msgs.msg import Odometry
from filter_py.data_buffer import ImuData
from filter_py.data_buffer import T265Data
import numpy as np

class Filter(Node):
    def __init__(self, name, qos_profile_pub, qos_profile_sub):
        super().__init__(node_name=name)
        self.imu_data_buffer = ImuData(20)
        self.imu_filter_coeffs = np.array([0,0.000583563548264273,0.00400881577664824,0.0125231803463430,0.0273227269740018,0.0479144334504878,0.0719557828622666,0.0956643612336359,0.114707278934770,0.125319856873582,0.125319856873582,0.114707278934770,0.0956643612336359,0.0719557828622666,0.0479144334504878,0.0273227269740018,0.0125231803463430,0.00400881577664824,0.000583563548264273,0])
        self.t265_data_buffer = T265Data(20)
        self.t265_filter_coeffs = np.array([0,-0.000811230936137161,-0.00442258883059359,-0.00887027049079436,-0.00666855822467418,0.0116943008496511,0.0509668662203333,0.105538433056030,0.159458371841038,0.193114676515147,0.193114676515147,0.159458371841038,0.105538433056030,0.0509668662203333,0.0116943008496511,-0.00666855822467418,-0.00887027049079436,-0.00442258883059359,-0.000811230936137161,0])

        self.ImuFilterFrameID = self.declare_parameter('ImuFilterFrameID','Imu_filter_frame').value
        self.T265FilterFrameID = self.declare_parameter('T265FilterFrameID','t265_filter_frame').value
        self.subscriber_imu = self.create_subscription(msg_type=Imu, topic='Imu_data', callback=self.imu_filter, qos_profile=qos_profile_sub)
        # self.subscriber_imu = self.create_subscription(msg_type=Imu, topic='imu/data', callback=self.imu_filter, qos_profile=qos_profile_sub)
        self.publishers_imu = self.create_publisher(msg_type=Imu, topic='Imu_data_filter', qos_profile=qos_profile_pub)
        self.subscriber_t265 = self.create_subscription(msg_type=Odometry, topic='/camera/pose/sample', callback=self.t265_filter, qos_profile=qos_profile_sub)
        self.publishers_t265 = self.create_publisher(msg_type=Odometry, topic='t265_odometry_filter', qos_profile=qos_profile_pub)

    def imu_filter(self, msg):
        data = Imu()
        data.header.frame_id = self.ImuFilterFrameID
        data.header.stamp = msg.header.stamp
        self.imu_data_buffer.update(msg)
        data.angular_velocity.x = float((self.imu_filter_coeffs @ self.imu_data_buffer.angular_velocity_x)[0])
        data.angular_velocity.y = float((self.imu_filter_coeffs @ self.imu_data_buffer.angular_velocity_y)[0])
        data.angular_velocity.z = float((self.imu_filter_coeffs @ self.imu_data_buffer.angular_velocity_z)[0])
        # data.angular_velocity.z = float(self.imu_data_buffer.angular_velocity_z[0])
        data.linear_acceleration.x = float((self.imu_filter_coeffs @ self.imu_data_buffer.linear_acceleration_x)[0])
        data.linear_acceleration.y = float((self.imu_filter_coeffs @ self.imu_data_buffer.linear_acceleration_y)[0])
        data.linear_acceleration.z = float((self.imu_filter_coeffs @ self.imu_data_buffer.linear_acceleration_z)[0])
        data.orientation.x = float((self.imu_filter_coeffs @ self.imu_data_buffer.roll_rad)[0]) #/np.pi)*180
        data.orientation.y = float((self.imu_filter_coeffs @ self.imu_data_buffer.pitch_rad)[0]) #/np.pi)*180
        # data.orientation.z = float((self.imu_filter_coeffs @ self.imu_data_buffer.yaw_rad)[0]) #/np.pi)*180
        data.orientation.z = float(self.imu_data_buffer.yaw_rad[0])
        data.orientation.w = 0.
        self.publishers_imu.publish(data)

    def t265_filter(self, msg):
        data = Odometry()
        data.header.frame_id = self.T265FilterFrameID
        data.header.stamp = msg.header.stamp
        self.t265_data_buffer.update(msg)
        data.pose.pose.position.x = float((self.t265_filter_coeffs @ self.t265_data_buffer.X)[0])
        data.pose.pose.position.y = float((self.t265_filter_coeffs @ self.t265_data_buffer.Y)[0])
        data.pose.pose.position.z = float((self.t265_filter_coeffs @ self.t265_data_buffer.Z)[0])
        data.twist.twist.linear.x = float((self.t265_filter_coeffs @ self.t265_data_buffer.vx)[0])
        data.twist.twist.linear.y = float((self.t265_filter_coeffs @ self.t265_data_buffer.vy)[0])
        data.twist.twist.linear.z = float((self.t265_filter_coeffs @ self.t265_data_buffer.vz)[0])
        self.publishers_t265.publish(data)


def main(args=None):
    rclpy.init()

    qos_profile_publisher = QoSProfile(depth=10)
    # Options  QoSDurabilityPolicy.VOLATILE, QoSDurabilityPolicy.TRANSIENT_LOCAL,
    qos_profile_publisher.durability = QoSDurabilityPolicy.VOLATILE
    qos_profile_publisher.deadline = Duration(seconds=1)
    # Options QoSLivelinessPolicy.MANUAL_BY_TOPIC, QoSLivelinessPolicy.AUTOMATIC
    qos_profile_publisher.liveliness = QoSLivelinessPolicy.AUTOMATIC
    qos_profile_publisher.reliability = QoSReliabilityPolicy.BEST_EFFORT

    qos_profile_subscriber = QoSProfile(depth=10)
    qos_profile_subscriber.reliability = QoSReliabilityPolicy.BEST_EFFORT
    qos_profile_subscriber.durability = QoSDurabilityPolicy.VOLATILE

    node = Filter("filter_py", qos_profile_publisher, qos_profile_subscriber)
    print("filter startup")
    rclpy.spin(node)
    rclpy.shutdown()