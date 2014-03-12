/** ###################################################################
**     Filename  : Events.C
**     Project   : MotorDrive
**     Processor : MC9S12XDT256BMPV
**     Beantype  : Events
**     Version   : Driver 01.04
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2010-2-3, 17:46
**     Abstract  :
**         This is user's event module.
**         Put your event handler code here.
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
/* MODULE Events */


#include "Cpu.h"
#include "Events.h"

#pragma CODE_SEG DEFAULT

/*
** ===================================================================
**     Event       :  TI1_OnInterrupt (module Events)
**
**     From bean   :  TI1 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the bean is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TI1_OnInterrupt(void)
{
  static int counter=0;
  static int s[4]={254,251,239,191};
  
  ++counter;
  if(counter>=1000){
//    TI1_Disable();
    Byte1_PutVal(0);
  }else{
    Byte1_PutVal(s[counter&3]);
  }
  /* Write your code here ... */
}


/* END Events */

/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
