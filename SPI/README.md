<h1> SPI Driver </h1>

<h3> Functions available: </h3>

```C

int8_t SPI_Clock_Enable(SPI_Config *config);
int8_t SPI_Clock_Disable(SPI_Config *config);
int8_t SPI_Config_Reset(SPI_Config *config);
void SPI_Init(SPI_Config *config);
void SPI_DeInit(SPI_Config *config);
void SPI_TX_Byte(SPI_Config *config, uint16_t data);
uint16_t SPI_RX_Byte(SPI_Config *config);
void SPI_TX_Buffer(SPI_Config *config, uint8_t *tx_buffer, uint16_t length);
void SPI_RX_Buffer(SPI_Config *config, uint8_t *rx_buffer, uint16_t length);

```

<h3> Declare a config structure at the top of the program to setup the peripheral: </h3>

```C

SPI_Condfig xDevice;

```

<h3> Use functions in SPI_Defs.h for assistance: </h3>

```C

xDevice.Port = SPI1;
xDevice.clock_pin = SPI1_CLK.PA5;
xDevice.miso_pin = SPII_MISO.PA6;
xDevice.mosi_pin = SPI1_MOSI.PA7;
.........

```

