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

all: square square_mallu square_packing_with_overlap square_packing_with_overlap_and_interval

square: $(OBJDIR)/square.o
	$(CC) -o $(BINDIR)/square $(GECODE_LIB_LOCATION) $(OBJDIR)/square.o $(GECODEFLAGS)

square_mallu: $(OBJDIR)/square_mallu.o
	$(CC) -o $(BINDIR)/square_mallu $(GECODE_LIB_LOCATION) $(OBJDIR)/square_mallu.o $(GECODEFLAGS)

square_packing_with_overlap: $(OBJDIR)/square_packing_with_overlap.o
	$(CC) -o $(BINDIR)/square_packing_with_overlap $(GECODE_LIB_LOCATION) $(OBJDIR)/square_packing_with_overlap.o $(GECODEFLAGS)

square_packing_with_overlap_and_interval: $(OBJDIR)/square_packing_with_overlap_and_interval.o
	$(CC) -o $(BINDIR)/square_packing_with_overlap_and_interval $(GECODE_LIB_LOCATION) $(OBJDIR)/square_packing_with_overlap_and_interval.o $(GECODEFLAGS)

$(OBJDIR)/square_packing.o: $(SRCDIR)/square_packing.cpp
	$(CC) $(CFLAGS) $(SRCDIR)/square_packing.cpp -o $(OBJDIR)/square_packing.o

$(OBJDIR)/no-overlap.o: $(SRCDIR)/no-overlap.cpp
	$(CC) $(CFLAGS) $(SRCDIR)/no-overlap.cpp -o $(OBJDIR)/no-overlap.o

$(OBJDIR)/square_packing_with_overlap.o: $(SRCDIR)/square_packing_with_overlap.cpp
	$(CC) $(CFLAGS) $(SRCDIR)/square_packing_with_overlap.cpp -o $(OBJDIR)/square_packing_with_overlap.o

$(OBJDIR)/interval.o: $(SRCDIR)/interval.cpp
	$(CC) $(CFLAGS) $(SRCDIR)/interval.cpp -o $(OBJDIR)/interval.o

$(OBJDIR)/square_packing_with_overlap_and_interval.o: $(SRCDIR)/square_packing_with_overlap_and_interval.cpp
	$(CC) $(CFLAGS) $(SRCDIR)/square_packing_with_overlap_and_interval.cpp -o $(OBJDIR)/square_packing_with_overlap_and_interval.o

$(OBJDIR)/square.o: $(SRCDIR)/square.cpp
	$(CC) $(CFLAGS) $(SRCDIR)/square.cpp -o $(OBJDIR)/square.o

$(OBJDIR)/square_mallu.o: $(SRCDIR)/square_mallu.cpp
	$(CC) $(CFLAGS) $(SRCDIR)/square_mallu.cpp -o $(OBJDIR)/square_mallu.o

.PHONY: clean

clean:
	rm -f obj/* bin/*