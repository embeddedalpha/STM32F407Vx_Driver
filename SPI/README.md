<h1> SPI Driver </h1>

<h3> Functions available: </h3>

'''C

int8_t SPI_Clock_Enable(SPI_Config *config);
int8_t SPI_Clock_Disable(SPI_Config *config);
int8_t SPI_Config_Reset(SPI_Config *config);
void SPI_Init(SPI_Config *config);
void SPI_DeInit(SPI_Config *config);
void SPI_TX_Byte(SPI_Config *config, uint16_t data);
uint16_t SPI_RX_Byte(SPI_Config *config);
void SPI_TX_Buffer(SPI_Config *config, uint8_t *tx_buffer, uint16_t length);
void SPI_RX_Buffer(SPI_Config *config, uint8_t *rx_buffer, uint16_t length);

'''