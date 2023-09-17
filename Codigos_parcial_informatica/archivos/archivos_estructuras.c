#include<stdio.h>
#include<stdlib.h>
#include "archivos.h"



int main()
{
ptrNodo paciente = NULL;
int opcion;

printf("\n1)Para ingresar un paciente\n2)Para eliminar un paciente\n3)Para mostrar los pacientes ingresados\n4)Para salir del menu\n");
scanf("%d",&opcion);

do
{
	switch(opcion)
	{
		case 1:ingresar_paciente(&paciente);break;
		case 2:mostrar(paciente);eliminar_paciente(&paciente);break;
		case 3:mostrar(paciente);break;
		default: ;
	}	
}while(opcion != 4);
return 0;
}











