//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: motion_controller_circle_test.cpp
//
// Code generated for Simulink model 'motion_controller_circle_test'.
//
// Model version                  : 2.193
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Mon Dec  4 13:23:35 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "motion_controller_circle_test.h"
#include "rtwtypes.h"
#include "motion_controller_circle_test_types.h"
#include <math.h>
#include "rt_atan2d_snf.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <string.h>
#include "rmw/qos_profiles.h"
#include <stddef.h>

// Named constants for Chart: '<Root>/Chart'
const uint8_T motion_controller__IN_set_angle = 3U;
const uint8_T motion_controller_c_IN_waitting = 4U;
const uint8_T motion_controller_ci_IN_running = 2U;
const uint8_T motion_controller_ci_IN_waiting = 4U;
const uint8_T motion_controller_circle_IN_ini = 1U;

// Named constants for Chart: '<S4>/Chart1'
const uint8_T motion_contro_IN_velocity_mode1 = 2U;
const uint8_T motion_controlle_IN_effort_mode = 2U;
const uint8_T motion_controller_circle_IN_Ini = 1U;

// System initialize for atomic system:
void motion_controller_circle_test::motion_control_CurrentTime_Init
  (DW_CurrentTime_motion_control_T *localDW)
{
  // Start for MATLABSystem: '<S3>/Current Time'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void motion_controller_circle_test::motion_controller_c_CurrentTime
  (B_CurrentTime_motion_controll_T *localB)
{
  // MATLABSystem: '<S3>/Current Time'
  currentROS2TimeBus(&localB->CurrentTime);
}

// Termination for atomic system:
void motion_controller_circle_test::motion_control_CurrentTime_Term
  (DW_CurrentTime_motion_control_T *localDW)
{
  // Terminate for MATLABSystem: '<S3>/Current Time'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/Current Time'
}

// System initialize for Simulink Function: '<S4>/get_angle'
void motion_controller_circle_test::motion_controlle_get_angle_Init()
{
  static const char_T prmName[9] = "angleMax";

  // Start for MATLABSystem: '<S16>/Get Parameter'
  motion_controller_circle_tes_DW.obj_j.matlabCodegenIsDeleted = false;
  motion_controller_circle_tes_DW.obj_j.isInitialized = 1;
  ParamGet_motion_controller_circle_test_193.initParam(&prmName[0]);
  ParamGet_motion_controller_circle_test_193.setInitialValue(0.6);
  motion_controller_circle_tes_DW.obj_j.isSetupComplete = true;
}

// Output and update for Simulink Function: '<S4>/get_angle'
void motion_controller_circle_test::motion_controller_cir_get_angle(real_T
  rtu_angle, real_T rty_angle_cmd[4])
{
  real_T b_value;

  // MATLABSystem: '<S16>/Get Parameter'
  ParamGet_motion_controller_circle_test_193.getParameter(&b_value);

  // MATLAB Function: '<S16>/MATLAB Function' incorporates:
  //   Constant: '<S16>/Constant'
  //   MATLABSystem: '<S16>/Get Parameter'
  //   SignalConversion generated from: '<S16>/angle'

  b_value *= rtu_angle;
  if (motion_controller_circle_test_P.Constant_Value_j == 1.0) {
    b_value = motion_controller_circle_test_P.L / (tan(b_value) + 1.0E-9);
    if (b_value >= 0.0) {
      // SignalConversion generated from: '<S16>/angle_cmd'
      rty_angle_cmd[0] = rt_atan2d_snf(motion_controller_circle_test_P.L,
        b_value - motion_controller_circle_test_P.Tw / 2.0);
      b_value = rt_atan2d_snf(motion_controller_circle_test_P.L,
        motion_controller_circle_test_P.Tw / 2.0 + b_value);
    } else {
      // SignalConversion generated from: '<S16>/angle_cmd'
      rty_angle_cmd[0] = rt_atan2d_snf(motion_controller_circle_test_P.L,
        b_value - motion_controller_circle_test_P.Tw / 2.0) - 3.1415926535897931;
      b_value = rt_atan2d_snf(motion_controller_circle_test_P.L,
        motion_controller_circle_test_P.Tw / 2.0 + b_value) - 3.1415926535897931;
    }
  } else {
    // SignalConversion generated from: '<S16>/angle_cmd'
    rty_angle_cmd[0] = b_value;
  }

  // SignalConversion generated from: '<S16>/angle_cmd' incorporates:
  //   MATLAB Function: '<S16>/MATLAB Function'

  rty_angle_cmd[1] = b_value;
  rty_angle_cmd[2] = 0.0;
  rty_angle_cmd[3] = 0.0;
}

// Termination for Simulink Function: '<S4>/get_angle'
void motion_controller_circle_test::motion_controlle_get_angle_Term()
{
  // Terminate for MATLABSystem: '<S16>/Get Parameter'
  if (!motion_controller_circle_tes_DW.obj_j.matlabCodegenIsDeleted) {
    motion_controller_circle_tes_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S16>/Get Parameter'
}

// System initialize for Simulink Function: '<S4>/get_effort'
void motion_controller_circle_test::motion_controll_get_effort_Init()
{
  static const char_T prmName[10] = "effortMax";

  // Start for MATLABSystem: '<S17>/Get Parameter'
  motion_controller_circle_tes_DW.obj.matlabCodegenIsDeleted = false;
  motion_controller_circle_tes_DW.obj.isInitialized = 1;
  ParamGet_motion_controller_circle_test_202.initParam(&prmName[0]);
  ParamGet_motion_controller_circle_test_202.setInitialValue(0.3);
  motion_controller_circle_tes_DW.obj.isSetupComplete = true;
}

// Output and update for Simulink Function: '<S4>/get_effort'
void motion_controller_circle_test::motion_controller_ci_get_effort(real_T
  rtu_longdrive, real_T rty_effort_cmd[4])
{
  real_T b_value;

  // MATLABSystem: '<S17>/Get Parameter'
  ParamGet_motion_controller_circle_test_202.getParameter(&b_value);

  // MATLAB Function: '<S17>/MATLAB Function' incorporates:
  //   MATLABSystem: '<S17>/Get Parameter'
  //   SignalConversion generated from: '<S17>/longdrive'

  b_value *= rtu_longdrive;

  // SignalConversion generated from: '<S17>/effort_cmd' incorporates:
  //   MATLAB Function: '<S17>/MATLAB Function'

  rty_effort_cmd[0] = b_value;
  rty_effort_cmd[1] = -b_value;
  rty_effort_cmd[2] = -b_value;
  rty_effort_cmd[3] = b_value;
}

// Termination for Simulink Function: '<S4>/get_effort'
void motion_controller_circle_test::motion_controll_get_effort_Term()
{
  // Terminate for MATLABSystem: '<S17>/Get Parameter'
  if (!motion_controller_circle_tes_DW.obj.matlabCodegenIsDeleted) {
    motion_controller_circle_tes_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S17>/Get Parameter'
}

void motion_controller_circle_test::motion_control_SystemCore_setup
  (ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[11];
  static const char_T b_zeroDelimTopic_0[11] = "/motor_cmd";

  // Start for MATLABSystem: '<S11>/SinkBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S11>/SinkBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)5.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 11; i++) {
    // Start for MATLABSystem: '<S11>/SinkBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Pub_motion_controller_circle_test_4.createPublisher(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_circle_test::motion_contr_SystemCore_setup_d
  (ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[11];
  static const char_T b_zeroDelimTopic_0[11] = "/servo_cmd";

  // Start for MATLABSystem: '<S12>/SinkBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S12>/SinkBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)10.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 11; i++) {
    // Start for MATLABSystem: '<S12>/SinkBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Pub_motion_controller_circle_test_148.createPublisher(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_circle_test::motion_cont_SystemCore_setup_de
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

  Sub_motion_controller_circle_test_1.createSubscriber(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

// Model step function
void motion_controller_circle_test::step()
{
  real_T b_value;
  real_T rtb_Gain1;
  real_T rtb_Gain2;
  boolean_T b_varargout_1;
  boolean_T rtb_LogicalOperator;

  // MATLABSystem: '<Root>/Get Parameter1'
  ParamGet_motion_controller_circle_test_295.getParameter(&b_value);

  // MATLABSystem: '<S20>/SourceBlock'
  b_varargout_1 = Sub_motion_controller_circle_test_1.getLatestMessage
    (&motion_controller_circle_test_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S20>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S22>/Enable'

  // Start for MATLABSystem: '<S20>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S22>/In1'
    motion_controller_circle_test_B.In1 =
      motion_controller_circle_test_B.b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S20>/Enabled Subsystem'

  // Gain: '<S2>/Gain1' incorporates:
  //   Constant: '<S2>/Constant2'
  //   SignalConversion generated from: '<S6>/Bus Selector'
  //   Sum: '<S2>/Add1'

  rtb_Gain1 = (static_cast<real_T>
               (motion_controller_circle_test_B.In1.mapped_channels[1]) -
               motion_controller_circle_test_P.Constant2_Value) *
    motion_controller_circle_test_P.Gain1_Gain;

  // Gain: '<S2>/Gain2' incorporates:
  //   Constant: '<S2>/Constant'
  //   Gain: '<S2>/Gain'
  //   SignalConversion generated from: '<S6>/Bus Selector'
  //   Sum: '<S2>/Add'

  rtb_Gain2 = (static_cast<real_T>
               (motion_controller_circle_test_B.In1.mapped_channels[0]) -
               motion_controller_circle_test_P.Constant_Value_iw) *
    motion_controller_circle_test_P.Gain_Gain *
    motion_controller_circle_test_P.Gain2_Gain;

  // Chart: '<Root>/Chart' incorporates:
  //   MATLABSystem: '<Root>/Get Parameter1'

  if (motion_controller_circle_tes_DW.is_active_c5_motion_controller_ == 0U) {
    motion_controller_circle_tes_DW.is_active_c5_motion_controller_ = 1U;
    motion_controller_circle_tes_DW.is_steer = motion_controller_circle_IN_ini;
    motion_controller_circle_test_B.angle_out = 0.0;
    motion_controller_circle_tes_DW.is_longdrive =
      motion_controller_circle_IN_ini;
    motion_controller_circle_test_B.longdrive_out = rtb_Gain1;
  } else {
    switch (motion_controller_circle_tes_DW.is_steer) {
     case motion_controller_circle_IN_ini:
      if (fabs(rtb_Gain2) > 0.1) {
        motion_controller_circle_tes_DW.is_steer =
          motion_controller__IN_set_angle;
        motion_controller_circle_tes_DW.counter_f = 50.0;
        motion_controller_circle_test_B.angle_out = rtb_Gain2;
      }
      break;

     case motion_controller_ci_IN_running:
      if (rtb_Gain2 >= 0.4) {
        motion_controller_circle_tes_DW.is_steer =
          motion_controller_ci_IN_waiting;
        motion_controller_circle_test_B.angle_out =
          motion_controller_circle_tes_DW.ini;
      } else if (!(fabs(motion_controller_circle_test_B.angle_out) >= 1.0)) {
        if (motion_controller_circle_test_B.angle_out >= 0.0) {
          motion_controller_circle_test_B.angle_out += b_value / 180.0 *
            3.1415926535897931 / 100.0;
        } else {
          motion_controller_circle_test_B.angle_out -= b_value / 180.0 *
            3.1415926535897931 / 100.0;
        }
      }
      break;

     case motion_controller__IN_set_angle:
      if (rtb_Gain2 == 0.0) {
        motion_controller_circle_tes_DW.ini =
          motion_controller_circle_test_B.angle_out;
        motion_controller_circle_tes_DW.is_steer =
          motion_controller_circle_IN_ini;
        motion_controller_circle_test_B.angle_out = 0.0;
      } else if (motion_controller_circle_tes_DW.counter_f <= 1.0) {
        motion_controller_circle_tes_DW.ini =
          motion_controller_circle_test_B.angle_out;
        motion_controller_circle_tes_DW.is_steer =
          motion_controller_ci_IN_waiting;
      } else {
        motion_controller_circle_tes_DW.counter_f--;
        if (fabs(rtb_Gain2 - motion_controller_circle_test_B.angle_out) > 0.02)
        {
          motion_controller_circle_test_B.angle_out = rtb_Gain2;
          motion_controller_circle_tes_DW.counter_f = 50.0;
        }
      }
      break;

     default:
      // case IN_waiting:
      if (rtb_Gain2 <= -0.98) {
        motion_controller_circle_tes_DW.is_steer =
          motion_controller_ci_IN_running;
        if (!(fabs(motion_controller_circle_test_B.angle_out) >= 1.0)) {
          if (motion_controller_circle_test_B.angle_out >= 0.0) {
            motion_controller_circle_test_B.angle_out += b_value / 180.0 *
              3.1415926535897931 / 100.0;
          } else {
            motion_controller_circle_test_B.angle_out -= b_value / 180.0 *
              3.1415926535897931 / 100.0;
          }
        }
      } else if (rtb_Gain2 == 1.0) {
        motion_controller_circle_tes_DW.is_steer =
          motion_controller__IN_set_angle;
        motion_controller_circle_tes_DW.counter_f = 50.0;
        motion_controller_circle_test_B.angle_out = 1.0;
      }
      break;
    }

    switch (motion_controller_circle_tes_DW.is_longdrive) {
     case motion_controller_circle_IN_ini:
      if (rtb_Gain1 >= 0.05) {
        motion_controller_circle_tes_DW.is_longdrive =
          motion_controller__IN_set_angle;
        motion_controller_circle_tes_DW.counter_ld = 150.0;
        motion_controller_circle_test_B.longdrive_out = rtb_Gain1;
      } else {
        motion_controller_circle_test_B.longdrive_out = rtb_Gain1;
      }
      break;

     case motion_controller_ci_IN_running:
      if (rtb_Gain1 < -0.1) {
        motion_controller_circle_tes_DW.is_longdrive =
          motion_controller__IN_set_angle;
        motion_controller_circle_tes_DW.counter_ld = 150.0;
        motion_controller_circle_test_B.longdrive_out = rtb_Gain1;
      } else if (rtb_Gain1 > 0.9) {
        motion_controller_circle_tes_DW.is_longdrive =
          motion_controller_c_IN_waitting;
        motion_controller_circle_test_B.longdrive_out = 0.0;
      }
      break;

     case motion_controller__IN_set_angle:
      if (motion_controller_circle_test_B.longdrive_out < 0.02) {
        motion_controller_circle_tes_DW.ini_ld =
          motion_controller_circle_test_B.longdrive_out;
        motion_controller_circle_tes_DW.is_longdrive =
          motion_controller_circle_IN_ini;
        motion_controller_circle_test_B.longdrive_out = rtb_Gain1;
      } else if (motion_controller_circle_tes_DW.counter_ld <= 1.0) {
        motion_controller_circle_tes_DW.ini_ld =
          motion_controller_circle_test_B.longdrive_out;
        motion_controller_circle_tes_DW.is_longdrive =
          motion_controller_ci_IN_running;
      } else {
        motion_controller_circle_tes_DW.counter_ld--;
        if (fabs(rtb_Gain1 - motion_controller_circle_test_B.longdrive_out) >
            0.02) {
          motion_controller_circle_test_B.longdrive_out = rtb_Gain1;
          motion_controller_circle_tes_DW.counter_ld = 150.0;
        }
      }
      break;

     default:
      // case IN_waitting:
      if (rtb_Gain1 < 0.2) {
        motion_controller_circle_tes_DW.is_longdrive =
          motion_controller_ci_IN_running;
        motion_controller_circle_test_B.longdrive_out =
          motion_controller_circle_tes_DW.ini_ld;
      }
      break;
    }
  }

  // End of Chart: '<Root>/Chart'

  // Logic: '<Root>/LogicalOperator'
  rtb_LogicalOperator = (motion_controller_circle_test_B.In1.failsafe ||
    motion_controller_circle_test_B.In1.frame_lost);

  // Outputs for Atomic SubSystem: '<Root>/controller'
  // Chart: '<S4>/Chart1' incorporates:
  //   MATLABSystem: '<S20>/SourceBlock'
  //   SignalConversion generated from: '<S6>/Bus Selector'
  //
  if (motion_controller_circle_tes_DW.is_active_c6_motion_controller_ == 0U) {
    motion_controller_circle_tes_DW.is_active_c6_motion_controller_ = 1U;
    motion_controller_circle_tes_DW.is_Is_ready =
      motion_controller_circle_IN_Ini;
    motion_controller_circle_tes_DW.check = 1.0;
    motion_controller_circle_tes_DW.ready = false;
    motion_controller_circle_tes_DW.is_cmd = motion_controller_circle_IN_Ini;
    motion_controller_circle_test_B.angle_cmd[0] = 0.0;
    motion_controller_circle_test_B.spd_cmd[0] = 0.0;
    motion_controller_circle_test_B.effort_cmd[0] = 0.0;
    motion_controller_circle_test_B.angle_cmd[1] = 0.0;
    motion_controller_circle_test_B.spd_cmd[1] = 0.0;
    motion_controller_circle_test_B.effort_cmd[1] = 0.0;
    motion_controller_circle_test_B.angle_cmd[2] = 0.0;
    motion_controller_circle_test_B.spd_cmd[2] = 0.0;
    motion_controller_circle_test_B.effort_cmd[2] = 0.0;
    motion_controller_circle_test_B.angle_cmd[3] = 0.0;
    motion_controller_circle_test_B.spd_cmd[3] = 0.0;
    motion_controller_circle_test_B.effort_cmd[3] = 0.0;
    motion_controller_circle_test_B.mode = 0;
  } else {
    if (motion_controller_circle_tes_DW.is_Is_ready ==
        motion_controller_circle_IN_Ini) {
      if ((motion_controller_circle_test_B.In1.mapped_channels[3] == 1000) &&
          (!rtb_LogicalOperator) && b_varargout_1) {
        motion_controller_circle_tes_DW.is_Is_ready =
          motion_contro_IN_velocity_mode1;
        motion_controller_circle_tes_DW.ready = true;
        motion_controller_circle_tes_DW.check = 1.0;
        motion_controller_circle_tes_DW.sum = 0.0;
        motion_controller_circle_tes_DW.counter = 0.0;
      }

      // case IN_velocity_mode1:
    } else if ((motion_controller_circle_test_B.In1.mapped_channels[3] != 1000) ||
               rtb_LogicalOperator || (motion_controller_circle_tes_DW.check ==
                0.0)) {
      motion_controller_circle_tes_DW.is_Is_ready =
        motion_controller_circle_IN_Ini;
      motion_controller_circle_tes_DW.check = 1.0;
      motion_controller_circle_tes_DW.ready = false;
    } else {
      motion_controller_circle_tes_DW.counter++;
      motion_controller_circle_tes_DW.sum += static_cast<real_T>(b_varargout_1);
      if (rtIsNaN(motion_controller_circle_tes_DW.counter)) {
        b_value = (rtNaN);
      } else if (rtIsInf(motion_controller_circle_tes_DW.counter)) {
        b_value = (rtNaN);
      } else if (motion_controller_circle_tes_DW.counter == 0.0) {
        b_value = 0.0;
      } else {
        b_value = fmod(motion_controller_circle_tes_DW.counter, 20.0);
        if (b_value == 0.0) {
          b_value = 0.0;
        } else if (motion_controller_circle_tes_DW.counter < 0.0) {
          b_value += 20.0;
        }
      }

      if (b_value == 0.0) {
        motion_controller_circle_tes_DW.check =
          motion_controller_circle_tes_DW.sum;
        motion_controller_circle_tes_DW.sum = 0.0;
      }
    }

    if (motion_controller_circle_tes_DW.is_cmd ==
        motion_controller_circle_IN_Ini) {
      motion_controller_circle_test_B.spd_cmd[0] = 0.0;
      motion_controller_circle_test_B.spd_cmd[1] = 0.0;
      motion_controller_circle_test_B.spd_cmd[2] = 0.0;
      motion_controller_circle_test_B.spd_cmd[3] = 0.0;
      if (motion_controller_circle_tes_DW.ready) {
        motion_controller_circle_tes_DW.is_cmd = motion_controlle_IN_effort_mode;
        motion_controller_circle_test_B.effort_cmd[0] = 0.0;
        motion_controller_circle_test_B.effort_cmd[1] = 0.0;
        motion_controller_circle_test_B.effort_cmd[2] = 0.0;
        motion_controller_circle_test_B.effort_cmd[3] = 0.0;
      }

      // case IN_effort_mode:
    } else if (!motion_controller_circle_tes_DW.ready) {
      motion_controller_circle_tes_DW.is_cmd = motion_controller_circle_IN_Ini;
      motion_controller_circle_test_B.angle_cmd[0] = 0.0;
      motion_controller_circle_test_B.spd_cmd[0] = 0.0;
      motion_controller_circle_test_B.effort_cmd[0] = 0.0;
      motion_controller_circle_test_B.angle_cmd[1] = 0.0;
      motion_controller_circle_test_B.spd_cmd[1] = 0.0;
      motion_controller_circle_test_B.effort_cmd[1] = 0.0;
      motion_controller_circle_test_B.angle_cmd[2] = 0.0;
      motion_controller_circle_test_B.spd_cmd[2] = 0.0;
      motion_controller_circle_test_B.effort_cmd[2] = 0.0;
      motion_controller_circle_test_B.angle_cmd[3] = 0.0;
      motion_controller_circle_test_B.spd_cmd[3] = 0.0;
      motion_controller_circle_test_B.effort_cmd[3] = 0.0;
      motion_controller_circle_test_B.mode = 0;
    } else {
      motion_controller_cir_get_angle(motion_controller_circle_test_B.angle_out,
        motion_controller_circle_test_B.angle_cmd);
      motion_controller_ci_get_effort
        (motion_controller_circle_test_B.longdrive_out,
         motion_controller_circle_test_B.effort_cmd);
      motion_controller_circle_test_B.mode = 2;
      if (motion_controller_circle_test_B.longdrive_out < -0.2) {
        motion_controller_circle_test_B.mode = 0;
      }
    }
  }

  // End of Chart: '<S4>/Chart1'
  // End of Outputs for SubSystem: '<Root>/controller'

  // Outputs for Enabled SubSystem: '<Root>/cmd_pub' incorporates:
  //   EnablePort: '<S3>/Enable'

  // RelationalOperator: '<S5>/Compare' incorporates:
  //   Constant: '<S5>/Constant'
  //   SignalConversion generated from: '<S6>/Bus Selector'

  if (motion_controller_circle_test_B.In1.mapped_channels[5] ==
      motion_controller_circle_test_P.ctc_const) {
    motion_controller_c_CurrentTime
      (&motion_controller_circle_test_B.CurrentTime1);

    // BusAssignment: '<S3>/Bus Assignment1' incorporates:
    //   Constant: '<S8>/Constant'

    motion_controller_circle_test_B.BusAssignment1 =
      motion_controller_circle_test_P.Constant_Value;

    // Saturate: '<Root>/Saturation'
    b_value = motion_controller_circle_test_B.effort_cmd[0];
    if (b_value > motion_controller_circle_test_P.Saturation_UpperSat_k) {
      b_value = motion_controller_circle_test_P.Saturation_UpperSat_k;
    } else if (b_value < motion_controller_circle_test_P.Saturation_LowerSat_n)
    {
      b_value = motion_controller_circle_test_P.Saturation_LowerSat_n;
    }

    // Saturate: '<S3>/Saturation1'
    rtb_Gain1 = motion_controller_circle_test_B.spd_cmd[0];

    // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
    //   ForEach: '<S10>/For Each'

    // ForEachSliceAssignment generated from: '<S10>/actuaor_command' incorporates:
    //   BusAssignment: '<S10>/Bus Assignment1'
    //   Constant: '<S14>/Constant'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0] =
      motion_controller_circle_test_P.CoreSubsys_p.Constant_Value;

    // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'

    // Saturate: '<S3>/Saturation2'
    if (b_value > motion_controller_circle_test_P.Saturation2_UpperSat) {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0].effort =
        motion_controller_circle_test_P.Saturation2_UpperSat;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'
    } else if (b_value < motion_controller_circle_test_P.Saturation2_LowerSat) {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0].effort =
        motion_controller_circle_test_P.Saturation2_LowerSat;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0].effort =
        b_value;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'
    }

    // Saturate: '<S3>/Saturation1'
    if (rtb_Gain1 > motion_controller_circle_test_P.Saturation1_UpperSat) {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0].velocity =
        motion_controller_circle_test_P.Saturation1_UpperSat;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'
    } else if (rtb_Gain1 < motion_controller_circle_test_P.Saturation1_LowerSat)
    {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0].velocity =
        motion_controller_circle_test_P.Saturation1_LowerSat;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0].velocity =
        rtb_Gain1;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'
    }

    // Saturate: '<Root>/Saturation'
    b_value = motion_controller_circle_test_B.effort_cmd[1];
    if (b_value > motion_controller_circle_test_P.Saturation_UpperSat_k) {
      b_value = motion_controller_circle_test_P.Saturation_UpperSat_k;
    } else if (b_value < motion_controller_circle_test_P.Saturation_LowerSat_n)
    {
      b_value = motion_controller_circle_test_P.Saturation_LowerSat_n;
    }

    // Saturate: '<S3>/Saturation1'
    rtb_Gain1 = motion_controller_circle_test_B.spd_cmd[1];

    // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
    //   ForEach: '<S10>/For Each'

    // ForEachSliceAssignment generated from: '<S10>/actuaor_command' incorporates:
    //   BusAssignment: '<S10>/Bus Assignment1'
    //   Constant: '<S14>/Constant'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1] =
      motion_controller_circle_test_P.CoreSubsys_p.Constant_Value;

    // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'

    // Saturate: '<S3>/Saturation2'
    if (b_value > motion_controller_circle_test_P.Saturation2_UpperSat) {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1].effort =
        motion_controller_circle_test_P.Saturation2_UpperSat;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'
    } else if (b_value < motion_controller_circle_test_P.Saturation2_LowerSat) {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1].effort =
        motion_controller_circle_test_P.Saturation2_LowerSat;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1].effort =
        b_value;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'
    }

    // Saturate: '<S3>/Saturation1'
    if (rtb_Gain1 > motion_controller_circle_test_P.Saturation1_UpperSat) {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1].velocity =
        motion_controller_circle_test_P.Saturation1_UpperSat;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'
    } else if (rtb_Gain1 < motion_controller_circle_test_P.Saturation1_LowerSat)
    {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1].velocity =
        motion_controller_circle_test_P.Saturation1_LowerSat;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1].velocity =
        rtb_Gain1;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'
    }

    // Saturate: '<Root>/Saturation'
    b_value = motion_controller_circle_test_B.effort_cmd[2];
    if (b_value > motion_controller_circle_test_P.Saturation_UpperSat_k) {
      b_value = motion_controller_circle_test_P.Saturation_UpperSat_k;
    } else if (b_value < motion_controller_circle_test_P.Saturation_LowerSat_n)
    {
      b_value = motion_controller_circle_test_P.Saturation_LowerSat_n;
    }

    // Saturate: '<S3>/Saturation1'
    rtb_Gain1 = motion_controller_circle_test_B.spd_cmd[2];

    // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
    //   ForEach: '<S10>/For Each'

    // ForEachSliceAssignment generated from: '<S10>/actuaor_command' incorporates:
    //   BusAssignment: '<S10>/Bus Assignment1'
    //   Constant: '<S14>/Constant'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2] =
      motion_controller_circle_test_P.CoreSubsys_p.Constant_Value;

    // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'

    // Saturate: '<S3>/Saturation2'
    if (b_value > motion_controller_circle_test_P.Saturation2_UpperSat) {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2].effort =
        motion_controller_circle_test_P.Saturation2_UpperSat;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'
    } else if (b_value < motion_controller_circle_test_P.Saturation2_LowerSat) {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2].effort =
        motion_controller_circle_test_P.Saturation2_LowerSat;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2].effort =
        b_value;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'
    }

    // Saturate: '<S3>/Saturation1'
    if (rtb_Gain1 > motion_controller_circle_test_P.Saturation1_UpperSat) {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2].velocity =
        motion_controller_circle_test_P.Saturation1_UpperSat;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'
    } else if (rtb_Gain1 < motion_controller_circle_test_P.Saturation1_LowerSat)
    {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2].velocity =
        motion_controller_circle_test_P.Saturation1_LowerSat;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2].velocity =
        rtb_Gain1;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'
    }

    // Saturate: '<Root>/Saturation'
    b_value = motion_controller_circle_test_B.effort_cmd[3];
    if (b_value > motion_controller_circle_test_P.Saturation_UpperSat_k) {
      b_value = motion_controller_circle_test_P.Saturation_UpperSat_k;
    } else if (b_value < motion_controller_circle_test_P.Saturation_LowerSat_n)
    {
      b_value = motion_controller_circle_test_P.Saturation_LowerSat_n;
    }

    // Saturate: '<S3>/Saturation1'
    rtb_Gain1 = motion_controller_circle_test_B.spd_cmd[3];

    // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
    //   ForEach: '<S10>/For Each'

    // ForEachSliceAssignment generated from: '<S10>/actuaor_command' incorporates:
    //   BusAssignment: '<S10>/Bus Assignment1'
    //   Constant: '<S14>/Constant'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3] =
      motion_controller_circle_test_P.CoreSubsys_p.Constant_Value;

    // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'

    // Saturate: '<S3>/Saturation2'
    if (b_value > motion_controller_circle_test_P.Saturation2_UpperSat) {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3].effort =
        motion_controller_circle_test_P.Saturation2_UpperSat;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'
    } else if (b_value < motion_controller_circle_test_P.Saturation2_LowerSat) {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3].effort =
        motion_controller_circle_test_P.Saturation2_LowerSat;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3].effort =
        b_value;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'
    }

    // Saturate: '<S3>/Saturation1'
    if (rtb_Gain1 > motion_controller_circle_test_P.Saturation1_UpperSat) {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3].velocity =
        motion_controller_circle_test_P.Saturation1_UpperSat;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'
    } else if (rtb_Gain1 < motion_controller_circle_test_P.Saturation1_LowerSat)
    {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3].velocity =
        motion_controller_circle_test_P.Saturation1_LowerSat;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3].velocity =
        rtb_Gain1;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'
    }

    // BusAssignment: '<S3>/Bus Assignment1' incorporates:
    //   DataTypeConversion: '<S3>/Data Type Conversion'

    motion_controller_circle_test_B.BusAssignment1.header.stamp =
      motion_controller_circle_test_B.CurrentTime1.CurrentTime;
    motion_controller_circle_test_B.BusAssignment1.drive_mode =
      motion_controller_circle_test_B.mode;
    memcpy(&motion_controller_circle_test_B.BusAssignment1.actuator_command[0],
           &motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0],
           sizeof(SL_Bus_custom_interfaces_Actuator) << 2U);

    // MATLABSystem: '<S11>/SinkBlock'
    Pub_motion_controller_circle_test_4.publish
      (&motion_controller_circle_test_B.BusAssignment1);
    motion_controller_c_CurrentTime(&motion_controller_circle_test_B.CurrentTime);

    // BusAssignment: '<S3>/Bus Assignment2' incorporates:
    //   Constant: '<S7>/Constant'

    motion_controller_circle_test_B.BusAssignment1 =
      motion_controller_circle_test_P.Constant_Value_i;

    // Saturate: '<S3>/Saturation'
    b_value = motion_controller_circle_test_B.angle_cmd[0];

    // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem' incorporates:
    //   ForEach: '<S9>/For Each'

    // ForEachSliceAssignment generated from: '<S9>/actuaor_command' incorporates:
    //   BusAssignment: '<S9>/Bus Assignment1'
    //   Constant: '<S13>/Constant'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0] =
      motion_controller_circle_test_P.CoreSubsys.Constant_Value;

    // End of Outputs for SubSystem: '<S3>/For Each Subsystem'

    // Saturate: '<S3>/Saturation'
    if (b_value > motion_controller_circle_test_P.Saturation_UpperSat) {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem' incorporates:
      //   ForEach: '<S9>/For Each'

      // BusAssignment: '<S9>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S9>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0].position =
        motion_controller_circle_test_P.Saturation_UpperSat;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem'
    } else if (b_value < motion_controller_circle_test_P.Saturation_LowerSat) {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem' incorporates:
      //   ForEach: '<S9>/For Each'

      // BusAssignment: '<S9>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S9>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0].position =
        motion_controller_circle_test_P.Saturation_LowerSat;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem'
    } else {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem' incorporates:
      //   ForEach: '<S9>/For Each'

      // BusAssignment: '<S9>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S9>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0].position =
        b_value;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem'
    }

    b_value = motion_controller_circle_test_B.angle_cmd[1];

    // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem' incorporates:
    //   ForEach: '<S9>/For Each'

    // ForEachSliceAssignment generated from: '<S9>/actuaor_command' incorporates:
    //   BusAssignment: '<S9>/Bus Assignment1'
    //   Constant: '<S13>/Constant'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1] =
      motion_controller_circle_test_P.CoreSubsys.Constant_Value;

    // End of Outputs for SubSystem: '<S3>/For Each Subsystem'

    // Saturate: '<S3>/Saturation'
    if (b_value > motion_controller_circle_test_P.Saturation_UpperSat) {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem' incorporates:
      //   ForEach: '<S9>/For Each'

      // BusAssignment: '<S9>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S9>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1].position =
        motion_controller_circle_test_P.Saturation_UpperSat;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem'
    } else if (b_value < motion_controller_circle_test_P.Saturation_LowerSat) {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem' incorporates:
      //   ForEach: '<S9>/For Each'

      // BusAssignment: '<S9>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S9>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1].position =
        motion_controller_circle_test_P.Saturation_LowerSat;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem'
    } else {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem' incorporates:
      //   ForEach: '<S9>/For Each'

      // BusAssignment: '<S9>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S9>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1].position =
        b_value;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem'
    }

    b_value = motion_controller_circle_test_B.angle_cmd[2];

    // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem' incorporates:
    //   ForEach: '<S9>/For Each'

    // ForEachSliceAssignment generated from: '<S9>/actuaor_command' incorporates:
    //   BusAssignment: '<S9>/Bus Assignment1'
    //   Constant: '<S13>/Constant'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2] =
      motion_controller_circle_test_P.CoreSubsys.Constant_Value;

    // End of Outputs for SubSystem: '<S3>/For Each Subsystem'

    // Saturate: '<S3>/Saturation'
    if (b_value > motion_controller_circle_test_P.Saturation_UpperSat) {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem' incorporates:
      //   ForEach: '<S9>/For Each'

      // BusAssignment: '<S9>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S9>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2].position =
        motion_controller_circle_test_P.Saturation_UpperSat;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem'
    } else if (b_value < motion_controller_circle_test_P.Saturation_LowerSat) {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem' incorporates:
      //   ForEach: '<S9>/For Each'

      // BusAssignment: '<S9>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S9>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2].position =
        motion_controller_circle_test_P.Saturation_LowerSat;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem'
    } else {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem' incorporates:
      //   ForEach: '<S9>/For Each'

      // BusAssignment: '<S9>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S9>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2].position =
        b_value;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem'
    }

    b_value = motion_controller_circle_test_B.angle_cmd[3];

    // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem' incorporates:
    //   ForEach: '<S9>/For Each'

    // ForEachSliceAssignment generated from: '<S9>/actuaor_command' incorporates:
    //   BusAssignment: '<S9>/Bus Assignment1'
    //   Constant: '<S13>/Constant'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3] =
      motion_controller_circle_test_P.CoreSubsys.Constant_Value;

    // End of Outputs for SubSystem: '<S3>/For Each Subsystem'

    // Saturate: '<S3>/Saturation'
    if (b_value > motion_controller_circle_test_P.Saturation_UpperSat) {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem' incorporates:
      //   ForEach: '<S9>/For Each'

      // BusAssignment: '<S9>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S9>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3].position =
        motion_controller_circle_test_P.Saturation_UpperSat;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem'
    } else if (b_value < motion_controller_circle_test_P.Saturation_LowerSat) {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem' incorporates:
      //   ForEach: '<S9>/For Each'

      // BusAssignment: '<S9>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S9>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3].position =
        motion_controller_circle_test_P.Saturation_LowerSat;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem'
    } else {
      // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem' incorporates:
      //   ForEach: '<S9>/For Each'

      // BusAssignment: '<S9>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S9>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3].position =
        b_value;

      // End of Outputs for SubSystem: '<S3>/For Each Subsystem'
    }

    // BusAssignment: '<S3>/Bus Assignment2'
    motion_controller_circle_test_B.BusAssignment1.header.stamp =
      motion_controller_circle_test_B.CurrentTime.CurrentTime;
    memcpy(&motion_controller_circle_test_B.BusAssignment1.actuator_command[0],
           &motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0],
           sizeof(SL_Bus_custom_interfaces_Actuator) << 2U);

    // MATLABSystem: '<S12>/SinkBlock'
    Pub_motion_controller_circle_test_148.publish
      (&motion_controller_circle_test_B.BusAssignment1);
  }

  // End of RelationalOperator: '<S5>/Compare'
  // End of Outputs for SubSystem: '<Root>/cmd_pub'
}

