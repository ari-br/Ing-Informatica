#include <iostream>

#define V 5

using namespace std;

void MostrarSolucion(int distancias[]){
	for (int i=0; i<V; i++)
		cout << i << " " << distancias[i]<<endl;
}

int MinimaDistancia(int distancias[], int visitados[]){
	//función encuentra el vértice con la distancia mínima que aún no ha sido visitado
	int indice_minimo, minima_distancia=999999;
	
	for (int i=0; i<V; i++){
		if (visitados[i]==0 && distancias[i]<=minima_distancia){
			minima_distancia=distancias[i];
			indice_minimo=i;
		}
	}
	return indice_minimo;
}

void dijkstra(int grafo[V][V], int origen){
	int distancias[V];//para "guardar" las distancias mas cortas(menos costosas, etc) para llegar a cada vértice (i) desde el "origen"
	int visitados[V];//para "marcar" los vértices ya procesados
	
	//inicializamos los arreglos
	for (int i=0; i<V; i++){
		distancias[i]=999999;//valor alto para empezar a guardar los mínimos desde la primera iteración
		visitados[i]=0;//ningún vértice aún es visitado
	}
	
	distancias[origen]=0;//por convención la distancia al mismo vértice es 0
	
	//Comenzamos:
	for (int vertice=0; vertice<V-1; vertice++){//recorreros cada uno de los vértices menos 1 (por el origen)
		int vertice_minina_distancia=MinimaDistancia(distancias, visitados);
		//La función MinimaDistancia() devolverá el nodo donde tengo la mínima distancia aún visitada
		//NOTA: en la primera iteración, el escogido será el "origen"
		visitados[vertice_minina_distancia]=1;
		
		//procesamos el vértice: actualizamos distancias[] de los vértices donde hay relaciones
		//es decir donde hay adyacencias/valores/conexiones
		for (int i=0; i<V; i++){
			if (visitados[i]!=1 //descarto los que han sido visitados
			&& grafo[vertice_minina_distancia][i]//que tenga una relación entre "vertice_minina_distancia" con "i"
			&& distancias[vertice_minina_distancia]!=999999 //no mantiene el valor inicial
			&& distancias[vertice_minina_distancia] + grafo[vertice_minina_distancia][i] < distancias[i])//es decir encontré una nueva distancia mínima
				//actualizamos la distancia minima a ese vértice:
				distancias[i]=distancias[vertice_minina_distancia] + grafo[vertice_minina_distancia][i];	
		}
		
	}
	MostrarSolucion(distancias);
}

int main(){
	int grafo[V][V]={{0,3,0,7,0},
					 {3,0,4,2,0},
					 {0,4,0,5,6},
					 {7,2,5,0,4},
					 {0,0,6,4,0}};
					
	dijkstra(grafo, 0);//el 2do parámetro es el vértice de origen (en este caso: "a")
	return 0;
}
