    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define MAX_SENSOR_NODE 4
    #define SENSOR_NODE_NAME_SIZE 20
    #define SENSOR_NODE_MEASURE_SIZE 20

    typedef struct {
        char name[SENSOR_NODE_NAME_SIZE];
        char measure[SENSOR_NODE_MEASURE_SIZE];
        double value;
    }SensorNode;

    typedef struct {
        SensorNode nodes[MAX_SENSOR_NODE];
        int nodeCount;
    } SensorManager;



    static SensorManager* sensorManagerInstance = NULL;

    // Function to create or get the unique SensorManager instance
    SensorManager* createSensorManager() {
        if (sensorManagerInstance != NULL) {
            printf("Error: Sensor Manager already exists! Cannot create another one.\n");
            return NULL;
        }

        sensorManagerInstance = (SensorManager*)malloc(sizeof(SensorManager));
        if (sensorManagerInstance != NULL){
            sensorManagerInstance->nodeCount = 0;
        }
        return sensorManagerInstance;
    }

    // Function to destroy the Sensor Manager instance
    void destroySensorManager() {
        if (sensorManagerInstance != NULL) {
            free(sensorManagerInstance);
            sensorManagerInstance = NULL;
        }
    }

    // Funtion add new Sensor
    int addSensorNode(SensorManager *manager, const char* name, const char* measure, double value) {
        if (manager->nodeCount >= MAX_SENSOR_NODE) {
            printf("Sensor Node list is full! \n");
        }
        snprintf(manager->nodes[manager->nodeCount].name, SENSOR_NODE_NAME_SIZE, "%s", name);
        snprintf(manager->nodes[manager->nodeCount].measure, SENSOR_NODE_MEASURE_SIZE, "%s", measure);
        manager->nodes[manager->nodeCount].value = value;
        manager->nodeCount++;
        return 1; 
    }

    void displayData(SensorManager *manager) {
        printf("=== Sensor Manager === \n\n");
        for (int i = 0; i < manager->nodeCount; i++) {
            printf("SensorNode %d: Name: %s, Value: %.2f Measure: %s \n", i+1, manager->nodes[i].name, manager->nodes[i].value, manager->nodes[i].measure);
        }
    }

    int main() {
        // Create the Sensor Manager
        SensorManager* sensorManager =  createSensorManager();
        if (sensorManager != NULL) {
            printf("Sensor Manager created \n");
        }

        // Attempt to create a second Sensor Manager
        SensorManager* sensorManager2 = createSensorManager();
        if (sensorManager2 == NULL) {
            printf("Failed to create Sensor Manager 2.\n\n");
        }

        // Add Sensor Nodes
        if (sensorManager != NULL) {
            addSensorNode(sensorManager, "Nhiet do","do", 30.5);
            addSensorNode(sensorManager, "Do am","%", 70.2);
            addSensorNode(sensorManager,"Ap suat", "atm",13.25);
        }
        // Display the current Sensor Nodes
        displayData(sensorManager);

        // Destroy the Sensor Manager
        destroySensorManager();
        printf("Sensor Manager destroyed. \n");

        return 0;
    }
