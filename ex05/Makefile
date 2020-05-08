# Makefile for OPS exercise 2
# Use tabs for indentation, not spaces!

all: printversion getsignal sendsignal

# Link object files and create a binary executable:
getsignal: getsignal.o 
	gcc -Wall -o getsignal getsignal.o

sendsignal: sendsignal.o 
	gcc -Wall -o sendsignal sendsignal.o

# Compile C-files and create object files (.o).
# The option -c ensures no linking takes place:
getsignal.o: getsignal.c
	gcc -c -Wall getsignal.c

sendsignal.o: sendsignal.c
	gcc -c -Wall sendsignal.c

clean:
	rm -f *.o

cleanall: clean
	rm -f getsignal sendsignal

printversion:
	gcc --version | grep gcc
