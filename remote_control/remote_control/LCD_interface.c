/*
 * LCD_interface.c
 *
 * Created: 29/08/2023 16:39:29
 *  Author: AMIT
 */ 
#include "STD_TYPE.h" 
#include "MATH.h" 
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h" 
#define  F_CPU 16000000  
#include <util/delay.h> 
    
void LCD_Vid_Send_Number(u32 copy_u32_num){
	u8 arr[10];
	u8 Loc_u8_in1=0,Loc_u8_in2=0;
	do{
		arr[Loc_u8_in1]= copy_u32_num%10;
		copy_u32_num/=10;
		Loc_u8_in1++;
	}while(copy_u32_num>0);
	Loc_u8_in1--;
	for(Loc_u8_in2=0;Loc_u8_in2<=Loc_u8_in1;Loc_u8_in2++){
		LCD_Vid_Send_Data((arr[Loc_u8_in1-Loc_u8_in2]+48));
	}
}
                  
static void  SHData(u8 copy_u8_data){
	u8 Loc_u8_in=0 ; 
	u8 Loc_u8_pin[4]={LCD_D4_PIN,LCD_D5_PIN,LCD_D6_PIN,LCD_D7_PIN} ; 
	for(Loc_u8_in=0;Loc_u8_in<4;Loc_u8_in++){
		
		DIO_Vid_Set_Pin_Val(LCD_DPORT,Loc_u8_pin[Loc_u8_in],GET_BIT(copy_u8_data,Loc_u8_in)) ;
		
	}
	
	
}					  

static void  Send_Enable(void){
	
		DIO_Vid_Set_Pin_Val(LCD_CPORT,LCD_EN_PIN,HIGH) ;
		_delay_ms(2) ;
		DIO_Vid_Set_Pin_Val(LCD_CPORT,LCD_EN_PIN,LOW) ;
		
}

					  
void LCD_Vid_Send_Command(u8 copy_u8_command){
	
	/* SET RS PIN IN LCD  TO SEND COMMAND */
	DIO_Vid_Set_Pin_Val(LCD_CPORT,LCD_RS_PIN,LOW) ; 
	/* SET RW PIN IN LCD  TO Write COMMAND */
	DIO_Vid_Set_Pin_Val(LCD_CPORT,LCD_RW_PIN,LOW) ;
 
    #if  LCD_MODE == FOUR_BIT_MODE 
	   /* SEND HSB Command  */ 
	   SHData(copy_u8_command>>4) ; 
	     Send_Enable() ; 
		 /*LSB */
		 SHData(copy_u8_command) ;
		 Send_Enable() ;
      #elif LCD_MODE == EIGHT_BIT_MODE 
	/* send command  */
	DIO_Vid_Set_Port_Val(LCD_DPORT,copy_u8_command) ; 
	/* SEND EN Pulse*/  
	Send_Enable() ;
	#endif
	

	
	
	
	
}

void LCD_Vid_Send_Data(u8 copy_u8_data){
	
	/* SET RS PIN IN LCD  TO SEND COMMAND */
	DIO_Vid_Set_Pin_Val(LCD_CPORT,LCD_RS_PIN,HIGH) ;
	/* SET RW PIN IN LCD  TO Write COMMAND */
	DIO_Vid_Set_Pin_Val(LCD_CPORT,LCD_RW_PIN,LOW) ;
	#if  LCD_MODE == FOUR_BIT_MODE
	/* SEND HSB Command  */
	SHData(copy_u8_data>>4) ;
	Send_Enable() ;
	/*LSB */
	SHData(copy_u8_data) ;
	Send_Enable() ;
	#elif LCD_MODE == EIGHT_BIT_MODE
	/* send data  */
	DIO_Vid_Set_Port_Val(LCD_DPORT,copy_u8_data) ;
	/* SEND EN Pulse*/
	Send_Enable() ;
	#endif
	
	
}

void LCD_Vid_Init(void){
	_delay_ms(40) ;
	
	#if LCD_MODE ==  FOUR_BIT_MODE 
	      /* SEND  function set  */
		  SHData(0b0010) ; 
		  Send_Enable() ; 
		  SHData(0b0010) ; 
		  Send_Enable() ; 
		  SHData(0b1000) ;
		  Send_Enable() ; 
    #elif LCD_MODE == EIGHT_BIT_MODE 	
	/* SEND  function set  */
	LCD_Vid_Send_Command(0x3C) ; 
	#endif 
	/* send ON/OFF Command  */ 
	LCD_Vid_Send_Command(0x0C) ; 
	/* send  CLR command  */
	LCD_Vid_Send_Command(1) ; 

}

void LCD_Vid_Send_String(ch8 * add_u8_str){
	
	u8 Loc_u8_in=0 ;
	while(add_u8_str[Loc_u8_in] != '\0'){
		
		LCD_Vid_Send_Data(add_u8_str[Loc_u8_in]) ;
		Loc_u8_in++ ; 
	}
	
	
}

void LCD_Vid_GOTOXY(u8 copy_u8_x , u8 copy_u8_y){
	
	u8 Loc_u8_DDRAMaddress=0 ; 
	if(copy_u8_y==0){
	
		 Loc_u8_DDRAMaddress=copy_u8_x ; 
	}
	else if (copy_u8_y==1){
		Loc_u8_DDRAMaddress=copy_u8_x+0x40 ; 
		
	}
	
	/* set DDRAM  */
	SET_BIT(Loc_u8_DDRAMaddress,7) ; 
	LCD_Vid_Send_Command(Loc_u8_DDRAMaddress) ; 
}
void LCD_Vid_Send_Special_Char(u8 copy_u8_x  ,u8 copy_u8_y , u8 copy_u8_pattern , u8 copy_u8_data[8])
{
	u8 Loc_u8_in;
	u8 Loc_u8_CGRAMadd=copy_u8_pattern*8 ; 
	
	/*  set CGRAM  */
	   SET_BIT(Loc_u8_CGRAMadd,6) ;
	   CLR_BIT(Loc_u8_CGRAMadd,7) ; 
	   
	LCD_Vid_Send_Command(Loc_u8_CGRAMadd);
	 /* Write data in CGRAM  */
	for(Loc_u8_in = 0 ; Loc_u8_in<8 ; Loc_u8_in++){
		
		LCD_Vid_Send_Data(copy_u8_data[Loc_u8_in]);
	}
	
	/* back to ddram to dispaly data*/ 
	LCD_Vid_GOTOXY(copy_u8_x,copy_u8_y) ;
	
	LCD_Vid_Send_Data(copy_u8_pattern)  ;
	
}