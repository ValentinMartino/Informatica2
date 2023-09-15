#include <stdio.h>

//LISTAS ENLASADAS 

void ingresar_lista(ptrNodo *ptrS) //esta funcion se utiliza para ingresar una nueva lista que nosotros queramos
{

//estas variables se utilizaran para movernos en las estructuras de datos
ptrNodo ptrNuevo;
ptrNodo ptrActual;
ptrNodo ptrAnterior;
int dato;

printf("\ningrese el valor qu desee\n");
scanf("%d",&dato);

ptrNuevo = (ptrNodo)malloc(sizeof(NODO));//se guarda espacio de memoria para la nueva estructura a ingresar

if(ptrNuevo != NULL)//se comprueba que se haya podido guardar memoria
{
	ptrNuevo->num = dato;//se inicializan los datos
	ptrNuevo->ptrSig = NULL;
	
	ptrActual = *ptrS;
	ptrAnterior = NULL;
	
	if(ptrActual != NULL)//se comprueba de que haya una estructura
	{
		while(ptrActual != NULL && dato > ptrActual->num)
		{
			ptrAnterior = ptrActual;//estas lineas se utilizan para movernos en las estructuras
			ptrActual = ptrAnterior->ptrSig;
		}
		if(ptrAnterior != NULL)//por si la estructura no es la ultima en ser agregada
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
	else//si la estructura que creamos es la unica
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


//-------------------------------------------------------------------------------------------------------------------------------


void ingresa_pila(ptrNodo *ptrS)//esta funcion se utiliza para ingresar una nueva estructura
{
ptrNodo ptrNuevo;
int dato;

printf("\ningrese le dato que desee\n");
scanf("%d",&dato);

ptrNuevo = (ptrNodo)malloc(sizeof(NODO));//se guarda espacio de memoria para la estructura

if(ptrNuevo != NULL)
{
	ptrNuevo->num = dato;//se inicializan todos los datos
	ptrNuevo->ptrSig = *ptrS;//se coloca en la estructura
	*ptrS = ptrNuevo;
}
else
{
	printf("\nerror\n");
}
}

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

void ingresar_cola(ptrNodo *ptrS, ptrNodo *ptrF )//esta funcion se utiliza para ingresar una nueva estructura
{
ptrNodo ptrActual;//estas variables la utilizaremos para movernos en las estructuras
ptrNodo ptrNuevo;
ptrNodo ptrFinal;
int dato;

printf("\ningrese el dato:\n");
scanf("%i",&dato);

ptrNuevo = (ptrNodo)malloc(sizeof(NODO));//se guarda espacio para la estructura
ptrActual = *ptrS;
ptrFinal = *ptrF;

if(ptrNuevo != NULL)//se revisa si se puedo guardar espacio
{
	ptrNuevo->num = dato;//se inicializan los datos
	ptrNuevo->ptrSig = NULL;
	
	if(ptrActual != NULL)
	{
		ptrFinal->ptrSig = ptrNuevo;//se acomoda la estructura al final de la cola
		*ptrF = ptrNuevo;	
	}
	else
	{
		*ptrS = ptrNuevo;
		*ptrF = ptrNuevo;
	}
}
else//si no hay espacio
{
	printf("\n error \n");
}
}

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

void mostrar(ptrNodo ptrS)//esta funcion se utiliza para mostrar todas las estructuras de datos
{
ptrNodo ptrActual;//se utilizan para movernos en las estructuras
ptrNodo ptrAnterior;

ptrActual = ptrS;
ptrAnterior = NULL;

if(ptrActual != NULL)
{
	while(ptrActual != NULL)
	{
		printf(" %d-->",ptrActual->num);//se imprimen los datos
		
		ptrAnterior = ptrActual;//nos movemos en las estructuras
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
            if(ptrActual->num == dato && ptrAnterior != NULL) //en el caso que se desee eliminar el nodo que no es primero
            {
                ptrAnterior->ptrSig = ptrActual->ptrSig;
                free(ptrActual);
                ban = 1;
            }

            if(ptrActual->num == dato && ptrAnterior == NULL) //en caso de que se quiera eliminar al primero
            {
                *ptrS = ptrActual->ptrSig;
                free(ptrActual);
                ban = 1;
            }

            ptrAnterior = ptrActual;          //estas lineas hace que podamos movernos por la estrcutura
            ptrActual = ptrAnterior->ptrSig;
        }

        if(ban == 0) //sale del while porque no esncontro el dato que se queria eliminar
        {
            printf("\nNo existe el archivo que quiera eliminar.\n");
        }
    }
    else
    {
        printf("\nNo hay estructura que eliminar. ");
    }

}


/*-------------------------------------------------------------------------------------------------------------------------------------------------*/






