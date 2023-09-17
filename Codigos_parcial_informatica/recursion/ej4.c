/*calcula el maximo comun divisor con recursion final*/
#include<stdio.h>

long mcd(long, long);

int main(int argc, char *argv[])
{
	long a = 4454,b = 143052;
	printf("\nel maximo comu divisor de a = %ld y b = %ld es %ld\n", a, b, mcd(a , b));

return 0;
}

long mcd(long a, long b)
{
	
	if(a == b) return a;
	else if(a > b)return mcd(a-b,b);
	else return mcd(a, b-a);

}
