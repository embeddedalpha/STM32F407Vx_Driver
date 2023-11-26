/*
 * Ethernet_Defs.h
 *
 *  Created on: Nov 25, 2023
 *      Author: kunal
 */

#ifndef ETHERNET_DEFS_H_
#define ETHERNET_DEFS_H_

#include "main.h"

static const struct Ethernet_Mode
{
	uint8_t MII;
	uint8_t MII_Half_Duplex;
	uint8_t MII_Full_Duplex;
	uint8_t RMII;
}Ethernet_Mode = {0,1,2,3};

static const struct Ethernet_Speed
{
	uint8_t Speed_10Mbits;
	uint8_t Speed_100Mbits;

}Ethernet_Speed = {0<<14, 1<<14};

static const struct Ethernet_Phy
{
	uint32_t LAN8720;
	uint32_t DP83867;

}Ethernet_Phy = {0x0007C0F0, 0x2000A231};


static const struct PHY_Default_Registers
{
	uint8_t Basic_Mode_Register;
	uint8_t Basic_Mode_Status_Register;
	uint8_t PHY_Identifier_1_Register;
	uint8_t PHY_Identifier_2_Register;
	uint8_t Auto_Negotiation_Advertisement_Register;
	uint8_t Auto_Negotiation_Link_Partner_Ability_Register;
	uint8_t Auto_Negotiation_Expansion_Register;

}PHY_Default_Registers = {0,1,2,3,4,5,6};


#endif /* ETHERNET_DEFS_H_ */
