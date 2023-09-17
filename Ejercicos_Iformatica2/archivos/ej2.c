#include<stdio.h>
#include<stdio.h>

int main()
{
FILE * pt;
//char nombre[30];
char caracterE;
char caracterL;

//printf("\ningrese el nombre que desee que tenga su archivo: \n");
//scanf("%s", nombre); 

pt = fopen("valu.txt" ,"w+");
if(pt == NULL)
{
	printf("\nhubo un error \n");
} 
else
{
	printf("\nescriba lo que desee en su archivo: \n");
	while((caracterE = getchar ()) != '\n')
	{
		fputc(caracterE , pt );
	}

	printf("\nel archivo contiene: \n");
	while((caracterL = fgetc(pt)) != EOF)
	    {
		printf("%c",caracterL);
	    }



}


fclose(pt);





return 0;
}
