import os
from launch import LaunchDescription
from ament_index_python.packages import get_package_share_directory
from launch_ros.actions import Node

def generate_launch_description():
    ld = LaunchDescription()

    # config = os.path.join(
    #     get_package_share_directory('motion_controller_circle_test'),
    #     os.pardir, os.pardir, os.pardir,'src/motion_controller_cpp/'
    #     'config',
    #     'motion_controller_circle_test.yaml'
    # )
    config = os.path.abspath(os.path.join(
        get_package_share_directory('motion_controller_circle_test'), 
        os.pardir, os.pardir, os.pardir, os.pardir, 
        'src/motion_controller_cpp/',
        'config',
        'motion_controller_circle_test.yaml'))

    motion_controller_circle_test =Node(
        package="motion_controller_circle_test",
        executable="motion_controller_circle_test",
        parameters=[config]
    )

    ld.add_action(motion_controller_circle_test)

    return ld