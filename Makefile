# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -fPIC

# Directories
SRC = src
OBJ = obj
BUILD = build
LIB = lib
INCLUDE = include
DEMO = demo

# Source Files
COMMON_SRC = $(SRC)/heapcommon.c
MAXHEAP_SRC = $(SRC)/maxheap.c
MINHEAP_SRC = $(SRC)/minheap.c

# Object Files
COMMON_OBJ = $(OBJ)/heapcommon.o
MAXHEAP_OBJ = $(OBJ)/maxheap.o
MINHEAP_OBJ = $(OBJ)/minheap.o

# Shared Libraries
LIBMAXHEAP = $(LIB)/libmaxheap.so
LIBMINHEAP = $(LIB)/libminheap.so

# Test Executable
APP = $(BUILD)/heap_demo

# Targets
all: $(LIBMAXHEAP) $(LIBMINHEAP) $(APP)

# Pattern rule to compile .c files to .o files
$(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p $(OBJ)
	$(CC) $(CFLAGS) -c $< -o $@

# Create shared libraries
$(LIBMAXHEAP): $(MAXHEAP_OBJ) $(COMMON_OBJ)
	@mkdir -p $(LIB)
	$(CC) -shared -o $@ $^

$(LIBMINHEAP): $(MINHEAP_OBJ) $(COMMON_OBJ)
	@mkdir -p $(LIB)
	$(CC) -shared -o $@ $^

# Link shared libraries into demo executable
$(APP): $(DEMO)/heap_demo.c $(LIBMAXHEAP) $(LIBMINHEAP)
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -o $@ $< -L$(LIB) -lmaxheap -lminheap -Wl,-rpath,$(LIB)

clean:
	rm -f $(OBJ)/*.o $(LIB)/*.so $(BUILD)/*

.PHONY: all clean
