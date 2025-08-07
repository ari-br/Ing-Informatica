#include <iostream>
using namespace std;

int buscarMenor(int array[], int left, int right){
    //caso base:
    if(left == right) return array[left];
    //caso recursivo
    int mid = (left + right) / 2;
    int minLeft = buscarMenor(array, left, mid);
    int minRight = buscarMenor(array, mid+1, right);
    return (minLeft < minRight)? minLeft : minRight;
}

void buscarIntervaloCentro(int array[], int left, int mid, int right, int &startCenter, int &endCenter, int menor){
    for(startCenter = mid; startCenter >= left; startCenter--) 
        if(array[startCenter] != menor) break;
    startCenter++;
    for(endCenter = mid+1; endCenter <= right; endCenter++) 
        if(array[endCenter] != menor) break;
    endCenter--;
}

void buscarIntervaloMaximo(int array[], int left, int right, int &start, int &end, int menor){
    //caso base    
    if(left == right){
        if(array[left] == menor){
            start = left; 
            end = left;
        }
        return; 
    }
    //caso recursivo
    int mid = (left + right) / 2;
    int startLeft=-1, endLeft = -1; 
    int startRight=-1, endRight = -1; 
    int startCenter=-1, endCenter=-1;
    buscarIntervaloMaximo(array, left, mid, startLeft, endLeft, menor);
    buscarIntervaloMaximo(array, mid+1, right, startRight, endRight, menor);
    buscarIntervaloCentro(array, left, mid, right, startCenter, endCenter, menor);
    
    //calcular el tamaño maximo de los intervalos
    int maxLength = -1;   
    if(endCenter - startCenter >= maxLength){
        maxLength = endCenter - startCenter;
        start = startCenter;
        end = endCenter;
    } 
    if(endLeft - startLeft >= maxLength){
        maxLength = endLeft - startLeft;
        start = startLeft;
        end = endLeft;
    }
    if(endRight - startRight >= maxLength){
        maxLength = endRight - startRight;
        start = startRight;
        end = endRight;
    }
}


int main(){
    int array[] = {98, 88, 88, 90, 88, 92, 89, 89, 92, 90, 88, 88, 88, 88, 88, 95, 90, 89, 90, 91, 88, 88, 90, 90, 88, 88, 95, 88, 90, 91};
    int n = sizeof(array) /sizeof(array[0]);
    int menor = buscarMenor(array, 0, n-1);
    int start = -1, end = -1;
    buscarIntervaloMaximo(array, 0, n-1, start, end, menor);
    cout<<"El menor peso es: "<<menor<<endl;
    cout<<"El rango maximo es "<<start+1<<"-"<<end+1<<endl;
}