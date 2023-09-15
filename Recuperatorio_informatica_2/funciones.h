#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdint.h>



struct geoloc//en esta estructura se van a encontrar todos los datos de la geolocalizacion del taxi
{
	float latitud;
	float longitud;
	char * hora_unix;
	int chofer;
	int alarma;

};

struct Taxi//en esta estructura se encuentran datos mas personales del taxi
{
	int numero_de_interno;
	char marca[30];
	char patente[10];
	char propietario[30];
	int tel_de_contacto;
	struct geoloc datos;//esta miembro es de tipo struct geoloc
	struct Taxi *ptrSig;//puntero que apunta al siguiente nodo
};

typedef struct Taxi TAXI;
typedef TAXI *ptrTaxi;



//funciones

int leer_archivo(ptrTaxi *ptrs);//esta funcion se encargara de leer los datos que son enviados por el archivo binario y de llamar a la funcion que se encargara de meterlos en la estructura de datos, ademas se llamara a la funcion que crea el archivo de texto con los datos leidos

char * horaUnix( uint8_t byteA, uint8_t byteB, uint8_t byteC, uint8_t byteD );//esta funcion nos devolvera la hora unix mientras nosotros le pasemos 4 bytes de tipo uint8_t

float Latitud_Longitud( uint8_t byteA, uint8_t byteB, uint8_t byteC, uint8_t byteD );//esta funcion nos devolver la latitud o longitud cuendo nosotros le pasemos 4 bytes de tipo uint8_t

void taxi_nuevo(int e_interno, int e_chofer, int e_alarma, float latitud, float longitud,char *hora, ptrTaxi *ptrs);//esta funcion se encargara de crear una nueva estructura de datos ingresando los datos del taxi que se le haya pasado

void archivo_taxi(ptrTaxi ptrs);//esta funcion ingresara los datos del taxi a un archivo de texto

void archivo_geolocalizacion(ptrTaxi ptrs);//esta funcion se encargara de ingresar los datos de la geolocalizacion del taxi a un archivo de texto

void agregar(ptrTaxi *ptrs,int num);//esta funcion se utiliza para que usuario puede agregar los datos que le faltan al taxi si es que el lo desea



#endif
