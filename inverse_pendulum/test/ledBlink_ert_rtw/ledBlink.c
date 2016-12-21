/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ledBlink.c
 *
 * Code generated for Simulink model 'ledBlink'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Wed Dec 21 14:25:04 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ledBlink.h"
#include "ledBlink_private.h"

/* Block states (auto storage) */
DW_ledBlink_T ledBlink_DW;

/* Real-time model */
RT_MODEL_ledBlink_T ledBlink_M_;
RT_MODEL_ledBlink_T *const ledBlink_M = &ledBlink_M_;

/* Model step function */
void ledBlink_step(void)
{
  real_T rtb_PulseGenerator;
  uint8_T rtb_PulseGenerator_0;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (ledBlink_DW.clockTickCounter <
                        ledBlink_P.PulseGenerator_Duty) &&
    (ledBlink_DW.clockTickCounter >= 0L) ? ledBlink_P.PulseGenerator_Amp : 0.0;
  if (ledBlink_DW.clockTickCounter >= ledBlink_P.PulseGenerator_Period - 1.0) {
    ledBlink_DW.clockTickCounter = 0L;
  } else {
    ledBlink_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  if (rtb_PulseGenerator < 256.0) {
    if (rtb_PulseGenerator >= 0.0) {
      rtb_PulseGenerator_0 = (uint8_T)rtb_PulseGenerator;
    } else {
      rtb_PulseGenerator_0 = 0U;
    }
  } else {
    rtb_PulseGenerator_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* S-Function (arduinodigitaloutput_sfcn): '<S1>/Digital Output' */
  MW_digitalWrite(ledBlink_P.DigitalOutput_pinNumber, rtb_PulseGenerator_0);
}

/* Model initialize function */
void ledBlink_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(ledBlink_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&ledBlink_DW, 0,
                sizeof(DW_ledBlink_T));

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  ledBlink_DW.clockTickCounter = 0L;

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S1>/Digital Output' */
  MW_pinModeOutput(ledBlink_P.DigitalOutput_pinNumber);
}

/* Model terminate function */
void ledBlink_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
