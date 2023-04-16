INC_DIR = ./inc
SRC_DIR = ./src
BIN_DIR = ./bin
OBJ_DIR = ./obj
TMP_DIR = ./tmp

CLFLAGS = gcc -g -Wall -pedantic -Werror -Wextra -Wconversion -std=gnu11
NASMFLAGS = nasm

all: dir $(BIN_DIR)/calculadora $(BIN_DIR)/calculadora32
	@echo Todo ha sido construido correctamente

$(BIN_DIR)/calculadora: $(OBJ_DIR)/main.o $(OBJ_DIR)/mult.o $(OBJ_DIR)/coinHelper.o $(OBJ_DIR)/simbolos.o $(BIN_DIR)/getPrice
	@$(CLFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/mult.o $(OBJ_DIR)/coinHelper.o $(OBJ_DIR)/simbolos.o -o $(BIN_DIR)/calculadora

$(BIN_DIR)/calculadora32: $(OBJ_DIR)/main32.o $(OBJ_DIR)/mult32.o $(OBJ_DIR)/coinHelper32.o $(OBJ_DIR)/simbolos32.o $(BIN_DIR)/getPrice
	@$(CLFLAGS) -m32 $(OBJ_DIR)/main32.o $(OBJ_DIR)/mult32.o $(OBJ_DIR)/coinHelper32.o $(OBJ_DIR)/simbolos32.o -o $(BIN_DIR)/calculadora32

dir:
	@mkdir -p $(BIN_DIR)

$(BIN_DIR)/getPrice: $(OBJ_DIR)/getPrice.o $(OBJ_DIR)/simbolos.o
	@$(CLFLAGS) $(OBJ_DIR)/getPrice.o $(OBJ_DIR)/simbolos.o -lcurl -o $(BIN_DIR)/getPrice

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	@mkdir -p $(OBJ_DIR)
	@$(CLFLAGS) -c $(SRC_DIR)/main.c -I $(INC_DIR) -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/main32.o: $(SRC_DIR)/main.c
	@mkdir -p $(OBJ_DIR)
	@$(CLFLAGS) -m32 -c $(SRC_DIR)/main.c -I $(INC_DIR) -o $(OBJ_DIR)/main32.o

$(OBJ_DIR)/getPrice.o: $(SRC_DIR)/getPrice.c
	@mkdir -p $(OBJ_DIR)
	@$(CLFLAGS) -c $(SRC_DIR)/getPrice.c -I $(INC_DIR) -o $(OBJ_DIR)/getPrice.o

$(OBJ_DIR)/coinHelper.o: $(SRC_DIR)/coinHelper.c
	@mkdir -p $(OBJ_DIR)
	@$(CLFLAGS) -c $(SRC_DIR)/coinHelper.c -I $(INC_DIR) -o $(OBJ_DIR)/coinHelper.o

$(OBJ_DIR)/coinHelper32.o: $(SRC_DIR)/coinHelper.c
	@mkdir -p $(OBJ_DIR)
	@$(CLFLAGS) -m32 -c $(SRC_DIR)/coinHelper.c -I $(INC_DIR) -o $(OBJ_DIR)/coinHelper32.o

$(OBJ_DIR)/simbolos.o: $(SRC_DIR)/simbolos.c
	@mkdir -p $(OBJ_DIR)
	@$(CLFLAGS) -c $(SRC_DIR)/simbolos.c -I $(INC_DIR) -o $(OBJ_DIR)/simbolos.o

$(OBJ_DIR)/simbolos32.o: $(SRC_DIR)/simbolos.c
	@mkdir -p $(OBJ_DIR)
	@$(CLFLAGS) -m32 -c $(SRC_DIR)/simbolos.c -I $(INC_DIR) -o $(OBJ_DIR)/simbolos32.o

$(OBJ_DIR)/mult.o: $(SRC_DIR)/mult.asm
	@mkdir -p $(OBJ_DIR)
	@$(NASMFLAGS) -felf64 $(SRC_DIR)/mult.asm -o $(OBJ_DIR)/mult.o

$(OBJ_DIR)/mult32.o: $(SRC_DIR)/mult32.asm
	@mkdir -p $(OBJ_DIR)
	@$(NASMFLAGS) -felf $(SRC_DIR)/mult32.asm -o $(OBJ_DIR)/mult32.o

clean:
	@rm -f -r $(OBJ_DIR) $(BIN_DIR) $(TMP_DIR)
	@echo Todo ha sido limpiado