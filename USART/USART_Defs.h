/*
 * USART_Defs.h
 *
 *  Created on: Oct 18, 2023
 *      Author: kunal
 */

#ifndef USART_DEFS_H_
#define USART_DEFS_H_


#include "main.h"
#include "USART1_Pin_Defs.h"
#include "USART2_Pin_Defs.h"

static const struct USART_Clock
{
	bool Clock_Enable;
	bool Clock_Disable;

}USART_Clock = {1,0};

static const struct Communication_Mode
{
	uint8_t Single_Wire_Half_Duplex;
	uint8_t Full_Duplex;

}Communication_Mode = {0,1};








#endif /* USART_DEFS_H_ */
