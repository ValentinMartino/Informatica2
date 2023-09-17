#include <iostream>
#define PI 3.14

using namespace std;

class Objeto
{
	public: 
	//constructores
	Objeto(){x = y = 0;}
	Objeto(int a, int b){x = a; y = b;}
	//destructor
	~Objeto(){};
	//setter
	void set_x(int a){x = a;}
	void set_y(int b){y = b;}
	//getter
	int get_x(){return x;}
	int get_y(){return y;}
	//otras funciones
	virtual void imprimir();
	
	
	private:
	int x;//coordenadas de centro del objeto geometrico
	int y;
};

//------------------------------------------------------------------------------------------------------------------------------

class Circulo : public Objeto
{
	public:
	//constructores
	Circulo(){circunferencia = area = 0;}
	Circulo(float circ, float are, int a, int b);
	//destructor
	~Circulo(){};
	//setters
	void set_circunferencia(float circ){circunferencia = circ;}  
	void set_area(float are){area = are;}
	//getters
	float get_circunferencia(){return circunferencia;}
	float get_area(){return area;}
	//otras funciones
	void calculo_area(float radio);
	void calculo_circunferencia(float radio);
	void imprimir();


	private:
	float circunferencia;
	float area;

};

//---------------------------------------------------------------------------------------------------------------------------------

class Cuadrado : public Objeto
{
	public:
	//constructores
	Cuadrado(){perimetro = area = 0;}
	Cuadrado(float peri, float are, int a, int b);
	//destructor
	~Cuadrado(){};
	//setters
	void set_perimetro(float peri){perimetro = peri;}  
	void set_area(float are){area = are;}
	//getters
	float get_perimetro(){return perimetro;}
	float get_area(){return area;}
	//otras funciones
	void calculo_area(float lado);
	void calculo_perimetro(float lado);
	void imprimir();


	private:
	float perimetro;
	float area;
};


//-----------------------------------------------------------------------------------------------------------------------------------

int main()
{
Circulo c1;
Cuadrado c2;
c1.set_x(2);
c1.set_y(3);
c1.calculo_area(5);
c1.calculo_circunferencia(5);
c1.imprimir();

c2.set_x(4);
c2.set_y(5);
c2.calculo_area(5);
c2.calculo_perimetro(5);
c2.imprimir();


return 0;
}

//-------------------------------------------------------------------------------------------------------------------------------------
//funciones de la clase objeto

void Objeto::imprimir()
{
	cout << "las cordenadas de su centro son: " << "(" << x << "," << y << ")" << endl;
}

//---------------------------------------------------------------------------------------------------------------------------------
//funciones de la clase Circulo

Circulo::Circulo(float circ, float are,int a, int b) : Objeto(a, b)
{
	circunferencia = circ;
	area = are;
}

void Circulo::calculo_area(float radio)
{
	area = PI * ((radio)*(radio)); 
}

void Circulo::calculo_circunferencia(float radio)
{
	circunferencia = PI * radio * 2;
}

void Circulo::imprimir()
{
	Objeto::imprimir();
	cout << "el area es: " << area << endl;
	cout << "la circunferencia es: " << circunferencia << endl;
}

//-----------------------------------------------------------------------------------------------------------------------
//funciones de la clase cuadradoo

Cuadrado::Cuadrado(float peri, float are,int a, int b) : Objeto(a, b)
{
	perimetro = peri;
	area = are;
}

void Cuadrado::calculo_area(float lado)
{
	area = lado * lado; 
}

void Cuadrado::calculo_perimetro(float lado)
{
	perimetro = lado * 4;
}

void Cuadrado::imprimir()
{
	Objeto::imprimir();
	cout << "el area es: " << area << endl;
	cout << "el perimetro es es: " << perimetro << endl;
}	
