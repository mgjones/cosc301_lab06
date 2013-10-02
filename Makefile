CC=gcc
CFLAGS=-g -Wall

all: broken 

broken: broken.o
	$(CC) $(CFLAGS) -o $@ broken.o

.PHONY: clean
clean:
	rm -f *.o broken

.c.o:
	$(CC) -c $(CFLAGS) $<
