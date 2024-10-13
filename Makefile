# Makefile for ECU Project

# Compiler
CC = gcc

# Compiler Flags
CFLAGS = -Wall -Wextra -O2

# Source Files
SRCS = ecu_vars.c ecu_log.c

# Header Files
HEADERS = ecu_vars.h

# Output Directory and Executable
OUT_DIR = dist
OUT_EXE = $(OUT_DIR)/log.exe

# Default Target
all: $(OUT_EXE)

# Link the executable
$(OUT_EXE): $(SRCS) $(HEADERS)
	@mkdir -p $(OUT_DIR)
	$(CC) $(CFLAGS) $(SRCS) -o $(OUT_EXE)

# Clean up build artifacts
clean:
	rm -rf $(OUT_DIR)

# Phony Targets
.PHONY: all clean

