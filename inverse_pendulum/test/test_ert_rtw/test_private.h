/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test_private.h
 *
 * Code generated for Simulink model 'test'.
 *
 * Model version                  : 1.34
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Wed Dec 21 14:25:44 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_test_private_h_
#define RTW_HEADER_test_private_h_
#include "rtwtypes.h"

extern void motorDriver_Outputs_wrapper(const int8_T *speed1,
  const int8_T *speed2,
  const int8_T *direction1,
  const int8_T *direction2,
  const real_T *xD);
extern void motorDriver_Update_wrapper(const int8_T *speed1,
  const int8_T *speed2,
  const int8_T *direction1,
  const int8_T *direction2,
  real_T *xD);

#endif                                 /* RTW_HEADER_test_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
