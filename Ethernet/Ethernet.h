/*
 * Ethernet.h
 *
 *  Created on: Nov 25, 2023
 *      Author: kunal
 */

#ifndef ETHERNET_H_
#define ETHERNET_H_

#include "main.h"
#include "GPIO.h"
#include "Ethernet_Defs.h"



typedef struct Ethernet_Config
{
	uint8_t mode;
	uint8_t PHY_Chip_ID;
	uint8_t PHY_Address;
	uint8_t Speed;
	uint8_t Source_MAC_Address[6];
	bool Debug;

}Ethernet_Config;




#endif /* ETHERNET_H_ */
