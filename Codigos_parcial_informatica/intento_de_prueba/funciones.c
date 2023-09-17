#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "funciones.h"



/*Funcion 1*/

void insertar_vaca(ptrNodo *ptrS)
{	
	ptrNodo ptrActual;
	ptrNodo ptrAnterior;
	ptrNodo ptrNuevo;
	int aux;
	
	FILE *archivo;
				
	ptrNuevo = (ptrNodo)malloc(sizeof (NODO)); /* crea un nodo */

	if(ptrNuevo != NULL)     /* hay espacio disponible */
	{
		do
		{
			printf("ingrese el numero de la vaca: ");	
			scanf("%d",&aux);
			if(encontrar_vaca(*ptrS, aux) == 1)
			{
				printf("\nel numero de vaca ya esta utilizado, intente con otro\n");
			}
		}while(encontrar_vaca(*ptrS, aux) == 1);
		
		ptrNuevo->vaca = aux;
		getchar();
		printf("\nIngrese el nombre del propietario: ");
		fgets(ptrNuevo->propietario, 50, stdin);
		
		printf("\nIngrese el lugar de nacimiento: ");
		fgets(ptrNuevo->lugar_nacimiento, 50, stdin);
				
		printf("\nIngrese la raza de la vaca: ");
		fgets(ptrNuevo->raza, 50, stdin);
		
		printf("\nIngrese el lugar de faena: ");
		fgets(ptrNuevo->lugar_faena, 50, stdin);		
		
		printf("\nIngrese el dia de nacimiento: ");
		scanf("%i", & ptrNuevo->fecha_nacimiento[0]);
		
		printf("\nIngrese el mes de nacimiento: ");
		scanf("%i", & ptrNuevo->fecha_nacimiento[1]);
		
		printf("\nIngrese el año de nacimiento: ");
		scanf("%i", & ptrNuevo->fecha_nacimiento[2]);
		
		ptrNuevo->ptrSig = NULL; /* el nuevo nodo apunta a NULL por si es el utlimo o por si es el unico */
		
		/*Se llama a la funcion que crea el archivo con los datos de la vaca ya ingresados*/
		int comparacion = insertar_archivo(archivo, ptrNuevo);
		if(comparacion == 0)
		{
			printf("\nSe ha creado correctamente el archivo con la vaca.\n");
		}
		else
		{
			printf("\nERROR al crear el archivo.\n");
		}
			
		ptrAnterior = NULL;
		ptrActual = *ptrS;      /* hace que el ptr actual sea el que pasaron por la funcion */
		
		
		while(ptrActual != NULL && ptrNuevo->vaca > ptrActual->vaca)  /* ordena los pacientes segun el nombre */
		{
			ptrAnterior = ptrActual;
			ptrActual = ptrAnterior->ptrSig;
		}

		if(ptrAnterior == NULL) /* si es el primer paciente*/
		{
			ptrNuevo->ptrSig = ptrActual;
			*ptrS = ptrNuevo;
			
			/*ptrNuevo->ptrSig = *ptrS;
			*ptrS = ptrNuevo;*/
		}
		else
		{
			ptrAnterior->ptrSig = ptrNuevo;
			ptrNuevo->ptrSig = ptrActual;		
		}	
		
	}
	else
	{
		printf("\nNo se pudo crear espacio para la vaca. \n" );
	}

}

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/


/*Funcion 2*/

int insertar_archivo(FILE *archivo, ptrNodo ptrS)
{
	char cad_n[5];
	char nombre_archivo[10] = "vaca";
	sprintf(cad_n,"%i",ptrS->vaca);
	strcat(nombre_archivo,cad_n);
	
	
	archivo = fopen(nombre_archivo, "w");
		
	if(archivo == NULL)
	{
		printf("\nNo se pudo abrir el archivo.\n");
		return 1;
	}
	else
	{
		fprintf(archivo,"Datos de la vaca.\n\n");
		fprintf(archivo,"\nvaca numero:  %i", ptrS->vaca);
		fprintf(archivo,"\npropietario: %s",ptrS->propietario);
		fprintf(archivo,"\nlugar de nacimiento: %s", ptrS->lugar_nacimiento);
		fprintf(archivo,"\nFecha de nacimiento: %i/%i/%i", ptrS->fecha_nacimiento[0], ptrS->fecha_nacimiento[1], ptrS->fecha_nacimiento[2]);
		fprintf(archivo,"\nRaza: %s", ptrS->raza);
		fprintf(archivo,"\nlugar de faena: %s", ptrS->lugar_faena);
		
					
		fclose(archivo);
		return 0;		
	}
}

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

