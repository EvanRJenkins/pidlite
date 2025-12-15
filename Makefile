CC = gcc
CFLAGS = -Iinclude -Wall -Wextra
SRCS = src/test.c src/pidlite.c
TARGET = test_pid

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
