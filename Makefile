CC = gcc
CFLAGS = -Wall -Wextra -O2

LIB_DIR = lib
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = tests
BIN_DIR = bin
BUILD_DIR = build
AR = ar
ARFLAGS = rcs
LIB_NAME = logger
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
TEST_SRC = $(TEST_DIR)/test.c
TEST_OUT = $(BIN_DIR)/test
TEST_FLAGS = -L$(LIB_DIR)/ -l$(LIB_NAME)
all: static_lib dynamic_lib tests dirs

dirs:
	@mkdir -p $(LIB_DIR) $(OBJ_DIR)

static_lib: lib$(LIB_NAME).a
dynamic_lib: lib$(LIB_NAME).dylib

lib$(LIB_NAME).a: $(OBJ)
	$(AR) $(ARFLAGS) lib/$@ $^

tests: $(TEST_SRC) lib$(LIB_NAME).a
	$(CC) $(CFLAGS) $< -o $(TEST_OUT) $(TEST_FLAGS)

lib$(LIB_NAME).dylib: $(OBJ)
	$(CC) -shared -o lib/$@ $^

%.o: %.c dirs
	$(CC) $(CFLAGS) -c $< -o $@

test: tests
	@./$(TEST_OUT)
