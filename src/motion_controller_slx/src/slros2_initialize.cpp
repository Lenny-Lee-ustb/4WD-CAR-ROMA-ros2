// Copyright 2022-2023 The MathWorks, Inc.
// Generated 03-Dec-2024 20:50:02
#include "slros2_initialize.h"
// motion_controller_slx/cmd_pub/Publish
SimulinkPublisher<custom_interfaces::msg::ActuatorCommand,SL_Bus_custom_interfaces_ActuatorCommand> Pub_motion_controller_slx_4;
// motion_controller_slx/cmd_pub/Publish2
SimulinkPublisher<custom_interfaces::msg::ActuatorCommand,SL_Bus_custom_interfaces_ActuatorCommand> Pub_motion_controller_slx_148;
// motion_controller_slx/Subsystem/Subscribe
SimulinkSubscriber<nav_msgs::msg::Odometry,SL_Bus_nav_msgs_Odometry> Sub_motion_controller_slx_368;
// motion_controller_slx/Subsystem/Subscribe1
SimulinkSubscriber<sensor_msgs::msg::Imu,SL_Bus_sensor_msgs_Imu> Sub_motion_controller_slx_369;
// motion_controller_slx/subscription/Subscribe
SimulinkSubscriber<sbus_interface::msg::Sbus,SL_Bus_sbus_interface_Sbus> Sub_motion_controller_slx_1;
// motion_controller_slx/subscription/Subscribe1
SimulinkSubscriber<custom_interfaces::msg::ActuatorState,SL_Bus_custom_interfaces_ActuatorState> Sub_motion_controller_slx_238;
// For Block motion_controller_slx/controller/Get Parameter1
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_slx_217;
// For Block motion_controller_slx/controller/Subsystem/Get Parameter
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_slx_316;
// For Block motion_controller_slx/controller/Subsystem/Get Parameter1
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_slx_317;
// For Block motion_controller_slx/controller/Subsystem/Get Parameter2
SimulinkParameterGetter<boolean_T,bool> ParamGet_motion_controller_slx_301;
// For Block motion_controller_slx/controller/Subsystem/Get Parameter3
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_slx_194;
// For Block motion_controller_slx/controller/Subsystem/Get Parameter4
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_slx_298;
// For Block motion_controller_slx/controller/Subsystem/Get Parameter5
SimulinkParameterGetter<boolean_T,bool> ParamGet_motion_controller_slx_329;
// For Block motion_controller_slx/controller/get_effort/Get Parameter
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_slx_202;
// For Block motion_controller_slx/controller/get_effort/Get Parameter1
SimulinkParameterGetter<boolean_T,bool> ParamGet_motion_controller_slx_353;
// For Block motion_controller_slx/controller/get_effort/Get Parameter2
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_slx_354;
// For Block motion_controller_slx/controller/get_effort/Get Parameter3
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_slx_355;
// For Block motion_controller_slx/controller/get_effort/Get Parameter4
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_slx_365;
// For Block motion_controller_slx/controller/get_effort/Get Parameter5
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_slx_393;
