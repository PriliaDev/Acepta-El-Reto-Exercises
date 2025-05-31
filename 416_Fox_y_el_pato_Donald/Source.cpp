#include <iostream> //ok sin enviar
using namespace std;



int main()
{
	int n;

	cin >> n;

	while (n != 0)
	{
		int* dia = new int[n];
		int* mes = new int[n];

		for (int i = 0; i < n; i++)
		{
			cin >> dia[i];
			cin.ignore(1);
			cin >> mes[i];
			cin.ignore(5);
			
		}

		bool Cumple = false;

		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (dia[i] == dia[j] && mes[i] == mes[j])
				{
					Cumple = true;
				}
				
			}
		}

		if (Cumple)
		{
			cout << "SI";
		}
		else
		{
			cout << "NO";
		}

		delete[] dia;
		dia = nullptr;

		delete[] mes;
		mes = nullptr;
		cin >> n;
	}

	return 0;
}