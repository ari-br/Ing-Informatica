#include <iostream>
using namespace std;

int BusquedaBinaria(int A[], int k, int posicion_inicial, int posicion_final){
	//Recordar que se toma como base de la estrategia la recursividad
	
	//CASO BASE
	if (posicion_inicial>posicion_final)//este escenario es cuando no se encontró a K
		return -1;
	
	//PARTE RECURSIVA
	int posicion_medio=(posicion_inicial+posicion_final)/2;//calculamos la posicion del medio para analizarla
	
	if (A[posicion_medio]==k) //si es que hemos encontrado a K en el medio del arreglo, BINGO!
		return posicion_medio;
	else
		if (A[posicion_medio]>k)//si k es menor que el elemento que está en el medio del arreglo, analizamos el SUBARREGLO DE LA IZQUIERDA
			return BusquedaBinaria(A, k, posicion_inicial, posicion_medio-1);
		else //si k es menor que el elemento que está en el medio del arreglo, analizamos el SUBARREGLO DE LA DERECHA
			return BusquedaBinaria(A, k, posicion_medio+1, posicion_final);
}

int main(){
	int A[]={1,5,7,9,12,15,17,20};//OJO!! ARREGLO ORDENADO
	int n=8;
	int k=7;
	
	int posicion=BusquedaBinaria(A, k, 0, n-1);//como parámetros: El arreglo, el elemento a buscar, la pos.inicial, la pos.final
	if (posicion==-1)
		cout<<"El elemento NO SE encuentra en el arreglo."<<endl;
	else
		cout<<"El elemento SE encuentra en el arreglo. Posicion="<<posicion+1<<endl;	
	return 0;
}
