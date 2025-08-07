#include <iostream>
using namespace std;

void imprimirMatriz(int matriz[][5], int n, int m, int i=0, int j=0){
    if(i == n) return;
    cout<<matriz[i][j]<<"\t";
    if(j < m - 1)
        imprimirMatriz(matriz, n, m, i, j + 1);
    else { //pasar a la siguiente fila
        cout<<endl;
        imprimirMatriz(matriz, n, m, i + 1, 0);
    }
}

void imprimirAnillo(int matriz[][5], int n, int m, 
                        int x, int y, int a = 1){
    if(x - a < 0 || y - a < 0 || x + a>=n || y + a >=m)
        return;
    cout<<"Anillo "<<a<<": ";
    for(int j=y-a; j<=y+a;++j)
        cout<<matriz[x-a][j]<<" ";
    for(int i=x-a+1;i<=x+a;++i)
        cout<<matriz[i][y+a]<<" ";
    for(int j=y+a-1; j>=y-a;--j)
        cout<<matriz[x+a][j]<<" ";
    for(int i=x+a-1;i>=x-a + 1;--i)
        cout<<matriz[i][y-a]<<" ";   
    cout<<endl;
    imprimirAnillo(matriz, n, m, x, y, a + 1);
}   

int main(){   
    int matriz[5][5] = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}
    };
    int n=5, m = 5;
    int x=2, y=2;
    imprimirMatriz(matriz, n, m);   
    cout<<"Recorrer anillos cocentricos desde ("<<x<<","<<y<<")"<<endl;
    imprimirAnillo(matriz, n, m, x, y);
    return 0;
}