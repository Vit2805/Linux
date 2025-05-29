#ifndef SENSOR_H
#define SENSOR_H

typedef struct {
    void (*init)(void);      //Function to initialize the sensor
    float (*readData)(float); //Function to read date from the sensor
} Sensor;


#endif //SENSOR_H