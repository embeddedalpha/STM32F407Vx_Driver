/*
 * SDIO.c
 *
 *  Created on: Nov 22, 2023
 *      Author: kunal
 */


#include "SDIO.h"



void SDIO_Init(SDIO_Config *config)
{
	RCC -> APB2ENR |= RCC_APB2ENR_SDIOEN;

	if(config->mode == SDIO_Mode.MMC_1_Bit)
	{
		GPIO_Pin_Init(GPIOC, 12, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
		GPIO_Pin_Init(GPIOC, 8, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
		GPIO_Pin_Init(GPIOD, 2, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
	}else if(config->mode == SDIO_Mode.SD_4_Bit)
	{
		GPIO_Pin_Init(GPIOC, 12, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
		GPIO_Pin_Init(GPIOD, 2, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
		GPIO_Pin_Init(GPIOC, 8, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
		GPIO_Pin_Init(GPIOC, 9, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
		GPIO_Pin_Init(GPIOC, 10, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
		GPIO_Pin_Init(GPIOC, 11, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
	}else if(config->mode == SDIO_Mode.MMC_4_Bit)
	{
		GPIO_Pin_Init(GPIOC, 12, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
		GPIO_Pin_Init(GPIOD, 2, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
		GPIO_Pin_Init(GPIOC, 8, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
		GPIO_Pin_Init(GPIOC, 9, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
		GPIO_Pin_Init(GPIOC, 10, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
		GPIO_Pin_Init(GPIOC, 11, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.SDIO_1);
	}
}


