//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: motion_controller_withPIC_types.h
//
// Code generated for Simulink model 'motion_controller_withPIC'.
//
// Model version                  : 2.353
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Mon Jan  6 15:09:04 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_motion_controller_withPIC_types_h_
#define RTW_HEADER_motion_controller_withPIC_types_h_
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

// Custom Type definition for MATLABSystem: '<S69>/SourceBlock'
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

// Custom Type definition for MATLAB Function: '<S61>/solvex'
#ifndef struct_s5cJJO9CAPQxuVG0iaeiP4F_motio_T
#define struct_s5cJJO9CAPQxuVG0iaeiP4F_motio_T

struct s5cJJO9CAPQxuVG0iaeiP4F_motio_T
{
  real_T xstar[41];
  real_T fstar;
  real_T firstorderopt;
  real_T lambda[161];
  int32_T state;
  real_T maxConstr;
  int32_T iterations;
  real_T searchDir[41];
};

#endif                                // struct_s5cJJO9CAPQxuVG0iaeiP4F_motio_T

#ifndef struct_sKnhLiTH4yv7eF1oV2a74RG_motio_T
#define struct_sKnhLiTH4yv7eF1oV2a74RG_motio_T

struct sKnhLiTH4yv7eF1oV2a74RG_motio_T
{
  real_T grad[41];
  real_T Hx[40];
  boolean_T hasLinear;
  int32_T nvar;
  int32_T maxVar;
  real_T beta;
  real_T rho;
  int32_T objtype;
  int32_T prev_objtype;
  int32_T prev_nvar;
  boolean_T prev_hasLinear;
  real_T gammaScalar;
};

#endif                                // struct_sKnhLiTH4yv7eF1oV2a74RG_motio_T

#ifndef struct_s8kZFjDlzP6eNfOekUiP5MF_motio_T
#define struct_s8kZFjDlzP6eNfOekUiP5MF_motio_T

struct s8kZFjDlzP6eNfOekUiP5MF_motio_T
{
  real_T FMat[1681];
  int32_T ldm;
  int32_T ndims;
  int32_T info;
  real_T scaleFactor;
  boolean_T ConvexCheck;
  real_T regTol_;
  real_T workspace_[1968];
  real_T workspace2_[1968];
};

#endif                                // struct_s8kZFjDlzP6eNfOekUiP5MF_motio_T

// Custom Type definition for MATLAB Function: '<S62>/solvex'
#ifndef struct_sL9bDKomAYkxZSVrG9w6En_motion_T
#define struct_sL9bDKomAYkxZSVrG9w6En_motion_T

struct sL9bDKomAYkxZSVrG9w6En_motion_T
{
  int32_T MaxIterations;
  real_T ConstrRelTolFactor;
  real_T ProbRelTolFactor;
  boolean_T RemainFeasible;
};

#endif                                // struct_sL9bDKomAYkxZSVrG9w6En_motion_T

#ifndef struct_sYqpSPVJXu9aOn60zG4DpzD_motio_T
#define struct_sYqpSPVJXu9aOn60zG4DpzD_motio_T

struct sYqpSPVJXu9aOn60zG4DpzD_motio_T
{
  real_T xstar[21];
  real_T fstar;
  real_T firstorderopt;
  real_T lambda[81];
  int32_T state;
  real_T maxConstr;
  int32_T iterations;
  real_T searchDir[21];
};

#endif                                // struct_sYqpSPVJXu9aOn60zG4DpzD_motio_T

#ifndef struct_s3PrFoa9w5ssw8XLEJooNqH_motio_T
#define struct_s3PrFoa9w5ssw8XLEJooNqH_motio_T

struct s3PrFoa9w5ssw8XLEJooNqH_motio_T
{
  real_T grad[21];
  real_T Hx[20];
  boolean_T hasLinear;
  int32_T nvar;
  int32_T maxVar;
  real_T beta;
  real_T rho;
  int32_T objtype;
  int32_T prev_objtype;
  int32_T prev_nvar;
  boolean_T prev_hasLinear;
  real_T gammaScalar;
};

#endif                                // struct_s3PrFoa9w5ssw8XLEJooNqH_motio_T

