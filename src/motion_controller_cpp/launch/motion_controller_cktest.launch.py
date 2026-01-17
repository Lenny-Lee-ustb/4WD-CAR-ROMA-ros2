import os
from launch import LaunchDescription
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    ld = LaunchDescription()

    config = os.path.abspath(os.path.join(
        get_package_share_directory('motion_controller_cktest'), 
        os.pardir, os.pardir, os.pardir, os.pardir, 
        'src/motion_controller_cpp/',
        'config',
        'motion_controller_cktest.yaml'))
    
    motion_controller_slide_test =Node(
        package="motion_controller_cktest",
        executable="motion_controller_cktest",
        parameters=[config]
    )


    ld.add_action(motion_controller_slide_test)
    # ld.add_entity(camera)

    return ld