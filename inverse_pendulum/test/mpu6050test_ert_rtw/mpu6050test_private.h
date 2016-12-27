/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mpu6050test_private.h
 *
 * Code generated for Simulink model 'mpu6050test'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Wed Dec 21 17:09:46 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_mpu6050test_private_h_
#define RTW_HEADER_mpu6050test_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

extern void MPU6050_Outputs_wrapper(real_T *roll,
  real_T *pitch,
  real_T *yaw,
  const real_T *xD);
extern void MPU6050_Update_wrapper(real_T *roll,
  real_T *pitch,
  real_T *yaw,
  real_T *xD);

#endif                                 /* RTW_HEADER_mpu6050test_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
