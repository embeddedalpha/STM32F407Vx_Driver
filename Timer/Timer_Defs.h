/*
 * Timer_Defs.h
 *
 *  Created on: Nov 20, 2023
 *      Author: kunal
 */

#ifndef TIMER_DEFS_H_
#define TIMER_DEFS_H_

#include "main.h"

static const struct Timer_Channel
{
	uint8_t Channel_1;
	uint8_t Channel_2;
	uint8_t Channel_3;
	uint8_t Channel_4;

}Timer_Channel={1,2,3,4};

static const struct Timer_Counter_Direction
{
	uint8_t Down;
	uint8_t Up;
	uint8_t Center_Aligned;

}Timer_Counter_Direction={1,2,3};

static const struct Timer_Channel_n_Feature
{
	uint8_t Disable;
	uint8_t Input_Capture_Direct_Mode;
	uint8_t Output_Capture_No_Input;
	uint8_t Output_Capture_P;
	uint8_t Output_Capture_N;
	uint8_t Output_Capture_P_N;
	uint8_t PWM_Generation_P;
	uint8_t PWM_Generation_N;
	uint8_t PWM_Generation_P_N;
	uint8_t Forced_Output_P;
	uint8_t Forced_Output_N;
	uint8_t Forced_Output_P_N;

}Timer_Channel_1_Feature={0,1,2,3,4,5,6,7,8,9,10,11};


static const struct Timer_DMA
{
	uint8_t Disable;
	uint8_t Enable;

}Timer_DMA = {0,1};



#endif /* TIMER_DEFS_H_ */
