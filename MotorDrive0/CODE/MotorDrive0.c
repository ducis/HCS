/** ###################################################################
**     Filename  : MotorDrive0.C
**     Project   : MotorDrive0
**     Processor : MC9S12XDT256BMPV
**     Version   : Driver 01.13
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2010-4-6, 23:23
**     Abstract  :
**         Main module.
**         This module contains user's application code.
**     Settings  :
**     Contents  :
**         No public methods
**
**     (c) Copyright UNIS, a.s. 1997-2008
**     UNIS, a.s.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/
/* MODULE MotorDrive0 */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "PWM0.h"
#include "PWM1.h"
#include "PWM2.h"
#include "PWM3.h"
#include "PWM4.h"
#include "PWM5.h"
#include "FC1.h"
#include "AS1.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "math.h"  
const float delta=2.0943951023931954923084289221863f;
const float doubledelta=4.1887902047863909846168578443727f;
const float doublepi=6.283185307179586476925286766559f;
const short resetDelay=0;
float lead=0.0f;
float pwmPeriod=0.0f;                         
float timecoefficient=0.000001f;//0.000001f;//about 1Hz
void CalculateDuty(float ratio,short *pDuty){
  if(ratio>0){
    pDuty[0]=(short)(ratio*pwmPeriod+0.49f);
    pDuty[1]=0;
  }else if(ratio<0){
    pDuty[0]=0;
    pDuty[1]=(short)(-ratio*pwmPeriod+0.49f);
  }else{
    pDuty[0]=0;
    pDuty[1]=0;
  }
}                
short duty[6]={0,0,0,0,0,0};
void main(void)
{
  /* Write your local variable definition here */
  float phase=0;
  pwmPeriod=PWMPER0;
  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  //PWM0_SetDutyTicks16(0);
  //PWM1_SetDutyTicks16(0);
  //PWM2_SetDutyTicks16(0);
  //PWM3_SetDutyTicks16(0);
  //PWM4_SetDutyTicks16(0);
  //PWM5_SetDutyTicks16(0);
  PWMDTY0=duty[0]&0xff;
  PWMDTY1=duty[1]&0xff;
  PWMDTY2=duty[2]&0xff;
  PWMDTY3=duty[3]&0xff;
  PWMDTY4=duty[4]&0xff;
  PWMDTY5=duty[5]&0xff;
  PWM0_Enable();
  PWM1_Enable();
  PWM2_Enable();
  PWM3_Enable();
  PWM4_Enable();
  PWM5_Enable();        
  
  while(1){
    short i;
    short timepassed;              
    float theta;
    short newduty[6];
    bool bUpdatePWM=0;
    FC1_GetCounterValue(&timepassed);
    theta=fmod(phase+timecoefficient*(float)timepassed,doublepi);
    //ratio[0]=sin(theta);
    //ratio[1]=sin(theta+delta);
    //ratio[2]=sin(theta+doubledelta);
    CalculateDuty(sin(theta),newduty+0);
    CalculateDuty(sin(theta+delta),newduty+2);
    CalculateDuty(sin(theta+doubledelta),newduty+4);
    for(i=0;i<6,!bUpdatePWM;++i){
      bUpdatePWM|=(newduty[i]!=duty[i]);
    }
    if(bUpdatePWM){
      FC1_GetCounterValue(&timepassed);
      FC1_Reset();
      phase=fmod(phase+timecoefficient*(timepassed+resetDelay),doublepi);
      //ratio[0]=sin(phase+lead);
      //ratio[1]=sin(phase+lead+delta);
      //ratio[2]=sin(phase+lead+doubledelta);
      CalculateDuty(sin(phase+lead),duty+0);
      CalculateDuty(sin(phase+lead+delta),duty+2);
      CalculateDuty(sin(phase+lead+doubledelta),duty+4);
      {
        //PWM0_SetDutyTicks16(duty[0]);
        //PWM1_SetDutyTicks16(duty[1]);
        //PWM2_SetDutyTicks16(duty[2]);
        //PWM3_SetDutyTicks16(duty[3]);
        //PWM4_SetDutyTicks16(duty[4]);
        //PWM5_SetDutyTicks16(duty[5]);
          PWMDTY0=duty[0]&0xff;
          PWMDTY1=duty[1]&0xff;
          PWMDTY2=duty[2]&0xff;
          PWMDTY3=duty[3]&0xff;
          PWMDTY4=duty[4]&0xff;
          PWMDTY5=duty[5]&0xff;
          {
            static short tick=128;
            --tick;
            if(tick<=0){
              AS1_SendChar(PWMDTY0);
              AS1_SendChar(PWMDTY1);
              AS1_SendChar(PWMDTY2);
              AS1_SendChar(PWMDTY3);
              AS1_SendChar(PWMDTY4);
              AS1_SendChar(PWMDTY5);
              tick=16;
            }
          }
        /*  PWM0_SetRatio16(0);
          PWM1_SetRatio16(0x7FFF);
          PWM2_SetRatio16(0);
          PWM3_SetRatio16(0x7FFF);
          PWM4_SetRatio16(0);
          PWM5_SetRatio16(0x7FFF);*/
          //PWMDTY5=10;
      }
    }
  }
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END MotorDrive0 */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
