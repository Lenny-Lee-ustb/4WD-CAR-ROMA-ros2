//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xgemv_DWEvxrPL.cpp
//
// Code generated for Simulink model 'motion_controller_withPIC'.
//
// Model version                  : 2.322
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sat Jan  4 16:50:06 2025
//
#include "rtwtypes.h"
#include "xgemv_DWEvxrPL.h"
#include <string.h>

// Function for MATLAB Function: '<S48>/solvex'
void xgemv_DWEvxrPL(int32_T m, int32_T n, const real_T A[1600], int32_T lda,
                    const real_T x[41], real_T y[40])
{
  if ((m != 0) && (n != 0)) {
    int32_T c;
    int32_T ix;
    memset(&y[0], 0, static_cast<uint8_T>(m) * sizeof(real_T));
    ix = 0;
    c = (n - 1) * lda + 1;
    for (int32_T b_iy = 1; lda < 0 ? b_iy >= c : b_iy <= c; b_iy += lda) {
      int32_T d;
      d = (b_iy + m) - 1;
      for (int32_T b = b_iy; b <= d; b++) {
        int32_T tmp;
        tmp = b - b_iy;
        y[tmp] += A[b - 1] * x[ix];
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
