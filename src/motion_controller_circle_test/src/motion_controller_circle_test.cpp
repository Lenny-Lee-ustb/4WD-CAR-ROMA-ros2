//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: motion_controller_circle_test.cpp
//
// Code generated for Simulink model 'motion_controller_circle_test'.
//
// Model version                  : 2.201
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Tue Dec 19 21:19:51 2023
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

// Named constants for Chart: '<S1>/Chart'
const uint8_T motion_controller__IN_set_angle = 3U;
const uint8_T motion_controller_ci_IN_running = 2U;
const uint8_T motion_controller_ci_IN_waiting = 4U;
const uint8_T motion_controller_circle_IN_ini = 1U;

// Named constants for Chart: '<S3>/Chart1'
const uint8_T motion_contro_IN_velocity_mode1 = 2U;
const uint8_T motion_controlle_IN_effort_mode = 2U;
const uint8_T motion_controller_circle_IN_Ini = 1U;

// System initialize for atomic system:
void motion_controller_circle_test::motion_control_CurrentTime_Init
  (DW_CurrentTime_motion_control_T *localDW)
{
  // Start for MATLABSystem: '<S2>/Current Time'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void motion_controller_circle_test::motion_controller_c_CurrentTime
  (B_CurrentTime_motion_controll_T *localB)
{
  // MATLABSystem: '<S2>/Current Time'
  currentROS2TimeBus(&localB->CurrentTime);
}

// Termination for atomic system:
void motion_controller_circle_test::motion_control_CurrentTime_Term
  (DW_CurrentTime_motion_control_T *localDW)
{
  // Terminate for MATLABSystem: '<S2>/Current Time'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/Current Time'
}

// Output and update for Simulink Function: '<S3>/get_angle'
void motion_controller_circle_test::motion_controller_cir_get_angle(real_T
  rtu_angle, real_T rty_angle_cmd[4]) const
{
  real_T deltaFR;

  // MATLAB Function: '<S17>/MATLAB Function' incorporates:
  //   SignalConversion generated from: '<S17>/In1'
  //   SignalConversion generated from: '<S17>/angle'

  if (motion_controller_circle_test_B.GetParameter1 == 1.0) {
    deltaFR = motion_controller_circle_test_P.L / (tan(rtu_angle) + 1.0E-9);
    if (deltaFR >= 0.0) {
      // SignalConversion generated from: '<S17>/angle_cmd'
      rty_angle_cmd[0] = rt_atan2d_snf(motion_controller_circle_test_P.L,
        deltaFR - motion_controller_circle_test_P.Tw / 2.0);
      deltaFR = rt_atan2d_snf(motion_controller_circle_test_P.L,
        motion_controller_circle_test_P.Tw / 2.0 + deltaFR);
    } else {
      // SignalConversion generated from: '<S17>/angle_cmd'
      rty_angle_cmd[0] = rt_atan2d_snf(motion_controller_circle_test_P.L,
        deltaFR - motion_controller_circle_test_P.Tw / 2.0) - 3.1415926535897931;
      deltaFR = rt_atan2d_snf(motion_controller_circle_test_P.L,
        motion_controller_circle_test_P.Tw / 2.0 + deltaFR) - 3.1415926535897931;
    }
  } else {
    // SignalConversion generated from: '<S17>/angle_cmd' incorporates:
    //   SignalConversion generated from: '<S17>/angle'

    rty_angle_cmd[0] = rtu_angle;
    deltaFR = rtu_angle;
  }

  // SignalConversion generated from: '<S17>/angle_cmd' incorporates:
  //   MATLAB Function: '<S17>/MATLAB Function'

  rty_angle_cmd[1] = deltaFR;
  rty_angle_cmd[2] = 0.0;
  rty_angle_cmd[3] = 0.0;
}

// System initialize for Simulink Function: '<S3>/get_effort'
void motion_controller_circle_test::motion_controll_get_effort_Init()
{
  static const char_T prmName[10] = "effortMax";

  // Start for MATLABSystem: '<S18>/Get Parameter'
  motion_controller_circle_tes_DW.obj.matlabCodegenIsDeleted = false;
  motion_controller_circle_tes_DW.obj.isInitialized = 1;
  ParamGet_motion_controller_circle_test_202.initParam(&prmName[0]);
  ParamGet_motion_controller_circle_test_202.setInitialValue(0.3);
  motion_controller_circle_tes_DW.obj.isSetupComplete = true;
}

// Output and update for Simulink Function: '<S3>/get_effort'
void motion_controller_circle_test::motion_controller_ci_get_effort()
{
}

// Termination for Simulink Function: '<S3>/get_effort'
void motion_controller_circle_test::motion_controll_get_effort_Term()
{
  // Terminate for MATLABSystem: '<S18>/Get Parameter'
  if (!motion_controller_circle_tes_DW.obj.matlabCodegenIsDeleted) {
    motion_controller_circle_tes_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S18>/Get Parameter'
}

// Output and update for Simulink Function: '<S3>/get_spd'
void motion_controller_circle_test::motion_controller_circl_get_spd(real_T
  rtu_angle, real_T rtu_longdrive, real_T rty_spd_cmd[4]) const
{
  real_T b_x;
  real_T vFR;
  real_T vRL;
  real_T vRR;
  real_T vRR_tmp;

  // MATLAB Function: '<S19>/MATLAB Function' incorporates:
  //   SignalConversion generated from: '<S19>/ackermann_enable'
  //   SignalConversion generated from: '<S19>/angle'
  //   SignalConversion generated from: '<S19>/longdrive'

  if (motion_controller_circle_test_B.GetParameter1 == 1.0) {
    vRL = motion_controller_circle_test_P.L / (tan(rtu_angle) + 1.0E-9);
    if (vRL >= 0.0) {
      b_x = rt_atan2d_snf(motion_controller_circle_test_P.L, vRL -
                          motion_controller_circle_test_P.Tw / 2.0);
      vFR = rt_atan2d_snf(motion_controller_circle_test_P.L,
                          motion_controller_circle_test_P.Tw / 2.0 + vRL);
    } else {
      b_x = rt_atan2d_snf(motion_controller_circle_test_P.L, vRL -
                          motion_controller_circle_test_P.Tw / 2.0) -
        3.1415926535897931;
      vFR = rt_atan2d_snf(motion_controller_circle_test_P.L,
                          motion_controller_circle_test_P.Tw / 2.0 + vRL) -
        3.1415926535897931;
    }

    vRR_tmp = cos(asin(motion_controller_circle_test_P.b / vRL));
    vRR = (motion_controller_circle_test_P.Tw / 2.0 + vRL) / vRL * rtu_longdrive
      * vRR_tmp;
    vRL = (vRL - motion_controller_circle_test_P.Tw / 2.0) / vRL * rtu_longdrive
      * vRR_tmp;
    vFR = vRR / cos(vFR);

    // SignalConversion generated from: '<S19>/spd_cmd' incorporates:
    //   SignalConversion generated from: '<S19>/angle'
    //   SignalConversion generated from: '<S19>/longdrive'

    rty_spd_cmd[0] = vRL / cos(b_x);
  } else {
    // SignalConversion generated from: '<S19>/spd_cmd' incorporates:
    //   SignalConversion generated from: '<S19>/longdrive'

    rty_spd_cmd[0] = rtu_longdrive;
    vFR = rtu_longdrive;
    vRL = rtu_longdrive;
    vRR = rtu_longdrive;
  }

  // SignalConversion generated from: '<S19>/spd_cmd' incorporates:
  //   MATLAB Function: '<S19>/MATLAB Function'

  rty_spd_cmd[1] = -vFR;
  rty_spd_cmd[2] = -vRR;
  rty_spd_cmd[3] = vRL;
}

void motion_controller_circle_test::motion_control_SystemCore_setup
  (ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[11];
  static const char_T b_zeroDelimTopic_0[11] = "/motor_cmd";

  // Start for MATLABSystem: '<S12>/SinkBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S12>/SinkBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)5.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 11; i++) {
    // Start for MATLABSystem: '<S12>/SinkBlock'
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

  // Start for MATLABSystem: '<S13>/SinkBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S13>/SinkBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)10.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 11; i++) {
    // Start for MATLABSystem: '<S13>/SinkBlock'
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

  // Start for MATLABSystem: '<S23>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S23>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  for (int32_T i = 0; i < 6; i++) {
    // Start for MATLABSystem: '<S23>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_motion_controller_circle_test_1.createSubscriber(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

// Model step function
void motion_controller_circle_test::step()
{
  boolean_T b_varargout_1;
  boolean_T rtb_LogicalOperator;

  // MATLABSystem: '<S1>/Get Parameter1'
  ParamGet_motion_controller_circle_test_400.getParameter
    (&motion_controller_circle_test_B.b_value);

  // MATLABSystem: '<S23>/SourceBlock'
  b_varargout_1 = Sub_motion_controller_circle_test_1.getLatestMessage
    (&motion_controller_circle_test_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S23>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S25>/Enable'

  // Start for MATLABSystem: '<S23>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S25>/In1'
    motion_controller_circle_test_B.In1 =
      motion_controller_circle_test_B.b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S23>/Enabled Subsystem'

  // Gain: '<S1>/Gain2' incorporates:
  //   Constant: '<S1>/Constant'
  //   Gain: '<S1>/Gain'
  //   SignalConversion generated from: '<S5>/Bus Selector'
  //   Sum: '<S1>/Add'

  motion_controller_circle_test_B.Gain2 = (static_cast<real_T>
    (motion_controller_circle_test_B.In1.mapped_channels[0]) -
    motion_controller_circle_test_P.Constant_Value_iw) *
    motion_controller_circle_test_P.Gain_Gain *
    motion_controller_circle_test_P.Gain2_Gain;

  // Chart: '<S1>/Chart' incorporates:
  //   MATLABSystem: '<S1>/Get Parameter1'

  if (motion_controller_circle_tes_DW.is_active_c8_motion_controller_ == 0U) {
    motion_controller_circle_tes_DW.is_active_c8_motion_controller_ = 1U;
    motion_controller_circle_tes_DW.is_steer = motion_controller_circle_IN_ini;
    motion_controller_circle_test_B.angle_out = 0.0;
  } else {
    switch (motion_controller_circle_tes_DW.is_steer) {
     case motion_controller_circle_IN_ini:
      if (fabs(motion_controller_circle_test_B.Gain2) > 0.05) {
        motion_controller_circle_tes_DW.is_steer =
          motion_controller__IN_set_angle;
        motion_controller_circle_tes_DW.counter_d = 50.0;
        motion_controller_circle_test_B.angle_out =
          motion_controller_circle_test_B.Gain2;
      }
      break;

     case motion_controller_ci_IN_running:
      if (motion_controller_circle_test_B.Gain2 >= 0.4) {
        motion_controller_circle_tes_DW.is_steer =
          motion_controller_ci_IN_waiting;
        motion_controller_circle_test_B.angle_out =
          motion_controller_circle_tes_DW.ini;
      } else if (fabs(motion_controller_circle_test_B.angle_out) > 1.0) {
        motion_controller_circle_tes_DW.direction =
          -motion_controller_circle_tes_DW.direction;
        if (!rtIsNaN(motion_controller_circle_test_B.angle_out)) {
          if (motion_controller_circle_test_B.angle_out < 0.0) {
            motion_controller_circle_test_B.angle_out = -1.0;
          } else {
            motion_controller_circle_test_B.angle_out =
              (motion_controller_circle_test_B.angle_out > 0.0);
          }
        }
      } else if (fabs(motion_controller_circle_test_B.angle_out) < fabs
                 (motion_controller_circle_tes_DW.ini)) {
        motion_controller_circle_tes_DW.direction =
          -motion_controller_circle_tes_DW.direction;
        motion_controller_circle_test_B.angle_out =
          motion_controller_circle_tes_DW.ini;
      } else if (motion_controller_circle_tes_DW.ini >= 0.0) {
        motion_controller_circle_test_B.angle_out +=
          motion_controller_circle_tes_DW.direction *
          motion_controller_circle_test_B.b_value / 180.0 * 3.1415926535897931 /
          100.0;
      } else {
        motion_controller_circle_test_B.angle_out -=
          motion_controller_circle_tes_DW.direction *
          motion_controller_circle_test_B.b_value / 180.0 * 3.1415926535897931 /
          100.0;
      }
      break;

     case motion_controller__IN_set_angle:
      if (motion_controller_circle_test_B.Gain2 == 0.0) {
        motion_controller_circle_tes_DW.ini =
          motion_controller_circle_test_B.angle_out;
        motion_controller_circle_tes_DW.is_steer =
          motion_controller_circle_IN_ini;
        motion_controller_circle_test_B.angle_out = 0.0;
      } else if (motion_controller_circle_tes_DW.counter_d <= 1.0) {
        motion_controller_circle_tes_DW.ini =
          motion_controller_circle_test_B.angle_out;
        motion_controller_circle_tes_DW.is_steer =
          motion_controller_ci_IN_waiting;
      } else {
        motion_controller_circle_tes_DW.counter_d--;
        if (fabs(motion_controller_circle_test_B.Gain2 -
                 motion_controller_circle_test_B.angle_out) > 0.02) {
          motion_controller_circle_test_B.angle_out =
            motion_controller_circle_test_B.Gain2;
          motion_controller_circle_tes_DW.counter_d = 50.0;
        }
      }
      break;

     default:
      // case IN_waiting:
      if (motion_controller_circle_test_B.Gain2 <= -0.98) {
        motion_controller_circle_tes_DW.is_steer =
          motion_controller_ci_IN_running;
        motion_controller_circle_tes_DW.direction = 1.0;
      } else if (motion_controller_circle_test_B.Gain2 == 1.0) {
        motion_controller_circle_tes_DW.is_steer =
          motion_controller__IN_set_angle;
        motion_controller_circle_tes_DW.counter_d = 50.0;
        motion_controller_circle_test_B.angle_out = 1.0;
      }
      break;
    }
  }

  // End of Chart: '<S1>/Chart'

  // MATLABSystem: '<S1>/Get Parameter'
  ParamGet_motion_controller_circle_test_399.getParameter
    (&motion_controller_circle_test_B.b_value);

  // Product: '<S1>/Product' incorporates:
  //   MATLABSystem: '<S1>/Get Parameter'

  motion_controller_circle_test_B.Gain2 =
    motion_controller_circle_test_B.angle_out *
    motion_controller_circle_test_B.b_value;

  // MATLABSystem: '<S1>/Get Parameter4'
  ParamGet_motion_controller_circle_test_396.getParameter
    (&motion_controller_circle_test_B.b_value);

  // MATLABSystem: '<S1>/Get Parameter3'
  ParamGet_motion_controller_circle_test_395.getParameter
    (&motion_controller_circle_test_B.b_value_m);

  // Product: '<S1>/Product1' incorporates:
  //   Constant: '<S1>/Constant2'
  //   Gain: '<S1>/Gain1'
  //   MATLABSystem: '<S1>/Get Parameter3'
  //   SignalConversion generated from: '<S5>/Bus Selector'
  //   Sum: '<S1>/Add1'

  motion_controller_circle_test_B.b_value_m *= (static_cast<real_T>
    (motion_controller_circle_test_B.In1.mapped_channels[2]) -
    motion_controller_circle_test_P.Constant2_Value) *
    motion_controller_circle_test_P.Gain1_Gain;

  // Chart: '<S1>/Chart2' incorporates:
  //   MATLABSystem: '<S1>/Get Parameter4'

  if (motion_controller_circle_tes_DW.is_active_c1_motion_controller_ == 0U) {
    motion_controller_circle_tes_DW.is_active_c1_motion_controller_ = 1U;
    motion_controller_circle_test_B.out = 0.0;
  } else {
    motion_controller_circle_test_B.direction =
      motion_controller_circle_test_B.b_value_m -
      motion_controller_circle_test_B.out;
    if (fabs(motion_controller_circle_test_B.direction) < 0.001) {
      motion_controller_circle_test_B.out =
        motion_controller_circle_test_B.b_value_m;
    } else if (motion_controller_circle_test_B.b_value == 0.0) {
      motion_controller_circle_test_B.out =
        motion_controller_circle_test_B.b_value_m;
    } else {
      if (rtIsNaN(motion_controller_circle_test_B.direction)) {
        motion_controller_circle_test_B.b_value_m = (rtNaN);
      } else if (motion_controller_circle_test_B.direction < 0.0) {
        motion_controller_circle_test_B.b_value_m = -1.0;
      } else {
        motion_controller_circle_test_B.b_value_m =
          (motion_controller_circle_test_B.direction > 0.0);
      }

      motion_controller_circle_test_B.out +=
        motion_controller_circle_test_B.b_value_m *
        motion_controller_circle_test_B.b_value * 0.01;
    }
  }

  // End of Chart: '<S1>/Chart2'

  // Logic: '<Root>/LogicalOperator'
  rtb_LogicalOperator = (motion_controller_circle_test_B.In1.failsafe ||
    motion_controller_circle_test_B.In1.frame_lost);

  // Outputs for Atomic SubSystem: '<Root>/controller'
  // MATLABSystem: '<S3>/Get Parameter1'
  ParamGet_motion_controller_circle_test_363.getParameter
    (&motion_controller_circle_test_B.GetParameter1);

  // Chart: '<S3>/Chart1' incorporates:
  //   MATLABSystem: '<S23>/SourceBlock'
  //   SignalConversion generated from: '<S5>/Bus Selector'
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
        motion_controller_circle_test_B.b_value = (rtNaN);
      } else if (rtIsInf(motion_controller_circle_tes_DW.counter)) {
        motion_controller_circle_test_B.b_value = (rtNaN);
      } else if (motion_controller_circle_tes_DW.counter == 0.0) {
        motion_controller_circle_test_B.b_value = 0.0;
      } else {
        motion_controller_circle_test_B.b_value = fmod
          (motion_controller_circle_tes_DW.counter, 20.0);
        if (motion_controller_circle_test_B.b_value == 0.0) {
          motion_controller_circle_test_B.b_value = 0.0;
        } else if (motion_controller_circle_tes_DW.counter < 0.0) {
          motion_controller_circle_test_B.b_value += 20.0;
        }
      }

      if (motion_controller_circle_test_B.b_value == 0.0) {
        motion_controller_circle_tes_DW.check =
          motion_controller_circle_tes_DW.sum;
        motion_controller_circle_tes_DW.sum = 0.0;
      }
    }

    if (motion_controller_circle_tes_DW.is_cmd ==
        motion_controller_circle_IN_Ini) {
      motion_controller_circle_test_B.effort_cmd[0] = 0.0;
      motion_controller_circle_test_B.effort_cmd[1] = 0.0;
      motion_controller_circle_test_B.effort_cmd[2] = 0.0;
      motion_controller_circle_test_B.effort_cmd[3] = 0.0;
      if (motion_controller_circle_tes_DW.ready) {
        motion_controller_circle_tes_DW.is_cmd = motion_controlle_IN_effort_mode;
        motion_controller_circle_test_B.effort_cmd[0] = 0.0;
        motion_controller_circle_test_B.effort_cmd[1] = 0.0;
        motion_controller_circle_test_B.effort_cmd[2] = 0.0;
        motion_controller_circle_test_B.effort_cmd[3] = 0.0;
      }
    } else {
      // case IN_effort_mode:
      motion_controller_circle_test_B.effort_cmd[0] = 0.0;
      motion_controller_circle_test_B.effort_cmd[1] = 0.0;
      motion_controller_circle_test_B.effort_cmd[2] = 0.0;
      motion_controller_circle_test_B.effort_cmd[3] = 0.0;
      if (!motion_controller_circle_tes_DW.ready) {
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
        motion_controller_cir_get_angle(motion_controller_circle_test_B.Gain2,
          motion_controller_circle_test_B.angle_cmd);
        motion_controller_circl_get_spd(motion_controller_circle_test_B.Gain2,
          motion_controller_circle_test_B.out,
          motion_controller_circle_test_B.spd_cmd);
        motion_controller_circle_test_B.mode = 1;
        if (motion_controller_circle_test_B.out < -0.2) {
          motion_controller_circle_test_B.mode = 0;
        }
      }
    }
  }

  // End of Chart: '<S3>/Chart1'
  // End of Outputs for SubSystem: '<Root>/controller'

  // Outputs for Enabled SubSystem: '<Root>/cmd_pub' incorporates:
  //   EnablePort: '<S2>/Enable'

  // RelationalOperator: '<S4>/Compare' incorporates:
  //   Constant: '<S4>/Constant'
  //   SignalConversion generated from: '<S5>/Bus Selector'

  if (motion_controller_circle_test_B.In1.mapped_channels[5] ==
      motion_controller_circle_test_P.ctc_const) {
    motion_controller_c_CurrentTime
      (&motion_controller_circle_test_B.CurrentTime1);

    // BusAssignment: '<S2>/Bus Assignment1' incorporates:
    //   Constant: '<S9>/Constant'

    motion_controller_circle_test_B.BusAssignment1 =
      motion_controller_circle_test_P.Constant_Value;

    // Saturate: '<Root>/Saturation'
    motion_controller_circle_test_B.b_value =
      motion_controller_circle_test_B.effort_cmd[0];
    if (motion_controller_circle_test_B.b_value >
        motion_controller_circle_test_P.Saturation_UpperSat_k) {
      motion_controller_circle_test_B.b_value =
        motion_controller_circle_test_P.Saturation_UpperSat_k;
    } else if (motion_controller_circle_test_B.b_value <
               motion_controller_circle_test_P.Saturation_LowerSat_n) {
      motion_controller_circle_test_B.b_value =
        motion_controller_circle_test_P.Saturation_LowerSat_n;
    }

    // Saturate: '<S2>/Saturation2' incorporates:
    //   Saturate: '<Root>/Saturation'

    if (motion_controller_circle_test_B.b_value >
        motion_controller_circle_test_P.Saturation2_UpperSat) {
      motion_controller_circle_test_B.b_value =
        motion_controller_circle_test_P.Saturation2_UpperSat;
    } else if (motion_controller_circle_test_B.b_value <
               motion_controller_circle_test_P.Saturation2_LowerSat) {
      motion_controller_circle_test_B.b_value =
        motion_controller_circle_test_P.Saturation2_LowerSat;
    }

    motion_controller_circle_test_B.effort_cmd[0] =
      motion_controller_circle_test_B.b_value;

    // Saturate: '<S2>/Saturation1'
    motion_controller_circle_test_B.Gain2 =
      motion_controller_circle_test_B.spd_cmd[0];

    // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
    //   ForEach: '<S11>/For Each'

    // ForEachSliceAssignment generated from: '<S11>/actuaor_command' incorporates:
    //   BusAssignment: '<S11>/Bus Assignment1'
    //   Constant: '<S15>/Constant'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0] =
      motion_controller_circle_test_P.CoreSubsys_p.Constant_Value;

    // BusAssignment: '<S11>/Bus Assignment1' incorporates:
    //   ForEachSliceAssignment generated from: '<S11>/actuaor_command'
    //   ForEachSliceSelector generated from: '<S11>/effort'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0].effort =
      motion_controller_circle_test_B.b_value;

    // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'

    // Saturate: '<S2>/Saturation1'
    if (motion_controller_circle_test_B.Gain2 >
        motion_controller_circle_test_P.Saturation1_UpperSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S11>/For Each'

      // BusAssignment: '<S11>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S11>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0].velocity =
        motion_controller_circle_test_P.Saturation1_UpperSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    } else if (motion_controller_circle_test_B.Gain2 <
               motion_controller_circle_test_P.Saturation1_LowerSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S11>/For Each'

      // BusAssignment: '<S11>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S11>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0].velocity =
        motion_controller_circle_test_P.Saturation1_LowerSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S11>/For Each'

      // BusAssignment: '<S11>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S11>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0].velocity =
        motion_controller_circle_test_B.Gain2;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    }

    // Saturate: '<Root>/Saturation'
    motion_controller_circle_test_B.b_value =
      motion_controller_circle_test_B.effort_cmd[1];
    if (motion_controller_circle_test_B.b_value >
        motion_controller_circle_test_P.Saturation_UpperSat_k) {
      motion_controller_circle_test_B.b_value =
        motion_controller_circle_test_P.Saturation_UpperSat_k;
    } else if (motion_controller_circle_test_B.b_value <
               motion_controller_circle_test_P.Saturation_LowerSat_n) {
      motion_controller_circle_test_B.b_value =
        motion_controller_circle_test_P.Saturation_LowerSat_n;
    }

    // Saturate: '<S2>/Saturation2' incorporates:
    //   Saturate: '<Root>/Saturation'

    if (motion_controller_circle_test_B.b_value >
        motion_controller_circle_test_P.Saturation2_UpperSat) {
      motion_controller_circle_test_B.b_value =
        motion_controller_circle_test_P.Saturation2_UpperSat;
    } else if (motion_controller_circle_test_B.b_value <
               motion_controller_circle_test_P.Saturation2_LowerSat) {
      motion_controller_circle_test_B.b_value =
        motion_controller_circle_test_P.Saturation2_LowerSat;
    }

    motion_controller_circle_test_B.effort_cmd[1] =
      motion_controller_circle_test_B.b_value;

    // Saturate: '<S2>/Saturation1'
    motion_controller_circle_test_B.Gain2 =
      motion_controller_circle_test_B.spd_cmd[1];

    // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
    //   ForEach: '<S11>/For Each'

    // ForEachSliceAssignment generated from: '<S11>/actuaor_command' incorporates:
    //   BusAssignment: '<S11>/Bus Assignment1'
    //   Constant: '<S15>/Constant'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1] =
      motion_controller_circle_test_P.CoreSubsys_p.Constant_Value;

    // BusAssignment: '<S11>/Bus Assignment1' incorporates:
    //   ForEachSliceAssignment generated from: '<S11>/actuaor_command'
    //   ForEachSliceSelector generated from: '<S11>/effort'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1].effort =
      motion_controller_circle_test_B.b_value;

    // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'

    // Saturate: '<S2>/Saturation1'
    if (motion_controller_circle_test_B.Gain2 >
        motion_controller_circle_test_P.Saturation1_UpperSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S11>/For Each'

      // BusAssignment: '<S11>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S11>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1].velocity =
        motion_controller_circle_test_P.Saturation1_UpperSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    } else if (motion_controller_circle_test_B.Gain2 <
               motion_controller_circle_test_P.Saturation1_LowerSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S11>/For Each'

      // BusAssignment: '<S11>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S11>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1].velocity =
        motion_controller_circle_test_P.Saturation1_LowerSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S11>/For Each'

      // BusAssignment: '<S11>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S11>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1].velocity =
        motion_controller_circle_test_B.Gain2;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    }

    // Saturate: '<Root>/Saturation'
    motion_controller_circle_test_B.b_value =
      motion_controller_circle_test_B.effort_cmd[2];
    if (motion_controller_circle_test_B.b_value >
        motion_controller_circle_test_P.Saturation_UpperSat_k) {
      motion_controller_circle_test_B.b_value =
        motion_controller_circle_test_P.Saturation_UpperSat_k;
    } else if (motion_controller_circle_test_B.b_value <
               motion_controller_circle_test_P.Saturation_LowerSat_n) {
      motion_controller_circle_test_B.b_value =
        motion_controller_circle_test_P.Saturation_LowerSat_n;
    }

    // Saturate: '<S2>/Saturation2' incorporates:
    //   Saturate: '<Root>/Saturation'

    if (motion_controller_circle_test_B.b_value >
        motion_controller_circle_test_P.Saturation2_UpperSat) {
      motion_controller_circle_test_B.b_value =
        motion_controller_circle_test_P.Saturation2_UpperSat;
    } else if (motion_controller_circle_test_B.b_value <
               motion_controller_circle_test_P.Saturation2_LowerSat) {
      motion_controller_circle_test_B.b_value =
        motion_controller_circle_test_P.Saturation2_LowerSat;
    }

    motion_controller_circle_test_B.effort_cmd[2] =
      motion_controller_circle_test_B.b_value;

    // Saturate: '<S2>/Saturation1'
    motion_controller_circle_test_B.Gain2 =
      motion_controller_circle_test_B.spd_cmd[2];

    // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
    //   ForEach: '<S11>/For Each'

    // ForEachSliceAssignment generated from: '<S11>/actuaor_command' incorporates:
    //   BusAssignment: '<S11>/Bus Assignment1'
    //   Constant: '<S15>/Constant'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2] =
      motion_controller_circle_test_P.CoreSubsys_p.Constant_Value;

    // BusAssignment: '<S11>/Bus Assignment1' incorporates:
    //   ForEachSliceAssignment generated from: '<S11>/actuaor_command'
    //   ForEachSliceSelector generated from: '<S11>/effort'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2].effort =
      motion_controller_circle_test_B.b_value;

    // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'

    // Saturate: '<S2>/Saturation1'
    if (motion_controller_circle_test_B.Gain2 >
        motion_controller_circle_test_P.Saturation1_UpperSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S11>/For Each'

      // BusAssignment: '<S11>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S11>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2].velocity =
        motion_controller_circle_test_P.Saturation1_UpperSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    } else if (motion_controller_circle_test_B.Gain2 <
               motion_controller_circle_test_P.Saturation1_LowerSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S11>/For Each'

      // BusAssignment: '<S11>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S11>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2].velocity =
        motion_controller_circle_test_P.Saturation1_LowerSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S11>/For Each'

      // BusAssignment: '<S11>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S11>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2].velocity =
        motion_controller_circle_test_B.Gain2;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    }

    // Saturate: '<Root>/Saturation'
    motion_controller_circle_test_B.b_value =
      motion_controller_circle_test_B.effort_cmd[3];
    if (motion_controller_circle_test_B.b_value >
        motion_controller_circle_test_P.Saturation_UpperSat_k) {
      motion_controller_circle_test_B.b_value =
        motion_controller_circle_test_P.Saturation_UpperSat_k;
    } else if (motion_controller_circle_test_B.b_value <
               motion_controller_circle_test_P.Saturation_LowerSat_n) {
      motion_controller_circle_test_B.b_value =
        motion_controller_circle_test_P.Saturation_LowerSat_n;
    }

    // Saturate: '<S2>/Saturation2' incorporates:
    //   Saturate: '<Root>/Saturation'

    if (motion_controller_circle_test_B.b_value >
        motion_controller_circle_test_P.Saturation2_UpperSat) {
      motion_controller_circle_test_B.b_value =
        motion_controller_circle_test_P.Saturation2_UpperSat;
    } else if (motion_controller_circle_test_B.b_value <
               motion_controller_circle_test_P.Saturation2_LowerSat) {
      motion_controller_circle_test_B.b_value =
        motion_controller_circle_test_P.Saturation2_LowerSat;
    }

    motion_controller_circle_test_B.effort_cmd[3] =
      motion_controller_circle_test_B.b_value;

    // Saturate: '<S2>/Saturation1'
    motion_controller_circle_test_B.Gain2 =
      motion_controller_circle_test_B.spd_cmd[3];

    // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
    //   ForEach: '<S11>/For Each'

    // ForEachSliceAssignment generated from: '<S11>/actuaor_command' incorporates:
    //   BusAssignment: '<S11>/Bus Assignment1'
    //   Constant: '<S15>/Constant'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3] =
      motion_controller_circle_test_P.CoreSubsys_p.Constant_Value;

    // BusAssignment: '<S11>/Bus Assignment1' incorporates:
    //   ForEachSliceAssignment generated from: '<S11>/actuaor_command'
    //   ForEachSliceSelector generated from: '<S11>/effort'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3].effort =
      motion_controller_circle_test_B.b_value;

    // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'

    // Saturate: '<S2>/Saturation1'
    if (motion_controller_circle_test_B.Gain2 >
        motion_controller_circle_test_P.Saturation1_UpperSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S11>/For Each'

      // BusAssignment: '<S11>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S11>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3].velocity =
        motion_controller_circle_test_P.Saturation1_UpperSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    } else if (motion_controller_circle_test_B.Gain2 <
               motion_controller_circle_test_P.Saturation1_LowerSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S11>/For Each'

      // BusAssignment: '<S11>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S11>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3].velocity =
        motion_controller_circle_test_P.Saturation1_LowerSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem1' incorporates:
      //   ForEach: '<S11>/For Each'

      // BusAssignment: '<S11>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S11>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3].velocity =
        motion_controller_circle_test_B.Gain2;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem1'
    }

    // BusAssignment: '<S2>/Bus Assignment1' incorporates:
    //   DataTypeConversion: '<S2>/Data Type Conversion'

    motion_controller_circle_test_B.BusAssignment1.header.stamp =
      motion_controller_circle_test_B.CurrentTime1.CurrentTime;
    motion_controller_circle_test_B.BusAssignment1.drive_mode =
      motion_controller_circle_test_B.mode;
    memcpy(&motion_controller_circle_test_B.BusAssignment1.actuator_command[0],
           &motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0],
           sizeof(SL_Bus_custom_interfaces_Actuator) << 2U);

    // MATLABSystem: '<S12>/SinkBlock'
    Pub_motion_controller_circle_test_4.publish
      (&motion_controller_circle_test_B.BusAssignment1);
    motion_controller_c_CurrentTime(&motion_controller_circle_test_B.CurrentTime);

    // BusAssignment: '<S2>/Bus Assignment2' incorporates:
    //   Constant: '<S8>/Constant'

    motion_controller_circle_test_B.BusAssignment1 =
      motion_controller_circle_test_P.Constant_Value_i;

    // Saturate: '<S2>/Saturation'
    motion_controller_circle_test_B.Gain2 =
      motion_controller_circle_test_B.angle_cmd[0];

    // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
    //   ForEach: '<S10>/For Each'

    // ForEachSliceAssignment generated from: '<S10>/actuaor_command' incorporates:
    //   BusAssignment: '<S10>/Bus Assignment1'
    //   Constant: '<S14>/Constant'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0] =
      motion_controller_circle_test_P.CoreSubsys.Constant_Value;

    // End of Outputs for SubSystem: '<S2>/For Each Subsystem'

    // Saturate: '<S2>/Saturation'
    if (motion_controller_circle_test_B.Gain2 >
        motion_controller_circle_test_P.Saturation_UpperSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0].position =
        motion_controller_circle_test_P.Saturation_UpperSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem'
    } else if (motion_controller_circle_test_B.Gain2 <
               motion_controller_circle_test_P.Saturation_LowerSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0].position =
        motion_controller_circle_test_P.Saturation_LowerSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem'
    } else {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0].position =
        motion_controller_circle_test_B.Gain2;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem'
    }

    motion_controller_circle_test_B.Gain2 =
      motion_controller_circle_test_B.angle_cmd[1];

    // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
    //   ForEach: '<S10>/For Each'

    // ForEachSliceAssignment generated from: '<S10>/actuaor_command' incorporates:
    //   BusAssignment: '<S10>/Bus Assignment1'
    //   Constant: '<S14>/Constant'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1] =
      motion_controller_circle_test_P.CoreSubsys.Constant_Value;

    // End of Outputs for SubSystem: '<S2>/For Each Subsystem'

    // Saturate: '<S2>/Saturation'
    if (motion_controller_circle_test_B.Gain2 >
        motion_controller_circle_test_P.Saturation_UpperSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1].position =
        motion_controller_circle_test_P.Saturation_UpperSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem'
    } else if (motion_controller_circle_test_B.Gain2 <
               motion_controller_circle_test_P.Saturation_LowerSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1].position =
        motion_controller_circle_test_P.Saturation_LowerSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem'
    } else {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1].position =
        motion_controller_circle_test_B.Gain2;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem'
    }

    motion_controller_circle_test_B.Gain2 =
      motion_controller_circle_test_B.angle_cmd[2];

    // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
    //   ForEach: '<S10>/For Each'

    // ForEachSliceAssignment generated from: '<S10>/actuaor_command' incorporates:
    //   BusAssignment: '<S10>/Bus Assignment1'
    //   Constant: '<S14>/Constant'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2] =
      motion_controller_circle_test_P.CoreSubsys.Constant_Value;

    // End of Outputs for SubSystem: '<S2>/For Each Subsystem'

    // Saturate: '<S2>/Saturation'
    if (motion_controller_circle_test_B.Gain2 >
        motion_controller_circle_test_P.Saturation_UpperSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2].position =
        motion_controller_circle_test_P.Saturation_UpperSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem'
    } else if (motion_controller_circle_test_B.Gain2 <
               motion_controller_circle_test_P.Saturation_LowerSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2].position =
        motion_controller_circle_test_P.Saturation_LowerSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem'
    } else {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2].position =
        motion_controller_circle_test_B.Gain2;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem'
    }

    motion_controller_circle_test_B.Gain2 =
      motion_controller_circle_test_B.angle_cmd[3];

    // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
    //   ForEach: '<S10>/For Each'

    // ForEachSliceAssignment generated from: '<S10>/actuaor_command' incorporates:
    //   BusAssignment: '<S10>/Bus Assignment1'
    //   Constant: '<S14>/Constant'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3] =
      motion_controller_circle_test_P.CoreSubsys.Constant_Value;

    // End of Outputs for SubSystem: '<S2>/For Each Subsystem'

    // Saturate: '<S2>/Saturation'
    if (motion_controller_circle_test_B.Gain2 >
        motion_controller_circle_test_P.Saturation_UpperSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3].position =
        motion_controller_circle_test_P.Saturation_UpperSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem'
    } else if (motion_controller_circle_test_B.Gain2 <
               motion_controller_circle_test_P.Saturation_LowerSat) {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3].position =
        motion_controller_circle_test_P.Saturation_LowerSat;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem'
    } else {
      // Outputs for Iterator SubSystem: '<S2>/For Each Subsystem' incorporates:
      //   ForEach: '<S10>/For Each'

      // BusAssignment: '<S10>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S10>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3].position =
        motion_controller_circle_test_B.Gain2;

      // End of Outputs for SubSystem: '<S2>/For Each Subsystem'
    }

    // BusAssignment: '<S2>/Bus Assignment2'
    motion_controller_circle_test_B.BusAssignment1.header.stamp =
      motion_controller_circle_test_B.CurrentTime.CurrentTime;
    memcpy(&motion_controller_circle_test_B.BusAssignment1.actuator_command[0],
           &motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0],
           sizeof(SL_Bus_custom_interfaces_Actuator) << 2U);

    // MATLABSystem: '<S13>/SinkBlock'
    Pub_motion_controller_circle_test_148.publish
      (&motion_controller_circle_test_B.BusAssignment1);
  }

  // End of RelationalOperator: '<S4>/Compare'
  // End of Outputs for SubSystem: '<Root>/cmd_pub'
}

