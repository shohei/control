/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: pos_step_sl.h
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

#ifndef RTW_HEADER_pos_step_sl_h_
#define RTW_HEADER_pos_step_sl_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef pos_step_sl_COMMON_INCLUDES_
# define pos_step_sl_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "dt_info.h"
#include "ext_work.h"
#include "arduino_analoginput_lct.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* pos_step_sl_COMMON_INCLUDES_ */

#include "pos_step_sl_types.h"

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
  real_T VectorConcatenate[2];         /* '<Root>/Vector Concatenate' */
  real_T Gain;                         /* '<Root>/Gain' */
} B_pos_step_sl_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} DW_pos_step_sl_T;

/* Parameters (auto storage) */
struct P_pos_step_sl_T_ {
  real_T Kp_id;                        /* Variable: Kp_id
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T r;                            /* Variable: r
                                        * Referenced by: '<Root>/Constant'
                                        */
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S2>/PWM'
                                        */
  uint32_T PWM_pinNumber_f;            /* Mask Parameter: PWM_pinNumber_f
                                        * Referenced by: '<S3>/PWM'
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
  real_T Constant_Value;               /* Expression: -2.5
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Gain3_Gain;                   /* Expression: (42/42)*57.3
                                        * Referenced by: '<S1>/Gain3'
                                        */
  real_T Gain_Gain;                    /* Expression: 255/5
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 255
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: 255
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  uint32_T AnalogInput_p1;             /* Computed Parameter: AnalogInput_p1
                                        * Referenced by: '<S1>/Analog Input'
                                        */
  uint16_T Gain2_Gain;                 /* Computed Parameter: Gain2_Gain
                                        * Referenced by: '<S1>/Gain2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_pos_step_sl_T {
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
extern P_pos_step_sl_T pos_step_sl_P;

/* Block signals (auto storage) */
extern B_pos_step_sl_T pos_step_sl_B;

/* Block states (auto storage) */
extern DW_pos_step_sl_T pos_step_sl_DW;

/* Model entry point functions */
extern void pos_step_sl_initialize(void);
extern void pos_step_sl_output(void);
extern void pos_step_sl_update(void);
extern void pos_step_sl_terminate(void);

/* Real-time Model object */
extern RT_MODEL_pos_step_sl_T *const pos_step_sl_M;

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
 * '<Root>' : 'pos_step_sl'
 * '<S1>'   : 'pos_step_sl/Servo Motor  '
 * '<S2>'   : 'pos_step_sl/Servo Motor  /PWM'
 * '<S3>'   : 'pos_step_sl/Servo Motor  /PWM1'
 */
#endif                                 /* RTW_HEADER_pos_step_sl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
