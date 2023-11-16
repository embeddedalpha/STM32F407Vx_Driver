#include "main.h"
#include "SPI.h"


SPI_Config xDevice;

uint16_t Read_Byte(void);


int main(void)
{
	MCU_Clock_Setup();
	Delay_Config();

	SPI_Config_Reset(&xDevice);

	xDevice.Port = SPI1;
	xDevice.clock_pin = SPI1_CLK.PA5;
	xDevice.miso_pin = SPI1_MISO.PA6;
	xDevice.mosi_pin = SPI1_MOSI.PA7;
	xDevice.NSS_Port = GPIOA;
	xDevice.NSS_Pin = 4;
	xDevice.prescaler = SPI_Prescaler.CLK_div_8;
	SPI_Init(&xDevice);


	uint16_t chip;

	for(;;)
	{
		chip = Read_Byte();
		Delay_ms(100);
	}
}



uint16_t Read_Byte(void)
{
	uint16_t rx_byte;
	SPI_NSS_Low(&xDevice);
	SPI_TRX_Byte(&xDevice, 0x00);
	SPI_TRX_Byte(&xDevice, 0x39);
	rx_byte = SPI_TRX_Byte(&xDevice, 0x01);
	rx_byte = SPI_TRX_Byte(&xDevice, 0xAA);
	SPI_NSS_High(&xDevice);

	return rx_byte;
}
