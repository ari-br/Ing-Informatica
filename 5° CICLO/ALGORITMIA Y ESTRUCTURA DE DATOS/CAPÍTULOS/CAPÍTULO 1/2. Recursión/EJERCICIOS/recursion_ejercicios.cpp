#include <iostream>

using namespace std;

int fact(int n){
    if(n == 1) return 1;
    else return n * fact(n-1);
}

int fib(int n){
    if(n == 1) return 0;
    else if(n == 2) return 1;
    else return fib(n-2) + fib(n-1);
}

void imprimir(int datos[], int n){
    if(n == 1) cout<<datos[0]<<endl;
    else {
        imprimir(datos, n - 1);   
        cout<<datos[n-1]<<endl;             
    }
}

int mayor(int datos[], int n){
    if(n == 1) return datos[0];
    else {
        int mayResto = mayor(datos, n - 1);
        return max(mayResto, datos[n-1]);
    }        
}

int main() {
    int n = 5;
    int datos[n] = {20, 14, 6, 8, 3};
    cout << mayor(datos, n);
    return 0;
}

