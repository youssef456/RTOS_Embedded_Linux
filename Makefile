CC = $(CC)
CFLAGS = $(CFLAGS)

SRC_DIR = src
BUILD_DIR = ${WORKDIR}/build

TARGET = rtos

all: ${TARGET}

${TARGET}: ${OBJS}
	$(CC) $(CFLAGS) -o $@ $^

${BUILD_DIR}/%.o: ${SRC_DIR}/%.c | ${BUILD_DIR}
	$(CC) $(CFLAGS) -c -o $@ $<

${BUILD_DIR}:
	mkdir -p $@

clean:
	rm -rf ${BUILD_DIR} ${TARGET}

.PHONY: all clean

