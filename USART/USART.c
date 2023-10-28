/*
 * USART.c
 *
 *  Created on: Oct 18, 2023
 *      Author: kunal
 */


#include "main.h"
#include "USART.h"

void USART_Config_Reset(USART_Config *config)
{
	config->mode = Mode.Disable;
	config->hardware_flow = Hardware_Flow.Disable;
	config->low_power_uart = Low_Power_USART.Disable;
	config->baudrate = 9600;
	config->dma_enable = DMA_Enable.RX_Disable | DMA_Enable.TX_Disable;
	config->interrupt = Interrupt_Type.Disable;
}


int8_t USART_Clock_Enable(USART_Config *config)
{
	if(config->Port == USART1)
	{
		if(config->low_power_uart == Low_Power_USART.Enable) RCC -> APB2LPENR |= RCC_APB2LPENR_USART1LPEN;
		else RCC -> APB2ENR |= RCC_APB2ENR_USART1EN;
	}
	else if(config->Port == USART2)
	{
		if(config->low_power_uart == Low_Power_USART.Enable) RCC -> APB1LPENR |= RCC_APB1LPENR_USART2LPEN;
		else RCC -> APB1ENR |= RCC_APB1ENR_USART2EN;
	}
	else if(config->Port == USART3)
	{
		if(config->low_power_uart == Low_Power_USART.Enable) RCC -> APB1LPENR |= RCC_APB1LPENR_USART3LPEN;
		else RCC -> APB1ENR |= RCC_APB1ENR_USART3EN;
	}
	else if(config->Port == UART4)
	{
		if(config->low_power_uart == Low_Power_USART.Enable) return -1;
		else RCC -> APB1ENR |= RCC_APB1ENR_UART4EN;
	}
	else if(config->Port == UART5)
	{
		if(config->low_power_uart == Low_Power_USART.Enable) return -1;
		else RCC -> APB1ENR |= RCC_APB1ENR_UART5EN;
	}
	else if(config->Port == USART6)
	{
		if(config->low_power_uart == Low_Power_USART.Enable) RCC -> APB2LPENR |= RCC_APB2LPENR_USART6LPEN;
		else RCC -> APB2ENR |= RCC_APB2ENR_USART6EN;
	}
	else
	{
		return -1;
	}
	return 1;
}


int8_t USART_Clock_Disable(USART_Config *config)
{
	if(config->Port == USART1)
	{
		if(config->low_power_uart == Low_Power_USART.Disable) RCC -> APB2LPENR &= ~RCC_APB2LPENR_USART1LPEN;
		else RCC -> APB2ENR &= ~RCC_APB2ENR_USART1EN;
	}
	else if(config->Port == USART2)
	{
		if(config->low_power_uart == Low_Power_USART.Disable) RCC -> APB1LPENR &= ~RCC_APB1LPENR_USART2LPEN;
		else RCC -> APB1ENR &= ~RCC_APB1ENR_USART2EN;
	}
	else if(config->Port == USART3)
	{
		if(config->low_power_uart == Low_Power_USART.Disable) RCC -> APB1LPENR &= ~RCC_APB1LPENR_USART3LPEN;
		else RCC -> APB1ENR &= ~RCC_APB1ENR_USART3EN;
	}
	else if(config->Port == UART4)
	{
		if(config->low_power_uart == Low_Power_USART.Disable) return -1;
		else RCC -> APB1ENR &= ~RCC_APB1ENR_UART4EN;
	}
	else if(config->Port == UART5)
	{
		if(config->low_power_uart == Low_Power_USART.Disable) return -1;
		else RCC -> APB1ENR &= ~RCC_APB1ENR_UART5EN;
	}
	else if(config->Port == USART6)
	{
		if(config->low_power_uart == Low_Power_USART.Disable) RCC -> APB2LPENR &= ~RCC_APB2LPENR_USART6LPEN;
		else RCC -> APB2ENR &= ~RCC_APB2ENR_USART6EN;
	}
	else
	{
		return -1;
	}
	return 1;
}

