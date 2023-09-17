#include <iostream>

using namespace std; 
void divicion(float &, float &);

int main()
{
	float dividendo;
	float divisor;
	
	cout << "ingrese el valor del dividendo \n";
	cin >> dividendo;
	
	do
	{
		cout << "ingrese el valor del divisor \n";
		cin >> divisor;
	} while(divisor == 0);
	
	cout << divisor << dividendo ;
	divicion(divisor , dividendo);	
	cout << divisor << dividendo ;


	return 0;
}


void divicion(float &bobo, float &vivi)
{
	
	
	bobo ++;
	vivi ++;
	//cout << bobo << vivi ;
}	
