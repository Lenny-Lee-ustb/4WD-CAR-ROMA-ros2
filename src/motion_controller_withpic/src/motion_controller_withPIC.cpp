//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: motion_controller_withPIC.cpp
//
// Code generated for Simulink model 'motion_controller_withPIC'.
//
// Model version                  : 2.369
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Thu Jan  9 15:54:26 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Linux 64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "motion_controller_withPIC.h"
#include "rtwtypes.h"
#include "motion_controller_withPIC_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <math.h>
#include "rt_atan2d_snf.h"
#include <string.h>
#include <emmintrin.h>
#include "rt_roundd_snf.h"
#include "rmw/qos_profiles.h"
#include <stddef.h>
#include "strcmp_1LovgLAH.h"
#include "countsort_Ormz6pKD.h"
#include "xgemv_bQMFK39u.h"
#include "xgemv_DWEvxrPL.h"
#include "xgemv_L5SThEQW.h"
#include "countsort_JblpZJs7.h"
#include "xgemv_WOwAYNtc.h"
#include "xgemv_szX0RER2.h"
#include "xgemv_CxqfdDRY.h"
#include "div_nde_s32_floor.h"

// Named constants for Chart: '<Root>/Chart'
const uint8_T motion_contr_IN_NO_ACTIVE_CHILD = 0U;
const uint8_T motion_controller_wi_IN_testing = 3U;
const uint8_T motion_controller_withPI_IN_ini = 1U;
const uint8_T motion_controller_with_IN_saver = 2U;

// Named constants for Chart: '<S9>/Chart'
const uint8_T motion_controller_wi_IN_running = 2U;

// Named constants for Chart: '<S15>/Chart'
const uint8_T motion_contro_IN_velocity_mode1 = 2U;
const uint8_T motion_control_IN_velocity_mode = 4U;
const uint8_T motion_controlle_IN_effort_mode = 2U;
const uint8_T motion_controller_wi_IN_braking = 1U;
const uint8_T motion_controller_wi_IN_forward = 2U;
const uint8_T motion_controller_withPI_IN_Ini = 1U;
const uint8_T motion_controller_withP_IN_hold = 3U;

// System initialize for atomic system:
void motion_controller_withPIC::motion_control_CurrentTime_Init
  (DW_CurrentTime_motion_control_T *localDW)
{
  // Start for MATLABSystem: '<S14>/Current Time'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void motion_controller_withPIC::motion_controller_w_CurrentTime
  (B_CurrentTime_motion_controll_T *localB)
{
  // MATLABSystem: '<S14>/Current Time'
  currentROS2TimeBus(&localB->CurrentTime);
}

// Termination for atomic system:
void motion_controller_withPIC::motion_control_CurrentTime_Term
  (DW_CurrentTime_motion_control_T *localDW)
{
  // Terminate for MATLABSystem: '<S14>/Current Time'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/Current Time'
}

// Output and update for Simulink Function: '<S15>/get_angle_4w'
void motion_controller_withPIC::motion_controller__get_angle_4w(real_T
  rtu_delta_f, real_T rtu_delta_r, real_T rty_angle_cmd[4]) const
{
  real_T deltaFR;
  real_T deltaRL;
  real_T deltaRR;

  // MATLAB Function: '<S48>/MATLAB Function' incorporates:
  //   SignalConversion generated from: '<S48>/ackermann_enable'
  //   SignalConversion generated from: '<S48>/delta_f'
  //   SignalConversion generated from: '<S48>/delta_r'

  if (motion_controller_withPIC_B.GetParameter1 == 1.0) {
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
    deltaRL_tmp = 2.0 * motion_controller_withPIC_P.L * deltaFL_tmp;
    deltaFR_tmp = (deltaFR * deltaFL_tmp - deltaRR * deltaRL) *
      motion_controller_withPIC_P.Tw;
    deltaFL_tmp = 2.0 * motion_controller_withPIC_P.L - deltaFR_tmp;

    // SignalConversion generated from: '<S48>/angle_cmd' incorporates:
    //   SignalConversion generated from: '<S48>/delta_f'
    //   SignalConversion generated from: '<S48>/delta_r'

    rty_angle_cmd[0] = atan(deltaRL_tmp / deltaFL_tmp) * deltaFR;
    deltaFR_tmp += 2.0 * motion_controller_withPIC_P.L;
    deltaFR *= atan(deltaRL_tmp / deltaFR_tmp);
    deltaRL_tmp = 2.0 * motion_controller_withPIC_P.L * deltaRL;
    deltaRL = atan(deltaRL_tmp / deltaFL_tmp) * deltaRR;
    deltaRR *= atan(deltaRL_tmp / deltaFR_tmp);
  } else {
    // SignalConversion generated from: '<S48>/angle_cmd' incorporates:
    //   SignalConversion generated from: '<S48>/delta_f'

    rty_angle_cmd[0] = rtu_delta_f;
    deltaFR = rtu_delta_f;
    deltaRR = rtu_delta_r;
    deltaRL = rtu_delta_r;
  }

  // SignalConversion generated from: '<S48>/angle_cmd' incorporates:
  //   MATLAB Function: '<S48>/MATLAB Function'

  rty_angle_cmd[1] = deltaFR;
  rty_angle_cmd[2] = deltaRR;
  rty_angle_cmd[3] = deltaRL;
}

// System initialize for Simulink Function: '<S15>/get_effort'
void motion_controller_withPIC::motion_controll_get_effort_Init()
{
  static const char_T prmName[10] = "effortMax";
  static const char_T prmName_0[10] = "tcsK1Sgne";
  static const char_T prmName_1[7] = "tcsK2e";
  static const char_T prmName_2[16] = "tcsKappaDesired";

  // Start for MATLABSystem: '<S49>/Get Parameter'
  motion_controller_withPIC_DW.obj_d.matlabCodegenIsDeleted = false;
  motion_controller_withPIC_DW.obj_d.isInitialized = 1;
  ParamGet_motion_controller_withPIC_202.initParam(&prmName[0]);
  ParamGet_motion_controller_withPIC_202.setInitialValue(0.6);
  motion_controller_withPIC_DW.obj_d.isSetupComplete = true;

  // Start for MATLABSystem: '<S49>/Get Parameter2'
  motion_controller_withPIC_DW.obj_ae.matlabCodegenIsDeleted = false;
  motion_controller_withPIC_DW.obj_ae.isInitialized = 1;
  ParamGet_motion_controller_withPIC_354.initParam(&prmName_0[0]);
  ParamGet_motion_controller_withPIC_354.setInitialValue(0.8);
  motion_controller_withPIC_DW.obj_ae.isSetupComplete = true;

  // Start for MATLABSystem: '<S49>/Get Parameter3'
  motion_controller_withPIC_DW.obj_lw.matlabCodegenIsDeleted = false;
  motion_controller_withPIC_DW.obj_lw.isInitialized = 1;
  ParamGet_motion_controller_withPIC_355.initParam(&prmName_1[0]);
  ParamGet_motion_controller_withPIC_355.setInitialValue(10.0);
  motion_controller_withPIC_DW.obj_lw.isSetupComplete = true;

  // Start for MATLABSystem: '<S49>/Get Parameter5'
  motion_controller_withPIC_DW.obj_a.matlabCodegenIsDeleted = false;
  motion_controller_withPIC_DW.obj_a.isInitialized = 1;
  ParamGet_motion_controller_withPIC_393.initParam(&prmName_2[0]);
  ParamGet_motion_controller_withPIC_393.setInitialValue(0.15);
  motion_controller_withPIC_DW.obj_a.isSetupComplete = true;
}

// Output and update for Simulink Function: '<S15>/get_effort'
void motion_controller_withPIC::motion_controller_wi_get_effort(real_T
  rtu_longdrive, real_T rtu_vx, real_T rtu_dvx, const real_T rtu_omega4w[4],
  real_T rty_effort_cmd[4])
{
  // MATLABSystem: '<S49>/Get Parameter'
  ParamGet_motion_controller_withPIC_202.getParameter
    (&motion_controller_withPIC_B.b_value);

  // MATLABSystem: '<S49>/Get Parameter2'
  ParamGet_motion_controller_withPIC_354.getParameter
    (&motion_controller_withPIC_B.b_value_c);

  // MATLABSystem: '<S49>/Get Parameter3'
  ParamGet_motion_controller_withPIC_355.getParameter
    (&motion_controller_withPIC_B.b_value_k);

  // MATLABSystem: '<S49>/Get Parameter5'
  ParamGet_motion_controller_withPIC_393.getParameter
    (&motion_controller_withPIC_B.b_value_cx);

  // MATLAB Function: '<S49>/MATLAB Function' incorporates:
  //   Constant: '<S49>/Constant4'
  //   MATLABSystem: '<S49>/Get Parameter'
  //   MATLABSystem: '<S49>/Get Parameter2'
  //   MATLABSystem: '<S49>/Get Parameter3'
  //   MATLABSystem: '<S49>/Get Parameter5'
  //   SignalConversion generated from: '<S49>/angle1'
  //   SignalConversion generated from: '<S49>/angle2'
  //   SignalConversion generated from: '<S49>/angle3'
  //   SignalConversion generated from: '<S49>/angle'

  motion_controller_withPIC_B.effort = rtu_longdrive *
    motion_controller_withPIC_B.b_value;
  if (motion_controller_withPIC_P.Constant4_Value != 0.0) {
    real_T sat_idx_0;
    real_T sat_idx_1;
    real_T sat_idx_2;
    real_T sat_idx_3;
    if (rtu_vx <= 0.0) {
      sat_idx_0 = 0.4;
      sat_idx_1 = 0.4;
      sat_idx_2 = 0.4;
      sat_idx_3 = 0.4;
    } else {
      real_T rtb_e_0;
      real_T tmp;
      real_T tmp_0;
      boolean_T tmp_1;
      motion_controller_withPIC_B.y_m = rtu_vx * rtu_vx;
      tmp_0 = motion_controller_withPIC_P.MATLABFunction_J * rtu_vx;
      motion_controller_withPIC_B.d =
        motion_controller_withPIC_P.MATLABFunction_Re * rtu_dvx;
      tmp = motion_controller_withPIC_P.MATLABFunction_Re *
        motion_controller_withPIC_P.MATLABFunction_Re *
        motion_controller_withPIC_P.Constant4_Value / tmp_0;
      rtb_e_0 = motion_controller_withPIC_B.b_value_cx - (rtu_omega4w[0] *
        motion_controller_withPIC_P.MATLABFunction_Re / rtu_vx - 1.0);
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

      sat_idx_3 = (((rtb_e_0 * motion_controller_withPIC_B.b_value_k +
                     motion_controller_withPIC_B.b_value_c * sat_idx_3) +
                    motion_controller_withPIC_B.d * rtu_omega4w[0] /
                    motion_controller_withPIC_B.y_m) + tmp) * tmp_0 /
        motion_controller_withPIC_P.MATLABFunction_Re;
      tmp_1 = !rtIsNaN(motion_controller_withPIC_B.b_value);
      if ((!(sat_idx_3 <= motion_controller_withPIC_B.b_value)) && tmp_1) {
        sat_idx_3 = motion_controller_withPIC_B.b_value;
      }

      if ((sat_idx_3 <= 0.0) || rtIsNaN(sat_idx_3)) {
        sat_idx_0 = 0.0;
      } else {
        sat_idx_0 = sat_idx_3;
      }

      rtb_e_0 = motion_controller_withPIC_B.b_value_cx - (rtu_omega4w[1] *
        motion_controller_withPIC_P.MATLABFunction_Re / rtu_vx - 1.0);
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

      sat_idx_3 = (((rtb_e_0 * motion_controller_withPIC_B.b_value_k +
                     motion_controller_withPIC_B.b_value_c * sat_idx_3) +
                    motion_controller_withPIC_B.d * rtu_omega4w[1] /
                    motion_controller_withPIC_B.y_m) + tmp) * tmp_0 /
        motion_controller_withPIC_P.MATLABFunction_Re;
      if ((!(sat_idx_3 <= motion_controller_withPIC_B.b_value)) && tmp_1) {
        sat_idx_3 = motion_controller_withPIC_B.b_value;
      }

      if ((sat_idx_3 <= 0.0) || rtIsNaN(sat_idx_3)) {
        sat_idx_1 = 0.0;
      } else {
        sat_idx_1 = sat_idx_3;
      }

      rtb_e_0 = motion_controller_withPIC_B.b_value_cx - (rtu_omega4w[2] *
        motion_controller_withPIC_P.MATLABFunction_Re / rtu_vx - 1.0);
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

      sat_idx_3 = (((rtb_e_0 * motion_controller_withPIC_B.b_value_k +
                     motion_controller_withPIC_B.b_value_c * sat_idx_3) +
                    motion_controller_withPIC_B.d * rtu_omega4w[2] /
                    motion_controller_withPIC_B.y_m) + tmp) * tmp_0 /
        motion_controller_withPIC_P.MATLABFunction_Re;
      if ((!(sat_idx_3 <= motion_controller_withPIC_B.b_value)) && tmp_1) {
        sat_idx_3 = motion_controller_withPIC_B.b_value;
      }

      if ((sat_idx_3 <= 0.0) || rtIsNaN(sat_idx_3)) {
        sat_idx_2 = 0.0;
      } else {
        sat_idx_2 = sat_idx_3;
      }

      rtb_e_0 = motion_controller_withPIC_B.b_value_cx - (rtu_omega4w[3] *
        motion_controller_withPIC_P.MATLABFunction_Re / rtu_vx - 1.0);
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

      sat_idx_3 = (((rtb_e_0 * motion_controller_withPIC_B.b_value_k +
                     motion_controller_withPIC_B.b_value_c * sat_idx_3) +
                    motion_controller_withPIC_B.d * rtu_omega4w[3] /
                    motion_controller_withPIC_B.y_m) + tmp) * tmp_0 /
        motion_controller_withPIC_P.MATLABFunction_Re;
      if ((!(sat_idx_3 <= motion_controller_withPIC_B.b_value)) && tmp_1) {
        sat_idx_3 = motion_controller_withPIC_B.b_value;
      }

      if ((sat_idx_3 <= 0.0) || rtIsNaN(sat_idx_3)) {
        sat_idx_3 = 0.0;
      }
    }

    if (motion_controller_withPIC_B.effort <= sat_idx_0) {
      // SignalConversion generated from: '<S49>/angle_cmd'
      rty_effort_cmd[0] = motion_controller_withPIC_B.effort;
    } else {
      // SignalConversion generated from: '<S49>/angle_cmd'
      rty_effort_cmd[0] = sat_idx_0;
    }

    if (motion_controller_withPIC_B.effort <= sat_idx_1) {
      // SignalConversion generated from: '<S49>/angle_cmd'
      rty_effort_cmd[1] = -motion_controller_withPIC_B.effort;
    } else {
      // SignalConversion generated from: '<S49>/angle_cmd'
      rty_effort_cmd[1] = -sat_idx_1;
    }

    if (motion_controller_withPIC_B.effort <= sat_idx_2) {
      // SignalConversion generated from: '<S49>/angle_cmd'
      rty_effort_cmd[2] = -motion_controller_withPIC_B.effort;
    } else {
      // SignalConversion generated from: '<S49>/angle_cmd'
      rty_effort_cmd[2] = -sat_idx_2;
    }

    if (motion_controller_withPIC_B.effort <= sat_idx_3) {
      // SignalConversion generated from: '<S49>/angle_cmd'
      rty_effort_cmd[3] = motion_controller_withPIC_B.effort;
    } else {
      // SignalConversion generated from: '<S49>/angle_cmd'
      rty_effort_cmd[3] = sat_idx_3;
    }
  } else {
    // SignalConversion generated from: '<S49>/angle_cmd'
    rty_effort_cmd[0] = motion_controller_withPIC_B.effort;
    rty_effort_cmd[1] = -motion_controller_withPIC_B.effort;
    rty_effort_cmd[2] = -motion_controller_withPIC_B.effort;
    rty_effort_cmd[3] = motion_controller_withPIC_B.effort;
  }

  // End of MATLAB Function: '<S49>/MATLAB Function'
}

// Termination for Simulink Function: '<S15>/get_effort'
void motion_controller_withPIC::motion_controll_get_effort_Term()
{
  // Terminate for MATLABSystem: '<S49>/Get Parameter'
  if (!motion_controller_withPIC_DW.obj_d.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S49>/Get Parameter'

  // Terminate for MATLABSystem: '<S49>/Get Parameter2'
  if (!motion_controller_withPIC_DW.obj_ae.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_ae.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S49>/Get Parameter2'

  // Terminate for MATLABSystem: '<S49>/Get Parameter3'
  if (!motion_controller_withPIC_DW.obj_lw.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_lw.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S49>/Get Parameter3'

  // Terminate for MATLABSystem: '<S49>/Get Parameter5'
  if (!motion_controller_withPIC_DW.obj_a.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S49>/Get Parameter5'
}

// Output and update for Simulink Function: '<S15>/get_spd'
void motion_controller_withPIC::motion_controller_withP_get_spd(real_T rtu_angle,
  real_T rtu_longdrive, real_T rty_spd_cmd[4]) const
{
  real_T b_x;
  real_T vFR;
  real_T vRL;
  real_T vRR;
  real_T vRR_tmp;

  // MATLAB Function: '<S50>/MATLAB Function' incorporates:
  //   Gain: '<S50>/Gain'
  //   SignalConversion generated from: '<S50>/ackermann_enable'
  //   SignalConversion generated from: '<S50>/angle'
  //   SignalConversion generated from: '<S50>/longdrive'

  if (motion_controller_withPIC_P.Gain_Gain_m *
      motion_controller_withPIC_B.GetParameter1 == 1.0) {
    vRL = motion_controller_withPIC_P.L / (tan(rtu_angle) + 1.0E-9);
    if (vRL >= 0.0) {
      b_x = rt_atan2d_snf(motion_controller_withPIC_P.L, vRL -
                          motion_controller_withPIC_P.Tw / 2.0);
      vFR = rt_atan2d_snf(motion_controller_withPIC_P.L,
                          motion_controller_withPIC_P.Tw / 2.0 + vRL);
    } else {
      b_x = rt_atan2d_snf(motion_controller_withPIC_P.L, vRL -
                          motion_controller_withPIC_P.Tw / 2.0) -
        3.1415926535897931;
      vFR = rt_atan2d_snf(motion_controller_withPIC_P.L,
                          motion_controller_withPIC_P.Tw / 2.0 + vRL) -
        3.1415926535897931;
    }

    vRR_tmp = cos(asin(motion_controller_withPIC_P.b / vRL));
    vRR = (motion_controller_withPIC_P.Tw / 2.0 + vRL) / vRL * rtu_longdrive *
      vRR_tmp;
    vRL = (vRL - motion_controller_withPIC_P.Tw / 2.0) / vRL * rtu_longdrive *
      vRR_tmp;
    vFR = vRR / cos(vFR);

    // SignalConversion generated from: '<S50>/spd_cmd' incorporates:
    //   SignalConversion generated from: '<S50>/angle'
    //   SignalConversion generated from: '<S50>/longdrive'

    rty_spd_cmd[0] = vRL / cos(b_x);
  } else {
    // SignalConversion generated from: '<S50>/spd_cmd' incorporates:
    //   SignalConversion generated from: '<S50>/longdrive'

    rty_spd_cmd[0] = rtu_longdrive;
    vFR = rtu_longdrive;
    vRL = rtu_longdrive;
    vRR = rtu_longdrive;
  }

  // SignalConversion generated from: '<S50>/spd_cmd' incorporates:
  //   MATLAB Function: '<S50>/MATLAB Function'

  rty_spd_cmd[1] = -vFR;
  rty_spd_cmd[2] = -vRR;
  rty_spd_cmd[3] = vRL;
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motio_modifyOverheadPhaseOne__j
  (sVIU4VBONGRsUytHTQmMJFH_motio_T *obj)
{
  int32_T c;
  int32_T idxStartIneq;
  idxStartIneq = static_cast<uint8_T>(obj->sizes[0]);
  for (int32_T idx = 0; idx < idxStartIneq; idx++) {
    obj->ATwset[21 * idx + 20] = 0.0;
  }

  for (int32_T idx = 0; idx < 40; idx++) {
    obj->Aineq[21 * idx + 20] = -1.0;
  }

  obj->indexLB[obj->sizes[3] - 1] = 21;
  obj->lb[20] = obj->SLACK0;
  idxStartIneq = obj->isActiveIdx[2];
  c = obj->nActiveConstr;
  for (int32_T idx = idxStartIneq; idx <= c; idx++) {
    obj->ATwset[21 * (idx - 1) + 20] = -1.0;
  }

  if (obj->nWConstr[4] > 0) {
    idxStartIneq = static_cast<uint8_T>(obj->sizesNormal[4] + 1);
    for (int32_T idx = 0; idx < idxStartIneq; idx++) {
      obj->isActiveConstr[(obj->isActiveIdx[4] + idx) - 1] = false;
    }
  }

  obj->isActiveConstr[obj->isActiveIdx[4] - 2] = false;
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motion_control_setProblemType_k
  (sVIU4VBONGRsUytHTQmMJFH_motio_T *obj, int32_T PROBLEM_TYPE)
{
  int32_T colOffsetATw;
  int32_T colOffsetAineq;
  int32_T i_tmp;
  int32_T idx;
  int32_T idx_lb;
  switch (PROBLEM_TYPE) {
   case 3:
    obj->nVar = 20;
    obj->mConstr = obj->mConstrOrig;
    if (obj->nWConstr[4] > 0) {
      idx_lb = static_cast<uint8_T>(obj->sizesNormal[4]);
      for (idx = 0; idx < idx_lb; idx++) {
        obj->isActiveConstr[(obj->isActiveIdxNormal[4] + idx) - 1] =
          obj->isActiveConstr[(obj->isActiveIdx[4] + idx) - 1];
      }
    }

    for (idx = 0; idx < 5; idx++) {
      obj->sizes[idx] = obj->sizesNormal[idx];
    }

    for (idx = 0; idx < 6; idx++) {
      obj->isActiveIdx[idx] = obj->isActiveIdxNormal[idx];
    }
    break;

   case 1:
    obj->nVar = 21;
    obj->mConstr = obj->mConstrOrig + 1;
    for (idx = 0; idx < 5; idx++) {
      obj->sizes[idx] = obj->sizesPhaseOne[idx];
    }

    for (idx = 0; idx < 6; idx++) {
      obj->isActiveIdx[idx] = obj->isActiveIdxPhaseOne[idx];
    }

    motio_modifyOverheadPhaseOne__j(obj);
    break;

   case 2:
    obj->nVar = 20;
    obj->mConstr = 80;
    for (idx = 0; idx < 5; idx++) {
      obj->sizes[idx] = obj->sizesRegularized[idx];
    }

    if (obj->probType != 4) {
      for (idx = 0; idx < 40; idx++) {
        colOffsetAineq = 21 * idx;
        for (idx_lb = 21; idx_lb <= idx + 20; idx_lb++) {
          obj->Aineq[(idx_lb + colOffsetAineq) - 1] = 0.0;
        }

        obj->Aineq[(idx + colOffsetAineq) + 20] = -1.0;
      }

      idx_lb = 20;
      colOffsetAineq = obj->sizesNormal[3] + 1;
      colOffsetATw = obj->sizesRegularized[3];
      for (idx = colOffsetAineq; idx <= colOffsetATw; idx++) {
        idx_lb++;
        obj->indexLB[idx - 1] = idx_lb;
      }

      if (obj->nWConstr[4] > 0) {
        idx_lb = static_cast<uint8_T>(obj->sizesRegularized[4]);
        for (idx = 0; idx < idx_lb; idx++) {
          obj->isActiveConstr[obj->isActiveIdxRegularized[4] + idx] =
            obj->isActiveConstr[(obj->isActiveIdx[4] + idx) - 1];
        }
      }

      idx_lb = obj->isActiveIdx[4];
      colOffsetAineq = obj->isActiveIdxRegularized[4] - 1;
      if (idx_lb <= colOffsetAineq) {
        memset(&obj->isActiveConstr[idx_lb + -1], 0, static_cast<uint32_T>
               ((colOffsetAineq - idx_lb) + 1) * sizeof(boolean_T));
      }

      obj->lb[20] = 0.0;
      idx_lb = obj->isActiveIdx[2];
      colOffsetAineq = obj->nActiveConstr;
      for (idx = idx_lb; idx <= colOffsetAineq; idx++) {
        colOffsetATw = (idx - 1) * 21 - 1;
        if (obj->Wid[idx - 1] == 3) {
          i_tmp = obj->Wlocalidx[idx - 1];
          if (i_tmp + 19 >= 21) {
            memset(&obj->ATwset[colOffsetATw + 21], 0, static_cast<uint32_T>
                   ((((i_tmp + 19) + colOffsetATw) - colOffsetATw) - 20) *
                   sizeof(real_T));
          }

          obj->ATwset[(i_tmp + colOffsetATw) + 20] = -1.0;
          i_tmp += 21;
          if (i_tmp <= 20) {
            memset(&obj->ATwset[i_tmp + colOffsetATw], 0, static_cast<uint32_T>
                   (((colOffsetATw - i_tmp) - colOffsetATw) + 21) * sizeof
                   (real_T));
          }
        }
      }
    }

    for (idx = 0; idx < 6; idx++) {
      obj->isActiveIdx[idx] = obj->isActiveIdxRegularized[idx];
    }
    break;

   default:
    obj->nVar = 21;
    obj->mConstr = 81;
    for (idx = 0; idx < 5; idx++) {
      obj->sizes[idx] = obj->sizesRegPhaseOne[idx];
    }

    for (idx = 0; idx < 6; idx++) {
      obj->isActiveIdx[idx] = obj->isActiveIdxRegPhaseOne[idx];
    }

    motio_modifyOverheadPhaseOne__j(obj);
    break;
  }

  obj->probType = PROBLEM_TYPE;
}

// Function for MATLAB Function: '<S63>/solvex'
real_T motion_controller_withPIC::motion_controlle_xnrm2_hNM7iFHJ(int32_T n,
  const real_T x[1701], int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      motion_controller_withPIC_B.scale_n = 3.3121686421112381E-170;
      motion_controller_withPIC_B.kend_p = (ix0 + n) - 1;
      for (motion_controller_withPIC_B.k_l = ix0;
           motion_controller_withPIC_B.k_l <= motion_controller_withPIC_B.kend_p;
           motion_controller_withPIC_B.k_l++) {
        motion_controller_withPIC_B.absxk_h = fabs
          (x[motion_controller_withPIC_B.k_l - 1]);
        if (motion_controller_withPIC_B.absxk_h >
            motion_controller_withPIC_B.scale_n) {
          motion_controller_withPIC_B.t_k = motion_controller_withPIC_B.scale_n /
            motion_controller_withPIC_B.absxk_h;
          y = y * motion_controller_withPIC_B.t_k *
            motion_controller_withPIC_B.t_k + 1.0;
          motion_controller_withPIC_B.scale_n =
            motion_controller_withPIC_B.absxk_h;
        } else {
          motion_controller_withPIC_B.t_k = motion_controller_withPIC_B.absxk_h /
            motion_controller_withPIC_B.scale_n;
          y += motion_controller_withPIC_B.t_k * motion_controller_withPIC_B.t_k;
        }
      }

      y = motion_controller_withPIC_B.scale_n * sqrt(y);
    }
  }

  return y;
}

real_T motion_controller_withPIC::motion_controller_rt_hypotd_snf(real_T u0,
  real_T u1)
{
  real_T y;
  motion_controller_withPIC_B.a_j = fabs(u0);
  motion_controller_withPIC_B.b = fabs(u1);
  if (motion_controller_withPIC_B.a_j < motion_controller_withPIC_B.b) {
    motion_controller_withPIC_B.a_j /= motion_controller_withPIC_B.b;
    y = sqrt(motion_controller_withPIC_B.a_j * motion_controller_withPIC_B.a_j +
             1.0) * motion_controller_withPIC_B.b;
  } else if (motion_controller_withPIC_B.a_j > motion_controller_withPIC_B.b) {
    motion_controller_withPIC_B.b /= motion_controller_withPIC_B.a_j;
    y = sqrt(motion_controller_withPIC_B.b * motion_controller_withPIC_B.b + 1.0)
      * motion_controller_withPIC_B.a_j;
  } else if (rtIsNaN(motion_controller_withPIC_B.b)) {
    y = (rtNaN);
  } else {
    y = motion_controller_withPIC_B.a_j * 1.4142135623730951;
  }

  return y;
}

// Function for MATLAB Function: '<S63>/solvex'
real_T motion_controller_withPIC::motion_control_xzlarfg_Bt3Hq0Z4(int32_T n,
  real_T *alpha1, real_T x[1701], int32_T ix0)
{
  __m128d tmp;
  real_T tau;
  tau = 0.0;
  if (n > 0) {
    motion_controller_withPIC_B.xnorm_f = motion_controlle_xnrm2_hNM7iFHJ(n - 1,
      x, ix0);
    if (motion_controller_withPIC_B.xnorm_f != 0.0) {
      motion_controller_withPIC_B.xnorm_f = motion_controller_rt_hypotd_snf
        (*alpha1, motion_controller_withPIC_B.xnorm_f);
      if (*alpha1 >= 0.0) {
        motion_controller_withPIC_B.xnorm_f =
          -motion_controller_withPIC_B.xnorm_f;
      }

      if (fabs(motion_controller_withPIC_B.xnorm_f) < 1.0020841800044864E-292) {
        motion_controller_withPIC_B.knt_j = 0;
        motion_controller_withPIC_B.scalarLB_j = (ix0 + n) - 2;
        do {
          motion_controller_withPIC_B.knt_j++;
          motion_controller_withPIC_B.vectorUB_l =
            ((((motion_controller_withPIC_B.scalarLB_j - ix0) + 1) / 2) << 1) +
            ix0;
          motion_controller_withPIC_B.vectorUB_tmp_p =
            motion_controller_withPIC_B.vectorUB_l - 2;
          for (motion_controller_withPIC_B.d_n = ix0;
               motion_controller_withPIC_B.d_n <=
               motion_controller_withPIC_B.vectorUB_tmp_p;
               motion_controller_withPIC_B.d_n += 2) {
            tmp = _mm_loadu_pd(&x[motion_controller_withPIC_B.d_n - 1]);
            _mm_storeu_pd(&x[motion_controller_withPIC_B.d_n - 1], _mm_mul_pd
                          (tmp, _mm_set1_pd(9.9792015476736E+291)));
          }

          for (motion_controller_withPIC_B.d_n =
               motion_controller_withPIC_B.vectorUB_l;
               motion_controller_withPIC_B.d_n <=
               motion_controller_withPIC_B.scalarLB_j;
               motion_controller_withPIC_B.d_n++) {
            x[motion_controller_withPIC_B.d_n - 1] *= 9.9792015476736E+291;
          }

          motion_controller_withPIC_B.xnorm_f *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((fabs(motion_controller_withPIC_B.xnorm_f) <
                  1.0020841800044864E-292) && (motion_controller_withPIC_B.knt_j
                  < 20));

        motion_controller_withPIC_B.xnorm_f = motion_controller_rt_hypotd_snf
          (*alpha1, motion_controlle_xnrm2_hNM7iFHJ(n - 1, x, ix0));
        if (*alpha1 >= 0.0) {
          motion_controller_withPIC_B.xnorm_f =
            -motion_controller_withPIC_B.xnorm_f;
        }

        tau = (motion_controller_withPIC_B.xnorm_f - *alpha1) /
          motion_controller_withPIC_B.xnorm_f;
        motion_controller_withPIC_B.a_c = 1.0 / (*alpha1 -
          motion_controller_withPIC_B.xnorm_f);
        for (motion_controller_withPIC_B.d_n = ix0;
             motion_controller_withPIC_B.d_n <=
             motion_controller_withPIC_B.vectorUB_tmp_p;
             motion_controller_withPIC_B.d_n += 2) {
          tmp = _mm_loadu_pd(&x[motion_controller_withPIC_B.d_n - 1]);
          _mm_storeu_pd(&x[motion_controller_withPIC_B.d_n - 1], _mm_mul_pd(tmp,
            _mm_set1_pd(motion_controller_withPIC_B.a_c)));
        }

        for (motion_controller_withPIC_B.d_n =
             motion_controller_withPIC_B.vectorUB_l;
             motion_controller_withPIC_B.d_n <=
             motion_controller_withPIC_B.scalarLB_j;
             motion_controller_withPIC_B.d_n++) {
          x[motion_controller_withPIC_B.d_n - 1] *=
            motion_controller_withPIC_B.a_c;
        }

        for (motion_controller_withPIC_B.d_n = 0;
             motion_controller_withPIC_B.d_n < motion_controller_withPIC_B.knt_j;
             motion_controller_withPIC_B.d_n++) {
          motion_controller_withPIC_B.xnorm_f *= 1.0020841800044864E-292;
        }

        *alpha1 = motion_controller_withPIC_B.xnorm_f;
      } else {
        tau = (motion_controller_withPIC_B.xnorm_f - *alpha1) /
          motion_controller_withPIC_B.xnorm_f;
        motion_controller_withPIC_B.a_c = 1.0 / (*alpha1 -
          motion_controller_withPIC_B.xnorm_f);
        motion_controller_withPIC_B.d_n = (ix0 + n) - 2;
        motion_controller_withPIC_B.scalarLB_j =
          ((((motion_controller_withPIC_B.d_n - ix0) + 1) / 2) << 1) + ix0;
        motion_controller_withPIC_B.vectorUB_l =
          motion_controller_withPIC_B.scalarLB_j - 2;
        for (motion_controller_withPIC_B.knt_j = ix0;
             motion_controller_withPIC_B.knt_j <=
             motion_controller_withPIC_B.vectorUB_l;
             motion_controller_withPIC_B.knt_j += 2) {
          tmp = _mm_loadu_pd(&x[motion_controller_withPIC_B.knt_j - 1]);
          _mm_storeu_pd(&x[motion_controller_withPIC_B.knt_j - 1], _mm_mul_pd
                        (tmp, _mm_set1_pd(motion_controller_withPIC_B.a_c)));
        }

        for (motion_controller_withPIC_B.knt_j =
             motion_controller_withPIC_B.scalarLB_j;
             motion_controller_withPIC_B.knt_j <=
             motion_controller_withPIC_B.d_n; motion_controller_withPIC_B.knt_j
             ++) {
          x[motion_controller_withPIC_B.knt_j - 1] *=
            motion_controller_withPIC_B.a_c;
        }

        *alpha1 = motion_controller_withPIC_B.xnorm_f;
      }
    }
  }

  return tau;
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motion_controll_xzlarf_ROZS8xVG(int32_T m,
  int32_T n, int32_T iv0, real_T tau, real_T C[1701], int32_T ic0, real_T work
  [81])
{
  if (tau != 0.0) {
    boolean_T exitg2;
    motion_controller_withPIC_B.lastv = m;
    motion_controller_withPIC_B.lastc_b = iv0 + m;
    while ((motion_controller_withPIC_B.lastv > 0) &&
           (C[motion_controller_withPIC_B.lastc_b - 2] == 0.0)) {
      motion_controller_withPIC_B.lastv--;
      motion_controller_withPIC_B.lastc_b--;
    }

    motion_controller_withPIC_B.lastc_b = n;
    exitg2 = false;
    while ((!exitg2) && (motion_controller_withPIC_B.lastc_b > 0)) {
      int32_T exitg1;
      motion_controller_withPIC_B.coltop_f =
        (motion_controller_withPIC_B.lastc_b - 1) * 21 + ic0;
      motion_controller_withPIC_B.b_ia = motion_controller_withPIC_B.coltop_f;
      do {
        exitg1 = 0;
        if (motion_controller_withPIC_B.b_ia <=
            (motion_controller_withPIC_B.coltop_f +
             motion_controller_withPIC_B.lastv) - 1) {
          if (C[motion_controller_withPIC_B.b_ia - 1] != 0.0) {
            exitg1 = 1;
          } else {
            motion_controller_withPIC_B.b_ia++;
          }
        } else {
          motion_controller_withPIC_B.lastc_b--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    motion_controller_withPIC_B.lastc_b--;
  } else {
    motion_controller_withPIC_B.lastv = 0;
    motion_controller_withPIC_B.lastc_b = -1;
  }

  if (motion_controller_withPIC_B.lastv > 0) {
    if (motion_controller_withPIC_B.lastc_b + 1 != 0) {
      if (motion_controller_withPIC_B.lastc_b >= 0) {
        memset(&work[0], 0, static_cast<uint32_T>
               (motion_controller_withPIC_B.lastc_b + 1) * sizeof(real_T));
      }

      motion_controller_withPIC_B.jA_c = 21 *
        motion_controller_withPIC_B.lastc_b + ic0;
      for (motion_controller_withPIC_B.coltop_f = ic0;
           motion_controller_withPIC_B.coltop_f <=
           motion_controller_withPIC_B.jA_c;
           motion_controller_withPIC_B.coltop_f += 21) {
        motion_controller_withPIC_B.c_e = 0.0;
        motion_controller_withPIC_B.d_gu = (motion_controller_withPIC_B.coltop_f
          + motion_controller_withPIC_B.lastv) - 1;
        for (motion_controller_withPIC_B.b_ia =
             motion_controller_withPIC_B.coltop_f;
             motion_controller_withPIC_B.b_ia <=
             motion_controller_withPIC_B.d_gu; motion_controller_withPIC_B.b_ia
             ++) {
          motion_controller_withPIC_B.c_e += C[((iv0 +
            motion_controller_withPIC_B.b_ia) -
            motion_controller_withPIC_B.coltop_f) - 1] *
            C[motion_controller_withPIC_B.b_ia - 1];
        }

        motion_controller_withPIC_B.b_ia = div_nde_s32_floor
          (motion_controller_withPIC_B.coltop_f - ic0, 21);
        work[motion_controller_withPIC_B.b_ia] +=
          motion_controller_withPIC_B.c_e;
      }
    }

    if (!(-tau == 0.0)) {
      motion_controller_withPIC_B.jA_c = ic0;
      for (motion_controller_withPIC_B.coltop_f = 0;
           motion_controller_withPIC_B.coltop_f <=
           motion_controller_withPIC_B.lastc_b;
           motion_controller_withPIC_B.coltop_f++) {
        motion_controller_withPIC_B.c_e =
          work[motion_controller_withPIC_B.coltop_f];
        if (motion_controller_withPIC_B.c_e != 0.0) {
          motion_controller_withPIC_B.c_e *= -tau;
          motion_controller_withPIC_B.d_gu = motion_controller_withPIC_B.lastv +
            motion_controller_withPIC_B.jA_c;
          for (motion_controller_withPIC_B.b_ia =
               motion_controller_withPIC_B.jA_c;
               motion_controller_withPIC_B.b_ia <
               motion_controller_withPIC_B.d_gu;
               motion_controller_withPIC_B.b_ia++) {
            C[motion_controller_withPIC_B.b_ia - 1] += C[((iv0 +
              motion_controller_withPIC_B.b_ia) -
              motion_controller_withPIC_B.jA_c) - 1] *
              motion_controller_withPIC_B.c_e;
          }
        }

        motion_controller_withPIC_B.jA_c += 21;
      }
    }
  }
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motion_controller__qrf_nGv3LI5p(real_T A[1701],
  int32_T m, int32_T n, int32_T nfxd, real_T tau[21])
{
  memset(&motion_controller_withPIC_B.work_h[0], 0, 81U * sizeof(real_T));
  motion_controller_withPIC_B.b_hj = static_cast<uint8_T>(nfxd);
  for (motion_controller_withPIC_B.i_d1 = 0; motion_controller_withPIC_B.i_d1 <
       motion_controller_withPIC_B.b_hj; motion_controller_withPIC_B.i_d1++) {
    motion_controller_withPIC_B.ii_j = motion_controller_withPIC_B.i_d1 * 21 +
      motion_controller_withPIC_B.i_d1;
    motion_controller_withPIC_B.mmi_k = m - motion_controller_withPIC_B.i_d1;
    if (motion_controller_withPIC_B.i_d1 + 1 < m) {
      motion_controller_withPIC_B.b_atmp_f = A[motion_controller_withPIC_B.ii_j];
      motion_controller_withPIC_B.tau_i = motion_control_xzlarfg_Bt3Hq0Z4
        (motion_controller_withPIC_B.mmi_k,
         &motion_controller_withPIC_B.b_atmp_f, A,
         motion_controller_withPIC_B.ii_j + 2);
      tau[motion_controller_withPIC_B.i_d1] = motion_controller_withPIC_B.tau_i;
      A[motion_controller_withPIC_B.ii_j] = motion_controller_withPIC_B.b_atmp_f;
    } else {
      motion_controller_withPIC_B.tau_i = 0.0;
      tau[motion_controller_withPIC_B.i_d1] = 0.0;
    }

    if (motion_controller_withPIC_B.i_d1 + 1 < n) {
      motion_controller_withPIC_B.b_atmp_f = A[motion_controller_withPIC_B.ii_j];
      A[motion_controller_withPIC_B.ii_j] = 1.0;
      motion_controll_xzlarf_ROZS8xVG(motion_controller_withPIC_B.mmi_k, (n -
        motion_controller_withPIC_B.i_d1) - 1, motion_controller_withPIC_B.ii_j
        + 1, motion_controller_withPIC_B.tau_i, A,
        motion_controller_withPIC_B.ii_j + 22,
        motion_controller_withPIC_B.work_h);
      A[motion_controller_withPIC_B.ii_j] = motion_controller_withPIC_B.b_atmp_f;
    }
  }
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motion_controller_w_factorQRE_c
  (sIZAIOglGM5dPDQlNukc9SD_motio_T *obj, int32_T mrows, int32_T ncols)
{
  static const int32_T offsets[4] = { 0, 1, 2, 3 };

  __m128i tmp;
  if (mrows * ncols == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    obj->usedPivoting = true;
    obj->mrows = mrows;
    obj->ncols = ncols;
    if (mrows <= ncols) {
      motion_controller_withPIC_B.u1_k = mrows;
    } else {
      motion_controller_withPIC_B.u1_k = ncols;
    }

    obj->minRowCol = motion_controller_withPIC_B.u1_k;
    memset(&obj->tau[0], 0, 21U * sizeof(real_T));
    if (motion_controller_withPIC_B.u1_k < 1) {
      motion_controller_withPIC_B.nfxd_g = (ncols / 4) << 2;
      motion_controller_withPIC_B.i_a = motion_controller_withPIC_B.nfxd_g - 4;
      for (motion_controller_withPIC_B.u1_k = 0;
           motion_controller_withPIC_B.u1_k <= motion_controller_withPIC_B.i_a;
           motion_controller_withPIC_B.u1_k += 4) {
        tmp = _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32
          (motion_controller_withPIC_B.u1_k), _mm_loadu_si128((const __m128i *)
          &offsets[0])), _mm_set1_epi32(1));
        _mm_storeu_si128((__m128i *)&obj->jpvt[motion_controller_withPIC_B.u1_k],
                         tmp);
      }

      for (motion_controller_withPIC_B.u1_k = motion_controller_withPIC_B.nfxd_g;
           motion_controller_withPIC_B.u1_k < ncols;
           motion_controller_withPIC_B.u1_k++) {
        obj->jpvt[motion_controller_withPIC_B.u1_k] =
          motion_controller_withPIC_B.u1_k + 1;
      }
    } else {
      motion_controller_withPIC_B.nfxd_g = -1;
      for (motion_controller_withPIC_B.i_a = 0; motion_controller_withPIC_B.i_a <
           ncols; motion_controller_withPIC_B.i_a++) {
        if (obj->jpvt[motion_controller_withPIC_B.i_a] != 0) {
          motion_controller_withPIC_B.nfxd_g++;
          if (motion_controller_withPIC_B.i_a + 1 !=
              motion_controller_withPIC_B.nfxd_g + 1) {
            motion_controller_withPIC_B.ix_k = motion_controller_withPIC_B.i_a *
              21;
            motion_controller_withPIC_B.iy_p =
              motion_controller_withPIC_B.nfxd_g * 21;
            for (motion_controller_withPIC_B.mmi_c = 0;
                 motion_controller_withPIC_B.mmi_c < mrows;
                 motion_controller_withPIC_B.mmi_c++) {
              motion_controller_withPIC_B.temp_tmp_f =
                motion_controller_withPIC_B.ix_k +
                motion_controller_withPIC_B.mmi_c;
              motion_controller_withPIC_B.temp_h = obj->
                QR[motion_controller_withPIC_B.temp_tmp_f];
              motion_controller_withPIC_B.itemp_d =
                motion_controller_withPIC_B.iy_p +
                motion_controller_withPIC_B.mmi_c;
              obj->QR[motion_controller_withPIC_B.temp_tmp_f] = obj->
                QR[motion_controller_withPIC_B.itemp_d];
              obj->QR[motion_controller_withPIC_B.itemp_d] =
                motion_controller_withPIC_B.temp_h;
            }

            obj->jpvt[motion_controller_withPIC_B.i_a] = obj->
              jpvt[motion_controller_withPIC_B.nfxd_g];
            obj->jpvt[motion_controller_withPIC_B.nfxd_g] =
              motion_controller_withPIC_B.i_a + 1;
          } else {
            obj->jpvt[motion_controller_withPIC_B.i_a] =
              motion_controller_withPIC_B.i_a + 1;
          }
        } else {
          obj->jpvt[motion_controller_withPIC_B.i_a] =
            motion_controller_withPIC_B.i_a + 1;
        }
      }

      if (motion_controller_withPIC_B.nfxd_g + 1 <=
          motion_controller_withPIC_B.u1_k) {
        motion_controller_withPIC_B.nfxd_g++;
      } else {
        motion_controller_withPIC_B.nfxd_g = motion_controller_withPIC_B.u1_k;
      }

      memset(&obj->tau[0], 0, 21U * sizeof(real_T));
      motion_controller__qrf_nGv3LI5p(obj->QR, mrows, ncols,
        motion_controller_withPIC_B.nfxd_g, obj->tau);
      if (motion_controller_withPIC_B.nfxd_g < motion_controller_withPIC_B.u1_k)
      {
        memset(&motion_controller_withPIC_B.work_n[0], 0, 81U * sizeof(real_T));
        memset(&motion_controller_withPIC_B.vn1_b[0], 0, 81U * sizeof(real_T));
        memset(&motion_controller_withPIC_B.vn2_l[0], 0, 81U * sizeof(real_T));
        for (motion_controller_withPIC_B.i_a =
             motion_controller_withPIC_B.nfxd_g + 1;
             motion_controller_withPIC_B.i_a <= ncols;
             motion_controller_withPIC_B.i_a++) {
          motion_controller_withPIC_B.temp_h = motion_controlle_xnrm2_hNM7iFHJ
            (mrows - motion_controller_withPIC_B.nfxd_g, obj->QR,
             ((motion_controller_withPIC_B.i_a - 1) * 21 +
              motion_controller_withPIC_B.nfxd_g) + 1);
          motion_controller_withPIC_B.vn1_b[motion_controller_withPIC_B.i_a - 1]
            = motion_controller_withPIC_B.temp_h;
          motion_controller_withPIC_B.vn2_l[motion_controller_withPIC_B.i_a - 1]
            = motion_controller_withPIC_B.temp_h;
        }

        for (motion_controller_withPIC_B.i_a =
             motion_controller_withPIC_B.nfxd_g + 1;
             motion_controller_withPIC_B.i_a <= motion_controller_withPIC_B.u1_k;
             motion_controller_withPIC_B.i_a++) {
          motion_controller_withPIC_B.temp_tmp_f =
            (motion_controller_withPIC_B.i_a - 1) * 21;
          motion_controller_withPIC_B.ix_k =
            (motion_controller_withPIC_B.temp_tmp_f +
             motion_controller_withPIC_B.i_a) - 1;
          motion_controller_withPIC_B.iy_p = ncols -
            motion_controller_withPIC_B.i_a;
          motion_controller_withPIC_B.mmi_c = mrows -
            motion_controller_withPIC_B.i_a;
          if (motion_controller_withPIC_B.iy_p + 1 < 1) {
            motion_controller_withPIC_B.pvt_k = -2;
          } else {
            motion_controller_withPIC_B.pvt_k = -1;
            if (motion_controller_withPIC_B.iy_p + 1 > 1) {
              motion_controller_withPIC_B.temp_h = fabs
                (motion_controller_withPIC_B.vn1_b[motion_controller_withPIC_B.i_a
                 - 1]);
              for (motion_controller_withPIC_B.itemp_d = 2;
                   motion_controller_withPIC_B.itemp_d <=
                   motion_controller_withPIC_B.iy_p + 1;
                   motion_controller_withPIC_B.itemp_d++) {
                motion_controller_withPIC_B.s_h = fabs
                  (motion_controller_withPIC_B.vn1_b
                   [(motion_controller_withPIC_B.i_a +
                     motion_controller_withPIC_B.itemp_d) - 2]);
                if (motion_controller_withPIC_B.s_h >
                    motion_controller_withPIC_B.temp_h) {
                  motion_controller_withPIC_B.pvt_k =
                    motion_controller_withPIC_B.itemp_d - 2;
                  motion_controller_withPIC_B.temp_h =
                    motion_controller_withPIC_B.s_h;
                }
              }
            }
          }

          motion_controller_withPIC_B.pvt_k += motion_controller_withPIC_B.i_a;
          if (motion_controller_withPIC_B.pvt_k + 1 !=
              motion_controller_withPIC_B.i_a) {
            motion_controller_withPIC_B.c_ix_p =
              motion_controller_withPIC_B.pvt_k * 21;
            for (motion_controller_withPIC_B.c_k_m = 0;
                 motion_controller_withPIC_B.c_k_m < mrows;
                 motion_controller_withPIC_B.c_k_m++) {
              motion_controller_withPIC_B.b_temp_tmp_c =
                motion_controller_withPIC_B.c_ix_p +
                motion_controller_withPIC_B.c_k_m;
              motion_controller_withPIC_B.temp_h = obj->
                QR[motion_controller_withPIC_B.b_temp_tmp_c];
              motion_controller_withPIC_B.itemp_d =
                motion_controller_withPIC_B.temp_tmp_f +
                motion_controller_withPIC_B.c_k_m;
              obj->QR[motion_controller_withPIC_B.b_temp_tmp_c] = obj->
                QR[motion_controller_withPIC_B.itemp_d];
              obj->QR[motion_controller_withPIC_B.itemp_d] =
                motion_controller_withPIC_B.temp_h;
            }

            motion_controller_withPIC_B.itemp_d = obj->
              jpvt[motion_controller_withPIC_B.pvt_k];
            obj->jpvt[motion_controller_withPIC_B.pvt_k] = obj->
              jpvt[motion_controller_withPIC_B.i_a - 1];
            obj->jpvt[motion_controller_withPIC_B.i_a - 1] =
              motion_controller_withPIC_B.itemp_d;
            motion_controller_withPIC_B.vn1_b[motion_controller_withPIC_B.pvt_k]
              =
              motion_controller_withPIC_B.vn1_b[motion_controller_withPIC_B.i_a
              - 1];
            motion_controller_withPIC_B.vn2_l[motion_controller_withPIC_B.pvt_k]
              =
              motion_controller_withPIC_B.vn2_l[motion_controller_withPIC_B.i_a
              - 1];
          }

          if (motion_controller_withPIC_B.i_a < mrows) {
            motion_controller_withPIC_B.temp_h = obj->
              QR[motion_controller_withPIC_B.ix_k];
            obj->tau[motion_controller_withPIC_B.i_a - 1] =
              motion_control_xzlarfg_Bt3Hq0Z4(motion_controller_withPIC_B.mmi_c
              + 1, &motion_controller_withPIC_B.temp_h, obj->QR,
              motion_controller_withPIC_B.ix_k + 2);
            obj->QR[motion_controller_withPIC_B.ix_k] =
              motion_controller_withPIC_B.temp_h;
          } else {
            obj->tau[motion_controller_withPIC_B.i_a - 1] = 0.0;
          }

          if (motion_controller_withPIC_B.i_a < ncols) {
            motion_controller_withPIC_B.temp_h = obj->
              QR[motion_controller_withPIC_B.ix_k];
            obj->QR[motion_controller_withPIC_B.ix_k] = 1.0;
            motion_controll_xzlarf_ROZS8xVG(motion_controller_withPIC_B.mmi_c +
              1, motion_controller_withPIC_B.iy_p,
              motion_controller_withPIC_B.ix_k + 1, obj->
              tau[motion_controller_withPIC_B.i_a - 1], obj->QR,
              motion_controller_withPIC_B.ix_k + 22,
              motion_controller_withPIC_B.work_n);
            obj->QR[motion_controller_withPIC_B.ix_k] =
              motion_controller_withPIC_B.temp_h;
          }

          for (motion_controller_withPIC_B.itemp_d =
               motion_controller_withPIC_B.i_a + 1;
               motion_controller_withPIC_B.itemp_d <= ncols;
               motion_controller_withPIC_B.itemp_d++) {
            motion_controller_withPIC_B.ix_k =
              (motion_controller_withPIC_B.itemp_d - 1) * 21 +
              motion_controller_withPIC_B.i_a;
            motion_controller_withPIC_B.temp_h =
              motion_controller_withPIC_B.vn1_b[motion_controller_withPIC_B.itemp_d
              - 1];
            if (motion_controller_withPIC_B.temp_h != 0.0) {
              motion_controller_withPIC_B.s_h = fabs(obj->
                QR[motion_controller_withPIC_B.ix_k - 1]) /
                motion_controller_withPIC_B.temp_h;
              motion_controller_withPIC_B.s_h = 1.0 -
                motion_controller_withPIC_B.s_h *
                motion_controller_withPIC_B.s_h;
              if (motion_controller_withPIC_B.s_h < 0.0) {
                motion_controller_withPIC_B.s_h = 0.0;
              }

              motion_controller_withPIC_B.temp2_n =
                motion_controller_withPIC_B.temp_h /
                motion_controller_withPIC_B.vn2_l[motion_controller_withPIC_B.itemp_d
                - 1];
              motion_controller_withPIC_B.temp2_n =
                motion_controller_withPIC_B.temp2_n *
                motion_controller_withPIC_B.temp2_n *
                motion_controller_withPIC_B.s_h;
              if (motion_controller_withPIC_B.temp2_n <= 1.4901161193847656E-8)
              {
                if (motion_controller_withPIC_B.i_a < mrows) {
                  motion_controller_withPIC_B.temp_h =
                    motion_controlle_xnrm2_hNM7iFHJ
                    (motion_controller_withPIC_B.mmi_c, obj->QR,
                     motion_controller_withPIC_B.ix_k + 1);
                  motion_controller_withPIC_B.vn1_b[motion_controller_withPIC_B.itemp_d
                    - 1] = motion_controller_withPIC_B.temp_h;
                  motion_controller_withPIC_B.vn2_l[motion_controller_withPIC_B.itemp_d
                    - 1] = motion_controller_withPIC_B.temp_h;
                } else {
                  motion_controller_withPIC_B.vn1_b[motion_controller_withPIC_B.itemp_d
                    - 1] = 0.0;
                  motion_controller_withPIC_B.vn2_l[motion_controller_withPIC_B.itemp_d
                    - 1] = 0.0;
                }
              } else {
                motion_controller_withPIC_B.vn1_b[motion_controller_withPIC_B.itemp_d
                  - 1] = motion_controller_withPIC_B.temp_h * sqrt
                  (motion_controller_withPIC_B.s_h);
              }
            }
          }
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motion_controller_w_computeQ__l
  (sIZAIOglGM5dPDQlNukc9SD_motio_T *obj, int32_T nrows)
{
  motion_controller_withPIC_B.i_dl = obj->minRowCol;
  for (motion_controller_withPIC_B.idx_b = 0; motion_controller_withPIC_B.idx_b <
       motion_controller_withPIC_B.i_dl; motion_controller_withPIC_B.idx_b++) {
    motion_controller_withPIC_B.iQR0_i = 21 * motion_controller_withPIC_B.idx_b
      + motion_controller_withPIC_B.idx_b;
    motion_controller_withPIC_B.ia_o = obj->mrows -
      motion_controller_withPIC_B.idx_b;
    if (motion_controller_withPIC_B.ia_o - 2 >= 0) {
      memcpy(&obj->Q[motion_controller_withPIC_B.iQR0_i + 1], &obj->
             QR[motion_controller_withPIC_B.iQR0_i + 1], static_cast<uint32_T>
             (((motion_controller_withPIC_B.ia_o +
                motion_controller_withPIC_B.iQR0_i) -
               motion_controller_withPIC_B.iQR0_i) - 1) * sizeof(real_T));
    }
  }

  motion_controller_withPIC_B.idx_b = obj->mrows;
  if (nrows >= 1) {
    for (motion_controller_withPIC_B.itau_g = motion_controller_withPIC_B.i_dl;
         motion_controller_withPIC_B.itau_g < nrows;
         motion_controller_withPIC_B.itau_g++) {
      motion_controller_withPIC_B.ia_o = motion_controller_withPIC_B.itau_g * 21;
      memset(&obj->Q[motion_controller_withPIC_B.ia_o], 0, static_cast<uint32_T>
             ((motion_controller_withPIC_B.idx_b +
               motion_controller_withPIC_B.ia_o) -
              motion_controller_withPIC_B.ia_o) * sizeof(real_T));
      obj->Q[motion_controller_withPIC_B.ia_o +
        motion_controller_withPIC_B.itau_g] = 1.0;
    }

    motion_controller_withPIC_B.itau_g = obj->minRowCol - 1;
    memset(&motion_controller_withPIC_B.work_ny[0], 0, 21U * sizeof(real_T));
    motion_controller_withPIC_B.i_dl = obj->minRowCol;
    while (motion_controller_withPIC_B.i_dl >= 1) {
      motion_controller_withPIC_B.iQR0_i = ((motion_controller_withPIC_B.i_dl -
        1) * 21 + motion_controller_withPIC_B.i_dl) - 1;
      if (motion_controller_withPIC_B.i_dl < nrows) {
        obj->Q[motion_controller_withPIC_B.iQR0_i] = 1.0;
        motion_controller_withPIC_B.ia_o = motion_controller_withPIC_B.idx_b -
          motion_controller_withPIC_B.i_dl;
        if (obj->tau[motion_controller_withPIC_B.itau_g] != 0.0) {
          boolean_T exitg2;
          motion_controller_withPIC_B.lastc_e =
            motion_controller_withPIC_B.iQR0_i +
            motion_controller_withPIC_B.ia_o;
          while ((motion_controller_withPIC_B.ia_o + 1 > 0) && (obj->
                  Q[motion_controller_withPIC_B.lastc_e] == 0.0)) {
            motion_controller_withPIC_B.ia_o--;
            motion_controller_withPIC_B.lastc_e--;
          }

          motion_controller_withPIC_B.lastc_e = nrows -
            motion_controller_withPIC_B.i_dl;
          exitg2 = false;
          while ((!exitg2) && (motion_controller_withPIC_B.lastc_e > 0)) {
            int32_T exitg1;
            motion_controller_withPIC_B.coltop_e =
              ((motion_controller_withPIC_B.lastc_e - 1) * 21 +
               motion_controller_withPIC_B.iQR0_i) + 22;
            motion_controller_withPIC_B.c_ia_i =
              motion_controller_withPIC_B.coltop_e;
            do {
              exitg1 = 0;
              if (motion_controller_withPIC_B.c_ia_i <=
                  motion_controller_withPIC_B.coltop_e +
                  motion_controller_withPIC_B.ia_o) {
                if (obj->Q[motion_controller_withPIC_B.c_ia_i - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  motion_controller_withPIC_B.c_ia_i++;
                }
              } else {
                motion_controller_withPIC_B.lastc_e--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }

          motion_controller_withPIC_B.lastc_e--;
        } else {
          motion_controller_withPIC_B.ia_o = -1;
          motion_controller_withPIC_B.lastc_e = -1;
        }

        if (motion_controller_withPIC_B.ia_o + 1 > 0) {
          if (motion_controller_withPIC_B.lastc_e + 1 != 0) {
            if (motion_controller_withPIC_B.lastc_e >= 0) {
              memset(&motion_controller_withPIC_B.work_ny[0], 0, static_cast<
                     uint32_T>(motion_controller_withPIC_B.lastc_e + 1) * sizeof
                     (real_T));
            }

            motion_controller_withPIC_B.c_ia_i = (21 *
              motion_controller_withPIC_B.lastc_e +
              motion_controller_withPIC_B.iQR0_i) + 22;
            for (motion_controller_withPIC_B.coltop_e =
                 motion_controller_withPIC_B.iQR0_i + 22;
                 motion_controller_withPIC_B.coltop_e <=
                 motion_controller_withPIC_B.c_ia_i;
                 motion_controller_withPIC_B.coltop_e += 21) {
              motion_controller_withPIC_B.b_c_l = 0.0;
              motion_controller_withPIC_B.f_i =
                motion_controller_withPIC_B.coltop_e +
                motion_controller_withPIC_B.ia_o;
              for (motion_controller_withPIC_B.jA_m =
                   motion_controller_withPIC_B.coltop_e;
                   motion_controller_withPIC_B.jA_m <=
                   motion_controller_withPIC_B.f_i;
                   motion_controller_withPIC_B.jA_m++) {
                motion_controller_withPIC_B.b_c_l += obj->Q
                  [(motion_controller_withPIC_B.iQR0_i +
                    motion_controller_withPIC_B.jA_m) -
                  motion_controller_withPIC_B.coltop_e] * obj->
                  Q[motion_controller_withPIC_B.jA_m - 1];
              }

              motion_controller_withPIC_B.jA_m = div_nde_s32_floor
                ((motion_controller_withPIC_B.coltop_e -
                  motion_controller_withPIC_B.iQR0_i) - 22, 21);
              motion_controller_withPIC_B.work_ny[motion_controller_withPIC_B.jA_m]
                += motion_controller_withPIC_B.b_c_l;
            }
          }

          if (!(-obj->tau[motion_controller_withPIC_B.itau_g] == 0.0)) {
            motion_controller_withPIC_B.jA_m =
              motion_controller_withPIC_B.iQR0_i + 22;
            for (motion_controller_withPIC_B.coltop_e = 0;
                 motion_controller_withPIC_B.coltop_e <=
                 motion_controller_withPIC_B.lastc_e;
                 motion_controller_withPIC_B.coltop_e++) {
              motion_controller_withPIC_B.b_c_l =
                motion_controller_withPIC_B.work_ny[motion_controller_withPIC_B.coltop_e];
              if (motion_controller_withPIC_B.b_c_l != 0.0) {
                motion_controller_withPIC_B.b_c_l *= -obj->
                  tau[motion_controller_withPIC_B.itau_g];
                motion_controller_withPIC_B.f_i =
                  motion_controller_withPIC_B.ia_o +
                  motion_controller_withPIC_B.jA_m;
                for (motion_controller_withPIC_B.c_ia_i =
                     motion_controller_withPIC_B.jA_m;
                     motion_controller_withPIC_B.c_ia_i <=
                     motion_controller_withPIC_B.f_i;
                     motion_controller_withPIC_B.c_ia_i++) {
                  obj->Q[motion_controller_withPIC_B.c_ia_i - 1] += obj->Q
                    [(motion_controller_withPIC_B.iQR0_i +
                      motion_controller_withPIC_B.c_ia_i) -
                    motion_controller_withPIC_B.jA_m] *
                    motion_controller_withPIC_B.b_c_l;
                }
              }

              motion_controller_withPIC_B.jA_m += 21;
            }
          }
        }
      }

      if (motion_controller_withPIC_B.i_dl < motion_controller_withPIC_B.idx_b)
      {
        motion_controller_withPIC_B.lastc_e =
          ((motion_controller_withPIC_B.iQR0_i +
            motion_controller_withPIC_B.idx_b) -
           motion_controller_withPIC_B.i_dl) + 1;
        for (motion_controller_withPIC_B.ia_o =
             motion_controller_withPIC_B.iQR0_i + 2;
             motion_controller_withPIC_B.ia_o <=
             motion_controller_withPIC_B.lastc_e;
             motion_controller_withPIC_B.ia_o++) {
          obj->Q[motion_controller_withPIC_B.ia_o - 1] *= -obj->
            tau[motion_controller_withPIC_B.itau_g];
        }
      }

      obj->Q[motion_controller_withPIC_B.iQR0_i] = 1.0 - obj->
        tau[motion_controller_withPIC_B.itau_g];
      motion_controller_withPIC_B.lastc_e = static_cast<uint8_T>
        (motion_controller_withPIC_B.i_dl - 1);
      for (motion_controller_withPIC_B.ia_o = 0;
           motion_controller_withPIC_B.ia_o <
           motion_controller_withPIC_B.lastc_e; motion_controller_withPIC_B.ia_o
           ++) {
        obj->Q[(motion_controller_withPIC_B.iQR0_i -
                motion_controller_withPIC_B.ia_o) - 1] = 0.0;
      }

      motion_controller_withPIC_B.itau_g--;
      motion_controller_withPIC_B.i_dl--;
    }
  }
}

// Function for MATLAB Function: '<S63>/solvex'
int32_T motion_controller_withPIC::motion_ComputeNumDependentEq__d
  (sIZAIOglGM5dPDQlNukc9SD_motio_T *qrmanager, const real_T beqf[81], int32_T
   mConstr, int32_T nVar)
{
  real_T qtb;
  real_T tol;
  int32_T b;
  int32_T ix;
  int32_T numDependent;
  int32_T totalRank;
  boolean_T exitg1;
  numDependent = mConstr - nVar;
  if (numDependent <= 0) {
    numDependent = 0;
  }

  memset(&qrmanager->jpvt[0], 0, static_cast<uint8_T>(nVar) * sizeof(int32_T));
  motion_controller_w_factorQRE_c(qrmanager, mConstr, nVar);
  tol = 100.0 * static_cast<real_T>(nVar) * 2.2204460492503131E-16;
  if (nVar <= mConstr) {
    totalRank = nVar;
  } else {
    totalRank = mConstr;
  }

  totalRank += (totalRank - 1) * 21;
  while ((totalRank > 0) && (fabs(qrmanager->QR[totalRank - 1]) < tol)) {
    totalRank -= 22;
    numDependent++;
  }

  if (numDependent > 0) {
    motion_controller_w_computeQ__l(qrmanager, qrmanager->mrows);
    b = 0;
    exitg1 = false;
    while ((!exitg1) && (b <= numDependent - 1)) {
      ix = ((mConstr - b) - 1) * 21;
      qtb = 0.0;
      for (totalRank = 0; totalRank < mConstr; totalRank++) {
        qtb += qrmanager->Q[ix + totalRank] * beqf[totalRank];
      }

      if (fabs(qtb) >= tol) {
        numDependent = -1;
        exitg1 = true;
      } else {
        b++;
      }
    }
  }

  return numDependent;
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motion_controlle_removeConstr_n
  (sVIU4VBONGRsUytHTQmMJFH_motio_T *obj, int32_T idx_global)
{
  int32_T TYPE_tmp;
  int32_T b;
  TYPE_tmp = obj->Wid[idx_global - 1] - 1;
  obj->isActiveConstr[(obj->isActiveIdx[TYPE_tmp] + obj->Wlocalidx[idx_global -
                       1]) - 2] = false;
  obj->Wid[idx_global - 1] = obj->Wid[obj->nActiveConstr - 1];
  obj->Wlocalidx[idx_global - 1] = obj->Wlocalidx[obj->nActiveConstr - 1];
  b = static_cast<uint8_T>(obj->nVar);
  for (int32_T idx = 0; idx < b; idx++) {
    obj->ATwset[idx + 21 * (idx_global - 1)] = obj->ATwset[(obj->nActiveConstr -
      1) * 21 + idx];
  }

  obj->bwset[idx_global - 1] = obj->bwset[obj->nActiveConstr - 1];
  obj->nActiveConstr--;
  obj->nWConstr[TYPE_tmp]--;
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motion_control_removeEqConstr_i
  (sVIU4VBONGRsUytHTQmMJFH_motio_T *obj, int32_T idx_global)
{
  int32_T TYPE_tmp;
  int32_T b_tmp;
  int32_T idx;
  int32_T totalEq;
  totalEq = (obj->nWConstr[0] + obj->nWConstr[1]) - 1;
  if ((totalEq + 1 != 0) && (idx_global <= totalEq + 1)) {
    if ((totalEq + 1 == obj->nActiveConstr) || (totalEq + 1 == idx_global)) {
      obj->mEqRemoved++;
      motion_controlle_removeConstr_n(obj, idx_global);
    } else {
      obj->mEqRemoved++;
      TYPE_tmp = obj->Wid[idx_global - 1] - 1;
      obj->isActiveConstr[(obj->isActiveIdx[TYPE_tmp] + obj->
                           Wlocalidx[idx_global - 1]) - 2] = false;
      obj->Wid[idx_global - 1] = obj->Wid[totalEq];
      obj->Wlocalidx[idx_global - 1] = obj->Wlocalidx[totalEq];
      b_tmp = static_cast<uint8_T>(obj->nVar);
      for (idx = 0; idx < b_tmp; idx++) {
        obj->ATwset[idx + 21 * (idx_global - 1)] = obj->ATwset[21 * totalEq +
          idx];
      }

      obj->bwset[idx_global - 1] = obj->bwset[totalEq];
      obj->Wid[totalEq] = obj->Wid[obj->nActiveConstr - 1];
      obj->Wlocalidx[totalEq] = obj->Wlocalidx[obj->nActiveConstr - 1];
      for (idx = 0; idx < b_tmp; idx++) {
        obj->ATwset[idx + 21 * totalEq] = obj->ATwset[(obj->nActiveConstr - 1) *
          21 + idx];
      }

      obj->bwset[totalEq] = obj->bwset[obj->nActiveConstr - 1];
      obj->nActiveConstr--;
      obj->nWConstr[TYPE_tmp]--;
    }
  }
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motion_c_RemoveDependentIneq__e
  (sVIU4VBONGRsUytHTQmMJFH_motio_T *workingset, sIZAIOglGM5dPDQlNukc9SD_motio_T *
   qrmanager, s3cSGkBdKxRj6Qn3zsJRowG_motio_T *memspace, real_T tolfactor)
{
  motion_controller_withPIC_B.nActiveConstr_tmp = workingset->nActiveConstr;
  motion_controller_withPIC_B.nFixedConstr = workingset->nWConstr[0] +
    workingset->nWConstr[1];
  motion_controller_withPIC_B.nVar = workingset->nVar;
  if ((workingset->nWConstr[2] + workingset->nWConstr[3]) + workingset->
      nWConstr[4] > 0) {
    motion_controller_withPIC_B.tol_e = tolfactor * static_cast<real_T>
      (workingset->nVar) * 2.2204460492503131E-16;
    for (motion_controller_withPIC_B.nDepIneq = 0;
         motion_controller_withPIC_B.nDepIneq <
         motion_controller_withPIC_B.nFixedConstr;
         motion_controller_withPIC_B.nDepIneq++) {
      qrmanager->jpvt[motion_controller_withPIC_B.nDepIneq] = 1;
    }

    if (motion_controller_withPIC_B.nFixedConstr + 1 <=
        motion_controller_withPIC_B.nActiveConstr_tmp) {
      memset(&qrmanager->jpvt[motion_controller_withPIC_B.nFixedConstr], 0,
             static_cast<uint32_T>(motion_controller_withPIC_B.nActiveConstr_tmp
              - motion_controller_withPIC_B.nFixedConstr) * sizeof(int32_T));
    }

    for (motion_controller_withPIC_B.nDepIneq = 0;
         motion_controller_withPIC_B.nDepIneq <
         motion_controller_withPIC_B.nActiveConstr_tmp;
         motion_controller_withPIC_B.nDepIneq++) {
      motion_controller_withPIC_B.iy0_tmp_g = 21 *
        motion_controller_withPIC_B.nDepIneq;
      motion_controller_withPIC_B.c_ge = static_cast<uint8_T>
        (motion_controller_withPIC_B.nVar);
      memcpy(&qrmanager->QR[motion_controller_withPIC_B.iy0_tmp_g],
             &workingset->ATwset[motion_controller_withPIC_B.iy0_tmp_g],
             static_cast<uint32_T>((motion_controller_withPIC_B.c_ge +
               motion_controller_withPIC_B.iy0_tmp_g) -
              motion_controller_withPIC_B.iy0_tmp_g) * sizeof(real_T));
    }

    motion_controller_w_factorQRE_c(qrmanager, workingset->nVar,
      workingset->nActiveConstr);
    motion_controller_withPIC_B.nDepIneq = 0;
    motion_controller_withPIC_B.nActiveConstr_tmp = workingset->nActiveConstr -
      1;
    while (motion_controller_withPIC_B.nActiveConstr_tmp + 1 >
           motion_controller_withPIC_B.nVar) {
      motion_controller_withPIC_B.nDepIneq++;
      memspace->workspace_int[motion_controller_withPIC_B.nDepIneq - 1] =
        qrmanager->jpvt[motion_controller_withPIC_B.nActiveConstr_tmp];
      motion_controller_withPIC_B.nActiveConstr_tmp--;
    }

    if (motion_controller_withPIC_B.nActiveConstr_tmp + 1 <= workingset->nVar) {
      motion_controller_withPIC_B.nVar = 21 *
        motion_controller_withPIC_B.nActiveConstr_tmp +
        motion_controller_withPIC_B.nActiveConstr_tmp;
      while ((motion_controller_withPIC_B.nActiveConstr_tmp + 1 >
              motion_controller_withPIC_B.nFixedConstr) && (fabs(qrmanager->
               QR[motion_controller_withPIC_B.nVar]) <
              motion_controller_withPIC_B.tol_e)) {
        motion_controller_withPIC_B.nDepIneq++;
        memspace->workspace_int[motion_controller_withPIC_B.nDepIneq - 1] =
          qrmanager->jpvt[motion_controller_withPIC_B.nActiveConstr_tmp];
        motion_controller_withPIC_B.nActiveConstr_tmp--;
        motion_controller_withPIC_B.nVar -= 22;
      }
    }

    countsort_JblpZJs7(memspace->workspace_int,
                       motion_controller_withPIC_B.nDepIneq,
                       memspace->workspace_sort,
                       motion_controller_withPIC_B.nFixedConstr + 1,
                       workingset->nActiveConstr);
    for (motion_controller_withPIC_B.nFixedConstr =
         motion_controller_withPIC_B.nDepIneq;
         motion_controller_withPIC_B.nFixedConstr >= 1;
         motion_controller_withPIC_B.nFixedConstr--) {
      motion_controlle_removeConstr_n(workingset, memspace->
        workspace_int[motion_controller_withPIC_B.nFixedConstr - 1]);
    }
  }
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motion_controller_wi_factorQR_c
  (sIZAIOglGM5dPDQlNukc9SD_motio_T *obj, const real_T A[1701], int32_T mrows,
   int32_T ncols)
{
  static const int32_T offsets[4] = { 0, 1, 2, 3 };

  __m128i tmp;
  boolean_T guard1;
  motion_controller_withPIC_B.k_d = mrows * ncols;
  guard1 = false;
  if (motion_controller_withPIC_B.k_d > 0) {
    for (motion_controller_withPIC_B.i_a2 = 0; motion_controller_withPIC_B.i_a2 <
         ncols; motion_controller_withPIC_B.i_a2++) {
      motion_controller_withPIC_B.ix0_tmp = 21 *
        motion_controller_withPIC_B.i_a2;
      motion_controller_withPIC_B.k_d = static_cast<uint8_T>(mrows);
      memcpy(&obj->QR[motion_controller_withPIC_B.ix0_tmp],
             &A[motion_controller_withPIC_B.ix0_tmp], static_cast<uint32_T>
             ((motion_controller_withPIC_B.k_d +
               motion_controller_withPIC_B.ix0_tmp) -
              motion_controller_withPIC_B.ix0_tmp) * sizeof(real_T));
    }

    guard1 = true;
  } else if (motion_controller_withPIC_B.k_d == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    guard1 = true;
  }

  if (guard1) {
    obj->usedPivoting = false;
    obj->mrows = mrows;
    obj->ncols = ncols;
    motion_controller_withPIC_B.k_d = (ncols / 4) << 2;
    motion_controller_withPIC_B.ix0_tmp = motion_controller_withPIC_B.k_d - 4;
    for (motion_controller_withPIC_B.i_a2 = 0; motion_controller_withPIC_B.i_a2 <=
         motion_controller_withPIC_B.ix0_tmp; motion_controller_withPIC_B.i_a2 +=
         4) {
      tmp = _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32
        (motion_controller_withPIC_B.i_a2), _mm_loadu_si128((const __m128i *)
        &offsets[0])), _mm_set1_epi32(1));
      _mm_storeu_si128((__m128i *)&obj->jpvt[motion_controller_withPIC_B.i_a2],
                       tmp);
    }

    for (motion_controller_withPIC_B.i_a2 = motion_controller_withPIC_B.k_d;
         motion_controller_withPIC_B.i_a2 < ncols;
         motion_controller_withPIC_B.i_a2++) {
      obj->jpvt[motion_controller_withPIC_B.i_a2] =
        motion_controller_withPIC_B.i_a2 + 1;
    }

    if (mrows <= ncols) {
      motion_controller_withPIC_B.k_d = mrows;
    } else {
      motion_controller_withPIC_B.k_d = ncols;
    }

    obj->minRowCol = motion_controller_withPIC_B.k_d;
    memset(&obj->tau[0], 0, 21U * sizeof(real_T));
    if (motion_controller_withPIC_B.k_d >= 1) {
      memset(&obj->tau[0], 0, 21U * sizeof(real_T));
      motion_controller__qrf_nGv3LI5p(obj->QR, mrows, ncols,
        motion_controller_withPIC_B.k_d, obj->tau);
    }
  }
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motion_controlle_xgemv_7iafTBwP(int32_T m, const
  real_T A[840], const real_T x[1701], real_T y[81])
{
  for (motion_controller_withPIC_B.b_iy_p = 0;
       motion_controller_withPIC_B.b_iy_p <= 38;
       motion_controller_withPIC_B.b_iy_p += 2) {
    __m128d tmp;
    tmp = _mm_loadu_pd(&y[motion_controller_withPIC_B.b_iy_p]);
    _mm_storeu_pd(&y[motion_controller_withPIC_B.b_iy_p], _mm_mul_pd(tmp,
      _mm_set1_pd(-1.0)));
  }

  for (motion_controller_withPIC_B.b_iy_p = 0;
       motion_controller_withPIC_B.b_iy_p <= 819;
       motion_controller_withPIC_B.b_iy_p += 21) {
    motion_controller_withPIC_B.c_j3 = 0.0;
    motion_controller_withPIC_B.b_p2 = motion_controller_withPIC_B.b_iy_p + m;
    for (motion_controller_withPIC_B.ia_ap = motion_controller_withPIC_B.b_iy_p
         + 1; motion_controller_withPIC_B.ia_ap <=
         motion_controller_withPIC_B.b_p2; motion_controller_withPIC_B.ia_ap++)
    {
      motion_controller_withPIC_B.c_j3 += x[(motion_controller_withPIC_B.ia_ap -
        motion_controller_withPIC_B.b_iy_p) - 1] *
        A[motion_controller_withPIC_B.ia_ap - 1];
    }

    motion_controller_withPIC_B.ia_ap = div_nde_s32_floor
      (motion_controller_withPIC_B.b_iy_p, 21);
    y[motion_controller_withPIC_B.ia_ap] += motion_controller_withPIC_B.c_j3;
  }
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motion_controlle_xgemv_vyHQ2Zvi(int32_T m, const
  real_T A[840], const real_T x[1701], real_T y[81])
{
  for (motion_controller_withPIC_B.b_iy_c = 0;
       motion_controller_withPIC_B.b_iy_c <= 38;
       motion_controller_withPIC_B.b_iy_c += 2) {
    __m128d tmp;
    tmp = _mm_loadu_pd(&y[motion_controller_withPIC_B.b_iy_c]);
    _mm_storeu_pd(&y[motion_controller_withPIC_B.b_iy_c], _mm_mul_pd(tmp,
      _mm_set1_pd(-1.0)));
  }

  for (motion_controller_withPIC_B.b_iy_c = 0;
       motion_controller_withPIC_B.b_iy_c <= 819;
       motion_controller_withPIC_B.b_iy_c += 21) {
    motion_controller_withPIC_B.c_hn = 0.0;
    motion_controller_withPIC_B.b_g4 = motion_controller_withPIC_B.b_iy_c + m;
    for (motion_controller_withPIC_B.ia_b = motion_controller_withPIC_B.b_iy_c +
         1; motion_controller_withPIC_B.ia_b <= motion_controller_withPIC_B.b_g4;
         motion_controller_withPIC_B.ia_b++) {
      motion_controller_withPIC_B.c_hn += x[(motion_controller_withPIC_B.ia_b -
        motion_controller_withPIC_B.b_iy_c) + 80] *
        A[motion_controller_withPIC_B.ia_b - 1];
    }

    motion_controller_withPIC_B.ia_b = div_nde_s32_floor
      (motion_controller_withPIC_B.b_iy_c, 21);
    y[motion_controller_withPIC_B.ia_b] += motion_controller_withPIC_B.c_hn;
  }
}

// Function for MATLAB Function: '<S63>/solvex'
boolean_T motion_controller_withPIC::motio_feasibleX0ForWorkingSet_c(real_T
  workspace[1701], real_T xCurrent[21], sVIU4VBONGRsUytHTQmMJFH_motio_T
  *workingset, sIZAIOglGM5dPDQlNukc9SD_motio_T *qrmanager)
{
  __m128d tmp;
  __m128d tmp_0;
  boolean_T nonDegenerateWset;
  static const int32_T offsets[4] = { 0, 1, 2, 3 };

  __m128i tmp_1;
  int32_T exitg1;
  motion_controller_withPIC_B.mWConstr_tmp_tmp_j = workingset->nActiveConstr - 1;
  motion_controller_withPIC_B.nVar_tmp_tmp_m = workingset->nVar;
  nonDegenerateWset = true;
  if (workingset->nActiveConstr != 0) {
    for (motion_controller_withPIC_B.idx_f = 0;
         motion_controller_withPIC_B.idx_f <=
         motion_controller_withPIC_B.mWConstr_tmp_tmp_j;
         motion_controller_withPIC_B.idx_f++) {
      workspace[motion_controller_withPIC_B.idx_f] = workingset->
        bwset[motion_controller_withPIC_B.idx_f];
      workspace[motion_controller_withPIC_B.idx_f + 81] = workingset->
        bwset[motion_controller_withPIC_B.idx_f];
    }

    if (workingset->nActiveConstr != 0) {
      motion_controller_withPIC_B.d_a = (workingset->nActiveConstr - 1) * 21 + 1;
      for (motion_controller_withPIC_B.iac_m = 1;
           motion_controller_withPIC_B.iac_m <= motion_controller_withPIC_B.d_a;
           motion_controller_withPIC_B.iac_m += 21) {
        motion_controller_withPIC_B.c_h = 0.0;
        motion_controller_withPIC_B.jBcol_g = (motion_controller_withPIC_B.iac_m
          + motion_controller_withPIC_B.nVar_tmp_tmp_m) - 1;
        for (motion_controller_withPIC_B.idx_f =
             motion_controller_withPIC_B.iac_m;
             motion_controller_withPIC_B.idx_f <=
             motion_controller_withPIC_B.jBcol_g;
             motion_controller_withPIC_B.idx_f++) {
          motion_controller_withPIC_B.c_h += workingset->
            ATwset[motion_controller_withPIC_B.idx_f - 1] *
            xCurrent[motion_controller_withPIC_B.idx_f -
            motion_controller_withPIC_B.iac_m];
        }

        motion_controller_withPIC_B.idx_f = div_nde_s32_floor
          (motion_controller_withPIC_B.iac_m - 1, 21);
        workspace[motion_controller_withPIC_B.idx_f] -=
          motion_controller_withPIC_B.c_h;
      }
    }

    if (workingset->nActiveConstr >= workingset->nVar) {
      motion_controller_withPIC_B.d_a = static_cast<uint8_T>(workingset->nVar);
      for (motion_controller_withPIC_B.idx_f = 0;
           motion_controller_withPIC_B.idx_f < motion_controller_withPIC_B.d_a;
           motion_controller_withPIC_B.idx_f++) {
        motion_controller_withPIC_B.jBcol_g = 21 *
          motion_controller_withPIC_B.idx_f;
        for (motion_controller_withPIC_B.iac_m = 0;
             motion_controller_withPIC_B.iac_m <=
             motion_controller_withPIC_B.mWConstr_tmp_tmp_j;
             motion_controller_withPIC_B.iac_m++) {
          qrmanager->QR[motion_controller_withPIC_B.iac_m +
            motion_controller_withPIC_B.jBcol_g] = workingset->ATwset[21 *
            motion_controller_withPIC_B.iac_m +
            motion_controller_withPIC_B.idx_f];
        }
      }

      qrmanager->usedPivoting = false;
      qrmanager->mrows = workingset->nActiveConstr;
      qrmanager->ncols = workingset->nVar;
      motion_controller_withPIC_B.jBcol_g = (static_cast<uint8_T>
        (workingset->nVar) / 4) << 2;
      motion_controller_withPIC_B.iAcol_n = motion_controller_withPIC_B.jBcol_g
        - 4;
      for (motion_controller_withPIC_B.idx_f = 0;
           motion_controller_withPIC_B.idx_f <=
           motion_controller_withPIC_B.iAcol_n;
           motion_controller_withPIC_B.idx_f += 4) {
        tmp_1 = _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32
          (motion_controller_withPIC_B.idx_f), _mm_loadu_si128((const __m128i *)
          &offsets[0])), _mm_set1_epi32(1));
        _mm_storeu_si128((__m128i *)&qrmanager->
                         jpvt[motion_controller_withPIC_B.idx_f], tmp_1);
      }

      for (motion_controller_withPIC_B.idx_f =
           motion_controller_withPIC_B.jBcol_g;
           motion_controller_withPIC_B.idx_f < motion_controller_withPIC_B.d_a;
           motion_controller_withPIC_B.idx_f++) {
        qrmanager->jpvt[motion_controller_withPIC_B.idx_f] =
          motion_controller_withPIC_B.idx_f + 1;
      }

      if (workingset->nActiveConstr <= workingset->nVar) {
        motion_controller_withPIC_B.idx_f = workingset->nActiveConstr;
      } else {
        motion_controller_withPIC_B.idx_f = workingset->nVar;
      }

      qrmanager->minRowCol = motion_controller_withPIC_B.idx_f;
      memcpy(&motion_controller_withPIC_B.B_g[0], &qrmanager->QR[0], 1701U *
             sizeof(real_T));
      memset(&qrmanager->tau[0], 0, 21U * sizeof(real_T));
      if (motion_controller_withPIC_B.idx_f >= 1) {
        memset(&qrmanager->tau[0], 0, 21U * sizeof(real_T));
        motion_controller__qrf_nGv3LI5p(motion_controller_withPIC_B.B_g,
          workingset->nActiveConstr, workingset->nVar,
          motion_controller_withPIC_B.idx_f, qrmanager->tau);
      }

      memcpy(&qrmanager->QR[0], &motion_controller_withPIC_B.B_g[0], 1701U *
             sizeof(real_T));
      motion_controller_w_computeQ__l(qrmanager, qrmanager->mrows);
      memcpy(&motion_controller_withPIC_B.B_g[0], &workspace[0], 1701U * sizeof
             (real_T));
      for (motion_controller_withPIC_B.idx_f = 0;
           motion_controller_withPIC_B.idx_f <= 81;
           motion_controller_withPIC_B.idx_f += 81) {
        motion_controller_withPIC_B.d_a = motion_controller_withPIC_B.idx_f +
          motion_controller_withPIC_B.nVar_tmp_tmp_m;
        for (motion_controller_withPIC_B.iac_m =
             motion_controller_withPIC_B.idx_f + 1;
             motion_controller_withPIC_B.iac_m <=
             motion_controller_withPIC_B.d_a; motion_controller_withPIC_B.iac_m
             ++) {
          workspace[motion_controller_withPIC_B.iac_m - 1] = 0.0;
        }
      }

      motion_controller_withPIC_B.jBcol_g = -1;
      for (motion_controller_withPIC_B.idx_f = 0;
           motion_controller_withPIC_B.idx_f <= 81;
           motion_controller_withPIC_B.idx_f += 81) {
        motion_controller_withPIC_B.iAcol_n = -1;
        motion_controller_withPIC_B.br_c = motion_controller_withPIC_B.idx_f +
          motion_controller_withPIC_B.nVar_tmp_tmp_m;
        for (motion_controller_withPIC_B.iac_m =
             motion_controller_withPIC_B.idx_f + 1;
             motion_controller_withPIC_B.iac_m <=
             motion_controller_withPIC_B.br_c; motion_controller_withPIC_B.iac_m
             ++) {
          motion_controller_withPIC_B.c_h = 0.0;
          for (motion_controller_withPIC_B.d_a = 0;
               motion_controller_withPIC_B.d_a <=
               motion_controller_withPIC_B.mWConstr_tmp_tmp_j;
               motion_controller_withPIC_B.d_a++) {
            motion_controller_withPIC_B.c_h += qrmanager->Q
              [(motion_controller_withPIC_B.d_a +
                motion_controller_withPIC_B.iAcol_n) + 1] *
              motion_controller_withPIC_B.B_g[(motion_controller_withPIC_B.d_a +
              motion_controller_withPIC_B.jBcol_g) + 1];
          }

          workspace[motion_controller_withPIC_B.iac_m - 1] +=
            motion_controller_withPIC_B.c_h;
          motion_controller_withPIC_B.iAcol_n += 21;
        }

        motion_controller_withPIC_B.jBcol_g += 81;
      }

      for (motion_controller_withPIC_B.mWConstr_tmp_tmp_j = 0;
           motion_controller_withPIC_B.mWConstr_tmp_tmp_j < 2;
           motion_controller_withPIC_B.mWConstr_tmp_tmp_j++) {
        motion_controller_withPIC_B.iAcol_n = 81 *
          motion_controller_withPIC_B.mWConstr_tmp_tmp_j - 1;
        for (motion_controller_withPIC_B.d_a =
             motion_controller_withPIC_B.nVar_tmp_tmp_m;
             motion_controller_withPIC_B.d_a >= 1;
             motion_controller_withPIC_B.d_a--) {
          motion_controller_withPIC_B.br_c = (motion_controller_withPIC_B.d_a -
            1) * 21;
          motion_controller_withPIC_B.idx_f = motion_controller_withPIC_B.d_a +
            motion_controller_withPIC_B.iAcol_n;
          motion_controller_withPIC_B.c_h =
            workspace[motion_controller_withPIC_B.idx_f];
          if (motion_controller_withPIC_B.c_h != 0.0) {
            workspace[motion_controller_withPIC_B.idx_f] =
              motion_controller_withPIC_B.c_h / qrmanager->QR
              [(motion_controller_withPIC_B.d_a +
                motion_controller_withPIC_B.br_c) - 1];
            motion_controller_withPIC_B.ar_d = static_cast<uint8_T>
              (motion_controller_withPIC_B.d_a - 1);
            for (motion_controller_withPIC_B.jBcol_g = 0;
                 motion_controller_withPIC_B.jBcol_g <
                 motion_controller_withPIC_B.ar_d;
                 motion_controller_withPIC_B.jBcol_g++) {
              motion_controller_withPIC_B.iac_m =
                (motion_controller_withPIC_B.jBcol_g +
                 motion_controller_withPIC_B.iAcol_n) + 1;
              workspace[motion_controller_withPIC_B.iac_m] -= qrmanager->
                QR[motion_controller_withPIC_B.jBcol_g +
                motion_controller_withPIC_B.br_c] *
                workspace[motion_controller_withPIC_B.idx_f];
            }
          }
        }
      }
    } else {
      motion_controller_wi_factorQR_c(qrmanager, workingset->ATwset,
        workingset->nVar, workingset->nActiveConstr);
      motion_controller_w_computeQ__l(qrmanager, qrmanager->minRowCol);
      for (motion_controller_withPIC_B.idx_f = 0;
           motion_controller_withPIC_B.idx_f < 2;
           motion_controller_withPIC_B.idx_f++) {
        motion_controller_withPIC_B.jBcol_g = 81 *
          motion_controller_withPIC_B.idx_f;
        for (motion_controller_withPIC_B.iac_m = 0;
             motion_controller_withPIC_B.iac_m <=
             motion_controller_withPIC_B.mWConstr_tmp_tmp_j;
             motion_controller_withPIC_B.iac_m++) {
          motion_controller_withPIC_B.iAcol_n = 21 *
            motion_controller_withPIC_B.iac_m;
          motion_controller_withPIC_B.br_c = motion_controller_withPIC_B.iac_m +
            motion_controller_withPIC_B.jBcol_g;
          motion_controller_withPIC_B.c_h =
            workspace[motion_controller_withPIC_B.br_c];
          motion_controller_withPIC_B.ar_d = static_cast<uint8_T>
            (motion_controller_withPIC_B.iac_m);
          for (motion_controller_withPIC_B.d_a = 0;
               motion_controller_withPIC_B.d_a <
               motion_controller_withPIC_B.ar_d; motion_controller_withPIC_B.d_a
               ++) {
            motion_controller_withPIC_B.c_h -= qrmanager->
              QR[motion_controller_withPIC_B.d_a +
              motion_controller_withPIC_B.iAcol_n] *
              workspace[motion_controller_withPIC_B.d_a +
              motion_controller_withPIC_B.jBcol_g];
          }

          workspace[motion_controller_withPIC_B.br_c] =
            motion_controller_withPIC_B.c_h / qrmanager->
            QR[motion_controller_withPIC_B.iac_m +
            motion_controller_withPIC_B.iAcol_n];
        }
      }

      memcpy(&motion_controller_withPIC_B.B_g[0], &workspace[0], 1701U * sizeof
             (real_T));
      for (motion_controller_withPIC_B.idx_f = 0;
           motion_controller_withPIC_B.idx_f <= 81;
           motion_controller_withPIC_B.idx_f += 81) {
        motion_controller_withPIC_B.d_a = motion_controller_withPIC_B.idx_f +
          motion_controller_withPIC_B.nVar_tmp_tmp_m;
        for (motion_controller_withPIC_B.iac_m =
             motion_controller_withPIC_B.idx_f + 1;
             motion_controller_withPIC_B.iac_m <=
             motion_controller_withPIC_B.d_a; motion_controller_withPIC_B.iac_m
             ++) {
          workspace[motion_controller_withPIC_B.iac_m - 1] = 0.0;
        }
      }

      motion_controller_withPIC_B.br_c = 1;
      for (motion_controller_withPIC_B.idx_f = 0;
           motion_controller_withPIC_B.idx_f <= 81;
           motion_controller_withPIC_B.idx_f += 81) {
        motion_controller_withPIC_B.ar_d = -1;
        motion_controller_withPIC_B.h_k = motion_controller_withPIC_B.br_c +
          motion_controller_withPIC_B.mWConstr_tmp_tmp_j;
        for (motion_controller_withPIC_B.iac_m =
             motion_controller_withPIC_B.br_c; motion_controller_withPIC_B.iac_m
             <= motion_controller_withPIC_B.h_k;
             motion_controller_withPIC_B.iac_m++) {
          motion_controller_withPIC_B.l_c = motion_controller_withPIC_B.idx_f +
            motion_controller_withPIC_B.nVar_tmp_tmp_m;
          motion_controller_withPIC_B.jBcol_g =
            ((((motion_controller_withPIC_B.l_c -
                motion_controller_withPIC_B.idx_f) / 2) << 1) +
             motion_controller_withPIC_B.idx_f) + 1;
          motion_controller_withPIC_B.iAcol_n =
            motion_controller_withPIC_B.jBcol_g - 2;
          for (motion_controller_withPIC_B.d_a =
               motion_controller_withPIC_B.idx_f + 1;
               motion_controller_withPIC_B.d_a <=
               motion_controller_withPIC_B.iAcol_n;
               motion_controller_withPIC_B.d_a += 2) {
            tmp = _mm_loadu_pd(&qrmanager->Q[(motion_controller_withPIC_B.ar_d +
              motion_controller_withPIC_B.d_a) -
                               motion_controller_withPIC_B.idx_f]);
            tmp_0 = _mm_loadu_pd(&workspace[motion_controller_withPIC_B.d_a - 1]);
            _mm_storeu_pd(&workspace[motion_controller_withPIC_B.d_a - 1],
                          _mm_add_pd(_mm_mul_pd(tmp, _mm_set1_pd
              (motion_controller_withPIC_B.B_g[motion_controller_withPIC_B.iac_m
               - 1])), tmp_0));
          }

          for (motion_controller_withPIC_B.d_a =
               motion_controller_withPIC_B.jBcol_g;
               motion_controller_withPIC_B.d_a <=
               motion_controller_withPIC_B.l_c; motion_controller_withPIC_B.d_a
               ++) {
            workspace[motion_controller_withPIC_B.d_a - 1] += qrmanager->Q
              [(motion_controller_withPIC_B.ar_d +
                motion_controller_withPIC_B.d_a) -
              motion_controller_withPIC_B.idx_f] *
              motion_controller_withPIC_B.B_g[motion_controller_withPIC_B.iac_m
              - 1];
          }

          motion_controller_withPIC_B.ar_d += 21;
        }

        motion_controller_withPIC_B.br_c += 81;
      }
    }

    motion_controller_withPIC_B.mWConstr_tmp_tmp_j = 0;
    do {
      exitg1 = 0;
      if (motion_controller_withPIC_B.mWConstr_tmp_tmp_j <= static_cast<uint8_T>
          (motion_controller_withPIC_B.nVar_tmp_tmp_m) - 1) {
        if (rtIsInf(workspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_j]) ||
            rtIsNaN(workspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_j]))
        {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          motion_controller_withPIC_B.c_h =
            workspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_j + 81];
          if (rtIsInf(motion_controller_withPIC_B.c_h) || rtIsNaN
              (motion_controller_withPIC_B.c_h)) {
            nonDegenerateWset = false;
            exitg1 = 1;
          } else {
            motion_controller_withPIC_B.mWConstr_tmp_tmp_j++;
          }
        }
      } else {
        motion_controller_withPIC_B.jBcol_g =
          (motion_controller_withPIC_B.nVar_tmp_tmp_m / 2) << 1;
        motion_controller_withPIC_B.iAcol_n =
          motion_controller_withPIC_B.jBcol_g - 2;
        for (motion_controller_withPIC_B.mWConstr_tmp_tmp_j = 0;
             motion_controller_withPIC_B.mWConstr_tmp_tmp_j <=
             motion_controller_withPIC_B.iAcol_n;
             motion_controller_withPIC_B.mWConstr_tmp_tmp_j += 2) {
          tmp = _mm_loadu_pd
            (&workspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_j]);
          tmp_0 = _mm_loadu_pd
            (&xCurrent[motion_controller_withPIC_B.mWConstr_tmp_tmp_j]);
          _mm_storeu_pd
            (&workspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_j],
             _mm_add_pd(tmp, tmp_0));
        }

        for (motion_controller_withPIC_B.mWConstr_tmp_tmp_j =
             motion_controller_withPIC_B.jBcol_g;
             motion_controller_withPIC_B.mWConstr_tmp_tmp_j <
             motion_controller_withPIC_B.nVar_tmp_tmp_m;
             motion_controller_withPIC_B.mWConstr_tmp_tmp_j++) {
          workspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_j] +=
            xCurrent[motion_controller_withPIC_B.mWConstr_tmp_tmp_j];
        }

        if (workingset->probType == 2) {
          motion_controller_withPIC_B.c_h = 0.0;
          memcpy(&workingset->maxConstrWorkspace[0], &workingset->bineq[0], 40U *
                 sizeof(real_T));
          motion_controlle_xgemv_7iafTBwP(20, workingset->Aineq, workspace,
            workingset->maxConstrWorkspace);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp_j = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_j < 40;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_j++) {
            motion_controller_withPIC_B.u1_d = workingset->
              maxConstrWorkspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_j]
              - workspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_j + 20];
            workingset->
              maxConstrWorkspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_j]
              = motion_controller_withPIC_B.u1_d;
            if ((!(motion_controller_withPIC_B.c_h >=
                   motion_controller_withPIC_B.u1_d)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1_d))) {
              motion_controller_withPIC_B.c_h = motion_controller_withPIC_B.u1_d;
            }
          }
        } else {
          motion_controller_withPIC_B.c_h = 0.0;
          memcpy(&workingset->maxConstrWorkspace[0], &workingset->bineq[0], 40U *
                 sizeof(real_T));
          motion_controlle_xgemv_7iafTBwP(workingset->nVar, workingset->Aineq,
            workspace, workingset->maxConstrWorkspace);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp_j = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_j < 40;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_j++) {
            motion_controller_withPIC_B.u1_d = workingset->
              maxConstrWorkspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_j];
            if ((!(motion_controller_withPIC_B.c_h >=
                   motion_controller_withPIC_B.u1_d)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1_d))) {
              motion_controller_withPIC_B.c_h = motion_controller_withPIC_B.u1_d;
            }
          }
        }

        if (workingset->sizes[3] > 0) {
          motion_controller_withPIC_B.idx_f = static_cast<uint8_T>
            (workingset->sizes[3]);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp_j = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_j <
               motion_controller_withPIC_B.idx_f;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_j++) {
            motion_controller_withPIC_B.u1_d = -workspace[workingset->
              indexLB[motion_controller_withPIC_B.mWConstr_tmp_tmp_j] - 1] -
              workingset->lb[workingset->
              indexLB[motion_controller_withPIC_B.mWConstr_tmp_tmp_j] - 1];
            if ((!(motion_controller_withPIC_B.c_h >=
                   motion_controller_withPIC_B.u1_d)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1_d))) {
              motion_controller_withPIC_B.c_h = motion_controller_withPIC_B.u1_d;
            }
          }
        }

        if (workingset->sizes[4] > 0) {
          motion_controller_withPIC_B.idx_f = static_cast<uint8_T>
            (workingset->sizes[4]);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp_j = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_j <
               motion_controller_withPIC_B.idx_f;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_j++) {
            motion_controller_withPIC_B.u1_d = workspace[workingset->
              indexUB[motion_controller_withPIC_B.mWConstr_tmp_tmp_j] - 1] -
              workingset->ub[workingset->
              indexUB[motion_controller_withPIC_B.mWConstr_tmp_tmp_j] - 1];
            if ((!(motion_controller_withPIC_B.c_h >=
                   motion_controller_withPIC_B.u1_d)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1_d))) {
              motion_controller_withPIC_B.c_h = motion_controller_withPIC_B.u1_d;
            }
          }
        }

        if (workingset->sizes[0] > 0) {
          motion_controller_withPIC_B.idx_f = static_cast<uint8_T>
            (workingset->sizes[0]);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp_j = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_j <
               motion_controller_withPIC_B.idx_f;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_j++) {
            motion_controller_withPIC_B.u1_d = fabs(workspace
              [workingset->
              indexFixed[motion_controller_withPIC_B.mWConstr_tmp_tmp_j] - 1] -
              workingset->ub[workingset->
              indexFixed[motion_controller_withPIC_B.mWConstr_tmp_tmp_j] - 1]);
            if ((!(motion_controller_withPIC_B.c_h >=
                   motion_controller_withPIC_B.u1_d)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1_d))) {
              motion_controller_withPIC_B.c_h = motion_controller_withPIC_B.u1_d;
            }
          }
        }

        if (workingset->probType == 2) {
          motion_controller_withPIC_B.d_v_f = 0.0;
          memcpy(&workingset->maxConstrWorkspace[0], &workingset->bineq[0], 40U *
                 sizeof(real_T));
          motion_controlle_xgemv_vyHQ2Zvi(20, workingset->Aineq, workspace,
            workingset->maxConstrWorkspace);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp_j = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_j < 40;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_j++) {
            motion_controller_withPIC_B.u1_d = workingset->
              maxConstrWorkspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_j]
              - workspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_j + 101];
            workingset->
              maxConstrWorkspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_j]
              = motion_controller_withPIC_B.u1_d;
            if ((!(motion_controller_withPIC_B.d_v_f >=
                   motion_controller_withPIC_B.u1_d)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1_d))) {
              motion_controller_withPIC_B.d_v_f =
                motion_controller_withPIC_B.u1_d;
            }
          }
        } else {
          motion_controller_withPIC_B.d_v_f = 0.0;
          memcpy(&workingset->maxConstrWorkspace[0], &workingset->bineq[0], 40U *
                 sizeof(real_T));
          motion_controlle_xgemv_vyHQ2Zvi(workingset->nVar, workingset->Aineq,
            workspace, workingset->maxConstrWorkspace);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp_j = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_j < 40;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_j++) {
            motion_controller_withPIC_B.u1_d = workingset->
              maxConstrWorkspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_j];
            if ((!(motion_controller_withPIC_B.d_v_f >=
                   motion_controller_withPIC_B.u1_d)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1_d))) {
              motion_controller_withPIC_B.d_v_f =
                motion_controller_withPIC_B.u1_d;
            }
          }
        }

        if (workingset->sizes[3] > 0) {
          motion_controller_withPIC_B.idx_f = static_cast<uint8_T>
            (workingset->sizes[3]);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp_j = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_j <
               motion_controller_withPIC_B.idx_f;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_j++) {
            motion_controller_withPIC_B.u1_d = -workspace[workingset->
              indexLB[motion_controller_withPIC_B.mWConstr_tmp_tmp_j] + 80] -
              workingset->lb[workingset->
              indexLB[motion_controller_withPIC_B.mWConstr_tmp_tmp_j] - 1];
            if ((!(motion_controller_withPIC_B.d_v_f >=
                   motion_controller_withPIC_B.u1_d)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1_d))) {
              motion_controller_withPIC_B.d_v_f =
                motion_controller_withPIC_B.u1_d;
            }
          }
        }

        if (workingset->sizes[4] > 0) {
          motion_controller_withPIC_B.idx_f = static_cast<uint8_T>
            (workingset->sizes[4]);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp_j = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_j <
               motion_controller_withPIC_B.idx_f;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_j++) {
            motion_controller_withPIC_B.u1_d = workspace[workingset->
              indexUB[motion_controller_withPIC_B.mWConstr_tmp_tmp_j] + 80] -
              workingset->ub[workingset->
              indexUB[motion_controller_withPIC_B.mWConstr_tmp_tmp_j] - 1];
            if ((!(motion_controller_withPIC_B.d_v_f >=
                   motion_controller_withPIC_B.u1_d)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1_d))) {
              motion_controller_withPIC_B.d_v_f =
                motion_controller_withPIC_B.u1_d;
            }
          }
        }

        if (workingset->sizes[0] > 0) {
          motion_controller_withPIC_B.idx_f = static_cast<uint8_T>
            (workingset->sizes[0]);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp_j = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_j <
               motion_controller_withPIC_B.idx_f;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_j++) {
            motion_controller_withPIC_B.u1_d = fabs(workspace
              [workingset->
              indexFixed[motion_controller_withPIC_B.mWConstr_tmp_tmp_j] + 80] -
              workingset->ub[workingset->
              indexFixed[motion_controller_withPIC_B.mWConstr_tmp_tmp_j] - 1]);
            if ((!(motion_controller_withPIC_B.d_v_f >=
                   motion_controller_withPIC_B.u1_d)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1_d))) {
              motion_controller_withPIC_B.d_v_f =
                motion_controller_withPIC_B.u1_d;
            }
          }
        }

        if ((motion_controller_withPIC_B.c_h <= 2.2204460492503131E-16) ||
            (motion_controller_withPIC_B.c_h < motion_controller_withPIC_B.d_v_f))
        {
          motion_controller_withPIC_B.mWConstr_tmp_tmp_j = static_cast<uint8_T>
            (motion_controller_withPIC_B.nVar_tmp_tmp_m);
          memcpy(&xCurrent[0], &workspace[0], static_cast<uint32_T>
                 (motion_controller_withPIC_B.mWConstr_tmp_tmp_j) * sizeof
                 (real_T));
        } else {
          motion_controller_withPIC_B.mWConstr_tmp_tmp_j = static_cast<uint8_T>
            (motion_controller_withPIC_B.nVar_tmp_tmp_m);
          memcpy(&xCurrent[0], &workspace[81], static_cast<uint32_T>
                 (motion_controller_withPIC_B.mWConstr_tmp_tmp_j) * sizeof
                 (real_T));
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return nonDegenerateWset;
}

// Function for MATLAB Function: '<S63>/solvex'
real_T motion_controller_withPIC::motion_maxConstraintViolation_n
  (sVIU4VBONGRsUytHTQmMJFH_motio_T *obj, const real_T x[21])
{
  real_T u1;
  real_T v;
  int32_T b;
  int32_T k;
  if (obj->probType == 2) {
    v = 0.0;
    memcpy(&obj->maxConstrWorkspace[0], &obj->bineq[0], 40U * sizeof(real_T));
    xgemv_WOwAYNtc(20, obj->Aineq, x, obj->maxConstrWorkspace);
    for (k = 0; k < 40; k++) {
      u1 = obj->maxConstrWorkspace[k] - x[20];
      obj->maxConstrWorkspace[k] = u1;
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  } else {
    v = 0.0;
    memcpy(&obj->maxConstrWorkspace[0], &obj->bineq[0], 40U * sizeof(real_T));
    xgemv_WOwAYNtc(obj->nVar, obj->Aineq, x, obj->maxConstrWorkspace);
    for (k = 0; k < 40; k++) {
      u1 = obj->maxConstrWorkspace[k];
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  if (obj->sizes[3] > 0) {
    b = static_cast<uint8_T>(obj->sizes[3]);
    for (k = 0; k < b; k++) {
      u1 = -x[obj->indexLB[k] - 1] - obj->lb[obj->indexLB[k] - 1];
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  if (obj->sizes[4] > 0) {
    b = static_cast<uint8_T>(obj->sizes[4]);
    for (k = 0; k < b; k++) {
      u1 = x[obj->indexUB[k] - 1] - obj->ub[obj->indexUB[k] - 1];
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  if (obj->sizes[0] > 0) {
    b = static_cast<uint8_T>(obj->sizes[0]);
    for (k = 0; k < b; k++) {
      u1 = fabs(x[obj->indexFixed[k] - 1] - obj->ub[obj->indexFixed[k] - 1]);
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  return v;
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motion_co_PresolveWorkingSet_gj
  (sYqpSPVJXu9aOn60zG4DpzD_motio_T *solution, s3cSGkBdKxRj6Qn3zsJRowG_motio_T
   *memspace, sVIU4VBONGRsUytHTQmMJFH_motio_T *workingset,
   sIZAIOglGM5dPDQlNukc9SD_motio_T *qrmanager)
{
  boolean_T guard1;
  solution->state = 82;
  qrmanager->ldq = 21;
  memset(&qrmanager->QR[0], 0, 1701U * sizeof(real_T));
  memset(&qrmanager->Q[0], 0, 441U * sizeof(real_T));
  memset(&qrmanager->jpvt[0], 0, 81U * sizeof(int32_T));
  qrmanager->mrows = 0;
  qrmanager->ncols = 0;
  memset(&qrmanager->tau[0], 0, 21U * sizeof(real_T));
  qrmanager->minRowCol = 0;
  qrmanager->usedPivoting = false;
  motion_controller_withPIC_B.i_dm = workingset->nWConstr[0];
  motion_controller_withPIC_B.idx_row_c = 0;
  if (workingset->nWConstr[0] > 0) {
    motion_controller_withPIC_B.idxEndIneq_a = static_cast<uint8_T>
      (workingset->nWConstr[0]);
    motion_controller_withPIC_B.d_tmp = static_cast<uint8_T>(workingset->nVar);
    for (motion_controller_withPIC_B.idx_row_c = 0;
         motion_controller_withPIC_B.idx_row_c <
         motion_controller_withPIC_B.idxEndIneq_a;
         motion_controller_withPIC_B.idx_row_c++) {
      for (motion_controller_withPIC_B.idxStartIneq_j = 0;
           motion_controller_withPIC_B.idxStartIneq_j <
           motion_controller_withPIC_B.d_tmp;
           motion_controller_withPIC_B.idxStartIneq_j++) {
        qrmanager->QR[motion_controller_withPIC_B.idx_row_c + 21 *
          motion_controller_withPIC_B.idxStartIneq_j] = workingset->ATwset[21 *
          motion_controller_withPIC_B.idx_row_c +
          motion_controller_withPIC_B.idxStartIneq_j];
      }
    }

    motion_controller_withPIC_B.idx_row_c = motion_ComputeNumDependentEq__d
      (qrmanager, workingset->bwset, workingset->nWConstr[0], workingset->nVar);
    if (motion_controller_withPIC_B.idx_row_c > 0) {
      for (motion_controller_withPIC_B.idxStartIneq_j = 0;
           motion_controller_withPIC_B.idxStartIneq_j <
           motion_controller_withPIC_B.idxEndIneq_a;
           motion_controller_withPIC_B.idxStartIneq_j++) {
        motion_controller_withPIC_B.iy0_tmp_c = 21 *
          motion_controller_withPIC_B.idxStartIneq_j;
        memcpy(&qrmanager->QR[motion_controller_withPIC_B.iy0_tmp_c],
               &workingset->ATwset[motion_controller_withPIC_B.iy0_tmp_c],
               static_cast<uint32_T>((motion_controller_withPIC_B.d_tmp +
                 motion_controller_withPIC_B.iy0_tmp_c) -
                motion_controller_withPIC_B.iy0_tmp_c) * sizeof(real_T));
      }

      for (motion_controller_withPIC_B.idxStartIneq_j = 0;
           motion_controller_withPIC_B.idxStartIneq_j <
           motion_controller_withPIC_B.i_dm;
           motion_controller_withPIC_B.idxStartIneq_j++) {
        qrmanager->jpvt[motion_controller_withPIC_B.idxStartIneq_j] = 1;
      }

      motion_controller_withPIC_B.idxEndIneq_a = workingset->nWConstr[0] + 1;
      if (motion_controller_withPIC_B.idxEndIneq_a <=
          motion_controller_withPIC_B.i_dm) {
        memset(&qrmanager->jpvt[motion_controller_withPIC_B.idxEndIneq_a + -1],
               0, static_cast<uint32_T>((motion_controller_withPIC_B.i_dm -
                 motion_controller_withPIC_B.idxEndIneq_a) + 1) * sizeof(int32_T));
      }

      motion_controller_w_factorQRE_c(qrmanager, workingset->nVar,
        workingset->nWConstr[0]);
      for (motion_controller_withPIC_B.idxStartIneq_j = 0;
           motion_controller_withPIC_B.idxStartIneq_j <
           motion_controller_withPIC_B.idx_row_c;
           motion_controller_withPIC_B.idxStartIneq_j++) {
        memspace->workspace_int[motion_controller_withPIC_B.idxStartIneq_j] =
          qrmanager->jpvt[(motion_controller_withPIC_B.i_dm -
                           motion_controller_withPIC_B.idx_row_c) +
          motion_controller_withPIC_B.idxStartIneq_j];
      }

      countsort_JblpZJs7(memspace->workspace_int,
                         motion_controller_withPIC_B.idx_row_c,
                         memspace->workspace_sort, 1, workingset->nWConstr[0]);
      for (motion_controller_withPIC_B.i_dm =
           motion_controller_withPIC_B.idx_row_c;
           motion_controller_withPIC_B.i_dm >= 1;
           motion_controller_withPIC_B.i_dm--) {
        motion_control_removeEqConstr_i(workingset, memspace->
          workspace_int[motion_controller_withPIC_B.i_dm - 1]);
      }
    }
  }

  if ((motion_controller_withPIC_B.idx_row_c != -1) &&
      (workingset->nActiveConstr <= 21)) {
    motion_c_RemoveDependentIneq__e(workingset, qrmanager, memspace, 100.0);
    motion_controller_withPIC_B.okWorkingSet_n = motio_feasibleX0ForWorkingSet_c
      (memspace->workspace_double, solution->xstar, workingset, qrmanager);
    guard1 = false;
    if (!motion_controller_withPIC_B.okWorkingSet_n) {
      motion_c_RemoveDependentIneq__e(workingset, qrmanager, memspace, 1000.0);
      motion_controller_withPIC_B.okWorkingSet_n =
        motio_feasibleX0ForWorkingSet_c(memspace->workspace_double,
        solution->xstar, workingset, qrmanager);
      if (!motion_controller_withPIC_B.okWorkingSet_n) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (workingset->nWConstr[0] + workingset->nWConstr[1] == workingset->nVar)
      {
        motion_controller_withPIC_B.constrViolation_j =
          motion_maxConstraintViolation_n(workingset, solution->xstar);
        if (motion_controller_withPIC_B.constrViolation_j > 1.0E-8) {
          solution->state = -2;
        }
      }
    }
  } else {
    solution->state = -3;
    motion_controller_withPIC_B.idx_row_c = workingset->nWConstr[0] +
      workingset->nWConstr[1];
    motion_controller_withPIC_B.idxStartIneq_j =
      motion_controller_withPIC_B.idx_row_c + 1;
    motion_controller_withPIC_B.idxEndIneq_a = workingset->nActiveConstr;
    for (motion_controller_withPIC_B.i_dm =
         motion_controller_withPIC_B.idxStartIneq_j;
         motion_controller_withPIC_B.i_dm <=
         motion_controller_withPIC_B.idxEndIneq_a;
         motion_controller_withPIC_B.i_dm++) {
      workingset->isActiveConstr[(workingset->isActiveIdx[workingset->
        Wid[motion_controller_withPIC_B.i_dm - 1] - 1] + workingset->
        Wlocalidx[motion_controller_withPIC_B.i_dm - 1]) - 2] = false;
    }

    workingset->nWConstr[2] = 0;
    workingset->nWConstr[3] = 0;
    workingset->nWConstr[4] = 0;
    workingset->nActiveConstr = motion_controller_withPIC_B.idx_row_c;
  }
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motion_controller_linearForm__l(int32_T obj_nvar,
  real_T workspace[1701], const real_T H[400], const real_T f[20], const real_T
  x[21])
{
  int32_T d;
  int32_T ix;
  memcpy(&workspace[0], &f[0], static_cast<uint8_T>(obj_nvar) * sizeof(real_T));
  ix = 0;
  d = (obj_nvar - 1) * obj_nvar + 1;
  for (int32_T i = 1; obj_nvar < 0 ? i >= d : i <= d; i += obj_nvar) {
    real_T c;
    int32_T e;
    c = 0.5 * x[ix];
    e = (i + obj_nvar) - 1;
    for (int32_T b = i; b <= e; b++) {
      int32_T tmp;
      tmp = b - i;
      workspace[tmp] += H[b - 1] * c;
    }

    ix++;
  }
}

// Function for MATLAB Function: '<S63>/solvex'
real_T motion_controller_withPIC::motion_controller_computeFval_n(const
  s3PrFoa9w5ssw8XLEJooNqH_motio_T *obj, real_T workspace[1701], const real_T H
  [400], const real_T f[20], const real_T x[21])
{
  real_T val;
  int32_T b;
  int32_T b_k;
  switch (obj->objtype) {
   case 5:
    val = x[obj->nvar - 1];
    break;

   case 3:
    motion_controller_linearForm__l(obj->nvar, workspace, H, f, x);
    val = 0.0;
    if (obj->nvar >= 1) {
      b = static_cast<uint8_T>(obj->nvar);
      for (b_k = 0; b_k < b; b_k++) {
        val += x[b_k] * workspace[b_k];
      }
    }
    break;

   default:
    motion_controller_linearForm__l(obj->nvar, workspace, H, f, x);
    val = 0.0;
    for (b_k = 0; b_k < 20; b_k++) {
      val += x[b_k] * workspace[b_k];
    }
    break;
  }

  return val;
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motion_co_computeGrad_StoreHx_k
  (s3PrFoa9w5ssw8XLEJooNqH_motio_T *obj, const real_T H[400], const real_T f[20],
   const real_T x[21])
{
  __m128d tmp;
  __m128d tmp_0;
  int32_T b_ixlast;
  int32_T idx;
  int32_T scalarLB;
  int32_T vectorUB;
  switch (obj->objtype) {
   case 5:
    if (obj->nvar - 2 >= 0) {
      memset(&obj->grad[0], 0, static_cast<uint32_T>(obj->nvar - 1) * sizeof
             (real_T));
    }

    obj->grad[obj->nvar - 1] = obj->gammaScalar;
    break;

   case 3:
    xgemv_szX0RER2(obj->nvar, obj->nvar, H, obj->nvar, x, obj->Hx);
    if (static_cast<uint8_T>(obj->nvar) - 1 >= 0) {
      memcpy(&obj->grad[0], &obj->Hx[0], static_cast<uint8_T>(obj->nvar) *
             sizeof(real_T));
    }

    if (obj->hasLinear && (obj->nvar >= 1)) {
      b_ixlast = obj->nvar - 1;
      scalarLB = (obj->nvar / 2) << 1;
      vectorUB = scalarLB - 2;
      for (idx = 0; idx <= vectorUB; idx += 2) {
        tmp_0 = _mm_loadu_pd(&obj->grad[idx]);
        tmp = _mm_loadu_pd(&f[idx]);
        _mm_storeu_pd(&obj->grad[idx], _mm_add_pd(tmp_0, tmp));
      }

      for (idx = scalarLB; idx <= b_ixlast; idx++) {
        obj->grad[idx] += f[idx];
      }
    }
    break;

   default:
    xgemv_szX0RER2(obj->nvar, obj->nvar, H, obj->nvar, x, obj->Hx);
    b_ixlast = obj->nvar + 1;
    scalarLB = ((((20 - obj->nvar) / 2) << 1) + obj->nvar) + 1;
    vectorUB = scalarLB - 2;
    for (idx = b_ixlast; idx <= vectorUB; idx += 2) {
      tmp_0 = _mm_loadu_pd(&x[idx - 1]);
      _mm_storeu_pd(&obj->Hx[idx - 1], _mm_mul_pd(tmp_0, _mm_set1_pd(0.0)));
    }

    for (idx = scalarLB; idx < 21; idx++) {
      obj->Hx[idx - 1] = x[idx - 1] * 0.0;
    }

    memcpy(&obj->grad[0], &obj->Hx[0], 20U * sizeof(real_T));
    if (obj->hasLinear && (obj->nvar >= 1)) {
      b_ixlast = obj->nvar - 1;
      scalarLB = (obj->nvar / 2) << 1;
      vectorUB = scalarLB - 2;
      for (idx = 0; idx <= vectorUB; idx += 2) {
        tmp_0 = _mm_loadu_pd(&obj->grad[idx]);
        tmp = _mm_loadu_pd(&f[idx]);
        _mm_storeu_pd(&obj->grad[idx], _mm_add_pd(tmp_0, tmp));
      }

      for (idx = scalarLB; idx <= b_ixlast; idx++) {
        obj->grad[idx] += f[idx];
      }
    }
    break;
  }
}

// Function for MATLAB Function: '<S63>/solvex'
real_T motion_controller_withPIC::motion_co_computeFval_ReuseHx_n(const
  s3PrFoa9w5ssw8XLEJooNqH_motio_T *obj, real_T workspace[1701], const real_T f
  [20], const real_T x[21])
{
  real_T val;
  switch (obj->objtype) {
   case 5:
    val = x[obj->nvar - 1] * obj->gammaScalar;
    break;

   case 3:
    {
      if (obj->hasLinear) {
        int32_T e;
        int32_T scalarLB;
        int32_T vectorUB;
        e = static_cast<uint8_T>(obj->nvar);
        scalarLB = (static_cast<uint8_T>(obj->nvar) / 2) << 1;
        vectorUB = scalarLB - 2;
        for (int32_T k = 0; k <= vectorUB; k += 2) {
          __m128d tmp;
          __m128d tmp_0;
          tmp = _mm_loadu_pd(&obj->Hx[k]);
          tmp_0 = _mm_loadu_pd(&f[k]);
          _mm_storeu_pd(&workspace[k], _mm_add_pd(_mm_mul_pd(_mm_set1_pd(0.5),
            tmp), tmp_0));
        }

        for (int32_T k = scalarLB; k < e; k++) {
          workspace[k] = 0.5 * obj->Hx[k] + f[k];
        }

        val = 0.0;
        if (obj->nvar >= 1) {
          for (int32_T k = 0; k < e; k++) {
            val += x[k] * workspace[k];
          }
        }
      } else {
        val = 0.0;
        if (obj->nvar >= 1) {
          int32_T e;
          e = static_cast<uint8_T>(obj->nvar);
          for (int32_T k = 0; k < e; k++) {
            val += x[k] * obj->Hx[k];
          }
        }

        val *= 0.5;
      }
    }
    break;

   default:
    {
      if (obj->hasLinear) {
        int32_T e;
        if (static_cast<uint8_T>(obj->nvar) - 1 >= 0) {
          memcpy(&workspace[0], &f[0], static_cast<uint8_T>(obj->nvar) * sizeof
                 (real_T));
        }

        e = 19 - obj->nvar;
        for (int32_T k = 0; k <= e; k++) {
          workspace[obj->nvar + k] = 0.0;
        }

        val = 0.0;
        for (int32_T k = 0; k < 20; k++) {
          real_T workspace_0;
          workspace_0 = 0.5 * obj->Hx[k] + workspace[k];
          workspace[k] = workspace_0;
          val += x[k] * workspace_0;
        }
      } else {
        int32_T e;
        val = 0.0;
        for (int32_T k = 0; k < 20; k++) {
          val += x[k] * obj->Hx[k];
        }

        val *= 0.5;
        e = obj->nvar + 1;
        for (int32_T k = e; k < 21; k++) {
          val += x[k - 1] * 0.0;
        }
      }
    }
    break;
  }

  return val;
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_controlle_xrotg_ds3XgDMS(real_T *a,
  real_T *b, real_T *c, real_T *s)
{
  motion_controller_withPIC_B.roe = *b;
  motion_controller_withPIC_B.absa = fabs(*a);
  motion_controller_withPIC_B.absb = fabs(*b);
  if (motion_controller_withPIC_B.absa > motion_controller_withPIC_B.absb) {
    motion_controller_withPIC_B.roe = *a;
  }

  motion_controller_withPIC_B.scale_f = motion_controller_withPIC_B.absa +
    motion_controller_withPIC_B.absb;
  if (motion_controller_withPIC_B.scale_f == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *a = 0.0;
    *b = 0.0;
  } else {
    motion_controller_withPIC_B.ads = motion_controller_withPIC_B.absa /
      motion_controller_withPIC_B.scale_f;
    motion_controller_withPIC_B.bds = motion_controller_withPIC_B.absb /
      motion_controller_withPIC_B.scale_f;
    motion_controller_withPIC_B.scale_f *= sqrt(motion_controller_withPIC_B.ads *
      motion_controller_withPIC_B.ads + motion_controller_withPIC_B.bds *
      motion_controller_withPIC_B.bds);
    if (motion_controller_withPIC_B.roe < 0.0) {
      motion_controller_withPIC_B.scale_f = -motion_controller_withPIC_B.scale_f;
    }

    *c = *a / motion_controller_withPIC_B.scale_f;
    *s = *b / motion_controller_withPIC_B.scale_f;
    if (motion_controller_withPIC_B.absa > motion_controller_withPIC_B.absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }

    *a = motion_controller_withPIC_B.scale_f;
  }
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motion_contr_deleteColMoveEnd_a
  (sIZAIOglGM5dPDQlNukc9SD_motio_T *obj, int32_T idx)
{
  real_T b_s;
  real_T b_temp;
  real_T b_temp_tmp_0;
  real_T c_c;
  int32_T QRk0;
  int32_T b_n;
  int32_T b_temp_tmp;
  int32_T e_k;
  int32_T i;
  int32_T idxRotGCol;
  int32_T k;
  int32_T temp_tmp;
  if (obj->usedPivoting) {
    i = 1;
    while ((i <= obj->ncols) && (obj->jpvt[i - 1] != idx)) {
      i++;
    }

    idx = i;
  }

  if (idx >= obj->ncols) {
    obj->ncols--;
  } else {
    obj->jpvt[idx - 1] = obj->jpvt[obj->ncols - 1];
    QRk0 = obj->minRowCol;
    for (i = 0; i < QRk0; i++) {
      obj->QR[i + 21 * (idx - 1)] = obj->QR[(obj->ncols - 1) * 21 + i];
    }

    obj->ncols--;
    if (obj->mrows <= obj->ncols) {
      obj->minRowCol = obj->mrows;
    } else {
      obj->minRowCol = obj->ncols;
    }

    if (idx < obj->mrows) {
      if (obj->mrows - 1 <= obj->ncols) {
        i = obj->mrows - 1;
      } else {
        i = obj->ncols;
      }

      k = i;
      idxRotGCol = (idx - 1) * 21;
      while (k >= idx) {
        QRk0 = k + idxRotGCol;
        b_temp = obj->QR[QRk0];
        motion_controlle_xrotg_ds3XgDMS(&obj->QR[QRk0 - 1], &b_temp, &c_c, &b_s);
        obj->QR[QRk0] = b_temp;
        e_k = (k - 1) * 21;
        obj->QR[k + e_k] = 0.0;
        QRk0 = 21 * idx + k;
        b_temp_tmp = obj->ncols - idx;
        if (b_temp_tmp >= 1) {
          for (b_n = 0; b_n < b_temp_tmp; b_n++) {
            temp_tmp = b_n * 21 + QRk0;
            b_temp_tmp_0 = obj->QR[temp_tmp - 1];
            b_temp = b_temp_tmp_0 * c_c + obj->QR[temp_tmp] * b_s;
            obj->QR[temp_tmp] = obj->QR[temp_tmp] * c_c - b_temp_tmp_0 * b_s;
            obj->QR[temp_tmp - 1] = b_temp;
          }
        }

        b_n = obj->mrows;
        if (obj->mrows >= 1) {
          for (QRk0 = 0; QRk0 < b_n; QRk0++) {
            b_temp_tmp = e_k + QRk0;
            b_temp_tmp_0 = obj->Q[b_temp_tmp + 21];
            b_temp = b_temp_tmp_0 * b_s + obj->Q[b_temp_tmp] * c_c;
            obj->Q[b_temp_tmp + 21] = b_temp_tmp_0 * c_c - obj->Q[b_temp_tmp] *
              b_s;
            obj->Q[b_temp_tmp] = b_temp;
          }
        }

        k--;
      }

      for (k = idx + 1; k <= i; k++) {
        idxRotGCol = (k - 1) * 21;
        QRk0 = k + idxRotGCol;
        b_temp = obj->QR[QRk0];
        motion_controlle_xrotg_ds3XgDMS(&obj->QR[QRk0 - 1], &b_temp, &c_c, &b_s);
        obj->QR[QRk0] = b_temp;
        QRk0 = k * 22;
        b_n = obj->ncols - k;
        if (b_n >= 1) {
          for (e_k = 0; e_k < b_n; e_k++) {
            b_temp_tmp = e_k * 21 + QRk0;
            b_temp_tmp_0 = obj->QR[b_temp_tmp - 1];
            b_temp = b_temp_tmp_0 * c_c + obj->QR[b_temp_tmp] * b_s;
            obj->QR[b_temp_tmp] = obj->QR[b_temp_tmp] * c_c - b_temp_tmp_0 * b_s;
            obj->QR[b_temp_tmp - 1] = b_temp;
          }
        }

        e_k = obj->mrows;
        if (obj->mrows >= 1) {
          for (QRk0 = 0; QRk0 < e_k; QRk0++) {
            b_n = idxRotGCol + QRk0;
            b_temp_tmp_0 = obj->Q[b_n + 21];
            b_temp = b_temp_tmp_0 * b_s + obj->Q[b_n] * c_c;
            obj->Q[b_n + 21] = b_temp_tmp_0 * c_c - obj->Q[b_n] * b_s;
            obj->Q[b_n] = b_temp;
          }
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motion_controlle_fullColLDL2__a
  (sTy13TWZ7KObOACj8wDaLQC_motio_T *obj, int32_T NColsRemain, real_T REG_PRIMAL)
{
  for (motion_controller_withPIC_B.lastDiag_i = 0;
       motion_controller_withPIC_B.lastDiag_i < NColsRemain;
       motion_controller_withPIC_B.lastDiag_i++) {
    motion_controller_withPIC_B.LD_diagOffset_a = 22 *
      motion_controller_withPIC_B.lastDiag_i;
    motion_controller_withPIC_B.temp_g = obj->
      FMat[motion_controller_withPIC_B.LD_diagOffset_a];
    if (fabs(motion_controller_withPIC_B.temp_g) <= obj->regTol_) {
      motion_controller_withPIC_B.temp_g += REG_PRIMAL;
      obj->FMat[motion_controller_withPIC_B.LD_diagOffset_a] =
        motion_controller_withPIC_B.temp_g;
    }

    motion_controller_withPIC_B.alpha1_n = -1.0 /
      motion_controller_withPIC_B.temp_g;
    motion_controller_withPIC_B.subMatrixDim_i = (NColsRemain -
      motion_controller_withPIC_B.lastDiag_i) - 2;
    for (motion_controller_withPIC_B.b_k_l = 0;
         motion_controller_withPIC_B.b_k_l <=
         motion_controller_withPIC_B.subMatrixDim_i;
         motion_controller_withPIC_B.b_k_l++) {
      obj->workspace_[motion_controller_withPIC_B.b_k_l] = obj->FMat
        [(motion_controller_withPIC_B.LD_diagOffset_a +
          motion_controller_withPIC_B.b_k_l) + 1];
    }

    if (!(motion_controller_withPIC_B.alpha1_n == 0.0)) {
      motion_controller_withPIC_B.jA_o =
        motion_controller_withPIC_B.LD_diagOffset_a + 23;
      for (motion_controller_withPIC_B.b_k_l = 0;
           motion_controller_withPIC_B.b_k_l <=
           motion_controller_withPIC_B.subMatrixDim_i;
           motion_controller_withPIC_B.b_k_l++) {
        motion_controller_withPIC_B.temp_g = obj->
          workspace_[motion_controller_withPIC_B.b_k_l];
        if (motion_controller_withPIC_B.temp_g != 0.0) {
          motion_controller_withPIC_B.temp_g *=
            motion_controller_withPIC_B.alpha1_n;
          motion_controller_withPIC_B.b_p =
            motion_controller_withPIC_B.subMatrixDim_i +
            motion_controller_withPIC_B.jA_o;
          for (motion_controller_withPIC_B.ijA_o =
               motion_controller_withPIC_B.jA_o;
               motion_controller_withPIC_B.ijA_o <=
               motion_controller_withPIC_B.b_p;
               motion_controller_withPIC_B.ijA_o++) {
            obj->FMat[motion_controller_withPIC_B.ijA_o - 1] += obj->
              workspace_[motion_controller_withPIC_B.ijA_o -
              motion_controller_withPIC_B.jA_o] *
              motion_controller_withPIC_B.temp_g;
          }
        }

        motion_controller_withPIC_B.jA_o += 21;
      }
    }

    motion_controller_withPIC_B.alpha1_n = 1.0 / obj->
      FMat[motion_controller_withPIC_B.LD_diagOffset_a];
    motion_controller_withPIC_B.b_k_l =
      motion_controller_withPIC_B.LD_diagOffset_a +
      motion_controller_withPIC_B.subMatrixDim_i;
    motion_controller_withPIC_B.ijA_o = (((((motion_controller_withPIC_B.b_k_l -
      motion_controller_withPIC_B.LD_diagOffset_a) + 1) / 2) << 1) +
      motion_controller_withPIC_B.LD_diagOffset_a) + 2;
    motion_controller_withPIC_B.jA_o = motion_controller_withPIC_B.ijA_o - 2;
    for (motion_controller_withPIC_B.subMatrixDim_i =
         motion_controller_withPIC_B.LD_diagOffset_a + 2;
         motion_controller_withPIC_B.subMatrixDim_i <=
         motion_controller_withPIC_B.jA_o;
         motion_controller_withPIC_B.subMatrixDim_i += 2) {
      __m128d tmp;
      tmp = _mm_loadu_pd(&obj->FMat[motion_controller_withPIC_B.subMatrixDim_i -
                         1]);
      _mm_storeu_pd(&obj->FMat[motion_controller_withPIC_B.subMatrixDim_i - 1],
                    _mm_mul_pd(tmp, _mm_set1_pd
        (motion_controller_withPIC_B.alpha1_n)));
    }

    for (motion_controller_withPIC_B.subMatrixDim_i =
         motion_controller_withPIC_B.ijA_o;
         motion_controller_withPIC_B.subMatrixDim_i <=
         motion_controller_withPIC_B.b_k_l + 2;
         motion_controller_withPIC_B.subMatrixDim_i++) {
      obj->FMat[motion_controller_withPIC_B.subMatrixDim_i - 1] *=
        motion_controller_withPIC_B.alpha1_n;
    }
  }

  motion_controller_withPIC_B.lastDiag_i = (NColsRemain - 1) * 22;
  if (fabs(obj->FMat[motion_controller_withPIC_B.lastDiag_i]) <= obj->regTol_) {
    obj->FMat[motion_controller_withPIC_B.lastDiag_i] += REG_PRIMAL;
  }
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motion_control_compute_deltax_o(const real_T H
  [400], sYqpSPVJXu9aOn60zG4DpzD_motio_T *solution,
  s3cSGkBdKxRj6Qn3zsJRowG_motio_T *memspace, const
  sIZAIOglGM5dPDQlNukc9SD_motio_T *qrmanager, sTy13TWZ7KObOACj8wDaLQC_motio_T
  *cholmanager, const s3PrFoa9w5ssw8XLEJooNqH_motio_T *objective)
{
  __m128d tmp;
  __m128d tmp_0;
  int32_T exitg1;
  motion_controller_withPIC_B.nVar_n0 = qrmanager->mrows - 1;
  motion_controller_withPIC_B.mNull_tmp_a = qrmanager->mrows - qrmanager->ncols;
  if (motion_controller_withPIC_B.mNull_tmp_a <= 0) {
    if (motion_controller_withPIC_B.nVar_n0 >= 0) {
      memset(&solution->searchDir[0], 0, static_cast<uint32_T>
             (motion_controller_withPIC_B.nVar_n0 + 1) * sizeof(real_T));
    }
  } else {
    motion_controller_withPIC_B.b_ar_i = (qrmanager->mrows / 2) << 1;
    motion_controller_withPIC_B.vectorUB_b4 = motion_controller_withPIC_B.b_ar_i
      - 2;
    for (motion_controller_withPIC_B.A_maxDiag_idx_i = 0;
         motion_controller_withPIC_B.A_maxDiag_idx_i <=
         motion_controller_withPIC_B.vectorUB_b4;
         motion_controller_withPIC_B.A_maxDiag_idx_i += 2) {
      tmp_0 = _mm_loadu_pd(&objective->
                           grad[motion_controller_withPIC_B.A_maxDiag_idx_i]);
      _mm_storeu_pd(&solution->
                    searchDir[motion_controller_withPIC_B.A_maxDiag_idx_i],
                    _mm_mul_pd(tmp_0, _mm_set1_pd(-1.0)));
    }

    for (motion_controller_withPIC_B.A_maxDiag_idx_i =
         motion_controller_withPIC_B.b_ar_i;
         motion_controller_withPIC_B.A_maxDiag_idx_i <=
         motion_controller_withPIC_B.nVar_n0;
         motion_controller_withPIC_B.A_maxDiag_idx_i++) {
      solution->searchDir[motion_controller_withPIC_B.A_maxDiag_idx_i] =
        -objective->grad[motion_controller_withPIC_B.A_maxDiag_idx_i];
    }

    if (qrmanager->ncols <= 0) {
      if (objective->objtype == 3) {
        motion_controller_withPIC_B.temp_m4 = 1.4901161193847656E-6 *
          static_cast<real_T>(qrmanager->mrows);
        cholmanager->ndims = qrmanager->mrows;
        for (motion_controller_withPIC_B.mNull_tmp_a = 0;
             motion_controller_withPIC_B.mNull_tmp_a <=
             motion_controller_withPIC_B.nVar_n0;
             motion_controller_withPIC_B.mNull_tmp_a++) {
          motion_controller_withPIC_B.nullStartIdx_f =
            (motion_controller_withPIC_B.nVar_n0 + 1) *
            motion_controller_withPIC_B.mNull_tmp_a;
          motion_controller_withPIC_B.nVars_e = 21 *
            motion_controller_withPIC_B.mNull_tmp_a;
          for (motion_controller_withPIC_B.A_maxDiag_idx_i = 0;
               motion_controller_withPIC_B.A_maxDiag_idx_i <=
               motion_controller_withPIC_B.nVar_n0;
               motion_controller_withPIC_B.A_maxDiag_idx_i++) {
            cholmanager->FMat[motion_controller_withPIC_B.nVars_e +
              motion_controller_withPIC_B.A_maxDiag_idx_i] =
              H[motion_controller_withPIC_B.A_maxDiag_idx_i +
              motion_controller_withPIC_B.nullStartIdx_f];
          }
        }

        if (qrmanager->mrows < 1) {
          motion_controller_withPIC_B.A_maxDiag_idx_i = -1;
        } else {
          motion_controller_withPIC_B.A_maxDiag_idx_i = 0;
          if (qrmanager->mrows > 1) {
            motion_controller_withPIC_B.smax_g = fabs(cholmanager->FMat[0]);
            for (motion_controller_withPIC_B.mNull_tmp_a = 2;
                 motion_controller_withPIC_B.mNull_tmp_a <=
                 motion_controller_withPIC_B.nVar_n0 + 1;
                 motion_controller_withPIC_B.mNull_tmp_a++) {
              motion_controller_withPIC_B.s_l = fabs(cholmanager->FMat
                [(motion_controller_withPIC_B.mNull_tmp_a - 1) * 22]);
              if (motion_controller_withPIC_B.s_l >
                  motion_controller_withPIC_B.smax_g) {
                motion_controller_withPIC_B.A_maxDiag_idx_i =
                  motion_controller_withPIC_B.mNull_tmp_a - 1;
                motion_controller_withPIC_B.smax_g =
                  motion_controller_withPIC_B.s_l;
              }
            }
          }
        }

        motion_controller_withPIC_B.smax_g = fabs(cholmanager->FMat[21 *
          motion_controller_withPIC_B.A_maxDiag_idx_i +
          motion_controller_withPIC_B.A_maxDiag_idx_i]) * 2.2204460492503131E-16;
        motion_controller_withPIC_B.s_l = fabs
          (motion_controller_withPIC_B.temp_m4);
        if (motion_controller_withPIC_B.smax_g >=
            motion_controller_withPIC_B.s_l) {
          cholmanager->regTol_ = motion_controller_withPIC_B.smax_g;
        } else {
          cholmanager->regTol_ = motion_controller_withPIC_B.s_l;
        }

        motion_controlle_fullColLDL2__a(cholmanager, qrmanager->mrows,
          motion_controller_withPIC_B.temp_m4);
        if (cholmanager->ConvexCheck) {
          motion_controller_withPIC_B.mNull_tmp_a = 0;
          do {
            exitg1 = 0;
            if (motion_controller_withPIC_B.mNull_tmp_a <=
                motion_controller_withPIC_B.nVar_n0) {
              if (cholmanager->FMat[21 * motion_controller_withPIC_B.mNull_tmp_a
                  + motion_controller_withPIC_B.mNull_tmp_a] <= 0.0) {
                cholmanager->info = -motion_controller_withPIC_B.mNull_tmp_a - 1;
                exitg1 = 1;
              } else {
                motion_controller_withPIC_B.mNull_tmp_a++;
              }
            } else {
              cholmanager->ConvexCheck = false;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }

        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          motion_controller_withPIC_B.nVar_n0 = cholmanager->ndims - 1;
          if (cholmanager->ndims != 0) {
            for (motion_controller_withPIC_B.mNull_tmp_a = 0;
                 motion_controller_withPIC_B.mNull_tmp_a <=
                 motion_controller_withPIC_B.nVar_n0;
                 motion_controller_withPIC_B.mNull_tmp_a++) {
              motion_controller_withPIC_B.nullStartIdx_f =
                motion_controller_withPIC_B.mNull_tmp_a * 21 +
                motion_controller_withPIC_B.mNull_tmp_a;
              motion_controller_withPIC_B.nVars_e =
                motion_controller_withPIC_B.nVar_n0 -
                motion_controller_withPIC_B.mNull_tmp_a;
              for (motion_controller_withPIC_B.A_maxDiag_idx_i = 0;
                   motion_controller_withPIC_B.A_maxDiag_idx_i <
                   motion_controller_withPIC_B.nVars_e;
                   motion_controller_withPIC_B.A_maxDiag_idx_i++) {
                motion_controller_withPIC_B.b_A_maxDiag_idx_a =
                  (motion_controller_withPIC_B.A_maxDiag_idx_i +
                   motion_controller_withPIC_B.mNull_tmp_a) + 1;
                solution->
                  searchDir[motion_controller_withPIC_B.b_A_maxDiag_idx_a] -=
                  cholmanager->FMat[(motion_controller_withPIC_B.A_maxDiag_idx_i
                                     + motion_controller_withPIC_B.nullStartIdx_f)
                  + 1] * solution->
                  searchDir[motion_controller_withPIC_B.mNull_tmp_a];
              }
            }
          }

          motion_controller_withPIC_B.nVar_n0 = cholmanager->ndims;
          for (motion_controller_withPIC_B.mNull_tmp_a = 0;
               motion_controller_withPIC_B.mNull_tmp_a <
               motion_controller_withPIC_B.nVar_n0;
               motion_controller_withPIC_B.mNull_tmp_a++) {
            solution->searchDir[motion_controller_withPIC_B.mNull_tmp_a] /=
              cholmanager->FMat[21 * motion_controller_withPIC_B.mNull_tmp_a +
              motion_controller_withPIC_B.mNull_tmp_a];
          }

          if (cholmanager->ndims != 0) {
            for (motion_controller_withPIC_B.mNull_tmp_a =
                 motion_controller_withPIC_B.nVar_n0;
                 motion_controller_withPIC_B.mNull_tmp_a >= 1;
                 motion_controller_withPIC_B.mNull_tmp_a--) {
              motion_controller_withPIC_B.nullStartIdx_f =
                (motion_controller_withPIC_B.mNull_tmp_a - 1) * 21;
              motion_controller_withPIC_B.temp_m4 = solution->
                searchDir[motion_controller_withPIC_B.mNull_tmp_a - 1];
              for (motion_controller_withPIC_B.A_maxDiag_idx_i =
                   motion_controller_withPIC_B.nVar_n0;
                   motion_controller_withPIC_B.A_maxDiag_idx_i >=
                   motion_controller_withPIC_B.mNull_tmp_a + 1;
                   motion_controller_withPIC_B.A_maxDiag_idx_i--) {
                motion_controller_withPIC_B.temp_m4 -= cholmanager->FMat
                  [(motion_controller_withPIC_B.nullStartIdx_f +
                    motion_controller_withPIC_B.A_maxDiag_idx_i) - 1] *
                  solution->
                  searchDir[motion_controller_withPIC_B.A_maxDiag_idx_i - 1];
              }

              solution->searchDir[motion_controller_withPIC_B.mNull_tmp_a - 1] =
                motion_controller_withPIC_B.temp_m4;
            }
          }
        }
      }
    } else {
      motion_controller_withPIC_B.A_maxDiag_idx_i = 21 * qrmanager->ncols;
      motion_controller_withPIC_B.nullStartIdx_f =
        motion_controller_withPIC_B.A_maxDiag_idx_i + 1;
      if (objective->objtype == 5) {
        for (motion_controller_withPIC_B.nullStartIdx_f = 0;
             motion_controller_withPIC_B.nullStartIdx_f <
             motion_controller_withPIC_B.mNull_tmp_a;
             motion_controller_withPIC_B.nullStartIdx_f++) {
          memspace->workspace_double[motion_controller_withPIC_B.nullStartIdx_f]
            = -qrmanager->Q[(qrmanager->ncols +
                             motion_controller_withPIC_B.nullStartIdx_f) * 21 +
            motion_controller_withPIC_B.nVar_n0];
        }

        xgemv_CxqfdDRY(qrmanager->mrows, motion_controller_withPIC_B.mNull_tmp_a,
                       qrmanager->Q, motion_controller_withPIC_B.A_maxDiag_idx_i
                       + 1, memspace->workspace_double, solution->searchDir);
      } else {
        if (objective->objtype == 3) {
          motion_controller_withPIC_B.nVars_e = qrmanager->mrows;
          if ((qrmanager->mrows != 0) &&
              (motion_controller_withPIC_B.mNull_tmp_a != 0)) {
            motion_controller_withPIC_B.br_k =
              motion_controller_withPIC_B.A_maxDiag_idx_i;
            motion_controller_withPIC_B.lastColC_f =
              (motion_controller_withPIC_B.mNull_tmp_a - 1) * 81;
            for (motion_controller_withPIC_B.b_A_maxDiag_idx_a = 0;
                 motion_controller_withPIC_B.b_A_maxDiag_idx_a <=
                 motion_controller_withPIC_B.lastColC_f;
                 motion_controller_withPIC_B.b_A_maxDiag_idx_a += 81) {
              motion_controller_withPIC_B.e_ix_o =
                motion_controller_withPIC_B.b_A_maxDiag_idx_a +
                motion_controller_withPIC_B.nVars_e;
              for (motion_controller_withPIC_B.ic_j =
                   motion_controller_withPIC_B.b_A_maxDiag_idx_a + 1;
                   motion_controller_withPIC_B.ic_j <=
                   motion_controller_withPIC_B.e_ix_o;
                   motion_controller_withPIC_B.ic_j++) {
                memspace->workspace_double[motion_controller_withPIC_B.ic_j - 1]
                  = 0.0;
              }
            }

            for (motion_controller_withPIC_B.b_A_maxDiag_idx_a = 0;
                 motion_controller_withPIC_B.b_A_maxDiag_idx_a <=
                 motion_controller_withPIC_B.lastColC_f;
                 motion_controller_withPIC_B.b_A_maxDiag_idx_a += 81) {
              motion_controller_withPIC_B.ar_c = -1;
              motion_controller_withPIC_B.h_l = motion_controller_withPIC_B.br_k
                + motion_controller_withPIC_B.nVars_e;
              for (motion_controller_withPIC_B.ic_j =
                   motion_controller_withPIC_B.br_k + 1;
                   motion_controller_withPIC_B.ic_j <=
                   motion_controller_withPIC_B.h_l;
                   motion_controller_withPIC_B.ic_j++) {
                motion_controller_withPIC_B.i_ai =
                  motion_controller_withPIC_B.b_A_maxDiag_idx_a +
                  motion_controller_withPIC_B.nVars_e;
                motion_controller_withPIC_B.b_ar_i =
                  ((((motion_controller_withPIC_B.i_ai -
                      motion_controller_withPIC_B.b_A_maxDiag_idx_a) / 2) << 1)
                   + motion_controller_withPIC_B.b_A_maxDiag_idx_a) + 1;
                motion_controller_withPIC_B.vectorUB_b4 =
                  motion_controller_withPIC_B.b_ar_i - 2;
                for (motion_controller_withPIC_B.e_ix_o =
                     motion_controller_withPIC_B.b_A_maxDiag_idx_a + 1;
                     motion_controller_withPIC_B.e_ix_o <=
                     motion_controller_withPIC_B.vectorUB_b4;
                     motion_controller_withPIC_B.e_ix_o += 2) {
                  tmp_0 = _mm_loadu_pd(&H[(motion_controller_withPIC_B.ar_c +
                    motion_controller_withPIC_B.e_ix_o) -
                                       motion_controller_withPIC_B.b_A_maxDiag_idx_a]);
                  tmp = _mm_loadu_pd(&memspace->
                                     workspace_double[motion_controller_withPIC_B.e_ix_o
                                     - 1]);
                  _mm_storeu_pd(&memspace->
                                workspace_double[motion_controller_withPIC_B.e_ix_o
                                - 1], _mm_add_pd(_mm_mul_pd(tmp_0, _mm_set1_pd
                    (qrmanager->Q[motion_controller_withPIC_B.ic_j - 1])), tmp));
                }

                for (motion_controller_withPIC_B.e_ix_o =
                     motion_controller_withPIC_B.b_ar_i;
                     motion_controller_withPIC_B.e_ix_o <=
                     motion_controller_withPIC_B.i_ai;
                     motion_controller_withPIC_B.e_ix_o++) {
                  memspace->workspace_double[motion_controller_withPIC_B.e_ix_o
                    - 1] += H[(motion_controller_withPIC_B.ar_c +
                               motion_controller_withPIC_B.e_ix_o) -
                    motion_controller_withPIC_B.b_A_maxDiag_idx_a] *
                    qrmanager->Q[motion_controller_withPIC_B.ic_j - 1];
                }

                motion_controller_withPIC_B.ar_c +=
                  motion_controller_withPIC_B.nVars_e;
              }

              motion_controller_withPIC_B.br_k += 21;
            }
          }

          if (motion_controller_withPIC_B.mNull_tmp_a != 0) {
            motion_controller_withPIC_B.br_k =
              (motion_controller_withPIC_B.mNull_tmp_a - 1) * 21;
            for (motion_controller_withPIC_B.b_A_maxDiag_idx_a = 0;
                 motion_controller_withPIC_B.b_A_maxDiag_idx_a <=
                 motion_controller_withPIC_B.br_k;
                 motion_controller_withPIC_B.b_A_maxDiag_idx_a += 21) {
              motion_controller_withPIC_B.e_ix_o =
                motion_controller_withPIC_B.b_A_maxDiag_idx_a +
                motion_controller_withPIC_B.mNull_tmp_a;
              for (motion_controller_withPIC_B.ic_j =
                   motion_controller_withPIC_B.b_A_maxDiag_idx_a + 1;
                   motion_controller_withPIC_B.ic_j <=
                   motion_controller_withPIC_B.e_ix_o;
                   motion_controller_withPIC_B.ic_j++) {
                cholmanager->FMat[motion_controller_withPIC_B.ic_j - 1] = 0.0;
              }
            }

            motion_controller_withPIC_B.lastColC_f = -1;
            for (motion_controller_withPIC_B.b_A_maxDiag_idx_a = 0;
                 motion_controller_withPIC_B.b_A_maxDiag_idx_a <=
                 motion_controller_withPIC_B.br_k;
                 motion_controller_withPIC_B.b_A_maxDiag_idx_a += 21) {
              motion_controller_withPIC_B.b_ar_i =
                motion_controller_withPIC_B.A_maxDiag_idx_i;
              motion_controller_withPIC_B.vectorUB_b4 =
                motion_controller_withPIC_B.b_A_maxDiag_idx_a +
                motion_controller_withPIC_B.mNull_tmp_a;
              for (motion_controller_withPIC_B.ic_j =
                   motion_controller_withPIC_B.b_A_maxDiag_idx_a + 1;
                   motion_controller_withPIC_B.ic_j <=
                   motion_controller_withPIC_B.vectorUB_b4;
                   motion_controller_withPIC_B.ic_j++) {
                motion_controller_withPIC_B.temp_m4 = 0.0;
                for (motion_controller_withPIC_B.e_ix_o = 0;
                     motion_controller_withPIC_B.e_ix_o <
                     motion_controller_withPIC_B.nVars_e;
                     motion_controller_withPIC_B.e_ix_o++) {
                  motion_controller_withPIC_B.temp_m4 +=
                    memspace->workspace_double
                    [(motion_controller_withPIC_B.e_ix_o +
                      motion_controller_withPIC_B.lastColC_f) + 1] *
                    qrmanager->Q[motion_controller_withPIC_B.e_ix_o +
                    motion_controller_withPIC_B.b_ar_i];
                }

                cholmanager->FMat[motion_controller_withPIC_B.ic_j - 1] +=
                  motion_controller_withPIC_B.temp_m4;
                motion_controller_withPIC_B.b_ar_i += 21;
              }

              motion_controller_withPIC_B.lastColC_f += 81;
            }
          }
        }

        motion_controller_withPIC_B.temp_m4 = 1.4901161193847656E-6 *
          static_cast<real_T>(motion_controller_withPIC_B.mNull_tmp_a);
        cholmanager->ndims = motion_controller_withPIC_B.mNull_tmp_a;
        motion_controller_withPIC_B.b_A_maxDiag_idx_a = 0;
        if (motion_controller_withPIC_B.mNull_tmp_a > 1) {
          motion_controller_withPIC_B.smax_g = fabs(cholmanager->FMat[0]);
          for (motion_controller_withPIC_B.nVars_e = 2;
               motion_controller_withPIC_B.nVars_e <=
               motion_controller_withPIC_B.mNull_tmp_a;
               motion_controller_withPIC_B.nVars_e++) {
            motion_controller_withPIC_B.s_l = fabs(cholmanager->FMat
              [(motion_controller_withPIC_B.nVars_e - 1) * 22]);
            if (motion_controller_withPIC_B.s_l >
                motion_controller_withPIC_B.smax_g) {
              motion_controller_withPIC_B.b_A_maxDiag_idx_a =
                motion_controller_withPIC_B.nVars_e - 1;
              motion_controller_withPIC_B.smax_g =
                motion_controller_withPIC_B.s_l;
            }
          }
        }

        motion_controller_withPIC_B.smax_g = fabs(cholmanager->FMat[21 *
          motion_controller_withPIC_B.b_A_maxDiag_idx_a +
          motion_controller_withPIC_B.b_A_maxDiag_idx_a]) *
          2.2204460492503131E-16;
        if (motion_controller_withPIC_B.smax_g >=
            motion_controller_withPIC_B.temp_m4) {
          cholmanager->regTol_ = motion_controller_withPIC_B.smax_g;
        } else {
          cholmanager->regTol_ = motion_controller_withPIC_B.temp_m4;
        }

        motion_controlle_fullColLDL2__a(cholmanager,
          motion_controller_withPIC_B.mNull_tmp_a,
          motion_controller_withPIC_B.temp_m4);
        if (cholmanager->ConvexCheck) {
          motion_controller_withPIC_B.nVars_e = 0;
          do {
            exitg1 = 0;
            if (motion_controller_withPIC_B.nVars_e <=
                motion_controller_withPIC_B.mNull_tmp_a - 1) {
              if (cholmanager->FMat[21 * motion_controller_withPIC_B.nVars_e +
                  motion_controller_withPIC_B.nVars_e] <= 0.0) {
                cholmanager->info = -motion_controller_withPIC_B.nVars_e - 1;
                exitg1 = 1;
              } else {
                motion_controller_withPIC_B.nVars_e++;
              }
            } else {
              cholmanager->ConvexCheck = false;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }

        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          if (qrmanager->mrows != 0) {
            memset(&memspace->workspace_double[0], 0, static_cast<uint32_T>
                   (motion_controller_withPIC_B.mNull_tmp_a) * sizeof(real_T));
            motion_controller_withPIC_B.ic_j =
              ((motion_controller_withPIC_B.mNull_tmp_a - 1) * 21 +
               motion_controller_withPIC_B.A_maxDiag_idx_i) + 1;
            for (motion_controller_withPIC_B.nVars_e =
                 motion_controller_withPIC_B.nullStartIdx_f;
                 motion_controller_withPIC_B.nVars_e <=
                 motion_controller_withPIC_B.ic_j;
                 motion_controller_withPIC_B.nVars_e += 21) {
              motion_controller_withPIC_B.temp_m4 = 0.0;
              motion_controller_withPIC_B.e_ix_o =
                motion_controller_withPIC_B.nVars_e +
                motion_controller_withPIC_B.nVar_n0;
              for (motion_controller_withPIC_B.b_A_maxDiag_idx_a =
                   motion_controller_withPIC_B.nVars_e;
                   motion_controller_withPIC_B.b_A_maxDiag_idx_a <=
                   motion_controller_withPIC_B.e_ix_o;
                   motion_controller_withPIC_B.b_A_maxDiag_idx_a++) {
                motion_controller_withPIC_B.temp_m4 += qrmanager->
                  Q[motion_controller_withPIC_B.b_A_maxDiag_idx_a - 1] *
                  objective->grad[motion_controller_withPIC_B.b_A_maxDiag_idx_a
                  - motion_controller_withPIC_B.nVars_e];
              }

              motion_controller_withPIC_B.b_A_maxDiag_idx_a = div_nde_s32_floor
                ((motion_controller_withPIC_B.nVars_e -
                  motion_controller_withPIC_B.A_maxDiag_idx_i) - 1, 21);
              memspace->
                workspace_double[motion_controller_withPIC_B.b_A_maxDiag_idx_a] -=
                motion_controller_withPIC_B.temp_m4;
            }
          }

          motion_controller_withPIC_B.nVars_e = cholmanager->ndims - 1;
          if (cholmanager->ndims != 0) {
            for (motion_controller_withPIC_B.nVar_n0 = 0;
                 motion_controller_withPIC_B.nVar_n0 <=
                 motion_controller_withPIC_B.nVars_e;
                 motion_controller_withPIC_B.nVar_n0++) {
              motion_controller_withPIC_B.b_A_maxDiag_idx_a =
                motion_controller_withPIC_B.nVar_n0 * 21 +
                motion_controller_withPIC_B.nVar_n0;
              motion_controller_withPIC_B.ic_j =
                motion_controller_withPIC_B.nVars_e -
                motion_controller_withPIC_B.nVar_n0;
              for (motion_controller_withPIC_B.nullStartIdx_f = 0;
                   motion_controller_withPIC_B.nullStartIdx_f <
                   motion_controller_withPIC_B.ic_j;
                   motion_controller_withPIC_B.nullStartIdx_f++) {
                motion_controller_withPIC_B.e_ix_o =
                  (motion_controller_withPIC_B.nullStartIdx_f +
                   motion_controller_withPIC_B.nVar_n0) + 1;
                memspace->workspace_double[motion_controller_withPIC_B.e_ix_o] -=
                  cholmanager->FMat[(motion_controller_withPIC_B.nullStartIdx_f
                                     + motion_controller_withPIC_B.b_A_maxDiag_idx_a)
                  + 1] * memspace->
                  workspace_double[motion_controller_withPIC_B.nVar_n0];
              }
            }
          }

          motion_controller_withPIC_B.nVars_e = cholmanager->ndims;
          for (motion_controller_withPIC_B.nVar_n0 = 0;
               motion_controller_withPIC_B.nVar_n0 <
               motion_controller_withPIC_B.nVars_e;
               motion_controller_withPIC_B.nVar_n0++) {
            memspace->workspace_double[motion_controller_withPIC_B.nVar_n0] /=
              cholmanager->FMat[21 * motion_controller_withPIC_B.nVar_n0 +
              motion_controller_withPIC_B.nVar_n0];
          }

          if (cholmanager->ndims != 0) {
            for (motion_controller_withPIC_B.nVar_n0 =
                 motion_controller_withPIC_B.nVars_e;
                 motion_controller_withPIC_B.nVar_n0 >= 1;
                 motion_controller_withPIC_B.nVar_n0--) {
              motion_controller_withPIC_B.b_A_maxDiag_idx_a =
                (motion_controller_withPIC_B.nVar_n0 - 1) * 21;
              motion_controller_withPIC_B.temp_m4 = memspace->
                workspace_double[motion_controller_withPIC_B.nVar_n0 - 1];
              for (motion_controller_withPIC_B.nullStartIdx_f =
                   motion_controller_withPIC_B.nVars_e;
                   motion_controller_withPIC_B.nullStartIdx_f >=
                   motion_controller_withPIC_B.nVar_n0 + 1;
                   motion_controller_withPIC_B.nullStartIdx_f--) {
                motion_controller_withPIC_B.temp_m4 -= cholmanager->FMat
                  [(motion_controller_withPIC_B.b_A_maxDiag_idx_a +
                    motion_controller_withPIC_B.nullStartIdx_f) - 1] *
                  memspace->
                  workspace_double[motion_controller_withPIC_B.nullStartIdx_f -
                  1];
              }

              memspace->workspace_double[motion_controller_withPIC_B.nVar_n0 - 1]
                = motion_controller_withPIC_B.temp_m4;
            }
          }

          xgemv_CxqfdDRY(qrmanager->mrows,
                         motion_controller_withPIC_B.mNull_tmp_a, qrmanager->Q,
                         motion_controller_withPIC_B.A_maxDiag_idx_i + 1,
                         memspace->workspace_double, solution->searchDir);
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S63>/solvex'
real_T motion_controller_withPIC::motion_controlle_xnrm2_rY1rIeLd(int32_T n,
  const real_T x[21])
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[0]);
    } else {
      motion_controller_withPIC_B.scale_fr = 3.3121686421112381E-170;
      motion_controller_withPIC_B.b_e = static_cast<uint8_T>(n);
      for (motion_controller_withPIC_B.k_dt = 0;
           motion_controller_withPIC_B.k_dt < motion_controller_withPIC_B.b_e;
           motion_controller_withPIC_B.k_dt++) {
        motion_controller_withPIC_B.absxk_m = fabs
          (x[motion_controller_withPIC_B.k_dt]);
        if (motion_controller_withPIC_B.absxk_m >
            motion_controller_withPIC_B.scale_fr) {
          motion_controller_withPIC_B.t_a = motion_controller_withPIC_B.scale_fr
            / motion_controller_withPIC_B.absxk_m;
          y = y * motion_controller_withPIC_B.t_a *
            motion_controller_withPIC_B.t_a + 1.0;
          motion_controller_withPIC_B.scale_fr =
            motion_controller_withPIC_B.absxk_m;
        } else {
          motion_controller_withPIC_B.t_a = motion_controller_withPIC_B.absxk_m /
            motion_controller_withPIC_B.scale_fr;
          y += motion_controller_withPIC_B.t_a * motion_controller_withPIC_B.t_a;
        }
      }

      y = motion_controller_withPIC_B.scale_fr * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motion_controlle_xgemv_BberjsMK(int32_T m, const
  real_T A[840], const real_T x[21], real_T y[1701])
{
  for (motion_controller_withPIC_B.b_iy_g = 0;
       motion_controller_withPIC_B.b_iy_g <= 38;
       motion_controller_withPIC_B.b_iy_g += 2) {
    __m128d tmp;
    tmp = _mm_loadu_pd(&y[motion_controller_withPIC_B.b_iy_g]);
    _mm_storeu_pd(&y[motion_controller_withPIC_B.b_iy_g], _mm_mul_pd(tmp,
      _mm_set1_pd(-1.0)));
  }

  for (motion_controller_withPIC_B.b_iy_g = 0;
       motion_controller_withPIC_B.b_iy_g <= 819;
       motion_controller_withPIC_B.b_iy_g += 21) {
    motion_controller_withPIC_B.c_g = 0.0;
    motion_controller_withPIC_B.b_bp = motion_controller_withPIC_B.b_iy_g + m;
    for (motion_controller_withPIC_B.ia_k = motion_controller_withPIC_B.b_iy_g +
         1; motion_controller_withPIC_B.ia_k <= motion_controller_withPIC_B.b_bp;
         motion_controller_withPIC_B.ia_k++) {
      motion_controller_withPIC_B.c_g += x[(motion_controller_withPIC_B.ia_k -
        motion_controller_withPIC_B.b_iy_g) - 1] *
        A[motion_controller_withPIC_B.ia_k - 1];
    }

    motion_controller_withPIC_B.ia_k = div_nde_s32_floor
      (motion_controller_withPIC_B.b_iy_g, 21);
    y[motion_controller_withPIC_B.ia_k] += motion_controller_withPIC_B.c_g;
  }
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motion_controller_w_ratiotest_f(const real_T
  solution_xstar[21], const real_T solution_searchDir[21], real_T workspace[1701],
  int32_T workingset_nVar, const real_T workingset_Aineq[840], const real_T
  workingset_bineq[40], const real_T workingset_lb[21], const real_T
  workingset_ub[21], const int32_T workingset_indexLB[21], const int32_T
  workingset_indexUB[21], const int32_T workingset_sizes[5], const int32_T
  workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr[81],
  const int32_T workingset_nWConstr[5], real_T *toldelta, real_T *alpha,
  boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx)
{
  *alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  motion_controller_withPIC_B.p_max_g = 0.0;
  motion_controller_withPIC_B.denomTol_j = 2.2204460492503131E-13 *
    motion_controlle_xnrm2_rY1rIeLd(workingset_nVar, solution_searchDir);
  if (workingset_nWConstr[2] < 40) {
    memcpy(&workspace[0], &workingset_bineq[0], 40U * sizeof(real_T));
    motion_controlle_xgemv_BberjsMK(workingset_nVar, workingset_Aineq,
      solution_xstar, workspace);
    memset(&workspace[81], 0, 40U * sizeof(real_T));
    for (motion_controller_withPIC_B.k_o = 0; motion_controller_withPIC_B.k_o <=
         819; motion_controller_withPIC_B.k_o += 21) {
      motion_controller_withPIC_B.b_c_a = 0.0;
      motion_controller_withPIC_B.d_g = motion_controller_withPIC_B.k_o +
        workingset_nVar;
      for (motion_controller_withPIC_B.ia_a = motion_controller_withPIC_B.k_o +
           1; motion_controller_withPIC_B.ia_a <=
           motion_controller_withPIC_B.d_g; motion_controller_withPIC_B.ia_a++)
      {
        motion_controller_withPIC_B.b_c_a += solution_searchDir
          [(motion_controller_withPIC_B.ia_a - motion_controller_withPIC_B.k_o)
          - 1] * workingset_Aineq[motion_controller_withPIC_B.ia_a - 1];
      }

      motion_controller_withPIC_B.ia_a = div_nde_s32_floor
        (motion_controller_withPIC_B.k_o, 21) + 81;
      workspace[motion_controller_withPIC_B.ia_a] +=
        motion_controller_withPIC_B.b_c_a;
    }

    for (motion_controller_withPIC_B.k_o = 0; motion_controller_withPIC_B.k_o <
         40; motion_controller_withPIC_B.k_o++) {
      motion_controller_withPIC_B.workspace_j =
        workspace[motion_controller_withPIC_B.k_o + 81];
      if ((motion_controller_withPIC_B.workspace_j >
           motion_controller_withPIC_B.denomTol_j) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[2] +
            motion_controller_withPIC_B.k_o) - 1])) {
        motion_controller_withPIC_B.phaseOneCorrectionX_c =
          workspace[motion_controller_withPIC_B.k_o];
        motion_controller_withPIC_B.b_c_a = fabs
          (motion_controller_withPIC_B.phaseOneCorrectionX_c - *toldelta);
        motion_controller_withPIC_B.phaseOneCorrectionP_e = (1.0E-8 -
          motion_controller_withPIC_B.phaseOneCorrectionX_c) + *toldelta;
        if ((motion_controller_withPIC_B.b_c_a <=
             motion_controller_withPIC_B.phaseOneCorrectionP_e) || rtIsNaN
            (motion_controller_withPIC_B.phaseOneCorrectionP_e)) {
          motion_controller_withPIC_B.phaseOneCorrectionP_e =
            motion_controller_withPIC_B.b_c_a;
        }

        motion_controller_withPIC_B.b_c_a =
          motion_controller_withPIC_B.phaseOneCorrectionP_e /
          motion_controller_withPIC_B.workspace_j;
        if ((motion_controller_withPIC_B.b_c_a <= *alpha) && (fabs
             (motion_controller_withPIC_B.workspace_j) >
             motion_controller_withPIC_B.p_max_g)) {
          *alpha = motion_controller_withPIC_B.b_c_a;
          *constrType = 3;
          *constrIdx = motion_controller_withPIC_B.k_o + 1;
          *newBlocking = true;
        }

        motion_controller_withPIC_B.b_c_a = fabs
          (motion_controller_withPIC_B.phaseOneCorrectionX_c);
        if ((!(motion_controller_withPIC_B.b_c_a <= 1.0E-8 -
               motion_controller_withPIC_B.phaseOneCorrectionX_c)) && (!rtIsNaN
             (1.0E-8 - motion_controller_withPIC_B.phaseOneCorrectionX_c))) {
          motion_controller_withPIC_B.b_c_a = 1.0E-8 -
            motion_controller_withPIC_B.phaseOneCorrectionX_c;
        }

        motion_controller_withPIC_B.b_c_a /=
          motion_controller_withPIC_B.workspace_j;
        if (motion_controller_withPIC_B.b_c_a < *alpha) {
          *alpha = motion_controller_withPIC_B.b_c_a;
          *constrType = 3;
          *constrIdx = motion_controller_withPIC_B.k_o + 1;
          *newBlocking = true;
          motion_controller_withPIC_B.p_max_g = fabs
            (motion_controller_withPIC_B.workspace_j);
        }
      }
    }
  }

  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    motion_controller_withPIC_B.phaseOneCorrectionX_c =
      solution_xstar[workingset_nVar - 1] * 0.0;
    motion_controller_withPIC_B.phaseOneCorrectionP_e =
      solution_searchDir[workingset_nVar - 1] * 0.0;
    motion_controller_withPIC_B.ia_a = workingset_sizes[3];
    for (motion_controller_withPIC_B.k_o = 0; motion_controller_withPIC_B.k_o <=
         motion_controller_withPIC_B.ia_a - 2; motion_controller_withPIC_B.k_o++)
    {
      motion_controller_withPIC_B.d_g =
        workingset_indexLB[motion_controller_withPIC_B.k_o];
      motion_controller_withPIC_B.pk_corrected_m =
        -solution_searchDir[motion_controller_withPIC_B.d_g - 1] -
        motion_controller_withPIC_B.phaseOneCorrectionP_e;
      if ((motion_controller_withPIC_B.pk_corrected_m >
           motion_controller_withPIC_B.denomTol_j) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[3] +
            motion_controller_withPIC_B.k_o) - 1])) {
        motion_controller_withPIC_B.workspace_j =
          -solution_xstar[motion_controller_withPIC_B.d_g - 1] -
          workingset_lb[motion_controller_withPIC_B.d_g - 1];
        motion_controller_withPIC_B.ratio_o =
          (motion_controller_withPIC_B.workspace_j - *toldelta) -
          motion_controller_withPIC_B.phaseOneCorrectionX_c;
        motion_controller_withPIC_B.b_c_a = fabs
          (motion_controller_withPIC_B.ratio_o);
        if ((!(motion_controller_withPIC_B.b_c_a <= 1.0E-8 -
               motion_controller_withPIC_B.ratio_o)) && (!rtIsNaN(1.0E-8 -
              motion_controller_withPIC_B.ratio_o))) {
          motion_controller_withPIC_B.b_c_a = 1.0E-8 -
            motion_controller_withPIC_B.ratio_o;
        }

        motion_controller_withPIC_B.b_c_a /=
          motion_controller_withPIC_B.pk_corrected_m;
        if ((motion_controller_withPIC_B.b_c_a <= *alpha) && (fabs
             (motion_controller_withPIC_B.pk_corrected_m) >
             motion_controller_withPIC_B.p_max_g)) {
          *alpha = motion_controller_withPIC_B.b_c_a;
          *constrType = 4;
          *constrIdx = motion_controller_withPIC_B.k_o + 1;
          *newBlocking = true;
        }

        motion_controller_withPIC_B.ratio_o =
          motion_controller_withPIC_B.workspace_j -
          motion_controller_withPIC_B.phaseOneCorrectionX_c;
        motion_controller_withPIC_B.b_c_a = fabs
          (motion_controller_withPIC_B.ratio_o);
        if ((!(motion_controller_withPIC_B.b_c_a <= 1.0E-8 -
               motion_controller_withPIC_B.ratio_o)) && (!rtIsNaN(1.0E-8 -
              motion_controller_withPIC_B.ratio_o))) {
          motion_controller_withPIC_B.b_c_a = 1.0E-8 -
            motion_controller_withPIC_B.ratio_o;
        }

        motion_controller_withPIC_B.b_c_a /=
          motion_controller_withPIC_B.pk_corrected_m;
        if (motion_controller_withPIC_B.b_c_a < *alpha) {
          *alpha = motion_controller_withPIC_B.b_c_a;
          *constrType = 4;
          *constrIdx = motion_controller_withPIC_B.k_o + 1;
          *newBlocking = true;
          motion_controller_withPIC_B.p_max_g = fabs
            (motion_controller_withPIC_B.pk_corrected_m);
        }
      }
    }

    motion_controller_withPIC_B.ia_a = workingset_indexLB[workingset_sizes[3] -
      1] - 1;
    motion_controller_withPIC_B.phaseOneCorrectionX_c =
      solution_searchDir[motion_controller_withPIC_B.ia_a];
    if ((-motion_controller_withPIC_B.phaseOneCorrectionX_c >
         motion_controller_withPIC_B.denomTol_j) && (!workingset_isActiveConstr
         [(workingset_isActiveIdx[3] + workingset_sizes[3]) - 2])) {
      motion_controller_withPIC_B.workspace_j =
        -solution_xstar[motion_controller_withPIC_B.ia_a] -
        workingset_lb[motion_controller_withPIC_B.ia_a];
      motion_controller_withPIC_B.ratio_o =
        motion_controller_withPIC_B.workspace_j - *toldelta;
      motion_controller_withPIC_B.b_c_a = fabs
        (motion_controller_withPIC_B.ratio_o);
      if ((!(motion_controller_withPIC_B.b_c_a <= 1.0E-8 -
             motion_controller_withPIC_B.ratio_o)) && (!rtIsNaN(1.0E-8 -
            motion_controller_withPIC_B.ratio_o))) {
        motion_controller_withPIC_B.b_c_a = 1.0E-8 -
          motion_controller_withPIC_B.ratio_o;
      }

      motion_controller_withPIC_B.b_c_a /=
        -motion_controller_withPIC_B.phaseOneCorrectionX_c;
      if ((motion_controller_withPIC_B.b_c_a <= *alpha) && (fabs
           (motion_controller_withPIC_B.phaseOneCorrectionX_c) >
           motion_controller_withPIC_B.p_max_g)) {
        *alpha = motion_controller_withPIC_B.b_c_a;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }

      motion_controller_withPIC_B.b_c_a = fabs
        (motion_controller_withPIC_B.workspace_j);
      if ((!(motion_controller_withPIC_B.b_c_a <= 1.0E-8 -
             motion_controller_withPIC_B.workspace_j)) && (!rtIsNaN(1.0E-8 -
            motion_controller_withPIC_B.workspace_j))) {
        motion_controller_withPIC_B.b_c_a = 1.0E-8 -
          motion_controller_withPIC_B.workspace_j;
      }

      motion_controller_withPIC_B.b_c_a /=
        -motion_controller_withPIC_B.phaseOneCorrectionX_c;
      if (motion_controller_withPIC_B.b_c_a < *alpha) {
        *alpha = motion_controller_withPIC_B.b_c_a;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
        motion_controller_withPIC_B.p_max_g = fabs
          (motion_controller_withPIC_B.phaseOneCorrectionX_c);
      }
    }
  }

  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    motion_controller_withPIC_B.phaseOneCorrectionX_c =
      solution_xstar[workingset_nVar - 1] * 0.0;
    motion_controller_withPIC_B.phaseOneCorrectionP_e =
      solution_searchDir[workingset_nVar - 1] * 0.0;
    motion_controller_withPIC_B.ia_a = static_cast<uint8_T>(workingset_sizes[4]);
    for (motion_controller_withPIC_B.k_o = 0; motion_controller_withPIC_B.k_o <
         motion_controller_withPIC_B.ia_a; motion_controller_withPIC_B.k_o++) {
      motion_controller_withPIC_B.d_g =
        workingset_indexUB[motion_controller_withPIC_B.k_o];
      motion_controller_withPIC_B.pk_corrected_m =
        solution_searchDir[motion_controller_withPIC_B.d_g - 1] -
        motion_controller_withPIC_B.phaseOneCorrectionP_e;
      if ((motion_controller_withPIC_B.pk_corrected_m >
           motion_controller_withPIC_B.denomTol_j) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[4] +
            motion_controller_withPIC_B.k_o) - 1])) {
        motion_controller_withPIC_B.workspace_j =
          solution_xstar[motion_controller_withPIC_B.d_g - 1] -
          workingset_ub[motion_controller_withPIC_B.d_g - 1];
        motion_controller_withPIC_B.ratio_o =
          (motion_controller_withPIC_B.workspace_j - *toldelta) -
          motion_controller_withPIC_B.phaseOneCorrectionX_c;
        motion_controller_withPIC_B.b_c_a = fabs
          (motion_controller_withPIC_B.ratio_o);
        if ((!(motion_controller_withPIC_B.b_c_a <= 1.0E-8 -
               motion_controller_withPIC_B.ratio_o)) && (!rtIsNaN(1.0E-8 -
              motion_controller_withPIC_B.ratio_o))) {
          motion_controller_withPIC_B.b_c_a = 1.0E-8 -
            motion_controller_withPIC_B.ratio_o;
        }

        motion_controller_withPIC_B.b_c_a /=
          motion_controller_withPIC_B.pk_corrected_m;
        if ((motion_controller_withPIC_B.b_c_a <= *alpha) && (fabs
             (motion_controller_withPIC_B.pk_corrected_m) >
             motion_controller_withPIC_B.p_max_g)) {
          *alpha = motion_controller_withPIC_B.b_c_a;
          *constrType = 5;
          *constrIdx = motion_controller_withPIC_B.k_o + 1;
          *newBlocking = true;
        }

        motion_controller_withPIC_B.ratio_o =
          motion_controller_withPIC_B.workspace_j -
          motion_controller_withPIC_B.phaseOneCorrectionX_c;
        motion_controller_withPIC_B.b_c_a = fabs
          (motion_controller_withPIC_B.ratio_o);
        if ((!(motion_controller_withPIC_B.b_c_a <= 1.0E-8 -
               motion_controller_withPIC_B.ratio_o)) && (!rtIsNaN(1.0E-8 -
              motion_controller_withPIC_B.ratio_o))) {
          motion_controller_withPIC_B.b_c_a = 1.0E-8 -
            motion_controller_withPIC_B.ratio_o;
        }

        motion_controller_withPIC_B.b_c_a /=
          motion_controller_withPIC_B.pk_corrected_m;
        if (motion_controller_withPIC_B.b_c_a < *alpha) {
          *alpha = motion_controller_withPIC_B.b_c_a;
          *constrType = 5;
          *constrIdx = motion_controller_withPIC_B.k_o + 1;
          *newBlocking = true;
          motion_controller_withPIC_B.p_max_g = fabs
            (motion_controller_withPIC_B.pk_corrected_m);
        }
      }
    }
  }

  *toldelta += 6.608625846508183E-7;
  if (motion_controller_withPIC_B.p_max_g > 0.0) {
    motion_controller_withPIC_B.phaseOneCorrectionP_e = 6.608625846508183E-7 /
      motion_controller_withPIC_B.p_max_g;
    if (!(*alpha >= motion_controller_withPIC_B.phaseOneCorrectionP_e)) {
      *alpha = motion_controller_withPIC_B.phaseOneCorrectionP_e;
    }
  }

  *newBlocking = (((!*newBlocking) || (!(*alpha > 1.0))) && (*newBlocking));
  if (!(*alpha <= 1.0)) {
    *alpha = 1.0;
  }
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motion_cont_feasibleratiotest_d(const real_T
  solution_xstar[21], const real_T solution_searchDir[21], real_T workspace[1701],
  int32_T workingset_nVar, const real_T workingset_Aineq[840], const real_T
  workingset_bineq[40], const real_T workingset_lb[21], const real_T
  workingset_ub[21], const int32_T workingset_indexLB[21], const int32_T
  workingset_indexUB[21], const int32_T workingset_sizes[5], const int32_T
  workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr[81],
  const int32_T workingset_nWConstr[5], boolean_T isPhaseOne, real_T *alpha,
  boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx)
{
  *alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  motion_controller_withPIC_B.denomTol_f = 2.2204460492503131E-13 *
    motion_controlle_xnrm2_rY1rIeLd(workingset_nVar, solution_searchDir);
  if (workingset_nWConstr[2] < 40) {
    memcpy(&workspace[0], &workingset_bineq[0], 40U * sizeof(real_T));
    motion_controlle_xgemv_BberjsMK(workingset_nVar, workingset_Aineq,
      solution_xstar, workspace);
    memset(&workspace[81], 0, 40U * sizeof(real_T));
    for (motion_controller_withPIC_B.k_g = 0; motion_controller_withPIC_B.k_g <=
         819; motion_controller_withPIC_B.k_g += 21) {
      motion_controller_withPIC_B.b_c_o = 0.0;
      motion_controller_withPIC_B.d_c = motion_controller_withPIC_B.k_g +
        workingset_nVar;
      for (motion_controller_withPIC_B.ia_l = motion_controller_withPIC_B.k_g +
           1; motion_controller_withPIC_B.ia_l <=
           motion_controller_withPIC_B.d_c; motion_controller_withPIC_B.ia_l++)
      {
        motion_controller_withPIC_B.b_c_o += solution_searchDir
          [(motion_controller_withPIC_B.ia_l - motion_controller_withPIC_B.k_g)
          - 1] * workingset_Aineq[motion_controller_withPIC_B.ia_l - 1];
      }

      motion_controller_withPIC_B.ia_l = div_nde_s32_floor
        (motion_controller_withPIC_B.k_g, 21) + 81;
      workspace[motion_controller_withPIC_B.ia_l] +=
        motion_controller_withPIC_B.b_c_o;
    }

    for (motion_controller_withPIC_B.k_g = 0; motion_controller_withPIC_B.k_g <
         40; motion_controller_withPIC_B.k_g++) {
      motion_controller_withPIC_B.phaseOneCorrectionX_on =
        workspace[motion_controller_withPIC_B.k_g + 81];
      if ((motion_controller_withPIC_B.phaseOneCorrectionX_on >
           motion_controller_withPIC_B.denomTol_f) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[2] +
            motion_controller_withPIC_B.k_g) - 1])) {
        motion_controller_withPIC_B.phaseOneCorrectionP_i =
          workspace[motion_controller_withPIC_B.k_g];
        motion_controller_withPIC_B.b_c_o = fabs
          (motion_controller_withPIC_B.phaseOneCorrectionP_i);
        if ((!(motion_controller_withPIC_B.b_c_o <= 1.0E-8 -
               motion_controller_withPIC_B.phaseOneCorrectionP_i)) && (!rtIsNaN
             (1.0E-8 - motion_controller_withPIC_B.phaseOneCorrectionP_i))) {
          motion_controller_withPIC_B.b_c_o = 1.0E-8 -
            motion_controller_withPIC_B.phaseOneCorrectionP_i;
        }

        motion_controller_withPIC_B.b_c_o /=
          motion_controller_withPIC_B.phaseOneCorrectionX_on;
        if (motion_controller_withPIC_B.b_c_o < *alpha) {
          *alpha = motion_controller_withPIC_B.b_c_o;
          *constrType = 3;
          *constrIdx = motion_controller_withPIC_B.k_g + 1;
          *newBlocking = true;
        }
      }
    }
  }

  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    motion_controller_withPIC_B.phaseOneCorrectionX_on =
      solution_xstar[workingset_nVar - 1] * static_cast<real_T>(isPhaseOne);
    motion_controller_withPIC_B.phaseOneCorrectionP_i =
      solution_searchDir[workingset_nVar - 1] * static_cast<real_T>(isPhaseOne);
    motion_controller_withPIC_B.ia_l = workingset_sizes[3];
    for (motion_controller_withPIC_B.k_g = 0; motion_controller_withPIC_B.k_g <=
         motion_controller_withPIC_B.ia_l - 2; motion_controller_withPIC_B.k_g++)
    {
      motion_controller_withPIC_B.d_c =
        workingset_indexLB[motion_controller_withPIC_B.k_g];
      motion_controller_withPIC_B.pk_corrected_e =
        -solution_searchDir[motion_controller_withPIC_B.d_c - 1] -
        motion_controller_withPIC_B.phaseOneCorrectionP_i;
      if ((motion_controller_withPIC_B.pk_corrected_e >
           motion_controller_withPIC_B.denomTol_f) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[3] +
            motion_controller_withPIC_B.k_g) - 1])) {
        motion_controller_withPIC_B.ratio_j =
          (-solution_xstar[motion_controller_withPIC_B.d_c - 1] -
           workingset_lb[motion_controller_withPIC_B.d_c - 1]) -
          motion_controller_withPIC_B.phaseOneCorrectionX_on;
        motion_controller_withPIC_B.b_c_o = fabs
          (motion_controller_withPIC_B.ratio_j);
        if ((!(motion_controller_withPIC_B.b_c_o <= 1.0E-8 -
               motion_controller_withPIC_B.ratio_j)) && (!rtIsNaN(1.0E-8 -
              motion_controller_withPIC_B.ratio_j))) {
          motion_controller_withPIC_B.b_c_o = 1.0E-8 -
            motion_controller_withPIC_B.ratio_j;
        }

        motion_controller_withPIC_B.b_c_o /=
          motion_controller_withPIC_B.pk_corrected_e;
        if (motion_controller_withPIC_B.b_c_o < *alpha) {
          *alpha = motion_controller_withPIC_B.b_c_o;
          *constrType = 4;
          *constrIdx = motion_controller_withPIC_B.k_g + 1;
          *newBlocking = true;
        }
      }
    }

    motion_controller_withPIC_B.ia_l = workingset_indexLB[workingset_sizes[3] -
      1] - 1;
    motion_controller_withPIC_B.phaseOneCorrectionX_on =
      -solution_searchDir[motion_controller_withPIC_B.ia_l];
    if ((motion_controller_withPIC_B.phaseOneCorrectionX_on >
         motion_controller_withPIC_B.denomTol_f) && (!workingset_isActiveConstr
         [(workingset_isActiveIdx[3] + workingset_sizes[3]) - 2])) {
      motion_controller_withPIC_B.ratio_j =
        -solution_xstar[motion_controller_withPIC_B.ia_l] -
        workingset_lb[motion_controller_withPIC_B.ia_l];
      motion_controller_withPIC_B.b_c_o = fabs
        (motion_controller_withPIC_B.ratio_j);
      if ((!(motion_controller_withPIC_B.b_c_o <= 1.0E-8 -
             motion_controller_withPIC_B.ratio_j)) && (!rtIsNaN(1.0E-8 -
            motion_controller_withPIC_B.ratio_j))) {
        motion_controller_withPIC_B.b_c_o = 1.0E-8 -
          motion_controller_withPIC_B.ratio_j;
      }

      motion_controller_withPIC_B.b_c_o /=
        motion_controller_withPIC_B.phaseOneCorrectionX_on;
      if (motion_controller_withPIC_B.b_c_o < *alpha) {
        *alpha = motion_controller_withPIC_B.b_c_o;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }
    }
  }

  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    motion_controller_withPIC_B.phaseOneCorrectionX_on =
      solution_xstar[workingset_nVar - 1] * static_cast<real_T>(isPhaseOne);
    motion_controller_withPIC_B.phaseOneCorrectionP_i =
      solution_searchDir[workingset_nVar - 1] * static_cast<real_T>(isPhaseOne);
    motion_controller_withPIC_B.ia_l = static_cast<uint8_T>(workingset_sizes[4]);
    for (motion_controller_withPIC_B.k_g = 0; motion_controller_withPIC_B.k_g <
         motion_controller_withPIC_B.ia_l; motion_controller_withPIC_B.k_g++) {
      motion_controller_withPIC_B.d_c =
        workingset_indexUB[motion_controller_withPIC_B.k_g];
      motion_controller_withPIC_B.pk_corrected_e =
        solution_searchDir[motion_controller_withPIC_B.d_c - 1] -
        motion_controller_withPIC_B.phaseOneCorrectionP_i;
      if ((motion_controller_withPIC_B.pk_corrected_e >
           motion_controller_withPIC_B.denomTol_f) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[4] +
            motion_controller_withPIC_B.k_g) - 1])) {
        motion_controller_withPIC_B.ratio_j =
          (solution_xstar[motion_controller_withPIC_B.d_c - 1] -
           workingset_ub[motion_controller_withPIC_B.d_c - 1]) -
          motion_controller_withPIC_B.phaseOneCorrectionX_on;
        motion_controller_withPIC_B.b_c_o = fabs
          (motion_controller_withPIC_B.ratio_j);
        if ((!(motion_controller_withPIC_B.b_c_o <= 1.0E-8 -
               motion_controller_withPIC_B.ratio_j)) && (!rtIsNaN(1.0E-8 -
              motion_controller_withPIC_B.ratio_j))) {
          motion_controller_withPIC_B.b_c_o = 1.0E-8 -
            motion_controller_withPIC_B.ratio_j;
        }

        motion_controller_withPIC_B.b_c_o /=
          motion_controller_withPIC_B.pk_corrected_e;
        if (motion_controller_withPIC_B.b_c_o < *alpha) {
          *alpha = motion_controller_withPIC_B.b_c_o;
          *constrType = 5;
          *constrIdx = motion_controller_withPIC_B.k_g + 1;
          *newBlocking = true;
        }
      }
    }
  }

  if (!isPhaseOne) {
    *newBlocking = (((!*newBlocking) || (!(*alpha > 1.0))) && (*newBlocking));
    if (!(*alpha <= 1.0)) {
      *alpha = 1.0;
    }
  }
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::mo_addBoundToActiveSetMatrix__i
  (sVIU4VBONGRsUytHTQmMJFH_motio_T *obj, int32_T TYPE, int32_T idx_local)
{
  int32_T colOffset;
  int32_T idx_bnd_local;
  obj->nWConstr[TYPE - 1]++;
  obj->isActiveConstr[(obj->isActiveIdx[TYPE - 1] + idx_local) - 2] = true;
  obj->nActiveConstr++;
  obj->Wid[obj->nActiveConstr - 1] = TYPE;
  obj->Wlocalidx[obj->nActiveConstr - 1] = idx_local;
  colOffset = (obj->nActiveConstr - 1) * 21 - 1;
  if (TYPE == 5) {
    idx_bnd_local = obj->indexUB[idx_local - 1];
    obj->bwset[obj->nActiveConstr - 1] = obj->ub[idx_bnd_local - 1];
  } else {
    idx_bnd_local = obj->indexLB[idx_local - 1];
    obj->bwset[obj->nActiveConstr - 1] = obj->lb[idx_bnd_local - 1];
  }

  if (static_cast<uint8_T>(idx_bnd_local - 1) - 1 >= 0) {
    memset(&obj->ATwset[colOffset + 1], 0, static_cast<uint32_T>
           ((static_cast<uint8_T>(idx_bnd_local - 1) + colOffset) - colOffset) *
           sizeof(real_T));
  }

  obj->ATwset[idx_bnd_local + colOffset] = static_cast<real_T>(TYPE == 5) * 2.0
    - 1.0;
  if (idx_bnd_local + 1 <= obj->nVar) {
    memset(&obj->ATwset[(idx_bnd_local + colOffset) + 1], 0,
           static_cast<uint32_T>(((obj->nVar + colOffset) - idx_bnd_local) -
            colOffset) * sizeof(real_T));
  }

  switch (obj->probType) {
   case 3:
   case 2:
    break;

   default:
    obj->ATwset[obj->nVar + colOffset] = -1.0;
    break;
  }
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motion_controlle_compute_lambda(real_T
  workspace[1701], sYqpSPVJXu9aOn60zG4DpzD_motio_T *solution, const
  s3PrFoa9w5ssw8XLEJooNqH_motio_T *objective, const
  sIZAIOglGM5dPDQlNukc9SD_motio_T *qrmanager)
{
  int32_T nActiveConstr_tmp_tmp;
  nActiveConstr_tmp_tmp = qrmanager->ncols;
  if (qrmanager->ncols > 0) {
    real_T c;
    int32_T b_idx;
    int32_T idxQR;
    boolean_T guard1;
    guard1 = false;
    if (objective->objtype != 4) {
      boolean_T nonDegenerate;
      c = 100.0 * static_cast<real_T>(qrmanager->mrows) * 2.2204460492503131E-16;
      nonDegenerate = ((qrmanager->mrows > 0) && (qrmanager->ncols > 0));
      if (nonDegenerate) {
        boolean_T guard2;
        b_idx = qrmanager->ncols;
        guard2 = false;
        if (qrmanager->mrows < qrmanager->ncols) {
          idxQR = (qrmanager->ncols - 1) * 21 + qrmanager->mrows;
          while ((b_idx > qrmanager->mrows) && (fabs(qrmanager->QR[idxQR - 1]) >=
                  c)) {
            b_idx--;
            idxQR -= 21;
          }

          nonDegenerate = (b_idx == qrmanager->mrows);
          if (!nonDegenerate) {
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          idxQR = (b_idx - 1) * 21 + b_idx;
          while ((b_idx >= 1) && (fabs(qrmanager->QR[idxQR - 1]) >= c)) {
            b_idx--;
            idxQR -= 22;
          }

          nonDegenerate = (b_idx == 0);
        }
      }

      if (!nonDegenerate) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      int32_T b_ix;
      int32_T jjA;
      if (qrmanager->mrows != 0) {
        memset(&workspace[0], 0, static_cast<uint32_T>(qrmanager->ncols) *
               sizeof(real_T));
        jjA = (qrmanager->ncols - 1) * 21 + 1;
        for (b_idx = 1; b_idx <= jjA; b_idx += 21) {
          c = 0.0;
          b_ix = (b_idx + qrmanager->mrows) - 1;
          for (idxQR = b_idx; idxQR <= b_ix; idxQR++) {
            c += qrmanager->Q[idxQR - 1] * objective->grad[idxQR - b_idx];
          }

          idxQR = div_nde_s32_floor(b_idx - 1, 21);
          workspace[idxQR] += c;
        }
      }

      for (b_idx = nActiveConstr_tmp_tmp; b_idx >= 1; b_idx--) {
        jjA = ((b_idx - 1) * 21 + b_idx) - 2;
        workspace[b_idx - 1] /= qrmanager->QR[jjA + 1];
        for (idxQR = 0; idxQR <= b_idx - 2; idxQR++) {
          b_ix = (b_idx - idxQR) - 2;
          workspace[b_ix] -= workspace[b_idx - 1] * qrmanager->QR[jjA - idxQR];
        }
      }

      idxQR = (qrmanager->ncols / 2) << 1;
      jjA = idxQR - 2;
      for (b_idx = 0; b_idx <= jjA; b_idx += 2) {
        __m128d tmp;
        tmp = _mm_loadu_pd(&workspace[b_idx]);
        _mm_storeu_pd(&solution->lambda[b_idx], _mm_mul_pd(tmp, _mm_set1_pd(-1.0)));
      }

      for (b_idx = idxQR; b_idx < nActiveConstr_tmp_tmp; b_idx++) {
        solution->lambda[b_idx] = -workspace[b_idx];
      }
    }
  }
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motion_controller_wit_iterate_b(const real_T H
  [400], const real_T f[20], sYqpSPVJXu9aOn60zG4DpzD_motio_T *solution,
  s3cSGkBdKxRj6Qn3zsJRowG_motio_T *memspace, sVIU4VBONGRsUytHTQmMJFH_motio_T
  *workingset, sIZAIOglGM5dPDQlNukc9SD_motio_T *qrmanager,
  sTy13TWZ7KObOACj8wDaLQC_motio_T *cholmanager, s3PrFoa9w5ssw8XLEJooNqH_motio_T *
  objective, real_T options_ObjectiveLimit, real_T options_StepTolerance, real_T
  runTimeOptions_ConstrRelTolFact, real_T runTimeOptions_ProbRelTolFactor,
  boolean_T runTimeOptions_RemainFeasible)
{
  __m128d tmp;
  __m128d tmp_0;
  int32_T exitg1;
  boolean_T guard1;
  motion_controller_withPIC_B.subProblemChanged_i = true;
  motion_controller_withPIC_B.updateFval_n = true;
  motion_controller_withPIC_B.activeSetChangeID_n = 0;
  motion_controller_withPIC_B.TYPE_b = objective->objtype;
  motion_controller_withPIC_B.tolDelta_o = 6.7434957617430445E-7;
  motion_controller_withPIC_B.nVar_f = workingset->nVar;
  motion_controller_withPIC_B.globalActiveConstrIdx_k = 0;
  motion_co_computeGrad_StoreHx_k(objective, H, f, solution->xstar);
  solution->fstar = motion_co_computeFval_ReuseHx_n(objective,
    memspace->workspace_double, f, solution->xstar);
  if (solution->iterations < 200) {
    solution->state = -5;
  } else {
    solution->state = 0;
  }

  memset(&solution->lambda[0], 0, 81U * sizeof(real_T));
  do {
    exitg1 = 0;
    if (solution->state == -5) {
      guard1 = false;
      if (motion_controller_withPIC_B.subProblemChanged_i) {
        switch (motion_controller_withPIC_B.activeSetChangeID_n) {
         case 1:
          motion_controller_withPIC_B.Qk0_d = (workingset->nActiveConstr - 1) *
            21;
          if (qrmanager->mrows <= qrmanager->ncols + 1) {
            qrmanager->minRowCol = qrmanager->mrows;
          } else {
            qrmanager->minRowCol = qrmanager->ncols + 1;
          }

          motion_controller_withPIC_B.iy0 = 21 * qrmanager->ncols;
          if (qrmanager->mrows != 0) {
            motion_controller_withPIC_B.iyend_h =
              motion_controller_withPIC_B.iy0 + qrmanager->mrows;
            if (motion_controller_withPIC_B.iy0 + 1 <=
                motion_controller_withPIC_B.iyend_h) {
              memset(&qrmanager->QR[motion_controller_withPIC_B.iy0], 0,
                     static_cast<uint32_T>(motion_controller_withPIC_B.iyend_h -
                      motion_controller_withPIC_B.iy0) * sizeof(real_T));
            }

            motion_controller_withPIC_B.l_n = (qrmanager->mrows - 1) * 21 + 1;
            for (motion_controller_withPIC_B.localActiveConstrIdx_i = 1;
                 motion_controller_withPIC_B.localActiveConstrIdx_i <=
                 motion_controller_withPIC_B.l_n;
                 motion_controller_withPIC_B.localActiveConstrIdx_i += 21) {
              motion_controller_withPIC_B.normDelta_n = 0.0;
              motion_controller_withPIC_B.m =
                (motion_controller_withPIC_B.localActiveConstrIdx_i +
                 qrmanager->mrows) - 1;
              for (motion_controller_withPIC_B.iyend_h =
                   motion_controller_withPIC_B.localActiveConstrIdx_i;
                   motion_controller_withPIC_B.iyend_h <=
                   motion_controller_withPIC_B.m;
                   motion_controller_withPIC_B.iyend_h++) {
                motion_controller_withPIC_B.normDelta_n += workingset->ATwset
                  [(motion_controller_withPIC_B.Qk0_d +
                    motion_controller_withPIC_B.iyend_h) -
                  motion_controller_withPIC_B.localActiveConstrIdx_i] *
                  qrmanager->Q[motion_controller_withPIC_B.iyend_h - 1];
              }

              motion_controller_withPIC_B.iyend_h = div_nde_s32_floor
                (motion_controller_withPIC_B.localActiveConstrIdx_i - 1, 21) +
                motion_controller_withPIC_B.iy0;
              qrmanager->QR[motion_controller_withPIC_B.iyend_h] +=
                motion_controller_withPIC_B.normDelta_n;
            }
          }

          qrmanager->ncols++;
          qrmanager->jpvt[qrmanager->ncols - 1] = qrmanager->ncols;
          motion_controller_withPIC_B.iyend_h = qrmanager->mrows - 2;
          while (motion_controller_withPIC_B.iyend_h + 2 > qrmanager->ncols) {
            motion_controller_withPIC_B.localActiveConstrIdx_i =
              (qrmanager->ncols - 1) * 21 + motion_controller_withPIC_B.iyend_h;
            motion_controller_withPIC_B.temp_k = qrmanager->
              QR[motion_controller_withPIC_B.localActiveConstrIdx_i + 1];
            motion_controlle_xrotg_ds3XgDMS(&qrmanager->
              QR[motion_controller_withPIC_B.localActiveConstrIdx_i],
              &motion_controller_withPIC_B.temp_k,
              &motion_controller_withPIC_B.normDelta_n,
              &motion_controller_withPIC_B.s_m);
            qrmanager->QR[motion_controller_withPIC_B.localActiveConstrIdx_i + 1]
              = motion_controller_withPIC_B.temp_k;
            motion_controller_withPIC_B.Qk0_d = 21 *
              motion_controller_withPIC_B.iyend_h;
            motion_controller_withPIC_B.iy0 = qrmanager->mrows;
            if (qrmanager->mrows >= 1) {
              for (motion_controller_withPIC_B.localActiveConstrIdx_i = 0;
                   motion_controller_withPIC_B.localActiveConstrIdx_i <
                   motion_controller_withPIC_B.iy0;
                   motion_controller_withPIC_B.localActiveConstrIdx_i++) {
                motion_controller_withPIC_B.l_n =
                  motion_controller_withPIC_B.Qk0_d +
                  motion_controller_withPIC_B.localActiveConstrIdx_i;
                motion_controller_withPIC_B.temp_tmp_j = qrmanager->
                  Q[motion_controller_withPIC_B.l_n + 21];
                motion_controller_withPIC_B.temp_k =
                  motion_controller_withPIC_B.temp_tmp_j *
                  motion_controller_withPIC_B.s_m + qrmanager->
                  Q[motion_controller_withPIC_B.l_n] *
                  motion_controller_withPIC_B.normDelta_n;
                qrmanager->Q[motion_controller_withPIC_B.l_n + 21] =
                  motion_controller_withPIC_B.temp_tmp_j *
                  motion_controller_withPIC_B.normDelta_n - qrmanager->
                  Q[motion_controller_withPIC_B.l_n] *
                  motion_controller_withPIC_B.s_m;
                qrmanager->Q[motion_controller_withPIC_B.l_n] =
                  motion_controller_withPIC_B.temp_k;
              }
            }

            motion_controller_withPIC_B.iyend_h--;
          }
          break;

         case -1:
          motion_contr_deleteColMoveEnd_a(qrmanager,
            motion_controller_withPIC_B.globalActiveConstrIdx_k);
          break;

         default:
          motion_controller_wi_factorQR_c(qrmanager, workingset->ATwset,
            motion_controller_withPIC_B.nVar_f, workingset->nActiveConstr);
          motion_controller_w_computeQ__l(qrmanager, qrmanager->mrows);
          break;
        }

        motion_control_compute_deltax_o(H, solution, memspace, qrmanager,
          cholmanager, objective);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          motion_controller_withPIC_B.normDelta_n =
            motion_controlle_xnrm2_rY1rIeLd(motion_controller_withPIC_B.nVar_f,
            solution->searchDir);
          guard1 = true;
        }
      } else {
        motion_controller_withPIC_B.iyend_h = static_cast<uint8_T>
          (motion_controller_withPIC_B.nVar_f);
        memset(&solution->searchDir[0], 0, static_cast<uint32_T>
               (motion_controller_withPIC_B.iyend_h) * sizeof(real_T));
        motion_controller_withPIC_B.normDelta_n = 0.0;
        guard1 = true;
      }

      if (guard1) {
        if ((!motion_controller_withPIC_B.subProblemChanged_i) ||
            (motion_controller_withPIC_B.normDelta_n < options_StepTolerance) ||
            (workingset->nActiveConstr >= motion_controller_withPIC_B.nVar_f)) {
          motion_controlle_compute_lambda(memspace->workspace_double, solution,
            objective, qrmanager);
          if ((solution->state != -7) || (workingset->nActiveConstr >
               motion_controller_withPIC_B.nVar_f)) {
            motion_controller_withPIC_B.iyend_h = 0;
            motion_controller_withPIC_B.normDelta_n = 0.0 *
              runTimeOptions_ProbRelTolFactor * static_cast<real_T>
              (motion_controller_withPIC_B.TYPE_b != 5);
            motion_controller_withPIC_B.Qk0_d = (workingset->nWConstr[0] +
              workingset->nWConstr[1]) + 1;
            motion_controller_withPIC_B.iy0 = workingset->nActiveConstr;
            for (motion_controller_withPIC_B.localActiveConstrIdx_i =
                 motion_controller_withPIC_B.Qk0_d;
                 motion_controller_withPIC_B.localActiveConstrIdx_i <=
                 motion_controller_withPIC_B.iy0;
                 motion_controller_withPIC_B.localActiveConstrIdx_i++) {
              motion_controller_withPIC_B.s_m = solution->
                lambda[motion_controller_withPIC_B.localActiveConstrIdx_i - 1];
              if (motion_controller_withPIC_B.s_m <
                  motion_controller_withPIC_B.normDelta_n) {
                motion_controller_withPIC_B.normDelta_n =
                  motion_controller_withPIC_B.s_m;
                motion_controller_withPIC_B.iyend_h =
                  motion_controller_withPIC_B.localActiveConstrIdx_i;
              }
            }

            if (motion_controller_withPIC_B.iyend_h == 0) {
              solution->state = 1;
            } else {
              motion_controller_withPIC_B.activeSetChangeID_n = -1;
              motion_controller_withPIC_B.globalActiveConstrIdx_k =
                motion_controller_withPIC_B.iyend_h;
              motion_controller_withPIC_B.subProblemChanged_i = true;
              motion_controlle_removeConstr_n(workingset,
                motion_controller_withPIC_B.iyend_h);
              solution->lambda[motion_controller_withPIC_B.iyend_h - 1] = 0.0;
            }
          } else {
            motion_controller_withPIC_B.iyend_h = workingset->nActiveConstr;
            motion_controller_withPIC_B.activeSetChangeID_n = 0;
            motion_controller_withPIC_B.globalActiveConstrIdx_k =
              workingset->nActiveConstr;
            motion_controller_withPIC_B.subProblemChanged_i = true;
            motion_controlle_removeConstr_n(workingset,
              workingset->nActiveConstr);
            solution->lambda[motion_controller_withPIC_B.iyend_h - 1] = 0.0;
          }

          motion_controller_withPIC_B.updateFval_n = false;
        } else {
          motion_controller_withPIC_B.updateFval_n =
            (motion_controller_withPIC_B.TYPE_b == 5);
          if (motion_controller_withPIC_B.updateFval_n ||
              runTimeOptions_RemainFeasible) {
            motion_cont_feasibleratiotest_d(solution->xstar, solution->searchDir,
              memspace->workspace_double, workingset->nVar, workingset->Aineq,
              workingset->bineq, workingset->lb, workingset->ub,
              workingset->indexLB, workingset->indexUB, workingset->sizes,
              workingset->isActiveIdx, workingset->isActiveConstr,
              workingset->nWConstr, motion_controller_withPIC_B.updateFval_n,
              &motion_controller_withPIC_B.normDelta_n,
              &motion_controller_withPIC_B.newBlocking_h,
              &motion_controller_withPIC_B.iyend_h,
              &motion_controller_withPIC_B.localActiveConstrIdx_i);
          } else {
            motion_controller_w_ratiotest_f(solution->xstar, solution->searchDir,
              memspace->workspace_double, workingset->nVar, workingset->Aineq,
              workingset->bineq, workingset->lb, workingset->ub,
              workingset->indexLB, workingset->indexUB, workingset->sizes,
              workingset->isActiveIdx, workingset->isActiveConstr,
              workingset->nWConstr, &motion_controller_withPIC_B.tolDelta_o,
              &motion_controller_withPIC_B.normDelta_n,
              &motion_controller_withPIC_B.newBlocking_h,
              &motion_controller_withPIC_B.iyend_h,
              &motion_controller_withPIC_B.localActiveConstrIdx_i);
          }

          if (motion_controller_withPIC_B.newBlocking_h) {
            switch (motion_controller_withPIC_B.iyend_h) {
             case 3:
              workingset->nWConstr[2]++;
              workingset->isActiveConstr[(workingset->isActiveIdx[2] +
                motion_controller_withPIC_B.localActiveConstrIdx_i) - 2] = true;
              workingset->nActiveConstr++;
              workingset->Wid[workingset->nActiveConstr - 1] = 3;
              workingset->Wlocalidx[workingset->nActiveConstr - 1] =
                motion_controller_withPIC_B.localActiveConstrIdx_i;
              motion_controller_withPIC_B.iyend_h =
                (motion_controller_withPIC_B.localActiveConstrIdx_i - 1) * 21;
              motion_controller_withPIC_B.Qk0_d = (workingset->nActiveConstr - 1)
                * 21;
              motion_controller_withPIC_B.iy0 = workingset->nVar - 1;
              for (motion_controller_withPIC_B.activeSetChangeID_n = 0;
                   motion_controller_withPIC_B.activeSetChangeID_n <=
                   motion_controller_withPIC_B.iy0;
                   motion_controller_withPIC_B.activeSetChangeID_n++) {
                workingset->ATwset[motion_controller_withPIC_B.Qk0_d +
                  motion_controller_withPIC_B.activeSetChangeID_n] =
                  workingset->Aineq[motion_controller_withPIC_B.iyend_h +
                  motion_controller_withPIC_B.activeSetChangeID_n];
              }

              workingset->bwset[workingset->nActiveConstr - 1] =
                workingset->
                bineq[motion_controller_withPIC_B.localActiveConstrIdx_i - 1];
              break;

             case 4:
              mo_addBoundToActiveSetMatrix__i(workingset, 4,
                motion_controller_withPIC_B.localActiveConstrIdx_i);
              break;

             default:
              mo_addBoundToActiveSetMatrix__i(workingset, 5,
                motion_controller_withPIC_B.localActiveConstrIdx_i);
              break;
            }

            motion_controller_withPIC_B.activeSetChangeID_n = 1;
          } else {
            if (objective->objtype == 5) {
              if (motion_controlle_xnrm2_rY1rIeLd(objective->nvar,
                   solution->searchDir) > 100.0 * static_cast<real_T>
                  (objective->nvar) * 1.4901161193847656E-8) {
                solution->state = 3;
              } else {
                solution->state = 4;
              }
            }

            motion_controller_withPIC_B.subProblemChanged_i = false;
            if (workingset->nActiveConstr == 0) {
              solution->state = 1;
            }
          }

          if (!(motion_controller_withPIC_B.normDelta_n == 0.0)) {
            motion_controller_withPIC_B.iyend_h =
              (motion_controller_withPIC_B.nVar_f / 2) << 1;
            motion_controller_withPIC_B.Qk0_d =
              motion_controller_withPIC_B.iyend_h - 2;
            for (motion_controller_withPIC_B.localActiveConstrIdx_i = 0;
                 motion_controller_withPIC_B.localActiveConstrIdx_i <=
                 motion_controller_withPIC_B.Qk0_d;
                 motion_controller_withPIC_B.localActiveConstrIdx_i += 2) {
              tmp = _mm_loadu_pd(&solution->
                                 searchDir[motion_controller_withPIC_B.localActiveConstrIdx_i]);
              tmp_0 = _mm_loadu_pd(&solution->
                                   xstar[motion_controller_withPIC_B.localActiveConstrIdx_i]);
              _mm_storeu_pd(&solution->
                            xstar[motion_controller_withPIC_B.localActiveConstrIdx_i],
                            _mm_add_pd(_mm_mul_pd(_mm_set1_pd
                (motion_controller_withPIC_B.normDelta_n), tmp), tmp_0));
            }

            for (motion_controller_withPIC_B.localActiveConstrIdx_i =
                 motion_controller_withPIC_B.iyend_h;
                 motion_controller_withPIC_B.localActiveConstrIdx_i <
                 motion_controller_withPIC_B.nVar_f;
                 motion_controller_withPIC_B.localActiveConstrIdx_i++) {
              solution->xstar[motion_controller_withPIC_B.localActiveConstrIdx_i]
                += motion_controller_withPIC_B.normDelta_n * solution->
                searchDir[motion_controller_withPIC_B.localActiveConstrIdx_i];
            }
          }

          motion_co_computeGrad_StoreHx_k(objective, H, f, solution->xstar);
          motion_controller_withPIC_B.updateFval_n = true;
        }

        solution->iterations++;
        if ((solution->iterations >= 200) && ((solution->state != 1) ||
             (objective->objtype == 5))) {
          solution->state = 0;
        }

        if (solution->iterations - solution->iterations / 50 * 50 == 0) {
          solution->maxConstr = motion_maxConstraintViolation_n(workingset,
            solution->xstar);
          motion_controller_withPIC_B.normDelta_n = solution->maxConstr;
          if (objective->objtype == 5) {
            motion_controller_withPIC_B.normDelta_n = solution->maxConstr -
              solution->xstar[objective->nvar - 1];
          }

          if (motion_controller_withPIC_B.normDelta_n > 1.0E-8 *
              runTimeOptions_ConstrRelTolFact) {
            motion_controller_withPIC_B.iyend_h = static_cast<uint8_T>
              (objective->nvar);
            if (motion_controller_withPIC_B.iyend_h - 1 >= 0) {
              memcpy(&solution->searchDir[0], &solution->xstar[0],
                     static_cast<uint32_T>(motion_controller_withPIC_B.iyend_h) *
                     sizeof(real_T));
            }

            motion_controller_withPIC_B.newBlocking_h =
              motio_feasibleX0ForWorkingSet_c(memspace->workspace_double,
              solution->searchDir, workingset, qrmanager);
            if ((!motion_controller_withPIC_B.newBlocking_h) && (solution->state
                 != 0)) {
              solution->state = -2;
            }

            motion_controller_withPIC_B.activeSetChangeID_n = 0;
            motion_controller_withPIC_B.normDelta_n =
              motion_maxConstraintViolation_n(workingset, solution->searchDir);
            if (motion_controller_withPIC_B.normDelta_n < solution->maxConstr) {
              if (motion_controller_withPIC_B.iyend_h - 1 >= 0) {
                memcpy(&solution->xstar[0], &solution->searchDir[0],
                       static_cast<uint32_T>(motion_controller_withPIC_B.iyend_h)
                       * sizeof(real_T));
              }

              solution->maxConstr = motion_controller_withPIC_B.normDelta_n;
            }
          }
        }

        if (motion_controller_withPIC_B.updateFval_n) {
          solution->fstar = motion_co_computeFval_ReuseHx_n(objective,
            memspace->workspace_double, f, solution->xstar);
          if ((solution->fstar < options_ObjectiveLimit) && ((solution->state !=
                0) || (objective->objtype != 5))) {
            solution->state = 2;
          }
        }
      }
    } else {
      if (!motion_controller_withPIC_B.updateFval_n) {
        solution->fstar = motion_co_computeFval_ReuseHx_n(objective,
          memspace->workspace_double, f, solution->xstar);
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motion_c_PresolveWorkingSet_gjp
  (sYqpSPVJXu9aOn60zG4DpzD_motio_T *solution, s3cSGkBdKxRj6Qn3zsJRowG_motio_T
   *memspace, sVIU4VBONGRsUytHTQmMJFH_motio_T *workingset,
   sIZAIOglGM5dPDQlNukc9SD_motio_T *qrmanager)
{
  boolean_T guard1;
  solution->state = 82;
  motion_controller_withPIC_B.mWorkingFixed_e = workingset->nWConstr[0];
  motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp = workingset->nWConstr[0]
    + workingset->nWConstr[1];
  motion_controller_withPIC_B.idxStartIneq_i = 0;
  if (motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp > 0) {
    motion_controller_withPIC_B.c_tmp = static_cast<uint8_T>(workingset->nVar);
    for (motion_controller_withPIC_B.idxStartIneq_i = 0;
         motion_controller_withPIC_B.idxStartIneq_i <
         motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp;
         motion_controller_withPIC_B.idxStartIneq_i++) {
      for (motion_controller_withPIC_B.idxEndIneq_g = 0;
           motion_controller_withPIC_B.idxEndIneq_g <
           motion_controller_withPIC_B.c_tmp;
           motion_controller_withPIC_B.idxEndIneq_g++) {
        qrmanager->QR[motion_controller_withPIC_B.idxStartIneq_i + 21 *
          motion_controller_withPIC_B.idxEndIneq_g] = workingset->ATwset[21 *
          motion_controller_withPIC_B.idxStartIneq_i +
          motion_controller_withPIC_B.idxEndIneq_g];
      }
    }

    motion_controller_withPIC_B.idxStartIneq_i = motion_ComputeNumDependentEq__d
      (qrmanager, workingset->bwset,
       motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp, workingset->nVar);
    if (motion_controller_withPIC_B.idxStartIneq_i > 0) {
      for (motion_controller_withPIC_B.idxEndIneq_g = 0;
           motion_controller_withPIC_B.idxEndIneq_g <
           motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp;
           motion_controller_withPIC_B.idxEndIneq_g++) {
        motion_controller_withPIC_B.iy0_tmp = 21 *
          motion_controller_withPIC_B.idxEndIneq_g;
        memcpy(&qrmanager->QR[motion_controller_withPIC_B.iy0_tmp],
               &workingset->ATwset[motion_controller_withPIC_B.iy0_tmp],
               static_cast<uint32_T>((motion_controller_withPIC_B.c_tmp +
                 motion_controller_withPIC_B.iy0_tmp) -
                motion_controller_withPIC_B.iy0_tmp) * sizeof(real_T));
      }

      for (motion_controller_withPIC_B.idxEndIneq_g = 0;
           motion_controller_withPIC_B.idxEndIneq_g <
           motion_controller_withPIC_B.mWorkingFixed_e;
           motion_controller_withPIC_B.idxEndIneq_g++) {
        qrmanager->jpvt[motion_controller_withPIC_B.idxEndIneq_g] = 1;
      }

      motion_controller_withPIC_B.idxEndIneq_g = workingset->nWConstr[0] + 1;
      if (motion_controller_withPIC_B.idxEndIneq_g <=
          motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp) {
        memset(&qrmanager->jpvt[motion_controller_withPIC_B.idxEndIneq_g + -1],
               0, static_cast<uint32_T>
               ((motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp -
                 motion_controller_withPIC_B.idxEndIneq_g) + 1) * sizeof(int32_T));
      }

      motion_controller_w_factorQRE_c(qrmanager, workingset->nVar,
        motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp);
      for (motion_controller_withPIC_B.idxEndIneq_g = 0;
           motion_controller_withPIC_B.idxEndIneq_g <
           motion_controller_withPIC_B.idxStartIneq_i;
           motion_controller_withPIC_B.idxEndIneq_g++) {
        memspace->workspace_int[motion_controller_withPIC_B.idxEndIneq_g] =
          qrmanager->jpvt[(motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp -
                           motion_controller_withPIC_B.idxStartIneq_i) +
          motion_controller_withPIC_B.idxEndIneq_g];
      }

      countsort_JblpZJs7(memspace->workspace_int,
                         motion_controller_withPIC_B.idxStartIneq_i,
                         memspace->workspace_sort, 1,
                         motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp);
      for (motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp =
           motion_controller_withPIC_B.idxStartIneq_i;
           motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp >= 1;
           motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp--) {
        motion_control_removeEqConstr_i(workingset, memspace->
          workspace_int[motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp - 1]);
      }
    }
  }

  if ((motion_controller_withPIC_B.idxStartIneq_i != -1) &&
      (workingset->nActiveConstr <= 21)) {
    motion_c_RemoveDependentIneq__e(workingset, qrmanager, memspace, 100.0);
    motion_controller_withPIC_B.okWorkingSet_b = motio_feasibleX0ForWorkingSet_c
      (memspace->workspace_double, solution->xstar, workingset, qrmanager);
    guard1 = false;
    if (!motion_controller_withPIC_B.okWorkingSet_b) {
      motion_c_RemoveDependentIneq__e(workingset, qrmanager, memspace, 1000.0);
      motion_controller_withPIC_B.okWorkingSet_b =
        motio_feasibleX0ForWorkingSet_c(memspace->workspace_double,
        solution->xstar, workingset, qrmanager);
      if (!motion_controller_withPIC_B.okWorkingSet_b) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (workingset->nWConstr[0] + workingset->nWConstr[1] == workingset->nVar)
      {
        motion_controller_withPIC_B.constrViolation_f =
          motion_maxConstraintViolation_n(workingset, solution->xstar);
        if (motion_controller_withPIC_B.constrViolation_f > 1.0E-8) {
          solution->state = -2;
        }
      }
    }
  } else {
    solution->state = -3;
    motion_controller_withPIC_B.idxStartIneq_i = (workingset->nWConstr[0] +
      workingset->nWConstr[1]) + 1;
    motion_controller_withPIC_B.idxEndIneq_g = workingset->nActiveConstr;
    for (motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp =
         motion_controller_withPIC_B.idxStartIneq_i;
         motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp <=
         motion_controller_withPIC_B.idxEndIneq_g;
         motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp++) {
      workingset->isActiveConstr[(workingset->isActiveIdx[workingset->
        Wid[motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp - 1] - 1] +
        workingset->
        Wlocalidx[motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp - 1]) - 2]
        = false;
    }

    workingset->nWConstr[2] = 0;
    workingset->nWConstr[3] = 0;
    workingset->nWConstr[4] = 0;
    workingset->nActiveConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  }
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motion_c_computeFirstOrderOpt_k
  (sYqpSPVJXu9aOn60zG4DpzD_motio_T *solution, const
   s3PrFoa9w5ssw8XLEJooNqH_motio_T *objective, int32_T workingset_nVar, const
   real_T workingset_ATwset[1701], int32_T workingset_nActiveConstr, real_T
   workspace[1701])
{
  real_T infNorm;
  int32_T k;
  boolean_T exitg1;
  memcpy(&workspace[0], &objective->grad[0], static_cast<uint8_T>
         (workingset_nVar) * sizeof(real_T));
  if (workingset_nActiveConstr != 0) {
    int32_T c;
    int32_T ix;
    ix = 0;
    c = (workingset_nActiveConstr - 1) * 21 + 1;
    for (k = 1; k <= c; k += 21) {
      int32_T d;
      d = (k + workingset_nVar) - 1;
      for (int32_T b = k; b <= d; b++) {
        int32_T tmp;
        tmp = b - k;
        workspace[tmp] += workingset_ATwset[b - 1] * solution->lambda[ix];
      }

      ix++;
    }
  }

  infNorm = 0.0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= static_cast<uint8_T>(workingset_nVar) - 1)) {
    real_T abs_workspace_i;
    abs_workspace_i = fabs(workspace[k]);
    if (rtIsNaN(abs_workspace_i)) {
      infNorm = (rtNaN);
      exitg1 = true;
    } else {
      if (!(infNorm >= abs_workspace_i)) {
        infNorm = abs_workspace_i;
      }

      k++;
    }
  }

  solution->firstorderopt = infNorm;
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motion_controller_with_driver_e(const real_T H
  [400], const real_T f[20], sYqpSPVJXu9aOn60zG4DpzD_motio_T *solution,
  s3cSGkBdKxRj6Qn3zsJRowG_motio_T *memspace, sVIU4VBONGRsUytHTQmMJFH_motio_T
  *workingset, sTy13TWZ7KObOACj8wDaLQC_motio_T *cholmanager,
  sSOeZ9WO10chPn9Si6PKiCB_motio_T *options, real_T
  runTimeOptions_ConstrRelTolFact, real_T runTimeOptions_ProbRelTolFactor,
  sIZAIOglGM5dPDQlNukc9SD_motio_T *qrmanager, s3PrFoa9w5ssw8XLEJooNqH_motio_T
  *objective)
{
  static const char_T j[128] = { '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
    '\x06', '\a', '\b', '\t', '\n', '\v', '\f', '\r', '\x0e', '\x0f', '\x10',
    '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19',
    '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!', '\"', '#', '$',
    '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'a', 'b',
    'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
    'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']', '^', '_', '`',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~',
    '\x7f' };

  static const char_T l[8] = { 'q', 'u', 'a', 'd', 'p', 'r', 'o', 'g' };

  int32_T exitg2;
  boolean_T exitg1;
  boolean_T guard1;
  memset(&objective->grad[0], 0, 21U * sizeof(real_T));
  memset(&objective->Hx[0], 0, 20U * sizeof(real_T));
  objective->hasLinear = true;
  objective->nvar = 20;
  objective->maxVar = 21;
  objective->beta = 0.0;
  objective->rho = 0.0;
  objective->objtype = 3;
  objective->prev_objtype = 3;
  objective->prev_nvar = 0;
  objective->prev_hasLinear = false;
  objective->gammaScalar = 0.0;
  solution->iterations = 0;
  motion_controller_withPIC_B.i_g = workingset->nVar;
  motion_controller_withPIC_B.idxStartIneq_m = static_cast<uint8_T>
    (workingset->sizes[0]);
  for (motion_controller_withPIC_B.mConstr = 0;
       motion_controller_withPIC_B.mConstr <
       motion_controller_withPIC_B.idxStartIneq_m;
       motion_controller_withPIC_B.mConstr++) {
    solution->xstar[workingset->indexFixed[motion_controller_withPIC_B.mConstr]
      - 1] = workingset->ub[workingset->
      indexFixed[motion_controller_withPIC_B.mConstr] - 1];
  }

  motion_controller_withPIC_B.idxStartIneq_m = static_cast<uint8_T>
    (workingset->sizes[3]);
  for (motion_controller_withPIC_B.mConstr = 0;
       motion_controller_withPIC_B.mConstr <
       motion_controller_withPIC_B.idxStartIneq_m;
       motion_controller_withPIC_B.mConstr++) {
    if (workingset->isActiveConstr[(workingset->isActiveIdx[3] +
         motion_controller_withPIC_B.mConstr) - 1]) {
      solution->xstar[workingset->indexLB[motion_controller_withPIC_B.mConstr] -
        1] = -workingset->lb[workingset->
        indexLB[motion_controller_withPIC_B.mConstr] - 1];
    }
  }

  motion_controller_withPIC_B.idxStartIneq_m = static_cast<uint8_T>
    (workingset->sizes[4]);
  for (motion_controller_withPIC_B.mConstr = 0;
       motion_controller_withPIC_B.mConstr <
       motion_controller_withPIC_B.idxStartIneq_m;
       motion_controller_withPIC_B.mConstr++) {
    if (workingset->isActiveConstr[(workingset->isActiveIdx[4] +
         motion_controller_withPIC_B.mConstr) - 1]) {
      solution->xstar[workingset->indexUB[motion_controller_withPIC_B.mConstr] -
        1] = workingset->ub[workingset->
        indexUB[motion_controller_withPIC_B.mConstr] - 1];
    }
  }

  motion_co_PresolveWorkingSet_gj(solution, memspace, workingset, qrmanager);
  if (solution->state >= 0) {
    solution->iterations = 0;
    solution->maxConstr = motion_maxConstraintViolation_n(workingset,
      solution->xstar);
    guard1 = false;
    if (solution->maxConstr > 1.0E-8 * runTimeOptions_ConstrRelTolFact) {
      solution->xstar[20] = solution->maxConstr + 1.0;
      motion_controller_withPIC_B.b_workingset = *workingset;
      motion_control_setProblemType_k(&motion_controller_withPIC_B.b_workingset,
        1);
      motion_controller_withPIC_B.idxStartIneq_m =
        (motion_controller_withPIC_B.b_workingset.nWConstr[0] +
         motion_controller_withPIC_B.b_workingset.nWConstr[1]) + 1;
      motion_controller_withPIC_B.idxEndIneq_o =
        motion_controller_withPIC_B.b_workingset.nActiveConstr;
      for (motion_controller_withPIC_B.mConstr =
           motion_controller_withPIC_B.idxStartIneq_m;
           motion_controller_withPIC_B.mConstr <=
           motion_controller_withPIC_B.idxEndIneq_o;
           motion_controller_withPIC_B.mConstr++) {
        motion_controller_withPIC_B.b_workingset.isActiveConstr
          [(motion_controller_withPIC_B.b_workingset.isActiveIdx[motion_controller_withPIC_B.b_workingset.Wid
            [motion_controller_withPIC_B.mConstr - 1] - 1] +
            motion_controller_withPIC_B.b_workingset.Wlocalidx[motion_controller_withPIC_B.mConstr
            - 1]) - 2] = false;
      }

      motion_controller_withPIC_B.b_workingset.nWConstr[2] = 0;
      motion_controller_withPIC_B.b_workingset.nWConstr[3] = 0;
      motion_controller_withPIC_B.b_workingset.nWConstr[4] = 0;
      motion_controller_withPIC_B.b_workingset.nActiveConstr =
        motion_controller_withPIC_B.b_workingset.nWConstr[0] +
        motion_controller_withPIC_B.b_workingset.nWConstr[1];
      objective->prev_objtype = 3;
      objective->prev_nvar = 20;
      objective->prev_hasLinear = true;
      objective->objtype = 5;
      objective->nvar = 21;
      objective->gammaScalar = 1.0;
      objective->hasLinear = true;
      solution->fstar = motion_controller_computeFval_n(objective,
        memspace->workspace_double, H, f, solution->xstar);
      solution->state = 5;
      motion_controller_wit_iterate_b(H, f, solution, memspace,
        &motion_controller_withPIC_B.b_workingset, qrmanager, cholmanager,
        objective, 1.0E-8 * runTimeOptions_ConstrRelTolFact,
        1.4901161193847657E-10, runTimeOptions_ConstrRelTolFact,
        runTimeOptions_ProbRelTolFactor, true);
      if (motion_controller_withPIC_B.b_workingset.isActiveConstr
          [(motion_controller_withPIC_B.b_workingset.isActiveIdx[3] +
            motion_controller_withPIC_B.b_workingset.sizes[3]) - 2]) {
        motion_controller_withPIC_B.mConstr =
          motion_controller_withPIC_B.b_workingset.sizes[0];
        exitg1 = false;
        while ((!exitg1) && (motion_controller_withPIC_B.mConstr + 1 <=
                             motion_controller_withPIC_B.b_workingset.nActiveConstr))
        {
          if ((motion_controller_withPIC_B.b_workingset.Wid[motion_controller_withPIC_B.mConstr]
               == 4) &&
              (motion_controller_withPIC_B.b_workingset.Wlocalidx[motion_controller_withPIC_B.mConstr]
               == motion_controller_withPIC_B.b_workingset.sizes[3])) {
            motion_controlle_removeConstr_n
              (&motion_controller_withPIC_B.b_workingset,
               motion_controller_withPIC_B.mConstr + 1);
            exitg1 = true;
          } else {
            motion_controller_withPIC_B.mConstr++;
          }
        }
      }

      motion_controller_withPIC_B.mConstr =
        motion_controller_withPIC_B.b_workingset.nActiveConstr;
      while ((motion_controller_withPIC_B.mConstr >
              motion_controller_withPIC_B.b_workingset.sizes[0]) &&
             (motion_controller_withPIC_B.mConstr > workingset->nVar)) {
        motion_controlle_removeConstr_n
          (&motion_controller_withPIC_B.b_workingset,
           motion_controller_withPIC_B.mConstr);
        motion_controller_withPIC_B.mConstr--;
      }

      solution->maxConstr = solution->xstar[20];
      motion_control_setProblemType_k(&motion_controller_withPIC_B.b_workingset,
        3);
      objective->objtype = objective->prev_objtype;
      objective->nvar = objective->prev_nvar;
      objective->hasLinear = objective->prev_hasLinear;
      options->ObjectiveLimit = -1.0E+20;
      options->StepTolerance = 1.0E-8;
      *workingset = motion_controller_withPIC_B.b_workingset;
      if (solution->state == 0) {
      } else {
        solution->maxConstr = motion_maxConstraintViolation_n
          (&motion_controller_withPIC_B.b_workingset, solution->xstar);
        *workingset = motion_controller_withPIC_B.b_workingset;
        if (solution->maxConstr > 1.0E-8 * runTimeOptions_ConstrRelTolFact) {
          memset(&solution->lambda[0], 0, 81U * sizeof(real_T));
          solution->fstar = motion_controller_computeFval_n(objective,
            memspace->workspace_double, H, f, solution->xstar);
          solution->state = -2;
        } else {
          if (solution->maxConstr > 0.0) {
            motion_controller_withPIC_B.mConstr = static_cast<uint8_T>
              (motion_controller_withPIC_B.i_g);
            if (motion_controller_withPIC_B.mConstr - 1 >= 0) {
              memcpy(&solution->searchDir[0], &solution->xstar[0],
                     static_cast<uint32_T>(motion_controller_withPIC_B.mConstr) *
                     sizeof(real_T));
            }

            motion_c_PresolveWorkingSet_gjp(solution, memspace,
              &motion_controller_withPIC_B.b_workingset, qrmanager);
            *workingset = motion_controller_withPIC_B.b_workingset;
            motion_controller_withPIC_B.maxConstr_new_p =
              motion_maxConstraintViolation_n(workingset, solution->xstar);
            if (motion_controller_withPIC_B.maxConstr_new_p >=
                solution->maxConstr) {
              solution->maxConstr = motion_controller_withPIC_B.maxConstr_new_p;
              if (motion_controller_withPIC_B.mConstr - 1 >= 0) {
                memcpy(&solution->xstar[0], &solution->searchDir[0],
                       static_cast<uint32_T>(motion_controller_withPIC_B.mConstr)
                       * sizeof(real_T));
              }
            }
          }

          guard1 = true;
        }
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      motion_controller_wit_iterate_b(H, f, solution, memspace, workingset,
        qrmanager, cholmanager, objective, options->ObjectiveLimit,
        options->StepTolerance, runTimeOptions_ConstrRelTolFact,
        runTimeOptions_ProbRelTolFactor, true);
      motion_controller_withPIC_B.b_bool = false;
      motion_controller_withPIC_B.i_g = 0;
      do {
        exitg2 = 0;
        if (motion_controller_withPIC_B.i_g < 8) {
          if (j[static_cast<int32_T>(options->
               SolverName[motion_controller_withPIC_B.i_g])] != j
              [static_cast<int32_T>(l[motion_controller_withPIC_B.i_g])]) {
            exitg2 = 1;
          } else {
            motion_controller_withPIC_B.i_g++;
          }
        } else {
          motion_controller_withPIC_B.b_bool = true;
          exitg2 = 1;
        }
      } while (exitg2 == 0);

      if (motion_controller_withPIC_B.b_bool && (solution->state != -6)) {
        solution->maxConstr = motion_maxConstraintViolation_n(workingset,
          solution->xstar);
        motion_c_computeFirstOrderOpt_k(solution, objective, workingset->nVar,
          workingset->ATwset, workingset->nActiveConstr,
          memspace->workspace_double);
        while ((solution->iterations < 200) && ((solution->state == -7) ||
                ((solution->state == 1) && ((solution->maxConstr > 1.0E-8 *
                   runTimeOptions_ConstrRelTolFact) || (solution->firstorderopt >
                   1.0E-8 * runTimeOptions_ProbRelTolFactor))))) {
          motio_feasibleX0ForWorkingSet_c(memspace->workspace_double,
            solution->xstar, workingset, qrmanager);
          motion_c_PresolveWorkingSet_gjp(solution, memspace, workingset,
            qrmanager);
          motion_controller_withPIC_B.mConstr = workingset->probType;
          motion_controller_withPIC_B.idxStartIneq_m = workingset->nVar;
          solution->xstar[20] = solution->maxConstr + 1.0;
          if (workingset->probType == 3) {
            motion_controller_withPIC_B.i_g = 1;
          } else {
            motion_controller_withPIC_B.i_g = 4;
          }

          motion_control_setProblemType_k(workingset,
            motion_controller_withPIC_B.i_g);
          motion_controller_withPIC_B.idxEndIneq_o = workingset->nWConstr[0] +
            workingset->nWConstr[1];
          motion_controller_withPIC_B.b_idxStartIneq =
            motion_controller_withPIC_B.idxEndIneq_o + 1;
          motion_controller_withPIC_B.b_idxEndIneq = workingset->nActiveConstr;
          for (motion_controller_withPIC_B.i_g =
               motion_controller_withPIC_B.b_idxStartIneq;
               motion_controller_withPIC_B.i_g <=
               motion_controller_withPIC_B.b_idxEndIneq;
               motion_controller_withPIC_B.i_g++) {
            workingset->isActiveConstr[(workingset->isActiveIdx[workingset->
              Wid[motion_controller_withPIC_B.i_g - 1] - 1] +
              workingset->Wlocalidx[motion_controller_withPIC_B.i_g - 1]) - 2] =
              false;
          }

          workingset->nWConstr[2] = 0;
          workingset->nWConstr[3] = 0;
          workingset->nWConstr[4] = 0;
          workingset->nActiveConstr = motion_controller_withPIC_B.idxEndIneq_o;
          objective->prev_objtype = objective->objtype;
          objective->prev_nvar = objective->nvar;
          objective->prev_hasLinear = objective->hasLinear;
          objective->objtype = 5;
          objective->nvar = 21;
          objective->gammaScalar = 1.0;
          objective->hasLinear = true;
          solution->fstar = motion_controller_computeFval_n(objective,
            memspace->workspace_double, H, f, solution->xstar);
          solution->state = 5;
          motion_controller_wit_iterate_b(H, f, solution, memspace, workingset,
            qrmanager, cholmanager, objective, 1.0E-8 *
            runTimeOptions_ConstrRelTolFact, 1.4901161193847657E-10,
            runTimeOptions_ConstrRelTolFact, runTimeOptions_ProbRelTolFactor,
            false);
          if (workingset->isActiveConstr[(workingset->isActiveIdx[3] +
               workingset->sizes[3]) - 2]) {
            motion_controller_withPIC_B.i_g = workingset->sizes[0];
            exitg1 = false;
            while ((!exitg1) && (motion_controller_withPIC_B.i_g + 1 <=
                                 workingset->nActiveConstr)) {
              if ((workingset->Wid[motion_controller_withPIC_B.i_g] == 4) &&
                  (workingset->Wlocalidx[motion_controller_withPIC_B.i_g] ==
                   workingset->sizes[3])) {
                motion_controlle_removeConstr_n(workingset,
                  motion_controller_withPIC_B.i_g + 1);
                exitg1 = true;
              } else {
                motion_controller_withPIC_B.i_g++;
              }
            }
          }

          motion_controller_withPIC_B.i_g = workingset->nActiveConstr;
          while ((motion_controller_withPIC_B.i_g > workingset->sizes[0]) &&
                 (motion_controller_withPIC_B.i_g >
                  motion_controller_withPIC_B.idxStartIneq_m)) {
            motion_controlle_removeConstr_n(workingset,
              motion_controller_withPIC_B.i_g);
            motion_controller_withPIC_B.i_g--;
          }

          solution->maxConstr = solution->xstar[20];
          motion_control_setProblemType_k(workingset,
            motion_controller_withPIC_B.mConstr);
          objective->objtype = objective->prev_objtype;
          objective->nvar = objective->prev_nvar;
          objective->hasLinear = objective->prev_hasLinear;
          motion_controller_wit_iterate_b(H, f, solution, memspace, workingset,
            qrmanager, cholmanager, objective, -1.0E+20, 1.0E-8,
            runTimeOptions_ConstrRelTolFact, runTimeOptions_ProbRelTolFactor,
            false);
          solution->maxConstr = motion_maxConstraintViolation_n(workingset,
            solution->xstar);
          motion_c_computeFirstOrderOpt_k(solution, objective, workingset->nVar,
            workingset->ATwset, workingset->nActiveConstr,
            memspace->workspace_double);
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S63>/solvex'
void motion_controller_withPIC::motion_controller_wi_quadprog_k(const real_T H
  [400], const real_T f[20], const real_T Aineq[800], const real_T bineq[40],
  const real_T lb[20], const real_T ub[20], real_T x0[20], const
  sSOeZ9WO10chPn9Si6PKiCB_motio_T *options)
{
  __m128d tmp;
  boolean_T exitg1;
  boolean_T guard1;
  motion_controller_withPIC_B.exitflag_o = (rtInf);
  motion_controller_withPIC_B.c_k_p = 0;
  exitg1 = false;
  while ((!exitg1) && (motion_controller_withPIC_B.c_k_p < 20)) {
    if (lb[motion_controller_withPIC_B.c_k_p] >
        ub[motion_controller_withPIC_B.c_k_p]) {
      motion_controller_withPIC_B.exitflag_o = -2.0;
      exitg1 = true;
    } else {
      motion_controller_withPIC_B.c_k_p++;
    }
  }

  if (!(motion_controller_withPIC_B.exitflag_o == -2.0)) {
    motion_controller_withPIC_B.solution_l.fstar = 0.0;
    motion_controller_withPIC_B.solution_l.firstorderopt = 0.0;
    memset(&motion_controller_withPIC_B.solution_l.lambda[0], 0, 81U * sizeof
           (real_T));
    motion_controller_withPIC_B.solution_l.state = 0;
    motion_controller_withPIC_B.solution_l.maxConstr = 0.0;
    motion_controller_withPIC_B.solution_l.iterations = 0;
    memset(&motion_controller_withPIC_B.solution_l.searchDir[0], 0, 21U * sizeof
           (real_T));
    memset(&motion_controller_withPIC_B.solution_l.xstar[0], 0, 20U * sizeof
           (real_T));
    motion_controller_withPIC_B.CholRegManager_c.ldm = 21;
    motion_controller_withPIC_B.CholRegManager_c.ndims = 0;
    motion_controller_withPIC_B.CholRegManager_c.info = 0;
    motion_controller_withPIC_B.CholRegManager_c.ConvexCheck = true;
    motion_controller_withPIC_B.CholRegManager_c.regTol_ = 0.0;
    motion_controller_withPIC_B.CholRegManager_c.scaleFactor = 100.0;
    motion_controller_withPIC_B.WorkingSet_p.nVar = 20;
    motion_controller_withPIC_B.WorkingSet_p.nVarOrig = 20;
    motion_controller_withPIC_B.WorkingSet_p.nVarMax = 21;
    motion_controller_withPIC_B.WorkingSet_p.ldA = 21;
    memset(&motion_controller_withPIC_B.WorkingSet_p.Aineq[0], 0, 840U * sizeof
           (real_T));
    memset(&motion_controller_withPIC_B.WorkingSet_p.bineq[0], 0, 40U * sizeof
           (real_T));
    memset(&motion_controller_withPIC_B.WorkingSet_p.lb[0], 0, 21U * sizeof
           (real_T));
    memset(&motion_controller_withPIC_B.WorkingSet_p.ub[0], 0, 21U * sizeof
           (real_T));
    motion_controller_withPIC_B.WorkingSet_p.mEqRemoved = 0;
    memset(&motion_controller_withPIC_B.WorkingSet_p.ATwset[0], 0, 1701U *
           sizeof(real_T));
    motion_controller_withPIC_B.WorkingSet_p.nActiveConstr = 0;
    memset(&motion_controller_withPIC_B.WorkingSet_p.bwset[0], 0, 81U * sizeof
           (real_T));
    memset(&motion_controller_withPIC_B.WorkingSet_p.maxConstrWorkspace[0], 0,
           81U * sizeof(real_T));
    memset(&motion_controller_withPIC_B.WorkingSet_p.isActiveConstr[0], 0, 81U *
           sizeof(boolean_T));
    memset(&motion_controller_withPIC_B.WorkingSet_p.Wid[0], 0, 81U * sizeof
           (int32_T));
    memset(&motion_controller_withPIC_B.WorkingSet_p.Wlocalidx[0], 0, 81U *
           sizeof(int32_T));
    for (motion_controller_withPIC_B.i_o = 0; motion_controller_withPIC_B.i_o <
         5; motion_controller_withPIC_B.i_o++) {
      motion_controller_withPIC_B.WorkingSet_p.nWConstr[motion_controller_withPIC_B.i_o]
        = 0;
    }

    motion_controller_withPIC_B.WorkingSet_p.probType = 3;
    motion_controller_withPIC_B.WorkingSet_p.SLACK0 = 1.0E-5;
    memset(&motion_controller_withPIC_B.WorkingSet_p.indexLB[0], 0, 21U * sizeof
           (int32_T));
    memset(&motion_controller_withPIC_B.WorkingSet_p.indexUB[0], 0, 21U * sizeof
           (int32_T));
    memset(&motion_controller_withPIC_B.WorkingSet_p.indexFixed[0], 0, 21U *
           sizeof(int32_T));
    motion_controller_withPIC_B.c_k_p = 40;
    motion_controller_withPIC_B.idxFillStart_i = 0;
    motion_controller_withPIC_B.colOffsetATw_n = 0;
    for (motion_controller_withPIC_B.i_o = 0; motion_controller_withPIC_B.i_o <
         20; motion_controller_withPIC_B.i_o++) {
      motion_controller_withPIC_B.exitflag_o =
        lb[motion_controller_withPIC_B.i_o];
      guard1 = false;
      if ((!rtIsInf(motion_controller_withPIC_B.exitflag_o)) && (!rtIsNaN
           (motion_controller_withPIC_B.exitflag_o))) {
        if (fabs(motion_controller_withPIC_B.exitflag_o -
                 ub[motion_controller_withPIC_B.i_o]) < 1.0E-8) {
          motion_controller_withPIC_B.colOffsetATw_n++;
          motion_controller_withPIC_B.WorkingSet_p.indexFixed[motion_controller_withPIC_B.colOffsetATw_n
            - 1] = motion_controller_withPIC_B.i_o + 1;
        } else {
          motion_controller_withPIC_B.c_k_p++;
          motion_controller_withPIC_B.WorkingSet_p.indexLB[motion_controller_withPIC_B.c_k_p
            - 41] = motion_controller_withPIC_B.i_o + 1;
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        motion_controller_withPIC_B.exitflag_o =
          ub[motion_controller_withPIC_B.i_o];
        if ((!rtIsInf(motion_controller_withPIC_B.exitflag_o)) && (!rtIsNaN
             (motion_controller_withPIC_B.exitflag_o))) {
          motion_controller_withPIC_B.idxFillStart_i++;
          motion_controller_withPIC_B.WorkingSet_p.indexUB[motion_controller_withPIC_B.idxFillStart_i
            - 1] = motion_controller_withPIC_B.i_o + 1;
        }
      }
    }

    motion_controller_withPIC_B.i_o = (motion_controller_withPIC_B.c_k_p +
      motion_controller_withPIC_B.idxFillStart_i) +
      motion_controller_withPIC_B.colOffsetATw_n;
    motion_controller_withPIC_B.WorkingSet_p.mConstr =
      motion_controller_withPIC_B.i_o;
    motion_controller_withPIC_B.WorkingSet_p.mConstrOrig =
      motion_controller_withPIC_B.i_o;
    motion_controller_withPIC_B.WorkingSet_p.mConstrMax = 81;
    motion_controller_withPIC_B.WorkingSet_p.sizes[0] =
      motion_controller_withPIC_B.colOffsetATw_n;
    motion_controller_withPIC_B.WorkingSet_p.sizes[1] = 0;
    motion_controller_withPIC_B.WorkingSet_p.sizes[2] = 40;
    motion_controller_withPIC_B.WorkingSet_p.sizes[3] =
      motion_controller_withPIC_B.c_k_p - 40;
    motion_controller_withPIC_B.WorkingSet_p.sizes[4] =
      motion_controller_withPIC_B.idxFillStart_i;
    for (motion_controller_withPIC_B.i_o = 0; motion_controller_withPIC_B.i_o <
         5; motion_controller_withPIC_B.i_o++) {
      motion_controller_withPIC_B.WorkingSet_p.sizesNormal[motion_controller_withPIC_B.i_o]
        =
        motion_controller_withPIC_B.WorkingSet_p.sizes[motion_controller_withPIC_B.i_o];
    }

    motion_controller_withPIC_B.WorkingSet_p.sizesPhaseOne[0] =
      motion_controller_withPIC_B.colOffsetATw_n;
    motion_controller_withPIC_B.WorkingSet_p.sizesPhaseOne[1] = 0;
    motion_controller_withPIC_B.WorkingSet_p.sizesPhaseOne[2] = 40;
    motion_controller_withPIC_B.WorkingSet_p.sizesPhaseOne[3] =
      motion_controller_withPIC_B.c_k_p - 39;
    motion_controller_withPIC_B.WorkingSet_p.sizesPhaseOne[4] =
      motion_controller_withPIC_B.idxFillStart_i;
    motion_controller_withPIC_B.WorkingSet_p.sizesRegularized[0] =
      motion_controller_withPIC_B.colOffsetATw_n;
    motion_controller_withPIC_B.WorkingSet_p.sizesRegularized[1] = 0;
    motion_controller_withPIC_B.WorkingSet_p.sizesRegularized[2] = 40;
    motion_controller_withPIC_B.WorkingSet_p.sizesRegularized[3] =
      motion_controller_withPIC_B.c_k_p;
    motion_controller_withPIC_B.WorkingSet_p.sizesRegularized[4] =
      motion_controller_withPIC_B.idxFillStart_i;
    motion_controller_withPIC_B.WorkingSet_p.sizesRegPhaseOne[0] =
      motion_controller_withPIC_B.colOffsetATw_n;
    motion_controller_withPIC_B.WorkingSet_p.sizesRegPhaseOne[1] = 0;
    motion_controller_withPIC_B.WorkingSet_p.sizesRegPhaseOne[2] = 40;
    motion_controller_withPIC_B.WorkingSet_p.sizesRegPhaseOne[3] =
      motion_controller_withPIC_B.c_k_p + 1;
    motion_controller_withPIC_B.WorkingSet_p.sizesRegPhaseOne[4] =
      motion_controller_withPIC_B.idxFillStart_i;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxNormal[0] = 1;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxNormal[1] =
      motion_controller_withPIC_B.colOffsetATw_n;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxNormal[2] = 0;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxNormal[3] = 40;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxNormal[4] =
      motion_controller_withPIC_B.c_k_p - 40;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxNormal[5] =
      motion_controller_withPIC_B.idxFillStart_i;
    for (motion_controller_withPIC_B.i_o = 0; motion_controller_withPIC_B.i_o <
         6; motion_controller_withPIC_B.i_o++) {
      motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_o]
        =
        motion_controller_withPIC_B.WorkingSet_p.isActiveIdxNormal[motion_controller_withPIC_B.i_o];
    }

    for (motion_controller_withPIC_B.i_o = 0; motion_controller_withPIC_B.i_o <
         5; motion_controller_withPIC_B.i_o++) {
      motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_o
        + 1] +=
        motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_o];
    }

    for (motion_controller_withPIC_B.i_o = 0; motion_controller_withPIC_B.i_o <
         6; motion_controller_withPIC_B.i_o++) {
      motion_controller_withPIC_B.WorkingSet_p.isActiveIdx[motion_controller_withPIC_B.i_o]
        =
        motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_o];
    }

    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[0] = 1;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[1] =
      motion_controller_withPIC_B.colOffsetATw_n;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[2] = 0;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[3] = 40;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[4] =
      motion_controller_withPIC_B.c_k_p - 39;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[5] =
      motion_controller_withPIC_B.idxFillStart_i;
    for (motion_controller_withPIC_B.i_o = 0; motion_controller_withPIC_B.i_o <
         5; motion_controller_withPIC_B.i_o++) {
      motion_controller_withPIC_B.WorkingSet_p.isActiveIdxNormal[motion_controller_withPIC_B.i_o
        + 1] +=
        motion_controller_withPIC_B.WorkingSet_p.isActiveIdxNormal[motion_controller_withPIC_B.i_o];
      motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_o
        + 1] +=
        motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_o];
    }

    for (motion_controller_withPIC_B.i_o = 0; motion_controller_withPIC_B.i_o <
         6; motion_controller_withPIC_B.i_o++) {
      motion_controller_withPIC_B.WorkingSet_p.isActiveIdxPhaseOne[motion_controller_withPIC_B.i_o]
        =
        motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_o];
    }

    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[0] = 1;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[1] =
      motion_controller_withPIC_B.colOffsetATw_n;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[2] = 0;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[3] = 40;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[4] =
      motion_controller_withPIC_B.c_k_p;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[5] =
      motion_controller_withPIC_B.idxFillStart_i;
    for (motion_controller_withPIC_B.i_o = 0; motion_controller_withPIC_B.i_o <
         5; motion_controller_withPIC_B.i_o++) {
      motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_o
        + 1] +=
        motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_o];
    }

    for (motion_controller_withPIC_B.i_o = 0; motion_controller_withPIC_B.i_o <
         6; motion_controller_withPIC_B.i_o++) {
      motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegularized[motion_controller_withPIC_B.i_o]
        =
        motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_o];
    }

    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[0] = 1;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[1] =
      motion_controller_withPIC_B.colOffsetATw_n;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[2] = 0;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[3] = 40;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[4] =
      motion_controller_withPIC_B.c_k_p + 1;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[5] =
      motion_controller_withPIC_B.idxFillStart_i;
    for (motion_controller_withPIC_B.c_k_p = 0;
         motion_controller_withPIC_B.c_k_p < 5;
         motion_controller_withPIC_B.c_k_p++) {
      motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.c_k_p
        + 1] +=
        motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.c_k_p];
    }

    for (motion_controller_withPIC_B.c_k_p = 0;
         motion_controller_withPIC_B.c_k_p < 20;
         motion_controller_withPIC_B.c_k_p++) {
      for (motion_controller_withPIC_B.idxFillStart_i = 0;
           motion_controller_withPIC_B.idxFillStart_i < 40;
           motion_controller_withPIC_B.idxFillStart_i++) {
        motion_controller_withPIC_B.WorkingSet_p.Aineq[motion_controller_withPIC_B.c_k_p
          + 21 * motion_controller_withPIC_B.idxFillStart_i] = Aineq[40 *
          motion_controller_withPIC_B.c_k_p +
          motion_controller_withPIC_B.idxFillStart_i];
      }
    }

    memcpy(&motion_controller_withPIC_B.WorkingSet_p.bineq[0], &bineq[0], 40U *
           sizeof(real_T));
    for (motion_controller_withPIC_B.c_k_p = 0;
         motion_controller_withPIC_B.c_k_p <= 18;
         motion_controller_withPIC_B.c_k_p += 2) {
      tmp = _mm_loadu_pd(&lb[motion_controller_withPIC_B.c_k_p]);
      _mm_storeu_pd
        (&motion_controller_withPIC_B.WorkingSet_p.lb[motion_controller_withPIC_B.c_k_p],
         _mm_mul_pd(tmp, _mm_set1_pd(-1.0)));
      tmp = _mm_loadu_pd(&ub[motion_controller_withPIC_B.c_k_p]);
      _mm_storeu_pd
        (&motion_controller_withPIC_B.WorkingSet_p.ub[motion_controller_withPIC_B.c_k_p],
         tmp);
    }

    motion_control_setProblemType_k(&motion_controller_withPIC_B.WorkingSet_p, 3);
    motion_controller_withPIC_B.idxFillStart_i =
      motion_controller_withPIC_B.WorkingSet_p.isActiveIdx[2];
    for (motion_controller_withPIC_B.c_k_p =
         motion_controller_withPIC_B.idxFillStart_i;
         motion_controller_withPIC_B.c_k_p < 82;
         motion_controller_withPIC_B.c_k_p++) {
      motion_controller_withPIC_B.WorkingSet_p.isActiveConstr[motion_controller_withPIC_B.c_k_p
        - 1] = false;
    }

    motion_controller_withPIC_B.WorkingSet_p.nWConstr[0] =
      motion_controller_withPIC_B.WorkingSet_p.sizes[0];
    motion_controller_withPIC_B.WorkingSet_p.nWConstr[1] = 0;
    motion_controller_withPIC_B.WorkingSet_p.nWConstr[2] = 0;
    motion_controller_withPIC_B.WorkingSet_p.nWConstr[3] = 0;
    motion_controller_withPIC_B.WorkingSet_p.nWConstr[4] = 0;
    motion_controller_withPIC_B.WorkingSet_p.nActiveConstr =
      motion_controller_withPIC_B.WorkingSet_p.nWConstr[0];
    motion_controller_withPIC_B.idxFillStart_i = static_cast<uint8_T>
      (motion_controller_withPIC_B.WorkingSet_p.sizes[0]);
    for (motion_controller_withPIC_B.c_k_p = 0;
         motion_controller_withPIC_B.c_k_p <
         motion_controller_withPIC_B.idxFillStart_i;
         motion_controller_withPIC_B.c_k_p++) {
      motion_controller_withPIC_B.WorkingSet_p.Wid[motion_controller_withPIC_B.c_k_p]
        = 1;
      motion_controller_withPIC_B.WorkingSet_p.Wlocalidx[motion_controller_withPIC_B.c_k_p]
        = motion_controller_withPIC_B.c_k_p + 1;
      motion_controller_withPIC_B.WorkingSet_p.isActiveConstr[motion_controller_withPIC_B.c_k_p]
        = true;
      motion_controller_withPIC_B.colOffsetATw_n = 21 *
        motion_controller_withPIC_B.c_k_p;
      motion_controller_withPIC_B.i_o =
        motion_controller_withPIC_B.WorkingSet_p.indexFixed[motion_controller_withPIC_B.c_k_p];
      if (motion_controller_withPIC_B.i_o - 2 >= 0) {
        memset
          (&motion_controller_withPIC_B.WorkingSet_p.ATwset[motion_controller_withPIC_B.colOffsetATw_n],
           0, static_cast<uint32_T>(((motion_controller_withPIC_B.i_o +
              motion_controller_withPIC_B.colOffsetATw_n) -
             motion_controller_withPIC_B.colOffsetATw_n) - 1) * sizeof(real_T));
      }

      motion_controller_withPIC_B.WorkingSet_p.ATwset
        [(motion_controller_withPIC_B.WorkingSet_p.indexFixed[motion_controller_withPIC_B.c_k_p]
          + motion_controller_withPIC_B.colOffsetATw_n) - 1] = 1.0;
      motion_controller_withPIC_B.i_o =
        motion_controller_withPIC_B.WorkingSet_p.indexFixed[motion_controller_withPIC_B.c_k_p]
        + 1;
      motion_controller_withPIC_B.e_i =
        motion_controller_withPIC_B.WorkingSet_p.nVar;
      if (motion_controller_withPIC_B.i_o <= motion_controller_withPIC_B.e_i) {
        memset(&motion_controller_withPIC_B.WorkingSet_p.ATwset
               [(motion_controller_withPIC_B.i_o +
                 motion_controller_withPIC_B.colOffsetATw_n) + -1], 0,
               static_cast<uint32_T>((((motion_controller_withPIC_B.e_i +
                   motion_controller_withPIC_B.colOffsetATw_n) -
                  motion_controller_withPIC_B.i_o) -
                 motion_controller_withPIC_B.colOffsetATw_n) + 1) * sizeof
               (real_T));
      }

      motion_controller_withPIC_B.WorkingSet_p.bwset[motion_controller_withPIC_B.c_k_p]
        =
        motion_controller_withPIC_B.WorkingSet_p.ub[motion_controller_withPIC_B.WorkingSet_p.indexFixed
        [motion_controller_withPIC_B.c_k_p] - 1];
    }

    motion_controller_withPIC_B.WorkingSet_p.SLACK0 = 0.0;
    motion_controller_withPIC_B.exitflag_o = 1.0;
    for (motion_controller_withPIC_B.c_k_p = 0;
         motion_controller_withPIC_B.c_k_p < 40;
         motion_controller_withPIC_B.c_k_p++) {
      motion_controller_withPIC_B.colSum_c = 0.0;
      motion_controller_withPIC_B.colOffsetATw_n = 21 *
        motion_controller_withPIC_B.c_k_p;
      for (motion_controller_withPIC_B.idxFillStart_i = 0;
           motion_controller_withPIC_B.idxFillStart_i < 20;
           motion_controller_withPIC_B.idxFillStart_i++) {
        motion_controller_withPIC_B.colSum_c += fabs
          (motion_controller_withPIC_B.WorkingSet_p.Aineq[motion_controller_withPIC_B.idxFillStart_i
           + motion_controller_withPIC_B.colOffsetATw_n]);
      }

      if ((!(motion_controller_withPIC_B.exitflag_o >=
             motion_controller_withPIC_B.colSum_c)) && (!rtIsNaN
           (motion_controller_withPIC_B.colSum_c))) {
        motion_controller_withPIC_B.exitflag_o =
          motion_controller_withPIC_B.colSum_c;
      }
    }

    motion_controller_withPIC_B.colSum_c = 0.0;
    motion_controller_withPIC_B.f_infnrm_h = 0.0;
    for (motion_controller_withPIC_B.c_k_p = 0;
         motion_controller_withPIC_B.c_k_p < 20;
         motion_controller_withPIC_B.c_k_p++) {
      motion_controller_withPIC_B.b_colSum_i = 0.0;
      for (motion_controller_withPIC_B.idxFillStart_i = 0;
           motion_controller_withPIC_B.idxFillStart_i < 20;
           motion_controller_withPIC_B.idxFillStart_i++) {
        motion_controller_withPIC_B.b_colSum_i += fabs(H[20 *
          motion_controller_withPIC_B.c_k_p +
          motion_controller_withPIC_B.idxFillStart_i]);
      }

      if ((!(motion_controller_withPIC_B.colSum_c >=
             motion_controller_withPIC_B.b_colSum_i)) && (!rtIsNaN
           (motion_controller_withPIC_B.b_colSum_i))) {
        motion_controller_withPIC_B.colSum_c =
          motion_controller_withPIC_B.b_colSum_i;
      }

      motion_controller_withPIC_B.b_colSum_i = fabs
        (f[motion_controller_withPIC_B.c_k_p]);
      if ((!(motion_controller_withPIC_B.f_infnrm_h >=
             motion_controller_withPIC_B.b_colSum_i)) && (!rtIsNaN
           (motion_controller_withPIC_B.b_colSum_i))) {
        motion_controller_withPIC_B.f_infnrm_h =
          motion_controller_withPIC_B.b_colSum_i;
      }
    }

    if (motion_controller_withPIC_B.exitflag_o >=
        motion_controller_withPIC_B.f_infnrm_h) {
      motion_controller_withPIC_B.f_infnrm_h =
        motion_controller_withPIC_B.exitflag_o;
    }

    if (motion_controller_withPIC_B.f_infnrm_h >=
        motion_controller_withPIC_B.colSum_c) {
      motion_controller_withPIC_B.colSum_c =
        motion_controller_withPIC_B.f_infnrm_h;
    }

    motion_controller_withPIC_B.options_m = *options;
    motion_controller_with_driver_e(H, f,
      &motion_controller_withPIC_B.solution_l,
      &motion_controller_withPIC_B.memspace_g,
      &motion_controller_withPIC_B.WorkingSet_p,
      &motion_controller_withPIC_B.CholRegManager_c,
      &motion_controller_withPIC_B.options_m,
      motion_controller_withPIC_B.exitflag_o,
      motion_controller_withPIC_B.colSum_c,
      &motion_controller_withPIC_B.QRManager_f,
      &motion_controller_withPIC_B.QPObjective_e);
    memcpy(&x0[0], &motion_controller_withPIC_B.solution_l.xstar[0], 20U *
           sizeof(real_T));
  }
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion__modifyOverheadPhaseOne_
  (sT1ziU4p6vTWuD880X9yNJ_motion_T *obj)
{
  int32_T c;
  int32_T idxStartIneq;
  idxStartIneq = static_cast<uint8_T>(obj->sizes[0]);
  for (int32_T idx = 0; idx < idxStartIneq; idx++) {
    obj->ATwset[41 * idx + 40] = 0.0;
  }

  for (int32_T idx = 0; idx < 80; idx++) {
    obj->Aineq[41 * idx + 40] = -1.0;
  }

  obj->indexLB[obj->sizes[3] - 1] = 41;
  obj->lb[40] = obj->SLACK0;
  idxStartIneq = obj->isActiveIdx[2];
  c = obj->nActiveConstr;
  for (int32_T idx = idxStartIneq; idx <= c; idx++) {
    obj->ATwset[41 * (idx - 1) + 40] = -1.0;
  }

  if (obj->nWConstr[4] > 0) {
    idxStartIneq = static_cast<uint8_T>(obj->sizesNormal[4] + 1);
    for (int32_T idx = 0; idx < idxStartIneq; idx++) {
      obj->isActiveConstr[(obj->isActiveIdx[4] + idx) - 1] = false;
    }
  }

  obj->isActiveConstr[obj->isActiveIdx[4] - 2] = false;
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_controlle_setProblemType
  (sT1ziU4p6vTWuD880X9yNJ_motion_T *obj, int32_T PROBLEM_TYPE)
{
  int32_T colOffsetATw;
  int32_T colOffsetAineq;
  int32_T i_tmp;
  int32_T idx;
  int32_T idx_lb;
  switch (PROBLEM_TYPE) {
   case 3:
    obj->nVar = 40;
    obj->mConstr = obj->mConstrOrig;
    if (obj->nWConstr[4] > 0) {
      idx_lb = static_cast<uint8_T>(obj->sizesNormal[4]);
      for (idx = 0; idx < idx_lb; idx++) {
        obj->isActiveConstr[(obj->isActiveIdxNormal[4] + idx) - 1] =
          obj->isActiveConstr[(obj->isActiveIdx[4] + idx) - 1];
      }
    }

    for (idx = 0; idx < 5; idx++) {
      obj->sizes[idx] = obj->sizesNormal[idx];
    }

    for (idx = 0; idx < 6; idx++) {
      obj->isActiveIdx[idx] = obj->isActiveIdxNormal[idx];
    }
    break;

   case 1:
    obj->nVar = 41;
    obj->mConstr = obj->mConstrOrig + 1;
    for (idx = 0; idx < 5; idx++) {
      obj->sizes[idx] = obj->sizesPhaseOne[idx];
    }

    for (idx = 0; idx < 6; idx++) {
      obj->isActiveIdx[idx] = obj->isActiveIdxPhaseOne[idx];
    }

    motion__modifyOverheadPhaseOne_(obj);
    break;

   case 2:
    obj->nVar = 40;
    obj->mConstr = 160;
    for (idx = 0; idx < 5; idx++) {
      obj->sizes[idx] = obj->sizesRegularized[idx];
    }

    if (obj->probType != 4) {
      for (idx = 0; idx < 80; idx++) {
        colOffsetAineq = 41 * idx;
        for (idx_lb = 41; idx_lb <= idx + 40; idx_lb++) {
          obj->Aineq[(idx_lb + colOffsetAineq) - 1] = 0.0;
        }

        obj->Aineq[(idx + colOffsetAineq) + 40] = -1.0;
      }

      idx_lb = 40;
      colOffsetAineq = obj->sizesNormal[3] + 1;
      colOffsetATw = obj->sizesRegularized[3];
      for (idx = colOffsetAineq; idx <= colOffsetATw; idx++) {
        idx_lb++;
        obj->indexLB[idx - 1] = idx_lb;
      }

      if (obj->nWConstr[4] > 0) {
        idx_lb = static_cast<uint8_T>(obj->sizesRegularized[4]);
        for (idx = 0; idx < idx_lb; idx++) {
          obj->isActiveConstr[obj->isActiveIdxRegularized[4] + idx] =
            obj->isActiveConstr[(obj->isActiveIdx[4] + idx) - 1];
        }
      }

      idx_lb = obj->isActiveIdx[4];
      colOffsetAineq = obj->isActiveIdxRegularized[4] - 1;
      if (idx_lb <= colOffsetAineq) {
        memset(&obj->isActiveConstr[idx_lb + -1], 0, static_cast<uint32_T>
               ((colOffsetAineq - idx_lb) + 1) * sizeof(boolean_T));
      }

      obj->lb[40] = 0.0;
      idx_lb = obj->isActiveIdx[2];
      colOffsetAineq = obj->nActiveConstr;
      for (idx = idx_lb; idx <= colOffsetAineq; idx++) {
        colOffsetATw = (idx - 1) * 41 - 1;
        if (obj->Wid[idx - 1] == 3) {
          i_tmp = obj->Wlocalidx[idx - 1];
          if (i_tmp + 39 >= 41) {
            memset(&obj->ATwset[colOffsetATw + 41], 0, static_cast<uint32_T>
                   ((((i_tmp + 39) + colOffsetATw) - colOffsetATw) - 40) *
                   sizeof(real_T));
          }

          obj->ATwset[(i_tmp + colOffsetATw) + 40] = -1.0;
          i_tmp += 41;
          if (i_tmp <= 40) {
            memset(&obj->ATwset[i_tmp + colOffsetATw], 0, static_cast<uint32_T>
                   (((colOffsetATw - i_tmp) - colOffsetATw) + 41) * sizeof
                   (real_T));
          }
        }
      }
    }

    for (idx = 0; idx < 6; idx++) {
      obj->isActiveIdx[idx] = obj->isActiveIdxRegularized[idx];
    }
    break;

   default:
    obj->nVar = 41;
    obj->mConstr = 161;
    for (idx = 0; idx < 5; idx++) {
      obj->sizes[idx] = obj->sizesRegPhaseOne[idx];
    }

    for (idx = 0; idx < 6; idx++) {
      obj->isActiveIdx[idx] = obj->isActiveIdxRegPhaseOne[idx];
    }

    motion__modifyOverheadPhaseOne_(obj);
    break;
  }

  obj->probType = PROBLEM_TYPE;
}

// Function for MATLAB Function: '<S62>/solvex'
real_T motion_controller_withPIC::motion_controlle_xnrm2_h59MJ9zm(int32_T n,
  const real_T x[6601], int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      motion_controller_withPIC_B.scale = 3.3121686421112381E-170;
      motion_controller_withPIC_B.kend = (ix0 + n) - 1;
      for (motion_controller_withPIC_B.k_e = ix0;
           motion_controller_withPIC_B.k_e <= motion_controller_withPIC_B.kend;
           motion_controller_withPIC_B.k_e++) {
        motion_controller_withPIC_B.absxk = fabs
          (x[motion_controller_withPIC_B.k_e - 1]);
        if (motion_controller_withPIC_B.absxk >
            motion_controller_withPIC_B.scale) {
          motion_controller_withPIC_B.t_jw = motion_controller_withPIC_B.scale /
            motion_controller_withPIC_B.absxk;
          y = y * motion_controller_withPIC_B.t_jw *
            motion_controller_withPIC_B.t_jw + 1.0;
          motion_controller_withPIC_B.scale = motion_controller_withPIC_B.absxk;
        } else {
          motion_controller_withPIC_B.t_jw = motion_controller_withPIC_B.absxk /
            motion_controller_withPIC_B.scale;
          y += motion_controller_withPIC_B.t_jw *
            motion_controller_withPIC_B.t_jw;
        }
      }

      y = motion_controller_withPIC_B.scale * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S62>/solvex'
real_T motion_controller_withPIC::motion_control_xzlarfg_91xlzxZq(int32_T n,
  real_T *alpha1, real_T x[6601], int32_T ix0)
{
  __m128d tmp;
  real_T tau;
  tau = 0.0;
  if (n > 0) {
    motion_controller_withPIC_B.xnorm = motion_controlle_xnrm2_h59MJ9zm(n - 1, x,
      ix0);
    if (motion_controller_withPIC_B.xnorm != 0.0) {
      motion_controller_withPIC_B.xnorm = motion_controller_rt_hypotd_snf
        (*alpha1, motion_controller_withPIC_B.xnorm);
      if (*alpha1 >= 0.0) {
        motion_controller_withPIC_B.xnorm = -motion_controller_withPIC_B.xnorm;
      }

      if (fabs(motion_controller_withPIC_B.xnorm) < 1.0020841800044864E-292) {
        motion_controller_withPIC_B.knt = 0;
        motion_controller_withPIC_B.scalarLB = (ix0 + n) - 2;
        do {
          motion_controller_withPIC_B.knt++;
          motion_controller_withPIC_B.vectorUB =
            ((((motion_controller_withPIC_B.scalarLB - ix0) + 1) / 2) << 1) +
            ix0;
          motion_controller_withPIC_B.vectorUB_tmp =
            motion_controller_withPIC_B.vectorUB - 2;
          for (motion_controller_withPIC_B.d_j = ix0;
               motion_controller_withPIC_B.d_j <=
               motion_controller_withPIC_B.vectorUB_tmp;
               motion_controller_withPIC_B.d_j += 2) {
            tmp = _mm_loadu_pd(&x[motion_controller_withPIC_B.d_j - 1]);
            _mm_storeu_pd(&x[motion_controller_withPIC_B.d_j - 1], _mm_mul_pd
                          (tmp, _mm_set1_pd(9.9792015476736E+291)));
          }

          for (motion_controller_withPIC_B.d_j =
               motion_controller_withPIC_B.vectorUB;
               motion_controller_withPIC_B.d_j <=
               motion_controller_withPIC_B.scalarLB;
               motion_controller_withPIC_B.d_j++) {
            x[motion_controller_withPIC_B.d_j - 1] *= 9.9792015476736E+291;
          }

          motion_controller_withPIC_B.xnorm *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((fabs(motion_controller_withPIC_B.xnorm) <
                  1.0020841800044864E-292) && (motion_controller_withPIC_B.knt <
                  20));

        motion_controller_withPIC_B.xnorm = motion_controller_rt_hypotd_snf
          (*alpha1, motion_controlle_xnrm2_h59MJ9zm(n - 1, x, ix0));
        if (*alpha1 >= 0.0) {
          motion_controller_withPIC_B.xnorm = -motion_controller_withPIC_B.xnorm;
        }

        tau = (motion_controller_withPIC_B.xnorm - *alpha1) /
          motion_controller_withPIC_B.xnorm;
        motion_controller_withPIC_B.a = 1.0 / (*alpha1 -
          motion_controller_withPIC_B.xnorm);
        for (motion_controller_withPIC_B.d_j = ix0;
             motion_controller_withPIC_B.d_j <=
             motion_controller_withPIC_B.vectorUB_tmp;
             motion_controller_withPIC_B.d_j += 2) {
          tmp = _mm_loadu_pd(&x[motion_controller_withPIC_B.d_j - 1]);
          _mm_storeu_pd(&x[motion_controller_withPIC_B.d_j - 1], _mm_mul_pd(tmp,
            _mm_set1_pd(motion_controller_withPIC_B.a)));
        }

        for (motion_controller_withPIC_B.d_j =
             motion_controller_withPIC_B.vectorUB;
             motion_controller_withPIC_B.d_j <=
             motion_controller_withPIC_B.scalarLB;
             motion_controller_withPIC_B.d_j++) {
          x[motion_controller_withPIC_B.d_j - 1] *=
            motion_controller_withPIC_B.a;
        }

        for (motion_controller_withPIC_B.d_j = 0;
             motion_controller_withPIC_B.d_j < motion_controller_withPIC_B.knt;
             motion_controller_withPIC_B.d_j++) {
          motion_controller_withPIC_B.xnorm *= 1.0020841800044864E-292;
        }

        *alpha1 = motion_controller_withPIC_B.xnorm;
      } else {
        tau = (motion_controller_withPIC_B.xnorm - *alpha1) /
          motion_controller_withPIC_B.xnorm;
        motion_controller_withPIC_B.a = 1.0 / (*alpha1 -
          motion_controller_withPIC_B.xnorm);
        motion_controller_withPIC_B.d_j = (ix0 + n) - 2;
        motion_controller_withPIC_B.scalarLB =
          ((((motion_controller_withPIC_B.d_j - ix0) + 1) / 2) << 1) + ix0;
        motion_controller_withPIC_B.vectorUB =
          motion_controller_withPIC_B.scalarLB - 2;
        for (motion_controller_withPIC_B.knt = ix0;
             motion_controller_withPIC_B.knt <=
             motion_controller_withPIC_B.vectorUB;
             motion_controller_withPIC_B.knt += 2) {
          tmp = _mm_loadu_pd(&x[motion_controller_withPIC_B.knt - 1]);
          _mm_storeu_pd(&x[motion_controller_withPIC_B.knt - 1], _mm_mul_pd(tmp,
            _mm_set1_pd(motion_controller_withPIC_B.a)));
        }

        for (motion_controller_withPIC_B.knt =
             motion_controller_withPIC_B.scalarLB;
             motion_controller_withPIC_B.knt <= motion_controller_withPIC_B.d_j;
             motion_controller_withPIC_B.knt++) {
          x[motion_controller_withPIC_B.knt - 1] *=
            motion_controller_withPIC_B.a;
        }

        *alpha1 = motion_controller_withPIC_B.xnorm;
      }
    }
  }

  return tau;
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_controll_xzlarf_xH4hoCMV(int32_T m,
  int32_T n, int32_T iv0, real_T tau, real_T C[6601], int32_T ic0, real_T work
  [161])
{
  if (tau != 0.0) {
    boolean_T exitg2;
    motion_controller_withPIC_B.lastv_h = m;
    motion_controller_withPIC_B.lastc_m = iv0 + m;
    while ((motion_controller_withPIC_B.lastv_h > 0) &&
           (C[motion_controller_withPIC_B.lastc_m - 2] == 0.0)) {
      motion_controller_withPIC_B.lastv_h--;
      motion_controller_withPIC_B.lastc_m--;
    }

    motion_controller_withPIC_B.lastc_m = n;
    exitg2 = false;
    while ((!exitg2) && (motion_controller_withPIC_B.lastc_m > 0)) {
      int32_T exitg1;
      motion_controller_withPIC_B.coltop_b =
        (motion_controller_withPIC_B.lastc_m - 1) * 41 + ic0;
      motion_controller_withPIC_B.b_ia_e = motion_controller_withPIC_B.coltop_b;
      do {
        exitg1 = 0;
        if (motion_controller_withPIC_B.b_ia_e <=
            (motion_controller_withPIC_B.coltop_b +
             motion_controller_withPIC_B.lastv_h) - 1) {
          if (C[motion_controller_withPIC_B.b_ia_e - 1] != 0.0) {
            exitg1 = 1;
          } else {
            motion_controller_withPIC_B.b_ia_e++;
          }
        } else {
          motion_controller_withPIC_B.lastc_m--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    motion_controller_withPIC_B.lastc_m--;
  } else {
    motion_controller_withPIC_B.lastv_h = 0;
    motion_controller_withPIC_B.lastc_m = -1;
  }

  if (motion_controller_withPIC_B.lastv_h > 0) {
    if (motion_controller_withPIC_B.lastc_m + 1 != 0) {
      if (motion_controller_withPIC_B.lastc_m >= 0) {
        memset(&work[0], 0, static_cast<uint32_T>
               (motion_controller_withPIC_B.lastc_m + 1) * sizeof(real_T));
      }

      motion_controller_withPIC_B.jA_n = 41 *
        motion_controller_withPIC_B.lastc_m + ic0;
      for (motion_controller_withPIC_B.coltop_b = ic0;
           motion_controller_withPIC_B.coltop_b <=
           motion_controller_withPIC_B.jA_n;
           motion_controller_withPIC_B.coltop_b += 41) {
        motion_controller_withPIC_B.c_j = 0.0;
        motion_controller_withPIC_B.d_f = (motion_controller_withPIC_B.coltop_b
          + motion_controller_withPIC_B.lastv_h) - 1;
        for (motion_controller_withPIC_B.b_ia_e =
             motion_controller_withPIC_B.coltop_b;
             motion_controller_withPIC_B.b_ia_e <=
             motion_controller_withPIC_B.d_f; motion_controller_withPIC_B.b_ia_e
             ++) {
          motion_controller_withPIC_B.c_j += C[((iv0 +
            motion_controller_withPIC_B.b_ia_e) -
            motion_controller_withPIC_B.coltop_b) - 1] *
            C[motion_controller_withPIC_B.b_ia_e - 1];
        }

        motion_controller_withPIC_B.b_ia_e = div_nde_s32_floor
          (motion_controller_withPIC_B.coltop_b - ic0, 41);
        work[motion_controller_withPIC_B.b_ia_e] +=
          motion_controller_withPIC_B.c_j;
      }
    }

    if (!(-tau == 0.0)) {
      motion_controller_withPIC_B.jA_n = ic0;
      for (motion_controller_withPIC_B.coltop_b = 0;
           motion_controller_withPIC_B.coltop_b <=
           motion_controller_withPIC_B.lastc_m;
           motion_controller_withPIC_B.coltop_b++) {
        motion_controller_withPIC_B.c_j =
          work[motion_controller_withPIC_B.coltop_b];
        if (motion_controller_withPIC_B.c_j != 0.0) {
          motion_controller_withPIC_B.c_j *= -tau;
          motion_controller_withPIC_B.d_f = motion_controller_withPIC_B.lastv_h
            + motion_controller_withPIC_B.jA_n;
          for (motion_controller_withPIC_B.b_ia_e =
               motion_controller_withPIC_B.jA_n;
               motion_controller_withPIC_B.b_ia_e <
               motion_controller_withPIC_B.d_f;
               motion_controller_withPIC_B.b_ia_e++) {
            C[motion_controller_withPIC_B.b_ia_e - 1] += C[((iv0 +
              motion_controller_withPIC_B.b_ia_e) -
              motion_controller_withPIC_B.jA_n) - 1] *
              motion_controller_withPIC_B.c_j;
          }
        }

        motion_controller_withPIC_B.jA_n += 41;
      }
    }
  }
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_controller__qrf_ELz1YOWw(real_T A[6601],
  int32_T m, int32_T n, int32_T nfxd, real_T tau[41])
{
  memset(&motion_controller_withPIC_B.work_d[0], 0, 161U * sizeof(real_T));
  motion_controller_withPIC_B.b_o = static_cast<uint8_T>(nfxd);
  for (motion_controller_withPIC_B.i_b = 0; motion_controller_withPIC_B.i_b <
       motion_controller_withPIC_B.b_o; motion_controller_withPIC_B.i_b++) {
    motion_controller_withPIC_B.ii = motion_controller_withPIC_B.i_b * 41 +
      motion_controller_withPIC_B.i_b;
    motion_controller_withPIC_B.mmi_j = m - motion_controller_withPIC_B.i_b;
    if (motion_controller_withPIC_B.i_b + 1 < m) {
      motion_controller_withPIC_B.b_atmp = A[motion_controller_withPIC_B.ii];
      motion_controller_withPIC_B.tau = motion_control_xzlarfg_91xlzxZq
        (motion_controller_withPIC_B.mmi_j, &motion_controller_withPIC_B.b_atmp,
         A, motion_controller_withPIC_B.ii + 2);
      tau[motion_controller_withPIC_B.i_b] = motion_controller_withPIC_B.tau;
      A[motion_controller_withPIC_B.ii] = motion_controller_withPIC_B.b_atmp;
    } else {
      motion_controller_withPIC_B.tau = 0.0;
      tau[motion_controller_withPIC_B.i_b] = 0.0;
    }

    if (motion_controller_withPIC_B.i_b + 1 < n) {
      motion_controller_withPIC_B.b_atmp = A[motion_controller_withPIC_B.ii];
      A[motion_controller_withPIC_B.ii] = 1.0;
      motion_controll_xzlarf_xH4hoCMV(motion_controller_withPIC_B.mmi_j, (n -
        motion_controller_withPIC_B.i_b) - 1, motion_controller_withPIC_B.ii + 1,
        motion_controller_withPIC_B.tau, A, motion_controller_withPIC_B.ii + 42,
        motion_controller_withPIC_B.work_d);
      A[motion_controller_withPIC_B.ii] = motion_controller_withPIC_B.b_atmp;
    }
  }
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_controller_wit_factorQRE
  (s2uO2c2bmaUl7sY5vOWIzHG_motio_T *obj, int32_T mrows, int32_T ncols)
{
  static const int32_T offsets[4] = { 0, 1, 2, 3 };

  __m128i tmp;
  if (mrows * ncols == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    obj->usedPivoting = true;
    obj->mrows = mrows;
    obj->ncols = ncols;
    if (mrows <= ncols) {
      motion_controller_withPIC_B.u1_b = mrows;
    } else {
      motion_controller_withPIC_B.u1_b = ncols;
    }

    obj->minRowCol = motion_controller_withPIC_B.u1_b;
    memset(&obj->tau[0], 0, 41U * sizeof(real_T));
    if (motion_controller_withPIC_B.u1_b < 1) {
      motion_controller_withPIC_B.nfxd = (ncols / 4) << 2;
      motion_controller_withPIC_B.i_h = motion_controller_withPIC_B.nfxd - 4;
      for (motion_controller_withPIC_B.u1_b = 0;
           motion_controller_withPIC_B.u1_b <= motion_controller_withPIC_B.i_h;
           motion_controller_withPIC_B.u1_b += 4) {
        tmp = _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32
          (motion_controller_withPIC_B.u1_b), _mm_loadu_si128((const __m128i *)
          &offsets[0])), _mm_set1_epi32(1));
        _mm_storeu_si128((__m128i *)&obj->jpvt[motion_controller_withPIC_B.u1_b],
                         tmp);
      }

      for (motion_controller_withPIC_B.u1_b = motion_controller_withPIC_B.nfxd;
           motion_controller_withPIC_B.u1_b < ncols;
           motion_controller_withPIC_B.u1_b++) {
        obj->jpvt[motion_controller_withPIC_B.u1_b] =
          motion_controller_withPIC_B.u1_b + 1;
      }
    } else {
      motion_controller_withPIC_B.nfxd = -1;
      for (motion_controller_withPIC_B.i_h = 0; motion_controller_withPIC_B.i_h <
           ncols; motion_controller_withPIC_B.i_h++) {
        if (obj->jpvt[motion_controller_withPIC_B.i_h] != 0) {
          motion_controller_withPIC_B.nfxd++;
          if (motion_controller_withPIC_B.i_h + 1 !=
              motion_controller_withPIC_B.nfxd + 1) {
            motion_controller_withPIC_B.ix_i = motion_controller_withPIC_B.i_h *
              41;
            motion_controller_withPIC_B.iy = motion_controller_withPIC_B.nfxd *
              41;
            for (motion_controller_withPIC_B.mmi = 0;
                 motion_controller_withPIC_B.mmi < mrows;
                 motion_controller_withPIC_B.mmi++) {
              motion_controller_withPIC_B.temp_tmp_p =
                motion_controller_withPIC_B.ix_i +
                motion_controller_withPIC_B.mmi;
              motion_controller_withPIC_B.temp = obj->
                QR[motion_controller_withPIC_B.temp_tmp_p];
              motion_controller_withPIC_B.itemp = motion_controller_withPIC_B.iy
                + motion_controller_withPIC_B.mmi;
              obj->QR[motion_controller_withPIC_B.temp_tmp_p] = obj->
                QR[motion_controller_withPIC_B.itemp];
              obj->QR[motion_controller_withPIC_B.itemp] =
                motion_controller_withPIC_B.temp;
            }

            obj->jpvt[motion_controller_withPIC_B.i_h] = obj->
              jpvt[motion_controller_withPIC_B.nfxd];
            obj->jpvt[motion_controller_withPIC_B.nfxd] =
              motion_controller_withPIC_B.i_h + 1;
          } else {
            obj->jpvt[motion_controller_withPIC_B.i_h] =
              motion_controller_withPIC_B.i_h + 1;
          }
        } else {
          obj->jpvt[motion_controller_withPIC_B.i_h] =
            motion_controller_withPIC_B.i_h + 1;
        }
      }

      if (motion_controller_withPIC_B.nfxd + 1 <=
          motion_controller_withPIC_B.u1_b) {
        motion_controller_withPIC_B.nfxd++;
      } else {
        motion_controller_withPIC_B.nfxd = motion_controller_withPIC_B.u1_b;
      }

      memset(&obj->tau[0], 0, 41U * sizeof(real_T));
      motion_controller__qrf_ELz1YOWw(obj->QR, mrows, ncols,
        motion_controller_withPIC_B.nfxd, obj->tau);
      if (motion_controller_withPIC_B.nfxd < motion_controller_withPIC_B.u1_b) {
        memset(&motion_controller_withPIC_B.work[0], 0, 161U * sizeof(real_T));
        memset(&motion_controller_withPIC_B.vn1[0], 0, 161U * sizeof(real_T));
        memset(&motion_controller_withPIC_B.vn2[0], 0, 161U * sizeof(real_T));
        for (motion_controller_withPIC_B.i_h = motion_controller_withPIC_B.nfxd
             + 1; motion_controller_withPIC_B.i_h <= ncols;
             motion_controller_withPIC_B.i_h++) {
          motion_controller_withPIC_B.temp = motion_controlle_xnrm2_h59MJ9zm
            (mrows - motion_controller_withPIC_B.nfxd, obj->QR,
             ((motion_controller_withPIC_B.i_h - 1) * 41 +
              motion_controller_withPIC_B.nfxd) + 1);
          motion_controller_withPIC_B.vn1[motion_controller_withPIC_B.i_h - 1] =
            motion_controller_withPIC_B.temp;
          motion_controller_withPIC_B.vn2[motion_controller_withPIC_B.i_h - 1] =
            motion_controller_withPIC_B.temp;
        }

        for (motion_controller_withPIC_B.i_h = motion_controller_withPIC_B.nfxd
             + 1; motion_controller_withPIC_B.i_h <=
             motion_controller_withPIC_B.u1_b; motion_controller_withPIC_B.i_h++)
        {
          motion_controller_withPIC_B.temp_tmp_p =
            (motion_controller_withPIC_B.i_h - 1) * 41;
          motion_controller_withPIC_B.ix_i =
            (motion_controller_withPIC_B.temp_tmp_p +
             motion_controller_withPIC_B.i_h) - 1;
          motion_controller_withPIC_B.iy = ncols -
            motion_controller_withPIC_B.i_h;
          motion_controller_withPIC_B.mmi = mrows -
            motion_controller_withPIC_B.i_h;
          if (motion_controller_withPIC_B.iy + 1 < 1) {
            motion_controller_withPIC_B.pvt = -2;
          } else {
            motion_controller_withPIC_B.pvt = -1;
            if (motion_controller_withPIC_B.iy + 1 > 1) {
              motion_controller_withPIC_B.temp = fabs
                (motion_controller_withPIC_B.vn1[motion_controller_withPIC_B.i_h
                 - 1]);
              for (motion_controller_withPIC_B.itemp = 2;
                   motion_controller_withPIC_B.itemp <=
                   motion_controller_withPIC_B.iy + 1;
                   motion_controller_withPIC_B.itemp++) {
                motion_controller_withPIC_B.s = fabs
                  (motion_controller_withPIC_B.vn1
                   [(motion_controller_withPIC_B.i_h +
                     motion_controller_withPIC_B.itemp) - 2]);
                if (motion_controller_withPIC_B.s >
                    motion_controller_withPIC_B.temp) {
                  motion_controller_withPIC_B.pvt =
                    motion_controller_withPIC_B.itemp - 2;
                  motion_controller_withPIC_B.temp =
                    motion_controller_withPIC_B.s;
                }
              }
            }
          }

          motion_controller_withPIC_B.pvt += motion_controller_withPIC_B.i_h;
          if (motion_controller_withPIC_B.pvt + 1 !=
              motion_controller_withPIC_B.i_h) {
            motion_controller_withPIC_B.c_ix = motion_controller_withPIC_B.pvt *
              41;
            for (motion_controller_withPIC_B.c_k_d = 0;
                 motion_controller_withPIC_B.c_k_d < mrows;
                 motion_controller_withPIC_B.c_k_d++) {
              motion_controller_withPIC_B.b_temp_tmp_n =
                motion_controller_withPIC_B.c_ix +
                motion_controller_withPIC_B.c_k_d;
              motion_controller_withPIC_B.temp = obj->
                QR[motion_controller_withPIC_B.b_temp_tmp_n];
              motion_controller_withPIC_B.itemp =
                motion_controller_withPIC_B.temp_tmp_p +
                motion_controller_withPIC_B.c_k_d;
              obj->QR[motion_controller_withPIC_B.b_temp_tmp_n] = obj->
                QR[motion_controller_withPIC_B.itemp];
              obj->QR[motion_controller_withPIC_B.itemp] =
                motion_controller_withPIC_B.temp;
            }

            motion_controller_withPIC_B.itemp = obj->
              jpvt[motion_controller_withPIC_B.pvt];
            obj->jpvt[motion_controller_withPIC_B.pvt] = obj->
              jpvt[motion_controller_withPIC_B.i_h - 1];
            obj->jpvt[motion_controller_withPIC_B.i_h - 1] =
              motion_controller_withPIC_B.itemp;
            motion_controller_withPIC_B.vn1[motion_controller_withPIC_B.pvt] =
              motion_controller_withPIC_B.vn1[motion_controller_withPIC_B.i_h -
              1];
            motion_controller_withPIC_B.vn2[motion_controller_withPIC_B.pvt] =
              motion_controller_withPIC_B.vn2[motion_controller_withPIC_B.i_h -
              1];
          }

          if (motion_controller_withPIC_B.i_h < mrows) {
            motion_controller_withPIC_B.temp = obj->
              QR[motion_controller_withPIC_B.ix_i];
            obj->tau[motion_controller_withPIC_B.i_h - 1] =
              motion_control_xzlarfg_91xlzxZq(motion_controller_withPIC_B.mmi +
              1, &motion_controller_withPIC_B.temp, obj->QR,
              motion_controller_withPIC_B.ix_i + 2);
            obj->QR[motion_controller_withPIC_B.ix_i] =
              motion_controller_withPIC_B.temp;
          } else {
            obj->tau[motion_controller_withPIC_B.i_h - 1] = 0.0;
          }

          if (motion_controller_withPIC_B.i_h < ncols) {
            motion_controller_withPIC_B.temp = obj->
              QR[motion_controller_withPIC_B.ix_i];
            obj->QR[motion_controller_withPIC_B.ix_i] = 1.0;
            motion_controll_xzlarf_xH4hoCMV(motion_controller_withPIC_B.mmi + 1,
              motion_controller_withPIC_B.iy, motion_controller_withPIC_B.ix_i +
              1, obj->tau[motion_controller_withPIC_B.i_h - 1], obj->QR,
              motion_controller_withPIC_B.ix_i + 42,
              motion_controller_withPIC_B.work);
            obj->QR[motion_controller_withPIC_B.ix_i] =
              motion_controller_withPIC_B.temp;
          }

          for (motion_controller_withPIC_B.itemp =
               motion_controller_withPIC_B.i_h + 1;
               motion_controller_withPIC_B.itemp <= ncols;
               motion_controller_withPIC_B.itemp++) {
            motion_controller_withPIC_B.ix_i =
              (motion_controller_withPIC_B.itemp - 1) * 41 +
              motion_controller_withPIC_B.i_h;
            motion_controller_withPIC_B.temp =
              motion_controller_withPIC_B.vn1[motion_controller_withPIC_B.itemp
              - 1];
            if (motion_controller_withPIC_B.temp != 0.0) {
              motion_controller_withPIC_B.s = fabs(obj->
                QR[motion_controller_withPIC_B.ix_i - 1]) /
                motion_controller_withPIC_B.temp;
              motion_controller_withPIC_B.s = 1.0 -
                motion_controller_withPIC_B.s * motion_controller_withPIC_B.s;
              if (motion_controller_withPIC_B.s < 0.0) {
                motion_controller_withPIC_B.s = 0.0;
              }

              motion_controller_withPIC_B.temp2 =
                motion_controller_withPIC_B.temp /
                motion_controller_withPIC_B.vn2[motion_controller_withPIC_B.itemp
                - 1];
              motion_controller_withPIC_B.temp2 =
                motion_controller_withPIC_B.temp2 *
                motion_controller_withPIC_B.temp2 *
                motion_controller_withPIC_B.s;
              if (motion_controller_withPIC_B.temp2 <= 1.4901161193847656E-8) {
                if (motion_controller_withPIC_B.i_h < mrows) {
                  motion_controller_withPIC_B.temp =
                    motion_controlle_xnrm2_h59MJ9zm
                    (motion_controller_withPIC_B.mmi, obj->QR,
                     motion_controller_withPIC_B.ix_i + 1);
                  motion_controller_withPIC_B.vn1[motion_controller_withPIC_B.itemp
                    - 1] = motion_controller_withPIC_B.temp;
                  motion_controller_withPIC_B.vn2[motion_controller_withPIC_B.itemp
                    - 1] = motion_controller_withPIC_B.temp;
                } else {
                  motion_controller_withPIC_B.vn1[motion_controller_withPIC_B.itemp
                    - 1] = 0.0;
                  motion_controller_withPIC_B.vn2[motion_controller_withPIC_B.itemp
                    - 1] = 0.0;
                }
              } else {
                motion_controller_withPIC_B.vn1[motion_controller_withPIC_B.itemp
                  - 1] = motion_controller_withPIC_B.temp * sqrt
                  (motion_controller_withPIC_B.s);
              }
            }
          }
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_controller_wit_computeQ_
  (s2uO2c2bmaUl7sY5vOWIzHG_motio_T *obj, int32_T nrows)
{
  motion_controller_withPIC_B.i_i = obj->minRowCol;
  for (motion_controller_withPIC_B.idx_a = 0; motion_controller_withPIC_B.idx_a <
       motion_controller_withPIC_B.i_i; motion_controller_withPIC_B.idx_a++) {
    motion_controller_withPIC_B.iQR0 = 41 * motion_controller_withPIC_B.idx_a +
      motion_controller_withPIC_B.idx_a;
    motion_controller_withPIC_B.ia = obj->mrows -
      motion_controller_withPIC_B.idx_a;
    if (motion_controller_withPIC_B.ia - 2 >= 0) {
      memcpy(&obj->Q[motion_controller_withPIC_B.iQR0 + 1], &obj->
             QR[motion_controller_withPIC_B.iQR0 + 1], static_cast<uint32_T>
             (((motion_controller_withPIC_B.ia +
                motion_controller_withPIC_B.iQR0) -
               motion_controller_withPIC_B.iQR0) - 1) * sizeof(real_T));
    }
  }

  motion_controller_withPIC_B.idx_a = obj->mrows;
  if (nrows >= 1) {
    for (motion_controller_withPIC_B.itau = motion_controller_withPIC_B.i_i;
         motion_controller_withPIC_B.itau < nrows;
         motion_controller_withPIC_B.itau++) {
      motion_controller_withPIC_B.ia = motion_controller_withPIC_B.itau * 41;
      memset(&obj->Q[motion_controller_withPIC_B.ia], 0, static_cast<uint32_T>
             ((motion_controller_withPIC_B.idx_a +
               motion_controller_withPIC_B.ia) - motion_controller_withPIC_B.ia)
             * sizeof(real_T));
      obj->Q[motion_controller_withPIC_B.ia + motion_controller_withPIC_B.itau] =
        1.0;
    }

    motion_controller_withPIC_B.itau = obj->minRowCol - 1;
    memset(&motion_controller_withPIC_B.work_b[0], 0, 41U * sizeof(real_T));
    motion_controller_withPIC_B.i_i = obj->minRowCol;
    while (motion_controller_withPIC_B.i_i >= 1) {
      motion_controller_withPIC_B.iQR0 = ((motion_controller_withPIC_B.i_i - 1) *
        41 + motion_controller_withPIC_B.i_i) - 1;
      if (motion_controller_withPIC_B.i_i < nrows) {
        obj->Q[motion_controller_withPIC_B.iQR0] = 1.0;
        motion_controller_withPIC_B.ia = motion_controller_withPIC_B.idx_a -
          motion_controller_withPIC_B.i_i;
        if (obj->tau[motion_controller_withPIC_B.itau] != 0.0) {
          boolean_T exitg2;
          motion_controller_withPIC_B.lastc = motion_controller_withPIC_B.iQR0 +
            motion_controller_withPIC_B.ia;
          while ((motion_controller_withPIC_B.ia + 1 > 0) && (obj->
                  Q[motion_controller_withPIC_B.lastc] == 0.0)) {
            motion_controller_withPIC_B.ia--;
            motion_controller_withPIC_B.lastc--;
          }

          motion_controller_withPIC_B.lastc = nrows -
            motion_controller_withPIC_B.i_i;
          exitg2 = false;
          while ((!exitg2) && (motion_controller_withPIC_B.lastc > 0)) {
            int32_T exitg1;
            motion_controller_withPIC_B.coltop =
              ((motion_controller_withPIC_B.lastc - 1) * 41 +
               motion_controller_withPIC_B.iQR0) + 42;
            motion_controller_withPIC_B.c_ia =
              motion_controller_withPIC_B.coltop;
            do {
              exitg1 = 0;
              if (motion_controller_withPIC_B.c_ia <=
                  motion_controller_withPIC_B.coltop +
                  motion_controller_withPIC_B.ia) {
                if (obj->Q[motion_controller_withPIC_B.c_ia - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  motion_controller_withPIC_B.c_ia++;
                }
              } else {
                motion_controller_withPIC_B.lastc--;
                exitg1 = 2;
              }
            } while (exitg1 == 0);

            if (exitg1 == 1) {
              exitg2 = true;
            }
          }

          motion_controller_withPIC_B.lastc--;
        } else {
          motion_controller_withPIC_B.ia = -1;
          motion_controller_withPIC_B.lastc = -1;
        }

        if (motion_controller_withPIC_B.ia + 1 > 0) {
          if (motion_controller_withPIC_B.lastc + 1 != 0) {
            if (motion_controller_withPIC_B.lastc >= 0) {
              memset(&motion_controller_withPIC_B.work_b[0], 0,
                     static_cast<uint32_T>(motion_controller_withPIC_B.lastc + 1)
                     * sizeof(real_T));
            }

            motion_controller_withPIC_B.c_ia = (41 *
              motion_controller_withPIC_B.lastc +
              motion_controller_withPIC_B.iQR0) + 42;
            for (motion_controller_withPIC_B.coltop =
                 motion_controller_withPIC_B.iQR0 + 42;
                 motion_controller_withPIC_B.coltop <=
                 motion_controller_withPIC_B.c_ia;
                 motion_controller_withPIC_B.coltop += 41) {
              motion_controller_withPIC_B.b_c = 0.0;
              motion_controller_withPIC_B.f = motion_controller_withPIC_B.coltop
                + motion_controller_withPIC_B.ia;
              for (motion_controller_withPIC_B.jA =
                   motion_controller_withPIC_B.coltop;
                   motion_controller_withPIC_B.jA <=
                   motion_controller_withPIC_B.f; motion_controller_withPIC_B.jA
                   ++) {
                motion_controller_withPIC_B.b_c += obj->Q
                  [(motion_controller_withPIC_B.iQR0 +
                    motion_controller_withPIC_B.jA) -
                  motion_controller_withPIC_B.coltop] * obj->
                  Q[motion_controller_withPIC_B.jA - 1];
              }

              motion_controller_withPIC_B.jA = div_nde_s32_floor
                ((motion_controller_withPIC_B.coltop -
                  motion_controller_withPIC_B.iQR0) - 42, 41);
              motion_controller_withPIC_B.work_b[motion_controller_withPIC_B.jA]
                += motion_controller_withPIC_B.b_c;
            }
          }

          if (!(-obj->tau[motion_controller_withPIC_B.itau] == 0.0)) {
            motion_controller_withPIC_B.jA = motion_controller_withPIC_B.iQR0 +
              42;
            for (motion_controller_withPIC_B.coltop = 0;
                 motion_controller_withPIC_B.coltop <=
                 motion_controller_withPIC_B.lastc;
                 motion_controller_withPIC_B.coltop++) {
              motion_controller_withPIC_B.b_c =
                motion_controller_withPIC_B.work_b[motion_controller_withPIC_B.coltop];
              if (motion_controller_withPIC_B.b_c != 0.0) {
                motion_controller_withPIC_B.b_c *= -obj->
                  tau[motion_controller_withPIC_B.itau];
                motion_controller_withPIC_B.f = motion_controller_withPIC_B.ia +
                  motion_controller_withPIC_B.jA;
                for (motion_controller_withPIC_B.c_ia =
                     motion_controller_withPIC_B.jA;
                     motion_controller_withPIC_B.c_ia <=
                     motion_controller_withPIC_B.f;
                     motion_controller_withPIC_B.c_ia++) {
                  obj->Q[motion_controller_withPIC_B.c_ia - 1] += obj->Q
                    [(motion_controller_withPIC_B.iQR0 +
                      motion_controller_withPIC_B.c_ia) -
                    motion_controller_withPIC_B.jA] *
                    motion_controller_withPIC_B.b_c;
                }
              }

              motion_controller_withPIC_B.jA += 41;
            }
          }
        }
      }

      if (motion_controller_withPIC_B.i_i < motion_controller_withPIC_B.idx_a) {
        motion_controller_withPIC_B.lastc = ((motion_controller_withPIC_B.iQR0 +
          motion_controller_withPIC_B.idx_a) - motion_controller_withPIC_B.i_i)
          + 1;
        for (motion_controller_withPIC_B.ia = motion_controller_withPIC_B.iQR0 +
             2; motion_controller_withPIC_B.ia <=
             motion_controller_withPIC_B.lastc; motion_controller_withPIC_B.ia++)
        {
          obj->Q[motion_controller_withPIC_B.ia - 1] *= -obj->
            tau[motion_controller_withPIC_B.itau];
        }
      }

      obj->Q[motion_controller_withPIC_B.iQR0] = 1.0 - obj->
        tau[motion_controller_withPIC_B.itau];
      motion_controller_withPIC_B.lastc = static_cast<uint8_T>
        (motion_controller_withPIC_B.i_i - 1);
      for (motion_controller_withPIC_B.ia = 0; motion_controller_withPIC_B.ia <
           motion_controller_withPIC_B.lastc; motion_controller_withPIC_B.ia++)
      {
        obj->Q[(motion_controller_withPIC_B.iQR0 -
                motion_controller_withPIC_B.ia) - 1] = 0.0;
      }

      motion_controller_withPIC_B.itau--;
      motion_controller_withPIC_B.i_i--;
    }
  }
}

// Function for MATLAB Function: '<S62>/solvex'
int32_T motion_controller_withPIC::motion_c_ComputeNumDependentEq_
  (s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager, const real_T beqf[161], int32_T
   mConstr, int32_T nVar)
{
  int32_T numDependent;
  boolean_T exitg1;
  numDependent = mConstr - nVar;
  if (numDependent <= 0) {
    numDependent = 0;
  }

  motion_controller_withPIC_B.b_h = static_cast<uint8_T>(nVar);
  memset(&qrmanager->jpvt[0], 0, static_cast<uint32_T>
         (motion_controller_withPIC_B.b_h) * sizeof(int32_T));
  motion_controller_wit_factorQRE(qrmanager, mConstr, nVar);
  motion_controller_withPIC_B.tol = 100.0 * static_cast<real_T>(nVar) *
    2.2204460492503131E-16;
  if (nVar <= mConstr) {
    motion_controller_withPIC_B.totalRank = nVar;
  } else {
    motion_controller_withPIC_B.totalRank = mConstr;
  }

  motion_controller_withPIC_B.totalRank +=
    (motion_controller_withPIC_B.totalRank - 1) * 41;
  while ((motion_controller_withPIC_B.totalRank > 0) && (fabs(qrmanager->
           QR[motion_controller_withPIC_B.totalRank - 1]) <
          motion_controller_withPIC_B.tol)) {
    motion_controller_withPIC_B.totalRank -= 42;
    numDependent++;
  }

  if (numDependent > 0) {
    motion_controller_wit_computeQ_(qrmanager, qrmanager->mrows);
    motion_controller_withPIC_B.b_h = 0;
    exitg1 = false;
    while ((!exitg1) && (motion_controller_withPIC_B.b_h <= numDependent - 1)) {
      motion_controller_withPIC_B.ix = ((mConstr -
        motion_controller_withPIC_B.b_h) - 1) * 41;
      motion_controller_withPIC_B.qtb = 0.0;
      for (motion_controller_withPIC_B.totalRank = 0;
           motion_controller_withPIC_B.totalRank < mConstr;
           motion_controller_withPIC_B.totalRank++) {
        motion_controller_withPIC_B.qtb += qrmanager->
          Q[motion_controller_withPIC_B.ix +
          motion_controller_withPIC_B.totalRank] *
          beqf[motion_controller_withPIC_B.totalRank];
      }

      if (fabs(motion_controller_withPIC_B.qtb) >=
          motion_controller_withPIC_B.tol) {
        numDependent = -1;
        exitg1 = true;
      } else {
        motion_controller_withPIC_B.b_h++;
      }
    }
  }

  return numDependent;
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_controller__removeConstr
  (sT1ziU4p6vTWuD880X9yNJ_motion_T *obj, int32_T idx_global)
{
  int32_T TYPE_tmp;
  int32_T b;
  TYPE_tmp = obj->Wid[idx_global - 1] - 1;
  obj->isActiveConstr[(obj->isActiveIdx[TYPE_tmp] + obj->Wlocalidx[idx_global -
                       1]) - 2] = false;
  obj->Wid[idx_global - 1] = obj->Wid[obj->nActiveConstr - 1];
  obj->Wlocalidx[idx_global - 1] = obj->Wlocalidx[obj->nActiveConstr - 1];
  b = static_cast<uint8_T>(obj->nVar);
  for (int32_T idx = 0; idx < b; idx++) {
    obj->ATwset[idx + 41 * (idx_global - 1)] = obj->ATwset[(obj->nActiveConstr -
      1) * 41 + idx];
  }

  obj->bwset[idx_global - 1] = obj->bwset[obj->nActiveConstr - 1];
  obj->nActiveConstr--;
  obj->nWConstr[TYPE_tmp]--;
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_controlle_removeEqConstr
  (sT1ziU4p6vTWuD880X9yNJ_motion_T *obj, int32_T idx_global)
{
  int32_T TYPE_tmp;
  int32_T b_tmp;
  int32_T idx;
  int32_T totalEq;
  totalEq = (obj->nWConstr[0] + obj->nWConstr[1]) - 1;
  if ((totalEq + 1 != 0) && (idx_global <= totalEq + 1)) {
    if ((totalEq + 1 == obj->nActiveConstr) || (totalEq + 1 == idx_global)) {
      obj->mEqRemoved++;
      motion_controller__removeConstr(obj, idx_global);
    } else {
      obj->mEqRemoved++;
      TYPE_tmp = obj->Wid[idx_global - 1] - 1;
      obj->isActiveConstr[(obj->isActiveIdx[TYPE_tmp] + obj->
                           Wlocalidx[idx_global - 1]) - 2] = false;
      obj->Wid[idx_global - 1] = obj->Wid[totalEq];
      obj->Wlocalidx[idx_global - 1] = obj->Wlocalidx[totalEq];
      b_tmp = static_cast<uint8_T>(obj->nVar);
      for (idx = 0; idx < b_tmp; idx++) {
        obj->ATwset[idx + 41 * (idx_global - 1)] = obj->ATwset[41 * totalEq +
          idx];
      }

      obj->bwset[idx_global - 1] = obj->bwset[totalEq];
      obj->Wid[totalEq] = obj->Wid[obj->nActiveConstr - 1];
      obj->Wlocalidx[totalEq] = obj->Wlocalidx[obj->nActiveConstr - 1];
      for (idx = 0; idx < b_tmp; idx++) {
        obj->ATwset[idx + 41 * totalEq] = obj->ATwset[(obj->nActiveConstr - 1) *
          41 + idx];
      }

      obj->bwset[totalEq] = obj->bwset[obj->nActiveConstr - 1];
      obj->nActiveConstr--;
      obj->nWConstr[TYPE_tmp]--;
    }
  }
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_contr_RemoveDependentEq_
  (sFlCINAYeIgPgx0UwEHpaMF_motio_T *memspace, sT1ziU4p6vTWuD880X9yNJ_motion_T
   *workingset, int32_T *nDepInd, s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager)
{
  int32_T b_tmp;
  int32_T c_tmp;
  int32_T i;
  int32_T idx_col;
  int32_T idx_row;
  qrmanager->ldq = 41;
  memset(&qrmanager->QR[0], 0, 6601U * sizeof(real_T));
  memset(&qrmanager->Q[0], 0, 1681U * sizeof(real_T));
  memset(&qrmanager->jpvt[0], 0, 161U * sizeof(int32_T));
  qrmanager->mrows = 0;
  qrmanager->ncols = 0;
  memset(&qrmanager->tau[0], 0, 41U * sizeof(real_T));
  qrmanager->minRowCol = 0;
  qrmanager->usedPivoting = false;
  i = workingset->nWConstr[0];
  *nDepInd = 0;
  if (workingset->nWConstr[0] > 0) {
    b_tmp = static_cast<uint8_T>(workingset->nWConstr[0]);
    c_tmp = static_cast<uint8_T>(workingset->nVar);
    for (idx_row = 0; idx_row < b_tmp; idx_row++) {
      for (idx_col = 0; idx_col < c_tmp; idx_col++) {
        qrmanager->QR[idx_row + 41 * idx_col] = workingset->ATwset[41 * idx_row
          + idx_col];
      }
    }

    *nDepInd = motion_c_ComputeNumDependentEq_(qrmanager, workingset->bwset,
      workingset->nWConstr[0], workingset->nVar);
    if (*nDepInd > 0) {
      for (idx_row = 0; idx_row < b_tmp; idx_row++) {
        idx_col = 41 * idx_row;
        memcpy(&qrmanager->QR[idx_col], &workingset->ATwset[idx_col],
               static_cast<uint32_T>((c_tmp + idx_col) - idx_col) * sizeof
               (real_T));
      }

      for (b_tmp = 0; b_tmp < i; b_tmp++) {
        qrmanager->jpvt[b_tmp] = 1;
      }

      c_tmp = workingset->nWConstr[0] + 1;
      if (c_tmp <= i) {
        memset(&qrmanager->jpvt[c_tmp + -1], 0, static_cast<uint32_T>((i - c_tmp)
                + 1) * sizeof(int32_T));
      }

      motion_controller_wit_factorQRE(qrmanager, workingset->nVar,
        workingset->nWConstr[0]);
      for (b_tmp = 0; b_tmp < *nDepInd; b_tmp++) {
        memspace->workspace_int[b_tmp] = qrmanager->jpvt[(i - *nDepInd) + b_tmp];
      }

      countsort_Ormz6pKD(memspace->workspace_int, *nDepInd,
                         memspace->workspace_sort, 1, workingset->nWConstr[0]);
      for (i = *nDepInd; i >= 1; i--) {
        motion_controlle_removeEqConstr(workingset, memspace->workspace_int[i -
          1]);
      }
    }
  }
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_con_RemoveDependentIneq_
  (sT1ziU4p6vTWuD880X9yNJ_motion_T *workingset, s2uO2c2bmaUl7sY5vOWIzHG_motio_T *
   qrmanager, sFlCINAYeIgPgx0UwEHpaMF_motio_T *memspace, real_T tolfactor)
{
  real_T tol;
  int32_T iy0_tmp;
  int32_T nActiveConstr_tmp;
  int32_T nDepIneq;
  int32_T nFixedConstr;
  int32_T nVar;
  nActiveConstr_tmp = workingset->nActiveConstr;
  nFixedConstr = workingset->nWConstr[0] + workingset->nWConstr[1];
  nVar = workingset->nVar;
  if ((workingset->nWConstr[2] + workingset->nWConstr[3]) + workingset->
      nWConstr[4] > 0) {
    tol = tolfactor * static_cast<real_T>(workingset->nVar) *
      2.2204460492503131E-16;
    for (nDepIneq = 0; nDepIneq < nFixedConstr; nDepIneq++) {
      qrmanager->jpvt[nDepIneq] = 1;
    }

    if (nFixedConstr + 1 <= workingset->nActiveConstr) {
      memset(&qrmanager->jpvt[nFixedConstr], 0, static_cast<uint32_T>
             (workingset->nActiveConstr - nFixedConstr) * sizeof(int32_T));
    }

    for (nDepIneq = 0; nDepIneq < nActiveConstr_tmp; nDepIneq++) {
      iy0_tmp = 41 * nDepIneq;
      memcpy(&qrmanager->QR[iy0_tmp], &workingset->ATwset[iy0_tmp], static_cast<
             uint32_T>((static_cast<uint8_T>(nVar) + iy0_tmp) - iy0_tmp) *
             sizeof(real_T));
    }

    motion_controller_wit_factorQRE(qrmanager, workingset->nVar,
      workingset->nActiveConstr);
    nDepIneq = 0;
    for (nActiveConstr_tmp = workingset->nActiveConstr - 1; nActiveConstr_tmp +
         1 > nVar; nActiveConstr_tmp--) {
      nDepIneq++;
      memspace->workspace_int[nDepIneq - 1] = qrmanager->jpvt[nActiveConstr_tmp];
    }

    if (nActiveConstr_tmp + 1 <= workingset->nVar) {
      nVar = 41 * nActiveConstr_tmp + nActiveConstr_tmp;
      while ((nActiveConstr_tmp + 1 > nFixedConstr) && (fabs(qrmanager->QR[nVar])
              < tol)) {
        nDepIneq++;
        memspace->workspace_int[nDepIneq - 1] = qrmanager->
          jpvt[nActiveConstr_tmp];
        nActiveConstr_tmp--;
        nVar -= 42;
      }
    }

    countsort_Ormz6pKD(memspace->workspace_int, nDepIneq,
                       memspace->workspace_sort, nFixedConstr + 1,
                       workingset->nActiveConstr);
    for (nFixedConstr = nDepIneq; nFixedConstr >= 1; nFixedConstr--) {
      motion_controller__removeConstr(workingset, memspace->
        workspace_int[nFixedConstr - 1]);
    }
  }
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_controller_with_factorQR
  (s2uO2c2bmaUl7sY5vOWIzHG_motio_T *obj, const real_T A[6601], int32_T mrows,
   int32_T ncols)
{
  static const int32_T offsets[4] = { 0, 1, 2, 3 };

  __m128i tmp;
  boolean_T guard1;
  motion_controller_withPIC_B.k_p = mrows * ncols;
  guard1 = false;
  if (motion_controller_withPIC_B.k_p > 0) {
    for (motion_controller_withPIC_B.i_at = 0; motion_controller_withPIC_B.i_at <
         ncols; motion_controller_withPIC_B.i_at++) {
      motion_controller_withPIC_B.ix0_tmp_n = 41 *
        motion_controller_withPIC_B.i_at;
      motion_controller_withPIC_B.k_p = static_cast<uint8_T>(mrows);
      memcpy(&obj->QR[motion_controller_withPIC_B.ix0_tmp_n],
             &A[motion_controller_withPIC_B.ix0_tmp_n], static_cast<uint32_T>
             ((motion_controller_withPIC_B.k_p +
               motion_controller_withPIC_B.ix0_tmp_n) -
              motion_controller_withPIC_B.ix0_tmp_n) * sizeof(real_T));
    }

    guard1 = true;
  } else if (motion_controller_withPIC_B.k_p == 0) {
    obj->mrows = mrows;
    obj->ncols = ncols;
    obj->minRowCol = 0;
  } else {
    guard1 = true;
  }

  if (guard1) {
    obj->usedPivoting = false;
    obj->mrows = mrows;
    obj->ncols = ncols;
    motion_controller_withPIC_B.k_p = (ncols / 4) << 2;
    motion_controller_withPIC_B.ix0_tmp_n = motion_controller_withPIC_B.k_p - 4;
    for (motion_controller_withPIC_B.i_at = 0; motion_controller_withPIC_B.i_at <=
         motion_controller_withPIC_B.ix0_tmp_n; motion_controller_withPIC_B.i_at
         += 4) {
      tmp = _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32
        (motion_controller_withPIC_B.i_at), _mm_loadu_si128((const __m128i *)
        &offsets[0])), _mm_set1_epi32(1));
      _mm_storeu_si128((__m128i *)&obj->jpvt[motion_controller_withPIC_B.i_at],
                       tmp);
    }

    for (motion_controller_withPIC_B.i_at = motion_controller_withPIC_B.k_p;
         motion_controller_withPIC_B.i_at < ncols;
         motion_controller_withPIC_B.i_at++) {
      obj->jpvt[motion_controller_withPIC_B.i_at] =
        motion_controller_withPIC_B.i_at + 1;
    }

    if (mrows <= ncols) {
      motion_controller_withPIC_B.k_p = mrows;
    } else {
      motion_controller_withPIC_B.k_p = ncols;
    }

    obj->minRowCol = motion_controller_withPIC_B.k_p;
    memset(&obj->tau[0], 0, 41U * sizeof(real_T));
    if (motion_controller_withPIC_B.k_p >= 1) {
      memset(&obj->tau[0], 0, 41U * sizeof(real_T));
      motion_controller__qrf_ELz1YOWw(obj->QR, mrows, ncols,
        motion_controller_withPIC_B.k_p, obj->tau);
    }
  }
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_controlle_xgemv_kCjzUKKr(int32_T m, const
  real_T A[3280], const real_T x[6601], real_T y[161])
{
  for (motion_controller_withPIC_B.b_iy_o = 0;
       motion_controller_withPIC_B.b_iy_o <= 78;
       motion_controller_withPIC_B.b_iy_o += 2) {
    __m128d tmp;
    tmp = _mm_loadu_pd(&y[motion_controller_withPIC_B.b_iy_o]);
    _mm_storeu_pd(&y[motion_controller_withPIC_B.b_iy_o], _mm_mul_pd(tmp,
      _mm_set1_pd(-1.0)));
  }

  for (motion_controller_withPIC_B.b_iy_o = 0;
       motion_controller_withPIC_B.b_iy_o <= 3239;
       motion_controller_withPIC_B.b_iy_o += 41) {
    motion_controller_withPIC_B.c_o = 0.0;
    motion_controller_withPIC_B.b_en = motion_controller_withPIC_B.b_iy_o + m;
    for (motion_controller_withPIC_B.ia_m = motion_controller_withPIC_B.b_iy_o +
         1; motion_controller_withPIC_B.ia_m <= motion_controller_withPIC_B.b_en;
         motion_controller_withPIC_B.ia_m++) {
      motion_controller_withPIC_B.c_o += x[(motion_controller_withPIC_B.ia_m -
        motion_controller_withPIC_B.b_iy_o) - 1] *
        A[motion_controller_withPIC_B.ia_m - 1];
    }

    motion_controller_withPIC_B.ia_m = div_nde_s32_floor
      (motion_controller_withPIC_B.b_iy_o, 41);
    y[motion_controller_withPIC_B.ia_m] += motion_controller_withPIC_B.c_o;
  }
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_controlle_xgemv_vsfN2o0d(int32_T m, const
  real_T A[3280], const real_T x[6601], real_T y[161])
{
  for (motion_controller_withPIC_B.b_iy_m = 0;
       motion_controller_withPIC_B.b_iy_m <= 78;
       motion_controller_withPIC_B.b_iy_m += 2) {
    __m128d tmp;
    tmp = _mm_loadu_pd(&y[motion_controller_withPIC_B.b_iy_m]);
    _mm_storeu_pd(&y[motion_controller_withPIC_B.b_iy_m], _mm_mul_pd(tmp,
      _mm_set1_pd(-1.0)));
  }

  for (motion_controller_withPIC_B.b_iy_m = 0;
       motion_controller_withPIC_B.b_iy_m <= 3239;
       motion_controller_withPIC_B.b_iy_m += 41) {
    motion_controller_withPIC_B.c_hi = 0.0;
    motion_controller_withPIC_B.b_f = motion_controller_withPIC_B.b_iy_m + m;
    for (motion_controller_withPIC_B.ia_n = motion_controller_withPIC_B.b_iy_m +
         1; motion_controller_withPIC_B.ia_n <= motion_controller_withPIC_B.b_f;
         motion_controller_withPIC_B.ia_n++) {
      motion_controller_withPIC_B.c_hi += x[(motion_controller_withPIC_B.ia_n -
        motion_controller_withPIC_B.b_iy_m) + 160] *
        A[motion_controller_withPIC_B.ia_n - 1];
    }

    motion_controller_withPIC_B.ia_n = div_nde_s32_floor
      (motion_controller_withPIC_B.b_iy_m, 41);
    y[motion_controller_withPIC_B.ia_n] += motion_controller_withPIC_B.c_hi;
  }
}

// Function for MATLAB Function: '<S62>/solvex'
boolean_T motion_controller_withPIC::motion__feasibleX0ForWorkingSet(real_T
  workspace[6601], real_T xCurrent[41], sT1ziU4p6vTWuD880X9yNJ_motion_T
  *workingset, s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager)
{
  __m128d tmp;
  __m128d tmp_0;
  boolean_T nonDegenerateWset;
  static const int32_T offsets[4] = { 0, 1, 2, 3 };

  __m128i tmp_1;
  int32_T exitg1;
  motion_controller_withPIC_B.mWConstr_tmp_tmp = workingset->nActiveConstr - 1;
  motion_controller_withPIC_B.nVar_tmp_tmp = workingset->nVar;
  nonDegenerateWset = true;
  if (workingset->nActiveConstr != 0) {
    for (motion_controller_withPIC_B.idx_n = 0;
         motion_controller_withPIC_B.idx_n <=
         motion_controller_withPIC_B.mWConstr_tmp_tmp;
         motion_controller_withPIC_B.idx_n++) {
      workspace[motion_controller_withPIC_B.idx_n] = workingset->
        bwset[motion_controller_withPIC_B.idx_n];
      workspace[motion_controller_withPIC_B.idx_n + 161] = workingset->
        bwset[motion_controller_withPIC_B.idx_n];
    }

    if (workingset->nActiveConstr != 0) {
      motion_controller_withPIC_B.d_e = (workingset->nActiveConstr - 1) * 41 + 1;
      for (motion_controller_withPIC_B.iac = 1; motion_controller_withPIC_B.iac <=
           motion_controller_withPIC_B.d_e; motion_controller_withPIC_B.iac +=
           41) {
        motion_controller_withPIC_B.c = 0.0;
        motion_controller_withPIC_B.jBcol = (motion_controller_withPIC_B.iac +
          motion_controller_withPIC_B.nVar_tmp_tmp) - 1;
        for (motion_controller_withPIC_B.idx_n = motion_controller_withPIC_B.iac;
             motion_controller_withPIC_B.idx_n <=
             motion_controller_withPIC_B.jBcol;
             motion_controller_withPIC_B.idx_n++) {
          motion_controller_withPIC_B.c += workingset->
            ATwset[motion_controller_withPIC_B.idx_n - 1] *
            xCurrent[motion_controller_withPIC_B.idx_n -
            motion_controller_withPIC_B.iac];
        }

        motion_controller_withPIC_B.idx_n = div_nde_s32_floor
          (motion_controller_withPIC_B.iac - 1, 41);
        workspace[motion_controller_withPIC_B.idx_n] -=
          motion_controller_withPIC_B.c;
      }
    }

    if (workingset->nActiveConstr >= workingset->nVar) {
      motion_controller_withPIC_B.d_e = static_cast<uint8_T>(workingset->nVar);
      for (motion_controller_withPIC_B.idx_n = 0;
           motion_controller_withPIC_B.idx_n < motion_controller_withPIC_B.d_e;
           motion_controller_withPIC_B.idx_n++) {
        motion_controller_withPIC_B.jBcol = 41 *
          motion_controller_withPIC_B.idx_n;
        for (motion_controller_withPIC_B.iac = 0;
             motion_controller_withPIC_B.iac <=
             motion_controller_withPIC_B.mWConstr_tmp_tmp;
             motion_controller_withPIC_B.iac++) {
          qrmanager->QR[motion_controller_withPIC_B.iac +
            motion_controller_withPIC_B.jBcol] = workingset->ATwset[41 *
            motion_controller_withPIC_B.iac + motion_controller_withPIC_B.idx_n];
        }
      }

      qrmanager->usedPivoting = false;
      qrmanager->mrows = workingset->nActiveConstr;
      qrmanager->ncols = workingset->nVar;
      motion_controller_withPIC_B.jBcol = (static_cast<uint8_T>(workingset->nVar)
        / 4) << 2;
      motion_controller_withPIC_B.iAcol = motion_controller_withPIC_B.jBcol - 4;
      for (motion_controller_withPIC_B.idx_n = 0;
           motion_controller_withPIC_B.idx_n <=
           motion_controller_withPIC_B.iAcol; motion_controller_withPIC_B.idx_n +=
           4) {
        tmp_1 = _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32
          (motion_controller_withPIC_B.idx_n), _mm_loadu_si128((const __m128i *)
          &offsets[0])), _mm_set1_epi32(1));
        _mm_storeu_si128((__m128i *)&qrmanager->
                         jpvt[motion_controller_withPIC_B.idx_n], tmp_1);
      }

      for (motion_controller_withPIC_B.idx_n = motion_controller_withPIC_B.jBcol;
           motion_controller_withPIC_B.idx_n < motion_controller_withPIC_B.d_e;
           motion_controller_withPIC_B.idx_n++) {
        qrmanager->jpvt[motion_controller_withPIC_B.idx_n] =
          motion_controller_withPIC_B.idx_n + 1;
      }

      if (workingset->nActiveConstr <= workingset->nVar) {
        motion_controller_withPIC_B.idx_n = workingset->nActiveConstr;
      } else {
        motion_controller_withPIC_B.idx_n = workingset->nVar;
      }

      qrmanager->minRowCol = motion_controller_withPIC_B.idx_n;
      memcpy(&motion_controller_withPIC_B.B[0], &qrmanager->QR[0], 6601U *
             sizeof(real_T));
      memset(&qrmanager->tau[0], 0, 41U * sizeof(real_T));
      if (motion_controller_withPIC_B.idx_n >= 1) {
        memset(&qrmanager->tau[0], 0, 41U * sizeof(real_T));
        motion_controller__qrf_ELz1YOWw(motion_controller_withPIC_B.B,
          workingset->nActiveConstr, workingset->nVar,
          motion_controller_withPIC_B.idx_n, qrmanager->tau);
      }

      memcpy(&qrmanager->QR[0], &motion_controller_withPIC_B.B[0], 6601U *
             sizeof(real_T));
      motion_controller_wit_computeQ_(qrmanager, qrmanager->mrows);
      memcpy(&motion_controller_withPIC_B.B[0], &workspace[0], 6601U * sizeof
             (real_T));
      for (motion_controller_withPIC_B.idx_n = 0;
           motion_controller_withPIC_B.idx_n <= 161;
           motion_controller_withPIC_B.idx_n += 161) {
        motion_controller_withPIC_B.d_e = motion_controller_withPIC_B.idx_n +
          motion_controller_withPIC_B.nVar_tmp_tmp;
        for (motion_controller_withPIC_B.iac = motion_controller_withPIC_B.idx_n
             + 1; motion_controller_withPIC_B.iac <=
             motion_controller_withPIC_B.d_e; motion_controller_withPIC_B.iac++)
        {
          workspace[motion_controller_withPIC_B.iac - 1] = 0.0;
        }
      }

      motion_controller_withPIC_B.jBcol = -1;
      for (motion_controller_withPIC_B.idx_n = 0;
           motion_controller_withPIC_B.idx_n <= 161;
           motion_controller_withPIC_B.idx_n += 161) {
        motion_controller_withPIC_B.iAcol = -1;
        motion_controller_withPIC_B.br = motion_controller_withPIC_B.idx_n +
          motion_controller_withPIC_B.nVar_tmp_tmp;
        for (motion_controller_withPIC_B.iac = motion_controller_withPIC_B.idx_n
             + 1; motion_controller_withPIC_B.iac <=
             motion_controller_withPIC_B.br; motion_controller_withPIC_B.iac++)
        {
          motion_controller_withPIC_B.c = 0.0;
          for (motion_controller_withPIC_B.d_e = 0;
               motion_controller_withPIC_B.d_e <=
               motion_controller_withPIC_B.mWConstr_tmp_tmp;
               motion_controller_withPIC_B.d_e++) {
            motion_controller_withPIC_B.c += qrmanager->Q
              [(motion_controller_withPIC_B.d_e +
                motion_controller_withPIC_B.iAcol) + 1] *
              motion_controller_withPIC_B.B[(motion_controller_withPIC_B.d_e +
              motion_controller_withPIC_B.jBcol) + 1];
          }

          workspace[motion_controller_withPIC_B.iac - 1] +=
            motion_controller_withPIC_B.c;
          motion_controller_withPIC_B.iAcol += 41;
        }

        motion_controller_withPIC_B.jBcol += 161;
      }

      for (motion_controller_withPIC_B.mWConstr_tmp_tmp = 0;
           motion_controller_withPIC_B.mWConstr_tmp_tmp < 2;
           motion_controller_withPIC_B.mWConstr_tmp_tmp++) {
        motion_controller_withPIC_B.iAcol = 161 *
          motion_controller_withPIC_B.mWConstr_tmp_tmp - 1;
        for (motion_controller_withPIC_B.d_e =
             motion_controller_withPIC_B.nVar_tmp_tmp;
             motion_controller_withPIC_B.d_e >= 1;
             motion_controller_withPIC_B.d_e--) {
          motion_controller_withPIC_B.br = (motion_controller_withPIC_B.d_e - 1)
            * 41;
          motion_controller_withPIC_B.idx_n = motion_controller_withPIC_B.d_e +
            motion_controller_withPIC_B.iAcol;
          motion_controller_withPIC_B.c =
            workspace[motion_controller_withPIC_B.idx_n];
          if (motion_controller_withPIC_B.c != 0.0) {
            workspace[motion_controller_withPIC_B.idx_n] =
              motion_controller_withPIC_B.c / qrmanager->QR
              [(motion_controller_withPIC_B.d_e + motion_controller_withPIC_B.br)
              - 1];
            motion_controller_withPIC_B.ar = static_cast<uint8_T>
              (motion_controller_withPIC_B.d_e - 1);
            for (motion_controller_withPIC_B.jBcol = 0;
                 motion_controller_withPIC_B.jBcol <
                 motion_controller_withPIC_B.ar;
                 motion_controller_withPIC_B.jBcol++) {
              motion_controller_withPIC_B.iac =
                (motion_controller_withPIC_B.jBcol +
                 motion_controller_withPIC_B.iAcol) + 1;
              workspace[motion_controller_withPIC_B.iac] -= qrmanager->
                QR[motion_controller_withPIC_B.jBcol +
                motion_controller_withPIC_B.br] *
                workspace[motion_controller_withPIC_B.idx_n];
            }
          }
        }
      }
    } else {
      motion_controller_with_factorQR(qrmanager, workingset->ATwset,
        workingset->nVar, workingset->nActiveConstr);
      motion_controller_wit_computeQ_(qrmanager, qrmanager->minRowCol);
      for (motion_controller_withPIC_B.idx_n = 0;
           motion_controller_withPIC_B.idx_n < 2;
           motion_controller_withPIC_B.idx_n++) {
        motion_controller_withPIC_B.jBcol = 161 *
          motion_controller_withPIC_B.idx_n;
        for (motion_controller_withPIC_B.iac = 0;
             motion_controller_withPIC_B.iac <=
             motion_controller_withPIC_B.mWConstr_tmp_tmp;
             motion_controller_withPIC_B.iac++) {
          motion_controller_withPIC_B.iAcol = 41 *
            motion_controller_withPIC_B.iac;
          motion_controller_withPIC_B.br = motion_controller_withPIC_B.iac +
            motion_controller_withPIC_B.jBcol;
          motion_controller_withPIC_B.c =
            workspace[motion_controller_withPIC_B.br];
          motion_controller_withPIC_B.ar = static_cast<uint8_T>
            (motion_controller_withPIC_B.iac);
          for (motion_controller_withPIC_B.d_e = 0;
               motion_controller_withPIC_B.d_e < motion_controller_withPIC_B.ar;
               motion_controller_withPIC_B.d_e++) {
            motion_controller_withPIC_B.c -= qrmanager->
              QR[motion_controller_withPIC_B.d_e +
              motion_controller_withPIC_B.iAcol] *
              workspace[motion_controller_withPIC_B.d_e +
              motion_controller_withPIC_B.jBcol];
          }

          workspace[motion_controller_withPIC_B.br] =
            motion_controller_withPIC_B.c / qrmanager->
            QR[motion_controller_withPIC_B.iac +
            motion_controller_withPIC_B.iAcol];
        }
      }

      memcpy(&motion_controller_withPIC_B.B[0], &workspace[0], 6601U * sizeof
             (real_T));
      for (motion_controller_withPIC_B.idx_n = 0;
           motion_controller_withPIC_B.idx_n <= 161;
           motion_controller_withPIC_B.idx_n += 161) {
        motion_controller_withPIC_B.d_e = motion_controller_withPIC_B.idx_n +
          motion_controller_withPIC_B.nVar_tmp_tmp;
        for (motion_controller_withPIC_B.iac = motion_controller_withPIC_B.idx_n
             + 1; motion_controller_withPIC_B.iac <=
             motion_controller_withPIC_B.d_e; motion_controller_withPIC_B.iac++)
        {
          workspace[motion_controller_withPIC_B.iac - 1] = 0.0;
        }
      }

      motion_controller_withPIC_B.br = 1;
      for (motion_controller_withPIC_B.idx_n = 0;
           motion_controller_withPIC_B.idx_n <= 161;
           motion_controller_withPIC_B.idx_n += 161) {
        motion_controller_withPIC_B.ar = -1;
        motion_controller_withPIC_B.h = motion_controller_withPIC_B.br +
          motion_controller_withPIC_B.mWConstr_tmp_tmp;
        for (motion_controller_withPIC_B.iac = motion_controller_withPIC_B.br;
             motion_controller_withPIC_B.iac <= motion_controller_withPIC_B.h;
             motion_controller_withPIC_B.iac++) {
          motion_controller_withPIC_B.l_b = motion_controller_withPIC_B.idx_n +
            motion_controller_withPIC_B.nVar_tmp_tmp;
          motion_controller_withPIC_B.jBcol =
            ((((motion_controller_withPIC_B.l_b -
                motion_controller_withPIC_B.idx_n) / 2) << 1) +
             motion_controller_withPIC_B.idx_n) + 1;
          motion_controller_withPIC_B.iAcol = motion_controller_withPIC_B.jBcol
            - 2;
          for (motion_controller_withPIC_B.d_e =
               motion_controller_withPIC_B.idx_n + 1;
               motion_controller_withPIC_B.d_e <=
               motion_controller_withPIC_B.iAcol;
               motion_controller_withPIC_B.d_e += 2) {
            tmp = _mm_loadu_pd(&qrmanager->Q[(motion_controller_withPIC_B.ar +
              motion_controller_withPIC_B.d_e) -
                               motion_controller_withPIC_B.idx_n]);
            tmp_0 = _mm_loadu_pd(&workspace[motion_controller_withPIC_B.d_e - 1]);
            _mm_storeu_pd(&workspace[motion_controller_withPIC_B.d_e - 1],
                          _mm_add_pd(_mm_mul_pd(tmp, _mm_set1_pd
              (motion_controller_withPIC_B.B[motion_controller_withPIC_B.iac - 1])),
              tmp_0));
          }

          for (motion_controller_withPIC_B.d_e =
               motion_controller_withPIC_B.jBcol;
               motion_controller_withPIC_B.d_e <=
               motion_controller_withPIC_B.l_b; motion_controller_withPIC_B.d_e
               ++) {
            workspace[motion_controller_withPIC_B.d_e - 1] += qrmanager->Q
              [(motion_controller_withPIC_B.ar + motion_controller_withPIC_B.d_e)
              - motion_controller_withPIC_B.idx_n] *
              motion_controller_withPIC_B.B[motion_controller_withPIC_B.iac - 1];
          }

          motion_controller_withPIC_B.ar += 41;
        }

        motion_controller_withPIC_B.br += 161;
      }
    }

    motion_controller_withPIC_B.mWConstr_tmp_tmp = 0;
    do {
      exitg1 = 0;
      if (motion_controller_withPIC_B.mWConstr_tmp_tmp <= static_cast<uint8_T>
          (motion_controller_withPIC_B.nVar_tmp_tmp) - 1) {
        if (rtIsInf(workspace[motion_controller_withPIC_B.mWConstr_tmp_tmp]) ||
            rtIsNaN(workspace[motion_controller_withPIC_B.mWConstr_tmp_tmp])) {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          motion_controller_withPIC_B.c =
            workspace[motion_controller_withPIC_B.mWConstr_tmp_tmp + 161];
          if (rtIsInf(motion_controller_withPIC_B.c) || rtIsNaN
              (motion_controller_withPIC_B.c)) {
            nonDegenerateWset = false;
            exitg1 = 1;
          } else {
            motion_controller_withPIC_B.mWConstr_tmp_tmp++;
          }
        }
      } else {
        motion_controller_withPIC_B.jBcol =
          (motion_controller_withPIC_B.nVar_tmp_tmp / 2) << 1;
        motion_controller_withPIC_B.iAcol = motion_controller_withPIC_B.jBcol -
          2;
        for (motion_controller_withPIC_B.mWConstr_tmp_tmp = 0;
             motion_controller_withPIC_B.mWConstr_tmp_tmp <=
             motion_controller_withPIC_B.iAcol;
             motion_controller_withPIC_B.mWConstr_tmp_tmp += 2) {
          tmp = _mm_loadu_pd
            (&workspace[motion_controller_withPIC_B.mWConstr_tmp_tmp]);
          tmp_0 = _mm_loadu_pd
            (&xCurrent[motion_controller_withPIC_B.mWConstr_tmp_tmp]);
          _mm_storeu_pd(&workspace[motion_controller_withPIC_B.mWConstr_tmp_tmp],
                        _mm_add_pd(tmp, tmp_0));
        }

        for (motion_controller_withPIC_B.mWConstr_tmp_tmp =
             motion_controller_withPIC_B.jBcol;
             motion_controller_withPIC_B.mWConstr_tmp_tmp <
             motion_controller_withPIC_B.nVar_tmp_tmp;
             motion_controller_withPIC_B.mWConstr_tmp_tmp++) {
          workspace[motion_controller_withPIC_B.mWConstr_tmp_tmp] +=
            xCurrent[motion_controller_withPIC_B.mWConstr_tmp_tmp];
        }

        if (workingset->probType == 2) {
          motion_controller_withPIC_B.c = 0.0;
          memcpy(&workingset->maxConstrWorkspace[0], &workingset->bineq[0], 80U *
                 sizeof(real_T));
          motion_controlle_xgemv_kCjzUKKr(40, workingset->Aineq, workspace,
            workingset->maxConstrWorkspace);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp < 80;
               motion_controller_withPIC_B.mWConstr_tmp_tmp++) {
            motion_controller_withPIC_B.u1 = workingset->
              maxConstrWorkspace[motion_controller_withPIC_B.mWConstr_tmp_tmp] -
              workspace[motion_controller_withPIC_B.mWConstr_tmp_tmp + 40];
            workingset->
              maxConstrWorkspace[motion_controller_withPIC_B.mWConstr_tmp_tmp] =
              motion_controller_withPIC_B.u1;
            if ((!(motion_controller_withPIC_B.c >=
                   motion_controller_withPIC_B.u1)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1))) {
              motion_controller_withPIC_B.c = motion_controller_withPIC_B.u1;
            }
          }
        } else {
          motion_controller_withPIC_B.c = 0.0;
          memcpy(&workingset->maxConstrWorkspace[0], &workingset->bineq[0], 80U *
                 sizeof(real_T));
          motion_controlle_xgemv_kCjzUKKr(workingset->nVar, workingset->Aineq,
            workspace, workingset->maxConstrWorkspace);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp < 80;
               motion_controller_withPIC_B.mWConstr_tmp_tmp++) {
            motion_controller_withPIC_B.u1 = workingset->
              maxConstrWorkspace[motion_controller_withPIC_B.mWConstr_tmp_tmp];
            if ((!(motion_controller_withPIC_B.c >=
                   motion_controller_withPIC_B.u1)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1))) {
              motion_controller_withPIC_B.c = motion_controller_withPIC_B.u1;
            }
          }
        }

        if (workingset->sizes[3] > 0) {
          motion_controller_withPIC_B.idx_n = static_cast<uint8_T>
            (workingset->sizes[3]);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp <
               motion_controller_withPIC_B.idx_n;
               motion_controller_withPIC_B.mWConstr_tmp_tmp++) {
            motion_controller_withPIC_B.u1 = -workspace[workingset->
              indexLB[motion_controller_withPIC_B.mWConstr_tmp_tmp] - 1] -
              workingset->lb[workingset->
              indexLB[motion_controller_withPIC_B.mWConstr_tmp_tmp] - 1];
            if ((!(motion_controller_withPIC_B.c >=
                   motion_controller_withPIC_B.u1)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1))) {
              motion_controller_withPIC_B.c = motion_controller_withPIC_B.u1;
            }
          }
        }

        if (workingset->sizes[4] > 0) {
          motion_controller_withPIC_B.idx_n = static_cast<uint8_T>
            (workingset->sizes[4]);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp <
               motion_controller_withPIC_B.idx_n;
               motion_controller_withPIC_B.mWConstr_tmp_tmp++) {
            motion_controller_withPIC_B.u1 = workspace[workingset->
              indexUB[motion_controller_withPIC_B.mWConstr_tmp_tmp] - 1] -
              workingset->ub[workingset->
              indexUB[motion_controller_withPIC_B.mWConstr_tmp_tmp] - 1];
            if ((!(motion_controller_withPIC_B.c >=
                   motion_controller_withPIC_B.u1)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1))) {
              motion_controller_withPIC_B.c = motion_controller_withPIC_B.u1;
            }
          }
        }

        if (workingset->sizes[0] > 0) {
          motion_controller_withPIC_B.idx_n = static_cast<uint8_T>
            (workingset->sizes[0]);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp <
               motion_controller_withPIC_B.idx_n;
               motion_controller_withPIC_B.mWConstr_tmp_tmp++) {
            motion_controller_withPIC_B.u1 = fabs(workspace
              [workingset->
              indexFixed[motion_controller_withPIC_B.mWConstr_tmp_tmp] - 1] -
              workingset->ub[workingset->
              indexFixed[motion_controller_withPIC_B.mWConstr_tmp_tmp] - 1]);
            if ((!(motion_controller_withPIC_B.c >=
                   motion_controller_withPIC_B.u1)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1))) {
              motion_controller_withPIC_B.c = motion_controller_withPIC_B.u1;
            }
          }
        }

        if (workingset->probType == 2) {
          motion_controller_withPIC_B.d_v = 0.0;
          memcpy(&workingset->maxConstrWorkspace[0], &workingset->bineq[0], 80U *
                 sizeof(real_T));
          motion_controlle_xgemv_vsfN2o0d(40, workingset->Aineq, workspace,
            workingset->maxConstrWorkspace);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp < 80;
               motion_controller_withPIC_B.mWConstr_tmp_tmp++) {
            motion_controller_withPIC_B.u1 = workingset->
              maxConstrWorkspace[motion_controller_withPIC_B.mWConstr_tmp_tmp] -
              workspace[motion_controller_withPIC_B.mWConstr_tmp_tmp + 201];
            workingset->
              maxConstrWorkspace[motion_controller_withPIC_B.mWConstr_tmp_tmp] =
              motion_controller_withPIC_B.u1;
            if ((!(motion_controller_withPIC_B.d_v >=
                   motion_controller_withPIC_B.u1)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1))) {
              motion_controller_withPIC_B.d_v = motion_controller_withPIC_B.u1;
            }
          }
        } else {
          motion_controller_withPIC_B.d_v = 0.0;
          memcpy(&workingset->maxConstrWorkspace[0], &workingset->bineq[0], 80U *
                 sizeof(real_T));
          motion_controlle_xgemv_vsfN2o0d(workingset->nVar, workingset->Aineq,
            workspace, workingset->maxConstrWorkspace);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp < 80;
               motion_controller_withPIC_B.mWConstr_tmp_tmp++) {
            motion_controller_withPIC_B.u1 = workingset->
              maxConstrWorkspace[motion_controller_withPIC_B.mWConstr_tmp_tmp];
            if ((!(motion_controller_withPIC_B.d_v >=
                   motion_controller_withPIC_B.u1)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1))) {
              motion_controller_withPIC_B.d_v = motion_controller_withPIC_B.u1;
            }
          }
        }

        if (workingset->sizes[3] > 0) {
          motion_controller_withPIC_B.idx_n = static_cast<uint8_T>
            (workingset->sizes[3]);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp <
               motion_controller_withPIC_B.idx_n;
               motion_controller_withPIC_B.mWConstr_tmp_tmp++) {
            motion_controller_withPIC_B.u1 = -workspace[workingset->
              indexLB[motion_controller_withPIC_B.mWConstr_tmp_tmp] + 160] -
              workingset->lb[workingset->
              indexLB[motion_controller_withPIC_B.mWConstr_tmp_tmp] - 1];
            if ((!(motion_controller_withPIC_B.d_v >=
                   motion_controller_withPIC_B.u1)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1))) {
              motion_controller_withPIC_B.d_v = motion_controller_withPIC_B.u1;
            }
          }
        }

        if (workingset->sizes[4] > 0) {
          motion_controller_withPIC_B.idx_n = static_cast<uint8_T>
            (workingset->sizes[4]);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp <
               motion_controller_withPIC_B.idx_n;
               motion_controller_withPIC_B.mWConstr_tmp_tmp++) {
            motion_controller_withPIC_B.u1 = workspace[workingset->
              indexUB[motion_controller_withPIC_B.mWConstr_tmp_tmp] + 160] -
              workingset->ub[workingset->
              indexUB[motion_controller_withPIC_B.mWConstr_tmp_tmp] - 1];
            if ((!(motion_controller_withPIC_B.d_v >=
                   motion_controller_withPIC_B.u1)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1))) {
              motion_controller_withPIC_B.d_v = motion_controller_withPIC_B.u1;
            }
          }
        }

        if (workingset->sizes[0] > 0) {
          motion_controller_withPIC_B.idx_n = static_cast<uint8_T>
            (workingset->sizes[0]);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp <
               motion_controller_withPIC_B.idx_n;
               motion_controller_withPIC_B.mWConstr_tmp_tmp++) {
            motion_controller_withPIC_B.u1 = fabs(workspace
              [workingset->
              indexFixed[motion_controller_withPIC_B.mWConstr_tmp_tmp] + 160] -
              workingset->ub[workingset->
              indexFixed[motion_controller_withPIC_B.mWConstr_tmp_tmp] - 1]);
            if ((!(motion_controller_withPIC_B.d_v >=
                   motion_controller_withPIC_B.u1)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1))) {
              motion_controller_withPIC_B.d_v = motion_controller_withPIC_B.u1;
            }
          }
        }

        if ((motion_controller_withPIC_B.c <= 2.2204460492503131E-16) ||
            (motion_controller_withPIC_B.c < motion_controller_withPIC_B.d_v)) {
          motion_controller_withPIC_B.mWConstr_tmp_tmp = static_cast<uint8_T>
            (motion_controller_withPIC_B.nVar_tmp_tmp);
          memcpy(&xCurrent[0], &workspace[0], static_cast<uint32_T>
                 (motion_controller_withPIC_B.mWConstr_tmp_tmp) * sizeof(real_T));
        } else {
          motion_controller_withPIC_B.mWConstr_tmp_tmp = static_cast<uint8_T>
            (motion_controller_withPIC_B.nVar_tmp_tmp);
          memcpy(&xCurrent[0], &workspace[161], static_cast<uint32_T>
                 (motion_controller_withPIC_B.mWConstr_tmp_tmp) * sizeof(real_T));
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return nonDegenerateWset;
}

// Function for MATLAB Function: '<S62>/solvex'
real_T motion_controller_withPIC::motion_c_maxConstraintViolation
  (sT1ziU4p6vTWuD880X9yNJ_motion_T *obj, const real_T x[41])
{
  real_T u1;
  real_T v;
  int32_T b;
  int32_T k;
  if (obj->probType == 2) {
    v = 0.0;
    memcpy(&obj->maxConstrWorkspace[0], &obj->bineq[0], 80U * sizeof(real_T));
    xgemv_bQMFK39u(40, obj->Aineq, x, obj->maxConstrWorkspace);
    for (k = 0; k < 80; k++) {
      u1 = obj->maxConstrWorkspace[k] - x[40];
      obj->maxConstrWorkspace[k] = u1;
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  } else {
    v = 0.0;
    memcpy(&obj->maxConstrWorkspace[0], &obj->bineq[0], 80U * sizeof(real_T));
    xgemv_bQMFK39u(obj->nVar, obj->Aineq, x, obj->maxConstrWorkspace);
    for (k = 0; k < 80; k++) {
      u1 = obj->maxConstrWorkspace[k];
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  if (obj->sizes[3] > 0) {
    b = static_cast<uint8_T>(obj->sizes[3]);
    for (k = 0; k < b; k++) {
      u1 = -x[obj->indexLB[k] - 1] - obj->lb[obj->indexLB[k] - 1];
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  if (obj->sizes[4] > 0) {
    b = static_cast<uint8_T>(obj->sizes[4]);
    for (k = 0; k < b; k++) {
      u1 = x[obj->indexUB[k] - 1] - obj->ub[obj->indexUB[k] - 1];
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  if (obj->sizes[0] > 0) {
    b = static_cast<uint8_T>(obj->sizes[0]);
    for (k = 0; k < b; k++) {
      u1 = fabs(x[obj->indexFixed[k] - 1] - obj->ub[obj->indexFixed[k] - 1]);
      if ((!(v >= u1)) && (!rtIsNaN(u1))) {
        v = u1;
      }
    }
  }

  return v;
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_contr_PresolveWorkingSet
  (s5cJJO9CAPQxuVG0iaeiP4F_motio_T *solution, sFlCINAYeIgPgx0UwEHpaMF_motio_T
   *memspace, sT1ziU4p6vTWuD880X9yNJ_motion_T *workingset,
   s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager)
{
  real_T constrViolation;
  int32_T b;
  int32_T idxEndIneq;
  int32_T idxStartIneq;
  int32_T idxStartIneq_tmp;
  boolean_T guard1;
  boolean_T okWorkingSet;
  solution->state = 82;
  motion_contr_RemoveDependentEq_(memspace, workingset, &b, qrmanager);
  if ((b != -1) && (workingset->nActiveConstr <= 41)) {
    motion_con_RemoveDependentIneq_(workingset, qrmanager, memspace, 100.0);
    okWorkingSet = motion__feasibleX0ForWorkingSet(memspace->workspace_double,
      solution->xstar, workingset, qrmanager);
    guard1 = false;
    if (!okWorkingSet) {
      motion_con_RemoveDependentIneq_(workingset, qrmanager, memspace, 1000.0);
      okWorkingSet = motion__feasibleX0ForWorkingSet(memspace->workspace_double,
        solution->xstar, workingset, qrmanager);
      if (!okWorkingSet) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (workingset->nWConstr[0] + workingset->nWConstr[1] == workingset->nVar)
      {
        constrViolation = motion_c_maxConstraintViolation(workingset,
          solution->xstar);
        if (constrViolation > 1.0E-8) {
          solution->state = -2;
        }
      }
    }
  } else {
    solution->state = -3;
    idxStartIneq_tmp = workingset->nWConstr[0] + workingset->nWConstr[1];
    idxStartIneq = idxStartIneq_tmp + 1;
    idxEndIneq = workingset->nActiveConstr;
    for (b = idxStartIneq; b <= idxEndIneq; b++) {
      workingset->isActiveConstr[(workingset->isActiveIdx[workingset->Wid[b - 1]
        - 1] + workingset->Wlocalidx[b - 1]) - 2] = false;
    }

    workingset->nWConstr[2] = 0;
    workingset->nWConstr[3] = 0;
    workingset->nWConstr[4] = 0;
    workingset->nActiveConstr = idxStartIneq_tmp;
  }
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_controller_w_linearForm_(int32_T obj_nvar,
  real_T workspace[6601], const real_T H[1600], const real_T f[40], const real_T
  x[41])
{
  int32_T d;
  int32_T ix;
  memcpy(&workspace[0], &f[0], static_cast<uint8_T>(obj_nvar) * sizeof(real_T));
  ix = 0;
  d = (obj_nvar - 1) * obj_nvar + 1;
  for (int32_T i = 1; obj_nvar < 0 ? i >= d : i <= d; i += obj_nvar) {
    real_T c;
    int32_T e;
    c = 0.5 * x[ix];
    e = (i + obj_nvar) - 1;
    for (int32_T b = i; b <= e; b++) {
      int32_T tmp;
      tmp = b - i;
      workspace[tmp] += H[b - 1] * c;
    }

    ix++;
  }
}

// Function for MATLAB Function: '<S62>/solvex'
real_T motion_controller_withPIC::motion_controller_w_computeFval(const
  sKnhLiTH4yv7eF1oV2a74RG_motio_T *obj, real_T workspace[6601], const real_T H
  [1600], const real_T f[40], const real_T x[41])
{
  real_T val;
  int32_T b;
  int32_T b_k;
  switch (obj->objtype) {
   case 5:
    val = x[obj->nvar - 1];
    break;

   case 3:
    motion_controller_w_linearForm_(obj->nvar, workspace, H, f, x);
    val = 0.0;
    if (obj->nvar >= 1) {
      b = static_cast<uint8_T>(obj->nvar);
      for (b_k = 0; b_k < b; b_k++) {
        val += x[b_k] * workspace[b_k];
      }
    }
    break;

   default:
    motion_controller_w_linearForm_(obj->nvar, workspace, H, f, x);
    val = 0.0;
    for (b_k = 0; b_k < 40; b_k++) {
      val += x[b_k] * workspace[b_k];
    }
    break;
  }

  return val;
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_cont_computeGrad_StoreHx
  (sKnhLiTH4yv7eF1oV2a74RG_motio_T *obj, const real_T H[1600], const real_T f[40],
   const real_T x[41])
{
  __m128d tmp;
  __m128d tmp_0;
  int32_T b_ixlast;
  int32_T idx;
  int32_T scalarLB;
  int32_T vectorUB;
  switch (obj->objtype) {
   case 5:
    if (obj->nvar - 2 >= 0) {
      memset(&obj->grad[0], 0, static_cast<uint32_T>(obj->nvar - 1) * sizeof
             (real_T));
    }

    obj->grad[obj->nvar - 1] = obj->gammaScalar;
    break;

   case 3:
    xgemv_DWEvxrPL(obj->nvar, obj->nvar, H, obj->nvar, x, obj->Hx);
    if (static_cast<uint8_T>(obj->nvar) - 1 >= 0) {
      memcpy(&obj->grad[0], &obj->Hx[0], static_cast<uint8_T>(obj->nvar) *
             sizeof(real_T));
    }

    if (obj->hasLinear && (obj->nvar >= 1)) {
      b_ixlast = obj->nvar - 1;
      scalarLB = (obj->nvar / 2) << 1;
      vectorUB = scalarLB - 2;
      for (idx = 0; idx <= vectorUB; idx += 2) {
        tmp_0 = _mm_loadu_pd(&obj->grad[idx]);
        tmp = _mm_loadu_pd(&f[idx]);
        _mm_storeu_pd(&obj->grad[idx], _mm_add_pd(tmp_0, tmp));
      }

      for (idx = scalarLB; idx <= b_ixlast; idx++) {
        obj->grad[idx] += f[idx];
      }
    }
    break;

   default:
    xgemv_DWEvxrPL(obj->nvar, obj->nvar, H, obj->nvar, x, obj->Hx);
    b_ixlast = obj->nvar + 1;
    scalarLB = ((((40 - obj->nvar) / 2) << 1) + obj->nvar) + 1;
    vectorUB = scalarLB - 2;
    for (idx = b_ixlast; idx <= vectorUB; idx += 2) {
      tmp_0 = _mm_loadu_pd(&x[idx - 1]);
      _mm_storeu_pd(&obj->Hx[idx - 1], _mm_mul_pd(tmp_0, _mm_set1_pd(0.0)));
    }

    for (idx = scalarLB; idx < 41; idx++) {
      obj->Hx[idx - 1] = x[idx - 1] * 0.0;
    }

    memcpy(&obj->grad[0], &obj->Hx[0], 40U * sizeof(real_T));
    if (obj->hasLinear && (obj->nvar >= 1)) {
      b_ixlast = obj->nvar - 1;
      scalarLB = (obj->nvar / 2) << 1;
      vectorUB = scalarLB - 2;
      for (idx = 0; idx <= vectorUB; idx += 2) {
        tmp_0 = _mm_loadu_pd(&obj->grad[idx]);
        tmp = _mm_loadu_pd(&f[idx]);
        _mm_storeu_pd(&obj->grad[idx], _mm_add_pd(tmp_0, tmp));
      }

      for (idx = scalarLB; idx <= b_ixlast; idx++) {
        obj->grad[idx] += f[idx];
      }
    }
    break;
  }
}

// Function for MATLAB Function: '<S62>/solvex'
real_T motion_controller_withPIC::motion_cont_computeFval_ReuseHx(const
  sKnhLiTH4yv7eF1oV2a74RG_motio_T *obj, real_T workspace[6601], const real_T f
  [40], const real_T x[41])
{
  real_T val;
  switch (obj->objtype) {
   case 5:
    val = x[obj->nvar - 1] * obj->gammaScalar;
    break;

   case 3:
    {
      if (obj->hasLinear) {
        int32_T e;
        int32_T scalarLB;
        int32_T vectorUB;
        e = static_cast<uint8_T>(obj->nvar);
        scalarLB = (static_cast<uint8_T>(obj->nvar) / 2) << 1;
        vectorUB = scalarLB - 2;
        for (int32_T k = 0; k <= vectorUB; k += 2) {
          __m128d tmp;
          __m128d tmp_0;
          tmp = _mm_loadu_pd(&obj->Hx[k]);
          tmp_0 = _mm_loadu_pd(&f[k]);
          _mm_storeu_pd(&workspace[k], _mm_add_pd(_mm_mul_pd(_mm_set1_pd(0.5),
            tmp), tmp_0));
        }

        for (int32_T k = scalarLB; k < e; k++) {
          workspace[k] = 0.5 * obj->Hx[k] + f[k];
        }

        val = 0.0;
        if (obj->nvar >= 1) {
          for (int32_T k = 0; k < e; k++) {
            val += x[k] * workspace[k];
          }
        }
      } else {
        val = 0.0;
        if (obj->nvar >= 1) {
          int32_T e;
          e = static_cast<uint8_T>(obj->nvar);
          for (int32_T k = 0; k < e; k++) {
            val += x[k] * obj->Hx[k];
          }
        }

        val *= 0.5;
      }
    }
    break;

   default:
    {
      if (obj->hasLinear) {
        int32_T e;
        if (static_cast<uint8_T>(obj->nvar) - 1 >= 0) {
          memcpy(&workspace[0], &f[0], static_cast<uint8_T>(obj->nvar) * sizeof
                 (real_T));
        }

        e = 39 - obj->nvar;
        for (int32_T k = 0; k <= e; k++) {
          workspace[obj->nvar + k] = 0.0;
        }

        val = 0.0;
        for (int32_T k = 0; k < 40; k++) {
          real_T workspace_0;
          workspace_0 = 0.5 * obj->Hx[k] + workspace[k];
          workspace[k] = workspace_0;
          val += x[k] * workspace_0;
        }
      } else {
        int32_T e;
        val = 0.0;
        for (int32_T k = 0; k < 40; k++) {
          val += x[k] * obj->Hx[k];
        }

        val *= 0.5;
        e = obj->nvar + 1;
        for (int32_T k = e; k < 41; k++) {
          val += x[k - 1] * 0.0;
        }
      }
    }
    break;
  }

  return val;
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_control_deleteColMoveEnd
  (s2uO2c2bmaUl7sY5vOWIzHG_motio_T *obj, int32_T idx)
{
  if (obj->usedPivoting) {
    motion_controller_withPIC_B.i_gn = 1;
    while ((motion_controller_withPIC_B.i_gn <= obj->ncols) && (obj->
            jpvt[motion_controller_withPIC_B.i_gn - 1] != idx)) {
      motion_controller_withPIC_B.i_gn++;
    }

    idx = motion_controller_withPIC_B.i_gn;
  }

  if (idx >= obj->ncols) {
    obj->ncols--;
  } else {
    obj->jpvt[idx - 1] = obj->jpvt[obj->ncols - 1];
    motion_controller_withPIC_B.QRk0 = obj->minRowCol;
    for (motion_controller_withPIC_B.i_gn = 0; motion_controller_withPIC_B.i_gn <
         motion_controller_withPIC_B.QRk0; motion_controller_withPIC_B.i_gn++) {
      obj->QR[motion_controller_withPIC_B.i_gn + 41 * (idx - 1)] = obj->QR
        [(obj->ncols - 1) * 41 + motion_controller_withPIC_B.i_gn];
    }

    obj->ncols--;
    if (obj->mrows <= obj->ncols) {
      obj->minRowCol = obj->mrows;
    } else {
      obj->minRowCol = obj->ncols;
    }

    if (idx < obj->mrows) {
      if (obj->mrows - 1 <= obj->ncols) {
        motion_controller_withPIC_B.i_gn = obj->mrows - 1;
      } else {
        motion_controller_withPIC_B.i_gn = obj->ncols;
      }

      motion_controller_withPIC_B.k_c1 = motion_controller_withPIC_B.i_gn;
      motion_controller_withPIC_B.idxRotGCol = (idx - 1) * 41;
      while (motion_controller_withPIC_B.k_c1 >= idx) {
        motion_controller_withPIC_B.QRk0 = motion_controller_withPIC_B.k_c1 +
          motion_controller_withPIC_B.idxRotGCol;
        motion_controller_withPIC_B.b_temp = obj->
          QR[motion_controller_withPIC_B.QRk0];
        motion_controlle_xrotg_ds3XgDMS(&obj->
          QR[motion_controller_withPIC_B.QRk0 - 1],
          &motion_controller_withPIC_B.b_temp, &motion_controller_withPIC_B.c_c,
          &motion_controller_withPIC_B.b_s);
        obj->QR[motion_controller_withPIC_B.QRk0] =
          motion_controller_withPIC_B.b_temp;
        motion_controller_withPIC_B.e_k = (motion_controller_withPIC_B.k_c1 - 1)
          * 41;
        obj->QR[motion_controller_withPIC_B.k_c1 +
          motion_controller_withPIC_B.e_k] = 0.0;
        motion_controller_withPIC_B.QRk0 = 41 * idx +
          motion_controller_withPIC_B.k_c1;
        motion_controller_withPIC_B.b_temp_tmp_g = obj->ncols - idx;
        if (motion_controller_withPIC_B.b_temp_tmp_g >= 1) {
          for (motion_controller_withPIC_B.b_n = 0;
               motion_controller_withPIC_B.b_n <
               motion_controller_withPIC_B.b_temp_tmp_g;
               motion_controller_withPIC_B.b_n++) {
            motion_controller_withPIC_B.temp_tmp_o =
              motion_controller_withPIC_B.b_n * 41 +
              motion_controller_withPIC_B.QRk0;
            motion_controller_withPIC_B.b_temp_tmp = obj->
              QR[motion_controller_withPIC_B.temp_tmp_o - 1];
            motion_controller_withPIC_B.b_temp =
              motion_controller_withPIC_B.b_temp_tmp *
              motion_controller_withPIC_B.c_c + obj->
              QR[motion_controller_withPIC_B.temp_tmp_o] *
              motion_controller_withPIC_B.b_s;
            obj->QR[motion_controller_withPIC_B.temp_tmp_o] = obj->
              QR[motion_controller_withPIC_B.temp_tmp_o] *
              motion_controller_withPIC_B.c_c -
              motion_controller_withPIC_B.b_temp_tmp *
              motion_controller_withPIC_B.b_s;
            obj->QR[motion_controller_withPIC_B.temp_tmp_o - 1] =
              motion_controller_withPIC_B.b_temp;
          }
        }

        motion_controller_withPIC_B.b_n = obj->mrows;
        if (obj->mrows >= 1) {
          for (motion_controller_withPIC_B.QRk0 = 0;
               motion_controller_withPIC_B.QRk0 <
               motion_controller_withPIC_B.b_n; motion_controller_withPIC_B.QRk0
               ++) {
            motion_controller_withPIC_B.b_temp_tmp_g =
              motion_controller_withPIC_B.e_k + motion_controller_withPIC_B.QRk0;
            motion_controller_withPIC_B.b_temp_tmp = obj->
              Q[motion_controller_withPIC_B.b_temp_tmp_g + 41];
            motion_controller_withPIC_B.b_temp =
              motion_controller_withPIC_B.b_temp_tmp *
              motion_controller_withPIC_B.b_s + obj->
              Q[motion_controller_withPIC_B.b_temp_tmp_g] *
              motion_controller_withPIC_B.c_c;
            obj->Q[motion_controller_withPIC_B.b_temp_tmp_g + 41] =
              motion_controller_withPIC_B.b_temp_tmp *
              motion_controller_withPIC_B.c_c - obj->
              Q[motion_controller_withPIC_B.b_temp_tmp_g] *
              motion_controller_withPIC_B.b_s;
            obj->Q[motion_controller_withPIC_B.b_temp_tmp_g] =
              motion_controller_withPIC_B.b_temp;
          }
        }

        motion_controller_withPIC_B.k_c1--;
      }

      for (motion_controller_withPIC_B.k_c1 = idx + 1;
           motion_controller_withPIC_B.k_c1 <= motion_controller_withPIC_B.i_gn;
           motion_controller_withPIC_B.k_c1++) {
        motion_controller_withPIC_B.idxRotGCol =
          (motion_controller_withPIC_B.k_c1 - 1) * 41;
        motion_controller_withPIC_B.QRk0 = motion_controller_withPIC_B.k_c1 +
          motion_controller_withPIC_B.idxRotGCol;
        motion_controller_withPIC_B.b_temp = obj->
          QR[motion_controller_withPIC_B.QRk0];
        motion_controlle_xrotg_ds3XgDMS(&obj->
          QR[motion_controller_withPIC_B.QRk0 - 1],
          &motion_controller_withPIC_B.b_temp, &motion_controller_withPIC_B.c_c,
          &motion_controller_withPIC_B.b_s);
        obj->QR[motion_controller_withPIC_B.QRk0] =
          motion_controller_withPIC_B.b_temp;
        motion_controller_withPIC_B.QRk0 = motion_controller_withPIC_B.k_c1 * 42;
        motion_controller_withPIC_B.b_n = obj->ncols -
          motion_controller_withPIC_B.k_c1;
        if (motion_controller_withPIC_B.b_n >= 1) {
          for (motion_controller_withPIC_B.e_k = 0;
               motion_controller_withPIC_B.e_k < motion_controller_withPIC_B.b_n;
               motion_controller_withPIC_B.e_k++) {
            motion_controller_withPIC_B.b_temp_tmp_g =
              motion_controller_withPIC_B.e_k * 41 +
              motion_controller_withPIC_B.QRk0;
            motion_controller_withPIC_B.b_temp_tmp = obj->
              QR[motion_controller_withPIC_B.b_temp_tmp_g - 1];
            motion_controller_withPIC_B.b_temp =
              motion_controller_withPIC_B.b_temp_tmp *
              motion_controller_withPIC_B.c_c + obj->
              QR[motion_controller_withPIC_B.b_temp_tmp_g] *
              motion_controller_withPIC_B.b_s;
            obj->QR[motion_controller_withPIC_B.b_temp_tmp_g] = obj->
              QR[motion_controller_withPIC_B.b_temp_tmp_g] *
              motion_controller_withPIC_B.c_c -
              motion_controller_withPIC_B.b_temp_tmp *
              motion_controller_withPIC_B.b_s;
            obj->QR[motion_controller_withPIC_B.b_temp_tmp_g - 1] =
              motion_controller_withPIC_B.b_temp;
          }
        }

        motion_controller_withPIC_B.e_k = obj->mrows;
        if (obj->mrows >= 1) {
          for (motion_controller_withPIC_B.QRk0 = 0;
               motion_controller_withPIC_B.QRk0 <
               motion_controller_withPIC_B.e_k; motion_controller_withPIC_B.QRk0
               ++) {
            motion_controller_withPIC_B.b_n =
              motion_controller_withPIC_B.idxRotGCol +
              motion_controller_withPIC_B.QRk0;
            motion_controller_withPIC_B.b_temp_tmp = obj->
              Q[motion_controller_withPIC_B.b_n + 41];
            motion_controller_withPIC_B.b_temp =
              motion_controller_withPIC_B.b_temp_tmp *
              motion_controller_withPIC_B.b_s + obj->
              Q[motion_controller_withPIC_B.b_n] *
              motion_controller_withPIC_B.c_c;
            obj->Q[motion_controller_withPIC_B.b_n + 41] =
              motion_controller_withPIC_B.b_temp_tmp *
              motion_controller_withPIC_B.c_c - obj->
              Q[motion_controller_withPIC_B.b_n] *
              motion_controller_withPIC_B.b_s;
            obj->Q[motion_controller_withPIC_B.b_n] =
              motion_controller_withPIC_B.b_temp;
          }
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_controller__fullColLDL2_
  (s8kZFjDlzP6eNfOekUiP5MF_motio_T *obj, int32_T NColsRemain, real_T REG_PRIMAL)
{
  for (motion_controller_withPIC_B.lastDiag = 0;
       motion_controller_withPIC_B.lastDiag < NColsRemain;
       motion_controller_withPIC_B.lastDiag++) {
    motion_controller_withPIC_B.LD_diagOffset = 42 *
      motion_controller_withPIC_B.lastDiag;
    motion_controller_withPIC_B.temp_m = obj->
      FMat[motion_controller_withPIC_B.LD_diagOffset];
    if (fabs(motion_controller_withPIC_B.temp_m) <= obj->regTol_) {
      motion_controller_withPIC_B.temp_m += REG_PRIMAL;
      obj->FMat[motion_controller_withPIC_B.LD_diagOffset] =
        motion_controller_withPIC_B.temp_m;
    }

    motion_controller_withPIC_B.alpha1_h = -1.0 /
      motion_controller_withPIC_B.temp_m;
    motion_controller_withPIC_B.subMatrixDim = (NColsRemain -
      motion_controller_withPIC_B.lastDiag) - 2;
    for (motion_controller_withPIC_B.b_k = 0; motion_controller_withPIC_B.b_k <=
         motion_controller_withPIC_B.subMatrixDim;
         motion_controller_withPIC_B.b_k++) {
      obj->workspace_[motion_controller_withPIC_B.b_k] = obj->FMat
        [(motion_controller_withPIC_B.LD_diagOffset +
          motion_controller_withPIC_B.b_k) + 1];
    }

    if (!(motion_controller_withPIC_B.alpha1_h == 0.0)) {
      motion_controller_withPIC_B.jA_b =
        motion_controller_withPIC_B.LD_diagOffset + 43;
      for (motion_controller_withPIC_B.b_k = 0; motion_controller_withPIC_B.b_k <=
           motion_controller_withPIC_B.subMatrixDim;
           motion_controller_withPIC_B.b_k++) {
        motion_controller_withPIC_B.temp_m = obj->
          workspace_[motion_controller_withPIC_B.b_k];
        if (motion_controller_withPIC_B.temp_m != 0.0) {
          motion_controller_withPIC_B.temp_m *=
            motion_controller_withPIC_B.alpha1_h;
          motion_controller_withPIC_B.b_jk =
            motion_controller_withPIC_B.subMatrixDim +
            motion_controller_withPIC_B.jA_b;
          for (motion_controller_withPIC_B.ijA =
               motion_controller_withPIC_B.jA_b; motion_controller_withPIC_B.ijA
               <= motion_controller_withPIC_B.b_jk;
               motion_controller_withPIC_B.ijA++) {
            obj->FMat[motion_controller_withPIC_B.ijA - 1] += obj->
              workspace_[motion_controller_withPIC_B.ijA -
              motion_controller_withPIC_B.jA_b] *
              motion_controller_withPIC_B.temp_m;
          }
        }

        motion_controller_withPIC_B.jA_b += 41;
      }
    }

    motion_controller_withPIC_B.alpha1_h = 1.0 / obj->
      FMat[motion_controller_withPIC_B.LD_diagOffset];
    motion_controller_withPIC_B.b_k = motion_controller_withPIC_B.LD_diagOffset
      + motion_controller_withPIC_B.subMatrixDim;
    motion_controller_withPIC_B.ijA = (((((motion_controller_withPIC_B.b_k -
      motion_controller_withPIC_B.LD_diagOffset) + 1) / 2) << 1) +
      motion_controller_withPIC_B.LD_diagOffset) + 2;
    motion_controller_withPIC_B.jA_b = motion_controller_withPIC_B.ijA - 2;
    for (motion_controller_withPIC_B.subMatrixDim =
         motion_controller_withPIC_B.LD_diagOffset + 2;
         motion_controller_withPIC_B.subMatrixDim <=
         motion_controller_withPIC_B.jA_b;
         motion_controller_withPIC_B.subMatrixDim += 2) {
      __m128d tmp;
      tmp = _mm_loadu_pd(&obj->FMat[motion_controller_withPIC_B.subMatrixDim - 1]);
      _mm_storeu_pd(&obj->FMat[motion_controller_withPIC_B.subMatrixDim - 1],
                    _mm_mul_pd(tmp, _mm_set1_pd
        (motion_controller_withPIC_B.alpha1_h)));
    }

    for (motion_controller_withPIC_B.subMatrixDim =
         motion_controller_withPIC_B.ijA;
         motion_controller_withPIC_B.subMatrixDim <=
         motion_controller_withPIC_B.b_k + 2;
         motion_controller_withPIC_B.subMatrixDim++) {
      obj->FMat[motion_controller_withPIC_B.subMatrixDim - 1] *=
        motion_controller_withPIC_B.alpha1_h;
    }
  }

  motion_controller_withPIC_B.lastDiag = (NColsRemain - 1) * 42;
  if (fabs(obj->FMat[motion_controller_withPIC_B.lastDiag]) <= obj->regTol_) {
    obj->FMat[motion_controller_withPIC_B.lastDiag] += REG_PRIMAL;
  }
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_controlle_compute_deltax(const real_T H
  [1600], s5cJJO9CAPQxuVG0iaeiP4F_motio_T *solution,
  sFlCINAYeIgPgx0UwEHpaMF_motio_T *memspace, const
  s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager, s8kZFjDlzP6eNfOekUiP5MF_motio_T
  *cholmanager, const sKnhLiTH4yv7eF1oV2a74RG_motio_T *objective)
{
  __m128d tmp;
  __m128d tmp_0;
  int32_T exitg1;
  motion_controller_withPIC_B.nVar_c = qrmanager->mrows - 1;
  motion_controller_withPIC_B.mNull_tmp = qrmanager->mrows - qrmanager->ncols;
  if (motion_controller_withPIC_B.mNull_tmp <= 0) {
    if (motion_controller_withPIC_B.nVar_c >= 0) {
      memset(&solution->searchDir[0], 0, static_cast<uint32_T>
             (motion_controller_withPIC_B.nVar_c + 1) * sizeof(real_T));
    }
  } else {
    motion_controller_withPIC_B.b_ar = (qrmanager->mrows / 2) << 1;
    motion_controller_withPIC_B.vectorUB_b = motion_controller_withPIC_B.b_ar -
      2;
    for (motion_controller_withPIC_B.A_maxDiag_idx = 0;
         motion_controller_withPIC_B.A_maxDiag_idx <=
         motion_controller_withPIC_B.vectorUB_b;
         motion_controller_withPIC_B.A_maxDiag_idx += 2) {
      tmp_0 = _mm_loadu_pd(&objective->
                           grad[motion_controller_withPIC_B.A_maxDiag_idx]);
      _mm_storeu_pd(&solution->
                    searchDir[motion_controller_withPIC_B.A_maxDiag_idx],
                    _mm_mul_pd(tmp_0, _mm_set1_pd(-1.0)));
    }

    for (motion_controller_withPIC_B.A_maxDiag_idx =
         motion_controller_withPIC_B.b_ar;
         motion_controller_withPIC_B.A_maxDiag_idx <=
         motion_controller_withPIC_B.nVar_c;
         motion_controller_withPIC_B.A_maxDiag_idx++) {
      solution->searchDir[motion_controller_withPIC_B.A_maxDiag_idx] =
        -objective->grad[motion_controller_withPIC_B.A_maxDiag_idx];
    }

    if (qrmanager->ncols <= 0) {
      if (objective->objtype == 3) {
        motion_controller_withPIC_B.temp_i = 1.4901161193847656E-6 *
          static_cast<real_T>(qrmanager->mrows);
        cholmanager->ndims = qrmanager->mrows;
        for (motion_controller_withPIC_B.mNull_tmp = 0;
             motion_controller_withPIC_B.mNull_tmp <=
             motion_controller_withPIC_B.nVar_c;
             motion_controller_withPIC_B.mNull_tmp++) {
          motion_controller_withPIC_B.nullStartIdx =
            (motion_controller_withPIC_B.nVar_c + 1) *
            motion_controller_withPIC_B.mNull_tmp;
          motion_controller_withPIC_B.nVars = 41 *
            motion_controller_withPIC_B.mNull_tmp;
          for (motion_controller_withPIC_B.A_maxDiag_idx = 0;
               motion_controller_withPIC_B.A_maxDiag_idx <=
               motion_controller_withPIC_B.nVar_c;
               motion_controller_withPIC_B.A_maxDiag_idx++) {
            cholmanager->FMat[motion_controller_withPIC_B.nVars +
              motion_controller_withPIC_B.A_maxDiag_idx] =
              H[motion_controller_withPIC_B.A_maxDiag_idx +
              motion_controller_withPIC_B.nullStartIdx];
          }
        }

        if (qrmanager->mrows < 1) {
          motion_controller_withPIC_B.A_maxDiag_idx = -1;
        } else {
          motion_controller_withPIC_B.A_maxDiag_idx = 0;
          if (qrmanager->mrows > 1) {
            motion_controller_withPIC_B.smax = fabs(cholmanager->FMat[0]);
            for (motion_controller_withPIC_B.mNull_tmp = 2;
                 motion_controller_withPIC_B.mNull_tmp <=
                 motion_controller_withPIC_B.nVar_c + 1;
                 motion_controller_withPIC_B.mNull_tmp++) {
              motion_controller_withPIC_B.s_k = fabs(cholmanager->FMat
                [(motion_controller_withPIC_B.mNull_tmp - 1) * 42]);
              if (motion_controller_withPIC_B.s_k >
                  motion_controller_withPIC_B.smax) {
                motion_controller_withPIC_B.A_maxDiag_idx =
                  motion_controller_withPIC_B.mNull_tmp - 1;
                motion_controller_withPIC_B.smax =
                  motion_controller_withPIC_B.s_k;
              }
            }
          }
        }

        motion_controller_withPIC_B.smax = fabs(cholmanager->FMat[41 *
          motion_controller_withPIC_B.A_maxDiag_idx +
          motion_controller_withPIC_B.A_maxDiag_idx]) * 2.2204460492503131E-16;
        motion_controller_withPIC_B.s_k = fabs
          (motion_controller_withPIC_B.temp_i);
        if (motion_controller_withPIC_B.smax >= motion_controller_withPIC_B.s_k)
        {
          cholmanager->regTol_ = motion_controller_withPIC_B.smax;
        } else {
          cholmanager->regTol_ = motion_controller_withPIC_B.s_k;
        }

        motion_controller__fullColLDL2_(cholmanager, qrmanager->mrows,
          motion_controller_withPIC_B.temp_i);
        if (cholmanager->ConvexCheck) {
          motion_controller_withPIC_B.mNull_tmp = 0;
          do {
            exitg1 = 0;
            if (motion_controller_withPIC_B.mNull_tmp <=
                motion_controller_withPIC_B.nVar_c) {
              if (cholmanager->FMat[41 * motion_controller_withPIC_B.mNull_tmp +
                  motion_controller_withPIC_B.mNull_tmp] <= 0.0) {
                cholmanager->info = -motion_controller_withPIC_B.mNull_tmp - 1;
                exitg1 = 1;
              } else {
                motion_controller_withPIC_B.mNull_tmp++;
              }
            } else {
              cholmanager->ConvexCheck = false;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }

        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          motion_controller_withPIC_B.nVar_c = cholmanager->ndims - 1;
          if (cholmanager->ndims != 0) {
            for (motion_controller_withPIC_B.mNull_tmp = 0;
                 motion_controller_withPIC_B.mNull_tmp <=
                 motion_controller_withPIC_B.nVar_c;
                 motion_controller_withPIC_B.mNull_tmp++) {
              motion_controller_withPIC_B.nullStartIdx =
                motion_controller_withPIC_B.mNull_tmp * 41 +
                motion_controller_withPIC_B.mNull_tmp;
              motion_controller_withPIC_B.nVars =
                motion_controller_withPIC_B.nVar_c -
                motion_controller_withPIC_B.mNull_tmp;
              for (motion_controller_withPIC_B.A_maxDiag_idx = 0;
                   motion_controller_withPIC_B.A_maxDiag_idx <
                   motion_controller_withPIC_B.nVars;
                   motion_controller_withPIC_B.A_maxDiag_idx++) {
                motion_controller_withPIC_B.b_A_maxDiag_idx =
                  (motion_controller_withPIC_B.A_maxDiag_idx +
                   motion_controller_withPIC_B.mNull_tmp) + 1;
                solution->searchDir[motion_controller_withPIC_B.b_A_maxDiag_idx]
                  -= cholmanager->FMat
                  [(motion_controller_withPIC_B.A_maxDiag_idx +
                    motion_controller_withPIC_B.nullStartIdx) + 1] *
                  solution->searchDir[motion_controller_withPIC_B.mNull_tmp];
              }
            }
          }

          motion_controller_withPIC_B.nVar_c = cholmanager->ndims;
          for (motion_controller_withPIC_B.mNull_tmp = 0;
               motion_controller_withPIC_B.mNull_tmp <
               motion_controller_withPIC_B.nVar_c;
               motion_controller_withPIC_B.mNull_tmp++) {
            solution->searchDir[motion_controller_withPIC_B.mNull_tmp] /=
              cholmanager->FMat[41 * motion_controller_withPIC_B.mNull_tmp +
              motion_controller_withPIC_B.mNull_tmp];
          }

          if (cholmanager->ndims != 0) {
            for (motion_controller_withPIC_B.mNull_tmp =
                 motion_controller_withPIC_B.nVar_c;
                 motion_controller_withPIC_B.mNull_tmp >= 1;
                 motion_controller_withPIC_B.mNull_tmp--) {
              motion_controller_withPIC_B.nullStartIdx =
                (motion_controller_withPIC_B.mNull_tmp - 1) * 41;
              motion_controller_withPIC_B.temp_i = solution->
                searchDir[motion_controller_withPIC_B.mNull_tmp - 1];
              for (motion_controller_withPIC_B.A_maxDiag_idx =
                   motion_controller_withPIC_B.nVar_c;
                   motion_controller_withPIC_B.A_maxDiag_idx >=
                   motion_controller_withPIC_B.mNull_tmp + 1;
                   motion_controller_withPIC_B.A_maxDiag_idx--) {
                motion_controller_withPIC_B.temp_i -= cholmanager->FMat
                  [(motion_controller_withPIC_B.nullStartIdx +
                    motion_controller_withPIC_B.A_maxDiag_idx) - 1] *
                  solution->searchDir[motion_controller_withPIC_B.A_maxDiag_idx
                  - 1];
              }

              solution->searchDir[motion_controller_withPIC_B.mNull_tmp - 1] =
                motion_controller_withPIC_B.temp_i;
            }
          }
        }
      }
    } else {
      motion_controller_withPIC_B.A_maxDiag_idx = 41 * qrmanager->ncols;
      motion_controller_withPIC_B.nullStartIdx =
        motion_controller_withPIC_B.A_maxDiag_idx + 1;
      if (objective->objtype == 5) {
        for (motion_controller_withPIC_B.nullStartIdx = 0;
             motion_controller_withPIC_B.nullStartIdx <
             motion_controller_withPIC_B.mNull_tmp;
             motion_controller_withPIC_B.nullStartIdx++) {
          memspace->workspace_double[motion_controller_withPIC_B.nullStartIdx] =
            -qrmanager->Q[(qrmanager->ncols +
                           motion_controller_withPIC_B.nullStartIdx) * 41 +
            motion_controller_withPIC_B.nVar_c];
        }

        xgemv_L5SThEQW(qrmanager->mrows, motion_controller_withPIC_B.mNull_tmp,
                       qrmanager->Q, motion_controller_withPIC_B.A_maxDiag_idx +
                       1, memspace->workspace_double, solution->searchDir);
      } else {
        if (objective->objtype == 3) {
          motion_controller_withPIC_B.nVars = qrmanager->mrows;
          if ((qrmanager->mrows != 0) && (motion_controller_withPIC_B.mNull_tmp
               != 0)) {
            motion_controller_withPIC_B.br_n =
              motion_controller_withPIC_B.A_maxDiag_idx;
            motion_controller_withPIC_B.lastColC =
              (motion_controller_withPIC_B.mNull_tmp - 1) * 161;
            for (motion_controller_withPIC_B.b_A_maxDiag_idx = 0;
                 motion_controller_withPIC_B.b_A_maxDiag_idx <=
                 motion_controller_withPIC_B.lastColC;
                 motion_controller_withPIC_B.b_A_maxDiag_idx += 161) {
              motion_controller_withPIC_B.e_ix =
                motion_controller_withPIC_B.b_A_maxDiag_idx +
                motion_controller_withPIC_B.nVars;
              for (motion_controller_withPIC_B.ic =
                   motion_controller_withPIC_B.b_A_maxDiag_idx + 1;
                   motion_controller_withPIC_B.ic <=
                   motion_controller_withPIC_B.e_ix;
                   motion_controller_withPIC_B.ic++) {
                memspace->workspace_double[motion_controller_withPIC_B.ic - 1] =
                  0.0;
              }
            }

            for (motion_controller_withPIC_B.b_A_maxDiag_idx = 0;
                 motion_controller_withPIC_B.b_A_maxDiag_idx <=
                 motion_controller_withPIC_B.lastColC;
                 motion_controller_withPIC_B.b_A_maxDiag_idx += 161) {
              motion_controller_withPIC_B.ar_da = -1;
              motion_controller_withPIC_B.h_i = motion_controller_withPIC_B.br_n
                + motion_controller_withPIC_B.nVars;
              for (motion_controller_withPIC_B.ic =
                   motion_controller_withPIC_B.br_n + 1;
                   motion_controller_withPIC_B.ic <=
                   motion_controller_withPIC_B.h_i;
                   motion_controller_withPIC_B.ic++) {
                motion_controller_withPIC_B.i_n =
                  motion_controller_withPIC_B.b_A_maxDiag_idx +
                  motion_controller_withPIC_B.nVars;
                motion_controller_withPIC_B.b_ar =
                  ((((motion_controller_withPIC_B.i_n -
                      motion_controller_withPIC_B.b_A_maxDiag_idx) / 2) << 1) +
                   motion_controller_withPIC_B.b_A_maxDiag_idx) + 1;
                motion_controller_withPIC_B.vectorUB_b =
                  motion_controller_withPIC_B.b_ar - 2;
                for (motion_controller_withPIC_B.e_ix =
                     motion_controller_withPIC_B.b_A_maxDiag_idx + 1;
                     motion_controller_withPIC_B.e_ix <=
                     motion_controller_withPIC_B.vectorUB_b;
                     motion_controller_withPIC_B.e_ix += 2) {
                  tmp_0 = _mm_loadu_pd(&H[(motion_controller_withPIC_B.ar_da +
                    motion_controller_withPIC_B.e_ix) -
                                       motion_controller_withPIC_B.b_A_maxDiag_idx]);
                  tmp = _mm_loadu_pd(&memspace->
                                     workspace_double[motion_controller_withPIC_B.e_ix
                                     - 1]);
                  _mm_storeu_pd(&memspace->
                                workspace_double[motion_controller_withPIC_B.e_ix
                                - 1], _mm_add_pd(_mm_mul_pd(tmp_0, _mm_set1_pd
                    (qrmanager->Q[motion_controller_withPIC_B.ic - 1])), tmp));
                }

                for (motion_controller_withPIC_B.e_ix =
                     motion_controller_withPIC_B.b_ar;
                     motion_controller_withPIC_B.e_ix <=
                     motion_controller_withPIC_B.i_n;
                     motion_controller_withPIC_B.e_ix++) {
                  memspace->workspace_double[motion_controller_withPIC_B.e_ix -
                    1] += H[(motion_controller_withPIC_B.ar_da +
                             motion_controller_withPIC_B.e_ix) -
                    motion_controller_withPIC_B.b_A_maxDiag_idx] * qrmanager->
                    Q[motion_controller_withPIC_B.ic - 1];
                }

                motion_controller_withPIC_B.ar_da +=
                  motion_controller_withPIC_B.nVars;
              }

              motion_controller_withPIC_B.br_n += 41;
            }
          }

          if (motion_controller_withPIC_B.mNull_tmp != 0) {
            motion_controller_withPIC_B.br_n =
              (motion_controller_withPIC_B.mNull_tmp - 1) * 41;
            for (motion_controller_withPIC_B.b_A_maxDiag_idx = 0;
                 motion_controller_withPIC_B.b_A_maxDiag_idx <=
                 motion_controller_withPIC_B.br_n;
                 motion_controller_withPIC_B.b_A_maxDiag_idx += 41) {
              motion_controller_withPIC_B.e_ix =
                motion_controller_withPIC_B.b_A_maxDiag_idx +
                motion_controller_withPIC_B.mNull_tmp;
              for (motion_controller_withPIC_B.ic =
                   motion_controller_withPIC_B.b_A_maxDiag_idx + 1;
                   motion_controller_withPIC_B.ic <=
                   motion_controller_withPIC_B.e_ix;
                   motion_controller_withPIC_B.ic++) {
                cholmanager->FMat[motion_controller_withPIC_B.ic - 1] = 0.0;
              }
            }

            motion_controller_withPIC_B.lastColC = -1;
            for (motion_controller_withPIC_B.b_A_maxDiag_idx = 0;
                 motion_controller_withPIC_B.b_A_maxDiag_idx <=
                 motion_controller_withPIC_B.br_n;
                 motion_controller_withPIC_B.b_A_maxDiag_idx += 41) {
              motion_controller_withPIC_B.b_ar =
                motion_controller_withPIC_B.A_maxDiag_idx;
              motion_controller_withPIC_B.vectorUB_b =
                motion_controller_withPIC_B.b_A_maxDiag_idx +
                motion_controller_withPIC_B.mNull_tmp;
              for (motion_controller_withPIC_B.ic =
                   motion_controller_withPIC_B.b_A_maxDiag_idx + 1;
                   motion_controller_withPIC_B.ic <=
                   motion_controller_withPIC_B.vectorUB_b;
                   motion_controller_withPIC_B.ic++) {
                motion_controller_withPIC_B.temp_i = 0.0;
                for (motion_controller_withPIC_B.e_ix = 0;
                     motion_controller_withPIC_B.e_ix <
                     motion_controller_withPIC_B.nVars;
                     motion_controller_withPIC_B.e_ix++) {
                  motion_controller_withPIC_B.temp_i +=
                    memspace->workspace_double[(motion_controller_withPIC_B.e_ix
                    + motion_controller_withPIC_B.lastColC) + 1] * qrmanager->
                    Q[motion_controller_withPIC_B.e_ix +
                    motion_controller_withPIC_B.b_ar];
                }

                cholmanager->FMat[motion_controller_withPIC_B.ic - 1] +=
                  motion_controller_withPIC_B.temp_i;
                motion_controller_withPIC_B.b_ar += 41;
              }

              motion_controller_withPIC_B.lastColC += 161;
            }
          }
        }

        motion_controller_withPIC_B.temp_i = 1.4901161193847656E-6 *
          static_cast<real_T>(motion_controller_withPIC_B.mNull_tmp);
        cholmanager->ndims = motion_controller_withPIC_B.mNull_tmp;
        motion_controller_withPIC_B.b_A_maxDiag_idx = 0;
        if (motion_controller_withPIC_B.mNull_tmp > 1) {
          motion_controller_withPIC_B.smax = fabs(cholmanager->FMat[0]);
          for (motion_controller_withPIC_B.nVars = 2;
               motion_controller_withPIC_B.nVars <=
               motion_controller_withPIC_B.mNull_tmp;
               motion_controller_withPIC_B.nVars++) {
            motion_controller_withPIC_B.s_k = fabs(cholmanager->FMat
              [(motion_controller_withPIC_B.nVars - 1) * 42]);
            if (motion_controller_withPIC_B.s_k >
                motion_controller_withPIC_B.smax) {
              motion_controller_withPIC_B.b_A_maxDiag_idx =
                motion_controller_withPIC_B.nVars - 1;
              motion_controller_withPIC_B.smax = motion_controller_withPIC_B.s_k;
            }
          }
        }

        motion_controller_withPIC_B.smax = fabs(cholmanager->FMat[41 *
          motion_controller_withPIC_B.b_A_maxDiag_idx +
          motion_controller_withPIC_B.b_A_maxDiag_idx]) * 2.2204460492503131E-16;
        if (motion_controller_withPIC_B.smax >=
            motion_controller_withPIC_B.temp_i) {
          cholmanager->regTol_ = motion_controller_withPIC_B.smax;
        } else {
          cholmanager->regTol_ = motion_controller_withPIC_B.temp_i;
        }

        motion_controller__fullColLDL2_(cholmanager,
          motion_controller_withPIC_B.mNull_tmp,
          motion_controller_withPIC_B.temp_i);
        if (cholmanager->ConvexCheck) {
          motion_controller_withPIC_B.nVars = 0;
          do {
            exitg1 = 0;
            if (motion_controller_withPIC_B.nVars <=
                motion_controller_withPIC_B.mNull_tmp - 1) {
              if (cholmanager->FMat[41 * motion_controller_withPIC_B.nVars +
                  motion_controller_withPIC_B.nVars] <= 0.0) {
                cholmanager->info = -motion_controller_withPIC_B.nVars - 1;
                exitg1 = 1;
              } else {
                motion_controller_withPIC_B.nVars++;
              }
            } else {
              cholmanager->ConvexCheck = false;
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        }

        if (cholmanager->info != 0) {
          solution->state = -6;
        } else {
          if (qrmanager->mrows != 0) {
            memset(&memspace->workspace_double[0], 0, static_cast<uint32_T>
                   (motion_controller_withPIC_B.mNull_tmp) * sizeof(real_T));
            motion_controller_withPIC_B.ic =
              ((motion_controller_withPIC_B.mNull_tmp - 1) * 41 +
               motion_controller_withPIC_B.A_maxDiag_idx) + 1;
            for (motion_controller_withPIC_B.nVars =
                 motion_controller_withPIC_B.nullStartIdx;
                 motion_controller_withPIC_B.nVars <=
                 motion_controller_withPIC_B.ic;
                 motion_controller_withPIC_B.nVars += 41) {
              motion_controller_withPIC_B.temp_i = 0.0;
              motion_controller_withPIC_B.e_ix =
                motion_controller_withPIC_B.nVars +
                motion_controller_withPIC_B.nVar_c;
              for (motion_controller_withPIC_B.b_A_maxDiag_idx =
                   motion_controller_withPIC_B.nVars;
                   motion_controller_withPIC_B.b_A_maxDiag_idx <=
                   motion_controller_withPIC_B.e_ix;
                   motion_controller_withPIC_B.b_A_maxDiag_idx++) {
                motion_controller_withPIC_B.temp_i += qrmanager->
                  Q[motion_controller_withPIC_B.b_A_maxDiag_idx - 1] *
                  objective->grad[motion_controller_withPIC_B.b_A_maxDiag_idx -
                  motion_controller_withPIC_B.nVars];
              }

              motion_controller_withPIC_B.b_A_maxDiag_idx = div_nde_s32_floor
                ((motion_controller_withPIC_B.nVars -
                  motion_controller_withPIC_B.A_maxDiag_idx) - 1, 41);
              memspace->
                workspace_double[motion_controller_withPIC_B.b_A_maxDiag_idx] -=
                motion_controller_withPIC_B.temp_i;
            }
          }

          motion_controller_withPIC_B.nVars = cholmanager->ndims - 1;
          if (cholmanager->ndims != 0) {
            for (motion_controller_withPIC_B.nVar_c = 0;
                 motion_controller_withPIC_B.nVar_c <=
                 motion_controller_withPIC_B.nVars;
                 motion_controller_withPIC_B.nVar_c++) {
              motion_controller_withPIC_B.b_A_maxDiag_idx =
                motion_controller_withPIC_B.nVar_c * 41 +
                motion_controller_withPIC_B.nVar_c;
              motion_controller_withPIC_B.ic = motion_controller_withPIC_B.nVars
                - motion_controller_withPIC_B.nVar_c;
              for (motion_controller_withPIC_B.nullStartIdx = 0;
                   motion_controller_withPIC_B.nullStartIdx <
                   motion_controller_withPIC_B.ic;
                   motion_controller_withPIC_B.nullStartIdx++) {
                motion_controller_withPIC_B.e_ix =
                  (motion_controller_withPIC_B.nullStartIdx +
                   motion_controller_withPIC_B.nVar_c) + 1;
                memspace->workspace_double[motion_controller_withPIC_B.e_ix] -=
                  cholmanager->FMat[(motion_controller_withPIC_B.nullStartIdx +
                                     motion_controller_withPIC_B.b_A_maxDiag_idx)
                  + 1] * memspace->
                  workspace_double[motion_controller_withPIC_B.nVar_c];
              }
            }
          }

          motion_controller_withPIC_B.nVars = cholmanager->ndims;
          for (motion_controller_withPIC_B.nVar_c = 0;
               motion_controller_withPIC_B.nVar_c <
               motion_controller_withPIC_B.nVars;
               motion_controller_withPIC_B.nVar_c++) {
            memspace->workspace_double[motion_controller_withPIC_B.nVar_c] /=
              cholmanager->FMat[41 * motion_controller_withPIC_B.nVar_c +
              motion_controller_withPIC_B.nVar_c];
          }

          if (cholmanager->ndims != 0) {
            for (motion_controller_withPIC_B.nVar_c =
                 motion_controller_withPIC_B.nVars;
                 motion_controller_withPIC_B.nVar_c >= 1;
                 motion_controller_withPIC_B.nVar_c--) {
              motion_controller_withPIC_B.b_A_maxDiag_idx =
                (motion_controller_withPIC_B.nVar_c - 1) * 41;
              motion_controller_withPIC_B.temp_i = memspace->
                workspace_double[motion_controller_withPIC_B.nVar_c - 1];
              for (motion_controller_withPIC_B.nullStartIdx =
                   motion_controller_withPIC_B.nVars;
                   motion_controller_withPIC_B.nullStartIdx >=
                   motion_controller_withPIC_B.nVar_c + 1;
                   motion_controller_withPIC_B.nullStartIdx--) {
                motion_controller_withPIC_B.temp_i -= cholmanager->FMat
                  [(motion_controller_withPIC_B.b_A_maxDiag_idx +
                    motion_controller_withPIC_B.nullStartIdx) - 1] *
                  memspace->
                  workspace_double[motion_controller_withPIC_B.nullStartIdx - 1];
              }

              memspace->workspace_double[motion_controller_withPIC_B.nVar_c - 1]
                = motion_controller_withPIC_B.temp_i;
            }
          }

          xgemv_L5SThEQW(qrmanager->mrows, motion_controller_withPIC_B.mNull_tmp,
                         qrmanager->Q, motion_controller_withPIC_B.A_maxDiag_idx
                         + 1, memspace->workspace_double, solution->searchDir);
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S62>/solvex'
real_T motion_controller_withPIC::motion_controlle_xnrm2_DlmxxpnG(int32_T n,
  const real_T x[41])
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[0]);
    } else {
      motion_controller_withPIC_B.scale_j = 3.3121686421112381E-170;
      motion_controller_withPIC_B.b_l = static_cast<uint8_T>(n);
      for (motion_controller_withPIC_B.k_ce = 0;
           motion_controller_withPIC_B.k_ce < motion_controller_withPIC_B.b_l;
           motion_controller_withPIC_B.k_ce++) {
        motion_controller_withPIC_B.absxk_i = fabs
          (x[motion_controller_withPIC_B.k_ce]);
        if (motion_controller_withPIC_B.absxk_i >
            motion_controller_withPIC_B.scale_j) {
          motion_controller_withPIC_B.t_m = motion_controller_withPIC_B.scale_j /
            motion_controller_withPIC_B.absxk_i;
          y = y * motion_controller_withPIC_B.t_m *
            motion_controller_withPIC_B.t_m + 1.0;
          motion_controller_withPIC_B.scale_j =
            motion_controller_withPIC_B.absxk_i;
        } else {
          motion_controller_withPIC_B.t_m = motion_controller_withPIC_B.absxk_i /
            motion_controller_withPIC_B.scale_j;
          y += motion_controller_withPIC_B.t_m * motion_controller_withPIC_B.t_m;
        }
      }

      y = motion_controller_withPIC_B.scale_j * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_controlle_xgemv_pKPSQiPT(int32_T m, const
  real_T A[3280], const real_T x[41], real_T y[6601])
{
  for (motion_controller_withPIC_B.b_iy = 0; motion_controller_withPIC_B.b_iy <=
       78; motion_controller_withPIC_B.b_iy += 2) {
    __m128d tmp;
    tmp = _mm_loadu_pd(&y[motion_controller_withPIC_B.b_iy]);
    _mm_storeu_pd(&y[motion_controller_withPIC_B.b_iy], _mm_mul_pd(tmp,
      _mm_set1_pd(-1.0)));
  }

  for (motion_controller_withPIC_B.b_iy = 0; motion_controller_withPIC_B.b_iy <=
       3239; motion_controller_withPIC_B.b_iy += 41) {
    motion_controller_withPIC_B.c_m = 0.0;
    motion_controller_withPIC_B.b_he = motion_controller_withPIC_B.b_iy + m;
    for (motion_controller_withPIC_B.ia_i = motion_controller_withPIC_B.b_iy + 1;
         motion_controller_withPIC_B.ia_i <= motion_controller_withPIC_B.b_he;
         motion_controller_withPIC_B.ia_i++) {
      motion_controller_withPIC_B.c_m += x[(motion_controller_withPIC_B.ia_i -
        motion_controller_withPIC_B.b_iy) - 1] *
        A[motion_controller_withPIC_B.ia_i - 1];
    }

    motion_controller_withPIC_B.ia_i = div_nde_s32_floor
      (motion_controller_withPIC_B.b_iy, 41);
    y[motion_controller_withPIC_B.ia_i] += motion_controller_withPIC_B.c_m;
  }
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_controller_wit_ratiotest(const real_T
  solution_xstar[41], const real_T solution_searchDir[41], real_T workspace[6601],
  int32_T workingset_nVar, const real_T workingset_Aineq[3280], const real_T
  workingset_bineq[80], const real_T workingset_lb[41], const real_T
  workingset_ub[41], const int32_T workingset_indexLB[41], const int32_T
  workingset_indexUB[41], const int32_T workingset_sizes[5], const int32_T
  workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr[161],
  const int32_T workingset_nWConstr[5], real_T *toldelta, real_T *alpha,
  boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx)
{
  *alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  motion_controller_withPIC_B.p_max = 0.0;
  motion_controller_withPIC_B.denomTol = 2.2204460492503131E-13 *
    motion_controlle_xnrm2_DlmxxpnG(workingset_nVar, solution_searchDir);
  if (workingset_nWConstr[2] < 80) {
    memcpy(&workspace[0], &workingset_bineq[0], 80U * sizeof(real_T));
    motion_controlle_xgemv_pKPSQiPT(workingset_nVar, workingset_Aineq,
      solution_xstar, workspace);
    memset(&workspace[161], 0, 80U * sizeof(real_T));
    for (motion_controller_withPIC_B.k_c = 0; motion_controller_withPIC_B.k_c <=
         3239; motion_controller_withPIC_B.k_c += 41) {
      motion_controller_withPIC_B.b_c_d = 0.0;
      motion_controller_withPIC_B.d_oc = motion_controller_withPIC_B.k_c +
        workingset_nVar;
      for (motion_controller_withPIC_B.ia_ol = motion_controller_withPIC_B.k_c +
           1; motion_controller_withPIC_B.ia_ol <=
           motion_controller_withPIC_B.d_oc; motion_controller_withPIC_B.ia_ol++)
      {
        motion_controller_withPIC_B.b_c_d += solution_searchDir
          [(motion_controller_withPIC_B.ia_ol - motion_controller_withPIC_B.k_c)
          - 1] * workingset_Aineq[motion_controller_withPIC_B.ia_ol - 1];
      }

      motion_controller_withPIC_B.ia_ol = div_nde_s32_floor
        (motion_controller_withPIC_B.k_c, 41) + 161;
      workspace[motion_controller_withPIC_B.ia_ol] +=
        motion_controller_withPIC_B.b_c_d;
    }

    for (motion_controller_withPIC_B.k_c = 0; motion_controller_withPIC_B.k_c <
         80; motion_controller_withPIC_B.k_c++) {
      motion_controller_withPIC_B.workspace =
        workspace[motion_controller_withPIC_B.k_c + 161];
      if ((motion_controller_withPIC_B.workspace >
           motion_controller_withPIC_B.denomTol) && (!workingset_isActiveConstr
           [(workingset_isActiveIdx[2] + motion_controller_withPIC_B.k_c) - 1]))
      {
        motion_controller_withPIC_B.phaseOneCorrectionX =
          workspace[motion_controller_withPIC_B.k_c];
        motion_controller_withPIC_B.b_c_d = fabs
          (motion_controller_withPIC_B.phaseOneCorrectionX - *toldelta);
        motion_controller_withPIC_B.phaseOneCorrectionP = (1.0E-8 -
          motion_controller_withPIC_B.phaseOneCorrectionX) + *toldelta;
        if ((motion_controller_withPIC_B.b_c_d <=
             motion_controller_withPIC_B.phaseOneCorrectionP) || rtIsNaN
            (motion_controller_withPIC_B.phaseOneCorrectionP)) {
          motion_controller_withPIC_B.phaseOneCorrectionP =
            motion_controller_withPIC_B.b_c_d;
        }

        motion_controller_withPIC_B.b_c_d =
          motion_controller_withPIC_B.phaseOneCorrectionP /
          motion_controller_withPIC_B.workspace;
        if ((motion_controller_withPIC_B.b_c_d <= *alpha) && (fabs
             (motion_controller_withPIC_B.workspace) >
             motion_controller_withPIC_B.p_max)) {
          *alpha = motion_controller_withPIC_B.b_c_d;
          *constrType = 3;
          *constrIdx = motion_controller_withPIC_B.k_c + 1;
          *newBlocking = true;
        }

        motion_controller_withPIC_B.b_c_d = fabs
          (motion_controller_withPIC_B.phaseOneCorrectionX);
        if ((!(motion_controller_withPIC_B.b_c_d <= 1.0E-8 -
               motion_controller_withPIC_B.phaseOneCorrectionX)) && (!rtIsNaN
             (1.0E-8 - motion_controller_withPIC_B.phaseOneCorrectionX))) {
          motion_controller_withPIC_B.b_c_d = 1.0E-8 -
            motion_controller_withPIC_B.phaseOneCorrectionX;
        }

        motion_controller_withPIC_B.b_c_d /=
          motion_controller_withPIC_B.workspace;
        if (motion_controller_withPIC_B.b_c_d < *alpha) {
          *alpha = motion_controller_withPIC_B.b_c_d;
          *constrType = 3;
          *constrIdx = motion_controller_withPIC_B.k_c + 1;
          *newBlocking = true;
          motion_controller_withPIC_B.p_max = fabs
            (motion_controller_withPIC_B.workspace);
        }
      }
    }
  }

  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    motion_controller_withPIC_B.phaseOneCorrectionX =
      solution_xstar[workingset_nVar - 1] * 0.0;
    motion_controller_withPIC_B.phaseOneCorrectionP =
      solution_searchDir[workingset_nVar - 1] * 0.0;
    motion_controller_withPIC_B.ia_ol = workingset_sizes[3];
    for (motion_controller_withPIC_B.k_c = 0; motion_controller_withPIC_B.k_c <=
         motion_controller_withPIC_B.ia_ol - 2; motion_controller_withPIC_B.k_c
         ++) {
      motion_controller_withPIC_B.d_oc =
        workingset_indexLB[motion_controller_withPIC_B.k_c];
      motion_controller_withPIC_B.pk_corrected =
        -solution_searchDir[motion_controller_withPIC_B.d_oc - 1] -
        motion_controller_withPIC_B.phaseOneCorrectionP;
      if ((motion_controller_withPIC_B.pk_corrected >
           motion_controller_withPIC_B.denomTol) && (!workingset_isActiveConstr
           [(workingset_isActiveIdx[3] + motion_controller_withPIC_B.k_c) - 1]))
      {
        motion_controller_withPIC_B.workspace =
          -solution_xstar[motion_controller_withPIC_B.d_oc - 1] -
          workingset_lb[motion_controller_withPIC_B.d_oc - 1];
        motion_controller_withPIC_B.ratio =
          (motion_controller_withPIC_B.workspace - *toldelta) -
          motion_controller_withPIC_B.phaseOneCorrectionX;
        motion_controller_withPIC_B.b_c_d = fabs
          (motion_controller_withPIC_B.ratio);
        if ((!(motion_controller_withPIC_B.b_c_d <= 1.0E-8 -
               motion_controller_withPIC_B.ratio)) && (!rtIsNaN(1.0E-8 -
              motion_controller_withPIC_B.ratio))) {
          motion_controller_withPIC_B.b_c_d = 1.0E-8 -
            motion_controller_withPIC_B.ratio;
        }

        motion_controller_withPIC_B.b_c_d /=
          motion_controller_withPIC_B.pk_corrected;
        if ((motion_controller_withPIC_B.b_c_d <= *alpha) && (fabs
             (motion_controller_withPIC_B.pk_corrected) >
             motion_controller_withPIC_B.p_max)) {
          *alpha = motion_controller_withPIC_B.b_c_d;
          *constrType = 4;
          *constrIdx = motion_controller_withPIC_B.k_c + 1;
          *newBlocking = true;
        }

        motion_controller_withPIC_B.ratio =
          motion_controller_withPIC_B.workspace -
          motion_controller_withPIC_B.phaseOneCorrectionX;
        motion_controller_withPIC_B.b_c_d = fabs
          (motion_controller_withPIC_B.ratio);
        if ((!(motion_controller_withPIC_B.b_c_d <= 1.0E-8 -
               motion_controller_withPIC_B.ratio)) && (!rtIsNaN(1.0E-8 -
              motion_controller_withPIC_B.ratio))) {
          motion_controller_withPIC_B.b_c_d = 1.0E-8 -
            motion_controller_withPIC_B.ratio;
        }

        motion_controller_withPIC_B.b_c_d /=
          motion_controller_withPIC_B.pk_corrected;
        if (motion_controller_withPIC_B.b_c_d < *alpha) {
          *alpha = motion_controller_withPIC_B.b_c_d;
          *constrType = 4;
          *constrIdx = motion_controller_withPIC_B.k_c + 1;
          *newBlocking = true;
          motion_controller_withPIC_B.p_max = fabs
            (motion_controller_withPIC_B.pk_corrected);
        }
      }
    }

    motion_controller_withPIC_B.ia_ol = workingset_indexLB[workingset_sizes[3] -
      1] - 1;
    motion_controller_withPIC_B.phaseOneCorrectionX =
      solution_searchDir[motion_controller_withPIC_B.ia_ol];
    if ((-motion_controller_withPIC_B.phaseOneCorrectionX >
         motion_controller_withPIC_B.denomTol) && (!workingset_isActiveConstr
         [(workingset_isActiveIdx[3] + workingset_sizes[3]) - 2])) {
      motion_controller_withPIC_B.workspace =
        -solution_xstar[motion_controller_withPIC_B.ia_ol] -
        workingset_lb[motion_controller_withPIC_B.ia_ol];
      motion_controller_withPIC_B.ratio = motion_controller_withPIC_B.workspace
        - *toldelta;
      motion_controller_withPIC_B.b_c_d = fabs(motion_controller_withPIC_B.ratio);
      if ((!(motion_controller_withPIC_B.b_c_d <= 1.0E-8 -
             motion_controller_withPIC_B.ratio)) && (!rtIsNaN(1.0E-8 -
            motion_controller_withPIC_B.ratio))) {
        motion_controller_withPIC_B.b_c_d = 1.0E-8 -
          motion_controller_withPIC_B.ratio;
      }

      motion_controller_withPIC_B.b_c_d /=
        -motion_controller_withPIC_B.phaseOneCorrectionX;
      if ((motion_controller_withPIC_B.b_c_d <= *alpha) && (fabs
           (motion_controller_withPIC_B.phaseOneCorrectionX) >
           motion_controller_withPIC_B.p_max)) {
        *alpha = motion_controller_withPIC_B.b_c_d;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }

      motion_controller_withPIC_B.b_c_d = fabs
        (motion_controller_withPIC_B.workspace);
      if ((!(motion_controller_withPIC_B.b_c_d <= 1.0E-8 -
             motion_controller_withPIC_B.workspace)) && (!rtIsNaN(1.0E-8 -
            motion_controller_withPIC_B.workspace))) {
        motion_controller_withPIC_B.b_c_d = 1.0E-8 -
          motion_controller_withPIC_B.workspace;
      }

      motion_controller_withPIC_B.b_c_d /=
        -motion_controller_withPIC_B.phaseOneCorrectionX;
      if (motion_controller_withPIC_B.b_c_d < *alpha) {
        *alpha = motion_controller_withPIC_B.b_c_d;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
        motion_controller_withPIC_B.p_max = fabs
          (motion_controller_withPIC_B.phaseOneCorrectionX);
      }
    }
  }

  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    motion_controller_withPIC_B.phaseOneCorrectionX =
      solution_xstar[workingset_nVar - 1] * 0.0;
    motion_controller_withPIC_B.phaseOneCorrectionP =
      solution_searchDir[workingset_nVar - 1] * 0.0;
    motion_controller_withPIC_B.ia_ol = static_cast<uint8_T>(workingset_sizes[4]);
    for (motion_controller_withPIC_B.k_c = 0; motion_controller_withPIC_B.k_c <
         motion_controller_withPIC_B.ia_ol; motion_controller_withPIC_B.k_c++) {
      motion_controller_withPIC_B.d_oc =
        workingset_indexUB[motion_controller_withPIC_B.k_c];
      motion_controller_withPIC_B.pk_corrected =
        solution_searchDir[motion_controller_withPIC_B.d_oc - 1] -
        motion_controller_withPIC_B.phaseOneCorrectionP;
      if ((motion_controller_withPIC_B.pk_corrected >
           motion_controller_withPIC_B.denomTol) && (!workingset_isActiveConstr
           [(workingset_isActiveIdx[4] + motion_controller_withPIC_B.k_c) - 1]))
      {
        motion_controller_withPIC_B.workspace =
          solution_xstar[motion_controller_withPIC_B.d_oc - 1] -
          workingset_ub[motion_controller_withPIC_B.d_oc - 1];
        motion_controller_withPIC_B.ratio =
          (motion_controller_withPIC_B.workspace - *toldelta) -
          motion_controller_withPIC_B.phaseOneCorrectionX;
        motion_controller_withPIC_B.b_c_d = fabs
          (motion_controller_withPIC_B.ratio);
        if ((!(motion_controller_withPIC_B.b_c_d <= 1.0E-8 -
               motion_controller_withPIC_B.ratio)) && (!rtIsNaN(1.0E-8 -
              motion_controller_withPIC_B.ratio))) {
          motion_controller_withPIC_B.b_c_d = 1.0E-8 -
            motion_controller_withPIC_B.ratio;
        }

        motion_controller_withPIC_B.b_c_d /=
          motion_controller_withPIC_B.pk_corrected;
        if ((motion_controller_withPIC_B.b_c_d <= *alpha) && (fabs
             (motion_controller_withPIC_B.pk_corrected) >
             motion_controller_withPIC_B.p_max)) {
          *alpha = motion_controller_withPIC_B.b_c_d;
          *constrType = 5;
          *constrIdx = motion_controller_withPIC_B.k_c + 1;
          *newBlocking = true;
        }

        motion_controller_withPIC_B.ratio =
          motion_controller_withPIC_B.workspace -
          motion_controller_withPIC_B.phaseOneCorrectionX;
        motion_controller_withPIC_B.b_c_d = fabs
          (motion_controller_withPIC_B.ratio);
        if ((!(motion_controller_withPIC_B.b_c_d <= 1.0E-8 -
               motion_controller_withPIC_B.ratio)) && (!rtIsNaN(1.0E-8 -
              motion_controller_withPIC_B.ratio))) {
          motion_controller_withPIC_B.b_c_d = 1.0E-8 -
            motion_controller_withPIC_B.ratio;
        }

        motion_controller_withPIC_B.b_c_d /=
          motion_controller_withPIC_B.pk_corrected;
        if (motion_controller_withPIC_B.b_c_d < *alpha) {
          *alpha = motion_controller_withPIC_B.b_c_d;
          *constrType = 5;
          *constrIdx = motion_controller_withPIC_B.k_c + 1;
          *newBlocking = true;
          motion_controller_withPIC_B.p_max = fabs
            (motion_controller_withPIC_B.pk_corrected);
        }
      }
    }
  }

  *toldelta += 6.608625846508183E-7;
  if (motion_controller_withPIC_B.p_max > 0.0) {
    motion_controller_withPIC_B.phaseOneCorrectionP = 6.608625846508183E-7 /
      motion_controller_withPIC_B.p_max;
    if (!(*alpha >= motion_controller_withPIC_B.phaseOneCorrectionP)) {
      *alpha = motion_controller_withPIC_B.phaseOneCorrectionP;
    }
  }

  *newBlocking = (((!*newBlocking) || (!(*alpha > 1.0))) && (*newBlocking));
  if (!(*alpha <= 1.0)) {
    *alpha = 1.0;
  }
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_contro_feasibleratiotest(const real_T
  solution_xstar[41], const real_T solution_searchDir[41], real_T workspace[6601],
  int32_T workingset_nVar, const real_T workingset_Aineq[3280], const real_T
  workingset_bineq[80], const real_T workingset_lb[41], const real_T
  workingset_ub[41], const int32_T workingset_indexLB[41], const int32_T
  workingset_indexUB[41], const int32_T workingset_sizes[5], const int32_T
  workingset_isActiveIdx[6], const boolean_T workingset_isActiveConstr[161],
  const int32_T workingset_nWConstr[5], boolean_T isPhaseOne, real_T *alpha,
  boolean_T *newBlocking, int32_T *constrType, int32_T *constrIdx)
{
  *alpha = 1.0E+30;
  *newBlocking = false;
  *constrType = 0;
  *constrIdx = 0;
  motion_controller_withPIC_B.denomTol_g = 2.2204460492503131E-13 *
    motion_controlle_xnrm2_DlmxxpnG(workingset_nVar, solution_searchDir);
  if (workingset_nWConstr[2] < 80) {
    memcpy(&workspace[0], &workingset_bineq[0], 80U * sizeof(real_T));
    motion_controlle_xgemv_pKPSQiPT(workingset_nVar, workingset_Aineq,
      solution_xstar, workspace);
    memset(&workspace[161], 0, 80U * sizeof(real_T));
    for (motion_controller_withPIC_B.k_p4 = 0; motion_controller_withPIC_B.k_p4 <=
         3239; motion_controller_withPIC_B.k_p4 += 41) {
      motion_controller_withPIC_B.b_c_lu = 0.0;
      motion_controller_withPIC_B.d_i = motion_controller_withPIC_B.k_p4 +
        workingset_nVar;
      for (motion_controller_withPIC_B.ia_j = motion_controller_withPIC_B.k_p4 +
           1; motion_controller_withPIC_B.ia_j <=
           motion_controller_withPIC_B.d_i; motion_controller_withPIC_B.ia_j++)
      {
        motion_controller_withPIC_B.b_c_lu += solution_searchDir
          [(motion_controller_withPIC_B.ia_j - motion_controller_withPIC_B.k_p4)
          - 1] * workingset_Aineq[motion_controller_withPIC_B.ia_j - 1];
      }

      motion_controller_withPIC_B.ia_j = div_nde_s32_floor
        (motion_controller_withPIC_B.k_p4, 41) + 161;
      workspace[motion_controller_withPIC_B.ia_j] +=
        motion_controller_withPIC_B.b_c_lu;
    }

    for (motion_controller_withPIC_B.k_p4 = 0; motion_controller_withPIC_B.k_p4 <
         80; motion_controller_withPIC_B.k_p4++) {
      motion_controller_withPIC_B.phaseOneCorrectionX_o =
        workspace[motion_controller_withPIC_B.k_p4 + 161];
      if ((motion_controller_withPIC_B.phaseOneCorrectionX_o >
           motion_controller_withPIC_B.denomTol_g) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[2] +
            motion_controller_withPIC_B.k_p4) - 1])) {
        motion_controller_withPIC_B.phaseOneCorrectionP_h =
          workspace[motion_controller_withPIC_B.k_p4];
        motion_controller_withPIC_B.b_c_lu = fabs
          (motion_controller_withPIC_B.phaseOneCorrectionP_h);
        if ((!(motion_controller_withPIC_B.b_c_lu <= 1.0E-8 -
               motion_controller_withPIC_B.phaseOneCorrectionP_h)) && (!rtIsNaN
             (1.0E-8 - motion_controller_withPIC_B.phaseOneCorrectionP_h))) {
          motion_controller_withPIC_B.b_c_lu = 1.0E-8 -
            motion_controller_withPIC_B.phaseOneCorrectionP_h;
        }

        motion_controller_withPIC_B.b_c_lu /=
          motion_controller_withPIC_B.phaseOneCorrectionX_o;
        if (motion_controller_withPIC_B.b_c_lu < *alpha) {
          *alpha = motion_controller_withPIC_B.b_c_lu;
          *constrType = 3;
          *constrIdx = motion_controller_withPIC_B.k_p4 + 1;
          *newBlocking = true;
        }
      }
    }
  }

  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    motion_controller_withPIC_B.phaseOneCorrectionX_o =
      solution_xstar[workingset_nVar - 1] * static_cast<real_T>(isPhaseOne);
    motion_controller_withPIC_B.phaseOneCorrectionP_h =
      solution_searchDir[workingset_nVar - 1] * static_cast<real_T>(isPhaseOne);
    motion_controller_withPIC_B.ia_j = workingset_sizes[3];
    for (motion_controller_withPIC_B.k_p4 = 0; motion_controller_withPIC_B.k_p4 <=
         motion_controller_withPIC_B.ia_j - 2; motion_controller_withPIC_B.k_p4
         ++) {
      motion_controller_withPIC_B.d_i =
        workingset_indexLB[motion_controller_withPIC_B.k_p4];
      motion_controller_withPIC_B.pk_corrected_c =
        -solution_searchDir[motion_controller_withPIC_B.d_i - 1] -
        motion_controller_withPIC_B.phaseOneCorrectionP_h;
      if ((motion_controller_withPIC_B.pk_corrected_c >
           motion_controller_withPIC_B.denomTol_g) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[3] +
            motion_controller_withPIC_B.k_p4) - 1])) {
        motion_controller_withPIC_B.ratio_a =
          (-solution_xstar[motion_controller_withPIC_B.d_i - 1] -
           workingset_lb[motion_controller_withPIC_B.d_i - 1]) -
          motion_controller_withPIC_B.phaseOneCorrectionX_o;
        motion_controller_withPIC_B.b_c_lu = fabs
          (motion_controller_withPIC_B.ratio_a);
        if ((!(motion_controller_withPIC_B.b_c_lu <= 1.0E-8 -
               motion_controller_withPIC_B.ratio_a)) && (!rtIsNaN(1.0E-8 -
              motion_controller_withPIC_B.ratio_a))) {
          motion_controller_withPIC_B.b_c_lu = 1.0E-8 -
            motion_controller_withPIC_B.ratio_a;
        }

        motion_controller_withPIC_B.b_c_lu /=
          motion_controller_withPIC_B.pk_corrected_c;
        if (motion_controller_withPIC_B.b_c_lu < *alpha) {
          *alpha = motion_controller_withPIC_B.b_c_lu;
          *constrType = 4;
          *constrIdx = motion_controller_withPIC_B.k_p4 + 1;
          *newBlocking = true;
        }
      }
    }

    motion_controller_withPIC_B.ia_j = workingset_indexLB[workingset_sizes[3] -
      1] - 1;
    motion_controller_withPIC_B.phaseOneCorrectionX_o =
      -solution_searchDir[motion_controller_withPIC_B.ia_j];
    if ((motion_controller_withPIC_B.phaseOneCorrectionX_o >
         motion_controller_withPIC_B.denomTol_g) && (!workingset_isActiveConstr
         [(workingset_isActiveIdx[3] + workingset_sizes[3]) - 2])) {
      motion_controller_withPIC_B.ratio_a =
        -solution_xstar[motion_controller_withPIC_B.ia_j] -
        workingset_lb[motion_controller_withPIC_B.ia_j];
      motion_controller_withPIC_B.b_c_lu = fabs
        (motion_controller_withPIC_B.ratio_a);
      if ((!(motion_controller_withPIC_B.b_c_lu <= 1.0E-8 -
             motion_controller_withPIC_B.ratio_a)) && (!rtIsNaN(1.0E-8 -
            motion_controller_withPIC_B.ratio_a))) {
        motion_controller_withPIC_B.b_c_lu = 1.0E-8 -
          motion_controller_withPIC_B.ratio_a;
      }

      motion_controller_withPIC_B.b_c_lu /=
        motion_controller_withPIC_B.phaseOneCorrectionX_o;
      if (motion_controller_withPIC_B.b_c_lu < *alpha) {
        *alpha = motion_controller_withPIC_B.b_c_lu;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }
    }
  }

  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    motion_controller_withPIC_B.phaseOneCorrectionX_o =
      solution_xstar[workingset_nVar - 1] * static_cast<real_T>(isPhaseOne);
    motion_controller_withPIC_B.phaseOneCorrectionP_h =
      solution_searchDir[workingset_nVar - 1] * static_cast<real_T>(isPhaseOne);
    motion_controller_withPIC_B.ia_j = static_cast<uint8_T>(workingset_sizes[4]);
    for (motion_controller_withPIC_B.k_p4 = 0; motion_controller_withPIC_B.k_p4 <
         motion_controller_withPIC_B.ia_j; motion_controller_withPIC_B.k_p4++) {
      motion_controller_withPIC_B.d_i =
        workingset_indexUB[motion_controller_withPIC_B.k_p4];
      motion_controller_withPIC_B.pk_corrected_c =
        solution_searchDir[motion_controller_withPIC_B.d_i - 1] -
        motion_controller_withPIC_B.phaseOneCorrectionP_h;
      if ((motion_controller_withPIC_B.pk_corrected_c >
           motion_controller_withPIC_B.denomTol_g) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[4] +
            motion_controller_withPIC_B.k_p4) - 1])) {
        motion_controller_withPIC_B.ratio_a =
          (solution_xstar[motion_controller_withPIC_B.d_i - 1] -
           workingset_ub[motion_controller_withPIC_B.d_i - 1]) -
          motion_controller_withPIC_B.phaseOneCorrectionX_o;
        motion_controller_withPIC_B.b_c_lu = fabs
          (motion_controller_withPIC_B.ratio_a);
        if ((!(motion_controller_withPIC_B.b_c_lu <= 1.0E-8 -
               motion_controller_withPIC_B.ratio_a)) && (!rtIsNaN(1.0E-8 -
              motion_controller_withPIC_B.ratio_a))) {
          motion_controller_withPIC_B.b_c_lu = 1.0E-8 -
            motion_controller_withPIC_B.ratio_a;
        }

        motion_controller_withPIC_B.b_c_lu /=
          motion_controller_withPIC_B.pk_corrected_c;
        if (motion_controller_withPIC_B.b_c_lu < *alpha) {
          *alpha = motion_controller_withPIC_B.b_c_lu;
          *constrType = 5;
          *constrIdx = motion_controller_withPIC_B.k_p4 + 1;
          *newBlocking = true;
        }
      }
    }
  }

  if (!isPhaseOne) {
    *newBlocking = (((!*newBlocking) || (!(*alpha > 1.0))) && (*newBlocking));
    if (!(*alpha <= 1.0)) {
      *alpha = 1.0;
    }
  }
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::moti_addBoundToActiveSetMatrix_
  (sT1ziU4p6vTWuD880X9yNJ_motion_T *obj, int32_T TYPE, int32_T idx_local)
{
  int32_T colOffset;
  int32_T idx_bnd_local;
  obj->nWConstr[TYPE - 1]++;
  obj->isActiveConstr[(obj->isActiveIdx[TYPE - 1] + idx_local) - 2] = true;
  obj->nActiveConstr++;
  obj->Wid[obj->nActiveConstr - 1] = TYPE;
  obj->Wlocalidx[obj->nActiveConstr - 1] = idx_local;
  colOffset = (obj->nActiveConstr - 1) * 41 - 1;
  if (TYPE == 5) {
    idx_bnd_local = obj->indexUB[idx_local - 1];
    obj->bwset[obj->nActiveConstr - 1] = obj->ub[idx_bnd_local - 1];
  } else {
    idx_bnd_local = obj->indexLB[idx_local - 1];
    obj->bwset[obj->nActiveConstr - 1] = obj->lb[idx_bnd_local - 1];
  }

  if (static_cast<uint8_T>(idx_bnd_local - 1) - 1 >= 0) {
    memset(&obj->ATwset[colOffset + 1], 0, static_cast<uint32_T>
           ((static_cast<uint8_T>(idx_bnd_local - 1) + colOffset) - colOffset) *
           sizeof(real_T));
  }

  obj->ATwset[idx_bnd_local + colOffset] = static_cast<real_T>(TYPE == 5) * 2.0
    - 1.0;
  if (idx_bnd_local + 1 <= obj->nVar) {
    memset(&obj->ATwset[(idx_bnd_local + colOffset) + 1], 0,
           static_cast<uint32_T>(((obj->nVar + colOffset) - idx_bnd_local) -
            colOffset) * sizeof(real_T));
  }

  switch (obj->probType) {
   case 3:
   case 2:
    break;

   default:
    obj->ATwset[obj->nVar + colOffset] = -1.0;
    break;
  }
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::moti_checkStoppingAndUpdateFval(int32_T
  *activeSetChangeID, const real_T f[40], s5cJJO9CAPQxuVG0iaeiP4F_motio_T
  *solution, sFlCINAYeIgPgx0UwEHpaMF_motio_T *memspace, const
  sKnhLiTH4yv7eF1oV2a74RG_motio_T *objective, sT1ziU4p6vTWuD880X9yNJ_motion_T
  *workingset, s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager, real_T
  options_ObjectiveLimit, real_T runTimeOptions_ConstrRelTolFact, boolean_T
  updateFval)
{
  solution->iterations++;
  if ((solution->iterations >= 200) && ((solution->state != 1) ||
       (objective->objtype == 5))) {
    solution->state = 0;
  }

  if (solution->iterations - solution->iterations / 50 * 50 == 0) {
    solution->maxConstr = motion_c_maxConstraintViolation(workingset,
      solution->xstar);
    motion_controller_withPIC_B.tempMaxConstr = solution->maxConstr;
    if (objective->objtype == 5) {
      motion_controller_withPIC_B.tempMaxConstr = solution->maxConstr -
        solution->xstar[objective->nvar - 1];
    }

    if (motion_controller_withPIC_B.tempMaxConstr > 1.0E-8 *
        runTimeOptions_ConstrRelTolFact) {
      motion_controller_withPIC_B.e_tmp = static_cast<uint8_T>(objective->nvar);
      if (motion_controller_withPIC_B.e_tmp - 1 >= 0) {
        memcpy(&solution->searchDir[0], &solution->xstar[0],
               static_cast<uint32_T>(motion_controller_withPIC_B.e_tmp) * sizeof
               (real_T));
      }

      motion_controller_withPIC_B.nonDegenerateWset =
        motion__feasibleX0ForWorkingSet(memspace->workspace_double,
        solution->searchDir, workingset, qrmanager);
      if ((!motion_controller_withPIC_B.nonDegenerateWset) && (solution->state
           != 0)) {
        solution->state = -2;
      }

      *activeSetChangeID = 0;
      motion_controller_withPIC_B.tempMaxConstr =
        motion_c_maxConstraintViolation(workingset, solution->searchDir);
      if (motion_controller_withPIC_B.tempMaxConstr < solution->maxConstr) {
        if (motion_controller_withPIC_B.e_tmp - 1 >= 0) {
          memcpy(&solution->xstar[0], &solution->searchDir[0],
                 static_cast<uint32_T>(motion_controller_withPIC_B.e_tmp) *
                 sizeof(real_T));
        }

        solution->maxConstr = motion_controller_withPIC_B.tempMaxConstr;
      }
    }
  }

  if (updateFval) {
    solution->fstar = motion_cont_computeFval_ReuseHx(objective,
      memspace->workspace_double, f, solution->xstar);
    if ((solution->fstar < options_ObjectiveLimit) && ((solution->state != 0) ||
         (objective->objtype != 5))) {
      solution->state = 2;
    }
  }
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_controller_withP_iterate(const real_T H
  [1600], const real_T f[40], s5cJJO9CAPQxuVG0iaeiP4F_motio_T *solution,
  sFlCINAYeIgPgx0UwEHpaMF_motio_T *memspace, sT1ziU4p6vTWuD880X9yNJ_motion_T
  *workingset, s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager,
  s8kZFjDlzP6eNfOekUiP5MF_motio_T *cholmanager, sKnhLiTH4yv7eF1oV2a74RG_motio_T *
  objective, real_T options_ObjectiveLimit, real_T options_StepTolerance, real_T
  runTimeOptions_ConstrRelTolFact, real_T runTimeOptions_ProbRelTolFactor,
  boolean_T runTimeOptions_RemainFeasible)
{
  __m128d tmp;
  __m128d tmp_0;
  int32_T exitg1;
  boolean_T guard1;
  boolean_T guard11;
  boolean_T guard2;
  motion_controller_withPIC_B.subProblemChanged = true;
  motion_controller_withPIC_B.updateFval = true;
  motion_controller_withPIC_B.activeSetChangeID = 0;
  motion_controller_withPIC_B.TYPE = objective->objtype;
  motion_controller_withPIC_B.tolDelta = 6.7434957617430445E-7;
  motion_controller_withPIC_B.nVar_n = workingset->nVar;
  motion_controller_withPIC_B.globalActiveConstrIdx = 0;
  motion_cont_computeGrad_StoreHx(objective, H, f, solution->xstar);
  solution->fstar = motion_cont_computeFval_ReuseHx(objective,
    memspace->workspace_double, f, solution->xstar);
  if (solution->iterations < 200) {
    solution->state = -5;
  } else {
    solution->state = 0;
  }

  memset(&solution->lambda[0], 0, 161U * sizeof(real_T));
  do {
    exitg1 = 0;
    if (solution->state == -5) {
      guard11 = false;
      if (motion_controller_withPIC_B.subProblemChanged) {
        switch (motion_controller_withPIC_B.activeSetChangeID) {
         case 1:
          motion_controller_withPIC_B.Qk0 = (workingset->nActiveConstr - 1) * 41;
          if (qrmanager->mrows <= qrmanager->ncols + 1) {
            qrmanager->minRowCol = qrmanager->mrows;
          } else {
            qrmanager->minRowCol = qrmanager->ncols + 1;
          }

          motion_controller_withPIC_B.jjA = 41 * qrmanager->ncols;
          if (qrmanager->mrows != 0) {
            motion_controller_withPIC_B.iyend = motion_controller_withPIC_B.jjA
              + qrmanager->mrows;
            if (motion_controller_withPIC_B.jjA + 1 <=
                motion_controller_withPIC_B.iyend) {
              memset(&qrmanager->QR[motion_controller_withPIC_B.jjA], 0,
                     static_cast<uint32_T>(motion_controller_withPIC_B.iyend -
                      motion_controller_withPIC_B.jjA) * sizeof(real_T));
            }

            motion_controller_withPIC_B.i_f = (qrmanager->mrows - 1) * 41 + 1;
            for (motion_controller_withPIC_B.localActiveConstrIdx = 1;
                 motion_controller_withPIC_B.localActiveConstrIdx <=
                 motion_controller_withPIC_B.i_f;
                 motion_controller_withPIC_B.localActiveConstrIdx += 41) {
              motion_controller_withPIC_B.normDelta = 0.0;
              motion_controller_withPIC_B.d_ix =
                (motion_controller_withPIC_B.localActiveConstrIdx +
                 qrmanager->mrows) - 1;
              for (motion_controller_withPIC_B.iyend =
                   motion_controller_withPIC_B.localActiveConstrIdx;
                   motion_controller_withPIC_B.iyend <=
                   motion_controller_withPIC_B.d_ix;
                   motion_controller_withPIC_B.iyend++) {
                motion_controller_withPIC_B.normDelta += workingset->ATwset
                  [(motion_controller_withPIC_B.Qk0 +
                    motion_controller_withPIC_B.iyend) -
                  motion_controller_withPIC_B.localActiveConstrIdx] *
                  qrmanager->Q[motion_controller_withPIC_B.iyend - 1];
              }

              motion_controller_withPIC_B.d_ix = div_nde_s32_floor
                (motion_controller_withPIC_B.localActiveConstrIdx - 1, 41) +
                motion_controller_withPIC_B.jjA;
              qrmanager->QR[motion_controller_withPIC_B.d_ix] +=
                motion_controller_withPIC_B.normDelta;
            }
          }

          qrmanager->ncols++;
          qrmanager->jpvt[qrmanager->ncols - 1] = qrmanager->ncols;
          motion_controller_withPIC_B.iyend = qrmanager->mrows - 2;
          while (motion_controller_withPIC_B.iyend + 2 > qrmanager->ncols) {
            motion_controller_withPIC_B.localActiveConstrIdx = (qrmanager->ncols
              - 1) * 41 + motion_controller_withPIC_B.iyend;
            motion_controller_withPIC_B.temp_b = qrmanager->
              QR[motion_controller_withPIC_B.localActiveConstrIdx + 1];
            motion_controlle_xrotg_ds3XgDMS(&qrmanager->
              QR[motion_controller_withPIC_B.localActiveConstrIdx],
              &motion_controller_withPIC_B.temp_b,
              &motion_controller_withPIC_B.normDelta,
              &motion_controller_withPIC_B.s_hz);
            qrmanager->QR[motion_controller_withPIC_B.localActiveConstrIdx + 1] =
              motion_controller_withPIC_B.temp_b;
            motion_controller_withPIC_B.Qk0 = 41 *
              motion_controller_withPIC_B.iyend;
            motion_controller_withPIC_B.jjA = qrmanager->mrows;
            if (qrmanager->mrows >= 1) {
              for (motion_controller_withPIC_B.localActiveConstrIdx = 0;
                   motion_controller_withPIC_B.localActiveConstrIdx <
                   motion_controller_withPIC_B.jjA;
                   motion_controller_withPIC_B.localActiveConstrIdx++) {
                motion_controller_withPIC_B.d_ix =
                  motion_controller_withPIC_B.Qk0 +
                  motion_controller_withPIC_B.localActiveConstrIdx;
                motion_controller_withPIC_B.temp_tmp = qrmanager->
                  Q[motion_controller_withPIC_B.d_ix + 41];
                motion_controller_withPIC_B.temp_b =
                  motion_controller_withPIC_B.temp_tmp *
                  motion_controller_withPIC_B.s_hz + qrmanager->
                  Q[motion_controller_withPIC_B.d_ix] *
                  motion_controller_withPIC_B.normDelta;
                qrmanager->Q[motion_controller_withPIC_B.d_ix + 41] =
                  motion_controller_withPIC_B.temp_tmp *
                  motion_controller_withPIC_B.normDelta - qrmanager->
                  Q[motion_controller_withPIC_B.d_ix] *
                  motion_controller_withPIC_B.s_hz;
                qrmanager->Q[motion_controller_withPIC_B.d_ix] =
                  motion_controller_withPIC_B.temp_b;
              }
            }

            motion_controller_withPIC_B.iyend--;
          }
          break;

         case -1:
          motion_control_deleteColMoveEnd(qrmanager,
            motion_controller_withPIC_B.globalActiveConstrIdx);
          break;

         default:
          motion_controller_with_factorQR(qrmanager, workingset->ATwset,
            motion_controller_withPIC_B.nVar_n, workingset->nActiveConstr);
          motion_controller_wit_computeQ_(qrmanager, qrmanager->mrows);
          break;
        }

        motion_controlle_compute_deltax(H, solution, memspace, qrmanager,
          cholmanager, objective);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          motion_controller_withPIC_B.normDelta =
            motion_controlle_xnrm2_DlmxxpnG(motion_controller_withPIC_B.nVar_n,
            solution->searchDir);
          guard11 = true;
        }
      } else {
        motion_controller_withPIC_B.iyend = static_cast<uint8_T>
          (motion_controller_withPIC_B.nVar_n);
        memset(&solution->searchDir[0], 0, static_cast<uint32_T>
               (motion_controller_withPIC_B.iyend) * sizeof(real_T));
        motion_controller_withPIC_B.normDelta = 0.0;
        guard11 = true;
      }

      if (guard11) {
        if ((!motion_controller_withPIC_B.subProblemChanged) ||
            (motion_controller_withPIC_B.normDelta < options_StepTolerance) ||
            (workingset->nActiveConstr >= motion_controller_withPIC_B.nVar_n)) {
          motion_controller_withPIC_B.localActiveConstrIdx = qrmanager->ncols;
          if (qrmanager->ncols > 0) {
            guard1 = false;
            if (objective->objtype != 4) {
              motion_controller_withPIC_B.normDelta = 100.0 * static_cast<real_T>
                (qrmanager->mrows) * 2.2204460492503131E-16;
              motion_controller_withPIC_B.updateFval = ((qrmanager->mrows > 0) &&
                (qrmanager->ncols > 0));
              if (motion_controller_withPIC_B.updateFval) {
                motion_controller_withPIC_B.iyend = qrmanager->ncols;
                guard2 = false;
                if (qrmanager->mrows < qrmanager->ncols) {
                  motion_controller_withPIC_B.Qk0 = (qrmanager->ncols - 1) * 41
                    + qrmanager->mrows;
                  while ((motion_controller_withPIC_B.iyend > qrmanager->mrows) &&
                         (fabs(qrmanager->QR[motion_controller_withPIC_B.Qk0 - 1])
                          >= motion_controller_withPIC_B.normDelta)) {
                    motion_controller_withPIC_B.iyend--;
                    motion_controller_withPIC_B.Qk0 -= 41;
                  }

                  motion_controller_withPIC_B.updateFval =
                    (motion_controller_withPIC_B.iyend == qrmanager->mrows);
                  if (!motion_controller_withPIC_B.updateFval) {
                  } else {
                    guard2 = true;
                  }
                } else {
                  guard2 = true;
                }

                if (guard2) {
                  motion_controller_withPIC_B.Qk0 =
                    (motion_controller_withPIC_B.iyend - 1) * 41 +
                    motion_controller_withPIC_B.iyend;
                  while ((motion_controller_withPIC_B.iyend >= 1) && (fabs
                          (qrmanager->QR[motion_controller_withPIC_B.Qk0 - 1]) >=
                          motion_controller_withPIC_B.normDelta)) {
                    motion_controller_withPIC_B.iyend--;
                    motion_controller_withPIC_B.Qk0 -= 42;
                  }

                  motion_controller_withPIC_B.updateFval =
                    (motion_controller_withPIC_B.iyend == 0);
                }
              }

              if (!motion_controller_withPIC_B.updateFval) {
                solution->state = -7;
              } else {
                guard1 = true;
              }
            } else {
              guard1 = true;
            }

            if (guard1) {
              if (qrmanager->mrows != 0) {
                motion_controller_withPIC_B.Qk0 = qrmanager->ncols;
                memset(&memspace->workspace_double[0], 0, static_cast<uint32_T>
                       (motion_controller_withPIC_B.Qk0) * sizeof(real_T));
                motion_controller_withPIC_B.jjA = (qrmanager->ncols - 1) * 41 +
                  1;
                for (motion_controller_withPIC_B.iyend = 1;
                     motion_controller_withPIC_B.iyend <=
                     motion_controller_withPIC_B.jjA;
                     motion_controller_withPIC_B.iyend += 41) {
                  motion_controller_withPIC_B.normDelta = 0.0;
                  motion_controller_withPIC_B.d_ix =
                    (motion_controller_withPIC_B.iyend + qrmanager->mrows) - 1;
                  for (motion_controller_withPIC_B.Qk0 =
                       motion_controller_withPIC_B.iyend;
                       motion_controller_withPIC_B.Qk0 <=
                       motion_controller_withPIC_B.d_ix;
                       motion_controller_withPIC_B.Qk0++) {
                    motion_controller_withPIC_B.normDelta += qrmanager->
                      Q[motion_controller_withPIC_B.Qk0 - 1] * objective->
                      grad[motion_controller_withPIC_B.Qk0 -
                      motion_controller_withPIC_B.iyend];
                  }

                  motion_controller_withPIC_B.d_ix = div_nde_s32_floor
                    (motion_controller_withPIC_B.iyend - 1, 41);
                  memspace->workspace_double[motion_controller_withPIC_B.d_ix] +=
                    motion_controller_withPIC_B.normDelta;
                }
              }

              for (motion_controller_withPIC_B.iyend =
                   motion_controller_withPIC_B.localActiveConstrIdx;
                   motion_controller_withPIC_B.iyend >= 1;
                   motion_controller_withPIC_B.iyend--) {
                motion_controller_withPIC_B.jjA =
                  ((motion_controller_withPIC_B.iyend - 1) * 41 +
                   motion_controller_withPIC_B.iyend) - 2;
                memspace->workspace_double[motion_controller_withPIC_B.iyend - 1]
                  /= qrmanager->QR[motion_controller_withPIC_B.jjA + 1];
                for (motion_controller_withPIC_B.Qk0 = 0;
                     motion_controller_withPIC_B.Qk0 <=
                     motion_controller_withPIC_B.iyend - 2;
                     motion_controller_withPIC_B.Qk0++) {
                  motion_controller_withPIC_B.d_ix =
                    (motion_controller_withPIC_B.iyend -
                     motion_controller_withPIC_B.Qk0) - 2;
                  memspace->workspace_double[motion_controller_withPIC_B.d_ix] -=
                    memspace->workspace_double[motion_controller_withPIC_B.iyend
                    - 1] * qrmanager->QR[motion_controller_withPIC_B.jjA -
                    motion_controller_withPIC_B.Qk0];
                }
              }

              motion_controller_withPIC_B.Qk0 = (qrmanager->ncols / 2) << 1;
              motion_controller_withPIC_B.jjA = motion_controller_withPIC_B.Qk0
                - 2;
              for (motion_controller_withPIC_B.iyend = 0;
                   motion_controller_withPIC_B.iyend <=
                   motion_controller_withPIC_B.jjA;
                   motion_controller_withPIC_B.iyend += 2) {
                tmp = _mm_loadu_pd(&memspace->
                                   workspace_double[motion_controller_withPIC_B.iyend]);
                _mm_storeu_pd(&solution->
                              lambda[motion_controller_withPIC_B.iyend],
                              _mm_mul_pd(tmp, _mm_set1_pd(-1.0)));
              }

              for (motion_controller_withPIC_B.iyend =
                   motion_controller_withPIC_B.Qk0;
                   motion_controller_withPIC_B.iyend <
                   motion_controller_withPIC_B.localActiveConstrIdx;
                   motion_controller_withPIC_B.iyend++) {
                solution->lambda[motion_controller_withPIC_B.iyend] =
                  -memspace->workspace_double[motion_controller_withPIC_B.iyend];
              }
            }
          }

          if ((solution->state != -7) || (workingset->nActiveConstr >
               motion_controller_withPIC_B.nVar_n)) {
            motion_controller_withPIC_B.iyend = 0;
            motion_controller_withPIC_B.normDelta = 0.0 *
              runTimeOptions_ProbRelTolFactor * static_cast<real_T>
              (motion_controller_withPIC_B.TYPE != 5);
            motion_controller_withPIC_B.Qk0 = (workingset->nWConstr[0] +
              workingset->nWConstr[1]) + 1;
            motion_controller_withPIC_B.jjA = workingset->nActiveConstr;
            for (motion_controller_withPIC_B.localActiveConstrIdx =
                 motion_controller_withPIC_B.Qk0;
                 motion_controller_withPIC_B.localActiveConstrIdx <=
                 motion_controller_withPIC_B.jjA;
                 motion_controller_withPIC_B.localActiveConstrIdx++) {
              motion_controller_withPIC_B.s_hz = solution->
                lambda[motion_controller_withPIC_B.localActiveConstrIdx - 1];
              if (motion_controller_withPIC_B.s_hz <
                  motion_controller_withPIC_B.normDelta) {
                motion_controller_withPIC_B.normDelta =
                  motion_controller_withPIC_B.s_hz;
                motion_controller_withPIC_B.iyend =
                  motion_controller_withPIC_B.localActiveConstrIdx;
              }
            }

            if (motion_controller_withPIC_B.iyend == 0) {
              solution->state = 1;
            } else {
              motion_controller_withPIC_B.activeSetChangeID = -1;
              motion_controller_withPIC_B.globalActiveConstrIdx =
                motion_controller_withPIC_B.iyend;
              motion_controller_withPIC_B.subProblemChanged = true;
              motion_controller__removeConstr(workingset,
                motion_controller_withPIC_B.iyend);
              solution->lambda[motion_controller_withPIC_B.iyend - 1] = 0.0;
            }
          } else {
            motion_controller_withPIC_B.iyend = workingset->nActiveConstr;
            motion_controller_withPIC_B.activeSetChangeID = 0;
            motion_controller_withPIC_B.globalActiveConstrIdx =
              workingset->nActiveConstr;
            motion_controller_withPIC_B.subProblemChanged = true;
            motion_controller__removeConstr(workingset,
              workingset->nActiveConstr);
            solution->lambda[motion_controller_withPIC_B.iyend - 1] = 0.0;
          }

          motion_controller_withPIC_B.updateFval = false;
        } else {
          motion_controller_withPIC_B.updateFval =
            (motion_controller_withPIC_B.TYPE == 5);
          if (motion_controller_withPIC_B.updateFval ||
              runTimeOptions_RemainFeasible) {
            motion_contro_feasibleratiotest(solution->xstar, solution->searchDir,
              memspace->workspace_double, workingset->nVar, workingset->Aineq,
              workingset->bineq, workingset->lb, workingset->ub,
              workingset->indexLB, workingset->indexUB, workingset->sizes,
              workingset->isActiveIdx, workingset->isActiveConstr,
              workingset->nWConstr, motion_controller_withPIC_B.updateFval,
              &motion_controller_withPIC_B.normDelta,
              &motion_controller_withPIC_B.newBlocking,
              &motion_controller_withPIC_B.iyend,
              &motion_controller_withPIC_B.localActiveConstrIdx);
          } else {
            motion_controller_wit_ratiotest(solution->xstar, solution->searchDir,
              memspace->workspace_double, workingset->nVar, workingset->Aineq,
              workingset->bineq, workingset->lb, workingset->ub,
              workingset->indexLB, workingset->indexUB, workingset->sizes,
              workingset->isActiveIdx, workingset->isActiveConstr,
              workingset->nWConstr, &motion_controller_withPIC_B.tolDelta,
              &motion_controller_withPIC_B.normDelta,
              &motion_controller_withPIC_B.newBlocking,
              &motion_controller_withPIC_B.iyend,
              &motion_controller_withPIC_B.localActiveConstrIdx);
          }

          if (motion_controller_withPIC_B.newBlocking) {
            switch (motion_controller_withPIC_B.iyend) {
             case 3:
              workingset->nWConstr[2]++;
              workingset->isActiveConstr[(workingset->isActiveIdx[2] +
                motion_controller_withPIC_B.localActiveConstrIdx) - 2] = true;
              workingset->nActiveConstr++;
              workingset->Wid[workingset->nActiveConstr - 1] = 3;
              workingset->Wlocalidx[workingset->nActiveConstr - 1] =
                motion_controller_withPIC_B.localActiveConstrIdx;
              motion_controller_withPIC_B.iyend =
                (motion_controller_withPIC_B.localActiveConstrIdx - 1) * 41;
              motion_controller_withPIC_B.Qk0 = (workingset->nActiveConstr - 1) *
                41;
              motion_controller_withPIC_B.jjA = workingset->nVar - 1;
              for (motion_controller_withPIC_B.activeSetChangeID = 0;
                   motion_controller_withPIC_B.activeSetChangeID <=
                   motion_controller_withPIC_B.jjA;
                   motion_controller_withPIC_B.activeSetChangeID++) {
                workingset->ATwset[motion_controller_withPIC_B.Qk0 +
                  motion_controller_withPIC_B.activeSetChangeID] =
                  workingset->Aineq[motion_controller_withPIC_B.iyend +
                  motion_controller_withPIC_B.activeSetChangeID];
              }

              workingset->bwset[workingset->nActiveConstr - 1] =
                workingset->
                bineq[motion_controller_withPIC_B.localActiveConstrIdx - 1];
              break;

             case 4:
              moti_addBoundToActiveSetMatrix_(workingset, 4,
                motion_controller_withPIC_B.localActiveConstrIdx);
              break;

             default:
              moti_addBoundToActiveSetMatrix_(workingset, 5,
                motion_controller_withPIC_B.localActiveConstrIdx);
              break;
            }

            motion_controller_withPIC_B.activeSetChangeID = 1;
          } else {
            if (objective->objtype == 5) {
              if (motion_controlle_xnrm2_DlmxxpnG(objective->nvar,
                   solution->searchDir) > 100.0 * static_cast<real_T>
                  (objective->nvar) * 1.4901161193847656E-8) {
                solution->state = 3;
              } else {
                solution->state = 4;
              }
            }

            motion_controller_withPIC_B.subProblemChanged = false;
            if (workingset->nActiveConstr == 0) {
              solution->state = 1;
            }
          }

          if (!(motion_controller_withPIC_B.normDelta == 0.0)) {
            motion_controller_withPIC_B.Qk0 =
              (motion_controller_withPIC_B.nVar_n / 2) << 1;
            motion_controller_withPIC_B.jjA = motion_controller_withPIC_B.Qk0 -
              2;
            for (motion_controller_withPIC_B.localActiveConstrIdx = 0;
                 motion_controller_withPIC_B.localActiveConstrIdx <=
                 motion_controller_withPIC_B.jjA;
                 motion_controller_withPIC_B.localActiveConstrIdx += 2) {
              tmp = _mm_loadu_pd(&solution->
                                 searchDir[motion_controller_withPIC_B.localActiveConstrIdx]);
              tmp_0 = _mm_loadu_pd(&solution->
                                   xstar[motion_controller_withPIC_B.localActiveConstrIdx]);
              _mm_storeu_pd(&solution->
                            xstar[motion_controller_withPIC_B.localActiveConstrIdx],
                            _mm_add_pd(_mm_mul_pd(_mm_set1_pd
                (motion_controller_withPIC_B.normDelta), tmp), tmp_0));
            }

            for (motion_controller_withPIC_B.localActiveConstrIdx =
                 motion_controller_withPIC_B.Qk0;
                 motion_controller_withPIC_B.localActiveConstrIdx <
                 motion_controller_withPIC_B.nVar_n;
                 motion_controller_withPIC_B.localActiveConstrIdx++) {
              solution->xstar[motion_controller_withPIC_B.localActiveConstrIdx] +=
                motion_controller_withPIC_B.normDelta * solution->
                searchDir[motion_controller_withPIC_B.localActiveConstrIdx];
            }
          }

          motion_cont_computeGrad_StoreHx(objective, H, f, solution->xstar);
          motion_controller_withPIC_B.updateFval = true;
        }

        moti_checkStoppingAndUpdateFval
          (&motion_controller_withPIC_B.activeSetChangeID, f, solution, memspace,
           objective, workingset, qrmanager, options_ObjectiveLimit,
           runTimeOptions_ConstrRelTolFact,
           motion_controller_withPIC_B.updateFval);
      }
    } else {
      if (!motion_controller_withPIC_B.updateFval) {
        solution->fstar = motion_cont_computeFval_ReuseHx(objective,
          memspace->workspace_double, f, solution->xstar);
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_controller_with_phaseone(const real_T H
  [1600], const real_T f[40], s5cJJO9CAPQxuVG0iaeiP4F_motio_T *solution,
  sFlCINAYeIgPgx0UwEHpaMF_motio_T *memspace, sT1ziU4p6vTWuD880X9yNJ_motion_T
  *workingset, s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager,
  s8kZFjDlzP6eNfOekUiP5MF_motio_T *cholmanager, sSOeZ9WO10chPn9Si6PKiCB_motio_T *
  options, const sL9bDKomAYkxZSVrG9w6En_motion_T *runTimeOptions,
  sKnhLiTH4yv7eF1oV2a74RG_motio_T *objective)
{
  boolean_T exitg1;
  motion_controller_withPIC_B.nVar_j = workingset->nVar;
  solution->xstar[40] = solution->maxConstr + 1.0;
  motion_controlle_setProblemType(workingset, 1);
  motion_controller_withPIC_B.idxStartIneq_tmp_n = workingset->nWConstr[0] +
    workingset->nWConstr[1];
  motion_controller_withPIC_B.idxStartIneq_p =
    motion_controller_withPIC_B.idxStartIneq_tmp_n + 1;
  motion_controller_withPIC_B.idxEndIneq_b = workingset->nActiveConstr;
  for (motion_controller_withPIC_B.i_p =
       motion_controller_withPIC_B.idxStartIneq_p;
       motion_controller_withPIC_B.i_p <=
       motion_controller_withPIC_B.idxEndIneq_b; motion_controller_withPIC_B.i_p
       ++) {
    workingset->isActiveConstr[(workingset->isActiveIdx[workingset->
      Wid[motion_controller_withPIC_B.i_p - 1] - 1] + workingset->
      Wlocalidx[motion_controller_withPIC_B.i_p - 1]) - 2] = false;
  }

  workingset->nWConstr[2] = 0;
  workingset->nWConstr[3] = 0;
  workingset->nWConstr[4] = 0;
  workingset->nActiveConstr = motion_controller_withPIC_B.idxStartIneq_tmp_n;
  memset(&objective->grad[0], 0, 41U * sizeof(real_T));
  memset(&objective->Hx[0], 0, 40U * sizeof(real_T));
  objective->maxVar = 41;
  objective->beta = 0.0;
  objective->rho = 0.0;
  objective->prev_objtype = 3;
  objective->prev_nvar = 40;
  objective->prev_hasLinear = true;
  objective->objtype = 5;
  objective->nvar = 41;
  objective->gammaScalar = 1.0;
  objective->hasLinear = true;
  options->ObjectiveLimit = 1.0E-8 * runTimeOptions->ConstrRelTolFactor;
  options->StepTolerance = 1.4901161193847657E-10;
  solution->fstar = motion_controller_w_computeFval(objective,
    memspace->workspace_double, H, f, solution->xstar);
  solution->state = 5;
  motion_controller_withP_iterate(H, f, solution, memspace, workingset,
    qrmanager, cholmanager, objective, options->ObjectiveLimit,
    options->StepTolerance, runTimeOptions->ConstrRelTolFactor,
    runTimeOptions->ProbRelTolFactor, runTimeOptions->RemainFeasible);
  if (workingset->isActiveConstr[(workingset->isActiveIdx[3] + workingset->
       sizes[3]) - 2]) {
    motion_controller_withPIC_B.i_p = workingset->sizes[0];
    exitg1 = false;
    while ((!exitg1) && (motion_controller_withPIC_B.i_p + 1 <=
                         workingset->nActiveConstr)) {
      if ((workingset->Wid[motion_controller_withPIC_B.i_p] == 4) &&
          (workingset->Wlocalidx[motion_controller_withPIC_B.i_p] ==
           workingset->sizes[3])) {
        motion_controller__removeConstr(workingset,
          motion_controller_withPIC_B.i_p + 1);
        exitg1 = true;
      } else {
        motion_controller_withPIC_B.i_p++;
      }
    }
  }

  motion_controller_withPIC_B.i_p = workingset->nActiveConstr;
  while ((motion_controller_withPIC_B.i_p > workingset->sizes[0]) &&
         (motion_controller_withPIC_B.i_p > motion_controller_withPIC_B.nVar_j))
  {
    motion_controller__removeConstr(workingset, motion_controller_withPIC_B.i_p);
    motion_controller_withPIC_B.i_p--;
  }

  solution->maxConstr = solution->xstar[40];
  motion_controlle_setProblemType(workingset, 3);
  objective->objtype = objective->prev_objtype;
  objective->nvar = objective->prev_nvar;
  objective->hasLinear = objective->prev_hasLinear;
  options->ObjectiveLimit = -1.0E+20;
  options->StepTolerance = 1.0E-8;
}

// Function for MATLAB Function: '<S62>/solvex'
int32_T motion_controller_withPIC::motion_con_RemoveDependentEq__j
  (sFlCINAYeIgPgx0UwEHpaMF_motio_T *memspace, sT1ziU4p6vTWuD880X9yNJ_motion_T
   *workingset, s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager)
{
  int32_T nDepInd;
  motion_controller_withPIC_B.mWorkingFixed = workingset->nWConstr[0];
  motion_controller_withPIC_B.mTotalWorkingEq = workingset->nWConstr[0] +
    workingset->nWConstr[1];
  nDepInd = 0;
  if (motion_controller_withPIC_B.mTotalWorkingEq > 0) {
    motion_controller_withPIC_B.b_tmp = static_cast<uint8_T>(workingset->nVar);
    for (motion_controller_withPIC_B.idx_row = 0;
         motion_controller_withPIC_B.idx_row <
         motion_controller_withPIC_B.mTotalWorkingEq;
         motion_controller_withPIC_B.idx_row++) {
      for (motion_controller_withPIC_B.idx_col = 0;
           motion_controller_withPIC_B.idx_col <
           motion_controller_withPIC_B.b_tmp;
           motion_controller_withPIC_B.idx_col++) {
        qrmanager->QR[motion_controller_withPIC_B.idx_row + 41 *
          motion_controller_withPIC_B.idx_col] = workingset->ATwset[41 *
          motion_controller_withPIC_B.idx_row +
          motion_controller_withPIC_B.idx_col];
      }
    }

    nDepInd = motion_c_ComputeNumDependentEq_(qrmanager, workingset->bwset,
      motion_controller_withPIC_B.mTotalWorkingEq, workingset->nVar);
    if (nDepInd > 0) {
      for (motion_controller_withPIC_B.idx_row = 0;
           motion_controller_withPIC_B.idx_row <
           motion_controller_withPIC_B.mTotalWorkingEq;
           motion_controller_withPIC_B.idx_row++) {
        motion_controller_withPIC_B.idx_col = 41 *
          motion_controller_withPIC_B.idx_row;
        memcpy(&qrmanager->QR[motion_controller_withPIC_B.idx_col],
               &workingset->ATwset[motion_controller_withPIC_B.idx_col],
               static_cast<uint32_T>((motion_controller_withPIC_B.b_tmp +
                 motion_controller_withPIC_B.idx_col) -
                motion_controller_withPIC_B.idx_col) * sizeof(real_T));
      }

      for (motion_controller_withPIC_B.idx_row = 0;
           motion_controller_withPIC_B.idx_row <
           motion_controller_withPIC_B.mWorkingFixed;
           motion_controller_withPIC_B.idx_row++) {
        qrmanager->jpvt[motion_controller_withPIC_B.idx_row] = 1;
      }

      motion_controller_withPIC_B.idx_row = workingset->nWConstr[0] + 1;
      if (motion_controller_withPIC_B.idx_row <=
          motion_controller_withPIC_B.mTotalWorkingEq) {
        memset(&qrmanager->jpvt[motion_controller_withPIC_B.idx_row + -1], 0,
               static_cast<uint32_T>
               ((motion_controller_withPIC_B.mTotalWorkingEq -
                 motion_controller_withPIC_B.idx_row) + 1) * sizeof(int32_T));
      }

      motion_controller_wit_factorQRE(qrmanager, workingset->nVar,
        motion_controller_withPIC_B.mTotalWorkingEq);
      for (motion_controller_withPIC_B.mWorkingFixed = 0;
           motion_controller_withPIC_B.mWorkingFixed < nDepInd;
           motion_controller_withPIC_B.mWorkingFixed++) {
        memspace->workspace_int[motion_controller_withPIC_B.mWorkingFixed] =
          qrmanager->jpvt[(motion_controller_withPIC_B.mTotalWorkingEq - nDepInd)
          + motion_controller_withPIC_B.mWorkingFixed];
      }

      countsort_Ormz6pKD(memspace->workspace_int, nDepInd,
                         memspace->workspace_sort, 1,
                         motion_controller_withPIC_B.mTotalWorkingEq);
      for (motion_controller_withPIC_B.mTotalWorkingEq = nDepInd;
           motion_controller_withPIC_B.mTotalWorkingEq >= 1;
           motion_controller_withPIC_B.mTotalWorkingEq--) {
        motion_controlle_removeEqConstr(workingset, memspace->
          workspace_int[motion_controller_withPIC_B.mTotalWorkingEq - 1]);
      }
    }
  }

  return nDepInd;
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_con_PresolveWorkingSet_g
  (s5cJJO9CAPQxuVG0iaeiP4F_motio_T *solution, sFlCINAYeIgPgx0UwEHpaMF_motio_T
   *memspace, sT1ziU4p6vTWuD880X9yNJ_motion_T *workingset,
   s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager)
{
  boolean_T guard1;
  solution->state = 82;
  motion_controller_withPIC_B.b_a = motion_con_RemoveDependentEq__j(memspace,
    workingset, qrmanager);
  if ((motion_controller_withPIC_B.b_a != -1) && (workingset->nActiveConstr <=
       41)) {
    motion_con_RemoveDependentIneq_(workingset, qrmanager, memspace, 100.0);
    motion_controller_withPIC_B.okWorkingSet = motion__feasibleX0ForWorkingSet
      (memspace->workspace_double, solution->xstar, workingset, qrmanager);
    guard1 = false;
    if (!motion_controller_withPIC_B.okWorkingSet) {
      motion_con_RemoveDependentIneq_(workingset, qrmanager, memspace, 1000.0);
      motion_controller_withPIC_B.okWorkingSet = motion__feasibleX0ForWorkingSet
        (memspace->workspace_double, solution->xstar, workingset, qrmanager);
      if (!motion_controller_withPIC_B.okWorkingSet) {
        solution->state = -7;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      if (workingset->nWConstr[0] + workingset->nWConstr[1] == workingset->nVar)
      {
        motion_controller_withPIC_B.constrViolation =
          motion_c_maxConstraintViolation(workingset, solution->xstar);
        if (motion_controller_withPIC_B.constrViolation > 1.0E-8) {
          solution->state = -2;
        }
      }
    }
  } else {
    solution->state = -3;
    motion_controller_withPIC_B.idxStartIneq_tmp = workingset->nWConstr[0] +
      workingset->nWConstr[1];
    motion_controller_withPIC_B.idxStartIneq =
      motion_controller_withPIC_B.idxStartIneq_tmp + 1;
    motion_controller_withPIC_B.idxEndIneq = workingset->nActiveConstr;
    for (motion_controller_withPIC_B.b_a =
         motion_controller_withPIC_B.idxStartIneq;
         motion_controller_withPIC_B.b_a <=
         motion_controller_withPIC_B.idxEndIneq; motion_controller_withPIC_B.b_a
         ++) {
      workingset->isActiveConstr[(workingset->isActiveIdx[workingset->
        Wid[motion_controller_withPIC_B.b_a - 1] - 1] + workingset->
        Wlocalidx[motion_controller_withPIC_B.b_a - 1]) - 2] = false;
    }

    workingset->nWConstr[2] = 0;
    workingset->nWConstr[3] = 0;
    workingset->nWConstr[4] = 0;
    workingset->nActiveConstr = motion_controller_withPIC_B.idxStartIneq_tmp;
  }
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_con_computeFirstOrderOpt
  (s5cJJO9CAPQxuVG0iaeiP4F_motio_T *solution, const
   sKnhLiTH4yv7eF1oV2a74RG_motio_T *objective, int32_T workingset_nVar, const
   real_T workingset_ATwset[6601], int32_T workingset_nActiveConstr, real_T
   workspace[6601])
{
  real_T infNorm;
  int32_T k;
  boolean_T exitg1;
  memcpy(&workspace[0], &objective->grad[0], static_cast<uint8_T>
         (workingset_nVar) * sizeof(real_T));
  if (workingset_nActiveConstr != 0) {
    int32_T c;
    int32_T ix;
    ix = 0;
    c = (workingset_nActiveConstr - 1) * 41 + 1;
    for (k = 1; k <= c; k += 41) {
      int32_T d;
      d = (k + workingset_nVar) - 1;
      for (int32_T b = k; b <= d; b++) {
        int32_T tmp;
        tmp = b - k;
        workspace[tmp] += workingset_ATwset[b - 1] * solution->lambda[ix];
      }

      ix++;
    }
  }

  infNorm = 0.0;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= static_cast<uint8_T>(workingset_nVar) - 1)) {
    real_T abs_workspace_i;
    abs_workspace_i = fabs(workspace[k]);
    if (rtIsNaN(abs_workspace_i)) {
      infNorm = (rtNaN);
      exitg1 = true;
    } else {
      if (!(infNorm >= abs_workspace_i)) {
        infNorm = abs_workspace_i;
      }

      k++;
    }
  }

  solution->firstorderopt = infNorm;
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_controller_wi_phaseone_e(const real_T H
  [1600], const real_T f[40], s5cJJO9CAPQxuVG0iaeiP4F_motio_T *solution,
  sFlCINAYeIgPgx0UwEHpaMF_motio_T *memspace, sT1ziU4p6vTWuD880X9yNJ_motion_T
  *workingset, s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager,
  s8kZFjDlzP6eNfOekUiP5MF_motio_T *cholmanager, sKnhLiTH4yv7eF1oV2a74RG_motio_T *
  objective, sSOeZ9WO10chPn9Si6PKiCB_motio_T *options, const
  sL9bDKomAYkxZSVrG9w6En_motion_T *runTimeOptions)
{
  boolean_T exitg1;
  motion_controller_withPIC_B.PROBTYPE_ORIG = workingset->probType;
  motion_controller_withPIC_B.nVar_l = workingset->nVar;
  solution->xstar[40] = solution->maxConstr + 1.0;
  if (workingset->probType == 3) {
    motion_controller_withPIC_B.mConstr_h = 1;
  } else {
    motion_controller_withPIC_B.mConstr_h = 4;
  }

  motion_controlle_setProblemType(workingset,
    motion_controller_withPIC_B.mConstr_h);
  motion_controller_withPIC_B.idxStartIneq_tmp_e = workingset->nWConstr[0] +
    workingset->nWConstr[1];
  motion_controller_withPIC_B.idxStartIneq_c =
    motion_controller_withPIC_B.idxStartIneq_tmp_e + 1;
  motion_controller_withPIC_B.idxEndIneq_g0 = workingset->nActiveConstr;
  for (motion_controller_withPIC_B.mConstr_h =
       motion_controller_withPIC_B.idxStartIneq_c;
       motion_controller_withPIC_B.mConstr_h <=
       motion_controller_withPIC_B.idxEndIneq_g0;
       motion_controller_withPIC_B.mConstr_h++) {
    workingset->isActiveConstr[(workingset->isActiveIdx[workingset->
      Wid[motion_controller_withPIC_B.mConstr_h - 1] - 1] +
      workingset->Wlocalidx[motion_controller_withPIC_B.mConstr_h - 1]) - 2] =
      false;
  }

  workingset->nWConstr[2] = 0;
  workingset->nWConstr[3] = 0;
  workingset->nWConstr[4] = 0;
  workingset->nActiveConstr = motion_controller_withPIC_B.idxStartIneq_tmp_e;
  objective->prev_objtype = objective->objtype;
  objective->prev_nvar = objective->nvar;
  objective->prev_hasLinear = objective->hasLinear;
  objective->objtype = 5;
  objective->nvar = 41;
  objective->gammaScalar = 1.0;
  objective->hasLinear = true;
  options->ObjectiveLimit = 1.0E-8 * runTimeOptions->ConstrRelTolFactor;
  options->StepTolerance = 1.4901161193847657E-10;
  solution->fstar = motion_controller_w_computeFval(objective,
    memspace->workspace_double, H, f, solution->xstar);
  solution->state = 5;
  motion_controller_withP_iterate(H, f, solution, memspace, workingset,
    qrmanager, cholmanager, objective, options->ObjectiveLimit,
    options->StepTolerance, runTimeOptions->ConstrRelTolFactor,
    runTimeOptions->ProbRelTolFactor, runTimeOptions->RemainFeasible);
  if (workingset->isActiveConstr[(workingset->isActiveIdx[3] + workingset->
       sizes[3]) - 2]) {
    motion_controller_withPIC_B.mConstr_h = workingset->sizes[0];
    exitg1 = false;
    while ((!exitg1) && (motion_controller_withPIC_B.mConstr_h + 1 <=
                         workingset->nActiveConstr)) {
      if ((workingset->Wid[motion_controller_withPIC_B.mConstr_h] == 4) &&
          (workingset->Wlocalidx[motion_controller_withPIC_B.mConstr_h] ==
           workingset->sizes[3])) {
        motion_controller__removeConstr(workingset,
          motion_controller_withPIC_B.mConstr_h + 1);
        exitg1 = true;
      } else {
        motion_controller_withPIC_B.mConstr_h++;
      }
    }
  }

  motion_controller_withPIC_B.mConstr_h = workingset->nActiveConstr;
  while ((motion_controller_withPIC_B.mConstr_h > workingset->sizes[0]) &&
         (motion_controller_withPIC_B.mConstr_h >
          motion_controller_withPIC_B.nVar_l)) {
    motion_controller__removeConstr(workingset,
      motion_controller_withPIC_B.mConstr_h);
    motion_controller_withPIC_B.mConstr_h--;
  }

  solution->maxConstr = solution->xstar[40];
  motion_controlle_setProblemType(workingset,
    motion_controller_withPIC_B.PROBTYPE_ORIG);
  objective->objtype = objective->prev_objtype;
  objective->nvar = objective->prev_nvar;
  objective->hasLinear = objective->prev_hasLinear;
  options->ObjectiveLimit = -1.0E+20;
  options->StepTolerance = 1.0E-8;
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_controller_withPI_driver(const real_T H
  [1600], const real_T f[40], s5cJJO9CAPQxuVG0iaeiP4F_motio_T *solution,
  sFlCINAYeIgPgx0UwEHpaMF_motio_T *memspace, sT1ziU4p6vTWuD880X9yNJ_motion_T
  *workingset, s8kZFjDlzP6eNfOekUiP5MF_motio_T *cholmanager,
  sSOeZ9WO10chPn9Si6PKiCB_motio_T *options, sL9bDKomAYkxZSVrG9w6En_motion_T
  runTimeOptions, s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager,
  sKnhLiTH4yv7eF1oV2a74RG_motio_T *objective)
{
  boolean_T guard1;
  memset(&objective->grad[0], 0, 41U * sizeof(real_T));
  memset(&objective->Hx[0], 0, 40U * sizeof(real_T));
  objective->hasLinear = true;
  objective->nvar = 40;
  objective->maxVar = 41;
  objective->beta = 0.0;
  objective->rho = 0.0;
  objective->objtype = 3;
  objective->prev_objtype = 3;
  objective->prev_nvar = 0;
  objective->prev_hasLinear = false;
  objective->gammaScalar = 0.0;
  solution->iterations = 0;
  runTimeOptions.RemainFeasible = true;
  motion_controller_withPIC_B.i_j = workingset->nVar;
  motion_controller_withPIC_B.c_n = static_cast<uint8_T>(workingset->sizes[0]);
  for (motion_controller_withPIC_B.idx = 0; motion_controller_withPIC_B.idx <
       motion_controller_withPIC_B.c_n; motion_controller_withPIC_B.idx++) {
    solution->xstar[workingset->indexFixed[motion_controller_withPIC_B.idx] - 1]
      = workingset->ub[workingset->indexFixed[motion_controller_withPIC_B.idx] -
      1];
  }

  motion_controller_withPIC_B.c_n = static_cast<uint8_T>(workingset->sizes[3]);
  for (motion_controller_withPIC_B.idx = 0; motion_controller_withPIC_B.idx <
       motion_controller_withPIC_B.c_n; motion_controller_withPIC_B.idx++) {
    if (workingset->isActiveConstr[(workingset->isActiveIdx[3] +
         motion_controller_withPIC_B.idx) - 1]) {
      solution->xstar[workingset->indexLB[motion_controller_withPIC_B.idx] - 1] =
        -workingset->lb[workingset->indexLB[motion_controller_withPIC_B.idx] - 1];
    }
  }

  motion_controller_withPIC_B.c_n = static_cast<uint8_T>(workingset->sizes[4]);
  for (motion_controller_withPIC_B.idx = 0; motion_controller_withPIC_B.idx <
       motion_controller_withPIC_B.c_n; motion_controller_withPIC_B.idx++) {
    if (workingset->isActiveConstr[(workingset->isActiveIdx[4] +
         motion_controller_withPIC_B.idx) - 1]) {
      solution->xstar[workingset->indexUB[motion_controller_withPIC_B.idx] - 1] =
        workingset->ub[workingset->indexUB[motion_controller_withPIC_B.idx] - 1];
    }
  }

  motion_contr_PresolveWorkingSet(solution, memspace, workingset, qrmanager);
  if (solution->state >= 0) {
    solution->iterations = 0;
    solution->maxConstr = motion_c_maxConstraintViolation(workingset,
      solution->xstar);
    motion_controller_withPIC_B.d2 = 1.0E-8 * runTimeOptions.ConstrRelTolFactor;
    guard1 = false;
    if (solution->maxConstr > motion_controller_withPIC_B.d2) {
      motion_controller_with_phaseone(H, f, solution, memspace, workingset,
        qrmanager, cholmanager, options, &runTimeOptions, objective);
      if (solution->state == 0) {
      } else {
        solution->maxConstr = motion_c_maxConstraintViolation(workingset,
          solution->xstar);
        if (solution->maxConstr > motion_controller_withPIC_B.d2) {
          memset(&solution->lambda[0], 0, 161U * sizeof(real_T));
          solution->fstar = motion_controller_w_computeFval(objective,
            memspace->workspace_double, H, f, solution->xstar);
          solution->state = -2;
        } else {
          if (solution->maxConstr > 0.0) {
            motion_controller_withPIC_B.idx = static_cast<uint8_T>
              (motion_controller_withPIC_B.i_j);
            if (motion_controller_withPIC_B.idx - 1 >= 0) {
              memcpy(&solution->searchDir[0], &solution->xstar[0],
                     static_cast<uint32_T>(motion_controller_withPIC_B.idx) *
                     sizeof(real_T));
            }

            motion_con_PresolveWorkingSet_g(solution, memspace, workingset,
              qrmanager);
            motion_controller_withPIC_B.maxConstr_new =
              motion_c_maxConstraintViolation(workingset, solution->xstar);
            if (motion_controller_withPIC_B.maxConstr_new >= solution->maxConstr)
            {
              solution->maxConstr = motion_controller_withPIC_B.maxConstr_new;
              if (motion_controller_withPIC_B.idx - 1 >= 0) {
                memcpy(&solution->xstar[0], &solution->searchDir[0],
                       static_cast<uint32_T>(motion_controller_withPIC_B.idx) *
                       sizeof(real_T));
              }
            }
          }

          guard1 = true;
        }
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      motion_controller_withP_iterate(H, f, solution, memspace, workingset,
        qrmanager, cholmanager, objective, options->ObjectiveLimit,
        options->StepTolerance, runTimeOptions.ConstrRelTolFactor,
        runTimeOptions.ProbRelTolFactor, true);
      if (strcmp_1LovgLAH(options->SolverName) && (solution->state != -6)) {
        solution->maxConstr = motion_c_maxConstraintViolation(workingset,
          solution->xstar);
        motion_con_computeFirstOrderOpt(solution, objective, workingset->nVar,
          workingset->ATwset, workingset->nActiveConstr,
          memspace->workspace_double);
        runTimeOptions.RemainFeasible = false;
        while ((solution->iterations < 200) && ((solution->state == -7) ||
                ((solution->state == 1) && ((solution->maxConstr >
                   motion_controller_withPIC_B.d2) || (solution->firstorderopt >
                   1.0E-8 * runTimeOptions.ProbRelTolFactor))))) {
          motion__feasibleX0ForWorkingSet(memspace->workspace_double,
            solution->xstar, workingset, qrmanager);
          motion_con_PresolveWorkingSet_g(solution, memspace, workingset,
            qrmanager);
          motion_controller_wi_phaseone_e(H, f, solution, memspace, workingset,
            qrmanager, cholmanager, objective, options, &runTimeOptions);
          motion_controller_withP_iterate(H, f, solution, memspace, workingset,
            qrmanager, cholmanager, objective, options->ObjectiveLimit,
            options->StepTolerance, runTimeOptions.ConstrRelTolFactor,
            runTimeOptions.ProbRelTolFactor, false);
          solution->maxConstr = motion_c_maxConstraintViolation(workingset,
            solution->xstar);
          motion_con_computeFirstOrderOpt(solution, objective, workingset->nVar,
            workingset->ATwset, workingset->nActiveConstr,
            memspace->workspace_double);
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S62>/solvex'
void motion_controller_withPIC::motion_controller_with_quadprog(const real_T H
  [1600], const real_T f[40], const real_T Aineq[3200], const real_T bineq[80],
  const real_T lb[40], const real_T ub[40], real_T x0[40], const
  sSOeZ9WO10chPn9Si6PKiCB_motio_T *options)
{
  __m128d tmp;
  boolean_T exitg1;
  boolean_T guard1;
  motion_controller_withPIC_B.exitflag = (rtInf);
  motion_controller_withPIC_B.c_k = 0;
  exitg1 = false;
  while ((!exitg1) && (motion_controller_withPIC_B.c_k < 40)) {
    if (lb[motion_controller_withPIC_B.c_k] > ub[motion_controller_withPIC_B.c_k])
    {
      motion_controller_withPIC_B.exitflag = -2.0;
      exitg1 = true;
    } else {
      motion_controller_withPIC_B.c_k++;
    }
  }

  if (!(motion_controller_withPIC_B.exitflag == -2.0)) {
    motion_controller_withPIC_B.solution.fstar = 0.0;
    motion_controller_withPIC_B.solution.firstorderopt = 0.0;
    memset(&motion_controller_withPIC_B.solution.lambda[0], 0, 161U * sizeof
           (real_T));
    motion_controller_withPIC_B.solution.state = 0;
    motion_controller_withPIC_B.solution.maxConstr = 0.0;
    motion_controller_withPIC_B.solution.iterations = 0;
    memset(&motion_controller_withPIC_B.solution.searchDir[0], 0, 41U * sizeof
           (real_T));
    memset(&motion_controller_withPIC_B.solution.xstar[0], 0, 40U * sizeof
           (real_T));
    motion_controller_withPIC_B.CholRegManager.ldm = 41;
    motion_controller_withPIC_B.CholRegManager.ndims = 0;
    motion_controller_withPIC_B.CholRegManager.info = 0;
    motion_controller_withPIC_B.CholRegManager.ConvexCheck = true;
    motion_controller_withPIC_B.CholRegManager.regTol_ = 0.0;
    motion_controller_withPIC_B.CholRegManager.scaleFactor = 100.0;
    motion_controller_withPIC_B.WorkingSet.nVar = 40;
    motion_controller_withPIC_B.WorkingSet.nVarOrig = 40;
    motion_controller_withPIC_B.WorkingSet.nVarMax = 41;
    motion_controller_withPIC_B.WorkingSet.ldA = 41;
    memset(&motion_controller_withPIC_B.WorkingSet.Aineq[0], 0, 3280U * sizeof
           (real_T));
    memset(&motion_controller_withPIC_B.WorkingSet.bineq[0], 0, 80U * sizeof
           (real_T));
    memset(&motion_controller_withPIC_B.WorkingSet.lb[0], 0, 41U * sizeof(real_T));
    memset(&motion_controller_withPIC_B.WorkingSet.ub[0], 0, 41U * sizeof(real_T));
    motion_controller_withPIC_B.WorkingSet.mEqRemoved = 0;
    memset(&motion_controller_withPIC_B.WorkingSet.ATwset[0], 0, 6601U * sizeof
           (real_T));
    motion_controller_withPIC_B.WorkingSet.nActiveConstr = 0;
    memset(&motion_controller_withPIC_B.WorkingSet.bwset[0], 0, 161U * sizeof
           (real_T));
    memset(&motion_controller_withPIC_B.WorkingSet.maxConstrWorkspace[0], 0,
           161U * sizeof(real_T));
    memset(&motion_controller_withPIC_B.WorkingSet.isActiveConstr[0], 0, 161U *
           sizeof(boolean_T));
    memset(&motion_controller_withPIC_B.WorkingSet.Wid[0], 0, 161U * sizeof
           (int32_T));
    memset(&motion_controller_withPIC_B.WorkingSet.Wlocalidx[0], 0, 161U *
           sizeof(int32_T));
    for (motion_controller_withPIC_B.i_d = 0; motion_controller_withPIC_B.i_d <
         5; motion_controller_withPIC_B.i_d++) {
      motion_controller_withPIC_B.WorkingSet.nWConstr[motion_controller_withPIC_B.i_d]
        = 0;
    }

    motion_controller_withPIC_B.WorkingSet.probType = 3;
    motion_controller_withPIC_B.WorkingSet.SLACK0 = 1.0E-5;
    memset(&motion_controller_withPIC_B.WorkingSet.indexLB[0], 0, 41U * sizeof
           (int32_T));
    memset(&motion_controller_withPIC_B.WorkingSet.indexUB[0], 0, 41U * sizeof
           (int32_T));
    memset(&motion_controller_withPIC_B.WorkingSet.indexFixed[0], 0, 41U *
           sizeof(int32_T));
    motion_controller_withPIC_B.c_k = 80;
    motion_controller_withPIC_B.idxFillStart = 0;
    motion_controller_withPIC_B.colOffsetATw = 0;
    for (motion_controller_withPIC_B.i_d = 0; motion_controller_withPIC_B.i_d <
         40; motion_controller_withPIC_B.i_d++) {
      motion_controller_withPIC_B.exitflag = lb[motion_controller_withPIC_B.i_d];
      guard1 = false;
      if ((!rtIsInf(motion_controller_withPIC_B.exitflag)) && (!rtIsNaN
           (motion_controller_withPIC_B.exitflag))) {
        if (fabs(motion_controller_withPIC_B.exitflag -
                 ub[motion_controller_withPIC_B.i_d]) < 1.0E-8) {
          motion_controller_withPIC_B.colOffsetATw++;
          motion_controller_withPIC_B.WorkingSet.indexFixed[motion_controller_withPIC_B.colOffsetATw
            - 1] = motion_controller_withPIC_B.i_d + 1;
        } else {
          motion_controller_withPIC_B.c_k++;
          motion_controller_withPIC_B.WorkingSet.indexLB[motion_controller_withPIC_B.c_k
            - 81] = motion_controller_withPIC_B.i_d + 1;
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        motion_controller_withPIC_B.exitflag =
          ub[motion_controller_withPIC_B.i_d];
        if ((!rtIsInf(motion_controller_withPIC_B.exitflag)) && (!rtIsNaN
             (motion_controller_withPIC_B.exitflag))) {
          motion_controller_withPIC_B.idxFillStart++;
          motion_controller_withPIC_B.WorkingSet.indexUB[motion_controller_withPIC_B.idxFillStart
            - 1] = motion_controller_withPIC_B.i_d + 1;
        }
      }
    }

    motion_controller_withPIC_B.i_d = (motion_controller_withPIC_B.c_k +
      motion_controller_withPIC_B.idxFillStart) +
      motion_controller_withPIC_B.colOffsetATw;
    motion_controller_withPIC_B.WorkingSet.mConstr =
      motion_controller_withPIC_B.i_d;
    motion_controller_withPIC_B.WorkingSet.mConstrOrig =
      motion_controller_withPIC_B.i_d;
    motion_controller_withPIC_B.WorkingSet.mConstrMax = 161;
    motion_controller_withPIC_B.WorkingSet.sizes[0] =
      motion_controller_withPIC_B.colOffsetATw;
    motion_controller_withPIC_B.WorkingSet.sizes[1] = 0;
    motion_controller_withPIC_B.WorkingSet.sizes[2] = 80;
    motion_controller_withPIC_B.WorkingSet.sizes[3] =
      motion_controller_withPIC_B.c_k - 80;
    motion_controller_withPIC_B.WorkingSet.sizes[4] =
      motion_controller_withPIC_B.idxFillStart;
    for (motion_controller_withPIC_B.i_d = 0; motion_controller_withPIC_B.i_d <
         5; motion_controller_withPIC_B.i_d++) {
      motion_controller_withPIC_B.WorkingSet.sizesNormal[motion_controller_withPIC_B.i_d]
        =
        motion_controller_withPIC_B.WorkingSet.sizes[motion_controller_withPIC_B.i_d];
    }

    motion_controller_withPIC_B.WorkingSet.sizesPhaseOne[0] =
      motion_controller_withPIC_B.colOffsetATw;
    motion_controller_withPIC_B.WorkingSet.sizesPhaseOne[1] = 0;
    motion_controller_withPIC_B.WorkingSet.sizesPhaseOne[2] = 80;
    motion_controller_withPIC_B.WorkingSet.sizesPhaseOne[3] =
      motion_controller_withPIC_B.c_k - 79;
    motion_controller_withPIC_B.WorkingSet.sizesPhaseOne[4] =
      motion_controller_withPIC_B.idxFillStart;
    motion_controller_withPIC_B.WorkingSet.sizesRegularized[0] =
      motion_controller_withPIC_B.colOffsetATw;
    motion_controller_withPIC_B.WorkingSet.sizesRegularized[1] = 0;
    motion_controller_withPIC_B.WorkingSet.sizesRegularized[2] = 80;
    motion_controller_withPIC_B.WorkingSet.sizesRegularized[3] =
      motion_controller_withPIC_B.c_k;
    motion_controller_withPIC_B.WorkingSet.sizesRegularized[4] =
      motion_controller_withPIC_B.idxFillStart;
    motion_controller_withPIC_B.WorkingSet.sizesRegPhaseOne[0] =
      motion_controller_withPIC_B.colOffsetATw;
    motion_controller_withPIC_B.WorkingSet.sizesRegPhaseOne[1] = 0;
    motion_controller_withPIC_B.WorkingSet.sizesRegPhaseOne[2] = 80;
    motion_controller_withPIC_B.WorkingSet.sizesRegPhaseOne[3] =
      motion_controller_withPIC_B.c_k + 1;
    motion_controller_withPIC_B.WorkingSet.sizesRegPhaseOne[4] =
      motion_controller_withPIC_B.idxFillStart;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxNormal[0] = 1;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxNormal[1] =
      motion_controller_withPIC_B.colOffsetATw;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxNormal[2] = 0;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxNormal[3] = 80;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxNormal[4] =
      motion_controller_withPIC_B.c_k - 80;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxNormal[5] =
      motion_controller_withPIC_B.idxFillStart;
    for (motion_controller_withPIC_B.i_d = 0; motion_controller_withPIC_B.i_d <
         6; motion_controller_withPIC_B.i_d++) {
      motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_d]
        =
        motion_controller_withPIC_B.WorkingSet.isActiveIdxNormal[motion_controller_withPIC_B.i_d];
    }

    for (motion_controller_withPIC_B.i_d = 0; motion_controller_withPIC_B.i_d <
         5; motion_controller_withPIC_B.i_d++) {
      motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_d
        + 1] +=
        motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_d];
    }

    for (motion_controller_withPIC_B.i_d = 0; motion_controller_withPIC_B.i_d <
         6; motion_controller_withPIC_B.i_d++) {
      motion_controller_withPIC_B.WorkingSet.isActiveIdx[motion_controller_withPIC_B.i_d]
        =
        motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_d];
    }

    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[1] =
      motion_controller_withPIC_B.colOffsetATw;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[3] = 80;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[4] =
      motion_controller_withPIC_B.c_k - 79;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[5] =
      motion_controller_withPIC_B.idxFillStart;
    for (motion_controller_withPIC_B.i_d = 0; motion_controller_withPIC_B.i_d <
         5; motion_controller_withPIC_B.i_d++) {
      motion_controller_withPIC_B.WorkingSet.isActiveIdxNormal[motion_controller_withPIC_B.i_d
        + 1] +=
        motion_controller_withPIC_B.WorkingSet.isActiveIdxNormal[motion_controller_withPIC_B.i_d];
      motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_d
        + 1] +=
        motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_d];
    }

    for (motion_controller_withPIC_B.i_d = 0; motion_controller_withPIC_B.i_d <
         6; motion_controller_withPIC_B.i_d++) {
      motion_controller_withPIC_B.WorkingSet.isActiveIdxPhaseOne[motion_controller_withPIC_B.i_d]
        =
        motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_d];
    }

    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[1] =
      motion_controller_withPIC_B.colOffsetATw;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[3] = 80;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[4] =
      motion_controller_withPIC_B.c_k;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[5] =
      motion_controller_withPIC_B.idxFillStart;
    for (motion_controller_withPIC_B.i_d = 0; motion_controller_withPIC_B.i_d <
         5; motion_controller_withPIC_B.i_d++) {
      motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_d
        + 1] +=
        motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_d];
    }

    for (motion_controller_withPIC_B.i_d = 0; motion_controller_withPIC_B.i_d <
         6; motion_controller_withPIC_B.i_d++) {
      motion_controller_withPIC_B.WorkingSet.isActiveIdxRegularized[motion_controller_withPIC_B.i_d]
        =
        motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_d];
    }

    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[1] =
      motion_controller_withPIC_B.colOffsetATw;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[3] = 80;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[4] =
      motion_controller_withPIC_B.c_k + 1;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[5] =
      motion_controller_withPIC_B.idxFillStart;
    for (motion_controller_withPIC_B.c_k = 0; motion_controller_withPIC_B.c_k <
         5; motion_controller_withPIC_B.c_k++) {
      motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.c_k
        + 1] +=
        motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.c_k];
    }

    for (motion_controller_withPIC_B.c_k = 0; motion_controller_withPIC_B.c_k <
         80; motion_controller_withPIC_B.c_k++) {
      for (motion_controller_withPIC_B.idxFillStart = 0;
           motion_controller_withPIC_B.idxFillStart < 40;
           motion_controller_withPIC_B.idxFillStart++) {
        motion_controller_withPIC_B.WorkingSet.Aineq[motion_controller_withPIC_B.idxFillStart
          + 41 * motion_controller_withPIC_B.c_k] = Aineq[80 *
          motion_controller_withPIC_B.idxFillStart +
          motion_controller_withPIC_B.c_k];
      }

      motion_controller_withPIC_B.WorkingSet.bineq[motion_controller_withPIC_B.c_k]
        = bineq[motion_controller_withPIC_B.c_k];
    }

    for (motion_controller_withPIC_B.c_k = 0; motion_controller_withPIC_B.c_k <=
         38; motion_controller_withPIC_B.c_k += 2) {
      tmp = _mm_loadu_pd(&lb[motion_controller_withPIC_B.c_k]);
      _mm_storeu_pd
        (&motion_controller_withPIC_B.WorkingSet.lb[motion_controller_withPIC_B.c_k],
         _mm_mul_pd(tmp, _mm_set1_pd(-1.0)));
      tmp = _mm_loadu_pd(&ub[motion_controller_withPIC_B.c_k]);
      _mm_storeu_pd
        (&motion_controller_withPIC_B.WorkingSet.ub[motion_controller_withPIC_B.c_k],
         tmp);
    }

    motion_controlle_setProblemType(&motion_controller_withPIC_B.WorkingSet, 3);
    motion_controller_withPIC_B.idxFillStart =
      motion_controller_withPIC_B.WorkingSet.isActiveIdx[2];
    for (motion_controller_withPIC_B.c_k =
         motion_controller_withPIC_B.idxFillStart;
         motion_controller_withPIC_B.c_k < 162; motion_controller_withPIC_B.c_k
         ++) {
      motion_controller_withPIC_B.WorkingSet.isActiveConstr[motion_controller_withPIC_B.c_k
        - 1] = false;
    }

    motion_controller_withPIC_B.WorkingSet.nWConstr[0] =
      motion_controller_withPIC_B.WorkingSet.sizes[0];
    motion_controller_withPIC_B.WorkingSet.nWConstr[1] = 0;
    motion_controller_withPIC_B.WorkingSet.nWConstr[2] = 0;
    motion_controller_withPIC_B.WorkingSet.nWConstr[3] = 0;
    motion_controller_withPIC_B.WorkingSet.nWConstr[4] = 0;
    motion_controller_withPIC_B.WorkingSet.nActiveConstr =
      motion_controller_withPIC_B.WorkingSet.nWConstr[0];
    motion_controller_withPIC_B.idxFillStart = static_cast<uint8_T>
      (motion_controller_withPIC_B.WorkingSet.sizes[0]);
    for (motion_controller_withPIC_B.c_k = 0; motion_controller_withPIC_B.c_k <
         motion_controller_withPIC_B.idxFillStart;
         motion_controller_withPIC_B.c_k++) {
      motion_controller_withPIC_B.WorkingSet.Wid[motion_controller_withPIC_B.c_k]
        = 1;
      motion_controller_withPIC_B.WorkingSet.Wlocalidx[motion_controller_withPIC_B.c_k]
        = motion_controller_withPIC_B.c_k + 1;
      motion_controller_withPIC_B.WorkingSet.isActiveConstr[motion_controller_withPIC_B.c_k]
        = true;
      motion_controller_withPIC_B.colOffsetATw = 41 *
        motion_controller_withPIC_B.c_k;
      motion_controller_withPIC_B.i_d =
        motion_controller_withPIC_B.WorkingSet.indexFixed[motion_controller_withPIC_B.c_k];
      if (motion_controller_withPIC_B.i_d - 2 >= 0) {
        memset
          (&motion_controller_withPIC_B.WorkingSet.ATwset[motion_controller_withPIC_B.colOffsetATw],
           0, static_cast<uint32_T>(((motion_controller_withPIC_B.i_d +
              motion_controller_withPIC_B.colOffsetATw) -
             motion_controller_withPIC_B.colOffsetATw) - 1) * sizeof(real_T));
      }

      motion_controller_withPIC_B.WorkingSet.ATwset
        [(motion_controller_withPIC_B.WorkingSet.indexFixed[motion_controller_withPIC_B.c_k]
          + motion_controller_withPIC_B.colOffsetATw) - 1] = 1.0;
      motion_controller_withPIC_B.i_d =
        motion_controller_withPIC_B.WorkingSet.indexFixed[motion_controller_withPIC_B.c_k]
        + 1;
      motion_controller_withPIC_B.e =
        motion_controller_withPIC_B.WorkingSet.nVar;
      if (motion_controller_withPIC_B.i_d <= motion_controller_withPIC_B.e) {
        memset(&motion_controller_withPIC_B.WorkingSet.ATwset
               [(motion_controller_withPIC_B.i_d +
                 motion_controller_withPIC_B.colOffsetATw) + -1], 0,
               static_cast<uint32_T>((((motion_controller_withPIC_B.e +
                   motion_controller_withPIC_B.colOffsetATw) -
                  motion_controller_withPIC_B.i_d) -
                 motion_controller_withPIC_B.colOffsetATw) + 1) * sizeof(real_T));
      }

      motion_controller_withPIC_B.WorkingSet.bwset[motion_controller_withPIC_B.c_k]
        =
        motion_controller_withPIC_B.WorkingSet.ub[motion_controller_withPIC_B.WorkingSet.indexFixed
        [motion_controller_withPIC_B.c_k] - 1];
    }

    motion_controller_withPIC_B.WorkingSet.SLACK0 = 0.0;
    motion_controller_withPIC_B.exitflag = 1.0;
    for (motion_controller_withPIC_B.c_k = 0; motion_controller_withPIC_B.c_k <
         80; motion_controller_withPIC_B.c_k++) {
      motion_controller_withPIC_B.colSum = 0.0;
      motion_controller_withPIC_B.colOffsetATw = 41 *
        motion_controller_withPIC_B.c_k;
      for (motion_controller_withPIC_B.idxFillStart = 0;
           motion_controller_withPIC_B.idxFillStart < 40;
           motion_controller_withPIC_B.idxFillStart++) {
        motion_controller_withPIC_B.colSum += fabs
          (motion_controller_withPIC_B.WorkingSet.Aineq[motion_controller_withPIC_B.idxFillStart
           + motion_controller_withPIC_B.colOffsetATw]);
      }

      if ((!(motion_controller_withPIC_B.exitflag >=
             motion_controller_withPIC_B.colSum)) && (!rtIsNaN
           (motion_controller_withPIC_B.colSum))) {
        motion_controller_withPIC_B.exitflag =
          motion_controller_withPIC_B.colSum;
      }
    }

    motion_controller_withPIC_B.colSum = 0.0;
    motion_controller_withPIC_B.f_infnrm = 0.0;
    for (motion_controller_withPIC_B.c_k = 0; motion_controller_withPIC_B.c_k <
         40; motion_controller_withPIC_B.c_k++) {
      motion_controller_withPIC_B.b_colSum = 0.0;
      for (motion_controller_withPIC_B.idxFillStart = 0;
           motion_controller_withPIC_B.idxFillStart < 40;
           motion_controller_withPIC_B.idxFillStart++) {
        motion_controller_withPIC_B.b_colSum += fabs(H[40 *
          motion_controller_withPIC_B.c_k +
          motion_controller_withPIC_B.idxFillStart]);
      }

      if ((!(motion_controller_withPIC_B.colSum >=
             motion_controller_withPIC_B.b_colSum)) && (!rtIsNaN
           (motion_controller_withPIC_B.b_colSum))) {
        motion_controller_withPIC_B.colSum =
          motion_controller_withPIC_B.b_colSum;
      }

      motion_controller_withPIC_B.b_colSum = fabs
        (f[motion_controller_withPIC_B.c_k]);
      if ((!(motion_controller_withPIC_B.f_infnrm >=
             motion_controller_withPIC_B.b_colSum)) && (!rtIsNaN
           (motion_controller_withPIC_B.b_colSum))) {
        motion_controller_withPIC_B.f_infnrm =
          motion_controller_withPIC_B.b_colSum;
      }
    }

    motion_controller_withPIC_B.expl_temp.RemainFeasible = false;
    if (motion_controller_withPIC_B.exitflag >=
        motion_controller_withPIC_B.f_infnrm) {
      motion_controller_withPIC_B.f_infnrm =
        motion_controller_withPIC_B.exitflag;
    }

    if (motion_controller_withPIC_B.f_infnrm >=
        motion_controller_withPIC_B.colSum) {
      motion_controller_withPIC_B.expl_temp.ProbRelTolFactor =
        motion_controller_withPIC_B.f_infnrm;
    } else {
      motion_controller_withPIC_B.expl_temp.ProbRelTolFactor =
        motion_controller_withPIC_B.colSum;
    }

    motion_controller_withPIC_B.expl_temp.ConstrRelTolFactor =
      motion_controller_withPIC_B.exitflag;
    motion_controller_withPIC_B.expl_temp.MaxIterations = 200;
    motion_controller_withPIC_B.options = *options;
    motion_controller_withPI_driver(H, f, &motion_controller_withPIC_B.solution,
      &motion_controller_withPIC_B.memspace,
      &motion_controller_withPIC_B.WorkingSet,
      &motion_controller_withPIC_B.CholRegManager,
      &motion_controller_withPIC_B.options,
      motion_controller_withPIC_B.expl_temp,
      &motion_controller_withPIC_B.QRManager,
      &motion_controller_withPIC_B.QPObjective);
    memcpy(&x0[0], &motion_controller_withPIC_B.solution.xstar[0], 40U * sizeof
           (real_T));
  }
}

void motion_controller_withPIC::motion_SystemCore_setup_fxdcjik
  (ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[11];
  static const char_T b_zeroDelimTopic_0[11] = "/motor_cmd";

  // Start for MATLABSystem: '<S42>/SinkBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S42>/SinkBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)5.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 11; i++) {
    // Start for MATLABSystem: '<S42>/SinkBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Pub_motion_controller_withPIC_4.createPublisher(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_withPIC::motio_SystemCore_setup_fxdcjikh
  (ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[11];
  static const char_T b_zeroDelimTopic_0[11] = "/servo_cmd";

  // Start for MATLABSystem: '<S43>/SinkBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S43>/SinkBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)10.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 11; i++) {
    // Start for MATLABSystem: '<S43>/SinkBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Pub_motion_controller_withPIC_148.createPublisher(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_withPIC::motion_co_SystemCore_setup_fxdc
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[22];
  static const char_T b_zeroDelimTopic_0[22] = "/t265_odometry_filter";

  // Start for MATLABSystem: '<S31>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S31>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  for (int32_T i = 0; i < 22; i++) {
    // Start for MATLABSystem: '<S31>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_motion_controller_withPIC_514.createSubscriber(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_withPIC::motion_c_SystemCore_setup_fxdcj
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[17];
  static const char_T b_zeroDelimTopic_0[17] = "/Imu_data_filter";

  // Start for MATLABSystem: '<S32>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S32>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  for (int32_T i = 0; i < 17; i++) {
    // Start for MATLABSystem: '<S32>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_motion_controller_withPIC_515.createSubscriber(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_withPIC::moti_SystemCore_setup_fxdcjikhl
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[6];
  static const char_T b_zeroDelimTopic_0[6] = "/sbus";

  // Start for MATLABSystem: '<S69>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S69>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  for (int32_T i = 0; i < 6; i++) {
    // Start for MATLABSystem: '<S69>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_motion_controller_withPIC_1.createSubscriber(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_withPIC::motion_control_SystemCore_setup
  (ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[9];
  static const char_T b_zeroDelimTopic_0[9] = "/MPCtest";

  // Start for MATLABSystem: '<S20>/SinkBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S20>/SinkBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)10.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 9; i++) {
    // Start for MATLABSystem: '<S20>/SinkBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Pub_motion_controller_withPIC_545.createPublisher(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_withPIC::motion__SystemCore_setup_fxdcji
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[13];
  static const char_T b_zeroDelimTopic_0[13] = "/servo_state";

  // Start for MATLABSystem: '<S33>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S33>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  for (int32_T i = 0; i < 13; i++) {
    // Start for MATLABSystem: '<S33>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_motion_controller_withPIC_516.createSubscriber(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_withPIC::motion_contr_SystemCore_setup_f
  (ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[7];
  static const char_T b_zeroDelimTopic_0[7] = "/alpha";

  // Start for MATLABSystem: '<S22>/SinkBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S22>/SinkBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)10.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 7; i++) {
    // Start for MATLABSystem: '<S22>/SinkBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Pub_motion_controller_withPIC_831.createPublisher(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_withPIC::motion_cont_SystemCore_setup_fx
  (ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[16];
  static const char_T b_zeroDelimTopic_0[16] = "/FyAndAyDomegaz";

  // Start for MATLABSystem: '<S24>/SinkBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S24>/SinkBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)10.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 16; i++) {
    // Start for MATLABSystem: '<S24>/SinkBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Pub_motion_controller_withPIC_839.createPublisher(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_withPIC::motion_con_SystemCore_setup_fxd
  (ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[10];
  static const char_T b_zeroDelimTopic_0[10] = "/vyFvyrFr";

  // Start for MATLABSystem: '<S26>/SinkBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S26>/SinkBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)10.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 10; i++) {
    // Start for MATLABSystem: '<S26>/SinkBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Pub_motion_controller_withPIC_932.createPublisher(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_withPIC::mot_SystemCore_setup_fxdcjikhl4
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[13];
  static const char_T b_zeroDelimTopic_0[13] = "/motor_state";

  // Start for MATLABSystem: '<S70>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S70>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  for (int32_T i = 0; i < 13; i++) {
    // Start for MATLABSystem: '<S70>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_motion_controller_withPIC_238.createSubscriber(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

// Model step function
void motion_controller_withPIC::step()
{
  __m128d tmp;
  __m128d tmp_0;
  __m128d tmp_1;
  __m128d tmp_2;
  __m128d tmp_3;
  __m128d tmp_4;
  __m128d tmp_5;
  static const int8_T B[4] = { 1, 0, 0, 1 };

  static const int8_T A[100] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0,
    0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
    1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1 };

  static const int8_T A_0[400] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
    0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
    0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
    1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 };

  // MATLABSystem: '<S31>/SourceBlock'
  motion_controller_withPIC_B.LogicalOperator_j =
    Sub_motion_controller_withPIC_514.getLatestMessage
    (&motion_controller_withPIC_B.b_varargout_2_b);

  // Outputs for Enabled SubSystem: '<S31>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S34>/Enable'

  // Start for MATLABSystem: '<S31>/SourceBlock'
  if (motion_controller_withPIC_B.LogicalOperator_j) {
    // SignalConversion generated from: '<S34>/In1'
    motion_controller_withPIC_B.In1_je =
      motion_controller_withPIC_B.b_varargout_2_b;
  }

  // End of Start for MATLABSystem: '<S31>/SourceBlock'
  // End of Outputs for SubSystem: '<S31>/Enabled Subsystem'

  // MATLABSystem: '<S32>/SourceBlock'
  motion_controller_withPIC_B.LogicalOperator_j =
    Sub_motion_controller_withPIC_515.getLatestMessage
    (&motion_controller_withPIC_B.BusAssignment2);

  // Outputs for Enabled SubSystem: '<S32>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S35>/Enable'

  // Start for MATLABSystem: '<S32>/SourceBlock'
  if (motion_controller_withPIC_B.LogicalOperator_j) {
    // SignalConversion generated from: '<S35>/In1'
    motion_controller_withPIC_B.In1_f =
      motion_controller_withPIC_B.BusAssignment2;
  }

  // End of Start for MATLABSystem: '<S32>/SourceBlock'
  // End of Outputs for SubSystem: '<S32>/Enabled Subsystem'

  // MATLABSystem: '<S69>/SourceBlock'
  motion_controller_withPIC_B.LogicalOperator_j =
    Sub_motion_controller_withPIC_1.getLatestMessage
    (&motion_controller_withPIC_B.b_varargout_2_j);

  // Outputs for Enabled SubSystem: '<S69>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S72>/Enable'

  // Start for MATLABSystem: '<S69>/SourceBlock'
  if (motion_controller_withPIC_B.LogicalOperator_j) {
    // SignalConversion generated from: '<S72>/In1'
    motion_controller_withPIC_B.In1_m =
      motion_controller_withPIC_B.b_varargout_2_j;
  }

  // End of Outputs for SubSystem: '<S69>/Enabled Subsystem'

  // RelationalOperator: '<S37>/Compare' incorporates:
  //   Abs: '<S11>/Abs'
  //   Constant: '<S11>/Constant1'
  //   Constant: '<S37>/Constant'
  //   SignalConversion generated from: '<S17>/Bus Selector'
  //   Sum: '<S11>/Add'

  motion_controller_withPIC_B.Compare = (fabs(static_cast<real_T>
    (motion_controller_withPIC_B.In1_m.mapped_channels[0]) -
    motion_controller_withPIC_P.Constant1_Value) >=
    motion_controller_withPIC_P.CompareToConstant1_const);

  // Chart: '<S9>/Chart'
  if (motion_controller_withPIC_DW.is_active_c7_motion_controller_ == 0U) {
    motion_controller_withPIC_DW.is_active_c7_motion_controller_ = 1U;
    motion_controller_withPIC_DW.is_c7_motion_controller_withPIC =
      motion_controller_withPI_IN_ini;
    motion_controller_withPIC_DW.delay = 50.0;
    motion_controller_withPIC_B.y = 0.0;
    motion_controller_withPIC_B.yaw = 0.0;
  } else if (motion_controller_withPIC_DW.is_c7_motion_controller_withPIC ==
             motion_controller_withPI_IN_ini) {
    if (motion_controller_withPIC_DW.delay < 1.0) {
      motion_controller_withPIC_DW.is_c7_motion_controller_withPIC =
        motion_controller_wi_IN_running;
      motion_controller_withPIC_DW.y_ini =
        motion_controller_withPIC_B.In1_je.pose.pose.position.y;
      motion_controller_withPIC_DW.yaw_ini =
        motion_controller_withPIC_B.In1_f.orientation.z;
      motion_controller_withPIC_DW.yaw_l =
        motion_controller_withPIC_B.In1_f.orientation.z;
      motion_controller_withPIC_DW.delta = 0.0;
    } else {
      motion_controller_withPIC_DW.delay--;
    }

    // case IN_running:
  } else if (motion_controller_withPIC_B.Compare) {
    motion_controller_withPIC_DW.is_c7_motion_controller_withPIC =
      motion_controller_withPI_IN_ini;
    motion_controller_withPIC_DW.delay = 50.0;
    motion_controller_withPIC_B.y = 0.0;
    motion_controller_withPIC_B.yaw = 0.0;
  } else {
    motion_controller_withPIC_B.y =
      motion_controller_withPIC_B.In1_je.pose.pose.position.y -
      motion_controller_withPIC_DW.y_ini;
    motion_controller_withPIC_B.yaw =
      motion_controller_withPIC_B.In1_f.orientation.z -
      motion_controller_withPIC_DW.yaw_ini;
    if (motion_controller_withPIC_B.yaw - motion_controller_withPIC_DW.yaw_l >
        3.1415926535897931) {
      motion_controller_withPIC_DW.delta -= 6.2831853071795862;
    } else if (motion_controller_withPIC_B.yaw -
               motion_controller_withPIC_DW.yaw_l < -3.1415926535897931) {
      motion_controller_withPIC_DW.delta += 6.2831853071795862;
    }

    motion_controller_withPIC_DW.yaw_l = motion_controller_withPIC_B.yaw;
    motion_controller_withPIC_B.yaw += motion_controller_withPIC_DW.delta;
  }

  // End of Chart: '<S9>/Chart'

  // MATLAB Function: '<S9>/MATLAB Function' incorporates:
  //   Constant: '<S9>/Constant'

  motion_controller_withPIC_B.yp = motion_controller_withPIC_B.y -
    motion_controller_withPIC_P.Constant_Value_j * sin
    (motion_controller_withPIC_B.yaw);

  // MATLABSystem: '<Root>/Get Parameter18'
  ParamGet_motion_controller_withPIC_940.getParameter
    (&motion_controller_withPIC_B.b_value_k1);

  // MATLABSystem: '<Root>/Get Parameter20'
  ParamGet_motion_controller_withPIC_941.getParameter
    (&motion_controller_withPIC_B.b_value_c0);

  // MATLABSystem: '<Root>/Get Parameter21'
  ParamGet_motion_controller_withPIC_942.getParameter
    (&motion_controller_withPIC_B.b_value_ct);

  // MATLABSystem: '<Root>/Get Parameter22'
  ParamGet_motion_controller_withPIC_943.getParameter
    (&motion_controller_withPIC_B.b_value_p);

  // MATLABSystem: '<Root>/Get Parameter19'
  ParamGet_motion_controller_withPIC_924.getParameter
    (&motion_controller_withPIC_B.b_value_p5);

  // Saturate: '<Root>/Saturation'
  if (motion_controller_withPIC_B.b_value_p5 >
      motion_controller_withPIC_P.Saturation_UpperSat_a) {
    motion_controller_withPIC_B.b_value_p5 =
      motion_controller_withPIC_P.Saturation_UpperSat_a;
  } else if (motion_controller_withPIC_B.b_value_p5 <
             motion_controller_withPIC_P.Saturation_LowerSat_g) {
    motion_controller_withPIC_B.b_value_p5 =
      motion_controller_withPIC_P.Saturation_LowerSat_g;
  }

  // End of Saturate: '<Root>/Saturation'

  // MATLAB Function: '<Root>/MATLAB Function2' incorporates:
  //   MATLABSystem: '<Root>/Get Parameter18'
  //   MATLABSystem: '<Root>/Get Parameter20'
  //   MATLABSystem: '<Root>/Get Parameter21'
  //   MATLABSystem: '<Root>/Get Parameter22'

  if (!motion_controller_withPIC_DW.yd_not_empty) {
    for (motion_controller_withPIC_B.k = 0; motion_controller_withPIC_B.k < 100;
         motion_controller_withPIC_B.k++) {
      motion_controller_withPIC_DW.data100[motion_controller_withPIC_B.k] =
        motion_controller_withPIC_B.In1_f.angular_velocity.z;
      motion_controller_withPIC_B.y_g = (static_cast<real_T>
        (motion_controller_withPIC_B.k) - 50.0) /
        motion_controller_withPIC_B.b_value_ct /
        motion_controller_withPIC_B.b_value_p;
      motion_controller_withPIC_DW.gaussian_kernel100[motion_controller_withPIC_B.k]
        = motion_controller_withPIC_B.y_g * motion_controller_withPIC_B.y_g *
        -0.5;
      motion_controller_withPIC_DW.gaussian_kernel100[motion_controller_withPIC_B.k]
        = exp
        (motion_controller_withPIC_DW.gaussian_kernel100[motion_controller_withPIC_B.k]);
    }

    motion_controller_withPIC_B.y_g =
      motion_controller_withPIC_DW.gaussian_kernel100[0];
    for (motion_controller_withPIC_B.p_k = 0; motion_controller_withPIC_B.p_k <
         99; motion_controller_withPIC_B.p_k++) {
      motion_controller_withPIC_B.y_g +=
        motion_controller_withPIC_DW.gaussian_kernel100[motion_controller_withPIC_B.p_k
        + 1];
    }

    for (motion_controller_withPIC_B.isMpcEnable = 0;
         motion_controller_withPIC_B.isMpcEnable <= 98;
         motion_controller_withPIC_B.isMpcEnable += 2) {
      tmp_5 = _mm_loadu_pd
        (&motion_controller_withPIC_DW.gaussian_kernel100[motion_controller_withPIC_B.isMpcEnable]);
      _mm_storeu_pd
        (&motion_controller_withPIC_DW.gaussian_kernel100[motion_controller_withPIC_B.isMpcEnable],
         _mm_div_pd(tmp_5, _mm_set1_pd(motion_controller_withPIC_B.y_g)));
    }

    for (motion_controller_withPIC_B.p_k = 0; motion_controller_withPIC_B.p_k <
         200; motion_controller_withPIC_B.p_k++) {
      motion_controller_withPIC_DW.data200[motion_controller_withPIC_B.p_k] =
        motion_controller_withPIC_B.In1_f.angular_velocity.z;
      motion_controller_withPIC_B.y_g = (static_cast<real_T>
        (motion_controller_withPIC_B.p_k) - 100.0) /
        motion_controller_withPIC_B.b_value_ct /
        motion_controller_withPIC_B.b_value_p;
      motion_controller_withPIC_DW.gaussian_kernel200[motion_controller_withPIC_B.p_k]
        = motion_controller_withPIC_B.y_g * motion_controller_withPIC_B.y_g *
        -0.5;
      motion_controller_withPIC_DW.gaussian_kernel200[motion_controller_withPIC_B.p_k]
        = exp
        (motion_controller_withPIC_DW.gaussian_kernel200[motion_controller_withPIC_B.p_k]);
    }

    motion_controller_withPIC_B.y_g =
      motion_controller_withPIC_DW.gaussian_kernel200[0];
    for (motion_controller_withPIC_B.p_k = 0; motion_controller_withPIC_B.p_k <
         199; motion_controller_withPIC_B.p_k++) {
      motion_controller_withPIC_B.y_g +=
        motion_controller_withPIC_DW.gaussian_kernel200[motion_controller_withPIC_B.p_k
        + 1];
    }

    for (motion_controller_withPIC_B.isMpcEnable = 0;
         motion_controller_withPIC_B.isMpcEnable <= 198;
         motion_controller_withPIC_B.isMpcEnable += 2) {
      tmp_5 = _mm_loadu_pd
        (&motion_controller_withPIC_DW.gaussian_kernel200[motion_controller_withPIC_B.isMpcEnable]);
      _mm_storeu_pd
        (&motion_controller_withPIC_DW.gaussian_kernel200[motion_controller_withPIC_B.isMpcEnable],
         _mm_div_pd(tmp_5, _mm_set1_pd(motion_controller_withPIC_B.y_g)));
    }

    for (motion_controller_withPIC_B.p_k = 0; motion_controller_withPIC_B.p_k <
         50; motion_controller_withPIC_B.p_k++) {
      motion_controller_withPIC_DW.data50[motion_controller_withPIC_B.p_k] =
        motion_controller_withPIC_B.In1_f.angular_velocity.z;
      motion_controller_withPIC_B.y_g = (static_cast<real_T>
        (motion_controller_withPIC_B.p_k) - 25.0) /
        motion_controller_withPIC_B.b_value_ct /
        motion_controller_withPIC_B.b_value_p;
      motion_controller_withPIC_DW.gaussian_kernel50[motion_controller_withPIC_B.p_k]
        = motion_controller_withPIC_B.y_g * motion_controller_withPIC_B.y_g *
        -0.5;
      motion_controller_withPIC_DW.gaussian_kernel50[motion_controller_withPIC_B.p_k]
        = exp
        (motion_controller_withPIC_DW.gaussian_kernel50[motion_controller_withPIC_B.p_k]);
    }

    motion_controller_withPIC_B.b_value_ct =
      motion_controller_withPIC_DW.gaussian_kernel50[0];
    for (motion_controller_withPIC_B.p_k = 0; motion_controller_withPIC_B.p_k <
         49; motion_controller_withPIC_B.p_k++) {
      motion_controller_withPIC_B.b_value_ct +=
        motion_controller_withPIC_DW.gaussian_kernel50[motion_controller_withPIC_B.p_k
        + 1];
    }

    for (motion_controller_withPIC_B.isMpcEnable = 0;
         motion_controller_withPIC_B.isMpcEnable <= 48;
         motion_controller_withPIC_B.isMpcEnable += 2) {
      tmp_5 = _mm_loadu_pd
        (&motion_controller_withPIC_DW.gaussian_kernel50[motion_controller_withPIC_B.isMpcEnable]);
      _mm_storeu_pd
        (&motion_controller_withPIC_DW.gaussian_kernel50[motion_controller_withPIC_B.isMpcEnable],
         _mm_div_pd(tmp_5, _mm_set1_pd(motion_controller_withPIC_B.b_value_ct)));
    }

    motion_controller_withPIC_DW.yd =
      motion_controller_withPIC_B.In1_f.angular_velocity.z;
    motion_controller_withPIC_DW.yd_not_empty = true;
  }

  if (motion_controller_withPIC_B.b_value_k1) {
    if (motion_controller_withPIC_B.b_value_c0 == 50.0) {
      for (motion_controller_withPIC_B.isMpcEnable = 0;
           motion_controller_withPIC_B.isMpcEnable < 49;
           motion_controller_withPIC_B.isMpcEnable++) {
        motion_controller_withPIC_DW.data50[motion_controller_withPIC_B.isMpcEnable]
          =
          motion_controller_withPIC_DW.data50[motion_controller_withPIC_B.isMpcEnable
          + 1];
      }

      motion_controller_withPIC_DW.data50[49] =
        motion_controller_withPIC_B.In1_f.angular_velocity.z;
      memset(&motion_controller_withPIC_B.c_x[0], 0, 50U * sizeof(real_T));
      for (motion_controller_withPIC_B.b_kidx = 0;
           motion_controller_withPIC_B.b_kidx < 25;
           motion_controller_withPIC_B.b_kidx++) {
        motion_controller_withPIC_B.p_k = ((motion_controller_withPIC_B.b_kidx +
          25) / 2) << 1;
        motion_controller_withPIC_B.isMpcEnable =
          motion_controller_withPIC_B.p_k - 2;
        for (motion_controller_withPIC_B.i = 0; motion_controller_withPIC_B.i <=
             motion_controller_withPIC_B.isMpcEnable;
             motion_controller_withPIC_B.i += 2) {
          tmp_5 = _mm_loadu_pd(&motion_controller_withPIC_DW.data50
                               [(motion_controller_withPIC_B.i -
            motion_controller_withPIC_B.b_kidx) + 25]);
          tmp_5 = _mm_mul_pd(tmp_5, _mm_set1_pd
                             (motion_controller_withPIC_DW.gaussian_kernel50[motion_controller_withPIC_B.b_kidx]));
          tmp_4 = _mm_loadu_pd
            (&motion_controller_withPIC_B.c_x[motion_controller_withPIC_B.i]);
          _mm_storeu_pd
            (&motion_controller_withPIC_B.c_x[motion_controller_withPIC_B.i],
             _mm_add_pd(tmp_5, tmp_4));
        }

        for (motion_controller_withPIC_B.i = motion_controller_withPIC_B.p_k;
             motion_controller_withPIC_B.i <= motion_controller_withPIC_B.b_kidx
             + 24; motion_controller_withPIC_B.i++) {
          motion_controller_withPIC_B.c_x[motion_controller_withPIC_B.i] +=
            motion_controller_withPIC_DW.data50[(motion_controller_withPIC_B.i -
            motion_controller_withPIC_B.b_kidx) + 25] *
            motion_controller_withPIC_DW.gaussian_kernel50[motion_controller_withPIC_B.b_kidx];
        }
      }

      for (motion_controller_withPIC_B.i = 0; motion_controller_withPIC_B.i < 25;
           motion_controller_withPIC_B.i++) {
        motion_controller_withPIC_B.b_g = 49 - motion_controller_withPIC_B.i;
        for (motion_controller_withPIC_B.p_k = 0;
             motion_controller_withPIC_B.p_k <= motion_controller_withPIC_B.b_g;
             motion_controller_withPIC_B.p_k++) {
          motion_controller_withPIC_B.isMpcEnable =
            motion_controller_withPIC_B.i + motion_controller_withPIC_B.p_k;
          motion_controller_withPIC_B.c_x[motion_controller_withPIC_B.isMpcEnable]
            +=
            motion_controller_withPIC_DW.gaussian_kernel50[motion_controller_withPIC_B.i
            + 25] *
            motion_controller_withPIC_DW.data50[motion_controller_withPIC_B.p_k];
        }
      }

      motion_controller_withPIC_B.k = 50;
      memcpy(&motion_controller_withPIC_B.t_data[0],
             &motion_controller_withPIC_B.c_x[0], 50U * sizeof(real_T));
    } else if (motion_controller_withPIC_B.b_value_c0 == 100.0) {
      for (motion_controller_withPIC_B.isMpcEnable = 0;
           motion_controller_withPIC_B.isMpcEnable < 99;
           motion_controller_withPIC_B.isMpcEnable++) {
        motion_controller_withPIC_DW.data100[motion_controller_withPIC_B.isMpcEnable]
          =
          motion_controller_withPIC_DW.data100[motion_controller_withPIC_B.isMpcEnable
          + 1];
      }

      motion_controller_withPIC_DW.data100[99] =
        motion_controller_withPIC_B.In1_f.angular_velocity.z;
      memset(&motion_controller_withPIC_B.x[0], 0, 100U * sizeof(real_T));
      for (motion_controller_withPIC_B.b_kidx = 0;
           motion_controller_withPIC_B.b_kidx < 50;
           motion_controller_withPIC_B.b_kidx++) {
        motion_controller_withPIC_B.p_k = ((motion_controller_withPIC_B.b_kidx +
          50) / 2) << 1;
        motion_controller_withPIC_B.isMpcEnable =
          motion_controller_withPIC_B.p_k - 2;
        for (motion_controller_withPIC_B.i = 0; motion_controller_withPIC_B.i <=
             motion_controller_withPIC_B.isMpcEnable;
             motion_controller_withPIC_B.i += 2) {
          tmp_5 = _mm_loadu_pd(&motion_controller_withPIC_DW.data100
                               [(motion_controller_withPIC_B.i -
            motion_controller_withPIC_B.b_kidx) + 50]);
          tmp_5 = _mm_mul_pd(tmp_5, _mm_set1_pd
                             (motion_controller_withPIC_DW.gaussian_kernel100[motion_controller_withPIC_B.b_kidx]));
          tmp_4 = _mm_loadu_pd
            (&motion_controller_withPIC_B.x[motion_controller_withPIC_B.i]);
          _mm_storeu_pd
            (&motion_controller_withPIC_B.x[motion_controller_withPIC_B.i],
             _mm_add_pd(tmp_5, tmp_4));
        }

        for (motion_controller_withPIC_B.i = motion_controller_withPIC_B.p_k;
             motion_controller_withPIC_B.i <= motion_controller_withPIC_B.b_kidx
             + 49; motion_controller_withPIC_B.i++) {
          motion_controller_withPIC_B.x[motion_controller_withPIC_B.i] +=
            motion_controller_withPIC_DW.data100[(motion_controller_withPIC_B.i
            - motion_controller_withPIC_B.b_kidx) + 50] *
            motion_controller_withPIC_DW.gaussian_kernel100[motion_controller_withPIC_B.b_kidx];
        }
      }

      for (motion_controller_withPIC_B.p_k = 0; motion_controller_withPIC_B.p_k <
           50; motion_controller_withPIC_B.p_k++) {
        motion_controller_withPIC_B.isMpcEnable = 99 -
          motion_controller_withPIC_B.p_k;
        for (motion_controller_withPIC_B.b_kidx = 0;
             motion_controller_withPIC_B.b_kidx <=
             motion_controller_withPIC_B.isMpcEnable;
             motion_controller_withPIC_B.b_kidx++) {
          motion_controller_withPIC_B.i = motion_controller_withPIC_B.p_k +
            motion_controller_withPIC_B.b_kidx;
          motion_controller_withPIC_B.x[motion_controller_withPIC_B.i] +=
            motion_controller_withPIC_DW.gaussian_kernel100[motion_controller_withPIC_B.p_k
            + 50] *
            motion_controller_withPIC_DW.data100[motion_controller_withPIC_B.b_kidx];
        }
      }

      motion_controller_withPIC_B.k = 100;
      memcpy(&motion_controller_withPIC_B.t_data[0],
             &motion_controller_withPIC_B.x[0], 100U * sizeof(real_T));
    } else {
      for (motion_controller_withPIC_B.isMpcEnable = 0;
           motion_controller_withPIC_B.isMpcEnable < 199;
           motion_controller_withPIC_B.isMpcEnable++) {
        motion_controller_withPIC_DW.data200[motion_controller_withPIC_B.isMpcEnable]
          =
          motion_controller_withPIC_DW.data200[motion_controller_withPIC_B.isMpcEnable
          + 1];
      }

      motion_controller_withPIC_DW.data200[199] =
        motion_controller_withPIC_B.In1_f.angular_velocity.z;
      memset(&motion_controller_withPIC_B.t_data[0], 0, 200U * sizeof(real_T));
      for (motion_controller_withPIC_B.b_kidx = 0;
           motion_controller_withPIC_B.b_kidx < 100;
           motion_controller_withPIC_B.b_kidx++) {
        motion_controller_withPIC_B.p_k = ((motion_controller_withPIC_B.b_kidx +
          100) / 2) << 1;
        motion_controller_withPIC_B.isMpcEnable =
          motion_controller_withPIC_B.p_k - 2;
        for (motion_controller_withPIC_B.i = 0; motion_controller_withPIC_B.i <=
             motion_controller_withPIC_B.isMpcEnable;
             motion_controller_withPIC_B.i += 2) {
          tmp_5 = _mm_loadu_pd(&motion_controller_withPIC_DW.data200
                               [(motion_controller_withPIC_B.i -
            motion_controller_withPIC_B.b_kidx) + 100]);
          tmp_5 = _mm_mul_pd(tmp_5, _mm_set1_pd
                             (motion_controller_withPIC_DW.gaussian_kernel200[motion_controller_withPIC_B.b_kidx]));
          tmp_4 = _mm_loadu_pd
            (&motion_controller_withPIC_B.t_data[motion_controller_withPIC_B.i]);
          _mm_storeu_pd
            (&motion_controller_withPIC_B.t_data[motion_controller_withPIC_B.i],
             _mm_add_pd(tmp_5, tmp_4));
        }

        for (motion_controller_withPIC_B.i = motion_controller_withPIC_B.p_k;
             motion_controller_withPIC_B.i <= motion_controller_withPIC_B.b_kidx
             + 99; motion_controller_withPIC_B.i++) {
          motion_controller_withPIC_B.t_data[motion_controller_withPIC_B.i] +=
            motion_controller_withPIC_DW.data200[(motion_controller_withPIC_B.i
            - motion_controller_withPIC_B.b_kidx) + 100] *
            motion_controller_withPIC_DW.gaussian_kernel200[motion_controller_withPIC_B.b_kidx];
        }
      }

      for (motion_controller_withPIC_B.p_k = 0; motion_controller_withPIC_B.p_k <
           100; motion_controller_withPIC_B.p_k++) {
        motion_controller_withPIC_B.c_jz = 199 - motion_controller_withPIC_B.p_k;
        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable <=
             motion_controller_withPIC_B.c_jz;
             motion_controller_withPIC_B.isMpcEnable++) {
          motion_controller_withPIC_B.b_kidx = motion_controller_withPIC_B.p_k +
            motion_controller_withPIC_B.isMpcEnable;
          motion_controller_withPIC_B.t_data[motion_controller_withPIC_B.b_kidx]
            +=
            motion_controller_withPIC_DW.gaussian_kernel200[motion_controller_withPIC_B.p_k
            + 100] *
            motion_controller_withPIC_DW.data200[motion_controller_withPIC_B.isMpcEnable];
        }
      }

      motion_controller_withPIC_B.k = 200;
    }

    motion_controller_withPIC_B.y_g =
      motion_controller_withPIC_B.t_data[motion_controller_withPIC_B.k - 1];
  } else {
    motion_controller_withPIC_DW.yd = (1.0 -
      motion_controller_withPIC_B.b_value_p5) * motion_controller_withPIC_DW.yd
      + motion_controller_withPIC_B.b_value_p5 *
      motion_controller_withPIC_B.In1_f.angular_velocity.z;
    motion_controller_withPIC_B.y_g = motion_controller_withPIC_DW.yd;
  }

  // End of MATLAB Function: '<Root>/MATLAB Function2'

  // MATLABSystem: '<Root>/Get Parameter7'
  ParamGet_motion_controller_withPIC_605.getParameter
    (&motion_controller_withPIC_B.b_value_c0);

  // MATLABSystem: '<Root>/Get Parameter8'
  ParamGet_motion_controller_withPIC_606.getParameter
    (&motion_controller_withPIC_B.b_value_ct);

  // Chart: '<Root>/Chart' incorporates:
  //   MATLABSystem: '<Root>/Get Parameter7'
  //   MATLABSystem: '<Root>/Get Parameter8'

  if (motion_controller_withPIC_DW.is_active_c18_motion_controller == 0U) {
    motion_controller_withPIC_DW.is_active_c18_motion_controller = 1U;
    motion_controller_withPIC_DW.is_c18_motion_controller_withPI =
      motion_controller_withPI_IN_ini;
    motion_controller_withPIC_B.p_k = 0;
    motion_controller_withPIC_B.isMpcEnable = 0;
    motion_controller_withPIC_DW.enable_b = 0.0;
    motion_controller_withPIC_DW.Ay_l =
      motion_controller_withPIC_B.In1_f.linear_acceleration.y;
    motion_controller_withPIC_DW.r_l = motion_controller_withPIC_B.y_g;
  } else {
    switch (motion_controller_withPIC_DW.is_c18_motion_controller_withPI) {
     case motion_controller_withPI_IN_ini:
      motion_controller_withPIC_B.p_k = 0;
      motion_controller_withPIC_B.isMpcEnable = 0;
      if (motion_controller_withPIC_DW.enable_b >= 3.0) {
        motion_controller_withPIC_DW.is_c18_motion_controller_withPI =
          motion_controller_with_IN_saver;
        motion_controller_withPIC_B.p_k = 1;
        motion_controller_withPIC_DW.delay_a = 0.0;
      } else {
        if (fabs(motion_controller_withPIC_B.In1_f.linear_acceleration.y -
                 motion_controller_withPIC_DW.Ay_l) >
            motion_controller_withPIC_B.b_value_c0) {
          if (fabs(motion_controller_withPIC_B.y_g -
                   motion_controller_withPIC_DW.r_l) >
              motion_controller_withPIC_B.b_value_ct) {
            motion_controller_withPIC_DW.enable_b++;
          } else {
            motion_controller_withPIC_DW.enable_b = 0.0;
          }
        } else {
          motion_controller_withPIC_DW.enable_b = 0.0;
        }

        motion_controller_withPIC_DW.Ay_l =
          motion_controller_withPIC_B.In1_f.linear_acceleration.y;
        motion_controller_withPIC_DW.r_l = motion_controller_withPIC_B.y_g;
      }
      break;

     case motion_controller_with_IN_saver:
      motion_controller_withPIC_B.p_k = 1;
      motion_controller_withPIC_B.isMpcEnable = 0;
      if (motion_controller_withPIC_B.Compare) {
        motion_controller_withPIC_DW.is_c18_motion_controller_withPI =
          motion_controller_withPI_IN_ini;
        motion_controller_withPIC_B.p_k = 0;
        motion_controller_withPIC_DW.enable_b = 0.0;
        motion_controller_withPIC_DW.Ay_l =
          motion_controller_withPIC_B.In1_f.linear_acceleration.y;
        motion_controller_withPIC_DW.r_l = motion_controller_withPIC_B.y_g;
      } else if (motion_controller_withPIC_DW.delay_a > 2.0) {
        motion_controller_withPIC_DW.is_c18_motion_controller_withPI =
          motion_controller_wi_IN_testing;
        motion_controller_withPIC_B.isMpcEnable = 1;
      } else {
        motion_controller_withPIC_DW.delay_a++;
      }
      break;

     default:
      // case IN_testing:
      motion_controller_withPIC_B.p_k = 1;
      motion_controller_withPIC_B.isMpcEnable = 1;
      if (motion_controller_withPIC_B.Compare) {
        motion_controller_withPIC_DW.is_c18_motion_controller_withPI =
          motion_controller_withPI_IN_ini;
        motion_controller_withPIC_B.p_k = 0;
        motion_controller_withPIC_B.isMpcEnable = 0;
        motion_controller_withPIC_DW.enable_b = 0.0;
        motion_controller_withPIC_DW.Ay_l =
          motion_controller_withPIC_B.In1_f.linear_acceleration.y;
        motion_controller_withPIC_DW.r_l = motion_controller_withPIC_B.y_g;
      }
      break;
    }
  }

  // End of Chart: '<Root>/Chart'

  // MATLABSystem: '<S9>/Get Parameter22'
  ParamGet_motion_controller_withPIC_946.getParameter
    (&motion_controller_withPIC_B.b_value_c0);

  // MATLABSystem: '<S9>/Get Parameter1'
  ParamGet_motion_controller_withPIC_948.getParameter
    (&motion_controller_withPIC_B.b_value_ct);

  // MATLAB Function: '<S9>/MATLAB Function1' incorporates:
  //   MATLABSystem: '<S9>/Get Parameter1'
  //   MATLABSystem: '<S9>/Get Parameter22'

  motion_controller_withPIC_B.alpha1 = fabs
    (motion_controller_withPIC_B.b_value_c0);
  motion_controller_withPIC_B.alpha1_tmp = fabs
    (motion_controller_withPIC_B.In1_je.twist.twist.linear.x);
  if (motion_controller_withPIC_B.alpha1_tmp <
      motion_controller_withPIC_B.alpha1) {
    motion_controller_withPIC_B.vxp = 0.0;
  } else {
    if (rtIsNaN(motion_controller_withPIC_B.In1_je.twist.twist.linear.x)) {
      motion_controller_withPIC_B.alpha1_tmp_k = (rtNaN);
    } else if (motion_controller_withPIC_B.In1_je.twist.twist.linear.x < 0.0) {
      motion_controller_withPIC_B.alpha1_tmp_k = -1.0;
    } else {
      motion_controller_withPIC_B.alpha1_tmp_k =
        (motion_controller_withPIC_B.In1_je.twist.twist.linear.x > 0.0);
    }

    motion_controller_withPIC_B.vxp = (motion_controller_withPIC_B.alpha1_tmp -
      motion_controller_withPIC_B.alpha1) *
      motion_controller_withPIC_B.alpha1_tmp_k;
  }

  motion_controller_withPIC_B.alpha1 = fabs
    (motion_controller_withPIC_B.b_value_ct);
  motion_controller_withPIC_B.alpha1_tmp = fabs
    (motion_controller_withPIC_B.In1_je.twist.twist.linear.y);
  if (motion_controller_withPIC_B.alpha1_tmp <
      motion_controller_withPIC_B.alpha1) {
    motion_controller_withPIC_B.vyp = 0.0;
  } else {
    if (rtIsNaN(motion_controller_withPIC_B.In1_je.twist.twist.linear.y)) {
      motion_controller_withPIC_B.alpha1_tmp_k = (rtNaN);
    } else if (motion_controller_withPIC_B.In1_je.twist.twist.linear.y < 0.0) {
      motion_controller_withPIC_B.alpha1_tmp_k = -1.0;
    } else {
      motion_controller_withPIC_B.alpha1_tmp_k =
        (motion_controller_withPIC_B.In1_je.twist.twist.linear.y > 0.0);
    }

    motion_controller_withPIC_B.vyp = (motion_controller_withPIC_B.alpha1_tmp -
      motion_controller_withPIC_B.alpha1) *
      motion_controller_withPIC_B.alpha1_tmp_k;
  }

  // End of MATLAB Function: '<S9>/MATLAB Function1'

  // MATLABSystem: '<Root>/Get Parameter6'
  ParamGet_motion_controller_withPIC_907.getParameter
    (&motion_controller_withPIC_B.b_value_c0);

  // Sum: '<Root>/Add' incorporates:
  //   MATLABSystem: '<Root>/Get Parameter6'

  motion_controller_withPIC_B.Add = motion_controller_withPIC_B.vxp +
    motion_controller_withPIC_B.b_value_c0;

  // MATLABSystem: '<S13>/Get Parameter20'
  ParamGet_motion_controller_withPIC_916.getParameter
    (&motion_controller_withPIC_B.b_value_c0);

  // Sum: '<S13>/Add1' incorporates:
  //   Constant: '<S13>/Constant1'
  //   MATLABSystem: '<S13>/Get Parameter20'
  //   Product: '<S13>/Product'
  //   Sum: '<S13>/Add2'

  motion_controller_withPIC_B.Add1 = motion_controller_withPIC_B.vyp -
    (motion_controller_withPIC_P.Constant1_Value_n +
     motion_controller_withPIC_B.b_value_c0) * motion_controller_withPIC_B.y_g;

  // Outputs for Enabled SubSystem: '<Root>/picController' incorporates:
  //   EnablePort: '<S16>/Enable'

  // Trigonometry: '<S12>/Cos1' incorporates:
  //   MATLAB Function: '<S16>/update'

  motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp = cos
    (motion_controller_withPIC_B.yaw);

  // Trigonometry: '<S12>/Cos' incorporates:
  //   MATLAB Function: '<S16>/update'

  motion_controller_withPIC_B.rtb_Add_i_tmp_tmp = sin
    (motion_controller_withPIC_B.yaw);

  // End of Outputs for SubSystem: '<Root>/picController'

  // Sum: '<S12>/Add' incorporates:
  //   Product: '<S12>/Product3'
  //   Product: '<S12>/Product4'
  //   Trigonometry: '<S12>/Cos'
  //   Trigonometry: '<S12>/Cos1'

  motion_controller_withPIC_B.Add_i =
    motion_controller_withPIC_B.rtb_Add_i_tmp_tmp *
    motion_controller_withPIC_B.Add +
    motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp *
    motion_controller_withPIC_B.Add1;

  // BusAssignment: '<S5>/Bus Assignment2' incorporates:
  //   Constant: '<S19>/Constant'

  motion_controller_withPIC_B.BusAssignment2_i =
    motion_controller_withPIC_P.Constant_Value_a;
  motion_controller_withPIC_B.BusAssignment2_i.linear.y =
    motion_controller_withPIC_B.yp;
  motion_controller_withPIC_B.BusAssignment2_i.angular.z =
    motion_controller_withPIC_B.yaw;
  motion_controller_withPIC_B.BusAssignment2_i.linear.x =
    motion_controller_withPIC_B.isMpcEnable;
  motion_controller_withPIC_B.BusAssignment2_i.angular.y =
    motion_controller_withPIC_B.Add_i;

  // MATLABSystem: '<S20>/SinkBlock'
  Pub_motion_controller_withPIC_545.publish
    (&motion_controller_withPIC_B.BusAssignment2_i);

  // MATLABSystem: '<S33>/SourceBlock'
  motion_controller_withPIC_B.b_value_k1 =
    Sub_motion_controller_withPIC_516.getLatestMessage
    (&motion_controller_withPIC_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S33>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S36>/Enable'

  // Start for MATLABSystem: '<S33>/SourceBlock'
  if (motion_controller_withPIC_B.b_value_k1) {
    // SignalConversion generated from: '<S36>/In1'
    motion_controller_withPIC_B.In1_j =
      motion_controller_withPIC_B.b_varargout_2;
  }

  // End of Start for MATLABSystem: '<S33>/SourceBlock'
  // End of Outputs for SubSystem: '<S33>/Enabled Subsystem'

  // Outputs for Iterator SubSystem: '<S9>/For Each Subsystem' incorporates:
  //   ForEach: '<S28>/For Each'

  for (motion_controller_withPIC_B.ForEach_itr_c = 0;
       motion_controller_withPIC_B.ForEach_itr_c < 16;
       motion_controller_withPIC_B.ForEach_itr_c++) {
    // ForEachSliceAssignment generated from: '<S28>/Out1' incorporates:
    //   ForEachSliceSelector generated from: '<S28>/In1'

    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[motion_controller_withPIC_B.ForEach_itr_c]
      =
      motion_controller_withPIC_B.In1_j.actuator_state[motion_controller_withPIC_B.ForEach_itr_c]
      .position;
  }

  // End of Outputs for SubSystem: '<S9>/For Each Subsystem'

  // MATLABSystem: '<Root>/Get Parameter17'
  ParamGet_motion_controller_withPIC_910.getParameter
    (&motion_controller_withPIC_B.b_value_k1);

  // Switch: '<Root>/Switch' incorporates:
  //   MATLABSystem: '<Root>/Get Parameter17'

  if (motion_controller_withPIC_B.b_value_k1) {
    // DeadZone: '<Root>/Dead Zone'
    if (motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[0] >
        motion_controller_withPIC_P.DeadZone_End) {
      motion_controller_withPIC_B.Switch[0] =
        motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[0] -
        motion_controller_withPIC_P.DeadZone_End;
    } else if (motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[0] >=
               motion_controller_withPIC_P.DeadZone_Start) {
      motion_controller_withPIC_B.Switch[0] = 0.0;
    } else {
      motion_controller_withPIC_B.Switch[0] =
        motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[0] -
        motion_controller_withPIC_P.DeadZone_Start;
    }

    if (motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[1] >
        motion_controller_withPIC_P.DeadZone_End) {
      motion_controller_withPIC_B.Switch[1] =
        motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[1] -
        motion_controller_withPIC_P.DeadZone_End;
    } else if (motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[1] >=
               motion_controller_withPIC_P.DeadZone_Start) {
      motion_controller_withPIC_B.Switch[1] = 0.0;
    } else {
      motion_controller_withPIC_B.Switch[1] =
        motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[1] -
        motion_controller_withPIC_P.DeadZone_Start;
    }

    if (motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[2] >
        motion_controller_withPIC_P.DeadZone_End) {
      motion_controller_withPIC_B.Switch[2] =
        motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[2] -
        motion_controller_withPIC_P.DeadZone_End;
    } else if (motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[2] >=
               motion_controller_withPIC_P.DeadZone_Start) {
      motion_controller_withPIC_B.Switch[2] = 0.0;
    } else {
      motion_controller_withPIC_B.Switch[2] =
        motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[2] -
        motion_controller_withPIC_P.DeadZone_Start;
    }

    if (motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[3] >
        motion_controller_withPIC_P.DeadZone_End) {
      motion_controller_withPIC_B.Switch[3] =
        motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[3] -
        motion_controller_withPIC_P.DeadZone_End;
    } else if (motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[3] >=
               motion_controller_withPIC_P.DeadZone_Start) {
      motion_controller_withPIC_B.Switch[3] = 0.0;
    } else {
      motion_controller_withPIC_B.Switch[3] =
        motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[3] -
        motion_controller_withPIC_P.DeadZone_Start;
    }

    // End of DeadZone: '<Root>/Dead Zone'
  } else {
    motion_controller_withPIC_B.Switch[0] =
      motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[0];
    motion_controller_withPIC_B.Switch[1] =
      motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[1];
    motion_controller_withPIC_B.Switch[2] =
      motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[2];
    motion_controller_withPIC_B.Switch[3] =
      motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[3];
  }

  // End of Switch: '<Root>/Switch'

  // MATLAB Function: '<Root>/MATLAB Function'
  motion_controller_withPIC_B.df_j = (motion_controller_withPIC_B.Switch[0] +
    motion_controller_withPIC_B.Switch[1]) / 2.0;
  motion_controller_withPIC_B.dr_i = (motion_controller_withPIC_B.Switch[2] +
    motion_controller_withPIC_B.Switch[3]) / 2.0;

  // MATLABSystem: '<Root>/Get Parameter9'
  ParamGet_motion_controller_withPIC_614.getParameter
    (&motion_controller_withPIC_B.b_value_c0);

  // MATLABSystem: '<Root>/Get Parameter10'
  ParamGet_motion_controller_withPIC_615.getParameter
    (&motion_controller_withPIC_B.b_value_ct);

  // MATLABSystem: '<Root>/Get Parameter11'
  ParamGet_motion_controller_withPIC_616.getParameter
    (&motion_controller_withPIC_B.b_value_p);

  // MATLABSystem: '<Root>/Get Parameter12'
  ParamGet_motion_controller_withPIC_617.getParameter
    (&motion_controller_withPIC_B.b_value_p5);

  // MATLABSystem: '<Root>/Get Parameter13'
  ParamGet_motion_controller_withPIC_618.getParameter
    (&motion_controller_withPIC_B.b_value_af);

  // MATLABSystem: '<Root>/Get Parameter14'
  ParamGet_motion_controller_withPIC_619.getParameter
    (&motion_controller_withPIC_B.b_value_e);

  // MATLAB Function: '<Root>/update' incorporates:
  //   MATLAB Function: '<S16>/update'
  //   MATLABSystem: '<Root>/Get Parameter10'
  //   MATLABSystem: '<Root>/Get Parameter11'
  //   MATLABSystem: '<Root>/Get Parameter12'
  //   MATLABSystem: '<Root>/Get Parameter13'
  //   MATLABSystem: '<Root>/Get Parameter14'
  //   MATLABSystem: '<Root>/Get Parameter9'
  //   Trigonometry: '<S12>/Cos1'

  motion_controller_withPIC_B.alpha1_tmp = motion_controller_withPIC_P.B / 2.0 *
    motion_controller_withPIC_B.y_g;
  motion_controller_withPIC_B.alpha1_tmp_k = motion_controller_withPIC_B.Add -
    motion_controller_withPIC_B.alpha1_tmp;

  // Outputs for Enabled SubSystem: '<Root>/picController' incorporates:
  //   EnablePort: '<S16>/Enable'

  motion_controller_withPIC_B.alpha1_tmp_f = motion_controller_withPIC_B.Add *
    sin(motion_controller_withPIC_B.yaw);

  // End of Outputs for SubSystem: '<Root>/picController'
  motion_controller_withPIC_B.alpha1 = rt_atan2d_snf
    ((motion_controller_withPIC_B.Add_i -
      motion_controller_withPIC_B.alpha1_tmp_f) /
     motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp +
     motion_controller_withPIC_P.a * motion_controller_withPIC_B.y_g,
     motion_controller_withPIC_B.alpha1_tmp_k) -
    motion_controller_withPIC_B.df_j;
  motion_controller_withPIC_B.alpha2_tmp =
    motion_controller_withPIC_B.alpha1_tmp + motion_controller_withPIC_B.Add;
  motion_controller_withPIC_B.alpha1_tmp = rt_atan2d_snf
    ((motion_controller_withPIC_B.Add_i - motion_controller_withPIC_B.Add * sin
      (motion_controller_withPIC_B.yaw)) / cos(motion_controller_withPIC_B.yaw)
     + motion_controller_withPIC_P.a * motion_controller_withPIC_B.y_g,
     motion_controller_withPIC_B.alpha2_tmp) - motion_controller_withPIC_B.df_j;
  motion_controller_withPIC_B.Add_i = (motion_controller_withPIC_B.Add_i -
    motion_controller_withPIC_B.Add * sin(motion_controller_withPIC_B.yaw)) /
    cos(motion_controller_withPIC_B.yaw) - motion_controller_withPIC_P.b *
    motion_controller_withPIC_B.y_g;
  motion_controller_withPIC_B.alpha1_tmp_k = rt_atan2d_snf
    (motion_controller_withPIC_B.Add_i, motion_controller_withPIC_B.alpha1_tmp_k)
    - motion_controller_withPIC_B.dr_i;
  motion_controller_withPIC_B.alpha2_tmp = rt_atan2d_snf
    (motion_controller_withPIC_B.Add_i, motion_controller_withPIC_B.alpha2_tmp)
    - motion_controller_withPIC_B.dr_i;
  motion_controller_withPIC_B.Add_i = motion_controller_withPIC_P.m *
    motion_controller_withPIC_P.g;
  motion_controller_withPIC_B.Fy1_tmp_tmp = motion_controller_withPIC_P.m *
    motion_controller_withPIC_B.In1_f.linear_acceleration.x *
    motion_controller_withPIC_P.hCG;
  motion_controller_withPIC_B.b_value_o = (motion_controller_withPIC_B.Add_i *
    motion_controller_withPIC_P.b - motion_controller_withPIC_B.Fy1_tmp_tmp) /
    2.0 / motion_controller_withPIC_P.L;
  motion_controller_withPIC_B.Gain2 = motion_controller_withPIC_P.Krsf *
    motion_controller_withPIC_P.m *
    motion_controller_withPIC_B.In1_f.linear_acceleration.y *
    motion_controller_withPIC_P.hCG / motion_controller_withPIC_P.B;

  // Outputs for Enabled SubSystem: '<Root>/picController' incorporates:
  //   EnablePort: '<S16>/Enable'

  motion_controller_withPIC_B.Fy1_tmp = (motion_controller_withPIC_B.b_value_o -
    motion_controller_withPIC_B.Gain2) * motion_controller_withPIC_B.b_value_p;

  // End of Outputs for SubSystem: '<Root>/picController'
  motion_controller_withPIC_B.b_value_o2 = sin(atan
    (motion_controller_withPIC_B.b_value_c0 * sin
     (motion_controller_withPIC_B.alpha1)) *
    motion_controller_withPIC_B.b_value_ct) *
    motion_controller_withPIC_B.Fy1_tmp;

  // Outputs for Enabled SubSystem: '<Root>/picController' incorporates:
  //   EnablePort: '<S16>/Enable'

  motion_controller_withPIC_B.Fy2_tmp = (motion_controller_withPIC_B.b_value_o +
    motion_controller_withPIC_B.Gain2) * motion_controller_withPIC_B.b_value_p;

  // End of Outputs for SubSystem: '<Root>/picController'
  motion_controller_withPIC_B.b_value_o = sin(atan
    (motion_controller_withPIC_B.b_value_c0 * sin
     (motion_controller_withPIC_B.alpha1_tmp)) *
    motion_controller_withPIC_B.b_value_ct) *
    motion_controller_withPIC_B.Fy2_tmp;
  motion_controller_withPIC_B.Add_i = (motion_controller_withPIC_B.Add_i *
    motion_controller_withPIC_P.a + motion_controller_withPIC_B.Fy1_tmp_tmp) /
    2.0 / motion_controller_withPIC_P.L;
  motion_controller_withPIC_B.Fy1_tmp_tmp = (1.0 -
    motion_controller_withPIC_P.Krsf) * motion_controller_withPIC_P.m *
    motion_controller_withPIC_B.In1_f.linear_acceleration.y *
    motion_controller_withPIC_P.hCG / motion_controller_withPIC_P.B;

  // Outputs for Enabled SubSystem: '<Root>/picController' incorporates:
  //   EnablePort: '<S16>/Enable'

  motion_controller_withPIC_B.Fy3_tmp = (motion_controller_withPIC_B.Add_i -
    motion_controller_withPIC_B.Fy1_tmp_tmp) *
    motion_controller_withPIC_B.b_value_e;

  // End of Outputs for SubSystem: '<Root>/picController'
  motion_controller_withPIC_B.Gain2 = sin(atan
    (motion_controller_withPIC_B.b_value_p5 * sin
     (motion_controller_withPIC_B.alpha1_tmp_k)) *
    motion_controller_withPIC_B.b_value_af) *
    motion_controller_withPIC_B.Fy3_tmp;

  // Outputs for Enabled SubSystem: '<Root>/picController' incorporates:
  //   EnablePort: '<S16>/Enable'

  motion_controller_withPIC_B.Fy4_tmp = (motion_controller_withPIC_B.Add_i +
    motion_controller_withPIC_B.Fy1_tmp_tmp) *
    motion_controller_withPIC_B.b_value_e;

  // End of Outputs for SubSystem: '<Root>/picController'
  motion_controller_withPIC_B.Add_i = sin(atan
    (motion_controller_withPIC_B.b_value_p5 * sin
     (motion_controller_withPIC_B.alpha2_tmp)) *
    motion_controller_withPIC_B.b_value_af) *
    motion_controller_withPIC_B.Fy4_tmp;

  // BusAssignment: '<S6>/Bus Assignment2' incorporates:
  //   Constant: '<S21>/Constant'
  //   MATLAB Function: '<Root>/update'

  motion_controller_withPIC_B.BusAssignment2 =
    motion_controller_withPIC_P.Constant_Value_d;
  motion_controller_withPIC_B.BusAssignment2.orientation.x =
    motion_controller_withPIC_B.alpha1;
  motion_controller_withPIC_B.BusAssignment2.orientation.y =
    motion_controller_withPIC_B.alpha1_tmp;
  motion_controller_withPIC_B.BusAssignment2.orientation.z =
    motion_controller_withPIC_B.alpha1_tmp_k;
  motion_controller_withPIC_B.BusAssignment2.orientation.w =
    motion_controller_withPIC_B.alpha2_tmp;

  // MATLABSystem: '<S22>/SinkBlock'
  Pub_motion_controller_withPIC_831.publish
    (&motion_controller_withPIC_B.BusAssignment2);

  // BusAssignment: '<S7>/Bus Assignment2' incorporates:
  //   Constant: '<S23>/Constant'
  //   MATLAB Function: '<Root>/update'

  motion_controller_withPIC_B.BusAssignment2 =
    motion_controller_withPIC_P.Constant_Value_eh;
  motion_controller_withPIC_B.BusAssignment2.orientation.x =
    motion_controller_withPIC_B.b_value_o2;
  motion_controller_withPIC_B.BusAssignment2.orientation.y =
    motion_controller_withPIC_B.b_value_o;
  motion_controller_withPIC_B.BusAssignment2.orientation.z =
    motion_controller_withPIC_B.Gain2;
  motion_controller_withPIC_B.BusAssignment2.orientation.w =
    motion_controller_withPIC_B.Add_i;

  // Outputs for Enabled SubSystem: '<Root>/picController' incorporates:
  //   EnablePort: '<S16>/Enable'

  // MATLAB Function: '<Root>/update' incorporates:
  //   MATLAB Function: '<S16>/update'

  motion_controller_withPIC_B.alpha1 = cos(motion_controller_withPIC_B.df_j);
  motion_controller_withPIC_B.alpha1_tmp = cos(motion_controller_withPIC_B.dr_i);

  // End of Outputs for SubSystem: '<Root>/picController'

  // BusAssignment: '<S7>/Bus Assignment2' incorporates:
  //   MATLAB Function: '<Root>/update'

  motion_controller_withPIC_B.BusAssignment2.linear_acceleration.y =
    ((motion_controller_withPIC_B.b_value_o2 +
      motion_controller_withPIC_B.b_value_o) *
     motion_controller_withPIC_B.alpha1 + (motion_controller_withPIC_B.Gain2 +
      motion_controller_withPIC_B.Add_i) *
     motion_controller_withPIC_B.alpha1_tmp) * (1.0 /
    motion_controller_withPIC_P.m);

  // Outputs for Enabled SubSystem: '<Root>/picController' incorporates:
  //   EnablePort: '<S16>/Enable'

  // MATLAB Function: '<Root>/update' incorporates:
  //   MATLAB Function: '<S16>/update'

  motion_controller_withPIC_B.alpha1_tmp_k = sin
    (motion_controller_withPIC_B.df_j);
  motion_controller_withPIC_B.alpha2_tmp = sin(motion_controller_withPIC_B.dr_i);

  // End of Outputs for SubSystem: '<Root>/picController'
  motion_controller_withPIC_B.rtb_Add_i_tmp = motion_controller_withPIC_P.a *
    motion_controller_withPIC_B.alpha1;
  motion_controller_withPIC_B.Fy1_tmp_tmp_tmp = motion_controller_withPIC_P.B /
    2.0 * motion_controller_withPIC_B.alpha1_tmp_k;

  // Outputs for Enabled SubSystem: '<Root>/picController' incorporates:
  //   EnablePort: '<S16>/Enable'

  motion_controller_withPIC_B.Fy1_tmp_tmp =
    motion_controller_withPIC_B.rtb_Add_i_tmp -
    motion_controller_withPIC_B.Fy1_tmp_tmp_tmp;

  // End of Outputs for SubSystem: '<Root>/picController'
  motion_controller_withPIC_B.d1 = motion_controller_withPIC_P.B / 2.0 *
    motion_controller_withPIC_B.alpha2_tmp;
  motion_controller_withPIC_B.b_value_ax = -motion_controller_withPIC_P.b *
    motion_controller_withPIC_B.alpha1_tmp;

  // Outputs for Enabled SubSystem: '<Root>/picController' incorporates:
  //   EnablePort: '<S16>/Enable'

  motion_controller_withPIC_B.d_o = motion_controller_withPIC_B.b_value_ax -
    motion_controller_withPIC_B.d1;
  motion_controller_withPIC_B.Fy1_tmp_tmp_tmp +=
    motion_controller_withPIC_B.rtb_Add_i_tmp;
  motion_controller_withPIC_B.d1 += motion_controller_withPIC_B.b_value_ax;

  // End of Outputs for SubSystem: '<Root>/picController'

  // BusAssignment: '<S7>/Bus Assignment2' incorporates:
  //   MATLAB Function: '<Root>/update'

  motion_controller_withPIC_B.BusAssignment2.linear_acceleration.z =
    (((motion_controller_withPIC_B.Fy1_tmp_tmp_tmp *
       motion_controller_withPIC_B.b_value_o2 +
       motion_controller_withPIC_B.Fy1_tmp_tmp *
       motion_controller_withPIC_B.b_value_o) + motion_controller_withPIC_B.d1 *
      motion_controller_withPIC_B.Gain2) + motion_controller_withPIC_B.d_o *
     motion_controller_withPIC_B.Add_i) * (1.0 / motion_controller_withPIC_P.Izz);

  // MATLABSystem: '<S24>/SinkBlock'
  Pub_motion_controller_withPIC_839.publish
    (&motion_controller_withPIC_B.BusAssignment2);

  // BusAssignment: '<S8>/Bus Assignment2' incorporates:
  //   Constant: '<S25>/Constant'

  motion_controller_withPIC_B.BusAssignment2 =
    motion_controller_withPIC_P.Constant_Value_m;
  motion_controller_withPIC_B.BusAssignment2.orientation.x =
    motion_controller_withPIC_B.vxp;
  motion_controller_withPIC_B.BusAssignment2.orientation.y =
    motion_controller_withPIC_B.vyp;
  motion_controller_withPIC_B.BusAssignment2.orientation.z =
    motion_controller_withPIC_B.In1_f.angular_velocity.z;
  motion_controller_withPIC_B.BusAssignment2.orientation.w =
    motion_controller_withPIC_B.y_g;

  // MATLABSystem: '<S26>/SinkBlock'
  Pub_motion_controller_withPIC_932.publish
    (&motion_controller_withPIC_B.BusAssignment2);

  // Logic: '<Root>/Logical Operator'
  motion_controller_withPIC_B.Compare =
    (motion_controller_withPIC_B.In1_m.failsafe ||
     motion_controller_withPIC_B.In1_m.frame_lost);

  // MATLABSystem: '<S70>/SourceBlock'
  motion_controller_withPIC_B.b_value_k1 =
    Sub_motion_controller_withPIC_238.getLatestMessage
    (&motion_controller_withPIC_B.b_varargout_2);

  // Logic: '<S17>/Logical Operator' incorporates:
  //   MATLABSystem: '<S69>/SourceBlock'
  //   MATLABSystem: '<S70>/SourceBlock'
  //
  motion_controller_withPIC_B.LogicalOperator_j =
    (motion_controller_withPIC_B.LogicalOperator_j &&
     motion_controller_withPIC_B.b_value_k1);

  // Outputs for Enabled SubSystem: '<S70>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S73>/Enable'

  // Start for MATLABSystem: '<S70>/SourceBlock'
  if (motion_controller_withPIC_B.b_value_k1) {
    // SignalConversion generated from: '<S73>/In1'
    motion_controller_withPIC_B.In1 = motion_controller_withPIC_B.b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S70>/Enabled Subsystem'

  // Outputs for Iterator SubSystem: '<S17>/For Each Subsystem' incorporates:
  //   ForEach: '<S68>/For Each'

  for (motion_controller_withPIC_B.ForEach_itr = 0;
       motion_controller_withPIC_B.ForEach_itr < 16;
       motion_controller_withPIC_B.ForEach_itr++) {
    // ForEachSliceAssignment generated from: '<S68>/Out1' incorporates:
    //   ForEachSliceSelector generated from: '<S68>/In1'

    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[motion_controller_withPIC_B.ForEach_itr]
      =
      motion_controller_withPIC_B.In1.actuator_state[motion_controller_withPIC_B.ForEach_itr]
      .velocity;
  }

  // End of Outputs for SubSystem: '<S17>/For Each Subsystem'

  // Outputs for Atomic SubSystem: '<Root>/controller'
  // MATLABSystem: '<S47>/Get Parameter4'
  ParamGet_motion_controller_withPIC_298.getParameter
    (&motion_controller_withPIC_B.b_value_o);

  // MATLABSystem: '<S47>/Get Parameter2'
  ParamGet_motion_controller_withPIC_301.getParameter
    (&motion_controller_withPIC_B.b_value_k1);

  // MATLABSystem: '<S47>/Get Parameter3'
  ParamGet_motion_controller_withPIC_194.getParameter
    (&motion_controller_withPIC_B.b_value_o2);

  // Switch: '<S47>/Switch' incorporates:
  //   MATLABSystem: '<S47>/Get Parameter2'
  //   SignalConversion generated from: '<S17>/Bus Selector'

  if (motion_controller_withPIC_B.b_value_k1) {
    motion_controller_withPIC_B.i_gr =
      motion_controller_withPIC_B.In1_m.mapped_channels[2];
  } else {
    motion_controller_withPIC_B.i_gr =
      motion_controller_withPIC_B.In1_m.mapped_channels[1];
  }

  // Product: '<S47>/Product1' incorporates:
  //   Constant: '<S47>/Constant2'
  //   Gain: '<S47>/Gain1'
  //   MATLABSystem: '<S47>/Get Parameter3'
  //   Sum: '<S47>/Add1'
  //   Switch: '<S47>/Switch'

  motion_controller_withPIC_B.vyp = (static_cast<real_T>
    (motion_controller_withPIC_B.i_gr) -
    motion_controller_withPIC_P.Constant2_Value) *
    motion_controller_withPIC_P.Gain1_Gain_k *
    motion_controller_withPIC_B.b_value_o2;

  // Chart: '<S47>/Chart2' incorporates:
  //   MATLABSystem: '<S47>/Get Parameter4'

  if (motion_controller_withPIC_DW.is_active_c6_motion_controller_ == 0U) {
    motion_controller_withPIC_DW.is_active_c6_motion_controller_ = 1U;
    motion_controller_withPIC_B.out = 0.0;
  } else {
    motion_controller_withPIC_B.vxp = motion_controller_withPIC_B.vyp -
      motion_controller_withPIC_B.out;
    if (fabs(motion_controller_withPIC_B.vxp) < 0.01 *
        motion_controller_withPIC_B.b_value_o) {
      motion_controller_withPIC_B.out = motion_controller_withPIC_B.vyp;
    } else if (motion_controller_withPIC_B.b_value_o == 0.0) {
      motion_controller_withPIC_B.out = motion_controller_withPIC_B.vyp;
    } else {
      if (rtIsNaN(motion_controller_withPIC_B.vxp)) {
        motion_controller_withPIC_B.Gain2 = (rtNaN);
      } else if (motion_controller_withPIC_B.vxp < 0.0) {
        motion_controller_withPIC_B.Gain2 = -1.0;
      } else {
        motion_controller_withPIC_B.Gain2 = (motion_controller_withPIC_B.vxp >
          0.0);
      }

      motion_controller_withPIC_B.out += motion_controller_withPIC_B.Gain2 *
        motion_controller_withPIC_B.b_value_o * 0.01;
    }
  }

  // End of Chart: '<S47>/Chart2'

  // MATLABSystem: '<S47>/Get Parameter5'
  ParamGet_motion_controller_withPIC_329.getParameter
    (&motion_controller_withPIC_B.b_value_k1);

  // Gain: '<S47>/Gain2' incorporates:
  //   Constant: '<S47>/Constant'
  //   Gain: '<S47>/Gain'
  //   SignalConversion generated from: '<S17>/Bus Selector'
  //   Sum: '<S47>/Add'

  motion_controller_withPIC_B.Gain2 = (static_cast<real_T>
    (motion_controller_withPIC_B.In1_m.mapped_channels[0]) -
    motion_controller_withPIC_P.Constant_Value_ff) *
    motion_controller_withPIC_P.Gain_Gain_f *
    motion_controller_withPIC_P.Gain2_Gain_b;

  // MATLABSystem: '<S47>/Get Parameter1'
  ParamGet_motion_controller_withPIC_317.getParameter
    (&motion_controller_withPIC_B.b_value_o);

  // MATLABSystem: '<S47>/Get Parameter'
  ParamGet_motion_controller_withPIC_316.getParameter
    (&motion_controller_withPIC_B.b_value_o2);

  // MATLAB Function: '<S47>/MATLAB Function' incorporates:
  //   MATLABSystem: '<S47>/Get Parameter'
  //   MATLABSystem: '<S47>/Get Parameter1'
  //   MATLABSystem: '<S47>/Get Parameter5'

  if (motion_controller_withPIC_B.b_value_k1) {
    motion_controller_withPIC_B.vyp = motion_controller_withPIC_B.b_value_o /
      180.0 * 3.1415926535897931 * 0.01 / 2.0;
  } else {
    motion_controller_withPIC_B.vyp = motion_controller_withPIC_B.b_value_o /
      180.0 * 3.1415926535897931 * 0.01;
  }

  motion_controller_withPIC_B.vxp = motion_controller_withPIC_B.Gain2 -
    motion_controller_withPIC_DW.angle_out;
  if (fabs(motion_controller_withPIC_B.vxp) < motion_controller_withPIC_B.vyp) {
    motion_controller_withPIC_DW.angle_out = motion_controller_withPIC_B.Gain2;
  } else if (motion_controller_withPIC_B.b_value_o <= 0.0) {
    motion_controller_withPIC_DW.angle_out = motion_controller_withPIC_B.Gain2;
  } else {
    if (rtIsNaN(motion_controller_withPIC_B.vxp)) {
      motion_controller_withPIC_B.Gain2 = (rtNaN);
    } else if (motion_controller_withPIC_B.vxp < 0.0) {
      motion_controller_withPIC_B.Gain2 = -1.0;
    } else {
      motion_controller_withPIC_B.Gain2 = (motion_controller_withPIC_B.vxp > 0.0);
    }

    motion_controller_withPIC_DW.angle_out += motion_controller_withPIC_B.Gain2 *
      motion_controller_withPIC_B.vyp / motion_controller_withPIC_B.b_value_o2;
  }

  if (motion_controller_withPIC_B.b_value_k1) {
    motion_controller_withPIC_B.vxp = fabs
      (motion_controller_withPIC_DW.angle_out);
    if (rtIsNaN(motion_controller_withPIC_DW.angle_out)) {
      motion_controller_withPIC_B.Gain2 = (rtNaN);
    } else if (motion_controller_withPIC_DW.angle_out < 0.0) {
      motion_controller_withPIC_B.Gain2 = -1.0;
    } else {
      motion_controller_withPIC_B.Gain2 =
        (motion_controller_withPIC_DW.angle_out > 0.0);
    }

    if (!(motion_controller_withPIC_B.vxp <= 0.5)) {
      motion_controller_withPIC_B.vxp = 0.5;
    }

    motion_controller_withPIC_B.vxp = motion_controller_withPIC_B.Gain2 *
      motion_controller_withPIC_B.vxp * 2.0;
    motion_controller_withPIC_B.Gain2 = fabs
      (motion_controller_withPIC_DW.angle_out);
    if (motion_controller_withPIC_B.Gain2 > 0.5) {
      if (rtIsNaN(motion_controller_withPIC_DW.angle_out)) {
        motion_controller_withPIC_B.vyp = (rtNaN);
      } else if (motion_controller_withPIC_DW.angle_out < 0.0) {
        motion_controller_withPIC_B.vyp = -1.0;
      } else {
        motion_controller_withPIC_B.vyp =
          (motion_controller_withPIC_DW.angle_out > 0.0);
      }

      motion_controller_withPIC_B.vyp = (motion_controller_withPIC_B.Gain2 - 0.5)
        * -motion_controller_withPIC_B.vyp * 2.0;
    } else {
      motion_controller_withPIC_B.vyp = 0.0;
    }
  } else {
    motion_controller_withPIC_B.vxp = motion_controller_withPIC_DW.angle_out;
    motion_controller_withPIC_B.vyp = 0.0;
  }

  motion_controller_withPIC_B.vxp *= motion_controller_withPIC_B.b_value_o2;
  motion_controller_withPIC_B.vyp *= motion_controller_withPIC_B.b_value_o2;

  // End of MATLAB Function: '<S47>/MATLAB Function'

  // MATLABSystem: '<S15>/Get Parameter1'
  ParamGet_motion_controller_withPIC_217.getParameter
    (&motion_controller_withPIC_B.GetParameter1);

  // Chart: '<S15>/Chart' incorporates:
  //   Constant: '<S15>/Constant'
  //   SignalConversion generated from: '<S17>/Bus Selector'

  if (motion_controller_withPIC_DW.is_active_c3_motion_controller_ == 0U) {
    motion_controller_withPIC_DW.is_active_c3_motion_controller_ = 1U;
    motion_controller_withPIC_DW.is_Is_ready = motion_controller_withPI_IN_Ini;
    motion_controller_withPIC_DW.check = 1.0;
    motion_controller_withPIC_DW.ready = false;
    motion_controller_withPIC_DW.is_cmd = motion_controller_withPI_IN_Ini;
    motion_controller_withPIC_B.angle_cmd[0] = 0.0;
    motion_controller_withPIC_B.spd_cmd[0] = 0.0;
    motion_controller_withPIC_B.effort_cmd[0] = 0.0;
    motion_controller_withPIC_B.angle_cmd[1] = 0.0;
    motion_controller_withPIC_B.spd_cmd[1] = 0.0;
    motion_controller_withPIC_B.effort_cmd[1] = 0.0;
    motion_controller_withPIC_B.angle_cmd[2] = 0.0;
    motion_controller_withPIC_B.spd_cmd[2] = 0.0;
    motion_controller_withPIC_B.effort_cmd[2] = 0.0;
    motion_controller_withPIC_B.angle_cmd[3] = 0.0;
    motion_controller_withPIC_B.spd_cmd[3] = 0.0;
    motion_controller_withPIC_B.effort_cmd[3] = 0.0;
    motion_controller_withPIC_B.mode = 0;
  } else {
    if (motion_controller_withPIC_DW.is_Is_ready ==
        motion_controller_withPI_IN_Ini) {
      if ((motion_controller_withPIC_B.In1_m.mapped_channels[3] == 1000) &&
          (!motion_controller_withPIC_B.Compare) &&
          motion_controller_withPIC_B.LogicalOperator_j) {
        motion_controller_withPIC_DW.is_Is_ready =
          motion_contro_IN_velocity_mode1;
        motion_controller_withPIC_DW.ready = true;
        motion_controller_withPIC_DW.check = 1.0;
        motion_controller_withPIC_DW.sum = 0.0;
        motion_controller_withPIC_DW.counter = 0.0;
      }

      // case IN_velocity_mode1:
    } else if ((motion_controller_withPIC_B.In1_m.mapped_channels[3] != 1000) ||
               motion_controller_withPIC_B.Compare ||
               (motion_controller_withPIC_DW.check == 0.0)) {
      motion_controller_withPIC_DW.is_Is_ready = motion_controller_withPI_IN_Ini;
      motion_controller_withPIC_DW.check = 1.0;
      motion_controller_withPIC_DW.ready = false;
    } else {
      motion_controller_withPIC_DW.counter++;
      motion_controller_withPIC_DW.sum += static_cast<real_T>
        (motion_controller_withPIC_B.LogicalOperator_j);
      if (rtIsNaN(motion_controller_withPIC_DW.counter)) {
        motion_controller_withPIC_B.b_value_o2 = (rtNaN);
      } else if (rtIsInf(motion_controller_withPIC_DW.counter)) {
        motion_controller_withPIC_B.b_value_o2 = (rtNaN);
      } else if (motion_controller_withPIC_DW.counter == 0.0) {
        motion_controller_withPIC_B.b_value_o2 = 0.0;
      } else {
        motion_controller_withPIC_B.b_value_o2 = fmod
          (motion_controller_withPIC_DW.counter, 20.0);
        if (motion_controller_withPIC_B.b_value_o2 == 0.0) {
          motion_controller_withPIC_B.b_value_o2 = 0.0;
        } else if (motion_controller_withPIC_DW.counter < 0.0) {
          motion_controller_withPIC_B.b_value_o2 += 20.0;
        }
      }

      if (motion_controller_withPIC_B.b_value_o2 == 0.0) {
        motion_controller_withPIC_DW.check = motion_controller_withPIC_DW.sum;
        motion_controller_withPIC_DW.sum = 0.0;
      }
    }

    switch (motion_controller_withPIC_DW.is_cmd) {
     case motion_controller_withPI_IN_Ini:
      if (motion_controller_withPIC_DW.ready) {
        motion_controller_withPIC_DW.is_cmd = motion_control_IN_velocity_mode;
        motion_controller_withPIC_B.effort_cmd[0] = 0.0;
        motion_controller_withPIC_B.effort_cmd[1] = 0.0;
        motion_controller_withPIC_B.effort_cmd[2] = 0.0;
        motion_controller_withPIC_B.effort_cmd[3] = 0.0;
      }
      break;

     case motion_controlle_IN_effort_mode:
      if ((motion_controller_withPIC_B.In1_m.mapped_channels[4] != 1000) ||
          (!motion_controller_withPIC_DW.ready)) {
        motion_controller_withPIC_DW.is_effort_mode =
          motion_contr_IN_NO_ACTIVE_CHILD;
        motion_controller_withPIC_DW.is_cmd = motion_control_IN_velocity_mode;
        motion_controller_withPIC_B.effort_cmd[0] = 0.0;
        motion_controller_withPIC_B.effort_cmd[1] = 0.0;
        motion_controller_withPIC_B.effort_cmd[2] = 0.0;
        motion_controller_withPIC_B.effort_cmd[3] = 0.0;
      } else if (motion_controller_withPIC_DW.is_effort_mode ==
                 motion_controller_wi_IN_braking) {
        if (motion_controller_withPIC_B.out >= 0.0) {
          motion_controller_withPIC_DW.is_effort_mode =
            motion_controller_wi_IN_forward;
          motion_controller_withPIC_B.spd_cmd[0] = 0.0;
          motion_controller_withPIC_B.spd_cmd[1] = 0.0;
          motion_controller_withPIC_B.spd_cmd[2] = 0.0;
          motion_controller_withPIC_B.spd_cmd[3] = 0.0;
        } else {
          motion_controller_withPIC_B.b_value_o2 = 1.5 * fabs
            (motion_controller_withPIC_B.out);
          motion_controller_withPIC_B.b_value_o =
            (((motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[0] +
               motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[1]) +
              motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[2]) +
             motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[3]) / 4.0;
          if (fabs(motion_controller_withPIC_B.b_value_o) < 0.5) {
            motion_controller_withPIC_B.mode = 1;
            motion_controller_withPIC_B.spd_cmd[0] = 0.0;
            motion_controller_withPIC_B.spd_cmd[1] = 0.0;
            motion_controller_withPIC_B.spd_cmd[2] = 0.0;
            motion_controller_withPIC_B.spd_cmd[3] = 0.0;
            motion_controller_withPIC_B.b_value_o2 = 0.0;
          } else if (motion_controller_withPIC_B.b_value_o > 0.5) {
            motion_controller_withPIC_B.b_value_o2 =
              -motion_controller_withPIC_B.b_value_o2;
            motion_controller_withPIC_B.mode = 2;
          } else if (motion_controller_withPIC_B.b_value_o < -0.5) {
            motion_controller_withPIC_B.mode = 2;
          }

          motion_controller__get_angle_4w(motion_controller_withPIC_B.vxp,
            motion_controller_withPIC_B.vyp,
            motion_controller_withPIC_B.angle_cmd);
          motion_controller_withPIC_B.effort_cmd[0] =
            motion_controller_withPIC_B.b_value_o2 * 1.6;
          motion_controller_withPIC_B.vxp =
            -motion_controller_withPIC_B.b_value_o2 * 1.6;
          motion_controller_withPIC_B.effort_cmd[1] =
            motion_controller_withPIC_B.vxp;
          motion_controller_withPIC_B.effort_cmd[2] =
            motion_controller_withPIC_B.vxp;
          motion_controller_withPIC_B.effort_cmd[3] =
            motion_controller_withPIC_B.b_value_o2 * 1.6;
        }

        // case IN_forward:
      } else if (motion_controller_withPIC_B.out < -0.01) {
        motion_controller_withPIC_DW.is_effort_mode =
          motion_controller_wi_IN_braking;
        motion_controller_withPIC_B.spd_cmd[0] = 0.0;
        motion_controller_withPIC_B.spd_cmd[1] = 0.0;
        motion_controller_withPIC_B.spd_cmd[2] = 0.0;
        motion_controller_withPIC_B.spd_cmd[3] = 0.0;
      } else {
        motion_controller__get_angle_4w(motion_controller_withPIC_B.vxp,
          motion_controller_withPIC_B.vyp, motion_controller_withPIC_B.angle_cmd);
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_h[0] =
          motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[0] / 0.07;
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_h[1] =
          motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[1] / 0.07;
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_h[2] =
          motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[2] / 0.07;
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_h[3] =
          motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[3] / 0.07;
        if (motion_controller_withPIC_B.In1_m.mapped_channels[6] == 1000) {
          motion_controller_withPIC_B.Gain2 = -0.5 *
            motion_controller_withPIC_B.out;
        } else {
          motion_controller_withPIC_B.Gain2 = motion_controller_withPIC_B.out;
        }

        motion_controller_wi_get_effort(motion_controller_withPIC_B.Gain2,
          motion_controller_withPIC_P.Constant_Value_o,
          motion_controller_withPIC_P.Constant_Value_o,
          motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_h,
          motion_controller_withPIC_B.effort_cmd);
        motion_controller_withPIC_B.mode = 2;
      }
      break;

     case motion_controller_withP_IN_hold:
      if ((motion_controller_withPIC_B.In1_m.mapped_channels[4] != 1000) ||
          (!motion_controller_withPIC_DW.ready)) {
        motion_controller_withPIC_DW.is_cmd = motion_control_IN_velocity_mode;
        motion_controller_withPIC_B.effort_cmd[0] = 0.0;
        motion_controller_withPIC_B.effort_cmd[1] = 0.0;
        motion_controller_withPIC_B.effort_cmd[2] = 0.0;
        motion_controller_withPIC_B.effort_cmd[3] = 0.0;
      }
      break;

     default:
      // case IN_velocity_mode:
      if (!motion_controller_withPIC_DW.ready) {
        motion_controller_withPIC_DW.is_cmd = motion_controller_withPI_IN_Ini;
        motion_controller_withPIC_B.angle_cmd[0] = 0.0;
        motion_controller_withPIC_B.spd_cmd[0] = 0.0;
        motion_controller_withPIC_B.effort_cmd[0] = 0.0;
        motion_controller_withPIC_B.angle_cmd[1] = 0.0;
        motion_controller_withPIC_B.spd_cmd[1] = 0.0;
        motion_controller_withPIC_B.effort_cmd[1] = 0.0;
        motion_controller_withPIC_B.angle_cmd[2] = 0.0;
        motion_controller_withPIC_B.spd_cmd[2] = 0.0;
        motion_controller_withPIC_B.effort_cmd[2] = 0.0;
        motion_controller_withPIC_B.angle_cmd[3] = 0.0;
        motion_controller_withPIC_B.spd_cmd[3] = 0.0;
        motion_controller_withPIC_B.effort_cmd[3] = 0.0;
        motion_controller_withPIC_B.mode = 0;
      } else if ((motion_controller_withPIC_B.In1_m.mapped_channels[6] == 1000) &&
                 (motion_controller_withPIC_B.In1_m.mapped_channels[4] == 1000))
      {
        motion_controller_withPIC_DW.is_cmd = motion_controlle_IN_effort_mode;
        motion_controller_withPIC_DW.is_effort_mode =
          motion_controller_wi_IN_forward;
        motion_controller_withPIC_B.spd_cmd[0] = 0.0;
        motion_controller_withPIC_B.spd_cmd[1] = 0.0;
        motion_controller_withPIC_B.spd_cmd[2] = 0.0;
        motion_controller_withPIC_B.spd_cmd[3] = 0.0;
      } else if (motion_controller_withPIC_B.In1_m.mapped_channels[4] == 1000) {
        motion_controller_withPIC_DW.is_cmd = motion_controller_withP_IN_hold;
        motion_controller_withPIC_B.angle_cmd[0] = 0.0;
        motion_controller_withPIC_B.spd_cmd[0] = 0.0;
        motion_controller_withPIC_B.effort_cmd[0] = 0.0;
        motion_controller_withPIC_B.angle_cmd[1] = 0.0;
        motion_controller_withPIC_B.spd_cmd[1] = 0.0;
        motion_controller_withPIC_B.effort_cmd[1] = 0.0;
        motion_controller_withPIC_B.angle_cmd[2] = 0.0;
        motion_controller_withPIC_B.spd_cmd[2] = 0.0;
        motion_controller_withPIC_B.effort_cmd[2] = 0.0;
        motion_controller_withPIC_B.angle_cmd[3] = 0.0;
        motion_controller_withPIC_B.spd_cmd[3] = 0.0;
        motion_controller_withPIC_B.effort_cmd[3] = 0.0;
        motion_controller_withPIC_B.mode = 0;
      } else {
        motion_controller__get_angle_4w(motion_controller_withPIC_B.vxp,
          motion_controller_withPIC_B.vyp, motion_controller_withPIC_B.angle_cmd);
        motion_controller_withP_get_spd(motion_controller_withPIC_B.vxp,
          motion_controller_withPIC_B.out, motion_controller_withPIC_B.spd_cmd);
        motion_controller_withPIC_B.mode = 1;
      }
      break;
    }
  }

  // End of Chart: '<S15>/Chart'
  // End of Outputs for SubSystem: '<Root>/controller'

  // MATLABSystem: '<S10>/Get Parameter3'
  ParamGet_motion_controller_withPIC_621.getParameter
    (&motion_controller_withPIC_B.b_value_o);

  // MATLABSystem: '<S10>/Get Parameter1'
  ParamGet_motion_controller_withPIC_625.getParameter
    (&motion_controller_withPIC_B.b_value_k1);

  // Switch: '<S10>/Switch2' incorporates:
  //   Gain: '<S10>/Gain'
  //   Gain: '<S10>/Gain1'
  //   MATLABSystem: '<S10>/Get Parameter1'
  //   MATLABSystem: '<S10>/Get Parameter3'
  //   Product: '<S10>/Divide'

  if (motion_controller_withPIC_B.b_value_k1) {
    motion_controller_withPIC_B.Switch[0] = motion_controller_withPIC_B.spd_cmd
      [0] / motion_controller_withPIC_B.b_value_o *
      motion_controller_withPIC_P.Gain1_Gain;
    motion_controller_withPIC_B.Switch[1] = motion_controller_withPIC_B.spd_cmd
      [1] / motion_controller_withPIC_B.b_value_o *
      motion_controller_withPIC_P.Gain1_Gain;
    motion_controller_withPIC_B.Switch[2] = motion_controller_withPIC_B.spd_cmd
      [2] / motion_controller_withPIC_B.b_value_o *
      motion_controller_withPIC_P.Gain1_Gain;
    motion_controller_withPIC_B.Switch[3] = motion_controller_withPIC_B.spd_cmd
      [3] / motion_controller_withPIC_B.b_value_o *
      motion_controller_withPIC_P.Gain1_Gain;
  } else {
    motion_controller_withPIC_B.Switch[0] =
      motion_controller_withPIC_P.Gain_Gain *
      motion_controller_withPIC_B.effort_cmd[0];
    motion_controller_withPIC_B.Switch[1] =
      motion_controller_withPIC_P.Gain_Gain *
      motion_controller_withPIC_B.effort_cmd[1];
    motion_controller_withPIC_B.Switch[2] =
      motion_controller_withPIC_P.Gain_Gain *
      motion_controller_withPIC_B.effort_cmd[2];
    motion_controller_withPIC_B.Switch[3] =
      motion_controller_withPIC_P.Gain_Gain *
      motion_controller_withPIC_B.effort_cmd[3];
  }

  // End of Switch: '<S10>/Switch2'

  // MATLABSystem: '<Root>/Get Parameter'
  ParamGet_motion_controller_withPIC_557.getParameter
    (&motion_controller_withPIC_B.b_value_o);

  // MATLABSystem: '<Root>/Get Parameter1'
  ParamGet_motion_controller_withPIC_558.getParameter
    (&motion_controller_withPIC_B.b_value_o2);

  // MATLABSystem: '<Root>/Get Parameter2'
  ParamGet_motion_controller_withPIC_559.getParameter
    (&motion_controller_withPIC_B.Gain2);

  // MATLABSystem: '<Root>/Get Parameter3'
  ParamGet_motion_controller_withPIC_560.getParameter
    (&motion_controller_withPIC_B.Add_i);

  // MATLABSystem: '<Root>/Get Parameter4'
  ParamGet_motion_controller_withPIC_561.getParameter
    (&motion_controller_withPIC_B.b_value_ax);

  // MATLABSystem: '<Root>/Get Parameter5'
  ParamGet_motion_controller_withPIC_562.getParameter
    (&motion_controller_withPIC_B.b_value_as);

  // MATLABSystem: '<Root>/Get Parameter15'
  ParamGet_motion_controller_withPIC_631.getParameter
    (&motion_controller_withPIC_B.b_value_i);

  // MATLABSystem: '<Root>/Get Parameter16'
  ParamGet_motion_controller_withPIC_632.getParameter
    (&motion_controller_withPIC_B.b_value_l);

  // Outputs for Enabled SubSystem: '<Root>/picController' incorporates:
  //   EnablePort: '<S16>/Enable'

  if (motion_controller_withPIC_B.isMpcEnable > 0) {
    if (!motion_controller_withPIC_DW.picController_MODE) {
      // InitializeConditions for UnitDelay: '<S16>/Unit Delay'
      motion_controller_withPIC_DW.UnitDelay_DSTATE =
        motion_controller_withPIC_P.UnitDelay_InitialCondition;

      // InitializeConditions for UnitDelay: '<S16>/Unit Delay1'
      motion_controller_withPIC_DW.UnitDelay1_DSTATE =
        motion_controller_withPIC_P.UnitDelay1_InitialCondition;
      motion_controller_withPIC_DW.picController_MODE = true;
    }

    // MATLABSystem: '<S16>/Get Parameter'
    ParamGet_motion_controller_withPIC_637.getParameter
      (&motion_controller_withPIC_B.vyp);

    // MATLABSystem: '<S16>/Get Parameter1'
    ParamGet_motion_controller_withPIC_709.getParameter
      (&motion_controller_withPIC_B.b_value_k1);

    // MATLABSystem: '<S16>/Get Parameter2'
    ParamGet_motion_controller_withPIC_944.getParameter
      (&motion_controller_withPIC_B.b_value_ip);

    // MATLABSystem: '<S16>/Get Parameter6'
    ParamGet_motion_controller_withPIC_556.getParameter
      (&motion_controller_withPIC_B.vxp);

    // MATLAB Function: '<S16>/MATLAB Function' incorporates:
    //   MATLABSystem: '<Root>/Get Parameter'
    //   MATLABSystem: '<Root>/Get Parameter1'
    //   MATLABSystem: '<Root>/Get Parameter15'
    //   MATLABSystem: '<Root>/Get Parameter16'
    //   MATLABSystem: '<Root>/Get Parameter2'
    //   MATLABSystem: '<Root>/Get Parameter3'
    //   MATLABSystem: '<Root>/Get Parameter4'
    //   MATLABSystem: '<Root>/Get Parameter5'

    motion_controller_withPIC_B.y_j[0] = motion_controller_withPIC_B.b_value_o;
    motion_controller_withPIC_B.y_j[1] = motion_controller_withPIC_B.b_value_o2;
    motion_controller_withPIC_B.y_j[2] = motion_controller_withPIC_B.Gain2;
    motion_controller_withPIC_B.y_j[3] = motion_controller_withPIC_B.Add_i;
    motion_controller_withPIC_B.y_j[4] = motion_controller_withPIC_B.b_value_ax;
    motion_controller_withPIC_B.y_j[5] = motion_controller_withPIC_B.b_value_as;
    memset(&motion_controller_withPIC_B.Q[0], 0, 36U * sizeof(real_T));
    for (motion_controller_withPIC_B.j = 0; motion_controller_withPIC_B.j < 6;
         motion_controller_withPIC_B.j++) {
      motion_controller_withPIC_B.Q[motion_controller_withPIC_B.j + 6 *
        motion_controller_withPIC_B.j] =
        motion_controller_withPIC_B.y_j[motion_controller_withPIC_B.j];
    }

    motion_controller_withPIC_B.R[1] = 0.0;
    motion_controller_withPIC_B.R[2] = 0.0;
    motion_controller_withPIC_B.R[0] = motion_controller_withPIC_B.b_value_i;
    motion_controller_withPIC_B.R[3] = motion_controller_withPIC_B.b_value_l;

    // End of MATLAB Function: '<S16>/MATLAB Function'

    // MATLAB Function: '<S16>/MATLAB Function2' incorporates:
    //   MATLABSystem: '<S16>/Get Parameter2'

    if (motion_controller_withPIC_B.b_value_ip == 0.0) {
      motion_controller_withPIC_B.y_j[2] = rt_roundd_snf
        (motion_controller_withPIC_B.yaw / 2.0 / 3.1415926535897931) * 2.0 *
        3.1415926535897931;
    } else if (motion_controller_withPIC_B.b_value_ip == 1.0) {
      if (rtIsNaN(motion_controller_withPIC_B.yaw)) {
        motion_controller_withPIC_B.Gain2 = (rtNaN);
      } else if (motion_controller_withPIC_B.yaw < 0.0) {
        motion_controller_withPIC_B.Gain2 = -1.0;
      } else {
        motion_controller_withPIC_B.Gain2 = (motion_controller_withPIC_B.yaw >
          0.0);
      }

      motion_controller_withPIC_B.y_j[2] = motion_controller_withPIC_B.Gain2 *
        3.1415926535897931;
    } else {
      motion_controller_withPIC_B.y_j[2] = rt_roundd_snf
        (motion_controller_withPIC_B.yaw / 3.1415926535897931) *
        3.1415926535897931;
    }

    motion_controller_withPIC_B.y_j[0] = 0.0;
    motion_controller_withPIC_B.y_j[1] = 0.0;
    motion_controller_withPIC_B.y_j[3] = 0.0;
    motion_controller_withPIC_B.y_j[4] = 0.0;
    motion_controller_withPIC_B.y_j[5] = 0.0;

    // End of MATLAB Function: '<S16>/MATLAB Function2'

    // Sum: '<S59>/Add' incorporates:
    //   Product: '<S59>/Product3'
    //   Product: '<S59>/Product4'
    //   Trigonometry: '<S59>/Cos'
    //   Trigonometry: '<S59>/Cos1'

    motion_controller_withPIC_B.Add1 = sin(motion_controller_withPIC_B.yaw) *
      motion_controller_withPIC_B.Add + cos(motion_controller_withPIC_B.yaw) *
      motion_controller_withPIC_B.Add1;

    // Reshape: '<S16>/Reshape' incorporates:
    //   UnitDelay: '<S16>/Unit Delay'
    //   UnitDelay: '<S16>/Unit Delay1'

    motion_controller_withPIC_B.Reshape[0] = motion_controller_withPIC_B.yp;
    motion_controller_withPIC_B.Reshape[1] = motion_controller_withPIC_B.Add1;
    motion_controller_withPIC_B.Reshape[2] = motion_controller_withPIC_B.yaw;
    motion_controller_withPIC_B.Reshape[3] = motion_controller_withPIC_B.y_g;
    motion_controller_withPIC_B.Reshape[4] =
      motion_controller_withPIC_DW.UnitDelay_DSTATE;
    motion_controller_withPIC_B.Reshape[5] =
      motion_controller_withPIC_DW.UnitDelay1_DSTATE;

    // Switch: '<S16>/Switch' incorporates:
    //   Constant: '<S16>/Constant2'
    //   Constant: '<S56>/Constant'
    //   RelationalOperator: '<S56>/Compare'

    if (motion_controller_withPIC_B.y_g ==
        motion_controller_withPIC_P.CompareToConstant_const) {
      motion_controller_withPIC_B.y_g =
        motion_controller_withPIC_P.Constant2_Value_g;
    }

    // End of Switch: '<S16>/Switch'

    // MATLAB Function: '<S16>/update' incorporates:
    //   MATLAB Function: '<Root>/update'
    //   MATLABSystem: '<Root>/Get Parameter10'
    //   MATLABSystem: '<Root>/Get Parameter11'
    //   MATLABSystem: '<Root>/Get Parameter12'
    //   MATLABSystem: '<Root>/Get Parameter13'
    //   MATLABSystem: '<Root>/Get Parameter14'
    //   MATLABSystem: '<Root>/Get Parameter9'
    //   Trigonometry: '<S12>/Cos'
    //   Trigonometry: '<S12>/Cos1'

    motion_controller_withPIC_B.b_value_ax = motion_controller_withPIC_P.B *
      motion_controller_withPIC_B.y_g / 2.0;
    motion_controller_withPIC_B.b_value_as =
      motion_controller_withPIC_B.b_value_ax - motion_controller_withPIC_B.Add;
    motion_controller_withPIC_B.e_a_tmp = motion_controller_withPIC_B.Add1 -
      motion_controller_withPIC_B.alpha1_tmp_f;
    motion_controller_withPIC_B.alpha1_tmp_f = motion_controller_withPIC_P.b *
      motion_controller_withPIC_B.y_g;
    motion_controller_withPIC_B.e_a_tmp_f = motion_controller_withPIC_B.e_a_tmp /
      motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
    motion_controller_withPIC_B.e_a = motion_controller_withPIC_B.e_a_tmp_f -
      motion_controller_withPIC_B.alpha1_tmp_f;
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im = 0.0;
    } else if (motion_controller_withPIC_B.e_a_tmp * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_im =
        motion_controller_withPIC_B.e_a_tmp_f;
    } else {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_c_im =
        motion_controller_withPIC_B.e_a_tmp_f;
    }

    motion_controller_withPIC_B.b_value_i =
      motion_controller_withPIC_B.alpha1_tmp_f * 0.0;
    motion_controller_withPIC_B.f_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_c_im -
                    motion_controller_withPIC_B.alpha1_tmp_f,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp) -
                     motion_controller_withPIC_B.b_value_ax) -
                    motion_controller_withPIC_B.b_value_i));
    motion_controller_withPIC_B.b_value_l =
      motion_controller_withPIC_B.b_value_ax + motion_controller_withPIC_B.Add;
    motion_controller_withPIC_B.b_value_ip = (motion_controller_withPIC_B.Add1 -
      motion_controller_withPIC_B.Add * sin(motion_controller_withPIC_B.yaw)) /
      cos(motion_controller_withPIC_B.yaw) - motion_controller_withPIC_P.b *
      motion_controller_withPIC_B.y_g;
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im = 0.0;
    } else if ((motion_controller_withPIC_B.Add1 -
                motion_controller_withPIC_B.Add * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_im =
        motion_controller_withPIC_B.e_a_tmp_f;
    } else {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_c_im =
        motion_controller_withPIC_B.e_a_tmp_f;
    }

    motion_controller_withPIC_B.k_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_c_im -
                    motion_controller_withPIC_B.alpha1_tmp_f,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp) +
                     motion_controller_withPIC_B.b_value_ax) -
                    motion_controller_withPIC_B.b_value_i));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im = 0.0;
    } else if ((motion_controller_withPIC_B.Add1 -
                motion_controller_withPIC_B.Add * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_im =
        motion_controller_withPIC_B.e_a_tmp_f;
    } else {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_c_im =
        motion_controller_withPIC_B.e_a_tmp_f;
    }

    motion_controller_withPIC_B.n_a_tmp = motion_controller_withPIC_P.a *
      motion_controller_withPIC_B.y_g;
    motion_controller_withPIC_B.n_a_tmp_a = motion_controller_withPIC_B.n_a_tmp *
      0.0;
    motion_controller_withPIC_B.n_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_c_im,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp) -
                     motion_controller_withPIC_B.b_value_ax) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    motion_controller_withPIC_B.o_a_tmp = (motion_controller_withPIC_B.Add1 -
      motion_controller_withPIC_B.Add * sin(motion_controller_withPIC_B.yaw)) /
      cos(motion_controller_withPIC_B.yaw) + motion_controller_withPIC_B.n_a_tmp;
    motion_controller_withPIC_B.q_a_tmp = (0.0 -
      motion_controller_withPIC_B.b_value_ax) - motion_controller_withPIC_B.Add;
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im = 0.0;
    } else if ((motion_controller_withPIC_B.Add1 -
                motion_controller_withPIC_B.Add * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_im =
        motion_controller_withPIC_B.e_a_tmp_f;
    } else {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_c_im =
        motion_controller_withPIC_B.e_a_tmp_f;
    }

    motion_controller_withPIC_B.s_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_c_im,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp) +
                     motion_controller_withPIC_B.b_value_ax) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_f = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_i =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_ff = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_g =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_c = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_o =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_l = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_m =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_m = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_c =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_fm = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_p =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_e = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_o =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_o = 0.0;
    } else {
      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_f =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_f =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_i = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_ff =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_i = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_ff =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_g = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_c =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_g = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_c =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_o = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_l =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_o = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_l =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_m = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_m =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_m = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_m =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_c = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_fm =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_c = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_fm =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_p = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_e =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_p = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_e =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_o = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_o =
          motion_controller_withPIC_B.e_a_tmp_f;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_o = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_o =
          motion_controller_withPIC_B.e_a_tmp_f;
      }
    }

    motion_controller_withPIC_B.bb_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_c_im_o -
                    motion_controller_withPIC_B.alpha1_tmp_f,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_o) +
                     motion_controller_withPIC_B.b_value_ax) -
                    motion_controller_withPIC_B.b_value_i));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_o =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_o = 0.0;
    } else if ((motion_controller_withPIC_B.Add1 -
                motion_controller_withPIC_B.Add * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_o = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_im_o =
        motion_controller_withPIC_B.e_a_tmp_f;
    } else {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_o = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_c_im_o =
        motion_controller_withPIC_B.e_a_tmp_f;
    }

    motion_controller_withPIC_B.hb_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_c_im_o -
                    motion_controller_withPIC_B.alpha1_tmp_f,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_o) -
                     motion_controller_withPIC_B.b_value_ax) -
                    motion_controller_withPIC_B.b_value_i));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_o =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_o = 0.0;
    } else if ((motion_controller_withPIC_B.Add1 -
                motion_controller_withPIC_B.Add * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_o = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_im_o =
        motion_controller_withPIC_B.e_a_tmp_f;
    } else {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_o = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_c_im_o =
        motion_controller_withPIC_B.e_a_tmp_f;
    }

    motion_controller_withPIC_B.lb_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_c_im_o,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_o) -
                     motion_controller_withPIC_B.b_value_ax) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_o =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_o = 0.0;
    } else if ((motion_controller_withPIC_B.Add1 -
                motion_controller_withPIC_B.Add * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_o = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_im_o =
        motion_controller_withPIC_B.e_a_tmp_f;
    } else {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_o = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_c_im_o =
        motion_controller_withPIC_B.e_a_tmp_f;
    }

    motion_controller_withPIC_B.rb_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_c_im_o,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_o) +
                     motion_controller_withPIC_B.b_value_ax) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_o =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_o = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_h =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_o;
      motion_controller_withPIC_B.rtb_Add_c_im_l5 = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_h2 =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_o;
      motion_controller_withPIC_B.rtb_Add_c_im_me = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_mc =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_o;
      motion_controller_withPIC_B.rtb_Add_c_im_h = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_cs =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_o;
      motion_controller_withPIC_B.rtb_Add_c_im_k = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_pc =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_o;
      motion_controller_withPIC_B.rtb_Add_c_im_p = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_p4 =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_o;
      motion_controller_withPIC_B.rtb_Add_c_im_a = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_j =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_o;
      motion_controller_withPIC_B.rtb_Add_c_im_ek = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_ol =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_o;
      motion_controller_withPIC_B.rtb_Add_c_im_b = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_a =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_o;
      motion_controller_withPIC_B.rtb_Add_c_im_g = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_e =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_o;
      motion_controller_withPIC_B.rtb_Add_c_im_fi = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_h22 =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_o;
      motion_controller_withPIC_B.rtb_Add_c_im_ei = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_l =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_o;
      motion_controller_withPIC_B.rtb_Add_c_im_ch = 0.0;
    } else {
      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_o = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_o =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_o = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_o =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_h = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_l5 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_h = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_l5 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_h2 = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_me =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_h2 = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_me =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_mc = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_h =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_mc = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_h =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_cs = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_k =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_cs = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_k =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_pc = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_p =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_pc = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_p =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_p4 = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_a =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_p4 = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_a =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_j = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_ek =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_j = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_ek =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_ol = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_b =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_ol = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_b =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_a = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_g =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_a = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_g =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_e = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_fi =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_e = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_fi =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_h22 = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_ei =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_h22 = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_ei =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_l = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_ch =
          motion_controller_withPIC_B.e_a_tmp_f;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_l = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_ch =
          motion_controller_withPIC_B.e_a_tmp_f;
      }
    }

    motion_controller_withPIC_B.yb_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_c_im_ch -
                    motion_controller_withPIC_B.alpha1_tmp_f,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_l) +
                     motion_controller_withPIC_B.b_value_ax) -
                    motion_controller_withPIC_B.b_value_i));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_l =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_ch = 0.0;
    } else if ((motion_controller_withPIC_B.Add1 -
                motion_controller_withPIC_B.Add * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_l = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_im_ch =
        motion_controller_withPIC_B.e_a_tmp_f;
    } else {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_l = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_c_im_ch =
        motion_controller_withPIC_B.e_a_tmp_f;
    }

    motion_controller_withPIC_B.ec_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_c_im_ch -
                    motion_controller_withPIC_B.alpha1_tmp_f,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_l) -
                     motion_controller_withPIC_B.b_value_ax) -
                    motion_controller_withPIC_B.b_value_i));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_l =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_ch = 0.0;
    } else if ((motion_controller_withPIC_B.Add1 -
                motion_controller_withPIC_B.Add * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_l = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_im_ch =
        motion_controller_withPIC_B.e_a_tmp_f;
    } else {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_l = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_c_im_ch =
        motion_controller_withPIC_B.e_a_tmp_f;
    }

    motion_controller_withPIC_B.hc_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_c_im_ch,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_l) -
                     motion_controller_withPIC_B.b_value_ax) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_l =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_ch = 0.0;
    } else if ((motion_controller_withPIC_B.Add1 -
                motion_controller_withPIC_B.Add * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_l = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_im_ch =
        motion_controller_withPIC_B.e_a_tmp_f;
    } else {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_l = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_c_im_ch =
        motion_controller_withPIC_B.e_a_tmp_f;
    }

    motion_controller_withPIC_B.mc_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_c_im_ch,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_l) +
                     motion_controller_withPIC_B.b_value_ax) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_l =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_ch = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_ax =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_l;
      motion_controller_withPIC_B.rtb_Add_c_im_d = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_af =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_l;
      motion_controller_withPIC_B.rtb_Add_c_im_pb = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_ms =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_l;
      motion_controller_withPIC_B.rtb_Add_c_im_o3 = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_n =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_l;
      motion_controller_withPIC_B.rtb_Add_c_im_lu = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_pe =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_l;
      motion_controller_withPIC_B.rtb_Add_c_im_pt = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_f =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_l;
      motion_controller_withPIC_B.rtb_Add_c_im_i = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_ox =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_l;
      motion_controller_withPIC_B.rtb_Add_c_im_kk = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_l;
      motion_controller_withPIC_B.rtb_Add_c_im_ie = 0.0;
    } else {
      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_l = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_ch =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_l = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_ch =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_ax = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_d =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_ax = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_d =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_af = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_pb =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_af = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_pb =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_ms = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_o3 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_ms = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_o3 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_n = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_lu =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_n = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_lu =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_pe = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_pt =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_pe = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_pt =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_f = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_i =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_f = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_i =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_ox = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_kk =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_ox = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_kk =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_ie =
          motion_controller_withPIC_B.e_a_tmp_f;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_ie =
          motion_controller_withPIC_B.e_a_tmp_f;
      }
    }

    motion_controller_withPIC_B.rc_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_c_im_ie,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu) -
                     motion_controller_withPIC_B.b_value_ax) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_ie = 0.0;
    } else if ((motion_controller_withPIC_B.Add1 -
                motion_controller_withPIC_B.Add * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_im_ie =
        motion_controller_withPIC_B.e_a_tmp_f;
    } else {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_c_im_ie =
        motion_controller_withPIC_B.e_a_tmp_f;
    }

    motion_controller_withPIC_B.wc_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_c_im_ie,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu) +
                     motion_controller_withPIC_B.b_value_ax) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_ie = 0.0;
    } else if ((motion_controller_withPIC_B.Add1 -
                motion_controller_withPIC_B.Add * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_im_ie =
        motion_controller_withPIC_B.e_a_tmp_f;
    } else {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_c_im_ie =
        motion_controller_withPIC_B.e_a_tmp_f;
    }

    motion_controller_withPIC_B.ed_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_c_im_ie -
                    motion_controller_withPIC_B.alpha1_tmp_f,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu) +
                     motion_controller_withPIC_B.b_value_ax) -
                    motion_controller_withPIC_B.b_value_i));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_ie = 0.0;
    } else if ((motion_controller_withPIC_B.Add1 -
                motion_controller_withPIC_B.Add * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_im_ie =
        motion_controller_withPIC_B.e_a_tmp_f;
    } else {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_c_im_ie =
        motion_controller_withPIC_B.e_a_tmp_f;
    }

    motion_controller_withPIC_B.jd_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_c_im_ie -
                    motion_controller_withPIC_B.alpha1_tmp_f,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu) -
                     motion_controller_withPIC_B.b_value_ax) -
                    motion_controller_withPIC_B.b_value_i));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_ie = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_oc =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu;
      motion_controller_withPIC_B.rtb_Add_c_im_m4 = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_cu =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu;
      motion_controller_withPIC_B.rtb_Add_c_im_fb = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_hc =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu;
      motion_controller_withPIC_B.rtb_Add_c_im_m44 = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_ad =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu;
      motion_controller_withPIC_B.rtb_Add_c_im_kb = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_pcr =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu;
      motion_controller_withPIC_B.rtb_Add_c_im_bp = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_ch =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu;
      motion_controller_withPIC_B.rtb_Add_c_im_n = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_ij =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu;
      motion_controller_withPIC_B.rtb_Add_c_im_my = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_g =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu;
      motion_controller_withPIC_B.rtb_Add_c_im_j = 0.0;
    } else {
      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_ie =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_ie =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_oc = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_m4 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_oc = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_m4 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_cu = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_fb =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_cu = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_fb =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_hc = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_m44 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_hc = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_m44 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_ad = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_kb =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_ad = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_kb =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_pcr = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_bp =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_pcr = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_bp =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_ch = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_n =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_ch = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_n =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_ij = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_my =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_ij = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_my =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_g = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_j =
          motion_controller_withPIC_B.e_a_tmp_f;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_g = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_j =
          motion_controller_withPIC_B.e_a_tmp_f;
      }
    }

    motion_controller_withPIC_B.pd_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_c_im_j -
                    motion_controller_withPIC_B.alpha1_tmp_f,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_g) -
                     motion_controller_withPIC_B.b_value_ax) -
                    motion_controller_withPIC_B.b_value_i));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_g =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_j = 0.0;
    } else if ((motion_controller_withPIC_B.Add1 -
                motion_controller_withPIC_B.Add * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_g = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_im_j =
        motion_controller_withPIC_B.e_a_tmp_f;
    } else {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_g = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_c_im_j =
        motion_controller_withPIC_B.e_a_tmp_f;
    }

    motion_controller_withPIC_B.td_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_c_im_j,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_g) -
                     motion_controller_withPIC_B.b_value_ax) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_g =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_j = 0.0;
    } else if ((motion_controller_withPIC_B.Add1 -
                motion_controller_withPIC_B.Add * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_g = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_im_j =
        motion_controller_withPIC_B.e_a_tmp_f;
    } else {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_g = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_c_im_j =
        motion_controller_withPIC_B.e_a_tmp_f;
    }

    motion_controller_withPIC_B.ae_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_c_im_j,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_g) +
                     motion_controller_withPIC_B.b_value_ax) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_g =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_j = 0.0;
    } else if ((motion_controller_withPIC_B.Add1 -
                motion_controller_withPIC_B.Add * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_g = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_im_j =
        motion_controller_withPIC_B.e_a_tmp_f;
    } else {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_g = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_c_im_j =
        motion_controller_withPIC_B.e_a_tmp_f;
    }

    motion_controller_withPIC_B.ie_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_c_im_j -
                    motion_controller_withPIC_B.alpha1_tmp_f,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_g) +
                     motion_controller_withPIC_B.b_value_ax) -
                    motion_controller_withPIC_B.b_value_i));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_g =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_j = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_ev =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_g;
      motion_controller_withPIC_B.rtb_Add_c_im_mv = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_m0 =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_g;
      motion_controller_withPIC_B.rtb_Add_c_im_jg = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_fo =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_g;
      motion_controller_withPIC_B.rtb_Add_c_im_a5 = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_gl =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_g;
      motion_controller_withPIC_B.rtb_Add_c_im_nr = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_d =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_g;
      motion_controller_withPIC_B.rtb_Add_c_im_na = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_cg =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_g;
      motion_controller_withPIC_B.rtb_Add_c_im_fx = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_pm =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_g;
      motion_controller_withPIC_B.rtb_Add_c_im_p2 = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_d =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_g;
      motion_controller_withPIC_B.rtb_Add_c_im_nj = 0.0;
    } else {
      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_g = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_j =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_g = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_j =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_ev = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_mv =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_ev = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_mv =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_m0 = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_jg =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_m0 = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_jg =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_fo = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_a5 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_fo = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_a5 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_gl = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_nr =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_gl = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_nr =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_d = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_na =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_d = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_na =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_cg = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_fx =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_cg = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_fx =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_pm = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_p2 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_pm = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_p2 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_d = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_nj =
          motion_controller_withPIC_B.e_a_tmp_f;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_d = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_nj =
          motion_controller_withPIC_B.e_a_tmp_f;
      }
    }

    motion_controller_withPIC_B.ne_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_c_im_nj -
                    motion_controller_withPIC_B.alpha1_tmp_f,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_d) -
                     motion_controller_withPIC_B.b_value_ax) -
                    motion_controller_withPIC_B.b_value_i));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_d =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_nj = 0.0;
    } else if ((motion_controller_withPIC_B.Add1 -
                motion_controller_withPIC_B.Add * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_d = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_im_nj =
        motion_controller_withPIC_B.e_a_tmp_f;
    } else {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_d = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_c_im_nj =
        motion_controller_withPIC_B.e_a_tmp_f;
    }

    motion_controller_withPIC_B.qe_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_c_im_nj,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_d) -
                     motion_controller_withPIC_B.b_value_ax) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_d =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_nj = 0.0;
    } else if ((motion_controller_withPIC_B.Add1 -
                motion_controller_withPIC_B.Add * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_d = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_im_nj =
        motion_controller_withPIC_B.e_a_tmp_f;
    } else {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_d = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_c_im_nj =
        motion_controller_withPIC_B.e_a_tmp_f;
    }

    motion_controller_withPIC_B.ve_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_c_im_nj,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_d) +
                     motion_controller_withPIC_B.b_value_ax) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_d =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_nj = 0.0;
    } else if ((motion_controller_withPIC_B.Add1 -
                motion_controller_withPIC_B.Add * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_d = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_im_nj =
        motion_controller_withPIC_B.e_a_tmp_f;
    } else {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_d = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_c_im_nj =
        motion_controller_withPIC_B.e_a_tmp_f;
    }

    motion_controller_withPIC_B.df_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_c_im_nj -
                    motion_controller_withPIC_B.alpha1_tmp_f,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_d) +
                     motion_controller_withPIC_B.b_value_ax) -
                    motion_controller_withPIC_B.b_value_i));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_d =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_nj = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_k =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_d;
      motion_controller_withPIC_B.rtb_Add_c_im_n3 = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_oy =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_d;
      motion_controller_withPIC_B.rtb_Add_c_im_gg = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_cq =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_d;
      motion_controller_withPIC_B.rtb_Add_c_im_cj = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_m1 =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_d;
      motion_controller_withPIC_B.rtb_Add_c_im_jp = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_kn =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_d;
      motion_controller_withPIC_B.rtb_Add_c_im_mx = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_pr =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_d;
      motion_controller_withPIC_B.rtb_Add_c_im_dz = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_g4 =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_d;
      motion_controller_withPIC_B.rtb_Add_c_im_c3 = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_dv =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_d;
      motion_controller_withPIC_B.rtb_Add_c_im_cx = 0.0;
    } else {
      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_d = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_nj =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_d = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_nj =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_k = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_n3 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_k = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_n3 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_oy = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_gg =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_oy = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_gg =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_cq = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_cj =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_cq = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_cj =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_m1 = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_jp =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_m1 = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_jp =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_kn = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_mx =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_kn = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_mx =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_pr = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_dz =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_pr = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_dz =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_g4 = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_c3 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_g4 = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_c3 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_dv = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_cx =
          motion_controller_withPIC_B.e_a_tmp_f;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_dv = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_cx =
          motion_controller_withPIC_B.e_a_tmp_f;
      }
    }

    motion_controller_withPIC_B.ef_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_c_im_cx,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_dv) -
                     motion_controller_withPIC_B.b_value_ax) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_dv =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_cx = 0.0;
    } else if ((motion_controller_withPIC_B.Add1 -
                motion_controller_withPIC_B.Add * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_dv = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_im_cx =
        motion_controller_withPIC_B.e_a_tmp_f;
    } else {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_dv = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_c_im_cx =
        motion_controller_withPIC_B.e_a_tmp_f;
    }

    motion_controller_withPIC_B.ff_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_c_im_cx,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_dv) +
                     motion_controller_withPIC_B.b_value_ax) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_dv =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_cx = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_if =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_dv;
      motion_controller_withPIC_B.rtb_Add_c_im_dx = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_g4k =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_dv;
      motion_controller_withPIC_B.rtb_Add_c_im_lg = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_f1 =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_dv;
      motion_controller_withPIC_B.rtb_Add_c_im_db = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_jr =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_dv;
      motion_controller_withPIC_B.rtb_Add_c_im_i3 = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_h222 =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_dv;
      motion_controller_withPIC_B.rtb_Add_c_im_nm = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_j =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_dv;
      motion_controller_withPIC_B.rtb_Add_c_im_o30 = 0.0;
    } else {
      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_dv = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_cx =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_dv = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_cx =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_if = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_dx =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_if = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_dx =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_g4k = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_lg =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_g4k = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_lg =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_f1 = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_db =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_f1 = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_db =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_jr = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_i3 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_jr = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_i3 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_h222 = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_nm =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_h222 = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_nm =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_j = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_o30 =
          motion_controller_withPIC_B.e_a_tmp_f;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_j = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_o30 =
          motion_controller_withPIC_B.e_a_tmp_f;
      }
    }

    motion_controller_withPIC_B.gf_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_c_im_o30 -
                    motion_controller_withPIC_B.alpha1_tmp_f,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_j) -
                     motion_controller_withPIC_B.b_value_ax) -
                    motion_controller_withPIC_B.b_value_i));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_j =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_o30 = 0.0;
    } else if ((motion_controller_withPIC_B.Add1 -
                motion_controller_withPIC_B.Add * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_j = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_im_o30 =
        motion_controller_withPIC_B.e_a_tmp_f;
    } else {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_j = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_c_im_o30 =
        motion_controller_withPIC_B.e_a_tmp_f;
    }

    motion_controller_withPIC_B.hf_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_c_im_o30 -
                    motion_controller_withPIC_B.alpha1_tmp_f,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_j) +
                     motion_controller_withPIC_B.b_value_ax) -
                    motion_controller_withPIC_B.b_value_i));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_j =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_o30 = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_ch3 =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_j;
      motion_controller_withPIC_B.rtb_Add_c_im_bd = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_er =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_j;
      motion_controller_withPIC_B.rtb_Add_c_im_dd = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_ik =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_j;
      motion_controller_withPIC_B.rtb_Add_c_im_gs = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_nn =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_j;
      motion_controller_withPIC_B.rtb_Add_c_im_l0 = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_ce =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_j;
      motion_controller_withPIC_B.rtb_Add_c_im_nc = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_f =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_j;
      motion_controller_withPIC_B.rtb_Add_c_im_ph = 0.0;
    } else {
      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_j = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_o30 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_j = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_o30 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_ch3 = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_bd =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_ch3 = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_bd =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_er = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_dd =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_er = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_dd =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_ik = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_gs =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_ik = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_gs =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_nn = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_l0 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_nn = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_l0 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_ce = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_nc =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_ce = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_nc =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_f = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_ph =
          motion_controller_withPIC_B.e_a_tmp_f;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_f = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_ph =
          motion_controller_withPIC_B.e_a_tmp_f;
      }
    }

    motion_controller_withPIC_B.if_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_c_im_ph,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_f) -
                     motion_controller_withPIC_B.b_value_ax) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_f =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_ph = 0.0;
    } else if ((motion_controller_withPIC_B.Add1 -
                motion_controller_withPIC_B.Add * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_f = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_im_ph =
        motion_controller_withPIC_B.e_a_tmp_f;
    } else {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_f = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_c_im_ph =
        motion_controller_withPIC_B.e_a_tmp_f;
    }

    motion_controller_withPIC_B.jf_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_c_im_ph,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_f) +
                     motion_controller_withPIC_B.b_value_ax) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_f =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_ph = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_dk =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_f;
      motion_controller_withPIC_B.rtb_Add_c_im_oi = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_jrs =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_f;
      motion_controller_withPIC_B.rtb_Add_c_im_c2 = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_hp =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_f;
      motion_controller_withPIC_B.rtb_Add_c_im_da = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_c5 =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_f;
      motion_controller_withPIC_B.rtb_Add_c_im_pw = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_pi =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_f;
      motion_controller_withPIC_B.rtb_Add_c_im_a4 = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_js =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_f;
      motion_controller_withPIC_B.rtb_Add_c_im_ow = 0.0;
    } else {
      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_f = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_ph =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_f = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_ph =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_dk = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_oi =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_dk = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_oi =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_jrs = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_c2 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_jrs = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_c2 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_hp = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_da =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_hp = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_da =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_c5 = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_pw =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_c5 = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_pw =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_pi = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_a4 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_pi = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_a4 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_js = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_ow =
          motion_controller_withPIC_B.e_a_tmp_f;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_js = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_ow =
          motion_controller_withPIC_B.e_a_tmp_f;
      }
    }

    motion_controller_withPIC_B.kf_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_c_im_ow -
                    motion_controller_withPIC_B.alpha1_tmp_f,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_js) -
                     motion_controller_withPIC_B.b_value_ax) -
                    motion_controller_withPIC_B.b_value_i));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_js =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_ow = 0.0;
    } else if ((motion_controller_withPIC_B.Add1 -
                motion_controller_withPIC_B.Add * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_js = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_im_ow =
        motion_controller_withPIC_B.e_a_tmp_f;
    } else {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_js = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_c_im_ow =
        motion_controller_withPIC_B.e_a_tmp_f;
    }

    motion_controller_withPIC_B.lf_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_c_im_ow -
                    motion_controller_withPIC_B.alpha1_tmp_f,
                    ((motion_controller_withPIC_B.Add +
                      motion_controller_withPIC_B.rtb_Add_c_re_tmp_js) +
                     motion_controller_withPIC_B.b_value_ax) -
                    motion_controller_withPIC_B.b_value_i));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_c_re_tmp_js =
        (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_c_im_ow = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_jw =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_js;
      motion_controller_withPIC_B.rtb_Add_c_im_pi = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_ob =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_js;
      motion_controller_withPIC_B.rtb_Add_c_im_lm = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_kv =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_js;
      motion_controller_withPIC_B.rtb_Add_c_im_jk = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_fz =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_js;
      motion_controller_withPIC_B.rtb_Add_c_im_cm = 0.0;
      motion_controller_withPIC_B.rtb_Add_c_re_fq =
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_js;
      motion_controller_withPIC_B.e_a_tmp_f = 0.0;
    } else {
      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_js = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_ow =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_tmp_js = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_ow =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_jw = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_pi =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_jw = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_pi =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_ob = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_lm =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_ob = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_lm =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_kv = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_jk =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_kv = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_jk =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_fz = 0.0;
        motion_controller_withPIC_B.rtb_Add_c_im_cm =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_fz = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_c_im_cm =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
      }

      if ((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
           sin(motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_c_re_fq = 0.0;
      } else {
        motion_controller_withPIC_B.rtb_Add_c_re_fq = (rtNaN);
      }
    }

    motion_controller_withPIC_B.b_value_o = motion_controller_withPIC_P.B / 2.0 *
      motion_controller_withPIC_B.y_g;
    motion_controller_withPIC_B.Gain2 = motion_controller_withPIC_B.Add -
      motion_controller_withPIC_B.b_value_o;
    motion_controller_withPIC_B.b_value_o2 = sin(atan(sin(rt_atan2d_snf
      (motion_controller_withPIC_B.o_a_tmp, motion_controller_withPIC_B.Gain2) -
      motion_controller_withPIC_B.df_j) * motion_controller_withPIC_B.b_value_c0)
      * motion_controller_withPIC_B.b_value_ct) *
      motion_controller_withPIC_B.Fy1_tmp;
    motion_controller_withPIC_B.Add_i = motion_controller_withPIC_B.b_value_o +
      motion_controller_withPIC_B.Add;
    motion_controller_withPIC_B.b_value_o = sin(atan(sin(rt_atan2d_snf
      (motion_controller_withPIC_B.o_a_tmp, motion_controller_withPIC_B.Add_i) -
      motion_controller_withPIC_B.df_j) * motion_controller_withPIC_B.b_value_c0)
      * motion_controller_withPIC_B.b_value_ct) *
      motion_controller_withPIC_B.Fy2_tmp;
    motion_controller_withPIC_B.Gain2 = sin(atan(sin(rt_atan2d_snf
      (motion_controller_withPIC_B.b_value_ip, motion_controller_withPIC_B.Gain2)
      - motion_controller_withPIC_B.dr_i) *
      motion_controller_withPIC_B.b_value_p5) *
      motion_controller_withPIC_B.b_value_af) *
      motion_controller_withPIC_B.Fy3_tmp;
    motion_controller_withPIC_B.Add_i = sin(atan(sin(rt_atan2d_snf
      (motion_controller_withPIC_B.b_value_ip, motion_controller_withPIC_B.Add_i)
      - motion_controller_withPIC_B.dr_i) *
      motion_controller_withPIC_B.b_value_p5) *
      motion_controller_withPIC_B.b_value_af) *
      motion_controller_withPIC_B.Fy4_tmp;
    motion_controller_withPIC_B.Fy4_tmp = motion_controller_withPIC_B.dr_i +
      motion_controller_withPIC_B.yaw;
    motion_controller_withPIC_B.Fy2_tmp = cos
      (motion_controller_withPIC_B.Fy4_tmp);
    motion_controller_withPIC_B.Fy3_tmp = motion_controller_withPIC_B.df_j +
      motion_controller_withPIC_B.yaw;
    motion_controller_withPIC_B.Fy1_tmp = cos
      (motion_controller_withPIC_B.Fy3_tmp);
    motion_controller_withPIC_B.Fy3_tmp = sin
      (motion_controller_withPIC_B.Fy3_tmp);
    motion_controller_withPIC_B.Fy4_tmp = sin
      (motion_controller_withPIC_B.Fy4_tmp);
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[1] = 0.0;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_n =
      motion_controller_withPIC_B.b_value_p5 *
      motion_controller_withPIC_B.b_value_af *
      motion_controller_withPIC_B.b_value_e;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_i =
      motion_controller_withPIC_B.b_value_p5 *
      motion_controller_withPIC_B.b_value_p5;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_l =
      motion_controller_withPIC_B.b_value_c0 *
      motion_controller_withPIC_B.b_value_ct *
      motion_controller_withPIC_B.b_value_p;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__i3 =
      motion_controller_withPIC_B.b_value_c0 *
      motion_controller_withPIC_B.b_value_c0;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_b =
      motion_controller_withPIC_B.In1_f.linear_acceleration.x *
      motion_controller_withPIC_P.hCG * motion_controller_withPIC_P.m / 2.0;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d =
      (motion_controller_withPIC_P.a * motion_controller_withPIC_P.g *
       motion_controller_withPIC_P.m / 2.0 +
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_b) /
      motion_controller_withPIC_P.L;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e =
      motion_controller_withPIC_B.In1_f.linear_acceleration.y *
      motion_controller_withPIC_P.hCG * motion_controller_withPIC_P.m *
      (motion_controller_withPIC_P.Krsf - 1.0) / motion_controller_withPIC_P.B;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eh =
      motion_controller_withPIC_B.b_value_ip * 0.0;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a =
      (motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_b -
       motion_controller_withPIC_P.b * motion_controller_withPIC_P.g *
       motion_controller_withPIC_P.m / 2.0) / motion_controller_withPIC_P.L;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__il =
      motion_controller_withPIC_B.In1_f.linear_acceleration.y *
      motion_controller_withPIC_P.Krsf * motion_controller_withPIC_P.hCG *
      motion_controller_withPIC_P.m / motion_controller_withPIC_P.B;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_f =
      motion_controller_withPIC_B.o_a_tmp * 0.0;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j =
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d -
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d +=
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e =
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a +
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__il;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a -=
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__il;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_b = 1.0 /
      motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__il =
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_b /
      (motion_controller_withPIC_P.B * motion_controller_withPIC_B.y_g / 2.0 -
       motion_controller_withPIC_B.Add);
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ho =
      motion_controller_withPIC_B.b_value_as *
      motion_controller_withPIC_B.b_value_as;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_c =
      motion_controller_withPIC_B.b_value_l *
      motion_controller_withPIC_B.b_value_l;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__nu =
      motion_controller_withPIC_B.q_a_tmp * motion_controller_withPIC_B.q_a_tmp;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ki =
      motion_controller_withPIC_B.o_a_tmp * motion_controller_withPIC_B.o_a_tmp;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__av =
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eh /
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_c;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__kl =
      motion_controller_withPIC_B.b_value_ip *
      motion_controller_withPIC_B.b_value_ip;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fn =
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__kl +
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_c;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__jz =
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eh /
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ho;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__bn =
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_f /
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ho;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__hm =
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ki +
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ho;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_f /=
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__nu;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ki +=
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__nu;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eg =
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__il -
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__bn;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__hn =
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_b /
      motion_controller_withPIC_B.q_a_tmp -
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_f;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ku =
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_b /
      motion_controller_withPIC_B.b_value_l +
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__av;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[5] = -((cos(atan(sin
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_c_im_f -
        motion_controller_withPIC_B.alpha1_tmp_f,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re) -
         motion_controller_withPIC_B.b_value_ax) -
        motion_controller_withPIC_B.b_value_i)) *
      motion_controller_withPIC_B.b_value_p5) *
      motion_controller_withPIC_B.b_value_af) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_c_im -
        motion_controller_withPIC_B.alpha1_tmp_f,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_tmp) -
         motion_controller_withPIC_B.b_value_ax) -
        motion_controller_withPIC_B.b_value_i)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_n) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d * (1.0 /
      motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp /
      motion_controller_withPIC_B.b_value_as -
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__jz) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ho /
      ((motion_controller_withPIC_B.f_a * motion_controller_withPIC_B.f_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_i + 1.0) *
       (motion_controller_withPIC_B.e_a * motion_controller_withPIC_B.e_a +
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ho)) - cos(atan
      (sin(motion_controller_withPIC_B.dr_i - rt_atan2d_snf
           (motion_controller_withPIC_B.rtb_Add_c_im_c -
            motion_controller_withPIC_B.alpha1_tmp_f,
            ((motion_controller_withPIC_B.Add +
              motion_controller_withPIC_B.rtb_Add_c_re_g) +
             motion_controller_withPIC_B.b_value_ax) -
            motion_controller_withPIC_B.b_value_i)) *
       motion_controller_withPIC_B.b_value_p5) *
      motion_controller_withPIC_B.b_value_af) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_c_im_ff -
        motion_controller_withPIC_B.alpha1_tmp_f,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_i) +
         motion_controller_withPIC_B.b_value_ax) -
        motion_controller_withPIC_B.b_value_i)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_n) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ku *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_c /
      ((motion_controller_withPIC_B.k_a * motion_controller_withPIC_B.k_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_i + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fn)) *
      motion_controller_withPIC_B.Fy2_tmp - (cos(atan(sin
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_m,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_m) -
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.b_value_c0) *
      motion_controller_withPIC_B.b_value_ct) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_l,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_o) -
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_l) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eg *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ho /
      ((motion_controller_withPIC_B.n_a * motion_controller_withPIC_B.n_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__i3 + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__hm) + cos(atan
      (sin(motion_controller_withPIC_B.df_j - rt_atan2d_snf
           (motion_controller_withPIC_B.n_a_tmp +
            motion_controller_withPIC_B.rtb_Add_c_im_e,
            ((motion_controller_withPIC_B.Add +
              motion_controller_withPIC_B.rtb_Add_c_re_p) +
             motion_controller_withPIC_B.b_value_ax) +
            motion_controller_withPIC_B.n_a_tmp_a)) *
       motion_controller_withPIC_B.b_value_c0) *
      motion_controller_withPIC_B.b_value_ct) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_fm,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_c) +
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_l) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__hn *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__nu /
      ((motion_controller_withPIC_B.s_a * motion_controller_withPIC_B.s_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__i3 + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ki)) *
      motion_controller_withPIC_B.Fy1_tmp) / motion_controller_withPIC_P.m;
    motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp *=
      motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_b =
      (motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add * sin
       (motion_controller_withPIC_B.yaw)) *
      motion_controller_withPIC_B.rtb_Add_i_tmp_tmp /
      motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp -
      motion_controller_withPIC_B.Add;
    motion_controller_withPIC_B.e_a =
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_b /
      motion_controller_withPIC_B.b_value_as;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__kl +=
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ho;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__jz =
      motion_controller_withPIC_B.e_a -
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__jz;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__bn =
      motion_controller_withPIC_B.e_a -
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__bn;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_f =
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_b /
      motion_controller_withPIC_B.q_a_tmp -
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_f;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[9] = ((((cos(atan
      (sin(motion_controller_withPIC_B.dr_i - rt_atan2d_snf
           (motion_controller_withPIC_B.rtb_Add_c_im_h -
            motion_controller_withPIC_B.alpha1_tmp_f,
            ((motion_controller_withPIC_B.Add +
              motion_controller_withPIC_B.rtb_Add_c_re_mc) +
             motion_controller_withPIC_B.b_value_ax) -
            motion_controller_withPIC_B.b_value_i)) *
       motion_controller_withPIC_B.b_value_p5) *
      motion_controller_withPIC_B.b_value_af) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_c_im_me -
        motion_controller_withPIC_B.alpha1_tmp_f,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_h2) +
         motion_controller_withPIC_B.b_value_ax) -
        motion_controller_withPIC_B.b_value_i)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_n) *
      ((motion_controller_withPIC_B.e_a_tmp *
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp -
        motion_controller_withPIC_B.Add) / motion_controller_withPIC_B.b_value_l
       + motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__av) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_c /
      ((motion_controller_withPIC_B.bb_a * motion_controller_withPIC_B.bb_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_i + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fn) - cos(atan
      (sin(motion_controller_withPIC_B.dr_i - rt_atan2d_snf
           (motion_controller_withPIC_B.rtb_Add_c_im_p -
            motion_controller_withPIC_B.alpha1_tmp_f,
            ((motion_controller_withPIC_B.Add +
              motion_controller_withPIC_B.rtb_Add_c_re_pc) -
             motion_controller_withPIC_B.b_value_ax) -
            motion_controller_withPIC_B.b_value_i)) *
       motion_controller_withPIC_B.b_value_p5) *
      motion_controller_withPIC_B.b_value_af) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_c_im_k -
        motion_controller_withPIC_B.alpha1_tmp_f,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_cs) -
         motion_controller_withPIC_B.b_value_ax) -
        motion_controller_withPIC_B.b_value_i)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_n) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__jz *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ho /
      ((motion_controller_withPIC_B.hb_a * motion_controller_withPIC_B.hb_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_i + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__kl)) *
      motion_controller_withPIC_B.Fy2_tmp + (sin(atan(sin
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_c_im_o -
        motion_controller_withPIC_B.alpha1_tmp_f,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_tmp_o) -
         motion_controller_withPIC_B.b_value_ax) -
        motion_controller_withPIC_B.b_value_i)) *
      motion_controller_withPIC_B.b_value_p5) *
      motion_controller_withPIC_B.b_value_af) *
      motion_controller_withPIC_B.b_value_e *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d + sin(atan(sin
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_c_im_l5 -
        motion_controller_withPIC_B.alpha1_tmp_f,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_h) +
         motion_controller_withPIC_B.b_value_ax) -
        motion_controller_withPIC_B.b_value_i)) *
      motion_controller_withPIC_B.b_value_p5) *
      motion_controller_withPIC_B.b_value_af) *
      motion_controller_withPIC_B.b_value_e *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j) *
      motion_controller_withPIC_B.Fy4_tmp) - (sin(atan(sin
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_a,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_p4) -
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.b_value_c0) *
      motion_controller_withPIC_B.b_value_ct) *
      motion_controller_withPIC_B.b_value_p *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e + sin(atan(sin
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_ek,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_j) +
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.b_value_c0) *
      motion_controller_withPIC_B.b_value_ct) *
      motion_controller_withPIC_B.b_value_p *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a) *
      motion_controller_withPIC_B.Fy3_tmp) + (cos(atan(sin
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_g,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_a) -
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.b_value_c0) *
      motion_controller_withPIC_B.b_value_ct) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_b,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_ol) -
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_l) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__bn *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ho /
      ((motion_controller_withPIC_B.lb_a * motion_controller_withPIC_B.lb_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__i3 + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__hm) + cos(atan
      (sin(motion_controller_withPIC_B.df_j - rt_atan2d_snf
           (motion_controller_withPIC_B.n_a_tmp +
            motion_controller_withPIC_B.rtb_Add_c_im_ei,
            ((motion_controller_withPIC_B.Add +
              motion_controller_withPIC_B.rtb_Add_c_re_h22) +
             motion_controller_withPIC_B.b_value_ax) +
            motion_controller_withPIC_B.n_a_tmp_a)) *
       motion_controller_withPIC_B.b_value_c0) *
      motion_controller_withPIC_B.b_value_ct) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_fi,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_e) +
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_l) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_f *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__nu /
      ((motion_controller_withPIC_B.rb_a * motion_controller_withPIC_B.rb_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__i3 + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ki)) *
      motion_controller_withPIC_B.Fy1_tmp) / motion_controller_withPIC_P.m;
    motion_controller_withPIC_B.rtb_Add_c_re_tmp = motion_controller_withPIC_P.B
      / 2.0 * motion_controller_withPIC_B.b_value_ip;
    motion_controller_withPIC_B.e_a_tmp = motion_controller_withPIC_P.B / 2.0 *
      motion_controller_withPIC_B.o_a_tmp;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__av =
      motion_controller_withPIC_B.rtb_Add_c_re_tmp /
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ho +
      motion_controller_withPIC_P.b / motion_controller_withPIC_B.b_value_as;
    motion_controller_withPIC_B.rtb_Add_i_tmp_tmp = (0.0 -
      motion_controller_withPIC_P.a) / motion_controller_withPIC_B.b_value_as +
      motion_controller_withPIC_B.e_a_tmp /
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ho;
    motion_controller_withPIC_B.e_a_tmp = motion_controller_withPIC_B.e_a_tmp /
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__nu +
      motion_controller_withPIC_P.a / motion_controller_withPIC_B.q_a_tmp;
    motion_controller_withPIC_B.q_a_tmp = (0.0 - motion_controller_withPIC_P.b) /
      motion_controller_withPIC_B.b_value_l -
      motion_controller_withPIC_B.rtb_Add_c_re_tmp /
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_c;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[13] = ((cos(atan(sin
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_c_im_d -
        motion_controller_withPIC_B.alpha1_tmp_f,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_ax) +
         motion_controller_withPIC_B.b_value_ax) -
        motion_controller_withPIC_B.b_value_i)) *
      motion_controller_withPIC_B.b_value_p5) *
      motion_controller_withPIC_B.b_value_af) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_c_im_ch -
        motion_controller_withPIC_B.alpha1_tmp_f,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_tmp_l) +
         motion_controller_withPIC_B.b_value_ax) -
        motion_controller_withPIC_B.b_value_i)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_n) *
      motion_controller_withPIC_B.q_a_tmp *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_c /
      ((motion_controller_withPIC_B.yb_a * motion_controller_withPIC_B.yb_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_i + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fn) + cos(atan
      (sin(motion_controller_withPIC_B.dr_i - rt_atan2d_snf
           (motion_controller_withPIC_B.rtb_Add_c_im_o3 -
            motion_controller_withPIC_B.alpha1_tmp_f,
            ((motion_controller_withPIC_B.Add +
              motion_controller_withPIC_B.rtb_Add_c_re_ms) -
             motion_controller_withPIC_B.b_value_ax) -
            motion_controller_withPIC_B.b_value_i)) *
       motion_controller_withPIC_B.b_value_p5) *
      motion_controller_withPIC_B.b_value_af) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_c_im_pb -
        motion_controller_withPIC_B.alpha1_tmp_f,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_af) -
         motion_controller_withPIC_B.b_value_ax) -
        motion_controller_withPIC_B.b_value_i)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_n) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__av *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ho /
      ((motion_controller_withPIC_B.ec_a * motion_controller_withPIC_B.ec_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_i + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__kl)) *
      motion_controller_withPIC_B.Fy2_tmp - (cos(atan(sin
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_pt,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_pe) -
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.b_value_c0) *
      motion_controller_withPIC_B.b_value_ct) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_lu,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_n) -
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_l) *
      motion_controller_withPIC_B.rtb_Add_i_tmp_tmp *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ho /
      ((motion_controller_withPIC_B.hc_a * motion_controller_withPIC_B.hc_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__i3 + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__hm) - cos(atan
      (sin(motion_controller_withPIC_B.df_j - rt_atan2d_snf
           (motion_controller_withPIC_B.n_a_tmp +
            motion_controller_withPIC_B.rtb_Add_c_im_kk,
            ((motion_controller_withPIC_B.Add +
              motion_controller_withPIC_B.rtb_Add_c_re_ox) +
             motion_controller_withPIC_B.b_value_ax) +
            motion_controller_withPIC_B.n_a_tmp_a)) *
       motion_controller_withPIC_B.b_value_c0) *
      motion_controller_withPIC_B.b_value_ct) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_i,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_f) +
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_l) *
      motion_controller_withPIC_B.e_a_tmp *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__nu /
      ((motion_controller_withPIC_B.mc_a * motion_controller_withPIC_B.mc_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__i3 + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ki)) *
      motion_controller_withPIC_B.Fy1_tmp) / motion_controller_withPIC_P.m;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[0] = 0.0;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[2] = 0.0;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[4] = 1.0;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[6] = 0.0;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[8] = 0.0;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[10] = 0.0;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[12] = 0.0;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[14] = 1.0;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[3] = 0.0;
    motion_controller_withPIC_B.yb_a = motion_controller_withPIC_P.B *
      motion_controller_withPIC_B.alpha2_tmp / 2.0;
    motion_controller_withPIC_B.rtb_Add_c_re_tmp = motion_controller_withPIC_P.b
      * motion_controller_withPIC_B.alpha1_tmp;
    motion_controller_withPIC_B.rtb_Add_c_im_ch =
      motion_controller_withPIC_B.yb_a -
      motion_controller_withPIC_B.rtb_Add_c_re_tmp;
    motion_controller_withPIC_B.hc_a = motion_controller_withPIC_P.B *
      motion_controller_withPIC_B.alpha1_tmp_k / 2.0;
    motion_controller_withPIC_B.ec_a = motion_controller_withPIC_B.hc_a -
      motion_controller_withPIC_B.rtb_Add_i_tmp;
    motion_controller_withPIC_B.rtb_Add_i_tmp +=
      motion_controller_withPIC_B.hc_a;
    motion_controller_withPIC_B.rtb_Add_c_re_tmp +=
      motion_controller_withPIC_B.yb_a;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[7] = -(((-(cos(atan
      (sin(motion_controller_withPIC_B.df_j - rt_atan2d_snf
           (motion_controller_withPIC_B.n_a_tmp +
            motion_controller_withPIC_B.rtb_Add_c_im_m4,
            ((motion_controller_withPIC_B.Add +
              motion_controller_withPIC_B.rtb_Add_c_re_oc) -
             motion_controller_withPIC_B.b_value_ax) +
            motion_controller_withPIC_B.n_a_tmp_a)) *
       motion_controller_withPIC_B.b_value_c0) *
      motion_controller_withPIC_B.b_value_ct) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_ie,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_tmp_lu) -
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_l) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e *
      motion_controller_withPIC_B.rtb_Add_i_tmp *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eg *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ho) /
      ((motion_controller_withPIC_B.rc_a * motion_controller_withPIC_B.rc_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__i3 + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__hm) + cos(atan
      (sin(motion_controller_withPIC_B.df_j - rt_atan2d_snf
           (motion_controller_withPIC_B.n_a_tmp +
            motion_controller_withPIC_B.rtb_Add_c_im_m44,
            ((motion_controller_withPIC_B.Add +
              motion_controller_withPIC_B.rtb_Add_c_re_hc) +
             motion_controller_withPIC_B.b_value_ax) +
            motion_controller_withPIC_B.n_a_tmp_a)) *
       motion_controller_withPIC_B.b_value_c0) *
      motion_controller_withPIC_B.b_value_ct) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_fb,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_cu) +
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_l) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a *
      motion_controller_withPIC_B.ec_a *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__hn *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__nu /
      ((motion_controller_withPIC_B.wc_a * motion_controller_withPIC_B.wc_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__i3 + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ki)) + cos(atan
      (sin(motion_controller_withPIC_B.dr_i - rt_atan2d_snf
           (motion_controller_withPIC_B.rtb_Add_c_im_bp -
            motion_controller_withPIC_B.alpha1_tmp_f,
            ((motion_controller_withPIC_B.Add +
              motion_controller_withPIC_B.rtb_Add_c_re_pcr) +
             motion_controller_withPIC_B.b_value_ax) -
            motion_controller_withPIC_B.b_value_i)) *
       motion_controller_withPIC_B.b_value_p5) *
      motion_controller_withPIC_B.b_value_af) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_c_im_kb -
        motion_controller_withPIC_B.alpha1_tmp_f,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_ad) +
         motion_controller_withPIC_B.b_value_ax) -
        motion_controller_withPIC_B.b_value_i)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_n) *
      motion_controller_withPIC_B.rtb_Add_c_re_tmp *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ku *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_c /
      ((motion_controller_withPIC_B.ed_a * motion_controller_withPIC_B.ed_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_i + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fn)) + cos(atan
      (sin(motion_controller_withPIC_B.dr_i - rt_atan2d_snf
           (motion_controller_withPIC_B.rtb_Add_c_im_my -
            motion_controller_withPIC_B.alpha1_tmp_f,
            ((motion_controller_withPIC_B.Add +
              motion_controller_withPIC_B.rtb_Add_c_re_ij) -
             motion_controller_withPIC_B.b_value_ax) -
            motion_controller_withPIC_B.b_value_i)) *
       motion_controller_withPIC_B.b_value_p5) *
      motion_controller_withPIC_B.b_value_af) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_c_im_n -
        motion_controller_withPIC_B.alpha1_tmp_f,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_ch) -
         motion_controller_withPIC_B.b_value_ax) -
        motion_controller_withPIC_B.b_value_i)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_n) *
      motion_controller_withPIC_B.rtb_Add_c_im_ch *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d *
      (motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__il -
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eh /
       (motion_controller_withPIC_B.b_value_as *
        motion_controller_withPIC_B.b_value_as)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ho /
      ((motion_controller_withPIC_B.jd_a * motion_controller_withPIC_B.jd_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_i + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__kl)) /
      motion_controller_withPIC_P.Izz;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[11] = -(((cos(atan
      (sin(motion_controller_withPIC_B.dr_i - rt_atan2d_snf
           (motion_controller_withPIC_B.rtb_Add_c_im_mv -
            motion_controller_withPIC_B.alpha1_tmp_f,
            ((motion_controller_withPIC_B.Add +
              motion_controller_withPIC_B.rtb_Add_c_re_ev) -
             motion_controller_withPIC_B.b_value_ax) -
            motion_controller_withPIC_B.b_value_i)) *
       motion_controller_withPIC_B.b_value_p5) *
      motion_controller_withPIC_B.b_value_af) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_c_im_j -
        motion_controller_withPIC_B.alpha1_tmp_f,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_tmp_g) -
         motion_controller_withPIC_B.b_value_ax) -
        motion_controller_withPIC_B.b_value_i)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_n) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__jz *
      motion_controller_withPIC_B.rtb_Add_c_im_ch *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ho /
      ((motion_controller_withPIC_B.pd_a * motion_controller_withPIC_B.pd_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_i + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__kl) - cos(atan
      (sin(motion_controller_withPIC_B.df_j - rt_atan2d_snf
           (motion_controller_withPIC_B.n_a_tmp +
            motion_controller_withPIC_B.rtb_Add_c_im_a5,
            ((motion_controller_withPIC_B.Add +
              motion_controller_withPIC_B.rtb_Add_c_re_fo) -
             motion_controller_withPIC_B.b_value_ax) +
            motion_controller_withPIC_B.n_a_tmp_a)) *
       motion_controller_withPIC_B.b_value_c0) *
      motion_controller_withPIC_B.b_value_ct) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_jg,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_m0) -
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_l) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__bn *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e *
      motion_controller_withPIC_B.rtb_Add_i_tmp *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ho /
      ((motion_controller_withPIC_B.td_a * motion_controller_withPIC_B.td_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__i3 + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__hm)) + cos(atan
      (sin(motion_controller_withPIC_B.df_j - rt_atan2d_snf
           (motion_controller_withPIC_B.n_a_tmp +
            motion_controller_withPIC_B.rtb_Add_c_im_na,
            ((motion_controller_withPIC_B.Add +
              motion_controller_withPIC_B.rtb_Add_c_re_d) +
             motion_controller_withPIC_B.b_value_ax) +
            motion_controller_withPIC_B.n_a_tmp_a)) *
       motion_controller_withPIC_B.b_value_c0) *
      motion_controller_withPIC_B.b_value_ct) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_nr,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_gl) +
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_l) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_f *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a *
      motion_controller_withPIC_B.ec_a *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__nu /
      ((motion_controller_withPIC_B.ae_a * motion_controller_withPIC_B.ae_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__i3 + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ki)) + cos(atan
      (sin(motion_controller_withPIC_B.dr_i - rt_atan2d_snf
           (motion_controller_withPIC_B.rtb_Add_c_im_p2 -
            motion_controller_withPIC_B.alpha1_tmp_f,
            ((motion_controller_withPIC_B.Add +
              motion_controller_withPIC_B.rtb_Add_c_re_pm) +
             motion_controller_withPIC_B.b_value_ax) -
            motion_controller_withPIC_B.b_value_i)) *
       motion_controller_withPIC_B.b_value_p5) *
      motion_controller_withPIC_B.b_value_af) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_c_im_fx -
        motion_controller_withPIC_B.alpha1_tmp_f,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_cg) +
         motion_controller_withPIC_B.b_value_ax) -
        motion_controller_withPIC_B.b_value_i)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_n) *
      motion_controller_withPIC_B.rtb_Add_c_re_tmp *
      (((motion_controller_withPIC_B.Add1 - motion_controller_withPIC_B.Add *
         sin(motion_controller_withPIC_B.yaw)) * sin
        (motion_controller_withPIC_B.yaw) /
        motion_controller_withPIC_B.rtb_Add_i_tmp_tmp_tmp -
        motion_controller_withPIC_B.Add) / (motion_controller_withPIC_P.B *
      motion_controller_withPIC_B.y_g / 2.0 + motion_controller_withPIC_B.Add) +
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eh /
       (motion_controller_withPIC_B.b_value_l *
        motion_controller_withPIC_B.b_value_l)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_c /
      ((motion_controller_withPIC_B.ie_a * motion_controller_withPIC_B.ie_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_i + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fn)) /
      motion_controller_withPIC_P.Izz;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[15] = -(((-(cos(atan
      (sin(motion_controller_withPIC_B.dr_i - rt_atan2d_snf
           (motion_controller_withPIC_B.rtb_Add_c_im_n3 -
            motion_controller_withPIC_B.alpha1_tmp_f,
            ((motion_controller_withPIC_B.Add +
              motion_controller_withPIC_B.rtb_Add_c_re_k) -
             motion_controller_withPIC_B.b_value_ax) -
            motion_controller_withPIC_B.b_value_i)) *
       motion_controller_withPIC_B.b_value_p5) *
      motion_controller_withPIC_B.b_value_af) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_c_im_nj -
        motion_controller_withPIC_B.alpha1_tmp_f,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_tmp_d) -
         motion_controller_withPIC_B.b_value_ax) -
        motion_controller_withPIC_B.b_value_i)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_n) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__av *
      motion_controller_withPIC_B.rtb_Add_c_im_ch *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ho) /
      ((motion_controller_withPIC_B.ne_a * motion_controller_withPIC_B.ne_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_i + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__kl) + cos(atan
      (sin(motion_controller_withPIC_B.df_j - rt_atan2d_snf
           (motion_controller_withPIC_B.n_a_tmp +
            motion_controller_withPIC_B.rtb_Add_c_im_cj,
            ((motion_controller_withPIC_B.Add +
              motion_controller_withPIC_B.rtb_Add_c_re_cq) -
             motion_controller_withPIC_B.b_value_ax) +
            motion_controller_withPIC_B.n_a_tmp_a)) *
       motion_controller_withPIC_B.b_value_c0) *
      motion_controller_withPIC_B.b_value_ct) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_gg,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_oy) -
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_l) *
      motion_controller_withPIC_B.rtb_Add_i_tmp_tmp *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e *
      motion_controller_withPIC_B.rtb_Add_i_tmp *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ho /
      ((motion_controller_withPIC_B.qe_a * motion_controller_withPIC_B.qe_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__i3 + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__hm)) + cos(atan
      (sin(motion_controller_withPIC_B.df_j - rt_atan2d_snf
           (motion_controller_withPIC_B.n_a_tmp +
            motion_controller_withPIC_B.rtb_Add_c_im_mx,
            ((motion_controller_withPIC_B.Add +
              motion_controller_withPIC_B.rtb_Add_c_re_kn) +
             motion_controller_withPIC_B.b_value_ax) +
            motion_controller_withPIC_B.n_a_tmp_a)) *
       motion_controller_withPIC_B.b_value_c0) *
      motion_controller_withPIC_B.b_value_ct) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_jp,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_m1) +
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_l) *
      motion_controller_withPIC_B.e_a_tmp *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a *
      motion_controller_withPIC_B.ec_a *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__nu /
      ((motion_controller_withPIC_B.ve_a * motion_controller_withPIC_B.ve_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__i3 + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ki)) + cos(atan
      (sin(motion_controller_withPIC_B.dr_i - rt_atan2d_snf
           (motion_controller_withPIC_B.rtb_Add_c_im_c3 -
            motion_controller_withPIC_B.alpha1_tmp_f,
            ((motion_controller_withPIC_B.Add +
              motion_controller_withPIC_B.rtb_Add_c_re_g4) +
             motion_controller_withPIC_B.b_value_ax) -
            motion_controller_withPIC_B.b_value_i)) *
       motion_controller_withPIC_B.b_value_p5) *
      motion_controller_withPIC_B.b_value_af) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_c_im_dz -
        motion_controller_withPIC_B.alpha1_tmp_f,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_pr) +
         motion_controller_withPIC_B.b_value_ax) -
        motion_controller_withPIC_B.b_value_i)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_n) *
      motion_controller_withPIC_B.rtb_Add_c_re_tmp *
      motion_controller_withPIC_B.q_a_tmp *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_c /
      ((motion_controller_withPIC_B.df_a * motion_controller_withPIC_B.df_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_i + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fn)) /
      motion_controller_withPIC_P.Izz;
    motion_controller_withPIC_B.B0[1] = ((cos(atan(sin
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_dx,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_if) -
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.b_value_c0) *
      motion_controller_withPIC_B.b_value_ct) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_cx,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_tmp_dv) -
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_l) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e /
      (motion_controller_withPIC_B.ef_a * motion_controller_withPIC_B.ef_a *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__i3 + 1.0) + cos
      (atan(sin(motion_controller_withPIC_B.df_j - rt_atan2d_snf
                (motion_controller_withPIC_B.n_a_tmp +
                 motion_controller_withPIC_B.rtb_Add_c_im_db,
                 ((motion_controller_withPIC_B.Add +
                   motion_controller_withPIC_B.rtb_Add_c_re_f1) +
                  motion_controller_withPIC_B.b_value_ax) +
                 motion_controller_withPIC_B.n_a_tmp_a)) *
            motion_controller_withPIC_B.b_value_c0) *
       motion_controller_withPIC_B.b_value_ct) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_lg,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_g4k) +
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_l) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a /
      (motion_controller_withPIC_B.ff_a * motion_controller_withPIC_B.ff_a *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__i3 + 1.0)) *
      motion_controller_withPIC_B.Fy1_tmp - (sin(atan(sin
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_i3,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_jr) -
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.b_value_c0) *
      motion_controller_withPIC_B.b_value_ct) *
      motion_controller_withPIC_B.b_value_p *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e + sin(atan(sin
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_nm,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_h222) +
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.b_value_c0) *
      motion_controller_withPIC_B.b_value_ct) *
      motion_controller_withPIC_B.b_value_p *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a) *
      motion_controller_withPIC_B.Fy3_tmp) / motion_controller_withPIC_P.m;
    motion_controller_withPIC_B.B0[5] = ((sin(atan(sin
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_c_im_o30 -
        motion_controller_withPIC_B.alpha1_tmp_f,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_tmp_j) -
         motion_controller_withPIC_B.b_value_ax) -
        motion_controller_withPIC_B.b_value_i)) *
      motion_controller_withPIC_B.b_value_p5) *
      motion_controller_withPIC_B.b_value_af) *
      motion_controller_withPIC_B.b_value_e *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d + sin(atan(sin
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_c_im_bd -
        motion_controller_withPIC_B.alpha1_tmp_f,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_ch3) +
         motion_controller_withPIC_B.b_value_ax) -
        motion_controller_withPIC_B.b_value_i)) *
      motion_controller_withPIC_B.b_value_p5) *
      motion_controller_withPIC_B.b_value_af) *
      motion_controller_withPIC_B.b_value_e *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j) *
      motion_controller_withPIC_B.Fy4_tmp - (cos(atan(sin
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_c_im_gs -
        motion_controller_withPIC_B.alpha1_tmp_f,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_ik) -
         motion_controller_withPIC_B.b_value_ax) -
        motion_controller_withPIC_B.b_value_i)) *
      motion_controller_withPIC_B.b_value_p5) *
      motion_controller_withPIC_B.b_value_af) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_c_im_dd -
        motion_controller_withPIC_B.alpha1_tmp_f,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_er) -
         motion_controller_withPIC_B.b_value_ax) -
        motion_controller_withPIC_B.b_value_i)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_n) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d /
      (motion_controller_withPIC_B.gf_a * motion_controller_withPIC_B.gf_a *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_i + 1.0) + cos
      (atan(sin(motion_controller_withPIC_B.dr_i - rt_atan2d_snf
                (motion_controller_withPIC_B.rtb_Add_c_im_nc -
                 motion_controller_withPIC_B.alpha1_tmp_f,
                 ((motion_controller_withPIC_B.Add +
                   motion_controller_withPIC_B.rtb_Add_c_re_ce) +
                  motion_controller_withPIC_B.b_value_ax) -
                 motion_controller_withPIC_B.b_value_i)) *
            motion_controller_withPIC_B.b_value_p5) *
       motion_controller_withPIC_B.b_value_af) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_c_im_l0 -
        motion_controller_withPIC_B.alpha1_tmp_f,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_nn) +
         motion_controller_withPIC_B.b_value_ax) -
        motion_controller_withPIC_B.b_value_i)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_n) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j /
      (motion_controller_withPIC_B.hf_a * motion_controller_withPIC_B.hf_a *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_i + 1.0)) *
      motion_controller_withPIC_B.Fy2_tmp) / motion_controller_withPIC_P.m;
    motion_controller_withPIC_B.B0[0] = 0.0;
    motion_controller_withPIC_B.B0[2] = 0.0;
    motion_controller_withPIC_B.B0[4] = 0.0;
    motion_controller_withPIC_B.B0[6] = 0.0;
    motion_controller_withPIC_B.alpha1 = motion_controller_withPIC_P.B *
      motion_controller_withPIC_B.alpha1 / 2.0;
    motion_controller_withPIC_B.alpha1_tmp_k *= motion_controller_withPIC_P.a;
    motion_controller_withPIC_B.B0[3] = (((sin(atan(sin
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_ph,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_tmp_f) -
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.b_value_c0) *
      motion_controller_withPIC_B.b_value_ct) *
      motion_controller_withPIC_B.b_value_p *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e *
      (motion_controller_withPIC_B.alpha1 -
       motion_controller_withPIC_B.alpha1_tmp_k) - sin(atan(sin
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_oi,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_dk) +
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.b_value_c0) *
      motion_controller_withPIC_B.b_value_ct) *
      motion_controller_withPIC_B.b_value_p *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a *
      (motion_controller_withPIC_B.alpha1 +
       motion_controller_withPIC_B.alpha1_tmp_k)) + cos(atan(sin
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_da,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_hp) -
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.b_value_c0) *
      motion_controller_withPIC_B.b_value_ct) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_c2,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_jrs) -
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_l) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e *
      motion_controller_withPIC_B.rtb_Add_i_tmp /
      (motion_controller_withPIC_B.if_a * motion_controller_withPIC_B.if_a *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__i3 + 1.0)) - cos
      (atan(sin(motion_controller_withPIC_B.df_j - rt_atan2d_snf
                (motion_controller_withPIC_B.n_a_tmp +
                 motion_controller_withPIC_B.rtb_Add_c_im_a4,
                 ((motion_controller_withPIC_B.Add +
                   motion_controller_withPIC_B.rtb_Add_c_re_pi) +
                  motion_controller_withPIC_B.b_value_ax) +
                 motion_controller_withPIC_B.n_a_tmp_a)) *
            motion_controller_withPIC_B.b_value_c0) *
       motion_controller_withPIC_B.b_value_ct) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_c_im_pw,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_c5) +
         motion_controller_withPIC_B.b_value_ax) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_l) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a *
      motion_controller_withPIC_B.ec_a / (motion_controller_withPIC_B.jf_a *
      motion_controller_withPIC_B.jf_a *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__i3 + 1.0)) /
      motion_controller_withPIC_P.Izz;
    motion_controller_withPIC_B.alpha1 = motion_controller_withPIC_P.B *
      motion_controller_withPIC_B.alpha1_tmp / 2.0;
    motion_controller_withPIC_B.alpha1_tmp_k = motion_controller_withPIC_P.b *
      motion_controller_withPIC_B.alpha2_tmp;
    motion_controller_withPIC_B.B0[7] = -(((sin(atan(sin
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_c_im_ow -
        motion_controller_withPIC_B.alpha1_tmp_f,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_tmp_js) -
         motion_controller_withPIC_B.b_value_ax) -
        motion_controller_withPIC_B.b_value_i)) *
      motion_controller_withPIC_B.b_value_p5) *
      motion_controller_withPIC_B.b_value_af) *
      motion_controller_withPIC_B.b_value_e *
      (motion_controller_withPIC_B.alpha1 +
       motion_controller_withPIC_B.alpha1_tmp_k) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d - sin(atan(sin
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_c_im_pi -
        motion_controller_withPIC_B.alpha1_tmp_f,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_jw) +
         motion_controller_withPIC_B.b_value_ax) -
        motion_controller_withPIC_B.b_value_i)) *
      motion_controller_withPIC_B.b_value_p5) *
      motion_controller_withPIC_B.b_value_af) *
      motion_controller_withPIC_B.b_value_e *
      (motion_controller_withPIC_B.alpha1 -
       motion_controller_withPIC_B.alpha1_tmp_k) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j) + cos(atan
      (sin(motion_controller_withPIC_B.dr_i - rt_atan2d_snf
           (motion_controller_withPIC_B.rtb_Add_c_im_jk -
            motion_controller_withPIC_B.alpha1_tmp_f,
            ((motion_controller_withPIC_B.Add +
              motion_controller_withPIC_B.rtb_Add_c_re_kv) -
             motion_controller_withPIC_B.b_value_ax) -
            motion_controller_withPIC_B.b_value_i)) *
       motion_controller_withPIC_B.b_value_p5) *
      motion_controller_withPIC_B.b_value_af) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_c_im_lm -
        motion_controller_withPIC_B.alpha1_tmp_f,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_ob) -
         motion_controller_withPIC_B.b_value_ax) -
        motion_controller_withPIC_B.b_value_i)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_n) *
      motion_controller_withPIC_B.rtb_Add_c_im_ch *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d /
      (motion_controller_withPIC_B.kf_a * motion_controller_withPIC_B.kf_a *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_i + 1.0)) - cos
      (atan(sin(motion_controller_withPIC_B.dr_i - rt_atan2d_snf
                (motion_controller_withPIC_B.e_a_tmp_f -
                 motion_controller_withPIC_B.alpha1_tmp_f,
                 ((motion_controller_withPIC_B.Add +
                   motion_controller_withPIC_B.rtb_Add_c_re_fq) +
                  motion_controller_withPIC_B.b_value_ax) -
                 motion_controller_withPIC_B.b_value_i)) *
            motion_controller_withPIC_B.b_value_p5) *
       motion_controller_withPIC_B.b_value_af) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_c_im_cm -
        motion_controller_withPIC_B.alpha1_tmp_f,
        ((motion_controller_withPIC_B.Add +
          motion_controller_withPIC_B.rtb_Add_c_re_fz) +
         motion_controller_withPIC_B.b_value_ax) -
        motion_controller_withPIC_B.b_value_i)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_n) *
      motion_controller_withPIC_B.rtb_Add_c_re_tmp *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j /
      (motion_controller_withPIC_B.lf_a * motion_controller_withPIC_B.lf_a *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_i + 1.0)) /
      motion_controller_withPIC_P.Izz;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_h[0] =
      motion_controller_withPIC_B.Add1;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_h[1] =
      ((motion_controller_withPIC_B.b_value_o2 +
        motion_controller_withPIC_B.b_value_o) *
       motion_controller_withPIC_B.Fy1_tmp + (motion_controller_withPIC_B.Gain2
        + motion_controller_withPIC_B.Add_i) *
       motion_controller_withPIC_B.Fy2_tmp) * (1.0 /
      motion_controller_withPIC_P.m);
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_h[2] =
      motion_controller_withPIC_B.y_g;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_h[3] =
      (((motion_controller_withPIC_B.Fy1_tmp_tmp_tmp *
         motion_controller_withPIC_B.b_value_o2 +
         motion_controller_withPIC_B.Fy1_tmp_tmp *
         motion_controller_withPIC_B.b_value_o) + motion_controller_withPIC_B.d1
        * motion_controller_withPIC_B.Gain2) + motion_controller_withPIC_B.d_o *
       motion_controller_withPIC_B.Add_i) * (1.0 /
      motion_controller_withPIC_P.Izz);
    for (motion_controller_withPIC_B.isMpcEnable = 0;
         motion_controller_withPIC_B.isMpcEnable <= 2;
         motion_controller_withPIC_B.isMpcEnable += 2) {
      // MATLAB Function: '<S16>/update'
      tmp_5 = _mm_loadu_pd
        (&motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[motion_controller_withPIC_B.isMpcEnable
         + 4]);
      tmp_4 = _mm_loadu_pd
        (&motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[motion_controller_withPIC_B.isMpcEnable]);
      tmp = _mm_loadu_pd
        (&motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[motion_controller_withPIC_B.isMpcEnable
         + 8]);
      tmp_0 = _mm_loadu_pd
        (&motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[motion_controller_withPIC_B.isMpcEnable
         + 12]);
      tmp_1 = _mm_loadu_pd
        (&motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_h[motion_controller_withPIC_B.isMpcEnable]);
      tmp_2 = _mm_loadu_pd
        (&motion_controller_withPIC_B.B0[motion_controller_withPIC_B.isMpcEnable
         + 4]);
      tmp_3 = _mm_loadu_pd
        (&motion_controller_withPIC_B.B0[motion_controller_withPIC_B.isMpcEnable]);
      _mm_storeu_pd
        (&motion_controller_withPIC_B.gama[motion_controller_withPIC_B.isMpcEnable],
         _mm_sub_pd(_mm_sub_pd(tmp_1, _mm_add_pd(_mm_add_pd(_mm_add_pd
             (_mm_mul_pd(tmp_5, _mm_set1_pd(motion_controller_withPIC_B.Add1)),
              _mm_mul_pd(tmp_4, _mm_set1_pd(motion_controller_withPIC_B.yp))),
             _mm_mul_pd(tmp, _mm_set1_pd(motion_controller_withPIC_B.yaw))),
            _mm_mul_pd(tmp_0, _mm_set1_pd(motion_controller_withPIC_B.y_g)))),
                    _mm_add_pd(_mm_mul_pd(tmp_2, _mm_set1_pd
            (motion_controller_withPIC_B.dr_i)), _mm_mul_pd(tmp_3, _mm_set1_pd
            (motion_controller_withPIC_B.df_j)))));
    }

    // MATLAB Function: '<S16>/update'
    for (motion_controller_withPIC_B.isMpcEnable = 0;
         motion_controller_withPIC_B.isMpcEnable < 16;
         motion_controller_withPIC_B.isMpcEnable++) {
      motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.isMpcEnable] =
        0;
    }

    motion_controller_withPIC_B.b_I[0] = 1;
    motion_controller_withPIC_B.b_I[5] = 1;
    motion_controller_withPIC_B.b_I[10] = 1;
    motion_controller_withPIC_B.b_I[15] = 1;
    for (motion_controller_withPIC_B.isMpcEnable = 0;
         motion_controller_withPIC_B.isMpcEnable <= 6;
         motion_controller_withPIC_B.isMpcEnable += 2) {
      // MATLAB Function: '<S16>/update' incorporates:
      //   Constant: '<Root>/Constant2'

      tmp_5 = _mm_loadu_pd
        (&motion_controller_withPIC_B.B0[motion_controller_withPIC_B.isMpcEnable]);
      _mm_storeu_pd
        (&motion_controller_withPIC_B.B0[motion_controller_withPIC_B.isMpcEnable],
         _mm_mul_pd(_mm_set1_pd(motion_controller_withPIC_P.Constant2_Value_e),
                    tmp_5));
    }

    // MATLAB Function: '<S16>/update' incorporates:
    //   Constant: '<Root>/Constant2'

    motion_controller_withPIC_B.gama[0] *=
      motion_controller_withPIC_P.Constant2_Value_e;
    motion_controller_withPIC_B.gama[1] *=
      motion_controller_withPIC_P.Constant2_Value_e;
    motion_controller_withPIC_B.gama[2] *=
      motion_controller_withPIC_P.Constant2_Value_e;
    motion_controller_withPIC_B.gama[3] *=
      motion_controller_withPIC_P.Constant2_Value_e;
    for (motion_controller_withPIC_B.isMpcEnable = 0;
         motion_controller_withPIC_B.isMpcEnable < 4;
         motion_controller_withPIC_B.isMpcEnable++) {
      motion_controller_withPIC_B.b_kidx =
        motion_controller_withPIC_B.isMpcEnable << 2;
      motion_controller_withPIC_B.A1[6 * motion_controller_withPIC_B.isMpcEnable]
        =
        motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[motion_controller_withPIC_B.b_kidx]
        * motion_controller_withPIC_P.Constant2_Value_e + static_cast<real_T>
        (motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.b_kidx]);
      motion_controller_withPIC_B.A1[6 * motion_controller_withPIC_B.isMpcEnable
        + 1] =
        motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[motion_controller_withPIC_B.b_kidx
        + 1] * motion_controller_withPIC_P.Constant2_Value_e +
        static_cast<real_T>
        (motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.b_kidx + 1]);
      motion_controller_withPIC_B.A1[6 * motion_controller_withPIC_B.isMpcEnable
        + 2] =
        motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[motion_controller_withPIC_B.b_kidx
        + 2] * motion_controller_withPIC_P.Constant2_Value_e +
        static_cast<real_T>
        (motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.b_kidx + 2]);
      motion_controller_withPIC_B.A1[6 * motion_controller_withPIC_B.isMpcEnable
        + 3] =
        motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[motion_controller_withPIC_B.b_kidx
        + 3] * motion_controller_withPIC_P.Constant2_Value_e +
        static_cast<real_T>
        (motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.b_kidx + 3]);
    }

    for (motion_controller_withPIC_B.isMpcEnable = 0;
         motion_controller_withPIC_B.isMpcEnable < 2;
         motion_controller_withPIC_B.isMpcEnable++) {
      motion_controller_withPIC_B.b_kidx =
        motion_controller_withPIC_B.isMpcEnable << 2;
      motion_controller_withPIC_B.i = (motion_controller_withPIC_B.isMpcEnable +
        4) * 6;
      motion_controller_withPIC_B.A1[motion_controller_withPIC_B.i] =
        motion_controller_withPIC_B.B0[motion_controller_withPIC_B.b_kidx];
      motion_controller_withPIC_B.A1[motion_controller_withPIC_B.i + 1] =
        motion_controller_withPIC_B.B0[motion_controller_withPIC_B.b_kidx + 1];
      motion_controller_withPIC_B.A1[motion_controller_withPIC_B.i + 2] =
        motion_controller_withPIC_B.B0[motion_controller_withPIC_B.b_kidx + 2];
      motion_controller_withPIC_B.A1[motion_controller_withPIC_B.i + 3] =
        motion_controller_withPIC_B.B0[motion_controller_withPIC_B.b_kidx + 3];
    }

    for (motion_controller_withPIC_B.isMpcEnable = 0;
         motion_controller_withPIC_B.isMpcEnable < 4;
         motion_controller_withPIC_B.isMpcEnable++) {
      motion_controller_withPIC_B.A1[6 * motion_controller_withPIC_B.isMpcEnable
        + 4] = 0.0;
      motion_controller_withPIC_B.A1[6 * motion_controller_withPIC_B.isMpcEnable
        + 5] = 0.0;
    }

    motion_controller_withPIC_B.A1[28] = 1.0;
    motion_controller_withPIC_B.A1[29] = 0.0;
    motion_controller_withPIC_B.A1[34] = 0.0;
    motion_controller_withPIC_B.A1[35] = 1.0;
    motion_controller_withPIC_B.c_I[0] = 0;
    motion_controller_withPIC_B.c_I[1] = 0;
    motion_controller_withPIC_B.c_I[2] = 0;
    motion_controller_withPIC_B.c_I[3] = 0;
    for (motion_controller_withPIC_B.i = 0; motion_controller_withPIC_B.i < 2;
         motion_controller_withPIC_B.i++) {
      motion_controller_withPIC_B.c_I[motion_controller_withPIC_B.i +
        (motion_controller_withPIC_B.i << 1)] = 1;
      motion_controller_withPIC_B.isMpcEnable = motion_controller_withPIC_B.i <<
        2;
      motion_controller_withPIC_B.B1[6 * motion_controller_withPIC_B.i] =
        motion_controller_withPIC_B.B0[motion_controller_withPIC_B.isMpcEnable];
      motion_controller_withPIC_B.B1[6 * motion_controller_withPIC_B.i + 1] =
        motion_controller_withPIC_B.B0[motion_controller_withPIC_B.isMpcEnable +
        1];
      motion_controller_withPIC_B.B1[6 * motion_controller_withPIC_B.i + 2] =
        motion_controller_withPIC_B.B0[motion_controller_withPIC_B.isMpcEnable +
        2];
      motion_controller_withPIC_B.B1[6 * motion_controller_withPIC_B.i + 3] =
        motion_controller_withPIC_B.B0[motion_controller_withPIC_B.isMpcEnable +
        3];
    }

    motion_controller_withPIC_B.B1[4] = motion_controller_withPIC_B.c_I[0];
    motion_controller_withPIC_B.B1[5] = motion_controller_withPIC_B.c_I[1];
    motion_controller_withPIC_B.B1[10] = motion_controller_withPIC_B.c_I[2];
    motion_controller_withPIC_B.B1[11] = motion_controller_withPIC_B.c_I[3];

    // If: '<S60>/If' incorporates:
    //   MATLABSystem: '<S16>/Get Parameter1'

    if (motion_controller_withPIC_B.b_value_k1) {
      // Outputs for IfAction SubSystem: '<S60>/If Action Subsystem' incorporates:
      //   ActionPort: '<S62>/Action Port'

      // Gain: '<S62>/Gain1' incorporates:
      //   MATLABSystem: '<S16>/Get Parameter6'

      motion_controller_withPIC_B.yp = motion_controller_withPIC_P.Gain1_Gain_o *
        motion_controller_withPIC_B.vxp;

      // MATLAB Function: '<S62>/predict'
      memset(&motion_controller_withPIC_B.G_e[0], 0, 720U * sizeof(real_T));
      memcpy(&motion_controller_withPIC_B.t[0], &motion_controller_withPIC_B.A1
             [0], 36U * sizeof(real_T));
      for (motion_controller_withPIC_B.j = 0; motion_controller_withPIC_B.j < 20;
           motion_controller_withPIC_B.j++) {
        motion_controller_withPIC_B.i = motion_controller_withPIC_B.j * 6;
        motion_controller_withPIC_B.d_fm[0] = 6;
        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable < 6;
             motion_controller_withPIC_B.isMpcEnable++) {
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 6;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.G_e[(motion_controller_withPIC_B.i +
              motion_controller_withPIC_B.b_kidx) + 120 *
              motion_controller_withPIC_B.isMpcEnable] =
              motion_controller_withPIC_B.t[motion_controller_withPIC_B.d_fm[0] *
              motion_controller_withPIC_B.isMpcEnable +
              motion_controller_withPIC_B.b_kidx];
            motion_controller_withPIC_B.b_value_c0 = 0.0;
            for (motion_controller_withPIC_B.b_j = 0;
                 motion_controller_withPIC_B.b_j < 6;
                 motion_controller_withPIC_B.b_j++) {
              motion_controller_withPIC_B.b_value_c0 +=
                motion_controller_withPIC_B.t[6 *
                motion_controller_withPIC_B.b_j +
                motion_controller_withPIC_B.isMpcEnable] *
                motion_controller_withPIC_B.A1[6 *
                motion_controller_withPIC_B.b_kidx +
                motion_controller_withPIC_B.b_j];
            }

            motion_controller_withPIC_B.t_j[motion_controller_withPIC_B.isMpcEnable
              + 6 * motion_controller_withPIC_B.b_kidx] =
              motion_controller_withPIC_B.b_value_c0;
          }
        }

        memcpy(&motion_controller_withPIC_B.t[0],
               &motion_controller_withPIC_B.t_j[0], 36U * sizeof(real_T));
        motion_controller_withPIC_B.i = motion_controller_withPIC_B.j << 2;
        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable < 4;
             motion_controller_withPIC_B.isMpcEnable++) {
          motion_controller_withPIC_B.T_c[motion_controller_withPIC_B.i +
            motion_controller_withPIC_B.isMpcEnable] =
            motion_controller_withPIC_B.gama[motion_controller_withPIC_B.isMpcEnable];
        }
      }

      memset(&motion_controller_withPIC_B.H_e[0], 0, 4800U * sizeof(real_T));
      for (motion_controller_withPIC_B.c_jz = 0;
           motion_controller_withPIC_B.c_jz < 20;
           motion_controller_withPIC_B.c_jz++) {
        motion_controller_withPIC_B.i = motion_controller_withPIC_B.c_jz * 6 + 1;
        motion_controller_withPIC_B.b_value_c0 = 1.0;
        motion_controller_withPIC_B.b_g = static_cast<int32_T>(((6.0 -
          static_cast<real_T>(motion_controller_withPIC_B.i)) + 60.0) / 6.0);
        for (motion_controller_withPIC_B.b_j = 0;
             motion_controller_withPIC_B.b_j < motion_controller_withPIC_B.b_g;
             motion_controller_withPIC_B.b_j++) {
          motion_controller_withPIC_B.j = motion_controller_withPIC_B.b_j * 6 +
            motion_controller_withPIC_B.i;
          if (motion_controller_withPIC_B.j > motion_controller_withPIC_B.j + 5)
          {
            motion_controller_withPIC_B.k = -5;
            motion_controller_withPIC_B.j = -5;
          } else {
            motion_controller_withPIC_B.k = motion_controller_withPIC_B.j - 6;
          }

          if (motion_controller_withPIC_B.b_value_c0 >
              (motion_controller_withPIC_B.b_value_c0 + 2.0) - 1.0) {
            motion_controller_withPIC_B.l = 0;
            motion_controller_withPIC_B.isMpcEnable = 0;
          } else {
            motion_controller_withPIC_B.l = static_cast<int32_T>
              (motion_controller_withPIC_B.b_value_c0) - 1;
            motion_controller_withPIC_B.isMpcEnable = static_cast<int32_T>
              ((motion_controller_withPIC_B.b_value_c0 + 2.0) - 1.0);
          }

          motion_controller_withPIC_B.f_idx_0 = motion_controller_withPIC_B.j -
            motion_controller_withPIC_B.k;
          motion_controller_withPIC_B.f_idx_1 =
            motion_controller_withPIC_B.isMpcEnable -
            motion_controller_withPIC_B.l;
          for (motion_controller_withPIC_B.isMpcEnable = 0;
               motion_controller_withPIC_B.isMpcEnable <
               motion_controller_withPIC_B.f_idx_1;
               motion_controller_withPIC_B.isMpcEnable++) {
            for (motion_controller_withPIC_B.b_kidx = 0;
                 motion_controller_withPIC_B.b_kidx <
                 motion_controller_withPIC_B.f_idx_0;
                 motion_controller_withPIC_B.b_kidx++) {
              motion_controller_withPIC_B.H_e[((motion_controller_withPIC_B.k +
                motion_controller_withPIC_B.b_kidx) + 120 *
                (motion_controller_withPIC_B.l +
                 motion_controller_withPIC_B.isMpcEnable)) + 5] =
                motion_controller_withPIC_B.B1[motion_controller_withPIC_B.f_idx_0
                * motion_controller_withPIC_B.isMpcEnable +
                motion_controller_withPIC_B.b_kidx];
            }
          }

          motion_controller_withPIC_B.b_value_c0 += 2.0;
        }

        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable < 6;
             motion_controller_withPIC_B.isMpcEnable++) {
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 2;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.b_value_c0 = 0.0;
            for (motion_controller_withPIC_B.b_j = 0;
                 motion_controller_withPIC_B.b_j < 6;
                 motion_controller_withPIC_B.b_j++) {
              motion_controller_withPIC_B.b_value_c0 +=
                motion_controller_withPIC_B.A1[6 *
                motion_controller_withPIC_B.b_j +
                motion_controller_withPIC_B.isMpcEnable] *
                motion_controller_withPIC_B.B1[6 *
                motion_controller_withPIC_B.b_kidx +
                motion_controller_withPIC_B.b_j];
            }

            motion_controller_withPIC_B.rtb_A1_m[motion_controller_withPIC_B.isMpcEnable
              + 6 * motion_controller_withPIC_B.b_kidx] =
              motion_controller_withPIC_B.b_value_c0;
          }
        }

        memcpy(&motion_controller_withPIC_B.B1[0],
               &motion_controller_withPIC_B.rtb_A1_m[0], 12U * sizeof(real_T));
      }

      memset(&motion_controller_withPIC_B.W_m[0], 0, 9600U * sizeof(real_T));
      for (motion_controller_withPIC_B.isMpcEnable = 0;
           motion_controller_withPIC_B.isMpcEnable < 16;
           motion_controller_withPIC_B.isMpcEnable++) {
        motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.isMpcEnable]
          = 0;
      }

      motion_controller_withPIC_B.b_I[0] = 1;
      motion_controller_withPIC_B.b_I[5] = 1;
      motion_controller_withPIC_B.b_I[10] = 1;
      motion_controller_withPIC_B.b_I[15] = 1;
      for (motion_controller_withPIC_B.isMpcEnable = 0;
           motion_controller_withPIC_B.isMpcEnable < 4;
           motion_controller_withPIC_B.isMpcEnable++) {
        motion_controller_withPIC_B.b_kidx =
          motion_controller_withPIC_B.isMpcEnable << 2;
        motion_controller_withPIC_B.c_t[6 *
          motion_controller_withPIC_B.isMpcEnable] =
          motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.b_kidx];
        motion_controller_withPIC_B.c_t[6 *
          motion_controller_withPIC_B.isMpcEnable + 1] =
          motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.b_kidx + 1];
        motion_controller_withPIC_B.c_t[6 *
          motion_controller_withPIC_B.isMpcEnable + 2] =
          motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.b_kidx + 2];
        motion_controller_withPIC_B.c_t[6 *
          motion_controller_withPIC_B.isMpcEnable + 3] =
          motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.b_kidx + 3];
        motion_controller_withPIC_B.c_t[6 *
          motion_controller_withPIC_B.isMpcEnable + 4] = 0.0;
        motion_controller_withPIC_B.c_t[6 *
          motion_controller_withPIC_B.isMpcEnable + 5] = 0.0;
      }

      for (motion_controller_withPIC_B.b_g = 0; motion_controller_withPIC_B.b_g <
           20; motion_controller_withPIC_B.b_g++) {
        motion_controller_withPIC_B.i = motion_controller_withPIC_B.b_g * 6 + 1;
        motion_controller_withPIC_B.b_value_c0 = 1.0;
        motion_controller_withPIC_B.c_jz = static_cast<int32_T>(((6.0 -
          static_cast<real_T>(motion_controller_withPIC_B.i)) + 120.0) / 6.0);
        for (motion_controller_withPIC_B.b_j = 0;
             motion_controller_withPIC_B.b_j < motion_controller_withPIC_B.c_jz;
             motion_controller_withPIC_B.b_j++) {
          motion_controller_withPIC_B.j = motion_controller_withPIC_B.b_j * 6 +
            motion_controller_withPIC_B.i;
          if (motion_controller_withPIC_B.j > motion_controller_withPIC_B.j + 5)
          {
            motion_controller_withPIC_B.k = -5;
            motion_controller_withPIC_B.j = -5;
          } else {
            motion_controller_withPIC_B.k = motion_controller_withPIC_B.j - 6;
          }

          if (motion_controller_withPIC_B.b_value_c0 >
              (motion_controller_withPIC_B.b_value_c0 + 4.0) - 1.0) {
            motion_controller_withPIC_B.l = 0;
            motion_controller_withPIC_B.isMpcEnable = 0;
          } else {
            motion_controller_withPIC_B.l = static_cast<int32_T>
              (motion_controller_withPIC_B.b_value_c0) - 1;
            motion_controller_withPIC_B.isMpcEnable = static_cast<int32_T>
              ((motion_controller_withPIC_B.b_value_c0 + 4.0) - 1.0);
          }

          motion_controller_withPIC_B.f_idx_0 = motion_controller_withPIC_B.j -
            motion_controller_withPIC_B.k;
          motion_controller_withPIC_B.f_idx_1 =
            motion_controller_withPIC_B.isMpcEnable -
            motion_controller_withPIC_B.l;
          for (motion_controller_withPIC_B.isMpcEnable = 0;
               motion_controller_withPIC_B.isMpcEnable <
               motion_controller_withPIC_B.f_idx_1;
               motion_controller_withPIC_B.isMpcEnable++) {
            for (motion_controller_withPIC_B.b_kidx = 0;
                 motion_controller_withPIC_B.b_kidx <
                 motion_controller_withPIC_B.f_idx_0;
                 motion_controller_withPIC_B.b_kidx++) {
              motion_controller_withPIC_B.W_m[((motion_controller_withPIC_B.k +
                motion_controller_withPIC_B.b_kidx) + 120 *
                (motion_controller_withPIC_B.l +
                 motion_controller_withPIC_B.isMpcEnable)) + 5] =
                motion_controller_withPIC_B.c_t[motion_controller_withPIC_B.f_idx_0
                * motion_controller_withPIC_B.isMpcEnable +
                motion_controller_withPIC_B.b_kidx];
            }
          }

          motion_controller_withPIC_B.b_value_c0 += 4.0;
        }

        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable < 6;
             motion_controller_withPIC_B.isMpcEnable++) {
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 4;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.b_value_c0 = 0.0;
            for (motion_controller_withPIC_B.b_j = 0;
                 motion_controller_withPIC_B.b_j < 6;
                 motion_controller_withPIC_B.b_j++) {
              motion_controller_withPIC_B.b_value_c0 +=
                motion_controller_withPIC_B.A1[6 *
                motion_controller_withPIC_B.b_j +
                motion_controller_withPIC_B.isMpcEnable] *
                motion_controller_withPIC_B.c_t[6 *
                motion_controller_withPIC_B.b_kidx +
                motion_controller_withPIC_B.b_j];
            }

            motion_controller_withPIC_B.rtb_A1_o[motion_controller_withPIC_B.isMpcEnable
              + 6 * motion_controller_withPIC_B.b_kidx] =
              motion_controller_withPIC_B.b_value_c0;
          }
        }

        memcpy(&motion_controller_withPIC_B.c_t[0],
               &motion_controller_withPIC_B.rtb_A1_o[0], 24U * sizeof(real_T));
      }

      // End of MATLAB Function: '<S62>/predict'

      // MATLAB Function: '<S62>/solvex' incorporates:
      //   MATLABSystem: '<S16>/Get Parameter'
      //   MATLABSystem: '<S16>/Get Parameter6'
      //   Reshape: '<S16>/Reshape'
      //   UnitDelay: '<S16>/Unit Delay'
      //   UnitDelay: '<S16>/Unit Delay1'

      if (!motion_controller_withPIC_DW.x0_not_empty_k) {
        motion_controller_withPIC_DW.x0_not_empty_k = true;
        motion_controller_withPIC_DW.Umin_c = -motion_controller_withPIC_B.vyp;
        motion_controller_withPIC_DW.Umax_n = motion_controller_withPIC_B.vyp;
        motion_controller_withPIC_B.isMpcEnable = -1;
        motion_controller_withPIC_B.b_kidx = -1;
        for (motion_controller_withPIC_B.i = 0; motion_controller_withPIC_B.i <
             20; motion_controller_withPIC_B.i++) {
          for (motion_controller_withPIC_B.j = 0; motion_controller_withPIC_B.j <
               2; motion_controller_withPIC_B.j++) {
            motion_controller_withPIC_B.c_jz = motion_controller_withPIC_B.j <<
              1;
            motion_controller_withPIC_B.B_b = B[motion_controller_withPIC_B.c_jz];
            motion_controller_withPIC_B.B_k = B[motion_controller_withPIC_B.c_jz
              + 1];
            for (motion_controller_withPIC_B.c_jz = 0;
                 motion_controller_withPIC_B.c_jz < 20;
                 motion_controller_withPIC_B.c_jz++) {
              motion_controller_withPIC_B.A = A_0[20 *
                motion_controller_withPIC_B.i + motion_controller_withPIC_B.c_jz];
              motion_controller_withPIC_B.Rp[motion_controller_withPIC_B.isMpcEnable
                + 1] = motion_controller_withPIC_B.A *
                motion_controller_withPIC_B.B_b;
              motion_controller_withPIC_B.K[motion_controller_withPIC_B.b_kidx +
                1] = static_cast<int8_T>(motion_controller_withPIC_B.A *
                motion_controller_withPIC_B.B_b);
              motion_controller_withPIC_B.Rp[motion_controller_withPIC_B.isMpcEnable
                + 2] = motion_controller_withPIC_B.A *
                motion_controller_withPIC_B.B_k;
              motion_controller_withPIC_B.K[motion_controller_withPIC_B.b_kidx +
                2] = static_cast<int8_T>(motion_controller_withPIC_B.A *
                motion_controller_withPIC_B.B_k);
              motion_controller_withPIC_B.b_kidx =
                motion_controller_withPIC_B.isMpcEnable + 2;
              motion_controller_withPIC_B.isMpcEnable += 2;
            }
          }
        }

        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable < 40;
             motion_controller_withPIC_B.isMpcEnable++) {
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 40;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.i = 40 *
              motion_controller_withPIC_B.isMpcEnable +
              motion_controller_withPIC_B.b_kidx;
            motion_controller_withPIC_B.j = 80 *
              motion_controller_withPIC_B.isMpcEnable +
              motion_controller_withPIC_B.b_kidx;
            motion_controller_withPIC_DW.A_j[motion_controller_withPIC_B.j] =
              motion_controller_withPIC_B.Rp[motion_controller_withPIC_B.i];
            motion_controller_withPIC_DW.A_j[motion_controller_withPIC_B.j + 40]
              = -static_cast<real_T>
              (motion_controller_withPIC_B.K[motion_controller_withPIC_B.i]);
          }
        }
      }

      memset(&motion_controller_withPIC_B.Qp[0], 0, 14400U * sizeof(real_T));
      memset(&motion_controller_withPIC_B.rtb_H_o[0], 0, 120U * sizeof(real_T));
      motion_controller_withPIC_B.k = 6;
      for (motion_controller_withPIC_B.b_j = 0; motion_controller_withPIC_B.b_j <
           20; motion_controller_withPIC_B.b_j++) {
        motion_controller_withPIC_B.j = motion_controller_withPIC_B.b_j * 6 + 6;
        if (motion_controller_withPIC_B.j - 5 > motion_controller_withPIC_B.j) {
          motion_controller_withPIC_B.c_jz = 0;
          motion_controller_withPIC_B.b_g = 0;
        } else {
          motion_controller_withPIC_B.c_jz = motion_controller_withPIC_B.j - 6;
          motion_controller_withPIC_B.b_g = motion_controller_withPIC_B.j;
        }

        if (motion_controller_withPIC_B.k - 5 > motion_controller_withPIC_B.k) {
          motion_controller_withPIC_B.i = 0;
          motion_controller_withPIC_B.isMpcEnable = 0;
        } else {
          motion_controller_withPIC_B.i = motion_controller_withPIC_B.k - 6;
          motion_controller_withPIC_B.isMpcEnable =
            motion_controller_withPIC_B.k;
        }

        motion_controller_withPIC_B.f_idx_0 = motion_controller_withPIC_B.b_g -
          motion_controller_withPIC_B.c_jz;
        motion_controller_withPIC_B.f_idx_1 =
          motion_controller_withPIC_B.isMpcEnable -
          motion_controller_withPIC_B.i;
        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable <
             motion_controller_withPIC_B.f_idx_1;
             motion_controller_withPIC_B.isMpcEnable++) {
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx <
               motion_controller_withPIC_B.f_idx_0;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.Qp[(motion_controller_withPIC_B.c_jz +
              motion_controller_withPIC_B.b_kidx) + 120 *
              (motion_controller_withPIC_B.i +
               motion_controller_withPIC_B.isMpcEnable)] =
              motion_controller_withPIC_B.Q[motion_controller_withPIC_B.f_idx_0 *
              motion_controller_withPIC_B.isMpcEnable +
              motion_controller_withPIC_B.b_kidx];
          }
        }

        motion_controller_withPIC_B.k += 6;
        if (motion_controller_withPIC_B.j - 5 > motion_controller_withPIC_B.j) {
          motion_controller_withPIC_B.b_kidx = 0;
          motion_controller_withPIC_B.j = 0;
        } else {
          motion_controller_withPIC_B.b_kidx = motion_controller_withPIC_B.j - 6;
        }

        motion_controller_withPIC_B.i = motion_controller_withPIC_B.j -
          motion_controller_withPIC_B.b_kidx;
        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable <
             motion_controller_withPIC_B.i;
             motion_controller_withPIC_B.isMpcEnable++) {
          motion_controller_withPIC_B.rtb_H_o[motion_controller_withPIC_B.b_kidx
            + motion_controller_withPIC_B.isMpcEnable] =
            motion_controller_withPIC_B.y_j[motion_controller_withPIC_B.isMpcEnable];
        }
      }

      memset(&motion_controller_withPIC_B.Rp[0], 0, 1600U * sizeof(real_T));
      motion_controller_withPIC_B.k = 2;
      for (motion_controller_withPIC_B.b_j = 0; motion_controller_withPIC_B.b_j <
           20; motion_controller_withPIC_B.b_j++) {
        motion_controller_withPIC_B.j = motion_controller_withPIC_B.b_j << 1;
        if (motion_controller_withPIC_B.k - 1 > motion_controller_withPIC_B.k) {
          motion_controller_withPIC_B.i = 0;
          motion_controller_withPIC_B.isMpcEnable = 0;
        } else {
          motion_controller_withPIC_B.i = motion_controller_withPIC_B.k - 2;
          motion_controller_withPIC_B.isMpcEnable =
            motion_controller_withPIC_B.k;
        }

        motion_controller_withPIC_B.f_idx_1 =
          motion_controller_withPIC_B.isMpcEnable -
          motion_controller_withPIC_B.i;
        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable <
             motion_controller_withPIC_B.f_idx_1;
             motion_controller_withPIC_B.isMpcEnable++) {
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 2;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.Rp[(motion_controller_withPIC_B.j +
              motion_controller_withPIC_B.b_kidx) + 40 *
              (motion_controller_withPIC_B.i +
               motion_controller_withPIC_B.isMpcEnable)] =
              motion_controller_withPIC_B.R
              [(motion_controller_withPIC_B.isMpcEnable << 1) +
              motion_controller_withPIC_B.b_kidx];
          }
        }

        motion_controller_withPIC_B.k += 2;
      }

      for (motion_controller_withPIC_B.isMpcEnable = 0;
           motion_controller_withPIC_B.isMpcEnable < 120;
           motion_controller_withPIC_B.isMpcEnable++) {
        motion_controller_withPIC_B.b_kidx =
          motion_controller_withPIC_B.isMpcEnable * 40;
        memset
          (&motion_controller_withPIC_B.y_mb[motion_controller_withPIC_B.b_kidx],
           0, 40U * sizeof(real_T));
        for (motion_controller_withPIC_B.i = 0; motion_controller_withPIC_B.i <
             120; motion_controller_withPIC_B.i++) {
          motion_controller_withPIC_B.b_value_c0 =
            motion_controller_withPIC_B.Qp[motion_controller_withPIC_B.i * 120 +
            motion_controller_withPIC_B.isMpcEnable];
          for (motion_controller_withPIC_B.j = 0; motion_controller_withPIC_B.j <
               40; motion_controller_withPIC_B.j++) {
            motion_controller_withPIC_B.c_jz =
              motion_controller_withPIC_B.b_kidx + motion_controller_withPIC_B.j;
            motion_controller_withPIC_B.y_mb[motion_controller_withPIC_B.c_jz] +=
              motion_controller_withPIC_B.H_e[motion_controller_withPIC_B.j *
              120 + motion_controller_withPIC_B.i] *
              motion_controller_withPIC_B.b_value_c0;
          }
        }

        memset
          (&motion_controller_withPIC_B.b_y[motion_controller_withPIC_B.b_kidx],
           0, 40U * sizeof(real_T));
        for (motion_controller_withPIC_B.i = 0; motion_controller_withPIC_B.i <
             120; motion_controller_withPIC_B.i++) {
          motion_controller_withPIC_B.b_value_c0 =
            motion_controller_withPIC_B.Qp[motion_controller_withPIC_B.i * 120 +
            motion_controller_withPIC_B.isMpcEnable];
          for (motion_controller_withPIC_B.b_g = 0;
               motion_controller_withPIC_B.b_g < 40;
               motion_controller_withPIC_B.b_g++) {
            motion_controller_withPIC_B.j = motion_controller_withPIC_B.b_kidx +
              motion_controller_withPIC_B.b_g;
            motion_controller_withPIC_B.b_y[motion_controller_withPIC_B.j] +=
              motion_controller_withPIC_B.H_e[motion_controller_withPIC_B.b_g *
              120 + motion_controller_withPIC_B.i] *
              motion_controller_withPIC_B.b_value_c0;
          }
        }
      }

      motion_controller_withPIC_B.b_value_c0 =
        motion_controller_withPIC_DW.Umax_n -
        motion_controller_withPIC_DW.UnitDelay_DSTATE;
      motion_controller_withPIC_B.b_value_p5 =
        motion_controller_withPIC_DW.Umax_n -
        motion_controller_withPIC_DW.UnitDelay1_DSTATE;
      motion_controller_withPIC_B.isMpcEnable = -1;
      for (motion_controller_withPIC_B.b_kidx = 0;
           motion_controller_withPIC_B.b_kidx < 20;
           motion_controller_withPIC_B.b_kidx++) {
        motion_controller_withPIC_B.T[motion_controller_withPIC_B.isMpcEnable +
          1] = motion_controller_withPIC_B.b_value_c0;
        motion_controller_withPIC_B.T[motion_controller_withPIC_B.isMpcEnable +
          2] = motion_controller_withPIC_B.b_value_p5;
        motion_controller_withPIC_B.isMpcEnable += 2;
      }

      motion_controller_withPIC_B.b_value_c0 =
        motion_controller_withPIC_DW.UnitDelay_DSTATE -
        motion_controller_withPIC_DW.Umin_c;
      motion_controller_withPIC_B.b_value_p5 =
        motion_controller_withPIC_DW.UnitDelay1_DSTATE -
        motion_controller_withPIC_DW.Umin_c;
      motion_controller_withPIC_B.isMpcEnable = -1;
      for (motion_controller_withPIC_B.b_kidx = 0;
           motion_controller_withPIC_B.b_kidx < 20;
           motion_controller_withPIC_B.b_kidx++) {
        motion_controller_withPIC_B.b_K[motion_controller_withPIC_B.isMpcEnable
          + 1] = motion_controller_withPIC_B.b_value_c0;
        motion_controller_withPIC_B.b_K[motion_controller_withPIC_B.isMpcEnable
          + 2] = motion_controller_withPIC_B.b_value_p5;
        motion_controller_withPIC_B.isMpcEnable += 2;
      }

      for (motion_controller_withPIC_B.i = 0; motion_controller_withPIC_B.i < 40;
           motion_controller_withPIC_B.i++) {
        motion_controller_withPIC_B.V[motion_controller_withPIC_B.i] =
          motion_controller_withPIC_DW.x0_i[motion_controller_withPIC_B.i];
        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable < 120;
             motion_controller_withPIC_B.isMpcEnable++) {
          motion_controller_withPIC_B.b_value_p5 = 0.0;
          motion_controller_withPIC_B.b_value_c0 = 0.0;
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 120;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.b_value_p5 +=
              motion_controller_withPIC_B.H_e[120 *
              motion_controller_withPIC_B.i + motion_controller_withPIC_B.b_kidx]
              * motion_controller_withPIC_B.Qp[120 *
              motion_controller_withPIC_B.isMpcEnable +
              motion_controller_withPIC_B.b_kidx];
            motion_controller_withPIC_B.b_value_c0 =
              motion_controller_withPIC_B.b_value_p5;
          }

          motion_controller_withPIC_B.b_kidx = 40 *
            motion_controller_withPIC_B.isMpcEnable +
            motion_controller_withPIC_B.i;
          motion_controller_withPIC_B.rtb_H_e_k[motion_controller_withPIC_B.b_kidx]
            = motion_controller_withPIC_B.b_value_c0;
          motion_controller_withPIC_B.rtb_H_e_c[motion_controller_withPIC_B.b_kidx]
            = motion_controller_withPIC_B.b_value_p5;
        }

        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable < 6;
             motion_controller_withPIC_B.isMpcEnable++) {
          motion_controller_withPIC_B.b_value_c0 = 0.0;
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 120;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.b_value_c0 +=
              motion_controller_withPIC_B.rtb_H_e_k[40 *
              motion_controller_withPIC_B.b_kidx + motion_controller_withPIC_B.i]
              * motion_controller_withPIC_B.G_e[120 *
              motion_controller_withPIC_B.isMpcEnable +
              motion_controller_withPIC_B.b_kidx];
          }

          motion_controller_withPIC_B.rtb_H_e_d[motion_controller_withPIC_B.i +
            40 * motion_controller_withPIC_B.isMpcEnable] =
            motion_controller_withPIC_B.b_value_c0;
        }

        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable < 80;
             motion_controller_withPIC_B.isMpcEnable++) {
          motion_controller_withPIC_B.y_g = 0.0;
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 120;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.y_g += motion_controller_withPIC_B.y_mb
              [40 * motion_controller_withPIC_B.b_kidx +
              motion_controller_withPIC_B.i] * motion_controller_withPIC_B.W_m
              [120 * motion_controller_withPIC_B.isMpcEnable +
              motion_controller_withPIC_B.b_kidx];
          }

          motion_controller_withPIC_B.y_b[motion_controller_withPIC_B.i + 40 *
            motion_controller_withPIC_B.isMpcEnable] =
            motion_controller_withPIC_B.y_g;
        }

        motion_controller_withPIC_B.b_value_c0 = 0.0;
        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable < 6;
             motion_controller_withPIC_B.isMpcEnable++) {
          motion_controller_withPIC_B.b_value_c0 +=
            motion_controller_withPIC_B.rtb_H_e_d[40 *
            motion_controller_withPIC_B.isMpcEnable +
            motion_controller_withPIC_B.i] *
            motion_controller_withPIC_B.Reshape[motion_controller_withPIC_B.isMpcEnable];
        }

        motion_controller_withPIC_B.y_g = 0.0;
        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable < 80;
             motion_controller_withPIC_B.isMpcEnable++) {
          motion_controller_withPIC_B.y_g += motion_controller_withPIC_B.y_b[40 *
            motion_controller_withPIC_B.isMpcEnable +
            motion_controller_withPIC_B.i] *
            motion_controller_withPIC_B.T_c[motion_controller_withPIC_B.isMpcEnable];
        }

        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable < 40;
             motion_controller_withPIC_B.isMpcEnable++) {
          motion_controller_withPIC_B.alpha1 = 0.0;
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 120;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.alpha1 +=
              motion_controller_withPIC_B.rtb_H_e_c[40 *
              motion_controller_withPIC_B.b_kidx + motion_controller_withPIC_B.i]
              * motion_controller_withPIC_B.H_e[120 *
              motion_controller_withPIC_B.isMpcEnable +
              motion_controller_withPIC_B.b_kidx];
          }

          motion_controller_withPIC_B.b_kidx = 40 *
            motion_controller_withPIC_B.isMpcEnable +
            motion_controller_withPIC_B.i;
          motion_controller_withPIC_B.rtb_H_e_m[motion_controller_withPIC_B.b_kidx]
            = motion_controller_withPIC_B.Rp[motion_controller_withPIC_B.b_kidx]
            + motion_controller_withPIC_B.alpha1;
        }

        motion_controller_withPIC_B.alpha1 = 0.0;
        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable < 120;
             motion_controller_withPIC_B.isMpcEnable++) {
          motion_controller_withPIC_B.alpha1 += motion_controller_withPIC_B.b_y
            [40 * motion_controller_withPIC_B.isMpcEnable +
            motion_controller_withPIC_B.i] *
            motion_controller_withPIC_B.rtb_H_o[motion_controller_withPIC_B.isMpcEnable];
        }

        motion_controller_withPIC_B.rtb_H_e_j[motion_controller_withPIC_B.i] =
          (motion_controller_withPIC_B.b_value_c0 +
           motion_controller_withPIC_B.y_g) - motion_controller_withPIC_B.alpha1;
        motion_controller_withPIC_B.rtb_T_b[motion_controller_withPIC_B.i] =
          motion_controller_withPIC_B.T[motion_controller_withPIC_B.i];
        motion_controller_withPIC_B.rtb_T_b[motion_controller_withPIC_B.i + 40] =
          motion_controller_withPIC_B.b_K[motion_controller_withPIC_B.i];
        motion_controller_withPIC_B.rtb_Gain1_c_f[motion_controller_withPIC_B.i]
          = motion_controller_withPIC_B.yp;
        motion_controller_withPIC_B.b_value_a[motion_controller_withPIC_B.i] =
          motion_controller_withPIC_B.vxp;
      }

      motion_controller_with_quadprog(motion_controller_withPIC_B.rtb_H_e_m,
        motion_controller_withPIC_B.rtb_H_e_j, motion_controller_withPIC_DW.A_j,
        motion_controller_withPIC_B.rtb_T_b,
        motion_controller_withPIC_B.rtb_Gain1_c_f,
        motion_controller_withPIC_B.b_value_a, motion_controller_withPIC_B.V,
        &motion_controller_withPIC_DW.opts);
      motion_controller_withPIC_B.b_value_c0 = motion_controller_withPIC_B.V[0]
        + motion_controller_withPIC_DW.UnitDelay_DSTATE;
      motion_controller_withPIC_B.b_value_p5 = motion_controller_withPIC_B.V[1]
        + motion_controller_withPIC_DW.UnitDelay1_DSTATE;

      // SignalConversion generated from: '<S62>/dfl' incorporates:
      //   MATLAB Function: '<S62>/solvex'
      //   Merge: '<S60>/Merge'

      motion_controller_withPIC_B.Merge[0] =
        motion_controller_withPIC_B.b_value_c0;

      // SignalConversion generated from: '<S62>/dfr' incorporates:
      //   MATLAB Function: '<S62>/solvex'
      //   Merge: '<S60>/Merge'

      motion_controller_withPIC_B.Merge[1] =
        motion_controller_withPIC_B.b_value_c0;

      // SignalConversion generated from: '<S62>/drl' incorporates:
      //   MATLAB Function: '<S62>/solvex'
      //   Merge: '<S60>/Merge'

      motion_controller_withPIC_B.Merge[2] =
        motion_controller_withPIC_B.b_value_p5;

      // SignalConversion generated from: '<S62>/drr' incorporates:
      //   MATLAB Function: '<S62>/solvex'
      //   Merge: '<S60>/Merge'

      motion_controller_withPIC_B.Merge[3] =
        motion_controller_withPIC_B.b_value_p5;

      // End of Outputs for SubSystem: '<S60>/If Action Subsystem'
    } else {
      // Outputs for IfAction SubSystem: '<S60>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S63>/Action Port'

      // Gain: '<S63>/Gain1' incorporates:
      //   MATLABSystem: '<S16>/Get Parameter6'

      motion_controller_withPIC_B.yp = motion_controller_withPIC_P.Gain1_Gain_c *
        motion_controller_withPIC_B.vxp;

      // MATLAB Function: '<S63>/predict'
      memset(&motion_controller_withPIC_B.G[0], 0, 360U * sizeof(real_T));
      memcpy(&motion_controller_withPIC_B.t[0], &motion_controller_withPIC_B.A1
             [0], 36U * sizeof(real_T));
      for (motion_controller_withPIC_B.j = 0; motion_controller_withPIC_B.j < 10;
           motion_controller_withPIC_B.j++) {
        motion_controller_withPIC_B.i = motion_controller_withPIC_B.j * 6;
        motion_controller_withPIC_B.d_fm[0] = 6;
        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable < 6;
             motion_controller_withPIC_B.isMpcEnable++) {
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 6;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.G[(motion_controller_withPIC_B.i +
              motion_controller_withPIC_B.b_kidx) + 60 *
              motion_controller_withPIC_B.isMpcEnable] =
              motion_controller_withPIC_B.t[motion_controller_withPIC_B.d_fm[0] *
              motion_controller_withPIC_B.isMpcEnable +
              motion_controller_withPIC_B.b_kidx];
            motion_controller_withPIC_B.b_value_c0 = 0.0;
            for (motion_controller_withPIC_B.b_j = 0;
                 motion_controller_withPIC_B.b_j < 6;
                 motion_controller_withPIC_B.b_j++) {
              motion_controller_withPIC_B.b_value_c0 +=
                motion_controller_withPIC_B.t[6 *
                motion_controller_withPIC_B.b_j +
                motion_controller_withPIC_B.isMpcEnable] *
                motion_controller_withPIC_B.A1[6 *
                motion_controller_withPIC_B.b_kidx +
                motion_controller_withPIC_B.b_j];
            }

            motion_controller_withPIC_B.t_j[motion_controller_withPIC_B.isMpcEnable
              + 6 * motion_controller_withPIC_B.b_kidx] =
              motion_controller_withPIC_B.b_value_c0;
          }
        }

        memcpy(&motion_controller_withPIC_B.t[0],
               &motion_controller_withPIC_B.t_j[0], 36U * sizeof(real_T));
        motion_controller_withPIC_B.i = motion_controller_withPIC_B.j << 2;
        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable < 4;
             motion_controller_withPIC_B.isMpcEnable++) {
          motion_controller_withPIC_B.T[motion_controller_withPIC_B.i +
            motion_controller_withPIC_B.isMpcEnable] =
            motion_controller_withPIC_B.gama[motion_controller_withPIC_B.isMpcEnable];
        }
      }

      memset(&motion_controller_withPIC_B.H[0], 0, 1200U * sizeof(real_T));
      for (motion_controller_withPIC_B.c_jz = 0;
           motion_controller_withPIC_B.c_jz < 10;
           motion_controller_withPIC_B.c_jz++) {
        motion_controller_withPIC_B.i = motion_controller_withPIC_B.c_jz * 6 + 1;
        motion_controller_withPIC_B.b_value_c0 = 1.0;
        motion_controller_withPIC_B.b_g = static_cast<int32_T>(((6.0 -
          static_cast<real_T>(motion_controller_withPIC_B.i)) + 60.0) / 6.0);
        for (motion_controller_withPIC_B.b_j = 0;
             motion_controller_withPIC_B.b_j < motion_controller_withPIC_B.b_g;
             motion_controller_withPIC_B.b_j++) {
          motion_controller_withPIC_B.j = motion_controller_withPIC_B.b_j * 6 +
            motion_controller_withPIC_B.i;
          if (motion_controller_withPIC_B.j > motion_controller_withPIC_B.j + 5)
          {
            motion_controller_withPIC_B.k = -5;
            motion_controller_withPIC_B.j = -5;
          } else {
            motion_controller_withPIC_B.k = motion_controller_withPIC_B.j - 6;
          }

          if (motion_controller_withPIC_B.b_value_c0 >
              (motion_controller_withPIC_B.b_value_c0 + 2.0) - 1.0) {
            motion_controller_withPIC_B.l = 0;
            motion_controller_withPIC_B.isMpcEnable = 0;
          } else {
            motion_controller_withPIC_B.l = static_cast<int32_T>
              (motion_controller_withPIC_B.b_value_c0) - 1;
            motion_controller_withPIC_B.isMpcEnable = static_cast<int32_T>
              ((motion_controller_withPIC_B.b_value_c0 + 2.0) - 1.0);
          }

          motion_controller_withPIC_B.f_idx_0 = motion_controller_withPIC_B.j -
            motion_controller_withPIC_B.k;
          motion_controller_withPIC_B.f_idx_1 =
            motion_controller_withPIC_B.isMpcEnable -
            motion_controller_withPIC_B.l;
          for (motion_controller_withPIC_B.isMpcEnable = 0;
               motion_controller_withPIC_B.isMpcEnable <
               motion_controller_withPIC_B.f_idx_1;
               motion_controller_withPIC_B.isMpcEnable++) {
            for (motion_controller_withPIC_B.b_kidx = 0;
                 motion_controller_withPIC_B.b_kidx <
                 motion_controller_withPIC_B.f_idx_0;
                 motion_controller_withPIC_B.b_kidx++) {
              motion_controller_withPIC_B.H[((motion_controller_withPIC_B.k +
                motion_controller_withPIC_B.b_kidx) + 60 *
                (motion_controller_withPIC_B.l +
                 motion_controller_withPIC_B.isMpcEnable)) + 5] =
                motion_controller_withPIC_B.B1[motion_controller_withPIC_B.f_idx_0
                * motion_controller_withPIC_B.isMpcEnable +
                motion_controller_withPIC_B.b_kidx];
            }
          }

          motion_controller_withPIC_B.b_value_c0 += 2.0;
        }

        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable < 6;
             motion_controller_withPIC_B.isMpcEnable++) {
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 2;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.b_value_c0 = 0.0;
            for (motion_controller_withPIC_B.b_j = 0;
                 motion_controller_withPIC_B.b_j < 6;
                 motion_controller_withPIC_B.b_j++) {
              motion_controller_withPIC_B.b_value_c0 +=
                motion_controller_withPIC_B.A1[6 *
                motion_controller_withPIC_B.b_j +
                motion_controller_withPIC_B.isMpcEnable] *
                motion_controller_withPIC_B.B1[6 *
                motion_controller_withPIC_B.b_kidx +
                motion_controller_withPIC_B.b_j];
            }

            motion_controller_withPIC_B.rtb_A1_m[motion_controller_withPIC_B.isMpcEnable
              + 6 * motion_controller_withPIC_B.b_kidx] =
              motion_controller_withPIC_B.b_value_c0;
          }
        }

        memcpy(&motion_controller_withPIC_B.B1[0],
               &motion_controller_withPIC_B.rtb_A1_m[0], 12U * sizeof(real_T));
      }

      memset(&motion_controller_withPIC_B.W[0], 0, 2400U * sizeof(real_T));
      for (motion_controller_withPIC_B.isMpcEnable = 0;
           motion_controller_withPIC_B.isMpcEnable < 16;
           motion_controller_withPIC_B.isMpcEnable++) {
        motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.isMpcEnable]
          = 0;
      }

      motion_controller_withPIC_B.b_I[0] = 1;
      motion_controller_withPIC_B.b_I[5] = 1;
      motion_controller_withPIC_B.b_I[10] = 1;
      motion_controller_withPIC_B.b_I[15] = 1;
      for (motion_controller_withPIC_B.isMpcEnable = 0;
           motion_controller_withPIC_B.isMpcEnable < 4;
           motion_controller_withPIC_B.isMpcEnable++) {
        motion_controller_withPIC_B.b_kidx =
          motion_controller_withPIC_B.isMpcEnable << 2;
        motion_controller_withPIC_B.c_t[6 *
          motion_controller_withPIC_B.isMpcEnable] =
          motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.b_kidx];
        motion_controller_withPIC_B.c_t[6 *
          motion_controller_withPIC_B.isMpcEnable + 1] =
          motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.b_kidx + 1];
        motion_controller_withPIC_B.c_t[6 *
          motion_controller_withPIC_B.isMpcEnable + 2] =
          motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.b_kidx + 2];
        motion_controller_withPIC_B.c_t[6 *
          motion_controller_withPIC_B.isMpcEnable + 3] =
          motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.b_kidx + 3];
        motion_controller_withPIC_B.c_t[6 *
          motion_controller_withPIC_B.isMpcEnable + 4] = 0.0;
        motion_controller_withPIC_B.c_t[6 *
          motion_controller_withPIC_B.isMpcEnable + 5] = 0.0;
      }

      for (motion_controller_withPIC_B.b_g = 0; motion_controller_withPIC_B.b_g <
           10; motion_controller_withPIC_B.b_g++) {
        motion_controller_withPIC_B.i = motion_controller_withPIC_B.b_g * 6 + 1;
        motion_controller_withPIC_B.b_value_c0 = 1.0;
        motion_controller_withPIC_B.c_jz = static_cast<int32_T>(((6.0 -
          static_cast<real_T>(motion_controller_withPIC_B.i)) + 60.0) / 6.0);
        for (motion_controller_withPIC_B.b_j = 0;
             motion_controller_withPIC_B.b_j < motion_controller_withPIC_B.c_jz;
             motion_controller_withPIC_B.b_j++) {
          motion_controller_withPIC_B.j = motion_controller_withPIC_B.b_j * 6 +
            motion_controller_withPIC_B.i;
          if (motion_controller_withPIC_B.j > motion_controller_withPIC_B.j + 5)
          {
            motion_controller_withPIC_B.k = -5;
            motion_controller_withPIC_B.j = -5;
          } else {
            motion_controller_withPIC_B.k = motion_controller_withPIC_B.j - 6;
          }

          if (motion_controller_withPIC_B.b_value_c0 >
              (motion_controller_withPIC_B.b_value_c0 + 4.0) - 1.0) {
            motion_controller_withPIC_B.l = 0;
            motion_controller_withPIC_B.isMpcEnable = 0;
          } else {
            motion_controller_withPIC_B.l = static_cast<int32_T>
              (motion_controller_withPIC_B.b_value_c0) - 1;
            motion_controller_withPIC_B.isMpcEnable = static_cast<int32_T>
              ((motion_controller_withPIC_B.b_value_c0 + 4.0) - 1.0);
          }

          motion_controller_withPIC_B.f_idx_0 = motion_controller_withPIC_B.j -
            motion_controller_withPIC_B.k;
          motion_controller_withPIC_B.f_idx_1 =
            motion_controller_withPIC_B.isMpcEnable -
            motion_controller_withPIC_B.l;
          for (motion_controller_withPIC_B.isMpcEnable = 0;
               motion_controller_withPIC_B.isMpcEnable <
               motion_controller_withPIC_B.f_idx_1;
               motion_controller_withPIC_B.isMpcEnable++) {
            for (motion_controller_withPIC_B.b_kidx = 0;
                 motion_controller_withPIC_B.b_kidx <
                 motion_controller_withPIC_B.f_idx_0;
                 motion_controller_withPIC_B.b_kidx++) {
              motion_controller_withPIC_B.W[((motion_controller_withPIC_B.k +
                motion_controller_withPIC_B.b_kidx) + 60 *
                (motion_controller_withPIC_B.l +
                 motion_controller_withPIC_B.isMpcEnable)) + 5] =
                motion_controller_withPIC_B.c_t[motion_controller_withPIC_B.f_idx_0
                * motion_controller_withPIC_B.isMpcEnable +
                motion_controller_withPIC_B.b_kidx];
            }
          }

          motion_controller_withPIC_B.b_value_c0 += 4.0;
        }

        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable < 6;
             motion_controller_withPIC_B.isMpcEnable++) {
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 4;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.b_value_c0 = 0.0;
            for (motion_controller_withPIC_B.b_j = 0;
                 motion_controller_withPIC_B.b_j < 6;
                 motion_controller_withPIC_B.b_j++) {
              motion_controller_withPIC_B.b_value_c0 +=
                motion_controller_withPIC_B.A1[6 *
                motion_controller_withPIC_B.b_j +
                motion_controller_withPIC_B.isMpcEnable] *
                motion_controller_withPIC_B.c_t[6 *
                motion_controller_withPIC_B.b_kidx +
                motion_controller_withPIC_B.b_j];
            }

            motion_controller_withPIC_B.rtb_A1_o[motion_controller_withPIC_B.isMpcEnable
              + 6 * motion_controller_withPIC_B.b_kidx] =
              motion_controller_withPIC_B.b_value_c0;
          }
        }

        memcpy(&motion_controller_withPIC_B.c_t[0],
               &motion_controller_withPIC_B.rtb_A1_o[0], 24U * sizeof(real_T));
      }

      // End of MATLAB Function: '<S63>/predict'

      // MATLAB Function: '<S63>/solvex' incorporates:
      //   MATLABSystem: '<S16>/Get Parameter'
      //   MATLABSystem: '<S16>/Get Parameter6'
      //   Reshape: '<S16>/Reshape'
      //   UnitDelay: '<S16>/Unit Delay'
      //   UnitDelay: '<S16>/Unit Delay1'

      if (!motion_controller_withPIC_DW.x0_not_empty) {
        motion_controller_withPIC_DW.x0_not_empty = true;
        motion_controller_withPIC_DW.Umin = -motion_controller_withPIC_B.vyp;
        motion_controller_withPIC_DW.Umax = motion_controller_withPIC_B.vyp;
        motion_controller_withPIC_B.isMpcEnable = -1;
        motion_controller_withPIC_B.b_kidx = -1;
        for (motion_controller_withPIC_B.i = 0; motion_controller_withPIC_B.i <
             10; motion_controller_withPIC_B.i++) {
          for (motion_controller_withPIC_B.j = 0; motion_controller_withPIC_B.j <
               2; motion_controller_withPIC_B.j++) {
            motion_controller_withPIC_B.c_jz = motion_controller_withPIC_B.j <<
              1;
            motion_controller_withPIC_B.B_b = B[motion_controller_withPIC_B.c_jz];
            motion_controller_withPIC_B.B_k = B[motion_controller_withPIC_B.c_jz
              + 1];
            for (motion_controller_withPIC_B.c_jz = 0;
                 motion_controller_withPIC_B.c_jz < 10;
                 motion_controller_withPIC_B.c_jz++) {
              motion_controller_withPIC_B.A = A[10 *
                motion_controller_withPIC_B.i + motion_controller_withPIC_B.c_jz];
              motion_controller_withPIC_B.Rp_g[motion_controller_withPIC_B.isMpcEnable
                + 1] = motion_controller_withPIC_B.A *
                motion_controller_withPIC_B.B_b;
              motion_controller_withPIC_B.K_d[motion_controller_withPIC_B.b_kidx
                + 1] = static_cast<int8_T>(motion_controller_withPIC_B.A *
                motion_controller_withPIC_B.B_b);
              motion_controller_withPIC_B.Rp_g[motion_controller_withPIC_B.isMpcEnable
                + 2] = motion_controller_withPIC_B.A *
                motion_controller_withPIC_B.B_k;
              motion_controller_withPIC_B.K_d[motion_controller_withPIC_B.b_kidx
                + 2] = static_cast<int8_T>(motion_controller_withPIC_B.A *
                motion_controller_withPIC_B.B_k);
              motion_controller_withPIC_B.b_kidx =
                motion_controller_withPIC_B.isMpcEnable + 2;
              motion_controller_withPIC_B.isMpcEnable += 2;
            }
          }
        }

        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable < 20;
             motion_controller_withPIC_B.isMpcEnable++) {
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 20;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.i = 20 *
              motion_controller_withPIC_B.isMpcEnable +
              motion_controller_withPIC_B.b_kidx;
            motion_controller_withPIC_B.j = 40 *
              motion_controller_withPIC_B.isMpcEnable +
              motion_controller_withPIC_B.b_kidx;
            motion_controller_withPIC_DW.A[motion_controller_withPIC_B.j] =
              motion_controller_withPIC_B.Rp_g[motion_controller_withPIC_B.i];
            motion_controller_withPIC_DW.A[motion_controller_withPIC_B.j + 20] =
              -static_cast<real_T>
              (motion_controller_withPIC_B.K_d[motion_controller_withPIC_B.i]);
          }
        }
      }

      memset(&motion_controller_withPIC_B.Qp_c[0], 0, 3600U * sizeof(real_T));
      memset(&motion_controller_withPIC_B.b_b[0], 0, 60U * sizeof(real_T));
      motion_controller_withPIC_B.k = 6;
      for (motion_controller_withPIC_B.b_j = 0; motion_controller_withPIC_B.b_j <
           10; motion_controller_withPIC_B.b_j++) {
        motion_controller_withPIC_B.j = motion_controller_withPIC_B.b_j * 6 + 6;
        if (motion_controller_withPIC_B.j - 5 > motion_controller_withPIC_B.j) {
          motion_controller_withPIC_B.c_jz = 0;
          motion_controller_withPIC_B.b_g = 0;
        } else {
          motion_controller_withPIC_B.c_jz = motion_controller_withPIC_B.j - 6;
          motion_controller_withPIC_B.b_g = motion_controller_withPIC_B.j;
        }

        if (motion_controller_withPIC_B.k - 5 > motion_controller_withPIC_B.k) {
          motion_controller_withPIC_B.i = 0;
          motion_controller_withPIC_B.isMpcEnable = 0;
        } else {
          motion_controller_withPIC_B.i = motion_controller_withPIC_B.k - 6;
          motion_controller_withPIC_B.isMpcEnable =
            motion_controller_withPIC_B.k;
        }

        motion_controller_withPIC_B.f_idx_0 = motion_controller_withPIC_B.b_g -
          motion_controller_withPIC_B.c_jz;
        motion_controller_withPIC_B.f_idx_1 =
          motion_controller_withPIC_B.isMpcEnable -
          motion_controller_withPIC_B.i;
        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable <
             motion_controller_withPIC_B.f_idx_1;
             motion_controller_withPIC_B.isMpcEnable++) {
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx <
               motion_controller_withPIC_B.f_idx_0;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.Qp_c[(motion_controller_withPIC_B.c_jz +
              motion_controller_withPIC_B.b_kidx) + 60 *
              (motion_controller_withPIC_B.i +
               motion_controller_withPIC_B.isMpcEnable)] =
              motion_controller_withPIC_B.Q[motion_controller_withPIC_B.f_idx_0 *
              motion_controller_withPIC_B.isMpcEnable +
              motion_controller_withPIC_B.b_kidx];
          }
        }

        motion_controller_withPIC_B.k += 6;
        if (motion_controller_withPIC_B.j - 5 > motion_controller_withPIC_B.j) {
          motion_controller_withPIC_B.b_kidx = 0;
          motion_controller_withPIC_B.j = 0;
        } else {
          motion_controller_withPIC_B.b_kidx = motion_controller_withPIC_B.j - 6;
        }

        motion_controller_withPIC_B.i = motion_controller_withPIC_B.j -
          motion_controller_withPIC_B.b_kidx;
        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable <
             motion_controller_withPIC_B.i;
             motion_controller_withPIC_B.isMpcEnable++) {
          motion_controller_withPIC_B.b_b[motion_controller_withPIC_B.b_kidx +
            motion_controller_withPIC_B.isMpcEnable] =
            motion_controller_withPIC_B.y_j[motion_controller_withPIC_B.isMpcEnable];
        }
      }

      memset(&motion_controller_withPIC_B.Rp_g[0], 0, 400U * sizeof(real_T));
      motion_controller_withPIC_B.k = 2;
      for (motion_controller_withPIC_B.b_j = 0; motion_controller_withPIC_B.b_j <
           10; motion_controller_withPIC_B.b_j++) {
        motion_controller_withPIC_B.j = motion_controller_withPIC_B.b_j << 1;
        if (motion_controller_withPIC_B.k - 1 > motion_controller_withPIC_B.k) {
          motion_controller_withPIC_B.i = 0;
          motion_controller_withPIC_B.isMpcEnable = 0;
        } else {
          motion_controller_withPIC_B.i = motion_controller_withPIC_B.k - 2;
          motion_controller_withPIC_B.isMpcEnable =
            motion_controller_withPIC_B.k;
        }

        motion_controller_withPIC_B.f_idx_1 =
          motion_controller_withPIC_B.isMpcEnable -
          motion_controller_withPIC_B.i;
        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable <
             motion_controller_withPIC_B.f_idx_1;
             motion_controller_withPIC_B.isMpcEnable++) {
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 2;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.Rp_g[(motion_controller_withPIC_B.j +
              motion_controller_withPIC_B.b_kidx) + 20 *
              (motion_controller_withPIC_B.i +
               motion_controller_withPIC_B.isMpcEnable)] =
              motion_controller_withPIC_B.R
              [(motion_controller_withPIC_B.isMpcEnable << 1) +
              motion_controller_withPIC_B.b_kidx];
          }
        }

        motion_controller_withPIC_B.k += 2;
      }

      for (motion_controller_withPIC_B.isMpcEnable = 0;
           motion_controller_withPIC_B.isMpcEnable < 60;
           motion_controller_withPIC_B.isMpcEnable++) {
        motion_controller_withPIC_B.b_kidx =
          motion_controller_withPIC_B.isMpcEnable * 20;
        memset
          (&motion_controller_withPIC_B.y_n[motion_controller_withPIC_B.b_kidx],
           0, 20U * sizeof(real_T));
        for (motion_controller_withPIC_B.i = 0; motion_controller_withPIC_B.i <
             60; motion_controller_withPIC_B.i++) {
          motion_controller_withPIC_B.b_value_c0 =
            motion_controller_withPIC_B.Qp_c[motion_controller_withPIC_B.i * 60
            + motion_controller_withPIC_B.isMpcEnable];
          for (motion_controller_withPIC_B.j = 0; motion_controller_withPIC_B.j <
               20; motion_controller_withPIC_B.j++) {
            motion_controller_withPIC_B.c_jz =
              motion_controller_withPIC_B.b_kidx + motion_controller_withPIC_B.j;
            motion_controller_withPIC_B.y_n[motion_controller_withPIC_B.c_jz] +=
              motion_controller_withPIC_B.H[motion_controller_withPIC_B.j * 60 +
              motion_controller_withPIC_B.i] *
              motion_controller_withPIC_B.b_value_c0;
          }
        }

        memset
          (&motion_controller_withPIC_B.b_y_p[motion_controller_withPIC_B.b_kidx],
           0, 20U * sizeof(real_T));
        for (motion_controller_withPIC_B.i = 0; motion_controller_withPIC_B.i <
             60; motion_controller_withPIC_B.i++) {
          motion_controller_withPIC_B.b_value_c0 =
            motion_controller_withPIC_B.Qp_c[motion_controller_withPIC_B.i * 60
            + motion_controller_withPIC_B.isMpcEnable];
          for (motion_controller_withPIC_B.b_g = 0;
               motion_controller_withPIC_B.b_g < 20;
               motion_controller_withPIC_B.b_g++) {
            motion_controller_withPIC_B.j = motion_controller_withPIC_B.b_kidx +
              motion_controller_withPIC_B.b_g;
            motion_controller_withPIC_B.b_y_p[motion_controller_withPIC_B.j] +=
              motion_controller_withPIC_B.H[motion_controller_withPIC_B.b_g * 60
              + motion_controller_withPIC_B.i] *
              motion_controller_withPIC_B.b_value_c0;
          }
        }
      }

      motion_controller_withPIC_B.b_value_c0 = motion_controller_withPIC_DW.Umax
        - motion_controller_withPIC_DW.UnitDelay_DSTATE;
      motion_controller_withPIC_B.b_value_p5 = motion_controller_withPIC_DW.Umax
        - motion_controller_withPIC_DW.UnitDelay1_DSTATE;
      motion_controller_withPIC_B.isMpcEnable = -1;
      for (motion_controller_withPIC_B.b_kidx = 0;
           motion_controller_withPIC_B.b_kidx < 10;
           motion_controller_withPIC_B.b_kidx++) {
        motion_controller_withPIC_B.b_K_o[motion_controller_withPIC_B.isMpcEnable
          + 1] = motion_controller_withPIC_B.b_value_c0;
        motion_controller_withPIC_B.b_K_o[motion_controller_withPIC_B.isMpcEnable
          + 2] = motion_controller_withPIC_B.b_value_p5;
        motion_controller_withPIC_B.isMpcEnable += 2;
      }

      motion_controller_withPIC_B.b_value_c0 =
        motion_controller_withPIC_DW.UnitDelay_DSTATE -
        motion_controller_withPIC_DW.Umin;
      motion_controller_withPIC_B.b_value_p5 =
        motion_controller_withPIC_DW.UnitDelay1_DSTATE -
        motion_controller_withPIC_DW.Umin;
      motion_controller_withPIC_B.isMpcEnable = -1;
      for (motion_controller_withPIC_B.b_kidx = 0;
           motion_controller_withPIC_B.b_kidx < 10;
           motion_controller_withPIC_B.b_kidx++) {
        motion_controller_withPIC_B.c_K[motion_controller_withPIC_B.isMpcEnable
          + 1] = motion_controller_withPIC_B.b_value_c0;
        motion_controller_withPIC_B.c_K[motion_controller_withPIC_B.isMpcEnable
          + 2] = motion_controller_withPIC_B.b_value_p5;
        motion_controller_withPIC_B.isMpcEnable += 2;
      }

      for (motion_controller_withPIC_B.i = 0; motion_controller_withPIC_B.i < 20;
           motion_controller_withPIC_B.i++) {
        motion_controller_withPIC_B.V_i[motion_controller_withPIC_B.i] =
          motion_controller_withPIC_DW.x0[motion_controller_withPIC_B.i];
        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable < 60;
             motion_controller_withPIC_B.isMpcEnable++) {
          motion_controller_withPIC_B.b_value_p5 = 0.0;
          motion_controller_withPIC_B.b_value_c0 = 0.0;
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 60;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.b_value_p5 +=
              motion_controller_withPIC_B.H[60 * motion_controller_withPIC_B.i +
              motion_controller_withPIC_B.b_kidx] *
              motion_controller_withPIC_B.Qp_c[60 *
              motion_controller_withPIC_B.isMpcEnable +
              motion_controller_withPIC_B.b_kidx];
            motion_controller_withPIC_B.b_value_c0 =
              motion_controller_withPIC_B.b_value_p5;
          }

          motion_controller_withPIC_B.b_kidx = 20 *
            motion_controller_withPIC_B.isMpcEnable +
            motion_controller_withPIC_B.i;
          motion_controller_withPIC_B.rtb_H_j[motion_controller_withPIC_B.b_kidx]
            = motion_controller_withPIC_B.b_value_c0;
          motion_controller_withPIC_B.rtb_H_l[motion_controller_withPIC_B.b_kidx]
            = motion_controller_withPIC_B.b_value_p5;
        }

        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable < 6;
             motion_controller_withPIC_B.isMpcEnable++) {
          motion_controller_withPIC_B.b_value_c0 = 0.0;
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 60;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.b_value_c0 +=
              motion_controller_withPIC_B.rtb_H_j[20 *
              motion_controller_withPIC_B.b_kidx + motion_controller_withPIC_B.i]
              * motion_controller_withPIC_B.G[60 *
              motion_controller_withPIC_B.isMpcEnable +
              motion_controller_withPIC_B.b_kidx];
          }

          motion_controller_withPIC_B.rtb_H_o[motion_controller_withPIC_B.i + 20
            * motion_controller_withPIC_B.isMpcEnable] =
            motion_controller_withPIC_B.b_value_c0;
        }

        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable < 40;
             motion_controller_withPIC_B.isMpcEnable++) {
          motion_controller_withPIC_B.y_g = 0.0;
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 60;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.y_g += motion_controller_withPIC_B.y_n
              [20 * motion_controller_withPIC_B.b_kidx +
              motion_controller_withPIC_B.i] * motion_controller_withPIC_B.W[60 *
              motion_controller_withPIC_B.isMpcEnable +
              motion_controller_withPIC_B.b_kidx];
          }

          motion_controller_withPIC_B.y_d[motion_controller_withPIC_B.i + 20 *
            motion_controller_withPIC_B.isMpcEnable] =
            motion_controller_withPIC_B.y_g;
        }

        motion_controller_withPIC_B.b_value_c0 = 0.0;
        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable < 6;
             motion_controller_withPIC_B.isMpcEnable++) {
          motion_controller_withPIC_B.b_value_c0 +=
            motion_controller_withPIC_B.rtb_H_o[20 *
            motion_controller_withPIC_B.isMpcEnable +
            motion_controller_withPIC_B.i] *
            motion_controller_withPIC_B.Reshape[motion_controller_withPIC_B.isMpcEnable];
        }

        motion_controller_withPIC_B.y_g = 0.0;
        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable < 40;
             motion_controller_withPIC_B.isMpcEnable++) {
          motion_controller_withPIC_B.y_g += motion_controller_withPIC_B.y_d[20 *
            motion_controller_withPIC_B.isMpcEnable +
            motion_controller_withPIC_B.i] *
            motion_controller_withPIC_B.T[motion_controller_withPIC_B.isMpcEnable];
        }

        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable < 20;
             motion_controller_withPIC_B.isMpcEnable++) {
          motion_controller_withPIC_B.alpha1 = 0.0;
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 60;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.alpha1 +=
              motion_controller_withPIC_B.rtb_H_l[20 *
              motion_controller_withPIC_B.b_kidx + motion_controller_withPIC_B.i]
              * motion_controller_withPIC_B.H[60 *
              motion_controller_withPIC_B.isMpcEnable +
              motion_controller_withPIC_B.b_kidx];
          }

          motion_controller_withPIC_B.b_kidx = 20 *
            motion_controller_withPIC_B.isMpcEnable +
            motion_controller_withPIC_B.i;
          motion_controller_withPIC_B.rtb_H_ld[motion_controller_withPIC_B.b_kidx]
            =
            motion_controller_withPIC_B.Rp_g[motion_controller_withPIC_B.b_kidx]
            + motion_controller_withPIC_B.alpha1;
        }

        motion_controller_withPIC_B.alpha1 = 0.0;
        for (motion_controller_withPIC_B.isMpcEnable = 0;
             motion_controller_withPIC_B.isMpcEnable < 60;
             motion_controller_withPIC_B.isMpcEnable++) {
          motion_controller_withPIC_B.alpha1 +=
            motion_controller_withPIC_B.b_y_p[20 *
            motion_controller_withPIC_B.isMpcEnable +
            motion_controller_withPIC_B.i] *
            motion_controller_withPIC_B.b_b[motion_controller_withPIC_B.isMpcEnable];
        }

        motion_controller_withPIC_B.rtb_H_n[motion_controller_withPIC_B.i] =
          (motion_controller_withPIC_B.b_value_c0 +
           motion_controller_withPIC_B.y_g) - motion_controller_withPIC_B.alpha1;
        motion_controller_withPIC_B.b_K[motion_controller_withPIC_B.i] =
          motion_controller_withPIC_B.b_K_o[motion_controller_withPIC_B.i];
        motion_controller_withPIC_B.b_K[motion_controller_withPIC_B.i + 20] =
          motion_controller_withPIC_B.c_K[motion_controller_withPIC_B.i];
        motion_controller_withPIC_B.rtb_Gain1_m3[motion_controller_withPIC_B.i] =
          motion_controller_withPIC_B.yp;
        motion_controller_withPIC_B.b_value_cz[motion_controller_withPIC_B.i] =
          motion_controller_withPIC_B.vxp;
      }

      motion_controller_wi_quadprog_k(motion_controller_withPIC_B.rtb_H_ld,
        motion_controller_withPIC_B.rtb_H_n, motion_controller_withPIC_DW.A,
        motion_controller_withPIC_B.b_K,
        motion_controller_withPIC_B.rtb_Gain1_m3,
        motion_controller_withPIC_B.b_value_cz, motion_controller_withPIC_B.V_i,
        &motion_controller_withPIC_DW.opts_j);
      motion_controller_withPIC_B.b_value_c0 = motion_controller_withPIC_B.V_i[0]
        + motion_controller_withPIC_DW.UnitDelay_DSTATE;
      motion_controller_withPIC_B.b_value_p5 = motion_controller_withPIC_B.V_i[1]
        + motion_controller_withPIC_DW.UnitDelay1_DSTATE;

      // SignalConversion generated from: '<S63>/dfl' incorporates:
      //   MATLAB Function: '<S63>/solvex'
      //   Merge: '<S60>/Merge'

      motion_controller_withPIC_B.Merge[0] =
        motion_controller_withPIC_B.b_value_c0;

      // SignalConversion generated from: '<S63>/dfr' incorporates:
      //   MATLAB Function: '<S63>/solvex'
      //   Merge: '<S60>/Merge'

      motion_controller_withPIC_B.Merge[1] =
        motion_controller_withPIC_B.b_value_c0;

      // SignalConversion generated from: '<S63>/drl' incorporates:
      //   MATLAB Function: '<S63>/solvex'
      //   Merge: '<S60>/Merge'

      motion_controller_withPIC_B.Merge[2] =
        motion_controller_withPIC_B.b_value_p5;

      // SignalConversion generated from: '<S63>/drr' incorporates:
      //   MATLAB Function: '<S63>/solvex'
      //   Merge: '<S60>/Merge'

      motion_controller_withPIC_B.Merge[3] =
        motion_controller_withPIC_B.b_value_p5;

      // End of Outputs for SubSystem: '<S60>/If Action Subsystem1'
    }

    // End of If: '<S60>/If'

    // Update for UnitDelay: '<S16>/Unit Delay'
    motion_controller_withPIC_DW.UnitDelay_DSTATE =
      motion_controller_withPIC_B.Merge[0];

    // Update for UnitDelay: '<S16>/Unit Delay1'
    motion_controller_withPIC_DW.UnitDelay1_DSTATE =
      motion_controller_withPIC_B.Merge[3];
  } else {
    motion_controller_withPIC_DW.picController_MODE = false;
  }

  // End of Outputs for SubSystem: '<Root>/picController'

  // MATLABSystem: '<S10>/Get Parameter2'
  ParamGet_motion_controller_withPIC_629.getParameter
    (&motion_controller_withPIC_B.b_value_k1);

  // Switch: '<S10>/Switch1'
  if (motion_controller_withPIC_B.p_k != 0) {
    // Switch: '<S10>/Switch3' incorporates:
    //   Gain: '<S10>/Gain2'
    //   MATLABSystem: '<S10>/Get Parameter2'

    if (motion_controller_withPIC_B.b_value_k1) {
      motion_controller_withPIC_B.R[0] = motion_controller_withPIC_P.Gain2_Gain *
        motion_controller_withPIC_B.Merge[0];
      motion_controller_withPIC_B.R[1] = motion_controller_withPIC_P.Gain2_Gain *
        motion_controller_withPIC_B.Merge[1];
      motion_controller_withPIC_B.R[2] = motion_controller_withPIC_P.Gain2_Gain *
        motion_controller_withPIC_B.Merge[2];
      motion_controller_withPIC_B.R[3] = motion_controller_withPIC_P.Gain2_Gain *
        motion_controller_withPIC_B.Merge[3];
    } else {
      motion_controller_withPIC_B.R[0] = motion_controller_withPIC_B.Merge[0];
      motion_controller_withPIC_B.R[1] = motion_controller_withPIC_B.Merge[1];
      motion_controller_withPIC_B.R[2] = motion_controller_withPIC_B.Merge[2];
      motion_controller_withPIC_B.R[3] = motion_controller_withPIC_B.Merge[3];
    }

    // End of Switch: '<S10>/Switch3'
  } else {
    motion_controller_withPIC_B.R[0] = motion_controller_withPIC_B.angle_cmd[0];
    motion_controller_withPIC_B.R[1] = motion_controller_withPIC_B.angle_cmd[1];
    motion_controller_withPIC_B.R[2] = motion_controller_withPIC_B.angle_cmd[2];
    motion_controller_withPIC_B.R[3] = motion_controller_withPIC_B.angle_cmd[3];
  }

  // End of Switch: '<S10>/Switch1'

  // Outputs for Enabled SubSystem: '<Root>/cmd_pub' incorporates:
  //   EnablePort: '<S14>/Enable'

  // RelationalOperator: '<S2>/Compare' incorporates:
  //   Constant: '<S2>/Constant'
  //   SignalConversion generated from: '<S17>/Bus Selector'

  if (motion_controller_withPIC_B.In1_m.mapped_channels[5] ==
      motion_controller_withPIC_P.CompareToConstant_const_m) {
    motion_controller_w_CurrentTime(&motion_controller_withPIC_B.CurrentTime1);

    // Outputs for Iterator SubSystem: '<S14>/For Each Subsystem1' incorporates:
    //   ForEach: '<S41>/For Each'

    for (motion_controller_withPIC_B.ForEach_itr_j_l = 0;
         motion_controller_withPIC_B.ForEach_itr_j_l < 4;
         motion_controller_withPIC_B.ForEach_itr_j_l++) {
      // Saturate: '<S10>/Saturation'
      motion_controller_withPIC_B.yp =
        motion_controller_withPIC_B.Switch[motion_controller_withPIC_B.ForEach_itr_j_l];
      if (motion_controller_withPIC_B.yp >
          motion_controller_withPIC_P.Saturation_UpperSat_h) {
        motion_controller_withPIC_B.yp =
          motion_controller_withPIC_P.Saturation_UpperSat_h;
      } else if (motion_controller_withPIC_B.yp <
                 motion_controller_withPIC_P.Saturation_LowerSat_k) {
        motion_controller_withPIC_B.yp =
          motion_controller_withPIC_P.Saturation_LowerSat_k;
      }

      // Saturate: '<S14>/Saturation2' incorporates:
      //   Saturate: '<S10>/Saturation'

      if (motion_controller_withPIC_B.yp >
          motion_controller_withPIC_P.Saturation2_UpperSat) {
        motion_controller_withPIC_B.yp =
          motion_controller_withPIC_P.Saturation2_UpperSat;
      } else if (motion_controller_withPIC_B.yp <
                 motion_controller_withPIC_P.Saturation2_LowerSat) {
        motion_controller_withPIC_B.yp =
          motion_controller_withPIC_P.Saturation2_LowerSat;
      }

      motion_controller_withPIC_B.Switch[motion_controller_withPIC_B.ForEach_itr_j_l]
        = motion_controller_withPIC_B.yp;

      // End of Saturate: '<S14>/Saturation2'

      // Saturate: '<S14>/Saturation1'
      motion_controller_withPIC_B.vxp =
        motion_controller_withPIC_B.spd_cmd[motion_controller_withPIC_B.ForEach_itr_j_l];

      // ForEachSliceAssignment generated from: '<S41>/actuaor_command' incorporates:
      //   BusAssignment: '<S41>/Bus Assignment1'
      //   Constant: '<S45>/Constant'

      motion_controller_withPIC_B.ImpAsg_InsertedFor_actuaor_[motion_controller_withPIC_B.ForEach_itr_j_l]
        = motion_controller_withPIC_P.CoreSubsys_pn.Constant_Value;

      // BusAssignment: '<S41>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S41>/actuaor_command'
      //   ForEachSliceSelector generated from: '<S41>/effort'

      motion_controller_withPIC_B.ImpAsg_InsertedFor_actuaor_[motion_controller_withPIC_B.ForEach_itr_j_l]
        .effort = motion_controller_withPIC_B.yp;

      // Saturate: '<S14>/Saturation1'
      if (motion_controller_withPIC_B.vxp >
          motion_controller_withPIC_P.Saturation1_UpperSat) {
        // BusAssignment: '<S41>/Bus Assignment1' incorporates:
        //   ForEachSliceAssignment generated from: '<S41>/actuaor_command'

        motion_controller_withPIC_B.ImpAsg_InsertedFor_actuaor_[motion_controller_withPIC_B.ForEach_itr_j_l]
          .velocity = motion_controller_withPIC_P.Saturation1_UpperSat;
      } else if (motion_controller_withPIC_B.vxp <
                 motion_controller_withPIC_P.Saturation1_LowerSat) {
        // BusAssignment: '<S41>/Bus Assignment1' incorporates:
        //   ForEachSliceAssignment generated from: '<S41>/actuaor_command'

        motion_controller_withPIC_B.ImpAsg_InsertedFor_actuaor_[motion_controller_withPIC_B.ForEach_itr_j_l]
          .velocity = motion_controller_withPIC_P.Saturation1_LowerSat;
      } else {
        // BusAssignment: '<S41>/Bus Assignment1' incorporates:
        //   ForEachSliceAssignment generated from: '<S41>/actuaor_command'

        motion_controller_withPIC_B.ImpAsg_InsertedFor_actuaor_[motion_controller_withPIC_B.ForEach_itr_j_l]
          .velocity = motion_controller_withPIC_B.vxp;
      }
    }

    // End of Outputs for SubSystem: '<S14>/For Each Subsystem1'

    // BusAssignment: '<S14>/Bus Assignment1' incorporates:
    //   Constant: '<S39>/Constant'

    motion_controller_withPIC_B.BusAssignment1 =
      motion_controller_withPIC_P.Constant_Value_f;
    motion_controller_withPIC_B.BusAssignment1.header.stamp =
      motion_controller_withPIC_B.CurrentTime1.CurrentTime;

    // Switch: '<S10>/Switch' incorporates:
    //   Logic: '<S10>/Logical Operator1'

    if ((motion_controller_withPIC_B.p_k != 0) &&
        (motion_controller_withPIC_B.mode != 0)) {
      // DataTypeConversion: '<S14>/Data Type Conversion' incorporates:
      //   Constant: '<S10>/Constant'

      motion_controller_withPIC_B.alpha1 = floor
        (motion_controller_withPIC_P.Constant_Value_b);
      if (rtIsNaN(motion_controller_withPIC_B.alpha1) || rtIsInf
          (motion_controller_withPIC_B.alpha1)) {
        motion_controller_withPIC_B.alpha1 = 0.0;
      } else {
        motion_controller_withPIC_B.alpha1 = fmod
          (motion_controller_withPIC_B.alpha1, 4.294967296E+9);
      }

      if (motion_controller_withPIC_B.alpha1 < 0.0) {
        // BusAssignment: '<S14>/Bus Assignment1'
        motion_controller_withPIC_B.BusAssignment1.drive_mode =
          -static_cast<int32_T>(static_cast<uint32_T>
          (-motion_controller_withPIC_B.alpha1));
      } else {
        // BusAssignment: '<S14>/Bus Assignment1'
        motion_controller_withPIC_B.BusAssignment1.drive_mode =
          static_cast<int32_T>(static_cast<uint32_T>
          (motion_controller_withPIC_B.alpha1));
      }

      // End of DataTypeConversion: '<S14>/Data Type Conversion'
    } else {
      // BusAssignment: '<S14>/Bus Assignment1'
      motion_controller_withPIC_B.BusAssignment1.drive_mode =
        motion_controller_withPIC_B.mode;
    }

    // End of Switch: '<S10>/Switch'

    // BusAssignment: '<S14>/Bus Assignment1'
    memcpy(&motion_controller_withPIC_B.BusAssignment1.actuator_command[0],
           &motion_controller_withPIC_B.ImpAsg_InsertedFor_actuaor_[0], sizeof
           (SL_Bus_custom_interfaces_Actuator) << 2U);

    // MATLABSystem: '<S42>/SinkBlock'
    Pub_motion_controller_withPIC_4.publish
      (&motion_controller_withPIC_B.BusAssignment1);
    motion_controller_w_CurrentTime(&motion_controller_withPIC_B.CurrentTime);

    // Outputs for Iterator SubSystem: '<S14>/For Each Subsystem' incorporates:
    //   ForEach: '<S40>/For Each'

    // Saturate: '<S14>/Saturation'
    for (motion_controller_withPIC_B.ForEach_itr_p_k = 0;
         motion_controller_withPIC_B.ForEach_itr_p_k < 4;
         motion_controller_withPIC_B.ForEach_itr_p_k++) {
      motion_controller_withPIC_B.vxp =
        motion_controller_withPIC_B.R[motion_controller_withPIC_B.ForEach_itr_p_k];

      // ForEachSliceAssignment generated from: '<S40>/actuaor_command' incorporates:
      //   BusAssignment: '<S40>/Bus Assignment1'
      //   Constant: '<S44>/Constant'

      motion_controller_withPIC_B.ImpAsg_InsertedFor_actuaor_[motion_controller_withPIC_B.ForEach_itr_p_k]
        = motion_controller_withPIC_P.CoreSubsys_p.Constant_Value;
      if (motion_controller_withPIC_B.vxp >
          motion_controller_withPIC_P.Saturation_UpperSat) {
        // BusAssignment: '<S40>/Bus Assignment1' incorporates:
        //   ForEachSliceAssignment generated from: '<S40>/actuaor_command'

        motion_controller_withPIC_B.ImpAsg_InsertedFor_actuaor_[motion_controller_withPIC_B.ForEach_itr_p_k]
          .position = motion_controller_withPIC_P.Saturation_UpperSat;
      } else if (motion_controller_withPIC_B.vxp <
                 motion_controller_withPIC_P.Saturation_LowerSat) {
        // BusAssignment: '<S40>/Bus Assignment1' incorporates:
        //   ForEachSliceAssignment generated from: '<S40>/actuaor_command'

        motion_controller_withPIC_B.ImpAsg_InsertedFor_actuaor_[motion_controller_withPIC_B.ForEach_itr_p_k]
          .position = motion_controller_withPIC_P.Saturation_LowerSat;
      } else {
        // BusAssignment: '<S40>/Bus Assignment1' incorporates:
        //   ForEachSliceAssignment generated from: '<S40>/actuaor_command'

        motion_controller_withPIC_B.ImpAsg_InsertedFor_actuaor_[motion_controller_withPIC_B.ForEach_itr_p_k]
          .position = motion_controller_withPIC_B.vxp;
      }
    }

    // End of Saturate: '<S14>/Saturation'
    // End of Outputs for SubSystem: '<S14>/For Each Subsystem'

    // BusAssignment: '<S14>/Bus Assignment2' incorporates:
    //   Constant: '<S38>/Constant'

    motion_controller_withPIC_B.BusAssignment1 =
      motion_controller_withPIC_P.Constant_Value_i;
    motion_controller_withPIC_B.BusAssignment1.header.stamp =
      motion_controller_withPIC_B.CurrentTime.CurrentTime;
    memcpy(&motion_controller_withPIC_B.BusAssignment1.actuator_command[0],
           &motion_controller_withPIC_B.ImpAsg_InsertedFor_actuaor_[0], sizeof
           (SL_Bus_custom_interfaces_Actuator) << 2U);

    // MATLABSystem: '<S43>/SinkBlock'
    Pub_motion_controller_withPIC_148.publish
      (&motion_controller_withPIC_B.BusAssignment1);
  }

  // End of RelationalOperator: '<S2>/Compare'
  // End of Outputs for SubSystem: '<Root>/cmd_pub'
}

// Model initialize function
void motion_controller_withPIC::initialize()
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
    static const char_T prmName_6[19] = "isGsFilterElseMean";
    static const char_T prmName_7[16] = "rGsDataN5r10r20";
    static const char_T prmName_8[6] = "rGsFs";
    static const char_T prmName_9[9] = "rGsSigma";
    static const char_T prmName_a[18] = "rFilterUpdateRate";
    static const char_T prmName_b[17] = "picActivationDAy";
    static const char_T prmName_c[21] = "picActivationDomegaz";
    static const char_T prmName_d[11] = "vxDeadZone";
    static const char_T prmName_e[11] = "vyDeadZone";
    static const char_T prmName_f[6] = "vxAdd";
    static const char_T prmName_g[11] = "t265offset";
    static const char_T prmName_h[18] = "isSetSteeringDead";
    static const char_T prmName_i[7] = "tireBf";
    static const char_T prmName_j[7] = "tireCf";
    static const char_T prmName_k[8] = "tireMuf";
    static const char_T prmName_l[7] = "tireBr";
    static const char_T prmName_m[7] = "tireCr";
    static const char_T prmName_n[8] = "tireMur";
    static const char_T prmName_o[8] = "spdMax1";
    static const char_T prmName_p[14] = "testWithDrive";
    static const char_T prmName_q[9] = "Weight_Y";
    static const char_T prmName_r[10] = "Weight_Vy";
    static const char_T prmName_s[11] = "Weight_Yaw";
    static const char_T prmName_t[15] = "Weight_YawRate";
    static const char_T prmName_u[10] = "Weight_df";
    static const char_T prmName_v[10] = "Weight_dr";
    static const char_T prmName_w[11] = "Weight_ddf";
    static const char_T prmName_x[11] = "Weight_ddr";
    static const char_T prmName_y[10] = "noControl";
    static const char_T prmName_z[12] = "angleMaxMpc";
    static const char_T prmName_10[15] = "isMpcN20Else10";
    static const char_T prmName_11[28] = "mpcDesiredYaw0r1DefaultAuto";
    static const char_T prmName_12[9] = "mpc_lbub";
    static sSOeZ9WO10chPn9Si6PKiCB_motio_T tmp = { 0.01,// InitDamping
      { 'f', 'o', 'r', 'w', 'a', 'r', 'd' },// FiniteDifferenceType
      false,                           // SpecifyObjectiveGradient
      false,                           // ScaleProblem
      false,                           // SpecifyConstraintGradient
      true,                            // NonFiniteSupport
      false,                           // IterDisplaySQP
      -1.0,                            // FiniteDifferenceStepSize
      -1.0,                            // MaxFunctionEvaluations
      false,                           // IterDisplayQP
      0.0,                             // PricingTolerance

      { 'a', 'c', 't', 'i', 'v', 'e', '-', 's', 'e', 't' },// Algorithm
      -1.0E+20,                        // ObjectiveLimit
      1.0E-8,                          // ConstraintTolerance
      1.0E-8,                          // OptimalityTolerance
      1.0E-8,                          // StepTolerance
      200.0,                           // MaxIterations
      0.0,                             // FunctionTolerance

      { 'q', 'u', 'a', 'd', 'p', 'r', 'o', 'g' },// SolverName
      false,                           // CheckGradients

      { 'o', 'f', 'f' },               // Diagnostics
      0.0,                             // DiffMaxChange
      0.0,                             // DiffMinChange

      { 'f', 'i', 'n', 'a', 'l' },     // Display

      { 'o', 'f', 'f' },               // FunValCheck
      false,                           // UseParallel

      { 'a', 'u', 't', 'o' },          // LinearSolver

      { 'c', 'g' }                     // SubproblemAlgorithm
    };

    // SystemInitialize for Enabled SubSystem: '<Root>/picController'
    // SystemInitialize for IfAction SubSystem: '<S60>/If Action Subsystem'
    // SystemInitialize for MATLAB Function: '<S62>/solvex'
    tmp.DiffMaxChange = (rtInf);
    tmp.FunctionTolerance = (rtInf);

    // End of SystemInitialize for SubSystem: '<S60>/If Action Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/picController'

    // SystemInitialize for Enabled SubSystem: '<S31>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S34>/In1' incorporates:
    //   Outport: '<S34>/Out1'

    motion_controller_withPIC_B.In1_je = motion_controller_withPIC_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S31>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S32>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S35>/In1' incorporates:
    //   Outport: '<S35>/Out1'

    motion_controller_withPIC_B.In1_f = motion_controller_withPIC_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: '<S32>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S69>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S72>/In1' incorporates:
    //   Outport: '<S72>/Out1'

    motion_controller_withPIC_B.In1_m = motion_controller_withPIC_P.Out1_Y0_f;

    // End of SystemInitialize for SubSystem: '<S69>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S33>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S36>/In1' incorporates:
    //   Outport: '<S36>/Out1'

    motion_controller_withPIC_B.In1_j = motion_controller_withPIC_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S33>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S70>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S73>/In1' incorporates:
    //   Outport: '<S73>/Out1'

    motion_controller_withPIC_B.In1 = motion_controller_withPIC_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S70>/Enabled Subsystem'

    // SystemInitialize for Atomic SubSystem: '<Root>/controller'
    // SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S15>/get_effort' incorporates:
    //   SubSystem: '<S15>/get_effort'

    motion_controll_get_effort_Init();

    // End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S15>/get_effort' 

    // Start for MATLABSystem: '<S47>/Get Parameter4'
    motion_controller_withPIC_DW.obj_el.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_el.isInitialized = 1;
    ParamGet_motion_controller_withPIC_298.initParam(&prmName[0]);
    ParamGet_motion_controller_withPIC_298.setInitialValue(0.0);
    motion_controller_withPIC_DW.obj_el.isSetupComplete = true;

    // Start for MATLABSystem: '<S47>/Get Parameter2'
    motion_controller_withPIC_DW.obj_c.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_c.isInitialized = 1;
    ParamGet_motion_controller_withPIC_301.initParam(&prmName_0[0]);
    ParamGet_motion_controller_withPIC_301.setInitialValue(false);
    motion_controller_withPIC_DW.obj_c.isSetupComplete = true;

    // Start for MATLABSystem: '<S47>/Get Parameter3'
    motion_controller_withPIC_DW.obj_l4.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_l4.isInitialized = 1;
    ParamGet_motion_controller_withPIC_194.initParam(&prmName_1[0]);
    ParamGet_motion_controller_withPIC_194.setInitialValue(1.0);
    motion_controller_withPIC_DW.obj_l4.isSetupComplete = true;

    // Start for MATLABSystem: '<S47>/Get Parameter5'
    motion_controller_withPIC_DW.obj_g.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_g.isInitialized = 1;
    ParamGet_motion_controller_withPIC_329.initParam(&prmName_2[0]);
    ParamGet_motion_controller_withPIC_329.setInitialValue(true);
    motion_controller_withPIC_DW.obj_g.isSetupComplete = true;

    // Start for MATLABSystem: '<S47>/Get Parameter1'
    motion_controller_withPIC_DW.obj_o.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_o.isInitialized = 1;
    ParamGet_motion_controller_withPIC_317.initParam(&prmName_3[0]);
    ParamGet_motion_controller_withPIC_317.setInitialValue(0.0);
    motion_controller_withPIC_DW.obj_o.isSetupComplete = true;

    // Start for MATLABSystem: '<S47>/Get Parameter'
    motion_controller_withPIC_DW.obj_m.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_m.isInitialized = 1;
    ParamGet_motion_controller_withPIC_316.initParam(&prmName_4[0]);
    ParamGet_motion_controller_withPIC_316.setInitialValue(0.515);
    motion_controller_withPIC_DW.obj_m.isSetupComplete = true;

    // Start for MATLABSystem: '<S15>/Get Parameter1'
    motion_controller_withPIC_DW.obj_f.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_f.isInitialized = 1;
    ParamGet_motion_controller_withPIC_217.initParam(&prmName_5[0]);
    ParamGet_motion_controller_withPIC_217.setInitialValue(1.0);
    motion_controller_withPIC_DW.obj_f.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<Root>/controller'

    // SystemInitialize for Enabled SubSystem: '<Root>/picController'
    // InitializeConditions for UnitDelay: '<S16>/Unit Delay'
    motion_controller_withPIC_DW.UnitDelay_DSTATE =
      motion_controller_withPIC_P.UnitDelay_InitialCondition;

    // InitializeConditions for UnitDelay: '<S16>/Unit Delay1'
    motion_controller_withPIC_DW.UnitDelay1_DSTATE =
      motion_controller_withPIC_P.UnitDelay1_InitialCondition;

    // SystemInitialize for IfAction SubSystem: '<S60>/If Action Subsystem'
    // SystemInitialize for MATLAB Function: '<S62>/solvex'
    motion_controller_withPIC_DW.opts = tmp;

    // End of SystemInitialize for SubSystem: '<S60>/If Action Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S60>/If Action Subsystem1'
    // SystemInitialize for MATLAB Function: '<S63>/solvex'
    motion_controller_withPIC_DW.opts_j = tmp;

    // End of SystemInitialize for SubSystem: '<S60>/If Action Subsystem1'

    // SystemInitialize for Merge: '<S60>/Merge'
    motion_controller_withPIC_B.Merge[0] =
      motion_controller_withPIC_P.Merge_InitialOutput;
    motion_controller_withPIC_B.Merge[1] =
      motion_controller_withPIC_P.Merge_InitialOutput;
    motion_controller_withPIC_B.Merge[2] =
      motion_controller_withPIC_P.Merge_InitialOutput;
    motion_controller_withPIC_B.Merge[3] =
      motion_controller_withPIC_P.Merge_InitialOutput;

    // Start for MATLABSystem: '<S16>/Get Parameter'
    motion_controller_withPIC_DW.obj_p.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_p.isInitialized = 1;
    ParamGet_motion_controller_withPIC_637.initParam(&prmName_z[0]);
    ParamGet_motion_controller_withPIC_637.setInitialValue(0.515);
    motion_controller_withPIC_DW.obj_p.isSetupComplete = true;

    // Start for MATLABSystem: '<S16>/Get Parameter1'
    motion_controller_withPIC_DW.obj_l.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_l.isInitialized = 1;
    ParamGet_motion_controller_withPIC_709.initParam(&prmName_10[0]);
    ParamGet_motion_controller_withPIC_709.setInitialValue(true);
    motion_controller_withPIC_DW.obj_l.isSetupComplete = true;

    // Start for MATLABSystem: '<S16>/Get Parameter2'
    motion_controller_withPIC_DW.obj_e.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_e.isInitialized = 1;
    ParamGet_motion_controller_withPIC_944.initParam(&prmName_11[0]);
    ParamGet_motion_controller_withPIC_944.setInitialValue(-1.0);
    motion_controller_withPIC_DW.obj_e.isSetupComplete = true;

    // Start for MATLABSystem: '<S16>/Get Parameter6'
    motion_controller_withPIC_DW.obj.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj.isInitialized = 1;
    ParamGet_motion_controller_withPIC_556.initParam(&prmName_12[0]);
    ParamGet_motion_controller_withPIC_556.setInitialValue(0.0279);
    motion_controller_withPIC_DW.obj.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<Root>/picController'

    // SystemInitialize for Enabled SubSystem: '<Root>/cmd_pub'
    motion_control_CurrentTime_Init(&motion_controller_withPIC_DW.CurrentTime1);

    // Start for MATLABSystem: '<S42>/SinkBlock'
    motion_SystemCore_setup_fxdcjik(&motion_controller_withPIC_DW.obj_bq);
    motion_control_CurrentTime_Init(&motion_controller_withPIC_DW.CurrentTime);

    // Start for MATLABSystem: '<S43>/SinkBlock'
    motio_SystemCore_setup_fxdcjikh(&motion_controller_withPIC_DW.obj_ca);

    // End of SystemInitialize for SubSystem: '<Root>/cmd_pub'

    // Start for MATLABSystem: '<S31>/SourceBlock'
    motion_co_SystemCore_setup_fxdc(&motion_controller_withPIC_DW.obj_az);

    // Start for MATLABSystem: '<S32>/SourceBlock'
    motion_c_SystemCore_setup_fxdcj(&motion_controller_withPIC_DW.obj_en);

    // Start for MATLABSystem: '<S69>/SourceBlock'
    moti_SystemCore_setup_fxdcjikhl(&motion_controller_withPIC_DW.obj_nf);

    // Start for MATLABSystem: '<Root>/Get Parameter18'
    motion_controller_withPIC_DW.obj_h.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_h.isInitialized = 1;
    ParamGet_motion_controller_withPIC_940.initParam(&prmName_6[0]);
    ParamGet_motion_controller_withPIC_940.setInitialValue(true);
    motion_controller_withPIC_DW.obj_h.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter20'
    motion_controller_withPIC_DW.obj_f0.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_f0.isInitialized = 1;
    ParamGet_motion_controller_withPIC_941.initParam(&prmName_7[0]);
    ParamGet_motion_controller_withPIC_941.setInitialValue(100.0);
    motion_controller_withPIC_DW.obj_f0.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter21'
    motion_controller_withPIC_DW.obj_ou.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_ou.isInitialized = 1;
    ParamGet_motion_controller_withPIC_942.initParam(&prmName_8[0]);
    ParamGet_motion_controller_withPIC_942.setInitialValue(100.0);
    motion_controller_withPIC_DW.obj_ou.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter22'
    motion_controller_withPIC_DW.obj_cp.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_cp.isInitialized = 1;
    ParamGet_motion_controller_withPIC_943.initParam(&prmName_9[0]);
    ParamGet_motion_controller_withPIC_943.setInitialValue(0.8);
    motion_controller_withPIC_DW.obj_cp.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter19'
    motion_controller_withPIC_DW.obj_ka.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_ka.isInitialized = 1;
    ParamGet_motion_controller_withPIC_924.initParam(&prmName_a[0]);
    ParamGet_motion_controller_withPIC_924.setInitialValue(1.0);
    motion_controller_withPIC_DW.obj_ka.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter7'
    motion_controller_withPIC_DW.obj_b.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_b.isInitialized = 1;
    ParamGet_motion_controller_withPIC_605.initParam(&prmName_b[0]);
    ParamGet_motion_controller_withPIC_605.setInitialValue(0.28);
    motion_controller_withPIC_DW.obj_b.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter8'
    motion_controller_withPIC_DW.obj_k.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_k.isInitialized = 1;
    ParamGet_motion_controller_withPIC_606.initParam(&prmName_c[0]);
    ParamGet_motion_controller_withPIC_606.setInitialValue(0.0045);
    motion_controller_withPIC_DW.obj_k.isSetupComplete = true;

    // Start for MATLABSystem: '<S9>/Get Parameter22'
    motion_controller_withPIC_DW.obj_fa.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_fa.isInitialized = 1;
    ParamGet_motion_controller_withPIC_946.initParam(&prmName_d[0]);
    ParamGet_motion_controller_withPIC_946.setInitialValue(0.0);
    motion_controller_withPIC_DW.obj_fa.isSetupComplete = true;

    // Start for MATLABSystem: '<S9>/Get Parameter1'
    motion_controller_withPIC_DW.obj_f5.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_f5.isInitialized = 1;
    ParamGet_motion_controller_withPIC_948.initParam(&prmName_e[0]);
    ParamGet_motion_controller_withPIC_948.setInitialValue(0.0);
    motion_controller_withPIC_DW.obj_f5.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter6'
    motion_controller_withPIC_DW.obj_iv.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_iv.isInitialized = 1;
    ParamGet_motion_controller_withPIC_907.initParam(&prmName_f[0]);
    ParamGet_motion_controller_withPIC_907.setInitialValue(0.0);
    motion_controller_withPIC_DW.obj_iv.isSetupComplete = true;

    // Start for MATLABSystem: '<S13>/Get Parameter20'
    motion_controller_withPIC_DW.obj_my.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_my.isInitialized = 1;
    ParamGet_motion_controller_withPIC_916.initParam(&prmName_g[0]);
    ParamGet_motion_controller_withPIC_916.setInitialValue(0.0);
    motion_controller_withPIC_DW.obj_my.isSetupComplete = true;

    // Start for MATLABSystem: '<S20>/SinkBlock'
    motion_control_SystemCore_setup(&motion_controller_withPIC_DW.obj_ng);

    // Start for MATLABSystem: '<S33>/SourceBlock'
    motion__SystemCore_setup_fxdcji(&motion_controller_withPIC_DW.obj_dp);

    // Start for MATLABSystem: '<Root>/Get Parameter17'
    motion_controller_withPIC_DW.obj_pt.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_pt.isInitialized = 1;
    ParamGet_motion_controller_withPIC_910.initParam(&prmName_h[0]);
    ParamGet_motion_controller_withPIC_910.setInitialValue(true);
    motion_controller_withPIC_DW.obj_pt.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter9'
    motion_controller_withPIC_DW.obj_n.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_n.isInitialized = 1;
    ParamGet_motion_controller_withPIC_614.initParam(&prmName_i[0]);
    ParamGet_motion_controller_withPIC_614.setInitialValue(-49.824);
    motion_controller_withPIC_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter10'
    motion_controller_withPIC_DW.obj_ba.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_ba.isInitialized = 1;
    ParamGet_motion_controller_withPIC_615.initParam(&prmName_j[0]);
    ParamGet_motion_controller_withPIC_615.setInitialValue(1.128);
    motion_controller_withPIC_DW.obj_ba.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter11'
    motion_controller_withPIC_DW.obj_ff.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_ff.isInitialized = 1;
    ParamGet_motion_controller_withPIC_616.initParam(&prmName_k[0]);
    ParamGet_motion_controller_withPIC_616.setInitialValue(0.431);
    motion_controller_withPIC_DW.obj_ff.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter12'
    motion_controller_withPIC_DW.obj_co.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_co.isInitialized = 1;
    ParamGet_motion_controller_withPIC_617.initParam(&prmName_l[0]);
    ParamGet_motion_controller_withPIC_617.setInitialValue(-40.215);
    motion_controller_withPIC_DW.obj_co.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter13'
    motion_controller_withPIC_DW.obj_e5.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_e5.isInitialized = 1;
    ParamGet_motion_controller_withPIC_618.initParam(&prmName_m[0]);
    ParamGet_motion_controller_withPIC_618.setInitialValue(1.177);
    motion_controller_withPIC_DW.obj_e5.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter14'
    motion_controller_withPIC_DW.obj_hb.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_hb.isInitialized = 1;
    ParamGet_motion_controller_withPIC_619.initParam(&prmName_n[0]);
    ParamGet_motion_controller_withPIC_619.setInitialValue(0.399);
    motion_controller_withPIC_DW.obj_hb.isSetupComplete = true;

    // Start for MATLABSystem: '<S22>/SinkBlock'
    motion_contr_SystemCore_setup_f(&motion_controller_withPIC_DW.obj_j4);

    // Start for MATLABSystem: '<S24>/SinkBlock'
    motion_cont_SystemCore_setup_fx(&motion_controller_withPIC_DW.obj_pk);

    // Start for MATLABSystem: '<S26>/SinkBlock'
    motion_con_SystemCore_setup_fxd(&motion_controller_withPIC_DW.obj_ar);

    // Start for MATLABSystem: '<S70>/SourceBlock'
    mot_SystemCore_setup_fxdcjikhl4(&motion_controller_withPIC_DW.obj_mo);

    // Start for MATLABSystem: '<S10>/Get Parameter3'
    motion_controller_withPIC_DW.obj_p3.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_p3.isInitialized = 1;
    ParamGet_motion_controller_withPIC_621.initParam(&prmName_o[0]);
    ParamGet_motion_controller_withPIC_621.setInitialValue(1.0);
    motion_controller_withPIC_DW.obj_p3.isSetupComplete = true;

    // Start for MATLABSystem: '<S10>/Get Parameter1'
    motion_controller_withPIC_DW.obj_i.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_i.isInitialized = 1;
    ParamGet_motion_controller_withPIC_625.initParam(&prmName_p[0]);
    ParamGet_motion_controller_withPIC_625.setInitialValue(false);
    motion_controller_withPIC_DW.obj_i.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter'
    motion_controller_withPIC_DW.obj_ay.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_ay.isInitialized = 1;
    ParamGet_motion_controller_withPIC_557.initParam(&prmName_q[0]);
    ParamGet_motion_controller_withPIC_557.setInitialValue(40.0);
    motion_controller_withPIC_DW.obj_ay.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter1'
    motion_controller_withPIC_DW.obj_hm.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_hm.isInitialized = 1;
    ParamGet_motion_controller_withPIC_558.initParam(&prmName_r[0]);
    ParamGet_motion_controller_withPIC_558.setInitialValue(2.0);
    motion_controller_withPIC_DW.obj_hm.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter2'
    motion_controller_withPIC_DW.obj_di.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_di.isInitialized = 1;
    ParamGet_motion_controller_withPIC_559.initParam(&prmName_s[0]);
    ParamGet_motion_controller_withPIC_559.setInitialValue(40.0);
    motion_controller_withPIC_DW.obj_di.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter3'
    motion_controller_withPIC_DW.obj_pw.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_pw.isInitialized = 1;
    ParamGet_motion_controller_withPIC_560.initParam(&prmName_t[0]);
    ParamGet_motion_controller_withPIC_560.setInitialValue(2.0);
    motion_controller_withPIC_DW.obj_pw.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter4'
    motion_controller_withPIC_DW.obj_ny.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_ny.isInitialized = 1;
    ParamGet_motion_controller_withPIC_561.initParam(&prmName_u[0]);
    ParamGet_motion_controller_withPIC_561.setInitialValue(2.0);
    motion_controller_withPIC_DW.obj_ny.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter5'
    motion_controller_withPIC_DW.obj_j.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_j.isInitialized = 1;
    ParamGet_motion_controller_withPIC_562.initParam(&prmName_v[0]);
    ParamGet_motion_controller_withPIC_562.setInitialValue(5.0);
    motion_controller_withPIC_DW.obj_j.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter15'
    motion_controller_withPIC_DW.obj_kx.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_kx.isInitialized = 1;
    ParamGet_motion_controller_withPIC_631.initParam(&prmName_w[0]);
    ParamGet_motion_controller_withPIC_631.setInitialValue(2.0);
    motion_controller_withPIC_DW.obj_kx.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter16'
    motion_controller_withPIC_DW.obj_ma.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_ma.isInitialized = 1;
    ParamGet_motion_controller_withPIC_632.initParam(&prmName_x[0]);
    ParamGet_motion_controller_withPIC_632.setInitialValue(5.0);
    motion_controller_withPIC_DW.obj_ma.isSetupComplete = true;

    // Start for MATLABSystem: '<S10>/Get Parameter2'
    motion_controller_withPIC_DW.obj_ls.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_ls.isInitialized = 1;
    ParamGet_motion_controller_withPIC_629.initParam(&prmName_y[0]);
    ParamGet_motion_controller_withPIC_629.setInitialValue(false);
    motion_controller_withPIC_DW.obj_ls.isSetupComplete = true;
  }
}

// Model terminate function
void motion_controller_withPIC::terminate()
{
  // Terminate for MATLABSystem: '<S31>/SourceBlock'
  if (!motion_controller_withPIC_DW.obj_az.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_az.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S31>/SourceBlock'

  // Terminate for MATLABSystem: '<S32>/SourceBlock'
  if (!motion_controller_withPIC_DW.obj_en.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_en.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S32>/SourceBlock'

  // Terminate for MATLABSystem: '<S69>/SourceBlock'
  if (!motion_controller_withPIC_DW.obj_nf.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_nf.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S69>/SourceBlock'

  // Terminate for MATLABSystem: '<Root>/Get Parameter18'
  if (!motion_controller_withPIC_DW.obj_h.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter18'

  // Terminate for MATLABSystem: '<Root>/Get Parameter20'
  if (!motion_controller_withPIC_DW.obj_f0.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_f0.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter20'

  // Terminate for MATLABSystem: '<Root>/Get Parameter21'
  if (!motion_controller_withPIC_DW.obj_ou.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_ou.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter21'

  // Terminate for MATLABSystem: '<Root>/Get Parameter22'
  if (!motion_controller_withPIC_DW.obj_cp.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_cp.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter22'

  // Terminate for MATLABSystem: '<Root>/Get Parameter19'
  if (!motion_controller_withPIC_DW.obj_ka.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_ka.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter19'

  // Terminate for MATLABSystem: '<Root>/Get Parameter7'
  if (!motion_controller_withPIC_DW.obj_b.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter7'

  // Terminate for MATLABSystem: '<Root>/Get Parameter8'
  if (!motion_controller_withPIC_DW.obj_k.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter8'

  // Terminate for MATLABSystem: '<S9>/Get Parameter22'
  if (!motion_controller_withPIC_DW.obj_fa.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_fa.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/Get Parameter22'

  // Terminate for MATLABSystem: '<S9>/Get Parameter1'
  if (!motion_controller_withPIC_DW.obj_f5.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_f5.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/Get Parameter1'

  // Terminate for MATLABSystem: '<Root>/Get Parameter6'
  if (!motion_controller_withPIC_DW.obj_iv.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_iv.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter6'

  // Terminate for MATLABSystem: '<S13>/Get Parameter20'
  if (!motion_controller_withPIC_DW.obj_my.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_my.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S13>/Get Parameter20'

  // Terminate for MATLABSystem: '<S20>/SinkBlock'
  if (!motion_controller_withPIC_DW.obj_ng.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_ng.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S20>/SinkBlock'

  // Terminate for MATLABSystem: '<S33>/SourceBlock'
  if (!motion_controller_withPIC_DW.obj_dp.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_dp.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S33>/SourceBlock'

  // Terminate for MATLABSystem: '<Root>/Get Parameter17'
  if (!motion_controller_withPIC_DW.obj_pt.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_pt.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter17'

  // Terminate for MATLABSystem: '<Root>/Get Parameter9'
  if (!motion_controller_withPIC_DW.obj_n.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter9'

  // Terminate for MATLABSystem: '<Root>/Get Parameter10'
  if (!motion_controller_withPIC_DW.obj_ba.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_ba.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter10'

  // Terminate for MATLABSystem: '<Root>/Get Parameter11'
  if (!motion_controller_withPIC_DW.obj_ff.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_ff.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter11'

  // Terminate for MATLABSystem: '<Root>/Get Parameter12'
  if (!motion_controller_withPIC_DW.obj_co.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_co.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter12'

  // Terminate for MATLABSystem: '<Root>/Get Parameter13'
  if (!motion_controller_withPIC_DW.obj_e5.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_e5.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter13'

  // Terminate for MATLABSystem: '<Root>/Get Parameter14'
  if (!motion_controller_withPIC_DW.obj_hb.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_hb.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter14'

  // Terminate for MATLABSystem: '<S22>/SinkBlock'
  if (!motion_controller_withPIC_DW.obj_j4.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_j4.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S22>/SinkBlock'

  // Terminate for MATLABSystem: '<S24>/SinkBlock'
  if (!motion_controller_withPIC_DW.obj_pk.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_pk.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S24>/SinkBlock'

  // Terminate for MATLABSystem: '<S26>/SinkBlock'
  if (!motion_controller_withPIC_DW.obj_ar.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_ar.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S26>/SinkBlock'

  // Terminate for MATLABSystem: '<S70>/SourceBlock'
  if (!motion_controller_withPIC_DW.obj_mo.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_mo.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S70>/SourceBlock'

  // Terminate for Atomic SubSystem: '<Root>/controller'
  // Terminate for MATLABSystem: '<S47>/Get Parameter4'
  if (!motion_controller_withPIC_DW.obj_el.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_el.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S47>/Get Parameter4'

  // Terminate for MATLABSystem: '<S47>/Get Parameter2'
  if (!motion_controller_withPIC_DW.obj_c.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S47>/Get Parameter2'

  // Terminate for MATLABSystem: '<S47>/Get Parameter3'
  if (!motion_controller_withPIC_DW.obj_l4.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_l4.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S47>/Get Parameter3'

  // Terminate for MATLABSystem: '<S47>/Get Parameter5'
  if (!motion_controller_withPIC_DW.obj_g.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S47>/Get Parameter5'

  // Terminate for MATLABSystem: '<S47>/Get Parameter1'
  if (!motion_controller_withPIC_DW.obj_o.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S47>/Get Parameter1'

  // Terminate for MATLABSystem: '<S47>/Get Parameter'
  if (!motion_controller_withPIC_DW.obj_m.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S47>/Get Parameter'

  // Terminate for MATLABSystem: '<S15>/Get Parameter1'
  if (!motion_controller_withPIC_DW.obj_f.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S15>/Get Parameter1'

  // Terminate for S-Function (sfun_private_function_caller) generated from: '<S15>/get_effort' incorporates:
  //   SubSystem: '<S15>/get_effort'

  motion_controll_get_effort_Term();

  // End of Terminate for S-Function (sfun_private_function_caller) generated from: '<S15>/get_effort' 
  // End of Terminate for SubSystem: '<Root>/controller'

  // Terminate for MATLABSystem: '<S10>/Get Parameter3'
  if (!motion_controller_withPIC_DW.obj_p3.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_p3.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/Get Parameter3'

  // Terminate for MATLABSystem: '<S10>/Get Parameter1'
  if (!motion_controller_withPIC_DW.obj_i.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/Get Parameter1'

  // Terminate for MATLABSystem: '<Root>/Get Parameter'
  if (!motion_controller_withPIC_DW.obj_ay.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_ay.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter'

  // Terminate for MATLABSystem: '<Root>/Get Parameter1'
  if (!motion_controller_withPIC_DW.obj_hm.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_hm.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter1'

  // Terminate for MATLABSystem: '<Root>/Get Parameter2'
  if (!motion_controller_withPIC_DW.obj_di.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_di.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter2'

  // Terminate for MATLABSystem: '<Root>/Get Parameter3'
  if (!motion_controller_withPIC_DW.obj_pw.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_pw.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter3'

  // Terminate for MATLABSystem: '<Root>/Get Parameter4'
  if (!motion_controller_withPIC_DW.obj_ny.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_ny.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter4'

  // Terminate for MATLABSystem: '<Root>/Get Parameter5'
  if (!motion_controller_withPIC_DW.obj_j.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter5'

  // Terminate for MATLABSystem: '<Root>/Get Parameter15'
  if (!motion_controller_withPIC_DW.obj_kx.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_kx.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter15'

  // Terminate for MATLABSystem: '<Root>/Get Parameter16'
  if (!motion_controller_withPIC_DW.obj_ma.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_ma.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter16'

  // Terminate for Enabled SubSystem: '<Root>/picController'
  // Terminate for MATLABSystem: '<S16>/Get Parameter'
  if (!motion_controller_withPIC_DW.obj_p.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S16>/Get Parameter'

  // Terminate for MATLABSystem: '<S16>/Get Parameter1'
  if (!motion_controller_withPIC_DW.obj_l.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S16>/Get Parameter1'

  // Terminate for MATLABSystem: '<S16>/Get Parameter2'
  if (!motion_controller_withPIC_DW.obj_e.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S16>/Get Parameter2'

  // Terminate for MATLABSystem: '<S16>/Get Parameter6'
  if (!motion_controller_withPIC_DW.obj.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S16>/Get Parameter6'
  // End of Terminate for SubSystem: '<Root>/picController'

  // Terminate for MATLABSystem: '<S10>/Get Parameter2'
  if (!motion_controller_withPIC_DW.obj_ls.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_ls.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/Get Parameter2'

  // Terminate for Enabled SubSystem: '<Root>/cmd_pub'
  motion_control_CurrentTime_Term(&motion_controller_withPIC_DW.CurrentTime1);

  // Terminate for MATLABSystem: '<S42>/SinkBlock'
  if (!motion_controller_withPIC_DW.obj_bq.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_bq.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S42>/SinkBlock'
  motion_control_CurrentTime_Term(&motion_controller_withPIC_DW.CurrentTime);

  // Terminate for MATLABSystem: '<S43>/SinkBlock'
  if (!motion_controller_withPIC_DW.obj_ca.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_ca.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S43>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/cmd_pub'
}

// Constructor
motion_controller_withPIC::motion_controller_withPIC() :
  motion_controller_withPIC_B(),
  motion_controller_withPIC_DW(),
  motion_controller_withPIC_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
motion_controller_withPIC::~motion_controller_withPIC()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_motion_controller_wi_T * motion_controller_withPIC::getRTM()
{
  return (&motion_controller_withPIC_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
