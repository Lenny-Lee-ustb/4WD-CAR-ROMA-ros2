// Copyright 2022-2023 The MathWorks, Inc.
// Generated 03-Nov-2023 10:19:53
#include "slros2_initialize.h"
// motion_controller_node/cmd_pub/Publish
SimulinkPublisher<custom_interfaces::msg::ActuatorCommand,SL_Bus_custom_interfaces_ActuatorCommand> Pub_motion_controller_node_4;
// motion_controller_node/cmd_pub/Publish2
SimulinkPublisher<custom_interfaces::msg::ActuatorCommand,SL_Bus_custom_interfaces_ActuatorCommand> Pub_motion_controller_node_148;
// motion_controller_node/subscription/Subscribe
SimulinkSubscriber<sbus_interface::msg::Sbus,SL_Bus_sbus_interface_Sbus> Sub_motion_controller_node_1;
// motion_controller_node/subscription/Subscribe1
SimulinkSubscriber<custom_interfaces::msg::ActuatorState,SL_Bus_custom_interfaces_ActuatorState> Sub_motion_controller_node_238;
// For Block motion_controller_node/controller/get_angle/Get Parameter
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_node_193;
// For Block motion_controller_node/controller/get_angle/Get Parameter1
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_node_213;
// For Block motion_controller_node/controller/get_effort/Get Parameter
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_node_202;
// For Block motion_controller_node/controller/get_spd/Get Parameter
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_node_194;
// For Block motion_controller_node/controller/get_spd/Get Parameter1
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_node_217;
