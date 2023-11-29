import os
from launch import LaunchDescription
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    ld = LaunchDescription()

    config = os.path.join(
        get_package_share_directory('motion_controller_slide_test'),
        'config',
        'params.yaml'
    )
    motion_controller_slide_test =Node(
        package="motion_controller_slide_test",
        executable="motion_controller_slide_test",
        parameters=[config]
    )


    config = os.path.join(
        get_package_share_directory('realsense2_camera'),
        'launch',
    )
    camera = IncludeLaunchDescription(
            PythonLaunchDescriptionSource([config, '/rs_launch_test_launch.py'])
        )

    ld.add_action(motion_controller_slide_test)
    print(config)
    ld.add_entity(camera)

    return ld