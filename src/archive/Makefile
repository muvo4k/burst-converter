CC = gcc
CFLAGS = -g -Wall -Wextra

# List of source files
SRCS = main.c globals.c functions.c

# Generate object file names from source files
OBJS = $(SRCS:.c=.o)

# Name of the final executable
TARGET = program

# Additional header files
INCLUDES = -I.

.PHONY: all rebuild clean

all: rebuild

rebuild: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

$(OBJS): touch

.PHONY: touch
touch:
	touch $(SRCS)