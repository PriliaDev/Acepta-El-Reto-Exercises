#include <iostream>
using namespace std;

const int MAX = 50; //max de cubos posibles
const int MIN = 1;

int main()
{
    int f, c;

    cin >> f >> c;

    int** pixeles = new int*[f * 3]; //generamos un array dinamico cuyos datos son punteros que apuntan a un tipo int
    for (int i = 0; i < f*3; i++) {
        pixeles[i] = new int[c*3];  //  Cada puntero ahora apunta a un array dinámico de enteros
    }
    

    for (int i = 0; i < f*3; i++)
    {
        for (int j = 0; j < c*3; j++)
        {
            cin >> pixeles[i][j];
        }
    }

    int cubosAcolocar;

    cin >> cubosAcolocar;

    int*** cubos = new int **[cubosAcolocar]; //array dinamico de punteros a puntertos a datos int
    for (int i = 0; i < cubosAcolocar; i++) //para cada array dinamicos, que son los subos a colocar creamos un array dinamico para las filas
    {
        cubos[i] = new int* [3];
        for (int j = 0; j < 3; j++)         //para cada puntero de filas sera un array dinamico que diriga a las columnas, y por ende a los datos estaticos
        {
            cubos[i][j] = new int[3];
        }
    }

    for (int x = 0; x < cubosAcolocar; x++)
    {
        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++)         
            {
                cin >> cubos[x][i][j];
            }
        }
    }


    for (int x = 0; x < cubosAcolocar; x++) //para ver lo de ambos cubos
    {
        int i = 0, j = 0;;
        bool encontrado = false;
        while (i < f * 3 && j < c * 3 && !encontrado)
        {
            encontrado = true; //hasta que se demuestre lo contrario

            for (int z = 0; z < 3; z++)
            {
                for (int k = 0; k < 3;k++)
                {
                    if (pixeles[i + z][j + k] != cubos[x][z][k])
                    {
                        encontrado = false;
                    }
                }
            }

            if (encontrado)
            {
                cout << i << " " << j;
            }

            i = i + 3;
            j = j + 3;
        }
    }






    //para el pimer array dinamico
    for (int i = 0; i < f * 3; i++) //elinamicos todos los puntero que se habian convertido en arrays dinamicos
    {
        delete[] pixeles[i];
        pixeles[i] = nullptr;
    }
    delete[] pixeles; //eliminar el primer array dinamico
    pixeles = nullptr;


    //para el segundo array dinamico
    for (int i = 0; i < cubosAcolocar; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            delete[] cubos[i][j];
            cubos[i][j] = nullptr;
        }
        delete[] cubos[i];
        cubos[i] = nullptr;
    }
    delete[] cubos;
    cubos = nullptr;
    return 0;
}