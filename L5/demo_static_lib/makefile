CC = gcc
CFLAGS = -Wall -Werror

APP_NAME = $(OUT_DIR)/myapp
LIB_NAME = $(OUT_DIR)/mylib

SRC_DIR = .
OBJ_DIR = obj
OUT_DIR = out

APP_SRC = $(SRC_DIR)/main.c
LIB_SRC = $(SRC_DIR)/library.c

APP_OBJ = $(OBJ_DIR)/main.o
LIB_OBJ = $(OBJ_DIR)/library.o

all: $(APP_NAME)

$(APP_NAME): $(APP_OBJ) $(LIB_OBJ) | $(OUT_DIR)
	$(CC) $(CFLAGS) -o $@ $^

$(APP_OBJ): $(APP_SRC) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIB_OBJ): $(LIB_SRC) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(OUT_DIR)

.PHONY: all clean
