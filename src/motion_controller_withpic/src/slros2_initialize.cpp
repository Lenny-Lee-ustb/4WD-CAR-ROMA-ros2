// Copyright 2022-2023 The MathWorks, Inc.
// Generated 04-Jan-2025 16:58:15
#include "slros2_initialize.h"
// motion_controller_withPIC/StateFlow/Publish2
SimulinkPublisher<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Pub_motion_controller_withPIC_545;
// motion_controller_withPIC/cmd_pub/Publish
SimulinkPublisher<custom_interfaces::msg::ActuatorCommand,SL_Bus_custom_interfaces_ActuatorCommand> Pub_motion_controller_withPIC_4;
// motion_controller_withPIC/cmd_pub/Publish2
SimulinkPublisher<custom_interfaces::msg::ActuatorCommand,SL_Bus_custom_interfaces_ActuatorCommand> Pub_motion_controller_withPIC_148;
// motion_controller_withPIC/Subsystem1/Subscribe
SimulinkSubscriber<nav_msgs::msg::Odometry,SL_Bus_nav_msgs_Odometry> Sub_motion_controller_withPIC_514;
// motion_controller_withPIC/Subsystem1/Subscribe1
SimulinkSubscriber<sensor_msgs::msg::Imu,SL_Bus_sensor_msgs_Imu> Sub_motion_controller_withPIC_515;
// motion_controller_withPIC/Subsystem1/Subscribe2
SimulinkSubscriber<custom_interfaces::msg::ActuatorState,SL_Bus_custom_interfaces_ActuatorState> Sub_motion_controller_withPIC_516;
// motion_controller_withPIC/subscription/Subscribe
SimulinkSubscriber<sbus_interface::msg::Sbus,SL_Bus_sbus_interface_Sbus> Sub_motion_controller_withPIC_1;
// motion_controller_withPIC/subscription/Subscribe1
SimulinkSubscriber<custom_interfaces::msg::ActuatorState,SL_Bus_custom_interfaces_ActuatorState> Sub_motion_controller_withPIC_238;
// For Block motion_controller_withPIC/Get Parameter
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_557;
// For Block motion_controller_withPIC/Get Parameter1
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_558;
// For Block motion_controller_withPIC/Get Parameter10
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_615;
// For Block motion_controller_withPIC/Get Parameter11
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_616;
// For Block motion_controller_withPIC/Get Parameter12
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_617;
// For Block motion_controller_withPIC/Get Parameter13
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_618;
// For Block motion_controller_withPIC/Get Parameter14
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_619;
// For Block motion_controller_withPIC/Get Parameter15
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_631;
// For Block motion_controller_withPIC/Get Parameter16
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_632;
// For Block motion_controller_withPIC/Get Parameter2
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_559;
// For Block motion_controller_withPIC/Get Parameter3
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_560;
// For Block motion_controller_withPIC/Get Parameter4
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_561;
// For Block motion_controller_withPIC/Get Parameter5
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_562;
// For Block motion_controller_withPIC/Get Parameter7
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_605;
// For Block motion_controller_withPIC/Get Parameter8
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_606;
// For Block motion_controller_withPIC/Get Parameter9
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_614;
// For Block motion_controller_withPIC/Subsystem2/Get Parameter1
SimulinkParameterGetter<boolean_T,bool> ParamGet_motion_controller_withPIC_625;
// For Block motion_controller_withPIC/Subsystem2/Get Parameter2
SimulinkParameterGetter<boolean_T,bool> ParamGet_motion_controller_withPIC_629;
// For Block motion_controller_withPIC/Subsystem2/Get Parameter3
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_621;
// For Block motion_controller_withPIC/controller/Get Parameter1
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_217;
// For Block motion_controller_withPIC/controller/Subsystem/Get Parameter
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_316;
// For Block motion_controller_withPIC/controller/Subsystem/Get Parameter1
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_317;
// For Block motion_controller_withPIC/controller/Subsystem/Get Parameter2
SimulinkParameterGetter<boolean_T,bool> ParamGet_motion_controller_withPIC_301;
// For Block motion_controller_withPIC/controller/Subsystem/Get Parameter3
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_194;
// For Block motion_controller_withPIC/controller/Subsystem/Get Parameter4
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_298;
// For Block motion_controller_withPIC/controller/Subsystem/Get Parameter5
SimulinkParameterGetter<boolean_T,bool> ParamGet_motion_controller_withPIC_329;
// For Block motion_controller_withPIC/controller/get_effort/Get Parameter
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_202;
// For Block motion_controller_withPIC/controller/get_effort/Get Parameter2
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_354;
// For Block motion_controller_withPIC/controller/get_effort/Get Parameter3
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_355;
// For Block motion_controller_withPIC/controller/get_effort/Get Parameter5
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_393;
// For Block motion_controller_withPIC/picController/Get Parameter
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_637;
// For Block motion_controller_withPIC/picController/Get Parameter1
SimulinkParameterGetter<boolean_T,bool> ParamGet_motion_controller_withPIC_709;
// For Block motion_controller_withPIC/picController/Get Parameter6
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_556;
