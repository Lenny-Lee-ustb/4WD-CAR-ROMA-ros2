// Copyright 2022-2023 The MathWorks, Inc.
// Generated 04-Apr-2025 17:42:03
#ifndef _SLROS2_INITIALIZE_H_
#define _SLROS2_INITIALIZE_H_
#include "motion_controller_withTD3_types.h"
// Generic pub-sub header
#include "slros2_generic_pubsub.h"
// Generic service header
#include "slros2_generic_service.h"
#include "slros2_time.h"
#include "slros2_generic_param.h"
extern rclcpp::Node::SharedPtr SLROSNodePtr;
#ifndef SET_QOS_VALUES
#define SET_QOS_VALUES(qosStruct, hist, dep, dur, rel)  \
    {                                                   \
        qosStruct.history = hist;                       \
        qosStruct.depth = dep;                          \
        qosStruct.durability = dur;                     \
        qosStruct.reliability = rel;                    \
    }
#endif
inline rclcpp::QoS getQOSSettingsFromRMW(const rmw_qos_profile_t& qosProfile) {
    rclcpp::QoS qos(rclcpp::QoSInitialization::from_rmw(qosProfile));
    if (RMW_QOS_POLICY_DURABILITY_TRANSIENT_LOCAL == qosProfile.durability) {
        qos.transient_local();
    } else {
        qos.durability_volatile();
    }
    if (RMW_QOS_POLICY_RELIABILITY_RELIABLE == qosProfile.reliability) {
        qos.reliable();
    } else {
        qos.best_effort();
    }
    return qos;
}
// motion_controller_withTD3/StateFlow/Publish2
extern SimulinkPublisher<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Pub_motion_controller_withTD3_545;
// motion_controller_withTD3/StateFlow1/Publish2
extern SimulinkPublisher<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Pub_motion_controller_withTD3_1012;
// motion_controller_withTD3/StateFlow5/Publish2
extern SimulinkPublisher<sensor_msgs::msg::Imu,SL_Bus_sensor_msgs_Imu> Pub_motion_controller_withTD3_932;
// motion_controller_withTD3/cmd_pub/Publish
extern SimulinkPublisher<custom_interfaces::msg::ActuatorCommand,SL_Bus_custom_interfaces_ActuatorCommand> Pub_motion_controller_withTD3_4;
// motion_controller_withTD3/cmd_pub/Publish2
extern SimulinkPublisher<custom_interfaces::msg::ActuatorCommand,SL_Bus_custom_interfaces_ActuatorCommand> Pub_motion_controller_withTD3_148;
// motion_controller_withTD3/Subsystem1/Subscribe
extern SimulinkSubscriber<nav_msgs::msg::Odometry,SL_Bus_nav_msgs_Odometry> Sub_motion_controller_withTD3_514;
// motion_controller_withTD3/Subsystem1/Subscribe1
extern SimulinkSubscriber<sensor_msgs::msg::Imu,SL_Bus_sensor_msgs_Imu> Sub_motion_controller_withTD3_515;
// motion_controller_withTD3/Subsystem1/Subscribe2
extern SimulinkSubscriber<custom_interfaces::msg::ActuatorState,SL_Bus_custom_interfaces_ActuatorState> Sub_motion_controller_withTD3_516;
// motion_controller_withTD3/subscription/Subscribe
extern SimulinkSubscriber<sbus_interface::msg::Sbus,SL_Bus_sbus_interface_Sbus> Sub_motion_controller_withTD3_1;
// motion_controller_withTD3/subscription/Subscribe1
extern SimulinkSubscriber<custom_interfaces::msg::ActuatorState,SL_Bus_custom_interfaces_ActuatorState> Sub_motion_controller_withTD3_238;
// For Block motion_controller_withTD3/Get Parameter18
extern SimulinkParameterGetter<boolean_T,bool> ParamGet_motion_controller_withTD3_940;
// For Block motion_controller_withTD3/Get Parameter19
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_924;
// For Block motion_controller_withTD3/Get Parameter20
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_941;
// For Block motion_controller_withTD3/Get Parameter21
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_942;
// For Block motion_controller_withTD3/Get Parameter22
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_943;
// For Block motion_controller_withTD3/Get Parameter6
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_907;
// For Block motion_controller_withTD3/Get Parameter7
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_605;
// For Block motion_controller_withTD3/Get Parameter8
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_606;
// For Block motion_controller_withTD3/Subsystem1/Get Parameter1
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_948;
// For Block motion_controller_withTD3/Subsystem1/Get Parameter22
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_946;
// For Block motion_controller_withTD3/Subsystem2/Get Parameter1
extern SimulinkParameterGetter<boolean_T,bool> ParamGet_motion_controller_withTD3_625;
// For Block motion_controller_withTD3/Subsystem2/Get Parameter2
extern SimulinkParameterGetter<boolean_T,bool> ParamGet_motion_controller_withTD3_629;
// For Block motion_controller_withTD3/Subsystem2/Get Parameter3
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_621;
// For Block motion_controller_withTD3/Subsystem5/Get Parameter20
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_916;
// For Block motion_controller_withTD3/controller/Get Parameter1
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_217;
// For Block motion_controller_withTD3/controller/Subsystem/Get Parameter
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_316;
// For Block motion_controller_withTD3/controller/Subsystem/Get Parameter1
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_317;
// For Block motion_controller_withTD3/controller/Subsystem/Get Parameter2
extern SimulinkParameterGetter<boolean_T,bool> ParamGet_motion_controller_withTD3_301;
// For Block motion_controller_withTD3/controller/Subsystem/Get Parameter3
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_194;
// For Block motion_controller_withTD3/controller/Subsystem/Get Parameter4
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_298;
// For Block motion_controller_withTD3/controller/Subsystem/Get Parameter5
extern SimulinkParameterGetter<boolean_T,bool> ParamGet_motion_controller_withTD3_329;
// For Block motion_controller_withTD3/controller/get_effort/Get Parameter
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_202;
// For Block motion_controller_withTD3/controller/get_effort/Get Parameter2
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_354;
// For Block motion_controller_withTD3/controller/get_effort/Get Parameter3
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_355;
// For Block motion_controller_withTD3/controller/get_effort/Get Parameter5
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withTD3_393;
#endif
