/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motorTest_private.h
 *
 * Code generated for Simulink model 'motorTest'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Tue Dec 27 10:46:08 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_motorTest_private_h_
#define RTW_HEADER_motorTest_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

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

#endif                                 /* RTW_HEADER_motorTest_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
