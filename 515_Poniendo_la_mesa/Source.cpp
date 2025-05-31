#include <iostream> //ok
using namespace std;

//el pequeño lleba copas de 1 en 1, el mayor de 1 en 1 se quedan n impara copas, si es par de 2 en 2
//el pequeño da el primer paseo

int paseos(int nCopas, bool pequeño)
{
	int n;

	if (nCopas == 0)
	{
		n = 0;
	}
	else
	{
		if (pequeño)	//si le toca el pequeño
		{

			n = 1 + paseos(nCopas - 1,false);
		}
		else
		{
			if (nCopas % 2 != 0)
			{
				n = 1 + paseos(nCopas - 1,true);
			}
			else
			{
				n = 1 + paseos(nCopas - 2,true);
			}
		}
	}

	return n;
}

int main()
{
	int casos;
	cin >> casos;
	int nCopas;
	for (int i = 0; i < casos; i++)
	{
		cin >> nCopas;
		cout << paseos(nCopas,true) << endl;
	}
	return 0;
}