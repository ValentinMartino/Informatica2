CC = gcc
CFLAGS=-Wall

vinedo: main.o funciones.o funciones_binarias.o
	gcc -o hola main.o funciones.o funciones_binarias.o


main.o: main.c funciones.h funciones_binarias.h
	gcc -c main.c

funciones.o: funciones.c funciones.h
	gcc -c funciones.c
	
funciones_binarias.o: funciones_binarias.c funciones_binarias.h
	gcc -c funciones_binarias.c	
