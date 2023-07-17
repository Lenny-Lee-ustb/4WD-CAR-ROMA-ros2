from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()
    motion_controller_node = Node(
        package="motion_controller_cpp",
        executable="motion_controller",
        parameters=[
            {"example":100}
        ]
    )

    servo_485_node = Node(
        package="servo_rs485_py",
        executable="servo_rs485"
    )
    
    motor_can_node = Node(
        package="motor_can_cpp",
        executable="motor_can"
    )

    ld.add_action(motion_controller_node)
    ld.add_action(servo_485_node)
    ld.add_action(motor_can_node)

    return ld