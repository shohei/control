/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sensorTest_private.h
 *
 * Code generated for Simulink model 'sensorTest'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Fri Dec 23 10:33:40 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_sensorTest_private_h_
#define RTW_HEADER_sensorTest_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

extern void mpu6050_2_Outputs_wrapper(real_T *y0,
  const real_T *xD);
extern void mpu6050_2_Update_wrapper(real_T *y0,
  real_T *xD);

#endif                                 /* RTW_HEADER_sensorTest_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
