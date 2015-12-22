/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: velo_tc.c
 *
 * Code generated for Simulink model 'velo_tc'.
 *
 * Model version                  : 1.6
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 19 2015)
 * C/C++ source code generated on : Tue Dec 22 21:10:57 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "velo_tc.h"
#include "velo_tc_private.h"
#include "velo_tc_dt.h"

/* Block signals (auto storage) */
B_velo_tc_T velo_tc_B;

/* Block states (auto storage) */
DW_velo_tc_T velo_tc_DW;

/* Real-time model */
RT_MODEL_velo_tc_T velo_tc_M_;
RT_MODEL_velo_tc_T *const velo_tc_M = &velo_tc_M_;

/* Model output function */
void velo_tc_output(void)
{
  uint16_T rtb_AnalogInput_0;
  real_T rtb_Gain;
  uint8_T rtb_Gain_0;

  /* Step: '<Root>/Step' */
  rtb_Gain = velo_tc_M->Timing.taskTime0;
  if (rtb_Gain < velo_tc_P.Step_Time) {
    rtb_Gain = velo_tc_P.Step_Y0;
  } else {
    rtb_Gain = velo_tc_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* Switch: '<Root>/Switch' */
  if (rtb_Gain > velo_tc_P.Switch_Threshold) {
    /* Step: '<Root>/Step1' */
    if (velo_tc_M->Timing.taskTime0 < velo_tc_P.s_time) {
      rtb_Gain = velo_tc_P.r_const;
    } else {
      rtb_Gain = velo_tc_P.p_const;
    }
  } else {
    /* Step: '<Root>/Step1' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    rtb_Gain = velo_tc_P.u_ini;
  }

  /* End of Switch: '<Root>/Switch' */

  /* DataTypeConversion: '<S1>/Data Type Conversion1' */
  velo_tc_B.VectorConcatenate[0] = rtb_Gain;

  /* S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input' */
  rtb_AnalogInput_0 = MW_analogRead(velo_tc_P.AnalogInput_p1);

  /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
   *  Gain: '<S1>/Gain1'
   *  S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input'
   */
  velo_tc_B.VectorConcatenate[1] = (real_T)((uint32_T)velo_tc_P.Gain1_Gain *
    rtb_AnalogInput_0) * 1.1920928955078125E-7;

  /* Gain: '<S1>/Gain' */
  rtb_Gain *= velo_tc_P.Gain_Gain;

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  if (rtb_Gain < 256.0) {
    if (rtb_Gain >= 0.0) {
      rtb_Gain_0 = (uint8_T)rtb_Gain;
    } else {
      rtb_Gain_0 = 0U;
    }
  } else {
    rtb_Gain_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
  MW_analogWrite(velo_tc_P.PWM_pinNumber, rtb_Gain_0);
}

/* Model update function */
void velo_tc_update(void)
{
  /* signal main to stop simulation */
  {                                    /* Sample time: [0.01s, 0.0s] */
    if ((rtmGetTFinal(velo_tc_M)!=-1) &&
        !((rtmGetTFinal(velo_tc_M)-velo_tc_M->Timing.taskTime0) >
          velo_tc_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(velo_tc_M, "Simulation finished");
    }

    if (rtmGetStopRequested(velo_tc_M)) {
      rtmSetErrorStatus(velo_tc_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  velo_tc_M->Timing.taskTime0 =
    (++velo_tc_M->Timing.clockTick0) * velo_tc_M->Timing.stepSize0;
}

/* Model initialize function */
void velo_tc_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)velo_tc_M, 0,
                sizeof(RT_MODEL_velo_tc_T));
  rtmSetTFinal(velo_tc_M, 20.0);
  velo_tc_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  velo_tc_M->Sizes.checksums[0] = (730665787U);
  velo_tc_M->Sizes.checksums[1] = (3789317073U);
  velo_tc_M->Sizes.checksums[2] = (3294523768U);
  velo_tc_M->Sizes.checksums[3] = (2733310781U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[2];
    velo_tc_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(velo_tc_M->extModeInfo,
      &velo_tc_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(velo_tc_M->extModeInfo, velo_tc_M->Sizes.checksums);
    rteiSetTPtr(velo_tc_M->extModeInfo, rtmGetTPtr(velo_tc_M));
  }

  /* block I/O */
  (void) memset(((void *) &velo_tc_B), 0,
                sizeof(B_velo_tc_T));

  /* states (dwork) */
  (void) memset((void *)&velo_tc_DW, 0,
                sizeof(DW_velo_tc_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    velo_tc_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input' */
  MW_pinModeAnalogInput(velo_tc_P.AnalogInput_p1);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
  MW_pinModeOutput(velo_tc_P.PWM_pinNumber);
}

/* Model terminate function */
void velo_tc_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
