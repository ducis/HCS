/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : AS1.C
**     Project   : ProjectKeyboard
**     Processor : MC9S12XS128MAL
**     Beantype  : AsynchroSerial
**     Version   : Bean 02.454, Driver 01.19, CPU db: 3.00.003
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2009-12-6, 15:29
**     Abstract  :
**         This bean "AsynchroSerial" implements an asynchronous serial
**         communication. The bean supports different settings of
**         parity, word width, stop-bit and communication speed,
**         user can select interrupt or polling handler.
**         Communication speed can be changed also in runtime.
**         The bean requires one on-chip asynchronous serial channel.
**     Settings  :
**         Serial channel              : SCI0
**
**         Protocol
**             Init baud rate          : 9600baud
**             Width                   : 8 bits
**             Stop bits               : 1
**             Parity                  : none
**             Breaks                  : Disabled
**
**         Registers
**             Input buffer            : SCI0DRL   [207]
**             Output buffer           : SCI0DRL   [207]
**             Control register        : SCI0CR1   [202]
**             Mode register           : SCI0CR2   [203]
**             Baud setting reg.       : SCI0BD    [200]
**             Special register        : SCI0SR1   [204]
**
**         Input interrupt
**             Vector name             : Vsci0
**             Priority                : 4
**
**         Output interrupt
**             Vector name             : Vsci0
**             Priority                : 4
**
**         Used pins:
**         ----------------------------------------------------------
**           Function | On package           |    Name
**         ----------------------------------------------------------
**            Input   |     89               |  PS0_RxD0
**            Output  |     90               |  PS1_TxD0
**         ----------------------------------------------------------
**
**
**
**     Contents  :
**         RecvChar        - byte AS1_RecvChar(AS1_TComData *Chr);
**         SendChar        - byte AS1_SendChar(AS1_TComData Chr);
**         GetCharsInRxBuf - word AS1_GetCharsInRxBuf(void);
**         GetCharsInTxBuf - word AS1_GetCharsInTxBuf(void);
**
**     (c) Copyright UNIS, a.s. 1997-2008
**     UNIS, a.s.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/

/* MODULE AS1. */

#pragma MESSAGE DISABLE C4002 /* WARNING C4002: Result not used is ignored */
#pragma MESSAGE DISABLE C4301 /* INFORMATION C4301: Inline expansion done for function call */

#include "AS1.h"
#include "PWM8.h"
#include "TI1.h"
#include "InpB1.h"
#include "Byte1.h"
#include "Events.h"

#pragma DATA_SEG AS1_DATA
#pragma CODE_SEG AS1_CODE



#define OVERRUN_ERR      1             /* Overrun error flag bit   */
#define COMMON_ERR       2             /* Common error of RX       */
#define CHAR_IN_RX       4             /* Char is in the RX buffer     */
#define FULL_TX          8             /* Full transmit buffer     */

static byte SerFlag;                   /* Flags for serial communication */
                                       /* Bit 0 - Overrun error */
                                       /* Bit 1 - Common error of RX */
                                       /* Bit 2 - Char in the RX buffer */
                                       /* Bit 3 - Full TX buffer */
static AS1_TComData BufferRead;        /* Input char for SCI commmunication */

/*
** ===================================================================
**     Method      :  AS1_RecvChar (bean AsynchroSerial)
**
**     Description :
**         If any data is received, this method returns one
**         character, otherwise it returns an error code (it does
**         not wait for data). This method is enabled only if the
**         receiver property is enabled.
**         [Note:] Because the preferred method to handle error and
**         break exception in the interrupt mode is to use events
**         <OnError> and <OnBreak> the return value ERR_RXEMPTY has
**         higher priority than other error codes. As a consequence
**         the information about an exception in interrupt mode is
**         returned only if there is a valid character ready to be
**         read.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Chr             - Pointer to a received character
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_RXEMPTY - No data in receiver
**                           ERR_BREAK - Break character is detected
**                           (only when the <Interrupt service>
**                           property is disabled and the <Break
**                           signal> property is enabled)
**                           ERR_COMMON - common error occurred (the
**                           <GetError> method can be used for error
**                           specification)
** ===================================================================
*/
byte AS1_RecvChar(AS1_TComData *Chr)
{
  byte Result = ERR_OK;                /* Return error code */

  if(!(SerFlag & CHAR_IN_RX)) {        /* Is any char in the RX buffer? */
    return ERR_RXEMPTY;                /* If no then error */
  }
  EnterCritical();                     /* Save the PS register */
  *Chr = BufferRead;                   /* Received char */
  Result = (byte)((SerFlag & (OVERRUN_ERR|COMMON_ERR))?ERR_COMMON:ERR_OK);
  SerFlag &= ~(OVERRUN_ERR|COMMON_ERR|CHAR_IN_RX); /* Clear all errors in the status variable */
  ExitCritical();                      /* Restore the PS register */
  return Result;                       /* Return error code */
}

