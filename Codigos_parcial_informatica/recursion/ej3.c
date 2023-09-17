#include<stdio.h>

int factorial(int numero);

int main(int argc, char *argv[])
{
	int n;
	printf("introduzca el numero al que quiere obtener el factorial. \n");
	scanf("%d",&n);
	printf("el factorial de %d es %d", n, factorial(n));


return 0;
}

int factorial(int numero)
{
	if(numero > 1)
		return (numero * factorial(numero - 1));
	else
		return 1;	 

}
