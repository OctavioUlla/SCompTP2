INC_DIR = ./inc
SRC_DIR = ./src
BIN_DIR = ./bin
OBJ_DIR = ./obj

CLFLAGS = gcc -g -Wall -pedantic -Werror -Wextra -Wconversion -std=gnu11
NASMFLAGS = nasm -felf64

all: $(OBJ_DIR)/main.o $(OBJ_DIR)/getPrice.o $(OBJ_DIR)/mult.o 
	@mkdir -p $(BIN_DIR)
	@$(CLFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/getPrice.o $(OBJ_DIR)/mult.o  -lcurl -o $(BIN_DIR)/getPrice
	@echo Todo ha sido construido correctamente

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	@mkdir -p $(OBJ_DIR)
	@$(CLFLAGS) -c $(SRC_DIR)/main.c -I $(INC_DIR) -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/getPrice.o: $(SRC_DIR)/getPrice.c
	@mkdir -p $(OBJ_DIR)
	@$(CLFLAGS) -c $(SRC_DIR)/getPrice.c -I $(INC_DIR) -o $(OBJ_DIR)/getPrice.o

$(OBJ_DIR)/mult.o: $(SRC_DIR)/mult.asm
	@mkdir -p $(OBJ_DIR)
	@$(NASMFLAGS) $(SRC_DIR)/mult.asm -o $(OBJ_DIR)/mult.o
clean:
	@rm -f -r $(OBJ_DIR) $(BIN_DIR)
	@echo Todo ha sido limpiado