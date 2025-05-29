CC = gcc
CFLAGS = -Wall -Wextra -I.

# Directories
SRC_DIR = .
TEMP_DIR = $(SRC_DIR)/temperature_sensor
HUMID_DIR = $(SRC_DIR)/humidity_sensor
LIGHT_DIR = $(SRC_DIR)/light_sensor
FACTORY_DIR = $(SRC_DIR)/sensor_factory

# Source files
SRCS = $(TEMP_DIR)/temperature.c \
       $(HUMID_DIR)/humidity.c \
       $(LIGHT_DIR)/light.c \
       $(FACTORY_DIR)/sensor_factory.c \
       $(SRC_DIR)/main.c

# Object files
OBJS = $(SRCS:.c=.o)

# Output executable
TARGET = sensorProject

# Build rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
       del /f /q .\temperature_sensor\temperature.o .\humidity_sensor\humidity.o .\light_sensor\light.o .\sensor_factory\sensor_factory.o .\main.o sensorProject 2>nul
