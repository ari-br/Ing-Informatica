#include <iostream>
using namespace std;

int sumaCentro(int array[], int left, int mid, int right){
    int minLeft = 10000, minRight= 10000;
    int suma = 0;
    for(int i=mid; i>=left;i--){
        suma += array[i];
        if(suma < minLeft) minLeft = suma;
    }
    suma = 0;
    for(int i=mid+1;i<=right;i++){
        suma += array[i];
        if(suma < minRight) minRight = suma;
    }
    return minLeft + minRight;
}

int min(int a, int b){
    return (a > b)? b : a;
}

int sumaMinima(int array[], int left, int right){// O(n log n)
    //caso base
    if(left == right) return array[left];
    //caso recursivo
    int mid = (left + right) / 2;
    //obtener la suma maxima en el lado izquierdo
    int maxLeft = sumaMinima(array, left, mid);//O(n/2)
    //obtener la suma mazima en el lado derecho
    int maxRight = sumaMinima(array, mid + 1, right);//O(n/2)
    //obtener la suma maxima en el centro
    int maxCentro = sumaCentro(array, left, mid, right);//O(n)
    //retornar el maximo de las tres partes
    return min(maxLeft, min(maxRight, maxCentro));
}

int main(){
    int array[5] = {2, -3, 4, -5, -7};
    int minSuma = sumaMinima(array, 0, 4);
    cout<<"La suma del sub array minimo es:"<<minSuma<<endl;
}