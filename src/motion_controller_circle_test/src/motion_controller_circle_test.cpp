//
// Sponsored License - for use in support of a program or activity
// sponsored by MathWorks.  Not for government, commercial or other
// non-sponsored organizational use.
//
// File: motion_controller_circle_test.cpp
//
// Code generated for Simulink model 'motion_controller_circle_test'.
//
// Model version                  : 2.180
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Wed Nov 15 20:42:25 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "motion_controller_circle_test.h"
#include "motion_controller_circle_test_types.h"
#include "rtwtypes.h"
#include <string.h>
#include "rmw/qos_profiles.h"
#include <stddef.h>

// Named constants for Chart: '<S2>/Chart'
const uint8_T motion_contro_IN_velocity_mode1 = 2U;
const uint8_T motion_controller_ci_IN_running = 2U;
const uint8_T motion_controller_circ_IN_steer = 3U;
const uint8_T motion_controller_circle_IN_Ini = 1U;

// System initialize for atomic system:
void motion_controller_circle_test::motion_control_CurrentTime_Init
  (DW_CurrentTime_motion_control_T *localDW)
{
  // Start for MATLABSystem: '<S1>/Current Time'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void motion_controller_circle_test::motion_controller_c_CurrentTime
  (B_CurrentTime_motion_controll_T *localB)
{
  // MATLABSystem: '<S1>/Current Time'
  currentROS2TimeBus(&localB->CurrentTime);
}

// Termination for atomic system:
void motion_controller_circle_test::motion_control_CurrentTime_Term
  (DW_CurrentTime_motion_control_T *localDW)
{
  // Terminate for MATLABSystem: '<S1>/Current Time'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S1>/Current Time'
}

void motion_controller_circle_test::motion_control_SystemCore_setup
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

  // Start for MATLABSystem: '<S14>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S14>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  for (int32_T i = 0; i < 6; i++) {
    // Start for MATLABSystem: '<S14>/SourceBlock'
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
  real_T b_value_0;
  uint32_T qY;
  boolean_T b_varargout_1;
  boolean_T rtb_LogicalOperator;

  // MATLABSystem: '<S14>/SourceBlock'
  b_varargout_1 = Sub_motion_controller_circle_test_1.getLatestMessage
    (&motion_controller_circle_test_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S14>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S16>/Enable'

  // Start for MATLABSystem: '<S14>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S16>/In1'
    motion_controller_circle_test_B.In1 =
      motion_controller_circle_test_B.b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S14>/Enabled Subsystem'

  // Logic: '<Root>/LogicalOperator'
  rtb_LogicalOperator = (motion_controller_circle_test_B.In1.failsafe ||
    motion_controller_circle_test_B.In1.frame_lost);

  // Outputs for Atomic SubSystem: '<Root>/controller'
  // MATLABSystem: '<S2>/Get Parameter'
  ParamGet_motion_controller_circle_test_293.getParameter(&b_value);

  // Saturate: '<S2>/Saturation'
  if (b_value > motion_controller_circle_test_P.Saturation_UpperSat_h) {
    b_value = motion_controller_circle_test_P.Saturation_UpperSat_h;
  } else if (b_value < motion_controller_circle_test_P.Saturation_LowerSat_p) {
    b_value = motion_controller_circle_test_P.Saturation_LowerSat_p;
  }

  // End of Saturate: '<S2>/Saturation'

  // MATLABSystem: '<S2>/Get Parameter1'
  ParamGet_motion_controller_circle_test_295.getParameter(&b_value_0);

  // Chart: '<S2>/Chart' incorporates:
  //   MATLABSystem: '<S14>/SourceBlock'
  //   MATLABSystem: '<S2>/Get Parameter1'
  //   SignalConversion generated from: '<S4>/Bus Selector'
  //
  if (motion_controller_circle_tes_DW.is_active_c3_motion_controller_ == 0U) {
    motion_controller_circle_tes_DW.is_active_c3_motion_controller_ = 1U;
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
        motion_controller_circle_tes_DW.counter_check = 0U;
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
      qY = motion_controller_circle_tes_DW.counter_check + /*MW:OvSatOk*/ 1U;
      if (motion_controller_circle_tes_DW.counter_check + 1U <
          motion_controller_circle_tes_DW.counter_check) {
        qY = MAX_uint32_T;
      }

      motion_controller_circle_tes_DW.counter_check = qY;
      motion_controller_circle_tes_DW.sum += static_cast<real_T>(b_varargout_1);
      if (motion_controller_circle_tes_DW.counter_check -
          motion_controller_circle_tes_DW.counter_check / 20U * 20U == 0U) {
        motion_controller_circle_tes_DW.check =
          motion_controller_circle_tes_DW.sum;
        motion_controller_circle_tes_DW.sum = 0.0;
      }
    }

    switch (motion_controller_circle_tes_DW.is_cmd) {
     case motion_controller_circle_IN_Ini:
      motion_controller_circle_test_B.spd_cmd[0] = 0.0;
      motion_controller_circle_test_B.spd_cmd[1] = 0.0;
      motion_controller_circle_test_B.spd_cmd[2] = 0.0;
      motion_controller_circle_test_B.spd_cmd[3] = 0.0;
      if (motion_controller_circle_tes_DW.ready) {
        motion_controller_circle_tes_DW.is_cmd = motion_controller_circ_IN_steer;
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
      }
      break;

     case motion_controller_ci_IN_running:
      if (motion_controller_circle_test_B.In1.mapped_channels[4] != 1000) {
        motion_controller_circle_tes_DW.is_cmd = motion_controller_circ_IN_steer;
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
      } else {
        if (motion_controller_circle_test_B.In1.mapped_channels[2] <= 900) {
          if (motion_controller_circle_test_B.In1.mapped_channels[2] > 700) {
            b_value_0 -= 0.05;
          } else if (motion_controller_circle_test_B.In1.mapped_channels[2] >
                     500) {
            b_value_0 -= 0.1;
          } else if (motion_controller_circle_test_B.In1.mapped_channels[2] >
                     300) {
            b_value_0 = -b_value_0 + 0.1;
          } else if (motion_controller_circle_test_B.In1.mapped_channels[2] >
                     100) {
            b_value_0 = -b_value_0 + 0.05;
          } else {
            b_value_0 = -b_value_0;
          }
        }

        motion_controller_circle_test_B.angle_cmd[0] = b_value_0;
        motion_controller_circle_test_B.effort_cmd[0] = b_value;
        motion_controller_circle_test_B.angle_cmd[1] = b_value_0;
        motion_controller_circle_test_B.effort_cmd[1] = -b_value;
        motion_controller_circle_test_B.angle_cmd[2] = b_value_0;
        motion_controller_circle_test_B.effort_cmd[2] = -b_value;
        motion_controller_circle_test_B.angle_cmd[3] = b_value_0;
        motion_controller_circle_test_B.effort_cmd[3] = b_value;
        motion_controller_circle_test_B.mode = 2;
      }
      break;

     default:
      // case IN_steer:
      motion_controller_circle_test_B.spd_cmd[0] = 0.0;
      motion_controller_circle_test_B.spd_cmd[1] = 0.0;
      motion_controller_circle_test_B.spd_cmd[2] = 0.0;
      motion_controller_circle_test_B.spd_cmd[3] = 0.0;
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
      } else if (motion_controller_circle_test_B.In1.mapped_channels[4] == 1000)
      {
        motion_controller_circle_tes_DW.is_cmd = motion_controller_ci_IN_running;
        if (motion_controller_circle_test_B.In1.mapped_channels[2] <= 900) {
          if (motion_controller_circle_test_B.In1.mapped_channels[2] > 700) {
            b_value_0 -= 0.05;
          } else if (motion_controller_circle_test_B.In1.mapped_channels[2] >
                     500) {
            b_value_0 -= 0.1;
          } else if (motion_controller_circle_test_B.In1.mapped_channels[2] >
                     300) {
            b_value_0 = -b_value_0 + 0.1;
          } else if (motion_controller_circle_test_B.In1.mapped_channels[2] >
                     100) {
            b_value_0 = -b_value_0 + 0.05;
          } else {
            b_value_0 = -b_value_0;
          }
        }

        motion_controller_circle_test_B.angle_cmd[0] = b_value_0;
        motion_controller_circle_test_B.effort_cmd[0] = b_value;
        motion_controller_circle_test_B.angle_cmd[1] = b_value_0;
        motion_controller_circle_test_B.effort_cmd[1] = -b_value;
        motion_controller_circle_test_B.angle_cmd[2] = b_value_0;
        motion_controller_circle_test_B.effort_cmd[2] = -b_value;
        motion_controller_circle_test_B.angle_cmd[3] = b_value_0;
        motion_controller_circle_test_B.effort_cmd[3] = b_value;
        motion_controller_circle_test_B.mode = 2;
      } else {
        if (motion_controller_circle_test_B.In1.mapped_channels[2] <= 900) {
          if (motion_controller_circle_test_B.In1.mapped_channels[2] > 700) {
            b_value_0 -= 0.05;
          } else if (motion_controller_circle_test_B.In1.mapped_channels[2] >
                     500) {
            b_value_0 -= 0.1;
          } else if (motion_controller_circle_test_B.In1.mapped_channels[2] >
                     300) {
            b_value_0 = -b_value_0 + 0.1;
          } else if (motion_controller_circle_test_B.In1.mapped_channels[2] >
                     100) {
            b_value_0 = -b_value_0 + 0.05;
          } else {
            b_value_0 = -b_value_0;
          }
        }

        motion_controller_circle_test_B.angle_cmd[0] = b_value_0;
        motion_controller_circle_test_B.angle_cmd[1] = b_value_0;
        motion_controller_circle_test_B.angle_cmd[2] = b_value_0;
        motion_controller_circle_test_B.angle_cmd[3] = b_value_0;
        motion_controller_circle_test_B.mode = 2;
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

  if (motion_controller_circle_test_B.In1.mapped_channels[5] ==
      motion_controller_circle_test_P.ctc_const) {
    // Saturate: '<S1>/Saturation2'
    b_value = motion_controller_circle_test_B.effort_cmd[0];

    // Saturate: '<S1>/Saturation1'
    b_value_0 = motion_controller_circle_test_B.spd_cmd[0];

    // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
    //   ForEach: '<S8>/For Each'

    // ForEachSliceAssignment generated from: '<S8>/actuaor_command' incorporates:
    //   BusAssignment: '<S8>/Bus Assignment1'
    //   Constant: '<S12>/Constant'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0] =
      motion_controller_circle_test_P.CoreSubsys_p.Constant_Value;

    // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'

    // Saturate: '<S1>/Saturation2'
    if (b_value > motion_controller_circle_test_P.Saturation2_UpperSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0].effort =
        motion_controller_circle_test_P.Saturation2_UpperSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else if (b_value < motion_controller_circle_test_P.Saturation2_LowerSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0].effort =
        motion_controller_circle_test_P.Saturation2_LowerSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0].effort =
        b_value;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    }

    // Saturate: '<S1>/Saturation1'
    if (b_value_0 > motion_controller_circle_test_P.Saturation1_UpperSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0].velocity =
        motion_controller_circle_test_P.Saturation1_UpperSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else if (b_value_0 < motion_controller_circle_test_P.Saturation1_LowerSat)
    {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0].velocity =
        motion_controller_circle_test_P.Saturation1_LowerSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0].velocity =
        b_value_0;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    }

    // Saturate: '<S1>/Saturation2'
    b_value = motion_controller_circle_test_B.effort_cmd[1];

    // Saturate: '<S1>/Saturation1'
    b_value_0 = motion_controller_circle_test_B.spd_cmd[1];

    // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
    //   ForEach: '<S8>/For Each'

    // ForEachSliceAssignment generated from: '<S8>/actuaor_command' incorporates:
    //   BusAssignment: '<S8>/Bus Assignment1'
    //   Constant: '<S12>/Constant'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1] =
      motion_controller_circle_test_P.CoreSubsys_p.Constant_Value;

    // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'

    // Saturate: '<S1>/Saturation2'
    if (b_value > motion_controller_circle_test_P.Saturation2_UpperSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1].effort =
        motion_controller_circle_test_P.Saturation2_UpperSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else if (b_value < motion_controller_circle_test_P.Saturation2_LowerSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1].effort =
        motion_controller_circle_test_P.Saturation2_LowerSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1].effort =
        b_value;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    }

    // Saturate: '<S1>/Saturation1'
    if (b_value_0 > motion_controller_circle_test_P.Saturation1_UpperSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1].velocity =
        motion_controller_circle_test_P.Saturation1_UpperSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else if (b_value_0 < motion_controller_circle_test_P.Saturation1_LowerSat)
    {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1].velocity =
        motion_controller_circle_test_P.Saturation1_LowerSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1].velocity =
        b_value_0;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    }

    // Saturate: '<S1>/Saturation2'
    b_value = motion_controller_circle_test_B.effort_cmd[2];

    // Saturate: '<S1>/Saturation1'
    b_value_0 = motion_controller_circle_test_B.spd_cmd[2];

    // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
    //   ForEach: '<S8>/For Each'

    // ForEachSliceAssignment generated from: '<S8>/actuaor_command' incorporates:
    //   BusAssignment: '<S8>/Bus Assignment1'
    //   Constant: '<S12>/Constant'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2] =
      motion_controller_circle_test_P.CoreSubsys_p.Constant_Value;

    // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'

    // Saturate: '<S1>/Saturation2'
    if (b_value > motion_controller_circle_test_P.Saturation2_UpperSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2].effort =
        motion_controller_circle_test_P.Saturation2_UpperSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else if (b_value < motion_controller_circle_test_P.Saturation2_LowerSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2].effort =
        motion_controller_circle_test_P.Saturation2_LowerSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2].effort =
        b_value;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    }

    // Saturate: '<S1>/Saturation1'
    if (b_value_0 > motion_controller_circle_test_P.Saturation1_UpperSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2].velocity =
        motion_controller_circle_test_P.Saturation1_UpperSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else if (b_value_0 < motion_controller_circle_test_P.Saturation1_LowerSat)
    {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2].velocity =
        motion_controller_circle_test_P.Saturation1_LowerSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2].velocity =
        b_value_0;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    }

    // Saturate: '<S1>/Saturation2'
    b_value = motion_controller_circle_test_B.effort_cmd[3];

    // Saturate: '<S1>/Saturation1'
    b_value_0 = motion_controller_circle_test_B.spd_cmd[3];

    // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
    //   ForEach: '<S8>/For Each'

    // ForEachSliceAssignment generated from: '<S8>/actuaor_command' incorporates:
    //   BusAssignment: '<S8>/Bus Assignment1'
    //   Constant: '<S12>/Constant'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3] =
      motion_controller_circle_test_P.CoreSubsys_p.Constant_Value;

    // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'

    // Saturate: '<S1>/Saturation2'
    if (b_value > motion_controller_circle_test_P.Saturation2_UpperSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3].effort =
        motion_controller_circle_test_P.Saturation2_UpperSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else if (b_value < motion_controller_circle_test_P.Saturation2_LowerSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3].effort =
        motion_controller_circle_test_P.Saturation2_LowerSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3].effort =
        b_value;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    }

    // Saturate: '<S1>/Saturation1'
    if (b_value_0 > motion_controller_circle_test_P.Saturation1_UpperSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3].velocity =
        motion_controller_circle_test_P.Saturation1_UpperSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else if (b_value_0 < motion_controller_circle_test_P.Saturation1_LowerSat)
    {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3].velocity =
        motion_controller_circle_test_P.Saturation1_LowerSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    } else {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem1' incorporates:
      //   ForEach: '<S8>/For Each'

      // BusAssignment: '<S8>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S8>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3].velocity =
        b_value_0;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem1'
    }

    motion_controller_c_CurrentTime
      (&motion_controller_circle_test_B.CurrentTime1);

    // BusAssignment: '<S1>/Bus Assignment1' incorporates:
    //   Constant: '<S6>/Constant'
    //   DataTypeConversion: '<S1>/Data Type Conversion'

    motion_controller_circle_test_B.BusAssignment1 =
      motion_controller_circle_test_P.Constant_Value;
    motion_controller_circle_test_B.BusAssignment1.header.stamp =
      motion_controller_circle_test_B.CurrentTime1.CurrentTime;
    motion_controller_circle_test_B.BusAssignment1.drive_mode =
      motion_controller_circle_test_B.mode;
    memcpy(&motion_controller_circle_test_B.BusAssignment1.actuator_command[0],
           &motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0],
           sizeof(SL_Bus_custom_interfaces_Actuator) << 2U);

    // MATLABSystem: '<S9>/SinkBlock'
    Pub_motion_controller_circle_test_4.publish
      (&motion_controller_circle_test_B.BusAssignment1);

    // Saturate: '<S1>/Saturation'
    b_value = motion_controller_circle_test_B.angle_cmd[0];

    // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem' incorporates:
    //   ForEach: '<S7>/For Each'

    // ForEachSliceAssignment generated from: '<S7>/actuaor_command' incorporates:
    //   BusAssignment: '<S7>/Bus Assignment1'
    //   Constant: '<S11>/Constant'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0] =
      motion_controller_circle_test_P.CoreSubsys.Constant_Value;

    // End of Outputs for SubSystem: '<S1>/For Each Subsystem'

    // Saturate: '<S1>/Saturation'
    if (b_value > motion_controller_circle_test_P.Saturation_UpperSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem' incorporates:
      //   ForEach: '<S7>/For Each'

      // BusAssignment: '<S7>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0].position =
        motion_controller_circle_test_P.Saturation_UpperSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem'
    } else if (b_value < motion_controller_circle_test_P.Saturation_LowerSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem' incorporates:
      //   ForEach: '<S7>/For Each'

      // BusAssignment: '<S7>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0].position =
        motion_controller_circle_test_P.Saturation_LowerSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem'
    } else {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem' incorporates:
      //   ForEach: '<S7>/For Each'

      // BusAssignment: '<S7>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0].position =
        b_value;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem'
    }

    b_value = motion_controller_circle_test_B.angle_cmd[1];

    // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem' incorporates:
    //   ForEach: '<S7>/For Each'

    // ForEachSliceAssignment generated from: '<S7>/actuaor_command' incorporates:
    //   BusAssignment: '<S7>/Bus Assignment1'
    //   Constant: '<S11>/Constant'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1] =
      motion_controller_circle_test_P.CoreSubsys.Constant_Value;

    // End of Outputs for SubSystem: '<S1>/For Each Subsystem'

    // Saturate: '<S1>/Saturation'
    if (b_value > motion_controller_circle_test_P.Saturation_UpperSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem' incorporates:
      //   ForEach: '<S7>/For Each'

      // BusAssignment: '<S7>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1].position =
        motion_controller_circle_test_P.Saturation_UpperSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem'
    } else if (b_value < motion_controller_circle_test_P.Saturation_LowerSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem' incorporates:
      //   ForEach: '<S7>/For Each'

      // BusAssignment: '<S7>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1].position =
        motion_controller_circle_test_P.Saturation_LowerSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem'
    } else {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem' incorporates:
      //   ForEach: '<S7>/For Each'

      // BusAssignment: '<S7>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[1].position =
        b_value;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem'
    }

    b_value = motion_controller_circle_test_B.angle_cmd[2];

    // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem' incorporates:
    //   ForEach: '<S7>/For Each'

    // ForEachSliceAssignment generated from: '<S7>/actuaor_command' incorporates:
    //   BusAssignment: '<S7>/Bus Assignment1'
    //   Constant: '<S11>/Constant'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2] =
      motion_controller_circle_test_P.CoreSubsys.Constant_Value;

    // End of Outputs for SubSystem: '<S1>/For Each Subsystem'

    // Saturate: '<S1>/Saturation'
    if (b_value > motion_controller_circle_test_P.Saturation_UpperSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem' incorporates:
      //   ForEach: '<S7>/For Each'

      // BusAssignment: '<S7>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2].position =
        motion_controller_circle_test_P.Saturation_UpperSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem'
    } else if (b_value < motion_controller_circle_test_P.Saturation_LowerSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem' incorporates:
      //   ForEach: '<S7>/For Each'

      // BusAssignment: '<S7>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2].position =
        motion_controller_circle_test_P.Saturation_LowerSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem'
    } else {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem' incorporates:
      //   ForEach: '<S7>/For Each'

      // BusAssignment: '<S7>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[2].position =
        b_value;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem'
    }

    b_value = motion_controller_circle_test_B.angle_cmd[3];

    // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem' incorporates:
    //   ForEach: '<S7>/For Each'

    // ForEachSliceAssignment generated from: '<S7>/actuaor_command' incorporates:
    //   BusAssignment: '<S7>/Bus Assignment1'
    //   Constant: '<S11>/Constant'

    motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3] =
      motion_controller_circle_test_P.CoreSubsys.Constant_Value;

    // End of Outputs for SubSystem: '<S1>/For Each Subsystem'

    // Saturate: '<S1>/Saturation'
    if (b_value > motion_controller_circle_test_P.Saturation_UpperSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem' incorporates:
      //   ForEach: '<S7>/For Each'

      // BusAssignment: '<S7>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3].position =
        motion_controller_circle_test_P.Saturation_UpperSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem'
    } else if (b_value < motion_controller_circle_test_P.Saturation_LowerSat) {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem' incorporates:
      //   ForEach: '<S7>/For Each'

      // BusAssignment: '<S7>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3].position =
        motion_controller_circle_test_P.Saturation_LowerSat;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem'
    } else {
      // Outputs for Iterator SubSystem: '<S1>/For Each Subsystem' incorporates:
      //   ForEach: '<S7>/For Each'

      // BusAssignment: '<S7>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S7>/actuaor_command'

      motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[3].position =
        b_value;

      // End of Outputs for SubSystem: '<S1>/For Each Subsystem'
    }

    motion_controller_c_CurrentTime(&motion_controller_circle_test_B.CurrentTime);

    // BusAssignment: '<S1>/Bus Assignment2' incorporates:
    //   Constant: '<S5>/Constant'

    motion_controller_circle_test_B.BusAssignment1 =
      motion_controller_circle_test_P.Constant_Value_i;
    motion_controller_circle_test_B.BusAssignment1.header.stamp =
      motion_controller_circle_test_B.CurrentTime.CurrentTime;
    memcpy(&motion_controller_circle_test_B.BusAssignment1.actuator_command[0],
           &motion_controller_circle_test_B.ImpAsg_InsertedFor_actuaor_[0],
           sizeof(SL_Bus_custom_interfaces_Actuator) << 2U);

    // MATLABSystem: '<S10>/SinkBlock'
    Pub_motion_controller_circle_test_148.publish
      (&motion_controller_circle_test_B.BusAssignment1);
  }

  // End of RelationalOperator: '<S3>/Compare'
  // End of Outputs for SubSystem: '<Root>/cmd_pub'
}

