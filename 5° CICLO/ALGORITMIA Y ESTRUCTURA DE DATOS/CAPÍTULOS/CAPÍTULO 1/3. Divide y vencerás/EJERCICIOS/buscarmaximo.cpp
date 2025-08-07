#include <iostream>

/*
Dado un arreglo de enteros el cual primero crece y luego decrece.
Encontrar el máximo valor en el arreglo.
Ejemplo:
Entrada:{8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1}
Salida: 500
 */

int encontrarMaximo(int arr[], int n) {
    int izquierda = 0, derecha = n - 1;

    while (izquierda < derecha) {
        int medio = (izquierda + derecha) / 2;

        if (arr[medio] > arr[medio + 1]) {
            // El pico está en la mitad izquierda, incluyendo el medio
            derecha = medio;
        } else {
            // El pico está en la mitad derecha, excluyendo el medio
            izquierda = medio + 1;
        }
    }

    return arr[izquierda];
}

int main() {
    int arr[] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
    int n =  11;

    int maximo = encontrarMaximo(arr, n);
    std::cout << "El máximo valor en el arreglo es: " << maximo << std::endl;

    return 0;
}
