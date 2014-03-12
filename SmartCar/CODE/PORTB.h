/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : PORTB.H
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
**         Port name                   : B
**
**         Initial direction           : Output (direction cannot be changed)
**         Initial output value        : 0 = 000H
**         Initial pull option         : off
**
**         8-bit data register         : PORTB     [1]
**         8-bit control register      : DDRB      [3]
**
**             ----------------------------------------------------
**                   Bit     |   Pin   |   Name
**             ----------------------------------------------------
**                    0      |    24   |   PB0_ADDR0_DATA0
**                    1      |    25   |   PB1_ADDR1_DATA1
**                    2      |    26   |   PB2_ADDR2_DATA2
**                    3      |    27   |   PB3_ADDR3_DATA3
**                    4      |    28   |   PB4_ADDR4_DATA4
**                    5      |    29   |   PB5_ADDR5_DATA5
**                    6      |    30   |   PB6_ADDR6_DATA6
**                    7      |    31   |   PB7_ADDR7_DATA7
**             ----------------------------------------------------
**     Contents  :
**         GetDir - bool PORTB_GetDir(void);
**         GetVal - byte PORTB_GetVal(void);
**         PutVal - void PORTB_PutVal(byte Val);
**         GetBit - bool PORTB_GetBit(byte Bit);
**         PutBit - void PORTB_PutBit(byte Bit, bool Val);
**         SetBit - void PORTB_SetBit(byte Bit);
**         ClrBit - void PORTB_ClrBit(byte Bit);
**         NegBit - void PORTB_NegBit(byte Bit);
**
**     (c) Copyright UNIS, a.s. 1997-2008
**     UNIS, a.s.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/

#ifndef PORTB_H_
#define PORTB_H_

/* MODULE PORTB. */

  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"
#include "Cpu112.h"

#pragma CODE_SEG PORTB_CODE
/*
** ===================================================================
**     Method      :  PORTB_GetVal (bean ByteIO)
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
#define PORTB_GetVal() ( \
    getReg8(PORTB)                     /* Evaluate to port data */ \
  )

/*
** ===================================================================
**     Method      :  PORTB_PutVal (bean ByteIO)
**
**     Description :
**         This method writes the new output value.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val        - Output value (0 to 255)
**     Returns     : Nothing
** ===================================================================
*/
#define PORTB_PutVal(Val) ( \
    (void)setReg8(PORTB, Val)          /* BIT0-BIT7=Val[bits 0-7] */ \
  )

/*
** ===================================================================
**     Method      :  PORTB_GetBit (bean ByteIO)
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
bool PORTB_GetBit(byte Bit);

/*
** ===================================================================
**     Method      :  PORTB_PutBit (bean ByteIO)
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
void PORTB_PutBit(byte Bit, bool Val);

/*
** ===================================================================
**     Method      :  PORTB_SetBit (bean ByteIO)
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
void PORTB_SetBit(byte Bit);

/*
** ===================================================================
**     Method      :  PORTB_ClrBit (bean ByteIO)
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
void PORTB_ClrBit(byte Bit);

/*
** ===================================================================
**     Method      :  PORTB_NegBit (bean ByteIO)
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
void PORTB_NegBit(byte Bit);

/*
** ===================================================================
**     Method      :  PORTB_GetDir (bean ByteIO)
**
**     Description :
**         This method returns direction of the bean.
**     Parameters  : None
**     Returns     :
**         ---        - Direction of the bean (always TRUE, Output only)
**                      FALSE = Input, TRUE = Output
** ===================================================================
*/
#define PORTB_GetDir() ( \
    (bool)1                            /* Port is fixed to GPO mode */ \
  )

#pragma CODE_SEG DEFAULT

/* END PORTB. */
#endif /* #ifndef __PORTB_H_ */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
