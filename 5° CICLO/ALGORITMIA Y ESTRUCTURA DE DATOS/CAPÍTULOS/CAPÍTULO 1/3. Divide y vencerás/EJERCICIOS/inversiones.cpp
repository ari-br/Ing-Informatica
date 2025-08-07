#include <iostream>

/*
Dado un arreglo de enteros, encontrar el número de inversiones.
Una inversión es un par de elementos A[i] y A[j] tal que i < j y
A[i] > A[j].

Ejemplo:
Entrada: {1, 20, 6, 4, 5}
El número de inversiones es: 5
(20, 6)
(20, 4)
(20, 5)
(6, 4)
(6, 5)
*/

// fusionar dos subarrays y contar inversiones
int fusionarYContar(int arr[], int temp[], int izquierda, int medio, int derecha) {
    int i = izquierda;   // index del subarray izquierdo
    int j = medio + 1;   // index del subarray derecho
    int k = izquierda;   // index del subarray fusionado
    int inversiones = 0;

    while (i <= medio && j <= derecha) {
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++];
        } else { //arr[i] > arr[j]
            temp[k++] = arr[j++];
            inversiones += (medio - i + 1); // conteo de inversiones
            /*
            Si arr[i] > arr[j] (donde i está en el subarray izquierdo y j en el derecho), 
            entonces todos los elementos restantes en el subarray izquierdo 
            también serán mayores que arr[j].
            */
        }
    }
    //pasar restantes
    while (i <= medio) temp[k++] = arr[i++];
    while (j <= derecha) temp[k++] = arr[j++];
    //regresar el temporal al array original
    for (i = izquierda; i <= derecha; i++)  arr[i] = temp[i];

    return inversiones;
}

int contarInversionesRec(int arr[], int temp[], int izquierda, int derecha) {
    int inversiones = 0;
    if (izquierda < derecha) {
        int medio = (izquierda + derecha) / 2;
        //contar por la izquierda
        inversiones += contarInversionesRec(arr, temp, izquierda, medio);
        // contar por la derecha
        inversiones += contarInversionesRec(arr, temp, medio + 1, derecha);
        // contar durante la fusión de las dos mitades
        inversiones += fusionarYContar(arr, temp, izquierda, medio, derecha);
    }
    return inversiones;
}

int contarInversiones(int arr[], int n) {
    int *temp = new int[n];//para evitar creer varios arrays temporales
    int inversiones = contarInversionesRec(arr, temp, 0, n - 1);
    delete[] temp;
    return inversiones;
}

int main() {
    int arr[] = {1, 20, 6, 4, 5};
    int n = 5;
    int inversiones = contarInversiones(arr, n);
    std::cout << "El número de inversiones es: " << inversiones << std::endl;
    return 0;
}
