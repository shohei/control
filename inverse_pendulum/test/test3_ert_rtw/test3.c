/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test3.c
 *
 * Code generated for Simulink model 'test3'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Wed Dec 21 15:59:48 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test3.h"
#include "test3_private.h"

/* Block signals (auto storage) */
B_test3_T test3_B;

/* Block states (auto storage) */
DW_test3_T test3_DW;

/* Real-time model */
RT_MODEL_test3_T test3_M_;
RT_MODEL_test3_T *const test3_M = &test3_M_;

/* Model step function */
void test3_step(void)
{
  real_T rtb_PulseGenerator;

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_PulseGenerator = floor(test3_P.Constant_Value);
  if (rtIsNaN(rtb_PulseGenerator) || rtIsInf(rtb_PulseGenerator)) {
    rtb_PulseGenerator = 0.0;
  } else {
    rtb_PulseGenerator = fmod(rtb_PulseGenerator, 256.0);
  }

  test3_B.DataTypeConversion3 = (int8_T)(rtb_PulseGenerator < 0.0 ? (int16_T)
    (int8_T)-(int8_T)(uint8_T)-rtb_PulseGenerator : (int16_T)(int8_T)(uint8_T)
    rtb_PulseGenerator);

  /* End of DataTypeConversion: '<Root>/Data Type Conversion3' */

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  rtb_PulseGenerator = floor(test3_P.Constant1_Value);
  if (rtIsNaN(rtb_PulseGenerator) || rtIsInf(rtb_PulseGenerator)) {
    rtb_PulseGenerator = 0.0;
  } else {
    rtb_PulseGenerator = fmod(rtb_PulseGenerator, 256.0);
  }

  test3_B.DataTypeConversion2 = (int8_T)(rtb_PulseGenerator < 0.0 ? (int16_T)
    (int8_T)-(int8_T)(uint8_T)-rtb_PulseGenerator : (int16_T)(int8_T)(uint8_T)
    rtb_PulseGenerator);

  /* End of DataTypeConversion: '<Root>/Data Type Conversion2' */

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (test3_DW.clockTickCounter < test3_P.PulseGenerator_Duty)
    && (test3_DW.clockTickCounter >= 0L) ? test3_P.PulseGenerator_Amp : 0.0;
  if (test3_DW.clockTickCounter >= test3_P.PulseGenerator_Period - 1.0) {
    test3_DW.clockTickCounter = 0L;
  } else {
    test3_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* Switch: '<Root>/Switch' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   */
  if (rtb_PulseGenerator > test3_P.Switch_Threshold) {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    rtb_PulseGenerator = floor(test3_P.Constant2_Value);
    if (rtIsNaN(rtb_PulseGenerator) || rtIsInf(rtb_PulseGenerator)) {
      rtb_PulseGenerator = 0.0;
    } else {
      rtb_PulseGenerator = fmod(rtb_PulseGenerator, 256.0);
    }

    test3_B.Switch = (int8_T)(rtb_PulseGenerator < 0.0 ? (int16_T)(int8_T)
      -(int8_T)(uint8_T)-rtb_PulseGenerator : (int16_T)(int8_T)(uint8_T)
      rtb_PulseGenerator);
  } else {
    /* DataTypeConversion: '<Root>/Data Type Conversion4' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    rtb_PulseGenerator = floor(test3_P.Constant5_Value);
    if (rtIsNaN(rtb_PulseGenerator) || rtIsInf(rtb_PulseGenerator)) {
      rtb_PulseGenerator = 0.0;
    } else {
      rtb_PulseGenerator = fmod(rtb_PulseGenerator, 256.0);
    }

    test3_B.Switch = (int8_T)(rtb_PulseGenerator < 0.0 ? (int16_T)(int8_T)
      -(int8_T)(uint8_T)-rtb_PulseGenerator : (int16_T)(int8_T)(uint8_T)
      rtb_PulseGenerator);
  }

  /* End of Switch: '<Root>/Switch' */

  /* S-Function (motorDriver): '<Root>/S-Function Builder' */
  motorDriver_Outputs_wrapper(&test3_B.DataTypeConversion3,
    &test3_B.DataTypeConversion2, &test3_B.Switch, &test3_B.Switch,
    &test3_DW.SFunctionBuilder_DSTATE);

  /* S-Function "motorDriver_wrapper" Block: <Root>/S-Function Builder */
  motorDriver_Update_wrapper(&test3_B.DataTypeConversion3,
    &test3_B.DataTypeConversion2, &test3_B.Switch, &test3_B.Switch,
    &test3_DW.SFunctionBuilder_DSTATE);
}

/* Model initialize function */
void test3_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(test3_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &test3_B), 0,
                sizeof(B_test3_T));

  /* states (dwork) */
  (void) memset((void *)&test3_DW, 0,
                sizeof(DW_test3_T));

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  test3_DW.clockTickCounter = 0L;

  /* S-Function Block: <Root>/S-Function Builder */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        test3_DW.SFunctionBuilder_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void test3_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
