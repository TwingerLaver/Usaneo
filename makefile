# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Directories
SRC_DIR = src
BUILD_DIR = build
INCLUDE_DIR = include
RENDERING_DIR = rendering/OpenGL

# Include paths
INCLUDES = -I$(INCLUDE_DIR) -I.

# Library paths and libraries
LIB_DIR = lib
LIBS = -L$(LIB_DIR) -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lopengl32

# Source files
SOURCES = $(SRC_DIR)/main.cpp \
          $(INCLUDE_DIR)/glad.c \
          $(RENDERING_DIR)/RendererOpenGL.cpp \
          $(RENDERING_DIR)/2d/2d_camera.cpp

# Target
TARGET = $(BUILD_DIR)/usaneo.exe

# Default target
all: $(TARGET)

$(TARGET): $(SOURCES) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET) $(INCLUDES) $(LIBS)

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean target
clean:
	rm -rf $(BUILD_DIR)

# Rebuild target
rebuild: clean all

.PHONY: all clean rebuild