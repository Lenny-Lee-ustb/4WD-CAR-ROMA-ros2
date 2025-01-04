// Copyright 2022-2023 The MathWorks, Inc.
// Generated 28-Jun-2024 10:48:04
#include "slros2_initialize.h"
// td3_test1/cmd_pub/Publish
SimulinkPublisher<custom_interfaces::msg::ActuatorCommand,SL_Bus_custom_interfaces_ActuatorCommand> Pub_td3_test1_30;
// td3_test1/cmd_pub/Publish2
SimulinkPublisher<custom_interfaces::msg::ActuatorCommand,SL_Bus_custom_interfaces_ActuatorCommand> Pub_td3_test1_31;
// td3_test1/Subsystem/Subscribe
SimulinkSubscriber<nav_msgs::msg::Odometry,SL_Bus_nav_msgs_Odometry> Sub_td3_test1_124;
// td3_test1/Subsystem/Subscribe1
SimulinkSubscriber<sensor_msgs::msg::Imu,SL_Bus_sensor_msgs_Imu> Sub_td3_test1_149;
// td3_test1/Subsystem/Subscribe2
SimulinkSubscriber<custom_interfaces::msg::ActuatorState,SL_Bus_custom_interfaces_ActuatorState> Sub_td3_test1_167;
// td3_test1/sbus/Subscribe
SimulinkSubscriber<sbus_interface::msg::Sbus,SL_Bus_sbus_interface_Sbus> Sub_td3_test1_91;
// For Block td3_test1/Get Parameter
SimulinkParameterGetter<real64_T,double> ParamGet_td3_test1_231;
