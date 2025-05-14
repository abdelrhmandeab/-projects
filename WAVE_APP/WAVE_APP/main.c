/*
 * WAVE_APP.c
 *
 * Created: 10/11/2023 5:08:23 PM
 * Author : youssef
 */ 
#include "STD_TYPE.h"
#include "MATH.h"
#include "DIO_interface.h"
#include "Timer0_interface.h"
#include "TIMER1_interface.h"
#include "GIE_interface.h"
#include "EXT_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "Interrupt_Vector.h"
#define F_CPU 16000000UL
#include <util/delay.h>

volatile static u32 ON_TICK=0;
volatile static u32 TOV_TICK=0;
static u8 counter =0;
u8 i =0;
void SW_ICU(void);

int main(void){	
	ch8 Signal_Right[8]={0x00,0x00,0x00,0x10,0x08,0x04,0x03,0x00};
	ch8 Signal_Left[8]={0x00,0x00,0x00,0x01,0x02,0x04,0x18,0x00};
	ch8 Erase[8] = { 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
	
	
		DIO_Vid_Set_Pin_Dir(PORTD,PIN3,INPUT);
		DIO_Vid_Set_Pin_Dir(PORTB,PIN3,OUTPUT);
		DIO_Vid_Set_Pin_Dir(PORTB,PIN2,INPUT);
	/* LCD INIT */
	DIO_Vid_Set_Port_Dir(LCD_DPORT,0xf0);
	DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_RS_PIN,OUTPUT);
	DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_RW_PIN,OUTPUT);
	DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_EN_PIN,OUTPUT);
	LCD_Vid_Init();
	
	/* ENABLE GIE */
	GIE_Vid_Interrupt_Enable();
	/* INTERRUPT INIT */
	EXT_Vid_Interrupt_Init(RISING_EDGE);
	EXT_Vid_Interrupt_Initt();
	/*ENABLE EXT INTERRUPT*/
	EXT_Vid_Enable_Interrupt0();
	
	/*TIMER 1 INIT*/
	TIMER1_Vid_NormalMode_Init();
	Set_fun(SW_ICU);
	LCD_Vid_CUSTOM_CHAR(Signal_Right,0,0,0);
	LCD_Vid_CUSTOM_CHAR(Signal_Left,1,0,0);
	LCD_Vid_CUSTOM_CHAR(Erase,2,0,0);

	while (1)
	{
		
		EXT_Vid_Enable_Interrupt1();
		EXT_Vid_Enable_Interrupt2();
	
	
		if(counter==0){
			while(counter==0){
				
			LCD_Vid_GOTOxy(20,1);
			LCD_Vid_SEND_STRING("TON:");
			LCD_Vid_Send_NUM(ON_TICK);
			LCD_Vid_GOTOxy(33,1);
			LCD_Vid_SEND_STRING("TOV:");
			LCD_Vid_Send_NUM(TOV_TICK);
			LCD_Vid_GOTOxy(0,1);
			LCD_Vid_SEND_STRING("freq:");
			LCD_Vid_Send_NUM(16000000/(ON_TICK*64));
			
			LCD_Vid_GOTOxy(38,0);
			LCD_Vid_SEND_STRING	("0%");
			LCD_Vid_GOTOxy(0,0);
			LCD_Vid_SEND_STRING("______________________________________");
			
			}
		}
		if(counter==10){
			TIMER0_VID_Fast_PWM(10);
			
			LCD_Vid_GOTOxy(20,1);
			LCD_Vid_SEND_STRING("TON:");
			LCD_Vid_Send_NUM(ON_TICK);
			LCD_Vid_GOTOxy(26,1);
			LCD_Vid_SEND_STRING(" ");
			LCD_Vid_GOTOxy(33,1);
			LCD_Vid_SEND_STRING("TOV:");
			LCD_Vid_Send_NUM(TOV_TICK);
			LCD_Vid_GOTOxy(0,1);
			LCD_Vid_SEND_STRING("freq:");
			LCD_Vid_Send_NUM(16000000/(ON_TICK*64));
			LCD_Vid_GOTOxy(9,1);
			LCD_Vid_SEND_STRING(" ");
		
				LCD_Vid_GOTOxy(37,0);
				LCD_Vid_SEND_STRING("10%");
				while(counter==10){
					
						
					if(i>=32){
						LCD_Vid_GOTOxy(31,0);
						LCD_Vid_Send_Data(2);
						LCD_Vid_GOTOxy(32,0);
						LCD_Vid_Send_Data(2);
						LCD_Vid_GOTOxy(33,0);
						LCD_Vid_Send_Data(2);
						LCD_Vid_GOTOxy(34,0);
						LCD_Vid_Send_Data(2);
						LCD_Vid_GOTOxy(30,0);
						LCD_Vid_SEND_STRING("_____");
						i=0;
						
						
					}
					LCD_Vid_GOTOxy(0,0);
					LCD_Vid_SEND_STRING("________________________________");
					LCD_Vid_GOTOxy(i,0);
					LCD_Vid_Send_Data(1);
					LCD_Vid_GOTOxy(i+1,0);
					LCD_Vid_SEND_STRING("-");
					LCD_Vid_GOTOxy(i+2,0);
					LCD_Vid_Send_Data(0);
					LCD_Vid_GOTOxy(i+3,0);
					LCD_Vid_SEND_STRING("_");
					_delay_ms(50);
					i++;
				

				}
			
		}
		if(counter==20){
			TIMER0_VID_Fast_PWM(20);
			
			LCD_Vid_GOTOxy(20,1);
			LCD_Vid_SEND_STRING("TON:");
			LCD_Vid_Send_NUM(ON_TICK);
			LCD_Vid_GOTOxy(26,1);
			LCD_Vid_SEND_STRING(" ");
			LCD_Vid_GOTOxy(33,1);
			LCD_Vid_SEND_STRING("TOV:");
			LCD_Vid_Send_NUM(TOV_TICK);
			LCD_Vid_GOTOxy(0,1);
			LCD_Vid_SEND_STRING("freq:");
			LCD_Vid_Send_NUM(16000000/(ON_TICK*64));
			LCD_Vid_GOTOxy(9,1);
			LCD_Vid_SEND_STRING(" ");
			
			LCD_Vid_GOTOxy(37,0);
			LCD_Vid_SEND_STRING("20%");
				while(counter==20){
					
					if(i>=32){
						LCD_Vid_GOTOxy(31,0);
						LCD_Vid_Send_Data(2);
						LCD_Vid_GOTOxy(32,0);
						LCD_Vid_Send_Data(2);
						LCD_Vid_GOTOxy(33,0);
						LCD_Vid_Send_Data(2);
						LCD_Vid_GOTOxy(34,0);
						LCD_Vid_Send_Data(2);
						LCD_Vid_GOTOxy(30,0);
						LCD_Vid_SEND_STRING("_____");
						
						i=0;
					}
					LCD_Vid_GOTOxy(0,0);
					LCD_Vid_SEND_STRING("________________________________");
					LCD_Vid_GOTOxy(i,0);
					LCD_Vid_Send_Data(1);
					LCD_Vid_GOTOxy(i+1,0);
					LCD_Vid_SEND_STRING("--");
					LCD_Vid_GOTOxy(i+3,0);
					LCD_Vid_Send_Data(0);
					LCD_Vid_GOTOxy(i+4,0);
					LCD_Vid_SEND_STRING("_");
					_delay_ms(40);
					i++;

				}
				
			
			
		}
		
		
		
		
		if(counter==30){
			TIMER0_VID_Fast_PWM(30);
			
			LCD_Vid_GOTOxy(20,1);
			LCD_Vid_SEND_STRING("TON:");
			LCD_Vid_Send_NUM(ON_TICK);
			LCD_Vid_GOTOxy(26,1);
			LCD_Vid_SEND_STRING(" ");
			LCD_Vid_GOTOxy(33,1);
			LCD_Vid_SEND_STRING("TOV:");
			LCD_Vid_Send_NUM(TOV_TICK);
			LCD_Vid_GOTOxy(0,1);
			LCD_Vid_SEND_STRING("freq:");
			LCD_Vid_Send_NUM(16000000/(ON_TICK*64));
			LCD_Vid_GOTOxy(9,1);
			LCD_Vid_SEND_STRING(" ");
			
			LCD_Vid_GOTOxy(37,0);
			LCD_Vid_SEND_STRING("30%");
			while(counter==30){
				
				if(i>=31){
					LCD_Vid_GOTOxy(31,0);
					LCD_Vid_Send_Data(2);
					LCD_Vid_GOTOxy(32,0);
					LCD_Vid_Send_Data(2);
					LCD_Vid_GOTOxy(33,0);
					LCD_Vid_Send_Data(2);
					LCD_Vid_GOTOxy(34,0);
					LCD_Vid_Send_Data(2);
					LCD_Vid_GOTOxy(30,0);
					LCD_Vid_SEND_STRING("_____");
					
					i=0;
					
					
				}
				LCD_Vid_GOTOxy(0,0);
				LCD_Vid_SEND_STRING("________________________________");
				LCD_Vid_GOTOxy(i,0);
				LCD_Vid_Send_Data(1);
				LCD_Vid_GOTOxy(i+1,0);
				LCD_Vid_SEND_STRING("---");
				LCD_Vid_GOTOxy(i+4,0);
				LCD_Vid_Send_Data(0);
				LCD_Vid_GOTOxy(i+5,0);
				LCD_Vid_SEND_STRING("_");
				_delay_ms(50);
				i++;

			}
			
			
		}
		
				
				
				if(counter==40){
					TIMER0_VID_Fast_PWM(40);
					
					LCD_Vid_GOTOxy(20,1);
					LCD_Vid_SEND_STRING("TON:");
					LCD_Vid_Send_NUM(ON_TICK);
					LCD_Vid_GOTOxy(33,1);
					LCD_Vid_SEND_STRING("TOV:");
					LCD_Vid_Send_NUM(TOV_TICK);
					LCD_Vid_GOTOxy(0,1);
					LCD_Vid_SEND_STRING("freq:");
					LCD_Vid_Send_NUM(16000000/(ON_TICK*64));
					LCD_Vid_GOTOxy(9,1);
					LCD_Vid_SEND_STRING(" ");
					
					LCD_Vid_GOTOxy(37,0);
					LCD_Vid_SEND_STRING("40%");
					while(counter==40){
						
						if(i>=30){
							LCD_Vid_GOTOxy(31,0);
							LCD_Vid_Send_Data(2);
							LCD_Vid_GOTOxy(32,0);
							LCD_Vid_Send_Data(2);
							LCD_Vid_GOTOxy(33,0);
							LCD_Vid_Send_Data(2);
							LCD_Vid_GOTOxy(34,0);
							LCD_Vid_Send_Data(2);
							LCD_Vid_GOTOxy(30,0);
							LCD_Vid_SEND_STRING("_____");
							
							i=0;
							
							
						}
						LCD_Vid_GOTOxy(0,0);
						LCD_Vid_SEND_STRING("________________________________");
						LCD_Vid_GOTOxy(i,0);
						LCD_Vid_Send_Data(1);
						LCD_Vid_GOTOxy(i+1,0);
						LCD_Vid_SEND_STRING("----");
						LCD_Vid_GOTOxy(i+5,0);
						LCD_Vid_Send_Data(0);
						LCD_Vid_GOTOxy(i+6,0);
						LCD_Vid_SEND_STRING("_");
						_delay_ms(50);
						i++;

					}
					
					
				}
						
						
						if(counter==50){
							TIMER0_VID_Fast_PWM(50);
							
							LCD_Vid_GOTOxy(20,1);
							LCD_Vid_SEND_STRING("TON:");
							LCD_Vid_Send_NUM(ON_TICK);
							LCD_Vid_GOTOxy(33,1);
							LCD_Vid_SEND_STRING("TOV:");
							LCD_Vid_Send_NUM(TOV_TICK);
							LCD_Vid_GOTOxy(0,1);
							LCD_Vid_SEND_STRING("freq:");
							LCD_Vid_Send_NUM(16000000/(ON_TICK*64));
							LCD_Vid_GOTOxy(9,1);
							LCD_Vid_SEND_STRING(" ");
							
							LCD_Vid_GOTOxy(37,0);
							LCD_Vid_SEND_STRING("50%");
							while(counter==50){
								
								if(i>=29){
									LCD_Vid_GOTOxy(31,0);
									LCD_Vid_Send_Data(2);
									LCD_Vid_GOTOxy(32,0);
									LCD_Vid_Send_Data(2);
									LCD_Vid_GOTOxy(33,0);
									LCD_Vid_Send_Data(2);
									LCD_Vid_GOTOxy(34,0);
									LCD_Vid_Send_Data(2);
									LCD_Vid_GOTOxy(30,0);
									LCD_Vid_SEND_STRING("_____");
									
									i=0;
									
									
								}
								LCD_Vid_GOTOxy(0,0);
								LCD_Vid_SEND_STRING("________________________________");
								LCD_Vid_GOTOxy(i,0);
								LCD_Vid_Send_Data(1);
								LCD_Vid_GOTOxy(i+1,0);
								LCD_Vid_SEND_STRING("-----");
								LCD_Vid_GOTOxy(i+6,0);
								LCD_Vid_Send_Data(0);
								LCD_Vid_GOTOxy(i+7,0);
								LCD_Vid_SEND_STRING("_");
								_delay_ms(50);
								i++;

							}
							
							
						}
								
								
								if(counter==60){
									TIMER0_VID_Fast_PWM(60);
									
									LCD_Vid_GOTOxy(20,1);
									LCD_Vid_SEND_STRING("TON:");
									LCD_Vid_Send_NUM(ON_TICK);
									LCD_Vid_GOTOxy(33,1);
									LCD_Vid_SEND_STRING("TOV:");
									LCD_Vid_Send_NUM(TOV_TICK);
									LCD_Vid_GOTOxy(0,1);
									LCD_Vid_SEND_STRING("freq:");
									LCD_Vid_Send_NUM(16000000/(ON_TICK*64));
									LCD_Vid_GOTOxy(9,1);
									LCD_Vid_SEND_STRING(" ");
									
								LCD_Vid_GOTOxy(37,0);
								LCD_Vid_SEND_STRING("60%");
								while(counter==60){
									
									if(i>=28){
										LCD_Vid_GOTOxy(31,0);
										LCD_Vid_Send_Data(2);
										LCD_Vid_GOTOxy(32,0);
										LCD_Vid_Send_Data(2);
										LCD_Vid_GOTOxy(33,0);
										LCD_Vid_Send_Data(2);
										LCD_Vid_GOTOxy(34,0);
										LCD_Vid_Send_Data(2);
										LCD_Vid_GOTOxy(30,0);
										LCD_Vid_SEND_STRING("_____");
										
										i=0;
										
										
									}
									LCD_Vid_GOTOxy(0,0);
									LCD_Vid_SEND_STRING("________________________________");
									LCD_Vid_GOTOxy(i,0);
									LCD_Vid_Send_Data(1);
									LCD_Vid_GOTOxy(i+1,0);
									LCD_Vid_SEND_STRING("------");
									LCD_Vid_GOTOxy(i+7,0);
									LCD_Vid_Send_Data(0);
									LCD_Vid_GOTOxy(i+8,0);
									LCD_Vid_SEND_STRING("_");
									_delay_ms(50);
									i++;

								}
									
									
								}
									
										
								if(counter==70){
									TIMER0_VID_Fast_PWM(70);
									
									LCD_Vid_GOTOxy(20,1);
									LCD_Vid_SEND_STRING("TON:");
									LCD_Vid_Send_NUM(ON_TICK);
									LCD_Vid_GOTOxy(33,1);
									LCD_Vid_SEND_STRING("TOV:");
									LCD_Vid_Send_NUM(TOV_TICK);
									LCD_Vid_GOTOxy(0,1);
									LCD_Vid_SEND_STRING("freq:");
									LCD_Vid_Send_NUM(16000000/(ON_TICK*64));
									LCD_Vid_GOTOxy(9,1);
									LCD_Vid_SEND_STRING(" ");
									
									LCD_Vid_GOTOxy(37,0);
									LCD_Vid_SEND_STRING("70%");
									while(counter==70){
										
										if(i>=27){
											LCD_Vid_GOTOxy(31,0);
											LCD_Vid_Send_Data(2);
											LCD_Vid_GOTOxy(32,0);
											LCD_Vid_Send_Data(2);
											LCD_Vid_GOTOxy(33,0);
											LCD_Vid_Send_Data(2);
											LCD_Vid_GOTOxy(34,0);
											LCD_Vid_Send_Data(2);
											LCD_Vid_GOTOxy(30,0);
											LCD_Vid_SEND_STRING("_____");
											
											i=0;
											
											
										}
										LCD_Vid_GOTOxy(0,0);
										LCD_Vid_SEND_STRING("________________________________");
										LCD_Vid_GOTOxy(i,0);
										LCD_Vid_Send_Data(1);
										LCD_Vid_GOTOxy(i+1,0);
										LCD_Vid_SEND_STRING("--------");
										LCD_Vid_GOTOxy(i+8,0);
										LCD_Vid_Send_Data(0);
										LCD_Vid_GOTOxy(i+9,0);
										LCD_Vid_SEND_STRING("_");
										_delay_ms(50);
										i++;

									}
											
											
										}
												
												
							if(counter==80){
								TIMER0_VID_Fast_PWM(80);
								
								LCD_Vid_GOTOxy(20,1);
								LCD_Vid_SEND_STRING("TON:");
								LCD_Vid_Send_NUM(ON_TICK);
								LCD_Vid_GOTOxy(33,1);
								LCD_Vid_SEND_STRING("TOV:");
								LCD_Vid_Send_NUM(TOV_TICK);
								LCD_Vid_GOTOxy(0,1);
								LCD_Vid_SEND_STRING("freq:");
								LCD_Vid_Send_NUM(16000000/(ON_TICK*64));
								LCD_Vid_GOTOxy(9,1);
								LCD_Vid_SEND_STRING(" ");
								
								LCD_Vid_GOTOxy(37,0);
								LCD_Vid_SEND_STRING("80%");
								while(counter==80){
									
									if(i>=26){
										LCD_Vid_GOTOxy(31,0);
										LCD_Vid_Send_Data(2);
										LCD_Vid_GOTOxy(32,0);
										LCD_Vid_Send_Data(2);
										LCD_Vid_GOTOxy(33,0);
										LCD_Vid_Send_Data(2);
										LCD_Vid_GOTOxy(34,0);
										LCD_Vid_Send_Data(2);
										LCD_Vid_GOTOxy(30,0);
										LCD_Vid_SEND_STRING("_____");
										
										i=0;
										
										
									}
									LCD_Vid_GOTOxy(0,0);
									LCD_Vid_SEND_STRING("________________________________");
									LCD_Vid_GOTOxy(i,0);
									LCD_Vid_Send_Data(1);
									LCD_Vid_GOTOxy(i+1,0);
									LCD_Vid_SEND_STRING("---------");
									LCD_Vid_GOTOxy(i+9,0);
									LCD_Vid_Send_Data(0);
									LCD_Vid_GOTOxy(i+10,0);
									LCD_Vid_SEND_STRING("_");
									_delay_ms(50);
									i++;
							
								}
								
								
							}
							
							
							if(counter==90){
								TIMER0_VID_Fast_PWM(90);
								
								LCD_Vid_GOTOxy(20,1);
								LCD_Vid_SEND_STRING("TON:");
								LCD_Vid_Send_NUM(ON_TICK);
								LCD_Vid_GOTOxy(33,1);
								LCD_Vid_SEND_STRING("TOV:");
								LCD_Vid_Send_NUM(TOV_TICK);
								LCD_Vid_GOTOxy(0,1);
								LCD_Vid_SEND_STRING("freq:");
								LCD_Vid_Send_NUM(16000000/(ON_TICK*64));
								LCD_Vid_GOTOxy(9,1);
								LCD_Vid_SEND_STRING(" ");
								
								LCD_Vid_GOTOxy(37,0);
								LCD_Vid_SEND_STRING("90%");
								while(counter==90){
									
									if(i>=25){
										LCD_Vid_GOTOxy(31,0);
										LCD_Vid_Send_Data(2);
										LCD_Vid_GOTOxy(32,0);
										LCD_Vid_Send_Data(2);
										LCD_Vid_GOTOxy(33,0);
										LCD_Vid_Send_Data(2);
										LCD_Vid_GOTOxy(34,0);
										LCD_Vid_Send_Data(2);
										LCD_Vid_GOTOxy(30,0);
										LCD_Vid_SEND_STRING("_____");
										
										i=0;
										
										
									}
									LCD_Vid_GOTOxy(0,0);
									LCD_Vid_SEND_STRING("_____________________________________");
									LCD_Vid_GOTOxy(i,0);
									LCD_Vid_Send_Data(1);
									LCD_Vid_GOTOxy(i+1,0);
									LCD_Vid_SEND_STRING("---------");
									LCD_Vid_GOTOxy(i+10,0);
									LCD_Vid_Send_Data(0);
									LCD_Vid_GOTOxy(i+11,0);
									LCD_Vid_SEND_STRING("_");
									_delay_ms(50);
									i++;
									
								}
								
								
							}
							if (counter==100)
							{
								TIMER0_VID_Fast_PWM(99);
								
								LCD_Vid_GOTOxy(20,1);
								LCD_Vid_SEND_STRING("TON:");
								LCD_Vid_Send_NUM(ON_TICK);
								LCD_Vid_GOTOxy(33,1);
								LCD_Vid_SEND_STRING("TOV:");
								LCD_Vid_Send_NUM(TOV_TICK);
								LCD_Vid_GOTOxy(0,1);
								LCD_Vid_SEND_STRING("freq:");
								LCD_Vid_Send_NUM(16000000/(ON_TICK*64));
								LCD_Vid_GOTOxy(8,1);
								LCD_Vid_SEND_STRING("  ");
								
								LCD_Vid_GOTOxy(36,0);
								LCD_Vid_SEND_STRING("100%");
								LCD_Vid_GOTOxy(0,0);
								LCD_Vid_SEND_STRING("------------------------------------");								
								
							}
																			
		
		
	}
}

void SW_ICU(void)
{
	static u8 count = 0 ;
	count++;
	if(count==1){
		/* RESET TIMER*/
		TIMER1_Vid_Reset_Timer();
		EXT_Vid_Interrupt_Init(FALLING_EDGE);
		
	}
	else if(count == 2){
		
		ON_TICK=TIMER1_u32_ReadVal();
		EXT_Vid_Interrupt_Init(RISING_EDGE);
		
	}
	
	else if(count == 3){
		
		TOV_TICK=TIMER1_u32_ReadVal();
		
	}
	
	
}


void __vector_2(void)__attribute__((signal)) ;
void __vector_2(void)
{

	counter+=10;

}
void __vector_3(void)__attribute__((signal)) ;
void __vector_3(void)
{

	counter-=10;

}