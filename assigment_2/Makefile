# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Targets
TARGET = main
OBJECTS = main.o BinarySearchTree.o

# Build the target executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Compile main.cpp to main.o
main.o: main.cpp BinarySearchTree.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

# Compile BinarySearchTree.cpp to BinarySearchTree.o
BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h
	$(CXX) $(CXXFLAGS) -c BinarySearchTree.cpp -o BinarySearchTree.o

# Clean up object files and the executable
clean:
	rm -f $(OBJECTS) $(TARGET)
