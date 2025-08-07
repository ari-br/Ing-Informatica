#include <iostream>

using namespace std;

/*
Se tiene un arreglo que puede contener números positivos y
negativos. Encontrar la suma de números contiguos que tengan la
suma máxima.

Ejemplo:
Entrada: {-2, -5, 6, -2, -3, 1, 5, -6}
Salida: 7 (Los elementos que suman el máximo son 6, -2, -3, 1, 5)
*/

// Función para encontrar la suma máxima que cruza el punto medio
int sumaMaximaCruzada(int arr[], int izquierda, int medio, int derecha) {
    int sumaIzquierda = INT_MIN;
    int suma = 0;
    
    for (int i = medio; i >= izquierda; i--) {
        suma += arr[i];
        if (suma > sumaIzquierda) {
            sumaIzquierda = suma;
        }
    }

    int sumaDerecha = INT_MIN;
    suma = 0;
    
    for (int i = medio + 1; i <= derecha; i++) {
        suma += arr[i];
        if (suma > sumaDerecha) {
            sumaDerecha = suma;
        }
    }

    return sumaIzquierda + sumaDerecha;
}

int max(int a, int b){
    return (a > b)? a : b;
}

// Función principal de divide y vencerás
int sumaMaximaSubarray(int arr[], int izquierda, int derecha) {
    if (izquierda == derecha) {
        return arr[izquierda];
    }

    int medio = (izquierda + derecha) / 2;
    
    int sumaIzquierda = sumaMaximaSubarray(arr, izquierda, medio);
    int sumaDerecha = sumaMaximaSubarray(arr, medio + 1, derecha);
    int sumaCruzada = sumaMaximaCruzada(arr, izquierda, medio, derecha);

    return max(sumaIzquierda, max(sumaDerecha, sumaCruzada));
}

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n =  8;

    int maxSuma = sumaMaximaSubarray(arr, 0, n - 1);
    cout << "La suma máxima de subarray contiguo es: " << maxSuma << endl;

    return 0;
}
