//determinar si un numero es par o impar con recursion

#include<stdio.h>

long funcion(long );

int main()
{
long a;
printf("\ningrese un valor : ");
scanf("%ld", &a);

if(funcion(a) == 1)
printf("\nel numero es impar\n");

else
printf("\nel numero es par\n");


return 0;
}

long funcion( long a )
{
if(a == 1 )
 return 1;

if(a == 0)
 return 0;
 
return funcion(a - 2);  

}
