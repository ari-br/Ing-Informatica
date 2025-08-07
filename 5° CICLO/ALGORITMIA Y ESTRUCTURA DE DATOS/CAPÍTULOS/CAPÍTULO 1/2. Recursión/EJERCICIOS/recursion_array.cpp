#include <iostream>

using namespace std;

bool buscar(int datos[], int N, int key){
    if(N == 0) return false;
    else if(datos[N-1] == key) return true;
    else return buscar(datos, N - 1, key);
}

void imprimir(int datos[], int N){
    if(N==0) return;
    imprimir(datos, N-1);
    cout<<datos[N-1]<<endl;
}

void binario(int num){
    if(num > 0) {
        binario(num / 2);
        cout<<num % 2<<" ";
    }
}

void testBinario(){
    int num = 15;
    cout<<"Binario de "<<num<<" es ";
    binario(num);
    cout<<endl;
}

void testBuscarNumeros() {
    int N=6;
    int datos[N] = {2, 4, 6, 8, 10, 12};
    imprimir(datos, N);
    cout<<"Encontrado? "<<buscar(datos, N, 14);//0
}

int main(){
    testBuscarNumeros();
    testBinario();
}