// Model initialize function
void motion_controller_circle_test::initialize()
{
  {
    static const char_T prmName[7] = "effort";
    static const char_T prmName_0[10] = "angle_max";

    // SystemInitialize for Enabled SubSystem: '<S14>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S16>/In1' incorporates:
    //   Outport: '<S16>/Out1'

    motion_controller_circle_test_B.In1 =
      motion_controller_circle_test_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S14>/Enabled Subsystem'

    // SystemInitialize for Atomic SubSystem: '<Root>/controller'
    // Start for MATLABSystem: '<S2>/Get Parameter'
    motion_controller_circle_tes_DW.obj_e.matlabCodegenIsDeleted = false;
    motion_controller_circle_tes_DW.obj_e.isInitialized = 1;
    ParamGet_motion_controller_circle_test_293.initParam(&prmName[0]);
    ParamGet_motion_controller_circle_test_293.setInitialValue(0.05);
    motion_controller_circle_tes_DW.obj_e.isSetupComplete = true;

    // Start for MATLABSystem: '<S2>/Get Parameter1'
    motion_controller_circle_tes_DW.obj.matlabCodegenIsDeleted = false;
    motion_controller_circle_tes_DW.obj.isInitialized = 1;
    ParamGet_motion_controller_circle_test_295.initParam(&prmName_0[0]);
    ParamGet_motion_controller_circle_test_295.setInitialValue(0.7);
    motion_controller_circle_tes_DW.obj.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<Root>/controller'

    // SystemInitialize for Enabled SubSystem: '<Root>/cmd_pub'
    motion_control_CurrentTime_Init
      (&motion_controller_circle_tes_DW.CurrentTime1);

    // Start for MATLABSystem: '<S9>/SinkBlock'
    motion_control_SystemCore_setup(&motion_controller_circle_tes_DW.obj_b);
    motion_control_CurrentTime_Init(&motion_controller_circle_tes_DW.CurrentTime);

    // Start for MATLABSystem: '<S10>/SinkBlock'
    motion_contr_SystemCore_setup_d(&motion_controller_circle_tes_DW.obj_c);

    // End of SystemInitialize for SubSystem: '<Root>/cmd_pub'

    // Start for MATLABSystem: '<S14>/SourceBlock'
    motion_cont_SystemCore_setup_de(&motion_controller_circle_tes_DW.obj_n);
  }
}

