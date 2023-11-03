import os
from launch import LaunchDescription
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    sbus_config = os.path.join(
        get_package_share_directory('motion_controller_cpp'),
        'config',
        'sbus_params.yaml'
    )
    sbus_bridge_node =Node(
        package="sbus_bridge",
        executable="sbus_bridge_node",
        name="sbus_bridge_node",
        output="screen",
        emulate_tty=True,
        parameters=[sbus_config]
    )

    # motion_controller_node = Node(
    #     package="motion_controller_cpp",
    #     executable="motion_controller",
    #     parameters=[
    #         {"speedMax":3.5},
    #         {"angleMax":0.75}
    #     ]
    # )
    # motion_controller_node = Node(
    #     package="motion_controller_node",
    #     executable="motion_controller_node",
    #     parameters=[
    #         {"spdMax":3.5},
    #         {"angleMax":0.6},
    #         {"effortMax":0.6},
    #         {"ackermann_enable":1.0}            
    #     ]
    # )

    servo_config = os.path.join(
        get_package_share_directory('motion_controller_cpp'),
        'config',
        'servo_params.yaml'
    )
    servo_485_node = Node(
        package="servo_rs485_py",
        executable="servo_rs485_node",
        name="servo_rs485_node",
        output="screen",
        parameters=[servo_config]
    )
    
    can_config = os.path.join(
        get_package_share_directory('motion_controller_cpp'),
        'config',
        'motor_params.yaml'
    )
    motor_can_node = Node(
        package="motor_can_cpp",
        executable="motor_can",
        name="motor_can_node",
        output="screen",
        parameters=[can_config]
    )

    imu_node = Node(
            package='ch040_imu_cpp',
            executable='imu_publisher',
            name='imu_pub_node',
            output='screen'
    )

    battery_node = Node(
            package='battery_state_py',
            executable='talker',
            name='battery_state_node',
            output='screen'

    
    )
    wheel_node = Node(
        package="wheel_remote_py",
        executable="wheel_publisher",
        output='screen'
    )

    ld.add_action(sbus_bridge_node)
    # ld.add_action(motion_controller_node)
    ld.add_action(servo_485_node)
    ld.add_action(motor_can_node)
    ld.add_action(imu_node)
    ld.add_action(battery_node)
    ld.add_action(wheel_node)

    return ld