import rclpy
from std_msgs.msg import String
from std_msgs.msg import Float64MultiArray
from sensor_msgs.msg import BatteryState
from rclpy.node import Node

class Minimalsubscriber(Node):
    def listener_callback(self, msg):
        # self.get_logger().info('I heard: "%s"' % msg.data)
        self.get_logger().info('Get: \n Battery voltage: %.2f V; Battery temperature: %.2f C; Battery percentage: %d %%' % (msg.voltage, msg.temperature, msg.percentage))
    
    def __init__(self):
        super().__init__('minimal_subscriber')
        self.subscription = self.create_subscription(
            BatteryState, 'battery_state', self.listener_callback, 15
        )
        self.subscription

def main(args=None):
    rclpy.init(args=args)
    subscriber = Minimalsubscriber()
    rclpy.spin(subscriber)
    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object)
    subscriber.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()