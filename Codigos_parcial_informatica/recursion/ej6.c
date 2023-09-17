#include<stdio.h>

int par(int n);
int impar(int n);

int main(int argc, char *argv[])
{
	int n = 31;
	if(par(n))
		printf("\nEl numero es par.\n");
	else
		printf("\nEl numero es impar. \n");
		
return 0;
}

int par(int n)
{
	if(n == 0)return 1;
	else return impar(n-1);

}

int impar(int n)
{
	if(n == 0) return 0;
	else return par(n-1);

}
