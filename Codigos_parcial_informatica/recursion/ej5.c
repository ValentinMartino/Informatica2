#include<stdio.h>

long fibo(int );

int main(int argc, char *argv[])
{
	int n, i;
	long coef;
	
	printf("\ningrese la cantidad de terminos de fibonacci que desea\n ");
	scanf("%i", &n);
	printf("\nlos coeficientes de la serie de fibonacci son: \n");
	
	for(i = 0; i < n; i++)
	{
		coef = fibo(i);
		printf("coeficientes %d\t\t valor de fibonacci: %ld \n", i, coef);
	} 
	printf("\n");

return 0;
}

long fibo(int n)
{
	if(n > 1) return fibo(n-1) + fibo(n-2);
	else if (n == 0) return 0;
	else if(n == 1) return 1;
	else return 0; 

}


