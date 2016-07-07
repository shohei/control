/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: sine_pwm.h
 *
 * Code generated for Simulink model 'sine_pwm'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 19 2015)
 * C/C++ source code generated on : Fri Dec  4 15:43:14 2015
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_sine_pwm_h_
#define RTW_HEADER_sine_pwm_h_
#include <math.h>
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef sine_pwm_COMMON_INCLUDES_
# define sine_pwm_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* sine_pwm_COMMON_INCLUDES_ */

#include "sine_pwm_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
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
  real_T SineWave;                     /* '<Root>/Sine Wave' */
} B_sine_pwm_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  int32_T counter;                     /* '<Root>/Sine Wave' */
} DW_sine_pwm_T;

/* Parameters (auto storage) */
struct P_sine_pwm_T_ {
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S1>/PWM'
                                        */
  real_T SineWave_Amp;                 /* Expression: 255
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 128
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_NumSamp;             /* Expression: 10
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Offset;              /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_sine_pwm_T {
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

/* Block parameters (auto storage) */
extern P_sine_pwm_T sine_pwm_P;

/* Block signals (auto storage) */
extern B_sine_pwm_T sine_pwm_B;

/* Block states (auto storage) */
extern DW_sine_pwm_T sine_pwm_DW;

/* Model entry point functions */
extern void sine_pwm_initialize(void);
extern void sine_pwm_output(void);
extern void sine_pwm_update(void);
extern void sine_pwm_terminate(void);

/* Real-time Model object */
extern RT_MODEL_sine_pwm_T *const sine_pwm_M;

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
 * '<Root>' : 'sine_pwm'
 * '<S1>'   : 'sine_pwm/PWM'
 */
#endif                                 /* RTW_HEADER_sine_pwm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
