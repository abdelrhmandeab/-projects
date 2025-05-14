/*
 * TIMER1_interface.c
 *
 * Created: 10/3/2023 12:45:20 AM
 *  Author: youssef
 */ 

#include "STD_TYPE.h"
#include "MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "Timer1_private.h"
#include "Timer1_interface.h"
#include "GIE_interface.h"
#include "GIE_privte.h"






//void TIMER1_VID_Fast_PWM(u8 copy_u8_Duty){
	
//	SET_BIT(TCCR1B_Reg,CS10_PIN); /* Start + PRESCALER 64 */
	
	//SET_BIT(TCCR1B_Reg,CS11_PIN);
	//CLR_BIT(TCCR1B_Reg,CS12_PIN);
	
	//CLR_BIT(TCCR1A_Reg,COM1A0_PIN);  /*SLECT NON INVERTING MODE */
	//SET_BIT(TCCR1A_Reg,COM1A1_PIN);
	
	//SET_BIT(TCCR1A_Reg,WGM10_PIN); /* Select FAST PWM 10 BIT RES */
	//SET_BIT(TCCR1A_Reg,WGM11_PIN);
	//SET_BIT(TCCR1A_Reg,WGM12_PIN);
	//CLR_BIT(TCCR1A_Reg,WGM13_PIN);
	
	//OCR1AH_Reg=0;
	//OCR1AL_Reg=copy_u8_Duty*10.24;
	
	//while(GET_BIT(TIFR_Reg,OCF1A_PIN)==0);
	//SET_BIT(TIFR_Reg,OCF1A_PIN);
	
	
	
	
	
//}
void TIMER_Vid_FastPWM_ICR1_Init(void){
	
	
	CLR_BIT(TCCR1A_Reg,COM1A0_PIN);  /*SLECT NON INVERTING MODE Fast PWM */
	SET_BIT(TCCR1A_Reg,COM1A1_PIN);
	
	/* ICR MODE*/
		
	CLR_BIT(TCCR1A_Reg,WGM10_PIN); 
	SET_BIT(TCCR1A_Reg,WGM11_PIN);
	SET_BIT(TCCR1B_Reg,WGM12_PIN);
	SET_BIT(TCCR1B_Reg,WGM13_PIN);
	
	ICR1_Reg=40000;
	/* SET OCR1A */
	//OCR1A_Reg=2000;
	
	/* Select Prescaler */
	CLR_BIT(TCCR1B_Reg,CS10_PIN); 
	SET_BIT(TCCR1B_Reg,CS11_PIN);
	CLR_BIT(TCCR1B_Reg,CS12_PIN);
	
	
	
}


void TIMER1_Vid_SetCompareVal(u32 copy_u32_val){
	
	OCR1A_Reg=copy_u32_val;
	
}

void TIMER1_Vid_NormalMode_Init(){
	/* SELECT NORMAL MODE */
	
			
	CLR_BIT(TCCR1A_Reg,WGM10_PIN);
	CLR_BIT(TCCR1A_Reg,WGM11_PIN);
	CLR_BIT(TCCR1B_Reg,WGM12_PIN);
	CLR_BIT(TCCR1B_Reg,WGM13_PIN);
	
	/* SELECT PRESCALER */
	
	SET_BIT(TCCR1B_Reg,CS10_PIN);
	
	SET_BIT(TCCR1B_Reg,CS11_PIN);
	CLR_BIT(TCCR1B_Reg,CS12_PIN);
	
	
	
	
}
void TIMER1_Vid_Reset_Timer(){
	TCNT1_Reg=0x00;
	
	
	
}
u32  TIMER1_u32_ReadVal(){
	
	return TCNT1_Reg;
}
