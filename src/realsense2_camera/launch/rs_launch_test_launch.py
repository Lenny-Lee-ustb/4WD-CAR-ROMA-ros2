# License: Apache 2.0. See LICENSE file in root directory.
# Copyright(c) 2022 Intel Corporation. All Rights Reserved.


# DESCRIPTION #
# ----------- #
# Use this launch file to launch 2 devices.
# The Parameters available for definition in the command line for each camera are described in rs_launch.configurable_parameters
# For each device, the parameter name was changed to include an index.
# For example: to set camera_name for device1 set parameter camera_name1.
# command line example:
# ros2 launch realsense2_camera rs_multi_camera_launch.py camera_name1:=D400 device_type2:=l5. device_type1:=d4..

"""Launch realsense2_camera node."""
import copy
from launch import LaunchDescription
import launch_ros.actions
from launch.actions import IncludeLaunchDescription
from launch.substitutions import LaunchConfiguration, ThisLaunchFileDir
from launch.launch_description_sources import PythonLaunchDescriptionSource
from ament_index_python.packages import get_package_share_directory
import os
import sys
import pathlib
sys.path.append(str(pathlib.Path(__file__).parent.absolute()))
import rs_launch


odom_file = os.path.join(
        get_package_share_directory('realsense2_camera'),
        'config',
        'calibration_odometry.json'
    )
print("odom_config:",odom_file)
local_parameters = [{'name': 'enable_fisheye1', 'default': 'false', 'description': 'enable fisheye1 stream'},
                    {'name': 'enable_fisheye2', 'default': 'false', 'description': 'enable fisheye2 stream'},
                    {'name': 'calib_odom_file', 'default': odom_file, 'description': "''"},
                    {'name': 'topic_odom_in',   'default': '/wheel_odom', 'description': 'topic for T265 wheel odometry'},
                   ]
for param in local_parameters:
    if param['name'] == 'calib_odom_file':
        calib_odom_file_value = param['default']
        continue
    if param['name'] == 'topic_odom_in':
        topic_odom_in_value = param['default']
        break
print("check:", calib_odom_file_value)
print("check:", topic_odom_in_value)
default_params = copy.deepcopy(rs_launch.configurable_parameters)
                    

def set_configurable_parameters(local_params):
    return dict([(param['name'], LaunchConfiguration(param['name'])) for param in local_params])

def generate_launch_description():
    return LaunchDescription(
        rs_launch.declare_configurable_parameters(local_parameters)+
        rs_launch.declare_configurable_parameters(default_params)+
        [
        IncludeLaunchDescription(
            PythonLaunchDescriptionSource([ThisLaunchFileDir(), '/rs_launch.py']),
            launch_arguments=set_configurable_parameters(default_params).items(),
        ),
    ])
