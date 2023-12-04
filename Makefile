CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic
SRC_DIR = src
BUILD_DIR = build

# List of source files
SRCS = $(wildcard $(SRC_DIR)/*.c)
# List of object files
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))
# Executable name
TARGET = RTOS

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean
