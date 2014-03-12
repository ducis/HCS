/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : PE_Const.H
**     Project   : ProjectTimer
**     Processor : MC9S12XS128MAL
**     Beantype  : PE_Const
**     Version   : Driver 01.00
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2009-12-5, 14:52
**     Abstract  :
**         This bean "PE_Const" contains internal definitions
**         of the constants.
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

#ifndef __PE_Const_H
#define __PE_Const_H

/* Constants for detecting running mode */
#define HIGH_SPEED        0            /* High speed */
#define LOW_SPEED         1            /* Low speed */
#define SLOW_SPEED        2            /* Slow speed */

/* Reset cause constants */
#define RSTSRC_POR        1            /* Power-on reset        */
#define RSTSRC_PIN        8            /* External reset bit    */
#define RSTSRC_COP        4            /* COP reset             */
#define RSTSRC_ILOP       2            /* Illegal opcode reset  */
#define RSTSRC_ILAD       16           /* Illegal address reset */
#define RSTSRC_LVI        32           /* Low voltage inhibit reset */

#endif /* _PE_Const_H */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
