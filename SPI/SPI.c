/*
 * SPI.c
 *
 *  Created on: Nov 12, 2023
 *      Author: kunal
 */

#include "SPI.h"

int8_t SPI_Clock_Enable(SPI_Config *config)
{
	int8_t retval = 0;
	if(config ->Port == SPI1)RCC -> APB2ENR |= RCC_APB2ENR_SPI1EN;
	if(config ->Port == SPI2)RCC -> APB1ENR |= RCC_APB1ENR_SPI2EN;
	if(config ->Port == SPI3)RCC -> APB1ENR |= RCC_APB1ENR_SPI3EN;
	else
		retval = -1;
	return retval;
}

int8_t SPI_Clock_Disable(SPI_Config *config)
{
	int8_t retval = 0;
	if(config ->Port == SPI1)RCC -> APB2ENR &= ~RCC_APB2ENR_SPI1EN;
	if(config ->Port == SPI2)RCC -> APB1ENR &= ~RCC_APB1ENR_SPI2EN;
	if(config ->Port == SPI3)RCC -> APB1ENR &= ~RCC_APB1ENR_SPI3EN;
	else
		retval = -1;
	return retval;
}


int8_t SPI_Config_Reset(SPI_Config *config)
{
	int8_t retval = 0;
	if(config ->Port == SPI1)RCC -> APB2RSTR |= RCC_APB2ENR_SPI1EN;
	if(config ->Port == SPI2)RCC -> APB1RSTR |= RCC_APB1ENR_SPI2EN;
	if(config ->Port == SPI3)RCC -> APB1RSTR |= RCC_APB1ENR_SPI3EN;
	else
		retval = -1;
	return retval;
}


static void SPI_Pin(SPI_Config *config)
{
	if(config -> Port == SPI1)
	{
		if(config->clock_pin == SPI1_CLK.PA5) GPIO_Pin_Init(GPIOA, 5, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SPI_1);
		if(config->clock_pin == SPI1_CLK.PB3) GPIO_Pin_Init(GPIOB, 3, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SPI_1);

		if(config->miso_pin == SPI1_MISO.PA6) GPIO_Pin_Init(GPIOA, 6, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SPI_1);
		if(config->miso_pin == SPI1_MISO.PB4) GPIO_Pin_Init(GPIOB, 4, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SPI_1);

		if(config->mosi_pin == SPI1_MOSI.PA7) GPIO_Pin_Init(GPIOA, 7, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SPI_1);
		if(config->mosi_pin == SPI1_MOSI.PB5) GPIO_Pin_Init(GPIOB, 5, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SPI_1);
	}


}

void SPI_Init(SPI_Config *config)
{
	SPI_Pin(config);
}


void SPI_DeInit(SPI_Config *config);
void SPI_TX_Byte(SPI_Config *config, uint16_t data);
uint16_t SPI_RX_Byte(SPI_Config *config);
void SPI_TX_Buffer(SPI_Config *config, uint8_t *tx_buffer, uint16_t length);
void SPI_RX_Buffer(SPI_Config *config, uint8_t *rx_buffer, uint16_t length);
