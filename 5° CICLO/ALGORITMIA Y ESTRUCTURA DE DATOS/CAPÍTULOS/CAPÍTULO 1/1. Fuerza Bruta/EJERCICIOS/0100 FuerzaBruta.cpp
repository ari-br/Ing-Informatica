#include <iostream>

using namespace std;

// Funci�n para b�squeda secuencial
int bus_secuencial(int arr[], int largo, int k)
{
    int i, j, temp;
    i = 0;
    while (i < largo && arr[i] != k)//La iteraci�n termina cuando:
    //1) hemos recorrido todo el arreglo
    //2) hemos encontrado el elemento a buscar "k"
    {
        i++;//aumentamos el �ndice, es decir, seguimos recorriendo el arreglo
    }
    if (i < largo)//si el �ndice est� dentro del rango del arreglo
        return (i); // Devuelve la posici�n donde se encontr� el elemento
    else
        return (-1); // Devuelve -1 si el elemento no se encuentra en el arreglo
}

// Funci�n de ordenamiento Burbuja
void ord_burbuja(int arr[], int largo)
{
    int i, j, temp;

    for (i = 0; i <= largo - 2; i++)
    {
        cout << endl;
        for (j = 0; j <= largo - 2 - i; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                temp = arr[j];       // Almacena el valor actual en una variable temporal
                arr[j] = arr[j + 1]; // Intercambia los valores para ordenarlos
                arr[j + 1] = temp;
            }
            cout << arr[j] << " "; // Muestra los elementos durante el proceso de ordenamiento
        }
    }
}

// Funci�n de ordenamiento Selecci�n
void ord_seleccion(int arr[], int largo)
{
    int i, j, minimo, temp;

    for (i = 0; i <= largo - 2; i++)
    {
        minimo = i;
        for (j = i + 1; j <= largo - 1; j++)
        {
            if (arr[j] < arr[minimo])
                minimo = j; // Encuentra el �ndice del elemento m�nimo en el subarreglo restante
        }
        temp = arr[i];
        arr[i] = arr[minimo];
        arr[minimo] = temp; // Intercambia el elemento m�nimo con el elemento actual
    }
}

int main()
{
    int cont, valor, n = 8;
    int arreglo[] = {3, 2, 1, 4, 2, 7, 9, 5};

    cout << "Busqueda:";
    valor = bus_secuencial(arreglo, 8, 9);
    cout << valor << endl;

    cout << "Orden:";
    ord_burbuja(arreglo, n);
    cout << endl;
    for (cont = 0; cont < n; cont++)
        cout << arreglo[cont] << " "; // Muestra el arreglo ordenado

    return (0);
}

