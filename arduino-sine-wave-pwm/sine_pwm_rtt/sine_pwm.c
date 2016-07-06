/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sine_pwm.c
 *
 * Code generated for Simulink model 'sine_pwm'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 19 2015)
 * C/C++ source code generated on : Fri Dec  4 15:43:14 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sine_pwm.h"
#include "sine_pwm_private.h"
#include "sine_pwm_dt.h"

/* Block signals (auto storage) */
B_sine_pwm_T sine_pwm_B;

/* Block states (auto storage) */
DW_sine_pwm_T sine_pwm_DW;

/* Real-time model */
RT_MODEL_sine_pwm_T sine_pwm_M_;
RT_MODEL_sine_pwm_T *const sine_pwm_M = &sine_pwm_M_;

/* Model output function */
void sine_pwm_output(void)
{
  uint8_T tmp;

  /* Sin: '<Root>/Sine Wave' */
  sine_pwm_B.SineWave = sin(((real_T)sine_pwm_DW.counter +
    sine_pwm_P.SineWave_Offset) * 2.0 * 3.1415926535897931 /
    sine_pwm_P.SineWave_NumSamp) * sine_pwm_P.SineWave_Amp +
    sine_pwm_P.SineWave_Bias;

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  if (sine_pwm_B.SineWave < 256.0) {
    if (sine_pwm_B.SineWave >= 0.0) {
      tmp = (uint8_T)sine_pwm_B.SineWave;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S1>/PWM' */
  MW_analogWrite(sine_pwm_P.PWM_pinNumber, tmp);
}

/* Model update function */
void sine_pwm_update(void)
{
  /* Update for Sin: '<Root>/Sine Wave' */
  sine_pwm_DW.counter++;
  if (sine_pwm_DW.counter == sine_pwm_P.SineWave_NumSamp) {
    sine_pwm_DW.counter = 0L;
  }

  /* End of Update for Sin: '<Root>/Sine Wave' */

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(sine_pwm_M)!=-1) &&
        !((rtmGetTFinal(sine_pwm_M)-sine_pwm_M->Timing.taskTime0) >
          sine_pwm_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(sine_pwm_M, "Simulation finished");
    }

    if (rtmGetStopRequested(sine_pwm_M)) {
      rtmSetErrorStatus(sine_pwm_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  sine_pwm_M->Timing.taskTime0 =
    (++sine_pwm_M->Timing.clockTick0) * sine_pwm_M->Timing.stepSize0;
}

/* Model initialize function */
void sine_pwm_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)sine_pwm_M, 0,
                sizeof(RT_MODEL_sine_pwm_T));
  rtmSetTFinal(sine_pwm_M, -1);
  sine_pwm_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  sine_pwm_M->Sizes.checksums[0] = (2131686815U);
  sine_pwm_M->Sizes.checksums[1] = (2976833857U);
  sine_pwm_M->Sizes.checksums[2] = (2630089091U);
  sine_pwm_M->Sizes.checksums[3] = (817216220U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    sine_pwm_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(sine_pwm_M->extModeInfo,
      &sine_pwm_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(sine_pwm_M->extModeInfo, sine_pwm_M->Sizes.checksums);
    rteiSetTPtr(sine_pwm_M->extModeInfo, rtmGetTPtr(sine_pwm_M));
  }

  /* block I/O */
  (void) memset(((void *) &sine_pwm_B), 0,
                sizeof(B_sine_pwm_T));

  /* states (dwork) */
  (void) memset((void *)&sine_pwm_DW, 0,
                sizeof(DW_sine_pwm_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    sine_pwm_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S1>/PWM' */
  MW_pinModeOutput(sine_pwm_P.PWM_pinNumber);

  /* InitializeConditions for Sin: '<Root>/Sine Wave' */
  sine_pwm_DW.counter = 0L;
}

/* Model terminate function */
void sine_pwm_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
