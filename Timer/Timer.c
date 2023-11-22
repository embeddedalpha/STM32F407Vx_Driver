/*
 * Timer.c
 *
 *  Created on: Nov 20, 2023
 *      Author: kunal
 */

#include "Timer.h"

uint32_t Peripheral_Clock;



void Timer_Init(Timer_Config *config)
{
	uint32_t psc_temp;
	if((config->Port == TIM1) ||
	   (config->Port == TIM8) ||
	   (config->Port == TIM9) ||
	   (config->Port == TIM10) ||
	   (config->Port == TIM11)
	)
	{
		Peripheral_Clock = SystemCoreClock/2;
	}
	else if((config->Port == TIM2) ||
			(config->Port == TIM3) ||
			(config->Port == TIM4) ||
			(config->Port == TIM5) ||
			(config->Port == TIM6) ||
			(config->Port == TIM7) ||
			(config->Port == TIM12) ||
			(config->Port == TIM13) ||
			(config->Port == TIM14)
	)
	{
		Peripheral_Clock = SystemCoreClock;
	}

	psc_temp = Peripheral_Clock/(config->frequency * config->reload_value);
	config->Port->PSC = psc_temp;
	config->Port->ARR = config->reload_value;


	if(config->dma != Timer_DMA.Disable)
	{


	}





}
