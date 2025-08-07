#include <iostream>
using namespace std;

/**
Dado un arreglo ordenado en el cual todos los elementos aparecen
dos veces y un elemento aparece una sola vez. Encontrar el
elemento que aparece una sola vez. El algoritmo debe tener
complejidad O(log n).

Ejemplo:
Entrada: {1, 1, 3, 3, 4, 5, 5, 7, 7, 8, 8}
Salida: 4
 */
int encontrarElementoUnico(int nums[], int n) {
    int izquierda = 0, derecha = n - 1;

    while (izquierda < derecha) {
        int medio = (izquierda + derecha) / 2;

        // Asegurarse de que 'medio' sea par
        if (medio % 2 == 1) {
            medio--;
        }

        // Comparar el par
        if (nums[medio] == nums[medio + 1]) {
            izquierda = medio + 2;
        } else {
            derecha = medio;
        }
    }

    return nums[izquierda];
}

int main() {
    int nums[] = {1, 1, 2, 2, 3, 3, 4, 5, 5};
    int n =  9;

    cout << "El elemento único es: " << encontrarElementoUnico(nums, n) << endl;
    return 0;
}
