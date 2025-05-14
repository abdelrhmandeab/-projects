/*
 * UART_Interface.c
 *
 * Created: 10/11/2023 10:03:19 PM
 *  Author: abdelrhman deab
 */ 
#include "STD_TYPE.h"
#include "MATH.h"
#include "UART_private.h"

void UART_Vid_Init(void){
	
	//send 8-bit data
	u8 Loc_u8_temp=0;
	SET_BIT(Loc_u8_temp,7);
	SET_BIT(Loc_u8_temp,2);
	SET_BIT(Loc_u8_temp,1);
	UCSRC_REG=Loc_u8_temp;
	
	//set buad rate 9600 : 16MHZ
	UBRRL_REG=103;
	
	//enable RX
	SET_BIT(UCSRB_REG,4);
	//enable TX
	SET_BIT(UCSRB_REG,3);
	
}

void UART_Vid_TX(u8 copy_u8_data){
	
	UDR_REG=copy_u8_data;
	while (GET_BIT(UCSRA_REG,5)==0);
	
}

u8 UART_u8_RX(void){	
	while (GET_BIT(UCSRA_REG,7)==0);

	return UDR_REG;
}