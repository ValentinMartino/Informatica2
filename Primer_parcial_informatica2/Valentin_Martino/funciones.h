#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct
{
	int fecha_cosecha[3];
	int peso_cosechado;
}Datos1;

typedef struct 
{
	int temperatura_ambiente;
	int Humedad_ambiente;
	int Temperatura_suelo;
	int Humedad_suelo;
	int Radiacion_solar;
	int Hora_UNIX;
	
}Datos2;


struct vinedo
{
int identificador_surco[2];
char variedad_uva[30];
int humedad_max;
int humedad_min;
struct vinedo *ptrSig;

Datos1 datos1;
Datos2 datos2;

};

typedef struct vinedo VINO;
typedef VINO *ptrNodo;



void agregar_surco(ptrNodo * );
void modificar_surco_1(ptrNodo *);
void modificar_surco_2(ptrNodo *);
void eliminar_surco(ptrNodo *);




#endif
