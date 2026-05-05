CXX = g++

DEBUG ?= 1

ifeq ($(DEBUG),1)
   OPTFLAGS = -g
else
   OPTFLAGS = -O3
endif

ifeq ($(OS),Windows_NT)
CPPDEFINES = -DPROJECTCODEDLL_EXPORTS
TARGET = ../bin/libProjectCode.dll
else
CPPDEFINES =
TARGET = ../bin/libProjectCode.so
endif

CFLAGS = -I. -I../include/ProjectCode -std=c++20 -Wall -Werror -fPIC $(OPTFLAGS) $(CPPDEFINES)

# Current directory setup (FIXED)
SOURCES = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp, ../Output/%.o, $(SOURCES))

# Default target
all: directories $(TARGET)

# Create needed directories
directories:
	mkdir -p ../Output
	mkdir -p ../bin

# Compile .cpp → .o
../Output/%.o: %.cpp
	$(CXX) -c $< -o $@ $(CFLAGS)

# Link shared library
$(TARGET): $(OBJECTS)
	$(CXX) -shared -o $(TARGET) $(OBJECTS)

# Clean build
clean:
	rm -rf ../Output
	rm -rf ../bin/libProjectCode.so
	rm -rf ../bin/libProjectCode.dll
