#include<stdio.h>
#include<stdlib.h>
#include "archivos.h"

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

void ingresar_paciente(ptrNodo *ptrS )
{
ptrNodo ptrNuevo;
ptrNodo ptrActual;
ptrNodo ptrAnterior;

	ptrNuevo = (ptrNodo)malloc(sizeof(NODO));

	if(ptrNuevo != NULL)
	{
		printf("\ningrese el nombre del paciente: \n");
		scanf("%s",ptrNuevo->nombre);
		getchar();
		printf("\ningrese el apellido del paciente: \n");
		fgets(ptrNuevo->apellido,50,stdin);
		printf("\ningrese la edad del paciente: \n");
		scanf("%d",&ptrNuevo->edad);
		printf("\ningrese el peso del paciente: \n");
		scanf("%f",&ptrNuevo->peso);
		printf("\ningrese la altura del paciente: \n");
		scanf("%f",&ptrNuevo->altura);
	
		crear_archivo(ptrNuevo );
		
		ptrNuevo->ptrSig = NULL;
		ptrActual = *ptrS;
		ptrAnterior = NULL;
	
		if(ptrActual != NULL)
		{
			while(ptrActual != NULL &&  ptrNuevo->nombre[0] > ptrActual->nombre[0])
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

void mostrar(ptrNodo ptrS)
{
ptrNodo ptrActual;
ptrNodo ptrAnterior;
int i = 0;

ptrActual = ptrS;
ptrAnterior = NULL;

if(ptrActual != NULL)
{
	while(ptrActual != NULL)
	{	
		i++;
		printf(" %i)Nombre: %s ",i, ptrActual->nombre);
		ptrAnterior = ptrActual;
		ptrActual = ptrAnterior->ptrSig;
	}
	

}
else
{
	printf("\nno hay ningun paciente para mostrar\n");
}
}

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

void eliminar_paciente(ptrNodo *ptrS)
{
    ptrNodo ptrActual;
    ptrNodo ptrAnterior;
    char paciente[50];

    int ban = 0;

    ptrActual = *ptrS;
    ptrAnterior = NULL;


    if(ptrActual != NULL)
    {
        printf("\nIngrese solo el nombre del paciente que desea eliminar: ");
        scanf("%s",paciente);
        remove("paciente");

        while(ptrActual != NULL && ban == 0)
        {
            if(ptrActual->nombre == paciente && ptrAnterior != NULL) //caso en que quiera eliminar el nodo que no sea el primero
            {
                ptrAnterior->ptrSig = ptrActual->ptrSig;
                free(ptrActual);
                ban = 1;
            }

            if(ptrActual->nombre == paciente && ptrAnterior == NULL) //caso en el que quiera eliminar el primer nodo
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

void crear_archivo(ptrNodo ptrNuevo)
{
FILE *archivo;	
	archivo = fopen(ptrNuevo->nombre,"w");
	if(archivo == NULL)
	{
		printf("\n no se pudo crear el archivo \n");
	}
	else
	{
		printf("\nEl archivo fue creado con exito\n");
		fprintf(archivo,"Datos del paciente.\n\n");
        	fprintf(archivo,"\nNombre y apellido: %s %s", ptrNuevo->nombre, ptrNuevo->apellido);
        	fprintf(archivo,"\nPeso: %f", ptrNuevo->peso );
        	fprintf(archivo,"\nAltura: %f", ptrNuevo->altura);
        	fprintf(archivo,"\nEdad: %d", ptrNuevo->edad);
	}


fclose(archivo);
}



