#include <iostream>

using namespace std;

class Vaca
{

public: 
	Vaca(int a, float b, float c);
	void ingresar_datos(int a);
	void mostrar_datos() const ;


private:

	float peso;
	const float l_leche;
	const int num;

};

int main()
{
Vaca num1(1, 750.5, 36.3);

num1.mostrar_datos();







return 0;
}

Vaca::Vaca(int a, float b, float c): num(a), l_leche(c)
{
	peso = b;
}

void Vaca::ingresar_datos(int a)
{
	cout << "ingrese el peso de la vaca: " << endl;
	cin >> peso;
	//cout << "ingrese los litros de leche de la vaca: " << endl;
	//cin >> l_leche;

}

void Vaca::mostrar_datos() const
{
	cout << "el numero de la vaca es :" << num << endl;
	cout << "el peso de la vaca es :" << peso << endl;
	cout << "la cantidad de litros de leche  de la vaca es :" << l_leche << endl;

}


