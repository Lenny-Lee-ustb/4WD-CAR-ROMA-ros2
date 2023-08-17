//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: odometry.cpp
//
// Code generated for Simulink model 'odometry'.
//
// Model version                  : 1.21
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Mon Aug 14 19:30:55 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "odometry.h"
#include "odometry_types.h"
#include "rtwtypes.h"
#include "odometry_private.h"
#include <math.h>
#include "rmw/qos_profiles.h"
#include "rmw/types.h"
#include <stddef.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_defines.h"

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(static_cast<real_T>(tmp), static_cast<real_T>(tmp_0));
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

void odometry::odometry_SystemCore_setup_h4(ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[13];
  static const char_T tmp[12] = { '/', 's', 'e', 'r', 'v', 'o', '_', 's', 't',
    'a', 't', 'e' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_RELIABLE;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 12; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[12] = '\x00';
  Sub_odometry_163.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void odometry::odometry_SystemCore_setup_h(ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[13];
  static const char_T tmp[12] = { '/', 'm', 'o', 't', 'o', 'r', '_', 's', 't',
    'a', 't', 'e' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 12; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[12] = '\x00';
  Sub_odometry_89.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void odometry::odometry_SystemCore_setup_h4a(ros_slros2_internal_block_Sub_T
  *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[10];
  static const char_T tmp[9] = { '/', 'I', 'm', 'u', '_', 'd', 'a', 't', 'a' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 9; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[9] = '\x00';
  Sub_odometry_193.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void odometry::odometry_SystemCore_setup(ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[17];
  static const char_T tmp[16] = { '/', 'S', 'p', 'd', '_', 'P', 'o', 's', 'i',
    't', 'i', 'o', 'n', '_', 'X', 'Y' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 16; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[16] = '\x00';
  Pub_odometry_253.createPublisher(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

// Model step function
void odometry::step()
{
  // local scratch DWork variables
  int32_T ForEach_itr;
  int32_T ForEach_itr_j;
  real_T XY_dot_tmp;
  real_T XY_dot_tmp_0;
  real_T rtb_Add;
  real_T rtb_ManualSwitch_idx_1;
  real_T rtb_Merge;
  boolean_T b_varargout_1;
  boolean_T b_varargout_1_0;

  // MATLABSystem: '<S4>/SourceBlock'
  b_varargout_1 = Sub_odometry_163.getLatestMessage(&odometry_B.b_varargout_2_m);

  // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S12>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S12>/In1'
    odometry_B.In1_b = odometry_B.b_varargout_2_m;
  }

  // End of MATLABSystem: '<S4>/SourceBlock'
  // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'

  // Outputs for Iterator SubSystem: '<S8>/For Each Subsystem' incorporates:
  //   ForEach: '<S17>/For Each'

  for (ForEach_itr = 0; ForEach_itr < 16; ForEach_itr++) {
    // ForEachSliceAssignment generated from: '<S17>/x' incorporates:
    //   ForEachSliceSelector generated from: '<S17>/In1'

    odometry_B.ImpAsg_InsertedFor_x_at_inp[ForEach_itr] =
      odometry_B.In1_b.polygon.points[ForEach_itr].x;
  }

  // End of Outputs for SubSystem: '<S8>/For Each Subsystem'

  // MATLABSystem: '<S3>/SourceBlock'
  b_varargout_1 = Sub_odometry_89.getLatestMessage(&odometry_B.b_varargout_2_m);

  // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S11>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S11>/In1'
    odometry_B.In1_bo = odometry_B.b_varargout_2_m;
  }

  // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'

  // Outputs for Iterator SubSystem: '<S6>/For Each Subsystem' incorporates:
  //   ForEach: '<S14>/For Each'

  for (ForEach_itr_j = 0; ForEach_itr_j < 16; ForEach_itr_j++) {
    // ForEachSliceAssignment generated from: '<S14>/x' incorporates:
    //   ForEachSliceSelector generated from: '<S14>/In1'

    odometry_B.ImpAsg_InsertedFor_x_at_i_d[ForEach_itr_j] =
      odometry_B.In1_bo.polygon.points[ForEach_itr_j].x;
  }

  // End of Outputs for SubSystem: '<S6>/For Each Subsystem'

  // MATLABSystem: '<S5>/SourceBlock'
  b_varargout_1_0 = Sub_odometry_193.getLatestMessage(&odometry_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S13>/Enable'

  if (b_varargout_1_0) {
    // SignalConversion generated from: '<S13>/In1'
    odometry_B.In1 = odometry_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S5>/SourceBlock'
  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'

  // Sum: '<S10>/Add' incorporates:
  //   Constant: '<S10>/Constant'
  //   MATLAB Function: '<S9>/MATLAB Function'

  rtb_Add = rt_atan2d_snf((odometry_B.In1.orientation.w *
    odometry_B.In1.orientation.z + odometry_B.In1.orientation.x *
    odometry_B.In1.orientation.y) * 2.0, 1.0 - (odometry_B.In1.orientation.y *
    odometry_B.In1.orientation.y + odometry_B.In1.orientation.z *
    odometry_B.In1.orientation.z) * 2.0) + odometry_P.Constant_Value_p;

  // Outputs for Enabled SubSystem: '<S21>/Enabled Subsystem1' incorporates:
  //   EnablePort: '<S23>/Enable'

  // RelationalOperator: '<S22>/Compare' incorporates:
  //   Clock: '<S21>/Clock'
  //   Constant: '<S22>/Constant'

  if ((&odometry_M)->Timing.t[0] <= odometry_P.CompareToConstant_const) {
    // SignalConversion generated from: '<S23>/yaw'
    odometry_B.yaw = rtb_Add;
  }

  // End of RelationalOperator: '<S22>/Compare'
  // End of Outputs for SubSystem: '<S21>/Enabled Subsystem1'

  // If: '<S10>/If' incorporates:
  //   Constant: '<S20>/Constant'
  //   RelationalOperator: '<S20>/Relational Operator'
  //   Sum: '<S20>/Add'
  //   Switch: '<S20>/Switch'

  if (odometry_B.yaw <= 3.1415926535897931) {
    // Outputs for IfAction SubSystem: '<S10>/If Action Subsystem' incorporates:
    //   ActionPort: '<S19>/Action Port'

    // Switch: '<S19>/Switch' incorporates:
    //   Constant: '<S19>/Constant'
    //   Constant: '<S19>/Constant1'
    //   RelationalOperator: '<S19>/Relational Operator'
    //   Sum: '<S19>/Add'
    //   Sum: '<S19>/Add1'
    //   Sum: '<S19>/Add2'

    if (odometry_B.yaw + odometry_P.Constant_Value_lo < rtb_Add) {
      rtb_Merge = (rtb_Add - odometry_P.Constant1_Value) - odometry_B.yaw;
    } else {
      rtb_Merge = rtb_Add - odometry_B.yaw;
    }

    // End of Switch: '<S19>/Switch'
    // End of Outputs for SubSystem: '<S10>/If Action Subsystem'

    // Outputs for IfAction SubSystem: '<S10>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S20>/Action Port'

  } else if (odometry_B.yaw - odometry_P.Constant_Value_d > rtb_Add) {
    // Switch: '<S20>/Switch' incorporates:
    //   Constant: '<S20>/Constant1'
    //   Sum: '<S20>/Add1'

    rtb_Merge = (odometry_P.Constant1_Value_f - odometry_B.yaw) + rtb_Add;
  } else {
    // Switch: '<S20>/Switch' incorporates:
    //   Sum: '<S20>/Add2'

    rtb_Merge = rtb_Add - odometry_B.yaw;

    // End of Outputs for SubSystem: '<S10>/If Action Subsystem1'
  }

  // End of If: '<S10>/If'

  // Outputs for Enabled SubSystem: '<Root>/Subsystem1' incorporates:
  //   EnablePort: '<S7>/Enable'

  // MATLABSystem: '<S3>/SourceBlock' incorporates:
  //   MATLAB Function: '<S7>/MATLAB Function'

  if (b_varargout_1) {
    // UnitDelay: '<S7>/Unit Delay'
    odometry_B.UnitDelay[0] = odometry_DW.UnitDelay_DSTATE[0];
    odometry_B.UnitDelay[1] = odometry_DW.UnitDelay_DSTATE[1];

    // ManualSwitch: '<S16>/Manual Switch' incorporates:
    //   Constant: '<S16>/Constant'
    //   Gain: '<Root>/Gain'
    //   Gain: '<S16>/Gain'
    //   Product: '<S16>/Product'

    if (odometry_P.ManualSwitch_CurrentSetting == 1) {
      rtb_Add = (((odometry_P.Gain_Gain_m *
                   odometry_B.ImpAsg_InsertedFor_x_at_i_d[0] *
                   odometry_P.Constant_Value_j0[0] + odometry_P.Gain_Gain_m *
                   odometry_B.ImpAsg_InsertedFor_x_at_i_d[1] *
                   odometry_P.Constant_Value_j0[1]) + odometry_P.Gain_Gain_m *
                  odometry_B.ImpAsg_InsertedFor_x_at_i_d[2] *
                  odometry_P.Constant_Value_j0[2]) + odometry_P.Gain_Gain_m *
                 odometry_B.ImpAsg_InsertedFor_x_at_i_d[3] *
                 odometry_P.Constant_Value_j0[3]) * odometry_P.Gain_Gain;
    } else {
      rtb_Add = ((odometry_P.Gain_Gain_m *
                  odometry_B.ImpAsg_InsertedFor_x_at_i_d[0] *
                  odometry_P.Constant_Value_j0[0] + odometry_P.Gain_Gain_m *
                  odometry_B.ImpAsg_InsertedFor_x_at_i_d[1] *
                  odometry_P.Constant_Value_j0[1]) + odometry_P.Gain_Gain_m *
                 odometry_B.ImpAsg_InsertedFor_x_at_i_d[2] *
                 odometry_P.Constant_Value_j0[2]) + odometry_P.Gain_Gain_m *
        odometry_B.ImpAsg_InsertedFor_x_at_i_d[3] *
        odometry_P.Constant_Value_j0[3];
    }

    // End of ManualSwitch: '<S16>/Manual Switch'

    // MATLAB Function: '<S7>/MATLAB Function'
    XY_dot_tmp = sin(rtb_Merge);
    rtb_Merge = cos(rtb_Merge);

    // Reshape: '<S16>/Reshape1' incorporates:
    //   Gain: '<S16>/Gain1'
    //   Gain: '<S8>/Gain1'
    //   Product: '<S16>/Product1'
    //   Trigonometry: '<S16>/Tan'

    rtb_ManualSwitch_idx_1 = static_cast<real32_T>(tan(static_cast<real_T>
      (odometry_P.Gain1_Gain_i[0] * odometry_B.ImpAsg_InsertedFor_x_at_inp[0] +
       odometry_P.Gain1_Gain_i[1] * odometry_B.ImpAsg_InsertedFor_x_at_inp[1])))
      * odometry_P.Gain1_Gain * rtb_Add;

    // MATLAB Function: '<S7>/MATLAB Function' incorporates:
    //   Reshape: '<S16>/Reshape1'

    XY_dot_tmp_0 = rtb_Merge * rtb_Add + -XY_dot_tmp * rtb_ManualSwitch_idx_1;
    odometry_B.XY_dot[0] = XY_dot_tmp_0;

    // Sum: '<S7>/Add' incorporates:
    //   Gain: '<S7>/Gain'
    //   MATLAB Function: '<S7>/MATLAB Function'
    //   UnitDelay: '<S7>/Unit Delay'

    odometry_DW.UnitDelay_DSTATE[0] = odometry_P.Gain_Gain_n * XY_dot_tmp_0 +
      odometry_B.UnitDelay[0];

    // MATLAB Function: '<S7>/MATLAB Function' incorporates:
    //   Reshape: '<S16>/Reshape1'

    XY_dot_tmp = XY_dot_tmp * rtb_Add + rtb_Merge * rtb_ManualSwitch_idx_1;
    odometry_B.XY_dot[1] = XY_dot_tmp;

    // Sum: '<S7>/Add' incorporates:
    //   Gain: '<S7>/Gain'
    //   MATLAB Function: '<S7>/MATLAB Function'
    //   UnitDelay: '<S7>/Unit Delay'

    odometry_DW.UnitDelay_DSTATE[1] = odometry_P.Gain_Gain_n * XY_dot_tmp +
      odometry_B.UnitDelay[1];
  }

  // End of Outputs for SubSystem: '<Root>/Subsystem1'

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Constant: '<S1>/Constant'

  odometry_B.BusAssignment = odometry_P.Constant_Value;
  odometry_B.BusAssignment.twist.twist.linear.x = odometry_B.XY_dot[0];
  odometry_B.BusAssignment.twist.twist.linear.y = odometry_B.XY_dot[1];
  odometry_B.BusAssignment.pose.pose.position.x = odometry_B.UnitDelay[0];
  odometry_B.BusAssignment.pose.pose.position.y = odometry_B.UnitDelay[1];

  // MATLABSystem: '<S2>/SinkBlock'
  Pub_odometry_253.publish(&odometry_B.BusAssignment);

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  (&odometry_M)->Timing.t[0] =
    ((time_T)(++(&odometry_M)->Timing.clockTick0)) * (&odometry_M)
    ->Timing.stepSize0;

  {
    // Update absolute timer for sample time: [0.01s, 0.0s]
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 0.01, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    (&odometry_M)->Timing.clockTick1++;
  }
}

// Model initialize function
void odometry::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&(&odometry_M)->solverInfo, &(&odometry_M)
                          ->Timing.simTimeStep);
    rtsiSetTPtr(&(&odometry_M)->solverInfo, &rtmGetTPtr((&odometry_M)));
    rtsiSetStepSizePtr(&(&odometry_M)->solverInfo, &(&odometry_M)
                       ->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&(&odometry_M)->solverInfo, (&rtmGetErrorStatus
      ((&odometry_M))));
    rtsiSetRTModelPtr(&(&odometry_M)->solverInfo, (&odometry_M));
  }

  rtsiSetSimTimeStep(&(&odometry_M)->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&(&odometry_M)->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr((&odometry_M), &(&odometry_M)->Timing.tArray[0]);
  (&odometry_M)->Timing.stepSize0 = 0.01;

  // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
  // SystemInitialize for SignalConversion generated from: '<S12>/In1' incorporates:
  //   Outport: '<S12>/Out1'

  odometry_B.In1_b = odometry_P.Out1_Y0_k;

  // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem'
  // SystemInitialize for SignalConversion generated from: '<S11>/In1' incorporates:
  //   Outport: '<S11>/Out1'

  odometry_B.In1_bo = odometry_P.Out1_Y0_g;

  // End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
  // SystemInitialize for SignalConversion generated from: '<S13>/In1' incorporates:
  //   Outport: '<S13>/Out1'

  odometry_B.In1 = odometry_P.Out1_Y0;

  // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'

  // SystemInitialize for Enabled SubSystem: '<S21>/Enabled Subsystem1'
  // SystemInitialize for SignalConversion generated from: '<S23>/yaw' incorporates:
  //   Outport: '<S23>/Out1'

  odometry_B.yaw = odometry_P.Out1_Y0_p;

  // End of SystemInitialize for SubSystem: '<S21>/Enabled Subsystem1'

  // SystemInitialize for Enabled SubSystem: '<Root>/Subsystem1'
  // InitializeConditions for UnitDelay: '<S7>/Unit Delay'
  odometry_DW.UnitDelay_DSTATE[0] = odometry_P.UnitDelay_InitialCondition;

  // SystemInitialize for Outport: '<S7>/XY_dot'
  odometry_B.XY_dot[0] = odometry_P.XY_dot_Y0;

  // SystemInitialize for UnitDelay: '<S7>/Unit Delay' incorporates:
  //   Outport: '<S7>/XY'

  odometry_B.UnitDelay[0] = odometry_P.XY_Y0;

  // InitializeConditions for UnitDelay: '<S7>/Unit Delay'
  odometry_DW.UnitDelay_DSTATE[1] = odometry_P.UnitDelay_InitialCondition;

  // SystemInitialize for Outport: '<S7>/XY_dot'
  odometry_B.XY_dot[1] = odometry_P.XY_dot_Y0;

  // SystemInitialize for UnitDelay: '<S7>/Unit Delay' incorporates:
  //   Outport: '<S7>/XY'

  odometry_B.UnitDelay[1] = odometry_P.XY_Y0;

  // End of SystemInitialize for SubSystem: '<Root>/Subsystem1'

  // Start for MATLABSystem: '<S4>/SourceBlock'
  odometry_DW.obj_l.isInitialized = 0;
  odometry_DW.obj_l.matlabCodegenIsDeleted = false;
  odometry_SystemCore_setup_h4(&odometry_DW.obj_l);

  // Start for MATLABSystem: '<S3>/SourceBlock'
  odometry_DW.obj_j.isInitialized = 0;
  odometry_DW.obj_j.matlabCodegenIsDeleted = false;
  odometry_SystemCore_setup_h(&odometry_DW.obj_j);

  // Start for MATLABSystem: '<S5>/SourceBlock'
  odometry_DW.obj_a.isInitialized = 0;
  odometry_DW.obj_a.matlabCodegenIsDeleted = false;
  odometry_SystemCore_setup_h4a(&odometry_DW.obj_a);

  // Start for MATLABSystem: '<S2>/SinkBlock'
  odometry_DW.obj.isInitialized = 0;
  odometry_DW.obj.matlabCodegenIsDeleted = false;
  odometry_SystemCore_setup(&odometry_DW.obj);
}

// Model terminate function
void odometry::terminate()
{
  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!odometry_DW.obj_l.matlabCodegenIsDeleted) {
    odometry_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'

  // Terminate for MATLABSystem: '<S3>/SourceBlock'
  if (!odometry_DW.obj_j.matlabCodegenIsDeleted) {
    odometry_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SourceBlock'

  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!odometry_DW.obj_a.matlabCodegenIsDeleted) {
    odometry_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'

  // Terminate for MATLABSystem: '<S2>/SinkBlock'
  if (!odometry_DW.obj.matlabCodegenIsDeleted) {
    odometry_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/SinkBlock'
}

// Constructor
odometry::odometry() :
  odometry_B(),
  odometry_DW(),
  odometry_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
odometry::~odometry()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_odometry_T * odometry::getRTM()
{
  return (&odometry_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
