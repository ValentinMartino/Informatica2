#include <iostream>
#include <cstring>

using namespace std;

class Fecha
{
	public:
	//constructor
	Fecha(){ano = mes = dia = 0;}
	Fecha(int a, int m, int d);
	//destructor
	~Fecha(){};
	//setter
	void set_fecha(int a, int m, int d);
	//otras funciones
	void mostrar_fecha() const;
	
	
	private:
	int ano;
	int dia;
	int mes;

};

//----------------------------------------------------------------------------------------------------------------------------------

class Publicacion
{
	public:
	//constructor
	Publicacion(){}
	Publicacion(string edi, int a, int m, int d);
	//destructor
	~Publicacion(){};
	//setters
	void set_editorial(string edi){editorial = edi;}
	void set_fecha_publicacion(int a, int m, int d){fecha_publicacion.set_fecha(a,m,d);}
	//getters
	string ret_editorial(){return editorial;}
	Fecha ret_fecha_publicacion(){return fecha_publicacion;}
	//otras funciones
	
	virtual void mostrar_publicacion();

	private:
	string editorial;
	Fecha fecha_publicacion;

};

//-------------------------------------------------------------------------------------------------------------------------------

class Libro : public Publicacion
{
	public:
	//constructores
	Libro(){}
	Libro(int cod, string aut,string edi, int a, int m, int d);
	//destructor
	~Libro(){};
	//setter
	void set_codigo(int cod){codigo = cod;}
	void set_autor(string aut){autor = aut;}
	//getters
	int get_codigo(){return codigo;}
	string get_autor(){return autor;}
	//otras funciones
	void mostrar_publicacion();



	private:
	int codigo;
	string autor;

};

//----------------------------------------------------------------------------------------------------------------------------------
class Revista : public Publicacion
{
	public:
	//constructores
	Revista(){}
	Revista(int ej_a, int ej_c,string edi, int a, int m, int d);
	//destructor
	~Revista(){};
	//setter
	void set_ej_ano(int ej_a){ej_ano = ej_a;}
	void set_ej_circulando(int ej_c){ej_circulando = ej_c;}
	//getters
	int get_ej_ano(){return ej_ano;}
	int get_ej_circulando(){return ej_circulando;}
	//otras funciones
	void mostrar_publicacion();



	private:
	int ej_ano;
	int ej_circulando;

};

//-------------------------------------------------------------------------------------------------------------------------------
class Martin : public Libro
{
	public:
	Martin(){}
	Martin(int num_pag,int cod, string aut,string edi, int a, int m, int d);
	//setter
	void set_num_pags(int num_pag){num_pags = num_pag;}
	//getters
	int get_num_pags(){return num_pags;}
	//otras publicaciones
	void mostrar_publicacion();

	private:
	int num_pags;


};

//----------------------------------------------------------------------------------------------------------------------------------

int main()
{
	Martin fierro(778,82263,"gino","nemo",2010,6,30);
	
	fierro.mostrar_publicacion();
	

return 0;
}


//--------------------------------------------------------------------------------------------------------------------------------
//funciones de fecha

Fecha::Fecha(int a, int m, int d)
{
	ano = a;
	mes = m;	
	dia = d;
}

void Fecha::set_fecha(int a, int m, int d)
{
	ano = a;
	mes = m;
	dia = d;
}

void Fecha::mostrar_fecha() const
{
	cout << dia << "/" << mes << "/" << ano << endl;
}

//----------------------------------------------------------------------------------------------------------------------------------
//funciones de publicacion

Publicacion::Publicacion(string edi, int a, int m, int d) : fecha_publicacion(a ,m ,d)
{
	editorial = edi;
}

void Publicacion::mostrar_publicacion()
{
	cout << "editorial: " << editorial << endl;
	fecha_publicacion.mostrar_fecha();
}

//-----------------------------------------------------------------------------------------------------------------------------------
//funciones de la clase libro

Libro::Libro(int cod,string aut ,string edi, int a, int m, int d) : Publicacion(edi, a, m, d)
{
		codigo = cod;
		autor = aut;
}

void Libro::mostrar_publicacion()
{
	Publicacion::mostrar_publicacion();
	cout << "el autor es: " << autor << endl;
	cout << "el codigo es: " << codigo << endl;
}

//------------------------------------------------------------------------------------------------------------------------------
//funciones de la clase revista

Revista::Revista(int ej_a, int ej_c,string edi, int a, int m, int d) : Publicacion(edi, a, m, d)
{
		ej_ano = ej_a;
		ej_circulando = ej_c;
}

void Revista::mostrar_publicacion()
{
	Publicacion::mostrar_publicacion();
	cout << "los ejemplares por año son: " << ej_ano << endl;
	cout << "los ejemplares circulando son: " << ej_circulando << endl;
}

//-------------------------------------------------------------------------------------------------------------------------------
//funciones de la clase Martin

Martin::Martin(int num_pag,int cod, string aut,string edi, int a, int m, int d) : Libro(cod,aut ,edi, a, m, d)
{
	num_pags = num_pag;
}

void Martin::mostrar_publicacion()
{
	Libro::mostrar_publicacion();
	cout << "el numero de paginas es: " << num_pags << endl;
}




