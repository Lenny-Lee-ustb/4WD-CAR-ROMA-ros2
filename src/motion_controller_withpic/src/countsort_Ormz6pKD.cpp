//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: countsort_Ormz6pKD.cpp
//
// Code generated for Simulink model 'motion_controller_withPIC'.
//
// Model version                  : 2.322
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sat Jan  4 16:50:06 2025
//
#include "rtwtypes.h"
#include "countsort_Ormz6pKD.h"
#include <string.h>

// Function for MATLAB Function: '<S48>/solvex'
void countsort_Ormz6pKD(int32_T x[161], int32_T xLen, int32_T workspace[161],
  int32_T xMin, int32_T xMax)
{
  if ((xLen > 1) && (xMax > xMin)) {
    int32_T b_tmp;
    int32_T idxEnd;
    int32_T idxFill;
    int32_T idxStart;
    int32_T maxOffset;
    b_tmp = xMax - xMin;
    if (b_tmp >= 0) {
      memset(&workspace[0], 0, static_cast<uint32_T>(b_tmp + 1) * sizeof(int32_T));
    }

    maxOffset = b_tmp - 1;
    for (b_tmp = 0; b_tmp < xLen; b_tmp++) {
      idxFill = x[b_tmp] - xMin;
      workspace[idxFill]++;
    }

    for (b_tmp = 2; b_tmp <= maxOffset + 2; b_tmp++) {
      workspace[b_tmp - 1] += workspace[b_tmp - 2];
    }

    idxStart = 1;
    idxEnd = workspace[0];
    for (b_tmp = 0; b_tmp <= maxOffset; b_tmp++) {
      for (idxFill = idxStart; idxFill <= idxEnd; idxFill++) {
        x[idxFill - 1] = b_tmp + xMin;
      }

      idxStart = workspace[b_tmp] + 1;
      idxEnd = workspace[b_tmp + 1];
    }

    for (maxOffset = idxStart; maxOffset <= idxEnd; maxOffset++) {
      x[maxOffset - 1] = xMax;
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
