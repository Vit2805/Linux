#include <stdio.h>
#include "uart.h"

int main() {
    //Initalize the Builder
    UART_Builder builder = UART_Builder_init() ;

    //Config UART using the Builder
    UART_Config_t uartConfig = builder
        .setBaudRate(&builder, 115200)
        ->setParity(&builder, 1)
        ->setStopBits(&builder, 2)
        ->setDataBits(&builder, 9)
        ->build(&builder);

    //Printf the configured UART parameters
    printf("UART Configuration:\n");
    printf("Baud Rate: %d\n", uartConfig.baudRate);
    printf("Parity: %d\n", uartConfig.parity);
    printf("Stop Bits: %d\n", uartConfig.stopBits);
    printf("Data Bits: %d\n", uartConfig.dataBits);

    return 0;
}