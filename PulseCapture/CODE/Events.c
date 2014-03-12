/** ###################################################################
**     Filename  : Events.C
**     Project   : PulseCapture
**     Processor : MC9S12XS128MAL
**     Beantype  : Events
**     Version   : Driver 01.04
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2009-12-6, 13:33
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
unsigned char FSync=0;
unsigned int FRow=0;
unsigned int FRowCounter=0;
unsigned char Color=0;
//void TI1_OnInterrupt(void)
//{                      
  //Cap1_Reset();
  //Cap1_GetCaptureValue(t);
//  do{
//  }while(AS1_SendChar(FSync)==ERR_TXFULL);
//  do{    
//  }while(AS1_SendChar((byte)(FRow&0xFF))==ERR_TXFULL);
//  do{
//  }while(AS1_SendChar((byte)(FRow>>8))==ERR_TXFULL);
 // FSync=0;
  /* Write your code here ... */
//}


/*
** ===================================================================
**     Event       :  Cap1_OnCapture (module Events)
**
**     From bean   :  Cap1 [Capture]
**     Description :
**         This event is called on capturing of Timer/Counter actual
**         value (only when the bean is enabled - <Enable> and the
**         events are enabled - <EnableEvent>.This event is available
**         only if a <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Cap1_OnCapture(void)
{
  //AS1_SendChar('b');
  ++FSync;
  /* Write your code here ... */
  FRow=FRowCounter;
  FRowCounter=0;
}

/*
** ===================================================================
**     Event       :  Cap2_OnCapture (module Events)
**
**     From bean   :  Cap2 [Capture]
**     Description :
**         This event is called on capturing of Timer/Counter actual
**         value (only when the bean is enabled - <Enable> and the
**         events are enabled - <EnableEvent>.This event is available
**         only if a <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void Cap2_OnCapture(void)
{
  word i;
  word s=0;
  ++FRowCounter;
  //for(i=0;i<10;++i)
  //  s+=PortA_GetVal();
  //Color=s/10;
  //Color=PortA_GetVal();
  /* Write your code here ... */
}

/*
** ===================================================================
**     Event       :  TI2_OnInterrupt (module Events)
**
**     From bean   :  TI2 [TimerInt]
**     Description :
**         When a timer interrupt occurs this event is called (only
**         when the bean is enabled - <Enable> and the events are
**         enabled - <EnableEvent>). This event is enabled only if a
**         <interrupt service/event> is enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void TI2_OnInterrupt(void)
{
  Color=PortA_GetVal();
  AS1_SendChar(Color);
  /* Write your code here ... */
}



/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
