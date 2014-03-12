/** ###################################################################
**     THIS BEAN MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : PE_Timer.C
**     Project   : ProjectPWM
**     Processor : MC9S12XS128MAL
**     Beantype  : PE_Timer
**     Version   : Driver 01.03
**     Compiler  : CodeWarrior HCS12X C Compiler
**     Date/Time : 2009-12-5, 13:47
**     Abstract  :
**         This module "PE_Timer" implements internal methods and definitions
**         used by beans working with timers.
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


/* MODULE PE_Timer. */

#include "PE_Timer.h"


typedef unsigned long UINT32;

typedef union {
  UINT32 val;
  struct {
    unsigned short hi16, lo16;
  } s;
} OP_UINT32;

typedef struct {
  unsigned short dummy;
  UINT32 mid;
} M_UINT32;

typedef struct {
  UINT32 hi32, lo32;
} UINT64;

typedef union {
  UINT64 val;
  M_UINT32 m;
} OP_UINT64;

/*
** ===================================================================
**     Method      :  PE_Timer_LngMul (bean PE_Timer)
**
**     Description :
**         The method multiplies two 32 bit values and returns pointer to 
**         64 bit result.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
void PE_Timer_LngMul(dword va1, dword va2, dlong *var)
{
  OP_UINT32 *va = (OP_UINT32*)&va1;
  OP_UINT32 *vb = (OP_UINT32*)&va2;
  OP_UINT64 *vr = (OP_UINT64*)var;

  vr->val.hi32 = 0UL;
  vr->val.lo32 = ((UINT32)va->s.lo16) * ((UINT32)vb->s.lo16);
  {
    OP_UINT32 tmp;

    tmp.val = ((UINT32)va->s.lo16) * ((UINT32)vb->s.hi16);
    vr->m.mid += (UINT32)tmp.s.lo16;
    vr->val.hi32 += (UINT32)tmp.s.hi16;
  }
  {
    OP_UINT32 tmp;

    tmp.val = ((UINT32)va->s.hi16) * ((UINT32)vb->s.lo16);
    vr->m.mid += (UINT32)tmp.s.lo16;
    vr->val.hi32 += (UINT32)tmp.s.hi16;
  }
  vr->val.hi32 += ((UINT32)va->s.hi16) * ((UINT32)vb->s.hi16);
}

/*
** ===================================================================
**     Method      :  PE_Timer_LngHi3 (bean PE_Timer)
**
**     Description :
**         The method transfers 64 bit result to 16 bit ratio value and 
**         returns overflow flag.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
bool PE_Timer_LngHi3(dword High, dword Low, word *Out)
{
  if ((High >> 8) == 0) {
    if ((Low & 0x800000LU) != 0) {
      if (((Low >> 24) | (High << 8)) < 0xFFFFLU) {
        *Out = ((word)((Low >> 24) | (High << 8))) + 1;
        return FALSE;
      }
    } else {
      *Out = (word)((Low >> 24) | (High << 8));
      return FALSE;
    }
  }
  *Out = (word)((Low >> 24) | (High << 8));
  return TRUE;
}

/*
** ===================================================================
**     Method      :  PE_Timer_LngHi4 (bean PE_Timer)
**
**     Description :
**         The method transfers 64 bit result to 16 bit ratio value and 
**         returns overflow flag.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
bool PE_Timer_LngHi4(dword High, dword Low, word *Out)
{
  if ((High >> 16) == 0) {
    if ((Low & 0x80000000LU) != 0) {
      if (High < 0xFFFFLU) {
        *Out = ((word)High) + 1;
        return FALSE;
      }
    } else {
      *Out = (word)High;
      return FALSE;
    }
  }
  *Out = (word)High;
  return TRUE;
}



/* END PE_Timer. */

/*
** ###################################################################
**
**     This file was created by UNIS Processor Expert 3.00 [04.12]
**     for the Freescale HCS12X series of microcontrollers.
**
** ###################################################################
*/
