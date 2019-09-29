all : list.o hash.o bitmap.o main.o testlib
CC = gcc
CFLAGS = -W

main.o : 
	$(CC) $(CFLAGS) -c main.c -o $@

list.o : list.h
	$(CC) $(CFLAGS) -c list.c -o $@

hash.o : hash.h
	$(CC) $(CFLAGS) -c hash.c -o $@

bitmap.o : bitmap.h limits.h round.h stdio.c
	$(CC) $(CFLAGS) -c bitmap.c -o $@

testlib : list.o main.o
	$(CC) $(CFLAGS) list.o main.o -o testlib

clean :
	rm *.o testlib

