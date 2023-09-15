#include <stdio.h>

//funcion que devuelve la hora unix
char * horaUnix( uint8_t byteA, uint8_t byteB, uint8_t byteC, uint8_t byteD )//esta funcion devuelve la hora unix
{
    time_t hora = (byteD<<24) + (byteC<<16) + (byteB<<8) + byteA ; //se arma el dato  recordando que viene en litle endian
    char *ptrHora ;

    ptrHora = ctime( &hora ) ;

    return ptrHora;
}

//--------------------------------------------------------------------------------------------------------------------------------

void poner_archivo(ptrVino ptr)//esta funcion crea un archivo de texto con los datos de la estructuras 
{
ptrNodo ptrActual;//con estas variables se recorren las estructuras
ptrNodo ptrAnterior;
FILE *fd;

fd = fopen("datos.txt","w");//se abre el archivo
//con estas lineas comprobamos si el archivo se pudo abrir
if( fd == NULL)
{
   printf (" ERROR : no se pudo abrir rl archivo.\n");
   return -1;
}

ptrActual = ptrS;
ptrAnterior = NULL;
//con esta linea se arma el esqueleto del archivo
fprintf(fd,"ESTABLECIMIENTO	SURCO	FECHA Y HORA	VARIEDAD  HUM_SURCO  TEMP_SURCO  HUM_AMB  TEMP_AMB  RAD_SOLAR  ALARMA")

if(ptrActual != NULL)
{
	while(ptrActual != NULL)
	{
		//en estas lineas se van introducionde los datos al archivo
		if((ptrActual->identificador_surco - (ptrActual->identificador_surco % 100)) == 100)//metodo para obtener la ciudad donde esta el viñedo
		{
			fprintf(fd,"cafayate	");
		}
		else
		{
			fprintf(fd,"valle del uco	");
		}
		fprintf(fd,"%d	",ptrActual->identificador_surco % 100);
		//estas lienas se fijan que tipo de vino es y lo introducen en el archivo
		fprintf(fd,"%s	",ptrActual->hora_unix);//esto imprime la hora unix
		
		if(ptrActual->variedad_uva == 1)
			fprintf(fd,"malbec  ");
		if(ptrActual->variedad_uva == 2)
			fprintf(fd,"marloc  ");
		if(ptrActual->variedad_uva == 4)
			fprintf(fd,"Cabernet Sauvignon  ");
		if(ptrActual->variedad_uva == 8)
			fprintf(fd,"Pinot Negro  ");
		
		fprintf(fd,"%f  ",ptrActual->hum_suelo);
		fprintf(fd,"%f  ",ptrActual->temp_suelo);
		fprintf(fd,"%f  ",ptrActual->hum_ambiente);
		fprintf(fd,"%f  ",ptrActual->temp_ambiente);
		fprintf(fd,"%f  ",ptrActual->radiacion_solar);
		
		if(ptrActual->hum_suelo > ptrActual->humedad_maxima)
		{
			fprintf(fd,"1");
		}
		if(ptrActual->hum_suelo < ptrActual->humedad_maxima)
		{
			fprintf(fd,"2");
		}	
		
		ptrAnterior = ptrActual;//esto hace que se vayan cambiando las estructuras de datos
		ptrActual = ptrAnterior->ptrSig;
	}
}
else
{
	printf("\nERROR");
}
	
fclose(fd);
return 0;
}


//------------------------------------------------------------------------------------------------------------------------------------


