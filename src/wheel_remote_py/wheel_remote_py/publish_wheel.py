import rclpy
from rclpy.node import Node

# from std_msgs.msg import String
from geometry_msgs.msg import Twist
# from geometry_msgs.msg import Vector3

from socket import *

maxAngle = 0.7
maxSpeed = 5

serverPort = 12001
serverSocket = socket(AF_INET,SOCK_DGRAM)
serverSocket.bind(('',serverPort))    #注意bind方法括号内为一个元组，引号默认表示为127.0.0.1，即监听本地端口
print('ready')

class MinimalPublisher(Node):

    def __init__(self):
        super().__init__('wheel_publisher')
        self.publisher_ = self.create_publisher(Twist, 'cmd_vel', 10)
        timer_period = 0.01  # seconds
        self.timer = self.create_timer(timer_period, self.timer_callback)
        # self.i = 0

    def timer_callback(self):
        msg = Twist()
        wheel_info = recvWheel(serverSocket) # 1*3 list of float

        msg.angular.z = wheel_info[0] * maxAngle
        msg.linear.x = wheel_info[1] * maxSpeed
        # msg.linear.y = wheel_info[2]


        self.publisher_.publish(msg)
        # self.get_logger().info('Publishing: "%.4f", "%.4f"' % (msg.angular.z, msg.linear.x))
        # self.i += 1


def str2float(str):
    data = str.split()
    for i in range(len(data)):
        data[i] = float(data[i])
    return data

def recvWheel(serverSocket):
    message,clientAddress = serverSocket.recvfrom(2048)        #接收客户端发来的消息
    message = str2float(message)
    data = [0.0, 0.0]
    if message:
        data[0] = message[0]
        if message[2] > 0.01:
            speedHold = message[1]
            data[1] = (1 - message[2]) * speedHold
        elif message[2] <= 0.01:
            data[1] = message[1]
    # print(message, type(message[0]))
        serverSocket.sendto('Received'.encode(),clientAddress)        #使用socket时，只能以字节形式传送，故需要encode()
    return data

def main(args=None):
    rclpy.init(args=args)
    

    wheel_publisher = MinimalPublisher()

    rclpy.spin(wheel_publisher)

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    wheel_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    
    main()