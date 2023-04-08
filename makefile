INC_DIR = ./inc
SRC_DIR = ./src
TMP_DIR = ./tmp
BIN_DIR = ./bin
OBJ_DIR = ./obj

CLFLAGS = gcc -Wall -pedantic -Werror -Wextra -Wconversion -std=gnu11

all: $(OBJ_DIR)/main.o $(OBJ_DIR)/getPrice.o
	@mkdir -p $(BIN_DIR)
	@mkdir -p $(TMP_DIR)
	@$(CLFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/getPrice.o -lcurl -o $(BIN_DIR)/getPrice
	@echo Todo ha sido construido correctamente

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.c
	@mkdir -p $(OBJ_DIR)
	@$(CLFLAGS) -c $(SRC_DIR)/main.c -I $(INC_DIR) -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/getPrice.o: $(SRC_DIR)/getPrice.c
	@mkdir -p $(OBJ_DIR)
	@$(CLFLAGS) -c $(SRC_DIR)/getPrice.c -I $(INC_DIR) -o $(OBJ_DIR)/getPrice.o

clean:
	@rm -f -r $(OBJ_DIR) $(BIN_DIR) $(TMP_DIR)
	@echo Todo ha sido limpiado