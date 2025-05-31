#include <iostream> //ok
using namespace std;

int nPruebas(int casos,int* test)
{
	int n;

	if (casos == 1) //para una sola muestra se hace un unico test
	{
		n = 1;	
	}
	else
	{
		//si pn es 0, todos son negativos, si es 1, es positivo algunos
		int suma = 0;
		for (int i = 0; i < casos; i++) //leemos todos los test
		{
			suma += test[i];
		}
		//cout << suma << " ";
		if (suma == 0)
		{
			n = 1;
		}
		else
		{
			if (casos % 2 == 0)
			{
				int* test1 = new int[casos / 2];
				int* test2 = new int[casos / 2];

				for (int i = 0; i < casos/2; i++)
				{
					test1[i] = test[i];
					test2[i] = test[i + casos / 2];
				}

				n = 1 + nPruebas(casos / 2, test1) + nPruebas(casos / 2, test2);

				delete[] test1;
				delete[] test2;
			}
			else
			{
				int* test1 = new int[casos / 2 + 1];
				int* test2 = new int[casos / 2];

				for (int i = 0; i < casos / 2 + 1; i++)
				{
					test1[i] = test[i];
				}

				for (int i = 0; i < casos/2; i++)
				{
					test2[i] = test[i + casos / 2 + 1];
				}

				
				n = 1 + nPruebas(casos / 2 + 1, test1) + nPruebas(casos / 2, test2);

				delete[] test1;
				delete[] test2;
			}

		}
	}
	return n;
}

int main()
{
	int casos;

	cin >> casos;
	int* test = new int[casos];

	int total;
	cin >> total; //leemos todos los test

	for (int i = casos - 1; i >= 0; i--)  //los organizamos en un array dinamico del mismo orden
	{
		test[i] = total % 10;
		total = total / 10;
	}
	cout << nPruebas(casos,test);

	delete[] test;
	return 0;
}