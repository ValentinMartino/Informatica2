#include<stdio.h>

void ingresar(FILE * , char []);
void agregar(FILE * , char []);
void mostrar(FILE * , char []);

int main()
{
FILE *archivo;
char nombre[30];
int variable;

printf("\ningrese el nombre del archivo que desee agregar/crear/leer : \n");
scanf("%s", nombre);
archivo =  fopen(nombre, "w+");

do{
        printf("\n1)para crear.\n2)Para agregar.\n3)Para mostrar."
               "\n4)Para salir.\n");

        scanf("%i", &variable);
	getchar();
        switch(variable)
        {
            case 1: ingresar(archivo , nombre);   break;
            case 2: agregar(archivo , nombre);  break;
            case 3: mostrar(archivo , nombre); break;
            default: printf("\nEliga uno de los numeros inndicados:\n");
        }

    }while(variable != 4);

    printf("\n");



fclose(archivo);
return 0;
}

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

void ingresar(FILE *archivo,char nombre[])
{
char caracter;

printf("\n ingrese lo que desee dentro del archivo: \n");
while((caracter = getchar()) != '\n')
{
	fputc(caracter,archivo);
}
} 

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

void agregar(FILE *archivo,char nombre[])
{
char caracter;

printf("\ningrese lo que desee agregar en el archivo: \n");
fseek(archivo, 0, SEEK_END);
fputc('\n',archivo);
while((caracter = getchar()) != '\n')
{
	fputc(caracter,archivo);
}
}

/*-------------------------------------------------------------------------------------------------------------------------------------------------*/

void mostrar(FILE *archivo,char nombre[])
{
char caracter;
printf("\nlo que se encuentra escrito en el archivo es lo siguiente: \n");
while((caracter = fgetc(archivo)) != EOF)
{
	printf("%c", caracter);

}
}













