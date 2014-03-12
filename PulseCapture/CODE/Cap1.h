/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Cap1.H
**     Project   : PulseCapture
**     Processor : MC9S12XS128MAL
**     Beantype  : Capture
**     Version   : Bean 02.201, Driver 01.17, CPU db: 3.00.003
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2009-12-11, 20:03
**     Abstract  :
**         This bean "Capture" simply implements the capture function
**         of timer. The counter counts the same way as in free run mode. On
**         the selected edge of the input signal (on the input pin), the current
**         content of the counter register is written into the capture
**         register and the OnCapture event is called.
**     Settings  :
**             Timer capture encapsulation : Capture
**
**         Timer
**             Timer                   : TIM_Counter
**             Counter shared          : Yes
**
**         High speed mode
**             Prescaler               : divide-by-1
**           Maximal time for capture register
**             Xtal ticks              : 8388608
**             microseconds            : 524288
**             milliseconds            : 524
**             seconds                 : 1
**             seconds (real)          : 0.5242880
**             Hz                      : 2
**           One tick of timer is
**             microseconds            : 8
**
**         Initialization:
**              Timer                  : Enabled
**              Events                 : Enabled
**
**         Timer registers
**              Capture                : TC3       [86]
**              Counter                : TCNT      [68]
**              Mode                   : TIOS      [64]
**              Run                    : TSCR1     [70]
**              Prescaler              : TSCR2     [77]
**
**         Used input pin              : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       12            |  PT3_IOC3
**             ----------------------------------------------------
**
**         Port name                   : T
**         Bit number (in port)        : 3
**         Bit mask of the port        : 8
**
**         Signal edge/level           : both
**         Priority                    : 4
**         Pull option                 : off
**
**     Contents  :
**         Reset           - byte Cap1_Reset(void);
**         GetCaptureValue - byte Cap1_GetCaptureValue(Cap1_TCapturedValue *Value);
**
**     (c) Copyright UNIS, a.s. 1997-2008
**     UNIS, a.s.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/

#ifndef __Cap1
#define __Cap1

/* MODULE Cap1. */

#include "Cpu.h"

#pragma DATA_SEG Cap1_DATA
#pragma CODE_SEG Cap1_CODE

#define Cap1_TCapturedValue word /* Type of the captured value */
#define Cap1_PRESCALER_VALUE 64U       /* Initial prescaler value of the timer */
#define Cap1_TIMER_INPUT_CLOCK 8000000UL /* DEPRECATED. Initial timer input clock frequency [Hz] */
#define Cap1_COUNTER_INPUT_CLOCK_HZ 125000UL /* Initial counter input clock frequency [Hz] */
/* High speed mode constants */
#define Cap1_PRESCALER_VALUE_HIGH 64U  /* Initial prescaler value of the timer in high speed mode */
#define Cap1_TIMER_INPUT_CLOCK_HIGH 8000000UL /* DEPRECATED. Timer input clock frequency [Hz] in high speed mode */
#define Cap1_COUNTER_INPUT_CLOCK_HZ_HIGH 125000UL /* Initial counter input clock frequency [Hz] in high speed mode */

extern volatile word Cap1_CntrState;   /* Content of counter */

#define Cap1_Reset() (Cap1_CntrState = TCNT , ERR_OK)
/*
** ===================================================================
**     Method      :  Cap1_Reset (bean Capture)
**
**     Description :
**         This method resets the counter register (see implementation
**         note in <General Info>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

#define Cap1_GetCaptureValue(Value) \
 (*(Cap1_TCapturedValue*)(Value) = (TC3 - Cap1_CntrState), ERR_OK)
/*
** ===================================================================
**     Method      :  Cap1_GetCaptureValue (bean Capture)
**
**     Description :
**         This method gets the last value captured by enabled timer.
**         Note: one tick of timer is
**               8 us in high speed mode
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Value           - A pointer to the content of the
**                           capture register
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

void Cap1_Init(void);
/*
** ===================================================================
**     Method      :  Cap1_Init (bean Capture)
**
**     Description :
**         Initializes the associated peripheral(s) and the beans 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

#pragma CODE_SEG __NEAR_SEG NON_BANKED
__interrupt void Cap1_Interrupt(void);
#pragma CODE_SEG Cap1_CODE
/*
** ===================================================================
**     Method      :  Interrupt (bean Capture)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes of the bean event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

#pragma CODE_SEG DEFAULT

/* END Cap1. */

#endif /* ifndef __Cap1 */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
