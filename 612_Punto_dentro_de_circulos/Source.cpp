#include <iostream>//ok
using namespace std;

//x e y representar las corrdenadas de un punto

//para comprobar que el punto esta dentro del circulo, ajustaremos el sistema de referencia segun donde estemos

//De forma que, si vamos hacia a la izquierda x + r,y
//si vamos a la derecha x - r,y
//si vamos hacia arriba x,y - r
//si vamos hacia abajo x,y + r
//esto nos dara las coordenadas del punto segun un nuevo sistema de referencia en el centro del circulo a analizar


//para comprobar si lo contiene seria:
//Segun el T.pitágoras, si x^2 + y^2 <= r^2, quiere decir que esta contenido en el circulo


bool comprobaciones(int r, int x, int y)
{
	return (x * x + y * y <= r * r);
}

int circulo(int r, int x, int y)
{
	int ncirculos;
	
	if (r == 1) //quiere decir que hemos llegado al ultimo circulo
	{
		if (comprobaciones(r, x, y))
		{
			ncirculos = 1;
		}
		else
		{
			ncirculos = 0;
		}
	}
	else
	{
		if (comprobaciones(r, x, y))
		{
			ncirculos = 1;
		}
		else
		{
			ncirculos = 0;
		}

		//añadimos lo de la izquierda
		ncirculos += circulo(r / 2, x + r, y);
		//derecha
		ncirculos += circulo(r / 2, x - r, y);
		//arriba
		ncirculos += circulo(r / 2, x, y - r);
		//abajo
		ncirculos += circulo(r / 2, x, y + r);
	}




	return ncirculos;
}


	


int main()
{
	int radio, x, y;

	cin >> radio >> x >> y;

	cout << circulo(radio, x, y);

	return 0;
}