CC=gcc

all:frequency
frequency:main.c trieTree.c
	$(CC) -Wall -g main.c trieTree.c -o frequency

main.o:main.c trieTree.h
	$(CC) -Wall -g -c main.c

clean:
	rm -f *.o *.a *.so frequency
