#include <iostream>

using namespace std;

void suma(int , int, int);
void suma(float, float, float);
void suma(int, int);
void suma(float, float);
void suma(float, int);

int main()
{
int n1 = 2; 
int n2 = 5; 
int n3 = 7; 

suma(n1, n2, n3);
suma(n1, n2, n3);
suma(n1, n2);
suma(n1, n2);
suma(n1, n2);

return 0;
}

void suma(int n1, int n2, int n3)
{
	cout << n1+n2+n3 << endl;
}

void suma(float n1,float n2, float n3)
{
	cout << n1+n2+n3 << endl;
}

void suma(int n1, int n2)
{
	cout << n1+n2 << endl;
}

void suma(float n1, float n2)
{
	cout << n1+n2 << endl;
}

void suma(float n1, int n2)
{
	cout << n1+n2 << endl;
}
