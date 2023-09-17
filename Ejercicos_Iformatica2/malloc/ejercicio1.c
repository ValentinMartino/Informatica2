#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *a = malloc(sizeof(int ));
	int *b = malloc(sizeof(int ));
	*a = 5;
	*b = 4;
	
	
	
	int *c = malloc(sizeof(int ));
	*c = *a + *b;
	
	
	
	printf(" la suma da: %d\n" ,*c); 
	free(a);
	free(b);
	free(c);

	printf(" la suma da: %d\n" ,*c);


return 0;
}
