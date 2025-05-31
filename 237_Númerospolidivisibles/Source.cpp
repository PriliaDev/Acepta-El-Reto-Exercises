#include <iostream> //ok
using namespace std;

// un número es polidivisible si es divisible por su longitud y, además, si se le quita el último dígito queda un número que es a su vez polidivisible.

bool Polidivisible(int n)
{
    bool loEs;
    //1ºobtenemos el numero de cifras
    int cifras = 0;
    int aux = n;
    while(aux != 0)
    {
        aux = aux / 10;
        cifras++;
    }
    
    if (n % cifras == 0) //osea es divisible entre su longitud de cifras
    {
        if (cifras == 1) //caso base siempre cierto, todo es divisible entre 1
        {
            loEs = true;
        }
        else
        {
            loEs = Polidivisible(n / 10);//le quitamos la ultima cifra
        }
    }
    else //si no es divisible por ende el mismo No puede ser polodivisible
    {
        loEs = false;
    }

    return loEs;
}


int main()
{
    int n;
    
    cin >> n;

    if (Polidivisible(n))
    {
        cout << "POLIDIVISIBLE";
    }
    else
    {
        cout << "NO POLIDIVISIBLE";
    }

    return 0;
}