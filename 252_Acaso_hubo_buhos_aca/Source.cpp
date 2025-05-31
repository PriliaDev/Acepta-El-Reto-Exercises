#include <iostream> //ok
#include <string>		//mirar estas nuevas librerias, lo de cin.peek, cin eof, etc
#include <algorithm>
#include <cctype>
using namespace std; //lo de cin peek es interesante

bool palindromoIterativo(string palabra)
{
	for (int i = 0; i < palabra.size(); i++)
	{
		cout << palabra[i] << " " << palabra[palabra.size() - i - 1] << endl;
		if (palabra[i] == palabra[palabra.size() - i - 1])
		{
			if (i = palabra.size() - 1)
			{
				return true;
			}

		}
		else
		{
			return false;
		}
	}
}

bool palindromoRecursivo(string palabra, int indice)
{
	bool loEs;
	if (indice == palabra.size() / 2)		//si llega a la mitad es cierto	
	{
		loEs = true;
	}
	else if (palabra[indice] != palabra[palabra.size() - 1 - indice])
	{
		loEs = false;
	}
	else
	{
		loEs = palindromoRecursivo(palabra, indice + 1);
	}

	return loEs;
}

int main()
{
	string palabra;

	getline(cin, palabra);

	// Elimina todos los espacios (y cualquier carácter de espacio en blanco)
	palabra.erase(std::remove_if(palabra.begin(), palabra.end(), ::isspace), palabra.end());

	// Convierte todos los caracteres a minúsculas
	std::transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);

	cout << palabra;
	if (palindromoRecursivo(palabra, 0))
	{
		cout << "SI";
	}
	else
	{
		cout << "NO";
	}


	return 0;
}