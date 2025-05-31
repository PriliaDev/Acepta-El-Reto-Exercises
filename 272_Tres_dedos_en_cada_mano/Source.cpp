#include <iostream> //ok
#include <string>		
using namespace std; 


double bseisadiez(int n)
{
	double numero = n / 6;
	return 10.0 * n/6;
}

int main()
{
	int n;

	cin >> n;
	cout << bseisadiez(n);

	return 0;
}