static void PIN_Setup(USART_Config *config)
{
	if(config->Port == USART1)
	{
		if((config->mode == Mode.Asynchronous) ||
		   (config->mode == Mode.Synchronous) ||
		   (config->mode == Mode.IrDA) ||
		   (config->mode == Mode.LIN) )
		{
			if(config->TX_Pin == USART1_TX_Pin.PA9)GPIO_Pin_Init(GPIOA, USART1_TX_Pin.PA9, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_1);
			else if(config->TX_Pin == USART1_TX_Pin.PB6)GPIO_Pin_Init(GPIOB, USART1_TX_Pin.PB6, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_1);

			if(config->RX_Pin == USART1_RX_Pin.PA10)GPIO_Pin_Init(GPIOA, USART1_RX_Pin.PA10, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_1);
			else if(config->RX_Pin == USART1_RX_Pin.PB7)GPIO_Pin_Init(GPIOB, USART1_RX_Pin.PB7, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_1);

			if((config->mode == Mode.Synchronous))if(config->CLK_Pin == USART1_CLK_Pin.PA8)GPIO_Pin_Init(GPIOA, USART1_CLK_Pin.PA8, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_1);

			if(config->hardware_flow != Hardware_Flow.Disable)
			{
				if(config->hardware_flow == Hardware_Flow.CTS_Enable)GPIO_Pin_Init(GPIOA, USART1_CTS_Pin.PA11, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_1);
				if(config->hardware_flow == Hardware_Flow.RTS_Enable)GPIO_Pin_Init(GPIOA, USART1_RTS_Pin.PA12, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_1);
				if(config->hardware_flow == Hardware_Flow.CTS_RTS_Enable)
				{
					GPIO_Pin_Init(GPIOA, USART1_CTS_Pin.PA11, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_1);
					GPIO_Pin_Init(GPIOA, USART1_RTS_Pin.PA12, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_1);
				}
		    }
		}
		else if((config->mode == Mode.SmartCard) ||
		   (config->mode == Mode.SmartCard_Clock) ||
		   (config->mode == Mode.Single_Wire_Half_Duplex) )
		{
			if(config->TX_Pin == USART1_TX_Pin.PA9)GPIO_Pin_Init(GPIOA, USART1_TX_Pin.PA9, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_1);
			if((config->mode == Mode.SmartCard_Clock))GPIO_Pin_Init(GPIOA, USART1_CLK_Pin.PA8, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_1);

		}
	}

	if(config->Port == USART2)
	{
		if((config->mode == Mode.Asynchronous) ||
		   (config->mode == Mode.Synchronous) ||
		   (config->mode == Mode.IrDA) ||
		   (config->mode == Mode.LIN) )
		{
			if(config->TX_Pin == USART2_TX_Pin.PA2)GPIO_Pin_Init(GPIOA, USART2_TX_Pin.PA2, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_2);
			else if(config->TX_Pin == USART2_TX_Pin.PD5)GPIO_Pin_Init(GPIOD, USART2_TX_Pin.PD5, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_2);

			if(config->RX_Pin == USART2_RX_Pin.PA3)GPIO_Pin_Init(GPIOA, USART2_RX_Pin.PA3, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_2);
			else if(config->RX_Pin == USART2_RX_Pin.PD6)GPIO_Pin_Init(GPIOD, USART2_RX_Pin.PD6, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_2);

			if((config->mode == Mode.Synchronous)){
				if(config->CLK_Pin == USART2_CLK_Pin.PA4)GPIO_Pin_Init(GPIOA, USART2_CLK_Pin.PA4, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_2);
				else if(config->CLK_Pin == USART2_CLK_Pin.PD7)GPIO_Pin_Init(GPIOA, USART2_CLK_Pin.PD7, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_2);
			}


			if((config->hardware_flow != Hardware_Flow.Disable) || (config->hardware_flow == Hardware_Flow.CTS_RTS_Enable))
			{
				if(config->hardware_flow == Hardware_Flow.CTS_Enable)
				{
					if(config->CLK_Pin == USART2_CTS_Pin.PA0)
					{
						GPIO_Pin_Init(GPIOA, USART2_CTS_Pin.PA0, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_2);
					}
					else if(config->CLK_Pin == USART2_CTS_Pin.PD3)
					{
						GPIO_Pin_Init(GPIOD, USART2_CTS_Pin.PD3, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_2);
					}
				}
				if((config->hardware_flow == Hardware_Flow.RTS_Enable) || (config->hardware_flow == Hardware_Flow.CTS_RTS_Enable))
				{
					if(config->CLK_Pin == USART2_RTS_Pin.PA1)
					{
						GPIO_Pin_Init(GPIOA, USART2_RTS_Pin.PA1, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_2);
					}
					else if(config->CLK_Pin == USART2_RTS_Pin.PD4)
					{
						GPIO_Pin_Init(GPIOD, USART2_RTS_Pin.PD4, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_2);
					}
				}

		    }
		}
		else if((config->mode == Mode.SmartCard) ||
		   (config->mode == Mode.SmartCard_Clock) ||
		   (config->mode == Mode.Single_Wire_Half_Duplex))
		{
			if(config->TX_Pin == USART2_TX_Pin.PA2)
			{
				GPIO_Pin_Init(GPIOA, USART2_TX_Pin.PA2, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_2);
			}
			else if(config->TX_Pin == USART2_TX_Pin.PD5)
			{
				GPIO_Pin_Init(GPIOD, USART2_TX_Pin.PD5, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_2);
			}

			if((config->mode == Mode.SmartCard_Clock))
			{
				if(config->CLK_Pin == USART2_CLK_Pin.PA4)
				{
					GPIO_Pin_Init(GPIOA, USART2_CLK_Pin.PA4, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_2);
				}
				else if(config->CLK_Pin == USART2_CLK_Pin.PD7)
				{
					GPIO_Pin_Init(GPIOA, USART2_CLK_Pin.PD7, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_2);
				}
			}
		}
	}

	if(config->Port == USART3)
	{
		if((config->mode == Mode.Asynchronous) ||
		   (config->mode == Mode.Synchronous) ||
		   (config->mode == Mode.IrDA) ||
		   (config->mode == Mode.LIN) )
		{
			if(config->TX_Pin == USART3_TX_Pin.PB11)GPIO_Pin_Init(GPIOA, USART3_TX_Pin.PA9, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_3);
			else if(config->TX_Pin == USART3_TX_Pin.PC10)GPIO_Pin_Init(GPIOB, USART3_TX_Pin.PB6, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_3);
			else if(config->TX_Pin == USART3_TX_Pin.PD8)GPIO_Pin_Init(GPIOB, USART3_TX_Pin.PB6, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_3);

			if(config->RX_Pin == USART3_RX_Pin.PA10)GPIO_Pin_Init(GPIOA, USART3_RX_Pin.PA10, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_3);
			else if(config->RX_Pin == USART3_RX_Pin.PB7)GPIO_Pin_Init(GPIOB, USART3_RX_Pin.PB7, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_3);

			if((config->mode == Mode.Synchronous))if(config->CLK_Pin == USART3_CLK_Pin.PA8)GPIO_Pin_Init(GPIOA, USART3_CLK_Pin.PA8, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_3);

			if(config->hardware_flow != Hardware_Flow.Disable)
			{
				if((config->hardware_flow == Hardware_Flow.CTS_Enable) || (config->hardware_flow == Hardware_Flow.CTS_RTS_Enable))
				{
					GPIO_Pin_Init(GPIOA, USART3_CTS_Pin.PA11, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_3);
				}
				if((config->hardware_flow == Hardware_Flow.RTS_Enable) || (config->hardware_flow == Hardware_Flow.CTS_RTS_Enable))
				{
					GPIO_Pin_Init(GPIOA, USART3_RTS_Pin.PA12, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_3);
				}
		    }
		}
		else if((config->mode == Mode.SmartCard) ||
		   (config->mode == Mode.SmartCard_Clock) ||
		   (config->mode == Mode.Single_Wire_Half_Duplex) )
		{
			if(config->TX_Pin == USART3_TX_Pin.PA9)GPIO_Pin_Init(GPIOA, USART3_TX_Pin.PA9, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_3);
			if((config->mode == Mode.SmartCard_Clock))GPIO_Pin_Init(GPIOA, USART3_CLK_Pin.PA8, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.USART_3);

		}
	}

}

int8_t USART_Init(USART_Config *config)
{
	USART_Clock_Enable(config);
	PIN_Setup(config);

	return 1;
}

