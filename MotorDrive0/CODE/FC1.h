/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : FC1.H
**     Project   : MotorDrive0
**     Processor : MC9S12XDT256BMPV
**     Beantype  : FreeCntr
**     Version   : Bean 01.093, Driver 01.10, CPU db: 2.87.216
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2010-4-18, 0:02
**     Abstract  :
**         This device "FreeCntr" implements a free running counter for
**         time measurement.
**     Settings  :
**         Timer name                  : PIT0 (16-bit)
**         Compare name                : PITload0
**         Counter shared              : No
**
**         High speed mode
**             Prescaler               : divide-by-1
**             Clock                   : 40000000 Hz
**           Period
**             Xtal ticks              : 8192
**             microseconds            : 512
**             milliseconds            : 1
**             seconds (real)          : 0.0005120
**             Hz                      : 1953
**             kHz                     : 2
**           Frequency of counting (Bus clock / prescaler)
**             Hz                      : 40000000
**
**         Initialization:
**              Timer                  : Enabled
**
**         Timer registers
**              Counter                : PITCNT0   [842]
**              Mode                   : PITCFLMT  [832]
**              Run                    : PITCE     [834]
**              Compare                : PITLD0    [840]
**
**         Priority                    : 1
**         User handling procedure     : not specified
**     Contents  :
**         Reset           - byte FC1_Reset(void);
**         GetCounterValue - byte FC1_GetCounterValue(FC1_TTimerValue *Value);
**
**     (c) Copyright UNIS, a.s. 1997-2008
**     UNIS, a.s.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/

#ifndef __FC1
#define __FC1

/* MODULE FC1. */

#include "Cpu.h"


#pragma CODE_SEG FC1_CODE

#define FC1_TTimerValue word           /* This type represents counter or compare value, width depends on timer width */

#define FC1_PERIOD_VALUE     20480UL   /* Initial period value in ticks of the timer */
#define FC1_PRESCALER_VALUE  1U        /* Initial prescaler value of the timer */
#define FC1_COUNTER_INPUT_CLOCK_HZ 40000000UL /* Initial counter input clock frequency [Hz] */
#define FC1_TIMER_INPUT_CLOCK 40000000UL /* Deprecated. Initial timer input clock value [Hz] */
/* High speed mode constants */
#define FC1_PERIOD_VALUE_HIGH 20480UL  /* Initial period value in ticks of the timer in high speed mode */
#define FC1_PRESCALER_VALUE_HIGH 1U    /* Initial prescaler value of the timer in high speed mode */
#define FC1_COUNTER_INPUT_CLOCK_HZ_HIGH 40000000UL /* Counter input clock frequency in high speed mode [Hz] */
#define FC1_TIMER_INPUT_CLOCK_HIGH 40000000UL /* Deprecated. Timer input clock value [Hz] in high speed mode */

#define FC1_Reset() ( \
  PITFLT = 1,                          /* Force load register into counter register */ \
  ERR_OK                               /* Return result */ \
)
/*
** ===================================================================
**     Method      :  FC1_Reset (bean FreeCntr)
**
**     Description :
**         This method resets the timer-counter (sets to zero for
**         up-counting HW or to appropriate value for down-counting HW).
**         The method is available only if the counter register can be
**         written and the counter is not shared.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

#define FC1_GetCounterValue(PValue) ( \
  *(PValue) = PITCNT0,                 /* Read counter */ \
  ERR_OK                               /* Return result */ \
)
/*
** ===================================================================
**     Method      :  FC1_GetCounterValue (bean FreeCntr)
**
**     Description :
**         This method returns a content of counter.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Value           - A pointer to the returned 16-bit value.
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

#pragma CODE_SEG DEFAULT

/* END FC1. */

#endif /* ifndef __FC1 */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
