//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: motion_controller_slx.cpp
//
// Code generated for Simulink model 'motion_controller_slx'.
//
// Model version                  : 2.185
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Wed May 22 23:51:40 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "motion_controller_slx.h"
#include "rtwtypes.h"
#include "motion_controller_slx_types.h"
#include <math.h>

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_atan2d_snf.h"
#include <string.h>
#include "rmw/qos_profiles.h"
#include <stddef.h>

// Named constants for Chart: '<S3>/Chart'
const uint8_T motion_contr_IN_NO_ACTIVE_CHILD = 0U;
const uint8_T motion_contro_IN_velocity_mode1 = 2U;
const uint8_T motion_control_IN_velocity_mode = 4U;
const uint8_T motion_controlle_IN_effort_mode = 2U;
const uint8_T motion_controller_sl_IN_braking = 1U;
const uint8_T motion_controller_sl_IN_forward = 2U;
const uint8_T motion_controller_slx_IN_Ini = 1U;
const uint8_T motion_controller_slx_IN_hold = 3U;

// System initialize for atomic system:
void motion_controller_slx::motion_control_CurrentTime_Init
  (DW_CurrentTime_motion_control_T *localDW)
{
  // Start for MATLABSystem: '<S2>/Current Time'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void motion_controller_slx::motion_controller_s_CurrentTime
  (B_CurrentTime_motion_controll_T *localB)
{
  // MATLABSystem: '<S2>/Current Time'
  currentROS2TimeBus(&localB->CurrentTime);
}

// Termination for atomic system:
void motion_controller_slx::motion_control_CurrentTime_Term
  (DW_CurrentTime_motion_control_T *localDW)
{
  // Terminate for MATLABSystem: '<S2>/Current Time'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/Current Time'
}

//
// System initialize for atomic system:
//    '<S14>/Chart1'
//    '<S14>/Chart4'
//
void motion_controller_slx::motion_controller_s_Chart1_Init(real_T *rty_out)
{
  *rty_out = 0.0;
}

//
// Output and update for atomic system:
//    '<S14>/Chart1'
//    '<S14>/Chart4'
//
void motion_controller_slx::motion_controller_slx_Chart1(real_T
  rtu_steer_rate_dps, real_T rtu_angle, real_T *rty_out,
  DW_Chart1_motion_controller_s_T *localDW)
{
  // Chart: '<S14>/Chart1'
  if (localDW->is_active_c7_motion_controller_ == 0U) {
    localDW->is_active_c7_motion_controller_ = 1U;
    *rty_out = 0.0;
  } else {
    real_T direction;
    direction = rtu_angle - *rty_out;
    if (fabs(direction) < 0.001) {
      *rty_out = rtu_angle;
    } else if (rtu_steer_rate_dps == 0.0) {
      *rty_out = rtu_angle;
    } else {
      if (rtIsNaN(direction)) {
        direction = (rtNaN);
      } else if (direction < 0.0) {
        direction = -1.0;
      } else {
        direction = (direction > 0.0);
      }

      *rty_out += direction * rtu_steer_rate_dps / 180.0 * 3.1415926535897931 *
        0.01;
    }
  }

  // End of Chart: '<S14>/Chart1'
}

// Output and update for Simulink Function: '<S3>/get_angle_4w'
void motion_controller_slx::motion_controller__get_angle_4w(real_T rtu_delta_f,
  real_T rtu_delta_r, real_T rty_angle_cmd[4]) const
{
  real_T deltaFR;
  real_T deltaRL;
  real_T deltaRR;

  // MATLAB Function: '<S15>/MATLAB Function' incorporates:
  //   SignalConversion generated from: '<S15>/In1'
  //   SignalConversion generated from: '<S15>/angle1'
  //   SignalConversion generated from: '<S15>/angle'

  if (motion_controller_slx_B.GetParameter1 == 1.0) {
    real_T deltaFL_tmp;
    real_T deltaFR_tmp;
    real_T deltaRL_tmp;
    if (rtIsNaN(rtu_delta_f)) {
      deltaFR = (rtNaN);
    } else if (rtu_delta_f < 0.0) {
      deltaFR = -1.0;
    } else {
      deltaFR = (rtu_delta_f > 0.0);
    }

    if (rtIsNaN(rtu_delta_r)) {
      deltaRR = (rtNaN);
    } else if (rtu_delta_r < 0.0) {
      deltaRR = -1.0;
    } else {
      deltaRR = (rtu_delta_r > 0.0);
    }

    deltaFL_tmp = tan(fabs(rtu_delta_f));
    deltaRL = tan(fabs(rtu_delta_r));
    deltaRL_tmp = 2.0 * motion_controller_slx_P.L * deltaFL_tmp;
    deltaFR_tmp = (deltaFR * deltaFL_tmp - deltaRR * deltaRL) *
      motion_controller_slx_P.Tw;
    deltaFL_tmp = 2.0 * motion_controller_slx_P.L - deltaFR_tmp;

    // SignalConversion generated from: '<S15>/angle_cmd' incorporates:
    //   SignalConversion generated from: '<S15>/angle1'
    //   SignalConversion generated from: '<S15>/angle'

    rty_angle_cmd[0] = atan(deltaRL_tmp / deltaFL_tmp) * deltaFR;
    deltaFR_tmp += 2.0 * motion_controller_slx_P.L;
    deltaFR *= atan(deltaRL_tmp / deltaFR_tmp);
    deltaRL_tmp = 2.0 * motion_controller_slx_P.L * deltaRL;
    deltaRL = atan(deltaRL_tmp / deltaFL_tmp) * deltaRR;
    deltaRR *= atan(deltaRL_tmp / deltaFR_tmp);
  } else {
    // SignalConversion generated from: '<S15>/angle_cmd' incorporates:
    //   SignalConversion generated from: '<S15>/angle'

    rty_angle_cmd[0] = rtu_delta_f;
    deltaFR = rtu_delta_f;
    deltaRR = rtu_delta_r;
    deltaRL = rtu_delta_r;
  }

  // SignalConversion generated from: '<S15>/angle_cmd' incorporates:
  //   MATLAB Function: '<S15>/MATLAB Function'

  rty_angle_cmd[1] = deltaFR;
  rty_angle_cmd[2] = deltaRR;
  rty_angle_cmd[3] = deltaRL;
}

// System initialize for Simulink Function: '<S3>/get_effort'
void motion_controller_slx::motion_controll_get_effort_Init()
{
  static const char_T prmName[10] = "effortMax";

  // Start for MATLABSystem: '<S16>/Get Parameter'
  motion_controller_slx_DW.obj.matlabCodegenIsDeleted = false;
  motion_controller_slx_DW.obj.isInitialized = 1;
  ParamGet_motion_controller_slx_202.initParam(&prmName[0]);
  ParamGet_motion_controller_slx_202.setInitialValue(0.6);
  motion_controller_slx_DW.obj.isSetupComplete = true;
}

// Output and update for Simulink Function: '<S3>/get_effort'
void motion_controller_slx::motion_controller_sl_get_effort(real_T rtu_longdrive,
  real_T rty_effort_cmd[4])
{
  real_T b_value;

  // MATLABSystem: '<S16>/Get Parameter'
  ParamGet_motion_controller_slx_202.getParameter(&b_value);

  // MATLAB Function: '<S16>/MATLAB Function' incorporates:
  //   MATLABSystem: '<S16>/Get Parameter'
  //   SignalConversion generated from: '<S16>/angle'

  b_value *= rtu_longdrive;

  // SignalConversion generated from: '<S16>/angle_cmd' incorporates:
  //   MATLAB Function: '<S16>/MATLAB Function'

  rty_effort_cmd[0] = b_value;
  rty_effort_cmd[1] = -b_value;
  rty_effort_cmd[2] = -b_value;
  rty_effort_cmd[3] = b_value;
}

// Termination for Simulink Function: '<S3>/get_effort'
void motion_controller_slx::motion_controll_get_effort_Term()
{
  // Terminate for MATLABSystem: '<S16>/Get Parameter'
  if (!motion_controller_slx_DW.obj.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S16>/Get Parameter'
}

// Output and update for Simulink Function: '<S3>/get_spd'
void motion_controller_slx::motion_controller_slx_get_spd(real_T rtu_angle,
  real_T rtu_longdrive, real_T rty_spd_cmd[4]) const
{
  real_T b_x;
  real_T vFR;
  real_T vRL;
  real_T vRR;
  real_T vRR_tmp;

  // MATLAB Function: '<S17>/MATLAB Function' incorporates:
  //   Constant: '<S17>/Constant'
  //   SignalConversion generated from: '<S17>/angle'
  //   SignalConversion generated from: '<S17>/longdrive'

  if (motion_controller_slx_P.Constant_Value_o == 1.0) {
    vRL = motion_controller_slx_P.L / (tan(rtu_angle) + 1.0E-9);
    if (vRL >= 0.0) {
      b_x = rt_atan2d_snf(motion_controller_slx_P.L, vRL -
                          motion_controller_slx_P.Tw / 2.0);
      vFR = rt_atan2d_snf(motion_controller_slx_P.L, motion_controller_slx_P.Tw /
                          2.0 + vRL);
    } else {
      b_x = rt_atan2d_snf(motion_controller_slx_P.L, vRL -
                          motion_controller_slx_P.Tw / 2.0) - 3.1415926535897931;
      vFR = rt_atan2d_snf(motion_controller_slx_P.L, motion_controller_slx_P.Tw /
                          2.0 + vRL) - 3.1415926535897931;
    }

    vRR_tmp = cos(asin(motion_controller_slx_P.b / vRL));
    vRR = (motion_controller_slx_P.Tw / 2.0 + vRL) / vRL * rtu_longdrive *
      vRR_tmp;
    vRL = (vRL - motion_controller_slx_P.Tw / 2.0) / vRL * rtu_longdrive *
      vRR_tmp;
    vFR = vRR / cos(vFR);

    // SignalConversion generated from: '<S17>/spd_cmd' incorporates:
    //   SignalConversion generated from: '<S17>/angle'
    //   SignalConversion generated from: '<S17>/longdrive'

    rty_spd_cmd[0] = vRL / cos(b_x);
  } else {
    // SignalConversion generated from: '<S17>/spd_cmd' incorporates:
    //   SignalConversion generated from: '<S17>/longdrive'

    rty_spd_cmd[0] = rtu_longdrive;
    vFR = rtu_longdrive;
    vRL = rtu_longdrive;
    vRR = rtu_longdrive;
  }

  // SignalConversion generated from: '<S17>/spd_cmd' incorporates:
  //   MATLAB Function: '<S17>/MATLAB Function'

  rty_spd_cmd[1] = -vFR;
  rty_spd_cmd[2] = -vRR;
  rty_spd_cmd[3] = vRL;
}

void motion_controller_slx::motion_control_SystemCore_setup
  (ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[11];
  static const char_T b_zeroDelimTopic_0[11] = "/motor_cmd";

  // Start for MATLABSystem: '<S9>/SinkBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S9>/SinkBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)5.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 11; i++) {
    // Start for MATLABSystem: '<S9>/SinkBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Pub_motion_controller_slx_4.createPublisher(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_slx::motion_contr_SystemCore_setup_o
  (ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[11];
  static const char_T b_zeroDelimTopic_0[11] = "/servo_cmd";

  // Start for MATLABSystem: '<S10>/SinkBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S10>/SinkBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)10.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 11; i++) {
    // Start for MATLABSystem: '<S10>/SinkBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Pub_motion_controller_slx_148.createPublisher(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_slx::motion_cont_SystemCore_setup_o0
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[6];
  static const char_T b_zeroDelimTopic_0[6] = "/sbus";

  // Start for MATLABSystem: '<S26>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S26>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  for (int32_T i = 0; i < 6; i++) {
    // Start for MATLABSystem: '<S26>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_motion_controller_slx_1.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_slx::motion_con_SystemCore_setup_o0a
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[13];
  static const char_T b_zeroDelimTopic_0[13] = "/motor_state";

  // Start for MATLABSystem: '<S27>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S27>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  for (int32_T i = 0; i < 13; i++) {
    // Start for MATLABSystem: '<S27>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_motion_controller_slx_238.createSubscriber(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

// Model step function
void motion_controller_slx::step()
{
  int16_T tmp;
  boolean_T b_value;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_LogicalOperator_l;

  // MATLABSystem: '<S26>/SourceBlock'
  rtb_LogicalOperator_l = Sub_motion_controller_slx_1.getLatestMessage
    (&motion_controller_slx_B.b_varargout_2_m);

  // Outputs for Enabled SubSystem: '<S26>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S29>/Enable'

  // Start for MATLABSystem: '<S26>/SourceBlock'
  if (rtb_LogicalOperator_l) {
    // SignalConversion generated from: '<S29>/In1'
    motion_controller_slx_B.In1_m = motion_controller_slx_B.b_varargout_2_m;
  }

  // End of Outputs for SubSystem: '<S26>/Enabled Subsystem'

  // Logic: '<Root>/Logical Operator'
  rtb_LogicalOperator = (motion_controller_slx_B.In1_m.failsafe ||
    motion_controller_slx_B.In1_m.frame_lost);

  // MATLABSystem: '<S27>/SourceBlock'
  b_value = Sub_motion_controller_slx_238.getLatestMessage
    (&motion_controller_slx_B.b_varargout_2);

  // Logic: '<S4>/Logical Operator' incorporates:
  //   MATLABSystem: '<S26>/SourceBlock'
  //   MATLABSystem: '<S27>/SourceBlock'
  //
  rtb_LogicalOperator_l = (rtb_LogicalOperator_l && b_value);

  // Outputs for Enabled SubSystem: '<S27>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S30>/Enable'

  // Start for MATLABSystem: '<S27>/SourceBlock'
  if (b_value) {
    // SignalConversion generated from: '<S30>/In1'
    motion_controller_slx_B.In1 = motion_controller_slx_B.b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S27>/Enabled Subsystem'

  // Outputs for Iterator SubSystem: '<S4>/For Each Subsystem' incorporates:
  //   ForEach: '<S25>/For Each'

  for (motion_controller_slx_B.ForEach_itr = 0;
       motion_controller_slx_B.ForEach_itr < 16;
       motion_controller_slx_B.ForEach_itr++) {
    // ForEachSliceAssignment generated from: '<S25>/Out1' incorporates:
    //   ForEachSliceSelector generated from: '<S25>/In1'

    motion_controller_slx_B.ImpAsg_InsertedFor_Out1_at_[motion_controller_slx_B.ForEach_itr]
      =
      motion_controller_slx_B.In1.actuator_state[motion_controller_slx_B.ForEach_itr]
      .velocity;
  }

  // End of Outputs for SubSystem: '<S4>/For Each Subsystem'

  // Gain: '<S4>/Gain'
  motion_controller_slx_B.rtb_Gain_c = ((motion_controller_slx_P.Gain_Gain_n[0] *
    motion_controller_slx_B.ImpAsg_InsertedFor_Out1_at_[0] +
    motion_controller_slx_P.Gain_Gain_n[1] *
    motion_controller_slx_B.ImpAsg_InsertedFor_Out1_at_[1]) +
    motion_controller_slx_P.Gain_Gain_n[2] *
    motion_controller_slx_B.ImpAsg_InsertedFor_Out1_at_[2]) +
    motion_controller_slx_P.Gain_Gain_n[3] *
    motion_controller_slx_B.ImpAsg_InsertedFor_Out1_at_[3];

  // Outputs for Atomic SubSystem: '<Root>/controller'
  // MATLABSystem: '<S14>/Get Parameter4'
  ParamGet_motion_controller_slx_298.getParameter
    (&motion_controller_slx_B.b_value);

  // MATLABSystem: '<S14>/Get Parameter2'
  ParamGet_motion_controller_slx_301.getParameter
    (&motion_controller_slx_B.b_value_c);

  // MATLABSystem: '<S14>/Get Parameter3'
  ParamGet_motion_controller_slx_194.getParameter
    (&motion_controller_slx_B.b_value_k);

  // Switch: '<S14>/Switch' incorporates:
  //   MATLABSystem: '<S14>/Get Parameter2'
  //   SignalConversion generated from: '<S4>/Bus Selector'

  if (motion_controller_slx_B.b_value_c != 0.0) {
    tmp = motion_controller_slx_B.In1_m.mapped_channels[2];
  } else {
    tmp = motion_controller_slx_B.In1_m.mapped_channels[1];
  }

  // Product: '<S14>/Product1' incorporates:
  //   Constant: '<S14>/Constant2'
  //   Gain: '<S14>/Gain1'
  //   MATLABSystem: '<S14>/Get Parameter3'
  //   Sum: '<S14>/Add1'
  //   Switch: '<S14>/Switch'

  motion_controller_slx_B.b_value_k *= (static_cast<real_T>(tmp) -
    motion_controller_slx_P.Constant2_Value) *
    motion_controller_slx_P.Gain1_Gain;

  // Chart: '<S14>/Chart2' incorporates:
  //   MATLABSystem: '<S14>/Get Parameter4'

  if (motion_controller_slx_DW.is_active_c6_motion_controller_ == 0U) {
    motion_controller_slx_DW.is_active_c6_motion_controller_ = 1U;
    motion_controller_slx_B.out_k = 0.0;
  } else {
    motion_controller_slx_B.b_value_c = motion_controller_slx_B.b_value_k -
      motion_controller_slx_B.out_k;
    if (fabs(motion_controller_slx_B.b_value_c) < 0.001) {
      motion_controller_slx_B.out_k = motion_controller_slx_B.b_value_k;
    } else if (motion_controller_slx_B.b_value == 0.0) {
      motion_controller_slx_B.out_k = motion_controller_slx_B.b_value_k;
    } else {
      if (rtIsNaN(motion_controller_slx_B.b_value_c)) {
        motion_controller_slx_B.b_value_c = (rtNaN);
      } else if (motion_controller_slx_B.b_value_c < 0.0) {
        motion_controller_slx_B.b_value_c = -1.0;
      } else {
        motion_controller_slx_B.b_value_c = (motion_controller_slx_B.b_value_c >
          0.0);
      }

      motion_controller_slx_B.out_k += motion_controller_slx_B.b_value_c *
        motion_controller_slx_B.b_value * 0.01;
    }
  }

  // End of Chart: '<S14>/Chart2'

  // MATLABSystem: '<S14>/Get Parameter1'
  ParamGet_motion_controller_slx_317.getParameter
    (&motion_controller_slx_B.b_value);

  // MATLABSystem: '<S14>/Get Parameter5'
  ParamGet_motion_controller_slx_329.getParameter(&b_value);

  // Gain: '<S14>/Gain2' incorporates:
  //   Constant: '<S14>/Constant'
  //   Gain: '<S14>/Gain'
  //   SignalConversion generated from: '<S4>/Bus Selector'
  //   Sum: '<S14>/Add'

  motion_controller_slx_B.Gain2 = (static_cast<real_T>
    (motion_controller_slx_B.In1_m.mapped_channels[0]) -
    motion_controller_slx_P.Constant_Value_ff) *
    motion_controller_slx_P.Gain_Gain * motion_controller_slx_P.Gain2_Gain;

  // Chart: '<S14>/Chart3' incorporates:
  //   MATLABSystem: '<S14>/Get Parameter5'

  if (motion_controller_slx_DW.is_active_c8_motion_controller_ == 0U) {
    motion_controller_slx_DW.is_active_c8_motion_controller_ = 1U;
    if (b_value) {
      motion_controller_slx_B.rtb_df_tmp = fabs(motion_controller_slx_B.Gain2);
      b_value = rtIsNaN(motion_controller_slx_B.Gain2);
      if (b_value) {
        motion_controller_slx_B.b_value_c = (rtNaN);
      } else if (motion_controller_slx_B.Gain2 < 0.0) {
        motion_controller_slx_B.b_value_c = -1.0;
      } else {
        motion_controller_slx_B.b_value_c = (motion_controller_slx_B.Gain2 > 0.0);
      }

      if (motion_controller_slx_B.rtb_df_tmp <= 0.5) {
        motion_controller_slx_B.b_value_k = motion_controller_slx_B.rtb_df_tmp;
      } else {
        motion_controller_slx_B.b_value_k = 0.5;
      }

      motion_controller_slx_B.b_value_k = motion_controller_slx_B.b_value_c *
        motion_controller_slx_B.b_value_k * 2.0;
      if (motion_controller_slx_B.rtb_df_tmp > 0.5) {
        if (b_value) {
          motion_controller_slx_B.b_value_c = (rtNaN);
        } else if (motion_controller_slx_B.Gain2 < 0.0) {
          motion_controller_slx_B.b_value_c = -1.0;
        } else {
          motion_controller_slx_B.b_value_c = (motion_controller_slx_B.Gain2 >
            0.0);
        }

        motion_controller_slx_B.Gain2 = (motion_controller_slx_B.rtb_df_tmp -
          0.5) * -motion_controller_slx_B.b_value_c * 2.0;
      } else {
        motion_controller_slx_B.Gain2 = 0.0;
      }
    } else {
      motion_controller_slx_B.b_value_k = motion_controller_slx_B.Gain2;
      motion_controller_slx_B.Gain2 = 0.0;
    }
  } else if (b_value) {
    motion_controller_slx_B.rtb_df_tmp = fabs(motion_controller_slx_B.Gain2);
    if (rtIsNaN(motion_controller_slx_B.Gain2)) {
      motion_controller_slx_B.Gain2 = (rtNaN);
    } else if (motion_controller_slx_B.Gain2 < 0.0) {
      motion_controller_slx_B.Gain2 = -1.0;
    } else {
      motion_controller_slx_B.Gain2 = (motion_controller_slx_B.Gain2 > 0.0);
    }

    if (motion_controller_slx_B.rtb_df_tmp <= 0.5) {
      motion_controller_slx_B.b_value_c = motion_controller_slx_B.rtb_df_tmp;
    } else {
      motion_controller_slx_B.b_value_c = 0.5;
    }

    motion_controller_slx_B.b_value_k = motion_controller_slx_B.Gain2 *
      motion_controller_slx_B.b_value_c * 2.0;
    if (motion_controller_slx_B.rtb_df_tmp > 0.5) {
      motion_controller_slx_B.Gain2 = (motion_controller_slx_B.rtb_df_tmp - 0.5)
        * -motion_controller_slx_B.Gain2 * 2.0;
    } else {
      motion_controller_slx_B.Gain2 = 0.0;
    }
  } else {
    motion_controller_slx_B.b_value_k = motion_controller_slx_B.Gain2;
    motion_controller_slx_B.Gain2 = 0.0;
  }

  // End of Chart: '<S14>/Chart3'

  // MATLABSystem: '<S14>/Get Parameter'
  ParamGet_motion_controller_slx_316.getParameter
    (&motion_controller_slx_B.b_value_c);

  // Chart: '<S14>/Chart4' incorporates:
  //   MATLABSystem: '<S14>/Get Parameter'
  //   MATLABSystem: '<S14>/Get Parameter1'
  //   Product: '<S14>/Product2'

  motion_controller_slx_Chart1(motion_controller_slx_B.b_value,
    motion_controller_slx_B.b_value_k * motion_controller_slx_B.b_value_c,
    &motion_controller_slx_B.out, &motion_controller_slx_DW.sf_Chart4);

  // Chart: '<S14>/Chart1' incorporates:
  //   MATLABSystem: '<S14>/Get Parameter'
  //   MATLABSystem: '<S14>/Get Parameter1'
  //   Product: '<S14>/Product'

  motion_controller_slx_Chart1(motion_controller_slx_B.b_value,
    motion_controller_slx_B.Gain2 * motion_controller_slx_B.b_value_c,
    &motion_controller_slx_B.out_o, &motion_controller_slx_DW.sf_Chart1);

  // MATLABSystem: '<S3>/Get Parameter1'
  ParamGet_motion_controller_slx_217.getParameter
    (&motion_controller_slx_B.GetParameter1);

  // Chart: '<S3>/Chart' incorporates:
  //   Gain: '<S4>/Gain'
  //   SignalConversion generated from: '<S4>/Bus Selector'

  if (motion_controller_slx_DW.is_active_c3_motion_controller_ == 0U) {
    motion_controller_slx_DW.is_active_c3_motion_controller_ = 1U;
    motion_controller_slx_DW.is_Is_ready = motion_controller_slx_IN_Ini;
    motion_controller_slx_DW.check = 1.0;
    motion_controller_slx_DW.ready = false;
    motion_controller_slx_DW.is_cmd = motion_controller_slx_IN_Ini;
    motion_controller_slx_B.angle_cmd[0] = 0.0;
    motion_controller_slx_B.spd_cmd[0] = 0.0;
    motion_controller_slx_B.effort_cmd[0] = 0.0;
    motion_controller_slx_B.angle_cmd[1] = 0.0;
    motion_controller_slx_B.spd_cmd[1] = 0.0;
    motion_controller_slx_B.effort_cmd[1] = 0.0;
    motion_controller_slx_B.angle_cmd[2] = 0.0;
    motion_controller_slx_B.spd_cmd[2] = 0.0;
    motion_controller_slx_B.effort_cmd[2] = 0.0;
    motion_controller_slx_B.angle_cmd[3] = 0.0;
    motion_controller_slx_B.spd_cmd[3] = 0.0;
    motion_controller_slx_B.effort_cmd[3] = 0.0;
    motion_controller_slx_B.mode = 0;
  } else {
    if (motion_controller_slx_DW.is_Is_ready == motion_controller_slx_IN_Ini) {
      if ((motion_controller_slx_B.In1_m.mapped_channels[3] == 1000) &&
          (!rtb_LogicalOperator) && rtb_LogicalOperator_l) {
        motion_controller_slx_DW.is_Is_ready = motion_contro_IN_velocity_mode1;
        motion_controller_slx_DW.ready = true;
        motion_controller_slx_DW.check = 1.0;
        motion_controller_slx_DW.sum = 0.0;
        motion_controller_slx_DW.counter = 0.0;
      }

      // case IN_velocity_mode1:
    } else if ((motion_controller_slx_B.In1_m.mapped_channels[3] != 1000) ||
               rtb_LogicalOperator || (motion_controller_slx_DW.check == 0.0)) {
      motion_controller_slx_DW.is_Is_ready = motion_controller_slx_IN_Ini;
      motion_controller_slx_DW.check = 1.0;
      motion_controller_slx_DW.ready = false;
    } else {
      motion_controller_slx_DW.counter++;
      motion_controller_slx_DW.sum += static_cast<real_T>(rtb_LogicalOperator_l);
      if (rtIsNaN(motion_controller_slx_DW.counter)) {
        motion_controller_slx_B.b_value = (rtNaN);
      } else if (rtIsInf(motion_controller_slx_DW.counter)) {
        motion_controller_slx_B.b_value = (rtNaN);
      } else if (motion_controller_slx_DW.counter == 0.0) {
        motion_controller_slx_B.b_value = 0.0;
      } else {
        motion_controller_slx_B.b_value = fmod(motion_controller_slx_DW.counter,
          20.0);
        if (motion_controller_slx_B.b_value == 0.0) {
          motion_controller_slx_B.b_value = 0.0;
        } else if (motion_controller_slx_DW.counter < 0.0) {
          motion_controller_slx_B.b_value += 20.0;
        }
      }

      if (motion_controller_slx_B.b_value == 0.0) {
        motion_controller_slx_DW.check = motion_controller_slx_DW.sum;
        motion_controller_slx_DW.sum = 0.0;
      }
    }

    switch (motion_controller_slx_DW.is_cmd) {
     case motion_controller_slx_IN_Ini:
      if (motion_controller_slx_DW.ready) {
        motion_controller_slx_DW.is_cmd = motion_control_IN_velocity_mode;
        motion_controller_slx_B.effort_cmd[0] = 0.0;
        motion_controller_slx_B.effort_cmd[1] = 0.0;
        motion_controller_slx_B.effort_cmd[2] = 0.0;
        motion_controller_slx_B.effort_cmd[3] = 0.0;
      }
      break;

     case motion_controlle_IN_effort_mode:
      if ((motion_controller_slx_B.In1_m.mapped_channels[4] != 1000) ||
          (!motion_controller_slx_DW.ready)) {
        motion_controller_slx_DW.is_effort_mode =
          motion_contr_IN_NO_ACTIVE_CHILD;
        motion_controller_slx_DW.is_cmd = motion_control_IN_velocity_mode;
        motion_controller_slx_B.effort_cmd[0] = 0.0;
        motion_controller_slx_B.effort_cmd[1] = 0.0;
        motion_controller_slx_B.effort_cmd[2] = 0.0;
        motion_controller_slx_B.effort_cmd[3] = 0.0;
      } else if (motion_controller_slx_DW.is_effort_mode ==
                 motion_controller_sl_IN_braking) {
        if (motion_controller_slx_B.out_k >= 0.0) {
          motion_controller_slx_DW.is_effort_mode =
            motion_controller_sl_IN_forward;
          motion_controller_slx_B.spd_cmd[0] = 0.0;
          motion_controller_slx_B.spd_cmd[1] = 0.0;
          motion_controller_slx_B.spd_cmd[2] = 0.0;
          motion_controller_slx_B.spd_cmd[3] = 0.0;
        } else {
          motion_controller_slx_B.b_value = 1.5 * fabs
            (motion_controller_slx_B.out_k);
          if (fabs(motion_controller_slx_B.rtb_Gain_c) < 0.5) {
            motion_controller_slx_B.mode = 1;
            motion_controller_slx_B.spd_cmd[0] = 0.0;
            motion_controller_slx_B.spd_cmd[1] = 0.0;
            motion_controller_slx_B.spd_cmd[2] = 0.0;
            motion_controller_slx_B.spd_cmd[3] = 0.0;
            motion_controller_slx_B.b_value = 0.0;
          } else if (motion_controller_slx_B.rtb_Gain_c > 0.5) {
            motion_controller_slx_B.b_value = -motion_controller_slx_B.b_value;
            motion_controller_slx_B.mode = 2;
          } else if (motion_controller_slx_B.rtb_Gain_c < -0.5) {
            motion_controller_slx_B.mode = 2;
          }

          motion_controller__get_angle_4w(motion_controller_slx_B.out,
            motion_controller_slx_B.out_o, motion_controller_slx_B.angle_cmd);
          motion_controller_sl_get_effort(motion_controller_slx_B.b_value,
            motion_controller_slx_B.effort_cmd);
        }

        // case IN_forward:
      } else if (motion_controller_slx_B.out_k < -0.01) {
        motion_controller_slx_DW.is_effort_mode =
          motion_controller_sl_IN_braking;
        motion_controller_slx_B.spd_cmd[0] = 0.0;
        motion_controller_slx_B.spd_cmd[1] = 0.0;
        motion_controller_slx_B.spd_cmd[2] = 0.0;
        motion_controller_slx_B.spd_cmd[3] = 0.0;
      } else {
        motion_controller__get_angle_4w(motion_controller_slx_B.out,
          motion_controller_slx_B.out_o, motion_controller_slx_B.angle_cmd);
        if (motion_controller_slx_B.In1_m.mapped_channels[6] == 1000) {
          motion_controller_slx_B.b_value_c = -0.5 *
            motion_controller_slx_B.out_k;
        } else {
          motion_controller_slx_B.b_value_c = motion_controller_slx_B.out_k;
        }

        motion_controller_sl_get_effort(motion_controller_slx_B.b_value_c,
          motion_controller_slx_B.effort_cmd);
        motion_controller_slx_B.mode = 2;
      }
      break;

     case motion_controller_slx_IN_hold:
      if ((motion_controller_slx_B.In1_m.mapped_channels[4] != 1000) ||
          (!motion_controller_slx_DW.ready)) {
        motion_controller_slx_DW.is_cmd = motion_control_IN_velocity_mode;
        motion_controller_slx_B.effort_cmd[0] = 0.0;
        motion_controller_slx_B.effort_cmd[1] = 0.0;
        motion_controller_slx_B.effort_cmd[2] = 0.0;
        motion_controller_slx_B.effort_cmd[3] = 0.0;
      }
      break;

     default:
      // case IN_velocity_mode:
      if (!motion_controller_slx_DW.ready) {
        motion_controller_slx_DW.is_cmd = motion_controller_slx_IN_Ini;
        motion_controller_slx_B.angle_cmd[0] = 0.0;
        motion_controller_slx_B.spd_cmd[0] = 0.0;
        motion_controller_slx_B.effort_cmd[0] = 0.0;
        motion_controller_slx_B.angle_cmd[1] = 0.0;
        motion_controller_slx_B.spd_cmd[1] = 0.0;
        motion_controller_slx_B.effort_cmd[1] = 0.0;
        motion_controller_slx_B.angle_cmd[2] = 0.0;
        motion_controller_slx_B.spd_cmd[2] = 0.0;
        motion_controller_slx_B.effort_cmd[2] = 0.0;
        motion_controller_slx_B.angle_cmd[3] = 0.0;
        motion_controller_slx_B.spd_cmd[3] = 0.0;
        motion_controller_slx_B.effort_cmd[3] = 0.0;
        motion_controller_slx_B.mode = 0;
      } else if ((motion_controller_slx_B.In1_m.mapped_channels[6] == 1000) &&
                 (motion_controller_slx_B.In1_m.mapped_channels[4] == 1000)) {
        motion_controller_slx_DW.is_cmd = motion_controlle_IN_effort_mode;
        motion_controller_slx_DW.is_effort_mode =
          motion_controller_sl_IN_forward;
        motion_controller_slx_B.spd_cmd[0] = 0.0;
        motion_controller_slx_B.spd_cmd[1] = 0.0;
        motion_controller_slx_B.spd_cmd[2] = 0.0;
        motion_controller_slx_B.spd_cmd[3] = 0.0;
      } else if (motion_controller_slx_B.In1_m.mapped_channels[4] == 1000) {
        motion_controller_slx_DW.is_cmd = motion_controller_slx_IN_hold;
        motion_controller_slx_B.angle_cmd[0] = 0.0;
        motion_controller_slx_B.spd_cmd[0] = 0.0;
        motion_controller_slx_B.effort_cmd[0] = 0.0;
        motion_controller_slx_B.angle_cmd[1] = 0.0;
        motion_controller_slx_B.spd_cmd[1] = 0.0;
        motion_controller_slx_B.effort_cmd[1] = 0.0;
        motion_controller_slx_B.angle_cmd[2] = 0.0;
        motion_controller_slx_B.spd_cmd[2] = 0.0;
        motion_controller_slx_B.effort_cmd[2] = 0.0;
        motion_controller_slx_B.angle_cmd[3] = 0.0;
        motion_controller_slx_B.spd_cmd[3] = 0.0;
        motion_controller_slx_B.effort_cmd[3] = 0.0;
        motion_controller_slx_B.mode = 0;
      } else {
        motion_controller__get_angle_4w(motion_controller_slx_B.out,
          motion_controller_slx_B.out_o, motion_controller_slx_B.angle_cmd);
        motion_controller_slx_get_spd(motion_controller_slx_B.out,
          motion_controller_slx_B.out_k, motion_controller_slx_B.spd_cmd);
        motion_controller_slx_B.mode = 1;
      }
      break;
    }
  }

  // End of Chart: '<S3>/Chart'
  // End of Outputs for SubSystem: '<Root>/controller'

  // Outputs for Enabled SubSystem: '<Root>/cmd_pub' incorporates:
  //   EnablePort: '<S2>/Enable'

  // RelationalOperator: '<S1>/Compare' incorporates:
  //   Constant: '<S1>/Constant'
  //   SignalConversion generated from: '<S4>/Bus Selector'

  if (motion_controller_slx_B.In1_m.mapped_channels[5] ==
      motion_controller_slx_P.CompareToConstant_const) {
    motion_controller_s_CurrentTime(&motion_controller_slx_B.CurrentTime1);

    // BusAssignment: '<S2>/Bus Assignment1' incorporates:
    //   Constant: '<S6>/Constant'

    motion_controller_slx_B.BusAssignment1 =
      motion_controller_slx_P.Constant_Value_f;

    // Saturate: '<S2>/Saturation2'
    motion_controller_slx_B.rtb_Gain_c = motion_controller_slx_B.effort_cmd[0];

    // Saturate: '<S2>/Saturation1'
    motion_controller_slx_B.b_value = motion_controller_slx_B.spd_cmd[0];

    // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
    //   ForEach: '<S8>/For Each'

    // ForEachSliceAssignment generated from: '<S8>/actuaor_command' incorporates:
    //   BusAssignment: '<S8>/Bus Assignment1'
    //   Constant: '<S12>/Constant'

    motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[0] =
      motion_controller_slx_P.CoreSubsys_p.Constant_Value;

    // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'

    // Saturate: '<S2>/Saturation2'
    if (motion_controller_slx_B.rtb_Gain_c >
        motion_controller_slx_P.Saturation2_UpperSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[0].effort =
        motion_controller_slx_P.Saturation2_UpperSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    } else if (motion_controller_slx_B.rtb_Gain_c <
               motion_controller_slx_P.Saturation2_LowerSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[0].effort =
        motion_controller_slx_P.Saturation2_LowerSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[0].effort =
        motion_controller_slx_B.rtb_Gain_c;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    }

    // Saturate: '<S2>/Saturation1'
    if (motion_controller_slx_B.b_value >
        motion_controller_slx_P.Saturation1_UpperSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[0].velocity =
        motion_controller_slx_P.Saturation1_UpperSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    } else if (motion_controller_slx_B.b_value <
               motion_controller_slx_P.Saturation1_LowerSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[0].velocity =
        motion_controller_slx_P.Saturation1_LowerSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[0].velocity =
        motion_controller_slx_B.b_value;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    }

    // Saturate: '<S2>/Saturation2'
    motion_controller_slx_B.rtb_Gain_c = motion_controller_slx_B.effort_cmd[1];

    // Saturate: '<S2>/Saturation1'
    motion_controller_slx_B.b_value = motion_controller_slx_B.spd_cmd[1];

    // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
    //   ForEach: '<S8>/For Each'

    // ForEachSliceAssignment generated from: '<S8>/actuaor_command' incorporates:
    //   BusAssignment: '<S8>/Bus Assignment1'
    //   Constant: '<S12>/Constant'

    motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[1] =
      motion_controller_slx_P.CoreSubsys_p.Constant_Value;

    // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'

    // Saturate: '<S2>/Saturation2'
    if (motion_controller_slx_B.rtb_Gain_c >
        motion_controller_slx_P.Saturation2_UpperSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[1].effort =
        motion_controller_slx_P.Saturation2_UpperSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    } else if (motion_controller_slx_B.rtb_Gain_c <
               motion_controller_slx_P.Saturation2_LowerSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[1].effort =
        motion_controller_slx_P.Saturation2_LowerSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[1].effort =
        motion_controller_slx_B.rtb_Gain_c;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    }

    // Saturate: '<S2>/Saturation1'
    if (motion_controller_slx_B.b_value >
        motion_controller_slx_P.Saturation1_UpperSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[1].velocity =
        motion_controller_slx_P.Saturation1_UpperSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    } else if (motion_controller_slx_B.b_value <
               motion_controller_slx_P.Saturation1_LowerSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[1].velocity =
        motion_controller_slx_P.Saturation1_LowerSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[1].velocity =
        motion_controller_slx_B.b_value;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    }

    // Saturate: '<S2>/Saturation2'
    motion_controller_slx_B.rtb_Gain_c = motion_controller_slx_B.effort_cmd[2];

    // Saturate: '<S2>/Saturation1'
    motion_controller_slx_B.b_value = motion_controller_slx_B.spd_cmd[2];

    // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
    //   ForEach: '<S8>/For Each'

    // ForEachSliceAssignment generated from: '<S8>/actuaor_command' incorporates:
    //   BusAssignment: '<S8>/Bus Assignment1'
    //   Constant: '<S12>/Constant'

    motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[2] =
      motion_controller_slx_P.CoreSubsys_p.Constant_Value;

    // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'

    // Saturate: '<S2>/Saturation2'
    if (motion_controller_slx_B.rtb_Gain_c >
        motion_controller_slx_P.Saturation2_UpperSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[2].effort =
        motion_controller_slx_P.Saturation2_UpperSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    } else if (motion_controller_slx_B.rtb_Gain_c <
               motion_controller_slx_P.Saturation2_LowerSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[2].effort =
        motion_controller_slx_P.Saturation2_LowerSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[2].effort =
        motion_controller_slx_B.rtb_Gain_c;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    }

    // Saturate: '<S2>/Saturation1'
    if (motion_controller_slx_B.b_value >
        motion_controller_slx_P.Saturation1_UpperSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[2].velocity =
        motion_controller_slx_P.Saturation1_UpperSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    } else if (motion_controller_slx_B.b_value <
               motion_controller_slx_P.Saturation1_LowerSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[2].velocity =
        motion_controller_slx_P.Saturation1_LowerSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[2].velocity =
        motion_controller_slx_B.b_value;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    }

    // Saturate: '<S2>/Saturation2'
    motion_controller_slx_B.rtb_Gain_c = motion_controller_slx_B.effort_cmd[3];

    // Saturate: '<S2>/Saturation1'
    motion_controller_slx_B.b_value = motion_controller_slx_B.spd_cmd[3];

    // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
    //   ForEach: '<S8>/For Each'

    // ForEachSliceAssignment generated from: '<S8>/actuaor_command' incorporates:
    //   BusAssignment: '<S8>/Bus Assignment1'
    //   Constant: '<S12>/Constant'

    motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[3] =
      motion_controller_slx_P.CoreSubsys_p.Constant_Value;

    // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'

    // Saturate: '<S2>/Saturation2'
    if (motion_controller_slx_B.rtb_Gain_c >
        motion_controller_slx_P.Saturation2_UpperSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[3].effort =
        motion_controller_slx_P.Saturation2_UpperSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    } else if (motion_controller_slx_B.rtb_Gain_c <
               motion_controller_slx_P.Saturation2_LowerSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[3].effort =
        motion_controller_slx_P.Saturation2_LowerSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[3].effort =
        motion_controller_slx_B.rtb_Gain_c;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    }

    // Saturate: '<S2>/Saturation1'
    if (motion_controller_slx_B.b_value >
        motion_controller_slx_P.Saturation1_UpperSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[3].velocity =
        motion_controller_slx_P.Saturation1_UpperSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    } else if (motion_controller_slx_B.b_value <
               motion_controller_slx_P.Saturation1_LowerSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[3].velocity =
        motion_controller_slx_P.Saturation1_LowerSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[3].velocity =
        motion_controller_slx_B.b_value;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    }

    // BusAssignment: '<S2>/Bus Assignment1' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion'

    motion_controller_slx_B.BusAssignment1.header.stamp =
      motion_controller_slx_B.CurrentTime1.CurrentTime;
    motion_controller_slx_B.BusAssignment1.drive_mode =
      motion_controller_slx_B.mode;
    memcpy(&motion_controller_slx_B.BusAssignment1.actuator_command[0],
           &motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[0], sizeof
           (SL_Bus_custom_interfaces_Actuator) << 2U);

    // MATLABSystem: '<S9>/SinkBlock'
    Pub_motion_controller_slx_4.publish(&motion_controller_slx_B.BusAssignment1);
    motion_controller_s_CurrentTime(&motion_controller_slx_B.CurrentTime);

    // BusAssignment: '<S2>/Bus Assignment2' incorporates:
    //   Constant: '<S5>/Constant'

    motion_controller_slx_B.BusAssignment1 =
      motion_controller_slx_P.Constant_Value_i;

    // Saturate: '<S2>/Saturation'
    motion_controller_slx_B.rtb_Gain_c = motion_controller_slx_B.angle_cmd[0];

    // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
    //   ForEach: '<S7>/For Each'

    // ForEachSliceAssignment generated from: '<S7>/actuaor_command' incorporates:
    //   BusAssignment: '<S7>/Bus Assignment1'
    //   Constant: '<S11>/Constant'

    motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[0] =
      motion_controller_slx_P.CoreSubsys.Constant_Value;

    // End of Outputs for SubSystem: '<S2>/For Each Subsystem'

    // Saturate: '<S2>/Saturation'
    if (motion_controller_slx_B.rtb_Gain_c >
        motion_controller_slx_P.Saturation_UpperSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
      //   ForEach: '<S7>/For Each'

      // BusAssignment: '<S7>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[0].position =
        motion_controller_slx_P.Saturation_UpperSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem'
    } else if (motion_controller_slx_B.rtb_Gain_c <
               motion_controller_slx_P.Saturation_LowerSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
      //   ForEach: '<S7>/For Each'

      // BusAssignment: '<S7>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[0].position =
        motion_controller_slx_P.Saturation_LowerSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem'
    } else {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
      //   ForEach: '<S7>/For Each'

      // BusAssignment: '<S7>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[0].position =
        motion_controller_slx_B.rtb_Gain_c;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem'
    }

    motion_controller_slx_B.rtb_Gain_c = motion_controller_slx_B.angle_cmd[1];

    // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
    //   ForEach: '<S7>/For Each'

    // ForEachSliceAssignment generated from: '<S7>/actuaor_command' incorporates:
    //   BusAssignment: '<S7>/Bus Assignment1'
    //   Constant: '<S11>/Constant'

    motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[1] =
      motion_controller_slx_P.CoreSubsys.Constant_Value;

    // End of Outputs for SubSystem: '<S2>/For Each Subsystem'

    // Saturate: '<S2>/Saturation'
    if (motion_controller_slx_B.rtb_Gain_c >
        motion_controller_slx_P.Saturation_UpperSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
      //   ForEach: '<S7>/For Each'

      // BusAssignment: '<S7>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[1].position =
        motion_controller_slx_P.Saturation_UpperSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem'
    } else if (motion_controller_slx_B.rtb_Gain_c <
               motion_controller_slx_P.Saturation_LowerSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
      //   ForEach: '<S7>/For Each'

      // BusAssignment: '<S7>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[1].position =
        motion_controller_slx_P.Saturation_LowerSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem'
    } else {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
      //   ForEach: '<S7>/For Each'

      // BusAssignment: '<S7>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[1].position =
        motion_controller_slx_B.rtb_Gain_c;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem'
    }

    motion_controller_slx_B.rtb_Gain_c = motion_controller_slx_B.angle_cmd[2];

    // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
    //   ForEach: '<S7>/For Each'

    // ForEachSliceAssignment generated from: '<S7>/actuaor_command' incorporates:
    //   BusAssignment: '<S7>/Bus Assignment1'
    //   Constant: '<S11>/Constant'

    motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[2] =
      motion_controller_slx_P.CoreSubsys.Constant_Value;

    // End of Outputs for SubSystem: '<S2>/For Each Subsystem'

    // Saturate: '<S2>/Saturation'
    if (motion_controller_slx_B.rtb_Gain_c >
        motion_controller_slx_P.Saturation_UpperSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
      //   ForEach: '<S7>/For Each'

      // BusAssignment: '<S7>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[2].position =
        motion_controller_slx_P.Saturation_UpperSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem'
    } else if (motion_controller_slx_B.rtb_Gain_c <
               motion_controller_slx_P.Saturation_LowerSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
      //   ForEach: '<S7>/For Each'

      // BusAssignment: '<S7>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[2].position =
        motion_controller_slx_P.Saturation_LowerSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem'
    } else {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
      //   ForEach: '<S7>/For Each'

      // BusAssignment: '<S7>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[2].position =
        motion_controller_slx_B.rtb_Gain_c;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem'
    }

    motion_controller_slx_B.rtb_Gain_c = motion_controller_slx_B.angle_cmd[3];

    // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
    //   ForEach: '<S7>/For Each'

    // ForEachSliceAssignment generated from: '<S7>/actuaor_command' incorporates:
    //   BusAssignment: '<S7>/Bus Assignment1'
    //   Constant: '<S11>/Constant'

    motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[3] =
      motion_controller_slx_P.CoreSubsys.Constant_Value;

    // End of Outputs for SubSystem: '<S2>/For Each Subsystem'

    // Saturate: '<S2>/Saturation'
    if (motion_controller_slx_B.rtb_Gain_c >
        motion_controller_slx_P.Saturation_UpperSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
      //   ForEach: '<S7>/For Each'

      // BusAssignment: '<S7>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[3].position =
        motion_controller_slx_P.Saturation_UpperSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem'
    } else if (motion_controller_slx_B.rtb_Gain_c <
               motion_controller_slx_P.Saturation_LowerSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
      //   ForEach: '<S7>/For Each'

      // BusAssignment: '<S7>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[3].position =
        motion_controller_slx_P.Saturation_LowerSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem'
    } else {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
      //   ForEach: '<S7>/For Each'

      // BusAssignment: '<S7>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[3].position =
        motion_controller_slx_B.rtb_Gain_c;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem'
    }

    // BusAssignment: '<S2>/Bus Assignment2'
    motion_controller_slx_B.BusAssignment1.header.stamp =
      motion_controller_slx_B.CurrentTime.CurrentTime;
    memcpy(&motion_controller_slx_B.BusAssignment1.actuator_command[0],
           &motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[0], sizeof
           (SL_Bus_custom_interfaces_Actuator) << 2U);

    // MATLABSystem: '<S10>/SinkBlock'
    Pub_motion_controller_slx_148.publish
      (&motion_controller_slx_B.BusAssignment1);
  }

  // End of RelationalOperator: '<S1>/Compare'
  // End of Outputs for SubSystem: '<Root>/cmd_pub'
}

// Model initialize function
void motion_controller_slx::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    static const char_T prmName[13] = "acc_rate_mps";
    static const char_T prmName_0[11] = "drive_by_2";
    static const char_T prmName_1[7] = "spdMax";
    static const char_T prmName_2[15] = "steer_rate_dps";
    static const char_T prmName_3[4] = "FWS";
    static const char_T prmName_4[9] = "angleMax";
    static const char_T prmName_5[10] = "ackermann";

    // SystemInitialize for Enabled SubSystem: '<S26>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S29>/In1' incorporates:
    //   Outport: '<S29>/Out1'

    motion_controller_slx_B.In1_m = motion_controller_slx_P.Out1_Y0_f;

    // End of SystemInitialize for SubSystem: '<S26>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S27>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S30>/In1' incorporates:
    //   Outport: '<S30>/Out1'

    motion_controller_slx_B.In1 = motion_controller_slx_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S27>/Enabled Subsystem'

    // SystemInitialize for Atomic SubSystem: '<Root>/controller'
    // SystemInitialize for Chart: '<S14>/Chart4'
    motion_controller_s_Chart1_Init(&motion_controller_slx_B.out);

    // SystemInitialize for Chart: '<S14>/Chart1'
    motion_controller_s_Chart1_Init(&motion_controller_slx_B.out_o);

    // SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S3>/get_effort' incorporates:
    //   SubSystem: '<S3>/get_effort'

    motion_controll_get_effort_Init();

    // End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S3>/get_effort' 

    // Start for MATLABSystem: '<S14>/Get Parameter4'
    motion_controller_slx_DW.obj_e.matlabCodegenIsDeleted = false;
    motion_controller_slx_DW.obj_e.isInitialized = 1;
    ParamGet_motion_controller_slx_298.initParam(&prmName[0]);
    ParamGet_motion_controller_slx_298.setInitialValue(0.0);
    motion_controller_slx_DW.obj_e.isSetupComplete = true;

    // Start for MATLABSystem: '<S14>/Get Parameter2'
    motion_controller_slx_DW.obj_c.matlabCodegenIsDeleted = false;
    motion_controller_slx_DW.obj_c.isInitialized = 1;
    ParamGet_motion_controller_slx_301.initParam(&prmName_0[0]);
    ParamGet_motion_controller_slx_301.setInitialValue(0.0);
    motion_controller_slx_DW.obj_c.isSetupComplete = true;

    // Start for MATLABSystem: '<S14>/Get Parameter3'
    motion_controller_slx_DW.obj_l.matlabCodegenIsDeleted = false;
    motion_controller_slx_DW.obj_l.isInitialized = 1;
    ParamGet_motion_controller_slx_194.initParam(&prmName_1[0]);
    ParamGet_motion_controller_slx_194.setInitialValue(1.0);
    motion_controller_slx_DW.obj_l.isSetupComplete = true;

    // Start for MATLABSystem: '<S14>/Get Parameter1'
    motion_controller_slx_DW.obj_o.matlabCodegenIsDeleted = false;
    motion_controller_slx_DW.obj_o.isInitialized = 1;
    ParamGet_motion_controller_slx_317.initParam(&prmName_2[0]);
    ParamGet_motion_controller_slx_317.setInitialValue(0.0);
    motion_controller_slx_DW.obj_o.isSetupComplete = true;

    // Start for MATLABSystem: '<S14>/Get Parameter5'
    motion_controller_slx_DW.obj_g.matlabCodegenIsDeleted = false;
    motion_controller_slx_DW.obj_g.isInitialized = 1;
    ParamGet_motion_controller_slx_329.initParam(&prmName_3[0]);
    ParamGet_motion_controller_slx_329.setInitialValue(true);
    motion_controller_slx_DW.obj_g.isSetupComplete = true;

    // Start for MATLABSystem: '<S14>/Get Parameter'
    motion_controller_slx_DW.obj_m.matlabCodegenIsDeleted = false;
    motion_controller_slx_DW.obj_m.isInitialized = 1;
    ParamGet_motion_controller_slx_316.initParam(&prmName_4[0]);
    ParamGet_motion_controller_slx_316.setInitialValue(0.6);
    motion_controller_slx_DW.obj_m.isSetupComplete = true;

    // Start for MATLABSystem: '<S3>/Get Parameter1'
    motion_controller_slx_DW.obj_f.matlabCodegenIsDeleted = false;
    motion_controller_slx_DW.obj_f.isInitialized = 1;
    ParamGet_motion_controller_slx_217.initParam(&prmName_5[0]);
    ParamGet_motion_controller_slx_217.setInitialValue(1.0);
    motion_controller_slx_DW.obj_f.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<Root>/controller'

    // SystemInitialize for Enabled SubSystem: '<Root>/cmd_pub'
    motion_control_CurrentTime_Init(&motion_controller_slx_DW.CurrentTime1);

    // Start for MATLABSystem: '<S9>/SinkBlock'
    motion_control_SystemCore_setup(&motion_controller_slx_DW.obj_b);
    motion_control_CurrentTime_Init(&motion_controller_slx_DW.CurrentTime);

    // Start for MATLABSystem: '<S10>/SinkBlock'
    motion_contr_SystemCore_setup_o(&motion_controller_slx_DW.obj_ca);

    // End of SystemInitialize for SubSystem: '<Root>/cmd_pub'

    // Start for MATLABSystem: '<S26>/SourceBlock'
    motion_cont_SystemCore_setup_o0(&motion_controller_slx_DW.obj_n);

    // Start for MATLABSystem: '<S27>/SourceBlock'
    motion_con_SystemCore_setup_o0a(&motion_controller_slx_DW.obj_mo);
  }
}

// Model terminate function
void motion_controller_slx::terminate()
{
  // Terminate for MATLABSystem: '<S26>/SourceBlock'
  if (!motion_controller_slx_DW.obj_n.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S26>/SourceBlock'

  // Terminate for MATLABSystem: '<S27>/SourceBlock'
  if (!motion_controller_slx_DW.obj_mo.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_mo.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S27>/SourceBlock'

  // Terminate for Atomic SubSystem: '<Root>/controller'
  // Terminate for MATLABSystem: '<S14>/Get Parameter4'
  if (!motion_controller_slx_DW.obj_e.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/Get Parameter4'

  // Terminate for MATLABSystem: '<S14>/Get Parameter2'
  if (!motion_controller_slx_DW.obj_c.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/Get Parameter2'

  // Terminate for MATLABSystem: '<S14>/Get Parameter3'
  if (!motion_controller_slx_DW.obj_l.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/Get Parameter3'

  // Terminate for MATLABSystem: '<S14>/Get Parameter1'
  if (!motion_controller_slx_DW.obj_o.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/Get Parameter1'

  // Terminate for MATLABSystem: '<S14>/Get Parameter5'
  if (!motion_controller_slx_DW.obj_g.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/Get Parameter5'

  // Terminate for MATLABSystem: '<S14>/Get Parameter'
  if (!motion_controller_slx_DW.obj_m.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/Get Parameter'

  // Terminate for MATLABSystem: '<S3>/Get Parameter1'
  if (!motion_controller_slx_DW.obj_f.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/Get Parameter1'

  // Terminate for S-Function (sfun_private_function_caller) generated from: '<S3>/get_effort' incorporates:
  //   SubSystem: '<S3>/get_effort'

  motion_controll_get_effort_Term();

  // End of Terminate for S-Function (sfun_private_function_caller) generated from: '<S3>/get_effort' 
  // End of Terminate for SubSystem: '<Root>/controller'

  // Terminate for Enabled SubSystem: '<Root>/cmd_pub'
  motion_control_CurrentTime_Term(&motion_controller_slx_DW.CurrentTime1);

  // Terminate for MATLABSystem: '<S9>/SinkBlock'
  if (!motion_controller_slx_DW.obj_b.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/SinkBlock'
  motion_control_CurrentTime_Term(&motion_controller_slx_DW.CurrentTime);

  // Terminate for MATLABSystem: '<S10>/SinkBlock'
  if (!motion_controller_slx_DW.obj_ca.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_ca.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/cmd_pub'
}

// Constructor
motion_controller_slx::motion_controller_slx() :
  motion_controller_slx_B(),
  motion_controller_slx_DW(),
  motion_controller_slx_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
motion_controller_slx::~motion_controller_slx()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_motion_controller_sl_T * motion_controller_slx::getRTM()
{
  return (&motion_controller_slx_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
