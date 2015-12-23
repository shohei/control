/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: velo_pi_data.c
 *
 * Code generated for Simulink model 'velo_pi'.
 *
 * Model version                  : 1.42
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 19 2015)
 * C/C++ source code generated on : Wed Dec 23 16:42:38 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "velo_pi.h"
#include "velo_pi_private.h"

/* Block parameters (auto storage) */
P_velo_pi_T velo_pi_P = {
  22.408172804480504,                  /* Variable: Ki
                                        * Referenced by:
                                        *   '<Root>/Gain'
                                        *   '<Root>/Gain2'
                                        */
  2.2758311008360508,                  /* Variable: Kp
                                        * Referenced by:
                                        *   '<Root>/Gain1'
                                        *   '<Root>/Gain3'
                                        */
  1.5,                                 /* Variable: u_offset
                                        * Referenced by:
                                        *   '<Root>/Constant1'
                                        *   '<Root>/Constant2'
                                        */
  9U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S2>/PWM'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  200.0,                               /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  100.0,                               /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  2.0,                                 /* Expression: 2
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  -5.999988000024,                     /* Computed Parameter: TransferFcn_A
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  11.424403151193697,                  /* Computed Parameter: TransferFcn_C
                                        * Referenced by: '<Root>/Transfer Fcn'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Integrator1'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<Root>/Saturation'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
  51.0,                                /* Expression: 255/5
                                        * Referenced by: '<S1>/Gain'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Saturation1'
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
