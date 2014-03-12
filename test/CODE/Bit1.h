/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Bit1.H
**     Project   : test
**     Processor : MC9S12XS128MAL
**     Beantype  : BitIO
**     Version   : Bean 02.072, Driver 03.12, CPU db: 3.00.003
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2009-12-6, 14:02
**     Abstract  :
**         This bean "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This bean is set to work in Input direction only.
**         Methods of this bean are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings  :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       12            |  PT3_IOC3
**             ----------------------------------------------------
**
**         Port name                   : T
**
**         Bit number (in port)        : 3
**         Bit mask of the port        : 8
**
**         Initial direction           : Input (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : PTT       [576]
**         Port control register       : DDRT      [578]
**
**         Optimization for            : speed
**     Contents  :
**         GetVal - bool Bit1_GetVal(void);
**
**     (c) Copyright UNIS, a.s. 1997-2008
**     UNIS, a.s.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/

#ifndef Bit1_H_
#define Bit1_H_

/* MODULE Bit1. */

  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#pragma CODE_SEG Bit1_CODE
/*
** ===================================================================
**     Method      :  Bit1_GetVal (bean BitIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**         Note: This bean is set to work in Input direction only.
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
#define Bit1_GetVal() ( \
    (bool)((getReg8(PTT) & 8))         /* Return port data */ \
  )

#pragma CODE_SEG DEFAULT

/* END Bit1. */
#endif /* #ifndef __Bit1_H_ */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/