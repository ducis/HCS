/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : PortA.H
**     Project   : PulseCapture
**     Processor : MC9S12XS128MAL
**     Beantype  : ByteIO
**     Version   : Bean 02.056, Driver 03.13, CPU db: 3.00.003
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2009-12-11, 20:15
**     Abstract  :
**         This bean "ByteIO" implements an one-byte input/output.
**         It uses one 8-bit port.
**         Note: This bean is set to work in Input direction only.
**         Methods of this bean are mostly implemented as a macros 
**         (if supported by target langauage and compiler).
**     Settings  :
**         Port name                   : A
**
**         Initial direction           : Input (direction cannot be changed)
**         Initial output value        : 0 = 000H
**         Initial pull option         : off
**
**         8-bit data register         : PORTA     [0]
**         8-bit control register      : DDRA      [2]
**
**             ----------------------------------------------------
**                   Bit     |   Pin   |   Name
**             ----------------------------------------------------
**                    0      |    57   |   PA0
**                    1      |    58   |   PA1
**                    2      |    59   |   PA2
**                    3      |    60   |   PA3
**                    4      |    61   |   PA4
**                    5      |    62   |   PA5
**                    6      |    63   |   PA6
**                    7      |    64   |   PA7
**             ----------------------------------------------------
**     Contents  :
**         GetDir - bool PortA_GetDir(void);
**         GetVal - byte PortA_GetVal(void);
**         GetBit - bool PortA_GetBit(byte Bit);
**
**     (c) Copyright UNIS, a.s. 1997-2008
**     UNIS, a.s.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/

#ifndef PortA_H_
#define PortA_H_

/* MODULE PortA. */

  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

#pragma CODE_SEG PortA_CODE
/*
** ===================================================================
**     Method      :  PortA_GetVal (bean ByteIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pins and returns it
**           b) direction = Output : returns the last written value
**         Note: This bean is set to work in Input direction only.
**     Parameters  : None
**     Returns     :
**         ---        - Input value (0 to 255)
** ===================================================================
*/
#define PortA_GetVal() ( \
    getReg8(PORTA)                     /* Evaluate to port data */ \
  )

/*
** ===================================================================
**     Method      :  PortA_GetBit (bean ByteIO)
**
**     Description :
**         This method returns the specified bit of the input value.
**           a) direction = Input  : reads the input value from pins
**                                   and returns the specified bit
**           b) direction = Output : returns the specified bit
**                                   of the last written value
**         Note: This bean is set to work in Input direction only.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Bit        - Number of the bit to read (0 to 7)
**     Returns     :
**         ---        - Value of the specified bit (FALSE or TRUE)
**                      FALSE = "0" or "Low", TRUE = "1" or "High"
** ===================================================================
*/
bool PortA_GetBit(byte Bit);

/*
** ===================================================================
**     Method      :  PortA_GetDir (bean ByteIO)
**
**     Description :
**         This method returns direction of the bean.
**     Parameters  : None
**     Returns     :
**         ---        - Direction of the bean (always FALSE, Input only)
**                      FALSE = Input, TRUE = Output
** ===================================================================
*/
#define PortA_GetDir() ( \
    (bool)0                            /* Port is fixed to GPI mode */ \
  )

#pragma CODE_SEG DEFAULT

/* END PortA. */
#endif /* #ifndef __PortA_H_ */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