// Model initialize function
void motion_controller_circle_test::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    static const char_T prmName[10] = "ackermann";
    static const char_T prmName_0[15] = "steer_rate_dps";
    static const char_T prmName_1[9] = "angleMax";
    static const char_T prmName_2[13] = "acc_rate_mps";
    static const char_T prmName_3[7] = "spdMax";

    // SystemInitialize for Enabled SubSystem: '<S23>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S25>/In1' incorporates:
    //   Outport: '<S25>/Out1'

    motion_controller_circle_test_B.In1 =
      motion_controller_circle_test_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S23>/Enabled Subsystem'

    // SystemInitialize for Atomic SubSystem: '<Root>/controller'
    // SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S3>/get_effort' incorporates:
    //   SubSystem: '<S3>/get_effort'

    motion_controll_get_effort_Init();

    // End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S3>/get_effort' 

    // Start for MATLABSystem: '<S3>/Get Parameter1'
    motion_controller_circle_tes_DW.obj_k.matlabCodegenIsDeleted = false;
    motion_controller_circle_tes_DW.obj_k.isInitialized = 1;
    ParamGet_motion_controller_circle_test_363.initParam(&prmName[0]);
    ParamGet_motion_controller_circle_test_363.setInitialValue(1.0);
    motion_controller_circle_tes_DW.obj_k.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<Root>/controller'

    // SystemInitialize for Enabled SubSystem: '<Root>/cmd_pub'
    motion_control_CurrentTime_Init
      (&motion_controller_circle_tes_DW.CurrentTime1);

    // Start for MATLABSystem: '<S12>/SinkBlock'
    motion_control_SystemCore_setup(&motion_controller_circle_tes_DW.obj_bq);
    motion_control_CurrentTime_Init(&motion_controller_circle_tes_DW.CurrentTime);

    // Start for MATLABSystem: '<S13>/SinkBlock'
    motion_contr_SystemCore_setup_d(&motion_controller_circle_tes_DW.obj_c);

    // End of SystemInitialize for SubSystem: '<Root>/cmd_pub'

    // Start for MATLABSystem: '<S1>/Get Parameter1'
    motion_controller_circle_tes_DW.obj_h.matlabCodegenIsDeleted = false;
    motion_controller_circle_tes_DW.obj_h.isInitialized = 1;
    ParamGet_motion_controller_circle_test_400.initParam(&prmName_0[0]);
    ParamGet_motion_controller_circle_test_400.setInitialValue(0.0);
    motion_controller_circle_tes_DW.obj_h.isSetupComplete = true;

    // Start for MATLABSystem: '<S23>/SourceBlock'
    motion_cont_SystemCore_setup_de(&motion_controller_circle_tes_DW.obj_n);

    // Start for MATLABSystem: '<S1>/Get Parameter'
    motion_controller_circle_tes_DW.obj_e.matlabCodegenIsDeleted = false;
    motion_controller_circle_tes_DW.obj_e.isInitialized = 1;
    ParamGet_motion_controller_circle_test_399.initParam(&prmName_1[0]);
    ParamGet_motion_controller_circle_test_399.setInitialValue(0.6);
    motion_controller_circle_tes_DW.obj_e.isSetupComplete = true;

    // Start for MATLABSystem: '<S1>/Get Parameter4'
    motion_controller_circle_tes_DW.obj_b.matlabCodegenIsDeleted = false;
    motion_controller_circle_tes_DW.obj_b.isInitialized = 1;
    ParamGet_motion_controller_circle_test_396.initParam(&prmName_2[0]);
    ParamGet_motion_controller_circle_test_396.setInitialValue(0.0);
    motion_controller_circle_tes_DW.obj_b.isSetupComplete = true;

    // Start for MATLABSystem: '<S1>/Get Parameter3'
    motion_controller_circle_tes_DW.obj_o.matlabCodegenIsDeleted = false;
    motion_controller_circle_tes_DW.obj_o.isInitialized = 1;
    ParamGet_motion_controller_circle_test_395.initParam(&prmName_3[0]);
    ParamGet_motion_controller_circle_test_395.setInitialValue(1.0);
    motion_controller_circle_tes_DW.obj_o.isSetupComplete = true;
  }
}

