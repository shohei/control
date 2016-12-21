/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ledTet.c
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

#include "ledTet.h"
#include "ledTet_private.h"
#include "ledTet_dt.h"

/* Block signals (auto storage) */
B_ledTet_T ledTet_B;

/* Block states (auto storage) */
DW_ledTet_T ledTet_DW;

/* Real-time model */
RT_MODEL_ledTet_T ledTet_M_;
RT_MODEL_ledTet_T *const ledTet_M = &ledTet_M_;

/* Model step function */
void ledTet_step(void)
{
  real_T tmp;

  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  Constant: '<Root>/Constant'
   */
  tmp = floor(ledTet_P.Constant_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  ledTet_B.DataTypeConversion = (int8_T)(tmp < 0.0 ? (int16_T)(int8_T)-(int8_T)
    (uint8_T)-tmp : (int16_T)(int8_T)(uint8_T)tmp);

  /* End of DataTypeConversion: '<Root>/Data Type Conversion' */

  /* S-Function (led): '<Root>/S-Function Builder' */
  led_Outputs_wrapper(&ledTet_B.DataTypeConversion,
                      &ledTet_DW.SFunctionBuilder_DSTATE);

  /* S-Function "led_wrapper" Block: <Root>/S-Function Builder */
  led_Update_wrapper(&ledTet_B.DataTypeConversion,
                     &ledTet_DW.SFunctionBuilder_DSTATE);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.2s, 0.0s] */
    rtExtModeUpload(0, ledTet_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.2s, 0.0s] */
    if ((rtmGetTFinal(ledTet_M)!=-1) &&
        !((rtmGetTFinal(ledTet_M)-ledTet_M->Timing.taskTime0) >
          ledTet_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(ledTet_M, "Simulation finished");
    }

    if (rtmGetStopRequested(ledTet_M)) {
      rtmSetErrorStatus(ledTet_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ledTet_M->Timing.taskTime0 =
    (++ledTet_M->Timing.clockTick0) * ledTet_M->Timing.stepSize0;
}

/* Model initialize function */
void ledTet_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)ledTet_M, 0,
                sizeof(RT_MODEL_ledTet_T));
  rtmSetTFinal(ledTet_M, 10.0);
  ledTet_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  ledTet_M->Sizes.checksums[0] = (2434344644U);
  ledTet_M->Sizes.checksums[1] = (2818299618U);
  ledTet_M->Sizes.checksums[2] = (2072515841U);
  ledTet_M->Sizes.checksums[3] = (647167610U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    ledTet_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ledTet_M->extModeInfo,
      &ledTet_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ledTet_M->extModeInfo, ledTet_M->Sizes.checksums);
    rteiSetTPtr(ledTet_M->extModeInfo, rtmGetTPtr(ledTet_M));
  }

  /* block I/O */
  (void) memset(((void *) &ledTet_B), 0,
                sizeof(B_ledTet_T));

  /* states (dwork) */
  (void) memset((void *)&ledTet_DW, 0,
                sizeof(DW_ledTet_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ledTet_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* S-Function Block: <Root>/S-Function Builder */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        ledTet_DW.SFunctionBuilder_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void ledTet_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
