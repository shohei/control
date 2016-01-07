/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: velo_pi.c
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
#include "velo_pi_dt.h"

/* Block signals (auto storage) */
B_velo_pi_T velo_pi_B;

/* Continuous states */
X_velo_pi_T velo_pi_X;

/* Block states (auto storage) */
DW_velo_pi_T velo_pi_DW;

/* Real-time model */
RT_MODEL_velo_pi_T velo_pi_M_;
RT_MODEL_velo_pi_T *const velo_pi_M = &velo_pi_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  velo_pi_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  velo_pi_output();
  velo_pi_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  velo_pi_output();
  velo_pi_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function */
void velo_pi_output(void)
{
  uint16_T rtb_AnalogInput_0;
  real_T rtb_PulseGenerator;
  real_T rtb_TransferFcn;
  real_T rtb_Gain_b;
  if (rtmIsMajorTimeStep(velo_pi_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&velo_pi_M->solverInfo,((velo_pi_M->Timing.clockTick0+
      1)*velo_pi_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(velo_pi_M)) {
    velo_pi_M->Timing.t[0] = rtsiGetT(&velo_pi_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(velo_pi_M)) {
    /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
    rtb_PulseGenerator = (velo_pi_DW.clockTickCounter <
                          velo_pi_P.PulseGenerator_Duty) &&
      (velo_pi_DW.clockTickCounter >= 0L) ? velo_pi_P.PulseGenerator_Amp : 0.0;
    if (velo_pi_DW.clockTickCounter >= velo_pi_P.PulseGenerator_Period - 1.0) {
      velo_pi_DW.clockTickCounter = 0L;
    } else {
      velo_pi_DW.clockTickCounter++;
    }

    /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

    /* Sum: '<Root>/Sum1' incorporates:
     *  Constant: '<Root>/Constant2'
     */
    velo_pi_B.Sum1 = rtb_PulseGenerator + velo_pi_P.u_offset;
  }

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn1' */
  velo_pi_B.VectorConcatenate[0] = velo_pi_B.Sum1;
  if (rtmIsMajorTimeStep(velo_pi_M)) {
    /* S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input' */
    rtb_AnalogInput_0 = MW_analogRead(velo_pi_P.AnalogInput_p1);

    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  Gain: '<S1>/Gain1'
     *  S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input'
     */
    velo_pi_B.DataTypeConversion = (real_T)((uint32_T)velo_pi_P.Gain1_Gain *
      rtb_AnalogInput_0) * 1.1920928955078125E-7;
  }

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn2' */
  velo_pi_B.VectorConcatenate[1] = velo_pi_B.DataTypeConversion;

  /* TransferFcn: '<Root>/Transfer Fcn' */
  rtb_TransferFcn = velo_pi_P.TransferFcn_C * velo_pi_X.TransferFcn_CSTATE;

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn3' */
  velo_pi_B.VectorConcatenate[2] = rtb_TransferFcn;
  if (rtmIsMajorTimeStep(velo_pi_M)) {
    /* Sum: '<Root>/Sum2' */
    velo_pi_B.Sum2 = velo_pi_B.Sum1 - velo_pi_B.DataTypeConversion;

    /* Gain: '<Root>/Gain1' */
    velo_pi_B.Gain1 = velo_pi_P.Kp * velo_pi_B.Sum2;
  }

  /* Sum: '<Root>/Sum3' incorporates:
   *  Gain: '<Root>/Gain'
   *  Integrator: '<Root>/Integrator'
   */
  rtb_Gain_b = velo_pi_P.Ki * velo_pi_X.Integrator_CSTATE + velo_pi_B.Gain1;

  /* SignalConversion: '<Root>/ConcatBufferAtVector Concatenate1In1' */
  velo_pi_B.VectorConcatenate1[0] = rtb_Gain_b;

  /* Sum: '<Root>/Sum5' */
  velo_pi_B.Sum5 = velo_pi_B.Sum1 - rtb_TransferFcn;

  /* Sum: '<Root>/Sum4' incorporates:
   *  Gain: '<Root>/Gain2'
   *  Gain: '<Root>/Gain3'
   *  Integrator: '<Root>/Integrator1'
   */
  rtb_PulseGenerator = velo_pi_P.Ki * velo_pi_X.Integrator1_CSTATE +
    velo_pi_P.Kp * velo_pi_B.Sum5;

  /* SignalConversion: '<Root>/ConcatBufferAtVector Concatenate1In2' */
  velo_pi_B.VectorConcatenate1[1] = rtb_PulseGenerator;
  if (rtmIsMajorTimeStep(velo_pi_M)) {
  }

  /* Saturate: '<Root>/Saturation' */
  if (rtb_Gain_b > velo_pi_P.Saturation_UpperSat) {
    rtb_Gain_b = velo_pi_P.Saturation_UpperSat;
  } else {
    if (rtb_Gain_b < velo_pi_P.Saturation_LowerSat) {
      rtb_Gain_b = velo_pi_P.Saturation_LowerSat;
    }
  }

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Gain: '<S1>/Gain'
   *  Saturate: '<Root>/Saturation'
   */
  rtb_TransferFcn = velo_pi_P.Gain_Gain * rtb_Gain_b;
  if (rtb_TransferFcn < 256.0) {
    if (rtb_TransferFcn >= 0.0) {
      velo_pi_B.DataTypeConversion_d = (uint8_T)rtb_TransferFcn;
    } else {
      velo_pi_B.DataTypeConversion_d = 0U;
    }
  } else {
    velo_pi_B.DataTypeConversion_d = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S2>/Data Type Conversion' */
  if (rtmIsMajorTimeStep(velo_pi_M)) {
    /* S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
    MW_analogWrite(velo_pi_P.PWM_pinNumber, velo_pi_B.DataTypeConversion_d);
  }

  /* Saturate: '<Root>/Saturation1' */
  if (rtb_PulseGenerator > velo_pi_P.Saturation1_UpperSat) {
    rtb_PulseGenerator = velo_pi_P.Saturation1_UpperSat;
  } else {
    if (rtb_PulseGenerator < velo_pi_P.Saturation1_LowerSat) {
      rtb_PulseGenerator = velo_pi_P.Saturation1_LowerSat;
    }
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant1'
   *  Saturate: '<Root>/Saturation1'
   */
  velo_pi_B.Sum = rtb_PulseGenerator - velo_pi_P.u_offset;
}

/* Model update function */
void velo_pi_update(void)
{
  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(velo_pi_M)!=-1) &&
        !((rtmGetTFinal(velo_pi_M)-((velo_pi_M->Timing.clockTick1) * 0.02)) >
          ((velo_pi_M->Timing.clockTick1) * 0.02) * (DBL_EPSILON))) {
      rtmSetErrorStatus(velo_pi_M, "Simulation finished");
    }

    if (rtmGetStopRequested(velo_pi_M)) {
      rtmSetErrorStatus(velo_pi_M, "Simulation finished");
    }
  }

  if (rtmIsMajorTimeStep(velo_pi_M)) {
    rt_ertODEUpdateContinuousStates(&velo_pi_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ++velo_pi_M->Timing.clockTick0;
  velo_pi_M->Timing.t[0] = rtsiGetSolverStopTime(&velo_pi_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.02s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.02, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    velo_pi_M->Timing.clockTick1++;
  }
}

/* Derivatives for root system: '<Root>' */
void velo_pi_derivatives(void)
{
  XDot_velo_pi_T *_rtXdot;
  _rtXdot = ((XDot_velo_pi_T *) velo_pi_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += velo_pi_P.TransferFcn_A *
    velo_pi_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += velo_pi_B.Sum;

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = velo_pi_B.Sum2;

  /* Derivatives for Integrator: '<Root>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = velo_pi_B.Sum5;
}

/* Model initialize function */
void velo_pi_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)velo_pi_M, 0,
                sizeof(RT_MODEL_velo_pi_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&velo_pi_M->solverInfo, &velo_pi_M->Timing.simTimeStep);
    rtsiSetTPtr(&velo_pi_M->solverInfo, &rtmGetTPtr(velo_pi_M));
    rtsiSetStepSizePtr(&velo_pi_M->solverInfo, &velo_pi_M->Timing.stepSize0);
    rtsiSetdXPtr(&velo_pi_M->solverInfo, &velo_pi_M->ModelData.derivs);
    rtsiSetContStatesPtr(&velo_pi_M->solverInfo, (real_T **)
                         &velo_pi_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&velo_pi_M->solverInfo,
      &velo_pi_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&velo_pi_M->solverInfo, (&rtmGetErrorStatus(velo_pi_M)));
    rtsiSetRTModelPtr(&velo_pi_M->solverInfo, velo_pi_M);
  }

  rtsiSetSimTimeStep(&velo_pi_M->solverInfo, MAJOR_TIME_STEP);
  velo_pi_M->ModelData.intgData.y = velo_pi_M->ModelData.odeY;
  velo_pi_M->ModelData.intgData.f[0] = velo_pi_M->ModelData.odeF[0];
  velo_pi_M->ModelData.intgData.f[1] = velo_pi_M->ModelData.odeF[1];
  velo_pi_M->ModelData.intgData.f[2] = velo_pi_M->ModelData.odeF[2];
  velo_pi_M->ModelData.contStates = ((X_velo_pi_T *) &velo_pi_X);
  rtsiSetSolverData(&velo_pi_M->solverInfo, (void *)
                    &velo_pi_M->ModelData.intgData);
  rtsiSetSolverName(&velo_pi_M->solverInfo,"ode3");
  rtmSetTPtr(velo_pi_M, &velo_pi_M->Timing.tArray[0]);
  rtmSetTFinal(velo_pi_M, 10.0);
  velo_pi_M->Timing.stepSize0 = 0.02;

  /* External mode info */
  velo_pi_M->Sizes.checksums[0] = (2706613671U);
  velo_pi_M->Sizes.checksums[1] = (3810933888U);
  velo_pi_M->Sizes.checksums[2] = (3806631341U);
  velo_pi_M->Sizes.checksums[3] = (2013334830U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    velo_pi_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(velo_pi_M->extModeInfo,
      &velo_pi_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(velo_pi_M->extModeInfo, velo_pi_M->Sizes.checksums);
    rteiSetTPtr(velo_pi_M->extModeInfo, rtmGetTPtr(velo_pi_M));
  }

  /* block I/O */
  (void) memset(((void *) &velo_pi_B), 0,
                sizeof(B_velo_pi_T));

  /* states (continuous) */
  {
    (void) memset((void *)&velo_pi_X, 0,
                  sizeof(X_velo_pi_T));
  }

  /* states (dwork) */
  (void) memset((void *)&velo_pi_DW, 0,
                sizeof(DW_velo_pi_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    velo_pi_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  velo_pi_DW.clockTickCounter = -100L;

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input' */
  MW_pinModeAnalogInput(velo_pi_P.AnalogInput_p1);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
  MW_pinModeOutput(velo_pi_P.PWM_pinNumber);

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  velo_pi_X.TransferFcn_CSTATE = 0.0;

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  velo_pi_X.Integrator_CSTATE = velo_pi_P.Integrator_IC;

  /* InitializeConditions for Integrator: '<Root>/Integrator1' */
  velo_pi_X.Integrator1_CSTATE = velo_pi_P.Integrator1_IC;
}

/* Model terminate function */
void velo_pi_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
