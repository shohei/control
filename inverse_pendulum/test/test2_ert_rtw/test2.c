/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test2.c
 *
 * Code generated for Simulink model 'test2'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Wed Dec 21 14:50:19 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test2.h"
#include "test2_private.h"
#include "test2_dt.h"

/* Block signals (auto storage) */
B_test2_T test2_B;

/* Block states (auto storage) */
DW_test2_T test2_DW;

/* Real-time model */
RT_MODEL_test2_T test2_M_;
RT_MODEL_test2_T *const test2_M = &test2_M_;

/* Model step function */
void test2_step(void)
{
  real_T rtb_PulseGenerator;
  int8_T tmp;

  /* DataTypeConversion: '<Root>/Data Type Conversion3' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_PulseGenerator = floor(test2_P.Constant_Value);
  if (rtIsNaN(rtb_PulseGenerator) || rtIsInf(rtb_PulseGenerator)) {
    rtb_PulseGenerator = 0.0;
  } else {
    rtb_PulseGenerator = fmod(rtb_PulseGenerator, 256.0);
  }

  test2_B.DataTypeConversion3 = (int8_T)(rtb_PulseGenerator < 0.0 ? (int16_T)
    (int8_T)-(int8_T)(uint8_T)-rtb_PulseGenerator : (int16_T)(int8_T)(uint8_T)
    rtb_PulseGenerator);

  /* End of DataTypeConversion: '<Root>/Data Type Conversion3' */

  /* DataTypeConversion: '<Root>/Data Type Conversion2' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  rtb_PulseGenerator = floor(test2_P.Constant1_Value);
  if (rtIsNaN(rtb_PulseGenerator) || rtIsInf(rtb_PulseGenerator)) {
    rtb_PulseGenerator = 0.0;
  } else {
    rtb_PulseGenerator = fmod(rtb_PulseGenerator, 256.0);
  }

  test2_B.DataTypeConversion2 = (int8_T)(rtb_PulseGenerator < 0.0 ? (int16_T)
    (int8_T)-(int8_T)(uint8_T)-rtb_PulseGenerator : (int16_T)(int8_T)(uint8_T)
    rtb_PulseGenerator);

  /* End of DataTypeConversion: '<Root>/Data Type Conversion2' */

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (test2_DW.clockTickCounter < test2_P.PulseGenerator_Duty)
    && (test2_DW.clockTickCounter >= 0L) ? test2_P.PulseGenerator_Amp : 0.0;
  if (test2_DW.clockTickCounter >= test2_P.PulseGenerator_Period - 1.0) {
    test2_DW.clockTickCounter = 0L;
  } else {
    test2_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* Switch: '<Root>/Switch' incorporates:
   *  DataTypeConversion: '<Root>/Data Type Conversion1'
   *  DataTypeConversion: '<Root>/Data Type Conversion4'
   */
  if (rtb_PulseGenerator > test2_P.Switch_Threshold) {
    /* DataTypeConversion: '<Root>/Data Type Conversion1' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    rtb_PulseGenerator = floor(test2_P.Constant2_Value);
    if (rtIsNaN(rtb_PulseGenerator) || rtIsInf(rtb_PulseGenerator)) {
      rtb_PulseGenerator = 0.0;
    } else {
      rtb_PulseGenerator = fmod(rtb_PulseGenerator, 256.0);
    }

    test2_B.Switch = (int8_T)(rtb_PulseGenerator < 0.0 ? (int16_T)(int8_T)
      -(int8_T)(uint8_T)-rtb_PulseGenerator : (int16_T)(int8_T)(uint8_T)
      rtb_PulseGenerator);
  } else {
    /* DataTypeConversion: '<Root>/Data Type Conversion4' incorporates:
     *  Constant: '<Root>/Constant5'
     */
    rtb_PulseGenerator = floor(test2_P.Constant5_Value);
    if (rtIsNaN(rtb_PulseGenerator) || rtIsInf(rtb_PulseGenerator)) {
      rtb_PulseGenerator = 0.0;
    } else {
      rtb_PulseGenerator = fmod(rtb_PulseGenerator, 256.0);
    }

    test2_B.Switch = (int8_T)(rtb_PulseGenerator < 0.0 ? (int16_T)(int8_T)
      -(int8_T)(uint8_T)-rtb_PulseGenerator : (int16_T)(int8_T)(uint8_T)
      rtb_PulseGenerator);
  }

  /* End of Switch: '<Root>/Switch' */

  /* S-Function (motorDriver): '<Root>/S-Function Builder' */
  motorDriver_Outputs_wrapper(&test2_B.DataTypeConversion3,
    &test2_B.DataTypeConversion2, &test2_B.Switch, &test2_B.Switch,
    &test2_B.SFunctionBuilder_o1, &test2_B.SFunctionBuilder_o2,
    &test2_B.SFunctionBuilder_o3, &test2_B.SFunctionBuilder_o4,
    &test2_B.SFunctionBuilder_o5, &test2_B.SFunctionBuilder_o6,
    &test2_DW.SFunctionBuilder_DSTATE);

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  tmp = test2_B.SFunctionBuilder_o1;
  if (test2_B.SFunctionBuilder_o1 < 0) {
    tmp = 0;
  }

  /* S-Function (arduinodigitaloutput_sfcn): '<S1>/Digital Output' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   */
  MW_digitalWrite(test2_P.DigitalOutput_pinNumber, (uint8_T)tmp);

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  tmp = test2_B.SFunctionBuilder_o2;
  if (test2_B.SFunctionBuilder_o2 < 0) {
    tmp = 0;
  }

  /* S-Function (arduinodigitaloutput_sfcn): '<S2>/Digital Output' incorporates:
   *  DataTypeConversion: '<S2>/Data Type Conversion'
   */
  MW_digitalWrite(test2_P.DigitalOutput_pinNum_oq3g4mumzf, (uint8_T)tmp);

  /* DataTypeConversion: '<S3>/Data Type Conversion' */
  tmp = test2_B.SFunctionBuilder_o4;
  if (test2_B.SFunctionBuilder_o4 < 0) {
    tmp = 0;
  }

  /* S-Function (arduinodigitaloutput_sfcn): '<S3>/Digital Output' incorporates:
   *  DataTypeConversion: '<S3>/Data Type Conversion'
   */
  MW_digitalWrite(test2_P.DigitalOutput_pinNum_lq4ka0n3cr, (uint8_T)tmp);

  /* DataTypeConversion: '<S4>/Data Type Conversion' */
  tmp = test2_B.SFunctionBuilder_o5;
  if (test2_B.SFunctionBuilder_o5 < 0) {
    tmp = 0;
  }

  /* S-Function (arduinodigitaloutput_sfcn): '<S4>/Digital Output' incorporates:
   *  DataTypeConversion: '<S4>/Data Type Conversion'
   */
  MW_digitalWrite(test2_P.DigitalOutput_pinNum_bbnhqscnhg, (uint8_T)tmp);

  /* DataTypeConversion: '<S5>/Data Type Conversion' */
  tmp = test2_B.SFunctionBuilder_o3;
  if (test2_B.SFunctionBuilder_o3 < 0) {
    tmp = 0;
  }

  /* S-Function (arduinoanalogoutput_sfcn): '<S5>/PWM' incorporates:
   *  DataTypeConversion: '<S5>/Data Type Conversion'
   */
  MW_analogWrite(test2_P.PWM_pinNumber, (uint8_T)tmp);

  /* DataTypeConversion: '<S6>/Data Type Conversion' */
  tmp = test2_B.SFunctionBuilder_o6;
  if (test2_B.SFunctionBuilder_o6 < 0) {
    tmp = 0;
  }

  /* S-Function (arduinoanalogoutput_sfcn): '<S6>/PWM' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion'
   */
  MW_analogWrite(test2_P.PWM_pinNumber_cmnfljccqg, (uint8_T)tmp);

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn1' */
  test2_B.VectorConcatenate[0] = test2_B.SFunctionBuilder_o1;

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn2' */
  test2_B.VectorConcatenate[1] = test2_B.SFunctionBuilder_o2;

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn3' */
  test2_B.VectorConcatenate[2] = test2_B.SFunctionBuilder_o3;

  /* S-Function "motorDriver_wrapper" Block: <Root>/S-Function Builder */
  motorDriver_Update_wrapper(&test2_B.DataTypeConversion3,
    &test2_B.DataTypeConversion2, &test2_B.Switch, &test2_B.Switch,
    &test2_B.SFunctionBuilder_o1, &test2_B.SFunctionBuilder_o2,
    &test2_B.SFunctionBuilder_o3, &test2_B.SFunctionBuilder_o4,
    &test2_B.SFunctionBuilder_o5, &test2_B.SFunctionBuilder_o6,
    &test2_DW.SFunctionBuilder_DSTATE);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [2.0s, 0.0s] */
    rtExtModeUpload(0, test2_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [2.0s, 0.0s] */
    if ((rtmGetTFinal(test2_M)!=-1) &&
        !((rtmGetTFinal(test2_M)-test2_M->Timing.taskTime0) >
          test2_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(test2_M, "Simulation finished");
    }

    if (rtmGetStopRequested(test2_M)) {
      rtmSetErrorStatus(test2_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  test2_M->Timing.taskTime0 =
    (++test2_M->Timing.clockTick0) * test2_M->Timing.stepSize0;
}

/* Model initialize function */
void test2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)test2_M, 0,
                sizeof(RT_MODEL_test2_T));
  rtmSetTFinal(test2_M, 10.0);
  test2_M->Timing.stepSize0 = 2.0;

  /* External mode info */
  test2_M->Sizes.checksums[0] = (502487110U);
  test2_M->Sizes.checksums[1] = (1805634051U);
  test2_M->Sizes.checksums[2] = (3431928997U);
  test2_M->Sizes.checksums[3] = (1577140487U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    test2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(test2_M->extModeInfo,
      &test2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(test2_M->extModeInfo, test2_M->Sizes.checksums);
    rteiSetTPtr(test2_M->extModeInfo, rtmGetTPtr(test2_M));
  }

  /* block I/O */
  (void) memset(((void *) &test2_B), 0,
                sizeof(B_test2_T));

  /* states (dwork) */
  (void) memset((void *)&test2_DW, 0,
                sizeof(DW_test2_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    test2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  test2_DW.clockTickCounter = 0L;

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S1>/Digital Output' */
  MW_pinModeOutput(test2_P.DigitalOutput_pinNumber);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S2>/Digital Output' */
  MW_pinModeOutput(test2_P.DigitalOutput_pinNum_oq3g4mumzf);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S3>/Digital Output' */
  MW_pinModeOutput(test2_P.DigitalOutput_pinNum_lq4ka0n3cr);

  /* Start for S-Function (arduinodigitaloutput_sfcn): '<S4>/Digital Output' */
  MW_pinModeOutput(test2_P.DigitalOutput_pinNum_bbnhqscnhg);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S5>/PWM' */
  MW_pinModeOutput(test2_P.PWM_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S6>/PWM' */
  MW_pinModeOutput(test2_P.PWM_pinNumber_cmnfljccqg);

  /* S-Function Block: <Root>/S-Function Builder */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        test2_DW.SFunctionBuilder_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void test2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
