import os
from launch import LaunchDescription
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource

def generate_launch_description():
    ld = LaunchDescription()

    config = os.path.abspath(os.path.join(
        get_package_share_directory('motion_controller_withtd3'), 
        os.pardir, os.pardir, os.pardir, os.pardir, 
        'src/motion_controller_cpp/',
        'config',
        'TD3controller.yaml'))
    
    # mpccontroller =Node(
    #     package="motion_controller_withtd3",
    #     executable="motion_controller_withTD3",
    #     parameters=[config]
    # )
        
    mpccontroller =Node(
        package="agent2",
        executable="agent2",
        parameters=[config]
    )


    # config = os.path.join(
    #     get_package_share_directory('realsense2_camera'),
    #     'launch',
    # )
    # camera = IncludeLaunchDescription(
    #         # PythonLaunchDescriptionSource([config, '/rs_launch_test_launch.py'])
    #     PythonLaunchDescriptionSource([config, '/rs_launch.py'])
    #     )

    ld.add_action(mpccontroller)
    # ld.add_entity(camera)

    return ld