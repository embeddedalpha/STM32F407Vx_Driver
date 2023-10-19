/*
 * USART1_Pin_Defs.h
 *
 *  Created on: Oct 18, 2023
 *      Author: kunal
 */

#ifndef USART1_PIN_DEFS_H_
#define USART1_PIN_DEFS_H_

#include "main.h"

static const struct USART1_TX_Pin
{
	uint8_t PA9;
	uint8_t PB6;
}USART1_TX_Pin = {9,6};

static const struct USART1_RX_Pin
{
	uint8_t PA10;
	uint8_t PB7;
}USART1_RX_Pin = {10,7};

static const struct USART1_CLK_Pin
{
	uint8_t PA8;
}USART1_CLK_Pin = {8};

static const struct USART1_CTS_Pin
{
	uint8_t PA11;
}USART1_CTS_Pin = {11};

static const struct USART1_RTS_Pin
{
	uint8_t PA12;
}USART1_RTS_Pin = {12};



#endif /* USART1_PIN_DEFS_H_ */
