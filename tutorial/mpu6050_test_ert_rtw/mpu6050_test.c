/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mpu6050_test.c
 *
 * Code generated for Simulink model 'mpu6050_test'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Tue Dec 27 10:29:15 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "mpu6050_test.h"
#include "mpu6050_test_private.h"
#include "mpu6050_test_dt.h"

/* Block signals (auto storage) */
B_mpu6050_test_T mpu6050_test_B;

/* Block states (auto storage) */
DW_mpu6050_test_T mpu6050_test_DW;

/* Real-time model */
RT_MODEL_mpu6050_test_T mpu6050_test_M_;
RT_MODEL_mpu6050_test_T *const mpu6050_test_M = &mpu6050_test_M_;

/* Model step function */
void mpu6050_test_step(void)
{
  /* S-Function (mpu6050_sfcn): '<Root>/S-Function Builder' */
  mpu6050_sfcn_Outputs_wrapper( &mpu6050_test_B.VectorConcatenate[0],
    &mpu6050_test_B.VectorConcatenate[1], &mpu6050_test_B.VectorConcatenate[2],
    &mpu6050_test_DW.SFunctionBuilder_DSTATE);

  /* S-Function "mpu6050_sfcn_wrapper" Block: <Root>/S-Function Builder */
  mpu6050_sfcn_Update_wrapper( &mpu6050_test_B.VectorConcatenate[0],
    &mpu6050_test_B.VectorConcatenate[1], &mpu6050_test_B.VectorConcatenate[2],
    &mpu6050_test_DW.SFunctionBuilder_DSTATE);

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.05s, 0.0s] */
    rtExtModeUpload(0, mpu6050_test_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.05s, 0.0s] */
    if ((rtmGetTFinal(mpu6050_test_M)!=-1) &&
        !((rtmGetTFinal(mpu6050_test_M)-mpu6050_test_M->Timing.taskTime0) >
          mpu6050_test_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(mpu6050_test_M, "Simulation finished");
    }

    if (rtmGetStopRequested(mpu6050_test_M)) {
      rtmSetErrorStatus(mpu6050_test_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  mpu6050_test_M->Timing.taskTime0 =
    (++mpu6050_test_M->Timing.clockTick0) * mpu6050_test_M->Timing.stepSize0;
}

/* Model initialize function */
void mpu6050_test_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)mpu6050_test_M, 0,
                sizeof(RT_MODEL_mpu6050_test_T));
  rtmSetTFinal(mpu6050_test_M, -1);
  mpu6050_test_M->Timing.stepSize0 = 0.05;

  /* External mode info */
  mpu6050_test_M->Sizes.checksums[0] = (99469767U);
  mpu6050_test_M->Sizes.checksums[1] = (3943313258U);
  mpu6050_test_M->Sizes.checksums[2] = (1743427976U);
  mpu6050_test_M->Sizes.checksums[3] = (2884586276U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    mpu6050_test_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(mpu6050_test_M->extModeInfo,
      &mpu6050_test_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(mpu6050_test_M->extModeInfo,
                        mpu6050_test_M->Sizes.checksums);
    rteiSetTPtr(mpu6050_test_M->extModeInfo, rtmGetTPtr(mpu6050_test_M));
  }

  /* block I/O */
  (void) memset(((void *) &mpu6050_test_B), 0,
                sizeof(B_mpu6050_test_T));

  /* states (dwork) */
  (void) memset((void *)&mpu6050_test_DW, 0,
                sizeof(DW_mpu6050_test_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    mpu6050_test_M->SpecialInfo.mappingInfo = (&dtInfo);
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
        mpu6050_test_DW.SFunctionBuilder_DSTATE = initVector[0];
      }
    }
  }
}

/* Model terminate function */
void mpu6050_test_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
