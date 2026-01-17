//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: microKernel12.cpp
//
// Code generated for Simulink model 'motion_controller_withTD3'.
//
// Model version                  : 2.374
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Fri Apr  4 17:03:09 2025
//
#include "rtwtypes.h"
#include "microKernel12.h"
#include <xmmintrin.h>

void microKernel12(int32_T K, real32_T *A, int32_T LDA, const real32_T *B,
                   int32_T LDB, real32_T *C, int32_T LDC)
{
  __m128 c;
  __m128 c_0;
  __m128 c_1;
  __m128 c_2;
  int32_T c_tmp;
  int32_T idxA;
  int32_T idxB;
  idxA = 0;
  idxB = 0;
  c = _mm_loadu_ps(&C[0]);
  c_0 = _mm_loadu_ps(&C[LDC]);
  c_tmp = LDC << 1;
  c_1 = _mm_loadu_ps(&C[c_tmp]);
  c_2 = _mm_loadu_ps(&C[LDC * 3]);
  for (int32_T k = 0; k < K; k++) {
    __m128 a;
    real32_T bTemp;
    real32_T bTemp_0;
    real32_T bTemp_1;
    real32_T bTemp_2;
    a = _mm_loadu_ps(&A[idxA]);
    bTemp = B[idxB];
    bTemp_0 = B[idxB + LDB];
    bTemp_1 = B[(LDB << 1) + idxB];
    bTemp_2 = B[LDB * 3 + idxB];
    c = _mm_add_ps(c, _mm_mul_ps(a, _mm_set1_ps(bTemp)));
    c_0 = _mm_add_ps(c_0, _mm_mul_ps(a, _mm_set1_ps(bTemp_0)));
    c_1 = _mm_add_ps(c_1, _mm_mul_ps(a, _mm_set1_ps(bTemp_1)));
    c_2 = _mm_add_ps(c_2, _mm_mul_ps(a, _mm_set1_ps(bTemp_2)));
    idxA += LDA;
    idxB++;
  }

  _mm_storeu_ps(&C[0], c);
  _mm_storeu_ps(&C[LDC], c_0);
  _mm_storeu_ps(&C[c_tmp], c_1);
  _mm_storeu_ps(&C[LDC * 3], c_2);
}

//
// File trailer for generated code.
//
// [EOF]
//
