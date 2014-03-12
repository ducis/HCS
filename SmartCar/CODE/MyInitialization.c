/** ###################################################################
**     Filename  : MyInitialization.C
**     Project   : SmartCar
**     Processor : MC9S12DG128BCPV
**     Compiler  : CodeWarrior HC12 C Compiler
**     Date/Time : 2010-3-7, 21:09
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
/* Including needed modules to compile this module/procedure */
#include "MainMotor.h"
#include "VehicleStats.h"
#include "EYE.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
/* MODULE MyInitialization */
void MyInitialization(void){
    //PLL
    REFDV=1;								   										 	    
	  SYNR=4;			                        // 总线周期=16Mhz*(SYNR+1)/(REFDV+1)=40MHz
	  while(0==CRGFLG_LOCK);              // 等待 VCO 稳定
	  CLKSEL=0x80;
	  MainMotor_SetDutyTicks16(0); 
	  MainMotor_Enable();
	  EYE_Setup(g_eyez,FIRSTROW);
	  EYE_Setup(g_eyez+1,SECONDROW);
	  g_eyez[0].m_last_diode=3;
	  g_eyez[1].m_last_diode=2; 
	  {
	     unsigned char i;
	     for(i=0;i<10;i++)
       {
          his_v[i]=0;
          his_steer1[i]=STEER1_CENTER;
          his_steer2[i]=STEER2_CENTER;  
          first_diff[i]=0;
          g_eyez[0].m_his_line[i]=100;
          g_eyez[1].m_his_line[i]=100;
       }
       i=0;
	  }
}