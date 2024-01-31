import rclpy
from rclpy.node import Node
from custom_interfaces.msg import PressureSensor
from custom_interfaces.msg import ForceSensor
import serial
import binascii
import struct
import time
from rclpy.qos import QoSProfile
from rclpy.duration import Duration
from rclpy.qos import QoSDurabilityPolicy
from rclpy.qos import QoSLivelinessPolicy
from rclpy.qos import QoSReliabilityPolicy

class pressure_sensor(Node):
    def __init__(self, name, namespace, qos_profile):
        super().__init__(node_name=name, namespace=namespace)
        # self.x = 0
        self.frequency = self.declare_parameter('serial_frequency',500).value
        self.serial_port = self.declare_parameter('serial_port','/dev/ttyACM0').value
        self.serial_baudrate = self.declare_parameter('serial_baudrate',115200).value
        self.PressureSensorFrameID = self.declare_parameter('PressureSensorFrameID','PresssureSensor0').value
        self.publishers_force = self.create_publisher(msg_type=ForceSensor, topic='force_sensor', qos_profile=qos_profile)
        self.publishers_pressure = self.create_publisher(msg_type=PressureSensor, topic='pressure_sensor', qos_profile=qos_profile)
        self.read()


    def read(self):
        self.ser = serial.Serial(
                port = self.serial_port,
                baudrate = self.serial_baudrate,
                bytesize = 8,
                parity = 'N',
                stopbits = 1
                )
        self.get_logger().info('Start reading %s' % self.serial_port)
        try:
            ser = serial.Serial(self.serial_port, self.serial_baudrate)
            while rclpy.ok():
                data = ser.read(68)
                str_data = binascii.hexlify(data).decode('utf-8')
                if str_data[128:136]=="0000807f":
                    float_data = self.str2float(str_data)
                    pressure = self.filter_pressure(float_data)
                    force = self.filter_force(float_data)
                else:
                    self.get_logger().info("VERIFICATION FAILED, %s" % str_data[128:136])
                # print(float_data)
                self.pub_pressure(float_data, pressure)
                self.pub_force(force)
                time.sleep(5e-4)
        except serial.SerialException as e:
            self.get_logger().error('Serial port error: %s' % str(e))
            self.ser.close()
            time.sleep(1)

    def pub_pressure(self, raw_data, filter_data):
        data = PressureSensor()
        data.header.frame_id = self.PressureSensorFrameID
        data.header.stamp = self.get_clock().now().to_msg()
        data.raw_data = raw_data[5:15]
        data.filter_data = filter_data[0:10]
        self.publishers_pressure.publish(data)

    def pub_force(self, force):
        data = ForceSensor()
        data.header.frame_id = self.PressureSensorFrameID
        data.header.stamp = self.get_clock().now().to_msg()
        data.x1 = force[0]
        data.y1 = force[1]
        data.x2 = force[2]
        data.y2 = force[3]
        data.fx = force[4]
        data.fy = force[5]
        self.publishers_force.publish(data)

    def str2float(self,string_data):
        true_vars = list()
        sum = 0
        for x in range(16):
            data = string_data[sum:sum+2]
            sum += 2
            for y in range(3):
                data = string_data[sum:sum+2]+data
                sum += 2
            data = int(data,16)
            float_val = struct.unpack('!f', struct.pack('!I', data))[0]
            float_val = float_val / 65535
            true_vars.append(float_val)
        return true_vars
            
    def filter_pressure(self, floatdata):
        filter_data = [0.]*10
        return filter_data
    
    def filter_force(self, floatdata):
        x1 = (floatdata[1]) * 50 * 1e3
        y1 = (floatdata[2]) * 50 * 1e3
        x2 = (floatdata[3]) * 50 * 1e3
        # self.x = 0.999*self.x + 0.001*x2;
        # y1 = self.x
        y2 = (floatdata[4]) * 50 * 1e3
        # x1 = (floatdata[1]-0.5) * 25 * 1e3
        # y1 = (floatdata[2]-0.5) * 25 * 1e3
        # x2 = (floatdata[3]-0.5) * 25 * 1e3
        # y2 = (floatdata[4]-0.5) * 25 * 1e3
        Fx = floatdata[1] + floatdata[3]; # 13
        Fx = (Fx - 0.5) * 50 * 9.8;
        Fy = floatdata[3] + floatdata[4]; # 24
        Fy = (Fy - 0.5) * 50 * 9.8;
        return [x1, y1, x2, y2, Fx, -Fy]



def main(args=None):
    rclpy.init()

    qos_profile_publisher = QoSProfile(depth=100)
    # Options  QoSDurabilityPolicy.VOLATILE, QoSDurabilityPolicy.TRANSIENT_LOCAL,
    qos_profile_publisher.durability = QoSDurabilityPolicy.VOLATILE
    qos_profile_publisher.deadline = Duration(seconds=1)
    # Options QoSLivelinessPolicy.MANUAL_BY_TOPIC, QoSLivelinessPolicy.AUTOMATIC
    qos_profile_publisher.liveliness = QoSLivelinessPolicy.AUTOMATIC
    qos_profile_publisher.reliability = QoSReliabilityPolicy.BEST_EFFORT

    node = pressure_sensor("pressure_sensor", "car01", qos_profile_publisher)
    rclpy.spin(node)
    rclpy.shutdown()