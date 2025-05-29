#include <stdio.h>
#include "temperature.h"

// Initialize the temperature sensor
void temperatureSensorInit() {
    printf("Temperature sensor initialized.\n");
}

// Read data from the temperature sensor
float temperatureSensorReadData(float i) {
    return i; // Simulated value
}

// Create a temperature sensor object
Sensor createTemperatureSensor() {
    Sensor tempSensor;
    tempSensor.init = temperatureSensorInit;
    tempSensor.readData = temperatureSensorReadData;
    return tempSensor;
}