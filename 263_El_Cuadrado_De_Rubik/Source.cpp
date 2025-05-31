#include <iostream> //ok sin enviar
using namespace std;

const int MAX = 50;

struct tCara
{
	char color;
};

struct tCuadrado
{
	tCara caras[MAX][MAX];
	int capacidadPorLinea = 0;		//por fila y columna
};

int main()
{
	tCuadrado cuadrado;

	int n = 1;
	do
	{
		cin >> n;
		if (n != 0)
		{
			cuadrado.capacidadPorLinea = n * n;

			for (int i = 0; i < n; i++)	//leemos todos los las fichas
			{
				for (int k = 0; k < n; k++)
				{
					cin >> cuadrado.caras[i][k].color;
				}
			}

			char x,aux;
			int filaOcolumna;

			cin >> x;
			while (x != 'x')
			{
				cin >> filaOcolumna;
				
				
				if (filaOcolumna > 0)
				{
					filaOcolumna = filaOcolumna - 1;
					if (x == 'f')
					{
						aux = cuadrado.caras[filaOcolumna][n - 1].color;

						for (int i = n - 1; i > 0; i--)
						{
							cuadrado.caras[filaOcolumna][i].color = cuadrado.caras[filaOcolumna][i - 1].color;
						}
						cuadrado.caras[filaOcolumna][0].color = aux;

					}
					else
					{
						aux = cuadrado.caras[n - 1][filaOcolumna].color;

						for (int i = n - 1; i > 0; i--)
						{
							cuadrado.caras[i][filaOcolumna].color = cuadrado.caras[i - 1][filaOcolumna].color;
						}
						cuadrado.caras[0][filaOcolumna].color = aux;
					}

				}
				else
				{
					filaOcolumna = -filaOcolumna - 1;
					if (x == 'f')
					{
						aux = cuadrado.caras[filaOcolumna][0].color;

						for (int i = 0; i < n - 1; i++)
						{
							cuadrado.caras[filaOcolumna][i].color = cuadrado.caras[filaOcolumna][i + 1].color;
						}
						cuadrado.caras[filaOcolumna][n - 1].color = aux;

					}
					else
					{
						aux = cuadrado.caras[0][filaOcolumna].color;

						for (int i = 0; i < n - 1; i++)
						{
							cuadrado.caras[i][filaOcolumna].color = cuadrado.caras[i + 1][filaOcolumna].color;
						}
						cuadrado.caras[n - 1][filaOcolumna].color = aux;
					}

				}

				cin >> x;
			}

			for (int i = 0; i < n; i++)
			{
				for (int h = 0; h < n; h++)
				{
					cout << cuadrado.caras[i][h].color;
				}
				cout << endl;
			}
			cout << "---" << endl;

		}
	} while (n != 0);

	return 0;
}
