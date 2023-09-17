CC = gcc
CFLAGS=-Wall

programa: archivos_estructuras.o funciones_estructuras.o
	gcc -o programa archivos_estructuras.o funciones_estructuras.o


archivos_estructuras.o: archivos_estructuras.c archivos.h
	gcc -c archivos_estructuras.c

funciones_estructuras.o: funciones_estructuras.c archivos.h
	gcc -c funciones_estructuras.c
