CC = gcc
CFLAGS = #-Wall -Werror
LDFLAGS = -shared
LDLIBS = -ldl

APP_NAME = myapp
LIB_NAME = libmylib.so

SRC_DIR = .
OBJ_DIR = obj
OUT_DIR = out

APP_SRC = $(SRC_DIR)/main.c
LIB_SRC = $(SRC_DIR)/library.c

APP_OBJ = $(OBJ_DIR)/main.o
LIB_OBJ = $(OBJ_DIR)/library.o

all: $(OUT_DIR)/$(APP_NAME)

$(OUT_DIR)/$(APP_NAME): $(APP_OBJ) $(OUT_DIR)/$(LIB_NAME) | $(OUT_DIR)
	$(CC) $(CFLAGS) -o $@ $< -L$(OUT_DIR) -lmylib -Wl,-rpath=$(OUT_DIR) $(LDLIBS)

$(APP_OBJ): $(APP_SRC) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OUT_DIR)/$(LIB_NAME): $(LIB_OBJ) | $(OUT_DIR)
	$(CC) $(LDFLAGS) -o $@ $<

$(LIB_OBJ): $(LIB_SRC) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -fPIC -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OUT_DIR):
	mkdir -p $(OUT_DIR)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(OUT_DIR)

.PHONY: all clean
