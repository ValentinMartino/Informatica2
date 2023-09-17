#include <iostream>
#include <cstring>

using namespace std;

class Hora
{
	public:
	friend class Materia;
	//constructor
	Hora(){hora = minuto = segundo = 0;}
	Hora(int h, int m, int s){hora = h; minuto = m; segundo = s;}
	//destructor
	~Hora(){};
	//otras funciones
	void mostrar_hora(); 
	//seter 
	void set_hora(int h, int m, int s){hora = h; minuto = m; segundo = s;}
	
	private:
	int hora;
	int minuto;
	int segundo;
};

//---------------------------------------------------------------------------------------------------------------------------------

class Materia
{	friend void hola(Materia &p,int h, int m, int s);
	public:
	//constructor
	Materia(){}
	Materia(string nom,int h, int m, int s )
	{	
		nombre = nom;
		inicio.hora = h;
		inicio.minuto = m;
		inicio.segundo = s;
	}
	//otras funciones
	void mostrar_materia();

	private:
	string nombre;
	Hora inicio;
};

//----------------------------------------------------------------------------------------------------------------------------------

int main()
{
	Materia matematica("matematica",5,20,0);
	matematica.mostrar_materia();
	hola(matematica,3,5,6);
	matematica.mostrar_materia();


}

//--------------------------------------------------------------------------------------------------------------------------
void Hora::mostrar_hora()
{
	cout << hora << minuto << segundo << endl;
}
//------------------------------------------------------------------------------------------------------------------------

void Materia::mostrar_materia()
{
	inicio.mostrar_hora();
	cout << nombre << endl;
}

//-------------------------------------------------------------------------------------------------------------------------

void hola(Materia &p, int h, int m, int s) 
{
	p.nombre = "messi";
	p.inicio.set_hora(h,m,s); 	
}
