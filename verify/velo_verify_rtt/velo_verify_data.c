/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: velo_verify_data.c
 *
 * Code generated for Simulink model 'velo_verify'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 19 2015)
 * C/C++ source code generated on : Wed Dec 23 15:43:08 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "velo_verify.h"
#include "velo_verify_private.h"

/* Block parameters (auto storage) */
P_velo_verify_T velo_verify_P = {
  1.5,                                 /* Variable: u_offset
                                        * Referenced by: '<Root>/Constant1'
                                        */
  9U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S2>/PWM'
                                        */
  10.0,                                /* Expression: 10
                                        * Referenced by: '<Root>/Step'
                                        */
  1.5,                                 /* Expression: 1.5
                                        * Referenced by: '<Root>/Step'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<Root>/Step'
                                        */
  -5.999988000024,                     /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  11.424403151193697,                  /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  51.0,                                /* Expression: 255/5
                                        * Referenced by: '<S1>/Gain'
                                        */
  5U,                                  /* Computed Parameter: AnalogInput_p1
                                        * Referenced by: '<S1>/Analog Input'
                                        */
  41000U                               /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<S1>/Gain1'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
