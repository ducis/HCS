/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : AS1.C
**     Project   : MotorDrive0
**     Processor : MC9S12XDT256BMPV
**     Beantype  : AsynchroSerial
**     Version   : Bean 02.454, Driver 01.19, CPU db: 2.87.216
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2010-5-9, 1:48
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
**             Init baud rate          : 115200baud
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
**         RecvBlock       - byte AS1_RecvBlock(AS1_TComData *Ptr, word Size, word *Rcv);
**         SendBlock       - byte AS1_SendBlock(AS1_TComData *Ptr, word Size, word *Snd);
**         ClearRxBuf      - byte AS1_ClearRxBuf(void);
**         ClearTxBuf      - byte AS1_ClearTxBuf(void);
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
#include "PWM0.h"
#include "PWM1.h"
#include "PWM2.h"
#include "PWM3.h"
#include "PWM4.h"
#include "PWM5.h"
#include "FC1.h"
#include "Events.h"

#pragma DATA_SEG AS1_DATA
#pragma CODE_SEG AS1_CODE



#define OVERRUN_ERR      1             /* Overrun error flag bit   */
#define COMMON_ERR       2             /* Common error of RX       */
#define CHAR_IN_RX       4             /* Char is in the RX buffer     */
#define RUNINT_FROM_TX   8             /* Interrupt is in progress */
#define FULL_RX          16            /* Full receive buffer      */

static byte SerFlag;                   /* Flags for serial communication */
                                       /* Bit 0 - Overrun error */
                                       /* Bit 1 - Common error of RX */
                                       /* Bit 2 - Char in the RX buffer */
                                       /* Bit 3 - Interrupt is in progress */
                                       /* Bit 4 - Full RX buffer */
word AS1_InpLen;                       /* Length of the input buffer's content */
static AS1_TComData *InpPtrR;          /* Pointer for reading from the input buffer */
static AS1_TComData *InpPtrW;          /* Pointer for writing to the input buffer */
static AS1_TComData InpBuffer[AS1_INP_BUF_SIZE]; /* Input buffer for SCI commmunication */
word AS1_OutLen;                       /* Length of the output bufer's content */
static AS1_TComData *OutPtrR;          /* Pointer for reading from the output buffer */
static AS1_TComData *OutPtrW;          /* Pointer for writing to the output buffer */
static AS1_TComData OutBuffer[AS1_OUT_BUF_SIZE]; /* Output buffer for SCI commmunication */

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

  if(AS1_InpLen > 0) {                 /* Is number of received chars greater than 0? */
    EnterCritical();                   /* Save the PS register */
    AS1_InpLen--;                      /* Decrease number of received chars */
    *Chr = *(InpPtrR++);               /* Received char */
    if(InpPtrR >= (InpBuffer + AS1_INP_BUF_SIZE)) { /* Is the pointer out of the receive buffer? */
      InpPtrR = InpBuffer;             /* Set pointer to the first item into the receive buffer */
    }
    Result = (byte)((SerFlag & (OVERRUN_ERR|COMMON_ERR|FULL_RX))?ERR_COMMON:ERR_OK);
    SerFlag &= ~(OVERRUN_ERR|COMMON_ERR|FULL_RX|CHAR_IN_RX); /* Clear all errors in the status variable */
    ExitCritical();                    /* Restore the PS register */
  } else {
    return ERR_RXEMPTY;                /* Receiver is empty */
  }
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
  if(AS1_OutLen == AS1_OUT_BUF_SIZE) { /* Is number of chars in the buffer the same as the size of the transmit buffer? */
    return ERR_TXFULL;                 /* If yes then error */
  }
  EnterCritical();                     /* Save the PS register */
  AS1_OutLen++;                        /* Increase number of bytes in the transmit buffer */
  *(OutPtrW++) = Chr;                  /* Store char to the buffer */
  if(OutPtrW >= (OutBuffer + AS1_OUT_BUF_SIZE)) { /* Is the pointer out of the transmit buffer? */
    OutPtrW = OutBuffer;               /* Set the pointer to the first item in the transmit buffer */
  }
  SCI0CR2_TIE = 1;                     /* Enable transmit interrupt */
  ExitCritical();                      /* Restore the PS register */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  AS1_RecvBlock (bean AsynchroSerial)
**
**     Description :
**         If any data is received, this method returns the block of
**         the data and its length (and incidental error), otherwise
**         it returns an error code (it does not wait for data).
**         This method is available only if non-zero length of the
**         input buffer is defined and the receiver property is
**         enabled.
**         If less than requested number of characters is received
**         only the available data is copied from the receive buffer
**         to the user specified destination. The value ERR_EXEMPTY
**         is returned and the value of variable pointed by the Rcv
**         parameter is set to the number of received characters.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Ptr             - Pointer to the block of received data
**         Size            - Size of the block
**       * Rcv             - Pointer to real number of the received
**                           data
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_RXEMPTY - The receive buffer didn't
**                           contain the requested number of data.
**                           Only available data has been returned.
**                           ERR_COMMON - common error occurred (the
**                           GetError method can be used for error
**                           specification)
** ===================================================================
*/
byte AS1_RecvBlock(AS1_TComData *Ptr, word Size, word *Rcv)
{
  word count;                          /* Number of received chars */
  byte result = ERR_OK;                /* Error code to return */

  for(count = 0; count < Size; count++) {
    switch ( AS1_RecvChar(Ptr++)) {
    case ERR_RXEMPTY:
      if (result == ERR_OK) {
        result = ERR_RXEMPTY;
      }
     *Rcv = count;                     /* Return number of received chars */
      return result;
      break;
    case ERR_COMMON:
      result = ERR_COMMON;             /* Return the info that an error was detected */
      break;
    default:
      break;
    }
  }
  *Rcv = count;                        /* Return number of received chars */
  return result;                       /* Return last error code*/
}

