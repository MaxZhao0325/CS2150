# Hanzhang Zhao hz9xs Makefile 10.3

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2# Enable all warnings
DEBUG=-g
OBJECTS = TreeCalc.o TreeCalcTest.o TreeNode.o

TreeCalcTest: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "TreeCalcTest is Hot and Ready!"

.PHONY: clean
clean:
	-rm -f a.out *.o *~

TreeCalc.o: TreeCalc.cpp TreeCalc.h TreeNode.h
TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h TreeNode.h
TreeNode.o: TreeNode.cpp TreeNode.h

