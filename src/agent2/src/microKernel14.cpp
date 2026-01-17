//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: microKernel14.cpp
//
// Code generated for Simulink model 'agent2'.
//
// Model version                  : 2.413
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sat Jan 17 22:00:06 2026
//
#include "rtwtypes.h"
#include "microKernel14.h"
#include <xmmintrin.h>

void microKernel14(int32_T K, real32_T *A, int32_T LDA, const real32_T *B,
                   real32_T *C)
{
  __m128 c;
  __m128 c_0;
  __m128 c_1;
  __m128 c_2;
  int32_T idxA;
  int32_T idxB;
  idxA = 4;
  idxB = 0;
  c = _mm_loadu_ps(&C[0]);
  c_0 = _mm_loadu_ps(&C[4]);
  c_1 = _mm_loadu_ps(&C[8]);
  c_2 = _mm_loadu_ps(&C[12]);
  for (int32_T k = 0; k < K; k++) {
    __m128 a;
    __m128 a_0;
    __m128 a_1;
    __m128 a_2;
    __m128 b;
    real32_T bTemp;
    a = _mm_loadu_ps(&A[idxA - 4]);
    a_0 = _mm_loadu_ps(&A[idxA]);
    a_1 = _mm_loadu_ps(&A[idxA + 4]);
    a_2 = _mm_loadu_ps(&A[idxA + 8]);
    bTemp = B[idxB];
    b = _mm_set1_ps(bTemp);
    c = _mm_add_ps(c, _mm_mul_ps(a, b));
    c_0 = _mm_add_ps(c_0, _mm_mul_ps(a_0, b));
    c_1 = _mm_add_ps(c_1, _mm_mul_ps(a_1, b));
    c_2 = _mm_add_ps(c_2, _mm_mul_ps(a_2, b));
    idxA += LDA;
    idxB++;
  }

  _mm_storeu_ps(&C[0], c);
  _mm_storeu_ps(&C[4], c_0);
  _mm_storeu_ps(&C[8], c_1);
  _mm_storeu_ps(&C[12], c_2);
}

//
// File trailer for generated code.
//
// [EOF]
//
