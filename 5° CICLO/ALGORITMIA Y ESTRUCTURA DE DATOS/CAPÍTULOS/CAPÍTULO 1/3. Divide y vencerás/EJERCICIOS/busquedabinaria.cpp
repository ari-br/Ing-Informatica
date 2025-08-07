#include <iostream>
using namespace std;

int busBinaria(int array[], int ini, int fin, int key){
    if(ini > fin) return -1;
    int med = (ini + fin)/2;
    if(key == array[med])
        return med;
    else if(key < array[med])
        return busBinaria(array, ini, med - 1, key);
    else 
        return busBinaria(array, med + 1, fin, key);
}

int busBinaria(int array[], int n, int key){
    int ini = 0, fin = n -1;
    while(ini <= fin){
        int med = (ini + fin) / 2;
        if(key == array[med])
            return med;
        else if(key < array[med])
            fin = med - 1;
        else 
            ini = med + 1;
    }
    return -1;
}

int main(){
    int array[10] = {2, 3, 5, 8, 10, 11, 15, 18, 20, 22};
    int key = 18;
    int pos = busBinaria(array, 10, key);
    if(pos == -1)
        cout<<"No se encontro "<<key<<endl;
    else 
        cout<<"Posicion del elemento :"<<pos<<endl;
}
