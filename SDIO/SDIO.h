/*
 * SDIO.h
 *
 *  Created on: Nov 22, 2023
 *      Author: kunal
 */

#ifndef SDIO_H_
#define SDIO_H_

#include "main.h"
#include "DMA.h"
#include "GPIO.h"
#include "SDIO.h"
#include "SDIO_Defs.h"


typedef struct SDIO_Config
{
	SDIO_TypeDef *Port;
	uint32_t speed;
	uint8_t mode;


}SDIO_Config;





#endif /* SDIO_H_ */
