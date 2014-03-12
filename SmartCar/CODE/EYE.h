/** ###################################################################
**     Filename  : EYE.H
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

#ifndef __EYE_H
#define __EYE_H

/* MODULE EYE */

#define EYE_MAX 16
typedef struct{
  unsigned char m_nSen;
  unsigned char m_current[EYE_MAX];
  unsigned char m_his_current[EYE_MAX][10];
  unsigned char m_coordinate[EYE_MAX];
  unsigned char m_demarcate[EYE_MAX][2];   //¶¨½ç
  unsigned char m_last_diode;  
  unsigned char m_filter[EYE_MAX];
  unsigned short m_current_line;
  unsigned char m_his_line[10]; 
  unsigned char m_array[EYE_MAX][2];
  unsigned char m_mainArray[FIRSTROW][2];
}EYE;
extern EYE g_eyez[2];
void EYE_Setup(EYE *pEye,unsigned char nSensors);
/* END EYE */

#endif

