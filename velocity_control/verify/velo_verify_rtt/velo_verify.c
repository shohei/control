/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: velo_verify.c
 *
 * Code generated for Simulink model 'velo_verify'.
 *
 * Model version                  : 1.14
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 19 2015)
 * C/C++ source code generated on : Wed Dec 23 15:43:08 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "velo_verify.h"
#include "velo_verify_private.h"
#include "velo_verify_dt.h"

/* Block signals (auto storage) */
B_velo_verify_T velo_verify_B;

/* Continuous states */
X_velo_verify_T velo_verify_X;

/* Block states (auto storage) */
DW_velo_verify_T velo_verify_DW;

/* Real-time model */
RT_MODEL_velo_verify_T velo_verify_M_;
RT_MODEL_velo_verify_T *const velo_verify_M = &velo_verify_M_;

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
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  velo_verify_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  velo_verify_output();
  velo_verify_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  velo_verify_output();
  velo_verify_derivatives();

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
void velo_verify_output(void)
{
  uint16_T rtb_AnalogInput_0;
  real_T rtb_Step;
  real_T tmp;
  uint8_T tmp_0;
  if (rtmIsMajorTimeStep(velo_verify_M)) {
    /* set solver stop time */
    rtsiSetSolverStopTime(&velo_verify_M->solverInfo,
                          ((velo_verify_M->Timing.clockTick0+1)*
      velo_verify_M->Timing.stepSize0));
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(velo_verify_M)) {
    velo_verify_M->Timing.t[0] = rtsiGetT(&velo_verify_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(velo_verify_M)) {
    /* Step: '<Root>/Step' */
    if (((velo_verify_M->Timing.clockTick1) * 0.033333333333333333) <
        velo_verify_P.Step_Time) {
      rtb_Step = velo_verify_P.Step_Y0;
    } else {
      rtb_Step = velo_verify_P.Step_YFinal;
    }

    /* End of Step: '<Root>/Step' */

    /* DataTypeConversion: '<S1>/Data Type Conversion1' */
    velo_verify_B.VectorConcatenate[0] = rtb_Step;

    /* S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input' */
    rtb_AnalogInput_0 = MW_analogRead(velo_verify_P.AnalogInput_p1);

    /* DataTypeConversion: '<S1>/Data Type Conversion' incorporates:
     *  Gain: '<S1>/Gain1'
     *  S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input'
     */
    velo_verify_B.VectorConcatenate[1] = (real_T)((uint32_T)
      velo_verify_P.Gain1_Gain * rtb_AnalogInput_0) * 1.1920928955078125E-7;
  }

  /* TransferFcn: '<Root>/Transfer Fcn' */
  velo_verify_B.VectorConcatenate[2] = 0.0;
  velo_verify_B.VectorConcatenate[2] += velo_verify_P.TransferFcn_C *
    velo_verify_X.TransferFcn_CSTATE;
  if (rtmIsMajorTimeStep(velo_verify_M)) {
    /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
     *  Gain: '<S1>/Gain'
     */
    tmp = velo_verify_P.Gain_Gain * rtb_Step;
    if (tmp < 256.0) {
      if (tmp >= 0.0) {
        tmp_0 = (uint8_T)tmp;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    /* End of DataTypeConversion: '<S2>/Data Type Conversion' */

    /* S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
    MW_analogWrite(velo_verify_P.PWM_pinNumber, tmp_0);

    /* Sum: '<Root>/Sum' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    velo_verify_B.Sum = rtb_Step - velo_verify_P.u_offset;
  }
}

/* Model update function */
void velo_verify_update(void)
{
  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(velo_verify_M)!=-1) &&
        !((rtmGetTFinal(velo_verify_M)-((velo_verify_M->Timing.clockTick1) *
           0.033333333333333333)) > ((velo_verify_M->Timing.clockTick1) *
          0.033333333333333333) * (DBL_EPSILON))) {
      rtmSetErrorStatus(velo_verify_M, "Simulation finished");
    }

    if (rtmGetStopRequested(velo_verify_M)) {
      rtmSetErrorStatus(velo_verify_M, "Simulation finished");
    }
  }

  if (rtmIsMajorTimeStep(velo_verify_M)) {
    rt_ertODEUpdateContinuousStates(&velo_verify_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ++velo_verify_M->Timing.clockTick0;
  velo_verify_M->Timing.t[0] = rtsiGetSolverStopTime(&velo_verify_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.033333333333333333s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.033333333333333333, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    velo_verify_M->Timing.clockTick1++;
  }
}

/* Derivatives for root system: '<Root>' */
void velo_verify_derivatives(void)
{
  XDot_velo_verify_T *_rtXdot;
  _rtXdot = ((XDot_velo_verify_T *) velo_verify_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += velo_verify_P.TransferFcn_A *
    velo_verify_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += velo_verify_B.Sum;
}

/* Model initialize function */
void velo_verify_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)velo_verify_M, 0,
                sizeof(RT_MODEL_velo_verify_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&velo_verify_M->solverInfo,
                          &velo_verify_M->Timing.simTimeStep);
    rtsiSetTPtr(&velo_verify_M->solverInfo, &rtmGetTPtr(velo_verify_M));
    rtsiSetStepSizePtr(&velo_verify_M->solverInfo,
                       &velo_verify_M->Timing.stepSize0);
    rtsiSetdXPtr(&velo_verify_M->solverInfo, &velo_verify_M->ModelData.derivs);
    rtsiSetContStatesPtr(&velo_verify_M->solverInfo, (real_T **)
                         &velo_verify_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&velo_verify_M->solverInfo,
      &velo_verify_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&velo_verify_M->solverInfo, (&rtmGetErrorStatus
      (velo_verify_M)));
    rtsiSetRTModelPtr(&velo_verify_M->solverInfo, velo_verify_M);
  }

  rtsiSetSimTimeStep(&velo_verify_M->solverInfo, MAJOR_TIME_STEP);
  velo_verify_M->ModelData.intgData.y = velo_verify_M->ModelData.odeY;
  velo_verify_M->ModelData.intgData.f[0] = velo_verify_M->ModelData.odeF[0];
  velo_verify_M->ModelData.intgData.f[1] = velo_verify_M->ModelData.odeF[1];
  velo_verify_M->ModelData.intgData.f[2] = velo_verify_M->ModelData.odeF[2];
  velo_verify_M->ModelData.contStates = ((X_velo_verify_T *) &velo_verify_X);
  rtsiSetSolverData(&velo_verify_M->solverInfo, (void *)
                    &velo_verify_M->ModelData.intgData);
  rtsiSetSolverName(&velo_verify_M->solverInfo,"ode3");
  rtmSetTPtr(velo_verify_M, &velo_verify_M->Timing.tArray[0]);
  rtmSetTFinal(velo_verify_M, 20.0);
  velo_verify_M->Timing.stepSize0 = 0.033333333333333333;

  /* External mode info */
  velo_verify_M->Sizes.checksums[0] = (113473462U);
  velo_verify_M->Sizes.checksums[1] = (4059467475U);
  velo_verify_M->Sizes.checksums[2] = (3775690307U);
  velo_verify_M->Sizes.checksums[3] = (1321234197U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    velo_verify_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(velo_verify_M->extModeInfo,
      &velo_verify_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(velo_verify_M->extModeInfo,
                        velo_verify_M->Sizes.checksums);
    rteiSetTPtr(velo_verify_M->extModeInfo, rtmGetTPtr(velo_verify_M));
  }

  /* block I/O */
  (void) memset(((void *) &velo_verify_B), 0,
                sizeof(B_velo_verify_T));

  /* states (continuous) */
  {
    (void) memset((void *)&velo_verify_X, 0,
                  sizeof(X_velo_verify_T));
  }

  /* states (dwork) */
  (void) memset((void *)&velo_verify_DW, 0,
                sizeof(DW_velo_verify_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    velo_verify_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 16;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Start for S-Function (arduinoanaloginput_sfcn): '<S1>/Analog Input' */
  MW_pinModeAnalogInput(velo_verify_P.AnalogInput_p1);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
  MW_pinModeOutput(velo_verify_P.PWM_pinNumber);

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  velo_verify_X.TransferFcn_CSTATE = 0.0;
}

/* Model terminate function */
void velo_verify_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
