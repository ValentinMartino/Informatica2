#include <iostream>

using namespace std;

class Hora
{
	public:
	Hora();
	void establecer_hora(int, int, int);
	void imprime_militar();
	void imprime_estandar();
	
	
	private:
	int hora;
	int minutos;
	int segundos;
	

};

int main()
{
Hora h;

h.establecer_hora(49,25,34);
h.imprime_militar();
h.imprime_estandar();

return 0;
}



Hora::Hora()
{
	hora=minutos=segundos=0;
}

void Hora::establecer_hora(int h, int m, int s)
{
	if( h >= 0 && h < 24)
	{
		hora = h;
	}
	else
	{
		hora = 0;
	}
	
	if( m >= 0 && m < 60)
	{
		minutos = m;
	}
	else
	{
		minutos = 0;
	}
	
	if( s >= 0 && s < 60)
	{
		segundos = s;
	}
	else
	{
		segundos = 0;
	}

}

void Hora::imprime_militar()
{
	cout << hora <<":"<< minutos << ":" << segundos << endl;
}

void Hora::imprime_estandar()
{
	int ho;
	if(hora > 12)
	{
		ho = hora - 12;
	}
	else
	{
		ho = hora;
	}

	cout << ho <<":" << minutos << ":" << segundos << endl;

}
