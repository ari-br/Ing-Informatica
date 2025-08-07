#include <iostream>
using namespace std;

void BuscaSolitario(int A[], int posicion_inicial, int posicion_final){
	int posicion_medio;
	//Recordando que: DV tiene su base en la Recursión.
	
	//CASO BASE: Cuando nos quedamos con un solo elemento
	if (posicion_inicial==posicion_final){
		cout<<"Elemento: "<<A[posicion_inicial]<<endl;
		return;
	}
	//PARTE RECURSIVA
	posicion_medio=(posicion_inicial+posicion_final)/2;
	
	if (posicion_medio%2==0){//si la posicion del medio es par
		if (A[posicion_medio]==A[posicion_medio+1])
			//Los emparejados están en el subarreglo de la izquierda (inc. pos_medio+1)
			//Entonces analizo el subarreglo de la derecha (desde pos_medio+2)
			BuscaSolitario(A, posicion_medio+2, posicion_final);
		else//Los emparejados están en el subarreglo de la derecha (desde pos_medio+1)
			//Entonces analizo el subarreglo de la izquierda (hasta pos_medio)
			BuscaSolitario(A, posicion_inicial, posicion_medio);
	}else{//si la posicion del medio es impar
		if (A[posicion_medio]==A[posicion_medio-1])
			//Los emparejados están en el subarreglo de la izquierda (inc. pos_medio)
			//Entonces analizo el subarreglo de la derecha (desde pos_medio+1)
			BuscaSolitario(A, posicion_medio+1, posicion_final);
		else//Los emparejados están en el subarreglo de la derecha (inc. pos_medio)
			//Entonces analizo el subarreglo de la izquierda (hasta pos_medio-1)
			BuscaSolitario(A, posicion_inicial, posicion_medio-1);	
	}
}

int main (){
	int A[]={1, 1, 3, 3, 5, 5, 6, 7, 7, 9, 9};
	int n=11;
	BuscaSolitario(A,0,n-1);
	return 0;
}
