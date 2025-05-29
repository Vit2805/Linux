#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include "../sensor_factory/sensor.h"

// Function prototypes for the light sensor
void lightSensorInit();
float lightSensorReadData(float i);
Sensor createLightSensor();

#endif