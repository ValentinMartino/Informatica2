#include <iostream>
#define CANT 10

using namespace std;

class Conjunto
{
	public:
	//constructor
	Conjunto();
	Conjunto(int cop[]);
	//destructor
	~Conjunto(){};
	//otras funciones
	int agregar(int a);//en esta funcion se le puede agregar al conjunto el valor que deseea
	void vacia();//se vacia el arreglo completamente
	void eliminar(int a);//se elimina el valor que desee si es que esta en el arreglo
	void copiar(Conjunto b);//se copia el conjunto a otro que usted desee
	void imprimir();//se imprime el conjunto de valores

	private:
	int arr[CANT];
	void ordenar_arreglo();
};

//----------------------------------------------------------------------------------------------------------------------------

int main()
{
	Conjunto a;
	Conjunto b;

	a.agregar(3);
	a.agregar(5);
	a.agregar(7);
	a.agregar(2);
	a.agregar(8);
	
	a.copiar(b);
	a.imprimir();
	b.imprimir();
	
return 0;
}

//-----------------------------------------------------------------------------------------------------------------------------
//funciones de la clase conjunto
Conjunto::Conjunto()
{
	for(int i = 0; i < CANT; i++)
	{
		arr[i] = 0;
	}
}

Conjunto::Conjunto(int cop[])
{
	for(int i = 0; i < CANT; i++)
	{
		arr[i] = cop[i];
	}
}
void Conjunto::ordenar_arreglo()
{
	int aux;
	
	
	for(int i = 0; i<CANT ; i++)
        {
            for(int j = 0; j<CANT ; j++)
            {
                if (arr[j] > arr[j+1])
                {
                                aux = arr[j];
                                arr[j] = arr[j+1];
                                arr[j+1] = aux;
                }
            }
        }
	
}

int Conjunto::agregar(int a)
{
	for(int i = 0; i < CANT; i++)
	{
		if(arr[i] == a)
		{
			return 0;
		}
		
		if(arr[i] == 0 || arr[i] != a)
		{
			arr[i] = a;
		}
	}
	ordenar_arreglo();
	return 0;
}

void Conjunto::vacia()
{
	for(int i = 0; i < CANT; i++)
	{
		arr[i] = 0;
	}
}

void Conjunto::eliminar(int a)
{
	for(int i = 0; i < CANT; i ++)
	{
		if(arr[i] == a)
		{
			arr[i] = 0;
		}
	}
	ordenar_arreglo();
}

void Conjunto::imprimir()
{
	for(int i = 0; i < CANT; i++)
	{
		cout << arr[i] << endl;
	}
}

void Conjunto::copiar(Conjunto b)
{
	for(int i = 0; i < CANT; i++)
	{
		arr[i] = b.arr[i];
	}
}
