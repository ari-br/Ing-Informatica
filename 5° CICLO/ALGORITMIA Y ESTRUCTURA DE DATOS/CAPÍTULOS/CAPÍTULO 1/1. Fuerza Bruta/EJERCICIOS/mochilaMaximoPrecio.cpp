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

void mostrar(int binario[], int n, char paquetes[], int pesoPaquetes[], int precioPaquetes[]){
    cout<<"Solucion= ";
    for(int i=0;i<n;i++) {
        if(binario[i] == 1){
            cout<<paquetes[i]<<": ("<<pesoPaquetes[i]<<","<<precioPaquetes[i]<<") ";
        }
    }
    cout<<endl;
}

bool esSolucion(int binario[], int n, int pesoPaquetes[], int precioPaquetes[], int capacidad){
    int sumaPesos = 0, sumaPrecios = 0;    
    for(int i=0;i<n;i++)
        if(binario[i] == 1){
            sumaPesos += pesoPaquetes[i];    
            sumaPrecios += precioPaquetes[i];
        }
    if(sumaPesos <= capacidad) return sumaPrecios;
    else return 0;
}

int main() {
    int n = 5, capacidad = 5;
    int binario[n];
    int pesoPaquetes[n] = {1, 2, 3, 4, 2};
    int precioPaquetes[n] = {5, 3, 2, 2, 4};
    char paquetes[n] = {'A', 'B', 'E', 'C', 'D'};    
    int maxPrecio = 0, posMax = -1, sumaPrecios;
    for(int i=1;i<pow(2, n);i++){
        convertirBinario(i, binario, n);
        sumaPrecios = esSolucion(binario, n, pesoPaquetes, precioPaquetes, capacidad);
        if(sumaPrecios >= maxPrecio){
            maxPrecio = sumaPrecios;
            posMax = i;
        }
    }
    convertirBinario(posMax, binario, n);
    mostrar(binario, n, paquetes, pesoPaquetes, precioPaquetes);
    return 0;
}


