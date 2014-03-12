/** ###################################################################
**     Filename  : EYE.C
**     Project   : SmartCar
**     Processor : MC9S12DG128BCPV
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 2010-3-16, 0:54
**     Contents  :
**         User source code
**
**     (c) Copyright UNIS, a.s. 1997-2008
**     UNIS, a.s.
**     Jundrovska 33
**     624 00 Brno
**     Czech Republic
**     http      : www.processorexpert.com
**     mail      : info@processorexpert.com
** ###################################################################*/

/* MODULE EYE */
#include "EYE.h"
#include "stdio.h"
EYE g_eyez[2];
void EYE_Setup(EYE *pEye,unsigned char nSensors){
   memset(pEye,0,sizeof(EYE));
   pEye->m_nSen=nSensors;
   {
      unsigned char i;
      for(i=0;i<EYE_MAX;i++)
      {
        m_mainArray[i][0]=0xff;
        m_mainArray[i][1]=0x00;    
      }
   }
}



/* END EYE */
