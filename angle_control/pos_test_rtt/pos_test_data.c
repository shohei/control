/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pos_test_data.c
 *
 * Code generated for Simulink model 'pos_test'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 19 2015)
 * C/C++ source code generated on : Tue Dec 29 16:58:56 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "pos_test.h"
#include "pos_test_private.h"

/* Block parameters (auto storage) */
P_pos_test_T pos_test_P = {
  3U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S1>/PWM'
                                        */
  5U,                                  /* Mask Parameter: PWM_pinNumber_p
                                        * Referenced by: '<S2>/PWM'
                                        */
  -2.5,                                /* Expression: -2.5
                                        * Referenced by: '<Root>/Constant'
                                        */
  57.324,                              /* Expression: 57.324
                                        * Referenced by: '<Root>/Gain3'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Constant1'
                                        */
  51.0,                                /* Expression: 255/5
                                        * Referenced by: '<Root>/Gain'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<Root>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Gain1'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  1U,                                  /* Computed Parameter: AnalogInput_p1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
  40960U                               /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<Root>/Gain2'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