/*
** ===================================================================
**     Method      :  AS1_SendChar (bean AsynchroSerial)
**
**     Description :
**         Sends one character to the channel. If the bean is
**         temporarily disabled (Disable method) SendChar method
**         only stores data into an output buffer. In case of a zero
**         output buffer size, only one character can be stored.
**         Enabling the bean (Enable method) starts the transmission
**         of the stored data. This method is available only if the
**         transmitter property is enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Chr             - Character to send
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_TXFULL - Transmitter is full
** ===================================================================
*/
byte AS1_SendChar(AS1_TComData Chr)
{
  if(SerFlag & FULL_TX) {              /* Is any char in the TX buffer */
    return ERR_TXFULL;                 /* If yes then error */
  }
  EnterCritical();                     /* Save the PS register */
  (void) SCI0SR1;                      /* Reset interrupt request flag */
  SCI0DRL = (byte)Chr;                 /* Store char to transmitter register */
  SCI0CR2_TIE = 1;                     /* Enable transmit interrupt */
  SerFlag |= FULL_TX;                  /* Set the flag "full TX buffer" */
  ExitCritical();                      /* Restore the PS register */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  AS1_GetCharsInRxBuf (bean AsynchroSerial)
**
**     Description :
**         Returns the number of characters in the input buffer.
**         This method is available only if the receiver property is
**         enabled.
**     Parameters  : None
**     Returns     :
**         ---             - The number of characters in the input
**                           buffer.
** ===================================================================
*/
word AS1_GetCharsInRxBuf(void)
{
  return (SerFlag & CHAR_IN_RX) != 0;  /* Return number of chars in the receive buffer */
}
/*
** ===================================================================
**     Method      :  AS1_GetCharsInTxBuf (bean AsynchroSerial)
**
**     Description :
**         Returns the number of characters in the output buffer.
**         This method is available only if the transmitter property
**         is enabled.
**     Parameters  : None
**     Returns     :
**         ---             - The number of characters in the output
**                           buffer.
** ===================================================================
*/
word AS1_GetCharsInTxBuf(void)
{
  return (SerFlag & FULL_TX) != 0;     /* Return number of chars in the transmitter buffer */
}
/*
** ===================================================================
**     Method      :  AS1_InterruptRx (bean AsynchroSerial)
**
**     Description :
**         The method services the receive interrupt of the selected 
**         peripheral(s) and eventually invokes the bean's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#define ON_ERROR    1
#define ON_FULL_RX  2
#define ON_RX_CHAR  4
#pragma INLINE
void AS1_InterruptRx(void)
{
  AS1_TComData Data;                   /* Temporary variable for data */
  byte OnFlags = 0;                    /* Temporary variable for flags */

  Data = SCI0DRL;                      /* Read data from the receiver */
  if(SerFlag & CHAR_IN_RX) {           /* Is a character already present in the receive buffer? */
    SerFlag |= OVERRUN_ERR;            /* If yes then set flag OVERRUN_ERR */
    OnFlags |= ON_ERROR;               /* Set flag "OnError" */
  } else {
    BufferRead = Data;
    SerFlag |= CHAR_IN_RX;             /* Set flag "char in RX buffer" */
    OnFlags |= ON_RX_CHAR;             /* Set flag "OnRxChar" */
  }
  if(OnFlags & ON_ERROR) {             /* Was an error detected? */
    AS1_OnError();                     /* If yes then invoke user event */
  }
  else {
    if(OnFlags & ON_RX_CHAR) {         /* Is OnRxChar flag set? */
      AS1_OnRxChar();                  /* If yes then invoke user event */
    }
  }
}

