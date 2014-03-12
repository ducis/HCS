/** ###################################################################
**     Filename  : Events.C
**     Project   : ProjectPWM
**     Processor : MC9S12XS128MAL
**     Beantype  : Events
**     Version   : Driver 01.04
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2009-12-5, 13:47
**     Abstract  :
**         This is user's event module.
**         Put your event handler code here.
**     Settings  :
**     Contents  :
**         TI1_OnInterrupt - void TI1_OnInterrupt(void);
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
  //Byte1_PutVal(InpB1_GetVal()+(InpB2_GetVal()<<1)+(InpB3_GetVal()<<2));
  unsigned char r=0;
  if(InpB1_GetVal()){
     r|=1;
  }
  if(InpB2_GetVal()){
    r|=2;
  }
  if(InpB3_GetVal()){
    r|=4;
  }
  Byte1_PutVal(r);
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
