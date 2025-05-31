#include <iostream> //ok
#include <iomanip>
#include <string>
using namespace std;


int main()
{
	int n;

	cin >> n;
	string cadena;

	for (int i = 0; i < n; i++)
	{
		int nPuntuaciones;

		cin >> nPuntuaciones;
		cin.ignore(10000, '\n');		//habia un puto espacio en blanco que jodia el buffer

		string *saux = new string[nPuntuaciones];

		for (int x = 0; x < nPuntuaciones; x++)
		{
			getline(cin, saux[x]); 
		}

		
		for (int y = 0; y < 3; y++)
		{
			for (int x = 0; x < nPuntuaciones; x++)
			{
				cadena += (saux[x])[0 + y];
			}
		}
		
		delete[] saux;
	}

	cout << cadena;

	return 0;
}