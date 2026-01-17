//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: motion_controller_cktest_types.h
//
// Code generated for Simulink model 'motion_controller_cktest'.
//
// Model version                  : 2.260
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sat Jul 12 16:44:08 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_motion_controller_cktest_types_h_
#define RTW_HEADER_motion_controller_cktest_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_builtin_interfaces_Time_
#define DEFINED_TYPEDEF_FOR_SL_Bus_builtin_interfaces_Time_

// MsgType=builtin_interfaces/Time
struct SL_Bus_builtin_interfaces_Time
{
  int32_T sec;
  uint32_T nanosec;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_
#define DEFINED_TYPEDEF_FOR_SL_Bus_ROSVariableLengthArrayInfo_

struct SL_Bus_ROSVariableLengthArrayInfo
{
  uint32_T CurrentLength;
  uint32_T ReceivedLength;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_std_msgs_Header_
#define DEFINED_TYPEDEF_FOR_SL_Bus_std_msgs_Header_

// MsgType=std_msgs/Header
struct SL_Bus_std_msgs_Header
{
  // MsgType=builtin_interfaces/Time
  SL_Bus_builtin_interfaces_Time stamp;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=frame_id_SL_Info:TruncateAction=warn 
  uint8_T frame_id[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=frame_id
  SL_Bus_ROSVariableLengthArrayInfo frame_id_SL_Info;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_custom_interfaces_Actuator_
#define DEFINED_TYPEDEF_FOR_SL_Bus_custom_interfaces_Actuator_

// MsgType=custom_interfaces/Actuator
struct SL_Bus_custom_interfaces_Actuator
{
  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=name_SL_Info:TruncateAction=warn 
  uint8_T name[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=name
  SL_Bus_ROSVariableLengthArrayInfo name_SL_Info;
  real_T position;
  real_T velocity;
  real_T effort;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_custom_interfaces_ActuatorCommand_
#define DEFINED_TYPEDEF_FOR_SL_Bus_custom_interfaces_ActuatorCommand_

// MsgType=custom_interfaces/ActuatorCommand
struct SL_Bus_custom_interfaces_ActuatorCommand
{
  // MsgType=std_msgs/Header
  SL_Bus_std_msgs_Header header;
  int32_T drive_mode;

  // MsgType=custom_interfaces/Actuator
  SL_Bus_custom_interfaces_Actuator actuator_command[4];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_sbus_interface_Sbus_
#define DEFINED_TYPEDEF_FOR_SL_Bus_sbus_interface_Sbus_

// MsgType=sbus_interface/Sbus
struct SL_Bus_sbus_interface_Sbus
{
  // MsgType=std_msgs/Header
  SL_Bus_std_msgs_Header header;
  int16_T raw_channels[16];
  int16_T mapped_channels[16];
  boolean_T failsafe;
  boolean_T frame_lost;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_custom_interfaces_ActuatorState_
#define DEFINED_TYPEDEF_FOR_SL_Bus_custom_interfaces_ActuatorState_

// MsgType=custom_interfaces/ActuatorState
struct SL_Bus_custom_interfaces_ActuatorState
{
  // MsgType=std_msgs/Header
  SL_Bus_std_msgs_Header header;

  // MsgType=custom_interfaces/Actuator:IsVarLen=1:VarLenCategory=data:VarLenElem=actuator_state_SL_Info:TruncateAction=warn 
  SL_Bus_custom_interfaces_Actuator actuator_state[16];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=actuator_state
  SL_Bus_ROSVariableLengthArrayInfo actuator_state_SL_Info;
};

#endif

#ifndef struct_f_robotics_slcore_internal_bl_T
#define struct_f_robotics_slcore_internal_bl_T

struct f_robotics_slcore_internal_bl_T
{
  int32_T __dummy;
};

#endif                                // struct_f_robotics_slcore_internal_bl_T

#ifndef struct_ros_slros2_internal_block_Cur_T
#define struct_ros_slros2_internal_block_Cur_T

struct ros_slros2_internal_block_Cur_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_robotics_slcore_internal_bl_T SampleTimeHandler;
};

#endif                                // struct_ros_slros2_internal_block_Cur_T

// Custom Type definition for MATLABSystem: '<S23>/SourceBlock'
#include "rmw/qos_profiles.h"
#ifndef struct_ros_slros2_internal_block_Pub_T
#define struct_ros_slros2_internal_block_Pub_T

struct ros_slros2_internal_block_Pub_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slros2_internal_block_Pub_T

#ifndef struct_ros_slros2_internal_block_Sub_T
#define struct_ros_slros2_internal_block_Sub_T

struct ros_slros2_internal_block_Sub_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slros2_internal_block_Sub_T

#ifndef struct_ros_slros2_internal_block_Get_T
#define struct_ros_slros2_internal_block_Get_T

struct ros_slros2_internal_block_Get_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_robotics_slcore_internal_bl_T SampleTimeHandler;
};

#endif                                // struct_ros_slros2_internal_block_Get_T

// Parameters for system: '<S2>/For Each Subsystem'
typedef struct P_CoreSubsys_motion_controlle_T_ P_CoreSubsys_motion_controlle_T;

// Parameters for system: '<S2>/For Each Subsystem1'
typedef struct P_CoreSubsys_motion_control_g_T_ P_CoreSubsys_motion_control_g_T;

// Parameters (default storage)
typedef struct P_motion_controller_cktest_T_ P_motion_controller_cktest_T;

// Forward declaration for rtModel
typedef struct tag_RTM_motion_controller_ckt_T RT_MODEL_motion_controller_ck_T;

#endif                          // RTW_HEADER_motion_controller_cktest_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
