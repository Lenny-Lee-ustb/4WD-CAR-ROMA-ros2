//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: TD3_final_private.h
//
// Code generated for Simulink model 'TD3_final'.
//
// Model version                  : 1.8
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Fri Jun 21 14:28:05 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_TD3_final_private_h_
#define RTW_HEADER_TD3_final_private_h_
#include "rtwtypes.h"
#include "TD3_final_types.h"
#include "TD3_final.h"

extern void microKernel16(int32_T K, const real32_T *A, int32_T LDA, const
  real32_T *B, real32_T *C);
extern void microKernel15(int32_T K, real32_T *A, int32_T LDA, const real32_T *B,
  real32_T *C);
extern void microKernel14(int32_T K, real32_T *A, int32_T LDA, const real32_T *B,
  real32_T *C);
extern void microKernel13(int32_T K, const real32_T *A, int32_T LDA, const
  real32_T *B, int32_T LDB, real32_T *C, int32_T LDC);
extern void microKernel12(int32_T K, real32_T *A, int32_T LDA, const real32_T *B,
  int32_T LDB, real32_T *C, int32_T LDC);
extern int32_T div_s32_floor(int32_T numerator, int32_T denominator);

#endif                                 // RTW_HEADER_TD3_final_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
