#include<stdio.h>

int main(int argc, char *argv[])
{
FILE *archivo1;	
FILE *archivo2;
char nombre1[30];
char nombre2[30];
char caracter;
int ban1 = 1;
int ban2 = 1;

if(argv[1] != NULL && argv[2] != NULL)
{
	archivo1 = fopen(argv[1], "r");
	archivo2 = fopen(argv[2], "r");
	if(archivo1 == NULL && archivo2 == NULL)
	{
		printf("\nerror\n"); 
		return 1;
	}
	
}
else
{
	printf("\ningrese el nombre del primer archivo\n");
	scanf("%s",nombre1);
	printf("\ningrese el nombre del segundo archivo\n");
	scanf("%s",nombre2);
	archivo1 = fopen(nombre1, "r");
	archivo2 = fopen(nombre2, "r");
	if(archivo1 == NULL && archivo2 == NULL)
	{
		printf("\nerror\n"); 
		return 1;
	}

}

while(ban1 == 1 || ban2 == 1)
{	
	while(((caracter = fgetc(archivo1)) != '\n') && ban1 == 1)
	{
		if(caracter == EOF)
		{
			ban1 = 0;	
		}
		else
		{
			printf("%c",caracter);
		}
	}
	printf("\n");
	while(((caracter = fgetc(archivo2)) != '\n') && ban2 == 1)
	{
		if(caracter == EOF)
		{
			ban2 = 0;
		}
		else
		{
			printf("%c",caracter);
		}	
	}
	printf("\n");
}

fclose(archivo1);
fclose(archivo2);

return 0;
}


