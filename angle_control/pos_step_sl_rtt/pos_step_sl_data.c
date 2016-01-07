/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pos_step_sl_data.c
 *
 * Code generated for Simulink model 'pos_step_sl'.
 *
 * Model version                  : 1.36
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 19 2015)
 * C/C++ source code generated on : Tue Dec 29 20:59:24 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "pos_step_sl.h"
#include "pos_step_sl_private.h"

/* Block parameters (auto storage) */
P_pos_step_sl_T pos_step_sl_P = {
  0.12,                                /* Variable: Kp_id
                                        * Referenced by: '<Root>/Gain'
                                        */
  60.0,                                /* Variable: r
                                        * Referenced by: '<Root>/Constant'
                                        */
  3U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S2>/PWM'
                                        */
  5U,                                  /* Mask Parameter: PWM_pinNumber_f
                                        * Referenced by: '<S3>/PWM'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  500.0,                               /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  250.0,                               /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  -2.5,                                /* Expression: -2.5
                                        * Referenced by: '<S1>/Constant'
                                        */
  57.3,                                /* Expression: (42/42)*57.3
                                        * Referenced by: '<S1>/Gain3'
                                        */
  51.0,                                /* Expression: 255/5
                                        * Referenced by: '<S1>/Gain'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S1>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Saturation'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<S1>/Gain1'
                                        */
  255.0,                               /* Expression: 255
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  0U,                                  /* Computed Parameter: AnalogInput_p1
                                        * Referenced by: '<S1>/Analog Input'
                                        */
  40960U                               /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S1>/Gain2'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
