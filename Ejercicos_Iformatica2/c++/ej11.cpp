#include <iostream>

using namespace std;

class Vectores
{
	public:
	//constructor
	inline Vectores(int a, int b, int c)
	{
		x = a; 
		y = b; 
		z = c;
	};
	
	//otra funcion
	int comparar1(Vectores , Vectores);
	int comparar2(Vectores &p, Vectores &m);
	//void comparar(Vectores , Vectores);
	
	private:
	
	int x;
	int y;
	int z;

};

//-----------------------------------------------------------------------------------------------------------------

int main()
{
Vectores p(3,2,3);
Vectores m(1,2,3);
if(p.comparar1(p , m) == 1)
{
	cout << "son iguales " << endl;
}
else
{
	cout << "son distintos " << endl;
}

return 0;
}

//------------------------------------------------------------------------------------------------------------------

int Vectores::comparar1(Vectores p, Vectores m)
{
	if(p.x == m.x && p.y == m.y && p.z == m.z)
		return 1;
	else 
		return 0;
}

int Vectores::comparar2(Vectores &p, Vectores &m)
{
	if(p.x == m.x && p.y == m.y && p.z == m.z)
		return 1;
	else 
		return 0;
}
