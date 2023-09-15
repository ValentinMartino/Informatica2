#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "funciones.h"
#include <string.h>
#include <math.h>


//--------------------------------------------------------------------------------------------------------------------------------

int leer_archivo(ptrTaxi *ptrs)//esta funcion leera el archivo de texto y llamara a la funcion para que los introduzca en la estructura
{
	uint8_t inicio, chofer, alarma;// variables en donde vamos a meter los datos
	uint8_t byteA, byteB, byteC, byteD;//estas variables se utilizan para obtener la hora unix, latitud y longitud
	uint16_t interno;//para la variable del interno
	FILE *fd;//para utilizar el archivo binario
	int  e_chofer, e_alarma, e_interno;//enteros donde van a ir los valores de alarma y chofer 
	char hora[40];//esta variable guardara la hora unix
	float latitud, longitud;//estas guardan latitud y longitud
	
	fd = fopen("archivo.bin", "rb");// se abre el archivo binario en modo lectura
	if(  fd  == NULL ) 
    	{
        	printf("\nEl archivo binario no pudo abrirse.\n") ;
        	return -1;
    	}
	while(!feof( fd ) )
	{
		//leemos todos los datos del surco 
		fread(&inicio,1,1,fd); 
		if(inicio == 0xFE)//si el inicio es igual a 0xFE recien ahi empieza a leer los otros datos
		{
		
			fread(&interno,2,1,fd);
			//se leen los 4 bytes de latitud
			fread(&byteA,1,1,fd);
			fread(&byteB,1,1,fd);
			fread(&byteC,1,1,fd);
			fread(&byteD,1,1,fd);
			latitud = Latitud_Longitud(byteA, byteB, byteC, byteD);//en esta linea obtenemos la latitud
			//se leen los 4 bytes de longitud
			fread(&byteA,1,1,fd);
			fread(&byteB,1,1,fd);
			fread(&byteC,1,1,fd);
			fread(&byteD,1,1,fd);
			longitud = Latitud_Longitud(byteA, byteB, byteC, byteD);//en esta linea se obtiene la longitud
			//se leen los 4 bytes de la hora unix
			fread(&byteA,1,1,fd);
			fread(&byteB,1,1,fd);
			fread(&byteC,1,1,fd);
			fread(&byteD,1,1,fd);
			strcpy(hora,horaUnix(byteA, byteB, byteC, byteD));//en esta linea se obtiene la hora unix
			//se leen los datos del chofer y la alarma
			fread(&chofer,1,1,fd);
			fread(&alarma,1,1,fd);
			//pasamos los datos a enteros o flotante para que asi se puedan usar
			e_interno = (int)interno;
			e_chofer = (int)chofer;
			e_alarma = (int)alarma;
		
		
			//ahora llamamos a la funcion que va a ingresar los taxis a las estructuras
			taxi_nuevo(e_interno, e_chofer, e_alarma, latitud, longitud, hora, ptrs);
			
	

		}
		fclose(fd);
		//ahora llamamos a la funcion que cree el archivo con los datos de geolocalizacion
		archivo_geolocalizacion(*ptrs);
	}
return 0;
}


//--------------------------------------------------------------------------------------------------------------------------------

float Latitud_Longitud( uint8_t byteA, uint8_t byteB, uint8_t byteC, uint8_t byteD ) 
{
	uint32_t aux = (byteD<<24) + (byteC<<16) + (byteB<<8) + byteA ; //se arma la variable aux debido a que viene en little endian

    int signo, exponente, entero ;
    uint8_t aux2 ;
    uint32_t aux3, divisor = 0xFFFFFFFF ;
    float decimal, VALOR_FLOTANTE ;

    //se obtiene el signo: 
    if( aux >> 31 ) //a la variable aux se la corre 31 lugares
       signo = -1 ;
    else //si hay un 0 en el bit 32 es positivo
       signo = 1 ;

    //obtenemos la parte entera 
     aux2 = (aux>>23) ; //se corre 23 lugares a la derecha
     exponente = aux2 - 127 ; //obtenemos el exponente de la base 2

     aux2 = (aux >> (23 - exponente)) ; //se obtiene la parte que se encuentra antes de la coma
     aux2 <<= (8-exponente) ; 
     aux2 >>= (8-exponente) ;

     //se obtiene la parte entera
     entero = pow(2, exponente) + aux2 ; 

     //se obtiene la parte decimal
     aux3 = (aux << (9 + exponente)); 
     aux3 >>= (9 + exponente ) ;

     divisor <<= (9 + exponente) ; 
     divisor >>= (9 + exponente) ;

     decimal = (float) aux3/divisor ; //se calcula la parte final del decimal

     VALOR_FLOTANTE = (float) signo*( entero + decimal ) ;
    return VALOR_FLOTANTE ;


}


