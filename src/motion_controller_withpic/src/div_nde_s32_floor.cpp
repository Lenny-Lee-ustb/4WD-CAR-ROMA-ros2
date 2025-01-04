//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: div_nde_s32_floor.cpp
//
// Code generated for Simulink model 'motion_controller_withPIC'.
//
// Model version                  : 2.283
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Thu Dec 26 20:03:10 2024
//
#include "div_nde_s32_floor.h"
#include "rtwtypes.h"

int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

//
// File trailer for generated code.
//
// [EOF]
//
