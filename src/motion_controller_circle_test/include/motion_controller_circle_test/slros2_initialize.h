// Copyright 2022-2023 The MathWorks, Inc.
// Generated 19-Dec-2023 21:19:56
#ifndef _SLROS2_INITIALIZE_H_
#define _SLROS2_INITIALIZE_H_
#include "motion_controller_circle_test_types.h"
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
// motion_controller_circle_test/cmd_pub/Publish
extern SimulinkPublisher<custom_interfaces::msg::ActuatorCommand,SL_Bus_custom_interfaces_ActuatorCommand> Pub_motion_controller_circle_test_4;
// motion_controller_circle_test/cmd_pub/Publish2
extern SimulinkPublisher<custom_interfaces::msg::ActuatorCommand,SL_Bus_custom_interfaces_ActuatorCommand> Pub_motion_controller_circle_test_148;
// motion_controller_circle_test/subscription/Subscribe
extern SimulinkSubscriber<sbus_interface::msg::Sbus,SL_Bus_sbus_interface_Sbus> Sub_motion_controller_circle_test_1;
// For Block motion_controller_circle_test/Subsystem/Get Parameter
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_circle_test_399;
// For Block motion_controller_circle_test/Subsystem/Get Parameter1
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_circle_test_400;
// For Block motion_controller_circle_test/Subsystem/Get Parameter3
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_circle_test_395;
// For Block motion_controller_circle_test/Subsystem/Get Parameter4
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_circle_test_396;
// For Block motion_controller_circle_test/controller/Get Parameter1
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_circle_test_363;
// For Block motion_controller_circle_test/controller/get_effort/Get Parameter
extern SimulinkParameterGetter<real64_T,double> ParamGet_motion_controller_circle_test_202;
#endif
