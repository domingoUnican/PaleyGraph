
##### Configurable options:

## Compiler:
CC=gcc
#CC=cc

## Compiler flags:

# GCC:  (also -march=pentium etc, for machine-dependent optimizing)
CFLAGS=-Wall -O3 -fomit-frame-pointer -funroll-loops

# GCC w/ debugging:
#CFLAGS=-Wall -g -DINLINE=

# Compaq C / Digital C:
#CFLAGS=-arch=host -fast

# SunOS:
#CFLAGS=-fast

## Program options:

# Enable long options for cl (eg. "cl --help"), comment out to disable.
# Requires getopt_long(3)  (a GNU extension)
LONGOPTS = -DENABLE_LONG_OPTIONS


##### End of configurable options


all: Paley CoPaley test_paley



Paley: Paley.o cliquer.o graph.o reorder.o
	$(CC) $(LDFLAGS) -o $@ Paley.o cliquer.o graph.o reorder.o

CoPaley: CoPaley.o cliquer.o graph.o reorder.o
	$(CC) $(LDFLAGS) -o $@ CoPaley.o cliquer.o graph.o reorder.o

test_paley: test_paley.o cliquer.o graph.o reorder.o
	$(CC) $(LDFLAGS) -o $@ test_paley.o cliquer.o graph.o reorder.o

cl.o test_paley.o cliquer.o graph.o reorder.o: cliquer.h set.h graph.h misc.h reorder.h Makefile cliquerconf.h

Paley.o: Paley.c
	$(CC) $(CFLAGS) $(LONGOPTS) -o $@ -c $<

CoPaley.o: CoPaley.c
	$(CC) $(CFLAGS) $(LONGOPTS) -o $@ -c $<


test_paley.o: test_paley.c
	$(CC) $(CFLAGS) $(LONGOPTS) -o $@ -c $<



clean:
	rm -f *.o *~ cl testcases

backup:
	mkdir "`date "+backup-%Y-%m-%d-%H-%M"`" 2>/dev/null || true
	cp * "`date "+backup-%Y-%m-%d-%H-%M"`"  2>/dev/null || true

