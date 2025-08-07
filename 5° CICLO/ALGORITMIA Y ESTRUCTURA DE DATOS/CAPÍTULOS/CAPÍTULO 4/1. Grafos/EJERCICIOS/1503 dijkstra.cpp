#include <iostream>

#define V 5

using namespace std;

void MostrarSolucion(int distancias[]){
	for (int i=0; i<V; i++)
		cout << i << " " << distancias[i]<<endl;
}

int MinimaDistancia(int distancias[], int visitados[]){
	//funci�n encuentra el v�rtice con la distancia m�nima que a�n no ha sido visitado
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
	int distancias[V];//para "guardar" las distancias mas cortas(menos costosas, etc) para llegar a cada v�rtice (i) desde el "origen"
	int visitados[V];//para "marcar" los v�rtices ya procesados
	
	//inicializamos los arreglos
	for (int i=0; i<V; i++){
		distancias[i]=999999;//valor alto para empezar a guardar los m�nimos desde la primera iteraci�n
		visitados[i]=0;//ning�n v�rtice a�n es visitado
	}
	
	distancias[origen]=0;//por convenci�n la distancia al mismo v�rtice es 0
	
	//Comenzamos:
	for (int vertice=0; vertice<V-1; vertice++){//recorreros cada uno de los v�rtices menos 1 (por el origen)
		int vertice_minina_distancia=MinimaDistancia(distancias, visitados);
		//La funci�n MinimaDistancia() devolver� el nodo donde tengo la m�nima distancia a�n visitada
		//NOTA: en la primera iteraci�n, el escogido ser� el "origen"
		visitados[vertice_minina_distancia]=1;
		
		//procesamos el v�rtice: actualizamos distancias[] de los v�rtices donde hay relaciones
		//es decir donde hay adyacencias/valores/conexiones
		for (int i=0; i<V; i++){
			if (visitados[i]!=1 //descarto los que han sido visitados
			&& grafo[vertice_minina_distancia][i]//que tenga una relaci�n entre "vertice_minina_distancia" con "i"
			&& distancias[vertice_minina_distancia]!=999999 //no mantiene el valor inicial
			&& distancias[vertice_minina_distancia] + grafo[vertice_minina_distancia][i] < distancias[i])//es decir encontr� una nueva distancia m�nima
				//actualizamos la distancia minima a ese v�rtice:
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
					
	dijkstra(grafo, 0);//el 2do par�metro es el v�rtice de origen (en este caso: "a")
	return 0;
}
