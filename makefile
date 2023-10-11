CC = gcc
CC_FLAGS =  -g  -ansi -pedantic -W -Wall

assign1: main.o sort.o calculate.o
	$(CC) -g -o ass2 main.o  sort.o calculate.o $(CC_FLAGS)

main.o: main.c ass2.h
	$(CC) -c main.c  $(CC_FLAGS)

sort.o: sort.c sort.h
	$(CC) -c sort.c  $(CC_FLAGS)

calculate.o: calculate.c calculate.h
	$(CC) -c calculate.c  $(CC_FLAGS)