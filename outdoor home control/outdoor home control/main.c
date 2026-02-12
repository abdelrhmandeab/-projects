/*
 * main.c
 *
 * Created: 10/16/2023 5:14:39 PM
 *  Author: user
 */ 
#include "GIE_interface.h"
#include "DIO_interface.h"
#include "buzzer_interface.h"
#include "ULTRASONIC_interface.h"
#include "ULTRASONIC_config.h"
#include "uart_interface.h"
#include "TIMER0_interface.h"
#include "Tim1_interface.h"
#include "MATH.h"
#include "STD_TYPE.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "KEYPAD_config.h"
#include "KEYPAD_interface.h"
#include "ADC_test_config.h"
#include "ADC_test_interface.h"
#define F_CPU 16000000
#include <util/delay.h>

u8 val;
void password()
{
	KEYPAD_Vid_Init();
	u8 Loc_u8_val;
	u8 password[4], check[4];
	u8 i=0, j=0,x=0;
	BOOL test = 1;

	LCD_Vid_Send_String("Create Password:");
	LCD_Vid_GotoXY(COL1,ROW2);
	
	while(i<4){
		Loc_u8_val = KEYPAD_u8_Get_Key();
		if((Loc_u8_val >= '0') && (Loc_u8_val <= '9')){
			password[i] = Loc_u8_val;
			LCD_Vid_Send_Number(password[i]);
			_delay_ms(100);
			LCD_Vid_GotoXY(i,ROW2);
			LCD_Vid_Send_String("*");
			i++;
		}
	}
	
	_delay_ms(200);
	LCD_Vid_Send_Command(LCD_CLR);
	LCD_Vid_Send_String("Enter Password:");
	LCD_Vid_GotoXY(COL1,ROW2);
	i = 0;
	z : while (i<4){
		
		Loc_u8_val = KEYPAD_u8_Get_Key();
		if((Loc_u8_val >= '0') && (Loc_u8_val <= '9')){
			check[i] = Loc_u8_val;
			LCD_Vid_Send_Number(check[i]);
			_delay_ms(100);
			LCD_Vid_GotoXY(i,ROW2);
			LCD_Vid_Send_String("*");
			i++;
		}
	}
	while(x<3){
		_delay_ms(150);
		for(j=0 ; j<4 ; j++){
			if(check[j] != password[j]){
				test = 0;
			}
		}
		if(test == 1){
			u32 i = 0;
			DIO_Vid_Set_Pin_Dir(PORTD,PIN5,OUTPUT);	//OCRA1
			Tim1_Vid_Fast_Pwm_ICR1_Init();
			
			for (i = 0; i <= 1000;i++)
			{
				Tim1_Vid_Set_Compare_Val(i);
				_delay_ms(1);
			}
			
			LCD_Vid_Send_Command(LCD_CLR);
			LCD_Vid_Send_String("WELCOME :)");
			break;
		}
		if(test == 0){
			LCD_Vid_Send_Command(LCD_CLR);
			LCD_Vid_Send_String("Invalid Password");
			_delay_ms(150);
			LCD_Vid_Send_Command(LCD_CLR);
			LCD_Vid_Send_String("Enter Again:");
			LCD_Vid_GotoXY(COL1,ROW2);
			test = 1;
			i = 0;
			j = 0;
			x++;
			if(x==2){
				LCD_Vid_Send_Command(LCD_CLR);
				LCD_Vid_Send_String("ALERT!!!");
				break;
			}
			else
			goto z;
		}
	}
}
void calculator()
{
	KEYPAD_Vid_Init();
	u8 flag = 0, op = 0;
	u8 key, first_num = 0, second_num = 0; s32 result = 0;
	while(1)
	{

		key = KEYPAD_u8_Get_Key();
		switch(key){
			case 0xff: break;
			case 'C': LCD_Vid_Send_Command(0x01); flag=0; first_num=0; second_num=0; break;
			case '+': LCD_Vid_Send_Data(key); op=key; flag=1; break;
			case '-': LCD_Vid_Send_Data(key); op=key; flag=1; break;
			case '*': LCD_Vid_Send_Data(key); op=key; flag=1; break;
			case '/': LCD_Vid_Send_Data(key); op=key; flag=1; break;
			case '=':{
				LCD_Vid_Send_Data(key);
				switch(op){
					case '+': result = first_num + second_num; break;
					case '-': result = first_num - second_num; break;
					case '*': result = first_num * second_num; break;
					case '/': result = first_num / second_num; break;
				}
				if(op == '/' && second_num == 0){
					LCD_Vid_Send_String("Infinite!"); break;
				}
				else{
					LCD_Vid_Send_Number(result); break;
				}
			}
			default:
			LCD_Vid_Send_Data(key);
			if(flag == 0)
			first_num = first_num*10 + key - 48;
			else
			second_num = second_num*10 + key - 48;
		}

		
	}
}