// Model initialize function
void motion_controller_circle_test::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    static const char_T prmName[19] = "angle_increase_dps";

    // SystemInitialize for Enabled SubSystem: '<S20>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S22>/In1' incorporates:
    //   Outport: '<S22>/Out1'

    motion_controller_circle_test_B.In1 =
      motion_controller_circle_test_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S20>/Enabled Subsystem'

    // SystemInitialize for Atomic SubSystem: '<Root>/controller'
    // SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S4>/get_effort' incorporates:
    //   SubSystem: '<S4>/get_effort'

    motion_controll_get_effort_Init();

    // End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S4>/get_effort' 

    // SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S4>/get_angle' incorporates:
    //   SubSystem: '<S4>/get_angle'

    motion_controlle_get_angle_Init();

    // End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S4>/get_angle' 
    // End of SystemInitialize for SubSystem: '<Root>/controller'

    // SystemInitialize for Enabled SubSystem: '<Root>/cmd_pub'
    motion_control_CurrentTime_Init
      (&motion_controller_circle_tes_DW.CurrentTime1);

    // Start for MATLABSystem: '<S11>/SinkBlock'
    motion_control_SystemCore_setup(&motion_controller_circle_tes_DW.obj_b);
    motion_control_CurrentTime_Init(&motion_controller_circle_tes_DW.CurrentTime);

    // Start for MATLABSystem: '<S12>/SinkBlock'
    motion_contr_SystemCore_setup_d(&motion_controller_circle_tes_DW.obj_c);

    // End of SystemInitialize for SubSystem: '<Root>/cmd_pub'

    // Start for MATLABSystem: '<Root>/Get Parameter1'
    motion_controller_circle_tes_DW.obj_n.matlabCodegenIsDeleted = false;
    motion_controller_circle_tes_DW.obj_n.isInitialized = 1;
    ParamGet_motion_controller_circle_test_295.initParam(&prmName[0]);
    ParamGet_motion_controller_circle_test_295.setInitialValue(1.0);
    motion_controller_circle_tes_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<S20>/SourceBlock'
    motion_cont_SystemCore_setup_de(&motion_controller_circle_tes_DW.obj_nf);
  }
}

