CC=gcc
LD=gcc
CFLAGS= -std=c99

reverse: reverse.o
	$(LD) -o reverse reverse.o

reverse.o: reverse.c
	$(CC) -o reverse.o $(CFLAGS) -c reverse.c

clean:
	rm *.o
	rm reverse
