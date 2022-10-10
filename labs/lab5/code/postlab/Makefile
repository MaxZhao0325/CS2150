# Hanzhang Zhao hz9xs Makefile 10.4

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2# Enable all warnings
DEBUG=-g
OBJECTS = AVLNode.o AVLTree.o AVLPathTest.o

AVLTest: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "AVLTest is Hot and Ready!"

.PHONY: clean
clean:
	-rm -f a.out *.o *~

AVLNode.o: AVLNode.cpp AVLNode.h
AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h
AVLTree.o: AVLTree.cpp AVLNode.h AVLTree.h
