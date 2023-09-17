#ifndef FUNCIONES_H
#define FUNCIONES_H

struct nodo
{
int vaca;
char propietario[50];
char lugar_nacimiento[50]; 
int fecha_nacimiento[3];
char raza[50];
char lugar_faena[50];
char fecha_faena[3];

int identificacion;
float latitud;
float longuitud;
float hora_unix;

float temperatura;
int humedad;
float temperatura_corporal;
int ritmo_cardiaco;
struct nodo *ptrSig;
};

typedef struct nodo NODO;
typedef NODO *ptrNodo;

void insertar_vaca(ptrNodo *);
int insertar_archivo(FILE *, ptrNodo );
void mostrar_vaca(ptrNodo );
void eliminar_vaca(ptrNodo *);
int encontrar_vaca(ptrNodo , int );



#endif
