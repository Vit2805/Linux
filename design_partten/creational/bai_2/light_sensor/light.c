#include <stdio.h>
#include "light.h"

// Initialize the light sensor
void lightSensorInit() {
    printf("Light sensor initialized.\n");
}

// Read data from the light sensor
float lightSensorReadData(float i) {
    return i; // Simulated value
}

// Create a light sensor object
Sensor createLightSensor() {
    Sensor lightSensor;
    lightSensor.init = lightSensorInit;
    lightSensor.readData = lightSensorReadData;
    return lightSensor;
}