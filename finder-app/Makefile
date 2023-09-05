# Makefile for writer application

# Compiler and flags
CC := $(CROSS_COMPILE)gcc
CFLAGS := -Wall -Werror

# Source files and output binary
SRCS := writer.c
OBJS := $(SRCS:.c=.o)
OUT := writer

# Default target
default: $(OUT)

# Build the application
$(OUT): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Clean target
clean:
	rm -f $(OUT) $(OBJS)

.PHONY: default clean

