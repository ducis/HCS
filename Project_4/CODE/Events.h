/** ###################################################################
**     Filename  : Events.H
**     Project   : Project_4
**     Processor : MC9S12XS128MAA
**     Beantype  : Events
**     Version   : Driver 01.04
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2010-5-3, 23:12
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

#ifndef __Events_H
#define __Events_H
/* MODULE Events */

#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "IEE1.h"
#include "AS1.h"

#pragma CODE_SEG DEFAULT


void AS1_OnIdle(void);
/*
** ===================================================================
**     Event       :  AS1_OnIdle (module Events)
**
**     From bean   :  AS1 [AsynchroSerial]
**     Description :
**         This event is called when an idle condition on the
**         receiver is detected.
**         The event is available only when both <Interrupt
**         service/event> and <Receiver > properties are enabled.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

/* END Events */
#endif /* __Events_H*/

/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
