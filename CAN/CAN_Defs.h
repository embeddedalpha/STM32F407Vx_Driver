/*
 * CAN_Defs.h
 *
 *  Created on: Oct 10, 2023
 *      Author: Kunal
 */

#ifndef CAN_DEFS_H_
#define CAN_DEFS_H_

#include "main.h"



typedef enum can_retval
{
	success = 1,
	error_can_instance = -1,
	error_can_initialization = -2,
	error_can_normal = -3,
	error_can_sleep = -4,
	error_setup = -5,
	error_transmit = -6,
	error_filter = -7,
	no_filter_selected = 2,


}can_retval;


static const struct CAN_Baudrate
{
	uint32_t baud_1000K;
	uint32_t baud_800K ;
	uint32_t baud_500K ;
	uint32_t baud_250K ;
	uint32_t baud_125K ;
	uint32_t baud_100K ;
	uint32_t baud_83_333K ;
	uint32_t baud_50K     ;
	uint32_t baud_20K     ;
	uint32_t baud_10K     ;
}CAN_Baudrate = {0x001c0002, 0x001b0003, 0x001c0005, 0x001c000b, 0x001c0017, 0x001c001d, 0x001e001f,
		0x001c003b,0x001c0095,0x001c012b};


static const struct CAN_ID_Type
{
	uint8_t Standard_ID;
	uint8_t Extended_ID;
}CAN_ID_Type = {0,1};


static const struct CAN_Filter_Mode
{
	uint8_t Mask;
	uint8_t List;
}CAN_Filter_Mode = {0,1};

static const struct CAN_Fifo_Number
{
	uint8_t FIFO_0;
	uint8_t FIFO_1;
}CAN_Fifo_Number = {0,1};

/********************************************** CONTROLLER AREA NETWORK **********************************************/
static const struct CAN1_TX_Pin
{
	uint8_t PA12;
	uint8_t PD1;
	uint8_t PB9;
}CAN1_TX_Pin = {12,1,9};

static const struct CAN1_RX_Pin
{
	uint8_t PA11;
	uint8_t PD0;
	uint8_t PB8;
}CAN1_RX_Pin = {11,0,8};

static const struct CAN2_TX_Pin
{
	uint8_t PB13;
	uint8_t PB6;
}CAN2_TX_Pin = {13,6};

static const struct CAN2_RX_Pin
{
	uint8_t PB12;
	uint8_t PB5;
}CAN2_RX_Pin = {12,5};

#endif /* CAN_DEFS_H_ */
