#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_builtin_interfaces_Time and builtin_interfaces::msg::Time

void convertFromBus(builtin_interfaces::msg::Time& msgPtr, SL_Bus_builtin_interfaces_Time const* busPtr)
{
  const std::string rosMessageType("builtin_interfaces/Time");

  msgPtr.nanosec =  busPtr->nanosec;
  msgPtr.sec =  busPtr->sec;
}

void convertToBus(SL_Bus_builtin_interfaces_Time* busPtr, const builtin_interfaces::msg::Time& msgPtr)
{
  const std::string rosMessageType("builtin_interfaces/Time");

  busPtr->nanosec =  msgPtr.nanosec;
  busPtr->sec =  msgPtr.sec;
}


// Conversions between SL_Bus_custom_interfaces_Actuator and custom_interfaces::msg::Actuator

void convertFromBus(custom_interfaces::msg::Actuator& msgPtr, SL_Bus_custom_interfaces_Actuator const* busPtr)
{
  const std::string rosMessageType("custom_interfaces/Actuator");

  msgPtr.effort =  busPtr->effort;
  convertFromBusVariablePrimitiveArray(msgPtr.name, busPtr->name, busPtr->name_SL_Info);
  msgPtr.position =  busPtr->position;
  msgPtr.velocity =  busPtr->velocity;
}

void convertToBus(SL_Bus_custom_interfaces_Actuator* busPtr, const custom_interfaces::msg::Actuator& msgPtr)
{
  const std::string rosMessageType("custom_interfaces/Actuator");

  busPtr->effort =  msgPtr.effort;
  convertToBusVariablePrimitiveArray(busPtr->name, busPtr->name_SL_Info, msgPtr.name, slros::EnabledWarning(rosMessageType, "name"));
  busPtr->position =  msgPtr.position;
  busPtr->velocity =  msgPtr.velocity;
}


// Conversions between SL_Bus_custom_interfaces_ActuatorCommand and custom_interfaces::msg::ActuatorCommand

void convertFromBus(custom_interfaces::msg::ActuatorCommand& msgPtr, SL_Bus_custom_interfaces_ActuatorCommand const* busPtr)
{
  const std::string rosMessageType("custom_interfaces/ActuatorCommand");

  convertFromBusFixedNestedArray(msgPtr.actuator_command, busPtr->actuator_command);
  msgPtr.drive_mode =  busPtr->drive_mode;
  convertFromBus(msgPtr.header, &busPtr->header);
}

void convertToBus(SL_Bus_custom_interfaces_ActuatorCommand* busPtr, const custom_interfaces::msg::ActuatorCommand& msgPtr)
{
  const std::string rosMessageType("custom_interfaces/ActuatorCommand");

  convertToBusFixedNestedArray(busPtr->actuator_command, msgPtr.actuator_command, slros::NoopWarning());
  busPtr->drive_mode =  msgPtr.drive_mode;
  convertToBus(&busPtr->header, msgPtr.header);
}


// Conversions between SL_Bus_sbus_interface_Sbus and sbus_interface::msg::Sbus

void convertFromBus(sbus_interface::msg::Sbus& msgPtr, SL_Bus_sbus_interface_Sbus const* busPtr)
{
  const std::string rosMessageType("sbus_interface/Sbus");

  msgPtr.failsafe =  busPtr->failsafe;
  msgPtr.frame_lost =  busPtr->frame_lost;
  convertFromBus(msgPtr.header, &busPtr->header);
  convertFromBusFixedPrimitiveArray(msgPtr.mapped_channels, busPtr->mapped_channels);
  convertFromBusFixedPrimitiveArray(msgPtr.raw_channels, busPtr->raw_channels);
}

void convertToBus(SL_Bus_sbus_interface_Sbus* busPtr, const sbus_interface::msg::Sbus& msgPtr)
{
  const std::string rosMessageType("sbus_interface/Sbus");

  busPtr->failsafe =  msgPtr.failsafe;
  busPtr->frame_lost =  msgPtr.frame_lost;
  convertToBus(&busPtr->header, msgPtr.header);
  convertToBusFixedPrimitiveArray(busPtr->mapped_channels, msgPtr.mapped_channels, slros::NoopWarning());
  convertToBusFixedPrimitiveArray(busPtr->raw_channels, msgPtr.raw_channels, slros::NoopWarning());
}


// Conversions between SL_Bus_std_msgs_Header and std_msgs::msg::Header

void convertFromBus(std_msgs::msg::Header& msgPtr, SL_Bus_std_msgs_Header const* busPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertFromBusVariablePrimitiveArray(msgPtr.frame_id, busPtr->frame_id, busPtr->frame_id_SL_Info);
  convertFromBus(msgPtr.stamp, &busPtr->stamp);
}

void convertToBus(SL_Bus_std_msgs_Header* busPtr, const std_msgs::msg::Header& msgPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertToBusVariablePrimitiveArray(busPtr->frame_id, busPtr->frame_id_SL_Info, msgPtr.frame_id, slros::EnabledWarning(rosMessageType, "frame_id"));
  convertToBus(&busPtr->stamp, msgPtr.stamp);
}

