/** ###################################################################
**     Filename  : SmartCar.C
**     Project   : SmartCar
**     Processor : MC9S12DG128BCPV
**     Version   : Driver 01.13
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2010-3-6, 21:53
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
/* MODULE SmartCar */

/* Including needed modules to compile this module/procedure */
#include "Cpu112.h"
#include "Events.h"
#include "ForwardOrBackward.h"
#include "E.h"
#include "MotorEnableM3.h"
#include "M4.h"
#include "K0.h"
#include "MotorEnableK3.h"
#include "SCI.h"
#include "Servo1.h"
#include "Servo2.h"
#include "MainMotor.h"
#include "SpeedSensor.h"
#include "PORTA.h"
#include "PORTB.h"
#include "Cap1.h"
#include "Cap2.h"
#include "ATC0.h"
#include "ATC1.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
void MyInitialization(void);

void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/
  MyInitialization();
  /* Write your code here */

  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END SmartCar */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
