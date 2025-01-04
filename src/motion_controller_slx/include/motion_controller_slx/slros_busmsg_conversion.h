#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include "rclcpp/rclcpp.hpp"
#include <builtin_interfaces/msg/time.hpp>
#include <custom_interfaces/msg/actuator.hpp>
#include <custom_interfaces/msg/actuator_command.hpp>
#include <custom_interfaces/msg/actuator_state.hpp>
#include <geometry_msgs/msg/point.hpp>
#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/pose_with_covariance.hpp>
#include <geometry_msgs/msg/quaternion.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <geometry_msgs/msg/twist_with_covariance.hpp>
#include <geometry_msgs/msg/vector3.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <sbus_interface/msg/sbus.hpp>
#include <sensor_msgs/msg/imu.hpp>
#include <std_msgs/msg/header.hpp>
#include "motion_controller_slx_types.h"
#include "slros_msgconvert_utils.h"


void convertFromBus(builtin_interfaces::msg::Time& msgPtr, SL_Bus_builtin_interfaces_Time const* busPtr);
void convertToBus(SL_Bus_builtin_interfaces_Time* busPtr, const builtin_interfaces::msg::Time& msgPtr);

void convertFromBus(custom_interfaces::msg::Actuator& msgPtr, SL_Bus_custom_interfaces_Actuator const* busPtr);
void convertToBus(SL_Bus_custom_interfaces_Actuator* busPtr, const custom_interfaces::msg::Actuator& msgPtr);

void convertFromBus(custom_interfaces::msg::ActuatorCommand& msgPtr, SL_Bus_custom_interfaces_ActuatorCommand const* busPtr);
void convertToBus(SL_Bus_custom_interfaces_ActuatorCommand* busPtr, const custom_interfaces::msg::ActuatorCommand& msgPtr);

void convertFromBus(custom_interfaces::msg::ActuatorState& msgPtr, SL_Bus_custom_interfaces_ActuatorState const* busPtr);
void convertToBus(SL_Bus_custom_interfaces_ActuatorState* busPtr, const custom_interfaces::msg::ActuatorState& msgPtr);

void convertFromBus(geometry_msgs::msg::Point& msgPtr, SL_Bus_geometry_msgs_Point const* busPtr);
void convertToBus(SL_Bus_geometry_msgs_Point* busPtr, const geometry_msgs::msg::Point& msgPtr);

void convertFromBus(geometry_msgs::msg::Pose& msgPtr, SL_Bus_geometry_msgs_Pose const* busPtr);
void convertToBus(SL_Bus_geometry_msgs_Pose* busPtr, const geometry_msgs::msg::Pose& msgPtr);

void convertFromBus(geometry_msgs::msg::PoseWithCovariance& msgPtr, SL_Bus_geometry_msgs_PoseWithCovariance const* busPtr);
void convertToBus(SL_Bus_geometry_msgs_PoseWithCovariance* busPtr, const geometry_msgs::msg::PoseWithCovariance& msgPtr);

void convertFromBus(geometry_msgs::msg::Quaternion& msgPtr, SL_Bus_geometry_msgs_Quaternion const* busPtr);
void convertToBus(SL_Bus_geometry_msgs_Quaternion* busPtr, const geometry_msgs::msg::Quaternion& msgPtr);

void convertFromBus(geometry_msgs::msg::Twist& msgPtr, SL_Bus_geometry_msgs_Twist const* busPtr);
void convertToBus(SL_Bus_geometry_msgs_Twist* busPtr, const geometry_msgs::msg::Twist& msgPtr);

void convertFromBus(geometry_msgs::msg::TwistWithCovariance& msgPtr, SL_Bus_geometry_msgs_TwistWithCovariance const* busPtr);
void convertToBus(SL_Bus_geometry_msgs_TwistWithCovariance* busPtr, const geometry_msgs::msg::TwistWithCovariance& msgPtr);

void convertFromBus(geometry_msgs::msg::Vector3& msgPtr, SL_Bus_geometry_msgs_Vector3 const* busPtr);
void convertToBus(SL_Bus_geometry_msgs_Vector3* busPtr, const geometry_msgs::msg::Vector3& msgPtr);

void convertFromBus(nav_msgs::msg::Odometry& msgPtr, SL_Bus_nav_msgs_Odometry const* busPtr);
void convertToBus(SL_Bus_nav_msgs_Odometry* busPtr, const nav_msgs::msg::Odometry& msgPtr);

void convertFromBus(sbus_interface::msg::Sbus& msgPtr, SL_Bus_sbus_interface_Sbus const* busPtr);
void convertToBus(SL_Bus_sbus_interface_Sbus* busPtr, const sbus_interface::msg::Sbus& msgPtr);

void convertFromBus(sensor_msgs::msg::Imu& msgPtr, SL_Bus_sensor_msgs_Imu const* busPtr);
void convertToBus(SL_Bus_sensor_msgs_Imu* busPtr, const sensor_msgs::msg::Imu& msgPtr);

void convertFromBus(std_msgs::msg::Header& msgPtr, SL_Bus_std_msgs_Header const* busPtr);
void convertToBus(SL_Bus_std_msgs_Header* busPtr, const std_msgs::msg::Header& msgPtr);


#endif
