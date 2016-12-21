/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test3.h
 *
 * Code generated for Simulink model 'test3'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Wed Dec 21 15:59:48 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_test3_h_
#define RTW_HEADER_test3_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef test3_COMMON_INCLUDES_
# define test3_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* test3_COMMON_INCLUDES_ */

#include "test3_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  int8_T DataTypeConversion3;          /* '<Root>/Data Type Conversion3' */
  int8_T DataTypeConversion2;          /* '<Root>/Data Type Conversion2' */
  int8_T Switch;                       /* '<Root>/Switch' */
} B_test3_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T SFunctionBuilder_DSTATE;      /* '<Root>/S-Function Builder' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} DW_test3_T;

/* Parameters (auto storage) */
struct P_test3_T_ {
  real_T Constant5_Value;              /* Expression: 2
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant_Value;               /* Expression: 255
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 255
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_test3_T {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern P_test3_T test3_P;

/* Block signals (auto storage) */
extern B_test3_T test3_B;

/* Block states (auto storage) */
extern DW_test3_T test3_DW;

/* Model entry point functions */
extern void test3_initialize(void);
extern void test3_step(void);
extern void test3_terminate(void);

/* Real-time Model object */
extern RT_MODEL_test3_T *const test3_M;

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
 * '<Root>' : 'test3'
 */
#endif                                 /* RTW_HEADER_test3_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
