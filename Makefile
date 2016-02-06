CXX = g++

CXXFLAGS = -g -Wall -std=c++11

BINARIES = prog2

# tests: ${BINARIES}
# 	   ./prog2

prog2: Main.o Encode.o MinHeap.o Node.o
	${CXX} $^ -o $@

clean:
	/bin/rm -f ${BINARIES} *.o