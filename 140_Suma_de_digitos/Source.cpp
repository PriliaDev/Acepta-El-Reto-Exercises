#include <iostream> //ok
using namespace std;


//metodo recursivo
int sumaDigitos(int entero)
{
	int suma;

	if (entero == 0)
	{
		suma = 0;
	}
	else
	{
		cout << entero % 10 << " + ";
		suma = sumaDigitos(entero / 10) + entero % 10;
	}


	return suma;
}

//este ejericio tiene mucho mas sentido de forma iterativa
// % 10 consigues la ultima cifra
// con /10 quitas la ultima cifra

int main()
{
	int entero;

	cin >> entero;


	int suma;
	while (entero != -1)
	{
		suma = sumaDigitos(entero);
		cout << "= " << suma;
		cin >> entero;
	}


	return 0;
}