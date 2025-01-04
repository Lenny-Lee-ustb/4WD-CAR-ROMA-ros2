//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xgemv_WOwAYNtc.cpp
//
// Code generated for Simulink model 'motion_controller_withPIC'.
//
// Model version                  : 2.283
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Thu Dec 26 20:03:10 2024
//
#include "rtwtypes.h"
#include "xgemv_WOwAYNtc.h"
#include <emmintrin.h>
#include "div_nde_s32_floor.h"

// Function for MATLAB Function: '<S10>/solvex'
void xgemv_WOwAYNtc(int32_T m, const real_T A[840], const real_T x[21], real_T
                    y[81])
{
  for (int32_T b_iy = 0; b_iy <= 38; b_iy += 2) {
    __m128d tmp;
    tmp = _mm_loadu_pd(&y[b_iy]);
    _mm_storeu_pd(&y[b_iy], _mm_mul_pd(tmp, _mm_set1_pd(-1.0)));
  }

  for (int32_T b_iy = 0; b_iy <= 819; b_iy += 21) {
    real_T c;
    int32_T b;
    int32_T ia;
    c = 0.0;
    b = b_iy + m;
    for (ia = b_iy + 1; ia <= b; ia++) {
      c += x[(ia - b_iy) - 1] * A[ia - 1];
    }

    ia = div_nde_s32_floor(b_iy, 21);
    y[ia] += c;
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
