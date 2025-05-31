#include <iostream>//ok
using namespace std;


//podemos hacer cuadrados segun el valor mas pequeño de entre ancho y alto

int porcioniones(int ancho, int alto)
{
	int porci;
	

	if (ancho < 10 || alto < 10)//caso base
	{
		porci = 0;
	}
	else
	{
		if (ancho > alto)
		{
			porci = 1 + porcioniones(ancho - alto, alto);
		}
		else if (alto > ancho)
		{
			porci = 1 + porcioniones(ancho, alto - ancho);
		}
		else //el caso en el que son iguales ancho == alto
		{
			porci = 1;
		}
	}

	return porci;
}

int main()
{
	int ancho, alto;

	cin >> ancho >> alto;

	while (ancho != 0 && alto != 0)
	{

		cout << porcioniones(ancho, alto) << "\n";
		cin >> ancho >> alto;
	}

	return 0;
}