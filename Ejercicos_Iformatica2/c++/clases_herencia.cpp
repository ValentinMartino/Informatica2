#include <iostream>
#include <cstring>

using namespace std;
//clase padre Animal
class Animal
{
	public:
	//constructor predeterminado
	Animal();
	//constructor normal
	Animal(int patas, string esp);
	
	//setters
	void setter_patas(int patas);
	void setter_especie(string esp);
	
	//getters
	int ret_patas();
	string ret_especie();
	
	//otras funciones
	virtual void imprime_animal();

	//datos de animal
	protected:
	
	int n_patas;
	string especie;

};

//-----------------------------------------------------------------------------------------------------------------------------------------
//clase hija perro
class Perro : public Animal 
{
	
	public:
	//constructores de perro
	Perro();
	Perro(string raz, int patas, string esp);
	
	//setters de perro
	void setter_raza(string raz);
	
	//getters de perro
	string ret_raza();
	
	//otras funciones
	void imprime_animal();
	


	//datos de perro
	private:
	
	string raza;
	


};

//------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
	Perro tito;
	tito.setter_raza("delba");
	tito.setter_especie("mamifero");
	tito.setter_patas(4);
	
	tito.imprime_animal();

return 0;
}

//------------------------------------------------------------------------------------------------------------------------------------------------

// funciones de la clase animal
Animal::Animal()
{
	n_patas = 0;
	especie = "no hay especie";
}

Animal::Animal(int patas, string esp)
{
	n_patas = patas;
	especie = esp;
}

void Animal::setter_patas(int patas)//inicializa el numero de patas
{
	n_patas = patas;
}

void Animal::setter_especie(string esp)//inicializa la especie
{
	especie = esp;
}

int Animal::ret_patas()//devuelve el numero de patas del animal
{
	return n_patas;
}

string Animal::ret_especie()//devuelve la especie del animal
{
	return especie;
}

void Animal::imprime_animal()
{
	cout << "el animal tiene " << n_patas << " patas" << endl;
	cout << "la especie del animal es: " << especie << endl;
}


// -------------------------------------------------------------------------------------------------------------------------------------
//funciones de perro

Perro::Perro() : Animal()
{
	raza = "no hay raza";
}

Perro::Perro(string raz, int patas, string esp) : Animal(patas, esp) 
{
	raza = raz;
}

void Perro::setter_raza(string raz)
{
	raza = raz;
}

string Perro::ret_raza()
{
	return raza;
}

void Perro::imprime_animal()
{
	Animal::imprime_animal();
	Perro::imprime_animal();
	cout << "la raza del perro es: " << raza << endl;
}
