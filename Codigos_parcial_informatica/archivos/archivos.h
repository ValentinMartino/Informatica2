#ifndef ARCHIVOS_H
#define ARCHIVOS_H

struct nodo
{
char nombre[50];
char apellido[50];
int edad;
float peso;
float altura;
char numero_de_paciente[4];
struct nodo *ptrSig;
};

typedef struct nodo NODO;
typedef NODO *ptrNodo;


void ingresar_paciente(ptrNodo *);
void mostrar(ptrNodo );
void eliminar_paciente(ptrNodo *);
void crear_archivo(ptrNodo ); 
 
 
 
 
 
#endif 
