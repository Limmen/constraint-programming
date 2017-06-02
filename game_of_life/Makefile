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

all: life

life: $(OBJDIR)/life.o
	$(CC) -o $(BINDIR)/life $(GECODE_LIB_LOCATION) $(OBJDIR)/life.o $(GECODEFLAGS)

$(OBJDIR)/life.o: $(SRCDIR)/life.cpp
	$(CC) $(CFLAGS) $(SRCDIR)/life.cpp -o $(OBJDIR)/life.o

.PHONY: clean

clean:
	rm -f obj/* bin/*