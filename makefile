CC=gcc --std=c99 -g

all: test

main.o: main.c
	$(CC) -c main.c

arrayTools.o: arrayTools.c arrayTools.h
	$(CC) -c arrayTools.c

isValid.o: isValid.c isValid.h
	$(CC) -c isValid.c

a.out: main.o arrayTools.o isValid.o
	$(CC) main.o arrayTools.o isValid.o -o a.out

clean:
	rm -f a.out *.o
