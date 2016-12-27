/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: motorTest.c
 *
 * Code generated for Simulink model 'motorTest'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Tue Dec 27 10:46:08 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "motorTest.h"
#include "motorTest_private.h"
#include "motorTest_dt.h"

/* Block signals (auto storage) */
B_motorTest_T motorTest_B;

/* Block states (auto storage) */
DW_motorTest_T motorTest_DW;

/* Real-time model */
RT_MODEL_motorTest_T motorTest_M_;
RT_MODEL_motorTest_T *const motorTest_M = &motorTest_M_;

/* Model step function */
void motorTest_step(void)
{
  real_T tmp;

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  Constant: '<Root>/Constant'
   *  Gain: '<S1>/Slider Gain'
   */
  tmp = floor(motorTest_P.SliderGain_gain * motorTest_P.Constant_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  motorTest_B.DataTypeConversion3 = (int8_T)(tmp < 0.0 ? (int16_T)(int8_T)
    -(int8_T)(uint8_T)-tmp : (int16_T)(int8_T)(uint8_T)tmp);

  /* End of DataTypeConversion: '<Root>/Data Type Conversion3' */

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Gain: '<S2>/Slider Gain'
   */
  tmp = floor(motorTest_P.SliderGain1_gain * motorTest_P.Constant1_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  motorTest_B.DataTypeConversion2 = (int8_T)(tmp < 0.0 ? (int16_T)(int8_T)
    -(int8_T)(uint8_T)-tmp : (int16_T)(int8_T)(uint8_T)tmp);

  /* End of DataTypeConversion: '<Root>/Data Type Conversion2' */

  /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
   *  Constant: '<Root>/Constant2'
   */
  tmp = floor(motorTest_P.Constant2_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  motorTest_B.DataTypeConversion1 = (int8_T)(tmp < 0.0 ? (int16_T)(int8_T)
    -(int8_T)(uint8_T)-tmp : (int16_T)(int8_T)(uint8_T)tmp);

  /* End of DataTypeConversion: '<Root>/Data Type Conversion1' */

  /* S-Function (motorDriver): '<Root>/S-Function Builder1' */
  motorDriver_Outputs_wrapper(&motorTest_B.DataTypeConversion3,
    &motorTest_B.DataTypeConversion2, &motorTest_B.DataTypeConversion1,
    &motorTest_B.DataTypeConversion1, &motorTest_DW.SFunctionBuilder1_DSTATE);

  /* S-Function "motorDriver_wrapper" Block: <Root>/S-Function Builder1 */
  motorDriver_Update_wrapper(&motorTest_B.DataTypeConversion3,
    &motorTest_B.DataTypeConversion2, &motorTest_B.DataTypeConversion1,
    &motorTest_B.DataTypeConversion1, &motorTest_DW.SFunctionBuilder1_DSTATE);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.05s, 0.0s] */
    rtExtModeUpload(0, motorTest_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.05s, 0.0s] */
    if ((rtmGetTFinal(motorTest_M)!=-1) &&
        !((rtmGetTFinal(motorTest_M)-motorTest_M->Timing.taskTime0) >
          motorTest_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(motorTest_M, "Simulation finished");
    }

    if (rtmGetStopRequested(motorTest_M)) {
      rtmSetErrorStatus(motorTest_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  motorTest_M->Timing.taskTime0 =
    (++motorTest_M->Timing.clockTick0) * motorTest_M->Timing.stepSize0;
}

/* Model initialize function */
void motorTest_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)motorTest_M, 0,
                sizeof(RT_MODEL_motorTest_T));
  rtmSetTFinal(motorTest_M, -1);
  motorTest_M->Timing.stepSize0 = 0.05;

  /* External mode info */
  motorTest_M->Sizes.checksums[0] = (269859242U);
  motorTest_M->Sizes.checksums[1] = (3111303407U);
  motorTest_M->Sizes.checksums[2] = (2814806384U);
  motorTest_M->Sizes.checksums[3] = (3402666833U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    motorTest_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(motorTest_M->extModeInfo,
      &motorTest_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(motorTest_M->extModeInfo, motorTest_M->Sizes.checksums);
    rteiSetTPtr(motorTest_M->extModeInfo, rtmGetTPtr(motorTest_M));
  }

  /* block I/O */
  (void) memset(((void *) &motorTest_B), 0,
                sizeof(B_motorTest_T));

  /* states (dwork) */
  (void) memset((void *)&motorTest_DW, 0,
                sizeof(DW_motorTest_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    motorTest_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* S-Function Block: <Root>/S-Function Builder1 */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        motorTest_DW.SFunctionBuilder1_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void motorTest_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