// Model terminate function
void motion_controller_circle_test::terminate()
{
  // Terminate for MATLABSystem: '<S1>/Get Parameter1'
  if (!motion_controller_circle_tes_DW.obj_h.matlabCodegenIsDeleted) {
    motion_controller_circle_tes_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1>/Get Parameter1'

  // Terminate for MATLABSystem: '<S23>/SourceBlock'
  if (!motion_controller_circle_tes_DW.obj_n.matlabCodegenIsDeleted) {
    motion_controller_circle_tes_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S23>/SourceBlock'

  // Terminate for MATLABSystem: '<S1>/Get Parameter'
  if (!motion_controller_circle_tes_DW.obj_e.matlabCodegenIsDeleted) {
    motion_controller_circle_tes_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1>/Get Parameter'

  // Terminate for MATLABSystem: '<S1>/Get Parameter4'
  if (!motion_controller_circle_tes_DW.obj_b.matlabCodegenIsDeleted) {
    motion_controller_circle_tes_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1>/Get Parameter4'

  // Terminate for MATLABSystem: '<S1>/Get Parameter3'
  if (!motion_controller_circle_tes_DW.obj_o.matlabCodegenIsDeleted) {
    motion_controller_circle_tes_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1>/Get Parameter3'

  // Terminate for Atomic SubSystem: '<Root>/controller'
  // Terminate for S-Function (sfun_private_function_caller) generated from: '<S3>/get_effort' incorporates:
  //   SubSystem: '<S3>/get_effort'

  motion_controll_get_effort_Term();

  // End of Terminate for S-Function (sfun_private_function_caller) generated from: '<S3>/get_effort' 

  // Terminate for MATLABSystem: '<S3>/Get Parameter1'
  if (!motion_controller_circle_tes_DW.obj_k.matlabCodegenIsDeleted) {
    motion_controller_circle_tes_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/Get Parameter1'
  // End of Terminate for SubSystem: '<Root>/controller'

  // Terminate for Enabled SubSystem: '<Root>/cmd_pub'
  motion_control_CurrentTime_Term(&motion_controller_circle_tes_DW.CurrentTime1);

  // Terminate for MATLABSystem: '<S12>/SinkBlock'
  if (!motion_controller_circle_tes_DW.obj_bq.matlabCodegenIsDeleted) {
    motion_controller_circle_tes_DW.obj_bq.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/SinkBlock'
  motion_control_CurrentTime_Term(&motion_controller_circle_tes_DW.CurrentTime);

  // Terminate for MATLABSystem: '<S13>/SinkBlock'
  if (!motion_controller_circle_tes_DW.obj_c.matlabCodegenIsDeleted) {
    motion_controller_circle_tes_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S13>/SinkBlock'
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
