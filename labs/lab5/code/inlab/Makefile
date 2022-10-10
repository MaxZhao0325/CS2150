# Hanzhang Zhao hz9xs Makefile 10.4

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2# Enable all warnings
DEBUG=-g
OBJECTS = BinaryNode.o BinarySearchTree.o BSTPathTest.o

BSTPathTest: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "BSTPathTest is Hot and Ready!"

.PHONY: clean
clean:
	-rm -f a.out *.o *~

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h
BinaryNode.o: BinaryNode.cpp BinaryNode.h
BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h
