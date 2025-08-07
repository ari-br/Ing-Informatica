#include <iostream>
using namespace std;

void imprimir(int array[], int init, int end){
    for(int i=init;i<=end;i++)
      cout<<array[i]<<" ";
    cout<<endl;  
}

void swap(int *a, int *b){
    int *t = b; a = b; b = t;
}

int particionar(int array[], int init, int end){
    int pivot = init, i = init;
    for(int j=init + 1; j<=end; j++) {
        if(array[j] < array[pivot]) {
            i++;
            swap(array[i], array[j]);
        }
    }
    swap(array[pivot], array[i]);
    return i;
}

void quicksort(int array[], int init, int end){
    if(init > end) return;
    int pivot = particionar(array, init, end);
    quicksort(array, init, pivot-1);
    quicksort(array, pivot+1, end);
}

int main(){
    int array[10] = {12, 3, 15, 2, 6, 14, 11, 8, 4, 20};
    quicksort(array, 0, 9);
    imprimir(array, 0, 9);
}