#include<stdio.h>
#include<stdlib.h>

struct nodo
{
int num;
struct nodo *ptrSig;
};

typedef struct nodo Nodo;
typedef Nodo *pila;

void ingresar(pila *);//funcion para ingresar valores
void mostrar(pila );//funcion para mostrar la pila
void eliminar(pila *);//funcion para eliminar el primer elemento de la pila

int main()
{
pila ptrInicial = NULL;
int opcion;

do
{
	printf("\n1)para ingresar\n2)para eliminar\n3)para salir\n");
	scanf("%d", &opcion);
	switch(opcion)
	{
		case 1: ingresar(&ptrInicial);
			mostrar(ptrInicial);
			break;
		case 2: eliminar(&ptrInicial);
			mostrar(ptrInicial);
			break;
		default:printf("\n");	
	
	}

}while(opcion != 3);

return 0;
}

void ingresar(pila *ptrS)
{

pila ptrNuevo;
int dato;

printf("\ningrese el valor que desee:\n ");
scanf("%d", &dato);

ptrNuevo = malloc(sizeof(pila));
if(ptrNuevo != NULL)
{
	ptrNuevo->num = dato;
	ptrNuevo->ptrSig = NULL;
	
	ptrNuevo->ptrSig = *ptrS;
	*ptrS  = ptrNuevo;
}
else
{	
	printf("\nno hay espacio \n");
}

}
	



void mostrar(pila ptrS)
{

pila ptrActual;
pila ptrAnterior;

ptrActual = ptrS;
ptrAnterior = NULL;

if(ptrActual != NULL)
{	
	while(ptrActual != NULL )
	{
		printf(" %d --", ptrActual->num);
		ptrAnterior = ptrActual;
		ptrActual = ptrAnterior->ptrSig;

	}	 
	printf(" NULL\n ");
}
else 
{
	printf("\nno hay ningun dato ingresado \n");
}

}

void eliminar(pila *ptrS)
{
pila ptrActual;

ptrActual = *ptrS;

if(ptrActual != NULL)
{
	*ptrS = ptrActual->ptrSig;
	free(ptrActual);

}
else
	printf("\nno hay ningun dato ingresado\n");

}













