//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: motion_controller_slx.cpp
//
// Code generated for Simulink model 'motion_controller_slx'.
//
// Model version                  : 2.251
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Tue Dec  3 20:49:54 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "motion_controller_slx.h"
#include "rtwtypes.h"
#include "motion_controller_slx_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <math.h>
#include "rt_atan2d_snf.h"
#include <string.h>
#include "rmw/qos_profiles.h"
#include <stddef.h>

// Named constants for Chart: '<S4>/Chart'
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
  // Start for MATLABSystem: '<S3>/Current Time'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void motion_controller_slx::motion_controller_s_CurrentTime
  (B_CurrentTime_motion_controll_T *localB)
{
  // MATLABSystem: '<S3>/Current Time'
  currentROS2TimeBus(&localB->CurrentTime);
}

// Termination for atomic system:
void motion_controller_slx::motion_control_CurrentTime_Term
  (DW_CurrentTime_motion_control_T *localDW)
{
  // Terminate for MATLABSystem: '<S3>/Current Time'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/Current Time'
}

// Output and update for Simulink Function: '<S4>/get_angle_4w'
void motion_controller_slx::motion_controller__get_angle_4w(real_T rtu_delta_f,
  real_T rtu_delta_r, real_T rty_angle_cmd[4]) const
{
  real_T deltaFR;
  real_T deltaRL;
  real_T deltaRR;

  // MATLAB Function: '<S20>/MATLAB Function' incorporates:
  //   SignalConversion generated from: '<S20>/ackermann_enable'
  //   SignalConversion generated from: '<S20>/delta_f'
  //   SignalConversion generated from: '<S20>/delta_r'

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

    // SignalConversion generated from: '<S20>/angle_cmd' incorporates:
    //   SignalConversion generated from: '<S20>/delta_f'
    //   SignalConversion generated from: '<S20>/delta_r'

    rty_angle_cmd[0] = atan(deltaRL_tmp / deltaFL_tmp) * deltaFR;
    deltaFR_tmp += 2.0 * motion_controller_slx_P.L;
    deltaFR *= atan(deltaRL_tmp / deltaFR_tmp);
    deltaRL_tmp = 2.0 * motion_controller_slx_P.L * deltaRL;
    deltaRL = atan(deltaRL_tmp / deltaFL_tmp) * deltaRR;
    deltaRR *= atan(deltaRL_tmp / deltaFR_tmp);
  } else {
    // SignalConversion generated from: '<S20>/angle_cmd' incorporates:
    //   SignalConversion generated from: '<S20>/delta_f'

    rty_angle_cmd[0] = rtu_delta_f;
    deltaFR = rtu_delta_f;
    deltaRR = rtu_delta_r;
    deltaRL = rtu_delta_r;
  }

  // SignalConversion generated from: '<S20>/angle_cmd' incorporates:
  //   MATLAB Function: '<S20>/MATLAB Function'

  rty_angle_cmd[1] = deltaFR;
  rty_angle_cmd[2] = deltaRR;
  rty_angle_cmd[3] = deltaRL;
}

// System initialize for Simulink Function: '<S4>/get_effort'
void motion_controller_slx::motion_controll_get_effort_Init()
{
  static const char_T prmName[10] = "effortMax";
  static const char_T prmName_0[13] = "isTcsEnabled";
  static const char_T prmName_1[10] = "tcsK1Sgne";
  static const char_T prmName_2[7] = "tcsK2e";
  static const char_T prmName_3[17] = "tcsFxEstimatedMu";
  static const char_T prmName_4[16] = "tcsKappaDesired";

  // Start for MATLABSystem: '<S21>/Get Parameter'
  motion_controller_slx_DW.obj_d2.matlabCodegenIsDeleted = false;
  motion_controller_slx_DW.obj_d2.isInitialized = 1;
  ParamGet_motion_controller_slx_202.initParam(&prmName[0]);
  ParamGet_motion_controller_slx_202.setInitialValue(0.6);
  motion_controller_slx_DW.obj_d2.isSetupComplete = true;

  // Start for MATLABSystem: '<S21>/Get Parameter1'
  motion_controller_slx_DW.obj_p.matlabCodegenIsDeleted = false;
  motion_controller_slx_DW.obj_p.isInitialized = 1;
  ParamGet_motion_controller_slx_353.initParam(&prmName_0[0]);
  ParamGet_motion_controller_slx_353.setInitialValue(true);
  motion_controller_slx_DW.obj_p.isSetupComplete = true;

  // Start for MATLABSystem: '<S21>/Get Parameter2'
  motion_controller_slx_DW.obj_a.matlabCodegenIsDeleted = false;
  motion_controller_slx_DW.obj_a.isInitialized = 1;
  ParamGet_motion_controller_slx_354.initParam(&prmName_1[0]);
  ParamGet_motion_controller_slx_354.setInitialValue(0.8);
  motion_controller_slx_DW.obj_a.isSetupComplete = true;

  // Start for MATLABSystem: '<S21>/Get Parameter3'
  motion_controller_slx_DW.obj_l.matlabCodegenIsDeleted = false;
  motion_controller_slx_DW.obj_l.isInitialized = 1;
  ParamGet_motion_controller_slx_355.initParam(&prmName_2[0]);
  ParamGet_motion_controller_slx_355.setInitialValue(10.0);
  motion_controller_slx_DW.obj_l.isSetupComplete = true;

  // Start for MATLABSystem: '<S21>/Get Parameter4'
  motion_controller_slx_DW.obj_d.matlabCodegenIsDeleted = false;
  motion_controller_slx_DW.obj_d.isInitialized = 1;
  ParamGet_motion_controller_slx_365.initParam(&prmName_3[0]);
  ParamGet_motion_controller_slx_365.setInitialValue(0.6);
  motion_controller_slx_DW.obj_d.isSetupComplete = true;

  // Start for MATLABSystem: '<S21>/Get Parameter5'
  motion_controller_slx_DW.obj.matlabCodegenIsDeleted = false;
  motion_controller_slx_DW.obj.isInitialized = 1;
  ParamGet_motion_controller_slx_393.initParam(&prmName_4[0]);
  ParamGet_motion_controller_slx_393.setInitialValue(0.15);
  motion_controller_slx_DW.obj.isSetupComplete = true;
}

