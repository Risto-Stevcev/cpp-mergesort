CC = clang++
CXX = clang++

CFLAGS = -g -Wall -O3 $(shell pkg-config --cflags cppunit)
LDFLAGS = -g -Wall $(shell pkg-config --libs cppunit)

.PHONY:
default: Main

.PHONY:
test: TestMergeSort

Main: Main.o MergeSort.o

TestMergeSort: TestMergeSort.o MergeSort.o

MergeSort.o: MergeSort.h

.PHONY:
all: clean default test

.PHONY:
clean:
	rm -f *.o *.h.gch *.*~ a.out Main TestMergeSort
