#include<stdio.h>
#include "funciones_binarias.h"


int establecimiento()//esta funcion devuelve el establecimiento en el que se encuentra
{
unsigned char inicio, establecimiento;
FILE *archivo2;

archivo2 = fopen("test.bin","rb");//abre el archivo
if(archivo2 == NULL)
{
	printf("\nerror\n");
}
else
{

fread(&incio,1,1,archivo2);//estas lineas van tomando los bytes del archivo
fread(&establecimiento,1,1,archivo2);

}

if(establecimiento = 'A')//retorna 0 si es del primer establecimiento o 1 si es del segundo
{
	fclose(archivo2);
	return 0;
}
else
{
	fclose(archivo2);
	return 1;
}

}




int surco()//esta funcion devuelve el surco 
{
unsigned char inicio, establecimiento, surco;
FILE *archivo2;
int num;

archivo2 = fopen("test.bin","rb");
if(archivo2 == NULL)
{
	printf("\nerror\n");
}
else
{

fread(&incio,1,1,archivo2);
fread(&establecimiento,1,1,archivo2);
fread(&surco,1,1,archivo2);

}

num = (int)surco;//esta linea hace que el unsigned char sea un entero
fclose(archivo2);
return num;
}




int id_mensaje()
{
unsigned char inicio, establecimiento, surco, id_mensaje;
FILE *archivo2;
int num;

archivo2 = fopen("test.bin","rb");
if(archivo2 == NULL)
{
	printf("\nerror\n");
}
else
{

fread(&incio,1,1,archivo2);
fread(&establecimiento,1,1,archivo2);
fread(&surco,1,1,archivo2);
fread(&id_mensaje,1,1,archivo2);

}

num = (int)id_mensaje;//esta linea hace que el unsigned char sea un entero
fclose(archivo2);
return num;
}





int byte1()
{
unsigned char inicio, establecimiento, surco, id_mensaje, mensaje1;
FILE *archivo2;
int num;

archivo2 = fopen("test.bin","rb");
if(archivo2 == NULL)
{
	printf("\nerror\n");
}
else
{

fread(&incio,1,1,archivo2);
fread(&establecimiento,1,1,archivo2);
fread(&surco,1,1,archivo2);
fread(&id_mensaje,1,1,archivo2);
fread(&mensaje1,1,1,archivo2);
}

num = (int)mensaje1;//esta linea hace que el unsigned char sea un entero
fclose(archivo2);
return num;
}






int byte2()
{
unsigned char inicio, establecimiento, surco, id_mensaje, mensaje1, mensaje2;
FILE *archivo2;
int num;

archivo2 = fopen("test.bin","rb");
if(archivo2 == NULL)
{
	printf("\nerror\n");
}
else
{

fread(&incio,1,1,archivo2);
fread(&establecimiento,1,1,archivo2);
fread(&surco,1,1,archivo2);
fread(&id_mensaje,1,1,archivo2);
fread(&mensaje1,1,1,archivo2);
fread(&mensaje2,1,1,archivo2);

}
num = (int)mensaje2;//esta linea hace que el unsigned char sea un entero
fclose(archivo2);
return num;
}




int byte3()
{
unsigned char inicio, establecimiento, surco, id_mensaje, mensaje1, mensaje2, mensaje3;
FILE *archivo2;
int num;

archivo2 = fopen("test.bin","rb");
if(archivo2 == NULL)
{
	printf("\nerror\n");
}
else
{

fread(&incio,1,1,archivo2);
fread(&establecimiento,1,1,archivo2);
fread(&surco,1,1,archivo2);
fread(&id_mensaje,1,1,archivo2);
fread(&mensaje1,1,1,archivo2);
fread(&mensaje2,1,1,archivo2);
fread(&mensaje3,1,1,archivo2);
}
num = (int)mensaje3;//esta linea hace que el unsigned char sea un entero
fclose(archivo2);
return num;
}



int hora_UNIX()
{
unsigned char inicio, establecimiento, surco, id_mensaje, mensaje1, mensaje2, mensaje3;
unsigned int  hora_unix;
FILE *archivo2;
int num;

archivo2 = fopen("test.bin","rb");
if(archivo2 == NULL)
{
	printf("\nerror\n");
}
else
{

fread(&incio,1,1,archivo2);
fread(&establecimiento,1,1,archivo2);
fread(&surco,1,1,archivo2);
fread(&id_mensaje,1,1,archivo2);
fread(&mensaje1,1,1,archivo2);
fread(&mensaje2,1,1,archivo2);
fread(&mensaje3,1,1,archivo2);
}




return 
}
