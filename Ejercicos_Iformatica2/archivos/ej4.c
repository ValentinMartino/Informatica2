#include<stdio.h>



int main(int argc, char *argv[])
{
FILE *archivo;
char caracter;
int i = 0;

if(argv[2] != NULL)
{
	archivo = fopen(argv[2], "w+");
	if(archivo == NULL)
	{
		printf("\nerror\n");
	}
	else
	{
		printf("\ningrese lo que desee en el archivo. aprete enter cuando haya terminado: \n");
		while((caracter = getchar()) != '\n')
		{
			fputc(caracter, archivo);
		}
		
		fseek(archivo, 0, SEEK_SET);
		while((caracter = fgetc(archivo)) != EOF)
		{
			i++;
			if(caracter == '.')
			{
				i = 0;	
			}
			if(argv[1][0] == caracter)
			{
				fseek(archivo, -i,SEEK_CUR);
				printf("\n");
				while((caracter = fgetc(archivo)) != '.')
				{
					printf("%c",caracter);
				} 
			
				i = 0;	
			}		
		}
	}
}
else
{
	printf("\ndebe ingresar un caracter y el nombre del archivo\n");
}











}
