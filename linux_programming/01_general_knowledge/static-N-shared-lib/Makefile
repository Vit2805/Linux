.PHONY:

CUR_DIR := .
INC_DIR := $(CUR_DIR)/inc
SRC_DIR := $(CUR_DIR)/src
OBJ_DIR := $(CUR_DIR)/obj
BIN_DIR := $(CUR_DIR)/bin

LIB_NAME := hello
LIBS_DIR := $(CUR_DIR)/libs
LIBS_STATIC_DIR := $(LIBS_DIR)/static 
LIBS_SHARED_DIR := $(LIBS_DIR)/shared



# Create the object files 

shared_objs:
	gcc -c -o $(OBJ_DIR)/main.o main.c -I $(INC_DIR)
	gcc -c -fPIC -o $(OBJ_DIR)/hello_tung.o $(SRC_DIR)/hello_tung.c
	gcc -c -fPIC -o $(OBJ_DIR)/hello_world.o $(SRC_DIR)/hello_world.c

create_shared_lib:
	gcc -shared $(OBJ_DIR)/hello_tung.o $(OBJ_DIR)/hello_world.o -o $(LIBS_SHARED_DIR)/lib$(LIB_NAME).so

link_shared_lib:
	gcc $(OBJ_DIR)/main.o -L$(LIBS_SHARED_DIR) -l$(LIB_NAME) -o $(BIN_DIR)/use-shared-libary

install_shared_lib:
	install $(LIBS_SHARED_DIR)/lib$(LIB_NAME).so /usr/lib

all: shared_objs create_shared_lib link_shared_lib install_shared_lib
	@echo *make all target*

clean: 
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(LIBS_SHARED_DIR)/lib$(LIB_NAME).so
	rm -rf $(BIN_DIR)/use-shared-libary