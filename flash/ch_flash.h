
#include <SPI.h>
#include <stdint.h>
//256 kB Flash Memory
//
//
//
//
//
//

#define COMM_SPEED 48000000
#define DATA_ORDER MSBFIRST
#define KB_NAME_SIZE 9
#define KB_NAME "Charlotte"


#define SPI_MODE0 0x00
#define SPI_MODE1 0x04
#define SPI_MODE2 0x08
#define SPI_MODE3 0x0C

typedef  SPIClass* spi_handle;

spi_handle configureSpiSettings();

void enableSPI(spi_handle handl);
void disableSPI(spi_handle handl);
void sendBuffer(spi_handle handl);
