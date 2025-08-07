#include <iostream>

using namespace std;

// Función para búsqueda secuencial
int bus_secuencial(int arr[], int largo, int k)
{
    int i, j, temp;
    i = 0;
    while (i < largo && arr[i] != k)//La iteración termina cuando:
    //1) hemos recorrido todo el arreglo
    //2) hemos encontrado el elemento a buscar "k"
    {
        i++;//aumentamos el índice, es decir, seguimos recorriendo el arreglo
    }
    if (i < largo)//si el índice está dentro del rango del arreglo
        return (i); // Devuelve la posición donde se encontró el elemento
    else
        return (-1); // Devuelve -1 si el elemento no se encuentra en el arreglo
}

// Función de ordenamiento Burbuja
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

// Función de ordenamiento Selección
void ord_seleccion(int arr[], int largo)
{
    int i, j, minimo, temp;

    for (i = 0; i <= largo - 2; i++)
    {
        minimo = i;
        for (j = i + 1; j <= largo - 1; j++)
        {
            if (arr[j] < arr[minimo])
                minimo = j; // Encuentra el índice del elemento mínimo en el subarreglo restante
        }
        temp = arr[i];
        arr[i] = arr[minimo];
        arr[minimo] = temp; // Intercambia el elemento mínimo con el elemento actual
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

