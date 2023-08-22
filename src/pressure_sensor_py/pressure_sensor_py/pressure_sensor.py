import rclpy
from rclpy.node import Node
from custom_interfaces.msg import PressureSensor
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
        self.frequency = self.declare_parameter('serial_frequency',500).value
        self.serial_port = self.declare_parameter('serial_port','/dev/pressure_sensor1').value
        self.serial_baudrate = self.declare_parameter('serial_baudrate',115200).value
        self.PressureSensorFrameID = self.declare_parameter('PressureSensorFrameID','PresssureSensor0').value
        self.publishersx = self.create_publisher(msg_type=PressureSensor, topic='pressure_sensor', qos_profile=qos_profile)
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
                    filter_data = self.filter(float_data)
                else:
                    self.get_logger().info("VERIFICATION FAILED, %s" % str_data[128:136])
                print(float_data)
                self.pub(float_data, filter_data)
                time.sleep(1e-3)
        except serial.SerialException as e:
            self.get_logger().error('Serial port error: %s' % str(e))
            self.ser.close()
            time.sleep(1)

    def pub(self, raw_data, filter_data):
        data = PressureSensor()
        data.header.frame_id = self.PressureSensorFrameID
        data.header.stamp = self.get_clock().now().to_msg()
        data.raw_data = raw_data[0:10]
        data.filter_data = filter_data[0:10]
        self.publishersx.publish(data)

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
            true_vars.append(float_val)
        return true_vars
            
    def filter(self, floatdata):
        filter_data = [0.]*10
        return filter_data



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