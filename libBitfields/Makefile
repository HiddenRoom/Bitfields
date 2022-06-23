CC=gcc

CFLAGS=-Wall -g -lm

all: librarytest 

libBitfields.o: libBitfields.c bitfields.h 
	$(CC) $(CFLAGS) -c libBitfields.c

librarytest: librarytest.c libBitfields.o
	$(CC) $(CFLAGS) -o $@ $^
clean:
	shred -u -z -n5 libBitfields.o && shred -u -z -n5 librarytest 
