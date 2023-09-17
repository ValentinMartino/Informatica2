#include<stdio.h>
#include<stdlib.h>

struct nodo
{
int num;
struct nodo *ptrSig;
};

typedef struct nodo Nodo;
typedef Nodo *lista;

void ingresar(lista * , lista *);
void eliminar(lista *, lista *);
void mostrar(lista );

int main()
{
lista ptrInicial = NULL;
lista ptrFinal = NULL;
int opcion;

do
{
	printf("\n1)para ingresar\n2)para eliminar\n3)para salir\n");
	scanf("%d", &opcion);
	switch(opcion)
	{
		case 1: ingresar(&ptrInicial, &ptrFinal);
			mostrar(ptrInicial);
			break;
		case 2: eliminar(&ptrInicial, &ptrFinal);
			mostrar(ptrInicial);
			break;
		default:printf("\n");	
	
	}

}while(opcion != 3);

return 0;
}


void ingresar(lista *ptrS, lista *ptrF )
{
lista ptrActual;
lista ptrNuevo;
lista ptrFinal;
int dato;

printf("\ningrese el dato:\n");
scanf("%i",&dato);

ptrNuevo = malloc(sizeof(lista));//se crea espacio para el nodo
ptrActual = *ptrS;
ptrFinal = *ptrF;

if(ptrNuevo != NULL)//si se pudo crear el espacio entra
{
	ptrNuevo->num = dato;
	ptrNuevo->ptrSig = NULL;
	
	if(ptrActual != NULL)
	{
		ptrFinal->ptrSig = ptrNuevo;
		*ptrF = ptrNuevo;	
	}
	else
	{
		*ptrS = ptrNuevo;
		*ptrF = ptrNuevo;
	}
}
else//por si no hay espacio en el sistema
{
	printf("\n error \n");
}
}
void mostrar(lista ptrS)
{
lista ptrActual;
lista ptrAnterior;

ptrActual = ptrS;
ptrAnterior = NULL;

if(ptrActual != NULL)
{
	while(ptrActual != NULL )
	{
		printf("%i -->", ptrActual->num);
		ptrAnterior = ptrActual;
		ptrActual = ptrAnterior->ptrSig; 
	}
	printf("NULL");
}	
else
{
 printf("\nno hay ningun dato \n");	
}		

}

void eliminar(lista *ptrS, lista *ptrF)
{
lista ptrActual;
ptrActual = *ptrS;

if(ptrActual != NULL)
{
	if(ptrActual->ptrSig != NULL)
	{
		*ptrS = ptrActual->ptrSig;
		free(ptrActual);
	}
	else
	{
		*ptrF = NULL;
		*ptrS = ptrActual->ptrSig;
		free(ptrActual);
		
	}
}
else
{
	printf("\n");
}
}



