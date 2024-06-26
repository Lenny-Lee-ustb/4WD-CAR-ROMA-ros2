import numpy as np
from sensor_msgs.msg import Imu
from nav_msgs.msg import Odometry

class ImuData:
    def __init__(self, n):
        self.angular_velocity_x = np.zeros((n, 1))
        self.angular_velocity_y = np.zeros((n, 1))
        self.angular_velocity_z = np.zeros((n, 1))
        self.linear_acceleration_x = np.zeros((n, 1))
        self.linear_acceleration_y = np.zeros((n, 1))
        self.linear_acceleration_z = np.zeros((n, 1))
        self.roll_rad = np.zeros((n, 1))
        self.pitch_rad = np.zeros((n, 1))
        self.yaw_rad = np.zeros((n, 1))

    def update(self, msg):
        roll, pitch, yaw = self.quat2eul(msg.orientation.w, msg.orientation.x, msg.orientation.y, msg.orientation.z)
        self.roll_rad = np.append(self.roll_rad[1:], np.array([[roll]]),axis = 0)
        self.pitch_rad = np.append(self.pitch_rad[1:], np.array([[pitch]]),axis = 0)
        self.yaw_rad = np.append(self.yaw_rad[1:], np.array([[yaw]]),axis = 0)
        self.angular_velocity_x = np.append(self.angular_velocity_x[1:], np.array([[msg.angular_velocity.x]]),axis = 0)
        self.angular_velocity_y = np.append(self.angular_velocity_y[1:], np.array([[msg.angular_velocity.y]]),axis = 0)
        self.angular_velocity_z = np.append(self.angular_velocity_z[1:], np.array([[msg.angular_velocity.z]]),axis = 0)
        self.linear_acceleration_x = np.append(self.linear_acceleration_x[1:], np.array([[msg.linear_acceleration.x]]),axis = 0)
        self.linear_acceleration_y = np.append(self.linear_acceleration_y[1:], np.array([[msg.linear_acceleration.y]]),axis = 0)
        self.linear_acceleration_z = np.append(self.linear_acceleration_z[1:], np.array([[msg.linear_acceleration.z]]),axis = 0)

    def quat2eul(self, w, x, y, z):
        quaternion = np.array([w, x, y, z])
        quaternion_normalized = quaternion / np.linalg.norm(quaternion)

        # 计算对应的旋转矩阵
        R = np.array([[1-2*(quaternion_normalized[2]**2+quaternion_normalized[3]**2), 2*(quaternion_normalized[1]*quaternion_normalized[2]-quaternion_normalized[0]*quaternion_normalized[3]), 2*(quaternion_normalized[1]*quaternion_normalized[3]+quaternion_normalized[0]*quaternion_normalized[2])],
                    [2*(quaternion_normalized[1]*quaternion_normalized[2]+quaternion_normalized[0]*quaternion_normalized[3]), 1-2*(quaternion_normalized[1]**2+quaternion_normalized[3]**2), 2*(quaternion_normalized[2]*quaternion_normalized[3]-quaternion_normalized[0]*quaternion_normalized[1])],
                    [2*(quaternion_normalized[1]*quaternion_normalized[3]-quaternion_normalized[0]*quaternion_normalized[2]), 2*(quaternion_normalized[2]*quaternion_normalized[3]+quaternion_normalized[0]*quaternion_normalized[1]), 1-2*(quaternion_normalized[1]**2+quaternion_normalized[2]**2)]]
                    )

        # 计算欧拉角
        roll = np.arctan2(2*(quaternion_normalized[0]*quaternion_normalized[1] + quaternion_normalized[2]*quaternion_normalized[3]), 1 - 2*(quaternion_normalized[1]**2 + quaternion_normalized[2]**2))
        pitch = np.arcsin(2*(quaternion_normalized[0]*quaternion_normalized[2] - quaternion_normalized[3]*quaternion_normalized[1]))
        yaw = np.arctan2(2*(quaternion_normalized[0]*quaternion_normalized[3] + quaternion_normalized[1]*quaternion_normalized[2]), 1 - 2*(quaternion_normalized[2]**2 + quaternion_normalized[3]**2))

        return roll, pitch, yaw


class T265Data:
    def __init__(self, n):
        self.X = np.zeros((n, 1))
        self.Y = np.zeros((n, 1))
        self.Z = np.zeros((n, 1))
        self.vx = np.zeros((n, 1))
        self.vy = np.zeros((n, 1))
        self.vz = np.zeros((n, 1))

    def update(self, msg):
        data = Odometry()
        data.twist.twist.linear.x
        self.X = np.append(self.X[1:], np.array([[msg.pose.pose.position.x]]),axis = 0)
        self.Y = np.append(self.Y[1:], np.array([[msg.pose.pose.position.y]]),axis = 0)
        self.Z = np.append(self.Z[1:], np.array([[msg.pose.pose.position.z]]),axis = 0)
        self.vx = np.append(self.vx[1:], np.array([[msg.twist.twist.linear.x]]),axis = 0)
        self.vy = np.append(self.vy[1:], np.array([[msg.twist.twist.linear.y]]),axis = 0)
        self.vz = np.append(self.vz[1:], np.array([[msg.twist.twist.linear.z]]),axis = 0)