void leer_archivo(ptrVino *ptrs)
{
	unsigned char inicio, establecimiento, surco, id_mensaje, mensaje1, mensaje2, mensaje3;// variables en donde vamos a meter los datos
	uint8_t byteA, byteB, byteC, byteD;//estas variables se utilizan para obtener la hora unix
	FILE *fd;
	int e_establecimiento, e_surco, e_id_mensaje, e_mensaje1, e_mensaje2, e_mensaje3;
	char * hora;//esta variable guardara la hora unix
	
	fd = fopen("datos.bin", "rb");// se abre el archivo binario en modo lectura
		
	do
	{
		fread(&inicio,1,1,fd);//leemos todos los datos del surco 
		fread(&establecimiento,1,1,fd);
		fread(&surco,1,1,fd);
		fread(&id_mensaje,1,1,fd);
		fread(&mensaje1,1,1,fd);
		fread(&mensaje2,1,1,fd);
		fread(&mensaje3,1,1,fd);
		fread(&byteA,1,1,fd);
		fread(&byteB,1,1,fd);
		fread(&byteC,1,1,fd);
		fread(&byteD,1,1,fd);
		
	
		//en estas lineas pasamos los unsigned char a enteros para que de esta forma lo podamos usar
		if(establecimiento == 'A')
		{
			e_establecimiento = 100;
		}
		else 
		{
			e_establecimiento = 200;
		}
		e_surco = (int)surco;
		e_id_mensaje = (int)id_mensaje;
		e_mensaje1 = (float)mensaje1;
		e_mensaje2 = (float)mensaje2;
		e_mensaje3 = (float)mensaje3;

		//identificamos que tipo de id_mensaje vamos a tener
		
		//llamaremos a la funcion que nos devolvera la hora unix	
		hora = horaUnix(byteA, byteB, byteC, byteD);
	
		if(e_id_mensaje == 1)// si es igual a 1 debemos leer los datos ambientales
		{
			surco_ambiente(e_establecimiento, e_surco, e_mensaje1, e_mensaje2, e_mensaje3, hora, &ptrs);//funcion que busca el surco y lo ingresa los datos del ambiente
		
		}

		if(e_id_mensaje == 2)//si es igual a 2 debemos leer los datos del suelo
		{
			surco_suelo(e_establecimiento, e_surco, e_mensaje2, e_mensaje3, hora, &ptrs);//funcion que busca el surco y le ingresa los datos del suelo

		}
	
		if(e_id_mensaje == 4)//se crea un nuevo surco y se lo completa con los datos
		{
	
			surco_nuevo(e_establecimiento, e_surco, e_mensaje1, e_mensaje2, e_mensaje3, hora, &ptrs);//funcion que crea un nuevo surco con los datos
		}
	
	}while(!feof( fd ) );
	fclose(fd);
}


//----------------------------------------------------------------------------------------------------------------------------------

float obtenerValorFlotante( uint8_t byteA, uint8_t byteB, uint8_t byteC, uint8_t byteD ) 
{
	uint32_t aux = (byteD<<24) + (byteC<<16) + (byteB<<8) + byteA ; //con la variable aux armo el dato, recordando que viene dado en Littel Endian, por eso al revés
	int signo, exponente, entero ;
	uint8_t aux2 ;
	uint32_t aux3, divisor = 0xFFFFFFFF ;
	float decimal, VALOR_FLOTANTE ;
		
	/********OBTENGO EL SIGNO********/
	if( aux >> 31 ) //corro 31 lugares la variable aux: si tengo 1 va a ser verdadero, lo que significa que el signo es negativo.
		signo = -1 ;
	else //si tengo un 0 como bit 32, significa que el signo es positivo
		signo = 1 ;

	/********OBTENGO LA PARTE ENTERA DE LA MANTISA********/
	 aux2 = ( aux>>23 ) ; //corro 23 lugares a la derecha, por lo que me van a quedar 9 bits incluído el de signo. Como aux2 es de tipo 'uint8_t', solo toma los 8 bits de la derecha
	 exponente = aux2 - 127 ; //obtengo el exponente de la base 2

	aux2 = ( aux >> (23 - exponente) ) ; 	  //con esto obtengo la parte antes de la coma, sin emargo, me puede quedar basura. Ej: exp =5 ----- > aux2 = xxx 1010 1
 	aux2 <<= (8-exponente) ; // Ej: aux2 = 1010 1000
 	aux2 >>= (8-exponente) ; // Ej: aux2 = 0001 0101
 	
 	entero = pow( 2, exponente ) + aux2 ; //CALCULO FINAL DE LA PARTE ENTERA: 2^exp + aux2
 	
 	/********OBTENGO LA PARTE DECIMAL DE LA MANTISA********/
 	aux3 = ( aux << ( 9 + exponente ) ) ; //Si mi parte decimal es 18 de aux = xxxx xxxx xxxx xx11 0011 1010 1111 0011-----> aux3 = 11 0011 1010 1111 0011 0000 0000 0000 00
 	aux3 >>= (9 + exponente ) ;               //finalmente, borré todo lo que NO necesito ---------------------------------------> aux3 = 0000 0000 0000 0011 0011 1010 1111 0011
 	 	
 	divisor <<= (9 + exponente ) ; // Recordar que exponente=5 en el ejemplo de los comentarios. ---------------------> divisor = 11 1111 1111 1111 1111 0000 0000 0000 00
  	divisor >>= (9 + exponente ) ;// logro obtener mi divisor, acorde a mi parte decimal -------------------------------> divisor = 0000 0000 0000 0011 1111 1111 1111 1111
	
	decimal = (float) aux3/divisor ; //CALCULO FINAL DE LA PARTE DECIMAL
	
 	/********VALOR FLOTANTE********/
 	VALOR_FLOTANTE = (float) signo*( entero + decimal ) ;
	return VALOR_FLOTANTE ;	

}//fin de obtenerLatitud()

