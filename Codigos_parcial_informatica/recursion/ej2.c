#include<stdio.h>

int main()
{
	int c;
	if(scanf("%d", &c) != EOF)
	{
		main();
		printf("%d",c);
	}
return 0;
}
