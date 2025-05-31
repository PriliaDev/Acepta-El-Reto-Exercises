#include <iostream> //revisar
using namespace std;


const long long MOD = 1000000007; 

//lo que hara %mod es que se permite calcular todos los numeros a excpecio de aquellso que superen a aMOD
//dado que n > MOD % Mod = n y n >= MOD % MOD = 0

//la idea noe s hacerlo recursiovo, pera para ver como seria recursivo
long long bonacci(int n, long long x, long long y) {
    // Casos base:
    if (n == 0)
        return x % MOD;
    if (n == 1)
        return y % MOD;

    // Inicializamos dos variables:
    long long a = x % MOD;  // Representa F0(x,y)
    long long b = y % MOD;  // Representa F1(x,y)
    long long c;            // Variable auxiliar para F(n) en cada paso

    // Bucle iterativo desde 2 hasta n
    for (int i = 2; i <= n; i++) {
        c = (a + b) % MOD;  // Calculamos F(i) = F(i-1) + F(i-2) (aplicamos el módulo)
        a = b;              // Actualizamos a: ahora a (F(i-2)) pasa a ser el antiguo F(i-1)
        b = c;              // Actualizamos b: ahora b es el F(i) recién calculado
    }

    // Al salir del bucle, b es F(n) mod MOD.
    return b;
}


int main()
{
	int n,x,y;

	cin >> n >> x >> y;

	
	cout << bonacci(n, x, y);


	return 0;
}