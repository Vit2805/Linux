#ifndef HUMIDITY_SENSOR_H
#define HUMIDITY_SENSOR_H

#include "../sensor_factory/sensor.h"

// Function prototypes for the humidity sensor
void humiditySensorInit();
float humiditySensorReadData(float i);
Sensor createHumiditySensor();

#endif