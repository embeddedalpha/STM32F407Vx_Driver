/*
 * CAN.h
 *
 *  Created on: Oct 9, 2023
 *      Author: Kunal
 */

#ifndef CAN_H_
#define CAN_H_

#include "main.h"
#include "GPIO.h"
//#include "DMA.h"
#include "CAN_Defs.h"


typedef struct CAN_Interrupt_t
{
	bool Interrup_Enable;
	bool Sleep_Interrupt_Enable;
	bool Wakeup_Interrupt_Enable;
	bool Error_Interrupt_Enable;
	bool Last_Error_Enable;
	bool Buss_Off_Interrupt_Enable;
	bool Erro_Passive_Interrupt_Enable;
	bool Error_Warning_Interupt_Enable;
	bool FIFO_Overrun_Interupt_Enable;
	bool FIFO_Full_Interrupt_Enable;
	bool FIFO_Message_Pending_Interrupt_Enable;
	bool FIFO_Overrun_Interrupt_Enable;
	bool Transmit_Mailbox_Empty_Interrupt_Enable;
}CAN_Interrupt_t;

typedef struct CAN_Error_Status_t
{
	bool Stuff_Error;
	bool Form_Error;
	bool Acknowledge_Error;
	bool Bit_Recessive_Error;
	bool Bit_Dominant_Error;
	bool CRC_Error;
	bool Buss_Off_State;
	bool Passive_Error_Flag;
	bool Error_Warning_Flag;

}CAN_Error_Status_t;



typedef struct CAN_Filter_TypeDef
{
	bool active;
	uint8_t number;
	uint32_t Bank1;
	uint32_t Bank2;
	uint8_t FIFO_number;
	uint8_t Filter_mode;
}CAN_Filter_TypeDef;


typedef struct CAN_Config_t
{
	CAN_TypeDef *instance;
	uint8_t TX_Pins;
	uint8_t RX_Pins;
	uint32_t baudrate;
	bool automoatic_retransmission;
	bool automatic_wakeup;
	CAN_Interrupt_t interrupt;
	bool ID_Type;
}CAN_Config_t;


typedef struct CAN_Packet
{
	uint32_t ID;
	uint8_t data_length;
	uint8_t data[8];
	bool frame_type;
	uint8_t mailbox_number;
}CAN_Packet;





__WEAK void CAN1_TX_IRQHandler(void);
__WEAK void CAN1_RX0_IRQHandler(void);
__WEAK void CAN1_RX1_IRQHandler(void);
__WEAK void CAN1_SCE_IRQHandler(void);

__WEAK void CAN2_TX_IRQHandler(void);
__WEAK void CAN2_RX0_IRQHandler(void);
__WEAK void CAN2_RX1_IRQHandler(void);
__WEAK void CAN2_SCE_IRQHandler(void);


can_retval CAN_Clock_Activate(CAN_Config_t *config);
can_retval CAN_PIN_Enable(CAN_Config_t *config);

can_retval CAN_Setup(CAN_Config_t *config);
can_retval CAN_Initialization_Mode(CAN_Config_t *config);
can_retval CAN_Normal_Mode(CAN_Config_t *config);
can_retval CAN_Sleep_Mode(CAN_Config_t *config);
can_retval CAN_Filter_Setup(CAN_Config_t *config, CAN_Filter_TypeDef *filter);
can_retval CAN_Send_Packet(CAN_Config_t *config, CAN_Packet *frame);
can_retval CAN_PIN_Disable(CAN_Config_t *config);
can_retval CAN_Clock_Deactivate(CAN_Config_t *config);



/*
 * CAN CLOCK ENABLE
 *
 *
 *
 * CAN CLOCK DISABLE
 */


#endif /* CAN_H_ */
