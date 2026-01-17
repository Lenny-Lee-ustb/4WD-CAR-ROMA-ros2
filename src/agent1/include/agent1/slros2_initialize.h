// Copyright 2022-2023 The MathWorks, Inc.
// Generated 28-Apr-2025 16:19:43
#ifndef _SLROS2_INITIALIZE_H_
#define _SLROS2_INITIALIZE_H_
#include "agent1_types.h"
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
// agent1/StateFlow/Publish2
extern SimulinkPublisher<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Pub_agent1_545;
// agent1/StateFlow1/Publish2
extern SimulinkPublisher<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Pub_agent1_1012;
// agent1/StateFlow5/Publish2
extern SimulinkPublisher<sensor_msgs::msg::Imu,SL_Bus_sensor_msgs_Imu> Pub_agent1_932;
// agent1/cmd_pub/Publish
extern SimulinkPublisher<custom_interfaces::msg::ActuatorCommand,SL_Bus_custom_interfaces_ActuatorCommand> Pub_agent1_4;
// agent1/cmd_pub/Publish2
extern SimulinkPublisher<custom_interfaces::msg::ActuatorCommand,SL_Bus_custom_interfaces_ActuatorCommand> Pub_agent1_148;
// agent1/Subsystem1/Subscribe
extern SimulinkSubscriber<nav_msgs::msg::Odometry,SL_Bus_nav_msgs_Odometry> Sub_agent1_514;
// agent1/Subsystem1/Subscribe1
extern SimulinkSubscriber<sensor_msgs::msg::Imu,SL_Bus_sensor_msgs_Imu> Sub_agent1_515;
// agent1/Subsystem1/Subscribe2
extern SimulinkSubscriber<custom_interfaces::msg::ActuatorState,SL_Bus_custom_interfaces_ActuatorState> Sub_agent1_516;
// agent1/subscription/Subscribe
extern SimulinkSubscriber<sbus_interface::msg::Sbus,SL_Bus_sbus_interface_Sbus> Sub_agent1_1;
// agent1/subscription/Subscribe1
extern SimulinkSubscriber<custom_interfaces::msg::ActuatorState,SL_Bus_custom_interfaces_ActuatorState> Sub_agent1_238;
// For Block agent1/Get Parameter1
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_1028;
// For Block agent1/Get Parameter18
extern SimulinkParameterGetter<boolean_T,bool> ParamGet_agent1_940;
// For Block agent1/Get Parameter19
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_924;
// For Block agent1/Get Parameter20
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_941;
// For Block agent1/Get Parameter21
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_942;
// For Block agent1/Get Parameter22
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_943;
// For Block agent1/Get Parameter6
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_907;
// For Block agent1/Get Parameter7
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_605;
// For Block agent1/Get Parameter8
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_606;
// For Block agent1/Subsystem1/Get Parameter1
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_948;
// For Block agent1/Subsystem1/Get Parameter2
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_1030;
// For Block agent1/Subsystem1/Get Parameter22
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_946;
// For Block agent1/Subsystem1/Get Parameter3
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_1031;
// For Block agent1/Subsystem1/Get Parameter4
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_1032;
// For Block agent1/Subsystem1/Get Parameter5
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_1033;
// For Block agent1/Subsystem1/Get Parameter6
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_1034;
// For Block agent1/Subsystem1/Get Parameter7
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_1035;
// For Block agent1/Subsystem2/Get Parameter1
extern SimulinkParameterGetter<boolean_T,bool> ParamGet_agent1_625;
// For Block agent1/Subsystem2/Get Parameter2
extern SimulinkParameterGetter<boolean_T,bool> ParamGet_agent1_629;
// For Block agent1/Subsystem2/Get Parameter3
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_621;
// For Block agent1/Subsystem2/Get Parameter4
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_1037;
// For Block agent1/Subsystem5/Get Parameter20
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_916;
// For Block agent1/controller/Get Parameter1
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_217;
// For Block agent1/controller/Subsystem/Get Parameter
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_316;
// For Block agent1/controller/Subsystem/Get Parameter1
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_317;
// For Block agent1/controller/Subsystem/Get Parameter2
extern SimulinkParameterGetter<boolean_T,bool> ParamGet_agent1_301;
// For Block agent1/controller/Subsystem/Get Parameter4
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_298;
// For Block agent1/controller/Subsystem/Get Parameter5
extern SimulinkParameterGetter<boolean_T,bool> ParamGet_agent1_329;
// For Block agent1/controller/get_effort/Get Parameter
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_202;
// For Block agent1/controller/get_effort/Get Parameter2
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_354;
// For Block agent1/controller/get_effort/Get Parameter3
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_355;
// For Block agent1/controller/get_effort/Get Parameter5
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_393;
// For Block agent1/controller/get_spd/Get Parameter3
extern SimulinkParameterGetter<real64_T,double> ParamGet_agent1_194;
#endif