//------------------------------------------------------------------------------------------------------------------------------------


void taxi_nuevo(int e_interno, int e_chofer, int e_alarma, float latitud, float longitud,char *hora, ptrTaxi *ptrs)//a esta funcion se les pasaran los datos y la misma sera la encargada de meterlos en la estructura
{
ptrTaxi ptrNuevo;//las variables que utilizaremos
ptrTaxi ptrActual;
ptrTaxi ptrAnterior;

ptrNuevo = (ptrTaxi)malloc(sizeof(TAXI));//se gaurda espacio de memoria

if(ptrNuevo != NULL)
{
	//se introducen los datos a la nueva estructura de datos
	ptrNuevo->numero_de_interno = e_interno;
	ptrNuevo->datos.alarma = e_alarma;
	ptrNuevo->datos.chofer = e_chofer;
	ptrNuevo->datos.latitud = latitud;
	ptrNuevo->datos.longitud = longitud;
	strcpy(ptrNuevo->datos.hora_unix,hora);
	
	//se inicializan las otras variables
	ptrNuevo->ptrSig = NULL;
	ptrActual = *ptrs;
	ptrAnterior = NULL;
	
	
	//se colola el nuevo taxi dependiendo su numero_de_interno
        while(ptrActual != NULL && ptrNuevo->numero_de_interno > ptrActual->numero_de_interno)
        {
            ptrAnterior = ptrActual;
            ptrActual = ptrAnterior->ptrSig;
        }

        //si es el primero

        if(ptrAnterior == NULL)
        {
            ptrNuevo->ptrSig = ptrActual;
            *ptrs = ptrNuevo;

        }
        else
        {
            ptrAnterior->ptrSig = ptrNuevo;
            ptrNuevo->ptrSig = ptrActual;

        }


}
else
{
	printf("\nerror\n");
}

}


//------------------------------------------------------------------------------------------------------------------------------


char * horaUnix( uint8_t byteA, uint8_t byteB, uint8_t byteC, uint8_t byteD )
{
    time_t tiempo = (byteD<<24) + (byteC<<16) + (byteB<<8) + byteA ; //con la variable 'tiempo' armo el dato, recordando que viene dado en Littel Endian, por eso al revés
    char *ptrHUnix ;

    ptrHUnix = ctime( &tiempo ) ;

    return ptrHUnix;//retorna la hora unix en una cadena

}


//------------------------------------------------------------------------------------------------------------------------------------


void archivo_taxi(ptrTaxi ptrs)//esat funcion crear un archivo con los datos del taxi
{
ptrTaxi ptrActual;
ptrTaxi ptrAnterior;
FILE *fd;

fd = fopen("datos_taxi.txt","w");//se abre el archivo en modo escritura
ptrActual = ptrs;
ptrAnterior = NULL;

fprintf(fd,"NUMERO INTERNO\tMARCA\tPATENTE\tPROPIETARIO\tTEL DE CONTACTO");//esto es el marco del archivo

if(ptrActual != NULL)
{
	while(ptrActual != NULL)
	{
			
		//se escriben en el archivo de texto todos los datos del taxi
		fprintf(fd,"%d\t",ptrActual->numero_de_interno);
		fprintf(fd,"%s\t",ptrActual->marca);
		fprintf(fd,"%s\t",ptrActual->patente);
		fprintf(fd,"%s\t",ptrActual->propietario);
		fprintf(fd,"%d\t",ptrActual->tel_de_contacto);
		
		
		ptrAnterior = ptrActual;//esto hace que se vayan cambiando las estructuras de datos
		ptrActual = ptrAnterior->ptrSig;
	}
}
else
{
	printf("\nERROR");
}
	
fclose(fd);//se cierra el archivo de texto
}



