/*
 * CAN.c
 *
 *  Created on: Oct 9, 2023
 *      Author: Kunal
 */


#include "CAN.h"

volatile uint8_t CAN_INITIALIZATION_TIMEOUT = 100;
volatile uint8_t CAN_NORMAL_TIMEOUT = 100;
volatile uint8_t CAN_SLEEP_TIMEOUT = 100;
volatile uint8_t CAN_TRANSMIT_TIMEOUT = 100;
volatile uint8_t CAN_FILTER_TIMEOUT = 100;






can_retval CAN_Clock_Activate(CAN_Config_t *config)
{
	can_retval retval = success;
	if(config->instance == CAN1)
	{
		RCC -> APB1ENR |= RCC_APB1ENR_CAN1EN;
	}
	else if(config->instance == CAN1) { RCC -> APB1ENR |= RCC_APB1ENR_CAN2EN; }
	else
	{
		retval = error_can_instance;
		return retval;
	}
	return retval;
}


can_retval CAN_Clock_Deactivate(CAN_Config_t *config)
{
	can_retval retval = success;
	if(config->instance == CAN1)      { RCC -> APB1ENR |= RCC_APB1ENR_CAN1EN; }
	else if(config->instance == CAN1) { RCC -> APB1ENR |= RCC_APB1ENR_CAN2EN; }
	else
	{
		retval = error_can_instance;
		return retval;
	}
	return retval;
}


can_retval CAN_PIN_Enable(CAN_Config_t *config)
{
	can_retval retval = success;
	if(config->instance == CAN1)
	{
		if(config->TX_Pins == CAN1_TX_Pin.PA12)
		{
			GPIO_Clock_Enable(GPIOA);
			GPIO_Pin_Init(GPIOA, 12, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.CAN_1);
		}
		else if(config->TX_Pins == CAN1_TX_Pin.PB9)
		{
			GPIO_Clock_Enable(GPIOB);
			GPIO_Pin_Init(GPIOB, 9, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.CAN_1);
		}
		else if(config->TX_Pins == CAN1_TX_Pin.PD1)
		{
			GPIO_Clock_Enable(GPIOD);
		    GPIO_Pin_Init(GPIOD, 1, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.CAN_1);
		}
/*************************************************************************************************************************************************************************************/
		if(config->RX_Pins == CAN1_RX_Pin.PA11)
		{
			GPIO_Clock_Enable(GPIOA);
		    GPIO_Pin_Init(GPIOA, 11, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.CAN_1);
		}
		else if(config->RX_Pins == CAN1_RX_Pin.PB8)
		{
			GPIO_Clock_Enable(GPIOB);
		    GPIO_Pin_Init(GPIOB, 8, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.CAN_1);
		}
		else if(config->RX_Pins == CAN1_RX_Pin.PD0)
		{
			GPIO_Clock_Enable(GPIOD);
		    GPIO_Pin_Init(GPIOD, 0, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.CAN_1);
		}
	}

/*************************************************************************************************************************************************************************************/
/*************************************************************************************************************************************************************************************/

	else if(config->instance == CAN2)
	{
		if(config->TX_Pins == CAN2_TX_Pin.PB13)
		{
			GPIO_Clock_Enable(GPIOB);
		    GPIO_Pin_Init(GPIOB, 13, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.CAN_2);
		}
		else if(config->TX_Pins == CAN2_TX_Pin.PB6)
		{
			GPIO_Clock_Enable(GPIOB);
		    GPIO_Pin_Init(GPIOB, 6, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.CAN_2);
		}

		if(config->RX_Pins == CAN2_RX_Pin.PB12)
		{
			GPIO_Clock_Enable(GPIOB);
		    GPIO_Pin_Init(GPIOB, 12, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.CAN_2);
		}
		else if(config->RX_Pins == CAN2_RX_Pin.PB5)
		{
			GPIO_Clock_Enable(GPIOB);
		    GPIO_Pin_Init(GPIOB, 5, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.CAN_2);
		}
	}
	else
	{
		retval = error_can_instance;
		return retval;
	}
	return retval;

}


can_retval CAN_PIN_Disable(CAN_Config_t *config)
{
	can_retval retval = success;
	if(config->instance == CAN1)
	{
		if(config->TX_Pins == CAN1_TX_Pin.PA12)
			GPIO_Clock_Disable(GPIOA);
		else if(config->TX_Pins == CAN1_TX_Pin.PB9)
			GPIO_Clock_Disable(GPIOB);
		else if(config->TX_Pins == CAN1_TX_Pin.PD1)
			GPIO_Clock_Disable(GPIOA);

		if(config->RX_Pins == CAN1_RX_Pin.PA11)
			GPIO_Clock_Disable(GPIOA);
		else if(config->RX_Pins == CAN1_RX_Pin.PB8)
			GPIO_Clock_Disable(GPIOB);
		else if(config->RX_Pins == CAN1_RX_Pin.PD0)
			GPIO_Clock_Disable(GPIOD);
	}
	else if(config->instance == CAN2)
	{
		if(config->TX_Pins == CAN2_TX_Pin.PB13)
			GPIO_Pin_Init(GPIOB, 13, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.CAN_2);
		else if(config->TX_Pins == CAN2_TX_Pin.PB6)
			GPIO_Pin_Init(GPIOB, 6, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.CAN_2);

		if(config->RX_Pins == CAN2_RX_Pin.PB12)
			GPIO_Pin_Init(GPIOB, 12, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.CAN_2);
		else if(config->RX_Pins == CAN2_RX_Pin.PB5)
			GPIO_Pin_Init(GPIOB, 5, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.CAN_2);
	}
	else
	{
		retval = error_can_instance;
		return retval;
	}
	return retval;
}




