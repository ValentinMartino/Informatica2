#include <iostream>

using namespace std;

class Hora
{
	public:
	//constructores de la clase
	Hora();
	Hora(int h, int m, int s);

	//setters de la clase
	void setter_hora(int h);
	void setter_minuto(int m);
	void setter_segundo(int s);
	
	//getters de la clase
	int getter_hora();
	int getter_minuto();
	int getter_segundo();
	
	//otras funciones
	void mostrar_hora();
	
	private:
	
	int hora;
	int minuto;
	int segundo;
	

};

//--------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
	Hora cero;
	Hora mediodia(4,30,24);
	cero.setter_hora(15);
	
	cero.mostrar_hora();
	mediodia.mostrar_hora();


};

//----------------------------------------------------------------------------------------------------------------------------------------------
//funciones de la clase hora

Hora::Hora()
{
	hora = minuto = segundo = 0;
}

Hora::Hora(int h, int m, int s)
{
	if(h < 0 || h > 23)
	{
		hora = 0;
	}
	else
	{
		hora = h;
	}
	
	if(m < 0 || m > 60)
	{
		minuto = 0;
	}
	else
	{
		minuto = m;
	}
	
	if(s < 0 || s > 60)
	{
		segundo = 0;
	}
	else
	{
		segundo = s;
	}
		
}

void Hora::setter_hora(int h)
{
	if(h < 0 || h > 23)
	{
		hora = 0;
	}
	else
	{
		hora = h;
	}
}

void Hora::setter_minuto(int m)
{
	if(m < 0 || m > 60)
	{
		minuto = 0;
	}
	else
	{
		minuto = m;
	}
}

void Hora::setter_segundo(int s)
{
	if(s < 0 || s > 60)
	{
		segundo = 0;
	}
	else
	{
		segundo = s;
	}
}

int Hora::getter_hora()
{
	return hora;
}

int Hora::getter_minuto()
{
	return minuto;
}

int Hora::getter_segundo()
{
	return segundo;
}

void Hora::mostrar_hora()
{
	cout << hora << ":" << minuto << ":" << segundo << endl; 
}

