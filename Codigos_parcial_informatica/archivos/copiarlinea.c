#include<stdio.h>
#include<stdlib.h>


int main(int argc, char *argv[])
{	
	FILE *archivo;
	char c;
	int cont = 0;
	char letra;
		
	archivo = fopen(argv[1], "r");
	
	if(archivo == NULL)
	{
		printf("\nNo se pudo abrir el archivo.\n");
	}
	
	printf("\nIngrese el caracter que desee encontrar: ");
	scanf("%c",&letra );
	
	while(!feof(archivo))
	{
		c = fgetc(archivo);
		cont++;
		
		if(c == '\n')
			cont = 0;
		
		if(letra == c)
		{
			fseek(archivo, -cont , SEEK_CUR);
			
			while((c = fgetc(archivo)) != '\n')
			{
				printf("%c",c);
			}
			
			cont = 0;
		}
	}
	
	fclose(archivo);
	
	return 0;
}




































