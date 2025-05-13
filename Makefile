# Static library name
LIB_NAME = libsphysics.a

# Compiler and archiver
CC = gcc
AR = ar
ARFLAGS = rcs

# Directories
SRC_DIR = lib
OBJ_DIR = obj

# Source and object files
C_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(C_FILES))

# Include paths (add more with -I)
INCLUDES = -I./include

# Compiler flags
CFLAGS = -c $(INCLUDES)

# Default target
all: $(LIB_NAME)

# Link object files into static library
$(LIB_NAME): $(OBJ_FILES)
	$(AR) $(ARFLAGS) $@ $^

# Compile .c to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -o $@

# Ensure object directory exists
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean everything
clean:
	rm -rf $(OBJ_DIR) $(LIB_NAME)

.PHONY: all clean