#ifndef struct_sTy13TWZ7KObOACj8wDaLQC_motio_T
#define struct_sTy13TWZ7KObOACj8wDaLQC_motio_T

struct sTy13TWZ7KObOACj8wDaLQC_motio_T
{
  real_T FMat[441];
  int32_T ldm;
  int32_T ndims;
  int32_T info;
  real_T scaleFactor;
  boolean_T ConvexCheck;
  real_T regTol_;
  real_T workspace_[1008];
  real_T workspace2_[1008];
};

#endif                                // struct_sTy13TWZ7KObOACj8wDaLQC_motio_T

// Custom Type definition for MATLAB Function: '<S61>/solvex'
#ifndef struct_s2uO2c2bmaUl7sY5vOWIzHG_motio_T
#define struct_s2uO2c2bmaUl7sY5vOWIzHG_motio_T

struct s2uO2c2bmaUl7sY5vOWIzHG_motio_T
{
  int32_T ldq;
  real_T QR[6601];
  real_T Q[1681];
  int32_T jpvt[161];
  int32_T mrows;
  int32_T ncols;
  real_T tau[41];
  int32_T minRowCol;
  boolean_T usedPivoting;
};

#endif                                // struct_s2uO2c2bmaUl7sY5vOWIzHG_motio_T

#ifndef struct_sFlCINAYeIgPgx0UwEHpaMF_motio_T
#define struct_sFlCINAYeIgPgx0UwEHpaMF_motio_T

struct sFlCINAYeIgPgx0UwEHpaMF_motio_T
{
  real_T workspace_double[6601];
  int32_T workspace_int[161];
  int32_T workspace_sort[161];
};

#endif                                // struct_sFlCINAYeIgPgx0UwEHpaMF_motio_T

// Custom Type definition for MATLAB Function: '<S62>/solvex'
#ifndef struct_sIZAIOglGM5dPDQlNukc9SD_motio_T
#define struct_sIZAIOglGM5dPDQlNukc9SD_motio_T

struct sIZAIOglGM5dPDQlNukc9SD_motio_T
{
  int32_T ldq;
  real_T QR[1701];
  real_T Q[441];
  int32_T jpvt[81];
  int32_T mrows;
  int32_T ncols;
  real_T tau[21];
  int32_T minRowCol;
  boolean_T usedPivoting;
};

#endif                                // struct_sIZAIOglGM5dPDQlNukc9SD_motio_T

#ifndef struct_s3cSGkBdKxRj6Qn3zsJRowG_motio_T
#define struct_s3cSGkBdKxRj6Qn3zsJRowG_motio_T

struct s3cSGkBdKxRj6Qn3zsJRowG_motio_T
{
  real_T workspace_double[1701];
  int32_T workspace_int[81];
  int32_T workspace_sort[81];
};

#endif                                // struct_s3cSGkBdKxRj6Qn3zsJRowG_motio_T

#ifndef struct_sSOeZ9WO10chPn9Si6PKiCB_motio_T
#define struct_sSOeZ9WO10chPn9Si6PKiCB_motio_T

struct sSOeZ9WO10chPn9Si6PKiCB_motio_T
{
  real_T InitDamping;
  char_T FiniteDifferenceType[7];
  boolean_T SpecifyObjectiveGradient;
  boolean_T ScaleProblem;
  boolean_T SpecifyConstraintGradient;
  boolean_T NonFiniteSupport;
  boolean_T IterDisplaySQP;
  real_T FiniteDifferenceStepSize;
  real_T MaxFunctionEvaluations;
  boolean_T IterDisplayQP;
  real_T PricingTolerance;
  char_T Algorithm[10];
  real_T ObjectiveLimit;
  real_T ConstraintTolerance;
  real_T OptimalityTolerance;
  real_T StepTolerance;
  real_T MaxIterations;
  real_T FunctionTolerance;
  char_T SolverName[8];
  boolean_T CheckGradients;
  char_T Diagnostics[3];
  real_T DiffMaxChange;
  real_T DiffMinChange;
  char_T Display[5];
  char_T FunValCheck[3];
  boolean_T UseParallel;
  char_T LinearSolver[4];
  char_T SubproblemAlgorithm[2];
};

