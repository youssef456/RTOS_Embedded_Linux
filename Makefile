#CROSS_COMPILE ?=
#CROSS_COMPILE ?= aarch64-poky-linux-

#CC ?= $(CROSS_COMPILE)gcc

CFLAGS ?= -g -Wall -Werror

TARGET ?= rtos

LDFLAGS ?= -lpthread -lrt

CCFLAGS ?= -Wall -g -c

# Source and object directories
SRC_DIR := src
OBJ_DIR := obj

# List of source files
SRCS := $(wildcard $(SRC_DIR)/*.c)

# List of object files
OBJS := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

default: $(TARGET)

all: default

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(EXTRA_CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(EXTRA_CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)


