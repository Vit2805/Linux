#include <stdio.h>
#include "humidity.h"

// Initialize the humidity sensor
void humiditySensorInit() {
    printf("Humidity sensor initialized.\n");
}

// Read data from the humidity sensor
float humiditySensorReadData(float i) {
    return i; // Simulated value
}

// Create a humidity sensor object
Sensor createHumiditySensor() {
    Sensor humiditySensor;
    humiditySensor.init = humiditySensorInit;
    humiditySensor.readData = humiditySensorReadData;
    return humiditySensor;
}