#endif                                // struct_sSOeZ9WO10chPn9Si6PKiCB_motio_T

// Custom Type definition for MATLAB Function: '<S61>/solvex'
#ifndef struct_sT1ziU4p6vTWuD880X9yNJ_motion_T
#define struct_sT1ziU4p6vTWuD880X9yNJ_motion_T

struct sT1ziU4p6vTWuD880X9yNJ_motion_T
{
  int32_T mConstr;
  int32_T mConstrOrig;
  int32_T mConstrMax;
  int32_T nVar;
  int32_T nVarOrig;
  int32_T nVarMax;
  int32_T ldA;
  real_T Aineq[3280];
  real_T bineq[80];
  real_T lb[41];
  real_T ub[41];
  int32_T indexLB[41];
  int32_T indexUB[41];
  int32_T indexFixed[41];
  int32_T mEqRemoved;
  real_T ATwset[6601];
  real_T bwset[161];
  int32_T nActiveConstr;
  real_T maxConstrWorkspace[161];
  int32_T sizes[5];
  int32_T sizesNormal[5];
  int32_T sizesPhaseOne[5];
  int32_T sizesRegularized[5];
  int32_T sizesRegPhaseOne[5];
  int32_T isActiveIdx[6];
  int32_T isActiveIdxNormal[6];
  int32_T isActiveIdxPhaseOne[6];
  int32_T isActiveIdxRegularized[6];
  int32_T isActiveIdxRegPhaseOne[6];
  boolean_T isActiveConstr[161];
  int32_T Wid[161];
  int32_T Wlocalidx[161];
  int32_T nWConstr[5];
  int32_T probType;
  real_T SLACK0;
};

#endif                                // struct_sT1ziU4p6vTWuD880X9yNJ_motion_T

// Custom Type definition for MATLAB Function: '<S62>/solvex'
#ifndef struct_sVIU4VBONGRsUytHTQmMJFH_motio_T
#define struct_sVIU4VBONGRsUytHTQmMJFH_motio_T

struct sVIU4VBONGRsUytHTQmMJFH_motio_T
{
  int32_T mConstr;
  int32_T mConstrOrig;
  int32_T mConstrMax;
  int32_T nVar;
  int32_T nVarOrig;
  int32_T nVarMax;
  int32_T ldA;
  real_T Aineq[840];
  real_T bineq[40];
  real_T lb[21];
  real_T ub[21];
  int32_T indexLB[21];
  int32_T indexUB[21];
  int32_T indexFixed[21];
  int32_T mEqRemoved;
  real_T ATwset[1701];
  real_T bwset[81];
  int32_T nActiveConstr;
  real_T maxConstrWorkspace[81];
  int32_T sizes[5];
  int32_T sizesNormal[5];
  int32_T sizesPhaseOne[5];
  int32_T sizesRegularized[5];
  int32_T sizesRegPhaseOne[5];
  int32_T isActiveIdx[6];
  int32_T isActiveIdxNormal[6];
  int32_T isActiveIdxPhaseOne[6];
  int32_T isActiveIdxRegularized[6];
  int32_T isActiveIdxRegPhaseOne[6];
  boolean_T isActiveConstr[81];
  int32_T Wid[81];
  int32_T Wlocalidx[81];
  int32_T nWConstr[5];
  int32_T probType;
  real_T SLACK0;
};

#endif                                // struct_sVIU4VBONGRsUytHTQmMJFH_motio_T

// Parameters for system: '<S14>/For Each Subsystem'
typedef struct P_CoreSubsys_motion_control_g_T_ P_CoreSubsys_motion_control_g_T;

// Parameters for system: '<S14>/For Each Subsystem1'
typedef struct P_CoreSubsys_motion_contro_gm_T_ P_CoreSubsys_motion_contro_gm_T;

// Parameters (default storage)
typedef struct P_motion_controller_withPIC_T_ P_motion_controller_withPIC_T;

// Forward declaration for rtModel
typedef struct tag_RTM_motion_controller_wit_T RT_MODEL_motion_controller_wi_T;

#endif                         // RTW_HEADER_motion_controller_withPIC_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
