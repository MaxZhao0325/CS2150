# Hanzhang Zhao hz9xs Makefile 10.12

CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2# Enable all warnings
DEBUG=-g
OBJECTS = wordPuzzle.o timer.o hashTable.o

wordPuzzle: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "wordPuzzle is Hot and Ready!"

.PHONY: clean
clean:
	-rm -f a.out *.o *~

timer.o: timer.cpp timer.h
hashTable.o: hashTable.cpp hashTable.h
wordPuzzle.o: wordPuzzle.cpp hashTable.h timer.h
