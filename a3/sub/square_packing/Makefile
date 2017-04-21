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

all: square_packing

square_packing: $(OBJDIR)/square_packing.o
	$(CC) -o $(BINDIR)/square_packing $(GECODE_LIB_LOCATION) $(OBJDIR)/square_packing.o $(GECODEFLAGS)

$(OBJDIR)/square_packing.o: $(SRCDIR)/square_packing.cpp
	$(CC) $(CFLAGS) $(SRCDIR)/square_packing.cpp -o $(OBJDIR)/square_packing.o

.PHONY: clean

clean:
	rm -f obj/* bin/*