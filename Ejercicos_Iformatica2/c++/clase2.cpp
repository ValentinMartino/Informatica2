#include <iostream>

using namespace std;

class Punto
{
	public:
	Punto();
	void ingresar_datos(float , float);
	void mostrar_datos();
	void sumar_datos(Punto );
	void restar_datos(Punto );
	
	
	
	private:
	float X;
	float Y;
	

};

int main()
{

Punto p1, p2;
p1.mostrar_datos();
p2.mostrar_datos();
p1.ingresar_datos(2.3, 3.4);
p2.ingresar_datos(2.2, 3.3);
p1.sumar_datos(p2);
p1.restar_datos(p2);




return 0;
}

Punto::Punto()
{
	X = Y = 0;
}

void Punto::ingresar_datos(float x, float y)
{
	X = x;
	Y = y;
}

void Punto::mostrar_datos()
{
	cout << "la parte X es: "<< X << " y la parte Y es: " << Y << endl;
}

void Punto::sumar_datos(Punto p)
{
	cout << "la suma en X es: " << X+p.X <<" la suma en Y es: " << Y+p.Y << endl; 
}

void Punto::restar_datos(Punto p)
{
	cout << "la resta en X es: " << X-p.X <<" la resta en Y es: " << Y-p.Y << endl;
}





