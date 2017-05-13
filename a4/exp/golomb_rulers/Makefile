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

all: golomb_rulers

golomb_rulers: $(OBJDIR)/golomb_rulers.o
	$(CC) -o $(BINDIR)/golomb_rulers $(GECODE_LIB_LOCATION) $(OBJDIR)/golomb_rulers.o $(GECODEFLAGS)

$(OBJDIR)/golomb_rulers.o: $(SRCDIR)/golomb_rulers.cpp
	$(CC) $(CFLAGS) $(SRCDIR)/golomb_rulers.cpp -o $(OBJDIR)/golomb_rulers.o

.PHONY: clean

clean:
	rm -f obj/* bin/*