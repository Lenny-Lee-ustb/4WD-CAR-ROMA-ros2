// Copyright 2022 The MathWorks, Inc.
// Generated 03-Sep-2023 12:16:57
#ifndef _SLROS2_INITIALIZE_H_
#define _SLROS2_INITIALIZE_H_
#include "wheel_odometry_types.h"
// Generic pub-sub header
#include "slros2_generic_pubsub.h"
// Generic service header
#include "slros2_generic_service.h"
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
// wheel_odometry/Publish
extern SimulinkPublisher<nav_msgs::msg::Odometry,SL_Bus_nav_msgs_Odometry> Pub_wheel_odometry_253;
// wheel_odometry/Subscribe
extern SimulinkSubscriber<geometry_msgs::msg::PolygonStamped,SL_Bus_geometry_msgs_PolygonStamped> Sub_wheel_odometry_89;
// wheel_odometry/Subscribe1
extern SimulinkSubscriber<geometry_msgs::msg::PolygonStamped,SL_Bus_geometry_msgs_PolygonStamped> Sub_wheel_odometry_163;
// wheel_odometry/Subscribe2
extern SimulinkSubscriber<sensor_msgs::msg::Imu,SL_Bus_sensor_msgs_Imu> Sub_wheel_odometry_193;
// For Block wheel_odometry/Get Parameter
extern SimulinkParameterGetter<real64_T,double> ParamGet_wheel_odometry_353;
#endif
