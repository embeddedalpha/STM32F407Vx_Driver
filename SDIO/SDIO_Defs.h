/*
 * SDIO_Defs.h
 *
 *  Created on: Nov 22, 2023
 *      Author: kunal
 */

#ifndef SDIO_DEFS_H_
#define SDIO_DEFS_H_

#include "main.h"



static const struct SDIO_Mode
{
	uint8_t Disable;
	uint8_t SD_1_Bit;
	uint8_t SD_4_Bit;
	uint8_t MMC_1_Bit;
	uint8_t MMC_4_Bit;
	uint8_t MMC_8_Bit;

}SDIO_Mode = {0,1,2,3,4,5};


static const struct SDIO_Power_Phase
{
	uint8_t Off;
	uint8_t Up;
	uint8_t ON;

}SDIO_Power_Phase = {1,2,3};


static const struct SD_Commands
{
	uint8_t CMD0;
	uint8_t CMD0_Response;
	uint8_t CMD17;
	uint8_t CMD18;
	uint8_t CMD24;
	uint8_t CMD25;
	uint8_t CMD38;
	uint8_t CMD52;
	uint8_t CMD53;
	uint8_t CMD55;
	uint8_t CMD6;
	uint8_t CMD12;
	uint8_t CMD23;
	uint8_t CMD41;
	uint8_t CMD42;
	uint8_t CMD51;

}SD_Commands={};


#endif /* SDIO_DEFS_H_ */
