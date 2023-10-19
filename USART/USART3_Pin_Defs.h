/*
 * USART3_Pin_Defs.h
 *
 *  Created on: Oct 18, 2023
 *      Author: kunal
 */

#ifndef USART3_PIN_DEFS_H_
#define USART3_PIN_DEFS_H_

#include "main.h"

static const struct USART3_TX_Pin
{
	uint8_t PB11;
	uint8_t PD8;
	uint8_t PC10;
}USART3_TX_Pin = {11,8,10};

static const struct USART3_RX_Pin
{
	uint8_t PB10;
	uint8_t PD0;
	uint8_t PC11;
}USART3_RX_Pin = {10,0,11};

static const struct USART3_CLK_Pin
{
	uint8_t PB12;
	uint8_t PD10;
}USART3_CLK_Pin = {12,10};

static const struct USART3_CTS_Pin
{
	uint8_t PB13;
	uint8_t PD11;
}USART3_CTS_Pin = {0,3};

static const struct USART3_RTS_Pin
{
	uint8_t PB14;
	uint8_t PD12;
}USART3_RTS_Pin = {1,4};

#endif /* USART3_PIN_DEFS_H_ */
