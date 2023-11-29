//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: motion_controller_slide_test.cpp
//
// Code generated for Simulink model 'motion_controller_slide_test'.
//
// Model version                  : 2.173
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Thu Nov 23 10:42:02 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "motion_controller_slide_test.h"
#include "rtwtypes.h"
#include "motion_controller_slide_test_types.h"
#include <math.h>
#include "rt_atan2d_snf.h"
#include <string.h>
#include "rmw/qos_profiles.h"
#include <stddef.h>

extern "C"
{

#include "rt_nonfinite.h"

}

// Named constants for Chart: '<S2>/Chart'
const uint8_T motion_contr_IN_NO_ACTIVE_CHILD = 0U;
const uint8_T motion_contro_IN_velocity_mode1 = 2U;
const uint8_T motion_controller__IN_test_mode = 4U;
const uint8_T motion_controller_slid_IN_slide = 2U;
const uint8_T motion_controller_slide_IN_hold = 2U;
const uint8_T motion_controller_slide_IN_ini2 = 3U;
const uint8_T motion_controller_slide__IN_Ini = 1U;
const uint8_T motion_controller_slide__IN_acc = 1U;

// System initialize for atomic system:
void motion_controller_slide_test::motion_control_CurrentTime_Init
  (DW_CurrentTime_motion_control_T *localDW)
{
  // Start for MATLABSystem: '<S1>/Current Time'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void motion_controller_slide_test::motion_controller_s_CurrentTime
  (B_CurrentTime_motion_controll_T *localB)
{
  // MATLABSystem: '<S1>/Current Time'
  currentROS2TimeBus(&localB->CurrentTime);
}

// Termination for atomic system:
void motion_controller_slide_test::motion_control_CurrentTime_Term
  (DW_CurrentTime_motion_control_T *localDW)
{
  // Terminate for MATLABSystem: '<S1>/Current Time'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1>/Current Time'
}

// System initialize for Simulink Function: '<S2>/get_angle'
void motion_controller_slide_test::motion_controlle_get_angle_Init()
{
  static const char_T prmName[9] = "angleMax";

  // Start for MATLABSystem: '<S14>/Get Parameter'
  motion_controller_slide_test_DW.obj_j.matlabCodegenIsDeleted = false;
  motion_controller_slide_test_DW.obj_j.isInitialized = 1;
  ParamGet_motion_controller_slide_test_193.initParam(&prmName[0]);
  ParamGet_motion_controller_slide_test_193.setInitialValue(0.6);
  motion_controller_slide_test_DW.obj_j.isSetupComplete = true;
}

// Output and update for Simulink Function: '<S2>/get_angle'
void motion_controller_slide_test::motion_controller_sli_get_angle()
{
}

// Termination for Simulink Function: '<S2>/get_angle'
void motion_controller_slide_test::motion_controlle_get_angle_Term()
{
  // Terminate for MATLABSystem: '<S14>/Get Parameter'
  if (!motion_controller_slide_test_DW.obj_j.matlabCodegenIsDeleted) {
    motion_controller_slide_test_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/Get Parameter'
}

// System initialize for Simulink Function: '<S2>/get_effort'
void motion_controller_slide_test::motion_controll_get_effort_Init()
{
  static const char_T prmName[10] = "effortMax";

  // Start for MATLABSystem: '<S15>/Get Parameter'
  motion_controller_slide_test_DW.obj_d.matlabCodegenIsDeleted = false;
  motion_controller_slide_test_DW.obj_d.isInitialized = 1;
  ParamGet_motion_controller_slide_test_202.initParam(&prmName[0]);
  ParamGet_motion_controller_slide_test_202.setInitialValue(0.6);
  motion_controller_slide_test_DW.obj_d.isSetupComplete = true;
}

// Output and update for Simulink Function: '<S2>/get_effort'
void motion_controller_slide_test::motion_controller_sl_get_effort(real_T
  rtu_longdrive, real_T rty_effort_cmd[4])
{
  real_T b_value;

  // MATLABSystem: '<S15>/Get Parameter'
  ParamGet_motion_controller_slide_test_202.getParameter(&b_value);

  // MATLAB Function: '<S15>/MATLAB Function' incorporates:
  //   MATLABSystem: '<S15>/Get Parameter'
  //   SignalConversion generated from: '<S15>/angle'

  b_value *= rtu_longdrive;

  // SignalConversion generated from: '<S15>/angle_cmd' incorporates:
  //   MATLAB Function: '<S15>/MATLAB Function'

  rty_effort_cmd[0] = b_value;
  rty_effort_cmd[1] = -b_value;
  rty_effort_cmd[2] = -b_value;
  rty_effort_cmd[3] = b_value;
}

// Termination for Simulink Function: '<S2>/get_effort'
void motion_controller_slide_test::motion_controll_get_effort_Term()
{
  // Terminate for MATLABSystem: '<S15>/Get Parameter'
  if (!motion_controller_slide_test_DW.obj_d.matlabCodegenIsDeleted) {
    motion_controller_slide_test_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S15>/Get Parameter'
}

// System initialize for Simulink Function: '<S2>/get_spd'
void motion_controller_slide_test::motion_controller__get_spd_Init()
{
  static const char_T prmName[4] = "spd";

  // Start for MATLABSystem: '<S16>/Get Parameter'
  motion_controller_slide_test_DW.obj.matlabCodegenIsDeleted = false;
  motion_controller_slide_test_DW.obj.isInitialized = 1;
  ParamGet_motion_controller_slide_test_288.initParam(&prmName[0]);
  ParamGet_motion_controller_slide_test_288.setInitialValue(0.5);
  motion_controller_slide_test_DW.obj.isSetupComplete = true;
}

// Output and update for Simulink Function: '<S2>/get_spd'
void motion_controller_slide_test::motion_controller_slide_get_spd(real_T
  rtu_angle, real_T rtu_longdrive, real_T rty_spd_cmd[4])
{
  real_T R_;
  real_T b_value;
  real_T vFR;
  real_T vRL;

  // MATLABSystem: '<S16>/Get Parameter'
  ParamGet_motion_controller_slide_test_288.getParameter(&b_value);

  // MATLAB Function: '<S16>/MATLAB Function' incorporates:
  //   Constant: '<S16>/Constant'
  //   MATLABSystem: '<S16>/Get Parameter'
  //   SignalConversion generated from: '<S16>/longdrive1'
  //   SignalConversion generated from: '<S16>/longdrive'

  b_value *= rtu_longdrive;
  if (motion_controller_slide_test_P.Constant_Value_l == 1.0) {
    R_ = motion_controller_slide_test_P.L / (tan(rtu_angle) + 1.0E-9);
    if (R_ >= 0.0) {
      vFR = rt_atan2d_snf(motion_controller_slide_test_P.L, R_ -
                          motion_controller_slide_test_P.Tw / 2.0);
      vRL = rt_atan2d_snf(motion_controller_slide_test_P.L,
                          motion_controller_slide_test_P.Tw / 2.0 + R_);
    } else {
      vFR = rt_atan2d_snf(motion_controller_slide_test_P.L, R_ -
                          motion_controller_slide_test_P.Tw / 2.0) -
        3.1415926535897931;
      vRL = rt_atan2d_snf(motion_controller_slide_test_P.L,
                          motion_controller_slide_test_P.Tw / 2.0 + R_) -
        3.1415926535897931;
    }

    // SignalConversion generated from: '<S16>/angle_cmd' incorporates:
    //   SignalConversion generated from: '<S16>/longdrive1'

    rty_spd_cmd[0] = (motion_controller_slide_test_P.L / sin(vFR) -
                      motion_controller_slide_test_P.WHEEL_OFFSET) * b_value /
      R_;
    vFR = (motion_controller_slide_test_P.L / sin(vRL) +
           motion_controller_slide_test_P.WHEEL_OFFSET) * b_value / R_;
    vRL = ((R_ - motion_controller_slide_test_P.Tw / 2.0) -
           motion_controller_slide_test_P.WHEEL_OFFSET) * b_value / R_;
    b_value = ((motion_controller_slide_test_P.Tw / 2.0 + R_) +
               motion_controller_slide_test_P.WHEEL_OFFSET) * b_value / R_;
  } else {
    // SignalConversion generated from: '<S16>/angle_cmd'
    rty_spd_cmd[0] = b_value;
    vFR = b_value;
    vRL = b_value;
  }

  // SignalConversion generated from: '<S16>/angle_cmd' incorporates:
  //   MATLAB Function: '<S16>/MATLAB Function'

  rty_spd_cmd[1] = -vFR;
  rty_spd_cmd[2] = -vRL;
  rty_spd_cmd[3] = b_value;
}

// Termination for Simulink Function: '<S2>/get_spd'
void motion_controller_slide_test::motion_controller__get_spd_Term()
{
  // Terminate for MATLABSystem: '<S16>/Get Parameter'
  if (!motion_controller_slide_test_DW.obj.matlabCodegenIsDeleted) {
    motion_controller_slide_test_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S16>/Get Parameter'
}

void motion_controller_slide_test::motion_control_SystemCore_setup
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

  Pub_motion_controller_slide_test_4.createPublisher(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_slide_test::motion_contr_SystemCore_setup_h
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

  Pub_motion_controller_slide_test_148.createPublisher(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_slide_test::motion_cont_SystemCore_setup_h0
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[6];
  static const char_T b_zeroDelimTopic_0[6] = "/sbus";

  // Start for MATLABSystem: '<S20>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S20>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  for (int32_T i = 0; i < 6; i++) {
    // Start for MATLABSystem: '<S20>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_motion_controller_slide_test_1.createSubscriber(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_slide_test::motion_con_SystemCore_setup_h0k
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[20];
  static const char_T b_zeroDelimTopic_0[20] = "/camera/pose/sample";

  // Start for MATLABSystem: '<S21>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S21>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  for (int32_T i = 0; i < 20; i++) {
    // Start for MATLABSystem: '<S21>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_motion_controller_slide_test_283.createSubscriber(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

// Model step function
void motion_controller_slide_test::step()
{
  real_T u0;
  uint32_T qY;
  boolean_T b_varargout_1;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_LogicalOperator_l;

  // MATLABSystem: '<S20>/SourceBlock'
  rtb_LogicalOperator_l = Sub_motion_controller_slide_test_1.getLatestMessage
    (&motion_controller_slide_test_B.b_varargout_2_m);

  // Outputs for Enabled SubSystem: '<S20>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S23>/Enable'

  // Start for MATLABSystem: '<S20>/SourceBlock'
  if (rtb_LogicalOperator_l) {
    // SignalConversion generated from: '<S23>/In1'
    motion_controller_slide_test_B.In1_m =
      motion_controller_slide_test_B.b_varargout_2_m;
  }

  // End of Outputs for SubSystem: '<S20>/Enabled Subsystem'

  // Logic: '<Root>/LogicalOperator'
  rtb_LogicalOperator = (motion_controller_slide_test_B.In1_m.failsafe ||
    motion_controller_slide_test_B.In1_m.frame_lost);

  // MATLABSystem: '<S21>/SourceBlock'
  b_varargout_1 = Sub_motion_controller_slide_test_283.getLatestMessage
    (&motion_controller_slide_test_B.b_varargout_2);

  // Logic: '<S4>/Logical Operator' incorporates:
  //   MATLABSystem: '<S20>/SourceBlock'
  //   MATLABSystem: '<S21>/SourceBlock'
  //
  rtb_LogicalOperator_l = (rtb_LogicalOperator_l && b_varargout_1);

  // Outputs for Enabled SubSystem: '<S21>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S24>/Enable'

  // Start for MATLABSystem: '<S21>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S24>/In1'
    motion_controller_slide_test_B.In1 =
      motion_controller_slide_test_B.b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S21>/Enabled Subsystem'

  // Outputs for Atomic SubSystem: '<Root>/controller'
  // MATLABSystem: '<S2>/Get Parameter'
  ParamGet_motion_controller_slide_test_291.getParameter
    (&motion_controller_slide_test_B.b_value);

  // Chart: '<S2>/Chart' incorporates:
  //   MATLABSystem: '<S2>/Get Parameter'
  //   SignalConversion generated from: '<S4>/Bus Selector2'
  //   SignalConversion generated from: '<S4>/Bus Selector'

  if (motion_controller_slide_test_DW.is_active_c3_motion_controller_ == 0U) {
    motion_controller_slide_test_DW.is_active_c3_motion_controller_ = 1U;
    motion_controller_slide_test_DW.is_Is_ready =
      motion_controller_slide__IN_Ini;
    motion_controller_slide_test_DW.check = 1.0;
    motion_controller_slide_test_DW.ready = false;
    motion_controller_slide_test_DW.is_cmd = motion_controller_slide__IN_Ini;
    motion_controller_slide_test_B.angle_cmd[0] = 0.0;
    motion_controller_slide_test_B.spd_cmd[0] = 0.0;
    motion_controller_slide_test_B.effort_cmd[0] = 0.0;
    motion_controller_slide_test_B.angle_cmd[1] = 0.0;
    motion_controller_slide_test_B.spd_cmd[1] = 0.0;
    motion_controller_slide_test_B.effort_cmd[1] = 0.0;
    motion_controller_slide_test_B.angle_cmd[2] = 0.0;
    motion_controller_slide_test_B.spd_cmd[2] = 0.0;
    motion_controller_slide_test_B.effort_cmd[2] = 0.0;
    motion_controller_slide_test_B.angle_cmd[3] = 0.0;
    motion_controller_slide_test_B.spd_cmd[3] = 0.0;
    motion_controller_slide_test_B.effort_cmd[3] = 0.0;
    motion_controller_slide_test_B.mode = 0;
  } else {
    if (motion_controller_slide_test_DW.is_Is_ready ==
        motion_controller_slide__IN_Ini) {
      if ((motion_controller_slide_test_B.In1_m.mapped_channels[3] == 1000) && (
           !rtb_LogicalOperator) && rtb_LogicalOperator_l) {
        motion_controller_slide_test_DW.is_Is_ready =
          motion_contro_IN_velocity_mode1;
        motion_controller_slide_test_DW.ready = true;
        motion_controller_slide_test_DW.check = 1.0;
        motion_controller_slide_test_DW.sum = 0.0;
        motion_controller_slide_test_DW.counter_check = 0U;
      }

      // case IN_velocity_mode1:
    } else if ((motion_controller_slide_test_B.In1_m.mapped_channels[3] != 1000)
               || rtb_LogicalOperator || (motion_controller_slide_test_DW.check ==
                0.0)) {
      motion_controller_slide_test_DW.is_Is_ready =
        motion_controller_slide__IN_Ini;
      motion_controller_slide_test_DW.check = 1.0;
      motion_controller_slide_test_DW.ready = false;
    } else {
      qY = motion_controller_slide_test_DW.counter_check + /*MW:OvSatOk*/ 1U;
      if (motion_controller_slide_test_DW.counter_check + 1U <
          motion_controller_slide_test_DW.counter_check) {
        qY = MAX_uint32_T;
      }

      motion_controller_slide_test_DW.counter_check = qY;
      motion_controller_slide_test_DW.sum += static_cast<real_T>
        (rtb_LogicalOperator_l);
      if (motion_controller_slide_test_DW.counter_check -
          motion_controller_slide_test_DW.counter_check / 20U * 20U == 0U) {
        motion_controller_slide_test_DW.check =
          motion_controller_slide_test_DW.sum;
        motion_controller_slide_test_DW.sum = 0.0;
      }
    }

    switch (motion_controller_slide_test_DW.is_cmd) {
     case motion_controller_slide__IN_Ini:
      motion_controller_slide_test_B.angle_cmd[0] = 0.0;
      motion_controller_slide_test_B.angle_cmd[1] = 0.0;
      motion_controller_slide_test_B.angle_cmd[2] = 0.0;
      motion_controller_slide_test_B.angle_cmd[3] = 0.0;
      if (motion_controller_slide_test_DW.ready) {
        motion_controller_slide_test_DW.is_cmd = motion_controller_slide_IN_ini2;
        motion_controller_slide_test_B.angle_cmd[0] = 0.0;
        motion_controller_slide_test_B.effort_cmd[0] = 0.0;
        motion_controller_slide_test_B.spd_cmd[0] = 0.0;
        motion_controller_slide_test_B.angle_cmd[1] = 0.0;
        motion_controller_slide_test_B.effort_cmd[1] = 0.0;
        motion_controller_slide_test_B.spd_cmd[1] = 0.0;
        motion_controller_slide_test_B.angle_cmd[2] = 0.0;
        motion_controller_slide_test_B.effort_cmd[2] = 0.0;
        motion_controller_slide_test_B.spd_cmd[2] = 0.0;
        motion_controller_slide_test_B.angle_cmd[3] = 0.0;
        motion_controller_slide_test_B.effort_cmd[3] = 0.0;
        motion_controller_slide_test_B.spd_cmd[3] = 0.0;
      }
      break;

     case motion_controller_slide_IN_hold:
      motion_controller_slide_test_B.angle_cmd[0] = 0.0;
      motion_controller_slide_test_B.angle_cmd[1] = 0.0;
      motion_controller_slide_test_B.angle_cmd[2] = 0.0;
      motion_controller_slide_test_B.angle_cmd[3] = 0.0;
      if ((motion_controller_slide_test_B.In1_m.mapped_channels[4] != 1000) || (
           !motion_controller_slide_test_DW.ready)) {
        motion_controller_slide_test_DW.is_cmd = motion_controller_slide_IN_ini2;
        motion_controller_slide_test_B.angle_cmd[0] = 0.0;
        motion_controller_slide_test_B.effort_cmd[0] = 0.0;
        motion_controller_slide_test_B.spd_cmd[0] = 0.0;
        motion_controller_slide_test_B.angle_cmd[1] = 0.0;
        motion_controller_slide_test_B.effort_cmd[1] = 0.0;
        motion_controller_slide_test_B.spd_cmd[1] = 0.0;
        motion_controller_slide_test_B.angle_cmd[2] = 0.0;
        motion_controller_slide_test_B.effort_cmd[2] = 0.0;
        motion_controller_slide_test_B.spd_cmd[2] = 0.0;
        motion_controller_slide_test_B.angle_cmd[3] = 0.0;
        motion_controller_slide_test_B.effort_cmd[3] = 0.0;
        motion_controller_slide_test_B.spd_cmd[3] = 0.0;
      }
      break;

     case motion_controller_slide_IN_ini2:
      motion_controller_slide_test_B.angle_cmd[0] = 0.0;
      motion_controller_slide_test_B.angle_cmd[1] = 0.0;
      motion_controller_slide_test_B.angle_cmd[2] = 0.0;
      motion_controller_slide_test_B.angle_cmd[3] = 0.0;
      if (!motion_controller_slide_test_DW.ready) {
        motion_controller_slide_test_DW.is_cmd = motion_controller_slide__IN_Ini;
        motion_controller_slide_test_B.angle_cmd[0] = 0.0;
        motion_controller_slide_test_B.spd_cmd[0] = 0.0;
        motion_controller_slide_test_B.effort_cmd[0] = 0.0;
        motion_controller_slide_test_B.angle_cmd[1] = 0.0;
        motion_controller_slide_test_B.spd_cmd[1] = 0.0;
        motion_controller_slide_test_B.effort_cmd[1] = 0.0;
        motion_controller_slide_test_B.angle_cmd[2] = 0.0;
        motion_controller_slide_test_B.spd_cmd[2] = 0.0;
        motion_controller_slide_test_B.effort_cmd[2] = 0.0;
        motion_controller_slide_test_B.angle_cmd[3] = 0.0;
        motion_controller_slide_test_B.spd_cmd[3] = 0.0;
        motion_controller_slide_test_B.effort_cmd[3] = 0.0;
        motion_controller_slide_test_B.mode = 0;
      } else if ((motion_controller_slide_test_B.In1_m.mapped_channels[6] ==
                  1000) &&
                 (motion_controller_slide_test_B.In1_m.mapped_channels[4] ==
                  1000)) {
        motion_controller_slide_test_DW.is_cmd = motion_controller__IN_test_mode;
        motion_controller_slide_test_DW.is_test_mode =
          motion_controller_slide__IN_acc;
        motion_controller_slide_test_DW.x_ini =
          motion_controller_slide_test_B.In1.pose.pose.position.x;
        motion_controller_slide_test_DW.x_delta = 0.0;
        motion_controller_slide_test_DW.counter = 0.0;
        motion_controller_slide_test_B.angle_cmd[0] = 0.0;
        motion_controller_slide_test_B.spd_cmd[0] = 0.0;
        motion_controller_slide_test_B.angle_cmd[1] = 0.0;
        motion_controller_slide_test_B.spd_cmd[1] = 0.0;
        motion_controller_slide_test_B.angle_cmd[2] = 0.0;
        motion_controller_slide_test_B.spd_cmd[2] = 0.0;
        motion_controller_slide_test_B.angle_cmd[3] = 0.0;
        motion_controller_slide_test_B.spd_cmd[3] = 0.0;
      } else if (motion_controller_slide_test_B.In1_m.mapped_channels[4] == 1000)
      {
        motion_controller_slide_test_DW.is_cmd = motion_controller_slide_IN_hold;
        motion_controller_slide_test_B.angle_cmd[0] = 0.0;
        motion_controller_slide_test_B.spd_cmd[0] = 0.0;
        motion_controller_slide_test_B.effort_cmd[0] = 0.0;
        motion_controller_slide_test_B.angle_cmd[1] = 0.0;
        motion_controller_slide_test_B.spd_cmd[1] = 0.0;
        motion_controller_slide_test_B.effort_cmd[1] = 0.0;
        motion_controller_slide_test_B.angle_cmd[2] = 0.0;
        motion_controller_slide_test_B.spd_cmd[2] = 0.0;
        motion_controller_slide_test_B.effort_cmd[2] = 0.0;
        motion_controller_slide_test_B.angle_cmd[3] = 0.0;
        motion_controller_slide_test_B.spd_cmd[3] = 0.0;
        motion_controller_slide_test_B.effort_cmd[3] = 0.0;
        motion_controller_slide_test_B.mode = 0;
      } else {
        motion_controller_slide_test_B.mode = 0;
      }
      break;

     default:
      // case IN_test_mode:
      if ((motion_controller_slide_test_B.In1_m.mapped_channels[4] != 1000) || (
           !motion_controller_slide_test_DW.ready)) {
        motion_controller_slide_test_DW.is_test_mode =
          motion_contr_IN_NO_ACTIVE_CHILD;
        motion_controller_slide_test_DW.is_cmd = motion_controller_slide_IN_ini2;
        motion_controller_slide_test_B.angle_cmd[0] = 0.0;
        motion_controller_slide_test_B.effort_cmd[0] = 0.0;
        motion_controller_slide_test_B.spd_cmd[0] = 0.0;
        motion_controller_slide_test_B.angle_cmd[1] = 0.0;
        motion_controller_slide_test_B.effort_cmd[1] = 0.0;
        motion_controller_slide_test_B.spd_cmd[1] = 0.0;
        motion_controller_slide_test_B.angle_cmd[2] = 0.0;
        motion_controller_slide_test_B.effort_cmd[2] = 0.0;
        motion_controller_slide_test_B.spd_cmd[2] = 0.0;
        motion_controller_slide_test_B.angle_cmd[3] = 0.0;
        motion_controller_slide_test_B.effort_cmd[3] = 0.0;
        motion_controller_slide_test_B.spd_cmd[3] = 0.0;
      } else if (motion_controller_slide_test_DW.is_test_mode ==
                 motion_controller_slide__IN_acc) {
        motion_controller_slide_test_B.angle_cmd[0] = 0.0;
        motion_controller_slide_test_B.angle_cmd[1] = 0.0;
        motion_controller_slide_test_B.angle_cmd[2] = 0.0;
        motion_controller_slide_test_B.angle_cmd[3] = 0.0;
        if (motion_controller_slide_test_DW.x_delta >=
            motion_controller_slide_test_B.b_value) {
          motion_controller_slide_test_DW.is_test_mode =
            motion_controller_slid_IN_slide;
          motion_controller_slide_test_B.angle_cmd[0] = 0.0;
          motion_controller_slide_test_B.spd_cmd[0] = 0.0;
          motion_controller_slide_test_B.angle_cmd[1] = 0.0;
          motion_controller_slide_test_B.spd_cmd[1] = 0.0;
          motion_controller_slide_test_B.angle_cmd[2] = 0.0;
          motion_controller_slide_test_B.spd_cmd[2] = 0.0;
          motion_controller_slide_test_B.angle_cmd[3] = 0.0;
          motion_controller_slide_test_B.spd_cmd[3] = 0.0;
          motion_controller_slide_test_B.mode = 2;
        } else {
          motion_controller_slide_test_DW.x_delta =
            motion_controller_slide_test_B.In1.pose.pose.position.x -
            motion_controller_slide_test_DW.x_ini;
          motion_controller_slide_test_B.b_value =
            motion_controller_slide_test_DW.counter / 100.0;
          if (!(motion_controller_slide_test_B.b_value <= 1.0)) {
            motion_controller_slide_test_B.b_value = 1.0;
          }

          motion_controller_slide_get_spd(0.0,
            motion_controller_slide_test_B.b_value,
            motion_controller_slide_test_B.spd_cmd);
          motion_controller_slide_test_B.mode = 1;
          motion_controller_slide_test_DW.counter++;
        }
      } else {
        // case IN_slide:
        motion_controller_slide_test_B.angle_cmd[0] = 0.0;
        motion_controller_slide_test_B.angle_cmd[1] = 0.0;
        motion_controller_slide_test_B.angle_cmd[2] = 0.0;
        motion_controller_slide_test_B.angle_cmd[3] = 0.0;
        motion_controller_sl_get_effort(0.0,
          motion_controller_slide_test_B.effort_cmd);
        motion_controller_slide_test_B.mode = 2;
      }
      break;
    }
  }

  // End of Chart: '<S2>/Chart'
  // End of Outputs for SubSystem: '<Root>/controller'

  // Outputs for Enabled SubSystem: '<Root>/cmd_pub' incorporates:
  //   EnablePort: '<S1>/Enable'

  // RelationalOperator: '<S3>/Compare' incorporates:
  //   Constant: '<S3>/Constant'
  //   SignalConversion generated from: '<S4>/Bus Selector'

  if (motion_controller_slide_test_B.In1_m.mapped_channels[5] ==
      motion_controller_slide_test_P.ctc_const) {
    motion_controller_s_CurrentTime(&motion_controller_slide_test_B.CurrentTime1);

    // BusAssignment: '<S1>/Bus Assignment1' incorporates:
    //   Constant: '<S6>/Constant'

    motion_controller_slide_test_B.BusAssignment1 =
      motion_controller_slide_test_P.Constant_Value_f;

    // Saturate: '<S1>/Saturation2'
    motion_controller_slide_test_B.b_value =
      motion_controller_slide_test_B.effort_cmd[0];

    // Saturate: '<S1>/Saturation1'
    u0 = motion_controller_slide_test_B.spd_cmd[0];

    // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
    //   ForEach: '<S8>/For Each'

    // ForEachSliceAssignment generated from: '<S8>/actuaor_command' incorporates:
    //   BusAssignment: '<S8>/Bus Assignment1'
    //   Constant: '<S12>/Constant'

    motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[0] =
      motion_controller_slide_test_P.CoreSubsys_p.Constant_Value;

    // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'

    // Saturate: '<S1>/Saturation2'
    if (motion_controller_slide_test_B.b_value >
        motion_controller_slide_test_P.Saturation2_UpperSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[0].effort =
        motion_controller_slide_test_P.Saturation2_UpperSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else if (motion_controller_slide_test_B.b_value <
               motion_controller_slide_test_P.Saturation2_LowerSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[0].effort =
        motion_controller_slide_test_P.Saturation2_LowerSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[0].effort =
        motion_controller_slide_test_B.b_value;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    }

    // Saturate: '<S1>/Saturation1'
    if (u0 > motion_controller_slide_test_P.Saturation1_UpperSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[0].velocity =
        motion_controller_slide_test_P.Saturation1_UpperSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else if (u0 < motion_controller_slide_test_P.Saturation1_LowerSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[0].velocity =
        motion_controller_slide_test_P.Saturation1_LowerSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[0].velocity =
        u0;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    }

    // Saturate: '<S1>/Saturation2'
    motion_controller_slide_test_B.b_value =
      motion_controller_slide_test_B.effort_cmd[1];

    // Saturate: '<S1>/Saturation1'
    u0 = motion_controller_slide_test_B.spd_cmd[1];

    // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
    //   ForEach: '<S8>/For Each'

    // ForEachSliceAssignment generated from: '<S8>/actuaor_command' incorporates:
    //   BusAssignment: '<S8>/Bus Assignment1'
    //   Constant: '<S12>/Constant'

    motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[1] =
      motion_controller_slide_test_P.CoreSubsys_p.Constant_Value;

    // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'

    // Saturate: '<S1>/Saturation2'
    if (motion_controller_slide_test_B.b_value >
        motion_controller_slide_test_P.Saturation2_UpperSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[1].effort =
        motion_controller_slide_test_P.Saturation2_UpperSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else if (motion_controller_slide_test_B.b_value <
               motion_controller_slide_test_P.Saturation2_LowerSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[1].effort =
        motion_controller_slide_test_P.Saturation2_LowerSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[1].effort =
        motion_controller_slide_test_B.b_value;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    }

    // Saturate: '<S1>/Saturation1'
    if (u0 > motion_controller_slide_test_P.Saturation1_UpperSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[1].velocity =
        motion_controller_slide_test_P.Saturation1_UpperSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else if (u0 < motion_controller_slide_test_P.Saturation1_LowerSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[1].velocity =
        motion_controller_slide_test_P.Saturation1_LowerSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[1].velocity =
        u0;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    }

    // Saturate: '<S1>/Saturation2'
    motion_controller_slide_test_B.b_value =
      motion_controller_slide_test_B.effort_cmd[2];

    // Saturate: '<S1>/Saturation1'
    u0 = motion_controller_slide_test_B.spd_cmd[2];

    // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
    //   ForEach: '<S8>/For Each'

    // ForEachSliceAssignment generated from: '<S8>/actuaor_command' incorporates:
    //   BusAssignment: '<S8>/Bus Assignment1'
    //   Constant: '<S12>/Constant'

    motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[2] =
      motion_controller_slide_test_P.CoreSubsys_p.Constant_Value;

    // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'

    // Saturate: '<S1>/Saturation2'
    if (motion_controller_slide_test_B.b_value >
        motion_controller_slide_test_P.Saturation2_UpperSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[2].effort =
        motion_controller_slide_test_P.Saturation2_UpperSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else if (motion_controller_slide_test_B.b_value <
               motion_controller_slide_test_P.Saturation2_LowerSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[2].effort =
        motion_controller_slide_test_P.Saturation2_LowerSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[2].effort =
        motion_controller_slide_test_B.b_value;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    }

    // Saturate: '<S1>/Saturation1'
    if (u0 > motion_controller_slide_test_P.Saturation1_UpperSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[2].velocity =
        motion_controller_slide_test_P.Saturation1_UpperSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else if (u0 < motion_controller_slide_test_P.Saturation1_LowerSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[2].velocity =
        motion_controller_slide_test_P.Saturation1_LowerSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[2].velocity =
        u0;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    }

    // Saturate: '<S1>/Saturation2'
    motion_controller_slide_test_B.b_value =
      motion_controller_slide_test_B.effort_cmd[3];

    // Saturate: '<S1>/Saturation1'
    u0 = motion_controller_slide_test_B.spd_cmd[3];

    // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
    //   ForEach: '<S8>/For Each'

    // ForEachSliceAssignment generated from: '<S8>/actuaor_command' incorporates:
    //   BusAssignment: '<S8>/Bus Assignment1'
    //   Constant: '<S12>/Constant'

    motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[3] =
      motion_controller_slide_test_P.CoreSubsys_p.Constant_Value;

    // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'

    // Saturate: '<S1>/Saturation2'
    if (motion_controller_slide_test_B.b_value >
        motion_controller_slide_test_P.Saturation2_UpperSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[3].effort =
        motion_controller_slide_test_P.Saturation2_UpperSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else if (motion_controller_slide_test_B.b_value <
               motion_controller_slide_test_P.Saturation2_LowerSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[3].effort =
        motion_controller_slide_test_P.Saturation2_LowerSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[3].effort =
        motion_controller_slide_test_B.b_value;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    }

    // Saturate: '<S1>/Saturation1'
    if (u0 > motion_controller_slide_test_P.Saturation1_UpperSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[3].velocity =
        motion_controller_slide_test_P.Saturation1_UpperSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else if (u0 < motion_controller_slide_test_P.Saturation1_LowerSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[3].velocity =
        motion_controller_slide_test_P.Saturation1_LowerSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[3].velocity =
        u0;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    }

    // BusAssignment: '<S1>/Bus Assignment1' incorporates:
    //   DataTypeConversion: '<S1>/Data Type Conversion'

    motion_controller_slide_test_B.BusAssignment1.header.stamp =
      motion_controller_slide_test_B.CurrentTime1.CurrentTime;
    motion_controller_slide_test_B.BusAssignment1.drive_mode =
      motion_controller_slide_test_B.mode;
    memcpy(&motion_controller_slide_test_B.BusAssignment1.actuator_command[0],
           &motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[0],
           sizeof(SL_Bus_custom_interfaces_Actuator) << 2U);

    // MATLABSystem: '<S9>/SinkBlock'
    Pub_motion_controller_slide_test_4.publish
      (&motion_controller_slide_test_B.BusAssignment1);
    motion_controller_s_CurrentTime(&motion_controller_slide_test_B.CurrentTime);

    // BusAssignment: '<S1>/Bus Assignment2' incorporates:
    //   Constant: '<S5>/Constant'

    motion_controller_slide_test_B.BusAssignment1 =
      motion_controller_slide_test_P.Constant_Value_i;

    // Saturate: '<S1>/Saturation'
    motion_controller_slide_test_B.b_value =
      motion_controller_slide_test_B.angle_cmd[0];
    if (motion_controller_slide_test_B.b_value >
        motion_controller_slide_test_P.Saturation_UpperSat) {
      motion_controller_slide_test_B.b_value =
        motion_controller_slide_test_P.Saturation_UpperSat;
    } else if (motion_controller_slide_test_B.b_value <
               motion_controller_slide_test_P.Saturation_LowerSat) {
      motion_controller_slide_test_B.b_value =
        motion_controller_slide_test_P.Saturation_LowerSat;
    }

    motion_controller_slide_test_B.angle_cmd[0] =
      motion_controller_slide_test_B.b_value;

    // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem' incorporates:
    //   ForEach: '<S7>/For Each'

    // ForEachSliceAssignment generated from: '<S7>/actuaor_command' incorporates:
    //   BusAssignment: '<S7>/Bus Assignment1'
    //   Constant: '<S11>/Constant'

    motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[0] =
      motion_controller_slide_test_P.CoreSubsys.Constant_Value;

    // BusAssignment: '<S7>/Bus Assignment1' incorporates:
    //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'
    //   ForEachSliceSelector generated from: '<S7>/servo_position'

    motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[0].position =
      motion_controller_slide_test_B.b_value;

    // End of Outputs for SubSystem: '<S1>/For Each Subsystem'

    // Saturate: '<S1>/Saturation'
    motion_controller_slide_test_B.b_value =
      motion_controller_slide_test_B.angle_cmd[1];
    if (motion_controller_slide_test_B.b_value >
        motion_controller_slide_test_P.Saturation_UpperSat) {
      motion_controller_slide_test_B.b_value =
        motion_controller_slide_test_P.Saturation_UpperSat;
    } else if (motion_controller_slide_test_B.b_value <
               motion_controller_slide_test_P.Saturation_LowerSat) {
      motion_controller_slide_test_B.b_value =
        motion_controller_slide_test_P.Saturation_LowerSat;
    }

    motion_controller_slide_test_B.angle_cmd[1] =
      motion_controller_slide_test_B.b_value;

    // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem' incorporates:
    //   ForEach: '<S7>/For Each'

    // ForEachSliceAssignment generated from: '<S7>/actuaor_command' incorporates:
    //   BusAssignment: '<S7>/Bus Assignment1'
    //   Constant: '<S11>/Constant'

    motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[1] =
      motion_controller_slide_test_P.CoreSubsys.Constant_Value;

    // BusAssignment: '<S7>/Bus Assignment1' incorporates:
    //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'
    //   ForEachSliceSelector generated from: '<S7>/servo_position'

    motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[1].position =
      motion_controller_slide_test_B.b_value;

    // End of Outputs for SubSystem: '<S1>/For Each Subsystem'

    // Saturate: '<S1>/Saturation'
    motion_controller_slide_test_B.b_value =
      motion_controller_slide_test_B.angle_cmd[2];
    if (motion_controller_slide_test_B.b_value >
        motion_controller_slide_test_P.Saturation_UpperSat) {
      motion_controller_slide_test_B.b_value =
        motion_controller_slide_test_P.Saturation_UpperSat;
    } else if (motion_controller_slide_test_B.b_value <
               motion_controller_slide_test_P.Saturation_LowerSat) {
      motion_controller_slide_test_B.b_value =
        motion_controller_slide_test_P.Saturation_LowerSat;
    }

    motion_controller_slide_test_B.angle_cmd[2] =
      motion_controller_slide_test_B.b_value;

    // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem' incorporates:
    //   ForEach: '<S7>/For Each'

    // ForEachSliceAssignment generated from: '<S7>/actuaor_command' incorporates:
    //   BusAssignment: '<S7>/Bus Assignment1'
    //   Constant: '<S11>/Constant'

    motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[2] =
      motion_controller_slide_test_P.CoreSubsys.Constant_Value;

    // BusAssignment: '<S7>/Bus Assignment1' incorporates:
    //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'
    //   ForEachSliceSelector generated from: '<S7>/servo_position'

    motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[2].position =
      motion_controller_slide_test_B.b_value;

    // End of Outputs for SubSystem: '<S1>/For Each Subsystem'

    // Saturate: '<S1>/Saturation'
    motion_controller_slide_test_B.b_value =
      motion_controller_slide_test_B.angle_cmd[3];
    if (motion_controller_slide_test_B.b_value >
        motion_controller_slide_test_P.Saturation_UpperSat) {
      motion_controller_slide_test_B.b_value =
        motion_controller_slide_test_P.Saturation_UpperSat;
    } else if (motion_controller_slide_test_B.b_value <
               motion_controller_slide_test_P.Saturation_LowerSat) {
      motion_controller_slide_test_B.b_value =
        motion_controller_slide_test_P.Saturation_LowerSat;
    }

    motion_controller_slide_test_B.angle_cmd[3] =
      motion_controller_slide_test_B.b_value;

    // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem' incorporates:
    //   ForEach: '<S7>/For Each'

    // ForEachSliceAssignment generated from: '<S7>/actuaor_command' incorporates:
    //   BusAssignment: '<S7>/Bus Assignment1'
    //   Constant: '<S11>/Constant'

    motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[3] =
      motion_controller_slide_test_P.CoreSubsys.Constant_Value;

    // BusAssignment: '<S7>/Bus Assignment1' incorporates:
    //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'
    //   ForEachSliceSelector generated from: '<S7>/servo_position'

    motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[3].position =
      motion_controller_slide_test_B.b_value;

    // End of Outputs for SubSystem: '<S1>/For Each Subsystem'

    // BusAssignment: '<S1>/Bus Assignment2'
    motion_controller_slide_test_B.BusAssignment1.header.stamp =
      motion_controller_slide_test_B.CurrentTime.CurrentTime;
    memcpy(&motion_controller_slide_test_B.BusAssignment1.actuator_command[0],
           &motion_controller_slide_test_B.ImpAsg_InsertedFor_actuaor_[0],
           sizeof(SL_Bus_custom_interfaces_Actuator) << 2U);

    // MATLABSystem: '<S10>/SinkBlock'
    Pub_motion_controller_slide_test_148.publish
      (&motion_controller_slide_test_B.BusAssignment1);
  }

  // End of RelationalOperator: '<S3>/Compare'
  // End of Outputs for SubSystem: '<Root>/cmd_pub'
}

// Model initialize function
void motion_controller_slide_test::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    static const char_T prmName[9] = "distance";

    // SystemInitialize for Enabled SubSystem: '<S20>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S23>/In1' incorporates:
    //   Outport: '<S23>/Out1'

    motion_controller_slide_test_B.In1_m =
      motion_controller_slide_test_P.Out1_Y0_f;

    // End of SystemInitialize for SubSystem: '<S20>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S21>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S24>/In1' incorporates:
    //   Outport: '<S24>/Out1'

    motion_controller_slide_test_B.In1 = motion_controller_slide_test_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S21>/Enabled Subsystem'

    // SystemInitialize for Atomic SubSystem: '<Root>/controller'
    // SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S2>/get_effort' incorporates:
    //   SubSystem: '<S2>/get_effort'

    motion_controll_get_effort_Init();

    // End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S2>/get_effort' 

    // SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S2>/get_spd' incorporates:
    //   SubSystem: '<S2>/get_spd'

    motion_controller__get_spd_Init();

    // End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S2>/get_spd' 

    // SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S2>/get_angle' incorporates:
    //   SubSystem: '<S2>/get_angle'

    motion_controlle_get_angle_Init();

    // End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S2>/get_angle' 

    // Start for MATLABSystem: '<S2>/Get Parameter'
    motion_controller_slide_test_DW.obj_e.matlabCodegenIsDeleted = false;
    motion_controller_slide_test_DW.obj_e.isInitialized = 1;
    ParamGet_motion_controller_slide_test_291.initParam(&prmName[0]);
    ParamGet_motion_controller_slide_test_291.setInitialValue(1.0);
    motion_controller_slide_test_DW.obj_e.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<Root>/controller'

    // SystemInitialize for Enabled SubSystem: '<Root>/cmd_pub'
    motion_control_CurrentTime_Init
      (&motion_controller_slide_test_DW.CurrentTime1);

    // Start for MATLABSystem: '<S9>/SinkBlock'
    motion_control_SystemCore_setup(&motion_controller_slide_test_DW.obj_b);
    motion_control_CurrentTime_Init(&motion_controller_slide_test_DW.CurrentTime);

    // Start for MATLABSystem: '<S10>/SinkBlock'
    motion_contr_SystemCore_setup_h(&motion_controller_slide_test_DW.obj_c);

    // End of SystemInitialize for SubSystem: '<Root>/cmd_pub'

    // Start for MATLABSystem: '<S20>/SourceBlock'
    motion_cont_SystemCore_setup_h0(&motion_controller_slide_test_DW.obj_n);

    // Start for MATLABSystem: '<S21>/SourceBlock'
    motion_con_SystemCore_setup_h0k(&motion_controller_slide_test_DW.obj_l);
  }
}

// Model terminate function
void motion_controller_slide_test::terminate()
{
  // Terminate for MATLABSystem: '<S20>/SourceBlock'
  if (!motion_controller_slide_test_DW.obj_n.matlabCodegenIsDeleted) {
    motion_controller_slide_test_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S20>/SourceBlock'

  // Terminate for MATLABSystem: '<S21>/SourceBlock'
  if (!motion_controller_slide_test_DW.obj_l.matlabCodegenIsDeleted) {
    motion_controller_slide_test_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S21>/SourceBlock'

  // Terminate for Atomic SubSystem: '<Root>/controller'
  // Terminate for S-Function (sfun_private_function_caller) generated from: '<S2>/get_angle' incorporates:
  //   SubSystem: '<S2>/get_angle'

  motion_controlle_get_angle_Term();

  // End of Terminate for S-Function (sfun_private_function_caller) generated from: '<S2>/get_angle' 

  // Terminate for MATLABSystem: '<S2>/Get Parameter'
  if (!motion_controller_slide_test_DW.obj_e.matlabCodegenIsDeleted) {
    motion_controller_slide_test_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/Get Parameter'

  // Terminate for S-Function (sfun_private_function_caller) generated from: '<S2>/get_effort' incorporates:
  //   SubSystem: '<S2>/get_effort'

  motion_controll_get_effort_Term();

  // End of Terminate for S-Function (sfun_private_function_caller) generated from: '<S2>/get_effort' 

  // Terminate for S-Function (sfun_private_function_caller) generated from: '<S2>/get_spd' incorporates:
  //   SubSystem: '<S2>/get_spd'

  motion_controller__get_spd_Term();

  // End of Terminate for S-Function (sfun_private_function_caller) generated from: '<S2>/get_spd' 
  // End of Terminate for SubSystem: '<Root>/controller'

  // Terminate for Enabled SubSystem: '<Root>/cmd_pub'
  motion_control_CurrentTime_Term(&motion_controller_slide_test_DW.CurrentTime1);

  // Terminate for MATLABSystem: '<S9>/SinkBlock'
  if (!motion_controller_slide_test_DW.obj_b.matlabCodegenIsDeleted) {
    motion_controller_slide_test_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/SinkBlock'
  motion_control_CurrentTime_Term(&motion_controller_slide_test_DW.CurrentTime);

  // Terminate for MATLABSystem: '<S10>/SinkBlock'
  if (!motion_controller_slide_test_DW.obj_c.matlabCodegenIsDeleted) {
    motion_controller_slide_test_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/cmd_pub'
}

// Constructor
motion_controller_slide_test::motion_controller_slide_test() :
  motion_controller_slide_test_B(),
  motion_controller_slide_test_DW(),
  motion_controller_slide_test_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
motion_controller_slide_test::~motion_controller_slide_test()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_motion_controller_sl_T * motion_controller_slide_test::getRTM()
{
  return (&motion_controller_slide_test_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
