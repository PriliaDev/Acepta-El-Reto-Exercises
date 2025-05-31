#include <iostream> //ok pero faltan condiciones
#include <iomanip>
#include <string>
using namespace std;

//en una espiral,se empieza desde el centro y siempre si tiene que dejar un carril como vacio (si es posible)
//las espiras comienzan en el centro, exactamente en la columna n/2 y fila n/2 (debiendo de ser impar el cuadrado)
//no hacemos prevencion de entradas, dado que suponemos que la entrada dada sera correcta

int main()
{
	int n,suma;
	cin >> n;
	
	while (n != 0)
	{
		suma = 0;
		//creamos un array dinamico bidimensional del dato
		int** matriz = new int*[n];						//asignamos la primera dimension de las filas (ahora mismo es un aarray dinamico de punteros)
		
		for (int i = 0; i < n; i++)
		{
			matriz[i] = new int[n];						//cada fila le asignamos n columnas, conviertiendo esto en un array dinamico que almacena array dinamicos de n datos del tipo int, basicamente un matriz bidimensional
		}


		for (int i = 0; i < n; i++)						//leemos todos los datos de la matriz
		{
			for (int j = 0; j < n; j++)
			{
				cin >> matriz[i][j];
			}
		}

		suma += matriz[n / 2][n/2];						//añadimos el que se encuentra exactamente en el centro

		//SI NOS DAMOS CUENTA LA ESPIRAL LO QUE HACE ES DESPLAZARSE 1 CASILA EXTRA CADA DIRECCION
		//se repite un recorrido exacto, arriba, derecha, abajo izquierda
		
		int posF = n / 2;
		int posC = n / 2;

		int aux = 0;

		while (aux < n)												//es < n, dado que si aux ya es n, quiere decir que al hacer aux++ e intentar coger los datos de una direccion cojeremos datos invalidos, dado que estará fuera de n
		{
			
			aux++;
			if (aux <= n)											// todos se ejecutran solo y solo si cumple ser iguales o mas pequeñas que n y una condicion para no volver a repetirse
			{
				//subimos segun aux (subir en esta matriz es restar )
				for (int i = 1; i <= aux; i++)
				{
					if (posF - 1 >= 0)								//condicion para que en el momento que se aleje de los limites de la matriz no acceda a posiciones ilegalos
					{												//si de da el caso quiere decir que es la ultima vuelta, y el siguiente aux++ > n
						posF--;
						suma += matriz[posF][posC];
					}
				}
				cout << suma << " ";
			}
			
			aux++;//cambiamos de direccion por lo que aumentan las celdas
			if ((posF != 0 || posC != 0) && aux <= n) 
			{
				//derecha segun aux++
				for (int i = 1; i <= aux; i++)
				{
					
					if (posC + 1 < n)
					{
						posC++;
						suma += matriz[posF][posC];
					}
				}
				cout << suma << " ";
			}
			
			aux++;//cambiamos de direccion por lo que aumentan las celdas
			if ((posC != n - 1 || posF != 0) && aux <= n)
			{
				//abajo segun aux++
				for (int i = 1; i <= aux; i++)
				{
					if (posF + 1 < n)
					{
						posF++;
						suma += matriz[posF][posC];
					}
				}
				cout << suma << " ";
			}
			

			aux++;//cambiamos de direccion por lo que aumentan las celdas
			if (aux <= n)
			{
				//izquierda segun aux++
				for (int i = 1; i <= aux; i++)
				{
					if (posC - 1 >= 0)
					{
						posC--;
						suma += matriz[posF][posC];
					}
				}
				cout << suma << " ";
			}
			
		}

		cout << suma;

		for (int i = 0; i < n; i++)
		{
			delete[] matriz[i];							//barramos las n columnas asignadas a cada fila
		}
		delete[] matriz;								//borramos el array dinamico principal

		cin >> n;
	}
	//_CrtDumpMemoryLeaks();

	return 0;
}