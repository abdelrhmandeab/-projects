/*
 * remote_control.c
 *
 * Created: 7/11/2024 2:54:36 AM
 * Author : bodyy
 */ 

#include "DIO_interface.h"
#include "Keypad_config.h"
#include "Keypad_interface.h"
#include "UART_interface.h"
#include "LCD_config.h"
#include "LCD_interface.h"
#include "STD_TYPE.h"
#include "MATH.h"
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void){
	
	/* LCD DIR */
	DIO_Vid_Set_Port_Dir(LCD_DPORT,PORT_OUTPUT);
	DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_RS_PIN,OUTPUT);
	DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_RW_PIN,OUTPUT);
	DIO_Vid_Set_Pin_Dir(LCD_CPORT,LCD_EN_PIN,OUTPUT);
	
	LCD_Vid_Init();
		
	KEYPAD_Vid_Init();
	UART_Vid_Init();
	DIO_Vid_Set_Pin_Dir(PORTD,PIN1,OUTPUT); 
	u8 Loc_u8_val = 0;
	
	LCD_Vid_Send_String("welcome :)");
	_delay_ms(1000);
	LCD_Vid_Send_Command(LCD_CLR);	
  while (1){
		Loc_u8_val=KEYPAD_u8_Get_Key();
		if(Loc_u8_val == 2){
			UART_Vid_TX('F');
			LCD_Vid_Send_Command(LCD_CLR);
			LCD_Vid_Send_String("forward");
		}
		
		else if(Loc_u8_val == 4){
			UART_Vid_TX('L');
			LCD_Vid_Send_Command(LCD_CLR);
			LCD_Vid_Send_String("left");
		}
		
		else if(Loc_u8_val == 6){
			
			UART_Vid_TX('R');
			LCD_Vid_Send_Command(LCD_CLR);
			LCD_Vid_Send_String("right");
		}
		
		else if(Loc_u8_val == 8){
			UART_Vid_TX('B');
			LCD_Vid_Send_Command(LCD_CLR);
			LCD_Vid_Send_String("backward");
		}
		
		else if(Loc_u8_val == 5){
			UART_Vid_TX('S');
			LCD_Vid_Send_Command(LCD_CLR);
			LCD_Vid_Send_String("stop");
		}
    }
}

