# List of source files
SRCS_CPP = ../../src/main.cpp ../../src/globals.cpp ../../src/functions_unix.cpp ../../src/functions_win.cpp

# List of object files
OBJS = $(patsubst ../../src/%.cpp,%.o,$(SRCS_CPP))

# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -g -Wall -Wextra

# Target for building the program
program: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o program

# Rule to build object files
%.o: ../../src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) program
