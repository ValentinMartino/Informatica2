#include<stdio.h>
#include<stdlib.h>
#include "funciones.h"

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

void ingresar_lista(ptrNodo *ptrS)
{
ptrNodo ptrNuevo;
ptrNodo ptrActual;
ptrNodo ptrAnterior;
int dato;

printf("\ningrese el valor qu desee\n");
scanf("%d",&dato);

ptrNuevo = (ptrNodo)malloc(sizeof(NODO));

if(ptrNuevo != NULL)
{
	ptrNuevo->num = dato;
	ptrNuevo->ptrSig = NULL;
	ptrActual = *ptrS;
	ptrAnterior = NULL;
	
	if(ptrActual != NULL)
	{
		while(ptrActual != NULL && dato > ptrActual->num)
		{
			ptrAnterior = ptrActual;
			ptrActual = ptrAnterior->ptrSig;
		}
		if(ptrAnterior != NULL)
		{
			ptrNuevo->ptrSig = ptrAnterior->ptrSig;
			ptrAnterior->ptrSig = ptrNuevo;
		}
		else
		{
			ptrNuevo->ptrSig = *ptrS;
			*ptrS = ptrNuevo;
		}
		
	}
	else
	{
		ptrNuevo->ptrSig = *ptrS;
		*ptrS = ptrNuevo;
	}


}




else
{
	printf("\nerror\n");
}
}

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

void ingresa_pila(ptrNodo *ptrS)
{
ptrNodo ptrNuevo;
int dato;

printf("\ningrese le dato que desee\n");
scanf("%d",&dato);

ptrNuevo = (ptrNodo)malloc(sizeof(NODO));

if(ptrNuevo != NULL)
{
	ptrNuevo->num = dato;
	ptrNuevo->ptrSig = *ptrS;
	*ptrS = ptrNuevo;
}
else
{
	printf("\nerror\n");
}
}

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

void ingresar_cola(ptrNodo *ptrS, ptrNodo *ptrF )
{
ptrNodo ptrActual;
ptrNodo ptrNuevo;
ptrNodo ptrFinal;
int dato;

printf("\ningrese el dato:\n");
scanf("%i",&dato);

ptrNuevo = (ptrNodo)malloc(sizeof(NODO));//se crea espacio para el nodo
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

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

void mostrar(ptrNodo ptrS)
{
ptrNodo ptrActual;
ptrNodo ptrAnterior;

ptrActual = ptrS;
ptrAnterior = NULL;

if(ptrActual != NULL)
{
	while(ptrActual != NULL)
	{
		printf(" %d-->",ptrActual->num);
		ptrAnterior = ptrActual;
		ptrActual = ptrAnterior->ptrSig;
	}
	printf(" NULL");

}
else
{
	printf("\nno hay ningun dato para mostrar\n");
}
}

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

void eliminar_cola(ptrNodo *ptrS, ptrNodo *ptrF)
{
ptrNodo ptrActual;
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

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

void eliminar_pila(ptrNodo *ptrS)
{
ptrNodo ptrActual;

ptrActual = *ptrS;

if(ptrActual != NULL)
{
	*ptrS = ptrActual->ptrSig;
	free(ptrActual);

}
else
	printf("\nno hay ningun dato ingresado\n");

}

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

void eliminar_lista(ptrNodo *ptrS)
{
    ptrNodo ptrActual;
    ptrNodo ptrAnterior;

    ptrActual = *ptrS;

    if(ptrActual != NULL)
    {
        while(ptrActual != NULL)
        {
            ptrAnterior = ptrActual;
            ptrActual = ptrAnterior->ptrSig;

            free(ptrAnterior);
        }

        *ptrS = NULL;
    }
    else
    {
        printf("\nNo hay nada que borrar.\n");
    }


}

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

void eliminar_nodo(ptrNodo *ptrS)
{
    ptrNodo ptrActual;
    ptrNodo ptrAnterior;

    int dato;
    int ban = 0;

    ptrActual = *ptrS;
    ptrAnterior = NULL;


    if(ptrActual != NULL)
    {
        printf("\nIngrese el dato que quiera eliminar: ");
        scanf("%i",&dato);

        while(ptrActual != NULL && ban == 0)
        {
            if(ptrActual->num == dato && ptrAnterior != NULL) //caso en que quiera eliminar el nodo que no sea el primero
            {
                ptrAnterior->ptrSig = ptrActual->ptrSig;
                free(ptrActual);
                ban = 1;
            }

            if(ptrActual->num == dato && ptrAnterior == NULL) //caso en el que quiera eliminar el primer nodo
            {
                *ptrS = ptrActual->ptrSig;
                free(ptrActual);
                ban = 1;
            }

            ptrAnterior = ptrActual;          //estas dos lineas hace que se "corra" de nodo
            ptrActual = ptrAnterior->ptrSig;
        }

        if(ban == 0) //quiere decir que salio del while porque llego al final y no encontro el dato que el uduario queria elimiar
        {
            printf("\nNo existe el archivo que quiera eliminar.\n");
        }
    }
    else
    {
        printf("\nNo hay dato que eliminar. ");
    }

}


/*-------------------------------------------------------------------------------------------------------------------------------------------------*/



