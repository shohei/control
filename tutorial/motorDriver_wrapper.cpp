

/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif

/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#ifndef MATLAB_MEX_FILE
#include <Arduino.h>
int m1_1 = 4;
int m1_2 = 5;
int m1_pwm = 6;
int m2_1 = 7;
int m2_2 = 8;
int m2_pwm = 3;
#endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output functions
 *
 */
extern "C" void motorDriver_Outputs_wrapper(const int8_T *speed1,
			const int8_T *speed2,
			const int8_T *direction1,
			const int8_T *direction2,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
*/
if(xD[0]==1){
#ifndef MATLAB_MEX_FILE
    analogWrite(m1_pwm,*speed1);
    analogWrite(m2_pwm,*speed2);    
    switch(*direction1){
        case 0:
            digitalWrite(m1_1,LOW);
            digitalWrite(m1_2,LOW);
            break;
        case 1:
            digitalWrite(m1_1,HIGH);
            digitalWrite(m1_2,LOW);
            break;
        case 2:
            digitalWrite(m1_1,LOW);
            digitalWrite(m1_2,HIGH);
            break;
    }
    switch(*direction2){
        case 0:
            digitalWrite(m2_1,LOW);
            digitalWrite(m2_2,LOW);
            break;
        case 1:
            digitalWrite(m2_1,LOW);
            digitalWrite(m2_2,HIGH);
            break;
        case 2:
            digitalWrite(m2_1,HIGH);
            digitalWrite(m2_2,LOW);
            break;
    }        
#endif
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
  * Updates function
  *
  */
extern "C" void motorDriver_Update_wrapper(const int8_T *speed1,
			const int8_T *speed2,
			const int8_T *direction1,
			const int8_T *direction2,
			real_T *xD)
{
  /* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Code example
 *   xD[0] = u0[0];
 */
if(xD[0]!=1){
    #ifndef MATLAB_MEX_FILE
    pinMode(m1_1,OUTPUT); 
    pinMode(m1_2,OUTPUT);
    pinMode(m1_pwm,OUTPUT);
    pinMode(m2_1,OUTPUT);
    pinMode(m2_2,OUTPUT);
    pinMode(m2_pwm,OUTPUT);
    #endif
    xD[0]=1;
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}
