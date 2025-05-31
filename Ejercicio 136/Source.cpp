#include <iostream> //ok
using namespace std;


//si la fuerza de los hobbits es X, la fuerza de los enanos será 2x

int particiones(const int fuerza, const double eslabones)
{
	int part;

	if (fuerza >= eslabones || fuerza * 2 >= eslabones) //caso base en el que lo pueden llevar todo los hobits o bien lo pueden llebar todos los enanos
	{
		part = 0;
	}
	else //en caso contrario lo partiremos una vez, dejando un lado con 2/3* eslabon * 1/3 de eslabon (se les asigna el doble a los enanos)
	{
		part = 1 + particiones(fuerza, eslabones * 2 / 3);
	}


	return part;
}

int main()
{
	int Fhobbits,tamano;

	cin >> Fhobbits >> tamano;
	
	while (Fhobbits != 0 && tamano != 0)
	{
		cout << particiones(Fhobbits, tamano) << endl;
		cin >> Fhobbits >> tamano;
	}
	

	

	return 0;
}