#include<stdio.h>

long fibonaci(long);

int main()
{
    long num, resultado;

    printf("\nIngrese un numero: ");
    scanf("%ld", &num);

    resultado = fibonaci(num);

    printf("El numero %ld  de fibonacci es %ld.", num, resultado);

    printf("\n");
    return 0;
}


long fibonaci(long num)
{

    if(num == 1 || num ==0)
    {
        return num;
    }
    else
    {
        return fibonaci(num-1) + fibonaci(num-2);
    }
}
