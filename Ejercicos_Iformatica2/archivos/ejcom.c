#include<stdio.h>

void ingresar();
void agregar();
void mostrar();

int main()
{
int dato;

do
{
	printf("ingrese:\n1)Para ingresar datos\n2)Para agregar datos\n3)Para mostrar lo que este en el archivo\n4)Para salir\n ");
	scanf("%d",&dato);
	switch(dato)
	{
		case 1: ingresar();break;
		case 2: agregar();break;
		case 3: mostrar();break;
		default: printf("\n");

	}

}while(dato != 4);

return 0;
}

void ingresar()
{
FILE *archivo;
char caracter;

archivo = fopen("hola.txt","w");
if(archivo == NULL)
{
	printf("\nerror\n");
}	
else
{
	printf("\nescriba el texto a ingresar: \n");
	while((caracter = getchar()) != '\n')
	{
		fputc(caracter, archivo);
	}
		
}

fclose(archivo);

}

void mostrar()
{
FILE *archivo;
char caracter;

archivo = fopen("hola.txt", "r");
if(archivo ==NULL)
{
	printf("\n no se encontro el archivo \n");
}
else
{
	printf("\nel conetenido del archivo es: \n");
	while((caracter = fgetc(archivo)) != EOF)
	{
		printf("%c",caracter);
	}
}
fclose(archivo);

}


void agregar()
{
FILE *archivo;
char caracter;

archivo = fopen("hola.txt","a");
if(archivo == NULL)
{
	printf("\n error \n");
}
else
{
	printf("\ningrese lo que desea agregar al archivo: \n");
	fputc('\t',archivo);
	while((caracter = getchar ()) != '\n')
	{
		fputc(caracter, archivo);
	}
}
fclose(archivo);
}


































