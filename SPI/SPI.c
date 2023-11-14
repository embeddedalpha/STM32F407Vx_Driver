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
	else if(config -> Port == SPI2)
	{
		if(config->clock_pin == SPI2_CLK.PB10) GPIO_Pin_Init(GPIOB, 10, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SPI_1);
		if(config->clock_pin == SPI2_CLK.PB13) GPIO_Pin_Init(GPIOB, 13, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SPI_1);

		if(config->miso_pin == SPI2_MISO.PB14) GPIO_Pin_Init(GPIOB, 14, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SPI_1);
		if(config->miso_pin == SPI2_MISO.PC2) GPIO_Pin_Init(GPIOC, 2, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SPI_1);

		if(config->mosi_pin == SPI2_MOSI.PB15) GPIO_Pin_Init(GPIOB, 15, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SPI_1);
		if(config->mosi_pin == SPI2_MOSI.PC3) GPIO_Pin_Init(GPIOC, 3, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SPI_1);
	}
	else if(config -> Port == SPI3)
		{
		if(config->clock_pin == SPI3_CLK.PB3) GPIO_Pin_Init(GPIOB, 3, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SPI_1);
		if(config->clock_pin == SPI3_CLK.PC10) GPIO_Pin_Init(GPIOC, 10, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SPI_1);

		if(config->miso_pin == SPI3_MISO.PB4) GPIO_Pin_Init(GPIOB, 4, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SPI_1);
		if(config->miso_pin == SPI3_MISO.PC11) GPIO_Pin_Init(GPIOC,11, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SPI_1);

		if(config->mosi_pin == SPI3_MOSI.PB5) GPIO_Pin_Init(GPIOB, 5, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SPI_1);
		if(config->mosi_pin == SPI3_MOSI.PC12) GPIO_Pin_Init(GPIOC, 12, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SPI_1);
	}
}


void SPI_Init(SPI_Config *config)
{
	if(config->type == SPI_Type.Master)GPIO_Pin_Init(config->NSS_Port, config->NSS_Pin, MODE.General_Purpose_Output, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.Pull_Up, Alternate_Functions.None);
	if(config->type == SPI_Type.Slave)GPIO_Pin_Init(config->NSS_Port, config->NSS_Pin, MODE.Input, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.Pull_Up, Alternate_Functions.None);

	SPI_Pin(config);

	config->Port->CR1 |= config->clock_phase | config->clock_polarity |
					config->type | config->mode | config->frame_format |
					config->data_format | config->crc | (config->prescaler<<3);
	config->Port->CR2 |= config->dma | config->interrupt;

	if(config->Port == SPI1)
	{
		config->speed = (SystemCoreClock/2)/(2*2^(config->prescaler));
	}
	else
	{
		config->speed = (SystemCoreClock/4)/(2*2^(config->prescaler));
	}


	config->Port -> CR1 |= SPI_CR1_SPE;

}


void SPI_DeInit(SPI_Config *config);
void SPI_TX_Byte(SPI_Config *config, uint16_t data);
uint16_t SPI_RX_Byte(SPI_Config *config);
void SPI_TX_Buffer(SPI_Config *config, uint8_t *tx_buffer, uint16_t length);

void SPI_RX_Buffer(SPI_Config *config, uint8_t *rx_buffer, uint16_t length);
