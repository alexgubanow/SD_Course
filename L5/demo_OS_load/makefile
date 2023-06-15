CC = gcc
CFLAGS = -Wall -Werror

APP_NAME = myapp

SRC_DIR = .
OBJ_DIR = obj
OUT_DIR = out

APP_SRC = $(SRC_DIR)/main.c

LIB_NAME = libmylib.so
LIB_SRC = $(SRC_DIR)/library.c
LIB_OBJ = $(OBJ_DIR)/library.o

all: $(OUT_DIR)/$(APP_NAME)

$(OUT_DIR)/$(APP_NAME): $(APP_SRC) $(OUT_DIR)/$(LIB_NAME) | $(OUT_DIR)
	$(CC) $(CFLAGS) -o $@ $< -L$(OUT_DIR) -lmylib -Wl,-rpath='$$ORIGIN'

$(OUT_DIR)/$(LIB_NAME): $(LIB_OBJ) | $(OUT_DIR)
	$(CC) $(CFLAGS) -shared -o $@ $<

$(LIB_OBJ): $(LIB_SRC) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -fPIC -c -o $@ $<

$(OBJ_DIR) $(OUT_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR) $(OUT_DIR)

run: $(OUT_DIR)/$(APP_NAME)
	LD_LIBRARY_PATH=$(CURDIR)/$(OUT_DIR) ./$(OUT_DIR)/$(APP_NAME)

.PHONY: all clean run
