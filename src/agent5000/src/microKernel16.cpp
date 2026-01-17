//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: microKernel16.cpp
//
// Code generated for Simulink model 'motion_controller_withTD3'.
//
// Model version                  : 2.374
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Fri Apr  4 17:03:09 2025
//
#include "rtwtypes.h"
#include "microKernel16.h"

void microKernel16(int32_T K, const real32_T *A, int32_T LDA, const real32_T *B,
                   real32_T *C)
{
  int32_T idxA;
  int32_T idxB;
  real32_T c;
  idxA = 0;
  idxB = 0;
  c = C[0];
  for (int32_T k = 0; k < K; k++) {
    real32_T a;
    real32_T bTemp;
    a = A[idxA];
    bTemp = B[idxB];
    c += a * bTemp;
    idxA += LDA;
    idxB++;
  }

  C[0] = c;
}

//
// File trailer for generated code.
//
// [EOF]
//
