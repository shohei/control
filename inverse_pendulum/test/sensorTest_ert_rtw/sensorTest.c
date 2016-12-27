/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sensorTest.c
 *
 * Code generated for Simulink model 'sensorTest'.
 *
 * Model version                  : 1.11
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Fri Dec 23 10:33:40 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sensorTest.h"
#include "sensorTest_private.h"
#include "sensorTest_dt.h"

/* Block signals (auto storage) */
B_sensorTest_T sensorTest_B;

/* Block states (auto storage) */
DW_sensorTest_T sensorTest_DW;

/* Real-time model */
RT_MODEL_sensorTest_T sensorTest_M_;
RT_MODEL_sensorTest_T *const sensorTest_M = &sensorTest_M_;

/* Model step function */
void sensorTest_step(void)
{
  /* S-Function (mpu6050_2): '<Root>/S-Function Builder' */
  mpu6050_2_Outputs_wrapper( &sensorTest_B.SFunctionBuilder[0],
    &sensorTest_DW.SFunctionBuilder_DSTATE);

  /* S-Function "mpu6050_2_wrapper" Block: <Root>/S-Function Builder */
  mpu6050_2_Update_wrapper( &sensorTest_B.SFunctionBuilder[0],
    &sensorTest_DW.SFunctionBuilder_DSTATE);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.1s, 0.0s] */
    rtExtModeUpload(0, sensorTest_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(sensorTest_M)!=-1) &&
        !((rtmGetTFinal(sensorTest_M)-sensorTest_M->Timing.taskTime0) >
          sensorTest_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(sensorTest_M, "Simulation finished");
    }

    if (rtmGetStopRequested(sensorTest_M)) {
      rtmSetErrorStatus(sensorTest_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  sensorTest_M->Timing.taskTime0 =
    (++sensorTest_M->Timing.clockTick0) * sensorTest_M->Timing.stepSize0;
}

/* Model initialize function */
void sensorTest_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)sensorTest_M, 0,
                sizeof(RT_MODEL_sensorTest_T));
  rtmSetTFinal(sensorTest_M, -1);
  sensorTest_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  sensorTest_M->Sizes.checksums[0] = (1951388715U);
  sensorTest_M->Sizes.checksums[1] = (619853423U);
  sensorTest_M->Sizes.checksums[2] = (2611292288U);
  sensorTest_M->Sizes.checksums[3] = (2846917587U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    sensorTest_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(sensorTest_M->extModeInfo,
      &sensorTest_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(sensorTest_M->extModeInfo, sensorTest_M->Sizes.checksums);
    rteiSetTPtr(sensorTest_M->extModeInfo, rtmGetTPtr(sensorTest_M));
  }

  /* block I/O */
  (void) memset(((void *) &sensorTest_B), 0,
                sizeof(B_sensorTest_T));

  /* states (dwork) */
  (void) memset((void *)&sensorTest_DW, 0,
                sizeof(DW_sensorTest_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    sensorTest_M->SpecialInfo.mappingInfo = (&dtInfo);
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
        sensorTest_DW.SFunctionBuilder_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void sensorTest_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