// Model terminate function
void motion_controller_circle_test::terminate()
{
  // Terminate for MATLABSystem: '<S14>/SourceBlock'
  if (!motion_controller_circle_tes_DW.obj_n.matlabCodegenIsDeleted) {
    motion_controller_circle_tes_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/SourceBlock'

  // Terminate for Atomic SubSystem: '<Root>/controller'
  // Terminate for MATLABSystem: '<S2>/Get Parameter'
  if (!motion_controller_circle_tes_DW.obj_e.matlabCodegenIsDeleted) {
    motion_controller_circle_tes_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/Get Parameter'

  // Terminate for MATLABSystem: '<S2>/Get Parameter1'
  if (!motion_controller_circle_tes_DW.obj.matlabCodegenIsDeleted) {
    motion_controller_circle_tes_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S2>/Get Parameter1'
  // End of Terminate for SubSystem: '<Root>/controller'

  // Terminate for Enabled SubSystem: '<Root>/cmd_pub'
  motion_control_CurrentTime_Term(&motion_controller_circle_tes_DW.CurrentTime1);

  // Terminate for MATLABSystem: '<S9>/SinkBlock'
  if (!motion_controller_circle_tes_DW.obj_b.matlabCodegenIsDeleted) {
    motion_controller_circle_tes_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/SinkBlock'
  motion_control_CurrentTime_Term(&motion_controller_circle_tes_DW.CurrentTime);

  // Terminate for MATLABSystem: '<S10>/SinkBlock'
  if (!motion_controller_circle_tes_DW.obj_c.matlabCodegenIsDeleted) {
    motion_controller_circle_tes_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/SinkBlock'
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
