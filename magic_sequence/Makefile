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

all: magic_sequence magic_sequence_with_prop

magic_sequence: $(OBJDIR)/magic_sequence.o
	$(CC) -o $(BINDIR)/magic_sequence $(GECODE_LIB_LOCATION) $(OBJDIR)/magic_sequence.o $(GECODEFLAGS)

magic_sequence_with_prop: $(OBJDIR)/magic_sequence_with_prop.o
	$(CC) -o $(BINDIR)/magic_sequence_with_prop $(GECODE_LIB_LOCATION) $(OBJDIR)/magic_sequence_with_prop.o $(GECODEFLAGS)

$(OBJDIR)/magic_sequence.o: $(SRCDIR)/magic_sequence.cpp
	$(CC) $(CFLAGS) $(SRCDIR)/magic_sequence.cpp -o $(OBJDIR)/magic_sequence.o

$(OBJDIR)/magic_sequence_with_prop.o: $(SRCDIR)/magic_sequence_with_prop.cpp
	$(CC) $(CFLAGS) $(SRCDIR)/magic_sequence_with_prop.cpp -o $(OBJDIR)/magic_sequence_with_prop.o

.PHONY: clean

clean:
	rm -f obj/* bin/*