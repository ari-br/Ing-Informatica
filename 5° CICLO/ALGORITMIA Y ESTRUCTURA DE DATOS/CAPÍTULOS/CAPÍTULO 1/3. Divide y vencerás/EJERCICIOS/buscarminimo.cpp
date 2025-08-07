#include <iostream>
using namespace std;

/**
Un arreglo está rotado en algún punto desconocido. Encontrar el
elemento mínimo del arreglo. Asumir que todos los elementos son
distintos.

Ejemplo:
Entrada: {5, 6, 1, 2, 3, 4}
Salida: 1
 */

int encontrarMinimo(int array[], int n){
    int init=0, end = n - 1; 
    while(init < end){
        int med = (init + end)/2;
        if(array[med]  > array[end])
            init = med + 1;
        else
            end = med;
    }
    return array[init];//init = end
}

int main(){
    int array[10] = {8, 9, 10, 1, 2, 3, 4, 5, 6, 7};
    int minimo = encontrarMinimo(array, 10);
    cout<<"Minimo del array: "<< minimo <<endl;
}