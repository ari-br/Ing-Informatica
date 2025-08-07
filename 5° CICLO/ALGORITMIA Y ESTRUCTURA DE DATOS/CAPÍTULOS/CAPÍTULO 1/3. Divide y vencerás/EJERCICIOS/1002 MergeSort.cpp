#include <iostream>
using namespace std;
void Merge(int A[], int posicion_inicial, int posicion_medio, int posicion_final){
	int longitud1, longitud2;
	int i, p, q;//índices del arreglo A, y de los subarreglos P y Q
	
	longitud1=(posicion_medio+1)-posicion_inicial;//longitud de la primera mitad del arreglo
	longitud2=posicion_final-posicion_medio;//longitud de la segunda mitad del arreglo

	int P[longitud1+1];//subarreglo auxiliar para la primera mitad
	int Q[longitud2+1];//subarreglo auxiliar para la segunda mitad
	
	//al último espacio que hemos añadido en los subarreglos auxiliares, le ponemos un valor MUY GRANDE 
	P[longitud1]=999999;//número grande
	Q[longitud2]=999999;//número grande
	
	//copiamos las 2 mitades en los 2 subarreglos auxiliares
	for(i=posicion_inicial; i<=posicion_medio;i++)
		P[i-posicion_inicial]=A[i];
	for(i=posicion_medio+1; i<=posicion_final;i++)
		Q[i-(posicion_medio+1)]=A[i];
		
	p=q=0;
	for (i=posicion_inicial;i<=posicion_final;i++) //Aquí recorremos todo el arreglo: O(N)
		if (P[p]<Q[q])
			A[i]=P[p++];
		else
			A[i]=Q[q++];
}

void MergeSort(int A[], int posicion_inicial, int posicion_final){
	//Recordar que se toma como base de la estrategia de recursividad
	
	//CASO BASE
	if (posicion_inicial==posicion_final)//este escenario es cuando se queda con un solo elemento el subarreglo
		return;
	
	//PARTE RECURSIVA
	int posicion_medio=(posicion_inicial+posicion_final)/2;//calculamos la posicion del medio para operar
	MergeSort(A, posicion_inicial, posicion_medio);//Subarreglo de la IZQUIERDA //O(logN)
	//Hasta aquí, el subarreglo izquierdo retorna ordenado
	MergeSort(A, posicion_medio+1, posicion_final);//Subarreglo de la DERECHA //O(logN)
	//Hasta aquí, el subarreglo derecho retorna ordenado
	//Con la siguiente función, ordenamos los 2 subarreglos:
	Merge(A, posicion_inicial, posicion_medio, posicion_final); //O(N)
	//Hasta aquí, todo el arreglo está ordenado		
}

int main(){
	int A[]={11,4,7,1,6,3,2,9};//Es el arreglo que vamos a ORDENAR
	int i, n=8;
	
	//Mostramos el arreglo inicial
	cout<<"INICIAL: ";
	for (i=0;i<n;i++)
		cout<<A[i]<<" ";
	cout<<endl;
	
	MergeSort(A, 0,n-1);//Como parámetros, el arreglo, la pos.inicial y la pos.final
	//O(N logN)
	//Mostramos el arreglo inicial
	cout<<"ORDENADO: ";
	for (i=0;i<n;i++)
		cout<<A[i]<<" ";
	cout<<endl;
	return 0;
}
