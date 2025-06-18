# Makefile for App using GameEngine with headers in src/

CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -I../GameEngine/src
LDFLAGS := ../GameEngine/bin/libgameengine.a -lncurses

# Directories
SRC_DIR := src
OBJ_DIR := build
BIN_DIR := bin
TARGET := $(BIN_DIR)/main

# Automatically find all .cpp files and corresponding .o files
SRCS := $(shell find $(SRC_DIR) -name '*.cpp')
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# === New Target: rebuild everything from both Makefiles ===
rebuild:
	@echo "Cleaning GameEngine..."
	@make -C ../GameEngine clean
	@echo "Building GameEngine..."
	@make -C ../GameEngine
	@echo "Cleaning current project..."
	@$(MAKE) clean
	@echo "Building current project..."
	@$(MAKE) all

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
.PHONY: all clean rebuild
