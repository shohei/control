/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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

#include "mpu6050test.h"
#include "rtwtypes.h"
#include <ext_work.h>
#include <ext_svr.h>
#include <ext_share.h>
#include <updown.h>

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  mpu6050test_step();

  /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

  cli();

#endif;

  OverrunFlag--;
  rtExtModeCheckEndTrigger();
}

int main(void)
{
  volatile boolean_T runModel = 1;
  float modelBaseRate = 0.2;
  float systemClock = 0;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(mpu6050test_M, 0);

  /* initialize external mode */
  rtParseArgsForExtMode(0, NULL);
  mpu6050test_initialize();
  sei ();

  /* External mode */
  rtSetTFinalForExtMode(&rtmGetTFinal(mpu6050test_M));
  rtExtModeCheckInit(1);

  {
    boolean_T rtmStopReq = false;
    rtExtModeWaitForStartPkt(mpu6050test_M->extModeInfo, 1, &rtmStopReq);
    if (rtmStopReq) {
      rtmSetStopRequested(mpu6050test_M, true);
    }
  }

  rtERTExtModeStartMsg();
  cli();
  configureArduinoAVRTimer();
  runModel =
    (rtmGetErrorStatus(mpu6050test_M) == (NULL)) && !rtmGetStopRequested
    (mpu6050test_M);

#ifndef _MW_ARDUINO_LOOP_

  sei();

#endif;

  sei ();
  while (runModel) {
    /* External mode */
    {
      boolean_T rtmStopReq = false;
      rtExtModeOneStep(mpu6050test_M->extModeInfo, 1, &rtmStopReq);
      if (rtmStopReq) {
        rtmSetStopRequested(mpu6050test_M, true);
      }
    }

    runModel =
      (rtmGetErrorStatus(mpu6050test_M) == (NULL)) && !rtmGetStopRequested
      (mpu6050test_M);
    runModel = runModel && MW_Arduino_Loop();
  }

  rtExtModeShutdown(1);

  /* Disable rt_OneStep() here */

  /* Terminate model */
  mpu6050test_terminate();
  cli();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
