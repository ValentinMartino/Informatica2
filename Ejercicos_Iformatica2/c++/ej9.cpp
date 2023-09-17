#include <iostream>

using namespace std;

class Hora
{
	public: 
	//constructores
	Hora();
	Hora(int h, int m, int s);
	//destructor
	~Hora(){};
	//setters
	void set_hora(int h);
	void set_minuto(int m);
	void set_segundo(int s);
	//getters
	int ret_hora();
	int ret_minuto();
	int ret_segundo();
	//otras funciones
	void mostrar_hora();
	void sumar_horas(Hora p, Hora m);
	

	private:
	int hora;
	int segundo;
	int minuto;


};

//-------------------------------------------------------------------------------------------------------------------------------------

int main()
{
	Hora clase;
	Hora acto(3,55,20);
	Hora joda(11,35,40);
	
	acto.mostrar_hora();
	joda.mostrar_hora();
	clase.mostrar_hora();
	
	clase.sumar_horas(acto, joda);
	clase.mostrar_hora();
}

//-------------------------------------------------------------------------------------------------------------------------------------
//funciones de la clase hora
Hora::Hora()
{
	hora = minuto = segundo = 0;
}

Hora::Hora(int h, int m, int s)
{
	if(h < 12)
	{
		hora = h;
	}
	else
	{
		hora = 0;
	}
	if(m < 60)
	{
		minuto = m;
	}
	else
	{
		minuto = 0;
	}
	if(s < 60)
	{
		segundo = s;
	}
	else
	{
		segundo = 0;
	}	
}

void Hora::set_hora(int h)
{
	if(h < 12)
	{
		hora = h;
	}
	else
	{
		hora = 0;
	}
	
}

void Hora::set_minuto(int m)
{
	if(m < 60)
	{
		minuto = m;
	}
	else
	{
		minuto = 0;
	}
}
	
void Hora::set_segundo(int s)
{
	if(s < 60)
	{
		segundo = s;
	}
	else
	{
		segundo = 0;
	}	
}

int Hora::ret_hora()
{
	return hora;
}

int Hora::ret_minuto()
{
	return minuto;
}
	
int Hora::ret_segundo()
{
	return segundo;
}

void Hora::mostrar_hora()
{
	cout << "la hora es: " << hora << ":" << minuto << ":" << segundo << endl;
}

void Hora::sumar_horas(Hora p, Hora m )
{
	hora = p.hora + m.hora;
	minuto = p.minuto + m.minuto;
	segundo = p.segundo + m.segundo;
	
	if(hora > 12)
	{
		hora = hora % 12;
	}
	if(minuto > 60)
	{
		minuto = minuto % 60;
	}
	if(segundo > 60)
	{
		segundo = segundo % 60;
	}
	
}