can_retval CAN_Initialization_Mode(CAN_Config_t *config)
{
	can_retval retval = success;
	//start CAN initialization
	config->instance->MCR |= CAN_MCR_INRQ;
	config->instance->MCR &= ~CAN_MCR_SLEEP;
	while((!(config->instance->MSR & CAN_MSR_INAK)) && (config->instance->MSR & CAN_MSR_SLAK))
	{
		if(CAN_INITIALIZATION_TIMEOUT == 0)
		{
			retval = error_can_initialization;
			return retval;
		}
		CAN_INITIALIZATION_TIMEOUT--;

	}
	//CAN controller is in initialization mode
	config->instance->BTR = config->baudrate;


	return retval;
}

can_retval CAN_Normal_Mode(CAN_Config_t *config)
{
	can_retval retval = success;
	config->instance->MCR &= ~CAN_MCR_INRQ;
	config->instance->MCR &= ~CAN_MCR_SLEEP;
	while(((config->instance->MSR & CAN_MSR_INAK)) && (config->instance->MSR & CAN_MSR_SLAK))
	{
		if(CAN_INITIALIZATION_TIMEOUT == 0)
		{
			retval = error_can_normal;
			return retval;
		}
		CAN_NORMAL_TIMEOUT--;
	}
	return retval;
}

can_retval CAN_Sleep_Mode(CAN_Config_t *config)
{
	can_retval retval = success;
	config->instance->MCR |= CAN_MCR_SLEEP;
	while((config->instance->MSR & CAN_MSR_SLAK))
	{
		if(CAN_SLEEP_TIMEOUT == 0)
		{
			retval = error_can_sleep;
			return retval;
		}
		CAN_SLEEP_TIMEOUT--;
	}
	return retval;
}


can_retval CAN_Setup(CAN_Config_t *config)
{
	can_retval retval = success;

	if(CAN_PIN_Enable(config))
	{
		if(CAN_Clock_Activate(config))
		{
			if(CAN_Initialization_Mode(config) != success)
			{
				retval = error_setup;
				return  retval;
			}
		}
		else
		{
			retval = error_setup;
			return  retval;
		}
	}
	else
	{
		retval = error_setup;
		return  retval;
	}

	return retval;
}


can_retval CAN_Filter_Setup(CAN_Config_t *config, CAN_Filter_TypeDef *filter)
{
	can_retval retval = no_filter_selected;
	if(filter->active)
	{
		config->instance-> FMR |= CAN_FMR_FINIT;
		config->instance->FA1R |= 1 << filter->number;
		config->instance->FFA1R |= filter->FIFO_number << filter->number;

		if(config->ID_Type) config->instance->FS1R |= (1 << filter->number);
		else config->instance->FS1R &= ~(1 << filter->number);

		if(filter->Filter_mode)
		{
			config->instance->FM1R |= (1 << filter->number);
		}
		else config->instance->FM1R &= ~(1 << filter->number);

		config->instance->sFilterRegister[filter->FIFO_number].FR1 = filter->Bank1;
		config->instance->sFilterRegister[filter->FIFO_number].FR2 = filter->Bank2;
		config->instance-> FMR &= ~CAN_FMR_FINIT;
		while((config->instance-> FMR & CAN_FMR_FINIT))
		{
			if(CAN_FILTER_TIMEOUT == 0)
			{
				retval = error_filter;
			}
			CAN_FILTER_TIMEOUT--;
		}
	}
	return retval;
}


can_retval CAN_Send_Packet(CAN_Config_t *config, CAN_Packet *frame)
{
	can_retval retval = success;

	config->instance->sTxMailBox[frame->mailbox_number].TIR = (CAN_TI0R_EXID_Msk & frame->ID) |(config ->ID_Type << 2) | (frame->frame_type << 1);
	config->instance->sTxMailBox[frame->mailbox_number].TDTR = CAN_TDT0R_DLC_Msk & frame->data_length;
	config->instance->sTxMailBox[frame->mailbox_number].TDLR = (frame->data[0] << 0) | (frame->data[1] << 8) |
			                                                   (frame->data[2] << 16) | (frame->data[3] << 24);
	config->instance->sTxMailBox[frame->mailbox_number].TDHR = (frame->data[4] << 0) | (frame->data[5] << 8) |
			                                                   (frame->data[6] << 16) | (frame->data[7] << 24);
	config->instance->sTxMailBox[frame->mailbox_number].TIR |= CAN_TI0R_TXRQ;
	while(!(config->instance->sTxMailBox[frame->mailbox_number].TIR & CAN_TI0R_TXRQ))
	{
		if(CAN_TRANSMIT_TIMEOUT == 0)
		{
			retval = error_transmit;
			return retval;
		}
		CAN_TRANSMIT_TIMEOUT--;
	}

	return retval;
}


/************************************************************************************************/

__WEAK void CAN1_TX_IRQHandler(void)
{


}

__WEAK void CAN1_RX0_IRQHandler(void)
{

}

__WEAK void CAN1_RX1_IRQHandler(void)
{

}

__WEAK void CAN1_SCE_IRQHandler(void)
{

}

__WEAK void CAN2_TX_IRQHandler(void)
{


}

__WEAK void CAN2_RX0_IRQHandler(void)
{

}

__WEAK void CAN2_RX1_IRQHandler(void)
{

}

__WEAK void CAN2_SCE_IRQHandler(void)
{

}
