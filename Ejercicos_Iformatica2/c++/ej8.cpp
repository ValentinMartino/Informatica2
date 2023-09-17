#include <iostream>
#include <cstring>

using namespace std;

class Mamiferos
{
	public:
	//contructores
	Mamiferos();
	Mamiferos(int patas, int mamas, string habita);
	//destructor
	~Mamiferos(){};
	//setters
	void n_pata(int patas);
	void n_mama(int mamas);
	void habita(string habita);
	//getters
	int ret_patas();
	int ret_mamas();
	string ret_habitad();
	//otras funciones
	virtual void mostrar_datos();
	
	protected:
	
	int n_mamas;
	int n_patas;
	string habitad;	
};

//---------------------------------------------------------------------------------------------------------------------------------

class Perro : public Mamiferos
{
	public:
	//construcores
	Perro();
	Perro(int patas, int mamas, string habita, string raz, int altu, int anos);
	//destructor
	~Perro(){};
	//setters
	void raz(string raz);
	void altu(int altu);
	void anos(int anos);
	//getters
	int ret_altu();
	int ret_anos();
	string ret_raz();
	//otras funciones
	void mostrar_datos();

	private:
	string raza;
	int altura;
	int anios;

};

//-----------------------------------------------------------------------------------------------------------------------------------------

int main()
{
	Perro tito(4,6,"domestico","delba",50,12);
	tito.mostrar_datos();




return 0;
}

//------------------------------------------------------------------------------------------------------------------------------------------
//funciones de mamiferos
Mamiferos::Mamiferos()
{
	n_patas = 0;
	n_mamas = 0;
	habitad = "no hay habitad";
}

Mamiferos::Mamiferos(int patas, int mamas, string habita)
{
	n_patas = patas;
	n_mamas = mamas;
	habitad = habita;
}

void Mamiferos::n_pata(int patas)
{
	n_patas = patas;
}

void Mamiferos::n_mama(int mamas)
{
	n_mamas = mamas;
}

void Mamiferos::habita(string habita)
{
	habitad = habita;
}

int Mamiferos::ret_patas()
{
	return n_patas;
}

int Mamiferos::ret_mamas()
{
	return n_mamas;
}

string Mamiferos::ret_habitad()
{
	return habitad;
}

void Mamiferos::mostrar_datos()
{
	cout << "el numero de patas es: " << n_patas << endl;
	cout << "el numero de mamas es: "<< n_mamas << endl;
	cout << "su habitad es: " << habitad << endl;
}

//----------------------------------------------------------------------------------------------------------------------------------------
//funciones de perro
Perro::Perro() : Mamiferos()
{
	altura = 0;
	anios = 0;
	raza = "no hay raza";
}

Perro::Perro(int patas, int mamas, string habita, string raz, int altu, int anos) : Mamiferos(patas, mamas, habita)
{
	altura = altu;
	anios = anos;
	raza = raz;
}

void Perro::altu(int altu)
{
	altura = altu;
}

void Perro::anos(int anos)
{
	anios = anos;
}

void Perro::raz(string raz)
{
	raza = raz;
}

int Perro::ret_altu()
{
	return altura;
}

int Perro::ret_anos()
{
	return anios;
}

string Perro::ret_raz()
{
	return raza;
}

void Perro::mostrar_datos()
{
	Mamiferos::mostrar_datos();
	cout << "la altura es: " << altura << endl;
	cout << "los años que vive: "<< anios << endl;
	cout << "la raza del perro es: " << raza << endl;
}








