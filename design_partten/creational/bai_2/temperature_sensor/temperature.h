#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "../sensor_factory/sensor.h"

// Function prototypes for the temperature sensor
void temperatureSensorInit();
float temperatureSensorReadData(float i);
Sensor createTemperatureSensor();

#endif