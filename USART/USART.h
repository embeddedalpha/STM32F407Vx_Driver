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
	uint32_t baudrate;
	uint8_t mode;
	uint8_t TX_Pin;
	uint8_t RX_Pin;
	uint8_t interrupt;
	uint8_t hardware_flow;
	uint8_t stop_bits;
	uint8_t dma_enable;

}USART_Config;

void USART_Init(USART_Config *config);
void USART_TX_Byte(USART_Config *config, uint16_t data);
uint16_t USART_RX_Byte(USART_Config *config);
void USART_TX_Buffer(USART_Config *config, uint8_t tx_buffer, uint16_t length);
void USART_RX_Buffer(USART_Config *config, uint8_t *rx_buffer, uint16_t length);



#endif /* USART_H_ */
