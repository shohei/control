/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pos_step_sl.c
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
#include "pos_step_sl_dt.h"

/* Block signals (auto storage) */
B_pos_step_sl_T pos_step_sl_B;

/* Block states (auto storage) */
DW_pos_step_sl_T pos_step_sl_DW;

/* Real-time model */
RT_MODEL_pos_step_sl_T pos_step_sl_M_;
RT_MODEL_pos_step_sl_T *const pos_step_sl_M = &pos_step_sl_M_;

/* Model output function */
void pos_step_sl_output(void)
{
  uint16_T rtb_AnalogInput_0;
  real_T rtb_Saturation;
  real_T rtb_Saturation1;
  uint8_T rtb_Saturation1_0;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_Saturation = (pos_step_sl_DW.clockTickCounter <
                    pos_step_sl_P.PulseGenerator_Duty) &&
    (pos_step_sl_DW.clockTickCounter >= 0L) ? pos_step_sl_P.PulseGenerator_Amp :
    0.0;
  if (pos_step_sl_DW.clockTickCounter >= pos_step_sl_P.PulseGenerator_Period -
      1.0) {
    pos_step_sl_DW.clockTickCounter = 0L;
  } else {
    pos_step_sl_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   */
  rtb_Saturation -= pos_step_sl_P.r / 2.0;

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn1' */
  pos_step_sl_B.VectorConcatenate[0] = rtb_Saturation;

  /* S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input' */
  rtb_AnalogInput_0 = MW_analogRead(pos_step_sl_P.AnalogInput_p1);

  /* Gain: '<S1>/Gain3' incorporates:
   *  Constant: '<S1>/Constant'
   *  Gain: '<S1>/Gain2'
   *  S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input'
   *  Sum: '<S1>/Sum'
   */
  rtb_Saturation1 = ((real_T)((uint32_T)pos_step_sl_P.Gain2_Gain *
    rtb_AnalogInput_0) * 1.1920928955078125E-7 + pos_step_sl_P.Constant_Value) *
    pos_step_sl_P.Gain3_Gain;

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn2' */
  pos_step_sl_B.VectorConcatenate[1] = rtb_Saturation1;

  /* Gain: '<Root>/Gain' incorporates:
   *  Sum: '<Root>/Sum1'
   */
  pos_step_sl_B.Gain = (rtb_Saturation - rtb_Saturation1) * pos_step_sl_P.Kp_id;

  /* Gain: '<S1>/Gain' */
  rtb_Saturation1 = pos_step_sl_P.Gain_Gain * pos_step_sl_B.Gain;

  /* Saturate: '<S1>/Saturation' */
  if (rtb_Saturation1 > pos_step_sl_P.Saturation_UpperSat) {
    /* DataTypeConversion: '<S2>/Data Type Conversion' */
    rtb_Saturation = pos_step_sl_P.Saturation_UpperSat;
  } else if (rtb_Saturation1 < pos_step_sl_P.Saturation_LowerSat) {
    /* DataTypeConversion: '<S2>/Data Type Conversion' */
    rtb_Saturation = pos_step_sl_P.Saturation_LowerSat;
  } else {
    /* DataTypeConversion: '<S2>/Data Type Conversion' */
    rtb_Saturation = rtb_Saturation1;
  }

  /* End of Saturate: '<S1>/Saturation' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  if (rtb_Saturation < 256.0) {
    if (rtb_Saturation >= 0.0) {
      rtb_Saturation1_0 = (uint8_T)rtb_Saturation;
    } else {
      rtb_Saturation1_0 = 0U;
    }
  } else {
    rtb_Saturation1_0 = MAX_uint8_T;
  }

  /* S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
  MW_analogWrite(pos_step_sl_P.PWM_pinNumber, rtb_Saturation1_0);

  /* Gain: '<S1>/Gain1' */
  rtb_Saturation1 *= pos_step_sl_P.Gain1_Gain;

  /* Saturate: '<S1>/Saturation1' */
  if (rtb_Saturation1 > pos_step_sl_P.Saturation1_UpperSat) {
    rtb_Saturation1 = pos_step_sl_P.Saturation1_UpperSat;
  } else {
    if (rtb_Saturation1 < pos_step_sl_P.Saturation1_LowerSat) {
      rtb_Saturation1 = pos_step_sl_P.Saturation1_LowerSat;
    }
  }

  /* End of Saturate: '<S1>/Saturation1' */

  /* DataTypeConversion: '<S3>/Data Type Conversion' */
  if (rtb_Saturation1 < 256.0) {
    if (rtb_Saturation1 >= 0.0) {
      rtb_Saturation1_0 = (uint8_T)rtb_Saturation1;
    } else {
      rtb_Saturation1_0 = 0U;
    }
  } else {
    rtb_Saturation1_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S3>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S3>/PWM' */
  MW_analogWrite(pos_step_sl_P.PWM_pinNumber_f, rtb_Saturation1_0);
}

/* Model update function */
void pos_step_sl_update(void)
{
  /* signal main to stop simulation */
  {                                    /* Sample time: [0.02s, 0.0s] */
    if ((rtmGetTFinal(pos_step_sl_M)!=-1) &&
        !((rtmGetTFinal(pos_step_sl_M)-pos_step_sl_M->Timing.taskTime0) >
          pos_step_sl_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(pos_step_sl_M, "Simulation finished");
    }

    if (rtmGetStopRequested(pos_step_sl_M)) {
      rtmSetErrorStatus(pos_step_sl_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  pos_step_sl_M->Timing.taskTime0 =
    (++pos_step_sl_M->Timing.clockTick0) * pos_step_sl_M->Timing.stepSize0;
}

/* Model initialize function */
void pos_step_sl_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)pos_step_sl_M, 0,
                sizeof(RT_MODEL_pos_step_sl_T));
  rtmSetTFinal(pos_step_sl_M, 10.0);
  pos_step_sl_M->Timing.stepSize0 = 0.02;

  /* External mode info */
  pos_step_sl_M->Sizes.checksums[0] = (3720076488U);
  pos_step_sl_M->Sizes.checksums[1] = (951104174U);
  pos_step_sl_M->Sizes.checksums[2] = (741501938U);
  pos_step_sl_M->Sizes.checksums[3] = (3650775784U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    pos_step_sl_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(pos_step_sl_M->extModeInfo,
      &pos_step_sl_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(pos_step_sl_M->extModeInfo,
                        pos_step_sl_M->Sizes.checksums);
    rteiSetTPtr(pos_step_sl_M->extModeInfo, rtmGetTPtr(pos_step_sl_M));
  }

  /* block I/O */
  (void) memset(((void *) &pos_step_sl_B), 0,
                sizeof(B_pos_step_sl_T));

  /* states (dwork) */
  (void) memset((void *)&pos_step_sl_DW, 0,
                sizeof(DW_pos_step_sl_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    pos_step_sl_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  pos_step_sl_DW.clockTickCounter = 0L;

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input' */
  MW_pinModeAnalogInput(pos_step_sl_P.AnalogInput_p1);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
  MW_pinModeOutput(pos_step_sl_P.PWM_pinNumber);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S3>/PWM' */
  MW_pinModeOutput(pos_step_sl_P.PWM_pinNumber_f);
}

/* Model terminate function */
void pos_step_sl_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
