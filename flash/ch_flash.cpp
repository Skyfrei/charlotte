#include "ch_flash.h"


spi_handle configureSpiSettings(){
    spi_handle handl = &SPI;
    
    enableSPI(handl);
    handl->beginTransaction(SPISettings(COMM_SPEED, DATA_ORDER, SPI_MODE0));

    disableSPI(handl);
    return handl; 
}

void enableSPI(spi_handle handl){
    handl->begin();
}

void disableSPI(spi_handle handl){
    handl->end();
}

void sendBuffer(spi_handle handl){
    uint8_t* buffer = new uint8_t[KB_NAME_SIZE];
    for (int i = 0; i < sizeof(KB_NAME) / sizeof(char); i++){
        buffer[i] = int(KB_NAME[i]);
    }

    size_t size = sizeof(KB_NAME) / sizeof(char);
    enableSPI(handl);
    handl->transfer(buffer, size);
    disableSPI(handl);

    delete(buffer);
}



