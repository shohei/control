/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mpu6050test.h
 *
 * Code generated for Simulink model 'mpu6050test'.
 *
 * Model version                  : 1.9
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Wed Dec 21 16:37:07 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_mpu6050test_h_
#define RTW_HEADER_mpu6050test_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef mpu6050test_COMMON_INCLUDES_
# define mpu6050test_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#endif                                 /* mpu6050test_COMMON_INCLUDES_ */

#include "mpu6050test_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T SFunctionBuilder_o1;          /* '<Root>/S-Function Builder' */
  real_T SFunctionBuilder_o2;          /* '<Root>/S-Function Builder' */
  real_T SFunctionBuilder_o3;          /* '<Root>/S-Function Builder' */
  real_T VectorConcatenate[3];         /* '<Root>/Vector Concatenate' */
} B_mpu6050test_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T SFunctionBuilder_DSTATE;      /* '<Root>/S-Function Builder' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */
} DW_mpu6050test_T;

/* Real-time Model Data Structure */
struct tag_RTM_mpu6050test_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block signals (auto storage) */
extern B_mpu6050test_T mpu6050test_B;

/* Block states (auto storage) */
extern DW_mpu6050test_T mpu6050test_DW;

/* Model entry point functions */
extern void mpu6050test_initialize(void);
extern void mpu6050test_step(void);
extern void mpu6050test_terminate(void);

/* Real-time Model object */
extern RT_MODEL_mpu6050test_T *const mpu6050test_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'mpu6050test'
 */
#endif                                 /* RTW_HEADER_mpu6050test_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
