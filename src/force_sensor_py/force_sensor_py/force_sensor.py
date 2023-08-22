import rclpy
from rclpy.node import Node
from std_msgs.msg import Float32
from custom_interfaces.msg import ForceSensor
import signal
import serial
import time
from modbus_tk import modbus_rtu
from rclpy.qos import QoSProfile
from rclpy.duration import Duration
from rclpy.qos import QoSDurabilityPolicy
from rclpy.qos import QoSLivelinessPolicy
from rclpy.qos import QoSReliabilityPolicy


class force_sensor(Node):
    def __init__(self, name, namespace, qos_profile):
        super().__init__(node_name = name, namespace = namespace)
        self.frequency = self.declare_parameter('serial_frequency',100).value
        self.serial_port = self.declare_parameter('serial_port','/dev/force_sensor1').value
        self.serial_baudrate = self.declare_parameter('serial_baudrate',250000).value
        self.ForceSensorFrameID = self.declare_parameter('ForceSensorFrameID','ForceSensor0').value
        self.slave = self.declare_parameter('slave',[1,2]).value
        self.close = signal.signal(signal.SIGINT, self.close_modbus)
        self.publishersx_f = self.create_publisher(msg_type=ForceSensor, topic='force_sensor_front', qos_profile=qos_profile)
        self.publishersx_r = self.create_publisher(msg_type=ForceSensor, topic='force_sensor_rear', qos_profile=qos_profile)
        # self.multi_publisher(self.slave, qos_profile) # published by different publisher
        try:
            self.master = modbus_rtu.RtuMaster(serial.Serial(
                port = self.serial_port,
                baudrate = self.serial_baudrate,
                bytesize = 8,
                parity = 'E',
                stopbits = 1
                ))
            self.master.set_timeout(5.0)
            self.master.set_verbose(True)
            self.get_logger().info("create rtumaster successfully")
        except serial.SerialException as e:
             self.master.close()
             self.get_logger().error('Serial port error: %s' % str(e))
             time.sleep(1)
        self.multi_read(self.slave)
    
    def pub(self, force):
        pub_force = ForceSensor()
        pub_force.header.frame_id = self.ForceSensorFrameID
        pub_force.header.stamp = self.get_clock().now().to_msg()
        pub_force.x = force[0]
        pub_force.y = force[1]
        self.publishersx_f.publish(pub_force)
        pub_force.x = force[2]
        pub_force.y = force[3]
        self.publishersx_r.publish(pub_force)

    def multi_publisher(self,listx, qos_profile_publisher):
        self.publishersx = list()
        for x in listx:
            self.publishersx.append(self.create_publisher(msg_type=Float32, topic='force_state_'+str(x), qos_profile=qos_profile_publisher))

    def multi_topic_pub(self, num, force):
        pub_force = Float32()
        pub_force.data = force
        self.publishersx[num-1].publish(pub_force)


    def multi_read(self,listx):
        try:
            force = [0., 0., 0., 0.]
            while rclpy.ok():
                for x in listx:
                    force[x-1]=self.read_modbus(x)
                    # self.multi_topic_pub(x, force[x-1]) # published by different publisher
                    time.sleep(1/self.frequency/(len(force)-1))
                self.pub(force) # published by one publisher
                # time.sleep(1/self.frequency/3)
        except serial.SerialException as e:
            self.get_logger().error('Serial port error: %s' % str(e))
            self.master.close()
            time.sleep(1)


    def read_modbus(self, num):
        data = self.master.execute(slave=num, function_code=0x04, starting_address=0x0004, quantity_of_x = 0x03)
        # self.get_logger().info("(sensor%d)data0: %d, data1: %d, data2: %d" % (num, data[0], data[1], data[2]))
        true_value = self.complement_to_true_value(data[0], data[1], data[2])
        # self.get_logger().info("(sensor%d)force: %.4f" % (num, true_value))
        return true_value
                

    def close_modbus(self, signum, frame):
        self.get_logger().info('entry close_modbus')
        self.master.close()
        time.sleep(1)
        self.get_logger().info('Serial port closed.')
        rclpy.shutdown()

    def complement_to_true_value(self, high, low, state):
        data = (high<<16)+low
        index = state & 0x0F00
        index = index >> 8
        if int(data/(0x80000000))==0:
            data = float(data)
            return data/pow(10,index)
        else:
            data = data%0x80000000
            data = data - 0x80000000
            data = float(data)
            return data/pow(10,index)


def main(args=None):
    rclpy.init(args=args)

    qos_profile_publisher = QoSProfile(depth=100)
    # Options  QoSDurabilityPolicy.VOLATILE, QoSDurabilityPolicy.TRANSIENT_LOCAL,
    qos_profile_publisher.durability = QoSDurabilityPolicy.VOLATILE
    qos_profile_publisher.deadline = Duration(seconds=1)
    # Options QoSLivelinessPolicy.MANUAL_BY_TOPIC, QoSLivelinessPolicy.AUTOMATIC
    qos_profile_publisher.liveliness = QoSLivelinessPolicy.AUTOMATIC
    qos_profile_publisher.reliability = QoSReliabilityPolicy.BEST_EFFORT

    node = force_sensor("force_senser","car01", qos_profile_publisher)
    # node.multi_read([1,2])
    rclpy.spin(node)
    rclpy.shutdown()