void parkingSensor()
{
	GIE_Vid_Interrupt_Enable();
	ULTRASONIC_Vid_Init();
	TIMER0_Vid_Init(OV_MODE);
	buzzer_vid_init();
	LCD_Vid_Send_String("Distance = ");
	_delay_ms(10);
	
	while(1)
	{
		ULTRASONIC_Vid_Trig();
		_delay_ms(100);
		LCD_Vid_GotoXY(COL2,ROW2);
		LCD_Vid_Send_Data(' ');
		LCD_Vid_GotoXY(COL3,ROW2);
		LCD_Vid_Send_String(" cm");
		if(val != '1')
		{
			break;
		}
	}
}
void tempSensor()
{
	u16 celsius;

	ADC_Vid_Init();         
	DIO_Vid_Set_Pin_Dir(PORTA,PIN0,INPUT); /* initialize ADC*/
	
	while(1)
	{
		LCD_Vid_GotoXY(0,0);
		LCD_Vid_Send_String("TEMP = ");
		celsius = ADC_u16_Read(0);
		celsius *=0.488;
		LCD_Vid_Send_Number(celsius);/* send string data for printing */
		_delay_ms(1000);
	}
	
	
}
int main(void)
{
	/* LCD */
	DIO_Vid_Set_Port_Dir(LCD_DPORT, 0xff);
	DIO_Vid_Set_Pin_Dir(LCD_CPORT, LCD_RS_PIN ,OUTPUT);
	DIO_Vid_Set_Pin_Dir(LCD_CPORT, LCD_RW_PIN ,OUTPUT);
	DIO_Vid_Set_Pin_Dir(LCD_CPORT, LCD_EN_PIN ,OUTPUT);
	LCD_Vid_Init();
	
	UART_Vid_Init();

	LCD_Vid_Send_String("Welcome to our");
	LCD_Vid_GotoXY(0,1);
	LCD_Vid_Send_String("System :)");
	_delay_ms(1000);
	LCD_Vid_Send_Command(1);
	
    while(1)
    {
		val = UART_u8_RX();
		
		
		if (val == '1')
		{
			LCD_Vid_Send_Command(1);
			LCD_Vid_Send_String("Parking Sensor");
			_delay_ms(750);
			LCD_Vid_Send_Command(1);
			
			parkingSensor();
			
		} 
		else if(val == '2')
		{
			LCD_Vid_Send_Command(1);
			LCD_Vid_Send_String("PASSWORD");
			_delay_ms(750);
			LCD_Vid_Send_Command(1);
			
			password();
			
			
		}
		else if(val == '3')
		{
			LCD_Vid_Send_Command(1);
			LCD_Vid_Send_String("TEMPURATURE");
			_delay_ms(750);
			LCD_Vid_Send_Command(1);
			tempSensor();
			
		}
		else if(val == '4')
		{
			LCD_Vid_Send_Command(1);
			LCD_Vid_Send_String("CALCULATOR");
			_delay_ms(750);
			LCD_Vid_Send_Command(1);
			
			calculator();
		}
		else
		{
			LCD_Vid_Send_Command(1);
			LCD_Vid_Send_String("Not in System!!");
		}
		
			
    }
}

