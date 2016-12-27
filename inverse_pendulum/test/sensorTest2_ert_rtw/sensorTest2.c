/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sensorTest2.c
 *
 * Code generated for Simulink model 'sensorTest2'.
 *
 * Model version                  : 1.22
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Sat Dec 24 17:09:55 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sensorTest2.h"
#include "sensorTest2_private.h"
#include "sensorTest2_dt.h"

/* Block signals (auto storage) */
B_sensorTest2_T sensorTest2_B;

/* Block states (auto storage) */
DW_sensorTest2_T sensorTest2_DW;

/* Real-time model */
RT_MODEL_sensorTest2_T sensorTest2_M_;
RT_MODEL_sensorTest2_T *const sensorTest2_M = &sensorTest2_M_;

/* Model step function */
void sensorTest2_step(void)
{
  /* S-Function (mpu6050_2): '<Root>/S-Function Builder' */
  mpu6050_2_Outputs_wrapper( &sensorTest2_B.SFunctionBuilder[0],
    &sensorTest2_DW.SFunctionBuilder_DSTATE);

  /* S-Function "mpu6050_2_wrapper" Block: <Root>/S-Function Builder */
  mpu6050_2_Update_wrapper( &sensorTest2_B.SFunctionBuilder[0],
    &sensorTest2_DW.SFunctionBuilder_DSTATE);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.05s, 0.0s] */
    rtExtModeUpload(0, sensorTest2_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.05s, 0.0s] */
    if ((rtmGetTFinal(sensorTest2_M)!=-1) &&
        !((rtmGetTFinal(sensorTest2_M)-sensorTest2_M->Timing.taskTime0) >
          sensorTest2_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(sensorTest2_M, "Simulation finished");
    }

    if (rtmGetStopRequested(sensorTest2_M)) {
      rtmSetErrorStatus(sensorTest2_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  sensorTest2_M->Timing.taskTime0 =
    (++sensorTest2_M->Timing.clockTick0) * sensorTest2_M->Timing.stepSize0;
}

/* Model initialize function */
void sensorTest2_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)sensorTest2_M, 0,
                sizeof(RT_MODEL_sensorTest2_T));
  rtmSetTFinal(sensorTest2_M, -1);
  sensorTest2_M->Timing.stepSize0 = 0.05;

  /* External mode info */
  sensorTest2_M->Sizes.checksums[0] = (3431122145U);
  sensorTest2_M->Sizes.checksums[1] = (3211959410U);
  sensorTest2_M->Sizes.checksums[2] = (1805364270U);
  sensorTest2_M->Sizes.checksums[3] = (1788501227U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    sensorTest2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(sensorTest2_M->extModeInfo,
      &sensorTest2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(sensorTest2_M->extModeInfo,
                        sensorTest2_M->Sizes.checksums);
    rteiSetTPtr(sensorTest2_M->extModeInfo, rtmGetTPtr(sensorTest2_M));
  }

  /* block I/O */
  (void) memset(((void *) &sensorTest2_B), 0,
                sizeof(B_sensorTest2_T));

  /* states (dwork) */
  (void) memset((void *)&sensorTest2_DW, 0,
                sizeof(DW_sensorTest2_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    sensorTest2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;
  }

  /* S-Function Block: <Root>/S-Function Builder */
  {
    real_T initVector[1] = { 0 };

    {
      int_T i1;
      for (i1=0; i1 < 1; i1++) {
        sensorTest2_DW.SFunctionBuilder_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void sensorTest2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
