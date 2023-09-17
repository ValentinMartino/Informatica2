CC = gcc
CFLAGS=-Wall

vacas: main.o funciones.o
	gcc -o vacas main.o funciones.o


main.o: main.c funciones.h
	gcc -c main.c

funciones.o: funciones.c funciones.h
	gcc -c funciones.c
