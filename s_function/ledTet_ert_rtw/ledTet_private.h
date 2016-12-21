/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ledTet_private.h
 *
 * Code generated for Simulink model 'ledTet'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Mon Dec 19 18:24:14 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ledTet_private_h_
#define RTW_HEADER_ledTet_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif

extern void led_Outputs_wrapper(const int8_T *ledPin,
  const real_T *xD);
extern void led_Update_wrapper(const int8_T *ledPin,
  real_T *xD);

#endif                                 /* RTW_HEADER_ledTet_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
