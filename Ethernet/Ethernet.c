/*
 * Ethernet.c
 *
 *  Created on: Nov 25, 2023
 *      Author: kunal
 */


#include "Ethernet.h"

static uint16_t ETH_Read_PHY(uint8_t PHY_Address, uint8_t REG_Address)
{
	uint16_t data;
	ETH->MACMIIDR = 0x0000;
	ETH -> MACMIIAR &= ~ETH_MACMIIAR_MW;
	ETH -> MACMIIAR = ((  REG_Address) << ETH_MACMIIAR_MR_Pos) | ((PHY_Address) << ETH_MACMIIAR_PA_Pos)
			        | ETH_MACMIIAR_MB;
	while ((ETH->MACMIIAR & ETH_MACMIIAR_MB) != 0);
	data = ETH->MACMIIDR;
	return data;
}


static void ETH_Write_PHY(uint8_t PHY_Address, uint8_t REG_Address, uint16_t data)
{
	ETH -> MACMIIDR = data;
	ETH -> MACMIIAR = ((  REG_Address) << ETH_MACMIIAR_MR_Pos) | (( PHY_Address) << ETH_MACMIIAR_PA_Pos)
		            | ETH_MACMIIAR_MW | ETH_MACMIIAR_MB;
	while ((ETH->MACMIIAR & ETH_MACMIIAR_MB) != 0);
}


static void eth_rmii_pin_setup()
{
	// ETH_MDC
	GPIO_Pin_Init(GPIOC, 1, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.ETH_1);
	// ETH_REF_CLK
	GPIO_Pin_Init(GPIOA, 1, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.ETH_1);
	// ETH_MDIO
	GPIO_Pin_Init(GPIOA, 2, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.ETH_1);
	// ETH_CRS_DV
	GPIO_Pin_Init(GPIOA, 7, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.ETH_1);
	// ETH_RX_D0
	GPIO_Pin_Init(GPIOC, 4, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.ETH_1);
	// ETH_RX_D1
	GPIO_Pin_Init(GPIOC, 5, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.ETH_1);
	// ETH_TX_EN
	GPIO_Pin_Init(GPIOB, 11, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.ETH_1);
	// ETH_TX_D0
	GPIO_Pin_Init(GPIOB, 12, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.ETH_1);
	// ETH_TX_D1
	GPIO_Pin_Init(GPIOC, 13, MODE.Alternate_Function, Output_Type.Push_Pull, Speed.Very_High_Speed, Pull.No_Pull_Up_Down, Alternate_Functions.ETH_1);
}

void Ethernet_Init(Ethernet_Config *config)
{
	if(config->mode == Ethernet_Mode.RMII)
	{
		eth_rmii_pin_setup();
	}

	RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;
	SYSCFG -> PMC |= SYSCFG_PMC_MII_RMII_SEL ;

	while(ETH -> DMABMR & ETH_DMABMR_SR);

	RCC -> AHB1RSTR |= RCC_AHB1RSTR_ETHMACRST;
	RCC -> AHB1RSTR &= ~RCC_AHB1RSTR_ETHMACRST;

	ETH -> MACMIIAR &= ~ETH_MACMIIAR_CR;

	uint32_t temp;
	for(uint8_t temp_add = 0; temp_add < 32; temp_add++)
	{
		temp = (ETH_Read_PHY(temp_add, PHY_Default_Registers.PHY_Identifier_1_Register) << 16) |
			   (ETH_Read_PHY(temp_add, PHY_Default_Registers.PHY_Identifier_2_Register) << 0);

		if(temp == config->PHY_Chip_ID)
		{
			config->PHY_Address = temp_add;

			if(config->Debug)
			{
//				printConsole(USART1, "LAN8720 PHY's Address : %d  \r\n",temp_add);
				break;
			}

		}
	}
	//Do a Soft Reset
	ETH_Write_PHY(self->PHY.PHY_Address_New,PHY_Default_Registers.Basic_Mode_Register ,1<<15 );
	do temp = ETH_Read_PHY(self->PHY.PHY_Address_New, PHY_Default_Registers.Basic_Mode_Register);
	while ((temp & 0x8000));

	//Restart Auto-Negotiation
	temp = 0;
	temp = ETH_Read_PHY(self->PHY.PHY_Address_New, PHY_Default_Registers.Basic_Mode_Register);
	ETH_Write_PHY(self->PHY.PHY_Address_New,PHY_Default_Registers.Basic_Mode_Register ,temp|(1<<9) );

	//Check if Auto-Negotiation has completed
	do temp = ETH_Read_PHY(self->PHY.PHY_Address_New, PHY_Default_Registers.Basic_Mode_Status_Register);
	while (!(temp & (1<<5)));
	if(config->Debug)
	{
//		printConsole(USART1, "Auto-Negotiation Completed \r\n");
	}

	//Wait till link is up!
	do temp = ETH_Read_PHY(self->PHY.PHY_Address_New, PHY_Default_Registers.Basic_Mode_Status_Register);
	while (!(temp & (1<<2)));
	if(config->Debug)
	{
//		printConsole(USART1, "Link is up!!  \r\n");
	}
	if(ETH->MACFFR != 0) ETH -> MACFFR = 0;
	if(ETH->MACFCR != 0) ETH -> MACFCR = 0;
	if(ETH->MACVLANTR != 0) ETH -> MACVLANTR = 0;
	//Set Speed and Mode
	temp = ETH_Read_PHY(self->PHY.PHY_Address_New, PHY_Default_Registers.Auto_Negotiation_Link_Partner_Ability_Register);
	// Set Speed
	if(temp & (1<<8))
	{
		ETH -> MACCR |= ETH_MACCR_FES;	//100Mbits
		printConsole(USART1, "Link Speed : 100Mbits  \r\n");
	}
	else
	{
		ETH -> MACCR &= ~ETH_MACCR_FES;            //10Mbits
		printConsole(USART1, "Link Speed : 10Mbits  \r\n");
	}
	// Set Mode
	if(temp & (1<<7)){
		ETH -> MACCR |= ETH_MACCR_DM; //Full Duplex Mode
		printConsole(USART1, "Link Type : Full Duplex  \r\n");
	}
	else{
		ETH -> MACCR &= ~ETH_MACCR_DM;				//No Full Duplex Mode
		printConsole(USART1, "Link Type : No Full Duplex  \r\n");
	}




}
