#include <iostream>
#include <climits>
#define n 6
using namespace std;

int encontrarMinimo(int dist[], bool visitado[]) {
    int minDist = INT_MAX;
    int minIndice = -1;
    for (int i = 0; i < n; ++i) {
        if (!visitado[i] && dist[i] < minDist) {
            minDist = dist[i];
            minIndice = i;
        }
    }
    return minIndice;
}


void dijkstra(int grafo[][n], int origen) {
    int dist[n];           // Distancias mínimas desde el nodo origen
    bool visitado[n];      // Nodos ya procesados

    // Inicialización
    for (int i = 0; i < n; ++i) {
        dist[i] = INT_MAX; // Distancias iniciales a infinito
        visitado[i] = false;
    }
    dist[origen] = 0; // La distancia al nodo origen es 0

    // Procesar todos los nodos
    for (int i = 0; i < n; ++i) {
        // Encuentra el nodo no visitado con la menor distancia
        int u = encontrarMinimo(dist, visitado);

        // Marca el nodo como visitado
        if (u == -1) break; // Si no hay más nodos alcanzables
        visitado[u] = true;

        // Actualiza las distancias de los nodos vecinos
        for (int v = 0; v < n; ++v) {
            if (!visitado[v] && grafo[u][v] > 0) { // Si hay conexión
                int nuevaDist = dist[u] + grafo[u][v];
                //Si la nueva distancia mejora el costo actual, actualizar
                if (nuevaDist < dist[v]) {
                    dist[v] = nuevaDist;
                }
            }
        }
    }

    cout << "Nodo Origen: " << origen + 1 << endl;
    for (int i = 0; i < n; ++i) {
        if (dist[i] == INT_MAX)
            cout << "Nodo " << i + 1 << ": Inalcanzable" << endl;
        else
            cout << "Nodo " << i + 1 << ": " << dist[i] << endl;
    }
}

// Función principal
int main() {
    int grafo[][n] = {
        {0, 10, 0, 0, 0, 0},
        {10, 0, 5, 0, 0, 0},
        {0, 5, 0, 20, 1, 0},
        {0, 0, 20, 0, 2, 0},
        {0, 0, 1, 2, 0, 6},
        {0, 0, 0, 0, 6, 0}
    };

    int origen = 0; 
  
    dijkstra(grafo, origen);

    return 0;
}
