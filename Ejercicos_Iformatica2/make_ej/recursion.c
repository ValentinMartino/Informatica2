#include<stdio.h>
#include "recursion.h"

int recursion_par(int dato)
{
if(dato == 0)
return 1;
else
return recursion_impar(dato - 1); 
}

int recursion_impar(int dato)
{
if(dato == 0)
return 0;
else
return recursion_par(dato - 1);
}
