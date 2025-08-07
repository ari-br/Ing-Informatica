#include <iostream>
#include <cmath>
using namespace std;

void convertirBinario(int numdec, int binario[], int n){
    int j = n - 1;
    for(int i=0;i<n;i++) binario[i] = 0;
    while(numdec > 0){
        binario[j--] = numdec % 2;
        numdec = numdec / 2;
    }    
}

void mostrar(int binario[], int n, char paquetes[], int pesoPaquetes[]){
    cout<<"Solucion: ";
    for(int i=0;i<n;i++) {
        if(binario[i] == 1){
            cout<<paquetes[i]<<":"<<pesoPaquetes[i]<<"  ";
        }
    }
    cout<<endl;
}

bool esSolucion(int binario[], int n, int pesoPaquetes[], int capacidad){
    int sumaPesos = 0;
    for(int i=0;i<n;i++)
        if(binario[i] == 1)
            sumaPesos += pesoPaquetes[i];    
    return sumaPesos == capacidad;
}

int mochilaExacta() {
    int n = 5, capacidad = 5;
    int binario[n];
    int pesoPaquetes[n] = {1, 2, 3, 4, 2};
    char paquetes[n] = {'A', 'B', 'E', 'C', 'D'};    
    for(int i=1;i<pow(2, n);i++){
        convertirBinario(i, binario, n);
        if(esSolucion(binario, n, pesoPaquetes, capacidad))
            mostrar(binario, n, paquetes, pesoPaquetes);
    }
    return 0;
}

