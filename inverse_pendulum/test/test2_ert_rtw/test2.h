/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test2.h
 *
 * Code generated for Simulink model 'test2'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Wed Dec 21 14:50:19 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_test2_h_
#define RTW_HEADER_test2_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef test2_COMMON_INCLUDES_
# define test2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "arduino_digitaloutput_lct.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* test2_COMMON_INCLUDES_ */

#include "test2_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "MW_target_hardware_resources.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

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
  int8_T DataTypeConversion3;          /* '<Root>/Data Type Conversion3' */
  int8_T DataTypeConversion2;          /* '<Root>/Data Type Conversion2' */
  int8_T Switch;                       /* '<Root>/Switch' */
  int8_T SFunctionBuilder_o1;          /* '<Root>/S-Function Builder' */
  int8_T SFunctionBuilder_o2;          /* '<Root>/S-Function Builder' */
  int8_T SFunctionBuilder_o3;          /* '<Root>/S-Function Builder' */
  int8_T SFunctionBuilder_o4;          /* '<Root>/S-Function Builder' */
  int8_T SFunctionBuilder_o5;          /* '<Root>/S-Function Builder' */
  int8_T SFunctionBuilder_o6;          /* '<Root>/S-Function Builder' */
  int8_T VectorConcatenate[3];         /* '<Root>/Vector Concatenate' */
} B_test2_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T SFunctionBuilder_DSTATE;      /* '<Root>/S-Function Builder' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} DW_test2_T;

/* Parameters (auto storage) */
struct P_test2_T_ {
  uint32_T DigitalOutput_pinNumber;    /* Mask Parameter: DigitalOutput_pinNumber
                                        * Referenced by: '<S1>/Digital Output'
                                        */
  uint32_T DigitalOutput_pinNum_oq3g4mumzf;/* Mask Parameter: DigitalOutput_pinNum_oq3g4mumzf
                                            * Referenced by: '<S2>/Digital Output'
                                            */
  uint32_T DigitalOutput_pinNum_lq4ka0n3cr;/* Mask Parameter: DigitalOutput_pinNum_lq4ka0n3cr
                                            * Referenced by: '<S3>/Digital Output'
                                            */
  uint32_T DigitalOutput_pinNum_bbnhqscnhg;/* Mask Parameter: DigitalOutput_pinNum_bbnhqscnhg
                                            * Referenced by: '<S4>/Digital Output'
                                            */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S5>/PWM'
                                        */
  uint32_T PWM_pinNumber_cmnfljccqg;   /* Mask Parameter: PWM_pinNumber_cmnfljccqg
                                        * Referenced by: '<S6>/PWM'
                                        */
  real_T Constant5_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant_Value;               /* Expression: 254
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 254
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
struct tag_RTM_test2_T {
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
    uint16_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (auto storage) */
extern P_test2_T test2_P;

/* Block signals (auto storage) */
extern B_test2_T test2_B;

/* Block states (auto storage) */
extern DW_test2_T test2_DW;

/* Model entry point functions */
extern void test2_initialize(void);
extern void test2_step(void);
extern void test2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_test2_T *const test2_M;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Data Type Conversion10' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion5' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion6' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion7' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion8' : Eliminate redundant data type conversion
 * Block '<Root>/Data Type Conversion9' : Eliminate redundant data type conversion
 */

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
 * '<Root>' : 'test2'
 * '<S1>'   : 'test2/Digital Output'
 * '<S2>'   : 'test2/Digital Output1'
 * '<S3>'   : 'test2/Digital Output2'
 * '<S4>'   : 'test2/Digital Output3'
 * '<S5>'   : 'test2/PWM'
 * '<S6>'   : 'test2/PWM1'
 */
#endif                                 /* RTW_HEADER_test2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
