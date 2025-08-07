#include <iostream>
using namespace std;

int maximo_tres(int a, int b, int c){
	if (a>b && a>c) return a;
	if (b>a && b>c) return b;
	if (c>b && c>a) return c;
	
}
int IncrementoCentro(int A[], int posicion_inicial, int posicion_medio, int posicion_final){
	int i, izquierda=1, derecha=1;//los contadores inician en 1 por que el incremento devuelve el intervalo de días
	
	if (A[posicion_medio]>A[posicion_medio+1])
		return 1;
	//Recorremos del medio hacia la izquierda
	for (i=posicion_medio; i>posicion_inicial;i--)
		if(A[i]>A[i-1])
			izquierda++;
		else
			break;
	//Recorremos del medio hacia la derecha
	for (i=posicion_medio+1; i<posicion_final;i++)
		if(A[i]<A[i+1])
			derecha++;
		else
			break;	
	return izquierda+derecha;//devolvemos el incremento (intervalo de días) que involucra a la posicion del medio		
}
int CuentaIncremento(int A[], int posicion_inicial, int posicion_final){
	//DV tiene su base en la Recursividad
	
	//CASO BASE
	if (posicion_inicial==posicion_final)
		return 1;
	
	//PARTE RECURSIVA
	int posicion_medio=(posicion_inicial+posicion_final)/2;//calculamos la posicion del medio para operar
	
	int izquierda=CuentaIncremento(A,posicion_inicial, posicion_medio);//Similar a llamar a MergeSort()
	int derecha=CuentaIncremento(A,posicion_medio+1, posicion_final);//Similar a llamar a MergeSort()
	int centro=IncrementoCentro(A, posicion_inicial, posicion_medio, posicion_final);//Similar a llamar a Merge()
	
	return maximo_tres(izquierda, derecha, centro);
}


int main (){
	//int A[]={10,20,15,10,12,10,13,18};
	//int n=8;
	
	int A[]={7,2,9,10,16,10,13,8,2,10};
	int n=10;
	cout<< "Incremento Maximo: "<<CuentaIncremento(A,0,n-1)<<endl;
	return 0;
}

