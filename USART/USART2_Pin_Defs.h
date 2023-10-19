/*
 * USART2_Pin_Defs.h
 *
 *  Created on: Oct 18, 2023
 *      Author: kunal
 */

#ifndef USART2_PIN_DEFS_H_
#define USART2_PIN_DEFS_H_

#include "main.h"

static const struct USART2_TX_Pin
{
	uint8_t PA2;
	uint8_t PD5;
}USART2_TX_Pin = {2,5};

static const struct USART2_RX_Pin
{
	uint8_t PA3;
	uint8_t PD6;
}USART2_RX_Pin = {3,6};

static const struct USART2_CLK_Pin
{
	uint8_t PA4;
	uint8_t PD7;
}USART2_CLK_Pin = {4,7};

static const struct USART2_CTS_Pin
{
	uint8_t PA0;
	uint8_t PD3;
}USART2_CTS_Pin = {0,3};

static const struct USART2_RTS_Pin
{
	uint8_t PA1;
	uint8_t PD4;
}USART2_RTS_Pin = {1,4};


#endif /* USART2_PIN_DEFS_H_ */
