#include <iostream>
#include <queue>
#include <stack>
#define n 6
using namespace std;

void bfs(int grafo[][n], int inicio, int final = -1) {
    bool visitado[n] = {false};  // Array para marcar nodos visitados
    queue<int> cola;            // Cola para procesar nodos

    // Iniciar el recorrido desde el nodo de inicio
    visitado[inicio] = true;
    cola.push(inicio);

    while (!cola.empty()) {
        int nodo = cola.front(); cola.pop();
        cout << nodo<< endl;  //Agregar a la solucion
        if(final != -1 and nodo == final) break; //terminar si llegamos al final
        // Explorar los vecinos del nodo actual
        for (int i = 0; i < n; ++i) {
            if (grafo[nodo][i] && !visitado[i]) {
                visitado[i] = true;
                cola.push(i);
            }
        }
    }
}

void dfs_rec(int grafo[][n], int nodo, bool visitado[]) {
    visitado[nodo] = true;
    cout << nodo << endl;  //Agregar a la solucion
    // Explorar los vecinos del nodo actual
    for (int i = 0; i < n; ++i) {
        if (grafo[nodo][i] && !visitado[i]) {
            dfs_rec(grafo, i, visitado);
        }
    }
}

void dfs(int grafo[][n], int inicio) {
    bool visitado[n] = {false};  // Array para marcar nodos visitados    
    dfs_rec(grafo, inicio, visitado);    
}

void dfs_iterativo(int grafo[][n], int inicio, int final = -1) {
    bool visitado[n] = {false};  // Array para marcar nodos visitados   
    stack<int> pila;            // Pila para procesar nodos

    // Iniciar el recorrido desde el nodo de inicio
    visitado[inicio] = true;
    pila.push(inicio);

    while (!pila.empty()) {
        int nodo = pila.top(); pila.pop();
        cout << nodo<< endl;  //Agregar a la solucion
        if(final != -1 and nodo == final) break; //terminar si llegamos al final
        // Explorar los vecinos del nodo actual 
        // (lo hacemos en orden inverso para coincidir con el ejercicio manual)
        for (int i = n - 1; i >= 0; --i) {
            if (grafo[nodo][i] && !visitado[i])  {               
                visitado[i] = true;
                pila.push(i);            
            }
        }
    } 
}

int main() {
    // Ejemplo de grafo visto en clase
    // definido como matriz de adyacencia
    int grafo[][n] = {
      // 0  1  2  3  4  5
        {0, 0, 1, 1, 0, 0},
        {0, 0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1, 0},
        {1, 0, 0, 0, 1, 0},
        {0, 0, 1, 1, 0, 1},
        {0, 1, 0, 0, 1, 0}
    };

    int inicio = 0; // Nodo inicial

    cout << "Recorrido BFS: \n";
    bfs(grafo, inicio);

    cout << "Recorrido DFS: \n";
    dfs_iterativo(grafo, inicio);

    return 0;
}
