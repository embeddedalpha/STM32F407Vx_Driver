#include "main.h"
#include "SPI.h"
#include "DMA.h"


SPI_Config xSPI;
DMA_Config xDMA;

const uint8_t array[5] = {0x00,0x01,0x02,0x03,0x04};


int main(void)
{
	MCU_Clock_Setup();
	Delay_Config();

	SPI_Config_Reset(&xSPI);

	xSPI.Port = SPI1;
	xSPI.clock_pin = SPI1_CLK.PA5;
	xSPI.miso_pin = SPI1_MISO.PA6;
	xSPI.mosi_pin = SPI1_MOSI.PA7;
	xSPI.NSS_Port = GPIOA;
	xSPI.NSS_Pin = 4;
	xSPI.prescaler = SPI_Prescaler.CLK_div_8;
	SPI_Init(&xSPI);


	xDMA.stream = SPI_DMA_Stream.SPI1_RX;
	xDMA.controller = DMA2;
	xDMA.channel = SPI_DMA_Stream.SPI1_DMA_Channel;
	xDMA.circular_mode = DMA_Circular_Mode.Disable;
	xDMA.flow_control = DMA_Flow_Control.Peripheral_Control;
	xDMA.priority_level = DMA_Priority_Level.Very_high;
	xDMA.memory_data_size = DMA_Memory_Data_Size.byte;
	xDMA.peripheral_data_size = DMA_Peripheral_Data_Size.byte;
	xDMA.transfer_direction = DMA_Transfer_Direction.Memory_to_peripheral;
	xDMA.interrupts =  DMA_Interrupts.Disable;
	DMA_Init(&xDMA);

	xDMA.memory_address = (uint32_t)&array[0];
	xDMA.peripheral_address = (uint32_t)&(xSPI.Port->DR);
	xDMA.buffer_length = 5;
	DMA_Set_Target(&xDMA);





	for(;;)
	{

	}
}


