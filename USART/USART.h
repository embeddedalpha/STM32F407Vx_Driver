/*
 * USART.h
 *
 *  Created on: Oct 18, 2023
 *      Author: kunal
 */

#ifndef USART_H_
#define USART_H_


#include "main.h"
#include "GPIO.h"
#include "USART_Defs.h"






typedef struct USART_Config
{
	USART_TypeDef *Port;
	bool clock;
	uint8_t communication_mode;
	uint8_t mode;
	uint32_t baudrate;
	uint8_t TX_Pin;
	uint8_t RX_Pin;



}USART_Config;


#endif /* USART_H_ */
