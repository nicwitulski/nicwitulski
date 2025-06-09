# Makefile

# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -I./src
LDFLAGS := -lncurses

# Directories
SRC_DIR := src
OBJ_DIR := build
BIN_DIR := bin
TARGET := $(BIN_DIR)/main

# Automatically find all .cpp files and corresponding .o files
SRCS := $(shell find $(SRC_DIR) -name '*.cpp')
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Default target
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

# Compile .cpp files into .o files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Phony targets
.PHONY: all clean