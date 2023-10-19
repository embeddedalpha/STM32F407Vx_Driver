/*
 * UART4_Pin_Defs.h
 *
 *  Created on: Oct 18, 2023
 *      Author: kunal
 */

#ifndef UART4_PIN_DEFS_H_
#define UART4_PIN_DEFS_H_

#include "main.h"

static const struct UART4_TX_Pin
{
	uint8_t PA0;
	uint8_t PC10;
}UART4_TX_Pin = {0,10};

static const struct UART4_RX_Pin
{
	uint8_t PA1;
	uint8_t PC11;
}UART4_RX_Pin = {1,11};



#endif /* UART4_PIN_DEFS_H_ */
