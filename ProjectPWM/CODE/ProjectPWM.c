/** ###################################################################
**     Filename  : ProjectPWM.C
**     Project   : ProjectPWM
**     Processor : MC9S12XS128MAL
**     Version   : Driver 01.13
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2009-12-5, 13:47
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
/* MODULE ProjectPWM */

/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "PWM8.h"
#include "PWM9.h"
#include "PWM10.h"
#include "InpB1.h"
#include "InpB2.h"
#include "InpB3.h"
#include "TI1.h"
#include "Byte1.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */

  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END ProjectPWM */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
