/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pos_test.c
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
#include "pos_test_dt.h"

/* Block signals (auto storage) */
B_pos_test_T pos_test_B;

/* Block states (auto storage) */
DW_pos_test_T pos_test_DW;

/* Real-time model */
RT_MODEL_pos_test_T pos_test_M_;
RT_MODEL_pos_test_T *const pos_test_M = &pos_test_M_;

/* Model output function */
void pos_test_output(void)
{
  real_T rtb_Saturation1;
  real_T tmp;
  uint8_T rtb_Saturation1_0;

  /* S-Function (arduinoanaloginput_sfcn): '<Root>/Analog Input' */
  pos_test_B.AnalogInput = MW_analogRead(pos_test_P.AnalogInput_p1);

  /* Gain: '<Root>/Gain2' */
  pos_test_B.Gain2 = (uint32_T)pos_test_P.Gain2_Gain * pos_test_B.AnalogInput;

  /* Gain: '<Root>/Gain3' incorporates:
   *  Constant: '<Root>/Constant'
   *  Sum: '<Root>/Sum'
   */
  pos_test_B.Gain3 = ((real_T)pos_test_B.Gain2 * 1.1920928955078125E-7 +
                      pos_test_P.Constant_Value) * pos_test_P.Gain3_Gain;

  /* Gain: '<Root>/Gain' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  rtb_Saturation1 = pos_test_P.Gain_Gain * pos_test_P.Constant1_Value;

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Saturation1 > pos_test_P.Saturation_UpperSat) {
    /* DataTypeConversion: '<S1>/Data Type Conversion' */
    tmp = pos_test_P.Saturation_UpperSat;
  } else if (rtb_Saturation1 < pos_test_P.Saturation_LowerSat) {
    /* DataTypeConversion: '<S1>/Data Type Conversion' */
    tmp = pos_test_P.Saturation_LowerSat;
  } else {
    /* DataTypeConversion: '<S1>/Data Type Conversion' */
    tmp = rtb_Saturation1;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  if (tmp < 256.0) {
    if (tmp >= 0.0) {
      rtb_Saturation1_0 = (uint8_T)tmp;
    } else {
      rtb_Saturation1_0 = 0U;
    }
  } else {
    rtb_Saturation1_0 = MAX_uint8_T;
  }

  /* S-Function (arduinoanalogoutput_sfcn): '<S1>/PWM' */
  MW_analogWrite(pos_test_P.PWM_pinNumber, rtb_Saturation1_0);

  /* Gain: '<Root>/Gain1' */
  rtb_Saturation1 *= pos_test_P.Gain1_Gain;

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_Saturation1 > pos_test_P.Saturation1_UpperSat) {
    rtb_Saturation1 = pos_test_P.Saturation1_UpperSat;
  } else {
    if (rtb_Saturation1 < pos_test_P.Saturation1_LowerSat) {
      rtb_Saturation1 = pos_test_P.Saturation1_LowerSat;
    }
  }

  /* End of Saturate: '<Root>/Saturation1' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  if (rtb_Saturation1 < 256.0) {
    if (rtb_Saturation1 >= 0.0) {
      rtb_Saturation1_0 = (uint8_T)rtb_Saturation1;
    } else {
      rtb_Saturation1_0 = 0U;
    }
  } else {
    rtb_Saturation1_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
  MW_analogWrite(pos_test_P.PWM_pinNumber_p, rtb_Saturation1_0);
}

/* Model update function */
void pos_test_update(void)
{
  /* signal main to stop simulation */
  {                                    /* Sample time: [1.0s, 0.0s] */
    if ((rtmGetTFinal(pos_test_M)!=-1) &&
        !((rtmGetTFinal(pos_test_M)-pos_test_M->Timing.taskTime0) >
          pos_test_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(pos_test_M, "Simulation finished");
    }

    if (rtmGetStopRequested(pos_test_M)) {
      rtmSetErrorStatus(pos_test_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  pos_test_M->Timing.taskTime0 =
    (++pos_test_M->Timing.clockTick0) * pos_test_M->Timing.stepSize0;
}

/* Model initialize function */
void pos_test_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)pos_test_M, 0,
                sizeof(RT_MODEL_pos_test_T));
  rtmSetTFinal(pos_test_M, -1);
  pos_test_M->Timing.stepSize0 = 1.0;

  /* External mode info */
  pos_test_M->Sizes.checksums[0] = (234949635U);
  pos_test_M->Sizes.checksums[1] = (4151240017U);
  pos_test_M->Sizes.checksums[2] = (1168793164U);
  pos_test_M->Sizes.checksums[3] = (410676982U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    pos_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(pos_test_M->extModeInfo,
      &pos_test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(pos_test_M->extModeInfo, pos_test_M->Sizes.checksums);
    rteiSetTPtr(pos_test_M->extModeInfo, rtmGetTPtr(pos_test_M));
  }

  /* block I/O */
  (void) memset(((void *) &pos_test_B), 0,
                sizeof(B_pos_test_T));

  /* states (dwork) */
  (void) memset((void *)&pos_test_DW, 0,
                sizeof(DW_pos_test_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    pos_test_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (arduinoanaloginput_sfcn): '<Root>/Analog Input' */
  MW_pinModeAnalogInput(pos_test_P.AnalogInput_p1);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S1>/PWM' */
  MW_pinModeOutput(pos_test_P.PWM_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
  MW_pinModeOutput(pos_test_P.PWM_pinNumber_p);
}

/* Model terminate function */
void pos_test_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