/*
** ===================================================================
**     Method      :  AS1_InterruptTx (bean AsynchroSerial)
**
**     Description :
**         The method services the receive interrupt of the selected 
**         peripheral(s) and eventually invokes the bean's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#define ON_FREE_TX  1
#define ON_TX_CHAR  2
#pragma INLINE
void AS1_InterruptTx(void)
{
  byte OnFlags = 0;                    /* Temporary variable for flags */

  if(SerFlag & FULL_TX) {              /* Is a char already present in the transmit buffer? */
    OnFlags |= ON_TX_CHAR;             /* Set flag "OnTxChar" */
  }
  SerFlag &= ~FULL_TX;                 /* Reset flag "full TX buffer" */
  SCI0CR2_TIE = 0;                     /* Disable transmit interrupt */
  if(OnFlags & ON_TX_CHAR) {           /* Is flag "OnTxChar" set? */
    AS1_OnTxChar();                    /* If yes then invoke user event */
  }
}

/*
** ===================================================================
**     Method      :  AS1_Interrupt (bean AsynchroSerial)
**
**     Description :
**         The method services the receive interrupt of the selected 
**         peripheral(s) and eventually invokes the bean's event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
#pragma CODE_SEG __NEAR_SEG NON_BANKED
ISR(AS1_Interrupt)
{
  byte StatReg = getReg(SCI0SR1);

  if (StatReg & (SCI0SR1_OR_MASK | SCI0SR1_FE_MASK | SCI0SR1_NF_MASK)) { /* Is any error flag set? */
    SerFlag |= COMMON_ERR;             /* If yes then set an internal flag */
    (void) SCI0DRL;                    /* Dummy read of data register - clear error bits */
    StatReg &= ~SCI0SR1_RDRF_MASK;     /* Clear the receive data flag to discard the errorneous data */
    AS1_OnError();                     /* If yes then invoke user event */
  }
  if (StatReg & SCI0SR1_RDRF_MASK) {   /* Is the receiver interrupt flag set? */
    AS1_InterruptRx();                 /* If yes, then invoke the internal service routine. This routine is inlined. */
  }
  if (SCI0CR2_TIE) {                   /* Is the transmitter interrupt enabled? */
    if (StatReg & SCI0SR1_TDRE_MASK) { /* Is the transmitter interrupt flag set? */
      AS1_InterruptTx();               /* If yes, then invoke the internal service routine. This routine is inlined. */
    }
  }
}

#pragma CODE_SEG AS1_CODE
/*
** ===================================================================
**     Method      :  AS1_Init (bean AsynchroSerial)
**
**     Description :
**         Initializes the associated peripheral(s) and internal 
**         variables of the bean. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void AS1_Init(void)
{
  SerFlag = 0;                         /* Reset flags */
  /* SCI0CR1: LOOPS=0,SCISWAI=0,RSRC=0,M=0,WAKE=0,ILT=0,PE=0,PT=0 */
  setReg8(SCI0CR1, 0);                  
  /* SCI0SR2: AMAP=1,??=0,??=0,TXPOL=0,RXPOL=0,BRK13=0,TXDIR=0,RAF=0 */
  setReg8(SCI0SR2, 128);               /* Switch to the alternative register set */ 
  /* SCI0ASR1: RXEDGIF=1,??=0,??=0,??=0,??=0,BERRV=0,BERRIF=1,BKDIF=1 */
  setReg8(SCI0ASR1, 131);              /* Clear alternative status flags */ 
  /* SCI0ACR1: RXEDGIE=0,??=0,??=0,??=0,??=0,??=0,BERRIE=0,BKDIE=0 */
  setReg8(SCI0ACR1, 0);                 
  /* SCI0ACR2: ??=0,??=0,??=0,??=0,??=0,BERRM1=0,BERRM0=0,BKDFE=0 */
  setReg8(SCI0ACR2, 0);                 
  /* SCI0SR2: AMAP=0,??=0,??=0,TXPOL=0,RXPOL=0,BRK13=0,TXDIR=0,RAF=0 */
  setReg8(SCI0SR2, 0);                 /* Switch to the normal register set */ 
  (void) SCI0SR1;                      /* Reset interrupt request flags */
  /* SCI0CR2: TIE=0,TCIE=0,RIE=0,ILIE=0,TE=0,RE=0,RWU=0,SBK=0 */
  SCI0CR2 = 0;                         /* Disable error interrupts */
  SCI0BD = 52;                         /* Set prescaler bits */
  SCI0CR2 |= (SCI0CR2_TE_MASK | SCI0CR2_RE_MASK | SCI0CR2_RIE_MASK); /* Enable transmitter, Enable receiver, Enable receiver interrupt */
}



/* END AS1. */


/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
