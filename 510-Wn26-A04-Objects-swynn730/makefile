# Friendly Makefile for C++ assignment with auto-clean

# Compiler
CXX = clang++

# Compiler flags
CXXFLAGS = -std=c++20 -Iinclude/CppUnitLite

# All .cpp files in project root + framework .cpp files
SRCS = $(wildcard *.cpp) $(wildcard CppUnitLite/*.cpp)

# Output executable
TARGET = main

# Default target: build only
all: $(TARGET)

# Build target
$(TARGET): $(SRCS)
	@echo "🛠️  Compiling $(TARGET) from sources..."
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)
	@echo "✅ Build complete! Run it with ./$(TARGET)"

# Run target: clean, build, and execute
run: clean $(TARGET)
	@echo "▶️ Running $(TARGET)..."
	./$(TARGET)

# Clean target
clean:
	@echo "🧹 Cleaning up..."
	rm -f $(TARGET)
	@echo "✅ Clean complete"