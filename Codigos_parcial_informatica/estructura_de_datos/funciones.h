#ifndef FUNCIONES_H
#define FUNCIONES_H

struct nodo{

int num;
struct nodo *ptrSig;

};

typedef struct nodo NODO;
typedef NODO *ptrNodo;


void ingresar_lista(ptrNodo *);
void ingresa_pila(ptrNodo *);
void ingresar_cola(ptrNodo *, ptrNodo *);
void mostrar(ptrNodo);
void eliminar_cola(ptrNodo *, ptrNodo *);
void eliminar_pila(ptrNodo *);
void eliminar_lista(ptrNodo *);
void eliminar_nodo(ptrNodo *);

#endif
