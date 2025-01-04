//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xgemv_L5SThEQW.cpp
//
// Code generated for Simulink model 'motion_controller_withPIC'.
//
// Model version                  : 2.322
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sat Jan  4 16:50:06 2025
//
#include "rtwtypes.h"
#include "xgemv_L5SThEQW.h"
#include <string.h>

// Function for MATLAB Function: '<S48>/solvex'
void xgemv_L5SThEQW(int32_T m, int32_T n, const real_T A[1681], int32_T ia0,
                    const real_T x[6601], real_T y[41])
{
  if (m != 0) {
    int32_T b;
    int32_T ix;
    memset(&y[0], 0, static_cast<uint32_T>(m) * sizeof(real_T));
    ix = 0;
    b = (n - 1) * 41 + ia0;
    for (int32_T b_iy = ia0; b_iy <= b; b_iy += 41) {
      int32_T c;
      c = (b_iy + m) - 1;
      for (int32_T ia = b_iy; ia <= c; ia++) {
        int32_T tmp;
        tmp = ia - b_iy;
        y[tmp] += A[ia - 1] * x[ix];
      }

      ix++;
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
