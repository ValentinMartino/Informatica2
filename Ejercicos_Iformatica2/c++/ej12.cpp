/*Implementar una clase Fecha con miembros dato para
el mes, día y año. Cada objeto de esta clase representa
una fecha, que almacena el día, mes y año como enteros.
Se debe incluir un constructor por defecto, un construc-
tor de copia, funciones de acceso, una función reini-
ciar (int d, int m, int a) para reiniciar la fecha
de un objeto existente, una función adelantar(int d,
int m, int a) para avanzar a una fecha existente (dia,
d , mes, m , y año a ) y una función imprimir() . Emplear
una función de utilidad normalizar() para ase gurar
que los miembros dato están en el rango correcto
1 ≤ año, 1 ≤ mes ≤ 12, día ≤ días (Mes), donde
dias(Mes) es asegurar otra función que devuelve el nú-
mero de días de cada mes. */
#include <iostream>

using namespace std;

class Fecha
{
	public:
	//constructor
	Fecha(){anio = mes = dia = 0;}
	Fecha(Fecha &p);
	Fecha(int a, int m, int d);
	//destructor
	~Fecha(){};
	//otras funciones
	void reinicia(int a, int m, int d);
	void adelantar(int a, int m, int d);
	void imprimir();
	

	private:
	
	int anio;
	int mes;
	int dia;
	
	void asegurar();
};

//-----------------------------------------------------------------------------------------------------------------------

int main()
{
Fecha cumple(2000,3,5);


cumple.imprimir();
cumple.reinicia(2001, 6, 30);
cumple.imprimir();



return 0;
}

//---------------------------------------------------------------------------------------------------------------------------
//funciones de la clase fecha

Fecha::Fecha(int a, int m, int d)
{
		anio = a;
		mes = m;
		dia = d;
		asegurar();
}

Fecha::Fecha(Fecha &p)
{
		anio = p.anio;
		mes = p.mes;
		dia = p.dia;
		asegurar();
}

void Fecha::reinicia(int a, int m, int d)
{
	anio = a;
	mes = m;
	dia = d;
	asegurar();
}

void Fecha::adelantar(int a, int m, int d)
{
	anio = a;
	mes = m;
	dia = d;
	asegurar();
}

void Fecha::imprimir()
{
	cout << "la fecha es: " << anio << "/" << mes << "/" << dia << endl;
}

void Fecha::asegurar()
{
	if(anio < 1)
	{
		anio = 0;
	}
	if(mes > 12)
	{
		mes = mes % 12;
	}
	if(dia > 30)
	{
		dia = dia % 30;
	}
}
