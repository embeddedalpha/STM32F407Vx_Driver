/*
 * Timer.h
 *
 *  Created on: Nov 20, 2023
 *      Author: kunal
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "main.h"
#include "GPIO.h"
#include "DMA.h"
#include "Timer_Defs.h"


typedef struct Timer_Config
{
	TIM_TypeDef *Port;
	uint8_t channel;
	uint32_t frequency;
	uint16_t reload_value;
	uint8_t counter_direction;
	uint8_t channel_1_feature;
	uint8_t channel_2_feature;
	uint8_t channel_3_feature;
	uint8_t channel_4_feature;
	uint8_t dma;
}Timer_Config;


void Timer_Init(Timer_Config *config);





#endif /* TIMER_H_ */
