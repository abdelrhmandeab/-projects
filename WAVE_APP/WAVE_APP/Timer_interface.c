/*
 * Timer_interface.c
 *
 * Created: 9/26/2023 3:39:54 PM
 *  Author: youssef
 */ 

#include "STD_TYPE.h"
#include "MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "Timer0_private.h"
#include "Timer0_interface.h"
#include "GIE_interface.h"
#include "GIE_privte.h"
//#include "Interrupt_Vector.h"


void (*OV_MODE_ptr)(void)=null;
void (*CTC_MODE_ptr)(void)=null;

void Timer0_Vid_Init(u8 copy_u8_mode){
	
	/* select presclaer  */
	TCCR0_Reg&=0b11111000 ; // start +  64 prescaler
	TCCR0_Reg|=Prescalerms ; // start +  64 prescaler
	/* ENABLE GLOBAL INTERRUPT  */
	GIE_Vid_Interrupt_Enable() ;
	/* ENABLE  OVF INTERRUPT  */
	if(copy_u8_mode==OVF_MODE)
	SET_BIT(TIMSK_Reg ,TOIE0) ;
		
	else if(copy_u8_mode==CTC_MODE){
	/*SET CTC MODE*/
	SET_BIT(TCCR0_Reg,WGM01_PIN);
	CLR_BIT(TCCR0_Reg,WGM00_PIN);
	
	OCR0_Reg=OCR0_VAL;
	
	/* ENABLE OCR INTERRUPT*/
	SET_BIT(TIMSK_Reg,OCIE0); 
	
	
	}
		
}





void Timer0_Vid_Delayms(u16 copy_u16_timems){
	u16 counter=0;
	copy_u16_timems=copy_u16_timems/1.024;
			
					
	while(counter<copy_u16_timems){
			TCCR0_Reg&=0b00000111;
			TCCR0_Reg|=Prescalerms;
			
			while(GET_BIT(TIFR_Reg,TOV0)==0);
			SET_BIT(TIFR_Reg,TOV0);
			
			counter++;
	}
		TCCR0_Reg=DIVISION0;
}



void Timer0_Vid_Delayus(f64 copy_u16_timeus){
	
	
		u16 counter=0;
		copy_u16_timeus=copy_u16_timeus/16;
	
						
	while(counter<copy_u16_timeus){
		TCCR0_Reg&=0b00000111;
		TCCR0_Reg|=Prescalerus;
		
		while(GET_BIT(TIFR_Reg,TOV0)==0);
		SET_BIT(TIFR_Reg,TOV0);
		
		counter++;
		}
		
	TCCR0_Reg=DIVISION0;
	
}

void TIMER0_VID_Fast_PWM(u8 copy_u8_DutyCycle){
	/*SELECT PRESCALER*/
	TCCR0_Reg&=0b11111000 ; // start +  64 prescaler
	TCCR0_Reg|=Prescalerms ; // start +  64 prescaler
	
	/*SELECT FACT PWM*/
	SET_BIT(TCCR0_Reg,WGM00_PIN);
	SET_BIT(TCCR0_Reg,WGM01_PIN);
	
	/*SELECT NON INVERTING MODE*/
	
	SET_BIT(TCCR0_Reg,COM01_PIN);
	CLR_BIT(TCCR0_Reg,COM00_PIN);
	
	/*SET OCR OCR=D*2.56*/
	
	OCR0_Reg=copy_u8_DutyCycle*2.56;
	
	/*WAIT TO CTC HAPPEN*/
	
	while(GET_BIT(TIFR_Reg,OCF0)==0);
	
	/*CLR CTC FLAG*/
	
	SET_BIT(TIFR_Reg,OCF0);
	
	
	
	
}

void TIME0_Vid_SetCallBack(u8 copy_u8_mode , void (*ptr_fun)(void))
{
	
	if(copy_u8_mode==OVF_MODE)
	OV_MODE_ptr=ptr_fun;
	else if (copy_u8_mode==CTC_MODE)
	CTC_MODE_ptr=ptr_fun;
}



