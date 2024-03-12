CC = gcc
CXX = g++
CFLAGS = -g -Wall -Wextra
CXXFLAGS = -g -Wall -Wextra

# List of source files
SRCS_C = main.c
SRCS_CPP = main.cpp

# Generate object file names from source files
OBJS_C = $(SRCS_C:.c=.o)
OBJS_CPP = $(SRCS_CPP:.cpp=.o)

# Name of the final executable
TARGET = program

# Additional header files
INCLUDES = -I.

.PHONY: all rebuild clean

all: rebuild

rebuild: $(TARGET)

$(TARGET): $(OBJS_C) $(OBJS_CPP)
	$(CXX) $(CFLAGS) $(CXXFLAGS) $(INCLUDES) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS_C) $(OBJS_CPP) $(TARGET)

$(OBJS_C) $(OBJS_CPP): touch

.PHONY: touch
touch:
	touch $(SRCS_C) $(SRCS_CPP)
