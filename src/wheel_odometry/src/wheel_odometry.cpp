//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: wheel_odometry.cpp
//
// Code generated for Simulink model 'wheel_odometry'.
//
// Model version                  : 1.30
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Sun Sep  3 12:16:53 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "wheel_odometry.h"
#include "wheel_odometry_types.h"
#include "rtwtypes.h"
#include "wheel_odometry_private.h"
#include <math.h>
#include "rmw/qos_profiles.h"
#include "rmw/types.h"
#include <stddef.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_defines.h"

// Named constants for Chart: '<S7>/Chart'
const uint8_T wheel_odometry_IN_clearXY = 1U;
const uint8_T wheel_odometry_IN_hold = 2U;
const uint8_T wheel_odometry_IN_waiting = 3U;
const uint8_T wheel_odometry_IN_waiting1 = 4U;
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

void wheel_odometry::wheel_odome_SystemCore_setup_pb
  (ros_slros2_internal_block_Sub_T *obj)
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
  Sub_wheel_odometry_163.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void wheel_odometry::wheel_odomet_SystemCore_setup_p
  (ros_slros2_internal_block_Sub_T *obj)
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
  Sub_wheel_odometry_89.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void wheel_odometry::wheel_odom_SystemCore_setup_pbe
  (ros_slros2_internal_block_Sub_T *obj)
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
  Sub_wheel_odometry_193.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void wheel_odometry::wheel_odometry_SystemCore_setup
  (ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_durability_policy_t durability;
  rmw_qos_history_policy_t history;
  rmw_qos_profile_t qos_profile;
  rmw_qos_reliability_policy_t reliability;
  char_T b_zeroDelimTopic[12];
  static const char_T tmp[11] = { '/', 'w', 'h', 'e', 'e', 'l', '_', 'o', 'd',
    'o', 'm' };

  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;
  history = RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  reliability = RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT;
  durability = RMW_QOS_POLICY_DURABILITY_VOLATILE;
  SET_QOS_VALUES(qos_profile, history, (size_t)1.0, durability, reliability);
  for (int32_T i = 0; i < 11; i++) {
    b_zeroDelimTopic[i] = tmp[i];
  }

  b_zeroDelimTopic[11] = '\x00';
  Pub_wheel_odometry_253.createPublisher(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

// Model step function
void wheel_odometry::step()
{
  // local scratch DWork variables
  int32_T ForEach_itr;
  int32_T ForEach_itr_j;
  real_T XY_dot_tmp;
  real_T XY_dot_tmp_0;
  real_T XY_dot_tmp_1;
  real_T rtb_vxvy_idx_1;
  real_T s_idx_1_tmp;
  real32_T rtb_Gain1_0;
  boolean_T b_varargout_1;
  boolean_T b_varargout_1_0;

  // MATLABSystem: '<S4>/SourceBlock'
  b_varargout_1 = Sub_wheel_odometry_163.getLatestMessage
    (&wheel_odometry_B.b_varargout_2_m);

  // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S12>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S12>/In1'
    wheel_odometry_B.In1_b = wheel_odometry_B.b_varargout_2_m;
  }

  // End of MATLABSystem: '<S4>/SourceBlock'
  // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'

  // Outputs for Iterator SubSystem: '<S8>/For Each Subsystem' incorporates:
  //   ForEach: '<S19>/For Each'

  for (ForEach_itr = 0; ForEach_itr < 16; ForEach_itr++) {
    // ForEachSliceAssignment generated from: '<S19>/x' incorporates:
    //   ForEachSliceSelector generated from: '<S19>/In1'

    wheel_odometry_B.ImpAsg_InsertedFor_x_at_inp[ForEach_itr] =
      wheel_odometry_B.In1_b.polygon.points[ForEach_itr].x;
  }

  // End of Outputs for SubSystem: '<S8>/For Each Subsystem'

  // MATLABSystem: '<S3>/SourceBlock'
  b_varargout_1 = Sub_wheel_odometry_89.getLatestMessage
    (&wheel_odometry_B.b_varargout_2_m);

  // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S11>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S11>/In1'
    wheel_odometry_B.In1_bo = wheel_odometry_B.b_varargout_2_m;
  }

  // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'

  // Outputs for Iterator SubSystem: '<S6>/For Each Subsystem' incorporates:
  //   ForEach: '<S14>/For Each'

  for (ForEach_itr_j = 0; ForEach_itr_j < 16; ForEach_itr_j++) {
    // ForEachSliceAssignment generated from: '<S14>/x' incorporates:
    //   ForEachSliceSelector generated from: '<S14>/In1'

    wheel_odometry_B.ImpAsg_InsertedFor_x_at_i_d[ForEach_itr_j] =
      wheel_odometry_B.In1_bo.polygon.points[ForEach_itr_j].x;
  }

  // End of Outputs for SubSystem: '<S6>/For Each Subsystem'

  // MATLABSystem: '<Root>/Get Parameter'
  ParamGet_wheel_odometry_353.getParameter(&wheel_odometry_B.b_value);

  // Gain: '<S8>/Gain1'
  rtb_Gain1_0 = wheel_odometry_P.Gain1_Gain_i[0] *
    wheel_odometry_B.ImpAsg_InsertedFor_x_at_inp[0] +
    wheel_odometry_P.Gain1_Gain_i[1] *
    wheel_odometry_B.ImpAsg_InsertedFor_x_at_inp[1];

  // MATLABSystem: '<S5>/SourceBlock'
  b_varargout_1_0 = Sub_wheel_odometry_193.getLatestMessage
    (&wheel_odometry_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S13>/Enable'

  if (b_varargout_1_0) {
    // SignalConversion generated from: '<S13>/In1'
    wheel_odometry_B.In1 = wheel_odometry_B.b_varargout_2;
  }

  // End of MATLABSystem: '<S5>/SourceBlock'
  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'

  // Sum: '<S10>/Add' incorporates:
  //   Constant: '<S10>/Constant'
  //   MATLAB Function: '<S9>/MATLAB Function'

  wheel_odometry_B.Add = rt_atan2d_snf((wheel_odometry_B.In1.orientation.w *
    wheel_odometry_B.In1.orientation.z + wheel_odometry_B.In1.orientation.x *
    wheel_odometry_B.In1.orientation.y) * 2.0, 1.0 -
    (wheel_odometry_B.In1.orientation.y * wheel_odometry_B.In1.orientation.y +
     wheel_odometry_B.In1.orientation.z * wheel_odometry_B.In1.orientation.z) *
    2.0) + wheel_odometry_P.Constant_Value_p;

  // Outputs for Enabled SubSystem: '<S23>/Enabled Subsystem1' incorporates:
  //   EnablePort: '<S25>/Enable'

  // RelationalOperator: '<S24>/Compare' incorporates:
  //   Clock: '<S23>/Clock'
  //   Constant: '<S24>/Constant'

  if ((&wheel_odometry_M)->Timing.t[0] <=
      wheel_odometry_P.CompareToConstant_const) {
    // SignalConversion generated from: '<S25>/yaw'
    wheel_odometry_B.yaw = wheel_odometry_B.Add;
  }

  // End of RelationalOperator: '<S24>/Compare'
  // End of Outputs for SubSystem: '<S23>/Enabled Subsystem1'

  // If: '<S10>/If' incorporates:
  //   Constant: '<S22>/Constant'
  //   RelationalOperator: '<S22>/Relational Operator'
  //   Sum: '<S22>/Add'
  //   Switch: '<S22>/Switch'

  if (wheel_odometry_B.yaw <= 3.1415926535897931) {
    // Outputs for IfAction SubSystem: '<S10>/If Action Subsystem' incorporates:
    //   ActionPort: '<S21>/Action Port'

    // Switch: '<S21>/Switch' incorporates:
    //   Constant: '<S21>/Constant'
    //   Constant: '<S21>/Constant1'
    //   RelationalOperator: '<S21>/Relational Operator'
    //   Sum: '<S21>/Add'
    //   Sum: '<S21>/Add1'
    //   Sum: '<S21>/Add2'

    if (wheel_odometry_B.yaw + wheel_odometry_P.Constant_Value_lo <
        wheel_odometry_B.Add) {
      wheel_odometry_B.Add = (wheel_odometry_B.Add -
        wheel_odometry_P.Constant1_Value_e) - wheel_odometry_B.yaw;
    } else {
      wheel_odometry_B.Add -= wheel_odometry_B.yaw;
    }

    // End of Switch: '<S21>/Switch'
    // End of Outputs for SubSystem: '<S10>/If Action Subsystem'

    // Outputs for IfAction SubSystem: '<S10>/If Action Subsystem1' incorporates:
    //   ActionPort: '<S22>/Action Port'

  } else if (wheel_odometry_B.yaw - wheel_odometry_P.Constant_Value_d >
             wheel_odometry_B.Add) {
    // Switch: '<S22>/Switch' incorporates:
    //   Constant: '<S22>/Constant1'
    //   Sum: '<S22>/Add1'

    wheel_odometry_B.Add += wheel_odometry_P.Constant1_Value_f -
      wheel_odometry_B.yaw;
  } else {
    // Switch: '<S22>/Switch' incorporates:
    //   Sum: '<S22>/Add2'

    wheel_odometry_B.Add -= wheel_odometry_B.yaw;

    // End of Outputs for SubSystem: '<S10>/If Action Subsystem1'
  }

  // End of If: '<S10>/If'

  // Outputs for Enabled SubSystem: '<Root>/Subsystem1' incorporates:
  //   EnablePort: '<S7>/Enable'

  // MATLABSystem: '<S3>/SourceBlock' incorporates:
  //   MATLAB Function: '<S7>/MATLAB Function'

  if (b_varargout_1) {
    // ManualSwitch: '<S18>/Manual Switch' incorporates:
    //   Constant: '<S18>/Constant'
    //   Gain: '<S18>/Gain'
    //   MATLABSystem: '<Root>/Get Parameter'
    //   Product: '<Root>/Product'
    //   Product: '<S18>/Product'

    if (wheel_odometry_P.ManualSwitch_CurrentSetting == 1) {
      wheel_odometry_B.b_value = (((wheel_odometry_B.b_value *
        wheel_odometry_B.ImpAsg_InsertedFor_x_at_i_d[0] *
        wheel_odometry_P.Constant_Value_j0[0] + wheel_odometry_B.b_value *
        wheel_odometry_B.ImpAsg_InsertedFor_x_at_i_d[1] *
        wheel_odometry_P.Constant_Value_j0[1]) + wheel_odometry_B.b_value *
        wheel_odometry_B.ImpAsg_InsertedFor_x_at_i_d[2] *
        wheel_odometry_P.Constant_Value_j0[2]) + wheel_odometry_B.b_value *
        wheel_odometry_B.ImpAsg_InsertedFor_x_at_i_d[3] *
        wheel_odometry_P.Constant_Value_j0[3]) * wheel_odometry_P.Gain_Gain;
    } else {
      wheel_odometry_B.b_value = ((wheel_odometry_B.b_value *
        wheel_odometry_B.ImpAsg_InsertedFor_x_at_i_d[0] *
        wheel_odometry_P.Constant_Value_j0[0] + wheel_odometry_B.b_value *
        wheel_odometry_B.ImpAsg_InsertedFor_x_at_i_d[1] *
        wheel_odometry_P.Constant_Value_j0[1]) + wheel_odometry_B.b_value *
        wheel_odometry_B.ImpAsg_InsertedFor_x_at_i_d[2] *
        wheel_odometry_P.Constant_Value_j0[2]) + wheel_odometry_B.b_value *
        wheel_odometry_B.ImpAsg_InsertedFor_x_at_i_d[3] *
        wheel_odometry_P.Constant_Value_j0[3];
    }

    // End of ManualSwitch: '<S18>/Manual Switch'

    // Reshape: '<S18>/Reshape1' incorporates:
    //   Gain: '<S18>/Gain1'
    //   Gain: '<S8>/Gain1'
    //   Product: '<S18>/Product1'
    //   Trigonometry: '<S18>/Tan'

    rtb_vxvy_idx_1 = wheel_odometry_P.Gain1_Gain * static_cast<real32_T>(tan(
      static_cast<real_T>(rtb_Gain1_0))) * wheel_odometry_B.b_value;

    // Chart: '<S7>/Chart' incorporates:
    //   Gain: '<S8>/Gain1'
    //   Reshape: '<S18>/Reshape1'

    if (wheel_odometry_DW.is_active_c4_wheel_odometry == 0U) {
      wheel_odometry_DW.is_active_c4_wheel_odometry = 1U;
      wheel_odometry_DW.is_c4_wheel_odometry = wheel_odometry_IN_hold;
      wheel_odometry_B.reset = false;
    } else {
      switch (wheel_odometry_DW.is_c4_wheel_odometry) {
       case wheel_odometry_IN_clearXY:
        if (wheel_odometry_DW.delay < 2) {
          wheel_odometry_DW.is_c4_wheel_odometry = wheel_odometry_IN_hold;
          wheel_odometry_B.reset = false;
        } else {
          wheel_odometry_DW.delay = static_cast<int16_T>(wheel_odometry_DW.delay
            - 1);
        }
        break;

       case wheel_odometry_IN_hold:
        s_idx_1_tmp = fabs(wheel_odometry_B.b_value);
        if ((s_idx_1_tmp < 0.01) && (rtb_Gain1_0 > 0.6)) {
          wheel_odometry_DW.is_c4_wheel_odometry = wheel_odometry_IN_waiting;
        } else if ((s_idx_1_tmp < 0.01) && (rtb_Gain1_0 < -0.6)) {
          wheel_odometry_DW.is_c4_wheel_odometry = wheel_odometry_IN_waiting1;
        } else {
          wheel_odometry_B.reset = false;
        }
        break;

       case wheel_odometry_IN_waiting:
        if (rtb_Gain1_0 < -0.6) {
          wheel_odometry_DW.is_c4_wheel_odometry = wheel_odometry_IN_clearXY;
          wheel_odometry_B.reset = true;
          wheel_odometry_DW.delay = 5;
        } else if (fabs(wheel_odometry_B.b_value) >= 0.1) {
          wheel_odometry_DW.is_c4_wheel_odometry = wheel_odometry_IN_hold;
          wheel_odometry_B.reset = false;
        }
        break;

       default:
        // case IN_waiting1:
        if (fabs(wheel_odometry_B.b_value) >= 0.1) {
          wheel_odometry_DW.is_c4_wheel_odometry = wheel_odometry_IN_hold;
          wheel_odometry_B.reset = false;
        } else if (rtb_Gain1_0 > 0.6) {
          wheel_odometry_DW.is_c4_wheel_odometry = wheel_odometry_IN_clearXY;
          wheel_odometry_B.reset = true;
          wheel_odometry_DW.delay = 5;
        }
        break;
      }
    }

    // End of Chart: '<S7>/Chart'

    // MATLAB Function: '<S7>/MATLAB Function'
    XY_dot_tmp = sin(wheel_odometry_B.Add);
    XY_dot_tmp_0 = cos(wheel_odometry_B.Add);

    // UnitDelay: '<S7>/Unit Delay'
    wheel_odometry_B.UnitDelay[0] = wheel_odometry_DW.UnitDelay_DSTATE[0];

    // MATLAB Function: '<S7>/MATLAB Function' incorporates:
    //   Reshape: '<S18>/Reshape1'

    XY_dot_tmp_1 = XY_dot_tmp_0 * wheel_odometry_B.b_value + -XY_dot_tmp *
      rtb_vxvy_idx_1;
    wheel_odometry_B.XY_dot[0] = XY_dot_tmp_1;

    // Switch: '<S7>/Switch' incorporates:
    //   Constant: '<S7>/Constant1'
    //   MATLAB Function: '<S7>/MATLAB Function'
    //   UnitDelay: '<S7>/Unit Delay'

    if (wheel_odometry_B.reset) {
      s_idx_1_tmp = wheel_odometry_P.Constant1_Value[0];
    } else {
      s_idx_1_tmp = wheel_odometry_DW.UnitDelay_DSTATE[0];
    }

    // Sum: '<S7>/Add' incorporates:
    //   Gain: '<S7>/Gain'
    //   MATLAB Function: '<S7>/MATLAB Function'
    //   Switch: '<S7>/Switch'
    //   UnitDelay: '<S7>/Unit Delay'

    wheel_odometry_DW.UnitDelay_DSTATE[0] = wheel_odometry_P.Gain_Gain_n *
      XY_dot_tmp_1 + s_idx_1_tmp;

    // UnitDelay: '<S7>/Unit Delay'
    wheel_odometry_B.UnitDelay[1] = wheel_odometry_DW.UnitDelay_DSTATE[1];

    // MATLAB Function: '<S7>/MATLAB Function' incorporates:
    //   Reshape: '<S18>/Reshape1'

    XY_dot_tmp = XY_dot_tmp * wheel_odometry_B.b_value + XY_dot_tmp_0 *
      rtb_vxvy_idx_1;
    wheel_odometry_B.XY_dot[1] = XY_dot_tmp;

    // Switch: '<S7>/Switch' incorporates:
    //   Constant: '<S7>/Constant1'
    //   MATLAB Function: '<S7>/MATLAB Function'
    //   UnitDelay: '<S7>/Unit Delay'

    if (wheel_odometry_B.reset) {
      s_idx_1_tmp = wheel_odometry_P.Constant1_Value[1];
    } else {
      s_idx_1_tmp = wheel_odometry_DW.UnitDelay_DSTATE[1];
    }

    // Sum: '<S7>/Add' incorporates:
    //   Gain: '<S7>/Gain'
    //   MATLAB Function: '<S7>/MATLAB Function'
    //   Switch: '<S7>/Switch'
    //   UnitDelay: '<S7>/Unit Delay'

    wheel_odometry_DW.UnitDelay_DSTATE[1] = wheel_odometry_P.Gain_Gain_n *
      XY_dot_tmp + s_idx_1_tmp;

    // MATLAB Function: '<S7>/MATLAB Function1' incorporates:
    //   Constant: '<S7>/Constant'

    wheel_odometry_B.b_value = wheel_odometry_B.Add / 2.0;
    s_idx_1_tmp = wheel_odometry_P.Constant_Value_e / 2.0;
    wheel_odometry_B.Add = cos(wheel_odometry_B.b_value);
    wheel_odometry_B.b_value = sin(wheel_odometry_B.b_value);
    rtb_vxvy_idx_1 = cos(s_idx_1_tmp);
    s_idx_1_tmp = sin(s_idx_1_tmp);
    XY_dot_tmp = wheel_odometry_B.Add * rtb_vxvy_idx_1;
    XY_dot_tmp_0 = wheel_odometry_B.b_value * s_idx_1_tmp;
    wheel_odometry_B.q[0] = XY_dot_tmp * rtb_vxvy_idx_1 + XY_dot_tmp_0 *
      s_idx_1_tmp;
    wheel_odometry_B.q[1] = XY_dot_tmp * s_idx_1_tmp - XY_dot_tmp_0 *
      rtb_vxvy_idx_1;
    XY_dot_tmp = wheel_odometry_B.b_value * rtb_vxvy_idx_1;
    XY_dot_tmp_0 = wheel_odometry_B.Add * s_idx_1_tmp;
    wheel_odometry_B.q[2] = XY_dot_tmp_0 * rtb_vxvy_idx_1 + XY_dot_tmp *
      s_idx_1_tmp;
    wheel_odometry_B.q[3] = XY_dot_tmp * rtb_vxvy_idx_1 - XY_dot_tmp_0 *
      s_idx_1_tmp;
  }

  // End of Outputs for SubSystem: '<Root>/Subsystem1'

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Constant: '<S1>/Constant'

  wheel_odometry_B.BusAssignment = wheel_odometry_P.Constant_Value;
  wheel_odometry_B.BusAssignment.twist.twist.linear.x = wheel_odometry_B.XY_dot
    [0];
  wheel_odometry_B.BusAssignment.twist.twist.linear.y = wheel_odometry_B.XY_dot
    [1];
  wheel_odometry_B.BusAssignment.pose.pose.position.x =
    wheel_odometry_B.UnitDelay[0];
  wheel_odometry_B.BusAssignment.pose.pose.position.y =
    wheel_odometry_B.UnitDelay[1];
  wheel_odometry_B.BusAssignment.pose.pose.orientation.w = wheel_odometry_B.q[0];
  wheel_odometry_B.BusAssignment.pose.pose.orientation.x = wheel_odometry_B.q[1];
  wheel_odometry_B.BusAssignment.pose.pose.orientation.y = wheel_odometry_B.q[2];
  wheel_odometry_B.BusAssignment.pose.pose.orientation.z = wheel_odometry_B.q[3];

  // MATLABSystem: '<S2>/SinkBlock'
  Pub_wheel_odometry_253.publish(&wheel_odometry_B.BusAssignment);

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  (&wheel_odometry_M)->Timing.t[0] =
    ((time_T)(++(&wheel_odometry_M)->Timing.clockTick0)) * (&wheel_odometry_M)
    ->Timing.stepSize0;

  {
    // Update absolute timer for sample time: [0.01s, 0.0s]
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 0.01, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    (&wheel_odometry_M)->Timing.clockTick1++;
  }
}

// Model initialize function
void wheel_odometry::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&(&wheel_odometry_M)->solverInfo, &(&wheel_odometry_M
                          )->Timing.simTimeStep);
    rtsiSetTPtr(&(&wheel_odometry_M)->solverInfo, &rtmGetTPtr((&wheel_odometry_M)));
    rtsiSetStepSizePtr(&(&wheel_odometry_M)->solverInfo, &(&wheel_odometry_M)
                       ->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&(&wheel_odometry_M)->solverInfo, (&rtmGetErrorStatus
      ((&wheel_odometry_M))));
    rtsiSetRTModelPtr(&(&wheel_odometry_M)->solverInfo, (&wheel_odometry_M));
  }

  rtsiSetSimTimeStep(&(&wheel_odometry_M)->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&(&wheel_odometry_M)->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr((&wheel_odometry_M), &(&wheel_odometry_M)->Timing.tArray[0]);
  (&wheel_odometry_M)->Timing.stepSize0 = 0.01;

  {
    int32_T i;
    static const char_T tmp[14] = { 'W', 'h', 'e', 'e', 'l', 'S', 'p', 'd', '_',
      's', 'c', 'a', 'l', 'e' };

    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S12>/In1' incorporates:
    //   Outport: '<S12>/Out1'

    wheel_odometry_B.In1_b = wheel_odometry_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S11>/In1' incorporates:
    //   Outport: '<S11>/Out1'

    wheel_odometry_B.In1_bo = wheel_odometry_P.Out1_Y0_g;

    // End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S13>/In1' incorporates:
    //   Outport: '<S13>/Out1'

    wheel_odometry_B.In1 = wheel_odometry_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S23>/Enabled Subsystem1'
    // SystemInitialize for SignalConversion generated from: '<S25>/yaw' incorporates:
    //   Outport: '<S25>/Out1'

    wheel_odometry_B.yaw = wheel_odometry_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S23>/Enabled Subsystem1'

    // SystemInitialize for Enabled SubSystem: '<Root>/Subsystem1'
    // InitializeConditions for UnitDelay: '<S7>/Unit Delay'
    wheel_odometry_DW.UnitDelay_DSTATE[0] =
      wheel_odometry_P.UnitDelay_InitialCondition;

    // SystemInitialize for Outport: '<S7>/XY_dot'
    wheel_odometry_B.XY_dot[0] = wheel_odometry_P.XY_dot_Y0;

    // SystemInitialize for UnitDelay: '<S7>/Unit Delay' incorporates:
    //   Outport: '<S7>/XY'

    wheel_odometry_B.UnitDelay[0] = wheel_odometry_P.XY_Y0;

    // InitializeConditions for UnitDelay: '<S7>/Unit Delay'
    wheel_odometry_DW.UnitDelay_DSTATE[1] =
      wheel_odometry_P.UnitDelay_InitialCondition;

    // SystemInitialize for Outport: '<S7>/XY_dot'
    wheel_odometry_B.XY_dot[1] = wheel_odometry_P.XY_dot_Y0;

    // SystemInitialize for UnitDelay: '<S7>/Unit Delay' incorporates:
    //   Outport: '<S7>/XY'

    wheel_odometry_B.UnitDelay[1] = wheel_odometry_P.XY_Y0;

    // SystemInitialize for Outport: '<S7>/orientation'
    wheel_odometry_B.q[0] = wheel_odometry_P.orientation_Y0;
    wheel_odometry_B.q[1] = wheel_odometry_P.orientation_Y0;
    wheel_odometry_B.q[2] = wheel_odometry_P.orientation_Y0;
    wheel_odometry_B.q[3] = wheel_odometry_P.orientation_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/Subsystem1'

    // Start for MATLABSystem: '<S4>/SourceBlock'
    wheel_odometry_DW.obj_l.isInitialized = 0;
    wheel_odometry_DW.obj_l.matlabCodegenIsDeleted = false;
    wheel_odome_SystemCore_setup_pb(&wheel_odometry_DW.obj_l);

    // Start for MATLABSystem: '<S3>/SourceBlock'
    wheel_odometry_DW.obj_j.isInitialized = 0;
    wheel_odometry_DW.obj_j.matlabCodegenIsDeleted = false;
    wheel_odomet_SystemCore_setup_p(&wheel_odometry_DW.obj_j);

    // Start for MATLABSystem: '<Root>/Get Parameter'
    wheel_odometry_DW.obj.matlabCodegenIsDeleted = false;
    wheel_odometry_DW.obj.isInitialized = 1;
    for (i = 0; i < 14; i++) {
      wheel_odometry_B.prmName[i] = tmp[i];
    }

    wheel_odometry_B.prmName[14] = '\x00';
    ParamGet_wheel_odometry_353.initParam(&wheel_odometry_B.prmName[0]);
    ParamGet_wheel_odometry_353.setInitialValue(1.0);
    wheel_odometry_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Get Parameter'

    // Start for MATLABSystem: '<S5>/SourceBlock'
    wheel_odometry_DW.obj_a.isInitialized = 0;
    wheel_odometry_DW.obj_a.matlabCodegenIsDeleted = false;
    wheel_odom_SystemCore_setup_pbe(&wheel_odometry_DW.obj_a);

    // Start for MATLABSystem: '<S2>/SinkBlock'
    wheel_odometry_DW.obj_o.isInitialized = 0;
    wheel_odometry_DW.obj_o.matlabCodegenIsDeleted = false;
    wheel_odometry_SystemCore_setup(&wheel_odometry_DW.obj_o);
  }
}

// Model terminate function
void wheel_odometry::terminate()
{
  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!wheel_odometry_DW.obj_l.matlabCodegenIsDeleted) {
    wheel_odometry_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'

  // Terminate for MATLABSystem: '<S3>/SourceBlock'
  if (!wheel_odometry_DW.obj_j.matlabCodegenIsDeleted) {
    wheel_odometry_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SourceBlock'

  // Terminate for MATLABSystem: '<Root>/Get Parameter'
  if (!wheel_odometry_DW.obj.matlabCodegenIsDeleted) {
    wheel_odometry_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter'

  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!wheel_odometry_DW.obj_a.matlabCodegenIsDeleted) {
    wheel_odometry_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'

  // Terminate for MATLABSystem: '<S2>/SinkBlock'
  if (!wheel_odometry_DW.obj_o.matlabCodegenIsDeleted) {
    wheel_odometry_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/SinkBlock'
}

// Constructor
wheel_odometry::wheel_odometry() :
  wheel_odometry_B(),
  wheel_odometry_DW(),
  wheel_odometry_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
wheel_odometry::~wheel_odometry()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_wheel_odometry_T * wheel_odometry::getRTM()
{
  return (&wheel_odometry_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
