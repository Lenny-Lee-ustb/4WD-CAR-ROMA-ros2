//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: microKernel13.cpp
//
// Code generated for Simulink model 'motion_controller_withTD3'.
//
// Model version                  : 2.374
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Fri Apr  4 17:03:09 2025
//
#include "rtwtypes.h"
#include "microKernel13.h"

void microKernel13(int32_T K, const real32_T *A, int32_T LDA, const real32_T *B,
                   int32_T LDB, real32_T *C, int32_T LDC)
{
  int32_T c_tmp;
  int32_T idxA;
  int32_T idxB;
  real32_T c;
  real32_T c_0;
  real32_T c_1;
  real32_T c_2;
  idxA = 0;
  idxB = 0;
  c = C[0];
  c_0 = C[LDC];
  c_tmp = LDC << 1;
  c_1 = C[c_tmp];
  c_2 = C[LDC * 3];
  for (int32_T k = 0; k < K; k++) {
    real32_T a;
    real32_T bTemp;
    real32_T bTemp_0;
    real32_T bTemp_1;
    real32_T bTemp_2;
    a = A[idxA];
    bTemp = B[idxB];
    bTemp_0 = B[idxB + LDB];
    bTemp_1 = B[(LDB << 1) + idxB];
    bTemp_2 = B[LDB * 3 + idxB];
    c += a * bTemp;
    c_0 += a * bTemp_0;
    c_1 += a * bTemp_1;
    c_2 += a * bTemp_2;
    idxA += LDA;
    idxB++;
  }

  C[0] = c;
  C[LDC] = c_0;
  C[c_tmp] = c_1;
  C[LDC * 3] = c_2;
}

//
// File trailer for generated code.
//
// [EOF]
//
