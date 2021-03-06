/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : E.H
**     Project   : SmartCar
**     Processor : MC9S12DG128BCPV
**     Beantype  : ByteIO
**     Version   : Bean 02.056, Driver 03.10, CPU db: 2.87.345
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 2010-3-8, 14:01
**     Abstract  :
**         This bean "ByteIO" implements an one-byte input/output.
**         It uses one 8-bit port.
**         Note: This bean is set to work in Input direction only.
**         Methods of this bean are mostly implemented as a macros 
**         (if supported by target langauage and compiler).
**     Settings  :
**         Port name                   : E
**
**         Initial direction           : Input (direction cannot be changed)
**         Initial output value        : 0 = 000H
**         Initial pull option         : off
**
**         8-bit data register         : PORTE     [8]
**         8-bit control register      : DDRE      [9]
**         8-bit function register     : INTCR     [30]
**
**             ----------------------------------------------------
**                   Bit     |   Pin   |   Name
**             ----------------------------------------------------
**                    0      |    56   |   PE0_XIRQ
**                    1      |    55   |   PE1_IRQ
**                    2      |    54   |   PE2_R_W
**                    3      |    53   |   PE3_LSTRB_TAGLO
**                    4      |    39   |   PE4_ECLK
**                    5      |    38   |   PE5_IPIPE0_MODA
**                    6      |    37   |   PE6_IPIPE1_MODB
**                    7      |    36   |   PE7_XCLKS_NOACC
**             ----------------------------------------------------
**     Contents  :
**         GetDir - bool E_GetDir(void);
**         GetVal - byte E_GetVal(void);
**         GetBit - bool E_GetBit(byte Bit);
**
**     (c) Copyright UNIS, a.s. 1997-2008
**     UNIS, a.s.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/

#ifndef E_H_
#define E_H_

/* MODULE E. */

  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu112.h"

#pragma CODE_SEG E_CODE
/*
** ===================================================================
**     Method      :  E_GetVal (bean ByteIO)
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
#define E_GetVal() ( \
    getReg8(PORTE)                     /* Evaluate to port data */ \
  )

/*
** ===================================================================
**     Method      :  E_GetBit (bean ByteIO)
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
bool E_GetBit(byte Bit);

/*
** ===================================================================
**     Method      :  E_GetDir (bean ByteIO)
**
**     Description :
**         This method returns direction of the bean.
**     Parameters  : None
**     Returns     :
**         ---        - Direction of the bean (always FALSE, Input only)
**                      FALSE = Input, TRUE = Output
** ===================================================================
*/
#define E_GetDir() ( \
    (bool)0                            /* Port is fixed to GPI mode */ \
  )

#pragma CODE_SEG DEFAULT

/* END E. */
#endif /* #ifndef __E_H_ */
/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12 series of microcontrollers.
**
** ###################################################################
*/
