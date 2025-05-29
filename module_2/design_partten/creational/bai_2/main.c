#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include <stdlib.h>
#include "sensor_factory/sensor_factory.h"

int main() {
    // Create a temperature sensor
    Sensor* tempSensor = createSensor(SENSOR_TEMPERATURE);
    if (tempSensor != NULL) {
        tempSensor->init();
        float i;
        printf("Du lieu doc duoc: ");
        scanf("%f", &i);
        printf("Temperature: %.2f°C\n", tempSensor->readData(i));
        free(tempSensor);
    }

    // Create a humidity sensor
    Sensor* humiditySensor = createSensor(SENSOR_HUMIDITY);
    if (humiditySensor != NULL) {
        humiditySensor->init();
        float i;
        printf("Du lieu doc duoc: ");
        scanf("%f", &i);
        printf("Humidity: %.2f%%\n", humiditySensor->readData(i));
        free(humiditySensor);
    }

    // Create a light sensor
    Sensor* lightSensor = createSensor(SENSOR_LIGHT);
    if (lightSensor != NULL) {
        lightSensor->init();
        float i;
        printf("Du lieu doc duoc: ");
        scanf("%f", &i);
        printf("Light Intensity: %.2f lux\n", lightSensor->readData(i));
        free(lightSensor);
    }

    return 0;
}