/*
 * UART_interface.h
 *
 * Created: 10/11/2023 10:03:36 PM
 *  Author: abdelrhman deab
 */ 
#include "STD_TYPE.h"
#include "MATH.h"

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

void UART_Vid_Init(void);

void UART_Vid_TX(u8 copy_u8_data);

u8 UART_u8_RX(void);

#endif /* UART_INTERFACE_H_ */