// Output and update for Simulink Function: '<S4>/get_effort'
void motion_controller_slx::motion_controller_sl_get_effort(real_T rtu_longdrive,
  real_T rtu_vx, real_T rtu_dvx, const real_T rtu_omega4w[4], real_T
  rty_effort_cmd[4])
{
  real_T rtb_mu_r;
  boolean_T b_value;

  // MATLABSystem: '<S21>/Get Parameter'
  ParamGet_motion_controller_slx_202.getParameter
    (&motion_controller_slx_B.b_value);

  // MATLABSystem: '<S21>/Get Parameter1'
  ParamGet_motion_controller_slx_353.getParameter(&b_value);

  // MATLABSystem: '<S21>/Get Parameter2'
  ParamGet_motion_controller_slx_354.getParameter
    (&motion_controller_slx_B.b_value_m);

  // MATLABSystem: '<S21>/Get Parameter3'
  ParamGet_motion_controller_slx_355.getParameter
    (&motion_controller_slx_B.b_value_c);

  // MATLABSystem: '<S21>/Get Parameter4'
  ParamGet_motion_controller_slx_365.getParameter
    (&motion_controller_slx_B.b_value_k);

  // MATLAB Function: '<S21>/getFz' incorporates:
  //   SignalConversion generated from: '<S21>/angle3'

  motion_controller_slx_B.b_value_cx = motion_controller_slx_P.m *
    motion_controller_slx_P.g;
  motion_controller_slx_B.effort = motion_controller_slx_P.m * rtu_dvx *
    motion_controller_slx_P.h;
  motion_controller_slx_B.Fzf = (motion_controller_slx_B.b_value_cx *
    motion_controller_slx_P.b - motion_controller_slx_B.effort) / 2.0 /
    motion_controller_slx_P.L;
  motion_controller_slx_B.Fzr = (motion_controller_slx_B.b_value_cx *
    motion_controller_slx_P.a + motion_controller_slx_B.effort) / 2.0 /
    motion_controller_slx_P.L;

  // Sum: '<S21>/mu_r' incorporates:
  //   Constant: '<S21>/Constant'
  //   Constant: '<S21>/Constant1'
  //   Product: '<S21>/Fx1'
  //   SignalConversion generated from: '<S21>/angle1'

  rtb_mu_r = rtu_vx * motion_controller_slx_P.Constant_Value_m +
    motion_controller_slx_P.Constant1_Value;

  // MATLABSystem: '<S21>/Get Parameter5'
  ParamGet_motion_controller_slx_393.getParameter
    (&motion_controller_slx_B.b_value_cx);

  // MATLAB Function: '<S21>/MATLAB Function' incorporates:
  //   Constant: '<S21>/Constant2'
  //   Constant: '<S21>/Constant3'
  //   Gain: '<S21>/Gain'
  //   MATLABSystem: '<S21>/Get Parameter'
  //   MATLABSystem: '<S21>/Get Parameter1'
  //   MATLABSystem: '<S21>/Get Parameter2'
  //   MATLABSystem: '<S21>/Get Parameter3'
  //   MATLABSystem: '<S21>/Get Parameter5'
  //   Product: '<S21>/Fx3'
  //   SignalConversion generated from: '<S21>/angle1'
  //   SignalConversion generated from: '<S21>/angle2'
  //   SignalConversion generated from: '<S21>/angle3'
  //   SignalConversion generated from: '<S21>/angle'
  //   Sum: '<S21>/Ftr'
  //   Sum: '<S21>/Sum'

  motion_controller_slx_B.effort = rtu_longdrive *
    motion_controller_slx_B.b_value;
  if (b_value) {
    real_T sat_idx_0;
    real_T sat_idx_1;
    real_T sat_idx_3;
    if (rtu_vx <= 0.0) {
      sat_idx_0 = 0.4;
      sat_idx_1 = 0.4;
      motion_controller_slx_B.b_value_k = 0.4;
      sat_idx_3 = 0.4;
    } else {
      real_T rtb_e_0;
      real_T tmp;
      real_T tmp_0;
      motion_controller_slx_B.y = rtu_vx * rtu_vx;
      motion_controller_slx_B.b_y = motion_controller_slx_P.MATLABFunction_Re *
        motion_controller_slx_P.MATLABFunction_Re;
      tmp_0 = motion_controller_slx_P.MATLABFunction_J * rtu_vx;
      tmp = motion_controller_slx_P.MATLABFunction_Re * rtu_dvx;
      rtb_e_0 = motion_controller_slx_B.b_value_cx - (rtu_omega4w[0] *
        motion_controller_slx_P.MATLABFunction_Re / rtu_vx - 1.0);
      if (rtb_e_0 <= 5.0) {
        sat_idx_3 = rtb_e_0;
      } else {
        sat_idx_3 = 5.0;
      }

      if (sat_idx_3 <= -1.0) {
        rtb_e_0 = -1.0;
      } else {
        rtb_e_0 = sat_idx_3;
      }

      sat_idx_3 = rtb_e_0 / 0.04;
      if (!(sat_idx_3 <= 1.0)) {
        sat_idx_3 = 1.0;
      }

      if (sat_idx_3 <= -1.0) {
        sat_idx_3 = -1.0;
      }

      // Sum: '<S21>/Sum' incorporates:
      //   MATLAB Function: '<S21>/getFz'
      //   MATLABSystem: '<S21>/Get Parameter4'
      //   MATLABSystem: '<S21>/Get Parameter5'
      //   Product: '<S21>/Frr'
      //   Product: '<S21>/Fx'
      //   SignalConversion generated from: '<S21>/angle2'
      //   SignalConversion generated from: '<S21>/angle3'

      motion_controller_slx_B.Fzf = motion_controller_slx_B.b_value_k *
        motion_controller_slx_B.Fzf + motion_controller_slx_B.Fzf * rtb_mu_r;
      sat_idx_3 = (((rtu_omega4w[0] * motion_controller_slx_P.Constant2_Value *
                     motion_controller_slx_P.Gain_Gain +
                     motion_controller_slx_P.Constant3_Value) +
                    motion_controller_slx_B.Fzf) * motion_controller_slx_B.b_y /
                   tmp_0 + ((rtb_e_0 * motion_controller_slx_B.b_value_c +
        motion_controller_slx_B.b_value_m * sat_idx_3) + tmp * rtu_omega4w[0] /
                            motion_controller_slx_B.y)) * tmp_0 /
        motion_controller_slx_P.MATLABFunction_Re;
      b_value = !rtIsNaN(motion_controller_slx_B.b_value);
      if ((!(sat_idx_3 <= motion_controller_slx_B.b_value)) && b_value) {
        sat_idx_3 = motion_controller_slx_B.b_value;
      }

      if ((sat_idx_3 <= 0.0) || rtIsNaN(sat_idx_3)) {
        sat_idx_0 = 0.0;
      } else {
        sat_idx_0 = sat_idx_3;
      }

      rtb_e_0 = motion_controller_slx_B.b_value_cx - (rtu_omega4w[1] *
        motion_controller_slx_P.MATLABFunction_Re / rtu_vx - 1.0);
      if (rtb_e_0 <= 5.0) {
        sat_idx_3 = rtb_e_0;
      } else {
        sat_idx_3 = 5.0;
      }

      if (sat_idx_3 <= -1.0) {
        rtb_e_0 = -1.0;
      } else {
        rtb_e_0 = sat_idx_3;
      }

      sat_idx_3 = rtb_e_0 / 0.04;
      if (!(sat_idx_3 <= 1.0)) {
        sat_idx_3 = 1.0;
      }

      if (sat_idx_3 <= -1.0) {
        sat_idx_3 = -1.0;
      }

      sat_idx_3 = (((rtu_omega4w[1] * motion_controller_slx_P.Constant2_Value *
                     motion_controller_slx_P.Gain_Gain +
                     motion_controller_slx_P.Constant3_Value) +
                    motion_controller_slx_B.Fzf) * motion_controller_slx_B.b_y /
                   tmp_0 + ((rtb_e_0 * motion_controller_slx_B.b_value_c +
        motion_controller_slx_B.b_value_m * sat_idx_3) + tmp * rtu_omega4w[1] /
                            motion_controller_slx_B.y)) * tmp_0 /
        motion_controller_slx_P.MATLABFunction_Re;
      if ((!(sat_idx_3 <= motion_controller_slx_B.b_value)) && b_value) {
        sat_idx_3 = motion_controller_slx_B.b_value;
      }

      if ((sat_idx_3 <= 0.0) || rtIsNaN(sat_idx_3)) {
        sat_idx_1 = 0.0;
      } else {
        sat_idx_1 = sat_idx_3;
      }

      rtb_e_0 = motion_controller_slx_B.b_value_cx - (rtu_omega4w[2] *
        motion_controller_slx_P.MATLABFunction_Re / rtu_vx - 1.0);
      if (rtb_e_0 <= 5.0) {
        sat_idx_3 = rtb_e_0;
      } else {
        sat_idx_3 = 5.0;
      }

      if (sat_idx_3 <= -1.0) {
        rtb_e_0 = -1.0;
      } else {
        rtb_e_0 = sat_idx_3;
      }

      sat_idx_3 = rtb_e_0 / 0.04;
      if (!(sat_idx_3 <= 1.0)) {
        sat_idx_3 = 1.0;
      }

      if (sat_idx_3 <= -1.0) {
        sat_idx_3 = -1.0;
      }

      // Sum: '<S21>/Sum' incorporates:
      //   Constant: '<S21>/Constant2'
      //   Constant: '<S21>/Constant3'
      //   Gain: '<S21>/Gain'
      //   MATLAB Function: '<S21>/getFz'
      //   MATLABSystem: '<S21>/Get Parameter2'
      //   MATLABSystem: '<S21>/Get Parameter3'
      //   MATLABSystem: '<S21>/Get Parameter4'
      //   MATLABSystem: '<S21>/Get Parameter5'
      //   Product: '<S21>/Frr'
      //   Product: '<S21>/Fx'
      //   Product: '<S21>/Fx3'
      //   SignalConversion generated from: '<S21>/angle2'
      //   Sum: '<S21>/Ftr'

      motion_controller_slx_B.Fzf = motion_controller_slx_B.b_value_k *
        motion_controller_slx_B.Fzr + motion_controller_slx_B.Fzr * rtb_mu_r;
      sat_idx_3 = (((rtu_omega4w[2] * motion_controller_slx_P.Constant2_Value *
                     motion_controller_slx_P.Gain_Gain +
                     motion_controller_slx_P.Constant3_Value) +
                    motion_controller_slx_B.Fzf) * motion_controller_slx_B.b_y /
                   tmp_0 + ((rtb_e_0 * motion_controller_slx_B.b_value_c +
        motion_controller_slx_B.b_value_m * sat_idx_3) + tmp * rtu_omega4w[2] /
                            motion_controller_slx_B.y)) * tmp_0 /
        motion_controller_slx_P.MATLABFunction_Re;
      if ((!(sat_idx_3 <= motion_controller_slx_B.b_value)) && b_value) {
        sat_idx_3 = motion_controller_slx_B.b_value;
      }

      if ((sat_idx_3 <= 0.0) || rtIsNaN(sat_idx_3)) {
        motion_controller_slx_B.b_value_k = 0.0;
      } else {
        motion_controller_slx_B.b_value_k = sat_idx_3;
      }

      rtb_e_0 = motion_controller_slx_B.b_value_cx - (rtu_omega4w[3] *
        motion_controller_slx_P.MATLABFunction_Re / rtu_vx - 1.0);
      if (rtb_e_0 <= 5.0) {
        sat_idx_3 = rtb_e_0;
      } else {
        sat_idx_3 = 5.0;
      }

      if (sat_idx_3 <= -1.0) {
        rtb_e_0 = -1.0;
      } else {
        rtb_e_0 = sat_idx_3;
      }

      sat_idx_3 = rtb_e_0 / 0.04;
      if (!(sat_idx_3 <= 1.0)) {
        sat_idx_3 = 1.0;
      }

      if (sat_idx_3 <= -1.0) {
        sat_idx_3 = -1.0;
      }

      sat_idx_3 = (((rtu_omega4w[3] * motion_controller_slx_P.Constant2_Value *
                     motion_controller_slx_P.Gain_Gain +
                     motion_controller_slx_P.Constant3_Value) +
                    motion_controller_slx_B.Fzf) * motion_controller_slx_B.b_y /
                   tmp_0 + ((rtb_e_0 * motion_controller_slx_B.b_value_c +
        motion_controller_slx_B.b_value_m * sat_idx_3) + tmp * rtu_omega4w[3] /
                            motion_controller_slx_B.y)) * tmp_0 /
        motion_controller_slx_P.MATLABFunction_Re;
      if ((!(sat_idx_3 <= motion_controller_slx_B.b_value)) && b_value) {
        sat_idx_3 = motion_controller_slx_B.b_value;
      }

      if ((sat_idx_3 <= 0.0) || rtIsNaN(sat_idx_3)) {
        sat_idx_3 = 0.0;
      }
    }

    if (motion_controller_slx_B.effort <= sat_idx_0) {
      // SignalConversion generated from: '<S21>/angle_cmd'
      rty_effort_cmd[0] = motion_controller_slx_B.effort;
    } else {
      // SignalConversion generated from: '<S21>/angle_cmd'
      rty_effort_cmd[0] = sat_idx_0;
    }

    if (motion_controller_slx_B.effort <= sat_idx_1) {
      // SignalConversion generated from: '<S21>/angle_cmd'
      rty_effort_cmd[1] = -motion_controller_slx_B.effort;
    } else {
      // SignalConversion generated from: '<S21>/angle_cmd'
      rty_effort_cmd[1] = -sat_idx_1;
    }

    if (motion_controller_slx_B.effort <= motion_controller_slx_B.b_value_k) {
      // SignalConversion generated from: '<S21>/angle_cmd'
      rty_effort_cmd[2] = -motion_controller_slx_B.effort;
    } else {
      // SignalConversion generated from: '<S21>/angle_cmd'
      rty_effort_cmd[2] = -motion_controller_slx_B.b_value_k;
    }

    if (motion_controller_slx_B.effort <= sat_idx_3) {
      // SignalConversion generated from: '<S21>/angle_cmd'
      rty_effort_cmd[3] = motion_controller_slx_B.effort;
    } else {
      // SignalConversion generated from: '<S21>/angle_cmd'
      rty_effort_cmd[3] = sat_idx_3;
    }
  } else {
    // SignalConversion generated from: '<S21>/angle_cmd'
    rty_effort_cmd[0] = motion_controller_slx_B.effort;
    rty_effort_cmd[1] = -motion_controller_slx_B.effort;
    rty_effort_cmd[2] = -motion_controller_slx_B.effort;
    rty_effort_cmd[3] = motion_controller_slx_B.effort;
  }

  // End of MATLAB Function: '<S21>/MATLAB Function'
}

