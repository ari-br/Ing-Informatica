#include <iostream>
using namespace std;

void imprimir(int array[], int init, int end){
    for(int i=init;i<=end;i++)
      cout<<array[i]<<" ";
    cout<<endl;  
}

void merge(int array[], int init, int med, int end){
    int n = end - init + 1, j = 0;
    int *array2 = new int[n];
    //merge
    int p=init, q=med+1;
    while(p <= med && q <= end){
        if(array[p] < array[q])
            array2[j++] = array[p++];
        else 
            array2[j++] = array[q++];
    }
    
    while(p <= med) array2[j++] = array[p++];
    while(q <= end) array2[j++] = array[q++];
    
    //copiar desde array2
    for(int i=0; i<n; i++) array[i+init] = array2[i];
    delete[] array2;
}

void mergesort(int array[], int init, int end){
    if(init == end) return;
    int med = (init + end)/2;
    mergesort(array, init, med);
    mergesort(array, med+1, end);
    merge(array, init, med, end);
}

int main(){
    int array[10] = {22, 3, 10, 2, 6, 15, 11, 8, 4, 2};
    mergesort(array, 0, 9);
    imprimir(array, 0, 9);
}