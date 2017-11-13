CC=gcc --std=c99 -g

all: test

main.o: main.c
	$(CC) -c main.c

arrayTools.o: arrayTools.c arrayTools.h
	$(CC) -c arrayTools.c

isValid.o: isValid.c isValid.h
	$(CC) -c isValid.c

iScan.o: iScan.c iScan.h
		$(CC) -c iScan.c

test: main.o arrayTools.o isValid.o iScan.o
	$(CC) main.o arrayTools.o isValid.o iScan.o -o test

clean:
	rm -f test *.o
