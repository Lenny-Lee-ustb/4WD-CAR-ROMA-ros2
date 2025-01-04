//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: motion_controller_withPIC.cpp
//
// Code generated for Simulink model 'motion_controller_withPIC'.
//
// Model version                  : 2.323
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sat Jan  4 16:58:07 2025
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
#include "rt_roundd_snf.h"
#include <emmintrin.h>
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

// Named constants for Chart: '<S5>/Chart'
const uint8_T motion_controller_wi_IN_running = 2U;

// Named constants for Chart: '<S9>/Chart'
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
  // Start for MATLABSystem: '<S8>/Current Time'
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1;
  localDW->obj.isSetupComplete = true;
}

// Output and update for atomic system:
void motion_controller_withPIC::motion_controller_w_CurrentTime
  (B_CurrentTime_motion_controll_T *localB)
{
  // MATLABSystem: '<S8>/Current Time'
  currentROS2TimeBus(&localB->CurrentTime);
}

// Termination for atomic system:
void motion_controller_withPIC::motion_control_CurrentTime_Term
  (DW_CurrentTime_motion_control_T *localDW)
{
  // Terminate for MATLABSystem: '<S8>/Current Time'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/Current Time'
}

// Output and update for Simulink Function: '<S9>/get_angle_4w'
void motion_controller_withPIC::motion_controller__get_angle_4w(real_T
  rtu_delta_f, real_T rtu_delta_r, real_T rty_angle_cmd[4]) const
{
  real_T deltaFR;
  real_T deltaRL;
  real_T deltaRR;

  // MATLAB Function: '<S34>/MATLAB Function' incorporates:
  //   SignalConversion generated from: '<S34>/ackermann_enable'
  //   SignalConversion generated from: '<S34>/delta_f'
  //   SignalConversion generated from: '<S34>/delta_r'

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

    // SignalConversion generated from: '<S34>/angle_cmd' incorporates:
    //   SignalConversion generated from: '<S34>/delta_f'
    //   SignalConversion generated from: '<S34>/delta_r'

    rty_angle_cmd[0] = atan(deltaRL_tmp / deltaFL_tmp) * deltaFR;
    deltaFR_tmp += 2.0 * motion_controller_withPIC_P.L;
    deltaFR *= atan(deltaRL_tmp / deltaFR_tmp);
    deltaRL_tmp = 2.0 * motion_controller_withPIC_P.L * deltaRL;
    deltaRL = atan(deltaRL_tmp / deltaFL_tmp) * deltaRR;
    deltaRR *= atan(deltaRL_tmp / deltaFR_tmp);
  } else {
    // SignalConversion generated from: '<S34>/angle_cmd' incorporates:
    //   SignalConversion generated from: '<S34>/delta_f'

    rty_angle_cmd[0] = rtu_delta_f;
    deltaFR = rtu_delta_f;
    deltaRR = rtu_delta_r;
    deltaRL = rtu_delta_r;
  }

  // SignalConversion generated from: '<S34>/angle_cmd' incorporates:
  //   MATLAB Function: '<S34>/MATLAB Function'

  rty_angle_cmd[1] = deltaFR;
  rty_angle_cmd[2] = deltaRR;
  rty_angle_cmd[3] = deltaRL;
}

// System initialize for Simulink Function: '<S9>/get_effort'
void motion_controller_withPIC::motion_controll_get_effort_Init()
{
  static const char_T prmName[10] = "effortMax";
  static const char_T prmName_0[10] = "tcsK1Sgne";
  static const char_T prmName_1[7] = "tcsK2e";
  static const char_T prmName_2[16] = "tcsKappaDesired";

  // Start for MATLABSystem: '<S35>/Get Parameter'
  motion_controller_withPIC_DW.obj_d.matlabCodegenIsDeleted = false;
  motion_controller_withPIC_DW.obj_d.isInitialized = 1;
  ParamGet_motion_controller_withPIC_202.initParam(&prmName[0]);
  ParamGet_motion_controller_withPIC_202.setInitialValue(0.6);
  motion_controller_withPIC_DW.obj_d.isSetupComplete = true;

  // Start for MATLABSystem: '<S35>/Get Parameter2'
  motion_controller_withPIC_DW.obj_ae.matlabCodegenIsDeleted = false;
  motion_controller_withPIC_DW.obj_ae.isInitialized = 1;
  ParamGet_motion_controller_withPIC_354.initParam(&prmName_0[0]);
  ParamGet_motion_controller_withPIC_354.setInitialValue(0.8);
  motion_controller_withPIC_DW.obj_ae.isSetupComplete = true;

  // Start for MATLABSystem: '<S35>/Get Parameter3'
  motion_controller_withPIC_DW.obj_lw.matlabCodegenIsDeleted = false;
  motion_controller_withPIC_DW.obj_lw.isInitialized = 1;
  ParamGet_motion_controller_withPIC_355.initParam(&prmName_1[0]);
  ParamGet_motion_controller_withPIC_355.setInitialValue(10.0);
  motion_controller_withPIC_DW.obj_lw.isSetupComplete = true;

  // Start for MATLABSystem: '<S35>/Get Parameter5'
  motion_controller_withPIC_DW.obj_a.matlabCodegenIsDeleted = false;
  motion_controller_withPIC_DW.obj_a.isInitialized = 1;
  ParamGet_motion_controller_withPIC_393.initParam(&prmName_2[0]);
  ParamGet_motion_controller_withPIC_393.setInitialValue(0.15);
  motion_controller_withPIC_DW.obj_a.isSetupComplete = true;
}

// Output and update for Simulink Function: '<S9>/get_effort'
void motion_controller_withPIC::motion_controller_wi_get_effort(real_T
  rtu_longdrive, real_T rtu_vx, real_T rtu_dvx, const real_T rtu_omega4w[4],
  real_T rty_effort_cmd[4])
{
  // MATLABSystem: '<S35>/Get Parameter'
  ParamGet_motion_controller_withPIC_202.getParameter
    (&motion_controller_withPIC_B.b_value);

  // MATLABSystem: '<S35>/Get Parameter2'
  ParamGet_motion_controller_withPIC_354.getParameter
    (&motion_controller_withPIC_B.b_value_c);

  // MATLABSystem: '<S35>/Get Parameter3'
  ParamGet_motion_controller_withPIC_355.getParameter
    (&motion_controller_withPIC_B.b_value_k);

  // MATLABSystem: '<S35>/Get Parameter5'
  ParamGet_motion_controller_withPIC_393.getParameter
    (&motion_controller_withPIC_B.b_value_cx);

  // MATLAB Function: '<S35>/MATLAB Function' incorporates:
  //   Constant: '<S35>/Constant4'
  //   MATLABSystem: '<S35>/Get Parameter'
  //   MATLABSystem: '<S35>/Get Parameter2'
  //   MATLABSystem: '<S35>/Get Parameter3'
  //   MATLABSystem: '<S35>/Get Parameter5'
  //   SignalConversion generated from: '<S35>/angle1'
  //   SignalConversion generated from: '<S35>/angle2'
  //   SignalConversion generated from: '<S35>/angle3'
  //   SignalConversion generated from: '<S35>/angle'

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
      // SignalConversion generated from: '<S35>/angle_cmd'
      rty_effort_cmd[0] = motion_controller_withPIC_B.effort;
    } else {
      // SignalConversion generated from: '<S35>/angle_cmd'
      rty_effort_cmd[0] = sat_idx_0;
    }

    if (motion_controller_withPIC_B.effort <= sat_idx_1) {
      // SignalConversion generated from: '<S35>/angle_cmd'
      rty_effort_cmd[1] = -motion_controller_withPIC_B.effort;
    } else {
      // SignalConversion generated from: '<S35>/angle_cmd'
      rty_effort_cmd[1] = -sat_idx_1;
    }

    if (motion_controller_withPIC_B.effort <= sat_idx_2) {
      // SignalConversion generated from: '<S35>/angle_cmd'
      rty_effort_cmd[2] = -motion_controller_withPIC_B.effort;
    } else {
      // SignalConversion generated from: '<S35>/angle_cmd'
      rty_effort_cmd[2] = -sat_idx_2;
    }

    if (motion_controller_withPIC_B.effort <= sat_idx_3) {
      // SignalConversion generated from: '<S35>/angle_cmd'
      rty_effort_cmd[3] = motion_controller_withPIC_B.effort;
    } else {
      // SignalConversion generated from: '<S35>/angle_cmd'
      rty_effort_cmd[3] = sat_idx_3;
    }
  } else {
    // SignalConversion generated from: '<S35>/angle_cmd'
    rty_effort_cmd[0] = motion_controller_withPIC_B.effort;
    rty_effort_cmd[1] = -motion_controller_withPIC_B.effort;
    rty_effort_cmd[2] = -motion_controller_withPIC_B.effort;
    rty_effort_cmd[3] = motion_controller_withPIC_B.effort;
  }

  // End of MATLAB Function: '<S35>/MATLAB Function'
}

// Termination for Simulink Function: '<S9>/get_effort'
void motion_controller_withPIC::motion_controll_get_effort_Term()
{
  // Terminate for MATLABSystem: '<S35>/Get Parameter'
  if (!motion_controller_withPIC_DW.obj_d.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S35>/Get Parameter'

  // Terminate for MATLABSystem: '<S35>/Get Parameter2'
  if (!motion_controller_withPIC_DW.obj_ae.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_ae.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S35>/Get Parameter2'

  // Terminate for MATLABSystem: '<S35>/Get Parameter3'
  if (!motion_controller_withPIC_DW.obj_lw.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_lw.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S35>/Get Parameter3'

  // Terminate for MATLABSystem: '<S35>/Get Parameter5'
  if (!motion_controller_withPIC_DW.obj_a.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_a.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S35>/Get Parameter5'
}

// Output and update for Simulink Function: '<S9>/get_spd'
void motion_controller_withPIC::motion_controller_withP_get_spd(real_T rtu_angle,
  real_T rtu_longdrive, real_T rty_spd_cmd[4]) const
{
  real_T b_x;
  real_T vFR;
  real_T vRL;
  real_T vRR;
  real_T vRR_tmp;

  // MATLAB Function: '<S36>/MATLAB Function' incorporates:
  //   Gain: '<S36>/Gain'
  //   SignalConversion generated from: '<S36>/ackermann_enable'
  //   SignalConversion generated from: '<S36>/angle'
  //   SignalConversion generated from: '<S36>/longdrive'

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

    // SignalConversion generated from: '<S36>/spd_cmd' incorporates:
    //   SignalConversion generated from: '<S36>/angle'
    //   SignalConversion generated from: '<S36>/longdrive'

    rty_spd_cmd[0] = vRL / cos(b_x);
  } else {
    // SignalConversion generated from: '<S36>/spd_cmd' incorporates:
    //   SignalConversion generated from: '<S36>/longdrive'

    rty_spd_cmd[0] = rtu_longdrive;
    vFR = rtu_longdrive;
    vRL = rtu_longdrive;
    vRR = rtu_longdrive;
  }

  // SignalConversion generated from: '<S36>/spd_cmd' incorporates:
  //   MATLAB Function: '<S36>/MATLAB Function'

  rty_spd_cmd[1] = -vFR;
  rty_spd_cmd[2] = -vRR;
  rty_spd_cmd[3] = vRL;
}

// Function for MATLAB Function: '<S49>/solvex'
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

// Function for MATLAB Function: '<S49>/solvex'
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

// Function for MATLAB Function: '<S49>/solvex'
real_T motion_controller_withPIC::motion_controlle_xnrm2_hNM7iFHJ(int32_T n,
  const real_T x[1701], int32_T ix0)
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[ix0 - 1]);
    } else {
      motion_controller_withPIC_B.scale_b = 3.3121686421112381E-170;
      motion_controller_withPIC_B.kend_l = (ix0 + n) - 1;
      for (motion_controller_withPIC_B.k_h = ix0;
           motion_controller_withPIC_B.k_h <= motion_controller_withPIC_B.kend_l;
           motion_controller_withPIC_B.k_h++) {
        motion_controller_withPIC_B.absxk_o = fabs
          (x[motion_controller_withPIC_B.k_h - 1]);
        if (motion_controller_withPIC_B.absxk_o >
            motion_controller_withPIC_B.scale_b) {
          motion_controller_withPIC_B.t_n = motion_controller_withPIC_B.scale_b /
            motion_controller_withPIC_B.absxk_o;
          y = y * motion_controller_withPIC_B.t_n *
            motion_controller_withPIC_B.t_n + 1.0;
          motion_controller_withPIC_B.scale_b =
            motion_controller_withPIC_B.absxk_o;
        } else {
          motion_controller_withPIC_B.t_n = motion_controller_withPIC_B.absxk_o /
            motion_controller_withPIC_B.scale_b;
          y += motion_controller_withPIC_B.t_n * motion_controller_withPIC_B.t_n;
        }
      }

      y = motion_controller_withPIC_B.scale_b * sqrt(y);
    }
  }

  return y;
}

real_T motion_controller_withPIC::motion_controller_rt_hypotd_snf(real_T u0,
  real_T u1)
{
  real_T y;
  motion_controller_withPIC_B.a_hm = fabs(u0);
  motion_controller_withPIC_B.b = fabs(u1);
  if (motion_controller_withPIC_B.a_hm < motion_controller_withPIC_B.b) {
    motion_controller_withPIC_B.a_hm /= motion_controller_withPIC_B.b;
    y = sqrt(motion_controller_withPIC_B.a_hm * motion_controller_withPIC_B.a_hm
             + 1.0) * motion_controller_withPIC_B.b;
  } else if (motion_controller_withPIC_B.a_hm > motion_controller_withPIC_B.b) {
    motion_controller_withPIC_B.b /= motion_controller_withPIC_B.a_hm;
    y = sqrt(motion_controller_withPIC_B.b * motion_controller_withPIC_B.b + 1.0)
      * motion_controller_withPIC_B.a_hm;
  } else if (rtIsNaN(motion_controller_withPIC_B.b)) {
    y = (rtNaN);
  } else {
    y = motion_controller_withPIC_B.a_hm * 1.4142135623730951;
  }

  return y;
}

// Function for MATLAB Function: '<S49>/solvex'
real_T motion_controller_withPIC::motion_control_xzlarfg_Bt3Hq0Z4(int32_T n,
  real_T *alpha1, real_T x[1701], int32_T ix0)
{
  __m128d tmp;
  real_T tau;
  tau = 0.0;
  if (n > 0) {
    motion_controller_withPIC_B.xnorm_k = motion_controlle_xnrm2_hNM7iFHJ(n - 1,
      x, ix0);
    if (motion_controller_withPIC_B.xnorm_k != 0.0) {
      motion_controller_withPIC_B.xnorm_k = motion_controller_rt_hypotd_snf
        (*alpha1, motion_controller_withPIC_B.xnorm_k);
      if (*alpha1 >= 0.0) {
        motion_controller_withPIC_B.xnorm_k =
          -motion_controller_withPIC_B.xnorm_k;
      }

      if (fabs(motion_controller_withPIC_B.xnorm_k) < 1.0020841800044864E-292) {
        motion_controller_withPIC_B.knt_j = 0;
        motion_controller_withPIC_B.scalarLB_p = (ix0 + n) - 2;
        do {
          motion_controller_withPIC_B.knt_j++;
          motion_controller_withPIC_B.vectorUB_p =
            ((((motion_controller_withPIC_B.scalarLB_p - ix0) + 1) / 2) << 1) +
            ix0;
          motion_controller_withPIC_B.vectorUB_tmp_l =
            motion_controller_withPIC_B.vectorUB_p - 2;
          for (motion_controller_withPIC_B.d_l = ix0;
               motion_controller_withPIC_B.d_l <=
               motion_controller_withPIC_B.vectorUB_tmp_l;
               motion_controller_withPIC_B.d_l += 2) {
            tmp = _mm_loadu_pd(&x[motion_controller_withPIC_B.d_l - 1]);
            _mm_storeu_pd(&x[motion_controller_withPIC_B.d_l - 1], _mm_mul_pd
                          (tmp, _mm_set1_pd(9.9792015476736E+291)));
          }

          for (motion_controller_withPIC_B.d_l =
               motion_controller_withPIC_B.vectorUB_p;
               motion_controller_withPIC_B.d_l <=
               motion_controller_withPIC_B.scalarLB_p;
               motion_controller_withPIC_B.d_l++) {
            x[motion_controller_withPIC_B.d_l - 1] *= 9.9792015476736E+291;
          }

          motion_controller_withPIC_B.xnorm_k *= 9.9792015476736E+291;
          *alpha1 *= 9.9792015476736E+291;
        } while ((fabs(motion_controller_withPIC_B.xnorm_k) <
                  1.0020841800044864E-292) && (motion_controller_withPIC_B.knt_j
                  < 20));

        motion_controller_withPIC_B.xnorm_k = motion_controller_rt_hypotd_snf
          (*alpha1, motion_controlle_xnrm2_hNM7iFHJ(n - 1, x, ix0));
        if (*alpha1 >= 0.0) {
          motion_controller_withPIC_B.xnorm_k =
            -motion_controller_withPIC_B.xnorm_k;
        }

        tau = (motion_controller_withPIC_B.xnorm_k - *alpha1) /
          motion_controller_withPIC_B.xnorm_k;
        motion_controller_withPIC_B.a_h = 1.0 / (*alpha1 -
          motion_controller_withPIC_B.xnorm_k);
        for (motion_controller_withPIC_B.d_l = ix0;
             motion_controller_withPIC_B.d_l <=
             motion_controller_withPIC_B.vectorUB_tmp_l;
             motion_controller_withPIC_B.d_l += 2) {
          tmp = _mm_loadu_pd(&x[motion_controller_withPIC_B.d_l - 1]);
          _mm_storeu_pd(&x[motion_controller_withPIC_B.d_l - 1], _mm_mul_pd(tmp,
            _mm_set1_pd(motion_controller_withPIC_B.a_h)));
        }

        for (motion_controller_withPIC_B.d_l =
             motion_controller_withPIC_B.vectorUB_p;
             motion_controller_withPIC_B.d_l <=
             motion_controller_withPIC_B.scalarLB_p;
             motion_controller_withPIC_B.d_l++) {
          x[motion_controller_withPIC_B.d_l - 1] *=
            motion_controller_withPIC_B.a_h;
        }

        for (motion_controller_withPIC_B.d_l = 0;
             motion_controller_withPIC_B.d_l < motion_controller_withPIC_B.knt_j;
             motion_controller_withPIC_B.d_l++) {
          motion_controller_withPIC_B.xnorm_k *= 1.0020841800044864E-292;
        }

        *alpha1 = motion_controller_withPIC_B.xnorm_k;
      } else {
        tau = (motion_controller_withPIC_B.xnorm_k - *alpha1) /
          motion_controller_withPIC_B.xnorm_k;
        motion_controller_withPIC_B.a_h = 1.0 / (*alpha1 -
          motion_controller_withPIC_B.xnorm_k);
        motion_controller_withPIC_B.d_l = (ix0 + n) - 2;
        motion_controller_withPIC_B.scalarLB_p =
          ((((motion_controller_withPIC_B.d_l - ix0) + 1) / 2) << 1) + ix0;
        motion_controller_withPIC_B.vectorUB_p =
          motion_controller_withPIC_B.scalarLB_p - 2;
        for (motion_controller_withPIC_B.knt_j = ix0;
             motion_controller_withPIC_B.knt_j <=
             motion_controller_withPIC_B.vectorUB_p;
             motion_controller_withPIC_B.knt_j += 2) {
          tmp = _mm_loadu_pd(&x[motion_controller_withPIC_B.knt_j - 1]);
          _mm_storeu_pd(&x[motion_controller_withPIC_B.knt_j - 1], _mm_mul_pd
                        (tmp, _mm_set1_pd(motion_controller_withPIC_B.a_h)));
        }

        for (motion_controller_withPIC_B.knt_j =
             motion_controller_withPIC_B.scalarLB_p;
             motion_controller_withPIC_B.knt_j <=
             motion_controller_withPIC_B.d_l; motion_controller_withPIC_B.knt_j
             ++) {
          x[motion_controller_withPIC_B.knt_j - 1] *=
            motion_controller_withPIC_B.a_h;
        }

        *alpha1 = motion_controller_withPIC_B.xnorm_k;
      }
    }
  }

  return tau;
}

// Function for MATLAB Function: '<S49>/solvex'
void motion_controller_withPIC::motion_controll_xzlarf_ROZS8xVG(int32_T m,
  int32_T n, int32_T iv0, real_T tau, real_T C[1701], int32_T ic0, real_T work
  [81])
{
  if (tau != 0.0) {
    boolean_T exitg2;
    motion_controller_withPIC_B.lastv = m;
    motion_controller_withPIC_B.lastc_f = iv0 + m;
    while ((motion_controller_withPIC_B.lastv > 0) &&
           (C[motion_controller_withPIC_B.lastc_f - 2] == 0.0)) {
      motion_controller_withPIC_B.lastv--;
      motion_controller_withPIC_B.lastc_f--;
    }

    motion_controller_withPIC_B.lastc_f = n;
    exitg2 = false;
    while ((!exitg2) && (motion_controller_withPIC_B.lastc_f > 0)) {
      int32_T exitg1;
      motion_controller_withPIC_B.coltop_p =
        (motion_controller_withPIC_B.lastc_f - 1) * 21 + ic0;
      motion_controller_withPIC_B.b_ia = motion_controller_withPIC_B.coltop_p;
      do {
        exitg1 = 0;
        if (motion_controller_withPIC_B.b_ia <=
            (motion_controller_withPIC_B.coltop_p +
             motion_controller_withPIC_B.lastv) - 1) {
          if (C[motion_controller_withPIC_B.b_ia - 1] != 0.0) {
            exitg1 = 1;
          } else {
            motion_controller_withPIC_B.b_ia++;
          }
        } else {
          motion_controller_withPIC_B.lastc_f--;
          exitg1 = 2;
        }
      } while (exitg1 == 0);

      if (exitg1 == 1) {
        exitg2 = true;
      }
    }

    motion_controller_withPIC_B.lastc_f--;
  } else {
    motion_controller_withPIC_B.lastv = 0;
    motion_controller_withPIC_B.lastc_f = -1;
  }

  if (motion_controller_withPIC_B.lastv > 0) {
    if (motion_controller_withPIC_B.lastc_f + 1 != 0) {
      if (motion_controller_withPIC_B.lastc_f >= 0) {
        memset(&work[0], 0, static_cast<uint32_T>
               (motion_controller_withPIC_B.lastc_f + 1) * sizeof(real_T));
      }

      motion_controller_withPIC_B.jA_a = 21 *
        motion_controller_withPIC_B.lastc_f + ic0;
      for (motion_controller_withPIC_B.coltop_p = ic0;
           motion_controller_withPIC_B.coltop_p <=
           motion_controller_withPIC_B.jA_a;
           motion_controller_withPIC_B.coltop_p += 21) {
        motion_controller_withPIC_B.c_g = 0.0;
        motion_controller_withPIC_B.d_c = (motion_controller_withPIC_B.coltop_p
          + motion_controller_withPIC_B.lastv) - 1;
        for (motion_controller_withPIC_B.b_ia =
             motion_controller_withPIC_B.coltop_p;
             motion_controller_withPIC_B.b_ia <= motion_controller_withPIC_B.d_c;
             motion_controller_withPIC_B.b_ia++) {
          motion_controller_withPIC_B.c_g += C[((iv0 +
            motion_controller_withPIC_B.b_ia) -
            motion_controller_withPIC_B.coltop_p) - 1] *
            C[motion_controller_withPIC_B.b_ia - 1];
        }

        motion_controller_withPIC_B.b_ia = div_nde_s32_floor
          (motion_controller_withPIC_B.coltop_p - ic0, 21);
        work[motion_controller_withPIC_B.b_ia] +=
          motion_controller_withPIC_B.c_g;
      }
    }

    if (!(-tau == 0.0)) {
      motion_controller_withPIC_B.jA_a = ic0;
      for (motion_controller_withPIC_B.coltop_p = 0;
           motion_controller_withPIC_B.coltop_p <=
           motion_controller_withPIC_B.lastc_f;
           motion_controller_withPIC_B.coltop_p++) {
        motion_controller_withPIC_B.c_g =
          work[motion_controller_withPIC_B.coltop_p];
        if (motion_controller_withPIC_B.c_g != 0.0) {
          motion_controller_withPIC_B.c_g *= -tau;
          motion_controller_withPIC_B.d_c = motion_controller_withPIC_B.lastv +
            motion_controller_withPIC_B.jA_a;
          for (motion_controller_withPIC_B.b_ia =
               motion_controller_withPIC_B.jA_a;
               motion_controller_withPIC_B.b_ia <
               motion_controller_withPIC_B.d_c; motion_controller_withPIC_B.b_ia
               ++) {
            C[motion_controller_withPIC_B.b_ia - 1] += C[((iv0 +
              motion_controller_withPIC_B.b_ia) -
              motion_controller_withPIC_B.jA_a) - 1] *
              motion_controller_withPIC_B.c_g;
          }
        }

        motion_controller_withPIC_B.jA_a += 21;
      }
    }
  }
}

// Function for MATLAB Function: '<S49>/solvex'
void motion_controller_withPIC::motion_controller__qrf_nGv3LI5p(real_T A[1701],
  int32_T m, int32_T n, int32_T nfxd, real_T tau[21])
{
  memset(&motion_controller_withPIC_B.work_h[0], 0, 81U * sizeof(real_T));
  motion_controller_withPIC_B.b_j1 = static_cast<uint8_T>(nfxd);
  for (motion_controller_withPIC_B.i_np = 0; motion_controller_withPIC_B.i_np <
       motion_controller_withPIC_B.b_j1; motion_controller_withPIC_B.i_np++) {
    motion_controller_withPIC_B.ii_h = motion_controller_withPIC_B.i_np * 21 +
      motion_controller_withPIC_B.i_np;
    motion_controller_withPIC_B.mmi_d1 = m - motion_controller_withPIC_B.i_np;
    if (motion_controller_withPIC_B.i_np + 1 < m) {
      motion_controller_withPIC_B.b_atmp_n = A[motion_controller_withPIC_B.ii_h];
      motion_controller_withPIC_B.tau_h = motion_control_xzlarfg_Bt3Hq0Z4
        (motion_controller_withPIC_B.mmi_d1,
         &motion_controller_withPIC_B.b_atmp_n, A,
         motion_controller_withPIC_B.ii_h + 2);
      tau[motion_controller_withPIC_B.i_np] = motion_controller_withPIC_B.tau_h;
      A[motion_controller_withPIC_B.ii_h] = motion_controller_withPIC_B.b_atmp_n;
    } else {
      motion_controller_withPIC_B.tau_h = 0.0;
      tau[motion_controller_withPIC_B.i_np] = 0.0;
    }

    if (motion_controller_withPIC_B.i_np + 1 < n) {
      motion_controller_withPIC_B.b_atmp_n = A[motion_controller_withPIC_B.ii_h];
      A[motion_controller_withPIC_B.ii_h] = 1.0;
      motion_controll_xzlarf_ROZS8xVG(motion_controller_withPIC_B.mmi_d1, (n -
        motion_controller_withPIC_B.i_np) - 1, motion_controller_withPIC_B.ii_h
        + 1, motion_controller_withPIC_B.tau_h, A,
        motion_controller_withPIC_B.ii_h + 22,
        motion_controller_withPIC_B.work_h);
      A[motion_controller_withPIC_B.ii_h] = motion_controller_withPIC_B.b_atmp_n;
    }
  }
}

// Function for MATLAB Function: '<S49>/solvex'
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
      motion_controller_withPIC_B.u1_f = mrows;
    } else {
      motion_controller_withPIC_B.u1_f = ncols;
    }

    obj->minRowCol = motion_controller_withPIC_B.u1_f;
    memset(&obj->tau[0], 0, 21U * sizeof(real_T));
    if (motion_controller_withPIC_B.u1_f < 1) {
      motion_controller_withPIC_B.nfxd_k = (ncols / 4) << 2;
      motion_controller_withPIC_B.i_c = motion_controller_withPIC_B.nfxd_k - 4;
      for (motion_controller_withPIC_B.u1_f = 0;
           motion_controller_withPIC_B.u1_f <= motion_controller_withPIC_B.i_c;
           motion_controller_withPIC_B.u1_f += 4) {
        tmp = _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32
          (motion_controller_withPIC_B.u1_f), _mm_loadu_si128((const __m128i *)
          &offsets[0])), _mm_set1_epi32(1));
        _mm_storeu_si128((__m128i *)&obj->jpvt[motion_controller_withPIC_B.u1_f],
                         tmp);
      }

      for (motion_controller_withPIC_B.u1_f = motion_controller_withPIC_B.nfxd_k;
           motion_controller_withPIC_B.u1_f < ncols;
           motion_controller_withPIC_B.u1_f++) {
        obj->jpvt[motion_controller_withPIC_B.u1_f] =
          motion_controller_withPIC_B.u1_f + 1;
      }
    } else {
      motion_controller_withPIC_B.nfxd_k = -1;
      for (motion_controller_withPIC_B.i_c = 0; motion_controller_withPIC_B.i_c <
           ncols; motion_controller_withPIC_B.i_c++) {
        if (obj->jpvt[motion_controller_withPIC_B.i_c] != 0) {
          motion_controller_withPIC_B.nfxd_k++;
          if (motion_controller_withPIC_B.i_c + 1 !=
              motion_controller_withPIC_B.nfxd_k + 1) {
            motion_controller_withPIC_B.ix_p = motion_controller_withPIC_B.i_c *
              21;
            motion_controller_withPIC_B.iy_m =
              motion_controller_withPIC_B.nfxd_k * 21;
            for (motion_controller_withPIC_B.mmi_d = 0;
                 motion_controller_withPIC_B.mmi_d < mrows;
                 motion_controller_withPIC_B.mmi_d++) {
              motion_controller_withPIC_B.temp_tmp_jk =
                motion_controller_withPIC_B.ix_p +
                motion_controller_withPIC_B.mmi_d;
              motion_controller_withPIC_B.temp_f = obj->
                QR[motion_controller_withPIC_B.temp_tmp_jk];
              motion_controller_withPIC_B.itemp_p =
                motion_controller_withPIC_B.iy_m +
                motion_controller_withPIC_B.mmi_d;
              obj->QR[motion_controller_withPIC_B.temp_tmp_jk] = obj->
                QR[motion_controller_withPIC_B.itemp_p];
              obj->QR[motion_controller_withPIC_B.itemp_p] =
                motion_controller_withPIC_B.temp_f;
            }

            obj->jpvt[motion_controller_withPIC_B.i_c] = obj->
              jpvt[motion_controller_withPIC_B.nfxd_k];
            obj->jpvt[motion_controller_withPIC_B.nfxd_k] =
              motion_controller_withPIC_B.i_c + 1;
          } else {
            obj->jpvt[motion_controller_withPIC_B.i_c] =
              motion_controller_withPIC_B.i_c + 1;
          }
        } else {
          obj->jpvt[motion_controller_withPIC_B.i_c] =
            motion_controller_withPIC_B.i_c + 1;
        }
      }

      if (motion_controller_withPIC_B.nfxd_k + 1 <=
          motion_controller_withPIC_B.u1_f) {
        motion_controller_withPIC_B.nfxd_k++;
      } else {
        motion_controller_withPIC_B.nfxd_k = motion_controller_withPIC_B.u1_f;
      }

      memset(&obj->tau[0], 0, 21U * sizeof(real_T));
      motion_controller__qrf_nGv3LI5p(obj->QR, mrows, ncols,
        motion_controller_withPIC_B.nfxd_k, obj->tau);
      if (motion_controller_withPIC_B.nfxd_k < motion_controller_withPIC_B.u1_f)
      {
        memset(&motion_controller_withPIC_B.work_n[0], 0, 81U * sizeof(real_T));
        memset(&motion_controller_withPIC_B.vn1_b[0], 0, 81U * sizeof(real_T));
        memset(&motion_controller_withPIC_B.vn2_l[0], 0, 81U * sizeof(real_T));
        for (motion_controller_withPIC_B.i_c =
             motion_controller_withPIC_B.nfxd_k + 1;
             motion_controller_withPIC_B.i_c <= ncols;
             motion_controller_withPIC_B.i_c++) {
          motion_controller_withPIC_B.temp_f = motion_controlle_xnrm2_hNM7iFHJ
            (mrows - motion_controller_withPIC_B.nfxd_k, obj->QR,
             ((motion_controller_withPIC_B.i_c - 1) * 21 +
              motion_controller_withPIC_B.nfxd_k) + 1);
          motion_controller_withPIC_B.vn1_b[motion_controller_withPIC_B.i_c - 1]
            = motion_controller_withPIC_B.temp_f;
          motion_controller_withPIC_B.vn2_l[motion_controller_withPIC_B.i_c - 1]
            = motion_controller_withPIC_B.temp_f;
        }

        for (motion_controller_withPIC_B.i_c =
             motion_controller_withPIC_B.nfxd_k + 1;
             motion_controller_withPIC_B.i_c <= motion_controller_withPIC_B.u1_f;
             motion_controller_withPIC_B.i_c++) {
          motion_controller_withPIC_B.temp_tmp_jk =
            (motion_controller_withPIC_B.i_c - 1) * 21;
          motion_controller_withPIC_B.ix_p =
            (motion_controller_withPIC_B.temp_tmp_jk +
             motion_controller_withPIC_B.i_c) - 1;
          motion_controller_withPIC_B.iy_m = ncols -
            motion_controller_withPIC_B.i_c;
          motion_controller_withPIC_B.mmi_d = mrows -
            motion_controller_withPIC_B.i_c;
          if (motion_controller_withPIC_B.iy_m + 1 < 1) {
            motion_controller_withPIC_B.pvt_k = -2;
          } else {
            motion_controller_withPIC_B.pvt_k = -1;
            if (motion_controller_withPIC_B.iy_m + 1 > 1) {
              motion_controller_withPIC_B.temp_f = fabs
                (motion_controller_withPIC_B.vn1_b[motion_controller_withPIC_B.i_c
                 - 1]);
              for (motion_controller_withPIC_B.itemp_p = 2;
                   motion_controller_withPIC_B.itemp_p <=
                   motion_controller_withPIC_B.iy_m + 1;
                   motion_controller_withPIC_B.itemp_p++) {
                motion_controller_withPIC_B.s_c = fabs
                  (motion_controller_withPIC_B.vn1_b
                   [(motion_controller_withPIC_B.i_c +
                     motion_controller_withPIC_B.itemp_p) - 2]);
                if (motion_controller_withPIC_B.s_c >
                    motion_controller_withPIC_B.temp_f) {
                  motion_controller_withPIC_B.pvt_k =
                    motion_controller_withPIC_B.itemp_p - 2;
                  motion_controller_withPIC_B.temp_f =
                    motion_controller_withPIC_B.s_c;
                }
              }
            }
          }

          motion_controller_withPIC_B.pvt_k += motion_controller_withPIC_B.i_c;
          if (motion_controller_withPIC_B.pvt_k + 1 !=
              motion_controller_withPIC_B.i_c) {
            motion_controller_withPIC_B.c_ix_k =
              motion_controller_withPIC_B.pvt_k * 21;
            for (motion_controller_withPIC_B.c_k_a = 0;
                 motion_controller_withPIC_B.c_k_a < mrows;
                 motion_controller_withPIC_B.c_k_a++) {
              motion_controller_withPIC_B.b_temp_tmp_k =
                motion_controller_withPIC_B.c_ix_k +
                motion_controller_withPIC_B.c_k_a;
              motion_controller_withPIC_B.temp_f = obj->
                QR[motion_controller_withPIC_B.b_temp_tmp_k];
              motion_controller_withPIC_B.itemp_p =
                motion_controller_withPIC_B.temp_tmp_jk +
                motion_controller_withPIC_B.c_k_a;
              obj->QR[motion_controller_withPIC_B.b_temp_tmp_k] = obj->
                QR[motion_controller_withPIC_B.itemp_p];
              obj->QR[motion_controller_withPIC_B.itemp_p] =
                motion_controller_withPIC_B.temp_f;
            }

            motion_controller_withPIC_B.itemp_p = obj->
              jpvt[motion_controller_withPIC_B.pvt_k];
            obj->jpvt[motion_controller_withPIC_B.pvt_k] = obj->
              jpvt[motion_controller_withPIC_B.i_c - 1];
            obj->jpvt[motion_controller_withPIC_B.i_c - 1] =
              motion_controller_withPIC_B.itemp_p;
            motion_controller_withPIC_B.vn1_b[motion_controller_withPIC_B.pvt_k]
              =
              motion_controller_withPIC_B.vn1_b[motion_controller_withPIC_B.i_c
              - 1];
            motion_controller_withPIC_B.vn2_l[motion_controller_withPIC_B.pvt_k]
              =
              motion_controller_withPIC_B.vn2_l[motion_controller_withPIC_B.i_c
              - 1];
          }

          if (motion_controller_withPIC_B.i_c < mrows) {
            motion_controller_withPIC_B.temp_f = obj->
              QR[motion_controller_withPIC_B.ix_p];
            obj->tau[motion_controller_withPIC_B.i_c - 1] =
              motion_control_xzlarfg_Bt3Hq0Z4(motion_controller_withPIC_B.mmi_d
              + 1, &motion_controller_withPIC_B.temp_f, obj->QR,
              motion_controller_withPIC_B.ix_p + 2);
            obj->QR[motion_controller_withPIC_B.ix_p] =
              motion_controller_withPIC_B.temp_f;
          } else {
            obj->tau[motion_controller_withPIC_B.i_c - 1] = 0.0;
          }

          if (motion_controller_withPIC_B.i_c < ncols) {
            motion_controller_withPIC_B.temp_f = obj->
              QR[motion_controller_withPIC_B.ix_p];
            obj->QR[motion_controller_withPIC_B.ix_p] = 1.0;
            motion_controll_xzlarf_ROZS8xVG(motion_controller_withPIC_B.mmi_d +
              1, motion_controller_withPIC_B.iy_m,
              motion_controller_withPIC_B.ix_p + 1, obj->
              tau[motion_controller_withPIC_B.i_c - 1], obj->QR,
              motion_controller_withPIC_B.ix_p + 22,
              motion_controller_withPIC_B.work_n);
            obj->QR[motion_controller_withPIC_B.ix_p] =
              motion_controller_withPIC_B.temp_f;
          }

          for (motion_controller_withPIC_B.itemp_p =
               motion_controller_withPIC_B.i_c + 1;
               motion_controller_withPIC_B.itemp_p <= ncols;
               motion_controller_withPIC_B.itemp_p++) {
            motion_controller_withPIC_B.ix_p =
              (motion_controller_withPIC_B.itemp_p - 1) * 21 +
              motion_controller_withPIC_B.i_c;
            motion_controller_withPIC_B.temp_f =
              motion_controller_withPIC_B.vn1_b[motion_controller_withPIC_B.itemp_p
              - 1];
            if (motion_controller_withPIC_B.temp_f != 0.0) {
              motion_controller_withPIC_B.s_c = fabs(obj->
                QR[motion_controller_withPIC_B.ix_p - 1]) /
                motion_controller_withPIC_B.temp_f;
              motion_controller_withPIC_B.s_c = 1.0 -
                motion_controller_withPIC_B.s_c *
                motion_controller_withPIC_B.s_c;
              if (motion_controller_withPIC_B.s_c < 0.0) {
                motion_controller_withPIC_B.s_c = 0.0;
              }

              motion_controller_withPIC_B.temp2_i =
                motion_controller_withPIC_B.temp_f /
                motion_controller_withPIC_B.vn2_l[motion_controller_withPIC_B.itemp_p
                - 1];
              motion_controller_withPIC_B.temp2_i =
                motion_controller_withPIC_B.temp2_i *
                motion_controller_withPIC_B.temp2_i *
                motion_controller_withPIC_B.s_c;
              if (motion_controller_withPIC_B.temp2_i <= 1.4901161193847656E-8)
              {
                if (motion_controller_withPIC_B.i_c < mrows) {
                  motion_controller_withPIC_B.temp_f =
                    motion_controlle_xnrm2_hNM7iFHJ
                    (motion_controller_withPIC_B.mmi_d, obj->QR,
                     motion_controller_withPIC_B.ix_p + 1);
                  motion_controller_withPIC_B.vn1_b[motion_controller_withPIC_B.itemp_p
                    - 1] = motion_controller_withPIC_B.temp_f;
                  motion_controller_withPIC_B.vn2_l[motion_controller_withPIC_B.itemp_p
                    - 1] = motion_controller_withPIC_B.temp_f;
                } else {
                  motion_controller_withPIC_B.vn1_b[motion_controller_withPIC_B.itemp_p
                    - 1] = 0.0;
                  motion_controller_withPIC_B.vn2_l[motion_controller_withPIC_B.itemp_p
                    - 1] = 0.0;
                }
              } else {
                motion_controller_withPIC_B.vn1_b[motion_controller_withPIC_B.itemp_p
                  - 1] = motion_controller_withPIC_B.temp_f * sqrt
                  (motion_controller_withPIC_B.s_c);
              }
            }
          }
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S49>/solvex'
void motion_controller_withPIC::motion_controller_w_computeQ__l
  (sIZAIOglGM5dPDQlNukc9SD_motio_T *obj, int32_T nrows)
{
  motion_controller_withPIC_B.i_p = obj->minRowCol;
  for (motion_controller_withPIC_B.idx_g = 0; motion_controller_withPIC_B.idx_g <
       motion_controller_withPIC_B.i_p; motion_controller_withPIC_B.idx_g++) {
    motion_controller_withPIC_B.iQR0_o = 21 * motion_controller_withPIC_B.idx_g
      + motion_controller_withPIC_B.idx_g;
    motion_controller_withPIC_B.ia_e = obj->mrows -
      motion_controller_withPIC_B.idx_g;
    if (motion_controller_withPIC_B.ia_e - 2 >= 0) {
      memcpy(&obj->Q[motion_controller_withPIC_B.iQR0_o + 1], &obj->
             QR[motion_controller_withPIC_B.iQR0_o + 1], static_cast<uint32_T>
             (((motion_controller_withPIC_B.ia_e +
                motion_controller_withPIC_B.iQR0_o) -
               motion_controller_withPIC_B.iQR0_o) - 1) * sizeof(real_T));
    }
  }

  motion_controller_withPIC_B.idx_g = obj->mrows;
  if (nrows >= 1) {
    for (motion_controller_withPIC_B.itau_i = motion_controller_withPIC_B.i_p;
         motion_controller_withPIC_B.itau_i < nrows;
         motion_controller_withPIC_B.itau_i++) {
      motion_controller_withPIC_B.ia_e = motion_controller_withPIC_B.itau_i * 21;
      memset(&obj->Q[motion_controller_withPIC_B.ia_e], 0, static_cast<uint32_T>
             ((motion_controller_withPIC_B.idx_g +
               motion_controller_withPIC_B.ia_e) -
              motion_controller_withPIC_B.ia_e) * sizeof(real_T));
      obj->Q[motion_controller_withPIC_B.ia_e +
        motion_controller_withPIC_B.itau_i] = 1.0;
    }

    motion_controller_withPIC_B.itau_i = obj->minRowCol - 1;
    memset(&motion_controller_withPIC_B.work_i[0], 0, 21U * sizeof(real_T));
    motion_controller_withPIC_B.i_p = obj->minRowCol;
    while (motion_controller_withPIC_B.i_p >= 1) {
      motion_controller_withPIC_B.iQR0_o = ((motion_controller_withPIC_B.i_p - 1)
        * 21 + motion_controller_withPIC_B.i_p) - 1;
      if (motion_controller_withPIC_B.i_p < nrows) {
        obj->Q[motion_controller_withPIC_B.iQR0_o] = 1.0;
        motion_controller_withPIC_B.ia_e = motion_controller_withPIC_B.idx_g -
          motion_controller_withPIC_B.i_p;
        if (obj->tau[motion_controller_withPIC_B.itau_i] != 0.0) {
          boolean_T exitg2;
          motion_controller_withPIC_B.lastc_e =
            motion_controller_withPIC_B.iQR0_o +
            motion_controller_withPIC_B.ia_e;
          while ((motion_controller_withPIC_B.ia_e + 1 > 0) && (obj->
                  Q[motion_controller_withPIC_B.lastc_e] == 0.0)) {
            motion_controller_withPIC_B.ia_e--;
            motion_controller_withPIC_B.lastc_e--;
          }

          motion_controller_withPIC_B.lastc_e = nrows -
            motion_controller_withPIC_B.i_p;
          exitg2 = false;
          while ((!exitg2) && (motion_controller_withPIC_B.lastc_e > 0)) {
            int32_T exitg1;
            motion_controller_withPIC_B.coltop_m =
              ((motion_controller_withPIC_B.lastc_e - 1) * 21 +
               motion_controller_withPIC_B.iQR0_o) + 22;
            motion_controller_withPIC_B.c_ia_d =
              motion_controller_withPIC_B.coltop_m;
            do {
              exitg1 = 0;
              if (motion_controller_withPIC_B.c_ia_d <=
                  motion_controller_withPIC_B.coltop_m +
                  motion_controller_withPIC_B.ia_e) {
                if (obj->Q[motion_controller_withPIC_B.c_ia_d - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  motion_controller_withPIC_B.c_ia_d++;
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
          motion_controller_withPIC_B.ia_e = -1;
          motion_controller_withPIC_B.lastc_e = -1;
        }

        if (motion_controller_withPIC_B.ia_e + 1 > 0) {
          if (motion_controller_withPIC_B.lastc_e + 1 != 0) {
            if (motion_controller_withPIC_B.lastc_e >= 0) {
              memset(&motion_controller_withPIC_B.work_i[0], 0,
                     static_cast<uint32_T>(motion_controller_withPIC_B.lastc_e +
                      1) * sizeof(real_T));
            }

            motion_controller_withPIC_B.c_ia_d = (21 *
              motion_controller_withPIC_B.lastc_e +
              motion_controller_withPIC_B.iQR0_o) + 22;
            for (motion_controller_withPIC_B.coltop_m =
                 motion_controller_withPIC_B.iQR0_o + 22;
                 motion_controller_withPIC_B.coltop_m <=
                 motion_controller_withPIC_B.c_ia_d;
                 motion_controller_withPIC_B.coltop_m += 21) {
              motion_controller_withPIC_B.b_c_m = 0.0;
              motion_controller_withPIC_B.f_i =
                motion_controller_withPIC_B.coltop_m +
                motion_controller_withPIC_B.ia_e;
              for (motion_controller_withPIC_B.jA_j =
                   motion_controller_withPIC_B.coltop_m;
                   motion_controller_withPIC_B.jA_j <=
                   motion_controller_withPIC_B.f_i;
                   motion_controller_withPIC_B.jA_j++) {
                motion_controller_withPIC_B.b_c_m += obj->Q
                  [(motion_controller_withPIC_B.iQR0_o +
                    motion_controller_withPIC_B.jA_j) -
                  motion_controller_withPIC_B.coltop_m] * obj->
                  Q[motion_controller_withPIC_B.jA_j - 1];
              }

              motion_controller_withPIC_B.jA_j = div_nde_s32_floor
                ((motion_controller_withPIC_B.coltop_m -
                  motion_controller_withPIC_B.iQR0_o) - 22, 21);
              motion_controller_withPIC_B.work_i[motion_controller_withPIC_B.jA_j]
                += motion_controller_withPIC_B.b_c_m;
            }
          }

          if (!(-obj->tau[motion_controller_withPIC_B.itau_i] == 0.0)) {
            motion_controller_withPIC_B.jA_j =
              motion_controller_withPIC_B.iQR0_o + 22;
            for (motion_controller_withPIC_B.coltop_m = 0;
                 motion_controller_withPIC_B.coltop_m <=
                 motion_controller_withPIC_B.lastc_e;
                 motion_controller_withPIC_B.coltop_m++) {
              motion_controller_withPIC_B.b_c_m =
                motion_controller_withPIC_B.work_i[motion_controller_withPIC_B.coltop_m];
              if (motion_controller_withPIC_B.b_c_m != 0.0) {
                motion_controller_withPIC_B.b_c_m *= -obj->
                  tau[motion_controller_withPIC_B.itau_i];
                motion_controller_withPIC_B.f_i =
                  motion_controller_withPIC_B.ia_e +
                  motion_controller_withPIC_B.jA_j;
                for (motion_controller_withPIC_B.c_ia_d =
                     motion_controller_withPIC_B.jA_j;
                     motion_controller_withPIC_B.c_ia_d <=
                     motion_controller_withPIC_B.f_i;
                     motion_controller_withPIC_B.c_ia_d++) {
                  obj->Q[motion_controller_withPIC_B.c_ia_d - 1] += obj->Q
                    [(motion_controller_withPIC_B.iQR0_o +
                      motion_controller_withPIC_B.c_ia_d) -
                    motion_controller_withPIC_B.jA_j] *
                    motion_controller_withPIC_B.b_c_m;
                }
              }

              motion_controller_withPIC_B.jA_j += 21;
            }
          }
        }
      }

      if (motion_controller_withPIC_B.i_p < motion_controller_withPIC_B.idx_g) {
        motion_controller_withPIC_B.lastc_e =
          ((motion_controller_withPIC_B.iQR0_o +
            motion_controller_withPIC_B.idx_g) - motion_controller_withPIC_B.i_p)
          + 1;
        for (motion_controller_withPIC_B.ia_e =
             motion_controller_withPIC_B.iQR0_o + 2;
             motion_controller_withPIC_B.ia_e <=
             motion_controller_withPIC_B.lastc_e;
             motion_controller_withPIC_B.ia_e++) {
          obj->Q[motion_controller_withPIC_B.ia_e - 1] *= -obj->
            tau[motion_controller_withPIC_B.itau_i];
        }
      }

      obj->Q[motion_controller_withPIC_B.iQR0_o] = 1.0 - obj->
        tau[motion_controller_withPIC_B.itau_i];
      motion_controller_withPIC_B.lastc_e = static_cast<uint8_T>
        (motion_controller_withPIC_B.i_p - 1);
      for (motion_controller_withPIC_B.ia_e = 0;
           motion_controller_withPIC_B.ia_e <
           motion_controller_withPIC_B.lastc_e; motion_controller_withPIC_B.ia_e
           ++) {
        obj->Q[(motion_controller_withPIC_B.iQR0_o -
                motion_controller_withPIC_B.ia_e) - 1] = 0.0;
      }

      motion_controller_withPIC_B.itau_i--;
      motion_controller_withPIC_B.i_p--;
    }
  }
}

// Function for MATLAB Function: '<S49>/solvex'
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

// Function for MATLAB Function: '<S49>/solvex'
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

// Function for MATLAB Function: '<S49>/solvex'
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

// Function for MATLAB Function: '<S49>/solvex'
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
    motion_controller_withPIC_B.tol_f = tolfactor * static_cast<real_T>
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
      motion_controller_withPIC_B.iy0_tmp_c = 21 *
        motion_controller_withPIC_B.nDepIneq;
      motion_controller_withPIC_B.c_gr = static_cast<uint8_T>
        (motion_controller_withPIC_B.nVar);
      memcpy(&qrmanager->QR[motion_controller_withPIC_B.iy0_tmp_c],
             &workingset->ATwset[motion_controller_withPIC_B.iy0_tmp_c],
             static_cast<uint32_T>((motion_controller_withPIC_B.c_gr +
               motion_controller_withPIC_B.iy0_tmp_c) -
              motion_controller_withPIC_B.iy0_tmp_c) * sizeof(real_T));
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
              motion_controller_withPIC_B.tol_f)) {
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

// Function for MATLAB Function: '<S49>/solvex'
void motion_controller_withPIC::motion_controller_wi_factorQR_c
  (sIZAIOglGM5dPDQlNukc9SD_motio_T *obj, const real_T A[1701], int32_T mrows,
   int32_T ncols)
{
  static const int32_T offsets[4] = { 0, 1, 2, 3 };

  __m128i tmp;
  boolean_T guard1;
  motion_controller_withPIC_B.k_b = mrows * ncols;
  guard1 = false;
  if (motion_controller_withPIC_B.k_b > 0) {
    for (motion_controller_withPIC_B.i_g = 0; motion_controller_withPIC_B.i_g <
         ncols; motion_controller_withPIC_B.i_g++) {
      motion_controller_withPIC_B.ix0_tmp = 21 * motion_controller_withPIC_B.i_g;
      motion_controller_withPIC_B.k_b = static_cast<uint8_T>(mrows);
      memcpy(&obj->QR[motion_controller_withPIC_B.ix0_tmp],
             &A[motion_controller_withPIC_B.ix0_tmp], static_cast<uint32_T>
             ((motion_controller_withPIC_B.k_b +
               motion_controller_withPIC_B.ix0_tmp) -
              motion_controller_withPIC_B.ix0_tmp) * sizeof(real_T));
    }

    guard1 = true;
  } else if (motion_controller_withPIC_B.k_b == 0) {
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
    motion_controller_withPIC_B.k_b = (ncols / 4) << 2;
    motion_controller_withPIC_B.ix0_tmp = motion_controller_withPIC_B.k_b - 4;
    for (motion_controller_withPIC_B.i_g = 0; motion_controller_withPIC_B.i_g <=
         motion_controller_withPIC_B.ix0_tmp; motion_controller_withPIC_B.i_g +=
         4) {
      tmp = _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32
        (motion_controller_withPIC_B.i_g), _mm_loadu_si128((const __m128i *)
        &offsets[0])), _mm_set1_epi32(1));
      _mm_storeu_si128((__m128i *)&obj->jpvt[motion_controller_withPIC_B.i_g],
                       tmp);
    }

    for (motion_controller_withPIC_B.i_g = motion_controller_withPIC_B.k_b;
         motion_controller_withPIC_B.i_g < ncols;
         motion_controller_withPIC_B.i_g++) {
      obj->jpvt[motion_controller_withPIC_B.i_g] =
        motion_controller_withPIC_B.i_g + 1;
    }

    if (mrows <= ncols) {
      motion_controller_withPIC_B.k_b = mrows;
    } else {
      motion_controller_withPIC_B.k_b = ncols;
    }

    obj->minRowCol = motion_controller_withPIC_B.k_b;
    memset(&obj->tau[0], 0, 21U * sizeof(real_T));
    if (motion_controller_withPIC_B.k_b >= 1) {
      memset(&obj->tau[0], 0, 21U * sizeof(real_T));
      motion_controller__qrf_nGv3LI5p(obj->QR, mrows, ncols,
        motion_controller_withPIC_B.k_b, obj->tau);
    }
  }
}

// Function for MATLAB Function: '<S49>/solvex'
void motion_controller_withPIC::motion_controlle_xgemv_7iafTBwP(int32_T m, const
  real_T A[840], const real_T x[1701], real_T y[81])
{
  for (motion_controller_withPIC_B.b_iy_a = 0;
       motion_controller_withPIC_B.b_iy_a <= 38;
       motion_controller_withPIC_B.b_iy_a += 2) {
    __m128d tmp;
    tmp = _mm_loadu_pd(&y[motion_controller_withPIC_B.b_iy_a]);
    _mm_storeu_pd(&y[motion_controller_withPIC_B.b_iy_a], _mm_mul_pd(tmp,
      _mm_set1_pd(-1.0)));
  }

  for (motion_controller_withPIC_B.b_iy_a = 0;
       motion_controller_withPIC_B.b_iy_a <= 819;
       motion_controller_withPIC_B.b_iy_a += 21) {
    motion_controller_withPIC_B.c_l = 0.0;
    motion_controller_withPIC_B.b_fm = motion_controller_withPIC_B.b_iy_a + m;
    for (motion_controller_withPIC_B.ia_gr = motion_controller_withPIC_B.b_iy_a
         + 1; motion_controller_withPIC_B.ia_gr <=
         motion_controller_withPIC_B.b_fm; motion_controller_withPIC_B.ia_gr++)
    {
      motion_controller_withPIC_B.c_l += x[(motion_controller_withPIC_B.ia_gr -
        motion_controller_withPIC_B.b_iy_a) - 1] *
        A[motion_controller_withPIC_B.ia_gr - 1];
    }

    motion_controller_withPIC_B.ia_gr = div_nde_s32_floor
      (motion_controller_withPIC_B.b_iy_a, 21);
    y[motion_controller_withPIC_B.ia_gr] += motion_controller_withPIC_B.c_l;
  }
}

// Function for MATLAB Function: '<S49>/solvex'
void motion_controller_withPIC::motion_controlle_xgemv_vyHQ2Zvi(int32_T m, const
  real_T A[840], const real_T x[1701], real_T y[81])
{
  for (motion_controller_withPIC_B.b_iy_b = 0;
       motion_controller_withPIC_B.b_iy_b <= 38;
       motion_controller_withPIC_B.b_iy_b += 2) {
    __m128d tmp;
    tmp = _mm_loadu_pd(&y[motion_controller_withPIC_B.b_iy_b]);
    _mm_storeu_pd(&y[motion_controller_withPIC_B.b_iy_b], _mm_mul_pd(tmp,
      _mm_set1_pd(-1.0)));
  }

  for (motion_controller_withPIC_B.b_iy_b = 0;
       motion_controller_withPIC_B.b_iy_b <= 819;
       motion_controller_withPIC_B.b_iy_b += 21) {
    motion_controller_withPIC_B.c_jz = 0.0;
    motion_controller_withPIC_B.b_p = motion_controller_withPIC_B.b_iy_b + m;
    for (motion_controller_withPIC_B.ia_p = motion_controller_withPIC_B.b_iy_b +
         1; motion_controller_withPIC_B.ia_p <= motion_controller_withPIC_B.b_p;
         motion_controller_withPIC_B.ia_p++) {
      motion_controller_withPIC_B.c_jz += x[(motion_controller_withPIC_B.ia_p -
        motion_controller_withPIC_B.b_iy_b) + 80] *
        A[motion_controller_withPIC_B.ia_p - 1];
    }

    motion_controller_withPIC_B.ia_p = div_nde_s32_floor
      (motion_controller_withPIC_B.b_iy_b, 21);
    y[motion_controller_withPIC_B.ia_p] += motion_controller_withPIC_B.c_jz;
  }
}

// Function for MATLAB Function: '<S49>/solvex'
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
  motion_controller_withPIC_B.mWConstr_tmp_tmp_i = workingset->nActiveConstr - 1;
  motion_controller_withPIC_B.nVar_tmp_tmp_b = workingset->nVar;
  nonDegenerateWset = true;
  if (workingset->nActiveConstr != 0) {
    for (motion_controller_withPIC_B.idx_m = 0;
         motion_controller_withPIC_B.idx_m <=
         motion_controller_withPIC_B.mWConstr_tmp_tmp_i;
         motion_controller_withPIC_B.idx_m++) {
      workspace[motion_controller_withPIC_B.idx_m] = workingset->
        bwset[motion_controller_withPIC_B.idx_m];
      workspace[motion_controller_withPIC_B.idx_m + 81] = workingset->
        bwset[motion_controller_withPIC_B.idx_m];
    }

    if (workingset->nActiveConstr != 0) {
      motion_controller_withPIC_B.d_g = (workingset->nActiveConstr - 1) * 21 + 1;
      for (motion_controller_withPIC_B.iac_n = 1;
           motion_controller_withPIC_B.iac_n <= motion_controller_withPIC_B.d_g;
           motion_controller_withPIC_B.iac_n += 21) {
        motion_controller_withPIC_B.c_k = 0.0;
        motion_controller_withPIC_B.jBcol_c = (motion_controller_withPIC_B.iac_n
          + motion_controller_withPIC_B.nVar_tmp_tmp_b) - 1;
        for (motion_controller_withPIC_B.idx_m =
             motion_controller_withPIC_B.iac_n;
             motion_controller_withPIC_B.idx_m <=
             motion_controller_withPIC_B.jBcol_c;
             motion_controller_withPIC_B.idx_m++) {
          motion_controller_withPIC_B.c_k += workingset->
            ATwset[motion_controller_withPIC_B.idx_m - 1] *
            xCurrent[motion_controller_withPIC_B.idx_m -
            motion_controller_withPIC_B.iac_n];
        }

        motion_controller_withPIC_B.idx_m = div_nde_s32_floor
          (motion_controller_withPIC_B.iac_n - 1, 21);
        workspace[motion_controller_withPIC_B.idx_m] -=
          motion_controller_withPIC_B.c_k;
      }
    }

    if (workingset->nActiveConstr >= workingset->nVar) {
      motion_controller_withPIC_B.d_g = static_cast<uint8_T>(workingset->nVar);
      for (motion_controller_withPIC_B.idx_m = 0;
           motion_controller_withPIC_B.idx_m < motion_controller_withPIC_B.d_g;
           motion_controller_withPIC_B.idx_m++) {
        motion_controller_withPIC_B.jBcol_c = 21 *
          motion_controller_withPIC_B.idx_m;
        for (motion_controller_withPIC_B.iac_n = 0;
             motion_controller_withPIC_B.iac_n <=
             motion_controller_withPIC_B.mWConstr_tmp_tmp_i;
             motion_controller_withPIC_B.iac_n++) {
          qrmanager->QR[motion_controller_withPIC_B.iac_n +
            motion_controller_withPIC_B.jBcol_c] = workingset->ATwset[21 *
            motion_controller_withPIC_B.iac_n +
            motion_controller_withPIC_B.idx_m];
        }
      }

      qrmanager->usedPivoting = false;
      qrmanager->mrows = workingset->nActiveConstr;
      qrmanager->ncols = workingset->nVar;
      motion_controller_withPIC_B.jBcol_c = (static_cast<uint8_T>
        (workingset->nVar) / 4) << 2;
      motion_controller_withPIC_B.iAcol_d = motion_controller_withPIC_B.jBcol_c
        - 4;
      for (motion_controller_withPIC_B.idx_m = 0;
           motion_controller_withPIC_B.idx_m <=
           motion_controller_withPIC_B.iAcol_d;
           motion_controller_withPIC_B.idx_m += 4) {
        tmp_1 = _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32
          (motion_controller_withPIC_B.idx_m), _mm_loadu_si128((const __m128i *)
          &offsets[0])), _mm_set1_epi32(1));
        _mm_storeu_si128((__m128i *)&qrmanager->
                         jpvt[motion_controller_withPIC_B.idx_m], tmp_1);
      }

      for (motion_controller_withPIC_B.idx_m =
           motion_controller_withPIC_B.jBcol_c;
           motion_controller_withPIC_B.idx_m < motion_controller_withPIC_B.d_g;
           motion_controller_withPIC_B.idx_m++) {
        qrmanager->jpvt[motion_controller_withPIC_B.idx_m] =
          motion_controller_withPIC_B.idx_m + 1;
      }

      if (workingset->nActiveConstr <= workingset->nVar) {
        motion_controller_withPIC_B.idx_m = workingset->nActiveConstr;
      } else {
        motion_controller_withPIC_B.idx_m = workingset->nVar;
      }

      qrmanager->minRowCol = motion_controller_withPIC_B.idx_m;
      memcpy(&motion_controller_withPIC_B.B_g[0], &qrmanager->QR[0], 1701U *
             sizeof(real_T));
      memset(&qrmanager->tau[0], 0, 21U * sizeof(real_T));
      if (motion_controller_withPIC_B.idx_m >= 1) {
        memset(&qrmanager->tau[0], 0, 21U * sizeof(real_T));
        motion_controller__qrf_nGv3LI5p(motion_controller_withPIC_B.B_g,
          workingset->nActiveConstr, workingset->nVar,
          motion_controller_withPIC_B.idx_m, qrmanager->tau);
      }

      memcpy(&qrmanager->QR[0], &motion_controller_withPIC_B.B_g[0], 1701U *
             sizeof(real_T));
      motion_controller_w_computeQ__l(qrmanager, qrmanager->mrows);
      memcpy(&motion_controller_withPIC_B.B_g[0], &workspace[0], 1701U * sizeof
             (real_T));
      for (motion_controller_withPIC_B.idx_m = 0;
           motion_controller_withPIC_B.idx_m <= 81;
           motion_controller_withPIC_B.idx_m += 81) {
        motion_controller_withPIC_B.d_g = motion_controller_withPIC_B.idx_m +
          motion_controller_withPIC_B.nVar_tmp_tmp_b;
        for (motion_controller_withPIC_B.iac_n =
             motion_controller_withPIC_B.idx_m + 1;
             motion_controller_withPIC_B.iac_n <=
             motion_controller_withPIC_B.d_g; motion_controller_withPIC_B.iac_n
             ++) {
          workspace[motion_controller_withPIC_B.iac_n - 1] = 0.0;
        }
      }

      motion_controller_withPIC_B.jBcol_c = -1;
      for (motion_controller_withPIC_B.idx_m = 0;
           motion_controller_withPIC_B.idx_m <= 81;
           motion_controller_withPIC_B.idx_m += 81) {
        motion_controller_withPIC_B.iAcol_d = -1;
        motion_controller_withPIC_B.br_k = motion_controller_withPIC_B.idx_m +
          motion_controller_withPIC_B.nVar_tmp_tmp_b;
        for (motion_controller_withPIC_B.iac_n =
             motion_controller_withPIC_B.idx_m + 1;
             motion_controller_withPIC_B.iac_n <=
             motion_controller_withPIC_B.br_k; motion_controller_withPIC_B.iac_n
             ++) {
          motion_controller_withPIC_B.c_k = 0.0;
          for (motion_controller_withPIC_B.d_g = 0;
               motion_controller_withPIC_B.d_g <=
               motion_controller_withPIC_B.mWConstr_tmp_tmp_i;
               motion_controller_withPIC_B.d_g++) {
            motion_controller_withPIC_B.c_k += qrmanager->Q
              [(motion_controller_withPIC_B.d_g +
                motion_controller_withPIC_B.iAcol_d) + 1] *
              motion_controller_withPIC_B.B_g[(motion_controller_withPIC_B.d_g +
              motion_controller_withPIC_B.jBcol_c) + 1];
          }

          workspace[motion_controller_withPIC_B.iac_n - 1] +=
            motion_controller_withPIC_B.c_k;
          motion_controller_withPIC_B.iAcol_d += 21;
        }

        motion_controller_withPIC_B.jBcol_c += 81;
      }

      for (motion_controller_withPIC_B.mWConstr_tmp_tmp_i = 0;
           motion_controller_withPIC_B.mWConstr_tmp_tmp_i < 2;
           motion_controller_withPIC_B.mWConstr_tmp_tmp_i++) {
        motion_controller_withPIC_B.iAcol_d = 81 *
          motion_controller_withPIC_B.mWConstr_tmp_tmp_i - 1;
        for (motion_controller_withPIC_B.d_g =
             motion_controller_withPIC_B.nVar_tmp_tmp_b;
             motion_controller_withPIC_B.d_g >= 1;
             motion_controller_withPIC_B.d_g--) {
          motion_controller_withPIC_B.br_k = (motion_controller_withPIC_B.d_g -
            1) * 21;
          motion_controller_withPIC_B.idx_m = motion_controller_withPIC_B.d_g +
            motion_controller_withPIC_B.iAcol_d;
          motion_controller_withPIC_B.c_k =
            workspace[motion_controller_withPIC_B.idx_m];
          if (motion_controller_withPIC_B.c_k != 0.0) {
            workspace[motion_controller_withPIC_B.idx_m] =
              motion_controller_withPIC_B.c_k / qrmanager->QR
              [(motion_controller_withPIC_B.d_g +
                motion_controller_withPIC_B.br_k) - 1];
            motion_controller_withPIC_B.ar_c = static_cast<uint8_T>
              (motion_controller_withPIC_B.d_g - 1);
            for (motion_controller_withPIC_B.jBcol_c = 0;
                 motion_controller_withPIC_B.jBcol_c <
                 motion_controller_withPIC_B.ar_c;
                 motion_controller_withPIC_B.jBcol_c++) {
              motion_controller_withPIC_B.iac_n =
                (motion_controller_withPIC_B.jBcol_c +
                 motion_controller_withPIC_B.iAcol_d) + 1;
              workspace[motion_controller_withPIC_B.iac_n] -= qrmanager->
                QR[motion_controller_withPIC_B.jBcol_c +
                motion_controller_withPIC_B.br_k] *
                workspace[motion_controller_withPIC_B.idx_m];
            }
          }
        }
      }
    } else {
      motion_controller_wi_factorQR_c(qrmanager, workingset->ATwset,
        workingset->nVar, workingset->nActiveConstr);
      motion_controller_w_computeQ__l(qrmanager, qrmanager->minRowCol);
      for (motion_controller_withPIC_B.idx_m = 0;
           motion_controller_withPIC_B.idx_m < 2;
           motion_controller_withPIC_B.idx_m++) {
        motion_controller_withPIC_B.jBcol_c = 81 *
          motion_controller_withPIC_B.idx_m;
        for (motion_controller_withPIC_B.iac_n = 0;
             motion_controller_withPIC_B.iac_n <=
             motion_controller_withPIC_B.mWConstr_tmp_tmp_i;
             motion_controller_withPIC_B.iac_n++) {
          motion_controller_withPIC_B.iAcol_d = 21 *
            motion_controller_withPIC_B.iac_n;
          motion_controller_withPIC_B.br_k = motion_controller_withPIC_B.iac_n +
            motion_controller_withPIC_B.jBcol_c;
          motion_controller_withPIC_B.c_k =
            workspace[motion_controller_withPIC_B.br_k];
          motion_controller_withPIC_B.ar_c = static_cast<uint8_T>
            (motion_controller_withPIC_B.iac_n);
          for (motion_controller_withPIC_B.d_g = 0;
               motion_controller_withPIC_B.d_g <
               motion_controller_withPIC_B.ar_c; motion_controller_withPIC_B.d_g
               ++) {
            motion_controller_withPIC_B.c_k -= qrmanager->
              QR[motion_controller_withPIC_B.d_g +
              motion_controller_withPIC_B.iAcol_d] *
              workspace[motion_controller_withPIC_B.d_g +
              motion_controller_withPIC_B.jBcol_c];
          }

          workspace[motion_controller_withPIC_B.br_k] =
            motion_controller_withPIC_B.c_k / qrmanager->
            QR[motion_controller_withPIC_B.iac_n +
            motion_controller_withPIC_B.iAcol_d];
        }
      }

      memcpy(&motion_controller_withPIC_B.B_g[0], &workspace[0], 1701U * sizeof
             (real_T));
      for (motion_controller_withPIC_B.idx_m = 0;
           motion_controller_withPIC_B.idx_m <= 81;
           motion_controller_withPIC_B.idx_m += 81) {
        motion_controller_withPIC_B.d_g = motion_controller_withPIC_B.idx_m +
          motion_controller_withPIC_B.nVar_tmp_tmp_b;
        for (motion_controller_withPIC_B.iac_n =
             motion_controller_withPIC_B.idx_m + 1;
             motion_controller_withPIC_B.iac_n <=
             motion_controller_withPIC_B.d_g; motion_controller_withPIC_B.iac_n
             ++) {
          workspace[motion_controller_withPIC_B.iac_n - 1] = 0.0;
        }
      }

      motion_controller_withPIC_B.br_k = 1;
      for (motion_controller_withPIC_B.idx_m = 0;
           motion_controller_withPIC_B.idx_m <= 81;
           motion_controller_withPIC_B.idx_m += 81) {
        motion_controller_withPIC_B.ar_c = -1;
        motion_controller_withPIC_B.h_j = motion_controller_withPIC_B.br_k +
          motion_controller_withPIC_B.mWConstr_tmp_tmp_i;
        for (motion_controller_withPIC_B.iac_n =
             motion_controller_withPIC_B.br_k; motion_controller_withPIC_B.iac_n
             <= motion_controller_withPIC_B.h_j;
             motion_controller_withPIC_B.iac_n++) {
          motion_controller_withPIC_B.l_m = motion_controller_withPIC_B.idx_m +
            motion_controller_withPIC_B.nVar_tmp_tmp_b;
          motion_controller_withPIC_B.jBcol_c =
            ((((motion_controller_withPIC_B.l_m -
                motion_controller_withPIC_B.idx_m) / 2) << 1) +
             motion_controller_withPIC_B.idx_m) + 1;
          motion_controller_withPIC_B.iAcol_d =
            motion_controller_withPIC_B.jBcol_c - 2;
          for (motion_controller_withPIC_B.d_g =
               motion_controller_withPIC_B.idx_m + 1;
               motion_controller_withPIC_B.d_g <=
               motion_controller_withPIC_B.iAcol_d;
               motion_controller_withPIC_B.d_g += 2) {
            tmp = _mm_loadu_pd(&qrmanager->Q[(motion_controller_withPIC_B.ar_c +
              motion_controller_withPIC_B.d_g) -
                               motion_controller_withPIC_B.idx_m]);
            tmp_0 = _mm_loadu_pd(&workspace[motion_controller_withPIC_B.d_g - 1]);
            _mm_storeu_pd(&workspace[motion_controller_withPIC_B.d_g - 1],
                          _mm_add_pd(_mm_mul_pd(tmp, _mm_set1_pd
              (motion_controller_withPIC_B.B_g[motion_controller_withPIC_B.iac_n
               - 1])), tmp_0));
          }

          for (motion_controller_withPIC_B.d_g =
               motion_controller_withPIC_B.jBcol_c;
               motion_controller_withPIC_B.d_g <=
               motion_controller_withPIC_B.l_m; motion_controller_withPIC_B.d_g
               ++) {
            workspace[motion_controller_withPIC_B.d_g - 1] += qrmanager->Q
              [(motion_controller_withPIC_B.ar_c +
                motion_controller_withPIC_B.d_g) -
              motion_controller_withPIC_B.idx_m] *
              motion_controller_withPIC_B.B_g[motion_controller_withPIC_B.iac_n
              - 1];
          }

          motion_controller_withPIC_B.ar_c += 21;
        }

        motion_controller_withPIC_B.br_k += 81;
      }
    }

    motion_controller_withPIC_B.mWConstr_tmp_tmp_i = 0;
    do {
      exitg1 = 0;
      if (motion_controller_withPIC_B.mWConstr_tmp_tmp_i <= static_cast<uint8_T>
          (motion_controller_withPIC_B.nVar_tmp_tmp_b) - 1) {
        if (rtIsInf(workspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_i]) ||
            rtIsNaN(workspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_i]))
        {
          nonDegenerateWset = false;
          exitg1 = 1;
        } else {
          motion_controller_withPIC_B.c_k =
            workspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_i + 81];
          if (rtIsInf(motion_controller_withPIC_B.c_k) || rtIsNaN
              (motion_controller_withPIC_B.c_k)) {
            nonDegenerateWset = false;
            exitg1 = 1;
          } else {
            motion_controller_withPIC_B.mWConstr_tmp_tmp_i++;
          }
        }
      } else {
        motion_controller_withPIC_B.jBcol_c =
          (motion_controller_withPIC_B.nVar_tmp_tmp_b / 2) << 1;
        motion_controller_withPIC_B.iAcol_d =
          motion_controller_withPIC_B.jBcol_c - 2;
        for (motion_controller_withPIC_B.mWConstr_tmp_tmp_i = 0;
             motion_controller_withPIC_B.mWConstr_tmp_tmp_i <=
             motion_controller_withPIC_B.iAcol_d;
             motion_controller_withPIC_B.mWConstr_tmp_tmp_i += 2) {
          tmp = _mm_loadu_pd
            (&workspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_i]);
          tmp_0 = _mm_loadu_pd
            (&xCurrent[motion_controller_withPIC_B.mWConstr_tmp_tmp_i]);
          _mm_storeu_pd
            (&workspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_i],
             _mm_add_pd(tmp, tmp_0));
        }

        for (motion_controller_withPIC_B.mWConstr_tmp_tmp_i =
             motion_controller_withPIC_B.jBcol_c;
             motion_controller_withPIC_B.mWConstr_tmp_tmp_i <
             motion_controller_withPIC_B.nVar_tmp_tmp_b;
             motion_controller_withPIC_B.mWConstr_tmp_tmp_i++) {
          workspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_i] +=
            xCurrent[motion_controller_withPIC_B.mWConstr_tmp_tmp_i];
        }

        if (workingset->probType == 2) {
          motion_controller_withPIC_B.c_k = 0.0;
          memcpy(&workingset->maxConstrWorkspace[0], &workingset->bineq[0], 40U *
                 sizeof(real_T));
          motion_controlle_xgemv_7iafTBwP(20, workingset->Aineq, workspace,
            workingset->maxConstrWorkspace);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp_i = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_i < 40;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_i++) {
            motion_controller_withPIC_B.u1_h = workingset->
              maxConstrWorkspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_i]
              - workspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_i + 20];
            workingset->
              maxConstrWorkspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_i]
              = motion_controller_withPIC_B.u1_h;
            if ((!(motion_controller_withPIC_B.c_k >=
                   motion_controller_withPIC_B.u1_h)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1_h))) {
              motion_controller_withPIC_B.c_k = motion_controller_withPIC_B.u1_h;
            }
          }
        } else {
          motion_controller_withPIC_B.c_k = 0.0;
          memcpy(&workingset->maxConstrWorkspace[0], &workingset->bineq[0], 40U *
                 sizeof(real_T));
          motion_controlle_xgemv_7iafTBwP(workingset->nVar, workingset->Aineq,
            workspace, workingset->maxConstrWorkspace);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp_i = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_i < 40;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_i++) {
            motion_controller_withPIC_B.u1_h = workingset->
              maxConstrWorkspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_i];
            if ((!(motion_controller_withPIC_B.c_k >=
                   motion_controller_withPIC_B.u1_h)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1_h))) {
              motion_controller_withPIC_B.c_k = motion_controller_withPIC_B.u1_h;
            }
          }
        }

        if (workingset->sizes[3] > 0) {
          motion_controller_withPIC_B.idx_m = static_cast<uint8_T>
            (workingset->sizes[3]);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp_i = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_i <
               motion_controller_withPIC_B.idx_m;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_i++) {
            motion_controller_withPIC_B.u1_h = -workspace[workingset->
              indexLB[motion_controller_withPIC_B.mWConstr_tmp_tmp_i] - 1] -
              workingset->lb[workingset->
              indexLB[motion_controller_withPIC_B.mWConstr_tmp_tmp_i] - 1];
            if ((!(motion_controller_withPIC_B.c_k >=
                   motion_controller_withPIC_B.u1_h)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1_h))) {
              motion_controller_withPIC_B.c_k = motion_controller_withPIC_B.u1_h;
            }
          }
        }

        if (workingset->sizes[4] > 0) {
          motion_controller_withPIC_B.idx_m = static_cast<uint8_T>
            (workingset->sizes[4]);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp_i = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_i <
               motion_controller_withPIC_B.idx_m;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_i++) {
            motion_controller_withPIC_B.u1_h = workspace[workingset->
              indexUB[motion_controller_withPIC_B.mWConstr_tmp_tmp_i] - 1] -
              workingset->ub[workingset->
              indexUB[motion_controller_withPIC_B.mWConstr_tmp_tmp_i] - 1];
            if ((!(motion_controller_withPIC_B.c_k >=
                   motion_controller_withPIC_B.u1_h)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1_h))) {
              motion_controller_withPIC_B.c_k = motion_controller_withPIC_B.u1_h;
            }
          }
        }

        if (workingset->sizes[0] > 0) {
          motion_controller_withPIC_B.idx_m = static_cast<uint8_T>
            (workingset->sizes[0]);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp_i = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_i <
               motion_controller_withPIC_B.idx_m;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_i++) {
            motion_controller_withPIC_B.u1_h = fabs(workspace
              [workingset->
              indexFixed[motion_controller_withPIC_B.mWConstr_tmp_tmp_i] - 1] -
              workingset->ub[workingset->
              indexFixed[motion_controller_withPIC_B.mWConstr_tmp_tmp_i] - 1]);
            if ((!(motion_controller_withPIC_B.c_k >=
                   motion_controller_withPIC_B.u1_h)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1_h))) {
              motion_controller_withPIC_B.c_k = motion_controller_withPIC_B.u1_h;
            }
          }
        }

        if (workingset->probType == 2) {
          motion_controller_withPIC_B.d_v_i = 0.0;
          memcpy(&workingset->maxConstrWorkspace[0], &workingset->bineq[0], 40U *
                 sizeof(real_T));
          motion_controlle_xgemv_vyHQ2Zvi(20, workingset->Aineq, workspace,
            workingset->maxConstrWorkspace);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp_i = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_i < 40;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_i++) {
            motion_controller_withPIC_B.u1_h = workingset->
              maxConstrWorkspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_i]
              - workspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_i + 101];
            workingset->
              maxConstrWorkspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_i]
              = motion_controller_withPIC_B.u1_h;
            if ((!(motion_controller_withPIC_B.d_v_i >=
                   motion_controller_withPIC_B.u1_h)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1_h))) {
              motion_controller_withPIC_B.d_v_i =
                motion_controller_withPIC_B.u1_h;
            }
          }
        } else {
          motion_controller_withPIC_B.d_v_i = 0.0;
          memcpy(&workingset->maxConstrWorkspace[0], &workingset->bineq[0], 40U *
                 sizeof(real_T));
          motion_controlle_xgemv_vyHQ2Zvi(workingset->nVar, workingset->Aineq,
            workspace, workingset->maxConstrWorkspace);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp_i = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_i < 40;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_i++) {
            motion_controller_withPIC_B.u1_h = workingset->
              maxConstrWorkspace[motion_controller_withPIC_B.mWConstr_tmp_tmp_i];
            if ((!(motion_controller_withPIC_B.d_v_i >=
                   motion_controller_withPIC_B.u1_h)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1_h))) {
              motion_controller_withPIC_B.d_v_i =
                motion_controller_withPIC_B.u1_h;
            }
          }
        }

        if (workingset->sizes[3] > 0) {
          motion_controller_withPIC_B.idx_m = static_cast<uint8_T>
            (workingset->sizes[3]);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp_i = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_i <
               motion_controller_withPIC_B.idx_m;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_i++) {
            motion_controller_withPIC_B.u1_h = -workspace[workingset->
              indexLB[motion_controller_withPIC_B.mWConstr_tmp_tmp_i] + 80] -
              workingset->lb[workingset->
              indexLB[motion_controller_withPIC_B.mWConstr_tmp_tmp_i] - 1];
            if ((!(motion_controller_withPIC_B.d_v_i >=
                   motion_controller_withPIC_B.u1_h)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1_h))) {
              motion_controller_withPIC_B.d_v_i =
                motion_controller_withPIC_B.u1_h;
            }
          }
        }

        if (workingset->sizes[4] > 0) {
          motion_controller_withPIC_B.idx_m = static_cast<uint8_T>
            (workingset->sizes[4]);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp_i = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_i <
               motion_controller_withPIC_B.idx_m;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_i++) {
            motion_controller_withPIC_B.u1_h = workspace[workingset->
              indexUB[motion_controller_withPIC_B.mWConstr_tmp_tmp_i] + 80] -
              workingset->ub[workingset->
              indexUB[motion_controller_withPIC_B.mWConstr_tmp_tmp_i] - 1];
            if ((!(motion_controller_withPIC_B.d_v_i >=
                   motion_controller_withPIC_B.u1_h)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1_h))) {
              motion_controller_withPIC_B.d_v_i =
                motion_controller_withPIC_B.u1_h;
            }
          }
        }

        if (workingset->sizes[0] > 0) {
          motion_controller_withPIC_B.idx_m = static_cast<uint8_T>
            (workingset->sizes[0]);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp_i = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_i <
               motion_controller_withPIC_B.idx_m;
               motion_controller_withPIC_B.mWConstr_tmp_tmp_i++) {
            motion_controller_withPIC_B.u1_h = fabs(workspace
              [workingset->
              indexFixed[motion_controller_withPIC_B.mWConstr_tmp_tmp_i] + 80] -
              workingset->ub[workingset->
              indexFixed[motion_controller_withPIC_B.mWConstr_tmp_tmp_i] - 1]);
            if ((!(motion_controller_withPIC_B.d_v_i >=
                   motion_controller_withPIC_B.u1_h)) && (!rtIsNaN
                 (motion_controller_withPIC_B.u1_h))) {
              motion_controller_withPIC_B.d_v_i =
                motion_controller_withPIC_B.u1_h;
            }
          }
        }

        if ((motion_controller_withPIC_B.c_k <= 2.2204460492503131E-16) ||
            (motion_controller_withPIC_B.c_k < motion_controller_withPIC_B.d_v_i))
        {
          motion_controller_withPIC_B.mWConstr_tmp_tmp_i = static_cast<uint8_T>
            (motion_controller_withPIC_B.nVar_tmp_tmp_b);
          memcpy(&xCurrent[0], &workspace[0], static_cast<uint32_T>
                 (motion_controller_withPIC_B.mWConstr_tmp_tmp_i) * sizeof
                 (real_T));
        } else {
          motion_controller_withPIC_B.mWConstr_tmp_tmp_i = static_cast<uint8_T>
            (motion_controller_withPIC_B.nVar_tmp_tmp_b);
          memcpy(&xCurrent[0], &workspace[81], static_cast<uint32_T>
                 (motion_controller_withPIC_B.mWConstr_tmp_tmp_i) * sizeof
                 (real_T));
        }

        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }

  return nonDegenerateWset;
}

// Function for MATLAB Function: '<S49>/solvex'
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

// Function for MATLAB Function: '<S49>/solvex'
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
  motion_controller_withPIC_B.i_d = workingset->nWConstr[0];
  motion_controller_withPIC_B.idx_row_a = 0;
  if (workingset->nWConstr[0] > 0) {
    motion_controller_withPIC_B.idxEndIneq_c = static_cast<uint8_T>
      (workingset->nWConstr[0]);
    motion_controller_withPIC_B.d_tmp = static_cast<uint8_T>(workingset->nVar);
    for (motion_controller_withPIC_B.idx_row_a = 0;
         motion_controller_withPIC_B.idx_row_a <
         motion_controller_withPIC_B.idxEndIneq_c;
         motion_controller_withPIC_B.idx_row_a++) {
      for (motion_controller_withPIC_B.idxStartIneq_d = 0;
           motion_controller_withPIC_B.idxStartIneq_d <
           motion_controller_withPIC_B.d_tmp;
           motion_controller_withPIC_B.idxStartIneq_d++) {
        qrmanager->QR[motion_controller_withPIC_B.idx_row_a + 21 *
          motion_controller_withPIC_B.idxStartIneq_d] = workingset->ATwset[21 *
          motion_controller_withPIC_B.idx_row_a +
          motion_controller_withPIC_B.idxStartIneq_d];
      }
    }

    motion_controller_withPIC_B.idx_row_a = motion_ComputeNumDependentEq__d
      (qrmanager, workingset->bwset, workingset->nWConstr[0], workingset->nVar);
    if (motion_controller_withPIC_B.idx_row_a > 0) {
      for (motion_controller_withPIC_B.idxStartIneq_d = 0;
           motion_controller_withPIC_B.idxStartIneq_d <
           motion_controller_withPIC_B.idxEndIneq_c;
           motion_controller_withPIC_B.idxStartIneq_d++) {
        motion_controller_withPIC_B.iy0_tmp_a = 21 *
          motion_controller_withPIC_B.idxStartIneq_d;
        memcpy(&qrmanager->QR[motion_controller_withPIC_B.iy0_tmp_a],
               &workingset->ATwset[motion_controller_withPIC_B.iy0_tmp_a],
               static_cast<uint32_T>((motion_controller_withPIC_B.d_tmp +
                 motion_controller_withPIC_B.iy0_tmp_a) -
                motion_controller_withPIC_B.iy0_tmp_a) * sizeof(real_T));
      }

      for (motion_controller_withPIC_B.idxStartIneq_d = 0;
           motion_controller_withPIC_B.idxStartIneq_d <
           motion_controller_withPIC_B.i_d;
           motion_controller_withPIC_B.idxStartIneq_d++) {
        qrmanager->jpvt[motion_controller_withPIC_B.idxStartIneq_d] = 1;
      }

      motion_controller_withPIC_B.idxEndIneq_c = workingset->nWConstr[0] + 1;
      if (motion_controller_withPIC_B.idxEndIneq_c <=
          motion_controller_withPIC_B.i_d) {
        memset(&qrmanager->jpvt[motion_controller_withPIC_B.idxEndIneq_c + -1],
               0, static_cast<uint32_T>((motion_controller_withPIC_B.i_d -
                 motion_controller_withPIC_B.idxEndIneq_c) + 1) * sizeof(int32_T));
      }

      motion_controller_w_factorQRE_c(qrmanager, workingset->nVar,
        workingset->nWConstr[0]);
      for (motion_controller_withPIC_B.idxStartIneq_d = 0;
           motion_controller_withPIC_B.idxStartIneq_d <
           motion_controller_withPIC_B.idx_row_a;
           motion_controller_withPIC_B.idxStartIneq_d++) {
        memspace->workspace_int[motion_controller_withPIC_B.idxStartIneq_d] =
          qrmanager->jpvt[(motion_controller_withPIC_B.i_d -
                           motion_controller_withPIC_B.idx_row_a) +
          motion_controller_withPIC_B.idxStartIneq_d];
      }

      countsort_JblpZJs7(memspace->workspace_int,
                         motion_controller_withPIC_B.idx_row_a,
                         memspace->workspace_sort, 1, workingset->nWConstr[0]);
      for (motion_controller_withPIC_B.i_d =
           motion_controller_withPIC_B.idx_row_a;
           motion_controller_withPIC_B.i_d >= 1; motion_controller_withPIC_B.i_d
           --) {
        motion_control_removeEqConstr_i(workingset, memspace->
          workspace_int[motion_controller_withPIC_B.i_d - 1]);
      }
    }
  }

  if ((motion_controller_withPIC_B.idx_row_a != -1) &&
      (workingset->nActiveConstr <= 21)) {
    motion_c_RemoveDependentIneq__e(workingset, qrmanager, memspace, 100.0);
    motion_controller_withPIC_B.okWorkingSet_g = motio_feasibleX0ForWorkingSet_c
      (memspace->workspace_double, solution->xstar, workingset, qrmanager);
    guard1 = false;
    if (!motion_controller_withPIC_B.okWorkingSet_g) {
      motion_c_RemoveDependentIneq__e(workingset, qrmanager, memspace, 1000.0);
      motion_controller_withPIC_B.okWorkingSet_g =
        motio_feasibleX0ForWorkingSet_c(memspace->workspace_double,
        solution->xstar, workingset, qrmanager);
      if (!motion_controller_withPIC_B.okWorkingSet_g) {
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
    motion_controller_withPIC_B.idx_row_a = workingset->nWConstr[0] +
      workingset->nWConstr[1];
    motion_controller_withPIC_B.idxStartIneq_d =
      motion_controller_withPIC_B.idx_row_a + 1;
    motion_controller_withPIC_B.idxEndIneq_c = workingset->nActiveConstr;
    for (motion_controller_withPIC_B.i_d =
         motion_controller_withPIC_B.idxStartIneq_d;
         motion_controller_withPIC_B.i_d <=
         motion_controller_withPIC_B.idxEndIneq_c;
         motion_controller_withPIC_B.i_d++) {
      workingset->isActiveConstr[(workingset->isActiveIdx[workingset->
        Wid[motion_controller_withPIC_B.i_d - 1] - 1] + workingset->
        Wlocalidx[motion_controller_withPIC_B.i_d - 1]) - 2] = false;
    }

    workingset->nWConstr[2] = 0;
    workingset->nWConstr[3] = 0;
    workingset->nWConstr[4] = 0;
    workingset->nActiveConstr = motion_controller_withPIC_B.idx_row_a;
  }
}

// Function for MATLAB Function: '<S49>/solvex'
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

// Function for MATLAB Function: '<S49>/solvex'
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

// Function for MATLAB Function: '<S49>/solvex'
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

// Function for MATLAB Function: '<S49>/solvex'
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

// Function for MATLAB Function: '<S48>/solvex'
void motion_controller_withPIC::motion_controlle_xrotg_ds3XgDMS(real_T *a,
  real_T *b, real_T *c, real_T *s)
{
  motion_controller_withPIC_B.roe = *b;
  motion_controller_withPIC_B.absa = fabs(*a);
  motion_controller_withPIC_B.absb = fabs(*b);
  if (motion_controller_withPIC_B.absa > motion_controller_withPIC_B.absb) {
    motion_controller_withPIC_B.roe = *a;
  }

  motion_controller_withPIC_B.scale_c = motion_controller_withPIC_B.absa +
    motion_controller_withPIC_B.absb;
  if (motion_controller_withPIC_B.scale_c == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *a = 0.0;
    *b = 0.0;
  } else {
    motion_controller_withPIC_B.ads = motion_controller_withPIC_B.absa /
      motion_controller_withPIC_B.scale_c;
    motion_controller_withPIC_B.bds = motion_controller_withPIC_B.absb /
      motion_controller_withPIC_B.scale_c;
    motion_controller_withPIC_B.scale_c *= sqrt(motion_controller_withPIC_B.ads *
      motion_controller_withPIC_B.ads + motion_controller_withPIC_B.bds *
      motion_controller_withPIC_B.bds);
    if (motion_controller_withPIC_B.roe < 0.0) {
      motion_controller_withPIC_B.scale_c = -motion_controller_withPIC_B.scale_c;
    }

    *c = *a / motion_controller_withPIC_B.scale_c;
    *s = *b / motion_controller_withPIC_B.scale_c;
    if (motion_controller_withPIC_B.absa > motion_controller_withPIC_B.absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }

    *a = motion_controller_withPIC_B.scale_c;
  }
}

// Function for MATLAB Function: '<S49>/solvex'
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

// Function for MATLAB Function: '<S49>/solvex'
void motion_controller_withPIC::motion_controlle_fullColLDL2__a
  (sTy13TWZ7KObOACj8wDaLQC_motio_T *obj, int32_T NColsRemain, real_T REG_PRIMAL)
{
  for (motion_controller_withPIC_B.lastDiag_o = 0;
       motion_controller_withPIC_B.lastDiag_o < NColsRemain;
       motion_controller_withPIC_B.lastDiag_o++) {
    motion_controller_withPIC_B.LD_diagOffset_i = 22 *
      motion_controller_withPIC_B.lastDiag_o;
    motion_controller_withPIC_B.temp_ft = obj->
      FMat[motion_controller_withPIC_B.LD_diagOffset_i];
    if (fabs(motion_controller_withPIC_B.temp_ft) <= obj->regTol_) {
      motion_controller_withPIC_B.temp_ft += REG_PRIMAL;
      obj->FMat[motion_controller_withPIC_B.LD_diagOffset_i] =
        motion_controller_withPIC_B.temp_ft;
    }

    motion_controller_withPIC_B.alpha1_m = -1.0 /
      motion_controller_withPIC_B.temp_ft;
    motion_controller_withPIC_B.subMatrixDim_l = (NColsRemain -
      motion_controller_withPIC_B.lastDiag_o) - 2;
    for (motion_controller_withPIC_B.b_k_p = 0;
         motion_controller_withPIC_B.b_k_p <=
         motion_controller_withPIC_B.subMatrixDim_l;
         motion_controller_withPIC_B.b_k_p++) {
      obj->workspace_[motion_controller_withPIC_B.b_k_p] = obj->FMat
        [(motion_controller_withPIC_B.LD_diagOffset_i +
          motion_controller_withPIC_B.b_k_p) + 1];
    }

    if (!(motion_controller_withPIC_B.alpha1_m == 0.0)) {
      motion_controller_withPIC_B.jA_o =
        motion_controller_withPIC_B.LD_diagOffset_i + 23;
      for (motion_controller_withPIC_B.b_k_p = 0;
           motion_controller_withPIC_B.b_k_p <=
           motion_controller_withPIC_B.subMatrixDim_l;
           motion_controller_withPIC_B.b_k_p++) {
        motion_controller_withPIC_B.temp_ft = obj->
          workspace_[motion_controller_withPIC_B.b_k_p];
        if (motion_controller_withPIC_B.temp_ft != 0.0) {
          motion_controller_withPIC_B.temp_ft *=
            motion_controller_withPIC_B.alpha1_m;
          motion_controller_withPIC_B.b_cm =
            motion_controller_withPIC_B.subMatrixDim_l +
            motion_controller_withPIC_B.jA_o;
          for (motion_controller_withPIC_B.ijA_o =
               motion_controller_withPIC_B.jA_o;
               motion_controller_withPIC_B.ijA_o <=
               motion_controller_withPIC_B.b_cm;
               motion_controller_withPIC_B.ijA_o++) {
            obj->FMat[motion_controller_withPIC_B.ijA_o - 1] += obj->
              workspace_[motion_controller_withPIC_B.ijA_o -
              motion_controller_withPIC_B.jA_o] *
              motion_controller_withPIC_B.temp_ft;
          }
        }

        motion_controller_withPIC_B.jA_o += 21;
      }
    }

    motion_controller_withPIC_B.alpha1_m = 1.0 / obj->
      FMat[motion_controller_withPIC_B.LD_diagOffset_i];
    motion_controller_withPIC_B.b_k_p =
      motion_controller_withPIC_B.LD_diagOffset_i +
      motion_controller_withPIC_B.subMatrixDim_l;
    motion_controller_withPIC_B.ijA_o = (((((motion_controller_withPIC_B.b_k_p -
      motion_controller_withPIC_B.LD_diagOffset_i) + 1) / 2) << 1) +
      motion_controller_withPIC_B.LD_diagOffset_i) + 2;
    motion_controller_withPIC_B.jA_o = motion_controller_withPIC_B.ijA_o - 2;
    for (motion_controller_withPIC_B.subMatrixDim_l =
         motion_controller_withPIC_B.LD_diagOffset_i + 2;
         motion_controller_withPIC_B.subMatrixDim_l <=
         motion_controller_withPIC_B.jA_o;
         motion_controller_withPIC_B.subMatrixDim_l += 2) {
      __m128d tmp;
      tmp = _mm_loadu_pd(&obj->FMat[motion_controller_withPIC_B.subMatrixDim_l -
                         1]);
      _mm_storeu_pd(&obj->FMat[motion_controller_withPIC_B.subMatrixDim_l - 1],
                    _mm_mul_pd(tmp, _mm_set1_pd
        (motion_controller_withPIC_B.alpha1_m)));
    }

    for (motion_controller_withPIC_B.subMatrixDim_l =
         motion_controller_withPIC_B.ijA_o;
         motion_controller_withPIC_B.subMatrixDim_l <=
         motion_controller_withPIC_B.b_k_p + 2;
         motion_controller_withPIC_B.subMatrixDim_l++) {
      obj->FMat[motion_controller_withPIC_B.subMatrixDim_l - 1] *=
        motion_controller_withPIC_B.alpha1_m;
    }
  }

  motion_controller_withPIC_B.lastDiag_o = (NColsRemain - 1) * 22;
  if (fabs(obj->FMat[motion_controller_withPIC_B.lastDiag_o]) <= obj->regTol_) {
    obj->FMat[motion_controller_withPIC_B.lastDiag_o] += REG_PRIMAL;
  }
}

// Function for MATLAB Function: '<S49>/solvex'
void motion_controller_withPIC::motion_control_compute_deltax_o(const real_T H
  [400], sYqpSPVJXu9aOn60zG4DpzD_motio_T *solution,
  s3cSGkBdKxRj6Qn3zsJRowG_motio_T *memspace, const
  sIZAIOglGM5dPDQlNukc9SD_motio_T *qrmanager, sTy13TWZ7KObOACj8wDaLQC_motio_T
  *cholmanager, const s3PrFoa9w5ssw8XLEJooNqH_motio_T *objective)
{
  __m128d tmp;
  __m128d tmp_0;
  int32_T exitg1;
  motion_controller_withPIC_B.nVar_e = qrmanager->mrows - 1;
  motion_controller_withPIC_B.mNull_tmp_i = qrmanager->mrows - qrmanager->ncols;
  if (motion_controller_withPIC_B.mNull_tmp_i <= 0) {
    if (motion_controller_withPIC_B.nVar_e >= 0) {
      memset(&solution->searchDir[0], 0, static_cast<uint32_T>
             (motion_controller_withPIC_B.nVar_e + 1) * sizeof(real_T));
    }
  } else {
    motion_controller_withPIC_B.b_ar_b = (qrmanager->mrows / 2) << 1;
    motion_controller_withPIC_B.vectorUB_a = motion_controller_withPIC_B.b_ar_b
      - 2;
    for (motion_controller_withPIC_B.A_maxDiag_idx_f = 0;
         motion_controller_withPIC_B.A_maxDiag_idx_f <=
         motion_controller_withPIC_B.vectorUB_a;
         motion_controller_withPIC_B.A_maxDiag_idx_f += 2) {
      tmp_0 = _mm_loadu_pd(&objective->
                           grad[motion_controller_withPIC_B.A_maxDiag_idx_f]);
      _mm_storeu_pd(&solution->
                    searchDir[motion_controller_withPIC_B.A_maxDiag_idx_f],
                    _mm_mul_pd(tmp_0, _mm_set1_pd(-1.0)));
    }

    for (motion_controller_withPIC_B.A_maxDiag_idx_f =
         motion_controller_withPIC_B.b_ar_b;
         motion_controller_withPIC_B.A_maxDiag_idx_f <=
         motion_controller_withPIC_B.nVar_e;
         motion_controller_withPIC_B.A_maxDiag_idx_f++) {
      solution->searchDir[motion_controller_withPIC_B.A_maxDiag_idx_f] =
        -objective->grad[motion_controller_withPIC_B.A_maxDiag_idx_f];
    }

    if (qrmanager->ncols <= 0) {
      if (objective->objtype == 3) {
        motion_controller_withPIC_B.temp_dj = 1.4901161193847656E-6 *
          static_cast<real_T>(qrmanager->mrows);
        cholmanager->ndims = qrmanager->mrows;
        for (motion_controller_withPIC_B.mNull_tmp_i = 0;
             motion_controller_withPIC_B.mNull_tmp_i <=
             motion_controller_withPIC_B.nVar_e;
             motion_controller_withPIC_B.mNull_tmp_i++) {
          motion_controller_withPIC_B.nullStartIdx_i =
            (motion_controller_withPIC_B.nVar_e + 1) *
            motion_controller_withPIC_B.mNull_tmp_i;
          motion_controller_withPIC_B.nVars_a = 21 *
            motion_controller_withPIC_B.mNull_tmp_i;
          for (motion_controller_withPIC_B.A_maxDiag_idx_f = 0;
               motion_controller_withPIC_B.A_maxDiag_idx_f <=
               motion_controller_withPIC_B.nVar_e;
               motion_controller_withPIC_B.A_maxDiag_idx_f++) {
            cholmanager->FMat[motion_controller_withPIC_B.nVars_a +
              motion_controller_withPIC_B.A_maxDiag_idx_f] =
              H[motion_controller_withPIC_B.A_maxDiag_idx_f +
              motion_controller_withPIC_B.nullStartIdx_i];
          }
        }

        if (qrmanager->mrows < 1) {
          motion_controller_withPIC_B.A_maxDiag_idx_f = -1;
        } else {
          motion_controller_withPIC_B.A_maxDiag_idx_f = 0;
          if (qrmanager->mrows > 1) {
            motion_controller_withPIC_B.smax_n = fabs(cholmanager->FMat[0]);
            for (motion_controller_withPIC_B.mNull_tmp_i = 2;
                 motion_controller_withPIC_B.mNull_tmp_i <=
                 motion_controller_withPIC_B.nVar_e + 1;
                 motion_controller_withPIC_B.mNull_tmp_i++) {
              motion_controller_withPIC_B.s_gv = fabs(cholmanager->FMat
                [(motion_controller_withPIC_B.mNull_tmp_i - 1) * 22]);
              if (motion_controller_withPIC_B.s_gv >
                  motion_controller_withPIC_B.smax_n) {
                motion_controller_withPIC_B.A_maxDiag_idx_f =
                  motion_controller_withPIC_B.mNull_tmp_i - 1;
                motion_controller_withPIC_B.smax_n =
                  motion_controller_withPIC_B.s_gv;
              }
            }
          }
        }

        motion_controller_withPIC_B.smax_n = fabs(cholmanager->FMat[21 *
          motion_controller_withPIC_B.A_maxDiag_idx_f +
          motion_controller_withPIC_B.A_maxDiag_idx_f]) * 2.2204460492503131E-16;
        motion_controller_withPIC_B.s_gv = fabs
          (motion_controller_withPIC_B.temp_dj);
        if (motion_controller_withPIC_B.smax_n >=
            motion_controller_withPIC_B.s_gv) {
          cholmanager->regTol_ = motion_controller_withPIC_B.smax_n;
        } else {
          cholmanager->regTol_ = motion_controller_withPIC_B.s_gv;
        }

        motion_controlle_fullColLDL2__a(cholmanager, qrmanager->mrows,
          motion_controller_withPIC_B.temp_dj);
        if (cholmanager->ConvexCheck) {
          motion_controller_withPIC_B.mNull_tmp_i = 0;
          do {
            exitg1 = 0;
            if (motion_controller_withPIC_B.mNull_tmp_i <=
                motion_controller_withPIC_B.nVar_e) {
              if (cholmanager->FMat[21 * motion_controller_withPIC_B.mNull_tmp_i
                  + motion_controller_withPIC_B.mNull_tmp_i] <= 0.0) {
                cholmanager->info = -motion_controller_withPIC_B.mNull_tmp_i - 1;
                exitg1 = 1;
              } else {
                motion_controller_withPIC_B.mNull_tmp_i++;
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
          motion_controller_withPIC_B.nVar_e = cholmanager->ndims - 1;
          if (cholmanager->ndims != 0) {
            for (motion_controller_withPIC_B.mNull_tmp_i = 0;
                 motion_controller_withPIC_B.mNull_tmp_i <=
                 motion_controller_withPIC_B.nVar_e;
                 motion_controller_withPIC_B.mNull_tmp_i++) {
              motion_controller_withPIC_B.nullStartIdx_i =
                motion_controller_withPIC_B.mNull_tmp_i * 21 +
                motion_controller_withPIC_B.mNull_tmp_i;
              motion_controller_withPIC_B.nVars_a =
                motion_controller_withPIC_B.nVar_e -
                motion_controller_withPIC_B.mNull_tmp_i;
              for (motion_controller_withPIC_B.A_maxDiag_idx_f = 0;
                   motion_controller_withPIC_B.A_maxDiag_idx_f <
                   motion_controller_withPIC_B.nVars_a;
                   motion_controller_withPIC_B.A_maxDiag_idx_f++) {
                motion_controller_withPIC_B.b_A_maxDiag_idx_k =
                  (motion_controller_withPIC_B.A_maxDiag_idx_f +
                   motion_controller_withPIC_B.mNull_tmp_i) + 1;
                solution->
                  searchDir[motion_controller_withPIC_B.b_A_maxDiag_idx_k] -=
                  cholmanager->FMat[(motion_controller_withPIC_B.A_maxDiag_idx_f
                                     + motion_controller_withPIC_B.nullStartIdx_i)
                  + 1] * solution->
                  searchDir[motion_controller_withPIC_B.mNull_tmp_i];
              }
            }
          }

          motion_controller_withPIC_B.nVar_e = cholmanager->ndims;
          for (motion_controller_withPIC_B.mNull_tmp_i = 0;
               motion_controller_withPIC_B.mNull_tmp_i <
               motion_controller_withPIC_B.nVar_e;
               motion_controller_withPIC_B.mNull_tmp_i++) {
            solution->searchDir[motion_controller_withPIC_B.mNull_tmp_i] /=
              cholmanager->FMat[21 * motion_controller_withPIC_B.mNull_tmp_i +
              motion_controller_withPIC_B.mNull_tmp_i];
          }

          if (cholmanager->ndims != 0) {
            for (motion_controller_withPIC_B.mNull_tmp_i =
                 motion_controller_withPIC_B.nVar_e;
                 motion_controller_withPIC_B.mNull_tmp_i >= 1;
                 motion_controller_withPIC_B.mNull_tmp_i--) {
              motion_controller_withPIC_B.nullStartIdx_i =
                (motion_controller_withPIC_B.mNull_tmp_i - 1) * 21;
              motion_controller_withPIC_B.temp_dj = solution->
                searchDir[motion_controller_withPIC_B.mNull_tmp_i - 1];
              for (motion_controller_withPIC_B.A_maxDiag_idx_f =
                   motion_controller_withPIC_B.nVar_e;
                   motion_controller_withPIC_B.A_maxDiag_idx_f >=
                   motion_controller_withPIC_B.mNull_tmp_i + 1;
                   motion_controller_withPIC_B.A_maxDiag_idx_f--) {
                motion_controller_withPIC_B.temp_dj -= cholmanager->FMat
                  [(motion_controller_withPIC_B.nullStartIdx_i +
                    motion_controller_withPIC_B.A_maxDiag_idx_f) - 1] *
                  solution->
                  searchDir[motion_controller_withPIC_B.A_maxDiag_idx_f - 1];
              }

              solution->searchDir[motion_controller_withPIC_B.mNull_tmp_i - 1] =
                motion_controller_withPIC_B.temp_dj;
            }
          }
        }
      }
    } else {
      motion_controller_withPIC_B.A_maxDiag_idx_f = 21 * qrmanager->ncols;
      motion_controller_withPIC_B.nullStartIdx_i =
        motion_controller_withPIC_B.A_maxDiag_idx_f + 1;
      if (objective->objtype == 5) {
        for (motion_controller_withPIC_B.nullStartIdx_i = 0;
             motion_controller_withPIC_B.nullStartIdx_i <
             motion_controller_withPIC_B.mNull_tmp_i;
             motion_controller_withPIC_B.nullStartIdx_i++) {
          memspace->workspace_double[motion_controller_withPIC_B.nullStartIdx_i]
            = -qrmanager->Q[(qrmanager->ncols +
                             motion_controller_withPIC_B.nullStartIdx_i) * 21 +
            motion_controller_withPIC_B.nVar_e];
        }

        xgemv_CxqfdDRY(qrmanager->mrows, motion_controller_withPIC_B.mNull_tmp_i,
                       qrmanager->Q, motion_controller_withPIC_B.A_maxDiag_idx_f
                       + 1, memspace->workspace_double, solution->searchDir);
      } else {
        if (objective->objtype == 3) {
          motion_controller_withPIC_B.nVars_a = qrmanager->mrows;
          if ((qrmanager->mrows != 0) &&
              (motion_controller_withPIC_B.mNull_tmp_i != 0)) {
            motion_controller_withPIC_B.br_j =
              motion_controller_withPIC_B.A_maxDiag_idx_f;
            motion_controller_withPIC_B.lastColC_c =
              (motion_controller_withPIC_B.mNull_tmp_i - 1) * 81;
            for (motion_controller_withPIC_B.b_A_maxDiag_idx_k = 0;
                 motion_controller_withPIC_B.b_A_maxDiag_idx_k <=
                 motion_controller_withPIC_B.lastColC_c;
                 motion_controller_withPIC_B.b_A_maxDiag_idx_k += 81) {
              motion_controller_withPIC_B.e_ix_a =
                motion_controller_withPIC_B.b_A_maxDiag_idx_k +
                motion_controller_withPIC_B.nVars_a;
              for (motion_controller_withPIC_B.ic_a =
                   motion_controller_withPIC_B.b_A_maxDiag_idx_k + 1;
                   motion_controller_withPIC_B.ic_a <=
                   motion_controller_withPIC_B.e_ix_a;
                   motion_controller_withPIC_B.ic_a++) {
                memspace->workspace_double[motion_controller_withPIC_B.ic_a - 1]
                  = 0.0;
              }
            }

            for (motion_controller_withPIC_B.b_A_maxDiag_idx_k = 0;
                 motion_controller_withPIC_B.b_A_maxDiag_idx_k <=
                 motion_controller_withPIC_B.lastColC_c;
                 motion_controller_withPIC_B.b_A_maxDiag_idx_k += 81) {
              motion_controller_withPIC_B.ar_l = -1;
              motion_controller_withPIC_B.h_i = motion_controller_withPIC_B.br_j
                + motion_controller_withPIC_B.nVars_a;
              for (motion_controller_withPIC_B.ic_a =
                   motion_controller_withPIC_B.br_j + 1;
                   motion_controller_withPIC_B.ic_a <=
                   motion_controller_withPIC_B.h_i;
                   motion_controller_withPIC_B.ic_a++) {
                motion_controller_withPIC_B.i_ok =
                  motion_controller_withPIC_B.b_A_maxDiag_idx_k +
                  motion_controller_withPIC_B.nVars_a;
                motion_controller_withPIC_B.b_ar_b =
                  ((((motion_controller_withPIC_B.i_ok -
                      motion_controller_withPIC_B.b_A_maxDiag_idx_k) / 2) << 1)
                   + motion_controller_withPIC_B.b_A_maxDiag_idx_k) + 1;
                motion_controller_withPIC_B.vectorUB_a =
                  motion_controller_withPIC_B.b_ar_b - 2;
                for (motion_controller_withPIC_B.e_ix_a =
                     motion_controller_withPIC_B.b_A_maxDiag_idx_k + 1;
                     motion_controller_withPIC_B.e_ix_a <=
                     motion_controller_withPIC_B.vectorUB_a;
                     motion_controller_withPIC_B.e_ix_a += 2) {
                  tmp_0 = _mm_loadu_pd(&H[(motion_controller_withPIC_B.ar_l +
                    motion_controller_withPIC_B.e_ix_a) -
                                       motion_controller_withPIC_B.b_A_maxDiag_idx_k]);
                  tmp = _mm_loadu_pd(&memspace->
                                     workspace_double[motion_controller_withPIC_B.e_ix_a
                                     - 1]);
                  _mm_storeu_pd(&memspace->
                                workspace_double[motion_controller_withPIC_B.e_ix_a
                                - 1], _mm_add_pd(_mm_mul_pd(tmp_0, _mm_set1_pd
                    (qrmanager->Q[motion_controller_withPIC_B.ic_a - 1])), tmp));
                }

                for (motion_controller_withPIC_B.e_ix_a =
                     motion_controller_withPIC_B.b_ar_b;
                     motion_controller_withPIC_B.e_ix_a <=
                     motion_controller_withPIC_B.i_ok;
                     motion_controller_withPIC_B.e_ix_a++) {
                  memspace->workspace_double[motion_controller_withPIC_B.e_ix_a
                    - 1] += H[(motion_controller_withPIC_B.ar_l +
                               motion_controller_withPIC_B.e_ix_a) -
                    motion_controller_withPIC_B.b_A_maxDiag_idx_k] *
                    qrmanager->Q[motion_controller_withPIC_B.ic_a - 1];
                }

                motion_controller_withPIC_B.ar_l +=
                  motion_controller_withPIC_B.nVars_a;
              }

              motion_controller_withPIC_B.br_j += 21;
            }
          }

          if (motion_controller_withPIC_B.mNull_tmp_i != 0) {
            motion_controller_withPIC_B.br_j =
              (motion_controller_withPIC_B.mNull_tmp_i - 1) * 21;
            for (motion_controller_withPIC_B.b_A_maxDiag_idx_k = 0;
                 motion_controller_withPIC_B.b_A_maxDiag_idx_k <=
                 motion_controller_withPIC_B.br_j;
                 motion_controller_withPIC_B.b_A_maxDiag_idx_k += 21) {
              motion_controller_withPIC_B.e_ix_a =
                motion_controller_withPIC_B.b_A_maxDiag_idx_k +
                motion_controller_withPIC_B.mNull_tmp_i;
              for (motion_controller_withPIC_B.ic_a =
                   motion_controller_withPIC_B.b_A_maxDiag_idx_k + 1;
                   motion_controller_withPIC_B.ic_a <=
                   motion_controller_withPIC_B.e_ix_a;
                   motion_controller_withPIC_B.ic_a++) {
                cholmanager->FMat[motion_controller_withPIC_B.ic_a - 1] = 0.0;
              }
            }

            motion_controller_withPIC_B.lastColC_c = -1;
            for (motion_controller_withPIC_B.b_A_maxDiag_idx_k = 0;
                 motion_controller_withPIC_B.b_A_maxDiag_idx_k <=
                 motion_controller_withPIC_B.br_j;
                 motion_controller_withPIC_B.b_A_maxDiag_idx_k += 21) {
              motion_controller_withPIC_B.b_ar_b =
                motion_controller_withPIC_B.A_maxDiag_idx_f;
              motion_controller_withPIC_B.vectorUB_a =
                motion_controller_withPIC_B.b_A_maxDiag_idx_k +
                motion_controller_withPIC_B.mNull_tmp_i;
              for (motion_controller_withPIC_B.ic_a =
                   motion_controller_withPIC_B.b_A_maxDiag_idx_k + 1;
                   motion_controller_withPIC_B.ic_a <=
                   motion_controller_withPIC_B.vectorUB_a;
                   motion_controller_withPIC_B.ic_a++) {
                motion_controller_withPIC_B.temp_dj = 0.0;
                for (motion_controller_withPIC_B.e_ix_a = 0;
                     motion_controller_withPIC_B.e_ix_a <
                     motion_controller_withPIC_B.nVars_a;
                     motion_controller_withPIC_B.e_ix_a++) {
                  motion_controller_withPIC_B.temp_dj +=
                    memspace->workspace_double
                    [(motion_controller_withPIC_B.e_ix_a +
                      motion_controller_withPIC_B.lastColC_c) + 1] *
                    qrmanager->Q[motion_controller_withPIC_B.e_ix_a +
                    motion_controller_withPIC_B.b_ar_b];
                }

                cholmanager->FMat[motion_controller_withPIC_B.ic_a - 1] +=
                  motion_controller_withPIC_B.temp_dj;
                motion_controller_withPIC_B.b_ar_b += 21;
              }

              motion_controller_withPIC_B.lastColC_c += 81;
            }
          }
        }

        motion_controller_withPIC_B.temp_dj = 1.4901161193847656E-6 *
          static_cast<real_T>(motion_controller_withPIC_B.mNull_tmp_i);
        cholmanager->ndims = motion_controller_withPIC_B.mNull_tmp_i;
        motion_controller_withPIC_B.b_A_maxDiag_idx_k = 0;
        if (motion_controller_withPIC_B.mNull_tmp_i > 1) {
          motion_controller_withPIC_B.smax_n = fabs(cholmanager->FMat[0]);
          for (motion_controller_withPIC_B.nVars_a = 2;
               motion_controller_withPIC_B.nVars_a <=
               motion_controller_withPIC_B.mNull_tmp_i;
               motion_controller_withPIC_B.nVars_a++) {
            motion_controller_withPIC_B.s_gv = fabs(cholmanager->FMat
              [(motion_controller_withPIC_B.nVars_a - 1) * 22]);
            if (motion_controller_withPIC_B.s_gv >
                motion_controller_withPIC_B.smax_n) {
              motion_controller_withPIC_B.b_A_maxDiag_idx_k =
                motion_controller_withPIC_B.nVars_a - 1;
              motion_controller_withPIC_B.smax_n =
                motion_controller_withPIC_B.s_gv;
            }
          }
        }

        motion_controller_withPIC_B.smax_n = fabs(cholmanager->FMat[21 *
          motion_controller_withPIC_B.b_A_maxDiag_idx_k +
          motion_controller_withPIC_B.b_A_maxDiag_idx_k]) *
          2.2204460492503131E-16;
        if (motion_controller_withPIC_B.smax_n >=
            motion_controller_withPIC_B.temp_dj) {
          cholmanager->regTol_ = motion_controller_withPIC_B.smax_n;
        } else {
          cholmanager->regTol_ = motion_controller_withPIC_B.temp_dj;
        }

        motion_controlle_fullColLDL2__a(cholmanager,
          motion_controller_withPIC_B.mNull_tmp_i,
          motion_controller_withPIC_B.temp_dj);
        if (cholmanager->ConvexCheck) {
          motion_controller_withPIC_B.nVars_a = 0;
          do {
            exitg1 = 0;
            if (motion_controller_withPIC_B.nVars_a <=
                motion_controller_withPIC_B.mNull_tmp_i - 1) {
              if (cholmanager->FMat[21 * motion_controller_withPIC_B.nVars_a +
                  motion_controller_withPIC_B.nVars_a] <= 0.0) {
                cholmanager->info = -motion_controller_withPIC_B.nVars_a - 1;
                exitg1 = 1;
              } else {
                motion_controller_withPIC_B.nVars_a++;
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
                   (motion_controller_withPIC_B.mNull_tmp_i) * sizeof(real_T));
            motion_controller_withPIC_B.ic_a =
              ((motion_controller_withPIC_B.mNull_tmp_i - 1) * 21 +
               motion_controller_withPIC_B.A_maxDiag_idx_f) + 1;
            for (motion_controller_withPIC_B.nVars_a =
                 motion_controller_withPIC_B.nullStartIdx_i;
                 motion_controller_withPIC_B.nVars_a <=
                 motion_controller_withPIC_B.ic_a;
                 motion_controller_withPIC_B.nVars_a += 21) {
              motion_controller_withPIC_B.temp_dj = 0.0;
              motion_controller_withPIC_B.e_ix_a =
                motion_controller_withPIC_B.nVars_a +
                motion_controller_withPIC_B.nVar_e;
              for (motion_controller_withPIC_B.b_A_maxDiag_idx_k =
                   motion_controller_withPIC_B.nVars_a;
                   motion_controller_withPIC_B.b_A_maxDiag_idx_k <=
                   motion_controller_withPIC_B.e_ix_a;
                   motion_controller_withPIC_B.b_A_maxDiag_idx_k++) {
                motion_controller_withPIC_B.temp_dj += qrmanager->
                  Q[motion_controller_withPIC_B.b_A_maxDiag_idx_k - 1] *
                  objective->grad[motion_controller_withPIC_B.b_A_maxDiag_idx_k
                  - motion_controller_withPIC_B.nVars_a];
              }

              motion_controller_withPIC_B.b_A_maxDiag_idx_k = div_nde_s32_floor
                ((motion_controller_withPIC_B.nVars_a -
                  motion_controller_withPIC_B.A_maxDiag_idx_f) - 1, 21);
              memspace->
                workspace_double[motion_controller_withPIC_B.b_A_maxDiag_idx_k] -=
                motion_controller_withPIC_B.temp_dj;
            }
          }

          motion_controller_withPIC_B.nVars_a = cholmanager->ndims - 1;
          if (cholmanager->ndims != 0) {
            for (motion_controller_withPIC_B.nVar_e = 0;
                 motion_controller_withPIC_B.nVar_e <=
                 motion_controller_withPIC_B.nVars_a;
                 motion_controller_withPIC_B.nVar_e++) {
              motion_controller_withPIC_B.b_A_maxDiag_idx_k =
                motion_controller_withPIC_B.nVar_e * 21 +
                motion_controller_withPIC_B.nVar_e;
              motion_controller_withPIC_B.ic_a =
                motion_controller_withPIC_B.nVars_a -
                motion_controller_withPIC_B.nVar_e;
              for (motion_controller_withPIC_B.nullStartIdx_i = 0;
                   motion_controller_withPIC_B.nullStartIdx_i <
                   motion_controller_withPIC_B.ic_a;
                   motion_controller_withPIC_B.nullStartIdx_i++) {
                motion_controller_withPIC_B.e_ix_a =
                  (motion_controller_withPIC_B.nullStartIdx_i +
                   motion_controller_withPIC_B.nVar_e) + 1;
                memspace->workspace_double[motion_controller_withPIC_B.e_ix_a] -=
                  cholmanager->FMat[(motion_controller_withPIC_B.nullStartIdx_i
                                     + motion_controller_withPIC_B.b_A_maxDiag_idx_k)
                  + 1] * memspace->
                  workspace_double[motion_controller_withPIC_B.nVar_e];
              }
            }
          }

          motion_controller_withPIC_B.nVars_a = cholmanager->ndims;
          for (motion_controller_withPIC_B.nVar_e = 0;
               motion_controller_withPIC_B.nVar_e <
               motion_controller_withPIC_B.nVars_a;
               motion_controller_withPIC_B.nVar_e++) {
            memspace->workspace_double[motion_controller_withPIC_B.nVar_e] /=
              cholmanager->FMat[21 * motion_controller_withPIC_B.nVar_e +
              motion_controller_withPIC_B.nVar_e];
          }

          if (cholmanager->ndims != 0) {
            for (motion_controller_withPIC_B.nVar_e =
                 motion_controller_withPIC_B.nVars_a;
                 motion_controller_withPIC_B.nVar_e >= 1;
                 motion_controller_withPIC_B.nVar_e--) {
              motion_controller_withPIC_B.b_A_maxDiag_idx_k =
                (motion_controller_withPIC_B.nVar_e - 1) * 21;
              motion_controller_withPIC_B.temp_dj = memspace->
                workspace_double[motion_controller_withPIC_B.nVar_e - 1];
              for (motion_controller_withPIC_B.nullStartIdx_i =
                   motion_controller_withPIC_B.nVars_a;
                   motion_controller_withPIC_B.nullStartIdx_i >=
                   motion_controller_withPIC_B.nVar_e + 1;
                   motion_controller_withPIC_B.nullStartIdx_i--) {
                motion_controller_withPIC_B.temp_dj -= cholmanager->FMat
                  [(motion_controller_withPIC_B.b_A_maxDiag_idx_k +
                    motion_controller_withPIC_B.nullStartIdx_i) - 1] *
                  memspace->
                  workspace_double[motion_controller_withPIC_B.nullStartIdx_i -
                  1];
              }

              memspace->workspace_double[motion_controller_withPIC_B.nVar_e - 1]
                = motion_controller_withPIC_B.temp_dj;
            }
          }

          xgemv_CxqfdDRY(qrmanager->mrows,
                         motion_controller_withPIC_B.mNull_tmp_i, qrmanager->Q,
                         motion_controller_withPIC_B.A_maxDiag_idx_f + 1,
                         memspace->workspace_double, solution->searchDir);
        }
      }
    }
  }
}

// Function for MATLAB Function: '<S49>/solvex'
real_T motion_controller_withPIC::motion_controlle_xnrm2_rY1rIeLd(int32_T n,
  const real_T x[21])
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[0]);
    } else {
      motion_controller_withPIC_B.scale_h = 3.3121686421112381E-170;
      motion_controller_withPIC_B.b_m = static_cast<uint8_T>(n);
      for (motion_controller_withPIC_B.k_f = 0; motion_controller_withPIC_B.k_f <
           motion_controller_withPIC_B.b_m; motion_controller_withPIC_B.k_f++) {
        motion_controller_withPIC_B.absxk_oc = fabs
          (x[motion_controller_withPIC_B.k_f]);
        if (motion_controller_withPIC_B.absxk_oc >
            motion_controller_withPIC_B.scale_h) {
          motion_controller_withPIC_B.t_h = motion_controller_withPIC_B.scale_h /
            motion_controller_withPIC_B.absxk_oc;
          y = y * motion_controller_withPIC_B.t_h *
            motion_controller_withPIC_B.t_h + 1.0;
          motion_controller_withPIC_B.scale_h =
            motion_controller_withPIC_B.absxk_oc;
        } else {
          motion_controller_withPIC_B.t_h = motion_controller_withPIC_B.absxk_oc
            / motion_controller_withPIC_B.scale_h;
          y += motion_controller_withPIC_B.t_h * motion_controller_withPIC_B.t_h;
        }
      }

      y = motion_controller_withPIC_B.scale_h * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S49>/solvex'
void motion_controller_withPIC::motion_controlle_xgemv_BberjsMK(int32_T m, const
  real_T A[840], const real_T x[21], real_T y[1701])
{
  for (motion_controller_withPIC_B.b_iy_k = 0;
       motion_controller_withPIC_B.b_iy_k <= 38;
       motion_controller_withPIC_B.b_iy_k += 2) {
    __m128d tmp;
    tmp = _mm_loadu_pd(&y[motion_controller_withPIC_B.b_iy_k]);
    _mm_storeu_pd(&y[motion_controller_withPIC_B.b_iy_k], _mm_mul_pd(tmp,
      _mm_set1_pd(-1.0)));
  }

  for (motion_controller_withPIC_B.b_iy_k = 0;
       motion_controller_withPIC_B.b_iy_k <= 819;
       motion_controller_withPIC_B.b_iy_k += 21) {
    motion_controller_withPIC_B.c_jy = 0.0;
    motion_controller_withPIC_B.b_ca = motion_controller_withPIC_B.b_iy_k + m;
    for (motion_controller_withPIC_B.ia_j = motion_controller_withPIC_B.b_iy_k +
         1; motion_controller_withPIC_B.ia_j <= motion_controller_withPIC_B.b_ca;
         motion_controller_withPIC_B.ia_j++) {
      motion_controller_withPIC_B.c_jy += x[(motion_controller_withPIC_B.ia_j -
        motion_controller_withPIC_B.b_iy_k) - 1] *
        A[motion_controller_withPIC_B.ia_j - 1];
    }

    motion_controller_withPIC_B.ia_j = div_nde_s32_floor
      (motion_controller_withPIC_B.b_iy_k, 21);
    y[motion_controller_withPIC_B.ia_j] += motion_controller_withPIC_B.c_jy;
  }
}

// Function for MATLAB Function: '<S49>/solvex'
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
  motion_controller_withPIC_B.p_max_e = 0.0;
  motion_controller_withPIC_B.denomTol_m = 2.2204460492503131E-13 *
    motion_controlle_xnrm2_rY1rIeLd(workingset_nVar, solution_searchDir);
  if (workingset_nWConstr[2] < 40) {
    memcpy(&workspace[0], &workingset_bineq[0], 40U * sizeof(real_T));
    motion_controlle_xgemv_BberjsMK(workingset_nVar, workingset_Aineq,
      solution_xstar, workspace);
    memset(&workspace[81], 0, 40U * sizeof(real_T));
    for (motion_controller_withPIC_B.k_ad = 0; motion_controller_withPIC_B.k_ad <=
         819; motion_controller_withPIC_B.k_ad += 21) {
      motion_controller_withPIC_B.b_c_j = 0.0;
      motion_controller_withPIC_B.d_gy = motion_controller_withPIC_B.k_ad +
        workingset_nVar;
      for (motion_controller_withPIC_B.ia_b = motion_controller_withPIC_B.k_ad +
           1; motion_controller_withPIC_B.ia_b <=
           motion_controller_withPIC_B.d_gy; motion_controller_withPIC_B.ia_b++)
      {
        motion_controller_withPIC_B.b_c_j += solution_searchDir
          [(motion_controller_withPIC_B.ia_b - motion_controller_withPIC_B.k_ad)
          - 1] * workingset_Aineq[motion_controller_withPIC_B.ia_b - 1];
      }

      motion_controller_withPIC_B.ia_b = div_nde_s32_floor
        (motion_controller_withPIC_B.k_ad, 21) + 81;
      workspace[motion_controller_withPIC_B.ia_b] +=
        motion_controller_withPIC_B.b_c_j;
    }

    for (motion_controller_withPIC_B.k_ad = 0; motion_controller_withPIC_B.k_ad <
         40; motion_controller_withPIC_B.k_ad++) {
      motion_controller_withPIC_B.workspace_e =
        workspace[motion_controller_withPIC_B.k_ad + 81];
      if ((motion_controller_withPIC_B.workspace_e >
           motion_controller_withPIC_B.denomTol_m) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[2] +
            motion_controller_withPIC_B.k_ad) - 1])) {
        motion_controller_withPIC_B.phaseOneCorrectionX_o =
          workspace[motion_controller_withPIC_B.k_ad];
        motion_controller_withPIC_B.b_c_j = fabs
          (motion_controller_withPIC_B.phaseOneCorrectionX_o - *toldelta);
        motion_controller_withPIC_B.phaseOneCorrectionP_a = (1.0E-8 -
          motion_controller_withPIC_B.phaseOneCorrectionX_o) + *toldelta;
        if ((motion_controller_withPIC_B.b_c_j <=
             motion_controller_withPIC_B.phaseOneCorrectionP_a) || rtIsNaN
            (motion_controller_withPIC_B.phaseOneCorrectionP_a)) {
          motion_controller_withPIC_B.phaseOneCorrectionP_a =
            motion_controller_withPIC_B.b_c_j;
        }

        motion_controller_withPIC_B.b_c_j =
          motion_controller_withPIC_B.phaseOneCorrectionP_a /
          motion_controller_withPIC_B.workspace_e;
        if ((motion_controller_withPIC_B.b_c_j <= *alpha) && (fabs
             (motion_controller_withPIC_B.workspace_e) >
             motion_controller_withPIC_B.p_max_e)) {
          *alpha = motion_controller_withPIC_B.b_c_j;
          *constrType = 3;
          *constrIdx = motion_controller_withPIC_B.k_ad + 1;
          *newBlocking = true;
        }

        motion_controller_withPIC_B.b_c_j = fabs
          (motion_controller_withPIC_B.phaseOneCorrectionX_o);
        if ((!(motion_controller_withPIC_B.b_c_j <= 1.0E-8 -
               motion_controller_withPIC_B.phaseOneCorrectionX_o)) && (!rtIsNaN
             (1.0E-8 - motion_controller_withPIC_B.phaseOneCorrectionX_o))) {
          motion_controller_withPIC_B.b_c_j = 1.0E-8 -
            motion_controller_withPIC_B.phaseOneCorrectionX_o;
        }

        motion_controller_withPIC_B.b_c_j /=
          motion_controller_withPIC_B.workspace_e;
        if (motion_controller_withPIC_B.b_c_j < *alpha) {
          *alpha = motion_controller_withPIC_B.b_c_j;
          *constrType = 3;
          *constrIdx = motion_controller_withPIC_B.k_ad + 1;
          *newBlocking = true;
          motion_controller_withPIC_B.p_max_e = fabs
            (motion_controller_withPIC_B.workspace_e);
        }
      }
    }
  }

  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    motion_controller_withPIC_B.phaseOneCorrectionX_o =
      solution_xstar[workingset_nVar - 1] * 0.0;
    motion_controller_withPIC_B.phaseOneCorrectionP_a =
      solution_searchDir[workingset_nVar - 1] * 0.0;
    motion_controller_withPIC_B.ia_b = workingset_sizes[3];
    for (motion_controller_withPIC_B.k_ad = 0; motion_controller_withPIC_B.k_ad <=
         motion_controller_withPIC_B.ia_b - 2; motion_controller_withPIC_B.k_ad
         ++) {
      motion_controller_withPIC_B.d_gy =
        workingset_indexLB[motion_controller_withPIC_B.k_ad];
      motion_controller_withPIC_B.pk_corrected_j =
        -solution_searchDir[motion_controller_withPIC_B.d_gy - 1] -
        motion_controller_withPIC_B.phaseOneCorrectionP_a;
      if ((motion_controller_withPIC_B.pk_corrected_j >
           motion_controller_withPIC_B.denomTol_m) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[3] +
            motion_controller_withPIC_B.k_ad) - 1])) {
        motion_controller_withPIC_B.workspace_e =
          -solution_xstar[motion_controller_withPIC_B.d_gy - 1] -
          workingset_lb[motion_controller_withPIC_B.d_gy - 1];
        motion_controller_withPIC_B.ratio_g =
          (motion_controller_withPIC_B.workspace_e - *toldelta) -
          motion_controller_withPIC_B.phaseOneCorrectionX_o;
        motion_controller_withPIC_B.b_c_j = fabs
          (motion_controller_withPIC_B.ratio_g);
        if ((!(motion_controller_withPIC_B.b_c_j <= 1.0E-8 -
               motion_controller_withPIC_B.ratio_g)) && (!rtIsNaN(1.0E-8 -
              motion_controller_withPIC_B.ratio_g))) {
          motion_controller_withPIC_B.b_c_j = 1.0E-8 -
            motion_controller_withPIC_B.ratio_g;
        }

        motion_controller_withPIC_B.b_c_j /=
          motion_controller_withPIC_B.pk_corrected_j;
        if ((motion_controller_withPIC_B.b_c_j <= *alpha) && (fabs
             (motion_controller_withPIC_B.pk_corrected_j) >
             motion_controller_withPIC_B.p_max_e)) {
          *alpha = motion_controller_withPIC_B.b_c_j;
          *constrType = 4;
          *constrIdx = motion_controller_withPIC_B.k_ad + 1;
          *newBlocking = true;
        }

        motion_controller_withPIC_B.ratio_g =
          motion_controller_withPIC_B.workspace_e -
          motion_controller_withPIC_B.phaseOneCorrectionX_o;
        motion_controller_withPIC_B.b_c_j = fabs
          (motion_controller_withPIC_B.ratio_g);
        if ((!(motion_controller_withPIC_B.b_c_j <= 1.0E-8 -
               motion_controller_withPIC_B.ratio_g)) && (!rtIsNaN(1.0E-8 -
              motion_controller_withPIC_B.ratio_g))) {
          motion_controller_withPIC_B.b_c_j = 1.0E-8 -
            motion_controller_withPIC_B.ratio_g;
        }

        motion_controller_withPIC_B.b_c_j /=
          motion_controller_withPIC_B.pk_corrected_j;
        if (motion_controller_withPIC_B.b_c_j < *alpha) {
          *alpha = motion_controller_withPIC_B.b_c_j;
          *constrType = 4;
          *constrIdx = motion_controller_withPIC_B.k_ad + 1;
          *newBlocking = true;
          motion_controller_withPIC_B.p_max_e = fabs
            (motion_controller_withPIC_B.pk_corrected_j);
        }
      }
    }

    motion_controller_withPIC_B.ia_b = workingset_indexLB[workingset_sizes[3] -
      1] - 1;
    motion_controller_withPIC_B.phaseOneCorrectionX_o =
      solution_searchDir[motion_controller_withPIC_B.ia_b];
    if ((-motion_controller_withPIC_B.phaseOneCorrectionX_o >
         motion_controller_withPIC_B.denomTol_m) && (!workingset_isActiveConstr
         [(workingset_isActiveIdx[3] + workingset_sizes[3]) - 2])) {
      motion_controller_withPIC_B.workspace_e =
        -solution_xstar[motion_controller_withPIC_B.ia_b] -
        workingset_lb[motion_controller_withPIC_B.ia_b];
      motion_controller_withPIC_B.ratio_g =
        motion_controller_withPIC_B.workspace_e - *toldelta;
      motion_controller_withPIC_B.b_c_j = fabs
        (motion_controller_withPIC_B.ratio_g);
      if ((!(motion_controller_withPIC_B.b_c_j <= 1.0E-8 -
             motion_controller_withPIC_B.ratio_g)) && (!rtIsNaN(1.0E-8 -
            motion_controller_withPIC_B.ratio_g))) {
        motion_controller_withPIC_B.b_c_j = 1.0E-8 -
          motion_controller_withPIC_B.ratio_g;
      }

      motion_controller_withPIC_B.b_c_j /=
        -motion_controller_withPIC_B.phaseOneCorrectionX_o;
      if ((motion_controller_withPIC_B.b_c_j <= *alpha) && (fabs
           (motion_controller_withPIC_B.phaseOneCorrectionX_o) >
           motion_controller_withPIC_B.p_max_e)) {
        *alpha = motion_controller_withPIC_B.b_c_j;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }

      motion_controller_withPIC_B.b_c_j = fabs
        (motion_controller_withPIC_B.workspace_e);
      if ((!(motion_controller_withPIC_B.b_c_j <= 1.0E-8 -
             motion_controller_withPIC_B.workspace_e)) && (!rtIsNaN(1.0E-8 -
            motion_controller_withPIC_B.workspace_e))) {
        motion_controller_withPIC_B.b_c_j = 1.0E-8 -
          motion_controller_withPIC_B.workspace_e;
      }

      motion_controller_withPIC_B.b_c_j /=
        -motion_controller_withPIC_B.phaseOneCorrectionX_o;
      if (motion_controller_withPIC_B.b_c_j < *alpha) {
        *alpha = motion_controller_withPIC_B.b_c_j;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
        motion_controller_withPIC_B.p_max_e = fabs
          (motion_controller_withPIC_B.phaseOneCorrectionX_o);
      }
    }
  }

  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    motion_controller_withPIC_B.phaseOneCorrectionX_o =
      solution_xstar[workingset_nVar - 1] * 0.0;
    motion_controller_withPIC_B.phaseOneCorrectionP_a =
      solution_searchDir[workingset_nVar - 1] * 0.0;
    motion_controller_withPIC_B.ia_b = static_cast<uint8_T>(workingset_sizes[4]);
    for (motion_controller_withPIC_B.k_ad = 0; motion_controller_withPIC_B.k_ad <
         motion_controller_withPIC_B.ia_b; motion_controller_withPIC_B.k_ad++) {
      motion_controller_withPIC_B.d_gy =
        workingset_indexUB[motion_controller_withPIC_B.k_ad];
      motion_controller_withPIC_B.pk_corrected_j =
        solution_searchDir[motion_controller_withPIC_B.d_gy - 1] -
        motion_controller_withPIC_B.phaseOneCorrectionP_a;
      if ((motion_controller_withPIC_B.pk_corrected_j >
           motion_controller_withPIC_B.denomTol_m) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[4] +
            motion_controller_withPIC_B.k_ad) - 1])) {
        motion_controller_withPIC_B.workspace_e =
          solution_xstar[motion_controller_withPIC_B.d_gy - 1] -
          workingset_ub[motion_controller_withPIC_B.d_gy - 1];
        motion_controller_withPIC_B.ratio_g =
          (motion_controller_withPIC_B.workspace_e - *toldelta) -
          motion_controller_withPIC_B.phaseOneCorrectionX_o;
        motion_controller_withPIC_B.b_c_j = fabs
          (motion_controller_withPIC_B.ratio_g);
        if ((!(motion_controller_withPIC_B.b_c_j <= 1.0E-8 -
               motion_controller_withPIC_B.ratio_g)) && (!rtIsNaN(1.0E-8 -
              motion_controller_withPIC_B.ratio_g))) {
          motion_controller_withPIC_B.b_c_j = 1.0E-8 -
            motion_controller_withPIC_B.ratio_g;
        }

        motion_controller_withPIC_B.b_c_j /=
          motion_controller_withPIC_B.pk_corrected_j;
        if ((motion_controller_withPIC_B.b_c_j <= *alpha) && (fabs
             (motion_controller_withPIC_B.pk_corrected_j) >
             motion_controller_withPIC_B.p_max_e)) {
          *alpha = motion_controller_withPIC_B.b_c_j;
          *constrType = 5;
          *constrIdx = motion_controller_withPIC_B.k_ad + 1;
          *newBlocking = true;
        }

        motion_controller_withPIC_B.ratio_g =
          motion_controller_withPIC_B.workspace_e -
          motion_controller_withPIC_B.phaseOneCorrectionX_o;
        motion_controller_withPIC_B.b_c_j = fabs
          (motion_controller_withPIC_B.ratio_g);
        if ((!(motion_controller_withPIC_B.b_c_j <= 1.0E-8 -
               motion_controller_withPIC_B.ratio_g)) && (!rtIsNaN(1.0E-8 -
              motion_controller_withPIC_B.ratio_g))) {
          motion_controller_withPIC_B.b_c_j = 1.0E-8 -
            motion_controller_withPIC_B.ratio_g;
        }

        motion_controller_withPIC_B.b_c_j /=
          motion_controller_withPIC_B.pk_corrected_j;
        if (motion_controller_withPIC_B.b_c_j < *alpha) {
          *alpha = motion_controller_withPIC_B.b_c_j;
          *constrType = 5;
          *constrIdx = motion_controller_withPIC_B.k_ad + 1;
          *newBlocking = true;
          motion_controller_withPIC_B.p_max_e = fabs
            (motion_controller_withPIC_B.pk_corrected_j);
        }
      }
    }
  }

  *toldelta += 6.608625846508183E-7;
  if (motion_controller_withPIC_B.p_max_e > 0.0) {
    motion_controller_withPIC_B.phaseOneCorrectionP_a = 6.608625846508183E-7 /
      motion_controller_withPIC_B.p_max_e;
    if (!(*alpha >= motion_controller_withPIC_B.phaseOneCorrectionP_a)) {
      *alpha = motion_controller_withPIC_B.phaseOneCorrectionP_a;
    }
  }

  *newBlocking = (((!*newBlocking) || (!(*alpha > 1.0))) && (*newBlocking));
  if (!(*alpha <= 1.0)) {
    *alpha = 1.0;
  }
}

// Function for MATLAB Function: '<S49>/solvex'
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
  motion_controller_withPIC_B.denomTol_e = 2.2204460492503131E-13 *
    motion_controlle_xnrm2_rY1rIeLd(workingset_nVar, solution_searchDir);
  if (workingset_nWConstr[2] < 40) {
    memcpy(&workspace[0], &workingset_bineq[0], 40U * sizeof(real_T));
    motion_controlle_xgemv_BberjsMK(workingset_nVar, workingset_Aineq,
      solution_xstar, workspace);
    memset(&workspace[81], 0, 40U * sizeof(real_T));
    for (motion_controller_withPIC_B.k_l = 0; motion_controller_withPIC_B.k_l <=
         819; motion_controller_withPIC_B.k_l += 21) {
      motion_controller_withPIC_B.b_c_a = 0.0;
      motion_controller_withPIC_B.d_ev = motion_controller_withPIC_B.k_l +
        workingset_nVar;
      for (motion_controller_withPIC_B.ia_d = motion_controller_withPIC_B.k_l +
           1; motion_controller_withPIC_B.ia_d <=
           motion_controller_withPIC_B.d_ev; motion_controller_withPIC_B.ia_d++)
      {
        motion_controller_withPIC_B.b_c_a += solution_searchDir
          [(motion_controller_withPIC_B.ia_d - motion_controller_withPIC_B.k_l)
          - 1] * workingset_Aineq[motion_controller_withPIC_B.ia_d - 1];
      }

      motion_controller_withPIC_B.ia_d = div_nde_s32_floor
        (motion_controller_withPIC_B.k_l, 21) + 81;
      workspace[motion_controller_withPIC_B.ia_d] +=
        motion_controller_withPIC_B.b_c_a;
    }

    for (motion_controller_withPIC_B.k_l = 0; motion_controller_withPIC_B.k_l <
         40; motion_controller_withPIC_B.k_l++) {
      motion_controller_withPIC_B.phaseOneCorrectionX_j =
        workspace[motion_controller_withPIC_B.k_l + 81];
      if ((motion_controller_withPIC_B.phaseOneCorrectionX_j >
           motion_controller_withPIC_B.denomTol_e) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[2] +
            motion_controller_withPIC_B.k_l) - 1])) {
        motion_controller_withPIC_B.phaseOneCorrectionP_o =
          workspace[motion_controller_withPIC_B.k_l];
        motion_controller_withPIC_B.b_c_a = fabs
          (motion_controller_withPIC_B.phaseOneCorrectionP_o);
        if ((!(motion_controller_withPIC_B.b_c_a <= 1.0E-8 -
               motion_controller_withPIC_B.phaseOneCorrectionP_o)) && (!rtIsNaN
             (1.0E-8 - motion_controller_withPIC_B.phaseOneCorrectionP_o))) {
          motion_controller_withPIC_B.b_c_a = 1.0E-8 -
            motion_controller_withPIC_B.phaseOneCorrectionP_o;
        }

        motion_controller_withPIC_B.b_c_a /=
          motion_controller_withPIC_B.phaseOneCorrectionX_j;
        if (motion_controller_withPIC_B.b_c_a < *alpha) {
          *alpha = motion_controller_withPIC_B.b_c_a;
          *constrType = 3;
          *constrIdx = motion_controller_withPIC_B.k_l + 1;
          *newBlocking = true;
        }
      }
    }
  }

  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    motion_controller_withPIC_B.phaseOneCorrectionX_j =
      solution_xstar[workingset_nVar - 1] * static_cast<real_T>(isPhaseOne);
    motion_controller_withPIC_B.phaseOneCorrectionP_o =
      solution_searchDir[workingset_nVar - 1] * static_cast<real_T>(isPhaseOne);
    motion_controller_withPIC_B.ia_d = workingset_sizes[3];
    for (motion_controller_withPIC_B.k_l = 0; motion_controller_withPIC_B.k_l <=
         motion_controller_withPIC_B.ia_d - 2; motion_controller_withPIC_B.k_l++)
    {
      motion_controller_withPIC_B.d_ev =
        workingset_indexLB[motion_controller_withPIC_B.k_l];
      motion_controller_withPIC_B.pk_corrected_f =
        -solution_searchDir[motion_controller_withPIC_B.d_ev - 1] -
        motion_controller_withPIC_B.phaseOneCorrectionP_o;
      if ((motion_controller_withPIC_B.pk_corrected_f >
           motion_controller_withPIC_B.denomTol_e) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[3] +
            motion_controller_withPIC_B.k_l) - 1])) {
        motion_controller_withPIC_B.ratio_m =
          (-solution_xstar[motion_controller_withPIC_B.d_ev - 1] -
           workingset_lb[motion_controller_withPIC_B.d_ev - 1]) -
          motion_controller_withPIC_B.phaseOneCorrectionX_j;
        motion_controller_withPIC_B.b_c_a = fabs
          (motion_controller_withPIC_B.ratio_m);
        if ((!(motion_controller_withPIC_B.b_c_a <= 1.0E-8 -
               motion_controller_withPIC_B.ratio_m)) && (!rtIsNaN(1.0E-8 -
              motion_controller_withPIC_B.ratio_m))) {
          motion_controller_withPIC_B.b_c_a = 1.0E-8 -
            motion_controller_withPIC_B.ratio_m;
        }

        motion_controller_withPIC_B.b_c_a /=
          motion_controller_withPIC_B.pk_corrected_f;
        if (motion_controller_withPIC_B.b_c_a < *alpha) {
          *alpha = motion_controller_withPIC_B.b_c_a;
          *constrType = 4;
          *constrIdx = motion_controller_withPIC_B.k_l + 1;
          *newBlocking = true;
        }
      }
    }

    motion_controller_withPIC_B.ia_d = workingset_indexLB[workingset_sizes[3] -
      1] - 1;
    motion_controller_withPIC_B.phaseOneCorrectionX_j =
      -solution_searchDir[motion_controller_withPIC_B.ia_d];
    if ((motion_controller_withPIC_B.phaseOneCorrectionX_j >
         motion_controller_withPIC_B.denomTol_e) && (!workingset_isActiveConstr
         [(workingset_isActiveIdx[3] + workingset_sizes[3]) - 2])) {
      motion_controller_withPIC_B.ratio_m =
        -solution_xstar[motion_controller_withPIC_B.ia_d] -
        workingset_lb[motion_controller_withPIC_B.ia_d];
      motion_controller_withPIC_B.b_c_a = fabs
        (motion_controller_withPIC_B.ratio_m);
      if ((!(motion_controller_withPIC_B.b_c_a <= 1.0E-8 -
             motion_controller_withPIC_B.ratio_m)) && (!rtIsNaN(1.0E-8 -
            motion_controller_withPIC_B.ratio_m))) {
        motion_controller_withPIC_B.b_c_a = 1.0E-8 -
          motion_controller_withPIC_B.ratio_m;
      }

      motion_controller_withPIC_B.b_c_a /=
        motion_controller_withPIC_B.phaseOneCorrectionX_j;
      if (motion_controller_withPIC_B.b_c_a < *alpha) {
        *alpha = motion_controller_withPIC_B.b_c_a;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }
    }
  }

  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    motion_controller_withPIC_B.phaseOneCorrectionX_j =
      solution_xstar[workingset_nVar - 1] * static_cast<real_T>(isPhaseOne);
    motion_controller_withPIC_B.phaseOneCorrectionP_o =
      solution_searchDir[workingset_nVar - 1] * static_cast<real_T>(isPhaseOne);
    motion_controller_withPIC_B.ia_d = static_cast<uint8_T>(workingset_sizes[4]);
    for (motion_controller_withPIC_B.k_l = 0; motion_controller_withPIC_B.k_l <
         motion_controller_withPIC_B.ia_d; motion_controller_withPIC_B.k_l++) {
      motion_controller_withPIC_B.d_ev =
        workingset_indexUB[motion_controller_withPIC_B.k_l];
      motion_controller_withPIC_B.pk_corrected_f =
        solution_searchDir[motion_controller_withPIC_B.d_ev - 1] -
        motion_controller_withPIC_B.phaseOneCorrectionP_o;
      if ((motion_controller_withPIC_B.pk_corrected_f >
           motion_controller_withPIC_B.denomTol_e) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[4] +
            motion_controller_withPIC_B.k_l) - 1])) {
        motion_controller_withPIC_B.ratio_m =
          (solution_xstar[motion_controller_withPIC_B.d_ev - 1] -
           workingset_ub[motion_controller_withPIC_B.d_ev - 1]) -
          motion_controller_withPIC_B.phaseOneCorrectionX_j;
        motion_controller_withPIC_B.b_c_a = fabs
          (motion_controller_withPIC_B.ratio_m);
        if ((!(motion_controller_withPIC_B.b_c_a <= 1.0E-8 -
               motion_controller_withPIC_B.ratio_m)) && (!rtIsNaN(1.0E-8 -
              motion_controller_withPIC_B.ratio_m))) {
          motion_controller_withPIC_B.b_c_a = 1.0E-8 -
            motion_controller_withPIC_B.ratio_m;
        }

        motion_controller_withPIC_B.b_c_a /=
          motion_controller_withPIC_B.pk_corrected_f;
        if (motion_controller_withPIC_B.b_c_a < *alpha) {
          *alpha = motion_controller_withPIC_B.b_c_a;
          *constrType = 5;
          *constrIdx = motion_controller_withPIC_B.k_l + 1;
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

// Function for MATLAB Function: '<S49>/solvex'
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

// Function for MATLAB Function: '<S49>/solvex'
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

// Function for MATLAB Function: '<S49>/solvex'
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
  motion_controller_withPIC_B.subProblemChanged_h = true;
  motion_controller_withPIC_B.updateFval_n = true;
  motion_controller_withPIC_B.activeSetChangeID_i = 0;
  motion_controller_withPIC_B.TYPE_h = objective->objtype;
  motion_controller_withPIC_B.tolDelta_j = 6.7434957617430445E-7;
  motion_controller_withPIC_B.nVar_k = workingset->nVar;
  motion_controller_withPIC_B.globalActiveConstrIdx_d = 0;
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
      if (motion_controller_withPIC_B.subProblemChanged_h) {
        switch (motion_controller_withPIC_B.activeSetChangeID_i) {
         case 1:
          motion_controller_withPIC_B.Qk0_n = (workingset->nActiveConstr - 1) *
            21;
          if (qrmanager->mrows <= qrmanager->ncols + 1) {
            qrmanager->minRowCol = qrmanager->mrows;
          } else {
            qrmanager->minRowCol = qrmanager->ncols + 1;
          }

          motion_controller_withPIC_B.iy0 = 21 * qrmanager->ncols;
          if (qrmanager->mrows != 0) {
            motion_controller_withPIC_B.iyend_f =
              motion_controller_withPIC_B.iy0 + qrmanager->mrows;
            if (motion_controller_withPIC_B.iy0 + 1 <=
                motion_controller_withPIC_B.iyend_f) {
              memset(&qrmanager->QR[motion_controller_withPIC_B.iy0], 0,
                     static_cast<uint32_T>(motion_controller_withPIC_B.iyend_f -
                      motion_controller_withPIC_B.iy0) * sizeof(real_T));
            }

            motion_controller_withPIC_B.l_a = (qrmanager->mrows - 1) * 21 + 1;
            for (motion_controller_withPIC_B.localActiveConstrIdx_b = 1;
                 motion_controller_withPIC_B.localActiveConstrIdx_b <=
                 motion_controller_withPIC_B.l_a;
                 motion_controller_withPIC_B.localActiveConstrIdx_b += 21) {
              motion_controller_withPIC_B.normDelta_h = 0.0;
              motion_controller_withPIC_B.m =
                (motion_controller_withPIC_B.localActiveConstrIdx_b +
                 qrmanager->mrows) - 1;
              for (motion_controller_withPIC_B.iyend_f =
                   motion_controller_withPIC_B.localActiveConstrIdx_b;
                   motion_controller_withPIC_B.iyend_f <=
                   motion_controller_withPIC_B.m;
                   motion_controller_withPIC_B.iyend_f++) {
                motion_controller_withPIC_B.normDelta_h += workingset->ATwset
                  [(motion_controller_withPIC_B.Qk0_n +
                    motion_controller_withPIC_B.iyend_f) -
                  motion_controller_withPIC_B.localActiveConstrIdx_b] *
                  qrmanager->Q[motion_controller_withPIC_B.iyend_f - 1];
              }

              motion_controller_withPIC_B.iyend_f = div_nde_s32_floor
                (motion_controller_withPIC_B.localActiveConstrIdx_b - 1, 21) +
                motion_controller_withPIC_B.iy0;
              qrmanager->QR[motion_controller_withPIC_B.iyend_f] +=
                motion_controller_withPIC_B.normDelta_h;
            }
          }

          qrmanager->ncols++;
          qrmanager->jpvt[qrmanager->ncols - 1] = qrmanager->ncols;
          motion_controller_withPIC_B.iyend_f = qrmanager->mrows - 2;
          while (motion_controller_withPIC_B.iyend_f + 2 > qrmanager->ncols) {
            motion_controller_withPIC_B.localActiveConstrIdx_b =
              (qrmanager->ncols - 1) * 21 + motion_controller_withPIC_B.iyend_f;
            motion_controller_withPIC_B.temp_d = qrmanager->
              QR[motion_controller_withPIC_B.localActiveConstrIdx_b + 1];
            motion_controlle_xrotg_ds3XgDMS(&qrmanager->
              QR[motion_controller_withPIC_B.localActiveConstrIdx_b],
              &motion_controller_withPIC_B.temp_d,
              &motion_controller_withPIC_B.normDelta_h,
              &motion_controller_withPIC_B.s_f);
            qrmanager->QR[motion_controller_withPIC_B.localActiveConstrIdx_b + 1]
              = motion_controller_withPIC_B.temp_d;
            motion_controller_withPIC_B.Qk0_n = 21 *
              motion_controller_withPIC_B.iyend_f;
            motion_controller_withPIC_B.iy0 = qrmanager->mrows;
            if (qrmanager->mrows >= 1) {
              for (motion_controller_withPIC_B.localActiveConstrIdx_b = 0;
                   motion_controller_withPIC_B.localActiveConstrIdx_b <
                   motion_controller_withPIC_B.iy0;
                   motion_controller_withPIC_B.localActiveConstrIdx_b++) {
                motion_controller_withPIC_B.l_a =
                  motion_controller_withPIC_B.Qk0_n +
                  motion_controller_withPIC_B.localActiveConstrIdx_b;
                motion_controller_withPIC_B.temp_tmp_l = qrmanager->
                  Q[motion_controller_withPIC_B.l_a + 21];
                motion_controller_withPIC_B.temp_d =
                  motion_controller_withPIC_B.temp_tmp_l *
                  motion_controller_withPIC_B.s_f + qrmanager->
                  Q[motion_controller_withPIC_B.l_a] *
                  motion_controller_withPIC_B.normDelta_h;
                qrmanager->Q[motion_controller_withPIC_B.l_a + 21] =
                  motion_controller_withPIC_B.temp_tmp_l *
                  motion_controller_withPIC_B.normDelta_h - qrmanager->
                  Q[motion_controller_withPIC_B.l_a] *
                  motion_controller_withPIC_B.s_f;
                qrmanager->Q[motion_controller_withPIC_B.l_a] =
                  motion_controller_withPIC_B.temp_d;
              }
            }

            motion_controller_withPIC_B.iyend_f--;
          }
          break;

         case -1:
          motion_contr_deleteColMoveEnd_a(qrmanager,
            motion_controller_withPIC_B.globalActiveConstrIdx_d);
          break;

         default:
          motion_controller_wi_factorQR_c(qrmanager, workingset->ATwset,
            motion_controller_withPIC_B.nVar_k, workingset->nActiveConstr);
          motion_controller_w_computeQ__l(qrmanager, qrmanager->mrows);
          break;
        }

        motion_control_compute_deltax_o(H, solution, memspace, qrmanager,
          cholmanager, objective);
        if (solution->state != -5) {
          exitg1 = 1;
        } else {
          motion_controller_withPIC_B.normDelta_h =
            motion_controlle_xnrm2_rY1rIeLd(motion_controller_withPIC_B.nVar_k,
            solution->searchDir);
          guard1 = true;
        }
      } else {
        motion_controller_withPIC_B.iyend_f = static_cast<uint8_T>
          (motion_controller_withPIC_B.nVar_k);
        memset(&solution->searchDir[0], 0, static_cast<uint32_T>
               (motion_controller_withPIC_B.iyend_f) * sizeof(real_T));
        motion_controller_withPIC_B.normDelta_h = 0.0;
        guard1 = true;
      }

      if (guard1) {
        if ((!motion_controller_withPIC_B.subProblemChanged_h) ||
            (motion_controller_withPIC_B.normDelta_h < options_StepTolerance) ||
            (workingset->nActiveConstr >= motion_controller_withPIC_B.nVar_k)) {
          motion_controlle_compute_lambda(memspace->workspace_double, solution,
            objective, qrmanager);
          if ((solution->state != -7) || (workingset->nActiveConstr >
               motion_controller_withPIC_B.nVar_k)) {
            motion_controller_withPIC_B.iyend_f = 0;
            motion_controller_withPIC_B.normDelta_h = 0.0 *
              runTimeOptions_ProbRelTolFactor * static_cast<real_T>
              (motion_controller_withPIC_B.TYPE_h != 5);
            motion_controller_withPIC_B.Qk0_n = (workingset->nWConstr[0] +
              workingset->nWConstr[1]) + 1;
            motion_controller_withPIC_B.iy0 = workingset->nActiveConstr;
            for (motion_controller_withPIC_B.localActiveConstrIdx_b =
                 motion_controller_withPIC_B.Qk0_n;
                 motion_controller_withPIC_B.localActiveConstrIdx_b <=
                 motion_controller_withPIC_B.iy0;
                 motion_controller_withPIC_B.localActiveConstrIdx_b++) {
              motion_controller_withPIC_B.s_f = solution->
                lambda[motion_controller_withPIC_B.localActiveConstrIdx_b - 1];
              if (motion_controller_withPIC_B.s_f <
                  motion_controller_withPIC_B.normDelta_h) {
                motion_controller_withPIC_B.normDelta_h =
                  motion_controller_withPIC_B.s_f;
                motion_controller_withPIC_B.iyend_f =
                  motion_controller_withPIC_B.localActiveConstrIdx_b;
              }
            }

            if (motion_controller_withPIC_B.iyend_f == 0) {
              solution->state = 1;
            } else {
              motion_controller_withPIC_B.activeSetChangeID_i = -1;
              motion_controller_withPIC_B.globalActiveConstrIdx_d =
                motion_controller_withPIC_B.iyend_f;
              motion_controller_withPIC_B.subProblemChanged_h = true;
              motion_controlle_removeConstr_n(workingset,
                motion_controller_withPIC_B.iyend_f);
              solution->lambda[motion_controller_withPIC_B.iyend_f - 1] = 0.0;
            }
          } else {
            motion_controller_withPIC_B.iyend_f = workingset->nActiveConstr;
            motion_controller_withPIC_B.activeSetChangeID_i = 0;
            motion_controller_withPIC_B.globalActiveConstrIdx_d =
              workingset->nActiveConstr;
            motion_controller_withPIC_B.subProblemChanged_h = true;
            motion_controlle_removeConstr_n(workingset,
              workingset->nActiveConstr);
            solution->lambda[motion_controller_withPIC_B.iyend_f - 1] = 0.0;
          }

          motion_controller_withPIC_B.updateFval_n = false;
        } else {
          motion_controller_withPIC_B.updateFval_n =
            (motion_controller_withPIC_B.TYPE_h == 5);
          if (motion_controller_withPIC_B.updateFval_n ||
              runTimeOptions_RemainFeasible) {
            motion_cont_feasibleratiotest_d(solution->xstar, solution->searchDir,
              memspace->workspace_double, workingset->nVar, workingset->Aineq,
              workingset->bineq, workingset->lb, workingset->ub,
              workingset->indexLB, workingset->indexUB, workingset->sizes,
              workingset->isActiveIdx, workingset->isActiveConstr,
              workingset->nWConstr, motion_controller_withPIC_B.updateFval_n,
              &motion_controller_withPIC_B.normDelta_h,
              &motion_controller_withPIC_B.newBlocking_m,
              &motion_controller_withPIC_B.iyend_f,
              &motion_controller_withPIC_B.localActiveConstrIdx_b);
          } else {
            motion_controller_w_ratiotest_f(solution->xstar, solution->searchDir,
              memspace->workspace_double, workingset->nVar, workingset->Aineq,
              workingset->bineq, workingset->lb, workingset->ub,
              workingset->indexLB, workingset->indexUB, workingset->sizes,
              workingset->isActiveIdx, workingset->isActiveConstr,
              workingset->nWConstr, &motion_controller_withPIC_B.tolDelta_j,
              &motion_controller_withPIC_B.normDelta_h,
              &motion_controller_withPIC_B.newBlocking_m,
              &motion_controller_withPIC_B.iyend_f,
              &motion_controller_withPIC_B.localActiveConstrIdx_b);
          }

          if (motion_controller_withPIC_B.newBlocking_m) {
            switch (motion_controller_withPIC_B.iyend_f) {
             case 3:
              workingset->nWConstr[2]++;
              workingset->isActiveConstr[(workingset->isActiveIdx[2] +
                motion_controller_withPIC_B.localActiveConstrIdx_b) - 2] = true;
              workingset->nActiveConstr++;
              workingset->Wid[workingset->nActiveConstr - 1] = 3;
              workingset->Wlocalidx[workingset->nActiveConstr - 1] =
                motion_controller_withPIC_B.localActiveConstrIdx_b;
              motion_controller_withPIC_B.iyend_f =
                (motion_controller_withPIC_B.localActiveConstrIdx_b - 1) * 21;
              motion_controller_withPIC_B.Qk0_n = (workingset->nActiveConstr - 1)
                * 21;
              motion_controller_withPIC_B.iy0 = workingset->nVar - 1;
              for (motion_controller_withPIC_B.activeSetChangeID_i = 0;
                   motion_controller_withPIC_B.activeSetChangeID_i <=
                   motion_controller_withPIC_B.iy0;
                   motion_controller_withPIC_B.activeSetChangeID_i++) {
                workingset->ATwset[motion_controller_withPIC_B.Qk0_n +
                  motion_controller_withPIC_B.activeSetChangeID_i] =
                  workingset->Aineq[motion_controller_withPIC_B.iyend_f +
                  motion_controller_withPIC_B.activeSetChangeID_i];
              }

              workingset->bwset[workingset->nActiveConstr - 1] =
                workingset->
                bineq[motion_controller_withPIC_B.localActiveConstrIdx_b - 1];
              break;

             case 4:
              mo_addBoundToActiveSetMatrix__i(workingset, 4,
                motion_controller_withPIC_B.localActiveConstrIdx_b);
              break;

             default:
              mo_addBoundToActiveSetMatrix__i(workingset, 5,
                motion_controller_withPIC_B.localActiveConstrIdx_b);
              break;
            }

            motion_controller_withPIC_B.activeSetChangeID_i = 1;
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

            motion_controller_withPIC_B.subProblemChanged_h = false;
            if (workingset->nActiveConstr == 0) {
              solution->state = 1;
            }
          }

          if (!(motion_controller_withPIC_B.normDelta_h == 0.0)) {
            motion_controller_withPIC_B.iyend_f =
              (motion_controller_withPIC_B.nVar_k / 2) << 1;
            motion_controller_withPIC_B.Qk0_n =
              motion_controller_withPIC_B.iyend_f - 2;
            for (motion_controller_withPIC_B.localActiveConstrIdx_b = 0;
                 motion_controller_withPIC_B.localActiveConstrIdx_b <=
                 motion_controller_withPIC_B.Qk0_n;
                 motion_controller_withPIC_B.localActiveConstrIdx_b += 2) {
              tmp = _mm_loadu_pd(&solution->
                                 searchDir[motion_controller_withPIC_B.localActiveConstrIdx_b]);
              tmp_0 = _mm_loadu_pd(&solution->
                                   xstar[motion_controller_withPIC_B.localActiveConstrIdx_b]);
              _mm_storeu_pd(&solution->
                            xstar[motion_controller_withPIC_B.localActiveConstrIdx_b],
                            _mm_add_pd(_mm_mul_pd(_mm_set1_pd
                (motion_controller_withPIC_B.normDelta_h), tmp), tmp_0));
            }

            for (motion_controller_withPIC_B.localActiveConstrIdx_b =
                 motion_controller_withPIC_B.iyend_f;
                 motion_controller_withPIC_B.localActiveConstrIdx_b <
                 motion_controller_withPIC_B.nVar_k;
                 motion_controller_withPIC_B.localActiveConstrIdx_b++) {
              solution->xstar[motion_controller_withPIC_B.localActiveConstrIdx_b]
                += motion_controller_withPIC_B.normDelta_h * solution->
                searchDir[motion_controller_withPIC_B.localActiveConstrIdx_b];
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
          motion_controller_withPIC_B.normDelta_h = solution->maxConstr;
          if (objective->objtype == 5) {
            motion_controller_withPIC_B.normDelta_h = solution->maxConstr -
              solution->xstar[objective->nvar - 1];
          }

          if (motion_controller_withPIC_B.normDelta_h > 1.0E-8 *
              runTimeOptions_ConstrRelTolFact) {
            motion_controller_withPIC_B.iyend_f = static_cast<uint8_T>
              (objective->nvar);
            if (motion_controller_withPIC_B.iyend_f - 1 >= 0) {
              memcpy(&solution->searchDir[0], &solution->xstar[0],
                     static_cast<uint32_T>(motion_controller_withPIC_B.iyend_f) *
                     sizeof(real_T));
            }

            motion_controller_withPIC_B.newBlocking_m =
              motio_feasibleX0ForWorkingSet_c(memspace->workspace_double,
              solution->searchDir, workingset, qrmanager);
            if ((!motion_controller_withPIC_B.newBlocking_m) && (solution->state
                 != 0)) {
              solution->state = -2;
            }

            motion_controller_withPIC_B.activeSetChangeID_i = 0;
            motion_controller_withPIC_B.normDelta_h =
              motion_maxConstraintViolation_n(workingset, solution->searchDir);
            if (motion_controller_withPIC_B.normDelta_h < solution->maxConstr) {
              if (motion_controller_withPIC_B.iyend_f - 1 >= 0) {
                memcpy(&solution->xstar[0], &solution->searchDir[0],
                       static_cast<uint32_T>(motion_controller_withPIC_B.iyend_f)
                       * sizeof(real_T));
              }

              solution->maxConstr = motion_controller_withPIC_B.normDelta_h;
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

// Function for MATLAB Function: '<S49>/solvex'
void motion_controller_withPIC::motion_c_PresolveWorkingSet_gjp
  (sYqpSPVJXu9aOn60zG4DpzD_motio_T *solution, s3cSGkBdKxRj6Qn3zsJRowG_motio_T
   *memspace, sVIU4VBONGRsUytHTQmMJFH_motio_T *workingset,
   sIZAIOglGM5dPDQlNukc9SD_motio_T *qrmanager)
{
  boolean_T guard1;
  solution->state = 82;
  motion_controller_withPIC_B.mWorkingFixed_g = workingset->nWConstr[0];
  motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp = workingset->nWConstr[0]
    + workingset->nWConstr[1];
  motion_controller_withPIC_B.idxStartIneq_ge = 0;
  if (motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp > 0) {
    motion_controller_withPIC_B.c_tmp = static_cast<uint8_T>(workingset->nVar);
    for (motion_controller_withPIC_B.idxStartIneq_ge = 0;
         motion_controller_withPIC_B.idxStartIneq_ge <
         motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp;
         motion_controller_withPIC_B.idxStartIneq_ge++) {
      for (motion_controller_withPIC_B.idxEndIneq_g = 0;
           motion_controller_withPIC_B.idxEndIneq_g <
           motion_controller_withPIC_B.c_tmp;
           motion_controller_withPIC_B.idxEndIneq_g++) {
        qrmanager->QR[motion_controller_withPIC_B.idxStartIneq_ge + 21 *
          motion_controller_withPIC_B.idxEndIneq_g] = workingset->ATwset[21 *
          motion_controller_withPIC_B.idxStartIneq_ge +
          motion_controller_withPIC_B.idxEndIneq_g];
      }
    }

    motion_controller_withPIC_B.idxStartIneq_ge =
      motion_ComputeNumDependentEq__d(qrmanager, workingset->bwset,
      motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp, workingset->nVar);
    if (motion_controller_withPIC_B.idxStartIneq_ge > 0) {
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
           motion_controller_withPIC_B.mWorkingFixed_g;
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
           motion_controller_withPIC_B.idxStartIneq_ge;
           motion_controller_withPIC_B.idxEndIneq_g++) {
        memspace->workspace_int[motion_controller_withPIC_B.idxEndIneq_g] =
          qrmanager->jpvt[(motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp -
                           motion_controller_withPIC_B.idxStartIneq_ge) +
          motion_controller_withPIC_B.idxEndIneq_g];
      }

      countsort_JblpZJs7(memspace->workspace_int,
                         motion_controller_withPIC_B.idxStartIneq_ge,
                         memspace->workspace_sort, 1,
                         motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp);
      for (motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp =
           motion_controller_withPIC_B.idxStartIneq_ge;
           motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp >= 1;
           motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp--) {
        motion_control_removeEqConstr_i(workingset, memspace->
          workspace_int[motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp - 1]);
      }
    }
  }

  if ((motion_controller_withPIC_B.idxStartIneq_ge != -1) &&
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
        motion_controller_withPIC_B.constrViolation_h =
          motion_maxConstraintViolation_n(workingset, solution->xstar);
        if (motion_controller_withPIC_B.constrViolation_h > 1.0E-8) {
          solution->state = -2;
        }
      }
    }
  } else {
    solution->state = -3;
    motion_controller_withPIC_B.idxStartIneq_ge = (workingset->nWConstr[0] +
      workingset->nWConstr[1]) + 1;
    motion_controller_withPIC_B.idxEndIneq_g = workingset->nActiveConstr;
    for (motion_controller_withPIC_B.mTotalWorkingEq_tmp_tmp =
         motion_controller_withPIC_B.idxStartIneq_ge;
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

// Function for MATLAB Function: '<S49>/solvex'
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

// Function for MATLAB Function: '<S49>/solvex'
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
  motion_controller_withPIC_B.i_i = workingset->nVar;
  motion_controller_withPIC_B.idxStartIneq_g = static_cast<uint8_T>
    (workingset->sizes[0]);
  for (motion_controller_withPIC_B.mConstr = 0;
       motion_controller_withPIC_B.mConstr <
       motion_controller_withPIC_B.idxStartIneq_g;
       motion_controller_withPIC_B.mConstr++) {
    solution->xstar[workingset->indexFixed[motion_controller_withPIC_B.mConstr]
      - 1] = workingset->ub[workingset->
      indexFixed[motion_controller_withPIC_B.mConstr] - 1];
  }

  motion_controller_withPIC_B.idxStartIneq_g = static_cast<uint8_T>
    (workingset->sizes[3]);
  for (motion_controller_withPIC_B.mConstr = 0;
       motion_controller_withPIC_B.mConstr <
       motion_controller_withPIC_B.idxStartIneq_g;
       motion_controller_withPIC_B.mConstr++) {
    if (workingset->isActiveConstr[(workingset->isActiveIdx[3] +
         motion_controller_withPIC_B.mConstr) - 1]) {
      solution->xstar[workingset->indexLB[motion_controller_withPIC_B.mConstr] -
        1] = -workingset->lb[workingset->
        indexLB[motion_controller_withPIC_B.mConstr] - 1];
    }
  }

  motion_controller_withPIC_B.idxStartIneq_g = static_cast<uint8_T>
    (workingset->sizes[4]);
  for (motion_controller_withPIC_B.mConstr = 0;
       motion_controller_withPIC_B.mConstr <
       motion_controller_withPIC_B.idxStartIneq_g;
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
      motion_controller_withPIC_B.idxStartIneq_g =
        (motion_controller_withPIC_B.b_workingset.nWConstr[0] +
         motion_controller_withPIC_B.b_workingset.nWConstr[1]) + 1;
      motion_controller_withPIC_B.idxEndIneq_e =
        motion_controller_withPIC_B.b_workingset.nActiveConstr;
      for (motion_controller_withPIC_B.mConstr =
           motion_controller_withPIC_B.idxStartIneq_g;
           motion_controller_withPIC_B.mConstr <=
           motion_controller_withPIC_B.idxEndIneq_e;
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
              (motion_controller_withPIC_B.i_i);
            if (motion_controller_withPIC_B.mConstr - 1 >= 0) {
              memcpy(&solution->searchDir[0], &solution->xstar[0],
                     static_cast<uint32_T>(motion_controller_withPIC_B.mConstr) *
                     sizeof(real_T));
            }

            motion_c_PresolveWorkingSet_gjp(solution, memspace,
              &motion_controller_withPIC_B.b_workingset, qrmanager);
            *workingset = motion_controller_withPIC_B.b_workingset;
            motion_controller_withPIC_B.maxConstr_new_h =
              motion_maxConstraintViolation_n(workingset, solution->xstar);
            if (motion_controller_withPIC_B.maxConstr_new_h >=
                solution->maxConstr) {
              solution->maxConstr = motion_controller_withPIC_B.maxConstr_new_h;
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
      motion_controller_withPIC_B.i_i = 0;
      do {
        exitg2 = 0;
        if (motion_controller_withPIC_B.i_i < 8) {
          if (j[static_cast<int32_T>(options->
               SolverName[motion_controller_withPIC_B.i_i])] != j
              [static_cast<int32_T>(l[motion_controller_withPIC_B.i_i])]) {
            exitg2 = 1;
          } else {
            motion_controller_withPIC_B.i_i++;
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
          motion_controller_withPIC_B.idxStartIneq_g = workingset->nVar;
          solution->xstar[20] = solution->maxConstr + 1.0;
          if (workingset->probType == 3) {
            motion_controller_withPIC_B.i_i = 1;
          } else {
            motion_controller_withPIC_B.i_i = 4;
          }

          motion_control_setProblemType_k(workingset,
            motion_controller_withPIC_B.i_i);
          motion_controller_withPIC_B.idxEndIneq_e = workingset->nWConstr[0] +
            workingset->nWConstr[1];
          motion_controller_withPIC_B.b_idxStartIneq =
            motion_controller_withPIC_B.idxEndIneq_e + 1;
          motion_controller_withPIC_B.b_idxEndIneq = workingset->nActiveConstr;
          for (motion_controller_withPIC_B.i_i =
               motion_controller_withPIC_B.b_idxStartIneq;
               motion_controller_withPIC_B.i_i <=
               motion_controller_withPIC_B.b_idxEndIneq;
               motion_controller_withPIC_B.i_i++) {
            workingset->isActiveConstr[(workingset->isActiveIdx[workingset->
              Wid[motion_controller_withPIC_B.i_i - 1] - 1] +
              workingset->Wlocalidx[motion_controller_withPIC_B.i_i - 1]) - 2] =
              false;
          }

          workingset->nWConstr[2] = 0;
          workingset->nWConstr[3] = 0;
          workingset->nWConstr[4] = 0;
          workingset->nActiveConstr = motion_controller_withPIC_B.idxEndIneq_e;
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
            motion_controller_withPIC_B.i_i = workingset->sizes[0];
            exitg1 = false;
            while ((!exitg1) && (motion_controller_withPIC_B.i_i + 1 <=
                                 workingset->nActiveConstr)) {
              if ((workingset->Wid[motion_controller_withPIC_B.i_i] == 4) &&
                  (workingset->Wlocalidx[motion_controller_withPIC_B.i_i] ==
                   workingset->sizes[3])) {
                motion_controlle_removeConstr_n(workingset,
                  motion_controller_withPIC_B.i_i + 1);
                exitg1 = true;
              } else {
                motion_controller_withPIC_B.i_i++;
              }
            }
          }

          motion_controller_withPIC_B.i_i = workingset->nActiveConstr;
          while ((motion_controller_withPIC_B.i_i > workingset->sizes[0]) &&
                 (motion_controller_withPIC_B.i_i >
                  motion_controller_withPIC_B.idxStartIneq_g)) {
            motion_controlle_removeConstr_n(workingset,
              motion_controller_withPIC_B.i_i);
            motion_controller_withPIC_B.i_i--;
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

// Function for MATLAB Function: '<S49>/solvex'
void motion_controller_withPIC::motion_controller_wi_quadprog_k(const real_T H
  [400], const real_T f[20], const real_T Aineq[800], const real_T bineq[40],
  const real_T lb[20], const real_T ub[20], real_T x0[20], const
  sSOeZ9WO10chPn9Si6PKiCB_motio_T *options)
{
  __m128d tmp;
  boolean_T exitg1;
  boolean_T guard1;
  motion_controller_withPIC_B.exitflag_p = (rtInf);
  motion_controller_withPIC_B.c_k_m = 0;
  exitg1 = false;
  while ((!exitg1) && (motion_controller_withPIC_B.c_k_m < 20)) {
    if (lb[motion_controller_withPIC_B.c_k_m] >
        ub[motion_controller_withPIC_B.c_k_m]) {
      motion_controller_withPIC_B.exitflag_p = -2.0;
      exitg1 = true;
    } else {
      motion_controller_withPIC_B.c_k_m++;
    }
  }

  if (!(motion_controller_withPIC_B.exitflag_p == -2.0)) {
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
    motion_controller_withPIC_B.c_k_m = 40;
    motion_controller_withPIC_B.idxFillStart_i = 0;
    motion_controller_withPIC_B.colOffsetATw_p = 0;
    for (motion_controller_withPIC_B.i_o = 0; motion_controller_withPIC_B.i_o <
         20; motion_controller_withPIC_B.i_o++) {
      motion_controller_withPIC_B.exitflag_p =
        lb[motion_controller_withPIC_B.i_o];
      guard1 = false;
      if ((!rtIsInf(motion_controller_withPIC_B.exitflag_p)) && (!rtIsNaN
           (motion_controller_withPIC_B.exitflag_p))) {
        if (fabs(motion_controller_withPIC_B.exitflag_p -
                 ub[motion_controller_withPIC_B.i_o]) < 1.0E-8) {
          motion_controller_withPIC_B.colOffsetATw_p++;
          motion_controller_withPIC_B.WorkingSet_p.indexFixed[motion_controller_withPIC_B.colOffsetATw_p
            - 1] = motion_controller_withPIC_B.i_o + 1;
        } else {
          motion_controller_withPIC_B.c_k_m++;
          motion_controller_withPIC_B.WorkingSet_p.indexLB[motion_controller_withPIC_B.c_k_m
            - 41] = motion_controller_withPIC_B.i_o + 1;
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        motion_controller_withPIC_B.exitflag_p =
          ub[motion_controller_withPIC_B.i_o];
        if ((!rtIsInf(motion_controller_withPIC_B.exitflag_p)) && (!rtIsNaN
             (motion_controller_withPIC_B.exitflag_p))) {
          motion_controller_withPIC_B.idxFillStart_i++;
          motion_controller_withPIC_B.WorkingSet_p.indexUB[motion_controller_withPIC_B.idxFillStart_i
            - 1] = motion_controller_withPIC_B.i_o + 1;
        }
      }
    }

    motion_controller_withPIC_B.i_o = (motion_controller_withPIC_B.c_k_m +
      motion_controller_withPIC_B.idxFillStart_i) +
      motion_controller_withPIC_B.colOffsetATw_p;
    motion_controller_withPIC_B.WorkingSet_p.mConstr =
      motion_controller_withPIC_B.i_o;
    motion_controller_withPIC_B.WorkingSet_p.mConstrOrig =
      motion_controller_withPIC_B.i_o;
    motion_controller_withPIC_B.WorkingSet_p.mConstrMax = 81;
    motion_controller_withPIC_B.WorkingSet_p.sizes[0] =
      motion_controller_withPIC_B.colOffsetATw_p;
    motion_controller_withPIC_B.WorkingSet_p.sizes[1] = 0;
    motion_controller_withPIC_B.WorkingSet_p.sizes[2] = 40;
    motion_controller_withPIC_B.WorkingSet_p.sizes[3] =
      motion_controller_withPIC_B.c_k_m - 40;
    motion_controller_withPIC_B.WorkingSet_p.sizes[4] =
      motion_controller_withPIC_B.idxFillStart_i;
    for (motion_controller_withPIC_B.i_o = 0; motion_controller_withPIC_B.i_o <
         5; motion_controller_withPIC_B.i_o++) {
      motion_controller_withPIC_B.WorkingSet_p.sizesNormal[motion_controller_withPIC_B.i_o]
        =
        motion_controller_withPIC_B.WorkingSet_p.sizes[motion_controller_withPIC_B.i_o];
    }

    motion_controller_withPIC_B.WorkingSet_p.sizesPhaseOne[0] =
      motion_controller_withPIC_B.colOffsetATw_p;
    motion_controller_withPIC_B.WorkingSet_p.sizesPhaseOne[1] = 0;
    motion_controller_withPIC_B.WorkingSet_p.sizesPhaseOne[2] = 40;
    motion_controller_withPIC_B.WorkingSet_p.sizesPhaseOne[3] =
      motion_controller_withPIC_B.c_k_m - 39;
    motion_controller_withPIC_B.WorkingSet_p.sizesPhaseOne[4] =
      motion_controller_withPIC_B.idxFillStart_i;
    motion_controller_withPIC_B.WorkingSet_p.sizesRegularized[0] =
      motion_controller_withPIC_B.colOffsetATw_p;
    motion_controller_withPIC_B.WorkingSet_p.sizesRegularized[1] = 0;
    motion_controller_withPIC_B.WorkingSet_p.sizesRegularized[2] = 40;
    motion_controller_withPIC_B.WorkingSet_p.sizesRegularized[3] =
      motion_controller_withPIC_B.c_k_m;
    motion_controller_withPIC_B.WorkingSet_p.sizesRegularized[4] =
      motion_controller_withPIC_B.idxFillStart_i;
    motion_controller_withPIC_B.WorkingSet_p.sizesRegPhaseOne[0] =
      motion_controller_withPIC_B.colOffsetATw_p;
    motion_controller_withPIC_B.WorkingSet_p.sizesRegPhaseOne[1] = 0;
    motion_controller_withPIC_B.WorkingSet_p.sizesRegPhaseOne[2] = 40;
    motion_controller_withPIC_B.WorkingSet_p.sizesRegPhaseOne[3] =
      motion_controller_withPIC_B.c_k_m + 1;
    motion_controller_withPIC_B.WorkingSet_p.sizesRegPhaseOne[4] =
      motion_controller_withPIC_B.idxFillStart_i;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxNormal[0] = 1;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxNormal[1] =
      motion_controller_withPIC_B.colOffsetATw_p;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxNormal[2] = 0;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxNormal[3] = 40;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxNormal[4] =
      motion_controller_withPIC_B.c_k_m - 40;
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
      motion_controller_withPIC_B.colOffsetATw_p;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[2] = 0;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[3] = 40;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[4] =
      motion_controller_withPIC_B.c_k_m - 39;
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
      motion_controller_withPIC_B.colOffsetATw_p;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[2] = 0;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[3] = 40;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[4] =
      motion_controller_withPIC_B.c_k_m;
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
      motion_controller_withPIC_B.colOffsetATw_p;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[2] = 0;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[3] = 40;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[4] =
      motion_controller_withPIC_B.c_k_m + 1;
    motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[5] =
      motion_controller_withPIC_B.idxFillStart_i;
    for (motion_controller_withPIC_B.c_k_m = 0;
         motion_controller_withPIC_B.c_k_m < 5;
         motion_controller_withPIC_B.c_k_m++) {
      motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.c_k_m
        + 1] +=
        motion_controller_withPIC_B.WorkingSet_p.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.c_k_m];
    }

    for (motion_controller_withPIC_B.c_k_m = 0;
         motion_controller_withPIC_B.c_k_m < 20;
         motion_controller_withPIC_B.c_k_m++) {
      for (motion_controller_withPIC_B.idxFillStart_i = 0;
           motion_controller_withPIC_B.idxFillStart_i < 40;
           motion_controller_withPIC_B.idxFillStart_i++) {
        motion_controller_withPIC_B.WorkingSet_p.Aineq[motion_controller_withPIC_B.c_k_m
          + 21 * motion_controller_withPIC_B.idxFillStart_i] = Aineq[40 *
          motion_controller_withPIC_B.c_k_m +
          motion_controller_withPIC_B.idxFillStart_i];
      }
    }

    memcpy(&motion_controller_withPIC_B.WorkingSet_p.bineq[0], &bineq[0], 40U *
           sizeof(real_T));
    for (motion_controller_withPIC_B.c_k_m = 0;
         motion_controller_withPIC_B.c_k_m <= 18;
         motion_controller_withPIC_B.c_k_m += 2) {
      tmp = _mm_loadu_pd(&lb[motion_controller_withPIC_B.c_k_m]);
      _mm_storeu_pd
        (&motion_controller_withPIC_B.WorkingSet_p.lb[motion_controller_withPIC_B.c_k_m],
         _mm_mul_pd(tmp, _mm_set1_pd(-1.0)));
      tmp = _mm_loadu_pd(&ub[motion_controller_withPIC_B.c_k_m]);
      _mm_storeu_pd
        (&motion_controller_withPIC_B.WorkingSet_p.ub[motion_controller_withPIC_B.c_k_m],
         tmp);
    }

    motion_control_setProblemType_k(&motion_controller_withPIC_B.WorkingSet_p, 3);
    motion_controller_withPIC_B.idxFillStart_i =
      motion_controller_withPIC_B.WorkingSet_p.isActiveIdx[2];
    for (motion_controller_withPIC_B.c_k_m =
         motion_controller_withPIC_B.idxFillStart_i;
         motion_controller_withPIC_B.c_k_m < 82;
         motion_controller_withPIC_B.c_k_m++) {
      motion_controller_withPIC_B.WorkingSet_p.isActiveConstr[motion_controller_withPIC_B.c_k_m
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
    for (motion_controller_withPIC_B.c_k_m = 0;
         motion_controller_withPIC_B.c_k_m <
         motion_controller_withPIC_B.idxFillStart_i;
         motion_controller_withPIC_B.c_k_m++) {
      motion_controller_withPIC_B.WorkingSet_p.Wid[motion_controller_withPIC_B.c_k_m]
        = 1;
      motion_controller_withPIC_B.WorkingSet_p.Wlocalidx[motion_controller_withPIC_B.c_k_m]
        = motion_controller_withPIC_B.c_k_m + 1;
      motion_controller_withPIC_B.WorkingSet_p.isActiveConstr[motion_controller_withPIC_B.c_k_m]
        = true;
      motion_controller_withPIC_B.colOffsetATw_p = 21 *
        motion_controller_withPIC_B.c_k_m;
      motion_controller_withPIC_B.i_o =
        motion_controller_withPIC_B.WorkingSet_p.indexFixed[motion_controller_withPIC_B.c_k_m];
      if (motion_controller_withPIC_B.i_o - 2 >= 0) {
        memset
          (&motion_controller_withPIC_B.WorkingSet_p.ATwset[motion_controller_withPIC_B.colOffsetATw_p],
           0, static_cast<uint32_T>(((motion_controller_withPIC_B.i_o +
              motion_controller_withPIC_B.colOffsetATw_p) -
             motion_controller_withPIC_B.colOffsetATw_p) - 1) * sizeof(real_T));
      }

      motion_controller_withPIC_B.WorkingSet_p.ATwset
        [(motion_controller_withPIC_B.WorkingSet_p.indexFixed[motion_controller_withPIC_B.c_k_m]
          + motion_controller_withPIC_B.colOffsetATw_p) - 1] = 1.0;
      motion_controller_withPIC_B.i_o =
        motion_controller_withPIC_B.WorkingSet_p.indexFixed[motion_controller_withPIC_B.c_k_m]
        + 1;
      motion_controller_withPIC_B.e_o =
        motion_controller_withPIC_B.WorkingSet_p.nVar;
      if (motion_controller_withPIC_B.i_o <= motion_controller_withPIC_B.e_o) {
        memset(&motion_controller_withPIC_B.WorkingSet_p.ATwset
               [(motion_controller_withPIC_B.i_o +
                 motion_controller_withPIC_B.colOffsetATw_p) + -1], 0,
               static_cast<uint32_T>((((motion_controller_withPIC_B.e_o +
                   motion_controller_withPIC_B.colOffsetATw_p) -
                  motion_controller_withPIC_B.i_o) -
                 motion_controller_withPIC_B.colOffsetATw_p) + 1) * sizeof
               (real_T));
      }

      motion_controller_withPIC_B.WorkingSet_p.bwset[motion_controller_withPIC_B.c_k_m]
        =
        motion_controller_withPIC_B.WorkingSet_p.ub[motion_controller_withPIC_B.WorkingSet_p.indexFixed
        [motion_controller_withPIC_B.c_k_m] - 1];
    }

    motion_controller_withPIC_B.WorkingSet_p.SLACK0 = 0.0;
    motion_controller_withPIC_B.exitflag_p = 1.0;
    for (motion_controller_withPIC_B.c_k_m = 0;
         motion_controller_withPIC_B.c_k_m < 40;
         motion_controller_withPIC_B.c_k_m++) {
      motion_controller_withPIC_B.colSum_f = 0.0;
      motion_controller_withPIC_B.colOffsetATw_p = 21 *
        motion_controller_withPIC_B.c_k_m;
      for (motion_controller_withPIC_B.idxFillStart_i = 0;
           motion_controller_withPIC_B.idxFillStart_i < 20;
           motion_controller_withPIC_B.idxFillStart_i++) {
        motion_controller_withPIC_B.colSum_f += fabs
          (motion_controller_withPIC_B.WorkingSet_p.Aineq[motion_controller_withPIC_B.idxFillStart_i
           + motion_controller_withPIC_B.colOffsetATw_p]);
      }

      if ((!(motion_controller_withPIC_B.exitflag_p >=
             motion_controller_withPIC_B.colSum_f)) && (!rtIsNaN
           (motion_controller_withPIC_B.colSum_f))) {
        motion_controller_withPIC_B.exitflag_p =
          motion_controller_withPIC_B.colSum_f;
      }
    }

    motion_controller_withPIC_B.colSum_f = 0.0;
    motion_controller_withPIC_B.f_infnrm_e = 0.0;
    for (motion_controller_withPIC_B.c_k_m = 0;
         motion_controller_withPIC_B.c_k_m < 20;
         motion_controller_withPIC_B.c_k_m++) {
      motion_controller_withPIC_B.b_colSum_n = 0.0;
      for (motion_controller_withPIC_B.idxFillStart_i = 0;
           motion_controller_withPIC_B.idxFillStart_i < 20;
           motion_controller_withPIC_B.idxFillStart_i++) {
        motion_controller_withPIC_B.b_colSum_n += fabs(H[20 *
          motion_controller_withPIC_B.c_k_m +
          motion_controller_withPIC_B.idxFillStart_i]);
      }

      if ((!(motion_controller_withPIC_B.colSum_f >=
             motion_controller_withPIC_B.b_colSum_n)) && (!rtIsNaN
           (motion_controller_withPIC_B.b_colSum_n))) {
        motion_controller_withPIC_B.colSum_f =
          motion_controller_withPIC_B.b_colSum_n;
      }

      motion_controller_withPIC_B.b_colSum_n = fabs
        (f[motion_controller_withPIC_B.c_k_m]);
      if ((!(motion_controller_withPIC_B.f_infnrm_e >=
             motion_controller_withPIC_B.b_colSum_n)) && (!rtIsNaN
           (motion_controller_withPIC_B.b_colSum_n))) {
        motion_controller_withPIC_B.f_infnrm_e =
          motion_controller_withPIC_B.b_colSum_n;
      }
    }

    if (motion_controller_withPIC_B.exitflag_p >=
        motion_controller_withPIC_B.f_infnrm_e) {
      motion_controller_withPIC_B.f_infnrm_e =
        motion_controller_withPIC_B.exitflag_p;
    }

    if (motion_controller_withPIC_B.f_infnrm_e >=
        motion_controller_withPIC_B.colSum_f) {
      motion_controller_withPIC_B.colSum_f =
        motion_controller_withPIC_B.f_infnrm_e;
    }

    motion_controller_withPIC_B.options_m = *options;
    motion_controller_with_driver_e(H, f,
      &motion_controller_withPIC_B.solution_l,
      &motion_controller_withPIC_B.memspace_g,
      &motion_controller_withPIC_B.WorkingSet_p,
      &motion_controller_withPIC_B.CholRegManager_c,
      &motion_controller_withPIC_B.options_m,
      motion_controller_withPIC_B.exitflag_p,
      motion_controller_withPIC_B.colSum_f,
      &motion_controller_withPIC_B.QRManager_f,
      &motion_controller_withPIC_B.QPObjective_b);
    memcpy(&x0[0], &motion_controller_withPIC_B.solution_l.xstar[0], 20U *
           sizeof(real_T));
  }
}

// Function for MATLAB Function: '<S48>/solvex'
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

// Function for MATLAB Function: '<S48>/solvex'
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

// Function for MATLAB Function: '<S48>/solvex'
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
      for (motion_controller_withPIC_B.k_n = ix0;
           motion_controller_withPIC_B.k_n <= motion_controller_withPIC_B.kend;
           motion_controller_withPIC_B.k_n++) {
        motion_controller_withPIC_B.absxk = fabs
          (x[motion_controller_withPIC_B.k_n - 1]);
        if (motion_controller_withPIC_B.absxk >
            motion_controller_withPIC_B.scale) {
          motion_controller_withPIC_B.t_i = motion_controller_withPIC_B.scale /
            motion_controller_withPIC_B.absxk;
          y = y * motion_controller_withPIC_B.t_i *
            motion_controller_withPIC_B.t_i + 1.0;
          motion_controller_withPIC_B.scale = motion_controller_withPIC_B.absxk;
        } else {
          motion_controller_withPIC_B.t_i = motion_controller_withPIC_B.absxk /
            motion_controller_withPIC_B.scale;
          y += motion_controller_withPIC_B.t_i * motion_controller_withPIC_B.t_i;
        }
      }

      y = motion_controller_withPIC_B.scale * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S48>/solvex'
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
          for (motion_controller_withPIC_B.d_i4 = ix0;
               motion_controller_withPIC_B.d_i4 <=
               motion_controller_withPIC_B.vectorUB_tmp;
               motion_controller_withPIC_B.d_i4 += 2) {
            tmp = _mm_loadu_pd(&x[motion_controller_withPIC_B.d_i4 - 1]);
            _mm_storeu_pd(&x[motion_controller_withPIC_B.d_i4 - 1], _mm_mul_pd
                          (tmp, _mm_set1_pd(9.9792015476736E+291)));
          }

          for (motion_controller_withPIC_B.d_i4 =
               motion_controller_withPIC_B.vectorUB;
               motion_controller_withPIC_B.d_i4 <=
               motion_controller_withPIC_B.scalarLB;
               motion_controller_withPIC_B.d_i4++) {
            x[motion_controller_withPIC_B.d_i4 - 1] *= 9.9792015476736E+291;
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
        for (motion_controller_withPIC_B.d_i4 = ix0;
             motion_controller_withPIC_B.d_i4 <=
             motion_controller_withPIC_B.vectorUB_tmp;
             motion_controller_withPIC_B.d_i4 += 2) {
          tmp = _mm_loadu_pd(&x[motion_controller_withPIC_B.d_i4 - 1]);
          _mm_storeu_pd(&x[motion_controller_withPIC_B.d_i4 - 1], _mm_mul_pd(tmp,
            _mm_set1_pd(motion_controller_withPIC_B.a)));
        }

        for (motion_controller_withPIC_B.d_i4 =
             motion_controller_withPIC_B.vectorUB;
             motion_controller_withPIC_B.d_i4 <=
             motion_controller_withPIC_B.scalarLB;
             motion_controller_withPIC_B.d_i4++) {
          x[motion_controller_withPIC_B.d_i4 - 1] *=
            motion_controller_withPIC_B.a;
        }

        for (motion_controller_withPIC_B.d_i4 = 0;
             motion_controller_withPIC_B.d_i4 < motion_controller_withPIC_B.knt;
             motion_controller_withPIC_B.d_i4++) {
          motion_controller_withPIC_B.xnorm *= 1.0020841800044864E-292;
        }

        *alpha1 = motion_controller_withPIC_B.xnorm;
      } else {
        tau = (motion_controller_withPIC_B.xnorm - *alpha1) /
          motion_controller_withPIC_B.xnorm;
        motion_controller_withPIC_B.a = 1.0 / (*alpha1 -
          motion_controller_withPIC_B.xnorm);
        motion_controller_withPIC_B.d_i4 = (ix0 + n) - 2;
        motion_controller_withPIC_B.scalarLB =
          ((((motion_controller_withPIC_B.d_i4 - ix0) + 1) / 2) << 1) + ix0;
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
             motion_controller_withPIC_B.knt <= motion_controller_withPIC_B.d_i4;
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

// Function for MATLAB Function: '<S48>/solvex'
void motion_controller_withPIC::motion_controll_xzlarf_xH4hoCMV(int32_T m,
  int32_T n, int32_T iv0, real_T tau, real_T C[6601], int32_T ic0, real_T work
  [161])
{
  if (tau != 0.0) {
    boolean_T exitg2;
    motion_controller_withPIC_B.lastv_f = m;
    motion_controller_withPIC_B.lastc_b = iv0 + m;
    while ((motion_controller_withPIC_B.lastv_f > 0) &&
           (C[motion_controller_withPIC_B.lastc_b - 2] == 0.0)) {
      motion_controller_withPIC_B.lastv_f--;
      motion_controller_withPIC_B.lastc_b--;
    }

    motion_controller_withPIC_B.lastc_b = n;
    exitg2 = false;
    while ((!exitg2) && (motion_controller_withPIC_B.lastc_b > 0)) {
      int32_T exitg1;
      motion_controller_withPIC_B.coltop_n =
        (motion_controller_withPIC_B.lastc_b - 1) * 41 + ic0;
      motion_controller_withPIC_B.b_ia_p = motion_controller_withPIC_B.coltop_n;
      do {
        exitg1 = 0;
        if (motion_controller_withPIC_B.b_ia_p <=
            (motion_controller_withPIC_B.coltop_n +
             motion_controller_withPIC_B.lastv_f) - 1) {
          if (C[motion_controller_withPIC_B.b_ia_p - 1] != 0.0) {
            exitg1 = 1;
          } else {
            motion_controller_withPIC_B.b_ia_p++;
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
    motion_controller_withPIC_B.lastv_f = 0;
    motion_controller_withPIC_B.lastc_b = -1;
  }

  if (motion_controller_withPIC_B.lastv_f > 0) {
    if (motion_controller_withPIC_B.lastc_b + 1 != 0) {
      if (motion_controller_withPIC_B.lastc_b >= 0) {
        memset(&work[0], 0, static_cast<uint32_T>
               (motion_controller_withPIC_B.lastc_b + 1) * sizeof(real_T));
      }

      motion_controller_withPIC_B.jA_i = 41 *
        motion_controller_withPIC_B.lastc_b + ic0;
      for (motion_controller_withPIC_B.coltop_n = ic0;
           motion_controller_withPIC_B.coltop_n <=
           motion_controller_withPIC_B.jA_i;
           motion_controller_withPIC_B.coltop_n += 41) {
        motion_controller_withPIC_B.c_o = 0.0;
        motion_controller_withPIC_B.d_e = (motion_controller_withPIC_B.coltop_n
          + motion_controller_withPIC_B.lastv_f) - 1;
        for (motion_controller_withPIC_B.b_ia_p =
             motion_controller_withPIC_B.coltop_n;
             motion_controller_withPIC_B.b_ia_p <=
             motion_controller_withPIC_B.d_e; motion_controller_withPIC_B.b_ia_p
             ++) {
          motion_controller_withPIC_B.c_o += C[((iv0 +
            motion_controller_withPIC_B.b_ia_p) -
            motion_controller_withPIC_B.coltop_n) - 1] *
            C[motion_controller_withPIC_B.b_ia_p - 1];
        }

        motion_controller_withPIC_B.b_ia_p = div_nde_s32_floor
          (motion_controller_withPIC_B.coltop_n - ic0, 41);
        work[motion_controller_withPIC_B.b_ia_p] +=
          motion_controller_withPIC_B.c_o;
      }
    }

    if (!(-tau == 0.0)) {
      motion_controller_withPIC_B.jA_i = ic0;
      for (motion_controller_withPIC_B.coltop_n = 0;
           motion_controller_withPIC_B.coltop_n <=
           motion_controller_withPIC_B.lastc_b;
           motion_controller_withPIC_B.coltop_n++) {
        motion_controller_withPIC_B.c_o =
          work[motion_controller_withPIC_B.coltop_n];
        if (motion_controller_withPIC_B.c_o != 0.0) {
          motion_controller_withPIC_B.c_o *= -tau;
          motion_controller_withPIC_B.d_e = motion_controller_withPIC_B.lastv_f
            + motion_controller_withPIC_B.jA_i;
          for (motion_controller_withPIC_B.b_ia_p =
               motion_controller_withPIC_B.jA_i;
               motion_controller_withPIC_B.b_ia_p <
               motion_controller_withPIC_B.d_e;
               motion_controller_withPIC_B.b_ia_p++) {
            C[motion_controller_withPIC_B.b_ia_p - 1] += C[((iv0 +
              motion_controller_withPIC_B.b_ia_p) -
              motion_controller_withPIC_B.jA_i) - 1] *
              motion_controller_withPIC_B.c_o;
          }
        }

        motion_controller_withPIC_B.jA_i += 41;
      }
    }
  }
}

// Function for MATLAB Function: '<S48>/solvex'
void motion_controller_withPIC::motion_controller__qrf_ELz1YOWw(real_T A[6601],
  int32_T m, int32_T n, int32_T nfxd, real_T tau[41])
{
  memset(&motion_controller_withPIC_B.work_d[0], 0, 161U * sizeof(real_T));
  motion_controller_withPIC_B.b_jk = static_cast<uint8_T>(nfxd);
  for (motion_controller_withPIC_B.i_e = 0; motion_controller_withPIC_B.i_e <
       motion_controller_withPIC_B.b_jk; motion_controller_withPIC_B.i_e++) {
    motion_controller_withPIC_B.ii = motion_controller_withPIC_B.i_e * 41 +
      motion_controller_withPIC_B.i_e;
    motion_controller_withPIC_B.mmi_b = m - motion_controller_withPIC_B.i_e;
    if (motion_controller_withPIC_B.i_e + 1 < m) {
      motion_controller_withPIC_B.b_atmp = A[motion_controller_withPIC_B.ii];
      motion_controller_withPIC_B.tau = motion_control_xzlarfg_91xlzxZq
        (motion_controller_withPIC_B.mmi_b, &motion_controller_withPIC_B.b_atmp,
         A, motion_controller_withPIC_B.ii + 2);
      tau[motion_controller_withPIC_B.i_e] = motion_controller_withPIC_B.tau;
      A[motion_controller_withPIC_B.ii] = motion_controller_withPIC_B.b_atmp;
    } else {
      motion_controller_withPIC_B.tau = 0.0;
      tau[motion_controller_withPIC_B.i_e] = 0.0;
    }

    if (motion_controller_withPIC_B.i_e + 1 < n) {
      motion_controller_withPIC_B.b_atmp = A[motion_controller_withPIC_B.ii];
      A[motion_controller_withPIC_B.ii] = 1.0;
      motion_controll_xzlarf_xH4hoCMV(motion_controller_withPIC_B.mmi_b, (n -
        motion_controller_withPIC_B.i_e) - 1, motion_controller_withPIC_B.ii + 1,
        motion_controller_withPIC_B.tau, A, motion_controller_withPIC_B.ii + 42,
        motion_controller_withPIC_B.work_d);
      A[motion_controller_withPIC_B.ii] = motion_controller_withPIC_B.b_atmp;
    }
  }
}

// Function for MATLAB Function: '<S48>/solvex'
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
      motion_controller_withPIC_B.u1_p = mrows;
    } else {
      motion_controller_withPIC_B.u1_p = ncols;
    }

    obj->minRowCol = motion_controller_withPIC_B.u1_p;
    memset(&obj->tau[0], 0, 41U * sizeof(real_T));
    if (motion_controller_withPIC_B.u1_p < 1) {
      motion_controller_withPIC_B.nfxd = (ncols / 4) << 2;
      motion_controller_withPIC_B.i_n = motion_controller_withPIC_B.nfxd - 4;
      for (motion_controller_withPIC_B.u1_p = 0;
           motion_controller_withPIC_B.u1_p <= motion_controller_withPIC_B.i_n;
           motion_controller_withPIC_B.u1_p += 4) {
        tmp = _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32
          (motion_controller_withPIC_B.u1_p), _mm_loadu_si128((const __m128i *)
          &offsets[0])), _mm_set1_epi32(1));
        _mm_storeu_si128((__m128i *)&obj->jpvt[motion_controller_withPIC_B.u1_p],
                         tmp);
      }

      for (motion_controller_withPIC_B.u1_p = motion_controller_withPIC_B.nfxd;
           motion_controller_withPIC_B.u1_p < ncols;
           motion_controller_withPIC_B.u1_p++) {
        obj->jpvt[motion_controller_withPIC_B.u1_p] =
          motion_controller_withPIC_B.u1_p + 1;
      }
    } else {
      motion_controller_withPIC_B.nfxd = -1;
      for (motion_controller_withPIC_B.i_n = 0; motion_controller_withPIC_B.i_n <
           ncols; motion_controller_withPIC_B.i_n++) {
        if (obj->jpvt[motion_controller_withPIC_B.i_n] != 0) {
          motion_controller_withPIC_B.nfxd++;
          if (motion_controller_withPIC_B.i_n + 1 !=
              motion_controller_withPIC_B.nfxd + 1) {
            motion_controller_withPIC_B.ix_b = motion_controller_withPIC_B.i_n *
              41;
            motion_controller_withPIC_B.iy = motion_controller_withPIC_B.nfxd *
              41;
            for (motion_controller_withPIC_B.mmi = 0;
                 motion_controller_withPIC_B.mmi < mrows;
                 motion_controller_withPIC_B.mmi++) {
              motion_controller_withPIC_B.temp_tmp_j =
                motion_controller_withPIC_B.ix_b +
                motion_controller_withPIC_B.mmi;
              motion_controller_withPIC_B.temp = obj->
                QR[motion_controller_withPIC_B.temp_tmp_j];
              motion_controller_withPIC_B.itemp = motion_controller_withPIC_B.iy
                + motion_controller_withPIC_B.mmi;
              obj->QR[motion_controller_withPIC_B.temp_tmp_j] = obj->
                QR[motion_controller_withPIC_B.itemp];
              obj->QR[motion_controller_withPIC_B.itemp] =
                motion_controller_withPIC_B.temp;
            }

            obj->jpvt[motion_controller_withPIC_B.i_n] = obj->
              jpvt[motion_controller_withPIC_B.nfxd];
            obj->jpvt[motion_controller_withPIC_B.nfxd] =
              motion_controller_withPIC_B.i_n + 1;
          } else {
            obj->jpvt[motion_controller_withPIC_B.i_n] =
              motion_controller_withPIC_B.i_n + 1;
          }
        } else {
          obj->jpvt[motion_controller_withPIC_B.i_n] =
            motion_controller_withPIC_B.i_n + 1;
        }
      }

      if (motion_controller_withPIC_B.nfxd + 1 <=
          motion_controller_withPIC_B.u1_p) {
        motion_controller_withPIC_B.nfxd++;
      } else {
        motion_controller_withPIC_B.nfxd = motion_controller_withPIC_B.u1_p;
      }

      memset(&obj->tau[0], 0, 41U * sizeof(real_T));
      motion_controller__qrf_ELz1YOWw(obj->QR, mrows, ncols,
        motion_controller_withPIC_B.nfxd, obj->tau);
      if (motion_controller_withPIC_B.nfxd < motion_controller_withPIC_B.u1_p) {
        memset(&motion_controller_withPIC_B.work[0], 0, 161U * sizeof(real_T));
        memset(&motion_controller_withPIC_B.vn1[0], 0, 161U * sizeof(real_T));
        memset(&motion_controller_withPIC_B.vn2[0], 0, 161U * sizeof(real_T));
        for (motion_controller_withPIC_B.i_n = motion_controller_withPIC_B.nfxd
             + 1; motion_controller_withPIC_B.i_n <= ncols;
             motion_controller_withPIC_B.i_n++) {
          motion_controller_withPIC_B.temp = motion_controlle_xnrm2_h59MJ9zm
            (mrows - motion_controller_withPIC_B.nfxd, obj->QR,
             ((motion_controller_withPIC_B.i_n - 1) * 41 +
              motion_controller_withPIC_B.nfxd) + 1);
          motion_controller_withPIC_B.vn1[motion_controller_withPIC_B.i_n - 1] =
            motion_controller_withPIC_B.temp;
          motion_controller_withPIC_B.vn2[motion_controller_withPIC_B.i_n - 1] =
            motion_controller_withPIC_B.temp;
        }

        for (motion_controller_withPIC_B.i_n = motion_controller_withPIC_B.nfxd
             + 1; motion_controller_withPIC_B.i_n <=
             motion_controller_withPIC_B.u1_p; motion_controller_withPIC_B.i_n++)
        {
          motion_controller_withPIC_B.temp_tmp_j =
            (motion_controller_withPIC_B.i_n - 1) * 41;
          motion_controller_withPIC_B.ix_b =
            (motion_controller_withPIC_B.temp_tmp_j +
             motion_controller_withPIC_B.i_n) - 1;
          motion_controller_withPIC_B.iy = ncols -
            motion_controller_withPIC_B.i_n;
          motion_controller_withPIC_B.mmi = mrows -
            motion_controller_withPIC_B.i_n;
          if (motion_controller_withPIC_B.iy + 1 < 1) {
            motion_controller_withPIC_B.pvt = -2;
          } else {
            motion_controller_withPIC_B.pvt = -1;
            if (motion_controller_withPIC_B.iy + 1 > 1) {
              motion_controller_withPIC_B.temp = fabs
                (motion_controller_withPIC_B.vn1[motion_controller_withPIC_B.i_n
                 - 1]);
              for (motion_controller_withPIC_B.itemp = 2;
                   motion_controller_withPIC_B.itemp <=
                   motion_controller_withPIC_B.iy + 1;
                   motion_controller_withPIC_B.itemp++) {
                motion_controller_withPIC_B.s = fabs
                  (motion_controller_withPIC_B.vn1
                   [(motion_controller_withPIC_B.i_n +
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

          motion_controller_withPIC_B.pvt += motion_controller_withPIC_B.i_n;
          if (motion_controller_withPIC_B.pvt + 1 !=
              motion_controller_withPIC_B.i_n) {
            motion_controller_withPIC_B.c_ix = motion_controller_withPIC_B.pvt *
              41;
            for (motion_controller_withPIC_B.c_k_h = 0;
                 motion_controller_withPIC_B.c_k_h < mrows;
                 motion_controller_withPIC_B.c_k_h++) {
              motion_controller_withPIC_B.b_temp_tmp_o =
                motion_controller_withPIC_B.c_ix +
                motion_controller_withPIC_B.c_k_h;
              motion_controller_withPIC_B.temp = obj->
                QR[motion_controller_withPIC_B.b_temp_tmp_o];
              motion_controller_withPIC_B.itemp =
                motion_controller_withPIC_B.temp_tmp_j +
                motion_controller_withPIC_B.c_k_h;
              obj->QR[motion_controller_withPIC_B.b_temp_tmp_o] = obj->
                QR[motion_controller_withPIC_B.itemp];
              obj->QR[motion_controller_withPIC_B.itemp] =
                motion_controller_withPIC_B.temp;
            }

            motion_controller_withPIC_B.itemp = obj->
              jpvt[motion_controller_withPIC_B.pvt];
            obj->jpvt[motion_controller_withPIC_B.pvt] = obj->
              jpvt[motion_controller_withPIC_B.i_n - 1];
            obj->jpvt[motion_controller_withPIC_B.i_n - 1] =
              motion_controller_withPIC_B.itemp;
            motion_controller_withPIC_B.vn1[motion_controller_withPIC_B.pvt] =
              motion_controller_withPIC_B.vn1[motion_controller_withPIC_B.i_n -
              1];
            motion_controller_withPIC_B.vn2[motion_controller_withPIC_B.pvt] =
              motion_controller_withPIC_B.vn2[motion_controller_withPIC_B.i_n -
              1];
          }

          if (motion_controller_withPIC_B.i_n < mrows) {
            motion_controller_withPIC_B.temp = obj->
              QR[motion_controller_withPIC_B.ix_b];
            obj->tau[motion_controller_withPIC_B.i_n - 1] =
              motion_control_xzlarfg_91xlzxZq(motion_controller_withPIC_B.mmi +
              1, &motion_controller_withPIC_B.temp, obj->QR,
              motion_controller_withPIC_B.ix_b + 2);
            obj->QR[motion_controller_withPIC_B.ix_b] =
              motion_controller_withPIC_B.temp;
          } else {
            obj->tau[motion_controller_withPIC_B.i_n - 1] = 0.0;
          }

          if (motion_controller_withPIC_B.i_n < ncols) {
            motion_controller_withPIC_B.temp = obj->
              QR[motion_controller_withPIC_B.ix_b];
            obj->QR[motion_controller_withPIC_B.ix_b] = 1.0;
            motion_controll_xzlarf_xH4hoCMV(motion_controller_withPIC_B.mmi + 1,
              motion_controller_withPIC_B.iy, motion_controller_withPIC_B.ix_b +
              1, obj->tau[motion_controller_withPIC_B.i_n - 1], obj->QR,
              motion_controller_withPIC_B.ix_b + 42,
              motion_controller_withPIC_B.work);
            obj->QR[motion_controller_withPIC_B.ix_b] =
              motion_controller_withPIC_B.temp;
          }

          for (motion_controller_withPIC_B.itemp =
               motion_controller_withPIC_B.i_n + 1;
               motion_controller_withPIC_B.itemp <= ncols;
               motion_controller_withPIC_B.itemp++) {
            motion_controller_withPIC_B.ix_b =
              (motion_controller_withPIC_B.itemp - 1) * 41 +
              motion_controller_withPIC_B.i_n;
            motion_controller_withPIC_B.temp =
              motion_controller_withPIC_B.vn1[motion_controller_withPIC_B.itemp
              - 1];
            if (motion_controller_withPIC_B.temp != 0.0) {
              motion_controller_withPIC_B.s = fabs(obj->
                QR[motion_controller_withPIC_B.ix_b - 1]) /
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
                if (motion_controller_withPIC_B.i_n < mrows) {
                  motion_controller_withPIC_B.temp =
                    motion_controlle_xnrm2_h59MJ9zm
                    (motion_controller_withPIC_B.mmi, obj->QR,
                     motion_controller_withPIC_B.ix_b + 1);
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

// Function for MATLAB Function: '<S48>/solvex'
void motion_controller_withPIC::motion_controller_wit_computeQ_
  (s2uO2c2bmaUl7sY5vOWIzHG_motio_T *obj, int32_T nrows)
{
  motion_controller_withPIC_B.i_f = obj->minRowCol;
  for (motion_controller_withPIC_B.idx_n = 0; motion_controller_withPIC_B.idx_n <
       motion_controller_withPIC_B.i_f; motion_controller_withPIC_B.idx_n++) {
    motion_controller_withPIC_B.iQR0 = 41 * motion_controller_withPIC_B.idx_n +
      motion_controller_withPIC_B.idx_n;
    motion_controller_withPIC_B.ia = obj->mrows -
      motion_controller_withPIC_B.idx_n;
    if (motion_controller_withPIC_B.ia - 2 >= 0) {
      memcpy(&obj->Q[motion_controller_withPIC_B.iQR0 + 1], &obj->
             QR[motion_controller_withPIC_B.iQR0 + 1], static_cast<uint32_T>
             (((motion_controller_withPIC_B.ia +
                motion_controller_withPIC_B.iQR0) -
               motion_controller_withPIC_B.iQR0) - 1) * sizeof(real_T));
    }
  }

  motion_controller_withPIC_B.idx_n = obj->mrows;
  if (nrows >= 1) {
    for (motion_controller_withPIC_B.itau = motion_controller_withPIC_B.i_f;
         motion_controller_withPIC_B.itau < nrows;
         motion_controller_withPIC_B.itau++) {
      motion_controller_withPIC_B.ia = motion_controller_withPIC_B.itau * 41;
      memset(&obj->Q[motion_controller_withPIC_B.ia], 0, static_cast<uint32_T>
             ((motion_controller_withPIC_B.idx_n +
               motion_controller_withPIC_B.ia) - motion_controller_withPIC_B.ia)
             * sizeof(real_T));
      obj->Q[motion_controller_withPIC_B.ia + motion_controller_withPIC_B.itau] =
        1.0;
    }

    motion_controller_withPIC_B.itau = obj->minRowCol - 1;
    memset(&motion_controller_withPIC_B.work_j[0], 0, 41U * sizeof(real_T));
    motion_controller_withPIC_B.i_f = obj->minRowCol;
    while (motion_controller_withPIC_B.i_f >= 1) {
      motion_controller_withPIC_B.iQR0 = ((motion_controller_withPIC_B.i_f - 1) *
        41 + motion_controller_withPIC_B.i_f) - 1;
      if (motion_controller_withPIC_B.i_f < nrows) {
        obj->Q[motion_controller_withPIC_B.iQR0] = 1.0;
        motion_controller_withPIC_B.ia = motion_controller_withPIC_B.idx_n -
          motion_controller_withPIC_B.i_f;
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
            motion_controller_withPIC_B.i_f;
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
              memset(&motion_controller_withPIC_B.work_j[0], 0,
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
              motion_controller_withPIC_B.work_j[motion_controller_withPIC_B.jA]
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
                motion_controller_withPIC_B.work_j[motion_controller_withPIC_B.coltop];
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

      if (motion_controller_withPIC_B.i_f < motion_controller_withPIC_B.idx_n) {
        motion_controller_withPIC_B.lastc = ((motion_controller_withPIC_B.iQR0 +
          motion_controller_withPIC_B.idx_n) - motion_controller_withPIC_B.i_f)
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
        (motion_controller_withPIC_B.i_f - 1);
      for (motion_controller_withPIC_B.ia = 0; motion_controller_withPIC_B.ia <
           motion_controller_withPIC_B.lastc; motion_controller_withPIC_B.ia++)
      {
        obj->Q[(motion_controller_withPIC_B.iQR0 -
                motion_controller_withPIC_B.ia) - 1] = 0.0;
      }

      motion_controller_withPIC_B.itau--;
      motion_controller_withPIC_B.i_f--;
    }
  }
}

// Function for MATLAB Function: '<S48>/solvex'
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

  motion_controller_withPIC_B.b_d = static_cast<uint8_T>(nVar);
  memset(&qrmanager->jpvt[0], 0, static_cast<uint32_T>
         (motion_controller_withPIC_B.b_d) * sizeof(int32_T));
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
    motion_controller_withPIC_B.b_d = 0;
    exitg1 = false;
    while ((!exitg1) && (motion_controller_withPIC_B.b_d <= numDependent - 1)) {
      motion_controller_withPIC_B.ix = ((mConstr -
        motion_controller_withPIC_B.b_d) - 1) * 41;
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
        motion_controller_withPIC_B.b_d++;
      }
    }
  }

  return numDependent;
}

// Function for MATLAB Function: '<S48>/solvex'
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

// Function for MATLAB Function: '<S48>/solvex'
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

// Function for MATLAB Function: '<S48>/solvex'
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

// Function for MATLAB Function: '<S48>/solvex'
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

// Function for MATLAB Function: '<S48>/solvex'
void motion_controller_withPIC::motion_controller_with_factorQR
  (s2uO2c2bmaUl7sY5vOWIzHG_motio_T *obj, const real_T A[6601], int32_T mrows,
   int32_T ncols)
{
  static const int32_T offsets[4] = { 0, 1, 2, 3 };

  __m128i tmp;
  boolean_T guard1;
  motion_controller_withPIC_B.k_no = mrows * ncols;
  guard1 = false;
  if (motion_controller_withPIC_B.k_no > 0) {
    for (motion_controller_withPIC_B.i_hl = 0; motion_controller_withPIC_B.i_hl <
         ncols; motion_controller_withPIC_B.i_hl++) {
      motion_controller_withPIC_B.ix0_tmp_m = 41 *
        motion_controller_withPIC_B.i_hl;
      motion_controller_withPIC_B.k_no = static_cast<uint8_T>(mrows);
      memcpy(&obj->QR[motion_controller_withPIC_B.ix0_tmp_m],
             &A[motion_controller_withPIC_B.ix0_tmp_m], static_cast<uint32_T>
             ((motion_controller_withPIC_B.k_no +
               motion_controller_withPIC_B.ix0_tmp_m) -
              motion_controller_withPIC_B.ix0_tmp_m) * sizeof(real_T));
    }

    guard1 = true;
  } else if (motion_controller_withPIC_B.k_no == 0) {
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
    motion_controller_withPIC_B.k_no = (ncols / 4) << 2;
    motion_controller_withPIC_B.ix0_tmp_m = motion_controller_withPIC_B.k_no - 4;
    for (motion_controller_withPIC_B.i_hl = 0; motion_controller_withPIC_B.i_hl <=
         motion_controller_withPIC_B.ix0_tmp_m; motion_controller_withPIC_B.i_hl
         += 4) {
      tmp = _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32
        (motion_controller_withPIC_B.i_hl), _mm_loadu_si128((const __m128i *)
        &offsets[0])), _mm_set1_epi32(1));
      _mm_storeu_si128((__m128i *)&obj->jpvt[motion_controller_withPIC_B.i_hl],
                       tmp);
    }

    for (motion_controller_withPIC_B.i_hl = motion_controller_withPIC_B.k_no;
         motion_controller_withPIC_B.i_hl < ncols;
         motion_controller_withPIC_B.i_hl++) {
      obj->jpvt[motion_controller_withPIC_B.i_hl] =
        motion_controller_withPIC_B.i_hl + 1;
    }

    if (mrows <= ncols) {
      motion_controller_withPIC_B.k_no = mrows;
    } else {
      motion_controller_withPIC_B.k_no = ncols;
    }

    obj->minRowCol = motion_controller_withPIC_B.k_no;
    memset(&obj->tau[0], 0, 41U * sizeof(real_T));
    if (motion_controller_withPIC_B.k_no >= 1) {
      memset(&obj->tau[0], 0, 41U * sizeof(real_T));
      motion_controller__qrf_ELz1YOWw(obj->QR, mrows, ncols,
        motion_controller_withPIC_B.k_no, obj->tau);
    }
  }
}

// Function for MATLAB Function: '<S48>/solvex'
void motion_controller_withPIC::motion_controlle_xgemv_kCjzUKKr(int32_T m, const
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
    motion_controller_withPIC_B.c_g3 = 0.0;
    motion_controller_withPIC_B.b_ch = motion_controller_withPIC_B.b_iy_m + m;
    for (motion_controller_withPIC_B.ia_g = motion_controller_withPIC_B.b_iy_m +
         1; motion_controller_withPIC_B.ia_g <= motion_controller_withPIC_B.b_ch;
         motion_controller_withPIC_B.ia_g++) {
      motion_controller_withPIC_B.c_g3 += x[(motion_controller_withPIC_B.ia_g -
        motion_controller_withPIC_B.b_iy_m) - 1] *
        A[motion_controller_withPIC_B.ia_g - 1];
    }

    motion_controller_withPIC_B.ia_g = div_nde_s32_floor
      (motion_controller_withPIC_B.b_iy_m, 41);
    y[motion_controller_withPIC_B.ia_g] += motion_controller_withPIC_B.c_g3;
  }
}

// Function for MATLAB Function: '<S48>/solvex'
void motion_controller_withPIC::motion_controlle_xgemv_vsfN2o0d(int32_T m, const
  real_T A[3280], const real_T x[6601], real_T y[161])
{
  for (motion_controller_withPIC_B.b_iy_n = 0;
       motion_controller_withPIC_B.b_iy_n <= 78;
       motion_controller_withPIC_B.b_iy_n += 2) {
    __m128d tmp;
    tmp = _mm_loadu_pd(&y[motion_controller_withPIC_B.b_iy_n]);
    _mm_storeu_pd(&y[motion_controller_withPIC_B.b_iy_n], _mm_mul_pd(tmp,
      _mm_set1_pd(-1.0)));
  }

  for (motion_controller_withPIC_B.b_iy_n = 0;
       motion_controller_withPIC_B.b_iy_n <= 3239;
       motion_controller_withPIC_B.b_iy_n += 41) {
    motion_controller_withPIC_B.c_j3 = 0.0;
    motion_controller_withPIC_B.b_o = motion_controller_withPIC_B.b_iy_n + m;
    for (motion_controller_withPIC_B.ia_en = motion_controller_withPIC_B.b_iy_n
         + 1; motion_controller_withPIC_B.ia_en <=
         motion_controller_withPIC_B.b_o; motion_controller_withPIC_B.ia_en++) {
      motion_controller_withPIC_B.c_j3 += x[(motion_controller_withPIC_B.ia_en -
        motion_controller_withPIC_B.b_iy_n) + 160] *
        A[motion_controller_withPIC_B.ia_en - 1];
    }

    motion_controller_withPIC_B.ia_en = div_nde_s32_floor
      (motion_controller_withPIC_B.b_iy_n, 41);
    y[motion_controller_withPIC_B.ia_en] += motion_controller_withPIC_B.c_j3;
  }
}

// Function for MATLAB Function: '<S48>/solvex'
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
    for (motion_controller_withPIC_B.idx_b = 0;
         motion_controller_withPIC_B.idx_b <=
         motion_controller_withPIC_B.mWConstr_tmp_tmp;
         motion_controller_withPIC_B.idx_b++) {
      workspace[motion_controller_withPIC_B.idx_b] = workingset->
        bwset[motion_controller_withPIC_B.idx_b];
      workspace[motion_controller_withPIC_B.idx_b + 161] = workingset->
        bwset[motion_controller_withPIC_B.idx_b];
    }

    if (workingset->nActiveConstr != 0) {
      motion_controller_withPIC_B.d_a = (workingset->nActiveConstr - 1) * 41 + 1;
      for (motion_controller_withPIC_B.iac = 1; motion_controller_withPIC_B.iac <=
           motion_controller_withPIC_B.d_a; motion_controller_withPIC_B.iac +=
           41) {
        motion_controller_withPIC_B.c = 0.0;
        motion_controller_withPIC_B.jBcol = (motion_controller_withPIC_B.iac +
          motion_controller_withPIC_B.nVar_tmp_tmp) - 1;
        for (motion_controller_withPIC_B.idx_b = motion_controller_withPIC_B.iac;
             motion_controller_withPIC_B.idx_b <=
             motion_controller_withPIC_B.jBcol;
             motion_controller_withPIC_B.idx_b++) {
          motion_controller_withPIC_B.c += workingset->
            ATwset[motion_controller_withPIC_B.idx_b - 1] *
            xCurrent[motion_controller_withPIC_B.idx_b -
            motion_controller_withPIC_B.iac];
        }

        motion_controller_withPIC_B.idx_b = div_nde_s32_floor
          (motion_controller_withPIC_B.iac - 1, 41);
        workspace[motion_controller_withPIC_B.idx_b] -=
          motion_controller_withPIC_B.c;
      }
    }

    if (workingset->nActiveConstr >= workingset->nVar) {
      motion_controller_withPIC_B.d_a = static_cast<uint8_T>(workingset->nVar);
      for (motion_controller_withPIC_B.idx_b = 0;
           motion_controller_withPIC_B.idx_b < motion_controller_withPIC_B.d_a;
           motion_controller_withPIC_B.idx_b++) {
        motion_controller_withPIC_B.jBcol = 41 *
          motion_controller_withPIC_B.idx_b;
        for (motion_controller_withPIC_B.iac = 0;
             motion_controller_withPIC_B.iac <=
             motion_controller_withPIC_B.mWConstr_tmp_tmp;
             motion_controller_withPIC_B.iac++) {
          qrmanager->QR[motion_controller_withPIC_B.iac +
            motion_controller_withPIC_B.jBcol] = workingset->ATwset[41 *
            motion_controller_withPIC_B.iac + motion_controller_withPIC_B.idx_b];
        }
      }

      qrmanager->usedPivoting = false;
      qrmanager->mrows = workingset->nActiveConstr;
      qrmanager->ncols = workingset->nVar;
      motion_controller_withPIC_B.jBcol = (static_cast<uint8_T>(workingset->nVar)
        / 4) << 2;
      motion_controller_withPIC_B.iAcol = motion_controller_withPIC_B.jBcol - 4;
      for (motion_controller_withPIC_B.idx_b = 0;
           motion_controller_withPIC_B.idx_b <=
           motion_controller_withPIC_B.iAcol; motion_controller_withPIC_B.idx_b +=
           4) {
        tmp_1 = _mm_add_epi32(_mm_add_epi32(_mm_set1_epi32
          (motion_controller_withPIC_B.idx_b), _mm_loadu_si128((const __m128i *)
          &offsets[0])), _mm_set1_epi32(1));
        _mm_storeu_si128((__m128i *)&qrmanager->
                         jpvt[motion_controller_withPIC_B.idx_b], tmp_1);
      }

      for (motion_controller_withPIC_B.idx_b = motion_controller_withPIC_B.jBcol;
           motion_controller_withPIC_B.idx_b < motion_controller_withPIC_B.d_a;
           motion_controller_withPIC_B.idx_b++) {
        qrmanager->jpvt[motion_controller_withPIC_B.idx_b] =
          motion_controller_withPIC_B.idx_b + 1;
      }

      if (workingset->nActiveConstr <= workingset->nVar) {
        motion_controller_withPIC_B.idx_b = workingset->nActiveConstr;
      } else {
        motion_controller_withPIC_B.idx_b = workingset->nVar;
      }

      qrmanager->minRowCol = motion_controller_withPIC_B.idx_b;
      memcpy(&motion_controller_withPIC_B.B[0], &qrmanager->QR[0], 6601U *
             sizeof(real_T));
      memset(&qrmanager->tau[0], 0, 41U * sizeof(real_T));
      if (motion_controller_withPIC_B.idx_b >= 1) {
        memset(&qrmanager->tau[0], 0, 41U * sizeof(real_T));
        motion_controller__qrf_ELz1YOWw(motion_controller_withPIC_B.B,
          workingset->nActiveConstr, workingset->nVar,
          motion_controller_withPIC_B.idx_b, qrmanager->tau);
      }

      memcpy(&qrmanager->QR[0], &motion_controller_withPIC_B.B[0], 6601U *
             sizeof(real_T));
      motion_controller_wit_computeQ_(qrmanager, qrmanager->mrows);
      memcpy(&motion_controller_withPIC_B.B[0], &workspace[0], 6601U * sizeof
             (real_T));
      for (motion_controller_withPIC_B.idx_b = 0;
           motion_controller_withPIC_B.idx_b <= 161;
           motion_controller_withPIC_B.idx_b += 161) {
        motion_controller_withPIC_B.d_a = motion_controller_withPIC_B.idx_b +
          motion_controller_withPIC_B.nVar_tmp_tmp;
        for (motion_controller_withPIC_B.iac = motion_controller_withPIC_B.idx_b
             + 1; motion_controller_withPIC_B.iac <=
             motion_controller_withPIC_B.d_a; motion_controller_withPIC_B.iac++)
        {
          workspace[motion_controller_withPIC_B.iac - 1] = 0.0;
        }
      }

      motion_controller_withPIC_B.jBcol = -1;
      for (motion_controller_withPIC_B.idx_b = 0;
           motion_controller_withPIC_B.idx_b <= 161;
           motion_controller_withPIC_B.idx_b += 161) {
        motion_controller_withPIC_B.iAcol = -1;
        motion_controller_withPIC_B.br = motion_controller_withPIC_B.idx_b +
          motion_controller_withPIC_B.nVar_tmp_tmp;
        for (motion_controller_withPIC_B.iac = motion_controller_withPIC_B.idx_b
             + 1; motion_controller_withPIC_B.iac <=
             motion_controller_withPIC_B.br; motion_controller_withPIC_B.iac++)
        {
          motion_controller_withPIC_B.c = 0.0;
          for (motion_controller_withPIC_B.d_a = 0;
               motion_controller_withPIC_B.d_a <=
               motion_controller_withPIC_B.mWConstr_tmp_tmp;
               motion_controller_withPIC_B.d_a++) {
            motion_controller_withPIC_B.c += qrmanager->Q
              [(motion_controller_withPIC_B.d_a +
                motion_controller_withPIC_B.iAcol) + 1] *
              motion_controller_withPIC_B.B[(motion_controller_withPIC_B.d_a +
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
        for (motion_controller_withPIC_B.d_a =
             motion_controller_withPIC_B.nVar_tmp_tmp;
             motion_controller_withPIC_B.d_a >= 1;
             motion_controller_withPIC_B.d_a--) {
          motion_controller_withPIC_B.br = (motion_controller_withPIC_B.d_a - 1)
            * 41;
          motion_controller_withPIC_B.idx_b = motion_controller_withPIC_B.d_a +
            motion_controller_withPIC_B.iAcol;
          motion_controller_withPIC_B.c =
            workspace[motion_controller_withPIC_B.idx_b];
          if (motion_controller_withPIC_B.c != 0.0) {
            workspace[motion_controller_withPIC_B.idx_b] =
              motion_controller_withPIC_B.c / qrmanager->QR
              [(motion_controller_withPIC_B.d_a + motion_controller_withPIC_B.br)
              - 1];
            motion_controller_withPIC_B.ar = static_cast<uint8_T>
              (motion_controller_withPIC_B.d_a - 1);
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
                workspace[motion_controller_withPIC_B.idx_b];
            }
          }
        }
      }
    } else {
      motion_controller_with_factorQR(qrmanager, workingset->ATwset,
        workingset->nVar, workingset->nActiveConstr);
      motion_controller_wit_computeQ_(qrmanager, qrmanager->minRowCol);
      for (motion_controller_withPIC_B.idx_b = 0;
           motion_controller_withPIC_B.idx_b < 2;
           motion_controller_withPIC_B.idx_b++) {
        motion_controller_withPIC_B.jBcol = 161 *
          motion_controller_withPIC_B.idx_b;
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
          for (motion_controller_withPIC_B.d_a = 0;
               motion_controller_withPIC_B.d_a < motion_controller_withPIC_B.ar;
               motion_controller_withPIC_B.d_a++) {
            motion_controller_withPIC_B.c -= qrmanager->
              QR[motion_controller_withPIC_B.d_a +
              motion_controller_withPIC_B.iAcol] *
              workspace[motion_controller_withPIC_B.d_a +
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
      for (motion_controller_withPIC_B.idx_b = 0;
           motion_controller_withPIC_B.idx_b <= 161;
           motion_controller_withPIC_B.idx_b += 161) {
        motion_controller_withPIC_B.d_a = motion_controller_withPIC_B.idx_b +
          motion_controller_withPIC_B.nVar_tmp_tmp;
        for (motion_controller_withPIC_B.iac = motion_controller_withPIC_B.idx_b
             + 1; motion_controller_withPIC_B.iac <=
             motion_controller_withPIC_B.d_a; motion_controller_withPIC_B.iac++)
        {
          workspace[motion_controller_withPIC_B.iac - 1] = 0.0;
        }
      }

      motion_controller_withPIC_B.br = 1;
      for (motion_controller_withPIC_B.idx_b = 0;
           motion_controller_withPIC_B.idx_b <= 161;
           motion_controller_withPIC_B.idx_b += 161) {
        motion_controller_withPIC_B.ar = -1;
        motion_controller_withPIC_B.h = motion_controller_withPIC_B.br +
          motion_controller_withPIC_B.mWConstr_tmp_tmp;
        for (motion_controller_withPIC_B.iac = motion_controller_withPIC_B.br;
             motion_controller_withPIC_B.iac <= motion_controller_withPIC_B.h;
             motion_controller_withPIC_B.iac++) {
          motion_controller_withPIC_B.l_i = motion_controller_withPIC_B.idx_b +
            motion_controller_withPIC_B.nVar_tmp_tmp;
          motion_controller_withPIC_B.jBcol =
            ((((motion_controller_withPIC_B.l_i -
                motion_controller_withPIC_B.idx_b) / 2) << 1) +
             motion_controller_withPIC_B.idx_b) + 1;
          motion_controller_withPIC_B.iAcol = motion_controller_withPIC_B.jBcol
            - 2;
          for (motion_controller_withPIC_B.d_a =
               motion_controller_withPIC_B.idx_b + 1;
               motion_controller_withPIC_B.d_a <=
               motion_controller_withPIC_B.iAcol;
               motion_controller_withPIC_B.d_a += 2) {
            tmp = _mm_loadu_pd(&qrmanager->Q[(motion_controller_withPIC_B.ar +
              motion_controller_withPIC_B.d_a) -
                               motion_controller_withPIC_B.idx_b]);
            tmp_0 = _mm_loadu_pd(&workspace[motion_controller_withPIC_B.d_a - 1]);
            _mm_storeu_pd(&workspace[motion_controller_withPIC_B.d_a - 1],
                          _mm_add_pd(_mm_mul_pd(tmp, _mm_set1_pd
              (motion_controller_withPIC_B.B[motion_controller_withPIC_B.iac - 1])),
              tmp_0));
          }

          for (motion_controller_withPIC_B.d_a =
               motion_controller_withPIC_B.jBcol;
               motion_controller_withPIC_B.d_a <=
               motion_controller_withPIC_B.l_i; motion_controller_withPIC_B.d_a
               ++) {
            workspace[motion_controller_withPIC_B.d_a - 1] += qrmanager->Q
              [(motion_controller_withPIC_B.ar + motion_controller_withPIC_B.d_a)
              - motion_controller_withPIC_B.idx_b] *
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
          motion_controller_withPIC_B.idx_b = static_cast<uint8_T>
            (workingset->sizes[3]);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp <
               motion_controller_withPIC_B.idx_b;
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
          motion_controller_withPIC_B.idx_b = static_cast<uint8_T>
            (workingset->sizes[4]);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp <
               motion_controller_withPIC_B.idx_b;
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
          motion_controller_withPIC_B.idx_b = static_cast<uint8_T>
            (workingset->sizes[0]);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp <
               motion_controller_withPIC_B.idx_b;
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
          motion_controller_withPIC_B.idx_b = static_cast<uint8_T>
            (workingset->sizes[3]);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp <
               motion_controller_withPIC_B.idx_b;
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
          motion_controller_withPIC_B.idx_b = static_cast<uint8_T>
            (workingset->sizes[4]);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp <
               motion_controller_withPIC_B.idx_b;
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
          motion_controller_withPIC_B.idx_b = static_cast<uint8_T>
            (workingset->sizes[0]);
          for (motion_controller_withPIC_B.mWConstr_tmp_tmp = 0;
               motion_controller_withPIC_B.mWConstr_tmp_tmp <
               motion_controller_withPIC_B.idx_b;
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

// Function for MATLAB Function: '<S48>/solvex'
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

// Function for MATLAB Function: '<S48>/solvex'
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

// Function for MATLAB Function: '<S48>/solvex'
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

// Function for MATLAB Function: '<S48>/solvex'
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

// Function for MATLAB Function: '<S48>/solvex'
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

// Function for MATLAB Function: '<S48>/solvex'
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

// Function for MATLAB Function: '<S48>/solvex'
void motion_controller_withPIC::motion_control_deleteColMoveEnd
  (s2uO2c2bmaUl7sY5vOWIzHG_motio_T *obj, int32_T idx)
{
  if (obj->usedPivoting) {
    motion_controller_withPIC_B.i_ok1 = 1;
    while ((motion_controller_withPIC_B.i_ok1 <= obj->ncols) && (obj->
            jpvt[motion_controller_withPIC_B.i_ok1 - 1] != idx)) {
      motion_controller_withPIC_B.i_ok1++;
    }

    idx = motion_controller_withPIC_B.i_ok1;
  }

  if (idx >= obj->ncols) {
    obj->ncols--;
  } else {
    obj->jpvt[idx - 1] = obj->jpvt[obj->ncols - 1];
    motion_controller_withPIC_B.QRk0 = obj->minRowCol;
    for (motion_controller_withPIC_B.i_ok1 = 0;
         motion_controller_withPIC_B.i_ok1 < motion_controller_withPIC_B.QRk0;
         motion_controller_withPIC_B.i_ok1++) {
      obj->QR[motion_controller_withPIC_B.i_ok1 + 41 * (idx - 1)] = obj->QR
        [(obj->ncols - 1) * 41 + motion_controller_withPIC_B.i_ok1];
    }

    obj->ncols--;
    if (obj->mrows <= obj->ncols) {
      obj->minRowCol = obj->mrows;
    } else {
      obj->minRowCol = obj->ncols;
    }

    if (idx < obj->mrows) {
      if (obj->mrows - 1 <= obj->ncols) {
        motion_controller_withPIC_B.i_ok1 = obj->mrows - 1;
      } else {
        motion_controller_withPIC_B.i_ok1 = obj->ncols;
      }

      motion_controller_withPIC_B.k_g = motion_controller_withPIC_B.i_ok1;
      motion_controller_withPIC_B.idxRotGCol = (idx - 1) * 41;
      while (motion_controller_withPIC_B.k_g >= idx) {
        motion_controller_withPIC_B.QRk0 = motion_controller_withPIC_B.k_g +
          motion_controller_withPIC_B.idxRotGCol;
        motion_controller_withPIC_B.b_temp = obj->
          QR[motion_controller_withPIC_B.QRk0];
        motion_controlle_xrotg_ds3XgDMS(&obj->
          QR[motion_controller_withPIC_B.QRk0 - 1],
          &motion_controller_withPIC_B.b_temp, &motion_controller_withPIC_B.c_c,
          &motion_controller_withPIC_B.b_s);
        obj->QR[motion_controller_withPIC_B.QRk0] =
          motion_controller_withPIC_B.b_temp;
        motion_controller_withPIC_B.e_k = (motion_controller_withPIC_B.k_g - 1) *
          41;
        obj->QR[motion_controller_withPIC_B.k_g +
          motion_controller_withPIC_B.e_k] = 0.0;
        motion_controller_withPIC_B.QRk0 = 41 * idx +
          motion_controller_withPIC_B.k_g;
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

        motion_controller_withPIC_B.k_g--;
      }

      for (motion_controller_withPIC_B.k_g = idx + 1;
           motion_controller_withPIC_B.k_g <= motion_controller_withPIC_B.i_ok1;
           motion_controller_withPIC_B.k_g++) {
        motion_controller_withPIC_B.idxRotGCol =
          (motion_controller_withPIC_B.k_g - 1) * 41;
        motion_controller_withPIC_B.QRk0 = motion_controller_withPIC_B.k_g +
          motion_controller_withPIC_B.idxRotGCol;
        motion_controller_withPIC_B.b_temp = obj->
          QR[motion_controller_withPIC_B.QRk0];
        motion_controlle_xrotg_ds3XgDMS(&obj->
          QR[motion_controller_withPIC_B.QRk0 - 1],
          &motion_controller_withPIC_B.b_temp, &motion_controller_withPIC_B.c_c,
          &motion_controller_withPIC_B.b_s);
        obj->QR[motion_controller_withPIC_B.QRk0] =
          motion_controller_withPIC_B.b_temp;
        motion_controller_withPIC_B.QRk0 = motion_controller_withPIC_B.k_g * 42;
        motion_controller_withPIC_B.b_n = obj->ncols -
          motion_controller_withPIC_B.k_g;
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

// Function for MATLAB Function: '<S48>/solvex'
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

    motion_controller_withPIC_B.alpha1 = -1.0 /
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

    if (!(motion_controller_withPIC_B.alpha1 == 0.0)) {
      motion_controller_withPIC_B.jA_n =
        motion_controller_withPIC_B.LD_diagOffset + 43;
      for (motion_controller_withPIC_B.b_k = 0; motion_controller_withPIC_B.b_k <=
           motion_controller_withPIC_B.subMatrixDim;
           motion_controller_withPIC_B.b_k++) {
        motion_controller_withPIC_B.temp_m = obj->
          workspace_[motion_controller_withPIC_B.b_k];
        if (motion_controller_withPIC_B.temp_m != 0.0) {
          motion_controller_withPIC_B.temp_m *=
            motion_controller_withPIC_B.alpha1;
          motion_controller_withPIC_B.b_f =
            motion_controller_withPIC_B.subMatrixDim +
            motion_controller_withPIC_B.jA_n;
          for (motion_controller_withPIC_B.ijA =
               motion_controller_withPIC_B.jA_n; motion_controller_withPIC_B.ijA
               <= motion_controller_withPIC_B.b_f;
               motion_controller_withPIC_B.ijA++) {
            obj->FMat[motion_controller_withPIC_B.ijA - 1] += obj->
              workspace_[motion_controller_withPIC_B.ijA -
              motion_controller_withPIC_B.jA_n] *
              motion_controller_withPIC_B.temp_m;
          }
        }

        motion_controller_withPIC_B.jA_n += 41;
      }
    }

    motion_controller_withPIC_B.alpha1 = 1.0 / obj->
      FMat[motion_controller_withPIC_B.LD_diagOffset];
    motion_controller_withPIC_B.b_k = motion_controller_withPIC_B.LD_diagOffset
      + motion_controller_withPIC_B.subMatrixDim;
    motion_controller_withPIC_B.ijA = (((((motion_controller_withPIC_B.b_k -
      motion_controller_withPIC_B.LD_diagOffset) + 1) / 2) << 1) +
      motion_controller_withPIC_B.LD_diagOffset) + 2;
    motion_controller_withPIC_B.jA_n = motion_controller_withPIC_B.ijA - 2;
    for (motion_controller_withPIC_B.subMatrixDim =
         motion_controller_withPIC_B.LD_diagOffset + 2;
         motion_controller_withPIC_B.subMatrixDim <=
         motion_controller_withPIC_B.jA_n;
         motion_controller_withPIC_B.subMatrixDim += 2) {
      __m128d tmp;
      tmp = _mm_loadu_pd(&obj->FMat[motion_controller_withPIC_B.subMatrixDim - 1]);
      _mm_storeu_pd(&obj->FMat[motion_controller_withPIC_B.subMatrixDim - 1],
                    _mm_mul_pd(tmp, _mm_set1_pd
        (motion_controller_withPIC_B.alpha1)));
    }

    for (motion_controller_withPIC_B.subMatrixDim =
         motion_controller_withPIC_B.ijA;
         motion_controller_withPIC_B.subMatrixDim <=
         motion_controller_withPIC_B.b_k + 2;
         motion_controller_withPIC_B.subMatrixDim++) {
      obj->FMat[motion_controller_withPIC_B.subMatrixDim - 1] *=
        motion_controller_withPIC_B.alpha1;
    }
  }

  motion_controller_withPIC_B.lastDiag = (NColsRemain - 1) * 42;
  if (fabs(obj->FMat[motion_controller_withPIC_B.lastDiag]) <= obj->regTol_) {
    obj->FMat[motion_controller_withPIC_B.lastDiag] += REG_PRIMAL;
  }
}

// Function for MATLAB Function: '<S48>/solvex'
void motion_controller_withPIC::motion_controlle_compute_deltax(const real_T H
  [1600], s5cJJO9CAPQxuVG0iaeiP4F_motio_T *solution,
  sFlCINAYeIgPgx0UwEHpaMF_motio_T *memspace, const
  s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager, s8kZFjDlzP6eNfOekUiP5MF_motio_T
  *cholmanager, const sKnhLiTH4yv7eF1oV2a74RG_motio_T *objective)
{
  __m128d tmp;
  __m128d tmp_0;
  int32_T exitg1;
  motion_controller_withPIC_B.nVar_d = qrmanager->mrows - 1;
  motion_controller_withPIC_B.mNull_tmp = qrmanager->mrows - qrmanager->ncols;
  if (motion_controller_withPIC_B.mNull_tmp <= 0) {
    if (motion_controller_withPIC_B.nVar_d >= 0) {
      memset(&solution->searchDir[0], 0, static_cast<uint32_T>
             (motion_controller_withPIC_B.nVar_d + 1) * sizeof(real_T));
    }
  } else {
    motion_controller_withPIC_B.b_ar = (qrmanager->mrows / 2) << 1;
    motion_controller_withPIC_B.vectorUB_j = motion_controller_withPIC_B.b_ar -
      2;
    for (motion_controller_withPIC_B.A_maxDiag_idx = 0;
         motion_controller_withPIC_B.A_maxDiag_idx <=
         motion_controller_withPIC_B.vectorUB_j;
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
         motion_controller_withPIC_B.nVar_d;
         motion_controller_withPIC_B.A_maxDiag_idx++) {
      solution->searchDir[motion_controller_withPIC_B.A_maxDiag_idx] =
        -objective->grad[motion_controller_withPIC_B.A_maxDiag_idx];
    }

    if (qrmanager->ncols <= 0) {
      if (objective->objtype == 3) {
        motion_controller_withPIC_B.temp_l = 1.4901161193847656E-6 *
          static_cast<real_T>(qrmanager->mrows);
        cholmanager->ndims = qrmanager->mrows;
        for (motion_controller_withPIC_B.mNull_tmp = 0;
             motion_controller_withPIC_B.mNull_tmp <=
             motion_controller_withPIC_B.nVar_d;
             motion_controller_withPIC_B.mNull_tmp++) {
          motion_controller_withPIC_B.nullStartIdx =
            (motion_controller_withPIC_B.nVar_d + 1) *
            motion_controller_withPIC_B.mNull_tmp;
          motion_controller_withPIC_B.nVars = 41 *
            motion_controller_withPIC_B.mNull_tmp;
          for (motion_controller_withPIC_B.A_maxDiag_idx = 0;
               motion_controller_withPIC_B.A_maxDiag_idx <=
               motion_controller_withPIC_B.nVar_d;
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
                 motion_controller_withPIC_B.nVar_d + 1;
                 motion_controller_withPIC_B.mNull_tmp++) {
              motion_controller_withPIC_B.s_g = fabs(cholmanager->FMat
                [(motion_controller_withPIC_B.mNull_tmp - 1) * 42]);
              if (motion_controller_withPIC_B.s_g >
                  motion_controller_withPIC_B.smax) {
                motion_controller_withPIC_B.A_maxDiag_idx =
                  motion_controller_withPIC_B.mNull_tmp - 1;
                motion_controller_withPIC_B.smax =
                  motion_controller_withPIC_B.s_g;
              }
            }
          }
        }

        motion_controller_withPIC_B.smax = fabs(cholmanager->FMat[41 *
          motion_controller_withPIC_B.A_maxDiag_idx +
          motion_controller_withPIC_B.A_maxDiag_idx]) * 2.2204460492503131E-16;
        motion_controller_withPIC_B.s_g = fabs
          (motion_controller_withPIC_B.temp_l);
        if (motion_controller_withPIC_B.smax >= motion_controller_withPIC_B.s_g)
        {
          cholmanager->regTol_ = motion_controller_withPIC_B.smax;
        } else {
          cholmanager->regTol_ = motion_controller_withPIC_B.s_g;
        }

        motion_controller__fullColLDL2_(cholmanager, qrmanager->mrows,
          motion_controller_withPIC_B.temp_l);
        if (cholmanager->ConvexCheck) {
          motion_controller_withPIC_B.mNull_tmp = 0;
          do {
            exitg1 = 0;
            if (motion_controller_withPIC_B.mNull_tmp <=
                motion_controller_withPIC_B.nVar_d) {
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
          motion_controller_withPIC_B.nVar_d = cholmanager->ndims - 1;
          if (cholmanager->ndims != 0) {
            for (motion_controller_withPIC_B.mNull_tmp = 0;
                 motion_controller_withPIC_B.mNull_tmp <=
                 motion_controller_withPIC_B.nVar_d;
                 motion_controller_withPIC_B.mNull_tmp++) {
              motion_controller_withPIC_B.nullStartIdx =
                motion_controller_withPIC_B.mNull_tmp * 41 +
                motion_controller_withPIC_B.mNull_tmp;
              motion_controller_withPIC_B.nVars =
                motion_controller_withPIC_B.nVar_d -
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

          motion_controller_withPIC_B.nVar_d = cholmanager->ndims;
          for (motion_controller_withPIC_B.mNull_tmp = 0;
               motion_controller_withPIC_B.mNull_tmp <
               motion_controller_withPIC_B.nVar_d;
               motion_controller_withPIC_B.mNull_tmp++) {
            solution->searchDir[motion_controller_withPIC_B.mNull_tmp] /=
              cholmanager->FMat[41 * motion_controller_withPIC_B.mNull_tmp +
              motion_controller_withPIC_B.mNull_tmp];
          }

          if (cholmanager->ndims != 0) {
            for (motion_controller_withPIC_B.mNull_tmp =
                 motion_controller_withPIC_B.nVar_d;
                 motion_controller_withPIC_B.mNull_tmp >= 1;
                 motion_controller_withPIC_B.mNull_tmp--) {
              motion_controller_withPIC_B.nullStartIdx =
                (motion_controller_withPIC_B.mNull_tmp - 1) * 41;
              motion_controller_withPIC_B.temp_l = solution->
                searchDir[motion_controller_withPIC_B.mNull_tmp - 1];
              for (motion_controller_withPIC_B.A_maxDiag_idx =
                   motion_controller_withPIC_B.nVar_d;
                   motion_controller_withPIC_B.A_maxDiag_idx >=
                   motion_controller_withPIC_B.mNull_tmp + 1;
                   motion_controller_withPIC_B.A_maxDiag_idx--) {
                motion_controller_withPIC_B.temp_l -= cholmanager->FMat
                  [(motion_controller_withPIC_B.nullStartIdx +
                    motion_controller_withPIC_B.A_maxDiag_idx) - 1] *
                  solution->searchDir[motion_controller_withPIC_B.A_maxDiag_idx
                  - 1];
              }

              solution->searchDir[motion_controller_withPIC_B.mNull_tmp - 1] =
                motion_controller_withPIC_B.temp_l;
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
            motion_controller_withPIC_B.nVar_d];
        }

        xgemv_L5SThEQW(qrmanager->mrows, motion_controller_withPIC_B.mNull_tmp,
                       qrmanager->Q, motion_controller_withPIC_B.A_maxDiag_idx +
                       1, memspace->workspace_double, solution->searchDir);
      } else {
        if (objective->objtype == 3) {
          motion_controller_withPIC_B.nVars = qrmanager->mrows;
          if ((qrmanager->mrows != 0) && (motion_controller_withPIC_B.mNull_tmp
               != 0)) {
            motion_controller_withPIC_B.br_i =
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
              motion_controller_withPIC_B.ar_n = -1;
              motion_controller_withPIC_B.h_b = motion_controller_withPIC_B.br_i
                + motion_controller_withPIC_B.nVars;
              for (motion_controller_withPIC_B.ic =
                   motion_controller_withPIC_B.br_i + 1;
                   motion_controller_withPIC_B.ic <=
                   motion_controller_withPIC_B.h_b;
                   motion_controller_withPIC_B.ic++) {
                motion_controller_withPIC_B.i_b =
                  motion_controller_withPIC_B.b_A_maxDiag_idx +
                  motion_controller_withPIC_B.nVars;
                motion_controller_withPIC_B.b_ar =
                  ((((motion_controller_withPIC_B.i_b -
                      motion_controller_withPIC_B.b_A_maxDiag_idx) / 2) << 1) +
                   motion_controller_withPIC_B.b_A_maxDiag_idx) + 1;
                motion_controller_withPIC_B.vectorUB_j =
                  motion_controller_withPIC_B.b_ar - 2;
                for (motion_controller_withPIC_B.e_ix =
                     motion_controller_withPIC_B.b_A_maxDiag_idx + 1;
                     motion_controller_withPIC_B.e_ix <=
                     motion_controller_withPIC_B.vectorUB_j;
                     motion_controller_withPIC_B.e_ix += 2) {
                  tmp_0 = _mm_loadu_pd(&H[(motion_controller_withPIC_B.ar_n +
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
                     motion_controller_withPIC_B.i_b;
                     motion_controller_withPIC_B.e_ix++) {
                  memspace->workspace_double[motion_controller_withPIC_B.e_ix -
                    1] += H[(motion_controller_withPIC_B.ar_n +
                             motion_controller_withPIC_B.e_ix) -
                    motion_controller_withPIC_B.b_A_maxDiag_idx] * qrmanager->
                    Q[motion_controller_withPIC_B.ic - 1];
                }

                motion_controller_withPIC_B.ar_n +=
                  motion_controller_withPIC_B.nVars;
              }

              motion_controller_withPIC_B.br_i += 41;
            }
          }

          if (motion_controller_withPIC_B.mNull_tmp != 0) {
            motion_controller_withPIC_B.br_i =
              (motion_controller_withPIC_B.mNull_tmp - 1) * 41;
            for (motion_controller_withPIC_B.b_A_maxDiag_idx = 0;
                 motion_controller_withPIC_B.b_A_maxDiag_idx <=
                 motion_controller_withPIC_B.br_i;
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
                 motion_controller_withPIC_B.br_i;
                 motion_controller_withPIC_B.b_A_maxDiag_idx += 41) {
              motion_controller_withPIC_B.b_ar =
                motion_controller_withPIC_B.A_maxDiag_idx;
              motion_controller_withPIC_B.vectorUB_j =
                motion_controller_withPIC_B.b_A_maxDiag_idx +
                motion_controller_withPIC_B.mNull_tmp;
              for (motion_controller_withPIC_B.ic =
                   motion_controller_withPIC_B.b_A_maxDiag_idx + 1;
                   motion_controller_withPIC_B.ic <=
                   motion_controller_withPIC_B.vectorUB_j;
                   motion_controller_withPIC_B.ic++) {
                motion_controller_withPIC_B.temp_l = 0.0;
                for (motion_controller_withPIC_B.e_ix = 0;
                     motion_controller_withPIC_B.e_ix <
                     motion_controller_withPIC_B.nVars;
                     motion_controller_withPIC_B.e_ix++) {
                  motion_controller_withPIC_B.temp_l +=
                    memspace->workspace_double[(motion_controller_withPIC_B.e_ix
                    + motion_controller_withPIC_B.lastColC) + 1] * qrmanager->
                    Q[motion_controller_withPIC_B.e_ix +
                    motion_controller_withPIC_B.b_ar];
                }

                cholmanager->FMat[motion_controller_withPIC_B.ic - 1] +=
                  motion_controller_withPIC_B.temp_l;
                motion_controller_withPIC_B.b_ar += 41;
              }

              motion_controller_withPIC_B.lastColC += 161;
            }
          }
        }

        motion_controller_withPIC_B.temp_l = 1.4901161193847656E-6 *
          static_cast<real_T>(motion_controller_withPIC_B.mNull_tmp);
        cholmanager->ndims = motion_controller_withPIC_B.mNull_tmp;
        motion_controller_withPIC_B.b_A_maxDiag_idx = 0;
        if (motion_controller_withPIC_B.mNull_tmp > 1) {
          motion_controller_withPIC_B.smax = fabs(cholmanager->FMat[0]);
          for (motion_controller_withPIC_B.nVars = 2;
               motion_controller_withPIC_B.nVars <=
               motion_controller_withPIC_B.mNull_tmp;
               motion_controller_withPIC_B.nVars++) {
            motion_controller_withPIC_B.s_g = fabs(cholmanager->FMat
              [(motion_controller_withPIC_B.nVars - 1) * 42]);
            if (motion_controller_withPIC_B.s_g >
                motion_controller_withPIC_B.smax) {
              motion_controller_withPIC_B.b_A_maxDiag_idx =
                motion_controller_withPIC_B.nVars - 1;
              motion_controller_withPIC_B.smax = motion_controller_withPIC_B.s_g;
            }
          }
        }

        motion_controller_withPIC_B.smax = fabs(cholmanager->FMat[41 *
          motion_controller_withPIC_B.b_A_maxDiag_idx +
          motion_controller_withPIC_B.b_A_maxDiag_idx]) * 2.2204460492503131E-16;
        if (motion_controller_withPIC_B.smax >=
            motion_controller_withPIC_B.temp_l) {
          cholmanager->regTol_ = motion_controller_withPIC_B.smax;
        } else {
          cholmanager->regTol_ = motion_controller_withPIC_B.temp_l;
        }

        motion_controller__fullColLDL2_(cholmanager,
          motion_controller_withPIC_B.mNull_tmp,
          motion_controller_withPIC_B.temp_l);
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
              motion_controller_withPIC_B.temp_l = 0.0;
              motion_controller_withPIC_B.e_ix =
                motion_controller_withPIC_B.nVars +
                motion_controller_withPIC_B.nVar_d;
              for (motion_controller_withPIC_B.b_A_maxDiag_idx =
                   motion_controller_withPIC_B.nVars;
                   motion_controller_withPIC_B.b_A_maxDiag_idx <=
                   motion_controller_withPIC_B.e_ix;
                   motion_controller_withPIC_B.b_A_maxDiag_idx++) {
                motion_controller_withPIC_B.temp_l += qrmanager->
                  Q[motion_controller_withPIC_B.b_A_maxDiag_idx - 1] *
                  objective->grad[motion_controller_withPIC_B.b_A_maxDiag_idx -
                  motion_controller_withPIC_B.nVars];
              }

              motion_controller_withPIC_B.b_A_maxDiag_idx = div_nde_s32_floor
                ((motion_controller_withPIC_B.nVars -
                  motion_controller_withPIC_B.A_maxDiag_idx) - 1, 41);
              memspace->
                workspace_double[motion_controller_withPIC_B.b_A_maxDiag_idx] -=
                motion_controller_withPIC_B.temp_l;
            }
          }

          motion_controller_withPIC_B.nVars = cholmanager->ndims - 1;
          if (cholmanager->ndims != 0) {
            for (motion_controller_withPIC_B.nVar_d = 0;
                 motion_controller_withPIC_B.nVar_d <=
                 motion_controller_withPIC_B.nVars;
                 motion_controller_withPIC_B.nVar_d++) {
              motion_controller_withPIC_B.b_A_maxDiag_idx =
                motion_controller_withPIC_B.nVar_d * 41 +
                motion_controller_withPIC_B.nVar_d;
              motion_controller_withPIC_B.ic = motion_controller_withPIC_B.nVars
                - motion_controller_withPIC_B.nVar_d;
              for (motion_controller_withPIC_B.nullStartIdx = 0;
                   motion_controller_withPIC_B.nullStartIdx <
                   motion_controller_withPIC_B.ic;
                   motion_controller_withPIC_B.nullStartIdx++) {
                motion_controller_withPIC_B.e_ix =
                  (motion_controller_withPIC_B.nullStartIdx +
                   motion_controller_withPIC_B.nVar_d) + 1;
                memspace->workspace_double[motion_controller_withPIC_B.e_ix] -=
                  cholmanager->FMat[(motion_controller_withPIC_B.nullStartIdx +
                                     motion_controller_withPIC_B.b_A_maxDiag_idx)
                  + 1] * memspace->
                  workspace_double[motion_controller_withPIC_B.nVar_d];
              }
            }
          }

          motion_controller_withPIC_B.nVars = cholmanager->ndims;
          for (motion_controller_withPIC_B.nVar_d = 0;
               motion_controller_withPIC_B.nVar_d <
               motion_controller_withPIC_B.nVars;
               motion_controller_withPIC_B.nVar_d++) {
            memspace->workspace_double[motion_controller_withPIC_B.nVar_d] /=
              cholmanager->FMat[41 * motion_controller_withPIC_B.nVar_d +
              motion_controller_withPIC_B.nVar_d];
          }

          if (cholmanager->ndims != 0) {
            for (motion_controller_withPIC_B.nVar_d =
                 motion_controller_withPIC_B.nVars;
                 motion_controller_withPIC_B.nVar_d >= 1;
                 motion_controller_withPIC_B.nVar_d--) {
              motion_controller_withPIC_B.b_A_maxDiag_idx =
                (motion_controller_withPIC_B.nVar_d - 1) * 41;
              motion_controller_withPIC_B.temp_l = memspace->
                workspace_double[motion_controller_withPIC_B.nVar_d - 1];
              for (motion_controller_withPIC_B.nullStartIdx =
                   motion_controller_withPIC_B.nVars;
                   motion_controller_withPIC_B.nullStartIdx >=
                   motion_controller_withPIC_B.nVar_d + 1;
                   motion_controller_withPIC_B.nullStartIdx--) {
                motion_controller_withPIC_B.temp_l -= cholmanager->FMat
                  [(motion_controller_withPIC_B.b_A_maxDiag_idx +
                    motion_controller_withPIC_B.nullStartIdx) - 1] *
                  memspace->
                  workspace_double[motion_controller_withPIC_B.nullStartIdx - 1];
              }

              memspace->workspace_double[motion_controller_withPIC_B.nVar_d - 1]
                = motion_controller_withPIC_B.temp_l;
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

// Function for MATLAB Function: '<S48>/solvex'
real_T motion_controller_withPIC::motion_controlle_xnrm2_DlmxxpnG(int32_T n,
  const real_T x[41])
{
  real_T y;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = fabs(x[0]);
    } else {
      motion_controller_withPIC_B.scale_f = 3.3121686421112381E-170;
      motion_controller_withPIC_B.b_gr = static_cast<uint8_T>(n);
      for (motion_controller_withPIC_B.k_c = 0; motion_controller_withPIC_B.k_c <
           motion_controller_withPIC_B.b_gr; motion_controller_withPIC_B.k_c++)
      {
        motion_controller_withPIC_B.absxk_on = fabs
          (x[motion_controller_withPIC_B.k_c]);
        if (motion_controller_withPIC_B.absxk_on >
            motion_controller_withPIC_B.scale_f) {
          motion_controller_withPIC_B.t_iz = motion_controller_withPIC_B.scale_f
            / motion_controller_withPIC_B.absxk_on;
          y = y * motion_controller_withPIC_B.t_iz *
            motion_controller_withPIC_B.t_iz + 1.0;
          motion_controller_withPIC_B.scale_f =
            motion_controller_withPIC_B.absxk_on;
        } else {
          motion_controller_withPIC_B.t_iz =
            motion_controller_withPIC_B.absxk_on /
            motion_controller_withPIC_B.scale_f;
          y += motion_controller_withPIC_B.t_iz *
            motion_controller_withPIC_B.t_iz;
        }
      }

      y = motion_controller_withPIC_B.scale_f * sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<S48>/solvex'
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
    motion_controller_withPIC_B.c_j = 0.0;
    motion_controller_withPIC_B.b_g = motion_controller_withPIC_B.b_iy + m;
    for (motion_controller_withPIC_B.ia_c = motion_controller_withPIC_B.b_iy + 1;
         motion_controller_withPIC_B.ia_c <= motion_controller_withPIC_B.b_g;
         motion_controller_withPIC_B.ia_c++) {
      motion_controller_withPIC_B.c_j += x[(motion_controller_withPIC_B.ia_c -
        motion_controller_withPIC_B.b_iy) - 1] *
        A[motion_controller_withPIC_B.ia_c - 1];
    }

    motion_controller_withPIC_B.ia_c = div_nde_s32_floor
      (motion_controller_withPIC_B.b_iy, 41);
    y[motion_controller_withPIC_B.ia_c] += motion_controller_withPIC_B.c_j;
  }
}

// Function for MATLAB Function: '<S48>/solvex'
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
    for (motion_controller_withPIC_B.k_o = 0; motion_controller_withPIC_B.k_o <=
         3239; motion_controller_withPIC_B.k_o += 41) {
      motion_controller_withPIC_B.b_c_g = 0.0;
      motion_controller_withPIC_B.d_he = motion_controller_withPIC_B.k_o +
        workingset_nVar;
      for (motion_controller_withPIC_B.ia_i = motion_controller_withPIC_B.k_o +
           1; motion_controller_withPIC_B.ia_i <=
           motion_controller_withPIC_B.d_he; motion_controller_withPIC_B.ia_i++)
      {
        motion_controller_withPIC_B.b_c_g += solution_searchDir
          [(motion_controller_withPIC_B.ia_i - motion_controller_withPIC_B.k_o)
          - 1] * workingset_Aineq[motion_controller_withPIC_B.ia_i - 1];
      }

      motion_controller_withPIC_B.ia_i = div_nde_s32_floor
        (motion_controller_withPIC_B.k_o, 41) + 161;
      workspace[motion_controller_withPIC_B.ia_i] +=
        motion_controller_withPIC_B.b_c_g;
    }

    for (motion_controller_withPIC_B.k_o = 0; motion_controller_withPIC_B.k_o <
         80; motion_controller_withPIC_B.k_o++) {
      motion_controller_withPIC_B.workspace =
        workspace[motion_controller_withPIC_B.k_o + 161];
      if ((motion_controller_withPIC_B.workspace >
           motion_controller_withPIC_B.denomTol) && (!workingset_isActiveConstr
           [(workingset_isActiveIdx[2] + motion_controller_withPIC_B.k_o) - 1]))
      {
        motion_controller_withPIC_B.phaseOneCorrectionX =
          workspace[motion_controller_withPIC_B.k_o];
        motion_controller_withPIC_B.b_c_g = fabs
          (motion_controller_withPIC_B.phaseOneCorrectionX - *toldelta);
        motion_controller_withPIC_B.phaseOneCorrectionP = (1.0E-8 -
          motion_controller_withPIC_B.phaseOneCorrectionX) + *toldelta;
        if ((motion_controller_withPIC_B.b_c_g <=
             motion_controller_withPIC_B.phaseOneCorrectionP) || rtIsNaN
            (motion_controller_withPIC_B.phaseOneCorrectionP)) {
          motion_controller_withPIC_B.phaseOneCorrectionP =
            motion_controller_withPIC_B.b_c_g;
        }

        motion_controller_withPIC_B.b_c_g =
          motion_controller_withPIC_B.phaseOneCorrectionP /
          motion_controller_withPIC_B.workspace;
        if ((motion_controller_withPIC_B.b_c_g <= *alpha) && (fabs
             (motion_controller_withPIC_B.workspace) >
             motion_controller_withPIC_B.p_max)) {
          *alpha = motion_controller_withPIC_B.b_c_g;
          *constrType = 3;
          *constrIdx = motion_controller_withPIC_B.k_o + 1;
          *newBlocking = true;
        }

        motion_controller_withPIC_B.b_c_g = fabs
          (motion_controller_withPIC_B.phaseOneCorrectionX);
        if ((!(motion_controller_withPIC_B.b_c_g <= 1.0E-8 -
               motion_controller_withPIC_B.phaseOneCorrectionX)) && (!rtIsNaN
             (1.0E-8 - motion_controller_withPIC_B.phaseOneCorrectionX))) {
          motion_controller_withPIC_B.b_c_g = 1.0E-8 -
            motion_controller_withPIC_B.phaseOneCorrectionX;
        }

        motion_controller_withPIC_B.b_c_g /=
          motion_controller_withPIC_B.workspace;
        if (motion_controller_withPIC_B.b_c_g < *alpha) {
          *alpha = motion_controller_withPIC_B.b_c_g;
          *constrType = 3;
          *constrIdx = motion_controller_withPIC_B.k_o + 1;
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
    motion_controller_withPIC_B.ia_i = workingset_sizes[3];
    for (motion_controller_withPIC_B.k_o = 0; motion_controller_withPIC_B.k_o <=
         motion_controller_withPIC_B.ia_i - 2; motion_controller_withPIC_B.k_o++)
    {
      motion_controller_withPIC_B.d_he =
        workingset_indexLB[motion_controller_withPIC_B.k_o];
      motion_controller_withPIC_B.pk_corrected =
        -solution_searchDir[motion_controller_withPIC_B.d_he - 1] -
        motion_controller_withPIC_B.phaseOneCorrectionP;
      if ((motion_controller_withPIC_B.pk_corrected >
           motion_controller_withPIC_B.denomTol) && (!workingset_isActiveConstr
           [(workingset_isActiveIdx[3] + motion_controller_withPIC_B.k_o) - 1]))
      {
        motion_controller_withPIC_B.workspace =
          -solution_xstar[motion_controller_withPIC_B.d_he - 1] -
          workingset_lb[motion_controller_withPIC_B.d_he - 1];
        motion_controller_withPIC_B.ratio =
          (motion_controller_withPIC_B.workspace - *toldelta) -
          motion_controller_withPIC_B.phaseOneCorrectionX;
        motion_controller_withPIC_B.b_c_g = fabs
          (motion_controller_withPIC_B.ratio);
        if ((!(motion_controller_withPIC_B.b_c_g <= 1.0E-8 -
               motion_controller_withPIC_B.ratio)) && (!rtIsNaN(1.0E-8 -
              motion_controller_withPIC_B.ratio))) {
          motion_controller_withPIC_B.b_c_g = 1.0E-8 -
            motion_controller_withPIC_B.ratio;
        }

        motion_controller_withPIC_B.b_c_g /=
          motion_controller_withPIC_B.pk_corrected;
        if ((motion_controller_withPIC_B.b_c_g <= *alpha) && (fabs
             (motion_controller_withPIC_B.pk_corrected) >
             motion_controller_withPIC_B.p_max)) {
          *alpha = motion_controller_withPIC_B.b_c_g;
          *constrType = 4;
          *constrIdx = motion_controller_withPIC_B.k_o + 1;
          *newBlocking = true;
        }

        motion_controller_withPIC_B.ratio =
          motion_controller_withPIC_B.workspace -
          motion_controller_withPIC_B.phaseOneCorrectionX;
        motion_controller_withPIC_B.b_c_g = fabs
          (motion_controller_withPIC_B.ratio);
        if ((!(motion_controller_withPIC_B.b_c_g <= 1.0E-8 -
               motion_controller_withPIC_B.ratio)) && (!rtIsNaN(1.0E-8 -
              motion_controller_withPIC_B.ratio))) {
          motion_controller_withPIC_B.b_c_g = 1.0E-8 -
            motion_controller_withPIC_B.ratio;
        }

        motion_controller_withPIC_B.b_c_g /=
          motion_controller_withPIC_B.pk_corrected;
        if (motion_controller_withPIC_B.b_c_g < *alpha) {
          *alpha = motion_controller_withPIC_B.b_c_g;
          *constrType = 4;
          *constrIdx = motion_controller_withPIC_B.k_o + 1;
          *newBlocking = true;
          motion_controller_withPIC_B.p_max = fabs
            (motion_controller_withPIC_B.pk_corrected);
        }
      }
    }

    motion_controller_withPIC_B.ia_i = workingset_indexLB[workingset_sizes[3] -
      1] - 1;
    motion_controller_withPIC_B.phaseOneCorrectionX =
      solution_searchDir[motion_controller_withPIC_B.ia_i];
    if ((-motion_controller_withPIC_B.phaseOneCorrectionX >
         motion_controller_withPIC_B.denomTol) && (!workingset_isActiveConstr
         [(workingset_isActiveIdx[3] + workingset_sizes[3]) - 2])) {
      motion_controller_withPIC_B.workspace =
        -solution_xstar[motion_controller_withPIC_B.ia_i] -
        workingset_lb[motion_controller_withPIC_B.ia_i];
      motion_controller_withPIC_B.ratio = motion_controller_withPIC_B.workspace
        - *toldelta;
      motion_controller_withPIC_B.b_c_g = fabs(motion_controller_withPIC_B.ratio);
      if ((!(motion_controller_withPIC_B.b_c_g <= 1.0E-8 -
             motion_controller_withPIC_B.ratio)) && (!rtIsNaN(1.0E-8 -
            motion_controller_withPIC_B.ratio))) {
        motion_controller_withPIC_B.b_c_g = 1.0E-8 -
          motion_controller_withPIC_B.ratio;
      }

      motion_controller_withPIC_B.b_c_g /=
        -motion_controller_withPIC_B.phaseOneCorrectionX;
      if ((motion_controller_withPIC_B.b_c_g <= *alpha) && (fabs
           (motion_controller_withPIC_B.phaseOneCorrectionX) >
           motion_controller_withPIC_B.p_max)) {
        *alpha = motion_controller_withPIC_B.b_c_g;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }

      motion_controller_withPIC_B.b_c_g = fabs
        (motion_controller_withPIC_B.workspace);
      if ((!(motion_controller_withPIC_B.b_c_g <= 1.0E-8 -
             motion_controller_withPIC_B.workspace)) && (!rtIsNaN(1.0E-8 -
            motion_controller_withPIC_B.workspace))) {
        motion_controller_withPIC_B.b_c_g = 1.0E-8 -
          motion_controller_withPIC_B.workspace;
      }

      motion_controller_withPIC_B.b_c_g /=
        -motion_controller_withPIC_B.phaseOneCorrectionX;
      if (motion_controller_withPIC_B.b_c_g < *alpha) {
        *alpha = motion_controller_withPIC_B.b_c_g;
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
    motion_controller_withPIC_B.ia_i = static_cast<uint8_T>(workingset_sizes[4]);
    for (motion_controller_withPIC_B.k_o = 0; motion_controller_withPIC_B.k_o <
         motion_controller_withPIC_B.ia_i; motion_controller_withPIC_B.k_o++) {
      motion_controller_withPIC_B.d_he =
        workingset_indexUB[motion_controller_withPIC_B.k_o];
      motion_controller_withPIC_B.pk_corrected =
        solution_searchDir[motion_controller_withPIC_B.d_he - 1] -
        motion_controller_withPIC_B.phaseOneCorrectionP;
      if ((motion_controller_withPIC_B.pk_corrected >
           motion_controller_withPIC_B.denomTol) && (!workingset_isActiveConstr
           [(workingset_isActiveIdx[4] + motion_controller_withPIC_B.k_o) - 1]))
      {
        motion_controller_withPIC_B.workspace =
          solution_xstar[motion_controller_withPIC_B.d_he - 1] -
          workingset_ub[motion_controller_withPIC_B.d_he - 1];
        motion_controller_withPIC_B.ratio =
          (motion_controller_withPIC_B.workspace - *toldelta) -
          motion_controller_withPIC_B.phaseOneCorrectionX;
        motion_controller_withPIC_B.b_c_g = fabs
          (motion_controller_withPIC_B.ratio);
        if ((!(motion_controller_withPIC_B.b_c_g <= 1.0E-8 -
               motion_controller_withPIC_B.ratio)) && (!rtIsNaN(1.0E-8 -
              motion_controller_withPIC_B.ratio))) {
          motion_controller_withPIC_B.b_c_g = 1.0E-8 -
            motion_controller_withPIC_B.ratio;
        }

        motion_controller_withPIC_B.b_c_g /=
          motion_controller_withPIC_B.pk_corrected;
        if ((motion_controller_withPIC_B.b_c_g <= *alpha) && (fabs
             (motion_controller_withPIC_B.pk_corrected) >
             motion_controller_withPIC_B.p_max)) {
          *alpha = motion_controller_withPIC_B.b_c_g;
          *constrType = 5;
          *constrIdx = motion_controller_withPIC_B.k_o + 1;
          *newBlocking = true;
        }

        motion_controller_withPIC_B.ratio =
          motion_controller_withPIC_B.workspace -
          motion_controller_withPIC_B.phaseOneCorrectionX;
        motion_controller_withPIC_B.b_c_g = fabs
          (motion_controller_withPIC_B.ratio);
        if ((!(motion_controller_withPIC_B.b_c_g <= 1.0E-8 -
               motion_controller_withPIC_B.ratio)) && (!rtIsNaN(1.0E-8 -
              motion_controller_withPIC_B.ratio))) {
          motion_controller_withPIC_B.b_c_g = 1.0E-8 -
            motion_controller_withPIC_B.ratio;
        }

        motion_controller_withPIC_B.b_c_g /=
          motion_controller_withPIC_B.pk_corrected;
        if (motion_controller_withPIC_B.b_c_g < *alpha) {
          *alpha = motion_controller_withPIC_B.b_c_g;
          *constrType = 5;
          *constrIdx = motion_controller_withPIC_B.k_o + 1;
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

// Function for MATLAB Function: '<S48>/solvex'
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
  motion_controller_withPIC_B.denomTol_c = 2.2204460492503131E-13 *
    motion_controlle_xnrm2_DlmxxpnG(workingset_nVar, solution_searchDir);
  if (workingset_nWConstr[2] < 80) {
    memcpy(&workspace[0], &workingset_bineq[0], 80U * sizeof(real_T));
    motion_controlle_xgemv_pKPSQiPT(workingset_nVar, workingset_Aineq,
      solution_xstar, workspace);
    memset(&workspace[161], 0, 80U * sizeof(real_T));
    for (motion_controller_withPIC_B.k_j = 0; motion_controller_withPIC_B.k_j <=
         3239; motion_controller_withPIC_B.k_j += 41) {
      motion_controller_withPIC_B.b_c_mi = 0.0;
      motion_controller_withPIC_B.d_lj = motion_controller_withPIC_B.k_j +
        workingset_nVar;
      for (motion_controller_withPIC_B.ia_ce = motion_controller_withPIC_B.k_j +
           1; motion_controller_withPIC_B.ia_ce <=
           motion_controller_withPIC_B.d_lj; motion_controller_withPIC_B.ia_ce++)
      {
        motion_controller_withPIC_B.b_c_mi += solution_searchDir
          [(motion_controller_withPIC_B.ia_ce - motion_controller_withPIC_B.k_j)
          - 1] * workingset_Aineq[motion_controller_withPIC_B.ia_ce - 1];
      }

      motion_controller_withPIC_B.ia_ce = div_nde_s32_floor
        (motion_controller_withPIC_B.k_j, 41) + 161;
      workspace[motion_controller_withPIC_B.ia_ce] +=
        motion_controller_withPIC_B.b_c_mi;
    }

    for (motion_controller_withPIC_B.k_j = 0; motion_controller_withPIC_B.k_j <
         80; motion_controller_withPIC_B.k_j++) {
      motion_controller_withPIC_B.phaseOneCorrectionX_a =
        workspace[motion_controller_withPIC_B.k_j + 161];
      if ((motion_controller_withPIC_B.phaseOneCorrectionX_a >
           motion_controller_withPIC_B.denomTol_c) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[2] +
            motion_controller_withPIC_B.k_j) - 1])) {
        motion_controller_withPIC_B.phaseOneCorrectionP_l =
          workspace[motion_controller_withPIC_B.k_j];
        motion_controller_withPIC_B.b_c_mi = fabs
          (motion_controller_withPIC_B.phaseOneCorrectionP_l);
        if ((!(motion_controller_withPIC_B.b_c_mi <= 1.0E-8 -
               motion_controller_withPIC_B.phaseOneCorrectionP_l)) && (!rtIsNaN
             (1.0E-8 - motion_controller_withPIC_B.phaseOneCorrectionP_l))) {
          motion_controller_withPIC_B.b_c_mi = 1.0E-8 -
            motion_controller_withPIC_B.phaseOneCorrectionP_l;
        }

        motion_controller_withPIC_B.b_c_mi /=
          motion_controller_withPIC_B.phaseOneCorrectionX_a;
        if (motion_controller_withPIC_B.b_c_mi < *alpha) {
          *alpha = motion_controller_withPIC_B.b_c_mi;
          *constrType = 3;
          *constrIdx = motion_controller_withPIC_B.k_j + 1;
          *newBlocking = true;
        }
      }
    }
  }

  if (workingset_nWConstr[3] < workingset_sizes[3]) {
    motion_controller_withPIC_B.phaseOneCorrectionX_a =
      solution_xstar[workingset_nVar - 1] * static_cast<real_T>(isPhaseOne);
    motion_controller_withPIC_B.phaseOneCorrectionP_l =
      solution_searchDir[workingset_nVar - 1] * static_cast<real_T>(isPhaseOne);
    motion_controller_withPIC_B.ia_ce = workingset_sizes[3];
    for (motion_controller_withPIC_B.k_j = 0; motion_controller_withPIC_B.k_j <=
         motion_controller_withPIC_B.ia_ce - 2; motion_controller_withPIC_B.k_j
         ++) {
      motion_controller_withPIC_B.d_lj =
        workingset_indexLB[motion_controller_withPIC_B.k_j];
      motion_controller_withPIC_B.pk_corrected_jc =
        -solution_searchDir[motion_controller_withPIC_B.d_lj - 1] -
        motion_controller_withPIC_B.phaseOneCorrectionP_l;
      if ((motion_controller_withPIC_B.pk_corrected_jc >
           motion_controller_withPIC_B.denomTol_c) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[3] +
            motion_controller_withPIC_B.k_j) - 1])) {
        motion_controller_withPIC_B.ratio_i =
          (-solution_xstar[motion_controller_withPIC_B.d_lj - 1] -
           workingset_lb[motion_controller_withPIC_B.d_lj - 1]) -
          motion_controller_withPIC_B.phaseOneCorrectionX_a;
        motion_controller_withPIC_B.b_c_mi = fabs
          (motion_controller_withPIC_B.ratio_i);
        if ((!(motion_controller_withPIC_B.b_c_mi <= 1.0E-8 -
               motion_controller_withPIC_B.ratio_i)) && (!rtIsNaN(1.0E-8 -
              motion_controller_withPIC_B.ratio_i))) {
          motion_controller_withPIC_B.b_c_mi = 1.0E-8 -
            motion_controller_withPIC_B.ratio_i;
        }

        motion_controller_withPIC_B.b_c_mi /=
          motion_controller_withPIC_B.pk_corrected_jc;
        if (motion_controller_withPIC_B.b_c_mi < *alpha) {
          *alpha = motion_controller_withPIC_B.b_c_mi;
          *constrType = 4;
          *constrIdx = motion_controller_withPIC_B.k_j + 1;
          *newBlocking = true;
        }
      }
    }

    motion_controller_withPIC_B.ia_ce = workingset_indexLB[workingset_sizes[3] -
      1] - 1;
    motion_controller_withPIC_B.phaseOneCorrectionX_a =
      -solution_searchDir[motion_controller_withPIC_B.ia_ce];
    if ((motion_controller_withPIC_B.phaseOneCorrectionX_a >
         motion_controller_withPIC_B.denomTol_c) && (!workingset_isActiveConstr
         [(workingset_isActiveIdx[3] + workingset_sizes[3]) - 2])) {
      motion_controller_withPIC_B.ratio_i =
        -solution_xstar[motion_controller_withPIC_B.ia_ce] -
        workingset_lb[motion_controller_withPIC_B.ia_ce];
      motion_controller_withPIC_B.b_c_mi = fabs
        (motion_controller_withPIC_B.ratio_i);
      if ((!(motion_controller_withPIC_B.b_c_mi <= 1.0E-8 -
             motion_controller_withPIC_B.ratio_i)) && (!rtIsNaN(1.0E-8 -
            motion_controller_withPIC_B.ratio_i))) {
        motion_controller_withPIC_B.b_c_mi = 1.0E-8 -
          motion_controller_withPIC_B.ratio_i;
      }

      motion_controller_withPIC_B.b_c_mi /=
        motion_controller_withPIC_B.phaseOneCorrectionX_a;
      if (motion_controller_withPIC_B.b_c_mi < *alpha) {
        *alpha = motion_controller_withPIC_B.b_c_mi;
        *constrType = 4;
        *constrIdx = workingset_sizes[3];
        *newBlocking = true;
      }
    }
  }

  if (workingset_nWConstr[4] < workingset_sizes[4]) {
    motion_controller_withPIC_B.phaseOneCorrectionX_a =
      solution_xstar[workingset_nVar - 1] * static_cast<real_T>(isPhaseOne);
    motion_controller_withPIC_B.phaseOneCorrectionP_l =
      solution_searchDir[workingset_nVar - 1] * static_cast<real_T>(isPhaseOne);
    motion_controller_withPIC_B.ia_ce = static_cast<uint8_T>(workingset_sizes[4]);
    for (motion_controller_withPIC_B.k_j = 0; motion_controller_withPIC_B.k_j <
         motion_controller_withPIC_B.ia_ce; motion_controller_withPIC_B.k_j++) {
      motion_controller_withPIC_B.d_lj =
        workingset_indexUB[motion_controller_withPIC_B.k_j];
      motion_controller_withPIC_B.pk_corrected_jc =
        solution_searchDir[motion_controller_withPIC_B.d_lj - 1] -
        motion_controller_withPIC_B.phaseOneCorrectionP_l;
      if ((motion_controller_withPIC_B.pk_corrected_jc >
           motion_controller_withPIC_B.denomTol_c) &&
          (!workingset_isActiveConstr[(workingset_isActiveIdx[4] +
            motion_controller_withPIC_B.k_j) - 1])) {
        motion_controller_withPIC_B.ratio_i =
          (solution_xstar[motion_controller_withPIC_B.d_lj - 1] -
           workingset_ub[motion_controller_withPIC_B.d_lj - 1]) -
          motion_controller_withPIC_B.phaseOneCorrectionX_a;
        motion_controller_withPIC_B.b_c_mi = fabs
          (motion_controller_withPIC_B.ratio_i);
        if ((!(motion_controller_withPIC_B.b_c_mi <= 1.0E-8 -
               motion_controller_withPIC_B.ratio_i)) && (!rtIsNaN(1.0E-8 -
              motion_controller_withPIC_B.ratio_i))) {
          motion_controller_withPIC_B.b_c_mi = 1.0E-8 -
            motion_controller_withPIC_B.ratio_i;
        }

        motion_controller_withPIC_B.b_c_mi /=
          motion_controller_withPIC_B.pk_corrected_jc;
        if (motion_controller_withPIC_B.b_c_mi < *alpha) {
          *alpha = motion_controller_withPIC_B.b_c_mi;
          *constrType = 5;
          *constrIdx = motion_controller_withPIC_B.k_j + 1;
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

// Function for MATLAB Function: '<S48>/solvex'
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

// Function for MATLAB Function: '<S48>/solvex'
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

// Function for MATLAB Function: '<S48>/solvex'
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

            motion_controller_withPIC_B.i_e2 = (qrmanager->mrows - 1) * 41 + 1;
            for (motion_controller_withPIC_B.localActiveConstrIdx = 1;
                 motion_controller_withPIC_B.localActiveConstrIdx <=
                 motion_controller_withPIC_B.i_e2;
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
            motion_controller_withPIC_B.temp_k = qrmanager->
              QR[motion_controller_withPIC_B.localActiveConstrIdx + 1];
            motion_controlle_xrotg_ds3XgDMS(&qrmanager->
              QR[motion_controller_withPIC_B.localActiveConstrIdx],
              &motion_controller_withPIC_B.temp_k,
              &motion_controller_withPIC_B.normDelta,
              &motion_controller_withPIC_B.s_m);
            qrmanager->QR[motion_controller_withPIC_B.localActiveConstrIdx + 1] =
              motion_controller_withPIC_B.temp_k;
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
                motion_controller_withPIC_B.temp_k =
                  motion_controller_withPIC_B.temp_tmp *
                  motion_controller_withPIC_B.s_m + qrmanager->
                  Q[motion_controller_withPIC_B.d_ix] *
                  motion_controller_withPIC_B.normDelta;
                qrmanager->Q[motion_controller_withPIC_B.d_ix + 41] =
                  motion_controller_withPIC_B.temp_tmp *
                  motion_controller_withPIC_B.normDelta - qrmanager->
                  Q[motion_controller_withPIC_B.d_ix] *
                  motion_controller_withPIC_B.s_m;
                qrmanager->Q[motion_controller_withPIC_B.d_ix] =
                  motion_controller_withPIC_B.temp_k;
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
              motion_controller_withPIC_B.s_m = solution->
                lambda[motion_controller_withPIC_B.localActiveConstrIdx - 1];
              if (motion_controller_withPIC_B.s_m <
                  motion_controller_withPIC_B.normDelta) {
                motion_controller_withPIC_B.normDelta =
                  motion_controller_withPIC_B.s_m;
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

// Function for MATLAB Function: '<S48>/solvex'
void motion_controller_withPIC::motion_controller_with_phaseone(const real_T H
  [1600], const real_T f[40], s5cJJO9CAPQxuVG0iaeiP4F_motio_T *solution,
  sFlCINAYeIgPgx0UwEHpaMF_motio_T *memspace, sT1ziU4p6vTWuD880X9yNJ_motion_T
  *workingset, s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager,
  s8kZFjDlzP6eNfOekUiP5MF_motio_T *cholmanager, sSOeZ9WO10chPn9Si6PKiCB_motio_T *
  options, const sL9bDKomAYkxZSVrG9w6En_motion_T *runTimeOptions,
  sKnhLiTH4yv7eF1oV2a74RG_motio_T *objective)
{
  boolean_T exitg1;
  motion_controller_withPIC_B.nVar_b = workingset->nVar;
  solution->xstar[40] = solution->maxConstr + 1.0;
  motion_controlle_setProblemType(workingset, 1);
  motion_controller_withPIC_B.idxStartIneq_tmp_n = workingset->nWConstr[0] +
    workingset->nWConstr[1];
  motion_controller_withPIC_B.idxStartIneq_p =
    motion_controller_withPIC_B.idxStartIneq_tmp_n + 1;
  motion_controller_withPIC_B.idxEndIneq_nm = workingset->nActiveConstr;
  for (motion_controller_withPIC_B.i_ce =
       motion_controller_withPIC_B.idxStartIneq_p;
       motion_controller_withPIC_B.i_ce <=
       motion_controller_withPIC_B.idxEndIneq_nm;
       motion_controller_withPIC_B.i_ce++) {
    workingset->isActiveConstr[(workingset->isActiveIdx[workingset->
      Wid[motion_controller_withPIC_B.i_ce - 1] - 1] + workingset->
      Wlocalidx[motion_controller_withPIC_B.i_ce - 1]) - 2] = false;
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
    motion_controller_withPIC_B.i_ce = workingset->sizes[0];
    exitg1 = false;
    while ((!exitg1) && (motion_controller_withPIC_B.i_ce + 1 <=
                         workingset->nActiveConstr)) {
      if ((workingset->Wid[motion_controller_withPIC_B.i_ce] == 4) &&
          (workingset->Wlocalidx[motion_controller_withPIC_B.i_ce] ==
           workingset->sizes[3])) {
        motion_controller__removeConstr(workingset,
          motion_controller_withPIC_B.i_ce + 1);
        exitg1 = true;
      } else {
        motion_controller_withPIC_B.i_ce++;
      }
    }
  }

  motion_controller_withPIC_B.i_ce = workingset->nActiveConstr;
  while ((motion_controller_withPIC_B.i_ce > workingset->sizes[0]) &&
         (motion_controller_withPIC_B.i_ce > motion_controller_withPIC_B.nVar_b))
  {
    motion_controller__removeConstr(workingset, motion_controller_withPIC_B.i_ce);
    motion_controller_withPIC_B.i_ce--;
  }

  solution->maxConstr = solution->xstar[40];
  motion_controlle_setProblemType(workingset, 3);
  objective->objtype = objective->prev_objtype;
  objective->nvar = objective->prev_nvar;
  objective->hasLinear = objective->prev_hasLinear;
  options->ObjectiveLimit = -1.0E+20;
  options->StepTolerance = 1.0E-8;
}

// Function for MATLAB Function: '<S48>/solvex'
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

// Function for MATLAB Function: '<S48>/solvex'
void motion_controller_withPIC::motion_con_PresolveWorkingSet_g
  (s5cJJO9CAPQxuVG0iaeiP4F_motio_T *solution, sFlCINAYeIgPgx0UwEHpaMF_motio_T
   *memspace, sT1ziU4p6vTWuD880X9yNJ_motion_T *workingset,
   s2uO2c2bmaUl7sY5vOWIzHG_motio_T *qrmanager)
{
  boolean_T guard1;
  solution->state = 82;
  motion_controller_withPIC_B.b_i = motion_con_RemoveDependentEq__j(memspace,
    workingset, qrmanager);
  if ((motion_controller_withPIC_B.b_i != -1) && (workingset->nActiveConstr <=
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
    for (motion_controller_withPIC_B.b_i =
         motion_controller_withPIC_B.idxStartIneq;
         motion_controller_withPIC_B.b_i <=
         motion_controller_withPIC_B.idxEndIneq; motion_controller_withPIC_B.b_i
         ++) {
      workingset->isActiveConstr[(workingset->isActiveIdx[workingset->
        Wid[motion_controller_withPIC_B.b_i - 1] - 1] + workingset->
        Wlocalidx[motion_controller_withPIC_B.b_i - 1]) - 2] = false;
    }

    workingset->nWConstr[2] = 0;
    workingset->nWConstr[3] = 0;
    workingset->nWConstr[4] = 0;
    workingset->nActiveConstr = motion_controller_withPIC_B.idxStartIneq_tmp;
  }
}

// Function for MATLAB Function: '<S48>/solvex'
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

// Function for MATLAB Function: '<S48>/solvex'
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
  motion_controller_withPIC_B.nVar_c = workingset->nVar;
  solution->xstar[40] = solution->maxConstr + 1.0;
  if (workingset->probType == 3) {
    motion_controller_withPIC_B.mConstr_g = 1;
  } else {
    motion_controller_withPIC_B.mConstr_g = 4;
  }

  motion_controlle_setProblemType(workingset,
    motion_controller_withPIC_B.mConstr_g);
  motion_controller_withPIC_B.idxStartIneq_tmp_f = workingset->nWConstr[0] +
    workingset->nWConstr[1];
  motion_controller_withPIC_B.idxStartIneq_e =
    motion_controller_withPIC_B.idxStartIneq_tmp_f + 1;
  motion_controller_withPIC_B.idxEndIneq_n = workingset->nActiveConstr;
  for (motion_controller_withPIC_B.mConstr_g =
       motion_controller_withPIC_B.idxStartIneq_e;
       motion_controller_withPIC_B.mConstr_g <=
       motion_controller_withPIC_B.idxEndIneq_n;
       motion_controller_withPIC_B.mConstr_g++) {
    workingset->isActiveConstr[(workingset->isActiveIdx[workingset->
      Wid[motion_controller_withPIC_B.mConstr_g - 1] - 1] +
      workingset->Wlocalidx[motion_controller_withPIC_B.mConstr_g - 1]) - 2] =
      false;
  }

  workingset->nWConstr[2] = 0;
  workingset->nWConstr[3] = 0;
  workingset->nWConstr[4] = 0;
  workingset->nActiveConstr = motion_controller_withPIC_B.idxStartIneq_tmp_f;
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
    motion_controller_withPIC_B.mConstr_g = workingset->sizes[0];
    exitg1 = false;
    while ((!exitg1) && (motion_controller_withPIC_B.mConstr_g + 1 <=
                         workingset->nActiveConstr)) {
      if ((workingset->Wid[motion_controller_withPIC_B.mConstr_g] == 4) &&
          (workingset->Wlocalidx[motion_controller_withPIC_B.mConstr_g] ==
           workingset->sizes[3])) {
        motion_controller__removeConstr(workingset,
          motion_controller_withPIC_B.mConstr_g + 1);
        exitg1 = true;
      } else {
        motion_controller_withPIC_B.mConstr_g++;
      }
    }
  }

  motion_controller_withPIC_B.mConstr_g = workingset->nActiveConstr;
  while ((motion_controller_withPIC_B.mConstr_g > workingset->sizes[0]) &&
         (motion_controller_withPIC_B.mConstr_g >
          motion_controller_withPIC_B.nVar_c)) {
    motion_controller__removeConstr(workingset,
      motion_controller_withPIC_B.mConstr_g);
    motion_controller_withPIC_B.mConstr_g--;
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

// Function for MATLAB Function: '<S48>/solvex'
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
  motion_controller_withPIC_B.i_h = workingset->nVar;
  motion_controller_withPIC_B.c_a = static_cast<uint8_T>(workingset->sizes[0]);
  for (motion_controller_withPIC_B.idx = 0; motion_controller_withPIC_B.idx <
       motion_controller_withPIC_B.c_a; motion_controller_withPIC_B.idx++) {
    solution->xstar[workingset->indexFixed[motion_controller_withPIC_B.idx] - 1]
      = workingset->ub[workingset->indexFixed[motion_controller_withPIC_B.idx] -
      1];
  }

  motion_controller_withPIC_B.c_a = static_cast<uint8_T>(workingset->sizes[3]);
  for (motion_controller_withPIC_B.idx = 0; motion_controller_withPIC_B.idx <
       motion_controller_withPIC_B.c_a; motion_controller_withPIC_B.idx++) {
    if (workingset->isActiveConstr[(workingset->isActiveIdx[3] +
         motion_controller_withPIC_B.idx) - 1]) {
      solution->xstar[workingset->indexLB[motion_controller_withPIC_B.idx] - 1] =
        -workingset->lb[workingset->indexLB[motion_controller_withPIC_B.idx] - 1];
    }
  }

  motion_controller_withPIC_B.c_a = static_cast<uint8_T>(workingset->sizes[4]);
  for (motion_controller_withPIC_B.idx = 0; motion_controller_withPIC_B.idx <
       motion_controller_withPIC_B.c_a; motion_controller_withPIC_B.idx++) {
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
    motion_controller_withPIC_B.d_h = 1.0E-8 * runTimeOptions.ConstrRelTolFactor;
    guard1 = false;
    if (solution->maxConstr > motion_controller_withPIC_B.d_h) {
      motion_controller_with_phaseone(H, f, solution, memspace, workingset,
        qrmanager, cholmanager, options, &runTimeOptions, objective);
      if (solution->state == 0) {
      } else {
        solution->maxConstr = motion_c_maxConstraintViolation(workingset,
          solution->xstar);
        if (solution->maxConstr > motion_controller_withPIC_B.d_h) {
          memset(&solution->lambda[0], 0, 161U * sizeof(real_T));
          solution->fstar = motion_controller_w_computeFval(objective,
            memspace->workspace_double, H, f, solution->xstar);
          solution->state = -2;
        } else {
          if (solution->maxConstr > 0.0) {
            motion_controller_withPIC_B.idx = static_cast<uint8_T>
              (motion_controller_withPIC_B.i_h);
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
                   motion_controller_withPIC_B.d_h) || (solution->firstorderopt >
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

// Function for MATLAB Function: '<S48>/solvex'
void motion_controller_withPIC::motion_controller_with_quadprog(const real_T H
  [1600], const real_T f[40], const real_T Aineq[3200], const real_T bineq[80],
  const real_T lb[40], const real_T ub[40], real_T x0[40], const
  sSOeZ9WO10chPn9Si6PKiCB_motio_T *options)
{
  __m128d tmp;
  boolean_T exitg1;
  boolean_T guard1;
  motion_controller_withPIC_B.exitflag = (rtInf);
  motion_controller_withPIC_B.c_k_n = 0;
  exitg1 = false;
  while ((!exitg1) && (motion_controller_withPIC_B.c_k_n < 40)) {
    if (lb[motion_controller_withPIC_B.c_k_n] >
        ub[motion_controller_withPIC_B.c_k_n]) {
      motion_controller_withPIC_B.exitflag = -2.0;
      exitg1 = true;
    } else {
      motion_controller_withPIC_B.c_k_n++;
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
    for (motion_controller_withPIC_B.i_j = 0; motion_controller_withPIC_B.i_j <
         5; motion_controller_withPIC_B.i_j++) {
      motion_controller_withPIC_B.WorkingSet.nWConstr[motion_controller_withPIC_B.i_j]
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
    motion_controller_withPIC_B.c_k_n = 80;
    motion_controller_withPIC_B.idxFillStart = 0;
    motion_controller_withPIC_B.colOffsetATw = 0;
    for (motion_controller_withPIC_B.i_j = 0; motion_controller_withPIC_B.i_j <
         40; motion_controller_withPIC_B.i_j++) {
      motion_controller_withPIC_B.exitflag = lb[motion_controller_withPIC_B.i_j];
      guard1 = false;
      if ((!rtIsInf(motion_controller_withPIC_B.exitflag)) && (!rtIsNaN
           (motion_controller_withPIC_B.exitflag))) {
        if (fabs(motion_controller_withPIC_B.exitflag -
                 ub[motion_controller_withPIC_B.i_j]) < 1.0E-8) {
          motion_controller_withPIC_B.colOffsetATw++;
          motion_controller_withPIC_B.WorkingSet.indexFixed[motion_controller_withPIC_B.colOffsetATw
            - 1] = motion_controller_withPIC_B.i_j + 1;
        } else {
          motion_controller_withPIC_B.c_k_n++;
          motion_controller_withPIC_B.WorkingSet.indexLB[motion_controller_withPIC_B.c_k_n
            - 81] = motion_controller_withPIC_B.i_j + 1;
          guard1 = true;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        motion_controller_withPIC_B.exitflag =
          ub[motion_controller_withPIC_B.i_j];
        if ((!rtIsInf(motion_controller_withPIC_B.exitflag)) && (!rtIsNaN
             (motion_controller_withPIC_B.exitflag))) {
          motion_controller_withPIC_B.idxFillStart++;
          motion_controller_withPIC_B.WorkingSet.indexUB[motion_controller_withPIC_B.idxFillStart
            - 1] = motion_controller_withPIC_B.i_j + 1;
        }
      }
    }

    motion_controller_withPIC_B.i_j = (motion_controller_withPIC_B.c_k_n +
      motion_controller_withPIC_B.idxFillStart) +
      motion_controller_withPIC_B.colOffsetATw;
    motion_controller_withPIC_B.WorkingSet.mConstr =
      motion_controller_withPIC_B.i_j;
    motion_controller_withPIC_B.WorkingSet.mConstrOrig =
      motion_controller_withPIC_B.i_j;
    motion_controller_withPIC_B.WorkingSet.mConstrMax = 161;
    motion_controller_withPIC_B.WorkingSet.sizes[0] =
      motion_controller_withPIC_B.colOffsetATw;
    motion_controller_withPIC_B.WorkingSet.sizes[1] = 0;
    motion_controller_withPIC_B.WorkingSet.sizes[2] = 80;
    motion_controller_withPIC_B.WorkingSet.sizes[3] =
      motion_controller_withPIC_B.c_k_n - 80;
    motion_controller_withPIC_B.WorkingSet.sizes[4] =
      motion_controller_withPIC_B.idxFillStart;
    for (motion_controller_withPIC_B.i_j = 0; motion_controller_withPIC_B.i_j <
         5; motion_controller_withPIC_B.i_j++) {
      motion_controller_withPIC_B.WorkingSet.sizesNormal[motion_controller_withPIC_B.i_j]
        =
        motion_controller_withPIC_B.WorkingSet.sizes[motion_controller_withPIC_B.i_j];
    }

    motion_controller_withPIC_B.WorkingSet.sizesPhaseOne[0] =
      motion_controller_withPIC_B.colOffsetATw;
    motion_controller_withPIC_B.WorkingSet.sizesPhaseOne[1] = 0;
    motion_controller_withPIC_B.WorkingSet.sizesPhaseOne[2] = 80;
    motion_controller_withPIC_B.WorkingSet.sizesPhaseOne[3] =
      motion_controller_withPIC_B.c_k_n - 79;
    motion_controller_withPIC_B.WorkingSet.sizesPhaseOne[4] =
      motion_controller_withPIC_B.idxFillStart;
    motion_controller_withPIC_B.WorkingSet.sizesRegularized[0] =
      motion_controller_withPIC_B.colOffsetATw;
    motion_controller_withPIC_B.WorkingSet.sizesRegularized[1] = 0;
    motion_controller_withPIC_B.WorkingSet.sizesRegularized[2] = 80;
    motion_controller_withPIC_B.WorkingSet.sizesRegularized[3] =
      motion_controller_withPIC_B.c_k_n;
    motion_controller_withPIC_B.WorkingSet.sizesRegularized[4] =
      motion_controller_withPIC_B.idxFillStart;
    motion_controller_withPIC_B.WorkingSet.sizesRegPhaseOne[0] =
      motion_controller_withPIC_B.colOffsetATw;
    motion_controller_withPIC_B.WorkingSet.sizesRegPhaseOne[1] = 0;
    motion_controller_withPIC_B.WorkingSet.sizesRegPhaseOne[2] = 80;
    motion_controller_withPIC_B.WorkingSet.sizesRegPhaseOne[3] =
      motion_controller_withPIC_B.c_k_n + 1;
    motion_controller_withPIC_B.WorkingSet.sizesRegPhaseOne[4] =
      motion_controller_withPIC_B.idxFillStart;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxNormal[0] = 1;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxNormal[1] =
      motion_controller_withPIC_B.colOffsetATw;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxNormal[2] = 0;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxNormal[3] = 80;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxNormal[4] =
      motion_controller_withPIC_B.c_k_n - 80;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxNormal[5] =
      motion_controller_withPIC_B.idxFillStart;
    for (motion_controller_withPIC_B.i_j = 0; motion_controller_withPIC_B.i_j <
         6; motion_controller_withPIC_B.i_j++) {
      motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_j]
        =
        motion_controller_withPIC_B.WorkingSet.isActiveIdxNormal[motion_controller_withPIC_B.i_j];
    }

    for (motion_controller_withPIC_B.i_j = 0; motion_controller_withPIC_B.i_j <
         5; motion_controller_withPIC_B.i_j++) {
      motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_j
        + 1] +=
        motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_j];
    }

    for (motion_controller_withPIC_B.i_j = 0; motion_controller_withPIC_B.i_j <
         6; motion_controller_withPIC_B.i_j++) {
      motion_controller_withPIC_B.WorkingSet.isActiveIdx[motion_controller_withPIC_B.i_j]
        =
        motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_j];
    }

    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[1] =
      motion_controller_withPIC_B.colOffsetATw;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[3] = 80;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[4] =
      motion_controller_withPIC_B.c_k_n - 79;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[5] =
      motion_controller_withPIC_B.idxFillStart;
    for (motion_controller_withPIC_B.i_j = 0; motion_controller_withPIC_B.i_j <
         5; motion_controller_withPIC_B.i_j++) {
      motion_controller_withPIC_B.WorkingSet.isActiveIdxNormal[motion_controller_withPIC_B.i_j
        + 1] +=
        motion_controller_withPIC_B.WorkingSet.isActiveIdxNormal[motion_controller_withPIC_B.i_j];
      motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_j
        + 1] +=
        motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_j];
    }

    for (motion_controller_withPIC_B.i_j = 0; motion_controller_withPIC_B.i_j <
         6; motion_controller_withPIC_B.i_j++) {
      motion_controller_withPIC_B.WorkingSet.isActiveIdxPhaseOne[motion_controller_withPIC_B.i_j]
        =
        motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_j];
    }

    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[1] =
      motion_controller_withPIC_B.colOffsetATw;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[3] = 80;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[4] =
      motion_controller_withPIC_B.c_k_n;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[5] =
      motion_controller_withPIC_B.idxFillStart;
    for (motion_controller_withPIC_B.i_j = 0; motion_controller_withPIC_B.i_j <
         5; motion_controller_withPIC_B.i_j++) {
      motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_j
        + 1] +=
        motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_j];
    }

    for (motion_controller_withPIC_B.i_j = 0; motion_controller_withPIC_B.i_j <
         6; motion_controller_withPIC_B.i_j++) {
      motion_controller_withPIC_B.WorkingSet.isActiveIdxRegularized[motion_controller_withPIC_B.i_j]
        =
        motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.i_j];
    }

    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[0] = 1;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[1] =
      motion_controller_withPIC_B.colOffsetATw;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[2] = 0;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[3] = 80;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[4] =
      motion_controller_withPIC_B.c_k_n + 1;
    motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[5] =
      motion_controller_withPIC_B.idxFillStart;
    for (motion_controller_withPIC_B.c_k_n = 0;
         motion_controller_withPIC_B.c_k_n < 5;
         motion_controller_withPIC_B.c_k_n++) {
      motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.c_k_n
        + 1] +=
        motion_controller_withPIC_B.WorkingSet.isActiveIdxRegPhaseOne[motion_controller_withPIC_B.c_k_n];
    }

    for (motion_controller_withPIC_B.c_k_n = 0;
         motion_controller_withPIC_B.c_k_n < 80;
         motion_controller_withPIC_B.c_k_n++) {
      for (motion_controller_withPIC_B.idxFillStart = 0;
           motion_controller_withPIC_B.idxFillStart < 40;
           motion_controller_withPIC_B.idxFillStart++) {
        motion_controller_withPIC_B.WorkingSet.Aineq[motion_controller_withPIC_B.idxFillStart
          + 41 * motion_controller_withPIC_B.c_k_n] = Aineq[80 *
          motion_controller_withPIC_B.idxFillStart +
          motion_controller_withPIC_B.c_k_n];
      }

      motion_controller_withPIC_B.WorkingSet.bineq[motion_controller_withPIC_B.c_k_n]
        = bineq[motion_controller_withPIC_B.c_k_n];
    }

    for (motion_controller_withPIC_B.c_k_n = 0;
         motion_controller_withPIC_B.c_k_n <= 38;
         motion_controller_withPIC_B.c_k_n += 2) {
      tmp = _mm_loadu_pd(&lb[motion_controller_withPIC_B.c_k_n]);
      _mm_storeu_pd
        (&motion_controller_withPIC_B.WorkingSet.lb[motion_controller_withPIC_B.c_k_n],
         _mm_mul_pd(tmp, _mm_set1_pd(-1.0)));
      tmp = _mm_loadu_pd(&ub[motion_controller_withPIC_B.c_k_n]);
      _mm_storeu_pd
        (&motion_controller_withPIC_B.WorkingSet.ub[motion_controller_withPIC_B.c_k_n],
         tmp);
    }

    motion_controlle_setProblemType(&motion_controller_withPIC_B.WorkingSet, 3);
    motion_controller_withPIC_B.idxFillStart =
      motion_controller_withPIC_B.WorkingSet.isActiveIdx[2];
    for (motion_controller_withPIC_B.c_k_n =
         motion_controller_withPIC_B.idxFillStart;
         motion_controller_withPIC_B.c_k_n < 162;
         motion_controller_withPIC_B.c_k_n++) {
      motion_controller_withPIC_B.WorkingSet.isActiveConstr[motion_controller_withPIC_B.c_k_n
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
    for (motion_controller_withPIC_B.c_k_n = 0;
         motion_controller_withPIC_B.c_k_n <
         motion_controller_withPIC_B.idxFillStart;
         motion_controller_withPIC_B.c_k_n++) {
      motion_controller_withPIC_B.WorkingSet.Wid[motion_controller_withPIC_B.c_k_n]
        = 1;
      motion_controller_withPIC_B.WorkingSet.Wlocalidx[motion_controller_withPIC_B.c_k_n]
        = motion_controller_withPIC_B.c_k_n + 1;
      motion_controller_withPIC_B.WorkingSet.isActiveConstr[motion_controller_withPIC_B.c_k_n]
        = true;
      motion_controller_withPIC_B.colOffsetATw = 41 *
        motion_controller_withPIC_B.c_k_n;
      motion_controller_withPIC_B.i_j =
        motion_controller_withPIC_B.WorkingSet.indexFixed[motion_controller_withPIC_B.c_k_n];
      if (motion_controller_withPIC_B.i_j - 2 >= 0) {
        memset
          (&motion_controller_withPIC_B.WorkingSet.ATwset[motion_controller_withPIC_B.colOffsetATw],
           0, static_cast<uint32_T>(((motion_controller_withPIC_B.i_j +
              motion_controller_withPIC_B.colOffsetATw) -
             motion_controller_withPIC_B.colOffsetATw) - 1) * sizeof(real_T));
      }

      motion_controller_withPIC_B.WorkingSet.ATwset
        [(motion_controller_withPIC_B.WorkingSet.indexFixed[motion_controller_withPIC_B.c_k_n]
          + motion_controller_withPIC_B.colOffsetATw) - 1] = 1.0;
      motion_controller_withPIC_B.i_j =
        motion_controller_withPIC_B.WorkingSet.indexFixed[motion_controller_withPIC_B.c_k_n]
        + 1;
      motion_controller_withPIC_B.e =
        motion_controller_withPIC_B.WorkingSet.nVar;
      if (motion_controller_withPIC_B.i_j <= motion_controller_withPIC_B.e) {
        memset(&motion_controller_withPIC_B.WorkingSet.ATwset
               [(motion_controller_withPIC_B.i_j +
                 motion_controller_withPIC_B.colOffsetATw) + -1], 0,
               static_cast<uint32_T>((((motion_controller_withPIC_B.e +
                   motion_controller_withPIC_B.colOffsetATw) -
                  motion_controller_withPIC_B.i_j) -
                 motion_controller_withPIC_B.colOffsetATw) + 1) * sizeof(real_T));
      }

      motion_controller_withPIC_B.WorkingSet.bwset[motion_controller_withPIC_B.c_k_n]
        =
        motion_controller_withPIC_B.WorkingSet.ub[motion_controller_withPIC_B.WorkingSet.indexFixed
        [motion_controller_withPIC_B.c_k_n] - 1];
    }

    motion_controller_withPIC_B.WorkingSet.SLACK0 = 0.0;
    motion_controller_withPIC_B.exitflag = 1.0;
    for (motion_controller_withPIC_B.c_k_n = 0;
         motion_controller_withPIC_B.c_k_n < 80;
         motion_controller_withPIC_B.c_k_n++) {
      motion_controller_withPIC_B.colSum = 0.0;
      motion_controller_withPIC_B.colOffsetATw = 41 *
        motion_controller_withPIC_B.c_k_n;
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
    for (motion_controller_withPIC_B.c_k_n = 0;
         motion_controller_withPIC_B.c_k_n < 40;
         motion_controller_withPIC_B.c_k_n++) {
      motion_controller_withPIC_B.b_colSum = 0.0;
      for (motion_controller_withPIC_B.idxFillStart = 0;
           motion_controller_withPIC_B.idxFillStart < 40;
           motion_controller_withPIC_B.idxFillStart++) {
        motion_controller_withPIC_B.b_colSum += fabs(H[40 *
          motion_controller_withPIC_B.c_k_n +
          motion_controller_withPIC_B.idxFillStart]);
      }

      if ((!(motion_controller_withPIC_B.colSum >=
             motion_controller_withPIC_B.b_colSum)) && (!rtIsNaN
           (motion_controller_withPIC_B.b_colSum))) {
        motion_controller_withPIC_B.colSum =
          motion_controller_withPIC_B.b_colSum;
      }

      motion_controller_withPIC_B.b_colSum = fabs
        (f[motion_controller_withPIC_B.c_k_n]);
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

void motion_controller_withPIC::motion_co_SystemCore_setup_fxdc
  (ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[11];
  static const char_T b_zeroDelimTopic_0[11] = "/motor_cmd";

  // Start for MATLABSystem: '<S28>/SinkBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S28>/SinkBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)5.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 11; i++) {
    // Start for MATLABSystem: '<S28>/SinkBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Pub_motion_controller_withPIC_4.createPublisher(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_withPIC::motion_c_SystemCore_setup_fxdcj
  (ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[11];
  static const char_T b_zeroDelimTopic_0[11] = "/servo_cmd";

  // Start for MATLABSystem: '<S29>/SinkBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S29>/SinkBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)10.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 11; i++) {
    // Start for MATLABSystem: '<S29>/SinkBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Pub_motion_controller_withPIC_148.createPublisher(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_withPIC::motion_contr_SystemCore_setup_f
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[22];
  static const char_T b_zeroDelimTopic_0[22] = "/t265_odometry_filter";

  // Start for MATLABSystem: '<S17>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S17>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  for (int32_T i = 0; i < 22; i++) {
    // Start for MATLABSystem: '<S17>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_motion_controller_withPIC_514.createSubscriber(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_withPIC::motion_cont_SystemCore_setup_fx
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[17];
  static const char_T b_zeroDelimTopic_0[17] = "/Imu_data_filter";

  // Start for MATLABSystem: '<S18>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S18>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  for (int32_T i = 0; i < 17; i++) {
    // Start for MATLABSystem: '<S18>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_motion_controller_withPIC_515.createSubscriber(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_withPIC::motion__SystemCore_setup_fxdcji
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[6];
  static const char_T b_zeroDelimTopic_0[6] = "/sbus";

  // Start for MATLABSystem: '<S55>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S55>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  for (int32_T i = 0; i < 6; i++) {
    // Start for MATLABSystem: '<S55>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_motion_controller_withPIC_1.createSubscriber(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_withPIC::motion_con_SystemCore_setup_fxd
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[13];
  static const char_T b_zeroDelimTopic_0[13] = "/servo_state";

  // Start for MATLABSystem: '<S19>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S19>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  for (int32_T i = 0; i < 13; i++) {
    // Start for MATLABSystem: '<S19>/SourceBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Sub_motion_controller_withPIC_516.createSubscriber(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_withPIC::motion_control_SystemCore_setup
  (ros_slros2_internal_block_Pub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[9];
  static const char_T b_zeroDelimTopic_0[9] = "/MPCtest";

  // Start for MATLABSystem: '<S13>/SinkBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S13>/SinkBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)10.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_RELIABLE);
  for (int32_T i = 0; i < 9; i++) {
    // Start for MATLABSystem: '<S13>/SinkBlock'
    b_zeroDelimTopic[i] = b_zeroDelimTopic_0[i];
  }

  Pub_motion_controller_withPIC_545.createPublisher(&b_zeroDelimTopic[0],
    qos_profile);
  obj->isSetupComplete = true;
}

void motion_controller_withPIC::motion_SystemCore_setup_fxdcjik
  (ros_slros2_internal_block_Sub_T *obj)
{
  rmw_qos_profile_t qos_profile;
  char_T b_zeroDelimTopic[13];
  static const char_T b_zeroDelimTopic_0[13] = "/motor_state";

  // Start for MATLABSystem: '<S56>/SourceBlock'
  obj->isInitialized = 1;
  qos_profile = rmw_qos_profile_default;

  // Start for MATLABSystem: '<S56>/SourceBlock'
  SET_QOS_VALUES(qos_profile, RMW_QOS_POLICY_HISTORY_KEEP_LAST, (size_t)1.0,
                 RMW_QOS_POLICY_DURABILITY_VOLATILE,
                 RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT);
  for (int32_T i = 0; i < 13; i++) {
    // Start for MATLABSystem: '<S56>/SourceBlock'
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

  // BusAssignment: '<S4>/Bus Assignment2' incorporates:
  //   Constant: '<S12>/Constant'

  motion_controller_withPIC_B.BusAssignment2 =
    motion_controller_withPIC_P.Constant_Value_a;

  // MATLABSystem: '<S17>/SourceBlock'
  motion_controller_withPIC_B.LogicalOperator_j =
    Sub_motion_controller_withPIC_514.getLatestMessage
    (&motion_controller_withPIC_B.b_varargout_2_b);

  // Outputs for Enabled SubSystem: '<S17>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S20>/Enable'

  // Start for MATLABSystem: '<S17>/SourceBlock'
  if (motion_controller_withPIC_B.LogicalOperator_j) {
    // SignalConversion generated from: '<S20>/In1'
    motion_controller_withPIC_B.In1_je =
      motion_controller_withPIC_B.b_varargout_2_b;
  }

  // End of Start for MATLABSystem: '<S17>/SourceBlock'
  // End of Outputs for SubSystem: '<S17>/Enabled Subsystem'

  // MATLABSystem: '<S18>/SourceBlock'
  motion_controller_withPIC_B.LogicalOperator_j =
    Sub_motion_controller_withPIC_515.getLatestMessage
    (&motion_controller_withPIC_B.b_varargout_2_d);

  // Outputs for Enabled SubSystem: '<S18>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S21>/Enable'

  // Start for MATLABSystem: '<S18>/SourceBlock'
  if (motion_controller_withPIC_B.LogicalOperator_j) {
    // SignalConversion generated from: '<S21>/In1'
    motion_controller_withPIC_B.In1_f =
      motion_controller_withPIC_B.b_varargout_2_d;
  }

  // End of Start for MATLABSystem: '<S18>/SourceBlock'
  // End of Outputs for SubSystem: '<S18>/Enabled Subsystem'

  // MATLABSystem: '<S55>/SourceBlock'
  motion_controller_withPIC_B.LogicalOperator_j =
    Sub_motion_controller_withPIC_1.getLatestMessage
    (&motion_controller_withPIC_B.b_varargout_2_o);

  // Outputs for Enabled SubSystem: '<S55>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S58>/Enable'

  // Start for MATLABSystem: '<S55>/SourceBlock'
  if (motion_controller_withPIC_B.LogicalOperator_j) {
    // SignalConversion generated from: '<S58>/In1'
    motion_controller_withPIC_B.In1_m =
      motion_controller_withPIC_B.b_varargout_2_o;
  }

  // End of Outputs for SubSystem: '<S55>/Enabled Subsystem'

  // RelationalOperator: '<S23>/Compare' incorporates:
  //   Abs: '<S7>/Abs'
  //   Constant: '<S23>/Constant'
  //   Constant: '<S7>/Constant1'
  //   SignalConversion generated from: '<S11>/Bus Selector'
  //   Sum: '<S7>/Add'

  motion_controller_withPIC_B.Compare = (fabs(static_cast<real_T>
    (motion_controller_withPIC_B.In1_m.mapped_channels[0]) -
    motion_controller_withPIC_P.Constant1_Value) >=
    motion_controller_withPIC_P.CompareToConstant1_const);

  // Chart: '<S5>/Chart'
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

  // End of Chart: '<S5>/Chart'

  // MATLAB Function: '<S5>/MATLAB Function' incorporates:
  //   Constant: '<S5>/Constant'

  motion_controller_withPIC_B.yp = motion_controller_withPIC_B.y -
    motion_controller_withPIC_P.Constant_Value_j * sin
    (motion_controller_withPIC_B.yaw);

  // MATLABSystem: '<Root>/Get Parameter7'
  ParamGet_motion_controller_withPIC_605.getParameter
    (&motion_controller_withPIC_B.b_value_ct);

  // MATLABSystem: '<Root>/Get Parameter8'
  ParamGet_motion_controller_withPIC_606.getParameter
    (&motion_controller_withPIC_B.b_value_p);

  // Chart: '<Root>/Chart' incorporates:
  //   MATLABSystem: '<Root>/Get Parameter7'
  //   MATLABSystem: '<Root>/Get Parameter8'

  if (motion_controller_withPIC_DW.is_active_c18_motion_controller == 0U) {
    motion_controller_withPIC_DW.is_active_c18_motion_controller = 1U;
    motion_controller_withPIC_DW.is_c18_motion_controller_withPI =
      motion_controller_withPI_IN_ini;
    motion_controller_withPIC_B.isPicEnable = 0;
    motion_controller_withPIC_B.isMpcEnable = 0;
    motion_controller_withPIC_DW.enable_b = 0.0;
    motion_controller_withPIC_DW.Ay_l =
      motion_controller_withPIC_B.In1_f.linear_acceleration.y;
    motion_controller_withPIC_DW.r_l =
      motion_controller_withPIC_B.In1_f.angular_velocity.z;
  } else {
    switch (motion_controller_withPIC_DW.is_c18_motion_controller_withPI) {
     case motion_controller_withPI_IN_ini:
      motion_controller_withPIC_B.isPicEnable = 0;
      motion_controller_withPIC_B.isMpcEnable = 0;
      if (motion_controller_withPIC_DW.enable_b >= 3.0) {
        motion_controller_withPIC_DW.is_c18_motion_controller_withPI =
          motion_controller_with_IN_saver;
        motion_controller_withPIC_B.isPicEnable = 1;
        motion_controller_withPIC_DW.delay_a = 0.0;
      } else {
        if (fabs(motion_controller_withPIC_B.In1_f.linear_acceleration.y -
                 motion_controller_withPIC_DW.Ay_l) >
            motion_controller_withPIC_B.b_value_ct) {
          if (fabs(motion_controller_withPIC_B.In1_f.angular_velocity.z -
                   motion_controller_withPIC_DW.r_l) >
              motion_controller_withPIC_B.b_value_p) {
            motion_controller_withPIC_DW.enable_b++;
          } else {
            motion_controller_withPIC_DW.enable_b = 0.0;
          }
        } else {
          motion_controller_withPIC_DW.enable_b = 0.0;
        }

        motion_controller_withPIC_DW.Ay_l =
          motion_controller_withPIC_B.In1_f.linear_acceleration.y;
        motion_controller_withPIC_DW.r_l =
          motion_controller_withPIC_B.In1_f.angular_velocity.z;
      }
      break;

     case motion_controller_with_IN_saver:
      motion_controller_withPIC_B.isPicEnable = 1;
      motion_controller_withPIC_B.isMpcEnable = 0;
      if (motion_controller_withPIC_B.Compare) {
        motion_controller_withPIC_DW.is_c18_motion_controller_withPI =
          motion_controller_withPI_IN_ini;
        motion_controller_withPIC_B.isPicEnable = 0;
        motion_controller_withPIC_DW.enable_b = 0.0;
        motion_controller_withPIC_DW.Ay_l =
          motion_controller_withPIC_B.In1_f.linear_acceleration.y;
        motion_controller_withPIC_DW.r_l =
          motion_controller_withPIC_B.In1_f.angular_velocity.z;
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
      motion_controller_withPIC_B.isPicEnable = 1;
      motion_controller_withPIC_B.isMpcEnable = 1;
      if (motion_controller_withPIC_B.Compare) {
        motion_controller_withPIC_DW.is_c18_motion_controller_withPI =
          motion_controller_withPI_IN_ini;
        motion_controller_withPIC_B.isPicEnable = 0;
        motion_controller_withPIC_B.isMpcEnable = 0;
        motion_controller_withPIC_DW.enable_b = 0.0;
        motion_controller_withPIC_DW.Ay_l =
          motion_controller_withPIC_B.In1_f.linear_acceleration.y;
        motion_controller_withPIC_DW.r_l =
          motion_controller_withPIC_B.In1_f.angular_velocity.z;
      }
      break;
    }
  }

  // End of Chart: '<Root>/Chart'

  // MATLABSystem: '<S19>/SourceBlock'
  motion_controller_withPIC_B.b_value_ix =
    Sub_motion_controller_withPIC_516.getLatestMessage
    (&motion_controller_withPIC_B.b_varargout_2);

  // Outputs for Enabled SubSystem: '<S19>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S22>/Enable'

  // Start for MATLABSystem: '<S19>/SourceBlock'
  if (motion_controller_withPIC_B.b_value_ix) {
    // SignalConversion generated from: '<S22>/In1'
    motion_controller_withPIC_B.In1_j =
      motion_controller_withPIC_B.b_varargout_2;
  }

  // End of Start for MATLABSystem: '<S19>/SourceBlock'
  // End of Outputs for SubSystem: '<S19>/Enabled Subsystem'

  // Outputs for Iterator SubSystem: '<S5>/For Each Subsystem' incorporates:
  //   ForEach: '<S15>/For Each'

  for (motion_controller_withPIC_B.ForEach_itr_c = 0;
       motion_controller_withPIC_B.ForEach_itr_c < 16;
       motion_controller_withPIC_B.ForEach_itr_c++) {
    // ForEachSliceAssignment generated from: '<S15>/Out1' incorporates:
    //   ForEachSliceSelector generated from: '<S15>/In1'

    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[motion_controller_withPIC_B.ForEach_itr_c]
      =
      motion_controller_withPIC_B.In1_j.actuator_state[motion_controller_withPIC_B.ForEach_itr_c]
      .position;
  }

  // End of Outputs for SubSystem: '<S5>/For Each Subsystem'

  // MATLAB Function: '<Root>/MATLAB Function'
  motion_controller_withPIC_B.df_j =
    (motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[0] +
     motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[1]) / 2.0;
  motion_controller_withPIC_B.dr_i =
    (motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[2] +
     motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[3]) / 2.0;

  // MATLABSystem: '<Root>/Get Parameter'
  ParamGet_motion_controller_withPIC_557.getParameter
    (&motion_controller_withPIC_B.b_value_ct);

  // MATLABSystem: '<Root>/Get Parameter1'
  ParamGet_motion_controller_withPIC_558.getParameter
    (&motion_controller_withPIC_B.b_value_p);

  // MATLABSystem: '<Root>/Get Parameter2'
  ParamGet_motion_controller_withPIC_559.getParameter
    (&motion_controller_withPIC_B.b_value_p5);

  // MATLABSystem: '<Root>/Get Parameter3'
  ParamGet_motion_controller_withPIC_560.getParameter
    (&motion_controller_withPIC_B.b_value_a);

  // MATLABSystem: '<Root>/Get Parameter4'
  ParamGet_motion_controller_withPIC_561.getParameter
    (&motion_controller_withPIC_B.b_value_e);

  // MATLABSystem: '<Root>/Get Parameter5'
  ParamGet_motion_controller_withPIC_562.getParameter
    (&motion_controller_withPIC_B.b_value_ax);

  // MATLABSystem: '<Root>/Get Parameter15'
  ParamGet_motion_controller_withPIC_631.getParameter
    (&motion_controller_withPIC_B.b_value_as);

  // MATLABSystem: '<Root>/Get Parameter16'
  ParamGet_motion_controller_withPIC_632.getParameter
    (&motion_controller_withPIC_B.b_value_i);

  // MATLABSystem: '<Root>/Get Parameter9'
  ParamGet_motion_controller_withPIC_614.getParameter
    (&motion_controller_withPIC_B.b_value_l);

  // MATLABSystem: '<Root>/Get Parameter10'
  ParamGet_motion_controller_withPIC_615.getParameter
    (&motion_controller_withPIC_B.b_value_o);

  // MATLABSystem: '<Root>/Get Parameter11'
  ParamGet_motion_controller_withPIC_616.getParameter
    (&motion_controller_withPIC_B.b_value_o2);

  // MATLABSystem: '<Root>/Get Parameter12'
  ParamGet_motion_controller_withPIC_617.getParameter
    (&motion_controller_withPIC_B.b_value_ip);

  // MATLABSystem: '<Root>/Get Parameter13'
  ParamGet_motion_controller_withPIC_618.getParameter
    (&motion_controller_withPIC_B.b_value_f);

  // MATLABSystem: '<Root>/Get Parameter14'
  ParamGet_motion_controller_withPIC_619.getParameter
    (&motion_controller_withPIC_B.b_value_iz);

  // Outputs for Enabled SubSystem: '<Root>/picController' incorporates:
  //   EnablePort: '<S10>/Enable'

  if (motion_controller_withPIC_B.isMpcEnable > 0) {
    if (!motion_controller_withPIC_DW.picController_MODE) {
      // InitializeConditions for UnitDelay: '<S10>/Unit Delay'
      motion_controller_withPIC_DW.UnitDelay_DSTATE =
        motion_controller_withPIC_P.UnitDelay_InitialCondition;

      // InitializeConditions for UnitDelay: '<S10>/Unit Delay1'
      motion_controller_withPIC_DW.UnitDelay1_DSTATE =
        motion_controller_withPIC_P.UnitDelay1_InitialCondition;
      motion_controller_withPIC_DW.picController_MODE = true;
    }

    // MATLABSystem: '<S10>/Get Parameter'
    ParamGet_motion_controller_withPIC_637.getParameter
      (&motion_controller_withPIC_B.b_value_ff);

    // MATLABSystem: '<S10>/Get Parameter1'
    ParamGet_motion_controller_withPIC_709.getParameter
      (&motion_controller_withPIC_B.b_value_ix);

    // MATLABSystem: '<S10>/Get Parameter6'
    ParamGet_motion_controller_withPIC_556.getParameter
      (&motion_controller_withPIC_B.b_value_g);

    // MATLAB Function: '<S10>/MATLAB Function' incorporates:
    //   MATLABSystem: '<Root>/Get Parameter'
    //   MATLABSystem: '<Root>/Get Parameter1'
    //   MATLABSystem: '<Root>/Get Parameter15'
    //   MATLABSystem: '<Root>/Get Parameter16'
    //   MATLABSystem: '<Root>/Get Parameter2'
    //   MATLABSystem: '<Root>/Get Parameter3'
    //   MATLABSystem: '<Root>/Get Parameter4'
    //   MATLABSystem: '<Root>/Get Parameter5'

    motion_controller_withPIC_B.y_h[0] = motion_controller_withPIC_B.b_value_ct;
    motion_controller_withPIC_B.y_h[1] = motion_controller_withPIC_B.b_value_p;
    motion_controller_withPIC_B.y_h[2] = motion_controller_withPIC_B.b_value_p5;
    motion_controller_withPIC_B.y_h[3] = motion_controller_withPIC_B.b_value_a;
    motion_controller_withPIC_B.y_h[4] = motion_controller_withPIC_B.b_value_e;
    motion_controller_withPIC_B.y_h[5] = motion_controller_withPIC_B.b_value_ax;
    memset(&motion_controller_withPIC_B.Q[0], 0, 36U * sizeof(real_T));
    for (motion_controller_withPIC_B.j = 0; motion_controller_withPIC_B.j < 6;
         motion_controller_withPIC_B.j++) {
      motion_controller_withPIC_B.Q[motion_controller_withPIC_B.j + 6 *
        motion_controller_withPIC_B.j] =
        motion_controller_withPIC_B.y_h[motion_controller_withPIC_B.j];
    }

    motion_controller_withPIC_B.R[1] = 0.0;
    motion_controller_withPIC_B.R[2] = 0.0;
    motion_controller_withPIC_B.R[0] = motion_controller_withPIC_B.b_value_as;
    motion_controller_withPIC_B.R[3] = motion_controller_withPIC_B.b_value_i;

    // End of MATLAB Function: '<S10>/MATLAB Function'

    // MATLAB Function: '<S10>/MATLAB Function2'
    motion_controller_withPIC_B.y_h[0] = 0.0;
    motion_controller_withPIC_B.y_h[1] = 0.0;
    motion_controller_withPIC_B.y_h[2] = rt_roundd_snf
      (motion_controller_withPIC_B.yaw / 3.1415926535897931) *
      3.1415926535897931;
    motion_controller_withPIC_B.y_h[3] = 0.0;
    motion_controller_withPIC_B.y_h[4] = 0.0;
    motion_controller_withPIC_B.y_h[5] = 0.0;

    // Trigonometry: '<S45>/Cos1' incorporates:
    //   MATLAB Function: '<S10>/update'

    motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp = cos
      (motion_controller_withPIC_B.yaw);

    // Trigonometry: '<S45>/Cos' incorporates:
    //   MATLAB Function: '<S10>/update'

    motion_controller_withPIC_B.rtb_Add_tmp_tmp = sin
      (motion_controller_withPIC_B.yaw);

    // Sum: '<S45>/Add' incorporates:
    //   Product: '<S45>/Product3'
    //   Product: '<S45>/Product4'
    //   Trigonometry: '<S45>/Cos'
    //   Trigonometry: '<S45>/Cos1'

    motion_controller_withPIC_B.b_value_p =
      motion_controller_withPIC_B.rtb_Add_tmp_tmp *
      motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
      motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp *
      motion_controller_withPIC_B.In1_je.twist.twist.linear.y;

    // Reshape: '<S10>/Reshape' incorporates:
    //   UnitDelay: '<S10>/Unit Delay'
    //   UnitDelay: '<S10>/Unit Delay1'

    motion_controller_withPIC_B.Reshape[0] = motion_controller_withPIC_B.yp;
    motion_controller_withPIC_B.Reshape[1] =
      motion_controller_withPIC_B.b_value_p;
    motion_controller_withPIC_B.Reshape[2] = motion_controller_withPIC_B.yaw;
    motion_controller_withPIC_B.Reshape[3] =
      motion_controller_withPIC_B.In1_f.angular_velocity.z;
    motion_controller_withPIC_B.Reshape[4] =
      motion_controller_withPIC_DW.UnitDelay_DSTATE;
    motion_controller_withPIC_B.Reshape[5] =
      motion_controller_withPIC_DW.UnitDelay1_DSTATE;

    // Switch: '<S10>/Switch' incorporates:
    //   Constant: '<S10>/Constant2'
    //   Constant: '<S42>/Constant'
    //   RelationalOperator: '<S42>/Compare'

    if (motion_controller_withPIC_B.In1_f.angular_velocity.z ==
        motion_controller_withPIC_P.CompareToConstant_const) {
      motion_controller_withPIC_B.b_value_ct =
        motion_controller_withPIC_P.Constant2_Value_g;
    } else {
      motion_controller_withPIC_B.b_value_ct =
        motion_controller_withPIC_B.In1_f.angular_velocity.z;
    }

    // End of Switch: '<S10>/Switch'

    // MATLAB Function: '<S10>/update' incorporates:
    //   MATLABSystem: '<Root>/Get Parameter10'
    //   MATLABSystem: '<Root>/Get Parameter11'
    //   MATLABSystem: '<Root>/Get Parameter12'
    //   MATLABSystem: '<Root>/Get Parameter13'
    //   MATLABSystem: '<Root>/Get Parameter14'
    //   MATLABSystem: '<Root>/Get Parameter9'
    //   Trigonometry: '<S45>/Cos'
    //   Trigonometry: '<S45>/Cos1'

    motion_controller_withPIC_B.Ay =
      motion_controller_withPIC_B.In1_f.linear_acceleration.y;
    motion_controller_withPIC_B.b_value_a = motion_controller_withPIC_P.B *
      motion_controller_withPIC_B.b_value_ct / 2.0;
    motion_controller_withPIC_B.b_value_e =
      motion_controller_withPIC_B.b_value_a -
      motion_controller_withPIC_B.In1_je.twist.twist.linear.x;
    motion_controller_withPIC_B.b_value_p5 =
      motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
      (motion_controller_withPIC_B.yaw);
    motion_controller_withPIC_B.e_a_tmp = motion_controller_withPIC_B.b_value_p
      - motion_controller_withPIC_B.b_value_p5;
    motion_controller_withPIC_B.b_value_tmp = motion_controller_withPIC_P.b *
      motion_controller_withPIC_B.b_value_ct;
    motion_controller_withPIC_B.e_a_tmp_d = motion_controller_withPIC_B.e_a_tmp /
      motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
    motion_controller_withPIC_B.e_a = motion_controller_withPIC_B.e_a_tmp_d -
      motion_controller_withPIC_B.b_value_tmp;
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.b_value_ax =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.b_value_p5) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im = 0.0;
    } else if (motion_controller_withPIC_B.e_a_tmp * 0.0 == 0.0) {
      motion_controller_withPIC_B.b_value_ax = 0.0;
      motion_controller_withPIC_B.rtb_Add_im =
        motion_controller_withPIC_B.e_a_tmp_d;
    } else {
      motion_controller_withPIC_B.b_value_ax = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_im =
        motion_controller_withPIC_B.e_a_tmp_d;
    }

    motion_controller_withPIC_B.b_value_as =
      motion_controller_withPIC_B.b_value_tmp * 0.0;
    motion_controller_withPIC_B.f_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_im -
                    motion_controller_withPIC_B.b_value_tmp,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.b_value_ax) -
                     motion_controller_withPIC_B.b_value_a) -
                    motion_controller_withPIC_B.b_value_as));
    motion_controller_withPIC_B.b_value_i =
      motion_controller_withPIC_B.b_value_a +
      motion_controller_withPIC_B.In1_je.twist.twist.linear.x;
    motion_controller_withPIC_B.i_a_tmp_tmp_tmp =
      motion_controller_withPIC_B.b_value_p -
      motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
      (motion_controller_withPIC_B.yaw);
    motion_controller_withPIC_B.b_value_p5 =
      motion_controller_withPIC_B.i_a_tmp_tmp_tmp /
      motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
    motion_controller_withPIC_B.i_a_tmp = motion_controller_withPIC_B.b_value_p5
      - motion_controller_withPIC_B.b_value_tmp;
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.b_value_ax =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im = 0.0;
    } else if ((motion_controller_withPIC_B.b_value_p -
                motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.b_value_ax = 0.0;
      motion_controller_withPIC_B.rtb_Add_im =
        motion_controller_withPIC_B.e_a_tmp_d;
    } else {
      motion_controller_withPIC_B.b_value_ax = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_im =
        motion_controller_withPIC_B.e_a_tmp_d;
    }

    motion_controller_withPIC_B.k_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_im -
                    motion_controller_withPIC_B.b_value_tmp,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.b_value_ax) +
                     motion_controller_withPIC_B.b_value_a) -
                    motion_controller_withPIC_B.b_value_as));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.b_value_ax =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im = 0.0;
    } else if ((motion_controller_withPIC_B.b_value_p -
                motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.b_value_ax = 0.0;
      motion_controller_withPIC_B.rtb_Add_im =
        motion_controller_withPIC_B.e_a_tmp_d;
    } else {
      motion_controller_withPIC_B.b_value_ax = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_im =
        motion_controller_withPIC_B.e_a_tmp_d;
    }

    motion_controller_withPIC_B.n_a_tmp = motion_controller_withPIC_P.a *
      motion_controller_withPIC_B.b_value_ct;
    motion_controller_withPIC_B.n_a_tmp_a = motion_controller_withPIC_B.n_a_tmp *
      0.0;
    motion_controller_withPIC_B.n_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_im,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.b_value_ax) -
                     motion_controller_withPIC_B.b_value_a) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    motion_controller_withPIC_B.o_a_tmp = motion_controller_withPIC_B.b_value_p5
      + motion_controller_withPIC_B.n_a_tmp;
    motion_controller_withPIC_B.q_a_tmp = (0.0 -
      motion_controller_withPIC_B.b_value_a) -
      motion_controller_withPIC_B.In1_je.twist.twist.linear.x;
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.b_value_ax =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im = 0.0;
    } else if ((motion_controller_withPIC_B.b_value_p -
                motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.b_value_ax = 0.0;
      motion_controller_withPIC_B.rtb_Add_im =
        motion_controller_withPIC_B.e_a_tmp_d;
    } else {
      motion_controller_withPIC_B.b_value_ax = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_im =
        motion_controller_withPIC_B.e_a_tmp_d;
    }

    motion_controller_withPIC_B.s_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_im,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.b_value_ax) +
                     motion_controller_withPIC_B.b_value_a) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.b_value_ax =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im = 0.0;
      motion_controller_withPIC_B.rtb_Add_re =
        motion_controller_withPIC_B.b_value_ax;
      motion_controller_withPIC_B.rtb_Add_im_l = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_m =
        motion_controller_withPIC_B.b_value_ax;
      motion_controller_withPIC_B.rtb_Add_im_m = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_c =
        motion_controller_withPIC_B.b_value_ax;
      motion_controller_withPIC_B.rtb_Add_im_f = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_p =
        motion_controller_withPIC_B.b_value_ax;
      motion_controller_withPIC_B.rtb_Add_im_e = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_o =
        motion_controller_withPIC_B.b_value_ax;
      motion_controller_withPIC_B.rtb_Add_im_h = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_l =
        motion_controller_withPIC_B.b_value_ax;
      motion_controller_withPIC_B.rtb_Add_im_h2 = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_me =
        motion_controller_withPIC_B.b_value_ax;
      motion_controller_withPIC_B.rtb_Add_im_mc = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_tmp =
        motion_controller_withPIC_B.b_value_ax;
      motion_controller_withPIC_B.rtb_Add_im_h3 = 0.0;
    } else {
      motion_controller_withPIC_B.b_value_p5 =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0;
      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.b_value_ax = 0.0;
        motion_controller_withPIC_B.rtb_Add_im =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.b_value_ax = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_l =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_l =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_m = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_m =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_m = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_m =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_c = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_f =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_c = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_f =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_p = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_e =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_p = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_e =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_o = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_h =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_o = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_h =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_l = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_h2 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_l = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_h2 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_me = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_mc =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_me = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_mc =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_tmp = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_h3 =
          motion_controller_withPIC_B.e_a_tmp_d;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_tmp = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_h3 =
          motion_controller_withPIC_B.e_a_tmp_d;
      }
    }

    motion_controller_withPIC_B.bb_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_im_h3 -
                    motion_controller_withPIC_B.b_value_tmp,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp) +
                     motion_controller_withPIC_B.b_value_a) -
                    motion_controller_withPIC_B.b_value_as));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_h3 = 0.0;
    } else if ((motion_controller_withPIC_B.b_value_p -
                motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp = 0.0;
      motion_controller_withPIC_B.rtb_Add_im_h3 =
        motion_controller_withPIC_B.e_a_tmp_d;
    } else {
      motion_controller_withPIC_B.rtb_Add_re_tmp = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_im_h3 =
        motion_controller_withPIC_B.e_a_tmp_d;
    }

    motion_controller_withPIC_B.hb_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_im_h3 -
                    motion_controller_withPIC_B.b_value_tmp,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp) -
                     motion_controller_withPIC_B.b_value_a) -
                    motion_controller_withPIC_B.b_value_as));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_h3 = 0.0;
    } else if ((motion_controller_withPIC_B.b_value_p -
                motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp = 0.0;
      motion_controller_withPIC_B.rtb_Add_im_h3 =
        motion_controller_withPIC_B.e_a_tmp_d;
    } else {
      motion_controller_withPIC_B.rtb_Add_re_tmp = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_im_h3 =
        motion_controller_withPIC_B.e_a_tmp_d;
    }

    motion_controller_withPIC_B.lb_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_im_h3,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp) -
                     motion_controller_withPIC_B.b_value_a) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_h3 = 0.0;
    } else if ((motion_controller_withPIC_B.b_value_p -
                motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp = 0.0;
      motion_controller_withPIC_B.rtb_Add_im_h3 =
        motion_controller_withPIC_B.e_a_tmp_d;
    } else {
      motion_controller_withPIC_B.rtb_Add_re_tmp = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_im_h3 =
        motion_controller_withPIC_B.e_a_tmp_d;
    }

    motion_controller_withPIC_B.rb_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_im_h3,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp) +
                     motion_controller_withPIC_B.b_value_a) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_h3 = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_cs =
        motion_controller_withPIC_B.rtb_Add_re_tmp;
      motion_controller_withPIC_B.rtb_Add_im_k = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_pc =
        motion_controller_withPIC_B.rtb_Add_re_tmp;
      motion_controller_withPIC_B.rtb_Add_im_p = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_p4 =
        motion_controller_withPIC_B.rtb_Add_re_tmp;
      motion_controller_withPIC_B.rtb_Add_im_a = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_j =
        motion_controller_withPIC_B.rtb_Add_re_tmp;
      motion_controller_withPIC_B.rtb_Add_im_ek = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_ol =
        motion_controller_withPIC_B.rtb_Add_re_tmp;
      motion_controller_withPIC_B.rtb_Add_im_b = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_a =
        motion_controller_withPIC_B.rtb_Add_re_tmp;
      motion_controller_withPIC_B.rtb_Add_im_g = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_e =
        motion_controller_withPIC_B.rtb_Add_re_tmp;
      motion_controller_withPIC_B.rtb_Add_im_fi = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_h =
        motion_controller_withPIC_B.rtb_Add_re_tmp;
      motion_controller_withPIC_B.rtb_Add_im_ei = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_ch =
        motion_controller_withPIC_B.rtb_Add_re_tmp;
      motion_controller_withPIC_B.rtb_Add_im_ax = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_d =
        motion_controller_withPIC_B.rtb_Add_re_tmp;
      motion_controller_withPIC_B.rtb_Add_im_af = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_pb =
        motion_controller_withPIC_B.rtb_Add_re_tmp;
      motion_controller_withPIC_B.rtb_Add_im_ms = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_tmp_d =
        motion_controller_withPIC_B.rtb_Add_re_tmp;
      motion_controller_withPIC_B.rtb_Add_im_o = 0.0;
    } else {
      motion_controller_withPIC_B.b_value_p5 =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0;
      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_tmp = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_h3 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_tmp = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_h3 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_cs = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_k =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_cs = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_k =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_pc = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_p =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_pc = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_p =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_p4 = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_a =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_p4 = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_a =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_j = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_ek =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_j = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_ek =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_ol = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_b =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_ol = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_b =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_a = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_g =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_a = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_g =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_e = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_fi =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_e = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_fi =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_h = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_ei =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_h = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_ei =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_ch = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_ax =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_ch = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_ax =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_d = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_af =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_d = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_af =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_pb = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_ms =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_pb = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_ms =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_tmp_d = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_o =
          motion_controller_withPIC_B.e_a_tmp_d;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_tmp_d = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_o =
          motion_controller_withPIC_B.e_a_tmp_d;
      }
    }

    motion_controller_withPIC_B.yb_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_im_o -
                    motion_controller_withPIC_B.b_value_tmp,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp_d) +
                     motion_controller_withPIC_B.b_value_a) -
                    motion_controller_withPIC_B.b_value_as));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_d =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_o = 0.0;
    } else if ((motion_controller_withPIC_B.b_value_p -
                motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_d = 0.0;
      motion_controller_withPIC_B.rtb_Add_im_o =
        motion_controller_withPIC_B.e_a_tmp_d;
    } else {
      motion_controller_withPIC_B.rtb_Add_re_tmp_d = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_im_o =
        motion_controller_withPIC_B.e_a_tmp_d;
    }

    motion_controller_withPIC_B.ec_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_im_o -
                    motion_controller_withPIC_B.b_value_tmp,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp_d) -
                     motion_controller_withPIC_B.b_value_a) -
                    motion_controller_withPIC_B.b_value_as));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_d =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_o = 0.0;
    } else if ((motion_controller_withPIC_B.b_value_p -
                motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_d = 0.0;
      motion_controller_withPIC_B.rtb_Add_im_o =
        motion_controller_withPIC_B.e_a_tmp_d;
    } else {
      motion_controller_withPIC_B.rtb_Add_re_tmp_d = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_im_o =
        motion_controller_withPIC_B.e_a_tmp_d;
    }

    motion_controller_withPIC_B.hc_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_im_o,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp_d) -
                     motion_controller_withPIC_B.b_value_a) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_d =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_o = 0.0;
    } else if ((motion_controller_withPIC_B.b_value_p -
                motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_d = 0.0;
      motion_controller_withPIC_B.rtb_Add_im_o =
        motion_controller_withPIC_B.e_a_tmp_d;
    } else {
      motion_controller_withPIC_B.rtb_Add_re_tmp_d = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_im_o =
        motion_controller_withPIC_B.e_a_tmp_d;
    }

    motion_controller_withPIC_B.mc_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_im_o,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp_d) +
                     motion_controller_withPIC_B.b_value_a) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_d =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_o = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_n =
        motion_controller_withPIC_B.rtb_Add_re_tmp_d;
      motion_controller_withPIC_B.rtb_Add_im_lu = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_pe =
        motion_controller_withPIC_B.rtb_Add_re_tmp_d;
      motion_controller_withPIC_B.rtb_Add_im_pt = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_f =
        motion_controller_withPIC_B.rtb_Add_re_tmp_d;
      motion_controller_withPIC_B.rtb_Add_im_i = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_ox =
        motion_controller_withPIC_B.rtb_Add_re_tmp_d;
      motion_controller_withPIC_B.rtb_Add_im_kk = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_i =
        motion_controller_withPIC_B.rtb_Add_re_tmp_d;
      motion_controller_withPIC_B.rtb_Add_im_oc = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_m4 =
        motion_controller_withPIC_B.rtb_Add_re_tmp_d;
      motion_controller_withPIC_B.rtb_Add_im_c = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_fb =
        motion_controller_withPIC_B.rtb_Add_re_tmp_d;
      motion_controller_withPIC_B.rtb_Add_im_hc = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_tmp_j =
        motion_controller_withPIC_B.rtb_Add_re_tmp_d;
      motion_controller_withPIC_B.rtb_Add_im_m4 = 0.0;
    } else {
      motion_controller_withPIC_B.b_value_p5 =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0;
      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_tmp_d = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_o =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_tmp_d = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_o =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_n = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_lu =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_n = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_lu =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_pe = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_pt =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_pe = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_pt =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_f = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_i =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_f = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_i =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_ox = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_kk =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_ox = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_kk =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_i = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_oc =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_i = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_oc =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_m4 = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_c =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_m4 = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_c =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_fb = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_hc =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_fb = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_hc =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_tmp_j = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_m4 =
          motion_controller_withPIC_B.e_a_tmp_d;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_tmp_j = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_m4 =
          motion_controller_withPIC_B.e_a_tmp_d;
      }
    }

    motion_controller_withPIC_B.rc_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_im_m4,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp_j) -
                     motion_controller_withPIC_B.b_value_a) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_j =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_m4 = 0.0;
    } else if ((motion_controller_withPIC_B.b_value_p -
                motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_j = 0.0;
      motion_controller_withPIC_B.rtb_Add_im_m4 =
        motion_controller_withPIC_B.e_a_tmp_d;
    } else {
      motion_controller_withPIC_B.rtb_Add_re_tmp_j = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_im_m4 =
        motion_controller_withPIC_B.e_a_tmp_d;
    }

    motion_controller_withPIC_B.wc_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_im_m4,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp_j) +
                     motion_controller_withPIC_B.b_value_a) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_j =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_m4 = 0.0;
    } else if ((motion_controller_withPIC_B.b_value_p -
                motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_j = 0.0;
      motion_controller_withPIC_B.rtb_Add_im_m4 =
        motion_controller_withPIC_B.e_a_tmp_d;
    } else {
      motion_controller_withPIC_B.rtb_Add_re_tmp_j = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_im_m4 =
        motion_controller_withPIC_B.e_a_tmp_d;
    }

    motion_controller_withPIC_B.ed_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_im_m4 -
                    motion_controller_withPIC_B.b_value_tmp,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp_j) +
                     motion_controller_withPIC_B.b_value_a) -
                    motion_controller_withPIC_B.b_value_as));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_j =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_m4 = 0.0;
    } else if ((motion_controller_withPIC_B.b_value_p -
                motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_j = 0.0;
      motion_controller_withPIC_B.rtb_Add_im_m4 =
        motion_controller_withPIC_B.e_a_tmp_d;
    } else {
      motion_controller_withPIC_B.rtb_Add_re_tmp_j = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_im_m4 =
        motion_controller_withPIC_B.e_a_tmp_d;
    }

    motion_controller_withPIC_B.jd_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_im_m4 -
                    motion_controller_withPIC_B.b_value_tmp,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp_j) -
                     motion_controller_withPIC_B.b_value_a) -
                    motion_controller_withPIC_B.b_value_as));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_j =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_m4 = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_ad =
        motion_controller_withPIC_B.rtb_Add_re_tmp_j;
      motion_controller_withPIC_B.rtb_Add_im_kb = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_pcr =
        motion_controller_withPIC_B.rtb_Add_re_tmp_j;
      motion_controller_withPIC_B.rtb_Add_im_bp = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_chp =
        motion_controller_withPIC_B.rtb_Add_re_tmp_j;
      motion_controller_withPIC_B.rtb_Add_im_n = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_ij =
        motion_controller_withPIC_B.rtb_Add_re_tmp_j;
      motion_controller_withPIC_B.rtb_Add_im_my = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_jg =
        motion_controller_withPIC_B.rtb_Add_re_tmp_j;
      motion_controller_withPIC_B.rtb_Add_im_ev = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_mv =
        motion_controller_withPIC_B.rtb_Add_re_tmp_j;
      motion_controller_withPIC_B.rtb_Add_im_m0 = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_jgs =
        motion_controller_withPIC_B.rtb_Add_re_tmp_j;
      motion_controller_withPIC_B.rtb_Add_im_fo = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_tmp_f =
        motion_controller_withPIC_B.rtb_Add_re_tmp_j;
      motion_controller_withPIC_B.rtb_Add_im_a5 = 0.0;
    } else {
      motion_controller_withPIC_B.b_value_p5 =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0;
      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_tmp_j = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_m4 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_tmp_j = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_m4 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_ad = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_kb =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_ad = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_kb =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_pcr = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_bp =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_pcr = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_bp =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_chp = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_n =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_chp = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_n =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_ij = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_my =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_ij = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_my =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_jg = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_ev =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_jg = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_ev =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_mv = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_m0 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_mv = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_m0 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_jgs = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_fo =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_jgs = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_fo =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_tmp_f = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_a5 =
          motion_controller_withPIC_B.e_a_tmp_d;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_tmp_f = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_a5 =
          motion_controller_withPIC_B.e_a_tmp_d;
      }
    }

    motion_controller_withPIC_B.pd_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_im_a5 -
                    motion_controller_withPIC_B.b_value_tmp,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp_f) -
                     motion_controller_withPIC_B.b_value_a) -
                    motion_controller_withPIC_B.b_value_as));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_f =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_a5 = 0.0;
    } else if ((motion_controller_withPIC_B.b_value_p -
                motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_f = 0.0;
      motion_controller_withPIC_B.rtb_Add_im_a5 =
        motion_controller_withPIC_B.e_a_tmp_d;
    } else {
      motion_controller_withPIC_B.rtb_Add_re_tmp_f = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_im_a5 =
        motion_controller_withPIC_B.e_a_tmp_d;
    }

    motion_controller_withPIC_B.td_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_im_a5,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp_f) -
                     motion_controller_withPIC_B.b_value_a) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_f =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_a5 = 0.0;
    } else if ((motion_controller_withPIC_B.b_value_p -
                motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_f = 0.0;
      motion_controller_withPIC_B.rtb_Add_im_a5 =
        motion_controller_withPIC_B.e_a_tmp_d;
    } else {
      motion_controller_withPIC_B.rtb_Add_re_tmp_f = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_im_a5 =
        motion_controller_withPIC_B.e_a_tmp_d;
    }

    motion_controller_withPIC_B.ae_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_im_a5,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp_f) +
                     motion_controller_withPIC_B.b_value_a) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_f =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_a5 = 0.0;
    } else if ((motion_controller_withPIC_B.b_value_p -
                motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_f = 0.0;
      motion_controller_withPIC_B.rtb_Add_im_a5 =
        motion_controller_withPIC_B.e_a_tmp_d;
    } else {
      motion_controller_withPIC_B.rtb_Add_re_tmp_f = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_im_a5 =
        motion_controller_withPIC_B.e_a_tmp_d;
    }

    motion_controller_withPIC_B.ie_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_im_a5 -
                    motion_controller_withPIC_B.b_value_tmp,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp_f) +
                     motion_controller_withPIC_B.b_value_a) -
                    motion_controller_withPIC_B.b_value_as));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_f =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_a5 = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_g =
        motion_controller_withPIC_B.rtb_Add_re_tmp_f;
      motion_controller_withPIC_B.rtb_Add_im_nr = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_d3 =
        motion_controller_withPIC_B.rtb_Add_re_tmp_f;
      motion_controller_withPIC_B.rtb_Add_im_na = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_cg =
        motion_controller_withPIC_B.rtb_Add_re_tmp_f;
      motion_controller_withPIC_B.rtb_Add_im_fx = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_pm =
        motion_controller_withPIC_B.rtb_Add_re_tmp_f;
      motion_controller_withPIC_B.rtb_Add_im_p2 = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_nj =
        motion_controller_withPIC_B.rtb_Add_re_tmp_f;
      motion_controller_withPIC_B.rtb_Add_im_kt = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_n3 =
        motion_controller_withPIC_B.rtb_Add_re_tmp_f;
      motion_controller_withPIC_B.rtb_Add_im_oy = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_gg =
        motion_controller_withPIC_B.rtb_Add_re_tmp_f;
      motion_controller_withPIC_B.rtb_Add_im_cq = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_tmp_js =
        motion_controller_withPIC_B.rtb_Add_re_tmp_f;
      motion_controller_withPIC_B.rtb_Add_im_cj = 0.0;
    } else {
      motion_controller_withPIC_B.b_value_p5 =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0;
      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_tmp_f = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_a5 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_tmp_f = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_a5 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_g = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_nr =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_g = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_nr =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_d3 = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_na =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_d3 = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_na =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_cg = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_fx =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_cg = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_fx =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_pm = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_p2 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_pm = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_p2 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_nj = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_kt =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_nj = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_kt =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_n3 = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_oy =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_n3 = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_oy =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_gg = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_cq =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_gg = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_cq =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_tmp_js = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_cj =
          motion_controller_withPIC_B.e_a_tmp_d;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_tmp_js = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_cj =
          motion_controller_withPIC_B.e_a_tmp_d;
      }
    }

    motion_controller_withPIC_B.ne_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_im_cj -
                    motion_controller_withPIC_B.b_value_tmp,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp_js) -
                     motion_controller_withPIC_B.b_value_a) -
                    motion_controller_withPIC_B.b_value_as));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_js =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_cj = 0.0;
    } else if ((motion_controller_withPIC_B.b_value_p -
                motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_js = 0.0;
      motion_controller_withPIC_B.rtb_Add_im_cj =
        motion_controller_withPIC_B.e_a_tmp_d;
    } else {
      motion_controller_withPIC_B.rtb_Add_re_tmp_js = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_im_cj =
        motion_controller_withPIC_B.e_a_tmp_d;
    }

    motion_controller_withPIC_B.qe_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_im_cj,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp_js) -
                     motion_controller_withPIC_B.b_value_a) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_js =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_cj = 0.0;
    } else if ((motion_controller_withPIC_B.b_value_p -
                motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_js = 0.0;
      motion_controller_withPIC_B.rtb_Add_im_cj =
        motion_controller_withPIC_B.e_a_tmp_d;
    } else {
      motion_controller_withPIC_B.rtb_Add_re_tmp_js = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_im_cj =
        motion_controller_withPIC_B.e_a_tmp_d;
    }

    motion_controller_withPIC_B.ve_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_im_cj,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp_js) +
                     motion_controller_withPIC_B.b_value_a) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_js =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_cj = 0.0;
    } else if ((motion_controller_withPIC_B.b_value_p -
                motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_js = 0.0;
      motion_controller_withPIC_B.rtb_Add_im_cj =
        motion_controller_withPIC_B.e_a_tmp_d;
    } else {
      motion_controller_withPIC_B.rtb_Add_re_tmp_js = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_im_cj =
        motion_controller_withPIC_B.e_a_tmp_d;
    }

    motion_controller_withPIC_B.df_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_im_cj -
                    motion_controller_withPIC_B.b_value_tmp,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp_js) +
                     motion_controller_withPIC_B.b_value_a) -
                    motion_controller_withPIC_B.b_value_as));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_js =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_cj = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_m1 =
        motion_controller_withPIC_B.rtb_Add_re_tmp_js;
      motion_controller_withPIC_B.rtb_Add_im_j = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_k =
        motion_controller_withPIC_B.rtb_Add_re_tmp_js;
      motion_controller_withPIC_B.rtb_Add_im_mx = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_pr =
        motion_controller_withPIC_B.rtb_Add_re_tmp_js;
      motion_controller_withPIC_B.rtb_Add_im_d = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_g4 =
        motion_controller_withPIC_B.rtb_Add_re_tmp_js;
      motion_controller_withPIC_B.rtb_Add_im_c3 = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_cx =
        motion_controller_withPIC_B.rtb_Add_re_tmp_js;
      motion_controller_withPIC_B.rtb_Add_im_if = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_dx =
        motion_controller_withPIC_B.rtb_Add_re_tmp_js;
      motion_controller_withPIC_B.rtb_Add_im_g4 = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_lg =
        motion_controller_withPIC_B.rtb_Add_re_tmp_js;
      motion_controller_withPIC_B.rtb_Add_im_f1 = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_tmp_h =
        motion_controller_withPIC_B.rtb_Add_re_tmp_js;
      motion_controller_withPIC_B.rtb_Add_im_db = 0.0;
    } else {
      motion_controller_withPIC_B.b_value_p5 =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0;
      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_tmp_js = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_cj =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_tmp_js = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_cj =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_m1 = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_j =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_m1 = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_j =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_k = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_mx =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_k = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_mx =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_pr = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_d =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_pr = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_d =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_g4 = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_c3 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_g4 = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_c3 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_cx = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_if =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_cx = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_if =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_dx = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_g4 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_dx = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_g4 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_lg = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_f1 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_lg = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_f1 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_tmp_h = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_db =
          motion_controller_withPIC_B.e_a_tmp_d;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_tmp_h = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_db =
          motion_controller_withPIC_B.e_a_tmp_d;
      }
    }

    motion_controller_withPIC_B.ef_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_im_db,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp_h) -
                     motion_controller_withPIC_B.b_value_a) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_h =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_db = 0.0;
    } else if ((motion_controller_withPIC_B.b_value_p -
                motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_h = 0.0;
      motion_controller_withPIC_B.rtb_Add_im_db =
        motion_controller_withPIC_B.e_a_tmp_d;
    } else {
      motion_controller_withPIC_B.rtb_Add_re_tmp_h = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_im_db =
        motion_controller_withPIC_B.e_a_tmp_d;
    }

    motion_controller_withPIC_B.ff_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_im_db,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp_h) +
                     motion_controller_withPIC_B.b_value_a) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_h =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_db = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_jr =
        motion_controller_withPIC_B.rtb_Add_re_tmp_h;
      motion_controller_withPIC_B.rtb_Add_im_i3 = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_h2 =
        motion_controller_withPIC_B.rtb_Add_re_tmp_h;
      motion_controller_withPIC_B.rtb_Add_im_nm = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_o3 =
        motion_controller_withPIC_B.rtb_Add_re_tmp_h;
      motion_controller_withPIC_B.rtb_Add_im_ch = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_b =
        motion_controller_withPIC_B.rtb_Add_re_tmp_h;
      motion_controller_withPIC_B.rtb_Add_im_er = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_dd =
        motion_controller_withPIC_B.rtb_Add_re_tmp_h;
      motion_controller_withPIC_B.rtb_Add_im_ik = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_tmp_c =
        motion_controller_withPIC_B.rtb_Add_re_tmp_h;
      motion_controller_withPIC_B.rtb_Add_im_gs = 0.0;
    } else {
      motion_controller_withPIC_B.b_value_p5 =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0;
      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_tmp_h = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_db =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_tmp_h = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_db =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_jr = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_i3 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_jr = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_i3 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_h2 = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_nm =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_h2 = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_nm =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_o3 = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_ch =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_o3 = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_ch =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_b = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_er =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_b = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_er =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_dd = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_ik =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_dd = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_ik =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_tmp_c = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_gs =
          motion_controller_withPIC_B.e_a_tmp_d;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_tmp_c = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_gs =
          motion_controller_withPIC_B.e_a_tmp_d;
      }
    }

    motion_controller_withPIC_B.gf_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_im_gs -
                    motion_controller_withPIC_B.b_value_tmp,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp_c) -
                     motion_controller_withPIC_B.b_value_a) -
                    motion_controller_withPIC_B.b_value_as));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_c =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_gs = 0.0;
    } else if ((motion_controller_withPIC_B.b_value_p -
                motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_c = 0.0;
      motion_controller_withPIC_B.rtb_Add_im_gs =
        motion_controller_withPIC_B.e_a_tmp_d;
    } else {
      motion_controller_withPIC_B.rtb_Add_re_tmp_c = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_im_gs =
        motion_controller_withPIC_B.e_a_tmp_d;
    }

    motion_controller_withPIC_B.hf_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_im_gs -
                    motion_controller_withPIC_B.b_value_tmp,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp_c) +
                     motion_controller_withPIC_B.b_value_a) -
                    motion_controller_withPIC_B.b_value_as));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_c =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_gs = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_nn =
        motion_controller_withPIC_B.rtb_Add_re_tmp_c;
      motion_controller_withPIC_B.rtb_Add_im_l0 = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_ce =
        motion_controller_withPIC_B.rtb_Add_re_tmp_c;
      motion_controller_withPIC_B.rtb_Add_im_nc = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_ph =
        motion_controller_withPIC_B.rtb_Add_re_tmp_c;
      motion_controller_withPIC_B.rtb_Add_im_dk = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_oi =
        motion_controller_withPIC_B.rtb_Add_re_tmp_c;
      motion_controller_withPIC_B.rtb_Add_im_jr = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_c2 =
        motion_controller_withPIC_B.rtb_Add_re_tmp_c;
      motion_controller_withPIC_B.rtb_Add_im_hp = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_tmp_n =
        motion_controller_withPIC_B.rtb_Add_re_tmp_c;
      motion_controller_withPIC_B.rtb_Add_im_da = 0.0;
    } else {
      motion_controller_withPIC_B.b_value_p5 =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0;
      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_tmp_c = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_gs =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_tmp_c = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_gs =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_nn = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_l0 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_nn = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_l0 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_ce = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_nc =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_ce = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_nc =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_ph = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_dk =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_ph = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_dk =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_oi = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_jr =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_oi = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_jr =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_c2 = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_hp =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_c2 = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_hp =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_tmp_n = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_da =
          motion_controller_withPIC_B.e_a_tmp_d;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_tmp_n = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_da =
          motion_controller_withPIC_B.e_a_tmp_d;
      }
    }

    motion_controller_withPIC_B.if_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_im_da,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp_n) -
                     motion_controller_withPIC_B.b_value_a) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_n =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_da = 0.0;
    } else if ((motion_controller_withPIC_B.b_value_p -
                motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_n = 0.0;
      motion_controller_withPIC_B.rtb_Add_im_da =
        motion_controller_withPIC_B.e_a_tmp_d;
    } else {
      motion_controller_withPIC_B.rtb_Add_re_tmp_n = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_im_da =
        motion_controller_withPIC_B.e_a_tmp_d;
    }

    motion_controller_withPIC_B.jf_a = sin(motion_controller_withPIC_B.df_j -
      rt_atan2d_snf(motion_controller_withPIC_B.n_a_tmp +
                    motion_controller_withPIC_B.rtb_Add_im_da,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp_n) +
                     motion_controller_withPIC_B.b_value_a) +
                    motion_controller_withPIC_B.n_a_tmp_a));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_n =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_da = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_c5 =
        motion_controller_withPIC_B.rtb_Add_re_tmp_n;
      motion_controller_withPIC_B.rtb_Add_im_pw = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_pi =
        motion_controller_withPIC_B.rtb_Add_re_tmp_n;
      motion_controller_withPIC_B.rtb_Add_im_a4 = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_ow =
        motion_controller_withPIC_B.rtb_Add_re_tmp_n;
      motion_controller_withPIC_B.rtb_Add_im_jw = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_pie =
        motion_controller_withPIC_B.rtb_Add_re_tmp_n;
      motion_controller_withPIC_B.rtb_Add_im_ob = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_lm =
        motion_controller_withPIC_B.rtb_Add_re_tmp_n;
      motion_controller_withPIC_B.rtb_Add_im_kv = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_tmp_k =
        motion_controller_withPIC_B.rtb_Add_re_tmp_n;
      motion_controller_withPIC_B.rtb_Add_im_jk = 0.0;
    } else {
      motion_controller_withPIC_B.b_value_p5 =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0;
      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_tmp_n = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_da =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_tmp_n = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_da =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_c5 = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_pw =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_c5 = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_pw =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_pi = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_a4 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_pi = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_a4 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_ow = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_jw =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_ow = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_jw =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_pie = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_ob =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_pie = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_ob =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_lm = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_kv =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_lm = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_kv =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_tmp_k = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_jk =
          motion_controller_withPIC_B.e_a_tmp_d;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_tmp_k = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_jk =
          motion_controller_withPIC_B.e_a_tmp_d;
      }
    }

    motion_controller_withPIC_B.kf_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_im_jk -
                    motion_controller_withPIC_B.b_value_tmp,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp_k) -
                     motion_controller_withPIC_B.b_value_a) -
                    motion_controller_withPIC_B.b_value_as));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_k =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_jk = 0.0;
    } else if ((motion_controller_withPIC_B.b_value_p -
                motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
                (motion_controller_withPIC_B.yaw)) * 0.0 == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_k = 0.0;
      motion_controller_withPIC_B.rtb_Add_im_jk =
        motion_controller_withPIC_B.e_a_tmp_d;
    } else {
      motion_controller_withPIC_B.rtb_Add_re_tmp_k = (rtNaN);
      motion_controller_withPIC_B.rtb_Add_im_jk =
        motion_controller_withPIC_B.e_a_tmp_d;
    }

    motion_controller_withPIC_B.lf_a = sin(motion_controller_withPIC_B.dr_i -
      rt_atan2d_snf(motion_controller_withPIC_B.rtb_Add_im_jk -
                    motion_controller_withPIC_B.b_value_tmp,
                    ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                      motion_controller_withPIC_B.rtb_Add_re_tmp_k) +
                     motion_controller_withPIC_B.b_value_a) -
                    motion_controller_withPIC_B.b_value_as));
    if (motion_controller_withPIC_B.e_a_tmp == 0.0) {
      motion_controller_withPIC_B.rtb_Add_re_tmp_k =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0 /
        motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      motion_controller_withPIC_B.rtb_Add_im_jk = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_fz =
        motion_controller_withPIC_B.rtb_Add_re_tmp_k;
      motion_controller_withPIC_B.rtb_Add_im_cm = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_fq =
        motion_controller_withPIC_B.rtb_Add_re_tmp_k;
      motion_controller_withPIC_B.rtb_Add_im_nl = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_iu =
        motion_controller_withPIC_B.rtb_Add_re_tmp_k;
      motion_controller_withPIC_B.rtb_Add_im_l4 = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_i3 =
        motion_controller_withPIC_B.rtb_Add_re_tmp_k;
      motion_controller_withPIC_B.rtb_Add_im_k1 = 0.0;
      motion_controller_withPIC_B.rtb_Add_re_fc =
        motion_controller_withPIC_B.rtb_Add_re_tmp_k;
      motion_controller_withPIC_B.e_a_tmp_d = 0.0;
    } else {
      motion_controller_withPIC_B.b_value_p5 =
        (motion_controller_withPIC_B.b_value_p -
         motion_controller_withPIC_B.In1_je.twist.twist.linear.x * sin
         (motion_controller_withPIC_B.yaw)) * 0.0;
      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_tmp_k = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_jk =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_tmp_k = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_jk =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_fz = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_cm =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_fz = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_cm =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_fq = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_nl =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_fq = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_nl =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_iu = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_l4 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_iu = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_l4 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_i3 = 0.0;
        motion_controller_withPIC_B.rtb_Add_im_k1 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_i3 = (rtNaN);
        motion_controller_withPIC_B.rtb_Add_im_k1 =
          motion_controller_withPIC_B.e_a_tmp /
          motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
      }

      if (motion_controller_withPIC_B.b_value_p5 == 0.0) {
        motion_controller_withPIC_B.rtb_Add_re_fc = 0.0;
      } else {
        motion_controller_withPIC_B.rtb_Add_re_fc = (rtNaN);
      }
    }

    motion_controller_withPIC_B.Fy1_tmp_tmp = motion_controller_withPIC_P.m *
      motion_controller_withPIC_P.g;
    motion_controller_withPIC_B.Fy1_tmp_tmp_i = motion_controller_withPIC_P.m *
      motion_controller_withPIC_B.In1_f.linear_acceleration.x *
      motion_controller_withPIC_P.hCG;
    motion_controller_withPIC_B.Fy2 = (motion_controller_withPIC_B.Fy1_tmp_tmp *
      motion_controller_withPIC_P.b - motion_controller_withPIC_B.Fy1_tmp_tmp_i)
      / 2.0 / motion_controller_withPIC_P.L;
    motion_controller_withPIC_B.Fy1_tmp = motion_controller_withPIC_P.Krsf *
      motion_controller_withPIC_P.m * motion_controller_withPIC_B.Ay *
      motion_controller_withPIC_P.hCG / motion_controller_withPIC_P.B;
    motion_controller_withPIC_B.Fy4 = motion_controller_withPIC_P.B / 2.0 *
      motion_controller_withPIC_B.b_value_ct;
    motion_controller_withPIC_B.Fy3 =
      motion_controller_withPIC_B.In1_je.twist.twist.linear.x -
      motion_controller_withPIC_B.Fy4;
    motion_controller_withPIC_B.b_value_p5 = sin(atan(sin(rt_atan2d_snf
      (motion_controller_withPIC_B.o_a_tmp, motion_controller_withPIC_B.Fy3) -
      motion_controller_withPIC_B.df_j) * motion_controller_withPIC_B.b_value_l)
      * motion_controller_withPIC_B.b_value_o) *
      ((motion_controller_withPIC_B.Fy2 - motion_controller_withPIC_B.Fy1_tmp) *
       motion_controller_withPIC_B.b_value_o2);
    motion_controller_withPIC_B.Fy4 +=
      motion_controller_withPIC_B.In1_je.twist.twist.linear.x;
    motion_controller_withPIC_B.Fy2 = sin(atan(sin(rt_atan2d_snf
      (motion_controller_withPIC_B.o_a_tmp, motion_controller_withPIC_B.Fy4) -
      motion_controller_withPIC_B.df_j) * motion_controller_withPIC_B.b_value_l)
      * motion_controller_withPIC_B.b_value_o) *
      ((motion_controller_withPIC_B.Fy2 + motion_controller_withPIC_B.Fy1_tmp) *
       motion_controller_withPIC_B.b_value_o2);
    motion_controller_withPIC_B.Fy1_tmp_tmp =
      (motion_controller_withPIC_B.Fy1_tmp_tmp * motion_controller_withPIC_P.a +
       motion_controller_withPIC_B.Fy1_tmp_tmp_i) / 2.0 /
      motion_controller_withPIC_P.L;
    motion_controller_withPIC_B.Fy1_tmp_tmp_i = (1.0 -
      motion_controller_withPIC_P.Krsf) * motion_controller_withPIC_P.m *
      motion_controller_withPIC_B.Ay * motion_controller_withPIC_P.hCG /
      motion_controller_withPIC_P.B;
    motion_controller_withPIC_B.Fy3 = sin(atan(sin(rt_atan2d_snf
      (motion_controller_withPIC_B.i_a_tmp, motion_controller_withPIC_B.Fy3) -
      motion_controller_withPIC_B.dr_i) * motion_controller_withPIC_B.b_value_ip)
      * motion_controller_withPIC_B.b_value_f) *
      ((motion_controller_withPIC_B.Fy1_tmp_tmp -
        motion_controller_withPIC_B.Fy1_tmp_tmp_i) *
       motion_controller_withPIC_B.b_value_iz);
    motion_controller_withPIC_B.Fy4 = sin(atan(sin(rt_atan2d_snf
      (motion_controller_withPIC_B.i_a_tmp, motion_controller_withPIC_B.Fy4) -
      motion_controller_withPIC_B.dr_i) * motion_controller_withPIC_B.b_value_ip)
      * motion_controller_withPIC_B.b_value_f) *
      ((motion_controller_withPIC_B.Fy1_tmp_tmp +
        motion_controller_withPIC_B.Fy1_tmp_tmp_i) *
       motion_controller_withPIC_B.b_value_iz);
    motion_controller_withPIC_B.Fy1_tmp_tmp = motion_controller_withPIC_B.dr_i +
      motion_controller_withPIC_B.yaw;
    motion_controller_withPIC_B.Fy1_tmp_tmp_i = cos
      (motion_controller_withPIC_B.Fy1_tmp_tmp);
    motion_controller_withPIC_B.Fy1_tmp = motion_controller_withPIC_B.df_j +
      motion_controller_withPIC_B.yaw;
    motion_controller_withPIC_B.A0_tmp = cos(motion_controller_withPIC_B.Fy1_tmp);
    motion_controller_withPIC_B.A0_tmp_c = sin
      (motion_controller_withPIC_B.Fy1_tmp);
    motion_controller_withPIC_B.A0_tmp_o = sin
      (motion_controller_withPIC_B.Fy1_tmp_tmp);
    motion_controller_withPIC_B.Fy1_tmp_tmp = cos
      (motion_controller_withPIC_B.df_j);
    motion_controller_withPIC_B.Fy1_tmp = sin(motion_controller_withPIC_B.df_j);
    motion_controller_withPIC_B.A0_tmp_tmp_b = cos
      (motion_controller_withPIC_B.dr_i);
    motion_controller_withPIC_B.A0_tmp_tmp = sin
      (motion_controller_withPIC_B.dr_i);
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[1] = 0.0;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a =
      motion_controller_withPIC_B.b_value_ip *
      motion_controller_withPIC_B.b_value_f *
      motion_controller_withPIC_B.b_value_iz;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d =
      motion_controller_withPIC_B.b_value_ip *
      motion_controller_withPIC_B.b_value_ip;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e =
      motion_controller_withPIC_B.b_value_l *
      motion_controller_withPIC_B.b_value_o *
      motion_controller_withPIC_B.b_value_o2;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eh =
      motion_controller_withPIC_B.b_value_l *
      motion_controller_withPIC_B.b_value_l;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fr =
      motion_controller_withPIC_B.In1_f.linear_acceleration.x *
      motion_controller_withPIC_P.hCG * motion_controller_withPIC_P.m / 2.0;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_f =
      (motion_controller_withPIC_P.a * motion_controller_withPIC_P.g *
       motion_controller_withPIC_P.m / 2.0 +
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fr) /
      motion_controller_withPIC_P.L;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j =
      motion_controller_withPIC_B.Ay * motion_controller_withPIC_P.hCG *
      motion_controller_withPIC_P.m * (motion_controller_withPIC_P.Krsf - 1.0) /
      motion_controller_withPIC_P.B;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_o =
      motion_controller_withPIC_B.i_a_tmp * 0.0;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__oy =
      (motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fr -
       motion_controller_withPIC_P.b * motion_controller_withPIC_P.g *
       motion_controller_withPIC_P.m / 2.0) / motion_controller_withPIC_P.L;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_l =
      motion_controller_withPIC_B.Ay * motion_controller_withPIC_P.Krsf *
      motion_controller_withPIC_P.hCG * motion_controller_withPIC_P.m /
      motion_controller_withPIC_P.B;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__lu =
      motion_controller_withPIC_B.o_a_tmp * 0.0;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_g =
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_f -
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_f +=
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j =
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__oy +
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_l;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__oy -=
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_l;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fr = 1.0 /
      motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_l =
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fr /
      (motion_controller_withPIC_P.B * motion_controller_withPIC_B.b_value_ct /
       2.0 - motion_controller_withPIC_B.In1_je.twist.twist.linear.x);
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__av =
      motion_controller_withPIC_B.b_value_e *
      motion_controller_withPIC_B.b_value_e;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fn =
      motion_controller_withPIC_B.b_value_i *
      motion_controller_withPIC_B.b_value_i;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__jz =
      motion_controller_withPIC_B.q_a_tmp * motion_controller_withPIC_B.q_a_tmp;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__kl =
      motion_controller_withPIC_B.o_a_tmp * motion_controller_withPIC_B.o_a_tmp;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_b =
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_o /
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fn;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__hn =
      motion_controller_withPIC_B.i_a_tmp * motion_controller_withPIC_B.i_a_tmp;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_h =
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__hn +
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fn;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eg =
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_o /
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__av;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ku =
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__lu /
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__av;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__jw =
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__kl +
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__av;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__lu /=
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__jz;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__kl +=
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__jz;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__oo =
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_l -
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ku;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_c =
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fr /
      motion_controller_withPIC_B.q_a_tmp -
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__lu;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fr =
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fr /
      motion_controller_withPIC_B.b_value_i +
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_b;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[5] = -((cos(atan(sin
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_im_l -
        motion_controller_withPIC_B.b_value_tmp,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re) -
         motion_controller_withPIC_B.b_value_a) -
        motion_controller_withPIC_B.b_value_as)) *
      motion_controller_withPIC_B.b_value_ip) *
      motion_controller_withPIC_B.b_value_f) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_im -
        motion_controller_withPIC_B.b_value_tmp,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.b_value_ax) -
         motion_controller_withPIC_B.b_value_a) -
        motion_controller_withPIC_B.b_value_as)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_f * (1.0 /
      motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp /
      motion_controller_withPIC_B.b_value_e -
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eg) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__av /
      ((motion_controller_withPIC_B.f_a * motion_controller_withPIC_B.f_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d + 1.0) *
       (motion_controller_withPIC_B.e_a * motion_controller_withPIC_B.e_a +
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__av)) - cos(atan
      (sin(motion_controller_withPIC_B.dr_i - rt_atan2d_snf
           (motion_controller_withPIC_B.rtb_Add_im_f -
            motion_controller_withPIC_B.b_value_tmp,
            ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
              motion_controller_withPIC_B.rtb_Add_re_c) +
             motion_controller_withPIC_B.b_value_a) -
            motion_controller_withPIC_B.b_value_as)) *
       motion_controller_withPIC_B.b_value_ip) *
      motion_controller_withPIC_B.b_value_f) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_im_m -
        motion_controller_withPIC_B.b_value_tmp,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_m) +
         motion_controller_withPIC_B.b_value_a) -
        motion_controller_withPIC_B.b_value_as)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_g *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fr *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fn /
      ((motion_controller_withPIC_B.k_a * motion_controller_withPIC_B.k_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_h)) *
      motion_controller_withPIC_B.Fy1_tmp_tmp_i - (cos(atan(sin
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_h,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_o) -
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.b_value_l) *
      motion_controller_withPIC_B.b_value_o) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_e,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_p) -
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__oo *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__av /
      ((motion_controller_withPIC_B.n_a * motion_controller_withPIC_B.n_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eh + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__jw) + cos(atan
      (sin(motion_controller_withPIC_B.df_j - rt_atan2d_snf
           (motion_controller_withPIC_B.n_a_tmp +
            motion_controller_withPIC_B.rtb_Add_im_mc,
            ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
              motion_controller_withPIC_B.rtb_Add_re_me) +
             motion_controller_withPIC_B.b_value_a) +
            motion_controller_withPIC_B.n_a_tmp_a)) *
       motion_controller_withPIC_B.b_value_l) *
      motion_controller_withPIC_B.b_value_o) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_h2,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_l) +
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__oy *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_c *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__jz /
      ((motion_controller_withPIC_B.s_a * motion_controller_withPIC_B.s_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eh + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__kl)) *
      motion_controller_withPIC_B.A0_tmp) / motion_controller_withPIC_P.m;
    motion_controller_withPIC_B.b_value_ax =
      motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp *
      motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp;
    motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp =
      motion_controller_withPIC_B.i_a_tmp_tmp_tmp *
      motion_controller_withPIC_B.rtb_Add_tmp_tmp /
      motion_controller_withPIC_B.b_value_ax -
      motion_controller_withPIC_B.In1_je.twist.twist.linear.x;
    motion_controller_withPIC_B.e_a =
      motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp /
      motion_controller_withPIC_B.b_value_e;
    motion_controller_withPIC_B.i_a_tmp_tmp_tmp =
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__av +
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__hn;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eg =
      motion_controller_withPIC_B.e_a -
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eg;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ku =
      motion_controller_withPIC_B.e_a -
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ku;
    motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__lu =
      motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp /
      motion_controller_withPIC_B.q_a_tmp -
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__lu;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[9] = ((((cos(atan
      (sin(motion_controller_withPIC_B.dr_i - rt_atan2d_snf
           (motion_controller_withPIC_B.rtb_Add_im_a -
            motion_controller_withPIC_B.b_value_tmp,
            ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
              motion_controller_withPIC_B.rtb_Add_re_p4) +
             motion_controller_withPIC_B.b_value_a) -
            motion_controller_withPIC_B.b_value_as)) *
       motion_controller_withPIC_B.b_value_ip) *
      motion_controller_withPIC_B.b_value_f) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_im_p -
        motion_controller_withPIC_B.b_value_tmp,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_pc) +
         motion_controller_withPIC_B.b_value_a) -
        motion_controller_withPIC_B.b_value_as)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a) *
      ((motion_controller_withPIC_B.e_a_tmp *
        motion_controller_withPIC_B.rtb_Add_tmp_tmp /
        motion_controller_withPIC_B.b_value_ax -
        motion_controller_withPIC_B.In1_je.twist.twist.linear.x) /
       motion_controller_withPIC_B.b_value_i +
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_b) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_g *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fn /
      ((motion_controller_withPIC_B.bb_a * motion_controller_withPIC_B.bb_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_h) - cos(atan
      (sin(motion_controller_withPIC_B.dr_i - rt_atan2d_snf
           (motion_controller_withPIC_B.rtb_Add_im_b -
            motion_controller_withPIC_B.b_value_tmp,
            ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
              motion_controller_withPIC_B.rtb_Add_re_ol) -
             motion_controller_withPIC_B.b_value_a) -
            motion_controller_withPIC_B.b_value_as)) *
       motion_controller_withPIC_B.b_value_ip) *
      motion_controller_withPIC_B.b_value_f) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_im_ek -
        motion_controller_withPIC_B.b_value_tmp,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_j) -
         motion_controller_withPIC_B.b_value_a) -
        motion_controller_withPIC_B.b_value_as)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eg *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_f *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__av /
      ((motion_controller_withPIC_B.hb_a * motion_controller_withPIC_B.hb_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d + 1.0) *
       motion_controller_withPIC_B.i_a_tmp_tmp_tmp)) *
      motion_controller_withPIC_B.Fy1_tmp_tmp_i + (sin(atan(sin
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_im_h3 -
        motion_controller_withPIC_B.b_value_tmp,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_tmp) -
         motion_controller_withPIC_B.b_value_a) -
        motion_controller_withPIC_B.b_value_as)) *
      motion_controller_withPIC_B.b_value_ip) *
      motion_controller_withPIC_B.b_value_f) *
      motion_controller_withPIC_B.b_value_iz *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_f + sin(atan(sin
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_im_k -
        motion_controller_withPIC_B.b_value_tmp,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_cs) +
         motion_controller_withPIC_B.b_value_a) -
        motion_controller_withPIC_B.b_value_as)) *
      motion_controller_withPIC_B.b_value_ip) *
      motion_controller_withPIC_B.b_value_f) *
      motion_controller_withPIC_B.b_value_iz *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_g) *
      motion_controller_withPIC_B.A0_tmp_o) - (sin(atan(sin
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_g,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_a) -
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.b_value_l) *
      motion_controller_withPIC_B.b_value_o) *
      motion_controller_withPIC_B.b_value_o2 *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j + sin(atan(sin
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_fi,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_e) +
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.b_value_l) *
      motion_controller_withPIC_B.b_value_o) *
      motion_controller_withPIC_B.b_value_o2 *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__oy) *
      motion_controller_withPIC_B.A0_tmp_c) + (cos(atan(sin
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_ax,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_ch) -
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.b_value_l) *
      motion_controller_withPIC_B.b_value_o) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_ei,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_h) -
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ku *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__av /
      ((motion_controller_withPIC_B.lb_a * motion_controller_withPIC_B.lb_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eh + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__jw) + cos(atan
      (sin(motion_controller_withPIC_B.df_j - rt_atan2d_snf
           (motion_controller_withPIC_B.n_a_tmp +
            motion_controller_withPIC_B.rtb_Add_im_ms,
            ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
              motion_controller_withPIC_B.rtb_Add_re_pb) +
             motion_controller_withPIC_B.b_value_a) +
            motion_controller_withPIC_B.n_a_tmp_a)) *
       motion_controller_withPIC_B.b_value_l) *
      motion_controller_withPIC_B.b_value_o) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_af,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_d) +
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__lu *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__oy *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__jz /
      ((motion_controller_withPIC_B.rb_a * motion_controller_withPIC_B.rb_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eh + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__kl)) *
      motion_controller_withPIC_B.A0_tmp) / motion_controller_withPIC_P.m;
    motion_controller_withPIC_B.i_a_tmp *= motion_controller_withPIC_P.B / 2.0;
    motion_controller_withPIC_B.e_a_tmp = motion_controller_withPIC_P.B / 2.0 *
      motion_controller_withPIC_B.o_a_tmp;
    motion_controller_withPIC_B.rtb_Add_tmp_tmp =
      motion_controller_withPIC_B.i_a_tmp /
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__av +
      motion_controller_withPIC_P.b / motion_controller_withPIC_B.b_value_e;
    motion_controller_withPIC_B.e_a = (0.0 - motion_controller_withPIC_P.a) /
      motion_controller_withPIC_B.b_value_e +
      motion_controller_withPIC_B.e_a_tmp /
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__av;
    motion_controller_withPIC_B.e_a_tmp = motion_controller_withPIC_B.e_a_tmp /
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__jz +
      motion_controller_withPIC_P.a / motion_controller_withPIC_B.q_a_tmp;
    motion_controller_withPIC_B.b_value_i = (0.0 - motion_controller_withPIC_P.b)
      / motion_controller_withPIC_B.b_value_i -
      motion_controller_withPIC_B.i_a_tmp /
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fn;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[13] = ((cos(atan(sin
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_im_lu -
        motion_controller_withPIC_B.b_value_tmp,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_n) +
         motion_controller_withPIC_B.b_value_a) -
        motion_controller_withPIC_B.b_value_as)) *
      motion_controller_withPIC_B.b_value_ip) *
      motion_controller_withPIC_B.b_value_f) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_im_o -
        motion_controller_withPIC_B.b_value_tmp,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_tmp_d) +
         motion_controller_withPIC_B.b_value_a) -
        motion_controller_withPIC_B.b_value_as)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a) *
      motion_controller_withPIC_B.b_value_i *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_g *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fn /
      ((motion_controller_withPIC_B.yb_a * motion_controller_withPIC_B.yb_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_h) + cos(atan
      (sin(motion_controller_withPIC_B.dr_i - rt_atan2d_snf
           (motion_controller_withPIC_B.rtb_Add_im_i -
            motion_controller_withPIC_B.b_value_tmp,
            ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
              motion_controller_withPIC_B.rtb_Add_re_f) -
             motion_controller_withPIC_B.b_value_a) -
            motion_controller_withPIC_B.b_value_as)) *
       motion_controller_withPIC_B.b_value_ip) *
      motion_controller_withPIC_B.b_value_f) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_im_pt -
        motion_controller_withPIC_B.b_value_tmp,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_pe) -
         motion_controller_withPIC_B.b_value_a) -
        motion_controller_withPIC_B.b_value_as)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a) *
      motion_controller_withPIC_B.rtb_Add_tmp_tmp *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_f *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__av /
      ((motion_controller_withPIC_B.ec_a * motion_controller_withPIC_B.ec_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d + 1.0) *
       motion_controller_withPIC_B.i_a_tmp_tmp_tmp)) *
      motion_controller_withPIC_B.Fy1_tmp_tmp_i - (cos(atan(sin
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_oc,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_i) -
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.b_value_l) *
      motion_controller_withPIC_B.b_value_o) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_kk,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_ox) -
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e) *
      motion_controller_withPIC_B.e_a *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__av /
      ((motion_controller_withPIC_B.hc_a * motion_controller_withPIC_B.hc_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eh + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__jw) - cos(atan
      (sin(motion_controller_withPIC_B.df_j - rt_atan2d_snf
           (motion_controller_withPIC_B.n_a_tmp +
            motion_controller_withPIC_B.rtb_Add_im_hc,
            ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
              motion_controller_withPIC_B.rtb_Add_re_fb) +
             motion_controller_withPIC_B.b_value_a) +
            motion_controller_withPIC_B.n_a_tmp_a)) *
       motion_controller_withPIC_B.b_value_l) *
      motion_controller_withPIC_B.b_value_o) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_c,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_m4) +
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e) *
      motion_controller_withPIC_B.e_a_tmp *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__oy *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__jz /
      ((motion_controller_withPIC_B.mc_a * motion_controller_withPIC_B.mc_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eh + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__kl)) *
      motion_controller_withPIC_B.A0_tmp) / motion_controller_withPIC_P.m;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[0] = 0.0;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[2] = 0.0;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[4] = 1.0;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[6] = 0.0;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[8] = 0.0;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[10] = 0.0;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[12] = 0.0;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[14] = 1.0;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[3] = 0.0;
    motion_controller_withPIC_B.ec_a = motion_controller_withPIC_P.B *
      motion_controller_withPIC_B.A0_tmp_tmp / 2.0;
    motion_controller_withPIC_B.mc_a = motion_controller_withPIC_P.b *
      motion_controller_withPIC_B.A0_tmp_tmp_b;
    motion_controller_withPIC_B.yb_a = motion_controller_withPIC_B.ec_a -
      motion_controller_withPIC_B.mc_a;
    motion_controller_withPIC_B.rtb_Add_im_o = motion_controller_withPIC_P.B *
      motion_controller_withPIC_B.Fy1_tmp / 2.0;
    motion_controller_withPIC_B.b_value_ax = motion_controller_withPIC_P.a *
      motion_controller_withPIC_B.Fy1_tmp_tmp;
    motion_controller_withPIC_B.hc_a = motion_controller_withPIC_B.rtb_Add_im_o
      - motion_controller_withPIC_B.b_value_ax;
    motion_controller_withPIC_B.rtb_Add_im_o +=
      motion_controller_withPIC_B.b_value_ax;
    motion_controller_withPIC_B.ec_a += motion_controller_withPIC_B.mc_a;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[7] = -(((-(cos(atan
      (sin(motion_controller_withPIC_B.df_j - rt_atan2d_snf
           (motion_controller_withPIC_B.n_a_tmp +
            motion_controller_withPIC_B.rtb_Add_im_kb,
            ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
              motion_controller_withPIC_B.rtb_Add_re_ad) -
             motion_controller_withPIC_B.b_value_a) +
            motion_controller_withPIC_B.n_a_tmp_a)) *
       motion_controller_withPIC_B.b_value_l) *
      motion_controller_withPIC_B.b_value_o) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_m4,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_tmp_j) -
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j *
      motion_controller_withPIC_B.rtb_Add_im_o *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__oo *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__av) /
      ((motion_controller_withPIC_B.rc_a * motion_controller_withPIC_B.rc_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eh + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__jw) + cos(atan
      (sin(motion_controller_withPIC_B.df_j - rt_atan2d_snf
           (motion_controller_withPIC_B.n_a_tmp +
            motion_controller_withPIC_B.rtb_Add_im_n,
            ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
              motion_controller_withPIC_B.rtb_Add_re_chp) +
             motion_controller_withPIC_B.b_value_a) +
            motion_controller_withPIC_B.n_a_tmp_a)) *
       motion_controller_withPIC_B.b_value_l) *
      motion_controller_withPIC_B.b_value_o) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_bp,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_pcr) +
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__oy *
      motion_controller_withPIC_B.hc_a *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_c *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__jz /
      ((motion_controller_withPIC_B.wc_a * motion_controller_withPIC_B.wc_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eh + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__kl)) + cos(atan
      (sin(motion_controller_withPIC_B.dr_i - rt_atan2d_snf
           (motion_controller_withPIC_B.rtb_Add_im_ev -
            motion_controller_withPIC_B.b_value_tmp,
            ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
              motion_controller_withPIC_B.rtb_Add_re_jg) +
             motion_controller_withPIC_B.b_value_a) -
            motion_controller_withPIC_B.b_value_as)) *
       motion_controller_withPIC_B.b_value_ip) *
      motion_controller_withPIC_B.b_value_f) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_im_my -
        motion_controller_withPIC_B.b_value_tmp,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_ij) +
         motion_controller_withPIC_B.b_value_a) -
        motion_controller_withPIC_B.b_value_as)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a) *
      motion_controller_withPIC_B.ec_a *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_g *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fr *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fn /
      ((motion_controller_withPIC_B.ed_a * motion_controller_withPIC_B.ed_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_h)) + cos(atan
      (sin(motion_controller_withPIC_B.dr_i - rt_atan2d_snf
           (motion_controller_withPIC_B.rtb_Add_im_fo -
            motion_controller_withPIC_B.b_value_tmp,
            ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
              motion_controller_withPIC_B.rtb_Add_re_jgs) -
             motion_controller_withPIC_B.b_value_a) -
            motion_controller_withPIC_B.b_value_as)) *
       motion_controller_withPIC_B.b_value_ip) *
      motion_controller_withPIC_B.b_value_f) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_im_m0 -
        motion_controller_withPIC_B.b_value_tmp,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_mv) -
         motion_controller_withPIC_B.b_value_a) -
        motion_controller_withPIC_B.b_value_as)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a) *
      motion_controller_withPIC_B.yb_a *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_f *
      (motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_l -
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_o /
       (motion_controller_withPIC_B.b_value_e *
        motion_controller_withPIC_B.b_value_e)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__av /
      ((motion_controller_withPIC_B.jd_a * motion_controller_withPIC_B.jd_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d + 1.0) *
       motion_controller_withPIC_B.i_a_tmp_tmp_tmp)) /
      motion_controller_withPIC_P.Izz;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[11] = -(((cos(atan
      (sin(motion_controller_withPIC_B.dr_i - rt_atan2d_snf
           (motion_controller_withPIC_B.rtb_Add_im_nr -
            motion_controller_withPIC_B.b_value_tmp,
            ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
              motion_controller_withPIC_B.rtb_Add_re_g) -
             motion_controller_withPIC_B.b_value_a) -
            motion_controller_withPIC_B.b_value_as)) *
       motion_controller_withPIC_B.b_value_ip) *
      motion_controller_withPIC_B.b_value_f) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_im_a5 -
        motion_controller_withPIC_B.b_value_tmp,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_tmp_f) -
         motion_controller_withPIC_B.b_value_a) -
        motion_controller_withPIC_B.b_value_as)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eg *
      motion_controller_withPIC_B.yb_a *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_f *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__av /
      ((motion_controller_withPIC_B.pd_a * motion_controller_withPIC_B.pd_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d + 1.0) *
       motion_controller_withPIC_B.i_a_tmp_tmp_tmp) - cos(atan(sin
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_fx,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_cg) -
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.b_value_l) *
      motion_controller_withPIC_B.b_value_o) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_na,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_d3) -
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__ku *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j *
      motion_controller_withPIC_B.rtb_Add_im_o *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__av /
      ((motion_controller_withPIC_B.td_a * motion_controller_withPIC_B.td_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eh + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__jw)) + cos(atan
      (sin(motion_controller_withPIC_B.df_j - rt_atan2d_snf
           (motion_controller_withPIC_B.n_a_tmp +
            motion_controller_withPIC_B.rtb_Add_im_kt,
            ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
              motion_controller_withPIC_B.rtb_Add_re_nj) +
             motion_controller_withPIC_B.b_value_a) +
            motion_controller_withPIC_B.n_a_tmp_a)) *
       motion_controller_withPIC_B.b_value_l) *
      motion_controller_withPIC_B.b_value_o) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_p2,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_pm) +
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__lu *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__oy *
      motion_controller_withPIC_B.hc_a *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__jz /
      ((motion_controller_withPIC_B.ae_a * motion_controller_withPIC_B.ae_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eh + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__kl)) + cos(atan
      (sin(motion_controller_withPIC_B.dr_i - rt_atan2d_snf
           (motion_controller_withPIC_B.rtb_Add_im_cq -
            motion_controller_withPIC_B.b_value_tmp,
            ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
              motion_controller_withPIC_B.rtb_Add_re_gg) +
             motion_controller_withPIC_B.b_value_a) -
            motion_controller_withPIC_B.b_value_as)) *
       motion_controller_withPIC_B.b_value_ip) *
      motion_controller_withPIC_B.b_value_f) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_im_oy -
        motion_controller_withPIC_B.b_value_tmp,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_n3) +
         motion_controller_withPIC_B.b_value_a) -
        motion_controller_withPIC_B.b_value_as)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a) *
      motion_controller_withPIC_B.ec_a *
      (motion_controller_withPIC_B.rtb_Add_tmp_tmp_tmp /
       (motion_controller_withPIC_P.B * motion_controller_withPIC_B.b_value_ct /
        2.0 + motion_controller_withPIC_B.In1_je.twist.twist.linear.x) +
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_b) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_g *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fn /
      ((motion_controller_withPIC_B.ie_a * motion_controller_withPIC_B.ie_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_h)) /
      motion_controller_withPIC_P.Izz;
    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[15] = -(((-(cos(atan
      (sin(motion_controller_withPIC_B.dr_i - rt_atan2d_snf
           (motion_controller_withPIC_B.rtb_Add_im_j -
            motion_controller_withPIC_B.b_value_tmp,
            ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
              motion_controller_withPIC_B.rtb_Add_re_m1) -
             motion_controller_withPIC_B.b_value_a) -
            motion_controller_withPIC_B.b_value_as)) *
       motion_controller_withPIC_B.b_value_ip) *
      motion_controller_withPIC_B.b_value_f) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_im_cj -
        motion_controller_withPIC_B.b_value_tmp,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_tmp_js) -
         motion_controller_withPIC_B.b_value_a) -
        motion_controller_withPIC_B.b_value_as)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a) *
      motion_controller_withPIC_B.rtb_Add_tmp_tmp *
      motion_controller_withPIC_B.yb_a *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_f *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__av) /
      ((motion_controller_withPIC_B.ne_a * motion_controller_withPIC_B.ne_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d + 1.0) *
       motion_controller_withPIC_B.i_a_tmp_tmp_tmp) + cos(atan(sin
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_d,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_pr) -
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.b_value_l) *
      motion_controller_withPIC_B.b_value_o) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_mx,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_k) -
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e) *
      motion_controller_withPIC_B.e_a *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j *
      motion_controller_withPIC_B.rtb_Add_im_o *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__av /
      ((motion_controller_withPIC_B.qe_a * motion_controller_withPIC_B.qe_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eh + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__jw)) + cos(atan
      (sin(motion_controller_withPIC_B.df_j - rt_atan2d_snf
           (motion_controller_withPIC_B.n_a_tmp +
            motion_controller_withPIC_B.rtb_Add_im_if,
            ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
              motion_controller_withPIC_B.rtb_Add_re_cx) +
             motion_controller_withPIC_B.b_value_a) +
            motion_controller_withPIC_B.n_a_tmp_a)) *
       motion_controller_withPIC_B.b_value_l) *
      motion_controller_withPIC_B.b_value_o) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_c3,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_g4) +
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e) *
      motion_controller_withPIC_B.e_a_tmp *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__oy *
      motion_controller_withPIC_B.hc_a *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__jz /
      ((motion_controller_withPIC_B.ve_a * motion_controller_withPIC_B.ve_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eh + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__kl)) + cos(atan
      (sin(motion_controller_withPIC_B.dr_i - rt_atan2d_snf
           (motion_controller_withPIC_B.rtb_Add_im_f1 -
            motion_controller_withPIC_B.b_value_tmp,
            ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
              motion_controller_withPIC_B.rtb_Add_re_lg) +
             motion_controller_withPIC_B.b_value_a) -
            motion_controller_withPIC_B.b_value_as)) *
       motion_controller_withPIC_B.b_value_ip) *
      motion_controller_withPIC_B.b_value_f) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_im_g4 -
        motion_controller_withPIC_B.b_value_tmp,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_dx) +
         motion_controller_withPIC_B.b_value_a) -
        motion_controller_withPIC_B.b_value_as)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a) *
      motion_controller_withPIC_B.ec_a * motion_controller_withPIC_B.b_value_i *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_g *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__fn /
      ((motion_controller_withPIC_B.df_a * motion_controller_withPIC_B.df_a *
        motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d + 1.0) *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_h)) /
      motion_controller_withPIC_P.Izz;
    motion_controller_withPIC_B.B0[1] = ((cos(atan(sin
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_i3,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_jr) -
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.b_value_l) *
      motion_controller_withPIC_B.b_value_o) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_db,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_tmp_h) -
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j /
      (motion_controller_withPIC_B.ef_a * motion_controller_withPIC_B.ef_a *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eh + 1.0) + cos
      (atan(sin(motion_controller_withPIC_B.df_j - rt_atan2d_snf
                (motion_controller_withPIC_B.n_a_tmp +
                 motion_controller_withPIC_B.rtb_Add_im_ch,
                 ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                   motion_controller_withPIC_B.rtb_Add_re_o3) +
                  motion_controller_withPIC_B.b_value_a) +
                 motion_controller_withPIC_B.n_a_tmp_a)) *
            motion_controller_withPIC_B.b_value_l) *
       motion_controller_withPIC_B.b_value_o) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_nm,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_h2) +
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__oy /
      (motion_controller_withPIC_B.ff_a * motion_controller_withPIC_B.ff_a *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eh + 1.0)) *
      motion_controller_withPIC_B.A0_tmp - (sin(atan(sin
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_er,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_b) -
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.b_value_l) *
      motion_controller_withPIC_B.b_value_o) *
      motion_controller_withPIC_B.b_value_o2 *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j + sin(atan(sin
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_ik,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_dd) +
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.b_value_l) *
      motion_controller_withPIC_B.b_value_o) *
      motion_controller_withPIC_B.b_value_o2 *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__oy) *
      motion_controller_withPIC_B.A0_tmp_c) / motion_controller_withPIC_P.m;
    motion_controller_withPIC_B.B0[5] = ((sin(atan(sin
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_im_gs -
        motion_controller_withPIC_B.b_value_tmp,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_tmp_c) -
         motion_controller_withPIC_B.b_value_a) -
        motion_controller_withPIC_B.b_value_as)) *
      motion_controller_withPIC_B.b_value_ip) *
      motion_controller_withPIC_B.b_value_f) *
      motion_controller_withPIC_B.b_value_iz *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_f + sin(atan(sin
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_im_l0 -
        motion_controller_withPIC_B.b_value_tmp,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_nn) +
         motion_controller_withPIC_B.b_value_a) -
        motion_controller_withPIC_B.b_value_as)) *
      motion_controller_withPIC_B.b_value_ip) *
      motion_controller_withPIC_B.b_value_f) *
      motion_controller_withPIC_B.b_value_iz *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_g) *
      motion_controller_withPIC_B.A0_tmp_o - (cos(atan(sin
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_im_dk -
        motion_controller_withPIC_B.b_value_tmp,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_ph) -
         motion_controller_withPIC_B.b_value_a) -
        motion_controller_withPIC_B.b_value_as)) *
      motion_controller_withPIC_B.b_value_ip) *
      motion_controller_withPIC_B.b_value_f) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_im_nc -
        motion_controller_withPIC_B.b_value_tmp,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_ce) -
         motion_controller_withPIC_B.b_value_a) -
        motion_controller_withPIC_B.b_value_as)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_f /
      (motion_controller_withPIC_B.gf_a * motion_controller_withPIC_B.gf_a *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d + 1.0) + cos
      (atan(sin(motion_controller_withPIC_B.dr_i - rt_atan2d_snf
                (motion_controller_withPIC_B.rtb_Add_im_hp -
                 motion_controller_withPIC_B.b_value_tmp,
                 ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                   motion_controller_withPIC_B.rtb_Add_re_c2) +
                  motion_controller_withPIC_B.b_value_a) -
                 motion_controller_withPIC_B.b_value_as)) *
            motion_controller_withPIC_B.b_value_ip) *
       motion_controller_withPIC_B.b_value_f) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_im_jr -
        motion_controller_withPIC_B.b_value_tmp,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_oi) +
         motion_controller_withPIC_B.b_value_a) -
        motion_controller_withPIC_B.b_value_as)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_g /
      (motion_controller_withPIC_B.hf_a * motion_controller_withPIC_B.hf_a *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d + 1.0)) *
      motion_controller_withPIC_B.Fy1_tmp_tmp_i) / motion_controller_withPIC_P.m;
    motion_controller_withPIC_B.B0[0] = 0.0;
    motion_controller_withPIC_B.B0[2] = 0.0;
    motion_controller_withPIC_B.B0[4] = 0.0;
    motion_controller_withPIC_B.B0[6] = 0.0;
    motion_controller_withPIC_B.b_value_e = motion_controller_withPIC_P.B *
      motion_controller_withPIC_B.Fy1_tmp_tmp / 2.0;
    motion_controller_withPIC_B.rtb_Add_im_m4 = motion_controller_withPIC_P.a *
      motion_controller_withPIC_B.Fy1_tmp;
    motion_controller_withPIC_B.B0[3] = (((sin(atan(sin
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_da,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_tmp_n) -
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.b_value_l) *
      motion_controller_withPIC_B.b_value_o) *
      motion_controller_withPIC_B.b_value_o2 *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j *
      (motion_controller_withPIC_B.b_value_e -
       motion_controller_withPIC_B.rtb_Add_im_m4) - sin(atan(sin
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_pw,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_c5) +
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.b_value_l) *
      motion_controller_withPIC_B.b_value_o) *
      motion_controller_withPIC_B.b_value_o2 *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__oy *
      (motion_controller_withPIC_B.b_value_e +
       motion_controller_withPIC_B.rtb_Add_im_m4)) + cos(atan(sin
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_jw,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_ow) -
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.b_value_l) *
      motion_controller_withPIC_B.b_value_o) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_a4,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_pi) -
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_j *
      motion_controller_withPIC_B.rtb_Add_im_o /
      (motion_controller_withPIC_B.if_a * motion_controller_withPIC_B.if_a *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eh + 1.0)) - cos
      (atan(sin(motion_controller_withPIC_B.df_j - rt_atan2d_snf
                (motion_controller_withPIC_B.n_a_tmp +
                 motion_controller_withPIC_B.rtb_Add_im_kv,
                 ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                   motion_controller_withPIC_B.rtb_Add_re_lm) +
                  motion_controller_withPIC_B.b_value_a) +
                 motion_controller_withPIC_B.n_a_tmp_a)) *
            motion_controller_withPIC_B.b_value_l) *
       motion_controller_withPIC_B.b_value_o) * (cos
      (motion_controller_withPIC_B.df_j - rt_atan2d_snf
       (motion_controller_withPIC_B.n_a_tmp +
        motion_controller_withPIC_B.rtb_Add_im_ob,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_pie) +
         motion_controller_withPIC_B.b_value_a) +
        motion_controller_withPIC_B.n_a_tmp_a)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_e) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__oy *
      motion_controller_withPIC_B.hc_a / (motion_controller_withPIC_B.jf_a *
      motion_controller_withPIC_B.jf_a *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1__eh + 1.0)) /
      motion_controller_withPIC_P.Izz;
    motion_controller_withPIC_B.b_value_e = motion_controller_withPIC_P.B *
      motion_controller_withPIC_B.A0_tmp_tmp_b / 2.0;
    motion_controller_withPIC_B.rtb_Add_im_m4 = motion_controller_withPIC_P.b *
      motion_controller_withPIC_B.A0_tmp_tmp;
    motion_controller_withPIC_B.B0[7] = -(((sin(atan(sin
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_im_jk -
        motion_controller_withPIC_B.b_value_tmp,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_tmp_k) -
         motion_controller_withPIC_B.b_value_a) -
        motion_controller_withPIC_B.b_value_as)) *
      motion_controller_withPIC_B.b_value_ip) *
      motion_controller_withPIC_B.b_value_f) *
      motion_controller_withPIC_B.b_value_iz *
      (motion_controller_withPIC_B.b_value_e +
       motion_controller_withPIC_B.rtb_Add_im_m4) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_f - sin(atan(sin
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_im_cm -
        motion_controller_withPIC_B.b_value_tmp,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_fz) +
         motion_controller_withPIC_B.b_value_a) -
        motion_controller_withPIC_B.b_value_as)) *
      motion_controller_withPIC_B.b_value_ip) *
      motion_controller_withPIC_B.b_value_f) *
      motion_controller_withPIC_B.b_value_iz *
      (motion_controller_withPIC_B.b_value_e -
       motion_controller_withPIC_B.rtb_Add_im_m4) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_g) + cos(atan
      (sin(motion_controller_withPIC_B.dr_i - rt_atan2d_snf
           (motion_controller_withPIC_B.rtb_Add_im_l4 -
            motion_controller_withPIC_B.b_value_tmp,
            ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
              motion_controller_withPIC_B.rtb_Add_re_iu) -
             motion_controller_withPIC_B.b_value_a) -
            motion_controller_withPIC_B.b_value_as)) *
       motion_controller_withPIC_B.b_value_ip) *
      motion_controller_withPIC_B.b_value_f) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_im_nl -
        motion_controller_withPIC_B.b_value_tmp,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_fq) -
         motion_controller_withPIC_B.b_value_a) -
        motion_controller_withPIC_B.b_value_as)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a) *
      motion_controller_withPIC_B.yb_a *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_f /
      (motion_controller_withPIC_B.kf_a * motion_controller_withPIC_B.kf_a *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d + 1.0)) - cos
      (atan(sin(motion_controller_withPIC_B.dr_i - rt_atan2d_snf
                (motion_controller_withPIC_B.e_a_tmp_d -
                 motion_controller_withPIC_B.b_value_tmp,
                 ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
                   motion_controller_withPIC_B.rtb_Add_re_fc) +
                  motion_controller_withPIC_B.b_value_a) -
                 motion_controller_withPIC_B.b_value_as)) *
            motion_controller_withPIC_B.b_value_ip) *
       motion_controller_withPIC_B.b_value_f) * (cos
      (motion_controller_withPIC_B.dr_i - rt_atan2d_snf
       (motion_controller_withPIC_B.rtb_Add_im_k1 -
        motion_controller_withPIC_B.b_value_tmp,
        ((motion_controller_withPIC_B.In1_je.twist.twist.linear.x +
          motion_controller_withPIC_B.rtb_Add_re_i3) +
         motion_controller_withPIC_B.b_value_a) -
        motion_controller_withPIC_B.b_value_as)) *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_a) *
      motion_controller_withPIC_B.ec_a *
      motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_g /
      (motion_controller_withPIC_B.lf_a * motion_controller_withPIC_B.lf_a *
       motion_controller_withPIC_B.rtb_ImpAsg_InsertedFor_Out1_a_d + 1.0)) /
      motion_controller_withPIC_P.Izz;
    motion_controller_withPIC_B.rtb_Add_c[0] =
      motion_controller_withPIC_B.b_value_p;
    motion_controller_withPIC_B.i_a_tmp = motion_controller_withPIC_B.b_value_p5
      + motion_controller_withPIC_B.Fy2;
    motion_controller_withPIC_B.b_value_l = motion_controller_withPIC_B.Fy3 +
      motion_controller_withPIC_B.Fy4;
    motion_controller_withPIC_B.rtb_Add_c[1] =
      (motion_controller_withPIC_B.i_a_tmp * motion_controller_withPIC_B.A0_tmp
       + motion_controller_withPIC_B.b_value_l *
       motion_controller_withPIC_B.Fy1_tmp_tmp_i) * (1.0 /
      motion_controller_withPIC_P.m);
    motion_controller_withPIC_B.rtb_Add_c[2] =
      motion_controller_withPIC_B.b_value_ct;
    motion_controller_withPIC_B.b_value_a = motion_controller_withPIC_P.B / 2.0 *
      motion_controller_withPIC_B.Fy1_tmp;
    motion_controller_withPIC_B.b_value_o = -motion_controller_withPIC_P.b *
      motion_controller_withPIC_B.A0_tmp_tmp_b;
    motion_controller_withPIC_B.b_value_o2 = motion_controller_withPIC_P.B / 2.0
      * motion_controller_withPIC_B.A0_tmp_tmp;
    motion_controller_withPIC_B.rtb_Add_c[3] =
      ((((motion_controller_withPIC_B.b_value_a +
          motion_controller_withPIC_B.b_value_ax) *
         motion_controller_withPIC_B.b_value_p5 +
         (motion_controller_withPIC_B.b_value_ax -
          motion_controller_withPIC_B.b_value_a) *
         motion_controller_withPIC_B.Fy2) +
        (motion_controller_withPIC_B.b_value_o2 +
         motion_controller_withPIC_B.b_value_o) *
        motion_controller_withPIC_B.Fy3) +
       (motion_controller_withPIC_B.b_value_o -
        motion_controller_withPIC_B.b_value_o2) *
       motion_controller_withPIC_B.Fy4) * (1.0 / motion_controller_withPIC_P.Izz);
    for (motion_controller_withPIC_B.kidx = 0; motion_controller_withPIC_B.kidx <=
         2; motion_controller_withPIC_B.kidx += 2) {
      // MATLAB Function: '<S10>/update'
      tmp = _mm_loadu_pd
        (&motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[motion_controller_withPIC_B.kidx
         + 4]);
      tmp_0 = _mm_loadu_pd
        (&motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[motion_controller_withPIC_B.kidx]);
      tmp_1 = _mm_loadu_pd
        (&motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[motion_controller_withPIC_B.kidx
         + 8]);
      tmp_2 = _mm_loadu_pd
        (&motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[motion_controller_withPIC_B.kidx
         + 12]);
      tmp_3 = _mm_loadu_pd
        (&motion_controller_withPIC_B.rtb_Add_c[motion_controller_withPIC_B.kidx]);
      tmp_4 = _mm_loadu_pd
        (&motion_controller_withPIC_B.B0[motion_controller_withPIC_B.kidx + 4]);
      tmp_5 = _mm_loadu_pd
        (&motion_controller_withPIC_B.B0[motion_controller_withPIC_B.kidx]);
      _mm_storeu_pd
        (&motion_controller_withPIC_B.gama[motion_controller_withPIC_B.kidx],
         _mm_sub_pd(_mm_sub_pd(tmp_3, _mm_add_pd(_mm_add_pd(_mm_add_pd
             (_mm_mul_pd(tmp, _mm_set1_pd(motion_controller_withPIC_B.b_value_p)),
              _mm_mul_pd(tmp_0, _mm_set1_pd(motion_controller_withPIC_B.yp))),
             _mm_mul_pd(tmp_1, _mm_set1_pd(motion_controller_withPIC_B.yaw))),
            _mm_mul_pd(tmp_2, _mm_set1_pd(motion_controller_withPIC_B.b_value_ct)))),
                    _mm_add_pd(_mm_mul_pd(tmp_4, _mm_set1_pd
            (motion_controller_withPIC_B.dr_i)), _mm_mul_pd(tmp_5, _mm_set1_pd
            (motion_controller_withPIC_B.df_j)))));
    }

    // MATLAB Function: '<S10>/update'
    for (motion_controller_withPIC_B.kidx = 0; motion_controller_withPIC_B.kidx <
         16; motion_controller_withPIC_B.kidx++) {
      motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.kidx] = 0;
    }

    motion_controller_withPIC_B.b_I[0] = 1;
    motion_controller_withPIC_B.b_I[5] = 1;
    motion_controller_withPIC_B.b_I[10] = 1;
    motion_controller_withPIC_B.b_I[15] = 1;
    for (motion_controller_withPIC_B.kidx = 0; motion_controller_withPIC_B.kidx <=
         6; motion_controller_withPIC_B.kidx += 2) {
      // MATLAB Function: '<S10>/update' incorporates:
      //   Constant: '<Root>/Constant2'

      tmp = _mm_loadu_pd
        (&motion_controller_withPIC_B.B0[motion_controller_withPIC_B.kidx]);
      _mm_storeu_pd
        (&motion_controller_withPIC_B.B0[motion_controller_withPIC_B.kidx],
         _mm_mul_pd(_mm_set1_pd(motion_controller_withPIC_P.Constant2_Value_e),
                    tmp));
    }

    // MATLAB Function: '<S10>/update' incorporates:
    //   Constant: '<Root>/Constant2'

    motion_controller_withPIC_B.gama[0] *=
      motion_controller_withPIC_P.Constant2_Value_e;
    motion_controller_withPIC_B.gama[1] *=
      motion_controller_withPIC_P.Constant2_Value_e;
    motion_controller_withPIC_B.gama[2] *=
      motion_controller_withPIC_P.Constant2_Value_e;
    motion_controller_withPIC_B.gama[3] *=
      motion_controller_withPIC_P.Constant2_Value_e;
    for (motion_controller_withPIC_B.kidx = 0; motion_controller_withPIC_B.kidx <
         4; motion_controller_withPIC_B.kidx++) {
      motion_controller_withPIC_B.b_kidx = motion_controller_withPIC_B.kidx << 2;
      motion_controller_withPIC_B.A1[6 * motion_controller_withPIC_B.kidx] =
        motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[motion_controller_withPIC_B.b_kidx]
        * motion_controller_withPIC_P.Constant2_Value_e + static_cast<real_T>
        (motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.b_kidx]);
      motion_controller_withPIC_B.A1[6 * motion_controller_withPIC_B.kidx + 1] =
        motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[motion_controller_withPIC_B.b_kidx
        + 1] * motion_controller_withPIC_P.Constant2_Value_e +
        static_cast<real_T>
        (motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.b_kidx + 1]);
      motion_controller_withPIC_B.A1[6 * motion_controller_withPIC_B.kidx + 2] =
        motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[motion_controller_withPIC_B.b_kidx
        + 2] * motion_controller_withPIC_P.Constant2_Value_e +
        static_cast<real_T>
        (motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.b_kidx + 2]);
      motion_controller_withPIC_B.A1[6 * motion_controller_withPIC_B.kidx + 3] =
        motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[motion_controller_withPIC_B.b_kidx
        + 3] * motion_controller_withPIC_P.Constant2_Value_e +
        static_cast<real_T>
        (motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.b_kidx + 3]);
    }

    for (motion_controller_withPIC_B.kidx = 0; motion_controller_withPIC_B.kidx <
         2; motion_controller_withPIC_B.kidx++) {
      motion_controller_withPIC_B.b_kidx = motion_controller_withPIC_B.kidx << 2;
      motion_controller_withPIC_B.i = (motion_controller_withPIC_B.kidx + 4) * 6;
      motion_controller_withPIC_B.A1[motion_controller_withPIC_B.i] =
        motion_controller_withPIC_B.B0[motion_controller_withPIC_B.b_kidx];
      motion_controller_withPIC_B.A1[motion_controller_withPIC_B.i + 1] =
        motion_controller_withPIC_B.B0[motion_controller_withPIC_B.b_kidx + 1];
      motion_controller_withPIC_B.A1[motion_controller_withPIC_B.i + 2] =
        motion_controller_withPIC_B.B0[motion_controller_withPIC_B.b_kidx + 2];
      motion_controller_withPIC_B.A1[motion_controller_withPIC_B.i + 3] =
        motion_controller_withPIC_B.B0[motion_controller_withPIC_B.b_kidx + 3];
    }

    for (motion_controller_withPIC_B.kidx = 0; motion_controller_withPIC_B.kidx <
         4; motion_controller_withPIC_B.kidx++) {
      motion_controller_withPIC_B.A1[6 * motion_controller_withPIC_B.kidx + 4] =
        0.0;
      motion_controller_withPIC_B.A1[6 * motion_controller_withPIC_B.kidx + 5] =
        0.0;
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
      motion_controller_withPIC_B.kidx = motion_controller_withPIC_B.i << 2;
      motion_controller_withPIC_B.B1[6 * motion_controller_withPIC_B.i] =
        motion_controller_withPIC_B.B0[motion_controller_withPIC_B.kidx];
      motion_controller_withPIC_B.B1[6 * motion_controller_withPIC_B.i + 1] =
        motion_controller_withPIC_B.B0[motion_controller_withPIC_B.kidx + 1];
      motion_controller_withPIC_B.B1[6 * motion_controller_withPIC_B.i + 2] =
        motion_controller_withPIC_B.B0[motion_controller_withPIC_B.kidx + 2];
      motion_controller_withPIC_B.B1[6 * motion_controller_withPIC_B.i + 3] =
        motion_controller_withPIC_B.B0[motion_controller_withPIC_B.kidx + 3];
    }

    motion_controller_withPIC_B.B1[4] = motion_controller_withPIC_B.c_I[0];
    motion_controller_withPIC_B.B1[5] = motion_controller_withPIC_B.c_I[1];
    motion_controller_withPIC_B.B1[10] = motion_controller_withPIC_B.c_I[2];
    motion_controller_withPIC_B.B1[11] = motion_controller_withPIC_B.c_I[3];
    motion_controller_withPIC_B.Ay = (motion_controller_withPIC_B.i_a_tmp *
      motion_controller_withPIC_B.Fy1_tmp_tmp +
      motion_controller_withPIC_B.b_value_l *
      motion_controller_withPIC_B.A0_tmp_tmp_b) * (1.0 /
      motion_controller_withPIC_P.m);

    // If: '<S46>/If' incorporates:
    //   MATLABSystem: '<S10>/Get Parameter1'

    if (motion_controller_withPIC_B.b_value_ix) {
      // Outputs for IfAction SubSystem: '<S46>/If Action Subsystem' incorporates:
      //   ActionPort: '<S48>/Action Port'

      // Gain: '<S48>/Gain1' incorporates:
      //   MATLABSystem: '<S10>/Get Parameter6'

      motion_controller_withPIC_B.df_j =
        motion_controller_withPIC_P.Gain1_Gain_o *
        motion_controller_withPIC_B.b_value_g;

      // MATLAB Function: '<S48>/predict'
      memset(&motion_controller_withPIC_B.G_e[0], 0, 720U * sizeof(real_T));
      memcpy(&motion_controller_withPIC_B.t[0], &motion_controller_withPIC_B.A1
             [0], 36U * sizeof(real_T));
      for (motion_controller_withPIC_B.j = 0; motion_controller_withPIC_B.j < 20;
           motion_controller_withPIC_B.j++) {
        motion_controller_withPIC_B.i = motion_controller_withPIC_B.j * 6;
        motion_controller_withPIC_B.d_b[0] = 6;
        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx < 6;
             motion_controller_withPIC_B.kidx++) {
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 6;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.G_e[(motion_controller_withPIC_B.i +
              motion_controller_withPIC_B.b_kidx) + 120 *
              motion_controller_withPIC_B.kidx] =
              motion_controller_withPIC_B.t[motion_controller_withPIC_B.d_b[0] *
              motion_controller_withPIC_B.kidx +
              motion_controller_withPIC_B.b_kidx];
            motion_controller_withPIC_B.dr_i = 0.0;
            for (motion_controller_withPIC_B.loop_ub = 0;
                 motion_controller_withPIC_B.loop_ub < 6;
                 motion_controller_withPIC_B.loop_ub++) {
              motion_controller_withPIC_B.dr_i += motion_controller_withPIC_B.t
                [6 * motion_controller_withPIC_B.loop_ub +
                motion_controller_withPIC_B.kidx] *
                motion_controller_withPIC_B.A1[6 *
                motion_controller_withPIC_B.b_kidx +
                motion_controller_withPIC_B.loop_ub];
            }

            motion_controller_withPIC_B.t_j[motion_controller_withPIC_B.kidx + 6
              * motion_controller_withPIC_B.b_kidx] =
              motion_controller_withPIC_B.dr_i;
          }
        }

        memcpy(&motion_controller_withPIC_B.t[0],
               &motion_controller_withPIC_B.t_j[0], 36U * sizeof(real_T));
        motion_controller_withPIC_B.i = motion_controller_withPIC_B.j << 2;
        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx < 4;
             motion_controller_withPIC_B.kidx++) {
          motion_controller_withPIC_B.T_c[motion_controller_withPIC_B.i +
            motion_controller_withPIC_B.kidx] =
            motion_controller_withPIC_B.gama[motion_controller_withPIC_B.kidx];
        }
      }

      memset(&motion_controller_withPIC_B.H_e[0], 0, 4800U * sizeof(real_T));
      for (motion_controller_withPIC_B.d_i = 0; motion_controller_withPIC_B.d_i <
           20; motion_controller_withPIC_B.d_i++) {
        motion_controller_withPIC_B.i = motion_controller_withPIC_B.d_i * 6 + 1;
        motion_controller_withPIC_B.dr_i = 1.0;
        motion_controller_withPIC_B.loop_ub = static_cast<int32_T>(((6.0 -
          static_cast<real_T>(motion_controller_withPIC_B.i)) + 60.0) / 6.0);
        for (motion_controller_withPIC_B.b_j = 0;
             motion_controller_withPIC_B.b_j <
             motion_controller_withPIC_B.loop_ub;
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

          if (motion_controller_withPIC_B.dr_i >
              (motion_controller_withPIC_B.dr_i + 2.0) - 1.0) {
            motion_controller_withPIC_B.l = 0;
            motion_controller_withPIC_B.kidx = 0;
          } else {
            motion_controller_withPIC_B.l = static_cast<int32_T>
              (motion_controller_withPIC_B.dr_i) - 1;
            motion_controller_withPIC_B.kidx = static_cast<int32_T>
              ((motion_controller_withPIC_B.dr_i + 2.0) - 1.0);
          }

          motion_controller_withPIC_B.f_idx_0 = motion_controller_withPIC_B.j -
            motion_controller_withPIC_B.k;
          motion_controller_withPIC_B.f_idx_1 = motion_controller_withPIC_B.kidx
            - motion_controller_withPIC_B.l;
          for (motion_controller_withPIC_B.kidx = 0;
               motion_controller_withPIC_B.kidx <
               motion_controller_withPIC_B.f_idx_1;
               motion_controller_withPIC_B.kidx++) {
            for (motion_controller_withPIC_B.b_kidx = 0;
                 motion_controller_withPIC_B.b_kidx <
                 motion_controller_withPIC_B.f_idx_0;
                 motion_controller_withPIC_B.b_kidx++) {
              motion_controller_withPIC_B.H_e[((motion_controller_withPIC_B.k +
                motion_controller_withPIC_B.b_kidx) + 120 *
                (motion_controller_withPIC_B.l +
                 motion_controller_withPIC_B.kidx)) + 5] =
                motion_controller_withPIC_B.B1[motion_controller_withPIC_B.f_idx_0
                * motion_controller_withPIC_B.kidx +
                motion_controller_withPIC_B.b_kidx];
            }
          }

          motion_controller_withPIC_B.dr_i += 2.0;
        }

        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx < 6;
             motion_controller_withPIC_B.kidx++) {
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 2;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.dr_i = 0.0;
            for (motion_controller_withPIC_B.loop_ub = 0;
                 motion_controller_withPIC_B.loop_ub < 6;
                 motion_controller_withPIC_B.loop_ub++) {
              motion_controller_withPIC_B.dr_i +=
                motion_controller_withPIC_B.A1[6 *
                motion_controller_withPIC_B.loop_ub +
                motion_controller_withPIC_B.kidx] *
                motion_controller_withPIC_B.B1[6 *
                motion_controller_withPIC_B.b_kidx +
                motion_controller_withPIC_B.loop_ub];
            }

            motion_controller_withPIC_B.rtb_A1_j[motion_controller_withPIC_B.kidx
              + 6 * motion_controller_withPIC_B.b_kidx] =
              motion_controller_withPIC_B.dr_i;
          }
        }

        memcpy(&motion_controller_withPIC_B.B1[0],
               &motion_controller_withPIC_B.rtb_A1_j[0], 12U * sizeof(real_T));
      }

      memset(&motion_controller_withPIC_B.W_m[0], 0, 9600U * sizeof(real_T));
      for (motion_controller_withPIC_B.kidx = 0;
           motion_controller_withPIC_B.kidx < 16;
           motion_controller_withPIC_B.kidx++) {
        motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.kidx] = 0;
      }

      motion_controller_withPIC_B.b_I[0] = 1;
      motion_controller_withPIC_B.b_I[5] = 1;
      motion_controller_withPIC_B.b_I[10] = 1;
      motion_controller_withPIC_B.b_I[15] = 1;
      for (motion_controller_withPIC_B.kidx = 0;
           motion_controller_withPIC_B.kidx < 4;
           motion_controller_withPIC_B.kidx++) {
        motion_controller_withPIC_B.b_kidx = motion_controller_withPIC_B.kidx <<
          2;
        motion_controller_withPIC_B.c_t[6 * motion_controller_withPIC_B.kidx] =
          motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.b_kidx];
        motion_controller_withPIC_B.c_t[6 * motion_controller_withPIC_B.kidx + 1]
          = motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.b_kidx +
          1];
        motion_controller_withPIC_B.c_t[6 * motion_controller_withPIC_B.kidx + 2]
          = motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.b_kidx +
          2];
        motion_controller_withPIC_B.c_t[6 * motion_controller_withPIC_B.kidx + 3]
          = motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.b_kidx +
          3];
        motion_controller_withPIC_B.c_t[6 * motion_controller_withPIC_B.kidx + 4]
          = 0.0;
        motion_controller_withPIC_B.c_t[6 * motion_controller_withPIC_B.kidx + 5]
          = 0.0;
      }

      for (motion_controller_withPIC_B.b_j = 0; motion_controller_withPIC_B.b_j <
           20; motion_controller_withPIC_B.b_j++) {
        motion_controller_withPIC_B.i = motion_controller_withPIC_B.b_j * 6 + 1;
        motion_controller_withPIC_B.dr_i = 1.0;
        motion_controller_withPIC_B.d_i = static_cast<int32_T>(((6.0 -
          static_cast<real_T>(motion_controller_withPIC_B.i)) + 120.0) / 6.0);
        for (motion_controller_withPIC_B.loop_ub = 0;
             motion_controller_withPIC_B.loop_ub <
             motion_controller_withPIC_B.d_i;
             motion_controller_withPIC_B.loop_ub++) {
          motion_controller_withPIC_B.j = motion_controller_withPIC_B.loop_ub *
            6 + motion_controller_withPIC_B.i;
          if (motion_controller_withPIC_B.j > motion_controller_withPIC_B.j + 5)
          {
            motion_controller_withPIC_B.k = -5;
            motion_controller_withPIC_B.j = -5;
          } else {
            motion_controller_withPIC_B.k = motion_controller_withPIC_B.j - 6;
          }

          if (motion_controller_withPIC_B.dr_i >
              (motion_controller_withPIC_B.dr_i + 4.0) - 1.0) {
            motion_controller_withPIC_B.l = 0;
            motion_controller_withPIC_B.kidx = 0;
          } else {
            motion_controller_withPIC_B.l = static_cast<int32_T>
              (motion_controller_withPIC_B.dr_i) - 1;
            motion_controller_withPIC_B.kidx = static_cast<int32_T>
              ((motion_controller_withPIC_B.dr_i + 4.0) - 1.0);
          }

          motion_controller_withPIC_B.f_idx_0 = motion_controller_withPIC_B.j -
            motion_controller_withPIC_B.k;
          motion_controller_withPIC_B.f_idx_1 = motion_controller_withPIC_B.kidx
            - motion_controller_withPIC_B.l;
          for (motion_controller_withPIC_B.kidx = 0;
               motion_controller_withPIC_B.kidx <
               motion_controller_withPIC_B.f_idx_1;
               motion_controller_withPIC_B.kidx++) {
            for (motion_controller_withPIC_B.b_kidx = 0;
                 motion_controller_withPIC_B.b_kidx <
                 motion_controller_withPIC_B.f_idx_0;
                 motion_controller_withPIC_B.b_kidx++) {
              motion_controller_withPIC_B.W_m[((motion_controller_withPIC_B.k +
                motion_controller_withPIC_B.b_kidx) + 120 *
                (motion_controller_withPIC_B.l +
                 motion_controller_withPIC_B.kidx)) + 5] =
                motion_controller_withPIC_B.c_t[motion_controller_withPIC_B.f_idx_0
                * motion_controller_withPIC_B.kidx +
                motion_controller_withPIC_B.b_kidx];
            }
          }

          motion_controller_withPIC_B.dr_i += 4.0;
        }

        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx < 6;
             motion_controller_withPIC_B.kidx++) {
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 4;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.dr_i = 0.0;
            for (motion_controller_withPIC_B.loop_ub = 0;
                 motion_controller_withPIC_B.loop_ub < 6;
                 motion_controller_withPIC_B.loop_ub++) {
              motion_controller_withPIC_B.dr_i +=
                motion_controller_withPIC_B.A1[6 *
                motion_controller_withPIC_B.loop_ub +
                motion_controller_withPIC_B.kidx] *
                motion_controller_withPIC_B.c_t[6 *
                motion_controller_withPIC_B.b_kidx +
                motion_controller_withPIC_B.loop_ub];
            }

            motion_controller_withPIC_B.rtb_A1_n[motion_controller_withPIC_B.kidx
              + 6 * motion_controller_withPIC_B.b_kidx] =
              motion_controller_withPIC_B.dr_i;
          }
        }

        memcpy(&motion_controller_withPIC_B.c_t[0],
               &motion_controller_withPIC_B.rtb_A1_n[0], 24U * sizeof(real_T));
      }

      // End of MATLAB Function: '<S48>/predict'

      // MATLAB Function: '<S48>/solvex' incorporates:
      //   MATLABSystem: '<S10>/Get Parameter'
      //   MATLABSystem: '<S10>/Get Parameter6'
      //   Reshape: '<S10>/Reshape'
      //   UnitDelay: '<S10>/Unit Delay'
      //   UnitDelay: '<S10>/Unit Delay1'

      if (!motion_controller_withPIC_DW.x0_not_empty_k) {
        motion_controller_withPIC_DW.x0_not_empty_k = true;
        motion_controller_withPIC_DW.Umin_c =
          -motion_controller_withPIC_B.b_value_ff;
        motion_controller_withPIC_DW.Umax_n =
          motion_controller_withPIC_B.b_value_ff;
        motion_controller_withPIC_B.kidx = -1;
        motion_controller_withPIC_B.b_kidx = -1;
        for (motion_controller_withPIC_B.i = 0; motion_controller_withPIC_B.i <
             20; motion_controller_withPIC_B.i++) {
          for (motion_controller_withPIC_B.j = 0; motion_controller_withPIC_B.j <
               2; motion_controller_withPIC_B.j++) {
            motion_controller_withPIC_B.b_j = motion_controller_withPIC_B.j << 1;
            motion_controller_withPIC_B.B_k = B[motion_controller_withPIC_B.b_j];
            motion_controller_withPIC_B.B_b = B[motion_controller_withPIC_B.b_j
              + 1];
            for (motion_controller_withPIC_B.b_j = 0;
                 motion_controller_withPIC_B.b_j < 20;
                 motion_controller_withPIC_B.b_j++) {
              motion_controller_withPIC_B.A = A_0[20 *
                motion_controller_withPIC_B.i + motion_controller_withPIC_B.b_j];
              motion_controller_withPIC_B.Rp[motion_controller_withPIC_B.kidx +
                1] = motion_controller_withPIC_B.A *
                motion_controller_withPIC_B.B_k;
              motion_controller_withPIC_B.K[motion_controller_withPIC_B.b_kidx +
                1] = static_cast<int8_T>(motion_controller_withPIC_B.A *
                motion_controller_withPIC_B.B_k);
              motion_controller_withPIC_B.Rp[motion_controller_withPIC_B.kidx +
                2] = motion_controller_withPIC_B.A *
                motion_controller_withPIC_B.B_b;
              motion_controller_withPIC_B.K[motion_controller_withPIC_B.b_kidx +
                2] = static_cast<int8_T>(motion_controller_withPIC_B.A *
                motion_controller_withPIC_B.B_b);
              motion_controller_withPIC_B.b_kidx =
                motion_controller_withPIC_B.kidx + 2;
              motion_controller_withPIC_B.kidx += 2;
            }
          }
        }

        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx < 40;
             motion_controller_withPIC_B.kidx++) {
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 40;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.i = 40 *
              motion_controller_withPIC_B.kidx +
              motion_controller_withPIC_B.b_kidx;
            motion_controller_withPIC_B.j = 80 *
              motion_controller_withPIC_B.kidx +
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
          motion_controller_withPIC_B.d_i = 0;
          motion_controller_withPIC_B.loop_ub = 0;
        } else {
          motion_controller_withPIC_B.d_i = motion_controller_withPIC_B.j - 6;
          motion_controller_withPIC_B.loop_ub = motion_controller_withPIC_B.j;
        }

        if (motion_controller_withPIC_B.k - 5 > motion_controller_withPIC_B.k) {
          motion_controller_withPIC_B.i = 0;
          motion_controller_withPIC_B.kidx = 0;
        } else {
          motion_controller_withPIC_B.i = motion_controller_withPIC_B.k - 6;
          motion_controller_withPIC_B.kidx = motion_controller_withPIC_B.k;
        }

        motion_controller_withPIC_B.f_idx_0 =
          motion_controller_withPIC_B.loop_ub - motion_controller_withPIC_B.d_i;
        motion_controller_withPIC_B.f_idx_1 = motion_controller_withPIC_B.kidx -
          motion_controller_withPIC_B.i;
        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx <
             motion_controller_withPIC_B.f_idx_1;
             motion_controller_withPIC_B.kidx++) {
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx <
               motion_controller_withPIC_B.f_idx_0;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.Qp[(motion_controller_withPIC_B.d_i +
              motion_controller_withPIC_B.b_kidx) + 120 *
              (motion_controller_withPIC_B.i + motion_controller_withPIC_B.kidx)]
              =
              motion_controller_withPIC_B.Q[motion_controller_withPIC_B.f_idx_0 *
              motion_controller_withPIC_B.kidx +
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
        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx < motion_controller_withPIC_B.i;
             motion_controller_withPIC_B.kidx++) {
          motion_controller_withPIC_B.rtb_H_o[motion_controller_withPIC_B.b_kidx
            + motion_controller_withPIC_B.kidx] =
            motion_controller_withPIC_B.y_h[motion_controller_withPIC_B.kidx];
        }
      }

      memset(&motion_controller_withPIC_B.Rp[0], 0, 1600U * sizeof(real_T));
      motion_controller_withPIC_B.k = 2;
      for (motion_controller_withPIC_B.loop_ub = 0;
           motion_controller_withPIC_B.loop_ub < 20;
           motion_controller_withPIC_B.loop_ub++) {
        motion_controller_withPIC_B.j = motion_controller_withPIC_B.loop_ub << 1;
        if (motion_controller_withPIC_B.k - 1 > motion_controller_withPIC_B.k) {
          motion_controller_withPIC_B.i = 0;
          motion_controller_withPIC_B.kidx = 0;
        } else {
          motion_controller_withPIC_B.i = motion_controller_withPIC_B.k - 2;
          motion_controller_withPIC_B.kidx = motion_controller_withPIC_B.k;
        }

        motion_controller_withPIC_B.f_idx_1 = motion_controller_withPIC_B.kidx -
          motion_controller_withPIC_B.i;
        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx <
             motion_controller_withPIC_B.f_idx_1;
             motion_controller_withPIC_B.kidx++) {
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 2;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.Rp[(motion_controller_withPIC_B.j +
              motion_controller_withPIC_B.b_kidx) + 40 *
              (motion_controller_withPIC_B.i + motion_controller_withPIC_B.kidx)]
              = motion_controller_withPIC_B.R[(motion_controller_withPIC_B.kidx <<
              1) + motion_controller_withPIC_B.b_kidx];
          }
        }

        motion_controller_withPIC_B.k += 2;
      }

      for (motion_controller_withPIC_B.kidx = 0;
           motion_controller_withPIC_B.kidx < 120;
           motion_controller_withPIC_B.kidx++) {
        motion_controller_withPIC_B.b_kidx = motion_controller_withPIC_B.kidx *
          40;
        memset
          (&motion_controller_withPIC_B.y_mb[motion_controller_withPIC_B.b_kidx],
           0, 40U * sizeof(real_T));
        for (motion_controller_withPIC_B.i = 0; motion_controller_withPIC_B.i <
             120; motion_controller_withPIC_B.i++) {
          motion_controller_withPIC_B.b_value_ff =
            motion_controller_withPIC_B.Qp[motion_controller_withPIC_B.i * 120 +
            motion_controller_withPIC_B.kidx];
          for (motion_controller_withPIC_B.j = 0; motion_controller_withPIC_B.j <
               40; motion_controller_withPIC_B.j++) {
            motion_controller_withPIC_B.b_j = motion_controller_withPIC_B.b_kidx
              + motion_controller_withPIC_B.j;
            motion_controller_withPIC_B.y_mb[motion_controller_withPIC_B.b_j] +=
              motion_controller_withPIC_B.H_e[motion_controller_withPIC_B.j *
              120 + motion_controller_withPIC_B.i] *
              motion_controller_withPIC_B.b_value_ff;
          }
        }

        memset
          (&motion_controller_withPIC_B.b_y[motion_controller_withPIC_B.b_kidx],
           0, 40U * sizeof(real_T));
        for (motion_controller_withPIC_B.i = 0; motion_controller_withPIC_B.i <
             120; motion_controller_withPIC_B.i++) {
          motion_controller_withPIC_B.b_value_ff =
            motion_controller_withPIC_B.Qp[motion_controller_withPIC_B.i * 120 +
            motion_controller_withPIC_B.kidx];
          for (motion_controller_withPIC_B.b_j = 0;
               motion_controller_withPIC_B.b_j < 40;
               motion_controller_withPIC_B.b_j++) {
            motion_controller_withPIC_B.j = motion_controller_withPIC_B.b_kidx +
              motion_controller_withPIC_B.b_j;
            motion_controller_withPIC_B.b_y[motion_controller_withPIC_B.j] +=
              motion_controller_withPIC_B.H_e[motion_controller_withPIC_B.b_j *
              120 + motion_controller_withPIC_B.i] *
              motion_controller_withPIC_B.b_value_ff;
          }
        }
      }

      motion_controller_withPIC_B.b_value_ff =
        motion_controller_withPIC_DW.Umax_n -
        motion_controller_withPIC_DW.UnitDelay_DSTATE;
      motion_controller_withPIC_B.dr_i = motion_controller_withPIC_DW.Umax_n -
        motion_controller_withPIC_DW.UnitDelay1_DSTATE;
      motion_controller_withPIC_B.kidx = -1;
      for (motion_controller_withPIC_B.b_kidx = 0;
           motion_controller_withPIC_B.b_kidx < 20;
           motion_controller_withPIC_B.b_kidx++) {
        motion_controller_withPIC_B.T[motion_controller_withPIC_B.kidx + 1] =
          motion_controller_withPIC_B.b_value_ff;
        motion_controller_withPIC_B.T[motion_controller_withPIC_B.kidx + 2] =
          motion_controller_withPIC_B.dr_i;
        motion_controller_withPIC_B.kidx += 2;
      }

      motion_controller_withPIC_B.b_value_ff =
        motion_controller_withPIC_DW.UnitDelay_DSTATE -
        motion_controller_withPIC_DW.Umin_c;
      motion_controller_withPIC_B.dr_i =
        motion_controller_withPIC_DW.UnitDelay1_DSTATE -
        motion_controller_withPIC_DW.Umin_c;
      motion_controller_withPIC_B.kidx = -1;
      for (motion_controller_withPIC_B.b_kidx = 0;
           motion_controller_withPIC_B.b_kidx < 20;
           motion_controller_withPIC_B.b_kidx++) {
        motion_controller_withPIC_B.b_K[motion_controller_withPIC_B.kidx + 1] =
          motion_controller_withPIC_B.b_value_ff;
        motion_controller_withPIC_B.b_K[motion_controller_withPIC_B.kidx + 2] =
          motion_controller_withPIC_B.dr_i;
        motion_controller_withPIC_B.kidx += 2;
      }

      for (motion_controller_withPIC_B.i = 0; motion_controller_withPIC_B.i < 40;
           motion_controller_withPIC_B.i++) {
        motion_controller_withPIC_B.V[motion_controller_withPIC_B.i] =
          motion_controller_withPIC_DW.x0_i[motion_controller_withPIC_B.i];
        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx < 120;
             motion_controller_withPIC_B.kidx++) {
          motion_controller_withPIC_B.b_value_ff = 0.0;
          motion_controller_withPIC_B.b_value_l = 0.0;
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 120;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.b_value_ff +=
              motion_controller_withPIC_B.H_e[120 *
              motion_controller_withPIC_B.i + motion_controller_withPIC_B.b_kidx]
              * motion_controller_withPIC_B.Qp[120 *
              motion_controller_withPIC_B.kidx +
              motion_controller_withPIC_B.b_kidx];
            motion_controller_withPIC_B.b_value_l =
              motion_controller_withPIC_B.b_value_ff;
          }

          motion_controller_withPIC_B.b_kidx = 40 *
            motion_controller_withPIC_B.kidx + motion_controller_withPIC_B.i;
          motion_controller_withPIC_B.rtb_H_e_k[motion_controller_withPIC_B.b_kidx]
            = motion_controller_withPIC_B.b_value_l;
          motion_controller_withPIC_B.rtb_H_e_c[motion_controller_withPIC_B.b_kidx]
            = motion_controller_withPIC_B.b_value_ff;
        }

        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx < 6;
             motion_controller_withPIC_B.kidx++) {
          motion_controller_withPIC_B.b_value_l = 0.0;
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 120;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.b_value_l +=
              motion_controller_withPIC_B.rtb_H_e_k[40 *
              motion_controller_withPIC_B.b_kidx + motion_controller_withPIC_B.i]
              * motion_controller_withPIC_B.G_e[120 *
              motion_controller_withPIC_B.kidx +
              motion_controller_withPIC_B.b_kidx];
          }

          motion_controller_withPIC_B.rtb_H_e_d[motion_controller_withPIC_B.i +
            40 * motion_controller_withPIC_B.kidx] =
            motion_controller_withPIC_B.b_value_l;
        }

        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx < 80;
             motion_controller_withPIC_B.kidx++) {
          motion_controller_withPIC_B.dr_i = 0.0;
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 120;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.dr_i +=
              motion_controller_withPIC_B.y_mb[40 *
              motion_controller_withPIC_B.b_kidx + motion_controller_withPIC_B.i]
              * motion_controller_withPIC_B.W_m[120 *
              motion_controller_withPIC_B.kidx +
              motion_controller_withPIC_B.b_kidx];
          }

          motion_controller_withPIC_B.y_b[motion_controller_withPIC_B.i + 40 *
            motion_controller_withPIC_B.kidx] = motion_controller_withPIC_B.dr_i;
        }

        motion_controller_withPIC_B.b_value_l = 0.0;
        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx < 6;
             motion_controller_withPIC_B.kidx++) {
          motion_controller_withPIC_B.b_value_l +=
            motion_controller_withPIC_B.rtb_H_e_d[40 *
            motion_controller_withPIC_B.kidx + motion_controller_withPIC_B.i] *
            motion_controller_withPIC_B.Reshape[motion_controller_withPIC_B.kidx];
        }

        motion_controller_withPIC_B.dr_i = 0.0;
        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx < 80;
             motion_controller_withPIC_B.kidx++) {
          motion_controller_withPIC_B.dr_i += motion_controller_withPIC_B.y_b[40
            * motion_controller_withPIC_B.kidx + motion_controller_withPIC_B.i] *
            motion_controller_withPIC_B.T_c[motion_controller_withPIC_B.kidx];
        }

        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx < 40;
             motion_controller_withPIC_B.kidx++) {
          motion_controller_withPIC_B.b_value_ff = 0.0;
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 120;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.b_value_ff +=
              motion_controller_withPIC_B.rtb_H_e_c[40 *
              motion_controller_withPIC_B.b_kidx + motion_controller_withPIC_B.i]
              * motion_controller_withPIC_B.H_e[120 *
              motion_controller_withPIC_B.kidx +
              motion_controller_withPIC_B.b_kidx];
          }

          motion_controller_withPIC_B.b_kidx = 40 *
            motion_controller_withPIC_B.kidx + motion_controller_withPIC_B.i;
          motion_controller_withPIC_B.rtb_H_e_m[motion_controller_withPIC_B.b_kidx]
            = motion_controller_withPIC_B.Rp[motion_controller_withPIC_B.b_kidx]
            + motion_controller_withPIC_B.b_value_ff;
        }

        motion_controller_withPIC_B.b_value_ff = 0.0;
        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx < 120;
             motion_controller_withPIC_B.kidx++) {
          motion_controller_withPIC_B.b_value_ff +=
            motion_controller_withPIC_B.b_y[40 *
            motion_controller_withPIC_B.kidx + motion_controller_withPIC_B.i] *
            motion_controller_withPIC_B.rtb_H_o[motion_controller_withPIC_B.kidx];
        }

        motion_controller_withPIC_B.rtb_H_e_f[motion_controller_withPIC_B.i] =
          (motion_controller_withPIC_B.b_value_l +
           motion_controller_withPIC_B.dr_i) -
          motion_controller_withPIC_B.b_value_ff;
        motion_controller_withPIC_B.rtb_T_b[motion_controller_withPIC_B.i] =
          motion_controller_withPIC_B.T[motion_controller_withPIC_B.i];
        motion_controller_withPIC_B.rtb_T_b[motion_controller_withPIC_B.i + 40] =
          motion_controller_withPIC_B.b_K[motion_controller_withPIC_B.i];
        motion_controller_withPIC_B.rtb_Gain1_c_a[motion_controller_withPIC_B.i]
          = motion_controller_withPIC_B.df_j;
        motion_controller_withPIC_B.b_value_j[motion_controller_withPIC_B.i] =
          motion_controller_withPIC_B.b_value_g;
      }

      motion_controller_with_quadprog(motion_controller_withPIC_B.rtb_H_e_m,
        motion_controller_withPIC_B.rtb_H_e_f, motion_controller_withPIC_DW.A_j,
        motion_controller_withPIC_B.rtb_T_b,
        motion_controller_withPIC_B.rtb_Gain1_c_a,
        motion_controller_withPIC_B.b_value_j, motion_controller_withPIC_B.V,
        &motion_controller_withPIC_DW.opts);
      motion_controller_withPIC_B.b_value_ff = motion_controller_withPIC_B.V[0]
        + motion_controller_withPIC_DW.UnitDelay_DSTATE;
      motion_controller_withPIC_B.dr_i = motion_controller_withPIC_B.V[1] +
        motion_controller_withPIC_DW.UnitDelay1_DSTATE;

      // SignalConversion generated from: '<S48>/dfl' incorporates:
      //   MATLAB Function: '<S48>/solvex'
      //   Merge: '<S46>/Merge'

      motion_controller_withPIC_B.Merge[0] =
        motion_controller_withPIC_B.b_value_ff;

      // SignalConversion generated from: '<S48>/dfr' incorporates:
      //   MATLAB Function: '<S48>/solvex'
      //   Merge: '<S46>/Merge'

      motion_controller_withPIC_B.Merge[1] =
        motion_controller_withPIC_B.b_value_ff;

      // SignalConversion generated from: '<S48>/drl' incorporates:
      //   MATLAB Function: '<S48>/solvex'
      //   Merge: '<S46>/Merge'

      motion_controller_withPIC_B.Merge[2] = motion_controller_withPIC_B.dr_i;

      // SignalConversion generated from: '<S48>/drr' incorporates:
      //   MATLAB Function: '<S48>/solvex'
      //   Merge: '<S46>/Merge'

      motion_controller_withPIC_B.Merge[3] = motion_controller_withPIC_B.dr_i;

      // End of Outputs for SubSystem: '<S46>/If Action Subsystem'
    } else {
      // Outputs for IfAction SubSystem: '<S46>/If Action Subsystem1' incorporates:
      //   ActionPort: '<S49>/Action Port'

      // Gain: '<S49>/Gain1' incorporates:
      //   MATLABSystem: '<S10>/Get Parameter6'

      motion_controller_withPIC_B.df_j =
        motion_controller_withPIC_P.Gain1_Gain_c *
        motion_controller_withPIC_B.b_value_g;

      // MATLAB Function: '<S49>/predict'
      memset(&motion_controller_withPIC_B.G[0], 0, 360U * sizeof(real_T));
      memcpy(&motion_controller_withPIC_B.t[0], &motion_controller_withPIC_B.A1
             [0], 36U * sizeof(real_T));
      for (motion_controller_withPIC_B.j = 0; motion_controller_withPIC_B.j < 10;
           motion_controller_withPIC_B.j++) {
        motion_controller_withPIC_B.i = motion_controller_withPIC_B.j * 6;
        motion_controller_withPIC_B.d_b[0] = 6;
        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx < 6;
             motion_controller_withPIC_B.kidx++) {
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 6;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.G[(motion_controller_withPIC_B.i +
              motion_controller_withPIC_B.b_kidx) + 60 *
              motion_controller_withPIC_B.kidx] =
              motion_controller_withPIC_B.t[motion_controller_withPIC_B.d_b[0] *
              motion_controller_withPIC_B.kidx +
              motion_controller_withPIC_B.b_kidx];
            motion_controller_withPIC_B.dr_i = 0.0;
            for (motion_controller_withPIC_B.loop_ub = 0;
                 motion_controller_withPIC_B.loop_ub < 6;
                 motion_controller_withPIC_B.loop_ub++) {
              motion_controller_withPIC_B.dr_i += motion_controller_withPIC_B.t
                [6 * motion_controller_withPIC_B.loop_ub +
                motion_controller_withPIC_B.kidx] *
                motion_controller_withPIC_B.A1[6 *
                motion_controller_withPIC_B.b_kidx +
                motion_controller_withPIC_B.loop_ub];
            }

            motion_controller_withPIC_B.t_j[motion_controller_withPIC_B.kidx + 6
              * motion_controller_withPIC_B.b_kidx] =
              motion_controller_withPIC_B.dr_i;
          }
        }

        memcpy(&motion_controller_withPIC_B.t[0],
               &motion_controller_withPIC_B.t_j[0], 36U * sizeof(real_T));
        motion_controller_withPIC_B.i = motion_controller_withPIC_B.j << 2;
        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx < 4;
             motion_controller_withPIC_B.kidx++) {
          motion_controller_withPIC_B.T[motion_controller_withPIC_B.i +
            motion_controller_withPIC_B.kidx] =
            motion_controller_withPIC_B.gama[motion_controller_withPIC_B.kidx];
        }
      }

      memset(&motion_controller_withPIC_B.H[0], 0, 1200U * sizeof(real_T));
      for (motion_controller_withPIC_B.d_i = 0; motion_controller_withPIC_B.d_i <
           10; motion_controller_withPIC_B.d_i++) {
        motion_controller_withPIC_B.i = motion_controller_withPIC_B.d_i * 6 + 1;
        motion_controller_withPIC_B.dr_i = 1.0;
        motion_controller_withPIC_B.loop_ub = static_cast<int32_T>(((6.0 -
          static_cast<real_T>(motion_controller_withPIC_B.i)) + 60.0) / 6.0);
        for (motion_controller_withPIC_B.b_j = 0;
             motion_controller_withPIC_B.b_j <
             motion_controller_withPIC_B.loop_ub;
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

          if (motion_controller_withPIC_B.dr_i >
              (motion_controller_withPIC_B.dr_i + 2.0) - 1.0) {
            motion_controller_withPIC_B.l = 0;
            motion_controller_withPIC_B.kidx = 0;
          } else {
            motion_controller_withPIC_B.l = static_cast<int32_T>
              (motion_controller_withPIC_B.dr_i) - 1;
            motion_controller_withPIC_B.kidx = static_cast<int32_T>
              ((motion_controller_withPIC_B.dr_i + 2.0) - 1.0);
          }

          motion_controller_withPIC_B.f_idx_0 = motion_controller_withPIC_B.j -
            motion_controller_withPIC_B.k;
          motion_controller_withPIC_B.f_idx_1 = motion_controller_withPIC_B.kidx
            - motion_controller_withPIC_B.l;
          for (motion_controller_withPIC_B.kidx = 0;
               motion_controller_withPIC_B.kidx <
               motion_controller_withPIC_B.f_idx_1;
               motion_controller_withPIC_B.kidx++) {
            for (motion_controller_withPIC_B.b_kidx = 0;
                 motion_controller_withPIC_B.b_kidx <
                 motion_controller_withPIC_B.f_idx_0;
                 motion_controller_withPIC_B.b_kidx++) {
              motion_controller_withPIC_B.H[((motion_controller_withPIC_B.k +
                motion_controller_withPIC_B.b_kidx) + 60 *
                (motion_controller_withPIC_B.l +
                 motion_controller_withPIC_B.kidx)) + 5] =
                motion_controller_withPIC_B.B1[motion_controller_withPIC_B.f_idx_0
                * motion_controller_withPIC_B.kidx +
                motion_controller_withPIC_B.b_kidx];
            }
          }

          motion_controller_withPIC_B.dr_i += 2.0;
        }

        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx < 6;
             motion_controller_withPIC_B.kidx++) {
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 2;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.dr_i = 0.0;
            for (motion_controller_withPIC_B.loop_ub = 0;
                 motion_controller_withPIC_B.loop_ub < 6;
                 motion_controller_withPIC_B.loop_ub++) {
              motion_controller_withPIC_B.dr_i +=
                motion_controller_withPIC_B.A1[6 *
                motion_controller_withPIC_B.loop_ub +
                motion_controller_withPIC_B.kidx] *
                motion_controller_withPIC_B.B1[6 *
                motion_controller_withPIC_B.b_kidx +
                motion_controller_withPIC_B.loop_ub];
            }

            motion_controller_withPIC_B.rtb_A1_j[motion_controller_withPIC_B.kidx
              + 6 * motion_controller_withPIC_B.b_kidx] =
              motion_controller_withPIC_B.dr_i;
          }
        }

        memcpy(&motion_controller_withPIC_B.B1[0],
               &motion_controller_withPIC_B.rtb_A1_j[0], 12U * sizeof(real_T));
      }

      memset(&motion_controller_withPIC_B.W[0], 0, 2400U * sizeof(real_T));
      for (motion_controller_withPIC_B.kidx = 0;
           motion_controller_withPIC_B.kidx < 16;
           motion_controller_withPIC_B.kidx++) {
        motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.kidx] = 0;
      }

      motion_controller_withPIC_B.b_I[0] = 1;
      motion_controller_withPIC_B.b_I[5] = 1;
      motion_controller_withPIC_B.b_I[10] = 1;
      motion_controller_withPIC_B.b_I[15] = 1;
      for (motion_controller_withPIC_B.kidx = 0;
           motion_controller_withPIC_B.kidx < 4;
           motion_controller_withPIC_B.kidx++) {
        motion_controller_withPIC_B.b_kidx = motion_controller_withPIC_B.kidx <<
          2;
        motion_controller_withPIC_B.c_t[6 * motion_controller_withPIC_B.kidx] =
          motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.b_kidx];
        motion_controller_withPIC_B.c_t[6 * motion_controller_withPIC_B.kidx + 1]
          = motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.b_kidx +
          1];
        motion_controller_withPIC_B.c_t[6 * motion_controller_withPIC_B.kidx + 2]
          = motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.b_kidx +
          2];
        motion_controller_withPIC_B.c_t[6 * motion_controller_withPIC_B.kidx + 3]
          = motion_controller_withPIC_B.b_I[motion_controller_withPIC_B.b_kidx +
          3];
        motion_controller_withPIC_B.c_t[6 * motion_controller_withPIC_B.kidx + 4]
          = 0.0;
        motion_controller_withPIC_B.c_t[6 * motion_controller_withPIC_B.kidx + 5]
          = 0.0;
      }

      for (motion_controller_withPIC_B.b_j = 0; motion_controller_withPIC_B.b_j <
           10; motion_controller_withPIC_B.b_j++) {
        motion_controller_withPIC_B.i = motion_controller_withPIC_B.b_j * 6 + 1;
        motion_controller_withPIC_B.dr_i = 1.0;
        motion_controller_withPIC_B.d_i = static_cast<int32_T>(((6.0 -
          static_cast<real_T>(motion_controller_withPIC_B.i)) + 60.0) / 6.0);
        for (motion_controller_withPIC_B.loop_ub = 0;
             motion_controller_withPIC_B.loop_ub <
             motion_controller_withPIC_B.d_i;
             motion_controller_withPIC_B.loop_ub++) {
          motion_controller_withPIC_B.j = motion_controller_withPIC_B.loop_ub *
            6 + motion_controller_withPIC_B.i;
          if (motion_controller_withPIC_B.j > motion_controller_withPIC_B.j + 5)
          {
            motion_controller_withPIC_B.k = -5;
            motion_controller_withPIC_B.j = -5;
          } else {
            motion_controller_withPIC_B.k = motion_controller_withPIC_B.j - 6;
          }

          if (motion_controller_withPIC_B.dr_i >
              (motion_controller_withPIC_B.dr_i + 4.0) - 1.0) {
            motion_controller_withPIC_B.l = 0;
            motion_controller_withPIC_B.kidx = 0;
          } else {
            motion_controller_withPIC_B.l = static_cast<int32_T>
              (motion_controller_withPIC_B.dr_i) - 1;
            motion_controller_withPIC_B.kidx = static_cast<int32_T>
              ((motion_controller_withPIC_B.dr_i + 4.0) - 1.0);
          }

          motion_controller_withPIC_B.f_idx_0 = motion_controller_withPIC_B.j -
            motion_controller_withPIC_B.k;
          motion_controller_withPIC_B.f_idx_1 = motion_controller_withPIC_B.kidx
            - motion_controller_withPIC_B.l;
          for (motion_controller_withPIC_B.kidx = 0;
               motion_controller_withPIC_B.kidx <
               motion_controller_withPIC_B.f_idx_1;
               motion_controller_withPIC_B.kidx++) {
            for (motion_controller_withPIC_B.b_kidx = 0;
                 motion_controller_withPIC_B.b_kidx <
                 motion_controller_withPIC_B.f_idx_0;
                 motion_controller_withPIC_B.b_kidx++) {
              motion_controller_withPIC_B.W[((motion_controller_withPIC_B.k +
                motion_controller_withPIC_B.b_kidx) + 60 *
                (motion_controller_withPIC_B.l +
                 motion_controller_withPIC_B.kidx)) + 5] =
                motion_controller_withPIC_B.c_t[motion_controller_withPIC_B.f_idx_0
                * motion_controller_withPIC_B.kidx +
                motion_controller_withPIC_B.b_kidx];
            }
          }

          motion_controller_withPIC_B.dr_i += 4.0;
        }

        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx < 6;
             motion_controller_withPIC_B.kidx++) {
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 4;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.dr_i = 0.0;
            for (motion_controller_withPIC_B.loop_ub = 0;
                 motion_controller_withPIC_B.loop_ub < 6;
                 motion_controller_withPIC_B.loop_ub++) {
              motion_controller_withPIC_B.dr_i +=
                motion_controller_withPIC_B.A1[6 *
                motion_controller_withPIC_B.loop_ub +
                motion_controller_withPIC_B.kidx] *
                motion_controller_withPIC_B.c_t[6 *
                motion_controller_withPIC_B.b_kidx +
                motion_controller_withPIC_B.loop_ub];
            }

            motion_controller_withPIC_B.rtb_A1_n[motion_controller_withPIC_B.kidx
              + 6 * motion_controller_withPIC_B.b_kidx] =
              motion_controller_withPIC_B.dr_i;
          }
        }

        memcpy(&motion_controller_withPIC_B.c_t[0],
               &motion_controller_withPIC_B.rtb_A1_n[0], 24U * sizeof(real_T));
      }

      // End of MATLAB Function: '<S49>/predict'

      // MATLAB Function: '<S49>/solvex' incorporates:
      //   MATLABSystem: '<S10>/Get Parameter'
      //   MATLABSystem: '<S10>/Get Parameter6'
      //   Reshape: '<S10>/Reshape'
      //   UnitDelay: '<S10>/Unit Delay'
      //   UnitDelay: '<S10>/Unit Delay1'

      if (!motion_controller_withPIC_DW.x0_not_empty) {
        motion_controller_withPIC_DW.x0_not_empty = true;
        motion_controller_withPIC_DW.Umin =
          -motion_controller_withPIC_B.b_value_ff;
        motion_controller_withPIC_DW.Umax =
          motion_controller_withPIC_B.b_value_ff;
        motion_controller_withPIC_B.kidx = -1;
        motion_controller_withPIC_B.b_kidx = -1;
        for (motion_controller_withPIC_B.i = 0; motion_controller_withPIC_B.i <
             10; motion_controller_withPIC_B.i++) {
          for (motion_controller_withPIC_B.j = 0; motion_controller_withPIC_B.j <
               2; motion_controller_withPIC_B.j++) {
            motion_controller_withPIC_B.b_j = motion_controller_withPIC_B.j << 1;
            motion_controller_withPIC_B.B_k = B[motion_controller_withPIC_B.b_j];
            motion_controller_withPIC_B.B_b = B[motion_controller_withPIC_B.b_j
              + 1];
            for (motion_controller_withPIC_B.b_j = 0;
                 motion_controller_withPIC_B.b_j < 10;
                 motion_controller_withPIC_B.b_j++) {
              motion_controller_withPIC_B.A = A[10 *
                motion_controller_withPIC_B.i + motion_controller_withPIC_B.b_j];
              motion_controller_withPIC_B.Rp_g[motion_controller_withPIC_B.kidx
                + 1] = motion_controller_withPIC_B.A *
                motion_controller_withPIC_B.B_k;
              motion_controller_withPIC_B.K_e[motion_controller_withPIC_B.b_kidx
                + 1] = static_cast<int8_T>(motion_controller_withPIC_B.A *
                motion_controller_withPIC_B.B_k);
              motion_controller_withPIC_B.Rp_g[motion_controller_withPIC_B.kidx
                + 2] = motion_controller_withPIC_B.A *
                motion_controller_withPIC_B.B_b;
              motion_controller_withPIC_B.K_e[motion_controller_withPIC_B.b_kidx
                + 2] = static_cast<int8_T>(motion_controller_withPIC_B.A *
                motion_controller_withPIC_B.B_b);
              motion_controller_withPIC_B.b_kidx =
                motion_controller_withPIC_B.kidx + 2;
              motion_controller_withPIC_B.kidx += 2;
            }
          }
        }

        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx < 20;
             motion_controller_withPIC_B.kidx++) {
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 20;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.i = 20 *
              motion_controller_withPIC_B.kidx +
              motion_controller_withPIC_B.b_kidx;
            motion_controller_withPIC_B.j = 40 *
              motion_controller_withPIC_B.kidx +
              motion_controller_withPIC_B.b_kidx;
            motion_controller_withPIC_DW.A[motion_controller_withPIC_B.j] =
              motion_controller_withPIC_B.Rp_g[motion_controller_withPIC_B.i];
            motion_controller_withPIC_DW.A[motion_controller_withPIC_B.j + 20] =
              -static_cast<real_T>
              (motion_controller_withPIC_B.K_e[motion_controller_withPIC_B.i]);
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
          motion_controller_withPIC_B.d_i = 0;
          motion_controller_withPIC_B.loop_ub = 0;
        } else {
          motion_controller_withPIC_B.d_i = motion_controller_withPIC_B.j - 6;
          motion_controller_withPIC_B.loop_ub = motion_controller_withPIC_B.j;
        }

        if (motion_controller_withPIC_B.k - 5 > motion_controller_withPIC_B.k) {
          motion_controller_withPIC_B.i = 0;
          motion_controller_withPIC_B.kidx = 0;
        } else {
          motion_controller_withPIC_B.i = motion_controller_withPIC_B.k - 6;
          motion_controller_withPIC_B.kidx = motion_controller_withPIC_B.k;
        }

        motion_controller_withPIC_B.f_idx_0 =
          motion_controller_withPIC_B.loop_ub - motion_controller_withPIC_B.d_i;
        motion_controller_withPIC_B.f_idx_1 = motion_controller_withPIC_B.kidx -
          motion_controller_withPIC_B.i;
        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx <
             motion_controller_withPIC_B.f_idx_1;
             motion_controller_withPIC_B.kidx++) {
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx <
               motion_controller_withPIC_B.f_idx_0;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.Qp_c[(motion_controller_withPIC_B.d_i +
              motion_controller_withPIC_B.b_kidx) + 60 *
              (motion_controller_withPIC_B.i + motion_controller_withPIC_B.kidx)]
              =
              motion_controller_withPIC_B.Q[motion_controller_withPIC_B.f_idx_0 *
              motion_controller_withPIC_B.kidx +
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
        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx < motion_controller_withPIC_B.i;
             motion_controller_withPIC_B.kidx++) {
          motion_controller_withPIC_B.b_b[motion_controller_withPIC_B.b_kidx +
            motion_controller_withPIC_B.kidx] =
            motion_controller_withPIC_B.y_h[motion_controller_withPIC_B.kidx];
        }
      }

      memset(&motion_controller_withPIC_B.Rp_g[0], 0, 400U * sizeof(real_T));
      motion_controller_withPIC_B.k = 2;
      for (motion_controller_withPIC_B.loop_ub = 0;
           motion_controller_withPIC_B.loop_ub < 10;
           motion_controller_withPIC_B.loop_ub++) {
        motion_controller_withPIC_B.j = motion_controller_withPIC_B.loop_ub << 1;
        if (motion_controller_withPIC_B.k - 1 > motion_controller_withPIC_B.k) {
          motion_controller_withPIC_B.i = 0;
          motion_controller_withPIC_B.kidx = 0;
        } else {
          motion_controller_withPIC_B.i = motion_controller_withPIC_B.k - 2;
          motion_controller_withPIC_B.kidx = motion_controller_withPIC_B.k;
        }

        motion_controller_withPIC_B.f_idx_1 = motion_controller_withPIC_B.kidx -
          motion_controller_withPIC_B.i;
        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx <
             motion_controller_withPIC_B.f_idx_1;
             motion_controller_withPIC_B.kidx++) {
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 2;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.Rp_g[(motion_controller_withPIC_B.j +
              motion_controller_withPIC_B.b_kidx) + 20 *
              (motion_controller_withPIC_B.i + motion_controller_withPIC_B.kidx)]
              = motion_controller_withPIC_B.R[(motion_controller_withPIC_B.kidx <<
              1) + motion_controller_withPIC_B.b_kidx];
          }
        }

        motion_controller_withPIC_B.k += 2;
      }

      for (motion_controller_withPIC_B.kidx = 0;
           motion_controller_withPIC_B.kidx < 60;
           motion_controller_withPIC_B.kidx++) {
        motion_controller_withPIC_B.b_kidx = motion_controller_withPIC_B.kidx *
          20;
        memset
          (&motion_controller_withPIC_B.y_n[motion_controller_withPIC_B.b_kidx],
           0, 20U * sizeof(real_T));
        for (motion_controller_withPIC_B.i = 0; motion_controller_withPIC_B.i <
             60; motion_controller_withPIC_B.i++) {
          motion_controller_withPIC_B.b_value_ff =
            motion_controller_withPIC_B.Qp_c[motion_controller_withPIC_B.i * 60
            + motion_controller_withPIC_B.kidx];
          for (motion_controller_withPIC_B.j = 0; motion_controller_withPIC_B.j <
               20; motion_controller_withPIC_B.j++) {
            motion_controller_withPIC_B.b_j = motion_controller_withPIC_B.b_kidx
              + motion_controller_withPIC_B.j;
            motion_controller_withPIC_B.y_n[motion_controller_withPIC_B.b_j] +=
              motion_controller_withPIC_B.H[motion_controller_withPIC_B.j * 60 +
              motion_controller_withPIC_B.i] *
              motion_controller_withPIC_B.b_value_ff;
          }
        }

        memset
          (&motion_controller_withPIC_B.b_y_p[motion_controller_withPIC_B.b_kidx],
           0, 20U * sizeof(real_T));
        for (motion_controller_withPIC_B.i = 0; motion_controller_withPIC_B.i <
             60; motion_controller_withPIC_B.i++) {
          motion_controller_withPIC_B.b_value_ff =
            motion_controller_withPIC_B.Qp_c[motion_controller_withPIC_B.i * 60
            + motion_controller_withPIC_B.kidx];
          for (motion_controller_withPIC_B.b_j = 0;
               motion_controller_withPIC_B.b_j < 20;
               motion_controller_withPIC_B.b_j++) {
            motion_controller_withPIC_B.j = motion_controller_withPIC_B.b_kidx +
              motion_controller_withPIC_B.b_j;
            motion_controller_withPIC_B.b_y_p[motion_controller_withPIC_B.j] +=
              motion_controller_withPIC_B.H[motion_controller_withPIC_B.b_j * 60
              + motion_controller_withPIC_B.i] *
              motion_controller_withPIC_B.b_value_ff;
          }
        }
      }

      motion_controller_withPIC_B.b_value_ff = motion_controller_withPIC_DW.Umax
        - motion_controller_withPIC_DW.UnitDelay_DSTATE;
      motion_controller_withPIC_B.dr_i = motion_controller_withPIC_DW.Umax -
        motion_controller_withPIC_DW.UnitDelay1_DSTATE;
      motion_controller_withPIC_B.kidx = -1;
      for (motion_controller_withPIC_B.b_kidx = 0;
           motion_controller_withPIC_B.b_kidx < 10;
           motion_controller_withPIC_B.b_kidx++) {
        motion_controller_withPIC_B.b_K_n[motion_controller_withPIC_B.kidx + 1] =
          motion_controller_withPIC_B.b_value_ff;
        motion_controller_withPIC_B.b_K_n[motion_controller_withPIC_B.kidx + 2] =
          motion_controller_withPIC_B.dr_i;
        motion_controller_withPIC_B.kidx += 2;
      }

      motion_controller_withPIC_B.b_value_ff =
        motion_controller_withPIC_DW.UnitDelay_DSTATE -
        motion_controller_withPIC_DW.Umin;
      motion_controller_withPIC_B.dr_i =
        motion_controller_withPIC_DW.UnitDelay1_DSTATE -
        motion_controller_withPIC_DW.Umin;
      motion_controller_withPIC_B.kidx = -1;
      for (motion_controller_withPIC_B.b_kidx = 0;
           motion_controller_withPIC_B.b_kidx < 10;
           motion_controller_withPIC_B.b_kidx++) {
        motion_controller_withPIC_B.c_K[motion_controller_withPIC_B.kidx + 1] =
          motion_controller_withPIC_B.b_value_ff;
        motion_controller_withPIC_B.c_K[motion_controller_withPIC_B.kidx + 2] =
          motion_controller_withPIC_B.dr_i;
        motion_controller_withPIC_B.kidx += 2;
      }

      for (motion_controller_withPIC_B.i = 0; motion_controller_withPIC_B.i < 20;
           motion_controller_withPIC_B.i++) {
        motion_controller_withPIC_B.V_o[motion_controller_withPIC_B.i] =
          motion_controller_withPIC_DW.x0[motion_controller_withPIC_B.i];
        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx < 60;
             motion_controller_withPIC_B.kidx++) {
          motion_controller_withPIC_B.b_value_ff = 0.0;
          motion_controller_withPIC_B.b_value_l = 0.0;
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 60;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.b_value_ff +=
              motion_controller_withPIC_B.H[60 * motion_controller_withPIC_B.i +
              motion_controller_withPIC_B.b_kidx] *
              motion_controller_withPIC_B.Qp_c[60 *
              motion_controller_withPIC_B.kidx +
              motion_controller_withPIC_B.b_kidx];
            motion_controller_withPIC_B.b_value_l =
              motion_controller_withPIC_B.b_value_ff;
          }

          motion_controller_withPIC_B.b_kidx = 20 *
            motion_controller_withPIC_B.kidx + motion_controller_withPIC_B.i;
          motion_controller_withPIC_B.rtb_H_j[motion_controller_withPIC_B.b_kidx]
            = motion_controller_withPIC_B.b_value_l;
          motion_controller_withPIC_B.rtb_H_l[motion_controller_withPIC_B.b_kidx]
            = motion_controller_withPIC_B.b_value_ff;
        }

        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx < 6;
             motion_controller_withPIC_B.kidx++) {
          motion_controller_withPIC_B.b_value_l = 0.0;
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 60;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.b_value_l +=
              motion_controller_withPIC_B.rtb_H_j[20 *
              motion_controller_withPIC_B.b_kidx + motion_controller_withPIC_B.i]
              * motion_controller_withPIC_B.G[60 *
              motion_controller_withPIC_B.kidx +
              motion_controller_withPIC_B.b_kidx];
          }

          motion_controller_withPIC_B.rtb_H_o[motion_controller_withPIC_B.i + 20
            * motion_controller_withPIC_B.kidx] =
            motion_controller_withPIC_B.b_value_l;
        }

        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx < 40;
             motion_controller_withPIC_B.kidx++) {
          motion_controller_withPIC_B.dr_i = 0.0;
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 60;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.dr_i += motion_controller_withPIC_B.y_n
              [20 * motion_controller_withPIC_B.b_kidx +
              motion_controller_withPIC_B.i] * motion_controller_withPIC_B.W[60 *
              motion_controller_withPIC_B.kidx +
              motion_controller_withPIC_B.b_kidx];
          }

          motion_controller_withPIC_B.y_d[motion_controller_withPIC_B.i + 20 *
            motion_controller_withPIC_B.kidx] = motion_controller_withPIC_B.dr_i;
        }

        motion_controller_withPIC_B.b_value_l = 0.0;
        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx < 6;
             motion_controller_withPIC_B.kidx++) {
          motion_controller_withPIC_B.b_value_l +=
            motion_controller_withPIC_B.rtb_H_o[20 *
            motion_controller_withPIC_B.kidx + motion_controller_withPIC_B.i] *
            motion_controller_withPIC_B.Reshape[motion_controller_withPIC_B.kidx];
        }

        motion_controller_withPIC_B.dr_i = 0.0;
        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx < 40;
             motion_controller_withPIC_B.kidx++) {
          motion_controller_withPIC_B.dr_i += motion_controller_withPIC_B.y_d[20
            * motion_controller_withPIC_B.kidx + motion_controller_withPIC_B.i] *
            motion_controller_withPIC_B.T[motion_controller_withPIC_B.kidx];
        }

        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx < 20;
             motion_controller_withPIC_B.kidx++) {
          motion_controller_withPIC_B.b_value_ff = 0.0;
          for (motion_controller_withPIC_B.b_kidx = 0;
               motion_controller_withPIC_B.b_kidx < 60;
               motion_controller_withPIC_B.b_kidx++) {
            motion_controller_withPIC_B.b_value_ff +=
              motion_controller_withPIC_B.rtb_H_l[20 *
              motion_controller_withPIC_B.b_kidx + motion_controller_withPIC_B.i]
              * motion_controller_withPIC_B.H[60 *
              motion_controller_withPIC_B.kidx +
              motion_controller_withPIC_B.b_kidx];
          }

          motion_controller_withPIC_B.b_kidx = 20 *
            motion_controller_withPIC_B.kidx + motion_controller_withPIC_B.i;
          motion_controller_withPIC_B.rtb_H_ld[motion_controller_withPIC_B.b_kidx]
            =
            motion_controller_withPIC_B.Rp_g[motion_controller_withPIC_B.b_kidx]
            + motion_controller_withPIC_B.b_value_ff;
        }

        motion_controller_withPIC_B.b_value_ff = 0.0;
        for (motion_controller_withPIC_B.kidx = 0;
             motion_controller_withPIC_B.kidx < 60;
             motion_controller_withPIC_B.kidx++) {
          motion_controller_withPIC_B.b_value_ff +=
            motion_controller_withPIC_B.b_y_p[20 *
            motion_controller_withPIC_B.kidx + motion_controller_withPIC_B.i] *
            motion_controller_withPIC_B.b_b[motion_controller_withPIC_B.kidx];
        }

        motion_controller_withPIC_B.rtb_H_m[motion_controller_withPIC_B.i] =
          (motion_controller_withPIC_B.b_value_l +
           motion_controller_withPIC_B.dr_i) -
          motion_controller_withPIC_B.b_value_ff;
        motion_controller_withPIC_B.b_K[motion_controller_withPIC_B.i] =
          motion_controller_withPIC_B.b_K_n[motion_controller_withPIC_B.i];
        motion_controller_withPIC_B.b_K[motion_controller_withPIC_B.i + 20] =
          motion_controller_withPIC_B.c_K[motion_controller_withPIC_B.i];
        motion_controller_withPIC_B.rtb_Gain1_cz[motion_controller_withPIC_B.i] =
          motion_controller_withPIC_B.df_j;
        motion_controller_withPIC_B.b_value_m[motion_controller_withPIC_B.i] =
          motion_controller_withPIC_B.b_value_g;
      }

      motion_controller_wi_quadprog_k(motion_controller_withPIC_B.rtb_H_ld,
        motion_controller_withPIC_B.rtb_H_m, motion_controller_withPIC_DW.A,
        motion_controller_withPIC_B.b_K,
        motion_controller_withPIC_B.rtb_Gain1_cz,
        motion_controller_withPIC_B.b_value_m, motion_controller_withPIC_B.V_o,
        &motion_controller_withPIC_DW.opts_j);
      motion_controller_withPIC_B.b_value_ff = motion_controller_withPIC_B.V_o[0]
        + motion_controller_withPIC_DW.UnitDelay_DSTATE;
      motion_controller_withPIC_B.dr_i = motion_controller_withPIC_B.V_o[1] +
        motion_controller_withPIC_DW.UnitDelay1_DSTATE;

      // SignalConversion generated from: '<S49>/dfl' incorporates:
      //   MATLAB Function: '<S49>/solvex'
      //   Merge: '<S46>/Merge'

      motion_controller_withPIC_B.Merge[0] =
        motion_controller_withPIC_B.b_value_ff;

      // SignalConversion generated from: '<S49>/dfr' incorporates:
      //   MATLAB Function: '<S49>/solvex'
      //   Merge: '<S46>/Merge'

      motion_controller_withPIC_B.Merge[1] =
        motion_controller_withPIC_B.b_value_ff;

      // SignalConversion generated from: '<S49>/drl' incorporates:
      //   MATLAB Function: '<S49>/solvex'
      //   Merge: '<S46>/Merge'

      motion_controller_withPIC_B.Merge[2] = motion_controller_withPIC_B.dr_i;

      // SignalConversion generated from: '<S49>/drr' incorporates:
      //   MATLAB Function: '<S49>/solvex'
      //   Merge: '<S46>/Merge'

      motion_controller_withPIC_B.Merge[3] = motion_controller_withPIC_B.dr_i;

      // End of Outputs for SubSystem: '<S46>/If Action Subsystem1'
    }

    // End of If: '<S46>/If'

    // Update for UnitDelay: '<S10>/Unit Delay'
    motion_controller_withPIC_DW.UnitDelay_DSTATE =
      motion_controller_withPIC_B.Merge[0];

    // Update for UnitDelay: '<S10>/Unit Delay1'
    motion_controller_withPIC_DW.UnitDelay1_DSTATE =
      motion_controller_withPIC_B.Merge[3];
  } else {
    motion_controller_withPIC_DW.picController_MODE = false;
  }

  // End of Outputs for SubSystem: '<Root>/picController'

  // BusAssignment: '<S4>/Bus Assignment2'
  motion_controller_withPIC_B.BusAssignment2.linear.y =
    motion_controller_withPIC_B.yp;
  motion_controller_withPIC_B.BusAssignment2.angular.z =
    motion_controller_withPIC_B.yaw;
  motion_controller_withPIC_B.BusAssignment2.linear.x =
    motion_controller_withPIC_B.isMpcEnable;
  motion_controller_withPIC_B.BusAssignment2.angular.y =
    motion_controller_withPIC_B.Ay;

  // MATLABSystem: '<S13>/SinkBlock'
  Pub_motion_controller_withPIC_545.publish
    (&motion_controller_withPIC_B.BusAssignment2);

  // Logic: '<Root>/Logical Operator'
  motion_controller_withPIC_B.Compare =
    (motion_controller_withPIC_B.In1_m.failsafe ||
     motion_controller_withPIC_B.In1_m.frame_lost);

  // MATLABSystem: '<S56>/SourceBlock'
  motion_controller_withPIC_B.b_value_ix =
    Sub_motion_controller_withPIC_238.getLatestMessage
    (&motion_controller_withPIC_B.b_varargout_2);

  // Logic: '<S11>/Logical Operator' incorporates:
  //   MATLABSystem: '<S55>/SourceBlock'
  //   MATLABSystem: '<S56>/SourceBlock'
  //
  motion_controller_withPIC_B.LogicalOperator_j =
    (motion_controller_withPIC_B.LogicalOperator_j &&
     motion_controller_withPIC_B.b_value_ix);

  // Outputs for Enabled SubSystem: '<S56>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S59>/Enable'

  // Start for MATLABSystem: '<S56>/SourceBlock'
  if (motion_controller_withPIC_B.b_value_ix) {
    // SignalConversion generated from: '<S59>/In1'
    motion_controller_withPIC_B.In1 = motion_controller_withPIC_B.b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S56>/Enabled Subsystem'

  // Outputs for Iterator SubSystem: '<S11>/For Each Subsystem' incorporates:
  //   ForEach: '<S54>/For Each'

  for (motion_controller_withPIC_B.ForEach_itr = 0;
       motion_controller_withPIC_B.ForEach_itr < 16;
       motion_controller_withPIC_B.ForEach_itr++) {
    // ForEachSliceAssignment generated from: '<S54>/Out1' incorporates:
    //   ForEachSliceSelector generated from: '<S54>/In1'

    motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[motion_controller_withPIC_B.ForEach_itr]
      =
      motion_controller_withPIC_B.In1.actuator_state[motion_controller_withPIC_B.ForEach_itr]
      .velocity;
  }

  // End of Outputs for SubSystem: '<S11>/For Each Subsystem'

  // Outputs for Atomic SubSystem: '<Root>/controller'
  // MATLABSystem: '<S33>/Get Parameter4'
  ParamGet_motion_controller_withPIC_298.getParameter
    (&motion_controller_withPIC_B.b_value_ct);

  // MATLABSystem: '<S33>/Get Parameter2'
  ParamGet_motion_controller_withPIC_301.getParameter
    (&motion_controller_withPIC_B.b_value_ix);

  // MATLABSystem: '<S33>/Get Parameter3'
  ParamGet_motion_controller_withPIC_194.getParameter
    (&motion_controller_withPIC_B.b_value_p);

  // Switch: '<S33>/Switch' incorporates:
  //   MATLABSystem: '<S33>/Get Parameter2'
  //   SignalConversion generated from: '<S11>/Bus Selector'

  if (motion_controller_withPIC_B.b_value_ix) {
    motion_controller_withPIC_B.i_k =
      motion_controller_withPIC_B.In1_m.mapped_channels[2];
  } else {
    motion_controller_withPIC_B.i_k =
      motion_controller_withPIC_B.In1_m.mapped_channels[1];
  }

  // Product: '<S33>/Product1' incorporates:
  //   Constant: '<S33>/Constant2'
  //   Gain: '<S33>/Gain1'
  //   MATLABSystem: '<S33>/Get Parameter3'
  //   Sum: '<S33>/Add1'
  //   Switch: '<S33>/Switch'

  motion_controller_withPIC_B.b_value_g = (static_cast<real_T>
    (motion_controller_withPIC_B.i_k) -
    motion_controller_withPIC_P.Constant2_Value) *
    motion_controller_withPIC_P.Gain1_Gain_k *
    motion_controller_withPIC_B.b_value_p;

  // Chart: '<S33>/Chart2' incorporates:
  //   MATLABSystem: '<S33>/Get Parameter4'

  if (motion_controller_withPIC_DW.is_active_c6_motion_controller_ == 0U) {
    motion_controller_withPIC_DW.is_active_c6_motion_controller_ = 1U;
    motion_controller_withPIC_B.out = 0.0;
  } else {
    motion_controller_withPIC_B.yp = motion_controller_withPIC_B.b_value_g -
      motion_controller_withPIC_B.out;
    if (fabs(motion_controller_withPIC_B.yp) < 0.01 *
        motion_controller_withPIC_B.b_value_ct) {
      motion_controller_withPIC_B.out = motion_controller_withPIC_B.b_value_g;
    } else if (motion_controller_withPIC_B.b_value_ct == 0.0) {
      motion_controller_withPIC_B.out = motion_controller_withPIC_B.b_value_g;
    } else {
      if (rtIsNaN(motion_controller_withPIC_B.yp)) {
        motion_controller_withPIC_B.b_value_ff = (rtNaN);
      } else if (motion_controller_withPIC_B.yp < 0.0) {
        motion_controller_withPIC_B.b_value_ff = -1.0;
      } else {
        motion_controller_withPIC_B.b_value_ff = (motion_controller_withPIC_B.yp
          > 0.0);
      }

      motion_controller_withPIC_B.out += motion_controller_withPIC_B.b_value_ff *
        motion_controller_withPIC_B.b_value_ct * 0.01;
    }
  }

  // End of Chart: '<S33>/Chart2'

  // MATLABSystem: '<S33>/Get Parameter5'
  ParamGet_motion_controller_withPIC_329.getParameter
    (&motion_controller_withPIC_B.b_value_ix);

  // Gain: '<S33>/Gain2' incorporates:
  //   Constant: '<S33>/Constant'
  //   Gain: '<S33>/Gain'
  //   SignalConversion generated from: '<S11>/Bus Selector'
  //   Sum: '<S33>/Add'

  motion_controller_withPIC_B.b_value_ff = (static_cast<real_T>
    (motion_controller_withPIC_B.In1_m.mapped_channels[0]) -
    motion_controller_withPIC_P.Constant_Value_ff) *
    motion_controller_withPIC_P.Gain_Gain_f *
    motion_controller_withPIC_P.Gain2_Gain_b;

  // MATLABSystem: '<S33>/Get Parameter1'
  ParamGet_motion_controller_withPIC_317.getParameter
    (&motion_controller_withPIC_B.b_value_ct);

  // MATLABSystem: '<S33>/Get Parameter'
  ParamGet_motion_controller_withPIC_316.getParameter
    (&motion_controller_withPIC_B.b_value_p);

  // MATLAB Function: '<S33>/MATLAB Function' incorporates:
  //   MATLABSystem: '<S33>/Get Parameter'
  //   MATLABSystem: '<S33>/Get Parameter1'
  //   MATLABSystem: '<S33>/Get Parameter5'

  if (motion_controller_withPIC_B.b_value_ix) {
    motion_controller_withPIC_B.b_value_g =
      motion_controller_withPIC_B.b_value_ct / 180.0 * 3.1415926535897931 * 0.01
      / 2.0;
  } else {
    motion_controller_withPIC_B.b_value_g =
      motion_controller_withPIC_B.b_value_ct / 180.0 * 3.1415926535897931 * 0.01;
  }

  motion_controller_withPIC_B.yp = motion_controller_withPIC_B.b_value_ff -
    motion_controller_withPIC_DW.angle_out;
  if (fabs(motion_controller_withPIC_B.yp) <
      motion_controller_withPIC_B.b_value_g) {
    motion_controller_withPIC_DW.angle_out =
      motion_controller_withPIC_B.b_value_ff;
  } else if (motion_controller_withPIC_B.b_value_ct <= 0.0) {
    motion_controller_withPIC_DW.angle_out =
      motion_controller_withPIC_B.b_value_ff;
  } else {
    if (rtIsNaN(motion_controller_withPIC_B.yp)) {
      motion_controller_withPIC_B.b_value_ff = (rtNaN);
    } else if (motion_controller_withPIC_B.yp < 0.0) {
      motion_controller_withPIC_B.b_value_ff = -1.0;
    } else {
      motion_controller_withPIC_B.b_value_ff = (motion_controller_withPIC_B.yp >
        0.0);
    }

    motion_controller_withPIC_DW.angle_out +=
      motion_controller_withPIC_B.b_value_ff *
      motion_controller_withPIC_B.b_value_g /
      motion_controller_withPIC_B.b_value_p;
  }

  if (motion_controller_withPIC_B.b_value_ix) {
    motion_controller_withPIC_B.yp = fabs(motion_controller_withPIC_DW.angle_out);
    if (rtIsNaN(motion_controller_withPIC_DW.angle_out)) {
      motion_controller_withPIC_B.b_value_ff = (rtNaN);
    } else if (motion_controller_withPIC_DW.angle_out < 0.0) {
      motion_controller_withPIC_B.b_value_ff = -1.0;
    } else {
      motion_controller_withPIC_B.b_value_ff =
        (motion_controller_withPIC_DW.angle_out > 0.0);
    }

    if (!(motion_controller_withPIC_B.yp <= 0.5)) {
      motion_controller_withPIC_B.yp = 0.5;
    }

    motion_controller_withPIC_B.yp = motion_controller_withPIC_B.b_value_ff *
      motion_controller_withPIC_B.yp * 2.0;
    motion_controller_withPIC_B.b_value_ff = fabs
      (motion_controller_withPIC_DW.angle_out);
    if (motion_controller_withPIC_B.b_value_ff > 0.5) {
      if (rtIsNaN(motion_controller_withPIC_DW.angle_out)) {
        motion_controller_withPIC_B.b_value_g = (rtNaN);
      } else if (motion_controller_withPIC_DW.angle_out < 0.0) {
        motion_controller_withPIC_B.b_value_g = -1.0;
      } else {
        motion_controller_withPIC_B.b_value_g =
          (motion_controller_withPIC_DW.angle_out > 0.0);
      }

      motion_controller_withPIC_B.b_value_g =
        (motion_controller_withPIC_B.b_value_ff - 0.5) *
        -motion_controller_withPIC_B.b_value_g * 2.0;
    } else {
      motion_controller_withPIC_B.b_value_g = 0.0;
    }
  } else {
    motion_controller_withPIC_B.yp = motion_controller_withPIC_DW.angle_out;
    motion_controller_withPIC_B.b_value_g = 0.0;
  }

  motion_controller_withPIC_B.yp *= motion_controller_withPIC_B.b_value_p;
  motion_controller_withPIC_B.b_value_g *= motion_controller_withPIC_B.b_value_p;

  // End of MATLAB Function: '<S33>/MATLAB Function'

  // MATLABSystem: '<S9>/Get Parameter1'
  ParamGet_motion_controller_withPIC_217.getParameter
    (&motion_controller_withPIC_B.GetParameter1);

  // Chart: '<S9>/Chart' incorporates:
  //   Constant: '<S9>/Constant'
  //   SignalConversion generated from: '<S11>/Bus Selector'

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
        motion_controller_withPIC_B.b_value_ff = (rtNaN);
      } else if (rtIsInf(motion_controller_withPIC_DW.counter)) {
        motion_controller_withPIC_B.b_value_ff = (rtNaN);
      } else if (motion_controller_withPIC_DW.counter == 0.0) {
        motion_controller_withPIC_B.b_value_ff = 0.0;
      } else {
        motion_controller_withPIC_B.b_value_ff = fmod
          (motion_controller_withPIC_DW.counter, 20.0);
        if (motion_controller_withPIC_B.b_value_ff == 0.0) {
          motion_controller_withPIC_B.b_value_ff = 0.0;
        } else if (motion_controller_withPIC_DW.counter < 0.0) {
          motion_controller_withPIC_B.b_value_ff += 20.0;
        }
      }

      if (motion_controller_withPIC_B.b_value_ff == 0.0) {
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
          motion_controller_withPIC_B.b_value_ff = 1.5 * fabs
            (motion_controller_withPIC_B.out);
          motion_controller_withPIC_B.df_j =
            (((motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[0] +
               motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[1]) +
              motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[2]) +
             motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[3]) / 4.0;
          if (fabs(motion_controller_withPIC_B.df_j) < 0.5) {
            motion_controller_withPIC_B.mode = 1;
            motion_controller_withPIC_B.spd_cmd[0] = 0.0;
            motion_controller_withPIC_B.spd_cmd[1] = 0.0;
            motion_controller_withPIC_B.spd_cmd[2] = 0.0;
            motion_controller_withPIC_B.spd_cmd[3] = 0.0;
            motion_controller_withPIC_B.b_value_ff = 0.0;
          } else if (motion_controller_withPIC_B.df_j > 0.5) {
            motion_controller_withPIC_B.b_value_ff =
              -motion_controller_withPIC_B.b_value_ff;
            motion_controller_withPIC_B.mode = 2;
          } else if (motion_controller_withPIC_B.df_j < -0.5) {
            motion_controller_withPIC_B.mode = 2;
          }

          motion_controller__get_angle_4w(motion_controller_withPIC_B.yp,
            motion_controller_withPIC_B.b_value_g,
            motion_controller_withPIC_B.angle_cmd);
          motion_controller_withPIC_B.effort_cmd[0] =
            motion_controller_withPIC_B.b_value_ff * 1.6;
          motion_controller_withPIC_B.yp =
            -motion_controller_withPIC_B.b_value_ff * 1.6;
          motion_controller_withPIC_B.effort_cmd[1] =
            motion_controller_withPIC_B.yp;
          motion_controller_withPIC_B.effort_cmd[2] =
            motion_controller_withPIC_B.yp;
          motion_controller_withPIC_B.effort_cmd[3] =
            motion_controller_withPIC_B.b_value_ff * 1.6;
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
        motion_controller__get_angle_4w(motion_controller_withPIC_B.yp,
          motion_controller_withPIC_B.b_value_g,
          motion_controller_withPIC_B.angle_cmd);
        motion_controller_withPIC_B.rtb_Add_c[0] =
          motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[0] / 0.07;
        motion_controller_withPIC_B.rtb_Add_c[1] =
          motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[1] / 0.07;
        motion_controller_withPIC_B.rtb_Add_c[2] =
          motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[2] / 0.07;
        motion_controller_withPIC_B.rtb_Add_c[3] =
          motion_controller_withPIC_B.ImpAsg_InsertedFor_Out1_a_k[3] / 0.07;
        if (motion_controller_withPIC_B.In1_m.mapped_channels[6] == 1000) {
          motion_controller_withPIC_B.b_value_ff = -0.5 *
            motion_controller_withPIC_B.out;
        } else {
          motion_controller_withPIC_B.b_value_ff =
            motion_controller_withPIC_B.out;
        }

        motion_controller_wi_get_effort(motion_controller_withPIC_B.b_value_ff,
          motion_controller_withPIC_P.Constant_Value_o,
          motion_controller_withPIC_P.Constant_Value_o,
          motion_controller_withPIC_B.rtb_Add_c,
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
        motion_controller__get_angle_4w(motion_controller_withPIC_B.yp,
          motion_controller_withPIC_B.b_value_g,
          motion_controller_withPIC_B.angle_cmd);
        motion_controller_withP_get_spd(motion_controller_withPIC_B.yp,
          motion_controller_withPIC_B.out, motion_controller_withPIC_B.spd_cmd);
        motion_controller_withPIC_B.mode = 1;
      }
      break;
    }
  }

  // End of Chart: '<S9>/Chart'
  // End of Outputs for SubSystem: '<Root>/controller'

  // MATLABSystem: '<S6>/Get Parameter3'
  ParamGet_motion_controller_withPIC_621.getParameter
    (&motion_controller_withPIC_B.b_value_ct);

  // MATLABSystem: '<S6>/Get Parameter1'
  ParamGet_motion_controller_withPIC_625.getParameter
    (&motion_controller_withPIC_B.b_value_ix);

  // Switch: '<S6>/Switch2' incorporates:
  //   Gain: '<S6>/Gain'
  //   Gain: '<S6>/Gain1'
  //   MATLABSystem: '<S6>/Get Parameter1'
  //   MATLABSystem: '<S6>/Get Parameter3'
  //   Product: '<S6>/Divide'

  if (motion_controller_withPIC_B.b_value_ix) {
    motion_controller_withPIC_B.gama[0] = motion_controller_withPIC_B.spd_cmd[0]
      / motion_controller_withPIC_B.b_value_ct *
      motion_controller_withPIC_P.Gain1_Gain;
    motion_controller_withPIC_B.gama[1] = motion_controller_withPIC_B.spd_cmd[1]
      / motion_controller_withPIC_B.b_value_ct *
      motion_controller_withPIC_P.Gain1_Gain;
    motion_controller_withPIC_B.gama[2] = motion_controller_withPIC_B.spd_cmd[2]
      / motion_controller_withPIC_B.b_value_ct *
      motion_controller_withPIC_P.Gain1_Gain;
    motion_controller_withPIC_B.gama[3] = motion_controller_withPIC_B.spd_cmd[3]
      / motion_controller_withPIC_B.b_value_ct *
      motion_controller_withPIC_P.Gain1_Gain;
  } else {
    motion_controller_withPIC_B.gama[0] = motion_controller_withPIC_P.Gain_Gain *
      motion_controller_withPIC_B.effort_cmd[0];
    motion_controller_withPIC_B.gama[1] = motion_controller_withPIC_P.Gain_Gain *
      motion_controller_withPIC_B.effort_cmd[1];
    motion_controller_withPIC_B.gama[2] = motion_controller_withPIC_P.Gain_Gain *
      motion_controller_withPIC_B.effort_cmd[2];
    motion_controller_withPIC_B.gama[3] = motion_controller_withPIC_P.Gain_Gain *
      motion_controller_withPIC_B.effort_cmd[3];
  }

  // End of Switch: '<S6>/Switch2'

  // MATLABSystem: '<S6>/Get Parameter2'
  ParamGet_motion_controller_withPIC_629.getParameter
    (&motion_controller_withPIC_B.b_value_ix);

  // Switch: '<S6>/Switch1'
  if (motion_controller_withPIC_B.isPicEnable != 0) {
    // Switch: '<S6>/Switch3' incorporates:
    //   Gain: '<S6>/Gain2'
    //   MATLABSystem: '<S6>/Get Parameter2'

    if (motion_controller_withPIC_B.b_value_ix) {
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

    // End of Switch: '<S6>/Switch3'
  } else {
    motion_controller_withPIC_B.R[0] = motion_controller_withPIC_B.angle_cmd[0];
    motion_controller_withPIC_B.R[1] = motion_controller_withPIC_B.angle_cmd[1];
    motion_controller_withPIC_B.R[2] = motion_controller_withPIC_B.angle_cmd[2];
    motion_controller_withPIC_B.R[3] = motion_controller_withPIC_B.angle_cmd[3];
  }

  // End of Switch: '<S6>/Switch1'

  // Outputs for Enabled SubSystem: '<Root>/cmd_pub' incorporates:
  //   EnablePort: '<S8>/Enable'

  // RelationalOperator: '<S2>/Compare' incorporates:
  //   Constant: '<S2>/Constant'
  //   SignalConversion generated from: '<S11>/Bus Selector'

  if (motion_controller_withPIC_B.In1_m.mapped_channels[5] ==
      motion_controller_withPIC_P.CompareToConstant_const_m) {
    motion_controller_w_CurrentTime(&motion_controller_withPIC_B.CurrentTime1);

    // BusAssignment: '<S8>/Bus Assignment1' incorporates:
    //   Constant: '<S25>/Constant'

    motion_controller_withPIC_B.BusAssignment1 =
      motion_controller_withPIC_P.Constant_Value_f;

    // Outputs for Iterator SubSystem: '<S8>/For Each Subsystem1' incorporates:
    //   ForEach: '<S27>/For Each'

    for (motion_controller_withPIC_B.ForEach_itr_j_k = 0;
         motion_controller_withPIC_B.ForEach_itr_j_k < 4;
         motion_controller_withPIC_B.ForEach_itr_j_k++) {
      // Saturate: '<S6>/Saturation'
      motion_controller_withPIC_B.b_value_g =
        motion_controller_withPIC_B.gama[motion_controller_withPIC_B.ForEach_itr_j_k];
      if (motion_controller_withPIC_B.b_value_g >
          motion_controller_withPIC_P.Saturation_UpperSat_h) {
        motion_controller_withPIC_B.b_value_g =
          motion_controller_withPIC_P.Saturation_UpperSat_h;
      } else if (motion_controller_withPIC_B.b_value_g <
                 motion_controller_withPIC_P.Saturation_LowerSat_k) {
        motion_controller_withPIC_B.b_value_g =
          motion_controller_withPIC_P.Saturation_LowerSat_k;
      }

      // Saturate: '<S8>/Saturation2' incorporates:
      //   Saturate: '<S6>/Saturation'

      if (motion_controller_withPIC_B.b_value_g >
          motion_controller_withPIC_P.Saturation2_UpperSat) {
        motion_controller_withPIC_B.b_value_g =
          motion_controller_withPIC_P.Saturation2_UpperSat;
      } else if (motion_controller_withPIC_B.b_value_g <
                 motion_controller_withPIC_P.Saturation2_LowerSat) {
        motion_controller_withPIC_B.b_value_g =
          motion_controller_withPIC_P.Saturation2_LowerSat;
      }

      motion_controller_withPIC_B.gama[motion_controller_withPIC_B.ForEach_itr_j_k]
        = motion_controller_withPIC_B.b_value_g;

      // End of Saturate: '<S8>/Saturation2'

      // Saturate: '<S8>/Saturation1'
      motion_controller_withPIC_B.yp =
        motion_controller_withPIC_B.spd_cmd[motion_controller_withPIC_B.ForEach_itr_j_k];

      // ForEachSliceAssignment generated from: '<S27>/actuaor_command' incorporates:
      //   BusAssignment: '<S27>/Bus Assignment1'
      //   Constant: '<S31>/Constant'

      motion_controller_withPIC_B.ImpAsg_InsertedFor_actuaor_[motion_controller_withPIC_B.ForEach_itr_j_k]
        = motion_controller_withPIC_P.CoreSubsys_pn.Constant_Value;

      // BusAssignment: '<S27>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S27>/actuaor_command'
      //   ForEachSliceSelector generated from: '<S27>/effort'

      motion_controller_withPIC_B.ImpAsg_InsertedFor_actuaor_[motion_controller_withPIC_B.ForEach_itr_j_k]
        .effort = motion_controller_withPIC_B.b_value_g;

      // Saturate: '<S8>/Saturation1'
      if (motion_controller_withPIC_B.yp >
          motion_controller_withPIC_P.Saturation1_UpperSat) {
        // BusAssignment: '<S27>/Bus Assignment1' incorporates:
        //   ForEachSliceAssignment generated from: '<S27>/actuaor_command'

        motion_controller_withPIC_B.ImpAsg_InsertedFor_actuaor_[motion_controller_withPIC_B.ForEach_itr_j_k]
          .velocity = motion_controller_withPIC_P.Saturation1_UpperSat;
      } else if (motion_controller_withPIC_B.yp <
                 motion_controller_withPIC_P.Saturation1_LowerSat) {
        // BusAssignment: '<S27>/Bus Assignment1' incorporates:
        //   ForEachSliceAssignment generated from: '<S27>/actuaor_command'

        motion_controller_withPIC_B.ImpAsg_InsertedFor_actuaor_[motion_controller_withPIC_B.ForEach_itr_j_k]
          .velocity = motion_controller_withPIC_P.Saturation1_LowerSat;
      } else {
        // BusAssignment: '<S27>/Bus Assignment1' incorporates:
        //   ForEachSliceAssignment generated from: '<S27>/actuaor_command'

        motion_controller_withPIC_B.ImpAsg_InsertedFor_actuaor_[motion_controller_withPIC_B.ForEach_itr_j_k]
          .velocity = motion_controller_withPIC_B.yp;
      }
    }

    // End of Outputs for SubSystem: '<S8>/For Each Subsystem1'

    // BusAssignment: '<S8>/Bus Assignment1'
    motion_controller_withPIC_B.BusAssignment1.header.stamp =
      motion_controller_withPIC_B.CurrentTime1.CurrentTime;

    // Switch: '<S6>/Switch' incorporates:
    //   Logic: '<S6>/Logical Operator1'

    if ((motion_controller_withPIC_B.isPicEnable != 0) &&
        (motion_controller_withPIC_B.mode != 0)) {
      // DataTypeConversion: '<S8>/Data Type Conversion' incorporates:
      //   Constant: '<S6>/Constant'

      motion_controller_withPIC_B.b_value_ff = floor
        (motion_controller_withPIC_P.Constant_Value_b);
      if (rtIsNaN(motion_controller_withPIC_B.b_value_ff) || rtIsInf
          (motion_controller_withPIC_B.b_value_ff)) {
        motion_controller_withPIC_B.b_value_ff = 0.0;
      } else {
        motion_controller_withPIC_B.b_value_ff = fmod
          (motion_controller_withPIC_B.b_value_ff, 4.294967296E+9);
      }

      if (motion_controller_withPIC_B.b_value_ff < 0.0) {
        // BusAssignment: '<S8>/Bus Assignment1'
        motion_controller_withPIC_B.BusAssignment1.drive_mode =
          -static_cast<int32_T>(static_cast<uint32_T>
          (-motion_controller_withPIC_B.b_value_ff));
      } else {
        // BusAssignment: '<S8>/Bus Assignment1'
        motion_controller_withPIC_B.BusAssignment1.drive_mode =
          static_cast<int32_T>(static_cast<uint32_T>
          (motion_controller_withPIC_B.b_value_ff));
      }

      // End of DataTypeConversion: '<S8>/Data Type Conversion'
    } else {
      // BusAssignment: '<S8>/Bus Assignment1'
      motion_controller_withPIC_B.BusAssignment1.drive_mode =
        motion_controller_withPIC_B.mode;
    }

    // End of Switch: '<S6>/Switch'

    // BusAssignment: '<S8>/Bus Assignment1'
    memcpy(&motion_controller_withPIC_B.BusAssignment1.actuator_command[0],
           &motion_controller_withPIC_B.ImpAsg_InsertedFor_actuaor_[0], sizeof
           (SL_Bus_custom_interfaces_Actuator) << 2U);

    // MATLABSystem: '<S28>/SinkBlock'
    Pub_motion_controller_withPIC_4.publish
      (&motion_controller_withPIC_B.BusAssignment1);
    motion_controller_w_CurrentTime(&motion_controller_withPIC_B.CurrentTime);

    // BusAssignment: '<S8>/Bus Assignment2' incorporates:
    //   Constant: '<S24>/Constant'

    motion_controller_withPIC_B.BusAssignment1 =
      motion_controller_withPIC_P.Constant_Value_i;

    // Outputs for Iterator SubSystem: '<S8>/For Each Subsystem' incorporates:
    //   ForEach: '<S26>/For Each'

    // Saturate: '<S8>/Saturation'
    for (motion_controller_withPIC_B.ForEach_itr_p_d = 0;
         motion_controller_withPIC_B.ForEach_itr_p_d < 4;
         motion_controller_withPIC_B.ForEach_itr_p_d++) {
      motion_controller_withPIC_B.yp =
        motion_controller_withPIC_B.R[motion_controller_withPIC_B.ForEach_itr_p_d];
      if (motion_controller_withPIC_B.yp >
          motion_controller_withPIC_P.Saturation_UpperSat) {
        motion_controller_withPIC_B.yp =
          motion_controller_withPIC_P.Saturation_UpperSat;
      } else if (motion_controller_withPIC_B.yp <
                 motion_controller_withPIC_P.Saturation_LowerSat) {
        motion_controller_withPIC_B.yp =
          motion_controller_withPIC_P.Saturation_LowerSat;
      }

      motion_controller_withPIC_B.R[motion_controller_withPIC_B.ForEach_itr_p_d]
        = motion_controller_withPIC_B.yp;

      // ForEachSliceAssignment generated from: '<S26>/actuaor_command' incorporates:
      //   BusAssignment: '<S26>/Bus Assignment1'
      //   Constant: '<S30>/Constant'
      //   Saturate: '<S8>/Saturation'

      motion_controller_withPIC_B.ImpAsg_InsertedFor_actuaor_[motion_controller_withPIC_B.ForEach_itr_p_d]
        = motion_controller_withPIC_P.CoreSubsys_p.Constant_Value;

      // BusAssignment: '<S26>/Bus Assignment1' incorporates:
      //   ForEachSliceAssignment generated from: '<S26>/actuaor_command'
      //   ForEachSliceSelector generated from: '<S26>/servo_position'

      motion_controller_withPIC_B.ImpAsg_InsertedFor_actuaor_[motion_controller_withPIC_B.ForEach_itr_p_d]
        .position = motion_controller_withPIC_B.yp;
    }

    // End of Saturate: '<S8>/Saturation'
    // End of Outputs for SubSystem: '<S8>/For Each Subsystem'

    // BusAssignment: '<S8>/Bus Assignment2'
    motion_controller_withPIC_B.BusAssignment1.header.stamp =
      motion_controller_withPIC_B.CurrentTime.CurrentTime;
    memcpy(&motion_controller_withPIC_B.BusAssignment1.actuator_command[0],
           &motion_controller_withPIC_B.ImpAsg_InsertedFor_actuaor_[0], sizeof
           (SL_Bus_custom_interfaces_Actuator) << 2U);

    // MATLABSystem: '<S29>/SinkBlock'
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
    static const char_T prmName_6[17] = "picActivationDAy";
    static const char_T prmName_7[21] = "picActivationDomegaz";
    static const char_T prmName_8[9] = "Weight_Y";
    static const char_T prmName_9[10] = "Weight_Vy";
    static const char_T prmName_a[11] = "Weight_Yaw";
    static const char_T prmName_b[15] = "Weight_YawRate";
    static const char_T prmName_c[10] = "Weight_df";
    static const char_T prmName_d[10] = "Weight_dr";
    static const char_T prmName_e[11] = "Weight_ddf";
    static const char_T prmName_f[11] = "Weight_ddr";
    static const char_T prmName_g[7] = "tireBf";
    static const char_T prmName_h[7] = "tireCf";
    static const char_T prmName_i[8] = "tireMuf";
    static const char_T prmName_j[7] = "tireBr";
    static const char_T prmName_k[7] = "tireCr";
    static const char_T prmName_l[8] = "tireMur";
    static const char_T prmName_m[8] = "spdMax1";
    static const char_T prmName_n[14] = "testWithDrive";
    static const char_T prmName_o[10] = "noControl";
    static const char_T prmName_p[12] = "angleMaxMpc";
    static const char_T prmName_q[15] = "isMpcN20Else10";
    static const char_T prmName_r[9] = "mpc_lbub";
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
    // SystemInitialize for IfAction SubSystem: '<S46>/If Action Subsystem'
    // SystemInitialize for MATLAB Function: '<S48>/solvex'
    tmp.DiffMaxChange = (rtInf);
    tmp.FunctionTolerance = (rtInf);

    // End of SystemInitialize for SubSystem: '<S46>/If Action Subsystem'
    // End of SystemInitialize for SubSystem: '<Root>/picController'

    // SystemInitialize for Enabled SubSystem: '<S17>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S20>/In1' incorporates:
    //   Outport: '<S20>/Out1'

    motion_controller_withPIC_B.In1_je = motion_controller_withPIC_P.Out1_Y0_i;

    // End of SystemInitialize for SubSystem: '<S17>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S18>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S21>/In1' incorporates:
    //   Outport: '<S21>/Out1'

    motion_controller_withPIC_B.In1_f = motion_controller_withPIC_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: '<S18>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S55>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S58>/In1' incorporates:
    //   Outport: '<S58>/Out1'

    motion_controller_withPIC_B.In1_m = motion_controller_withPIC_P.Out1_Y0_f;

    // End of SystemInitialize for SubSystem: '<S55>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<S19>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S22>/In1' incorporates:
    //   Outport: '<S22>/Out1'

    motion_controller_withPIC_B.In1_j = motion_controller_withPIC_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S19>/Enabled Subsystem'

    // SystemInitialize for Enabled SubSystem: '<Root>/picController'
    // InitializeConditions for UnitDelay: '<S10>/Unit Delay'
    motion_controller_withPIC_DW.UnitDelay_DSTATE =
      motion_controller_withPIC_P.UnitDelay_InitialCondition;

    // InitializeConditions for UnitDelay: '<S10>/Unit Delay1'
    motion_controller_withPIC_DW.UnitDelay1_DSTATE =
      motion_controller_withPIC_P.UnitDelay1_InitialCondition;

    // SystemInitialize for IfAction SubSystem: '<S46>/If Action Subsystem'
    // SystemInitialize for MATLAB Function: '<S48>/solvex'
    motion_controller_withPIC_DW.opts = tmp;

    // End of SystemInitialize for SubSystem: '<S46>/If Action Subsystem'

    // SystemInitialize for IfAction SubSystem: '<S46>/If Action Subsystem1'
    // SystemInitialize for MATLAB Function: '<S49>/solvex'
    motion_controller_withPIC_DW.opts_j = tmp;

    // End of SystemInitialize for SubSystem: '<S46>/If Action Subsystem1'

    // SystemInitialize for Merge: '<S46>/Merge'
    motion_controller_withPIC_B.Merge[0] =
      motion_controller_withPIC_P.Merge_InitialOutput;
    motion_controller_withPIC_B.Merge[1] =
      motion_controller_withPIC_P.Merge_InitialOutput;
    motion_controller_withPIC_B.Merge[2] =
      motion_controller_withPIC_P.Merge_InitialOutput;
    motion_controller_withPIC_B.Merge[3] =
      motion_controller_withPIC_P.Merge_InitialOutput;

    // Start for MATLABSystem: '<S10>/Get Parameter'
    motion_controller_withPIC_DW.obj_p.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_p.isInitialized = 1;
    ParamGet_motion_controller_withPIC_637.initParam(&prmName_p[0]);
    ParamGet_motion_controller_withPIC_637.setInitialValue(0.515);
    motion_controller_withPIC_DW.obj_p.isSetupComplete = true;

    // Start for MATLABSystem: '<S10>/Get Parameter1'
    motion_controller_withPIC_DW.obj_l.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_l.isInitialized = 1;
    ParamGet_motion_controller_withPIC_709.initParam(&prmName_q[0]);
    ParamGet_motion_controller_withPIC_709.setInitialValue(true);
    motion_controller_withPIC_DW.obj_l.isSetupComplete = true;

    // Start for MATLABSystem: '<S10>/Get Parameter6'
    motion_controller_withPIC_DW.obj.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj.isInitialized = 1;
    ParamGet_motion_controller_withPIC_556.initParam(&prmName_r[0]);
    ParamGet_motion_controller_withPIC_556.setInitialValue(0.0279);
    motion_controller_withPIC_DW.obj.isSetupComplete = true;

    // SystemInitialize for Outport: '<S10>/Ay_check'
    motion_controller_withPIC_B.Ay = motion_controller_withPIC_P.Ay_check_Y0;

    // End of SystemInitialize for SubSystem: '<Root>/picController'

    // SystemInitialize for Enabled SubSystem: '<S56>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S59>/In1' incorporates:
    //   Outport: '<S59>/Out1'

    motion_controller_withPIC_B.In1 = motion_controller_withPIC_P.Out1_Y0_k;

    // End of SystemInitialize for SubSystem: '<S56>/Enabled Subsystem'

    // SystemInitialize for Atomic SubSystem: '<Root>/controller'
    // SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S9>/get_effort' incorporates:
    //   SubSystem: '<S9>/get_effort'

    motion_controll_get_effort_Init();

    // End of SystemInitialize for S-Function (sfun_private_function_caller) generated from: '<S9>/get_effort' 

    // Start for MATLABSystem: '<S33>/Get Parameter4'
    motion_controller_withPIC_DW.obj_e.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_e.isInitialized = 1;
    ParamGet_motion_controller_withPIC_298.initParam(&prmName[0]);
    ParamGet_motion_controller_withPIC_298.setInitialValue(0.0);
    motion_controller_withPIC_DW.obj_e.isSetupComplete = true;

    // Start for MATLABSystem: '<S33>/Get Parameter2'
    motion_controller_withPIC_DW.obj_c.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_c.isInitialized = 1;
    ParamGet_motion_controller_withPIC_301.initParam(&prmName_0[0]);
    ParamGet_motion_controller_withPIC_301.setInitialValue(false);
    motion_controller_withPIC_DW.obj_c.isSetupComplete = true;

    // Start for MATLABSystem: '<S33>/Get Parameter3'
    motion_controller_withPIC_DW.obj_l4.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_l4.isInitialized = 1;
    ParamGet_motion_controller_withPIC_194.initParam(&prmName_1[0]);
    ParamGet_motion_controller_withPIC_194.setInitialValue(1.0);
    motion_controller_withPIC_DW.obj_l4.isSetupComplete = true;

    // Start for MATLABSystem: '<S33>/Get Parameter5'
    motion_controller_withPIC_DW.obj_g.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_g.isInitialized = 1;
    ParamGet_motion_controller_withPIC_329.initParam(&prmName_2[0]);
    ParamGet_motion_controller_withPIC_329.setInitialValue(true);
    motion_controller_withPIC_DW.obj_g.isSetupComplete = true;

    // Start for MATLABSystem: '<S33>/Get Parameter1'
    motion_controller_withPIC_DW.obj_o.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_o.isInitialized = 1;
    ParamGet_motion_controller_withPIC_317.initParam(&prmName_3[0]);
    ParamGet_motion_controller_withPIC_317.setInitialValue(0.0);
    motion_controller_withPIC_DW.obj_o.isSetupComplete = true;

    // Start for MATLABSystem: '<S33>/Get Parameter'
    motion_controller_withPIC_DW.obj_m.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_m.isInitialized = 1;
    ParamGet_motion_controller_withPIC_316.initParam(&prmName_4[0]);
    ParamGet_motion_controller_withPIC_316.setInitialValue(0.515);
    motion_controller_withPIC_DW.obj_m.isSetupComplete = true;

    // Start for MATLABSystem: '<S9>/Get Parameter1'
    motion_controller_withPIC_DW.obj_f.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_f.isInitialized = 1;
    ParamGet_motion_controller_withPIC_217.initParam(&prmName_5[0]);
    ParamGet_motion_controller_withPIC_217.setInitialValue(1.0);
    motion_controller_withPIC_DW.obj_f.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<Root>/controller'

    // SystemInitialize for Enabled SubSystem: '<Root>/cmd_pub'
    motion_control_CurrentTime_Init(&motion_controller_withPIC_DW.CurrentTime1);

    // Start for MATLABSystem: '<S28>/SinkBlock'
    motion_co_SystemCore_setup_fxdc(&motion_controller_withPIC_DW.obj_bq);
    motion_control_CurrentTime_Init(&motion_controller_withPIC_DW.CurrentTime);

    // Start for MATLABSystem: '<S29>/SinkBlock'
    motion_c_SystemCore_setup_fxdcj(&motion_controller_withPIC_DW.obj_ca);

    // End of SystemInitialize for SubSystem: '<Root>/cmd_pub'

    // Start for MATLABSystem: '<S17>/SourceBlock'
    motion_contr_SystemCore_setup_f(&motion_controller_withPIC_DW.obj_az);

    // Start for MATLABSystem: '<S18>/SourceBlock'
    motion_cont_SystemCore_setup_fx(&motion_controller_withPIC_DW.obj_en);

    // Start for MATLABSystem: '<S55>/SourceBlock'
    motion__SystemCore_setup_fxdcji(&motion_controller_withPIC_DW.obj_nf);

    // Start for MATLABSystem: '<Root>/Get Parameter7'
    motion_controller_withPIC_DW.obj_b.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_b.isInitialized = 1;
    ParamGet_motion_controller_withPIC_605.initParam(&prmName_6[0]);
    ParamGet_motion_controller_withPIC_605.setInitialValue(0.28);
    motion_controller_withPIC_DW.obj_b.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter8'
    motion_controller_withPIC_DW.obj_k.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_k.isInitialized = 1;
    ParamGet_motion_controller_withPIC_606.initParam(&prmName_7[0]);
    ParamGet_motion_controller_withPIC_606.setInitialValue(0.0045);
    motion_controller_withPIC_DW.obj_k.isSetupComplete = true;

    // Start for MATLABSystem: '<S19>/SourceBlock'
    motion_con_SystemCore_setup_fxd(&motion_controller_withPIC_DW.obj_dp);

    // Start for MATLABSystem: '<Root>/Get Parameter'
    motion_controller_withPIC_DW.obj_ay.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_ay.isInitialized = 1;
    ParamGet_motion_controller_withPIC_557.initParam(&prmName_8[0]);
    ParamGet_motion_controller_withPIC_557.setInitialValue(40.0);
    motion_controller_withPIC_DW.obj_ay.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter1'
    motion_controller_withPIC_DW.obj_hm.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_hm.isInitialized = 1;
    ParamGet_motion_controller_withPIC_558.initParam(&prmName_9[0]);
    ParamGet_motion_controller_withPIC_558.setInitialValue(2.0);
    motion_controller_withPIC_DW.obj_hm.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter2'
    motion_controller_withPIC_DW.obj_di.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_di.isInitialized = 1;
    ParamGet_motion_controller_withPIC_559.initParam(&prmName_a[0]);
    ParamGet_motion_controller_withPIC_559.setInitialValue(40.0);
    motion_controller_withPIC_DW.obj_di.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter3'
    motion_controller_withPIC_DW.obj_pw.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_pw.isInitialized = 1;
    ParamGet_motion_controller_withPIC_560.initParam(&prmName_b[0]);
    ParamGet_motion_controller_withPIC_560.setInitialValue(2.0);
    motion_controller_withPIC_DW.obj_pw.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter4'
    motion_controller_withPIC_DW.obj_ny.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_ny.isInitialized = 1;
    ParamGet_motion_controller_withPIC_561.initParam(&prmName_c[0]);
    ParamGet_motion_controller_withPIC_561.setInitialValue(2.0);
    motion_controller_withPIC_DW.obj_ny.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter5'
    motion_controller_withPIC_DW.obj_j.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_j.isInitialized = 1;
    ParamGet_motion_controller_withPIC_562.initParam(&prmName_d[0]);
    ParamGet_motion_controller_withPIC_562.setInitialValue(5.0);
    motion_controller_withPIC_DW.obj_j.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter15'
    motion_controller_withPIC_DW.obj_kx.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_kx.isInitialized = 1;
    ParamGet_motion_controller_withPIC_631.initParam(&prmName_e[0]);
    ParamGet_motion_controller_withPIC_631.setInitialValue(2.0);
    motion_controller_withPIC_DW.obj_kx.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter16'
    motion_controller_withPIC_DW.obj_ma.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_ma.isInitialized = 1;
    ParamGet_motion_controller_withPIC_632.initParam(&prmName_f[0]);
    ParamGet_motion_controller_withPIC_632.setInitialValue(5.0);
    motion_controller_withPIC_DW.obj_ma.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter9'
    motion_controller_withPIC_DW.obj_n.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_n.isInitialized = 1;
    ParamGet_motion_controller_withPIC_614.initParam(&prmName_g[0]);
    ParamGet_motion_controller_withPIC_614.setInitialValue(-49.824);
    motion_controller_withPIC_DW.obj_n.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter10'
    motion_controller_withPIC_DW.obj_ba.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_ba.isInitialized = 1;
    ParamGet_motion_controller_withPIC_615.initParam(&prmName_h[0]);
    ParamGet_motion_controller_withPIC_615.setInitialValue(1.128);
    motion_controller_withPIC_DW.obj_ba.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter11'
    motion_controller_withPIC_DW.obj_ff.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_ff.isInitialized = 1;
    ParamGet_motion_controller_withPIC_616.initParam(&prmName_i[0]);
    ParamGet_motion_controller_withPIC_616.setInitialValue(0.431);
    motion_controller_withPIC_DW.obj_ff.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter12'
    motion_controller_withPIC_DW.obj_co.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_co.isInitialized = 1;
    ParamGet_motion_controller_withPIC_617.initParam(&prmName_j[0]);
    ParamGet_motion_controller_withPIC_617.setInitialValue(-40.215);
    motion_controller_withPIC_DW.obj_co.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter13'
    motion_controller_withPIC_DW.obj_e5.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_e5.isInitialized = 1;
    ParamGet_motion_controller_withPIC_618.initParam(&prmName_k[0]);
    ParamGet_motion_controller_withPIC_618.setInitialValue(1.177);
    motion_controller_withPIC_DW.obj_e5.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Get Parameter14'
    motion_controller_withPIC_DW.obj_h.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_h.isInitialized = 1;
    ParamGet_motion_controller_withPIC_619.initParam(&prmName_l[0]);
    ParamGet_motion_controller_withPIC_619.setInitialValue(0.399);
    motion_controller_withPIC_DW.obj_h.isSetupComplete = true;

    // Start for MATLABSystem: '<S13>/SinkBlock'
    motion_control_SystemCore_setup(&motion_controller_withPIC_DW.obj_ng);

    // Start for MATLABSystem: '<S56>/SourceBlock'
    motion_SystemCore_setup_fxdcjik(&motion_controller_withPIC_DW.obj_mo);

    // Start for MATLABSystem: '<S6>/Get Parameter3'
    motion_controller_withPIC_DW.obj_p3.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_p3.isInitialized = 1;
    ParamGet_motion_controller_withPIC_621.initParam(&prmName_m[0]);
    ParamGet_motion_controller_withPIC_621.setInitialValue(1.0);
    motion_controller_withPIC_DW.obj_p3.isSetupComplete = true;

    // Start for MATLABSystem: '<S6>/Get Parameter1'
    motion_controller_withPIC_DW.obj_i.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_i.isInitialized = 1;
    ParamGet_motion_controller_withPIC_625.initParam(&prmName_n[0]);
    ParamGet_motion_controller_withPIC_625.setInitialValue(false);
    motion_controller_withPIC_DW.obj_i.isSetupComplete = true;

    // Start for MATLABSystem: '<S6>/Get Parameter2'
    motion_controller_withPIC_DW.obj_ls.matlabCodegenIsDeleted = false;
    motion_controller_withPIC_DW.obj_ls.isInitialized = 1;
    ParamGet_motion_controller_withPIC_629.initParam(&prmName_o[0]);
    ParamGet_motion_controller_withPIC_629.setInitialValue(false);
    motion_controller_withPIC_DW.obj_ls.isSetupComplete = true;
  }
}

// Model terminate function
void motion_controller_withPIC::terminate()
{
  // Terminate for MATLABSystem: '<S17>/SourceBlock'
  if (!motion_controller_withPIC_DW.obj_az.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_az.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S17>/SourceBlock'

  // Terminate for MATLABSystem: '<S18>/SourceBlock'
  if (!motion_controller_withPIC_DW.obj_en.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_en.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S18>/SourceBlock'

  // Terminate for MATLABSystem: '<S55>/SourceBlock'
  if (!motion_controller_withPIC_DW.obj_nf.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_nf.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S55>/SourceBlock'

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

  // Terminate for MATLABSystem: '<S19>/SourceBlock'
  if (!motion_controller_withPIC_DW.obj_dp.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_dp.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S19>/SourceBlock'

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
  if (!motion_controller_withPIC_DW.obj_h.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<Root>/Get Parameter14'

  // Terminate for Enabled SubSystem: '<Root>/picController'
  // Terminate for MATLABSystem: '<S10>/Get Parameter'
  if (!motion_controller_withPIC_DW.obj_p.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/Get Parameter'

  // Terminate for MATLABSystem: '<S10>/Get Parameter1'
  if (!motion_controller_withPIC_DW.obj_l.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/Get Parameter1'

  // Terminate for MATLABSystem: '<S10>/Get Parameter6'
  if (!motion_controller_withPIC_DW.obj.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/Get Parameter6'
  // End of Terminate for SubSystem: '<Root>/picController'

  // Terminate for MATLABSystem: '<S13>/SinkBlock'
  if (!motion_controller_withPIC_DW.obj_ng.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_ng.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S13>/SinkBlock'

  // Terminate for MATLABSystem: '<S56>/SourceBlock'
  if (!motion_controller_withPIC_DW.obj_mo.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_mo.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S56>/SourceBlock'

  // Terminate for Atomic SubSystem: '<Root>/controller'
  // Terminate for MATLABSystem: '<S33>/Get Parameter4'
  if (!motion_controller_withPIC_DW.obj_e.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S33>/Get Parameter4'

  // Terminate for MATLABSystem: '<S33>/Get Parameter2'
  if (!motion_controller_withPIC_DW.obj_c.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S33>/Get Parameter2'

  // Terminate for MATLABSystem: '<S33>/Get Parameter3'
  if (!motion_controller_withPIC_DW.obj_l4.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_l4.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S33>/Get Parameter3'

  // Terminate for MATLABSystem: '<S33>/Get Parameter5'
  if (!motion_controller_withPIC_DW.obj_g.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S33>/Get Parameter5'

  // Terminate for MATLABSystem: '<S33>/Get Parameter1'
  if (!motion_controller_withPIC_DW.obj_o.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S33>/Get Parameter1'

  // Terminate for MATLABSystem: '<S33>/Get Parameter'
  if (!motion_controller_withPIC_DW.obj_m.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S33>/Get Parameter'

  // Terminate for MATLABSystem: '<S9>/Get Parameter1'
  if (!motion_controller_withPIC_DW.obj_f.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/Get Parameter1'

  // Terminate for S-Function (sfun_private_function_caller) generated from: '<S9>/get_effort' incorporates:
  //   SubSystem: '<S9>/get_effort'

  motion_controll_get_effort_Term();

  // End of Terminate for S-Function (sfun_private_function_caller) generated from: '<S9>/get_effort' 
  // End of Terminate for SubSystem: '<Root>/controller'

  // Terminate for MATLABSystem: '<S6>/Get Parameter3'
  if (!motion_controller_withPIC_DW.obj_p3.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_p3.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/Get Parameter3'

  // Terminate for MATLABSystem: '<S6>/Get Parameter1'
  if (!motion_controller_withPIC_DW.obj_i.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/Get Parameter1'

  // Terminate for MATLABSystem: '<S6>/Get Parameter2'
  if (!motion_controller_withPIC_DW.obj_ls.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_ls.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/Get Parameter2'

  // Terminate for Enabled SubSystem: '<Root>/cmd_pub'
  motion_control_CurrentTime_Term(&motion_controller_withPIC_DW.CurrentTime1);

  // Terminate for MATLABSystem: '<S28>/SinkBlock'
  if (!motion_controller_withPIC_DW.obj_bq.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_bq.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S28>/SinkBlock'
  motion_control_CurrentTime_Term(&motion_controller_withPIC_DW.CurrentTime);

  // Terminate for MATLABSystem: '<S29>/SinkBlock'
  if (!motion_controller_withPIC_DW.obj_ca.matlabCodegenIsDeleted) {
    motion_controller_withPIC_DW.obj_ca.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S29>/SinkBlock'
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
