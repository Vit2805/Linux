#ifndef UART_BUILDER_H
#define UART_BUILEDR_H

#include <stdint.h>

// UART Config Structure
typedef struct {
    uint32_t baudRate; 
    uint8_t parity;
    uint8_t stopBits;
    uint8_t dataBits;
} UART_Config_t;

// UART Builder Structure
typedef struct UART_Builder {
    UART_Config_t config;
    struct UART_Builder* (*setBaudRate)(struct UART_Builder*, uint32_t);
    struct UART_Builder* (*setParity)(struct UART_Builder*, uint8_t);
    struct UART_Builder* (*setStopBits)(struct UART_Builder*, uint8_t);
    struct UART_Builder* (*setDataBits)(struct UART_Builder*, uint8_t);
    UART_Config_t (*build)(struct UART_Builder*); 
} UART_Builder;

//Function to initialize the Builder
UART_Builder UART_Builder_init();


#endif // UART_BUILDER_H