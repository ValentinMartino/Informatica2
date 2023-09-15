#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "funciones.h"

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

void agregar_surco(ptrNodo *ptrS)
{
ptrNodo ptrNuevo;
ptrNodo ptrActual;
ptrNodo ptrAnterior;
int dato;
int variedad_uva;
FILE *archivo;

ptrNuevo = (ptrNodo)malloc(sizeof(VINO));

if(ptrNuevo != NULL)
{
	ptrNuevo->ptrSig = NULL;
	ptrActual = *ptrS;
	ptrAnterior = NULL;
	
	if (establecimiento() == '0')// si nos devuelve un letra 0 significa que es de cafayate por lo tanto centena para la locaciones; decenas y unidades para el tipo de surco. si la centena es 0 es cafayate y si es 1 es valle del uco;
	{
		ptrNuevo->identificador_surco[0] = 0;
	}
	else
	{
		ptrNuevo->identificador_surco[0] = 1;
	}
	
	ptrNuevo->identificador_surco[1] = surco();// la funcion surco nos pasa el valor del surco lo cual es asignado a la variable identificador surco
	
	variedad_uva = byte1();//la funcion nos devuelve que tipo de uva es
	switch(variedad_uva)
	{
		case 1:
			ptrNuevo->variedad_uva = "malbec"; break;
			ptrNuevo->humedad_max = byte2();//humedad maxima
			ptrNuevo->humedad_min = byte3();//humedad minima
		case 2:
			ptrNuevo->variedad_uva = "Merlot"; break;
			ptrNuevo->humedad_max = byte2();//humedad maxima
			ptrNuevo->humedad_min = byte3();//humedad minima
		case 4:
			ptrNuevo->variedad_uva = "Cabernet Sauvignon"; break;
			ptrNuevo->humedad_max = byte2();//humedad maxima
			ptrNuevo->humedad_min = byte3();//humedad minima
		case 8:
			ptrNuevo->variedad_uva = "Pinot Negro"; break;
			ptrNuevo->humedad_max = byte2();//humedad maxima
			ptrNuevo->humedad_min = byte3();//humedad minima
	
		default: printf("\n error \n");
	}
	
	
	
	ptrNuevo->datos2->hora_UNIX = hora_unix();//devuelve la hora unix
	
	
	if(ptrActual != NULL)
	{
		while(ptrActual != NULL && ptrNuevo->identificador_surco > ptrActual->identificador_surco)
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


void modificar_surco_1(ptrNodo *ptrS)
{
ptrNodo ptrActual;
ptrNodo ptrAnterior;
FILE *archivo;


ptrActual = *ptrS;
ptrAnterior = NULL;

if(ptrActual != NULL)
{
	while(ptrActual != NULL )
	{
		if(ptrActual->identificador_surco[0] == establecimiento())
		{
			if(ptrActual->identificador_surco[1] == surco())
			{
				ptrNuevo->datos2->temperatura_ambiente = byte1();//toma el primer byte del mensaje y devuelve la temperatura
				ptrNuevo->datos2->humedad_ambiente =  byte2();//toma el segundo byte del mensaje y devuelve la humedad
				ptrNuevo->datos2->radiacion_solar = byte3();//toma el tercer byte del mensaje y devuelve la radiacion solar	
				ptrNuevo->datos2->hora_UNIX = hora_unix();//devuelve la hora unix
		
			}
		
		}
		
		ptrAnterior = ptrActual; //recorre los nodos
		ptrActual = ptrAnterior->ptrSig;
	}
	printf(" NULL");

}
else
{
	printf("\nerror\n");
}
}


/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

void modificar_surco_2(ptrNodo *ptrS)
{
ptrNodo ptrActual;
ptrNodo ptrAnterior;
FILE *archivo;
uint8_t control = 0;
int dato = 0;//este dato se pasa a la funcion para avisarle de la alerta

ptrActual = *ptrS;
ptrAnterior = NULL;

if(ptrActual != NULL)
{
	while(ptrActual != NULL )
	{
		if(ptrActual->identificador_surco[0] == establecimiento())
		{
			if(ptrActual->identificador_surco[1] == surco())
			{
				ptrnuevo->datos2->temperatura_suelo = byte2();//toma el segundo byte del mensaje y devuelve la temperatura del suelo
				ptrNuevo->datos3->humedad_suelo = byte3();//toma el tercer byte del mensaje y devuelve la humedad del suelo
				if(ptrNuevo->datos2->humedad_suelo > ptrNuevo->humedad_max)//compara el nivel de humedad maximo y minimo con el obtenido por los sensores
				{
					control = 1;
					dato = 1;
					printf("\nel nivel de humedad es muy alta\n");
				}
				if(ptrNuevo->datos2->humedad_suelo < ptrNuevo->humedad_min)
				{
					control = 2;
					dato = 2;
					printf("\nel nivel de humedad es muy bajo\n");
				}
				
				ptrNuevo->datos2->hora_UNIX = hora_unix();//devuelve la hora unix
			}
		}
		
		ptrAnterior = ptrActual; //recorre los nodos
		ptrActual = ptrAnterior->ptrSig;
	}
	printf(" NULL");
	instertar_archivo_alerta(&archivo,ptrS,dato)

}
else
{
	printf("\nerror\n");
}
}


/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

int insertar_archivo(FILE *archivo, ptrNodo ptrS)//esta funcion ingresa los datos al archivo
{

    archivo = fopen("viñedo", "a+");

    if(archivo == NULL)
    {
        printf("\nNo se pudo abrir el archivo.\n");
        return 1;
    }
    else
    {
        fprintf(archivo,"\n");
        if(ptrS->identificador_surco[0] == 0);
        {	
        	fprintf(archivo,"cafayate");
        }
        else
        {
        	fprintf(archivo,"valle del uco");
        }
        fprintf(archivo,"\t%d",ptrS->identificador_surco[1]);
        fprintf(archivo,"\t%s", ptrS->variedad_uva);
        fprintf(archivo,"\t%i/%i/%i  %i", ptrS->fecha_cosecha[0], ptrS->fecha_cosecha[1], ptrS->fecha_cosecha[2],ptrS->hora_UNIX);
        fprintf(archivo,"\t%d", ptrS->datos2->temperatura_suelo);
        fprintf(archivo,"\t%d", ptrS->datos2->humedad_suelo);
        fprintf(archivo,"\t%d", ptrS->datos2->humedad_ambiente);
        fprintf(archivo,"\t%d", ptrS->datos2->temperatura_ambiente);
        fprintf(archivo,"\t%d", ptrS->datos2->radiacion_solar);
        fprintf(archivo,"\t -");
        

        fclose(archivo);
        return 0;
    }
}

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/


int insertar_archivo_alerta(FILE *archivo, ptrNodo ptrS,int dato)//esta funcion ingresa los datos al archivo agregando la advertencia sobre la humedad del suelo
{

    archivo = fopen("viñedo", "a+");

    if(archivo == NULL)
    {
        printf("\nNo se pudo abrir el archivo.\n");
        return 1;
    }
    else
    {
        fprintf(archivo,"\n");
        if(ptrS->identificador_surco[0] == 0);
        {	
        	fprintf(archivo,"cafayate");
        }
        else
        {
        	fprintf(archivo,"valle del uco");
        }
        fprintf(archivo,"\t%d",ptrS->identificador_surco[1]);
        fprintf(archivo,"\t%s", ptrS->variedad_uva);
        fprintf(archivo,"\t%i/%i/%i  %i", ptrS->fecha_cosecha[0], ptrS->fecha_cosecha[1], ptrS->fecha_cosecha[2],ptrS->hora_UNIX);
        fprintf(archivo,"\t%d", ptrS->datos2->temperatura_suelo);
        fprintf(archivo,"\t%d", ptrS->datos2->humedad_suelo);
        fprintf(archivo,"\t%d", ptrS->datos2->humedad_ambiente);
        fprintf(archivo,"\t%d", ptrS->datos2->temperatura_ambiente);
        fprintf(archivo,"\t%d", ptrS->datos2->radiacion_solar);
        if(dato == 0)//se analiza si la humedad es baja, alta o normal
        {
        	printf(archivo, "- ");
        }
        if(dato == 1)
        {
        	fprintf(archivo,"\tHA ");
        }
	else
	{
		fprintf(archivo,"HB ");
	}
        
        
        
        
        fclose(archivo);
        return 0;
    }
}




