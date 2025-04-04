// Copyright 2022-2023 The MathWorks, Inc.
// Generated 09-Jan-2025 15:54:34
#ifndef _SLROS2_INITIALIZE_H_
#define _SLROS2_INITIALIZE_H_
#include "motion_controller_withPIC_types.h"
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
// motion_controller_withPIC/StateFlow/Publish2
extern SimulinkPublisher<geometry_msgs::msg::Twist,SL_Bus_geometry_msgs_Twist> Pub_motion_controller_withPIC_545;
// motion_controller_withPIC/StateFlow1/Publish2
extern SimulinkPublisher<sensor_msgs::msg::Imu,SL_Bus_sensor_msgs_Imu> Pub_motion_controller_withPIC_831;
// motion_controller_withPIC/StateFlow2/Publish2
extern SimulinkPublisher<sensor_msgs::msg::Imu,SL_Bus_sensor_msgs_Imu> Pub_motion_controller_withPIC_839;
// motion_controller_withPIC/StateFlow5/Publish2
extern SimulinkPublisher<sensor_msgs::msg::Imu,SL_Bus_sensor_msgs_Imu> Pub_motion_controller_withPIC_932;
// motion_controller_withPIC/cmd_pub/Publish
extern SimulinkPublisher<custom_interfaces::msg::ActuatorCommand,SL_Bus_custom_interfaces_ActuatorCommand> Pub_motion_controller_withPIC_4;
// motion_controller_withPIC/cmd_pub/Publish2
extern SimulinkPublisher<custom_interfaces::msg::ActuatorCommand,SL_Bus_custom_interfaces_ActuatorCommand> Pub_motion_controller_withPIC_148;
// motion_controller_withPIC/Subsystem1/Subscribe
extern SimulinkSubscriber<nav_msgs::msg::Odometry,SL_Bus_nav_msgs_Odometry> Sub_motion_controller_withPIC_514;
// motion_controller_withPIC/Subsystem1/Subscribe1
extern SimulinkSubscriber<sensor_msgs::msg::Imu,SL_Bus_sensor_msgs_Imu> Sub_motion_controller_withPIC_515;
// motion_controller_withPIC/Subsystem1/Subscribe2
extern SimulinkSubscriber<custom_interfaces::msg::ActuatorState,SL_Bus_custom_interfaces_ActuatorState> Sub_motion_controller_withPIC_516;
// motion_controller_withPIC/subscription/Subscribe
extern SimulinkSubscriber<sbus_interface::msg::Sbus,SL_Bus_sbus_interface_Sbus> Sub_motion_controller_withPIC_1;
// motion_controller_withPIC/subscription/Subscribe1
extern SimulinkSubscriber<custom_interfaces::msg::ActuatorState,SL_Bus_custom_interfaces_ActuatorState> Sub_motion_controller_withPIC_238;
// For Block motion_controller_withPIC/Get Parameter
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_557;
// For Block motion_controller_withPIC/Get Parameter1
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_558;
// For Block motion_controller_withPIC/Get Parameter10
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_615;
// For Block motion_controller_withPIC/Get Parameter11
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_616;
// For Block motion_controller_withPIC/Get Parameter12
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_617;
// For Block motion_controller_withPIC/Get Parameter13
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_618;
// For Block motion_controller_withPIC/Get Parameter14
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_619;
// For Block motion_controller_withPIC/Get Parameter15
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_631;
// For Block motion_controller_withPIC/Get Parameter16
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_632;
// For Block motion_controller_withPIC/Get Parameter17
extern SimulinkParameterGetter<boolean_T,bool> ParamGet_motion_controller_withPIC_910;
// For Block motion_controller_withPIC/Get Parameter18
extern SimulinkParameterGetter<boolean_T,bool> ParamGet_motion_controller_withPIC_940;
// For Block motion_controller_withPIC/Get Parameter19
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_924;
// For Block motion_controller_withPIC/Get Parameter2
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_559;
// For Block motion_controller_withPIC/Get Parameter20
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_941;
// For Block motion_controller_withPIC/Get Parameter21
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_942;
// For Block motion_controller_withPIC/Get Parameter22
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_943;
// For Block motion_controller_withPIC/Get Parameter3
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_560;
// For Block motion_controller_withPIC/Get Parameter4
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_561;
// For Block motion_controller_withPIC/Get Parameter5
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_562;
// For Block motion_controller_withPIC/Get Parameter6
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_907;
// For Block motion_controller_withPIC/Get Parameter7
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_605;
// For Block motion_controller_withPIC/Get Parameter8
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_606;
// For Block motion_controller_withPIC/Get Parameter9
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_614;
// For Block motion_controller_withPIC/Subsystem1/Get Parameter1
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_948;
// For Block motion_controller_withPIC/Subsystem1/Get Parameter22
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_946;
// For Block motion_controller_withPIC/Subsystem2/Get Parameter1
extern SimulinkParameterGetter<boolean_T,bool> ParamGet_motion_controller_withPIC_625;
// For Block motion_controller_withPIC/Subsystem2/Get Parameter2
extern SimulinkParameterGetter<boolean_T,bool> ParamGet_motion_controller_withPIC_629;
// For Block motion_controller_withPIC/Subsystem2/Get Parameter3
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_621;
// For Block motion_controller_withPIC/Subsystem5/Get Parameter20
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_916;
// For Block motion_controller_withPIC/controller/Get Parameter1
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_217;
// For Block motion_controller_withPIC/controller/Subsystem/Get Parameter
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_316;
// For Block motion_controller_withPIC/controller/Subsystem/Get Parameter1
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_317;
// For Block motion_controller_withPIC/controller/Subsystem/Get Parameter2
extern SimulinkParameterGetter<boolean_T,bool> ParamGet_motion_controller_withPIC_301;
// For Block motion_controller_withPIC/controller/Subsystem/Get Parameter3
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_194;
// For Block motion_controller_withPIC/controller/Subsystem/Get Parameter4
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_298;
// For Block motion_controller_withPIC/controller/Subsystem/Get Parameter5
extern SimulinkParameterGetter<boolean_T,bool> ParamGet_motion_controller_withPIC_329;
// For Block motion_controller_withPIC/controller/get_effort/Get Parameter
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_202;
// For Block motion_controller_withPIC/controller/get_effort/Get Parameter2
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_354;
// For Block motion_controller_withPIC/controller/get_effort/Get Parameter3
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_355;
// For Block motion_controller_withPIC/controller/get_effort/Get Parameter5
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_393;
// For Block motion_controller_withPIC/picController/Get Parameter
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_637;
// For Block motion_controller_withPIC/picController/Get Parameter1
extern SimulinkParameterGetter<boolean_T,bool> ParamGet_motion_controller_withPIC_709;
// For Block motion_controller_withPIC/picController/Get Parameter2
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_944;
// For Block motion_controller_withPIC/picController/Get Parameter6
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_withPIC_556;
#endif
