/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : SpeedSensor.H
**     Project   : SmartCar
**     Processor : MC9S12DG128BCPV
**     Beantype  : PulseAccumulator
**     Version   : Bean 01.182, Driver 01.17, CPU db: 2.87.345
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 2010-3-9, 16:49
**     Abstract  :
**          In event counter mode, a pulse accumulator counts the number of active
**          edges at the input of its channel.
**          Due to ECT module setting (see CPU bean, property internal peripheral),
**          pulse accumulator is in queue mode. Reading the input capture holding
**          register will transfer the contents of the associated pulse accumulator
**          to its holding register. 
**          At the same time the pulse accumulator counter is cleared.
**
**          Pulse accumulator bean usually cooperates with capture bean on the same
**          channel.
**     Settings  :
**             Pulse accumulator       : PACNT01
**
**         Common ECT module settings:
**              Mode:                  : Queue
**              Holding registers:     : Disabled
**              Delay counter:         : 0
**              Modulus mode:          : yes
**         Initialization:
**              Mode                   : Event counter
**              Pulse accumulator      : Enabled
**              Events                 : Enabled
**              Overwrite mode         : Enabled
**
**         Timer registers
**              Counter                : PACN10    [100]
**              Hold                   : PA10H     [116]
**              Mode                   : ICOVW     [106]
**              Run                    : PBCTL     [112]
**
**         User handling procedure     : not specified
**
**         Used input pin              :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       9             |  PT0_IOC0
**             ----------------------------------------------------
**
**         Port name                   : T
**         Bit number (in port)        : 0
**         Bit mask of the port        : 1
**
**         Active input signal edge    : both
**         Pull option                 : off
**
**     Contents  :
**         ResetCounter    - void SpeedSensor_ResetCounter(void);
**         GetCounterValue - SpeedSensor_TCounterValue SpeedSensor_GetCounterValue(void);
**
**     (c) Copyright UNIS, a.s. 1997-2008
**     UNIS, a.s.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/

#ifndef __SpeedSensor
#define __SpeedSensor

/* MODULE SpeedSensor. */

#include "Cpu112.h"

#pragma CODE_SEG SpeedSensor_CODE

#ifndef __BWUserType_SpeedSensor_TCounterValue
#define __BWUserType_SpeedSensor_TCounterValue
typedef word SpeedSensor_TCounterValue; /* Counter value, width depends on selected peripheal. */
#endif


#define SpeedSensor_ResetCounter() (PACN10 = 0)
/*
** ===================================================================
**     Method      :  SpeedSensor_ResetCounter (bean PulseAccumulator)
**
**     Description :
**         This method resets the pulse accumulator counter (sets to
**         zero).
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/

#define SpeedSensor_GetCounterValue() (PACN10)
/*
** ===================================================================
**     Method      :  SpeedSensor_GetCounterValue (bean PulseAccumulator)
**
**     Description :
**         This method returns the content of the pulse accumulator
**         counter.
**     Parameters  : None
**     Returns     :
**         ---             - Content of the counter register.
** ===================================================================
*/

void SpeedSensor_Init(void);
/*
** ===================================================================
**     Method      :  SpeedSensor_Init (bean PulseAccumulator)
**
**     Description :
**         Initializes the associated peripheral(s) and the beans 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

#pragma CODE_SEG DEFAULT

/* END SpeedSensor. */

#endif /* ifndef __SpeedSensor */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