/*Funcion 3*/

void mostrar_vaca(ptrNodo ptrS)
{
	ptrNodo ptrActual;
	ptrNodo ptrAnterior;
	int aux;
	
	ptrActual = ptrS;
	ptrAnterior = NULL;
	
	printf("\nSe muestran la lista de vacas");
		
	putchar('\n');
	
	
	if(ptrActual != NULL) /*si hay por lo menos un nodo que mostrar*/
	{
		while(ptrActual != NULL) /*mientras que el ptrActual no llegue al final se itera el while*/
		{
			
			printf("\n-vaca numero: %i ",ptrActual->vaca);
			
			ptrAnterior = ptrActual;		/*estas dos lineas recorren todos los nodos hasta el final*/
			ptrActual = ptrAnterior->ptrSig;
			
		}
		printf("\n");
		do
		{
			printf("\ningrese el numero de la vaca que desea ver\n");
			scanf("%d",&aux);
			if(encontrar_vaca(ptrS, aux) == 0)
			{
				printf("\nla vaca no se encuentra, intente con otro numero\n");
			}
		}while(encontrar_vaca(ptrS, aux) == 0);
		
		ptrActual = ptrS;	//esto hace que se vuelva a recorrer la lista desde el principio
		ptrAnterior = NULL;
		
		while(ptrActual != NULL)
		{
			if(aux == ptrActual->vaca)
			{
				printf("Datos de la vaca.\n\n");
				printf("\nvaca numero:  %i", ptrActual->vaca);
				printf("\npropietario: %s",ptrActual->propietario);
				printf("\nlugar de nacimiento: %s", ptrActual->lugar_nacimiento);
				printf("\nFecha de nacimiento: %i/%i/%i", ptrActual->fecha_nacimiento[0], ptrActual->fecha_nacimiento[1],
				ptrActual->fecha_nacimiento[2]);
				printf("\nRaza: %s", ptrActual->raza);
				printf("\nlugar de faena: %s", ptrActual->lugar_faena);
			
			}
			
			ptrAnterior = ptrActual;          //estas dos lineas hace que se "corra" de nodo
			ptrActual = ptrAnterior->ptrSig;
		}
				
	}
	else
	{
		printf("\nNo hay nada que mostrar en la lista.\n");
	}
	
	
}

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

/*Funcion 4*/

void eliminar_vaca(ptrNodo *ptrS)
{
	ptrNodo ptrActual;
	ptrNodo ptrAnterior;

	int num;
	int ban = 0;	

	ptrActual = *ptrS;
	ptrAnterior = NULL;
	

	if(ptrActual != NULL)
	{
		printf("\nIngrese el numero de la vaca que quiera eliminar: ");
		scanf("%i", &num);
		getchar(); /*para el \n que queda en el buffer cuando apreta enter*/
	
		while(ptrActual != NULL && ban == 0)
		{
			if(ptrActual->vaca == num && ptrAnterior != NULL) //caso en que quiera eliminar el nodo que no sea el primero
			{
				ptrAnterior->ptrSig = ptrActual->ptrSig;       					 
				free(ptrActual);				
				ban = 1;
			}
			
			if(ptrActual->vaca == num && ptrAnterior == NULL) //caso en el que quiera eliminar el primer nodo
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
			printf("\nNo existe la vaca que quiera eliminar.\n");
		}
	}
	else
	{
		printf("\nNo hay niguna vaca que eliminar. ");
	}

}

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

int encontrar_vaca(ptrNodo ptrS, int numero_vaca)	//lafuncion retorna un 1 si encuentra a la vaca y 0 si no la encuentra
{
	ptrNodo ptrActual = ptrS;
	ptrNodo ptrAnterior;
	
	while(ptrActual != NULL)
	{
		if(numero_vaca == ptrActual->vaca)
		{
			return 1;                  
		}
		ptrAnterior = ptrActual;          //estas dos lineas hace que se "corra" de nodo
		ptrActual = ptrAnterior->ptrSig;
	}

	return 0;
}

