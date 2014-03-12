/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : PORTA.H
**     Project   : SmartCar
**     Processor : MC9S12DG128BCPV
**     Beantype  : ByteIO
**     Version   : Bean 02.056, Driver 03.10, CPU db: 2.87.345
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 2010-3-9, 16:49
**     Abstract  :
**         This bean "ByteIO" implements an one-byte input/output.
**         It uses one 8-bit port.
**         Note: This bean is set to work in Output direction only.
**         Methods of this bean are mostly implemented as a macros 
**         (if supported by target langauage and compiler).
**     Settings  :
**         Port name                   : A
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0 = 000H
**         Initial pull option         : off
**
**         8-bit data register         : PORTA     [0]
**         8-bit control register      : DDRA      [2]
**
**             ----------------------------------------------------
**                   Bit     |   Pin   |   Name
**             ----------------------------------------------------
**                    0      |    57   |   PA0_ADDR8_DATA8
**                    1      |    58   |   PA1_ADDR9_DATA9
**                    2      |    59   |   PA2_ADDR10_DATA10
**                    3      |    60   |   PA3_ADDR11_DATA11
**                    4      |    61   |   PA4_ADDR12_DATA12
**                    5      |    62   |   PA5_ADDR13_DATA13
**                    6      |    63   |   PA6_ADDR14_DATA14
**                    7      |    64   |   PA7_ADDR15_DATA15
**             ----------------------------------------------------
**     Contents  :
**         GetDir - bool PORTA_GetDir(void);
**         GetVal - byte PORTA_GetVal(void);
**         PutVal - void PORTA_PutVal(byte Val);
**         GetBit - bool PORTA_GetBit(byte Bit);
**         PutBit - void PORTA_PutBit(byte Bit, bool Val);
**         SetBit - void PORTA_SetBit(byte Bit);
**         ClrBit - void PORTA_ClrBit(byte Bit);
**         NegBit - void PORTA_NegBit(byte Bit);
**
**     (c) Copyright UNIS, a.s. 1997-2008
**     UNIS, a.s.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/

#ifndef PORTA_H_
#define PORTA_H_

/* MODULE PORTA. */

  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"
#include "Cpu112.h"

#pragma CODE_SEG PORTA_CODE
/*
** ===================================================================
**     Method      :  PORTA_GetVal (bean ByteIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pins and returns it
**           b) direction = Output : returns the last written value
**         Note: This bean is set to work in Output direction only.
**     Parameters  : None
**     Returns     :
**         ---        - Input value (0 to 255)
** ===================================================================
*/
#define PORTA_GetVal() ( \
    getReg8(PORTA)                     /* Evaluate to port data */ \
  )

/*
** ===================================================================
**     Method      :  PORTA_PutVal (bean ByteIO)
**
**     Description :
**         This method writes the new output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val        - Output value (0 to 255)
**     Returns     : Nothing
** ===================================================================
*/
#define PORTA_PutVal(Val) ( \
    (void)setReg8(PORTA, Val)          /* BIT0-BIT7=Val[bits 0-7] */ \
  )

/*
** ===================================================================
**     Method      :  PORTA_GetBit (bean ByteIO)
**
**     Description :
**         This method returns the specified bit of the input value.
**           a) direction = Input  : reads the input value from pins
**                                   and returns the specified bit
**           b) direction = Output : returns the specified bit
**                                   of the last written value
**         Note: This bean is set to work in Output direction only.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Bit        - Number of the bit to read (0 to 7)
**     Returns     :
**         ---        - Value of the specified bit (FALSE or TRUE)
**                      FALSE = "0" or "Low", TRUE = "1" or "High"
** ===================================================================
*/
bool PORTA_GetBit(byte Bit);

/*
** ===================================================================
**     Method      :  PORTA_PutBit (bean ByteIO)
**
**     Description :
**         This method writes the new value to the specified bit
**         of the output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Bit        - Number of the bit (0 to 7)
**         Val        - New value of the bit (FALSE or TRUE)
**                      FALSE = "0" or "Low", TRUE = "1" or "High"
**     Returns     : Nothing
** ===================================================================
*/
void PORTA_PutBit(byte Bit, bool Val);

/*
** ===================================================================
**     Method      :  PORTA_SetBit (bean ByteIO)
**
**     Description :
**         This method sets (sets to one) the specified bit of the
**         output value.
**         [ It is the same as "PutBit(Bit,TRUE);" ]
**     Parameters  :
**         NAME       - DESCRIPTION
**         Bit        - Number of the bit to set (0 to 7)
**     Returns     : Nothing
** ===================================================================
*/
void PORTA_SetBit(byte Bit);

/*
** ===================================================================
**     Method      :  PORTA_ClrBit (bean ByteIO)
**
**     Description :
**         This method clears (sets to zero) the specified bit
**         of the output value.
**         [ It is the same as "PutBit(Bit,FALSE);" ]
**     Parameters  :
**         NAME       - DESCRIPTION
**         Bit        - Number of the bit to clear (0 to 7)
**     Returns     : Nothing
** ===================================================================
*/
void PORTA_ClrBit(byte Bit);

/*
** ===================================================================
**     Method      :  PORTA_NegBit (bean ByteIO)
**
**     Description :
**         This method negates (inverts) the specified bit of the
**         output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Bit        - Number of the bit to invert (0 to 7)
**     Returns     : Nothing
** ===================================================================
*/
void PORTA_NegBit(byte Bit);

/*
** ===================================================================
**     Method      :  PORTA_GetDir (bean ByteIO)
**
**     Description :
**         This method returns direction of the bean.
**     Parameters  : None
**     Returns     :
**         ---        - Direction of the bean (always TRUE, Output only)
**                      FALSE = Input, TRUE = Output
** ===================================================================
*/
#define PORTA_GetDir() ( \
    (bool)1                            /* Port is fixed to GPO mode */ \
  )

#pragma CODE_SEG DEFAULT

/* END PORTA. */
#endif /* #ifndef __PORTA_H_ */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/