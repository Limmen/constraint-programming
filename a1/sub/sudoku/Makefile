#dirs
IDIR=include
SRCDIR=src
OBJDIR=obj
LIBDIR=lib
BINDIR=bin

#Gnu C++ compiler
CC=g++
#-Wall turns on warnings. -c output an object file
CFLAGS=-c -Wall -std=c++11

#gecode
GECODEFLAGS=-lgecodeflatzinc -lgecodedriver -lgecodegist -lgecodesearch -lgecodeminimodel -lgecodeset -gecodefloat -lgecodeint -lgecodekernel -lgecodesupport
GECODE_LIB_LOCATION=-L/usr/local/lib

all: sudoku

sudoku: $(OBJDIR)/sudoku.o
	$(CC) -o $(BINDIR)/sudoku $(GECODE_LIB_LOCATION) $(OBJDIR)/sudoku.o $(GECODEFLAGS)

$(OBJDIR)/sudoku.o: $(SRCDIR)/sudoku.cpp
	$(CC) $(CFLAGS) $(SRCDIR)/sudoku.cpp -o $(OBJDIR)/sudoku.o

.PHONY: clean

clean:
	rm -f obj/* bin/*