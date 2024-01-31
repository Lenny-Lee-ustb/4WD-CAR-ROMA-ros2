#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include "rclcpp/rclcpp.hpp"
#include <builtin_interfaces/msg/time.hpp>
#include <custom_interfaces/msg/actuator.hpp>
#include <custom_interfaces/msg/actuator_command.hpp>
#include <sbus_interface/msg/sbus.hpp>
#include <std_msgs/msg/header.hpp>
#include "motion_controller_acc_and_brk_types.h"
#include "slros_msgconvert_utils.h"


void convertFromBus(builtin_interfaces::msg::Time& msgPtr, SL_Bus_builtin_interfaces_Time const* busPtr);
void convertToBus(SL_Bus_builtin_interfaces_Time* busPtr, const builtin_interfaces::msg::Time& msgPtr);

void convertFromBus(custom_interfaces::msg::Actuator& msgPtr, SL_Bus_custom_interfaces_Actuator const* busPtr);
void convertToBus(SL_Bus_custom_interfaces_Actuator* busPtr, const custom_interfaces::msg::Actuator& msgPtr);

void convertFromBus(custom_interfaces::msg::ActuatorCommand& msgPtr, SL_Bus_custom_interfaces_ActuatorCommand const* busPtr);
void convertToBus(SL_Bus_custom_interfaces_ActuatorCommand* busPtr, const custom_interfaces::msg::ActuatorCommand& msgPtr);

void convertFromBus(sbus_interface::msg::Sbus& msgPtr, SL_Bus_sbus_interface_Sbus const* busPtr);
void convertToBus(SL_Bus_sbus_interface_Sbus* busPtr, const sbus_interface::msg::Sbus& msgPtr);

void convertFromBus(std_msgs::msg::Header& msgPtr, SL_Bus_std_msgs_Header const* busPtr);
void convertToBus(SL_Bus_std_msgs_Header* busPtr, const std_msgs::msg::Header& msgPtr);


#endif
