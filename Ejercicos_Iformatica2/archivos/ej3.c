#include<stdio.h>

int main()
{
FILE *archivo;
char caracter;

archivo = fopen("hola.txt", "w");
if(archivo == NULL)
{
	printf("\nel archivo no se pude abrir \n");
}
else
{
	printf("ingrese lo que desee que este en el archivo\n ");
	while((caracter = getchar ()) != '\n')
	{
		fputc(caracter, archivo);
	}
}


fclose(archivo);
archivo = fopen("hola.txt" , "r");
if(archivo == NULL)
{
	printf("\nerror\n");
}
else
{
	printf("\nel archivo contiene lo siguiuente \n");
	while((caracter = fgetc(archivo)) != EOF	)
	{
		printf("%c",caracter);
	}
	

}
fclose(archivo);

return 0;
}
