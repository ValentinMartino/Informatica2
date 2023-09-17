#include<stdio.h>

int main()
{
FILE *archivo;
FILE *archivo2;
char caracter;
int i = 0;

archivo = fopen("hola.txt" ,"w"); 
archivo2 = fopen("copia.txt", "w");
if(archivo == NULL)
{
	printf("no se pudo crear el archivo\n");
} 
else
{
	printf("\ningrese el lo que desee \n");
	while((caracter = getchar ()) != '\n')
	{
		i++;
		fputc(caracter, archivo);
		if(i % 4 == 0)
		{
			fputc(caracter, archivo2);
			i = 0;
					
		}
	}

}
fclose(archivo);
fclose(archivo2);



return 0;
}
