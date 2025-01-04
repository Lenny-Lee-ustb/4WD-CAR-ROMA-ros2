//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: strcmp_1LovgLAH.cpp
//
// Code generated for Simulink model 'motion_controller_withPIC'.
//
// Model version                  : 2.322
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Sat Jan  4 16:50:06 2025
//
#include "rtwtypes.h"
#include "strcmp_1LovgLAH.h"

// Function for MATLAB Function: '<S48>/solvex'
boolean_T strcmp_1LovgLAH(const char_T a[8])
{
  int32_T kstr;
  boolean_T b_bool;
  static const char_T b[128] = { '\x00', '\x01', '\x02', '\x03', '\x04', '\x05',
    '\x06', '\a', '\b', '\t', '\n', '\v', '\f', '\r', '\x0e', '\x0f', '\x10',
    '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19',
    '\x1a', '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!', '\"', '#', '$',
    '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'a', 'b',
    'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
    'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '[', '\\', ']', '^', '_', '`',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
    'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~',
    '\x7f' };

  static const char_T c[8] = { 'q', 'u', 'a', 'd', 'p', 'r', 'o', 'g' };

  b_bool = false;
  kstr = 0;
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (kstr < 8) {
      if (b[static_cast<int32_T>(a[kstr])] != b[static_cast<int32_T>(c[kstr])])
      {
        exitg1 = 1;
      } else {
        kstr++;
      }
    } else {
      b_bool = true;
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  return b_bool;
}

//
// File trailer for generated code.
//
// [EOF]
//
