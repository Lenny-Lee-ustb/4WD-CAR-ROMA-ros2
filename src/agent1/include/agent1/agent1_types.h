//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: agent1_types.h
//
// Code generated for Simulink model 'agent1'.
//
// Model version                  : 2.394
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Mon Apr 28 16:19:37 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_agent1_types_h_
#define RTW_HEADER_agent1_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
struct SL_Bus_geometry_msgs_Vector3
{
  real_T x;
  real_T y;
  real_T z;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
struct SL_Bus_geometry_msgs_Twist
{
  // MsgType=geometry_msgs/Vector3
  SL_Bus_geometry_msgs_Vector3 linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_geometry_msgs_Vector3 angular;
};

#endif

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

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Quaternion_
#define DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Quaternion_

// MsgType=geometry_msgs/Quaternion
struct SL_Bus_geometry_msgs_Quaternion
{
  real_T x;
  real_T y;
  real_T z;
  real_T w;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_sensor_msgs_Imu_
#define DEFINED_TYPEDEF_FOR_SL_Bus_sensor_msgs_Imu_

// MsgType=sensor_msgs/Imu
struct SL_Bus_sensor_msgs_Imu
{
  // MsgType=std_msgs/Header
  SL_Bus_std_msgs_Header header;

  // MsgType=geometry_msgs/Quaternion
  SL_Bus_geometry_msgs_Quaternion orientation;
  real_T orientation_covariance[9];

  // MsgType=geometry_msgs/Vector3
  SL_Bus_geometry_msgs_Vector3 angular_velocity;
  real_T angular_velocity_covariance[9];

  // MsgType=geometry_msgs/Vector3
  SL_Bus_geometry_msgs_Vector3 linear_acceleration;
  real_T linear_acceleration_covariance[9];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Point_
#define DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Point_

// MsgType=geometry_msgs/Point
struct SL_Bus_geometry_msgs_Point
{
  real_T x;
  real_T y;
  real_T z;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Pose_
#define DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_Pose_

// MsgType=geometry_msgs/Pose
struct SL_Bus_geometry_msgs_Pose
{
  // MsgType=geometry_msgs/Point
  SL_Bus_geometry_msgs_Point position;

  // MsgType=geometry_msgs/Quaternion
  SL_Bus_geometry_msgs_Quaternion orientation;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_PoseWithCovariance_
#define DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_PoseWithCovariance_

// MsgType=geometry_msgs/PoseWithCovariance
struct SL_Bus_geometry_msgs_PoseWithCovariance
{
  // MsgType=geometry_msgs/Pose
  SL_Bus_geometry_msgs_Pose pose;
  real_T covariance[36];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_TwistWithCovariance_
#define DEFINED_TYPEDEF_FOR_SL_Bus_geometry_msgs_TwistWithCovariance_

// MsgType=geometry_msgs/TwistWithCovariance
struct SL_Bus_geometry_msgs_TwistWithCovariance
{
  // MsgType=geometry_msgs/Twist
  SL_Bus_geometry_msgs_Twist twist;
  real_T covariance[36];
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_nav_msgs_Odometry_
#define DEFINED_TYPEDEF_FOR_SL_Bus_nav_msgs_Odometry_

// MsgType=nav_msgs/Odometry
struct SL_Bus_nav_msgs_Odometry
{
  // MsgType=std_msgs/Header
  SL_Bus_std_msgs_Header header;

  // PrimitiveROSType=string:IsVarLen=1:VarLenCategory=data:VarLenElem=child_frame_id_SL_Info:TruncateAction=warn 
  uint8_T child_frame_id[128];

  // IsVarLen=1:VarLenCategory=length:VarLenElem=child_frame_id
  SL_Bus_ROSVariableLengthArrayInfo child_frame_id_SL_Info;

  // MsgType=geometry_msgs/PoseWithCovariance
  SL_Bus_geometry_msgs_PoseWithCovariance pose;

  // MsgType=geometry_msgs/TwistWithCovariance
  SL_Bus_geometry_msgs_TwistWithCovariance twist;
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

// Custom Type definition for MATLABSystem: '<S58>/SourceBlock'
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

// Custom Type definition for MATLAB Function: '<S54>/PolicyWrapper'
#ifndef struct_dlarray_1_agent1_T
#define struct_dlarray_1_agent1_T

struct dlarray_1_agent1_T
{
  real32_T Data[2];
};

#endif                                 // struct_dlarray_1_agent1_T

#ifndef struct_cell_wrap_2_agent1_T
#define struct_cell_wrap_2_agent1_T

struct cell_wrap_2_agent1_T
{
  real_T f1[2];
};

#endif                                 // struct_cell_wrap_2_agent1_T

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
  cell_wrap_2_agent1_T UpperLimits_;
  cell_wrap_2_agent1_T LowerLimits_;
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

// Parameters for system: '<S12>/For Each Subsystem'
typedef struct P_CoreSubsys_agent1_g_T_ P_CoreSubsys_agent1_g_T;

// Parameters for system: '<S12>/For Each Subsystem1'
typedef struct P_CoreSubsys_agent1_gm_T_ P_CoreSubsys_agent1_gm_T;

// Parameters (default storage)
typedef struct P_agent1_T_ P_agent1_T;

// Forward declaration for rtModel
typedef struct tag_RTM_agent1_T RT_MODEL_agent1_T;

#endif                                 // RTW_HEADER_agent1_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
