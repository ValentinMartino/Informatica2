#include <iostream>

using namespace std;

class Unidimensional
{
	public:
	//constructores
	Unidimensional(){x = 0;}
	Unidimensional(int a){x = a;}
	//destructor
	~Unidimensional(){};
	//setter
	void set_x(int a){x = a;}
	//getters
	int get_x(){return x;}
	//otras funciones
	virtual void mostrar_punto();
	
	protected:
	int x;
};

//----------------------------------------------------------------------------------------------------------------------------

class bidimensional : public Unidimensional
{
	public:
	//constructores
	bidimensional();
	bidimensional(int a, int b);
	//destructor
	~bidimensional(){};
	//setter
	void set_y(int b){y = b;}
	//getter
	int get_y(){return y;}
	//otras funciones
	void mostrar_punto();


	protected:
	int y;
};

//-----------------------------------------------------------------------------------------------------------------------------

class tridimensional : public bidimensional
{
	public:
	//constructores
	tridimensional();
	tridimensional(int a, int b, int c);
	//destructor
	~tridimensional(){};
	//setter
	void set_z(int c){z = c;}
	//getter
	int get_z(){return z;}
	//otras funciones
	void mostrar_punto();


	private:
	int z;
};

//-----------------------------------------------------------------------------------------------------------------------------

int main()
{
	tridimensional p1(3,2,5);
	p1.mostrar_punto();

return 0;
}

//--------------------------------------------------------------------------------------------------------------------------------
//funciones de la clase unidimensional

void Unidimensional::mostrar_punto()
{
	cout << x << endl;
}

//----------------------------------------------------------------------------------------------------------------------------
//funciones de la clase bidimensional

bidimensional::bidimensional() : Unidimensional()
{
	y = 0;
}

bidimensional::bidimensional(int a, int b) : Unidimensional(a)
{
	y = b;
}

void bidimensional::mostrar_punto()
{
	Unidimensional::mostrar_punto();
	cout << y << endl;
}

//-------------------------------------------------------------------------------------------------------------------------------
//funciones de la clase tridimensional

tridimensional::tridimensional() : bidimensional()
{
	z = 0;
}

tridimensional::tridimensional(int a, int b, int c) : bidimensional(a, b)
{
	z = c;
}

void tridimensional::mostrar_punto()
{
	bidimensional::mostrar_punto();
	cout << z << endl;
}


