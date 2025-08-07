#include <iostream>
using namespace std;

int inicioRadiacion(int array[], int n){
   int left = 0, right = n;
   while(left < right){
        int mid = (left + right) / 2;
        if(array[mid] > 0)
            right = mid;
        else
            left = mid + 1;
   }
   return left;
}

int inicioRadiacionRec(int array[], int left, int right){
    //caso base
    if(left>=right) return left;
    //caso recursivo
    int mid = (left + right) / 2;
    if(array[mid] > 0) 
        return inicioRadiacionRec(array, left, mid);
    else
        return inicioRadiacionRec(array, mid+1, right);
}

int potenciaMaxima(int array[], int left, int right){
    //caso base
    if(left == right) return array[left];
    //caso recursivo
    int mid = (left + right) / 2;
    if(array[mid] > array[mid+1])
        return potenciaMaxima(array, left, mid);
    else
        return potenciaMaxima(array, mid+1, right);
}

int main(){
    //Se modifica el problema: los megatones crecen hasta llegar un maximo, y luego decrece (sin repetidos)
    int array[17] = {-1, 0, -1, 0, -1, -1, 0, 0, 1, 2, 4, 5, 8, 10, 3, 1, 1};
    int init = inicioRadiacionRec(array, 0, 16);//O(log n)
    int potMax = potenciaMaxima(array, init, 16);//O(log n)
    cout<<"Inicio de radiacion es en "<<init<<" km"<<endl;
    cout<<"Potencia maxima es "<<potMax<<" megatones"<<endl;
    return 0;
}