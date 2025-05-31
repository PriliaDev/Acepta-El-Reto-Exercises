#include <iostream> //OK sin enviar y ajustar bien la salida
using namespace std;


int main()
{
	int f,c;

	cin >> f >> c;

	char** sala = new char* [f];
	for (int i = 0; i < f; i++)
	{
		sala[i] = new char[c];
	}
	
	for (int i = 0; i < f; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> sala[i][j];
		}
	}

	int consultas;

	cin >> consultas;

	int fila, columna;
	string direccion;
	for (int i = 0; i < consultas; i++)
	{
		cin >> fila >> columna >> direccion;

		fila = fila - 1;
		columna = columna - 1;

		int nceldas = 0;
		int nceldasEnemigo = 0;;
		if (direccion == "ARRIBA")
		{
			for (int j = fila - 1; j >= 0; j--)
			{
				nceldasEnemigo++;
				
				if (sala[j][columna] == 'X')
				{
					nceldas = nceldasEnemigo;
					break;
				}
			}
		}
		else if (direccion == "ABAJO")
		{
			for (int j = fila + 1; j < f ; j++)
			{
				nceldasEnemigo++;
				if (sala[j][columna] == 'X')
				{
					nceldas = nceldasEnemigo;
					break;
				}
			}
		}
		else if (direccion == "DERECHA")
		{
			for (int j = columna + 1; j < c; j++)
			{
				nceldasEnemigo++;
				if (sala[fila][j] == 'X')
				{
					nceldas = nceldasEnemigo;
					break;
				}
			}
		}
		else
		{
			for (int j = columna - 1; j >= 0; j--)
			{
				nceldasEnemigo++;
				if (sala[fila][j] == 'X')
				{
					nceldas = nceldasEnemigo;
					break;
				}
			}
		}

		if (nceldas == 0)
		{
			cout << "NINGUNO" << endl;
		}
		else
		{
			cout << nceldas << endl;
		}
	}



	for (int i = 0; i < f; i++)
	{
		delete [] sala[i];
	}
	delete[] sala;
	return 0;
}