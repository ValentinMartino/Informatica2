#include <iostream>

using namespace std;

class Complejo
{
	public:
	//constructor
	Complejo(int a, int b)
	{
		parteReal= a;
		parteImaginaria = b;
	}
	Complejo operator+(Complejo);
	
	void imprimir();
	
	private:
	int parteReal;
	int parteImaginaria;
};


int main()
{

Complejo c1(2,3);
Complejo c2(2,3);
Complejo c3(0,0);
Complejo c4(7,5);

c3 = c1 + c2 + c4;
c3.imprimir();



return 0;
}






Complejo Complejo::operator+(Complejo op2) 
{
	double real = parteReal + op2.parteReal;
	double imag = parteImaginaria + op2.parteImaginaria;
	Complejo resultado(real, imag);
	return resultado;
}

void Complejo::imprimir()
{
	cout << parteReal << " " << parteImaginaria << endl;
}
