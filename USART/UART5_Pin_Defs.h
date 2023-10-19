/*
 * UART5_Pin_Defs.h
 *
 *  Created on: Oct 18, 2023
 *      Author: kunal
 */

#ifndef UART5_PIN_DEFS_H_
#define UART5_PIN_DEFS_H_


#include "main.h"

static const struct UART5_TX_Pin
{
	uint8_t PD2;
}UART5_TX_Pin = {2};

static const struct UART5_RX_Pin
{
	uint8_t PC12;
}UART5_RX_Pin = {12};

#endif /* UART5_PIN_DEFS_H_ */
