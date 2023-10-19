/*
 * USART6_Pin_Defs.h
 *
 *  Created on: Oct 18, 2023
 *      Author: kunal
 */

#ifndef USART6_PIN_DEFS_H_
#define USART6_PIN_DEFS_H_

#include "main.h"

static const struct USART6_TX_Pin
{
	uint8_t PC6;
}USART6_TX_Pin = {6};

static const struct USART6_RX_Pin
{
	uint8_t PC7;
}USART6_RX_Pin = {7};

static const struct USART6_CLK_Pin
{
	uint8_t PC8;
}USART6_CLK_Pin = {8};



#endif /* USART6_PIN_DEFS_H_ */
