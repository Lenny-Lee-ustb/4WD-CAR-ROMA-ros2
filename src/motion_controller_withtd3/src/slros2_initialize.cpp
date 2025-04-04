// Copyright 2022-2023 The MathWorks, Inc.
// Generated 04-Apr-2025 17:42:03
#include "slros2_initialize.h"
// motion_controller_withTD3/StateFlow/Publish2
SimulinkPublisher<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Pub_motion_controller_withTD3_545;
// motion_controller_withTD3/StateFlow1/Publish2
SimulinkPublisher<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Pub_motion_controller_withTD3_1012;
// motion_controller_withTD3/StateFlow5/Publish2
SimulinkPublisher<sensor_msgs::msg::Imu,SL_Bus_sensor_msgs_Imu> Pub_motion_controller_withTD3_932;
// motion_controller_withTD3/cmd_pub/Publish
SimulinkPublisher<custom_interfaces::msg::ActuatorCommand,SL_Bus_custom_interfaces_ActuatorCommand> Pub_motion_controller_withTD3_4;
// motion_controller_withTD3/cmd_pub/Publish2
SimulinkPublisher<custom_interfaces::msg::ActuatorCommand,SL_Bus_custom_interfaces_ActuatorCommand> Pub_motion_controller_withTD3_148;
// motion_controller_withTD3/Subsystem1/Subscribe
SimulinkSubscriber<nav_msgs::msg::Odometry,SL_Bus_nav_msgs_Odometry> Sub_motion_controller_withTD3_514;
// motion_controller_withTD3/Subsystem1/Subscribe1
SimulinkSubscriber<sensor_msgs::msg::Imu,SL_Bus_sensor_msgs_Imu> Sub_motion_controller_withTD3_515;
// motion_controller_withTD3/Subsystem1/Subscribe2
SimulinkSubscriber<custom_interfaces::msg::ActuatorState,SL_Bus_custom_interfaces_ActuatorState> Sub_motion_controller_withTD3_516;
// motion_controller_withTD3/subscription/Subscribe
SimulinkSubscriber<sbus_interface::msg::Sbus,SL_Bus_sbus_interface_Sbus> Sub_motion_controller_withTD3_1;
// motion_controller_withTD3/subscription/Subscribe1
SimulinkSubscriber<custom_interfaces::msg::ActuatorState,SL_Bus_custom_interfaces_ActuatorState> Sub_motion_controller_withTD3_238;
// For Block motion_controller_withTD3/Get Parameter18
SimulinkParameterGetter<boolean_T,bool> ParamGet_motion_controller_withTD3_940;
// For Block motion_controller_withTD3/Get Parameter19
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_924;
// For Block motion_controller_withTD3/Get Parameter20
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_941;
// For Block motion_controller_withTD3/Get Parameter21
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_942;
// For Block motion_controller_withTD3/Get Parameter22
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_943;
// For Block motion_controller_withTD3/Get Parameter6
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_907;
// For Block motion_controller_withTD3/Get Parameter7
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_605;
// For Block motion_controller_withTD3/Get Parameter8
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_606;
// For Block motion_controller_withTD3/Subsystem1/Get Parameter1
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_948;
// For Block motion_controller_withTD3/Subsystem1/Get Parameter22
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_946;
// For Block motion_controller_withTD3/Subsystem2/Get Parameter1
SimulinkParameterGetter<boolean_T,bool> ParamGet_motion_controller_withTD3_625;
// For Block motion_controller_withTD3/Subsystem2/Get Parameter2
SimulinkParameterGetter<boolean_T,bool> ParamGet_motion_controller_withTD3_629;
// For Block motion_controller_withTD3/Subsystem2/Get Parameter3
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_621;
// For Block motion_controller_withTD3/Subsystem5/Get Parameter20
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_916;
// For Block motion_controller_withTD3/controller/Get Parameter1
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_217;
// For Block motion_controller_withTD3/controller/Subsystem/Get Parameter
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_316;
// For Block motion_controller_withTD3/controller/Subsystem/Get Parameter1
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_317;
// For Block motion_controller_withTD3/controller/Subsystem/Get Parameter2
SimulinkParameterGetter<boolean_T,bool> ParamGet_motion_controller_withTD3_301;
// For Block motion_controller_withTD3/controller/Subsystem/Get Parameter3
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_194;
// For Block motion_controller_withTD3/controller/Subsystem/Get Parameter4
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_298;
// For Block motion_controller_withTD3/controller/Subsystem/Get Parameter5
SimulinkParameterGetter<boolean_T,bool> ParamGet_motion_controller_withTD3_329;
// For Block motion_controller_withTD3/controller/get_effort/Get Parameter
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_202;
// For Block motion_controller_withTD3/controller/get_effort/Get Parameter2
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_354;
// For Block motion_controller_withTD3/controller/get_effort/Get Parameter3
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_355;
// For Block motion_controller_withTD3/controller/get_effort/Get Parameter5
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_393;