// Model terminate function
void motion_controller_circle_test::terminate()
{
  // Terminate for MATLABSystem: '<Root>/Get Parameter1'
  if (!motion_controller_circle_tes_DW.obj_n.matlabCodegenIsDeleted) {
    motion_controller_circle_tes_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter1'

  // Terminate for MATLABSystem: '<S20>/SourceBlock'
  if (!motion_controller_circle_tes_DW.obj_nf.matlabCodegenIsDeleted) {
    motion_controller_circle_tes_DW.obj_nf.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S20>/SourceBlock'

  // Terminate for Atomic SubSystem: '<Root>/controller'
  // Terminate for S-Function (sfun_private_function_caller) generated from: '<S4>/get_effort' incorporates:
  //   SubSystem: '<S4>/get_effort'

  motion_controll_get_effort_Term();

  // End of Terminate for S-Function (sfun_private_function_caller) generated from: '<S4>/get_effort' 

  // Terminate for S-Function (sfun_private_function_caller) generated from: '<S4>/get_angle' incorporates:
  //   SubSystem: '<S4>/get_angle'

  motion_controlle_get_angle_Term();

  // End of Terminate for S-Function (sfun_private_function_caller) generated from: '<S4>/get_angle' 
  // End of Terminate for SubSystem: '<Root>/controller'

  // Terminate for Enabled SubSystem: '<Root>/cmd_pub'
  motion_control_CurrentTime_Term(&motion_controller_circle_tes_DW.CurrentTime1);

  // Terminate for MATLABSystem: '<S11>/SinkBlock'
  if (!motion_controller_circle_tes_DW.obj_b.matlabCodegenIsDeleted) {
    motion_controller_circle_tes_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/SinkBlock'
  motion_control_CurrentTime_Term(&motion_controller_circle_tes_DW.CurrentTime);

  // Terminate for MATLABSystem: '<S12>/SinkBlock'
  if (!motion_controller_circle_tes_DW.obj_c.matlabCodegenIsDeleted) {
    motion_controller_circle_tes_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/cmd_pub'
}

// Constructor
motion_controller_circle_test::motion_controller_circle_test() :
  motion_controller_circle_test_B(),
  motion_controller_circle_tes_DW(),
  motion_controller_circle_tes_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
motion_controller_circle_test::~motion_controller_circle_test()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_motion_controller_ci_T * motion_controller_circle_test::getRTM()
{
  return (&motion_controller_circle_tes_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