// Termination for Simulink Function: '<S4>/get_effort'
void motion_controller_slx::motion_controll_get_effort_Term()
{
  // Terminate for MATLABSystem: '<S21>/Get Parameter'
  if (!motion_controller_slx_DW.obj_d2.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_d2.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S21>/Get Parameter'

  // Terminate for MATLABSystem: '<S21>/Get Parameter1'
  if (!motion_controller_slx_DW.obj_p.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S21>/Get Parameter1'

  // Terminate for MATLABSystem: '<S21>/Get Parameter2'
  if (!motion_controller_slx_DW.obj_a.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S21>/Get Parameter2'

  // Terminate for MATLABSystem: '<S21>/Get Parameter3'
  if (!motion_controller_slx_DW.obj_l.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S21>/Get Parameter3'

  // Terminate for MATLABSystem: '<S21>/Get Parameter4'
  if (!motion_controller_slx_DW.obj_d.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S21>/Get Parameter4'

  // Terminate for MATLABSystem: '<S21>/Get Parameter5'
  if (!motion_controller_slx_DW.obj.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S21>/Get Parameter5'
}

// Output and update for Simulink Function: '<S4>/get_spd'
void motion_controller_slx::motion_controller_slx_get_spd(real_T rtu_angle,
  real_T rtu_longdrive, real_T rty_spd_cmd[4]) const
{
  real_T b_x;
  real_T vFR;
  real_T vRL;
  real_T vRR;
  real_T vRR_tmp;

  // MATLAB Function: '<S22>/MATLAB Function' incorporates:
  //   Gain: '<S22>/Gain'
  //   SignalConversion generated from: '<S22>/ackermann_enable'
  //   SignalConversion generated from: '<S22>/angle'
  //   SignalConversion generated from: '<S22>/longdrive'

  if (motion_controller_slx_P.Gain_Gain_m *
      motion_controller_slx_B.GetParameter1 == 1.0) {
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

    // SignalConversion generated from: '<S22>/spd_cmd' incorporates:
    //   SignalConversion generated from: '<S22>/angle'
    //   SignalConversion generated from: '<S22>/longdrive'

    rty_spd_cmd[0] = vRL / cos(b_x);
  } else {
    // SignalConversion generated from: '<S22>/spd_cmd' incorporates:
    //   SignalConversion generated from: '<S22>/longdrive'

    rty_spd_cmd[0] = rtu_longdrive;
    vFR = rtu_longdrive;
    vRL = rtu_longdrive;
    vRR = rtu_longdrive;
  }

  // SignalConversion generated from: '<S22>/spd_cmd' incorporates:
  //   MATLAB Function: '<S22>/MATLAB Function'

  rty_spd_cmd[1] = -vFR;
  rty_spd_cmd[2] = -vRR;
  rty_spd_cmd[3] = vRL;
}

void motion_controller_slx::motion_cont_SystemCore_setup_o0
  (ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[11];
  static const char_T b_zeroDelimTopic_0[11] = "/motor_cmd";

  // Start for MATLABSystem: '<S14>/SinkBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S14>/SinkBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)5.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 11; i++) {
    // Start for MATLABSystem: '<S14>/SinkBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Pub_motion_controller_slx_4.createPublisher(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_slx::motion_con_SystemCore_setup_o0a
  (ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[11];
  static const char_T b_zeroDelimTopic_0[11] = "/servo_cmd";

  // Start for MATLABSystem: '<S15>/SinkBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S15>/SinkBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)10.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 11; i++) {
    // Start for MATLABSystem: '<S15>/SinkBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Pub_motion_controller_slx_148.createPublisher(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_slx::motion_co_SystemCore_setup_o0aj
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[6];
  static const char_T b_zeroDelimTopic_0[6] = "/sbus";

  // Start for MATLABSystem: '<S30>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S30>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  for (int32_T i = 0; i < 6; i++) {
    // Start for MATLABSystem: '<S30>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_motion_controller_slx_1.createSubscriber(&b_zeroDelimTopic[0], qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_slx::motion_c_SystemCore_setup_o0ajj
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[13];
  static const char_T b_zeroDelimTopic_0[13] = "/motor_state";

  // Start for MATLABSystem: '<S31>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S31>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  for (int32_T i = 0; i < 13; i++) {
    // Start for MATLABSystem: '<S31>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_motion_controller_slx_238.createSubscriber(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_slx::motion_contr_SystemCore_setup_o
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[17];
  static const char_T b_zeroDelimTopic_0[17] = "/Imu_data_filter";

  // Start for MATLABSystem: '<S7>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S7>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  for (int32_T i = 0; i < 17; i++) {
    // Start for MATLABSystem: '<S7>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_motion_controller_slx_369.createSubscriber(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_slx::motion_control_SystemCore_setup
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[22];
  static const char_T b_zeroDelimTopic_0[22] = "/t265_odometry_filter";

  // Start for MATLABSystem: '<S6>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S6>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  for (int32_T i = 0; i < 22; i++) {
    // Start for MATLABSystem: '<S6>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_motion_controller_slx_368.createSubscriber(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

// Model step function
void motion_controller_slx::step()
{
  int16_T tmp;
  boolean_T b_value;
  boolean_T b_varargout_1;
  boolean_T b_varargout_1_0;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_LogicalOperator_l;

  // MATLABSystem: '<S30>/SourceBlock'
  b_varargout_1 = Sub_motion_controller_slx_1.getLatestMessage
    (&motion_controller_slx_B.b_varargout_2_k);

  // Outputs for Enabled SubSystem: '<S30>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S33>/Enable'

  // Start for MATLABSystem: '<S30>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S33>/In1'
    motion_controller_slx_B.In1_me = motion_controller_slx_B.b_varargout_2_k;
  }

  // End of Outputs for SubSystem: '<S30>/Enabled Subsystem'

  // Logic: '<Root>/Logical Operator'
  rtb_LogicalOperator = (motion_controller_slx_B.In1_me.failsafe ||
    motion_controller_slx_B.In1_me.frame_lost);

  // MATLABSystem: '<S31>/SourceBlock'
  b_varargout_1_0 = Sub_motion_controller_slx_238.getLatestMessage
    (&motion_controller_slx_B.b_varargout_2);

  // Logic: '<S5>/Logical Operator' incorporates:
  //   MATLABSystem: '<S30>/SourceBlock'
  //   MATLABSystem: '<S31>/SourceBlock'
  //
  rtb_LogicalOperator_l = (b_varargout_1 && b_varargout_1_0);

  // Outputs for Enabled SubSystem: '<S31>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S34>/Enable'

  // Start for MATLABSystem: '<S31>/SourceBlock'
  if (b_varargout_1_0) {
    // SignalConversion generated from: '<S34>/In1'
    motion_controller_slx_B.In1 = motion_controller_slx_B.b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S31>/Enabled Subsystem'

  // Outputs for Iterator SubSystem: '<S5>/For Each Subsystem' incorporates:
  //   ForEach: '<S29>/For Each'

  for (motion_controller_slx_B.ForEach_itr = 0;
       motion_controller_slx_B.ForEach_itr < 16;
       motion_controller_slx_B.ForEach_itr++) {
    // ForEachSliceAssignment generated from: '<S29>/Out1' incorporates:
    //   ForEachSliceSelector generated from: '<S29>/In1'

    motion_controller_slx_B.ImpAsg_InsertedFor_Out1_at_[motion_controller_slx_B.ForEach_itr]
      =
      motion_controller_slx_B.In1.actuator_state[motion_controller_slx_B.ForEach_itr]
      .velocity;
  }

  // End of Outputs for SubSystem: '<S5>/For Each Subsystem'

  // MATLABSystem: '<S7>/SourceBlock'
  b_varargout_1 = Sub_motion_controller_slx_369.getLatestMessage
    (&motion_controller_slx_B.b_varargout_2_c);

  // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S9>/Enable'

  // Start for MATLABSystem: '<S7>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S9>/In1'
    motion_controller_slx_B.In1_m = motion_controller_slx_B.b_varargout_2_c;
  }

  // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'

  // MATLABSystem: '<S6>/SourceBlock'
  b_varargout_1_0 = Sub_motion_controller_slx_368.getLatestMessage
    (&motion_controller_slx_B.b_varargout_2_m);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S8>/Enable'

  // Start for MATLABSystem: '<S6>/SourceBlock'
  if (b_varargout_1_0) {
    // SignalConversion generated from: '<S8>/In1'
    motion_controller_slx_B.In1_g = motion_controller_slx_B.b_varargout_2_m;
  }

  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'

  // Outputs for Atomic SubSystem: '<Root>/controller'
  // MATLABSystem: '<S19>/Get Parameter4'
  ParamGet_motion_controller_slx_298.getParameter
    (&motion_controller_slx_B.b_value_b);

  // MATLABSystem: '<S19>/Get Parameter2'
  ParamGet_motion_controller_slx_301.getParameter(&b_value);

  // MATLABSystem: '<S19>/Get Parameter3'
  ParamGet_motion_controller_slx_194.getParameter
    (&motion_controller_slx_B.b_value_p);

  // Switch: '<S19>/Switch' incorporates:
  //   MATLABSystem: '<S19>/Get Parameter2'
  //   SignalConversion generated from: '<S5>/Bus Selector'

  if (b_value) {
    tmp = motion_controller_slx_B.In1_me.mapped_channels[2];
  } else {
    tmp = motion_controller_slx_B.In1_me.mapped_channels[1];
  }

  // Product: '<S19>/Product1' incorporates:
  //   Constant: '<S19>/Constant2'
  //   Gain: '<S19>/Gain1'
  //   MATLABSystem: '<S19>/Get Parameter3'
  //   Sum: '<S19>/Add1'
  //   Switch: '<S19>/Switch'

  motion_controller_slx_B.b_value_p *= (static_cast<real_T>(tmp) -
    motion_controller_slx_P.Constant2_Value_f) *
    motion_controller_slx_P.Gain1_Gain;

  // Chart: '<S19>/Chart2' incorporates:
  //   MATLABSystem: '<S19>/Get Parameter4'

  if (motion_controller_slx_DW.is_active_c6_motion_controller_ == 0U) {
    motion_controller_slx_DW.is_active_c6_motion_controller_ = 1U;
    motion_controller_slx_B.out = 0.0;
  } else {
    motion_controller_slx_B.direction = motion_controller_slx_B.b_value_p -
      motion_controller_slx_B.out;
    if (fabs(motion_controller_slx_B.direction) < 0.01 *
        motion_controller_slx_B.b_value_b) {
      motion_controller_slx_B.out = motion_controller_slx_B.b_value_p;
    } else if (motion_controller_slx_B.b_value_b == 0.0) {
      motion_controller_slx_B.out = motion_controller_slx_B.b_value_p;
    } else {
      if (rtIsNaN(motion_controller_slx_B.direction)) {
        motion_controller_slx_B.direction = (rtNaN);
      } else if (motion_controller_slx_B.direction < 0.0) {
        motion_controller_slx_B.direction = -1.0;
      } else {
        motion_controller_slx_B.direction = (motion_controller_slx_B.direction >
          0.0);
      }

      motion_controller_slx_B.out += motion_controller_slx_B.direction *
        motion_controller_slx_B.b_value_b * 0.01;
    }
  }

  // End of Chart: '<S19>/Chart2'

  // MATLABSystem: '<S19>/Get Parameter5'
  ParamGet_motion_controller_slx_329.getParameter(&b_value);

  // Gain: '<S19>/Gain2' incorporates:
  //   Constant: '<S19>/Constant'
  //   Gain: '<S19>/Gain'
  //   SignalConversion generated from: '<S5>/Bus Selector'
  //   Sum: '<S19>/Add'

  motion_controller_slx_B.Gain2 = (static_cast<real_T>
    (motion_controller_slx_B.In1_me.mapped_channels[0]) -
    motion_controller_slx_P.Constant_Value_ff) *
    motion_controller_slx_P.Gain_Gain_f * motion_controller_slx_P.Gain2_Gain;

  // MATLABSystem: '<S19>/Get Parameter1'
  ParamGet_motion_controller_slx_317.getParameter
    (&motion_controller_slx_B.b_value_b);

  // MATLABSystem: '<S19>/Get Parameter'
  ParamGet_motion_controller_slx_316.getParameter
    (&motion_controller_slx_B.b_value_p);

  // MATLAB Function: '<S19>/MATLAB Function' incorporates:
  //   MATLABSystem: '<S19>/Get Parameter'
  //   MATLABSystem: '<S19>/Get Parameter1'
  //   MATLABSystem: '<S19>/Get Parameter5'

  if (b_value) {
    motion_controller_slx_B.rate = motion_controller_slx_B.b_value_b / 180.0 *
      3.1415926535897931 * 0.01 / 2.0;
  } else {
    motion_controller_slx_B.rate = motion_controller_slx_B.b_value_b / 180.0 *
      3.1415926535897931 * 0.01;
  }

  motion_controller_slx_B.direction = motion_controller_slx_B.Gain2 -
    motion_controller_slx_DW.angle_out;
  if (fabs(motion_controller_slx_B.direction) < motion_controller_slx_B.rate) {
    motion_controller_slx_DW.angle_out = motion_controller_slx_B.Gain2;
  } else if (motion_controller_slx_B.b_value_b <= 0.0) {
    motion_controller_slx_DW.angle_out = motion_controller_slx_B.Gain2;
  } else {
    if (rtIsNaN(motion_controller_slx_B.direction)) {
      motion_controller_slx_B.direction = (rtNaN);
    } else if (motion_controller_slx_B.direction < 0.0) {
      motion_controller_slx_B.direction = -1.0;
    } else {
      motion_controller_slx_B.direction = (motion_controller_slx_B.direction >
        0.0);
    }

    motion_controller_slx_DW.angle_out += motion_controller_slx_B.direction *
      motion_controller_slx_B.rate / motion_controller_slx_B.b_value_p;
  }

  if (b_value) {
    motion_controller_slx_B.b_value_b = fabs(motion_controller_slx_DW.angle_out);
    if (rtIsNaN(motion_controller_slx_DW.angle_out)) {
      motion_controller_slx_B.direction = (rtNaN);
    } else if (motion_controller_slx_DW.angle_out < 0.0) {
      motion_controller_slx_B.direction = -1.0;
    } else {
      motion_controller_slx_B.direction = (motion_controller_slx_DW.angle_out >
        0.0);
    }

    if (!(motion_controller_slx_B.b_value_b <= 0.5)) {
      motion_controller_slx_B.b_value_b = 0.5;
    }

    motion_controller_slx_B.b_value_b = motion_controller_slx_B.direction *
      motion_controller_slx_B.b_value_b * 2.0;
    motion_controller_slx_B.direction = fabs(motion_controller_slx_DW.angle_out);
    if (motion_controller_slx_B.direction > 0.5) {
      if (rtIsNaN(motion_controller_slx_DW.angle_out)) {
        motion_controller_slx_B.rate = (rtNaN);
      } else if (motion_controller_slx_DW.angle_out < 0.0) {
        motion_controller_slx_B.rate = -1.0;
      } else {
        motion_controller_slx_B.rate = (motion_controller_slx_DW.angle_out > 0.0);
      }

      motion_controller_slx_B.direction = (motion_controller_slx_B.direction -
        0.5) * -motion_controller_slx_B.rate * 2.0;
    } else {
      motion_controller_slx_B.direction = 0.0;
    }
  } else {
    motion_controller_slx_B.b_value_b = motion_controller_slx_DW.angle_out;
    motion_controller_slx_B.direction = 0.0;
  }

  motion_controller_slx_B.b_value_b *= motion_controller_slx_B.b_value_p;
  motion_controller_slx_B.b_value_p *= motion_controller_slx_B.direction;

  // End of MATLAB Function: '<S19>/MATLAB Function'

  // MATLABSystem: '<S4>/Get Parameter1'
  ParamGet_motion_controller_slx_217.getParameter
    (&motion_controller_slx_B.GetParameter1);

  // Chart: '<S4>/Chart' incorporates:
  //   Logic: '<S2>/Logical Operator'
  //   MATLABSystem: '<S6>/SourceBlock'
  //   MATLABSystem: '<S7>/SourceBlock'
  //   Product: '<S4>/Product'
  //   SignalConversion generated from: '<S5>/Bus Selector'
  //
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
      if ((motion_controller_slx_B.In1_me.mapped_channels[3] == 1000) &&
          (!rtb_LogicalOperator) && rtb_LogicalOperator_l) {
        motion_controller_slx_DW.is_Is_ready = motion_contro_IN_velocity_mode1;
        motion_controller_slx_DW.ready = true;
        motion_controller_slx_DW.check = 1.0;
        motion_controller_slx_DW.sum = 0.0;
        motion_controller_slx_DW.counter = 0.0;
      }

      // case IN_velocity_mode1:
    } else if ((motion_controller_slx_B.In1_me.mapped_channels[3] != 1000) ||
               rtb_LogicalOperator || (motion_controller_slx_DW.check == 0.0)) {
      motion_controller_slx_DW.is_Is_ready = motion_controller_slx_IN_Ini;
      motion_controller_slx_DW.check = 1.0;
      motion_controller_slx_DW.ready = false;
    } else {
      motion_controller_slx_DW.counter++;
      motion_controller_slx_DW.sum += static_cast<real_T>(rtb_LogicalOperator_l);
      if (rtIsNaN(motion_controller_slx_DW.counter)) {
        motion_controller_slx_B.direction = (rtNaN);
      } else if (rtIsInf(motion_controller_slx_DW.counter)) {
        motion_controller_slx_B.direction = (rtNaN);
      } else if (motion_controller_slx_DW.counter == 0.0) {
        motion_controller_slx_B.direction = 0.0;
      } else {
        motion_controller_slx_B.direction = fmod
          (motion_controller_slx_DW.counter, 20.0);
        if (motion_controller_slx_B.direction == 0.0) {
          motion_controller_slx_B.direction = 0.0;
        } else if (motion_controller_slx_DW.counter < 0.0) {
          motion_controller_slx_B.direction += 20.0;
        }
      }

      if (motion_controller_slx_B.direction == 0.0) {
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
      if ((motion_controller_slx_B.In1_me.mapped_channels[4] != 1000) ||
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
        if (motion_controller_slx_B.out >= 0.0) {
          motion_controller_slx_DW.is_effort_mode =
            motion_controller_sl_IN_forward;
          motion_controller_slx_B.spd_cmd[0] = 0.0;
          motion_controller_slx_B.spd_cmd[1] = 0.0;
          motion_controller_slx_B.spd_cmd[2] = 0.0;
          motion_controller_slx_B.spd_cmd[3] = 0.0;
        } else {
          motion_controller_slx_B.direction = 1.5 * fabs
            (motion_controller_slx_B.out);
          motion_controller_slx_B.rate =
            (((motion_controller_slx_B.ImpAsg_InsertedFor_Out1_at_[0] +
               motion_controller_slx_B.ImpAsg_InsertedFor_Out1_at_[1]) +
              motion_controller_slx_B.ImpAsg_InsertedFor_Out1_at_[2]) +
             motion_controller_slx_B.ImpAsg_InsertedFor_Out1_at_[3]) / 4.0;
          if (fabs(motion_controller_slx_B.rate) < 0.5) {
            motion_controller_slx_B.mode = 1;
            motion_controller_slx_B.spd_cmd[0] = 0.0;
            motion_controller_slx_B.spd_cmd[1] = 0.0;
            motion_controller_slx_B.spd_cmd[2] = 0.0;
            motion_controller_slx_B.spd_cmd[3] = 0.0;
            motion_controller_slx_B.direction = 0.0;
          } else if (motion_controller_slx_B.rate > 0.5) {
            motion_controller_slx_B.direction =
              -motion_controller_slx_B.direction;
            motion_controller_slx_B.mode = 2;
          } else if (motion_controller_slx_B.rate < -0.5) {
            motion_controller_slx_B.mode = 2;
          }

          motion_controller__get_angle_4w(motion_controller_slx_B.b_value_b,
            motion_controller_slx_B.b_value_p, motion_controller_slx_B.angle_cmd);
          motion_controller_slx_B.effort_cmd[0] =
            motion_controller_slx_B.direction * 1.6;
          motion_controller_slx_B.b_value_p = -motion_controller_slx_B.direction
            * 1.6;
          motion_controller_slx_B.effort_cmd[1] =
            motion_controller_slx_B.b_value_p;
          motion_controller_slx_B.effort_cmd[2] =
            motion_controller_slx_B.b_value_p;
          motion_controller_slx_B.effort_cmd[3] =
            motion_controller_slx_B.direction * 1.6;
        }

        // case IN_forward:
      } else if (motion_controller_slx_B.out < -0.01) {
        motion_controller_slx_DW.is_effort_mode =
          motion_controller_sl_IN_braking;
        motion_controller_slx_B.spd_cmd[0] = 0.0;
        motion_controller_slx_B.spd_cmd[1] = 0.0;
        motion_controller_slx_B.spd_cmd[2] = 0.0;
        motion_controller_slx_B.spd_cmd[3] = 0.0;
      } else {
        motion_controller__get_angle_4w(motion_controller_slx_B.b_value_b,
          motion_controller_slx_B.b_value_p, motion_controller_slx_B.angle_cmd);
        motion_controller_slx_B.rtb_ImpAsg_InsertedFor_Out1_a_c[0] =
          motion_controller_slx_B.ImpAsg_InsertedFor_Out1_at_[0] / 0.07;
        motion_controller_slx_B.rtb_ImpAsg_InsertedFor_Out1_a_c[1] =
          motion_controller_slx_B.ImpAsg_InsertedFor_Out1_at_[1] / 0.07;
        motion_controller_slx_B.rtb_ImpAsg_InsertedFor_Out1_a_c[2] =
          motion_controller_slx_B.ImpAsg_InsertedFor_Out1_at_[2] / 0.07;
        motion_controller_slx_B.rtb_ImpAsg_InsertedFor_Out1_a_c[3] =
          motion_controller_slx_B.ImpAsg_InsertedFor_Out1_at_[3] / 0.07;
        if (motion_controller_slx_B.In1_me.mapped_channels[6] == 1000) {
          motion_controller_slx_B.direction = -0.5 * motion_controller_slx_B.out;
        } else {
          motion_controller_slx_B.direction = motion_controller_slx_B.out;
        }

        motion_controller_sl_get_effort(motion_controller_slx_B.direction,
          motion_controller_slx_B.In1_g.twist.twist.linear.x * static_cast<
          real_T>(b_varargout_1_0 && b_varargout_1),
          motion_controller_slx_B.In1_m.linear_acceleration.x,
          motion_controller_slx_B.rtb_ImpAsg_InsertedFor_Out1_a_c,
          motion_controller_slx_B.effort_cmd);
        motion_controller_slx_B.mode = 2;
      }
      break;

     case motion_controller_slx_IN_hold:
      if ((motion_controller_slx_B.In1_me.mapped_channels[4] != 1000) ||
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
      } else if ((motion_controller_slx_B.In1_me.mapped_channels[6] == 1000) &&
                 (motion_controller_slx_B.In1_me.mapped_channels[4] == 1000)) {
        motion_controller_slx_DW.is_cmd = motion_controlle_IN_effort_mode;
        motion_controller_slx_DW.is_effort_mode =
          motion_controller_sl_IN_forward;
        motion_controller_slx_B.spd_cmd[0] = 0.0;
        motion_controller_slx_B.spd_cmd[1] = 0.0;
        motion_controller_slx_B.spd_cmd[2] = 0.0;
        motion_controller_slx_B.spd_cmd[3] = 0.0;
      } else if (motion_controller_slx_B.In1_me.mapped_channels[4] == 1000) {
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
        motion_controller__get_angle_4w(motion_controller_slx_B.b_value_b,
          motion_controller_slx_B.b_value_p, motion_controller_slx_B.angle_cmd);
        motion_controller_slx_get_spd(motion_controller_slx_B.b_value_b,
          motion_controller_slx_B.out, motion_controller_slx_B.spd_cmd);
        motion_controller_slx_B.mode = 1;
      }
      break;
    }
  }

  // End of Chart: '<S4>/Chart'
  // End of Outputs for SubSystem: '<Root>/controller'

  // Outputs for Enabled SubSystem: '<Root>/cmd_pub' incorporates:
  //   EnablePort: '<S3>/Enable'

  // RelationalOperator: '<S1>/Compare' incorporates:
  //   Constant: '<S1>/Constant'
  //   SignalConversion generated from: '<S5>/Bus Selector'

  if (motion_controller_slx_B.In1_me.mapped_channels[5] ==
      motion_controller_slx_P.CompareToConstant_const) {
    motion_controller_s_CurrentTime(&motion_controller_slx_B.CurrentTime1);

    // BusAssignment: '<S3>/Bus Assignment1' incorporates:
    //   Constant: '<S11>/Constant'

    motion_controller_slx_B.BusAssignment1 =
      motion_controller_slx_P.Constant_Value_f3;

    // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem1' incorporates:
    //   ForEach: '<S13>/For Each'

    for (motion_controller_slx_B.ForEach_itr_j_c = 0;
         motion_controller_slx_B.ForEach_itr_j_c < 4;
         motion_controller_slx_B.ForEach_itr_j_c++) {
      // Saturate: '<S3>/Saturation2'
      motion_controller_slx_B.b_value_b =
        motion_controller_slx_B.effort_cmd[motion_controller_slx_B.ForEach_itr_j_c];

      // Saturate: '<S3>/Saturation1'
      motion_controller_slx_B.b_value_p =
        motion_controller_slx_B.spd_cmd[motion_controller_slx_B.ForEach_itr_j_c];

      // ForEachSliceAssignment generated from: '<S13>/actuaor_command' incorporates:
      //   BusAssignment: '<S13>/Bus Assignment1'
      //   Constant: '<S17>/Constant'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[motion_controller_slx_B.ForEach_itr_j_c]
        = motion_controller_slx_P.CoreSubsys_p.Constant_Value;

      // Saturate: '<S3>/Saturation2'
      if (motion_controller_slx_B.b_value_b >
          motion_controller_slx_P.Saturation2_UpperSat) {
        // BusAssignment: '<S13>/Bus Assignment1' incorporates:
        //   ForEachSliceAssignment generated from: '<S13>/actuaor_command'

        motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[motion_controller_slx_B.ForEach_itr_j_c]
          .effort = motion_controller_slx_P.Saturation2_UpperSat;
      } else if (motion_controller_slx_B.b_value_b <
                 motion_controller_slx_P.Saturation2_LowerSat) {
        // BusAssignment: '<S13>/Bus Assignment1' incorporates:
        //   ForEachSliceAssignment generated from: '<S13>/actuaor_command'

        motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[motion_controller_slx_B.ForEach_itr_j_c]
          .effort = motion_controller_slx_P.Saturation2_LowerSat;
      } else {
        // BusAssignment: '<S13>/Bus Assignment1' incorporates:
        //   ForEachSliceAssignment generated from: '<S13>/actuaor_command'

        motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[motion_controller_slx_B.ForEach_itr_j_c]
          .effort = motion_controller_slx_B.b_value_b;
      }

      // Saturate: '<S3>/Saturation1'
      if (motion_controller_slx_B.b_value_p >
          motion_controller_slx_P.Saturation1_UpperSat) {
        // BusAssignment: '<S13>/Bus Assignment1' incorporates:
        //   ForEachSliceAssignment generated from: '<S13>/actuaor_command'

        motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[motion_controller_slx_B.ForEach_itr_j_c]
          .velocity = motion_controller_slx_P.Saturation1_UpperSat;
      } else if (motion_controller_slx_B.b_value_p <
                 motion_controller_slx_P.Saturation1_LowerSat) {
        // BusAssignment: '<S13>/Bus Assignment1' incorporates:
        //   ForEachSliceAssignment generated from: '<S13>/actuaor_command'

        motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[motion_controller_slx_B.ForEach_itr_j_c]
          .velocity = motion_controller_slx_P.Saturation1_LowerSat;
      } else {
        // BusAssignment: '<S13>/Bus Assignment1' incorporates:
        //   ForEachSliceAssignment generated from: '<S13>/actuaor_command'

        motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[motion_controller_slx_B.ForEach_itr_j_c]
          .velocity = motion_controller_slx_B.b_value_p;
      }
    }

    // End of Outputs for SubSystem: '<S3>/For Each Subsystem1'

    // BusAssignment: '<S3>/Bus Assignment1' incorporates:
    //   DataTypeConversion: '<S3>/Data Type Conversion'

    motion_controller_slx_B.BusAssignment1.header.stamp =
      motion_controller_slx_B.CurrentTime1.CurrentTime;
    motion_controller_slx_B.BusAssignment1.drive_mode =
      motion_controller_slx_B.mode;
    memcpy(&motion_controller_slx_B.BusAssignment1.actuator_command[0],
           &motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[0], sizeof
           (SL_Bus_custom_interfaces_Actuator) << 2U);

    // MATLABSystem: '<S14>/SinkBlock'
    Pub_motion_controller_slx_4.publish(&motion_controller_slx_B.BusAssignment1);
    motion_controller_s_CurrentTime(&motion_controller_slx_B.CurrentTime);

    // BusAssignment: '<S3>/Bus Assignment2' incorporates:
    //   Constant: '<S10>/Constant'

    motion_controller_slx_B.BusAssignment1 =
      motion_controller_slx_P.Constant_Value_i;

    // Outputs for Iterator SubSystem: '<S3>/For Each Subsystem' incorporates:
    //   ForEach: '<S12>/For Each'

    // Saturate: '<S3>/Saturation'
    for (motion_controller_slx_B.ForEach_itr_p_f = 0;
         motion_controller_slx_B.ForEach_itr_p_f < 4;
         motion_controller_slx_B.ForEach_itr_p_f++) {
      motion_controller_slx_B.b_value_b =
        motion_controller_slx_B.angle_cmd[motion_controller_slx_B.ForEach_itr_p_f];

      // ForEachSliceAssignment generated from: '<S12>/actuaor_command' incorporates:
      //   BusAssignment: '<S12>/Bus Assignment1'
      //   Constant: '<S16>/Constant'

      motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[motion_controller_slx_B.ForEach_itr_p_f]
        = motion_controller_slx_P.CoreSubsys.Constant_Value;
      if (motion_controller_slx_B.b_value_b >
          motion_controller_slx_P.Saturation_UpperSat) {
        // BusAssignment: '<S12>/Bus Assignment1' incorporates:
        //   ForEachSliceAssignment generated from: '<S12>/actuaor_command'

        motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[motion_controller_slx_B.ForEach_itr_p_f]
          .position = motion_controller_slx_P.Saturation_UpperSat;
      } else if (motion_controller_slx_B.b_value_b <
                 motion_controller_slx_P.Saturation_LowerSat) {
        // BusAssignment: '<S12>/Bus Assignment1' incorporates:
        //   ForEachSliceAssignment generated from: '<S12>/actuaor_command'

        motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[motion_controller_slx_B.ForEach_itr_p_f]
          .position = motion_controller_slx_P.Saturation_LowerSat;
      } else {
        // BusAssignment: '<S12>/Bus Assignment1' incorporates:
        //   ForEachSliceAssignment generated from: '<S12>/actuaor_command'

        motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[motion_controller_slx_B.ForEach_itr_p_f]
          .position = motion_controller_slx_B.b_value_b;
      }
    }

    // End of Saturate: '<S3>/Saturation'
    // End of Outputs for SubSystem: '<S3>/For Each Subsystem'

    // BusAssignment: '<S3>/Bus Assignment2'
    motion_controller_slx_B.BusAssignment1.header.stamp =
      motion_controller_slx_B.CurrentTime.CurrentTime;
    memcpy(&motion_controller_slx_B.BusAssignment1.actuator_command[0],
           &motion_controller_slx_B.ImpAsg_InsertedFor_actuaor_[0], sizeof
           (SL_Bus_custom_interfaces_Actuator) << 2U);

    // MATLABSystem: '<S15>/SinkBlock'
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
    static const char_T prmName_2[4] = "FWS";
    static const char_T prmName_3[15] = "steer_rate_dps";
    static const char_T prmName_4[9] = "angleMax";
    static const char_T prmName_5[10] = "ackermann";

    // SystemInitialize for Enabled SubSystem: '<S30>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S33>/In1' incorporates:
    //   Outport: '<S33>/Out1'

    motion_controller_slx_B.In1_me = motion_controller_slx_P.Out1_Y0_f;

    // End of SystemInitialize for SubSystem: '<S30>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S31>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S34>/In1' incorporates:
    //   Outport: '<S34>/Out1'

    motion_controller_slx_B.In1 = motion_controller_slx_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S31>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S9>/In1' incorporates:
    //   Outport: '<S9>/Out1'

    motion_controller_slx_B.In1_m = motion_controller_slx_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S8>/In1' incorporates:
    //   Outport: '<S8>/Out1'

    motion_controller_slx_B.In1_g = motion_controller_slx_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // SystemInitialize for Atomic SubSystem: '<Root>/controller'
    // SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S4>/get_effort' incorporates:
    //   SubSystem: '<S4>/get_effort'

    motion_controll_get_effort_Init();

    // End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S4>/get_effort' 

    // Start for MATLABSystem: '<S19>/Get Parameter4'
    motion_controller_slx_DW.obj_e.matlabCodegenIsDeleted = false;
    motion_controller_slx_DW.obj_e.isInitialized = 1;
    ParamGet_motion_controller_slx_298.initParam(&prmName[0]);
    ParamGet_motion_controller_slx_298.setInitialValue(0.0);
    motion_controller_slx_DW.obj_e.isSetupComplete = true;

    // Start for MATLABSystem: '<S19>/Get Parameter2'
    motion_controller_slx_DW.obj_c.matlabCodegenIsDeleted = false;
    motion_controller_slx_DW.obj_c.isInitialized = 1;
    ParamGet_motion_controller_slx_301.initParam(&prmName_0[0]);
    ParamGet_motion_controller_slx_301.setInitialValue(false);
    motion_controller_slx_DW.obj_c.isSetupComplete = true;

    // Start for MATLABSystem: '<S19>/Get Parameter3'
    motion_controller_slx_DW.obj_l4.matlabCodegenIsDeleted = false;
    motion_controller_slx_DW.obj_l4.isInitialized = 1;
    ParamGet_motion_controller_slx_194.initParam(&prmName_1[0]);
    ParamGet_motion_controller_slx_194.setInitialValue(1.0);
    motion_controller_slx_DW.obj_l4.isSetupComplete = true;

    // Start for MATLABSystem: '<S19>/Get Parameter5'
    motion_controller_slx_DW.obj_g.matlabCodegenIsDeleted = false;
    motion_controller_slx_DW.obj_g.isInitialized = 1;
    ParamGet_motion_controller_slx_329.initParam(&prmName_2[0]);
    ParamGet_motion_controller_slx_329.setInitialValue(true);
    motion_controller_slx_DW.obj_g.isSetupComplete = true;

    // Start for MATLABSystem: '<S19>/Get Parameter1'
    motion_controller_slx_DW.obj_o.matlabCodegenIsDeleted = false;
    motion_controller_slx_DW.obj_o.isInitialized = 1;
    ParamGet_motion_controller_slx_317.initParam(&prmName_3[0]);
    ParamGet_motion_controller_slx_317.setInitialValue(0.0);
    motion_controller_slx_DW.obj_o.isSetupComplete = true;

    // Start for MATLABSystem: '<S19>/Get Parameter'
    motion_controller_slx_DW.obj_m.matlabCodegenIsDeleted = false;
    motion_controller_slx_DW.obj_m.isInitialized = 1;
    ParamGet_motion_controller_slx_316.initParam(&prmName_4[0]);
    ParamGet_motion_controller_slx_316.setInitialValue(0.515);
    motion_controller_slx_DW.obj_m.isSetupComplete = true;

    // Start for MATLABSystem: '<S4>/Get Parameter1'
    motion_controller_slx_DW.obj_f.matlabCodegenIsDeleted = false;
    motion_controller_slx_DW.obj_f.isInitialized = 1;
    ParamGet_motion_controller_slx_217.initParam(&prmName_5[0]);
    ParamGet_motion_controller_slx_217.setInitialValue(1.0);
    motion_controller_slx_DW.obj_f.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<Root>/controller'

    // SystemInitialize for Enabled SubSystem: '<Root>/cmd_pub'
    motion_control_CurrentTime_Init(&motion_controller_slx_DW.CurrentTime1);

    // Start for MATLABSystem: '<S14>/SinkBlock'
    motion_cont_SystemCore_setup_o0(&motion_controller_slx_DW.obj_b);
    motion_control_CurrentTime_Init(&motion_controller_slx_DW.CurrentTime);

    // Start for MATLABSystem: '<S15>/SinkBlock'
    motion_con_SystemCore_setup_o0a(&motion_controller_slx_DW.obj_ca);

    // End of SystemInitialize for SubSystem: '<Root>/cmd_pub'

    // Start for MATLABSystem: '<S30>/SourceBlock'
    motion_co_SystemCore_setup_o0aj(&motion_controller_slx_DW.obj_n);

    // Start for MATLABSystem: '<S31>/SourceBlock'
    motion_c_SystemCore_setup_o0ajj(&motion_controller_slx_DW.obj_mo);

    // Start for MATLABSystem: '<S7>/SourceBlock'
    motion_contr_SystemCore_setup_o(&motion_controller_slx_DW.obj_ed);

    // Start for MATLABSystem: '<S6>/SourceBlock'
    motion_control_SystemCore_setup(&motion_controller_slx_DW.obj_os);
  }
}

// Model terminate function
void motion_controller_slx::terminate()
{
  // Terminate for MATLABSystem: '<S30>/SourceBlock'
  if (!motion_controller_slx_DW.obj_n.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S30>/SourceBlock'

  // Terminate for MATLABSystem: '<S31>/SourceBlock'
  if (!motion_controller_slx_DW.obj_mo.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_mo.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S31>/SourceBlock'

  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  if (!motion_controller_slx_DW.obj_ed.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_ed.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/SourceBlock'

  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!motion_controller_slx_DW.obj_os.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_os.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'

  // Terminate for Atomic SubSystem: '<Root>/controller'
  // Terminate for MATLABSystem: '<S19>/Get Parameter4'
  if (!motion_controller_slx_DW.obj_e.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S19>/Get Parameter4'

  // Terminate for MATLABSystem: '<S19>/Get Parameter2'
  if (!motion_controller_slx_DW.obj_c.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S19>/Get Parameter2'

  // Terminate for MATLABSystem: '<S19>/Get Parameter3'
  if (!motion_controller_slx_DW.obj_l4.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_l4.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S19>/Get Parameter3'

  // Terminate for MATLABSystem: '<S19>/Get Parameter5'
  if (!motion_controller_slx_DW.obj_g.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S19>/Get Parameter5'

  // Terminate for MATLABSystem: '<S19>/Get Parameter1'
  if (!motion_controller_slx_DW.obj_o.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S19>/Get Parameter1'

  // Terminate for MATLABSystem: '<S19>/Get Parameter'
  if (!motion_controller_slx_DW.obj_m.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S19>/Get Parameter'

  // Terminate for MATLABSystem: '<S4>/Get Parameter1'
  if (!motion_controller_slx_DW.obj_f.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/Get Parameter1'

  // Terminate for S-Function (sfun_private_function_caller) generated from: '<S4>/get_effort' incorporates:
  //   SubSystem: '<S4>/get_effort'

  motion_controll_get_effort_Term();

  // End of Terminate for S-Function (sfun_private_function_caller) generated from: '<S4>/get_effort' 
  // End of Terminate for SubSystem: '<Root>/controller'

  // Terminate for Enabled SubSystem: '<Root>/cmd_pub'
  motion_control_CurrentTime_Term(&motion_controller_slx_DW.CurrentTime1);

  // Terminate for MATLABSystem: '<S14>/SinkBlock'
  if (!motion_controller_slx_DW.obj_b.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/SinkBlock'
  motion_control_CurrentTime_Term(&motion_controller_slx_DW.CurrentTime);

  // Terminate for MATLABSystem: '<S15>/SinkBlock'
  if (!motion_controller_slx_DW.obj_ca.matlabCodegenIsDeleted) {
    motion_controller_slx_DW.obj_ca.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S15>/SinkBlock'
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
