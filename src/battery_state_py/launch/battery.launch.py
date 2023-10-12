import os
from launch import LaunchDescription
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    battery_node = Node(
            package='battery_state_py',
            executable='talker',
            name='battery_state_node',
            output='screen'
    )

    ld.add_action(battery_node)

    return ld