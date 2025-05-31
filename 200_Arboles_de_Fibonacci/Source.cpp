#include <iostream> //mas o menos, no lo pillo
using namespace std;


int fib(int entero)
{
	if (entero == 0)
	{
		return 0;
	}
	else if(entero == 1)
	{
		return 1;
	}
	else
	{
		return fib(entero - 2) + fib(entero - 1);
	}
}


void arbol(int n)
{
	cout << endl << fib(n) << "			" << "\n";

	if (n == 0 || n == 1)
	{
		return;
	}
	else
	{
		cout << "			" << fib(n - 2) << endl << "			" << fib(n - 1) << endl;
	}
}

int main()
{
	int entero;

	cin >> entero;


	
	while (entero >= 0)
	{
		arbol(entero);
		cout << "====" << endl;
		cin >> entero;
	}


	return 0;
}