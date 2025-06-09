# Makefile for GameEngine with headers in src/

CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -I./src
LDFLAGS :=

SRC_DIR := src
OBJ_DIR := build
BIN_DIR := bin
LIB_NAME := libgameengine.a
TARGET := $(BIN_DIR)/$(LIB_NAME)

SRCS := $(shell find $(SRC_DIR) -name '*.cpp')
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean
