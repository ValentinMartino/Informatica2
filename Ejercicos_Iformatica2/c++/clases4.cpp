#include <iostream>

using namespace std;

class Fecha
{
public:
	Fecha(int d, int m, int a);
	void mostrar_fecha() const;	

private:

	int dia;
	int mes;
	int ano;

};

class Alumno
{
friend void hola(Alumno &);
public:
	Alumno(int n, int dn, int mn, int an, int de, int me, int ae);
	void mostrar_alumno() const;

private:

	int num;
	Fecha fecha_nacimiento;
	Fecha fecha_egreso;
	
};

int main()
{
	Alumno valu(1, 30, 6, 2001, 8, 9, 2018);
	valu.mostrar_alumno();
	hola(valu);


return 0;
}

Fecha::Fecha(int d, int m, int a)
{
	dia = d;
	mes = m;
	ano = m;
}

void Fecha::mostrar_fecha() const
{
	cout << dia << "/" << mes << "/" << ano << endl;
}

Alumno::Alumno(int n, int dn, int mn, int an, int de, int me, int ae): fecha_nacimiento(dn,  mn,  an) , fecha_egreso(de, me,  ae){
	num = n;		
}

void Alumno::mostrar_alumno() const
{
	cout << "el numero del alumno es " << num << endl;
	fecha_nacimiento.mostrar_fecha();	
	fecha_egreso.mostrar_fecha();
}

void hola(Alumno &p)
{
	cout << p.num << endl;
}