/*
** ===================================================================
**     Method      :  AS1_SendBlock (bean AsynchroSerial)
**
**     Description :
**         Sends a block of characters to the channel.
**         This method is available only if non-zero length of the
**         output buffer is defined and the transmitter property is
**         enabled.
**     Parameters  :
**         NAME            - DESCRIPTION
**       * Ptr             - Pointer to the block of data to send
**         Size            - Size of the block
**       * Snd             - Pointer to number of data that are sent
**                           (moved to buffer)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_TXFULL - It was not possible to send
**                           requested number of bytes
** ===================================================================
*/
byte AS1_SendBlock(AS1_TComData *Ptr, word Size, word *Snd)
{
  word count;                          /* Number of sent chars */
  byte result = ERR_OK;                /* Last error */

  for(count = 0; count < Size; count++) {
    result = AS1_SendChar(*Ptr++);
    if(result != ERR_OK) {             /* Sending given number of chars */
      break;                           /* Break data block sending */
    }
  }
  *Snd = count;                        /* Return number of sent chars */
  return result;                       /* Return last error code*/
}

/*
** ===================================================================
**     Method      :  AS1_ClearRxBuf (bean AsynchroSerial)
**
**     Description :
**         Clears the receive buffer.
**         This method is available only if non-zero length of the
**         input buffer is defined and the receiver property is
**         enabled.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte AS1_ClearRxBuf(void)
{
  EnterCritical();                     /* Save the PS register */
  AS1_InpLen = 0;                      /* Set number of chars in the transmit buffer to 0 */
  InpPtrR = InpPtrW = InpBuffer;       /* Set pointers on the first item in the transmit buffer */
  SerFlag &= ~ (CHAR_IN_RX | FULL_RX); /* Clear the flags indicating a char in buffer */
  ExitCritical();                      /* Restore the PS register */
  return ERR_OK;                       /* OK */
}

/*
** ===================================================================
**     Method      :  AS1_ClearTxBuf (bean AsynchroSerial)
**
**     Description :
**         Clears the transmit buffer.
**         This method is available only if non-zero length of the
**         output buffer is defined and the receiver property is
**         enabled.
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/
byte AS1_ClearTxBuf(void)
{
  EnterCritical();                     /* Save the PS register */
  AS1_OutLen = 0;                      /* Set number of chars in the receive buffer to 0 */
  OutPtrR = OutPtrW = OutBuffer;       /* Set pointers on the first item in the receive buffer */
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
/*
word AS1_GetCharsInRxBuf(void)

**      This method is implemented as a macro. See header module. **
*/

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
/*
word AS1_GetCharsInTxBuf(void)

**      This method is implemented as a macro. See header module. **
*/

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
  if(AS1_InpLen < AS1_INP_BUF_SIZE) {  /* Is the number of bytes in the receive buffer lower than the size of the buffer? */
    AS1_InpLen++;                      /* Increse number of chars in the receive buffer */
    *(InpPtrW++) = Data;               /* Save received char to the receive buffer */
    if(InpPtrW >= (InpBuffer + AS1_INP_BUF_SIZE)) { /* Is the pointer out of the receive buffer? */
      InpPtrW = InpBuffer;             /* Set pointer on the first item into the receive buffer */
    }
  } else {
    SerFlag |= FULL_RX;                /* If yes then set flag buffer overflow */
    OnFlags |= ON_ERROR;               /* Set flag "OnError" */
  }
  if(OnFlags & ON_ERROR) {             /* Was an error detected? */
    AS1_OnError();                     /* If yes then invoke user event */
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
  SerFlag &= ~RUNINT_FROM_TX;          /* Reset flag "running int from TX" */
  if(AS1_OutLen) {                     /* Is number of bytes in the transmit buffer greater then 0? */
    AS1_OutLen--;                      /* Decrease number of chars in the transmit buffer */
    SerFlag |= RUNINT_FROM_TX;         /* Set flag "running int from TX"? */
    (void) SCI0SR1;                    /* Reset interrupt request flag */
    SCI0DRL = (byte)*(OutPtrR++);      /* Store char to transmitter register */
    if(OutPtrR >= (OutBuffer + AS1_OUT_BUF_SIZE)) { /* Is the pointer out of the transmit buffer? */
      OutPtrR = OutBuffer;             /* Set pointer on the first item into the transmit buffer */
    }
  }
  else {
    SCI0CR2_TIE = 0;                   /* Disable transmit interrupt */
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
  if (StatReg & SCI0SR1_IDLE_MASK) {   /* Was the idle line condition detected? */
    (void) SCI0DRL;                    /* Dummy read of the data register - clear the IDLE flag */
    AS1_OnIdle();                      /* If yes then invoke user event */
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
  AS1_InpLen = 0;                      /* No char in the receive buffer */
  InpPtrW = InpPtrR = InpBuffer;       /* Set pointer on the first item in the receive buffer */
  AS1_OutLen = 0;                      /* No char in the transmit buffer */
  OutPtrW = OutPtrR = OutBuffer;       /* Set pointer on the first item in the transmit buffer */
  /* SCI0CR2: TIE=0,TCIE=0,RIE=0,ILIE=0,TE=0,RE=0,RWU=0,SBK=0 */
  SCI0CR2 = 0;                         /* Disable error interrupts */
  SCI0BD = 22;                         /* Set prescaler bits */
  SCI0CR2 |= (SCI0CR2_TE_MASK | SCI0CR2_RE_MASK | SCI0CR2_RIE_MASK | SCI0CR2_ILIE_MASK); /* Enable transmitter, Enable receiver, Enable receiver interrupt, Enable idle interrupt */
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
