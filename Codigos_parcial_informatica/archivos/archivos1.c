#include<stdio.h>

int main(int argc, char *argv[])
{
FILE *archivo;
char caracter;
long tam;
char nombre[30];

if(argv[1] == NULL)
{
	printf("\ningrese el el nombre del archivo: \n");
	scanf("%s", nombre);
	archivo = fopen(nombre,"w");
	if(archivo == NULL)
	{
		printf("\nno se pudo abrir/crear el archivo \n");
	}
}
else
{
	archivo = fopen(argv[1],"w");
	if(archivo == NULL)
	{
		printf("\nno se pudo abrir/crear el archivo \n");
	}
}
getchar();
printf("ingrese lo que desee en el archivo: \n");
while((caracter = getchar()) != '\n')
{
	fputc(caracter, archivo);
}

fclose(archivo);




if(argv[1] == NULL)
{
	archivo = fopen(nombre,"r");
	if(archivo == NULL)
	{
		printf("\nno se pudo abrir/crear el archivo \n");
	}
}
else
{
	archivo = fopen(argv[1],"r");
	if(archivo == NULL)
	{
		printf("\nno se pudo abrir/crear el archivo \n");
	}
}

printf("\nel archivo contiene lo siguiente: \n");
while((caracter = fgetc(archivo)) != EOF)
{
	printf("%c",caracter);
}
printf("\n");

fseek(archivo, 0, SEEK_END);
tam = ftell(archivo);
printf("\nSi lo mostramos dado vuelta es: \n");

for(int i = 1; i <= tam; i++)
{
	fseek(archivo, -i,SEEK_END);
	caracter = fgetc(archivo);
	printf("%c", caracter);
} 

printf("\n");
fclose(archivo);

return 0;

}
