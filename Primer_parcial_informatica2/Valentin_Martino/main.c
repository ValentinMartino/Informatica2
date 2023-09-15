#include<stdio.h>
#include "funciones.h"
#include "funciones_binarias.h"

int main()
{
ptrNodo variable = NULL;
int mensaje;

mensaje = id_mensaje();//la funcion id_mensaje nos va a informar de que tipo de datos va a ser el mensaje
	switch(mensaje)
	{
		case 1: modificar_surco_1(&variable);
			break;
		case 2:	modificar_surco_2(&variable);
			break;
		case 4:	agregar_surco(&variable);
			break;
		default:printf("\nerror\n");
	}

return 0;
}
