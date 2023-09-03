import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    config = os.path.join(
        get_package_share_directory('wheel_odometry'),
        'config',
        'wheel_odometry.yaml'
    )

    return LaunchDescription([
        Node(
            package="wheel_odometry",
            executable="wheel_odometry",
            name="wheel_odometry_node",
            output="screen",
            emulate_tty=True,
            parameters=[config]
        )
    ])
