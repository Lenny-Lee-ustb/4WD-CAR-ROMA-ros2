import rclpy
import serial
import math
from sensor_msgs.msg import Imu
from rclpy.node import Node
from geometry_msgs.msg import Pose, PointStamped
from rclpy.qos import QoSProfile
from rclpy.duration import Duration
from rclpy.qos import QoSDurabilityPolicy
from rclpy.qos import QoSLivelinessPolicy
from rclpy.qos import QoSReliabilityPolicy


class ImuNode(Node):
    def __init__(self, nodeName, nameSpace, qos_profile) -> None:
        super().__init__(node_name=nodeName, namespace=nameSpace)
        self.get_logger().info("%s已启动" % self.get_node_names())
        self.declare_parameter('serial_ID', 0)
        self.declare_parameter('serial_port', '/dev/imu')
        self.declare_parameter('serial_baudrate', 921600)
        self.declare_parameter('ImuFrameID', 'Imu_0')
        self.serial_ID = self.get_parameter('serial_ID').get_parameter_value().integer_value
        self.serial_port = self.get_parameter('serial_port').get_parameter_value().string_value
        self.serial_baudrate = self.get_parameter('serial_baudrate').get_parameter_value().integer_value
        self.ImuFrameID = self.get_parameter('ImuFrameID').get_parameter_value().string_value
        self.publisher_ = self.create_publisher(msg_type=Imu, topic='imu_state_'+str(self.serial_ID), qos_profile=qos_profile) # init publisher
        self.rpy_publisher_ = self.create_publisher(msg_type=PointStamped, topic='imu_rpy_'+str(self.serial_ID), qos_profile=qos_profile) # init publisher

        # variables for DueData
        self.ACCData=[0.0]*8
        self.GYROData=[0.0]*8
        self.AngleData=[0.0]*8
        self.CheckSum=0
        self.Bytenum=0
        self.FrameState=0
        self.a = [0.0]*3
        self.w = [0.0]*3
        self.Angle = [0.0]*3

    def start_reading(self):
        self.get_logger().info('Start reading IMU-%d data' % self.serial_ID)
        try:
            ser = serial.Serial(self.serial_port, self.serial_baudrate)
            while rclpy.ok():
                # if ser.in_waiting > 0:
                data = ser.read(33)
                self.DueData(data)  # 解析串口数据
        except serial.SerialException as e:
            self.get_logger().error('Serial port error: %s' % str(e))

    def DueData(self, inputdata):  
        for data in inputdata:
            if self.FrameState==0:  
                if data==0x55 and self.Bytenum==0:
                    self.CheckSum=data
                    self.Bytenum=1
                    continue
                elif data==0x51 and self.Bytenum==1:
                    self.CheckSum+=data
                    self.FrameState=1
                    self.Bytenum=2
                elif data==0x52 and self.Bytenum==1:
                    self.CheckSum+=data
                    self.FrameState=2
                    self.Bytenum=2
                elif data==0x53 and self.Bytenum==1:
                    self.CheckSum+=data
                    self.FrameState=3
                    self.Bytenum=2
            elif self.FrameState==1:
                if self.Bytenum<10:           
                    self.ACCData[self.Bytenum-2]=data 
                    self.CheckSum+=data
                    self.Bytenum+=1
                else:
                    if data == (self.CheckSum&0xff):  
                        self.a = self.get_acc(self.ACCData)
                    self.CheckSum=0                  
                    self.Bytenum=0
                    self.FrameState=0
            elif self.FrameState==2: 
                if self.Bytenum<10:
                    self.GYROData[self.Bytenum-2]=data
                    self.CheckSum+=data
                    self.Bytenum+=1
                else:
                    if data == (self.CheckSum&0xff):
                        self.w = self.get_gyro(self.GYROData)
                    self.CheckSum=0
                    self.Bytenum=0
                    self.FrameState=0
            elif self.FrameState==3: 
                if self.Bytenum<10:
                    self.AngleData[self.Bytenum-2]=data
                    self.CheckSum+=data
                    self.Bytenum+=1
                else:
                    if data == (self.CheckSum&0xff):
                        self.Angle = self.get_angle(self.AngleData)
                        self.pub_data(self.a,self.w,self.Angle)
                    self.CheckSum=0
                    self.Bytenum=0
                    self.FrameState=0
 
    def get_acc(self, datahex):  
        axl = datahex[0]                                        
        axh = datahex[1]
        ayl = datahex[2]                                        
        ayh = datahex[3]
        azl = datahex[4]                                        
        azh = datahex[5]
        
        k_acc = 16.0
    
        acc_x = (axh << 8 | axl) / 32768.0 * k_acc
        acc_y = (ayh << 8 | ayl) / 32768.0 * k_acc
        acc_z = (azh << 8 | azl) / 32768.0 * k_acc
        if acc_x >= k_acc:
            acc_x -= 2 * k_acc
        if acc_y >= k_acc:
            acc_y -= 2 * k_acc
        if acc_z >= k_acc:
            acc_z-= 2 * k_acc
        return acc_x,acc_y,acc_z

    def get_gyro(self, datahex):                                      
        wxl = datahex[0]                                        
        wxh = datahex[1]
        wyl = datahex[2]                                        
        wyh = datahex[3]
        wzl = datahex[4]                                        
        wzh = datahex[5]
        k_gyro = 2000.0
    
        gyro_x = (wxh << 8 | wxl) / 32768.0 * k_gyro
        gyro_y = (wyh << 8 | wyl) / 32768.0 * k_gyro
        gyro_z = (wzh << 8 | wzl) / 32768.0 * k_gyro
        if gyro_x >= k_gyro:
            gyro_x -= 2 * k_gyro
        if gyro_y >= k_gyro:
            gyro_y -= 2 * k_gyro
        if gyro_z >=k_gyro:
            gyro_z-= 2 * k_gyro
        return gyro_x,gyro_y,gyro_z
    
    def get_angle(self, datahex):                                 
        rxl = datahex[0]                                        
        rxh = datahex[1]
        ryl = datahex[2]                                        
        ryh = datahex[3]
        rzl = datahex[4]                                        
        rzh = datahex[5]
        k_angle = 180.0
    
        angle_x = (rxh << 8 | rxl) / 32768.0 * k_angle
        angle_y = (ryh << 8 | ryl) / 32768.0 * k_angle
        angle_z = (rzh << 8 | rzl) / 32768.0 * k_angle
        # if angle_x >= k_angle:
        #     angle_x -= 2 * k_angle
        # if angle_y >= k_angle:
        #     angle_y -= 2 * k_angle
        # if angle_z >=k_angle:
        #     angle_z-= 2 * k_angle
        return angle_x,angle_y,angle_z

    def RPY2Quar(self, angle):
        roll = math.radians(angle[0])
        pitch = math.radians(angle[1])
        yaw = math.radians(angle[2])
        cy=math.cos(yaw*0.5)
        sy=math.sin(yaw*0.5)
        cp=math.cos(pitch*0.5)
        sp=math.sin(pitch*0.5)
        cr =math.cos(roll * 0.5)
        sr =math.sin(roll * 0.5)
        
        q= Pose()
        q.orientation.w= cy * cp * cr + sy * sp * sr
        q.orientation.x = cy * cp * sr - sy * sp * cr
        q.orientation.y = sy * cp * sr + cy * sp * cr
        q.orientation.z = sy * cp * cr - cy * sp * sr
        return q

    def pub_data(self, a,w,angle):
        pub_imu = Imu()
        pub_imu.header.frame_id = self.ImuFrameID
        pub_imu.header.stamp = self.get_clock().now().to_msg()
        pub_imu.linear_acceleration.x = a[0]
        pub_imu.linear_acceleration.y = a[1]
        pub_imu.linear_acceleration.z = a[2]
        pub_imu.angular_velocity.x = w[0]
        pub_imu.angular_velocity.y = w[1]
        pub_imu.angular_velocity.z = w[2]
        pub_imu.orientation = self.RPY2Quar(angle).orientation
        self.publisher_.publish(pub_imu)

        pub_rpy = PointStamped()
        pub_rpy.header = pub_imu.header
        pub_rpy.point.x = angle[0]
        pub_rpy.point.y = angle[1]
        pub_rpy.point.z = angle[2]
        self.rpy_publisher_.publish(pub_rpy)
        # self.get_logger().info('pub now')

def main(args=None):
    rclpy.init(args=args) # 初始化rclpy

    nameSpace = "car01"
    nodeName = "wt906_serial_node"

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