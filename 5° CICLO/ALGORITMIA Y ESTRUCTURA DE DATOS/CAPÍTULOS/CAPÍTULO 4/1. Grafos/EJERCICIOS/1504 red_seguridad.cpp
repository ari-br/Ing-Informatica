#include <iostream>

#define V 6

using namespace std;

void MostrarSolucion(int latencias[], double promedios_seguridad[]){
	for (int i=0; i<V; i++)
		cout << "Servidor: "<< i+1 << " Latencia: "<< latencias[i] << " Seguridad Promedio: " << promedios_seguridad[i]<<endl;
}

int MinimaLatencia(int distancias[], int visitados[]){
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

void dijkstra(int grafo[V][V], int seguridad[V][V], int origen){
	int latencias[V];
	double promedios_seguridad[V];
	int visitados[V];
	int numero_aristas[V];
	
	//inicializamos
	for (int i=0; i<V; i++){
		latencias[i]=999999;//valor alto para empezar a guardar los m�nimos desde la primera iteraci�n
		promedios_seguridad[i]=0.0;
		visitados[i]=0;//ning�n v�rtice a�n es visitado
		numero_aristas[i]=0;
	}
	
	latencias[origen]=0;
	promedios_seguridad[origen]=0.0;
	numero_aristas[origen]=0;
	
	//Comenzamos:
	for (int vertice=0; vertice<V-1; vertice++){//recorreros cada uno de los v�rtices menos 1 (por el origen)
		int vertice_minina_latencia=MinimaLatencia(latencias, visitados);
		//La funci�n MinimaDistancia() devolver� el nodo donde tengo la m�nima distancia a�n visitada
		//NOTA: en la primera iteraci�n, el escogido ser� el "origen"
		visitados[vertice_minina_latencia]=1;
		
		//procesamos el v�rtice: actualizamos distancias[] de los v�rtices donde hay relaciones
		//es decir donde hay adyacencias/valores/conexiones
		for (int i=0; i<V; i++){
			if (visitados[i]!=1 //descarto los que han sido visitados
			&& grafo[vertice_minina_latencia][i]//que tenga una relaci�n entre "vertice_minina_distancia" con "i"
			&& latencias[vertice_minina_latencia]!=999999 //no mantiene el valor inicial
			&& latencias[vertice_minina_latencia] + grafo[vertice_minina_latencia][i] < latencias[i]){//es decir encontr� una nueva distancia m�nima
				//actualizamos la distancia minima a ese v�rtice:
				latencias[i]=latencias[vertice_minina_latencia] + grafo[vertice_minina_latencia][i];
				promedios_seguridad[i]=	(seguridad[vertice_minina_latencia][i]+promedios_seguridad[i]*numero_aristas[i])/(numero_aristas[i]+1);
				numero_aristas[i]++;	
			}
		}
		
	}
	cout << "aristas :";
	for (int i=0; i<V; i++){
		cout << numero_aristas[i] << " ";
	}
	cout << endl;
	
	MostrarSolucion(latencias, promedios_seguridad);
}
	
	
int main(){
	int grafo[V][V]={
	{0, 0, 0, 3, 0, 0},
	{0, 0, 1, 0, 3, 0},
	{0, 1, 0, 2, 5, 7},
	{3, 0, 2, 0, 7, 0},
	{0, 3, 5, 7, 0, 2},
	{0, 0, 7, 0, 2, 0}
	};
	int seguridad[V][V]={
	{0, 0, 0, 9, 0, 0},
	{0, 0, 7, 0, 8, 0},
	{0, 7, 0, 7, 5, 7},
	{9, 0, 7, 0, 7, 0},
	{0, 8, 5, 7, 0, 9},
	{0, 0, 7, 0, 9, 0}
	};
	
	dijkstra(grafo, seguridad, 0);
	
	return 0;

}
