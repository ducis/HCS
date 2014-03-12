/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : Bit2.H
**     Project   : test
**     Processor : MC9S12XS128MAL
**     Beantype  : BitIO
**     Version   : Bean 02.072, Driver 03.12, CPU db: 3.00.003
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2009-12-6, 14:02
**     Abstract  :
**         This bean "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Note: This bean is set to work in Output direction only.
**         Methods of this bean are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings  :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       24            |  PB0
**             ----------------------------------------------------
**
**         Port name                   : B
**
**         Bit number (in port)        : 0
**         Bit mask of the port        : 1
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : PORTB     [1]
**         Port control register       : DDRB      [3]
**
**         Optimization for            : speed
**     Contents  :
**         GetVal - bool Bit2_GetVal(void);
**         PutVal - void Bit2_PutVal(bool Val);
**         ClrVal - void Bit2_ClrVal(void);
**         SetVal - void Bit2_SetVal(void);
**
**     (c) Copyright UNIS, a.s. 1997-2008
**     UNIS, a.s.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/

#ifndef Bit2_H_
#define Bit2_H_

/* MODULE Bit2. */

  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#pragma CODE_SEG Bit2_CODE
/*
** ===================================================================
**     Method      :  Bit2_GetVal (bean BitIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**         Note: This bean is set to work in Output direction only.
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
#define Bit2_GetVal() ( \
    (bool)((getReg8(PORTB) & 1))       /* Return port data */ \
  )

/*
** ===================================================================
**     Method      :  Bit2_PutVal (bean BitIO)
**
**     Description :
**         This method writes the new output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
void Bit2_PutVal(bool Val);

/*
** ===================================================================
**     Method      :  Bit2_ClrVal (bean BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define Bit2_ClrVal() ( \
    (void)clrReg8Bits(PORTB, 1)        /* PB0=0 */ \
  )

/*
** ===================================================================
**     Method      :  Bit2_SetVal (bean BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
#define Bit2_SetVal() ( \
    (void)setReg8Bits(PORTB, 1)        /* PB0=1 */ \
  )

#pragma CODE_SEG DEFAULT

/* END Bit2. */
#endif /* #ifndef __Bit2_H_ */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/