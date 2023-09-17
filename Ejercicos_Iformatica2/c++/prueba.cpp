#include <iostream>

using namespace std;

class Hora
{
	public:
	//constructor
	Hora(int h, int m, int s);
	void imprimir();
	//setters
	Hora &set_hora(int h);
	Hora &set_minuto(int m);
	Hora &set_segundo(int s);
	
	
	private: 
	int hora;
	int minuto;
	int segundo;

};


int main()
{
	Hora tomy(1,2,3);
	tomy.imprimir();
	tomy.set_hora(2).set_minuto(3).set_segundo(5);
	tomy.imprimir();
return 0;
}


Hora::Hora(int h, int m, int s)
{
	hora = h;
	minuto = m;
	segundo = s;	
}

void Hora::imprimir() 
{
	cout << hora << ":" << minuto << ":" << segundo << endl;
}

Hora &Hora::set_hora(int h)
{
	hora = h;
	return *this;
}

Hora &Hora::set_minuto(int m)
{
	minuto = m;
	return *this;
}

Hora &Hora::set_segundo(int s)
{
	segundo = s;
	return *this;
}
	
	
	
	
	
