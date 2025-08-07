//Implementar una funci�n recursiva que indique si un n�mero dado se encuentra en un arreglo de N n�meros enteros
#include <iostream>
using namespace std;

int BuscarNumeroRecursivo (int arreglo[], int longitud_arreglo, int numero_a_buscar){
	
	//CASO BASE
	if (longitud_arreglo==0)//Ya se recorri� todo el arreglo y no se encontr� el n�mero
		return -1;
	
	//CASO RECURSIVO
	if (arreglo[longitud_arreglo-1]==numero_a_buscar)
		return longitud_arreglo-1;
	else
		return BuscarNumeroRecursivo(arreglo, longitud_arreglo-1, numero_a_buscar);
	
}

int main (){
	int arreglo[]={24,20,25,23,10};
	int longitud_arreglo=5;
	int numero_a_buscar=5;
	cout << "El numero en el arreglo est� en la posici�n: " << BuscarNumeroRecursivo (arreglo, longitud_arreglo,numero_a_buscar) <<endl;
	return 0;
}
