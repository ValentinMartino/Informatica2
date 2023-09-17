#include<stdio.h>

void up_and_down(int);

int main(int argc, char *argv[])
{

up_and_down(1);


return 0;
}

void up_and_down(int n)
{
	printf("\nel nivel al que ha ingresado es el %d ubicacion de memoria %p.", n, &n);
	
	if(n < 4)
	{
		up_and_down(n+1);
	}
		
	printf("\nel nivel al que ha ingresado es el %d ubicacion de memoria %p.", n, &n);


}
