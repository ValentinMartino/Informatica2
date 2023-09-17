#include <iostream>
#include <cstring>

using namespace std;

class Alumno
{
	friend void promedio(Alumno bro);
	
	public:
	//contrusctores
	Alumno();
	Alumno(string nom, int lega);
	Alumno(string nom, int lega, int quimica, int fisica, int info, int estadistica);
	//destructor
	~Alumno(){};
	//setters
	void nomb(string nom);
	void lega(float lega);
	void quimica(float quimica);	
	void fisica(float fisica);	
	void info(float info);
	void estadistica(float estadistica);
	//getters
	string ret_nombre();
	float ret_legajo();
	float ret_quimica();
	float ret_fisica();
	float ret_info();
	float ret_estadistica();
	//otras funciones
	void mostrar_alumno();
	
	
	private:
	
	string nombre;
	float legajo;
	float nota_quimica;
	float nota_fisica;
	float nota_info;
	float nota_estadistica;
	
};

//-------------------------------------------------------------------------------------------------------------------------------------

int main()
{
	Alumno arr[5];
	for(int i = 0; i < 5; i++)
	{
		arr[i].mostrar_alumno();
		promedio(arr[i]);
	}


return 0;
}

//------------------------------------------------------------------------------------------------------------------------------------
//funciones de la clase alumno

Alumno::Alumno()
{
	nombre = "no hay nombre";
	legajo = 00000;
	nota_quimica = 0;
	nota_fisica = 0;
	nota_info = 0;
	nota_estadistica = 0;
}

Alumno::Alumno(string nom, int lega)
{
	nombre = nom;
	legajo = lega;
	nota_quimica = 0;
	nota_fisica = 0;
	nota_info = 0;
	nota_estadistica = 0;
}

Alumno::Alumno(string nom, int lega, int quimica, int fisica, int info, int estadistica)
{
	nombre = nom;
	legajo = lega;
	nota_quimica = quimica;
	nota_fisica = fisica;
	nota_info = info;
	nota_estadistica = estadistica;
}

void Alumno::nomb(string nom)
{
	nombre = nom;
}

void Alumno::lega(float lega)
{
	legajo = lega;
}

void Alumno::quimica(float quimica)
{
	nota_quimica = quimica;
}	

void Alumno::fisica(float fisica)
{
	nota_fisica = fisica;
}	

void Alumno::info(float info)
{
	nota_info = info;
}

void Alumno::estadistica(float estadistica)
{
	nota_estadistica = estadistica;
}

string Alumno::ret_nombre()
{
	return nombre;
}

float Alumno::ret_legajo()
{
	return legajo;
}

float Alumno::ret_quimica()
{
	return nota_quimica;
}

float Alumno::ret_fisica()
{
	return nota_fisica;
}

float Alumno::ret_info()
{
	return nota_info;
}

float Alumno::ret_estadistica()
{
	return nota_estadistica;
}

void Alumno::mostrar_alumno()
{
	cout << "el nombre del alumno es: " << nombre << endl;
	cout << "su legajo es: " << legajo << endl;
	cout << "sus notas son: " << endl;
	cout << "quimica: " << nota_quimica << endl;
	cout << "fisica: " << nota_fisica << endl;
	cout << "info: " << nota_info << endl;
	cout << "estadistica: " << nota_estadistica << endl;
}

void promedio(Alumno bro)
{
	float suma = 0;
	suma = bro.nota_quimica + bro.nota_fisica + bro.nota_info + bro.nota_estadistica;
	suma = suma/4;
	cout << "el promedio de sus notas es: " << suma << endl;
}

