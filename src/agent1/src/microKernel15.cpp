//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: microKernel15.cpp
//
// Code generated for Simulink model 'motion_controller_withTD3'.
//
// Model version                  : 2.374
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Fri Apr  4 17:03:09 2025
//
#include "rtwtypes.h"
#include "microKernel15.h"
#include <xmmintrin.h>

void microKernel15(int32_T K, real32_T *A, int32_T LDA, const real32_T *B,
                   real32_T *C)
{
  __m128 c;
  int32_T idxA;
  int32_T idxB;
  idxA = 0;
  idxB = 0;
  c = _mm_loadu_ps(&C[0]);
  for (int32_T k = 0; k < K; k++) {
    __m128 a;
    real32_T bTemp;
    a = _mm_loadu_ps(&A[idxA]);
    bTemp = B[idxB];
    c = _mm_add_ps(c, _mm_mul_ps(a, _mm_set1_ps(bTemp)));
    idxA += LDA;
    idxB++;
  }

  _mm_storeu_ps(&C[0], c);
}

//
// File trailer for generated code.
//
// [EOF]
//
