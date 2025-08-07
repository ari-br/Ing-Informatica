/*	Dado un arreglo de 0’s y 1’s el cual tiene todos los 1’s primero
	seguido de todos los 0’s. Encontrar el número de 0’s.
	Ejemplos:
		Entrada: {1, 1, 1, 0, 0, 0, 0}
		Output: 4
		Entrada: {1, 1, 1, 1, 1}
		Salida: 0
*/
#include <iostream>
using namespace std;
int CuentaCeros(int A[], int posicion_inicial, int posicion_final, int contador_ceros){
	//CASO BASE
	if (posicion_inicial > posicion_final)//cuando se cruzan las posiciones
		return contador_ceros;//el valor que tomará en el caso base es con el que se llamó de manera inicial en el main()
		//Es en la parte recursiva que iremos contando los 0s considerando el 4 parámetro.
	//PARTE RECURSIVA
	int posicion_medio=(posicion_inicial+posicion_final)/2;
	if (A[posicion_medio]==0)
		//Si es 0 la posicion del medio, el subarreglo de la DERECHA es de puros 0
		//Entonces, tengo que analizar el subarreglo de la IZQUIERDA
		return CuentaCeros(A, posicion_inicial, posicion_medio-1, contador_ceros+(posicion_final-posicion_medio+1));
	else
		//Si es 1 la posicion del medio, el subarreglo de la IZQUIERDA es de puros 1
		//Entonces, tengo que analizar el subarreglo de la DERECHA
		return CuentaCeros(A, posicion_medio+1, posicion_final, contador_ceros);
}
int main(){
	int A[]={1, 1, 1, 0, 0, 0, 0};//Dato de entrada
	int n=7;
	
	cout<<"Resultado: "<<CuentaCeros(A, 0, n-1, 0)<<endl;//parámetros: arreglo, pos.inicial, pos.final, contador de ceros
	return 0;
}
