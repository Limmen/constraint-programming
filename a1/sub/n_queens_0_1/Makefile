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

all: queens

queens: $(OBJDIR)/queens.o
	$(CC) -o $(BINDIR)/queens $(GECODE_LIB_LOCATION) $(OBJDIR)/queens.o $(GECODEFLAGS)

$(OBJDIR)/queens.o: $(SRCDIR)/queens.cpp
	$(CC) $(CFLAGS) $(SRCDIR)/queens.cpp -o $(OBJDIR)/queens.o

.PHONY: clean

clean:
	rm -f obj/* bin/*