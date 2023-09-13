##launch file
from launch import LaunchDescription
import launch_ros.actions 

def generate_launch_description():
    return LaunchDescription([
        launch_ros.actions.Node(
            package='ch040_imu_cpp',
            executable='imu_publisher',
            output='screen'
            ),
        launch_ros.actions.Node(
            package='ch040_imu_cpp',
            executable='listener',
            output='screen'
            ),
        ])

