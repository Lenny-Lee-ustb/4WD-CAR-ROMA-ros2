// Copyright 2022-2023 The MathWorks, Inc.
// Generated 22-Apr-2025 13:56:17
#include "slros2_initialize.h"
// agent5000/StateFlow/Publish2
SimulinkPublisher<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Pub_agent5000_545;
// agent5000/StateFlow1/Publish2
SimulinkPublisher<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Pub_agent5000_1012;
// agent5000/StateFlow5/Publish2
SimulinkPublisher<sensor_msgs::msg::Imu,SL_Bus_sensor_msgs_Imu> Pub_agent5000_932;
// agent5000/cmd_pub/Publish
SimulinkPublisher<custom_interfaces::msg::ActuatorCommand,SL_Bus_custom_interfaces_ActuatorCommand> Pub_agent5000_4;
// agent5000/cmd_pub/Publish2
SimulinkPublisher<custom_interfaces::msg::ActuatorCommand,SL_Bus_custom_interfaces_ActuatorCommand> Pub_agent5000_148;
// agent5000/Subsystem1/Subscribe
SimulinkSubscriber<nav_msgs::msg::Odometry,SL_Bus_nav_msgs_Odometry> Sub_agent5000_514;
// agent5000/Subsystem1/Subscribe1
SimulinkSubscriber<sensor_msgs::msg::Imu,SL_Bus_sensor_msgs_Imu> Sub_agent5000_515;
// agent5000/Subsystem1/Subscribe2
SimulinkSubscriber<custom_interfaces::msg::ActuatorState,SL_Bus_custom_interfaces_ActuatorState> Sub_agent5000_516;
// agent5000/subscription/Subscribe
SimulinkSubscriber<sbus_interface::msg::Sbus,SL_Bus_sbus_interface_Sbus> Sub_agent5000_1;
// agent5000/subscription/Subscribe1
SimulinkSubscriber<custom_interfaces::msg::ActuatorState,SL_Bus_custom_interfaces_ActuatorState> Sub_agent5000_238;
// For Block agent5000/Get Parameter1
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_1028;
// For Block agent5000/Get Parameter18
SimulinkParameterGetter<boolean_T,bool> ParamGet_agent5000_940;
// For Block agent5000/Get Parameter19
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_924;
// For Block agent5000/Get Parameter20
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_941;
// For Block agent5000/Get Parameter21
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_942;
// For Block agent5000/Get Parameter22
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_943;
// For Block agent5000/Get Parameter6
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_907;
// For Block agent5000/Get Parameter7
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_605;
// For Block agent5000/Get Parameter8
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_606;
// For Block agent5000/Subsystem1/Get Parameter1
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_948;
// For Block agent5000/Subsystem1/Get Parameter2
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_1030;
// For Block agent5000/Subsystem1/Get Parameter22
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_946;
// For Block agent5000/Subsystem1/Get Parameter3
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_1031;
// For Block agent5000/Subsystem1/Get Parameter4
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_1032;
// For Block agent5000/Subsystem1/Get Parameter5
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_1033;
// For Block agent5000/Subsystem1/Get Parameter6
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_1034;
// For Block agent5000/Subsystem1/Get Parameter7
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_1035;
// For Block agent5000/Subsystem2/Get Parameter1
SimulinkParameterGetter<boolean_T,bool> ParamGet_agent5000_625;
// For Block agent5000/Subsystem2/Get Parameter2
SimulinkParameterGetter<boolean_T,bool> ParamGet_agent5000_629;
// For Block agent5000/Subsystem2/Get Parameter3
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_621;
// For Block agent5000/Subsystem2/Get Parameter4
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_1037;
// For Block agent5000/Subsystem5/Get Parameter20
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_916;
// For Block agent5000/controller/Get Parameter1
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_217;
// For Block agent5000/controller/Subsystem/Get Parameter
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_316;
// For Block agent5000/controller/Subsystem/Get Parameter1
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_317;
// For Block agent5000/controller/Subsystem/Get Parameter2
SimulinkParameterGetter<boolean_T,bool> ParamGet_agent5000_301;
// For Block agent5000/controller/Subsystem/Get Parameter4
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_298;
// For Block agent5000/controller/Subsystem/Get Parameter5
SimulinkParameterGetter<boolean_T,bool> ParamGet_agent5000_329;
// For Block agent5000/controller/get_effort/Get Parameter
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_202;
// For Block agent5000/controller/get_effort/Get Parameter2
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_354;
// For Block agent5000/controller/get_effort/Get Parameter3
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_355;
// For Block agent5000/controller/get_effort/Get Parameter5
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_393;
// For Block agent5000/controller/get_spd/Get Parameter3
SimulinkParameterGetter<real64_T,double> ParamGet_agent5000_194;
