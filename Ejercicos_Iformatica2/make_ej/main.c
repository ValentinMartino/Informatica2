#include<stdio.h>
#include "recursion.h"

int main()
{
int dato;
printf("\ningrese el valor: \n");
scanf("%d", &dato);

if(recursion_par(dato))
	printf("el numero es par\n");
else
	printf("el numero es impar\n");
}
