// Copyright 2022-2023 The MathWorks, Inc.
// Generated 28-Jun-2024 10:48:04
#ifndef _SLROS2_INITIALIZE_H_
#define _SLROS2_INITIALIZE_H_
#include "td3_test1_types.h"
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
// td3_test1/cmd_pub/Publish
extern SimulinkPublisher<custom_interfaces::msg::ActuatorCommand,SL_Bus_custom_interfaces_ActuatorCommand> Pub_td3_test1_30;
// td3_test1/cmd_pub/Publish2
extern SimulinkPublisher<custom_interfaces::msg::ActuatorCommand,SL_Bus_custom_interfaces_ActuatorCommand> Pub_td3_test1_31;
// td3_test1/Subsystem/Subscribe
extern SimulinkSubscriber<nav_msgs::msg::Odometry,SL_Bus_nav_msgs_Odometry> Sub_td3_test1_124;
// td3_test1/Subsystem/Subscribe1
extern SimulinkSubscriber<sensor_msgs::msg::Imu,SL_Bus_sensor_msgs_Imu> Sub_td3_test1_149;
// td3_test1/Subsystem/Subscribe2
extern SimulinkSubscriber<custom_interfaces::msg::ActuatorState,SL_Bus_custom_interfaces_ActuatorState> Sub_td3_test1_167;
// td3_test1/sbus/Subscribe
extern SimulinkSubscriber<sbus_interface::msg::Sbus,SL_Bus_sbus_interface_Sbus> Sub_td3_test1_91;
// For Block td3_test1/Get Parameter
extern SimulinkParameterGetter<real64_T,double> ParamGet_td3_test1_231;
#endif
