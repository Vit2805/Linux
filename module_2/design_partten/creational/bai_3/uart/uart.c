#include <stdio.h>
#include <stdint.h>
#include "uart.h"

//Function to set the baund rate
static UART_Builder* setBaundRate(UART_Builder *builder, uint32_t baundRate) {
    if (baundRate < 1200 || baundRate > 115200) {
        printf("Error: Invalid baud rate. Its must be between 1200 and 115200. \n");
        return builder;
    }
    builder->config.baudRate = baundRate;
    return builder;
}

// Function to set the parity 
static UART_Builder* setParity(UART_Builder* builder, uint8_t parity) {
    if (parity > 2) {
        printf("Error: Invalid parity. Must be 0 (None), 1 (Odd) or 2 (Even).\n");
        return builder;
    }
    builder->config.parity = parity;
    return builder;
}

// Function to set the stop bits
static UART_Builder* setStopBits(UART_Builder* builder, uint8_t stopBits) {
    if (stopBits != 1 && stopBits != 2) {
        printf("Error: Invalid stop bits. Must be 1 or 2.\n");
        return builder;
    }
    builder->config.stopBits = stopBits;
    return builder;
}

// Function to set the data bits
static UART_Builder* setDataBits(UART_Builder* builder, uint8_t dataBits) {
    if (dataBits != 8 && dataBits != 9) {
        printf("Error: Invalid data bits. Must be 8 or 9. \n");
        return builder;
    }
    builder->config.dataBits = dataBits;
    return builder;
}

// Function to build and return the UART configuration
static UART_Config_t build(UART_Builder* builder) {
    return builder->config;
}

//Funtion to initialize the Builder
UART_Builder UART_Builder_init() {
    UART_Builder builder;
    builder.config.baudRate = 9600; 
    builder.config.parity = 0;
    builder.config.stopBits = 1;
    builder.config.dataBits = 8;
    builder.setBaudRate = setBaundRate;
    builder.setParity = setParity;
    builder.setStopBits = setStopBits;
    builder.setDataBits = setDataBits;
    builder.build = build;
    return builder;
}