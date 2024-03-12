CXX = g++
CXXFLAGS = -g -Wall -Wextra

# List of source files
SRCS_CPP = main.cpp globals.cpp functions.cpp

# Generate object file names from source files
OBJS_CPP = $(SRCS_CPP:.cpp=.o)

# Name of the final executable
TARGET = program

# Additional header files
INCLUDES = -I.

.PHONY: all rebuild clean

all: rebuild

rebuild: $(TARGET)

$(TARGET): $(OBJS_CPP)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS_CPP) $(TARGET)