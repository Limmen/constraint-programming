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

all: main

main: $(OBJDIR)/main.o
	$(CC) -o $(BINDIR)/send_more_money_gist_2 $(GECODE_LIB_LOCATION) $(OBJDIR)/main.o $(GECODEFLAGS)

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	$(CC) $(CFLAGS) $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o

.PHONY: clean

clean:
	rm -f obj/* bin/*