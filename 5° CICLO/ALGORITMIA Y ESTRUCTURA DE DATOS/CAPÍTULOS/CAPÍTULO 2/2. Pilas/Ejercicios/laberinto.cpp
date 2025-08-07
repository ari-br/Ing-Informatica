#include <iostream>
#include "Pila.h"
#include "funcionesPila.h"
#define MAX_N 100
#define CAMINO_CORRECTO 2
#define CAMINO_INCORRECTO 3
using namespace std;

void imprimirMatriz(int matriz[][100], int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<matriz[i][j]<<"\t";
        cout<<endl;
    }
}

bool esValido(int matriz[][100], int n, int m, int x, int y)
{
    return x >= 0 and y >= 0 and
           x < n and y < m and 
           matriz[x][y] == 1;
}

bool existeCamino(int matriz[][100], int n, int m){
    struct Pila pilaX;struct Pila pilaY;
    construir(pilaX);construir(pilaY);
    apilar(pilaX, 0);apilar(pilaY, 0);
    while(!esPilaVacia(pilaX) and !esPilaVacia(pilaY)){
        int x = cima(pilaX);
        int y = cima(pilaY);
        matriz[x][y] = CAMINO_CORRECTO;
        if(x == n -1 and y == m - 1) return true;
        if(esValido(matriz, n, m, x, y +1)){
           apilar(pilaX, x);apilar(pilaY, y + 1); 
        }
        else if (esValido(matriz, n, m, x+1, y)){
           apilar(pilaX, x+1);apilar(pilaY, y); 
        }
        else if (esValido(matriz, n, m, x, y-1)){
           apilar(pilaX, x);apilar(pilaY, y-1); 
        }
        else if (esValido(matriz, n, m, x-1, y)){
           apilar(pilaX, x-1);apilar(pilaY, y); 
        }
        else {
            matriz[x][y] = CAMINO_INCORRECTO;
            desapilar(pilaX);desapilar(pilaY);
        }
    }
    return false;
}

int main(int argc, char** argv) {
    int matriz[][MAX_N] = {
        {1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
    };
    int n=5, m = 5;
    imprimirMatriz(matriz, n, m);
    bool res = existeCamino(matriz, n, m);
    if(res) cout<<"Se encontro el camino\n";
    else cout<<"No existe camino\n";
    imprimirMatriz(matriz, n, m); // CAMINO_CORRECTO = 2        
    return 0;
}

