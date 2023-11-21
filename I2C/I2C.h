/*
 * I2C.h
 *
 *  Created on: Nov 20, 2023
 *      Author: kunal
 */

#ifndef I2C_H_
#define I2C_H_

#include "main.h"
#include "GPIO.h"
#include "DMA.h"
#include "I2C_Defs.h"


typedef struct I2C_Config
{
	I2C_TypeDef *Port;
	int32_t speed;
	uint8_t SCL_Pin;
	uint8_t SDA_Pin;
	uint8_t mode;
	uint16_t interrupts;
	uint16_t dma;
}I2C_Config;

void I2C_Init(I2C_Config *config);
void I2C_Clock_Enable(I2C_Config *config);
void I2C_Clock_Disable(I2C_Config *config);
void I2C_Reset(I2C_Config *config);

void I2C_Master_Start(I2C_Config *config);

void I2C_Master_Address(I2C_Config *config, uint8_t address, uint8_t read_write);

void I2C_Master_Send_Byte(I2C_Config *config, uint8_t data);

void I2C_Master_Send_Buffer(I2C_Config *config, uint8_t *data, int length);

void I2C_Master_Write_Register(I2C_Config *config, uint8_t device_address, uint8_t reg_address, uint8_t data);

int I2C_Master_Read_Register(I2C_Config *config, uint8_t device_address, uint8_t reg_address);

int I2C_Master_Receive_Byte(I2C_Config *config);

void I2C_Master_NACK(I2C_Config *config);

void I2C_Master_ACK(I2C_Config *config);

void I2C_Master_Stop(I2C_Config *config);

void I2C_Master_Write_Register_Block(I2C_Config *config, uint8_t device_address, uint8_t reg_address, uint8_t *data, int length);

#endif /* I2C_H_ */
