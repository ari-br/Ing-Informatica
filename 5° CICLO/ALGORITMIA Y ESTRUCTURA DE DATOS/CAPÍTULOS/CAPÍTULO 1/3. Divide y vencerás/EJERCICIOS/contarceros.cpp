#include <iostream>
using namespace std;

/**
 Dado un arreglo de 0’s y 1’s el cual tiene todos los 1’s primero
 seguido de todos los 0’s. Encontrar el número de 0’s.

Ejemplos:
Entrada: {1, 1, 1, 0, 0, 0, 0}
Output: 4
Entrada: {1, 1, 1, 1, 1}
Salida: 0   
 */
int contarCeros(int array[], int n){
    int init=0, end = n-1; 
    
    if(array[end] == 1) return 0;

    while(init < end){
        int med = (init + end)/2;
        if(array[med] == 0)
            end = med;
        else
            init = med + 1;
    }
    
    return n - init;//contamos desde init hasta n-1
}

int main(){
    int array[6] = {0,0,0,0,0,0};
    int count = contarCeros(array, 6);
    cout<<"Ceros: "<<count <<endl;
    return 0;
}