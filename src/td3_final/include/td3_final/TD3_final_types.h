//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: TD3_final_types.h
//
// Code generated for Simulink model 'TD3_final'.
//
// Model version                  : 1.8
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Fri Jun 21 14:28:05 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_TD3_final_types_h_
#define RTW_HEADER_TD3_final_types_h_
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

// Custom Type definition for MATLAB Function: '<S4>/PolicyWrapper'
#ifndef struct_dlarray_1_TD3_final_T
#define struct_dlarray_1_TD3_final_T

struct dlarray_1_TD3_final_T
{
  real32_T Data[2];
};

#endif                                 // struct_dlarray_1_TD3_final_T

// Custom Type definition for MATLABSystem: '<S5>/SinkBlock'
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

// Custom Type definition for MATLAB Function: '<S4>/PolicyWrapper'
#ifndef struct_cell_wrap_2_TD3_final_T
#define struct_cell_wrap_2_TD3_final_T

struct cell_wrap_2_TD3_final_T
{
  real_T f1[2];
};

#endif                                 // struct_cell_wrap_2_TD3_final_T

#ifndef struct_c_coder_internal_ctarget_dlne_T
#define struct_c_coder_internal_ctarget_dlne_T

struct c_coder_internal_ctarget_dlne_T
{
  boolean_T matlabCodegenIsDeleted;
  boolean_T IsNetworkInitialized;
};

#endif                                // struct_c_coder_internal_ctarget_dlne_T

#ifndef struct_rl_codegen_model_DLNetworkMod_T
#define struct_rl_codegen_model_DLNetworkMod_T

struct rl_codegen_model_DLNetworkMod_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  c_coder_internal_ctarget_dlne_T *InternalNetwork_;
};

#endif                                // struct_rl_codegen_model_DLNetworkMod_T

#ifndef struct_c_rl_codegen_policy_internal__T
#define struct_c_rl_codegen_policy_internal__T

struct c_rl_codegen_policy_internal__T
{
  cell_wrap_2_TD3_final_T UpperLimits_;
  cell_wrap_2_TD3_final_T LowerLimits_;
};

#endif                                // struct_c_rl_codegen_policy_internal__T

#ifndef struct_c_rl_codegen_policy_rlDetermi_T
#define struct_c_rl_codegen_policy_rlDetermi_T

struct c_rl_codegen_policy_rlDetermi_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  rl_codegen_model_DLNetworkMod_T *Model_;
  c_rl_codegen_policy_internal__T ActionBounder_;
};

#endif                                // struct_c_rl_codegen_policy_rlDetermi_T

// Parameters for system: '<Root>/For Each Subsystem'
typedef struct P_CoreSubsys_TD3_final_T_ P_CoreSubsys_TD3_final_T;

// Parameters (default storage)
typedef struct P_TD3_final_T_ P_TD3_final_T;

// Forward declaration for rtModel
typedef struct tag_RTM_TD3_final_T RT_MODEL_TD3_final_T;

#endif                                 // RTW_HEADER_TD3_final_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
