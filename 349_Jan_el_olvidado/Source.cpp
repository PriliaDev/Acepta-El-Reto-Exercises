#include <iostream>//ok
using namespace std;

int evalPrefix() {
    char ch;
    // Lee el siguiente car�cter (salta espacios y saltos de l�nea)
    cin >> ch;

    // Si es un operador, evaluamos recursivamente los dos operandos.
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        int op1 = evalPrefix(); // Primer operando
        int op2 = evalPrefix(); // Segundo operando
        switch (ch) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2; // Se pide divisi�n entera y se garantiza que no habr� divisi�n por cero.
        }
    }

    // Si no es operador, se supone que es un d�gito.
    // La conversi�n de car�cter a entero se hace restando el c�digo de '0'.
    return ch - '0';
}


int operacion() //el truco esta, es que si lee un signo, intentar leer un numero pero se encuntra otro signo, este mismo calculara lo relativo de ese signo y luego devolvera lo op
{
    int salida;
    char caracter;

    cin >> caracter; //ignorara espacios

    if (caracter == '+' || caracter == '-' || caracter == '*' || caracter == '/')
    {
        int op1 = operacion(); // hacemos que la recursion leea el digito y no entre en este if, devolviendo exactamente el digito
        int op2 = operacion(); // 
        switch (caracter)
        {
            case '+': 
            { 
                salida = op1 + op2;
            }
            break;
            case '-':
            {
                salida = op1 - op2;
            }
            break;
            case '*':
            {
                salida = op1 * op2;
            }
            break;
            case '/':
            {
                salida = op1 / op2;
            }
            break;
        }
    }
    else
    {
        salida = caracter - '0';
    }


    return salida;
}



int main() {
    int nCasos;
    cin >> nCasos; // Lee la cantidad de casos de prueba

    // Para cada caso, se eval�a la expresi�n en notaci�n polaca.
    for (int i = 0; i < nCasos; i++) {
        int resultado = operacion();
        cout << resultado << "\n";
    }

    return 0;
}


/*
cout << "Siguiente car�cter en el buffer (como char): " << char(nextChar) << endl;
cout << "Valor ASCII del siguiente car�cter: " << nextChar << endl;

*/