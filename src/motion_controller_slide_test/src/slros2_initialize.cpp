// Copyright 2022-2023 The MathWorks, Inc.
// Generated 23-Nov-2023 10:42:10
#include "slros2_initialize.h"
// motion_controller_slide_test/cmd_pub/Publish
SimulinkPublisher<custom_interfaces::msg::ActuatorCommand,SL_Bus_custom_interfaces_ActuatorCommand> Pub_motion_controller_slide_test_4;
// motion_controller_slide_test/cmd_pub/Publish2
SimulinkPublisher<custom_interfaces::msg::ActuatorCommand,SL_Bus_custom_interfaces_ActuatorCommand> Pub_motion_controller_slide_test_148;
// motion_controller_slide_test/subscription/Subscribe
SimulinkSubscriber<sbus_interface::msg::Sbus,SL_Bus_sbus_interface_Sbus> Sub_motion_controller_slide_test_1;
// motion_controller_slide_test/subscription/Subscribe2
SimulinkSubscriber<nav_msgs::msg::Odometry,SL_Bus_nav_msgs_Odometry> Sub_motion_controller_slide_test_283;
// For Block motion_controller_slide_test/controller/Get Parameter
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_slide_test_291;
// For Block motion_controller_slide_test/controller/get_angle/Get Parameter
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_slide_test_193;
// For Block motion_controller_slide_test/controller/get_effort/Get Parameter
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_slide_test_202;
// For Block motion_controller_slide_test/controller/get_spd/Get Parameter
SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_slide_test_288;
