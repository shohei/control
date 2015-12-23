/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: velo_tc_data.c
 *
 * Code generated for Simulink model 'velo_tc'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 19 2015)
 * C/C++ source code generated on : Tue Dec 22 21:20:16 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "velo_tc.h"
#include "velo_tc_private.h"

/* Block parameters (auto storage) */
P_velo_tc_T velo_tc_P = {
  2.5,                                 /* Variable: p_const
                                        * Referenced by: '<Root>/Step1'
                                        */
  1.8,                                 /* Variable: r_const
                                        * Referenced by: '<Root>/Step1'
                                        */
  10.0,                                /* Variable: s_time
                                        * Referenced by: '<Root>/Step1'
                                        */
  2.0,                                 /* Variable: u_ini
                                        * Referenced by: '<Root>/Constant1'
                                        */
  9U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S2>/PWM'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
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