//---------------------------------------------------------------------------------------------------------------------------------


void archivo_geolocalizacion(ptrTaxi ptrs)//esta funcion crea un archivo de texto con los datos de la geolocalizacion del taxi
{

ptrTaxi ptrActual;//estas variables son para movernos entre las estructuras de datos
ptrTaxi ptrAnterior;
FILE *fd;

fd = fopen("datos_geolocalizacion.txt","w");//se abre el archivo en modo escritura
ptrActual = ptrs;
ptrAnterior = NULL;

if(ptrActual != NULL)
{
	while(ptrActual != NULL)
	{
			
		//se escriben en el archivo de texto todos los datos de la geolocalizacion
		fprintf(fd,"%d\t",ptrActual->numero_de_interno);
		fprintf(fd,"%f\t",ptrActual->datos.latitud);
		fprintf(fd,"%f\t",ptrActual->datos.longitud);
		fprintf(fd,"%s\t",ptrActual->datos.hora_unix);
		fprintf(fd,"%d\t",ptrActual->datos.chofer);
		//ahora nos fijamos que tipo de alarma debemos poner en el archivo
		if(ptrActual->datos.alarma == 1)
			fprintf(fd,"boton de panico");
		
		if(ptrActual->datos.alarma == 2)
			fprintf(fd,"vehiculo detenido por mas de 10 min");
		
		if(ptrActual->datos.alarma == 4)
			fprintf(fd,"pasajero sospechoso, llamar a la policia");	
			
		if(ptrActual->datos.alarma == 8)
			fprintf(fd,"chofer descansando");
		
		if(ptrActual->datos.alarma == 16)
			fprintf(fd,"cambio de chofer");
		
		if(ptrActual->datos.alarma == 32)
			fprintf(fd,"todo anda normal");			
		
		
		ptrAnterior = ptrActual;//esto hace que se vayan cambiando las estructuras de datos
		ptrActual = ptrAnterior->ptrSig;
	}
}
else
{
	printf("\nERROR");
}
	
fclose(fd);// se cierra el archivo de texto

}



//-------------------------------------------------------------------------------------------------------------------------------


void agregar(ptrTaxi *ptrs,int num)//esta funcion se utiliza para agregar los datos del taxi que se desee
{
	ptrTaxi ptrActual;//estas variables se usan para movernos en las estructuras de datos
	ptrTaxi ptrAnterior;
	int ban = 0;

	ptrActual = *ptrs;
	ptrAnterior = NULL;
	
	if(ptrActual != NULL)
	{
		while(ptrActual != NULL && ban == 0)
		{
			if(ptrActual->numero_de_interno == num)//comprobamos que sea la estructura que se nos pide
			{
				//aca ingresamos los datos que desee el usuario
				printf("\ningrese la marca del taxi: \n");
				scanf("%[^\n]",ptrActual->marca);
				printf("\ningrese la patente del taxi: \n");
				scanf("%[^\n]",ptrActual->patente);
				printf("\ningrese el propietario del taxi: \n");
				scanf("%[^\n]",ptrActual->propietario);
				printf("\ningrese el numero del propietario del taxi: \n");
				scanf("%d",&ptrActual->tel_de_contacto);
				ban = 1;
			}
			ptrAnterior = ptrActual;//nos movemos entre las estructuras para encontrar el surco que nosotros queramos
			ptrActual = ptrAnterior->ptrSig;
		}
			
	}
	else
	{
		printf("\nerror\n");
	}
}
