//Implementar una funci�n recursiva que permita obtener el mayor n�mero de un arreglo de N n�meros enteros
#include <iostream>
using namespace std;

int EncuentraMayorRecursivo (int arreglo[], int longitud_arreglo){
	int opcion1, opcion2;
	cout<<endl<<"Longitud = "<<	longitud_arreglo<<endl;
	
	
	//CASO BASE
	if (longitud_arreglo==1){//s�lo hay un elemento en el arreglo, entonces es el m�ximo
		//cout<<endl<<"Longitud = "<<	longitud_arreglo<<endl;
		//cout<<"Caso base: retorna = "<< arreglo[longitud_arreglo-1]<<endl;
		return arreglo[longitud_arreglo-1];
	}
	
	//CASO RECURSIVO
	opcion1=arreglo[longitud_arreglo-1];//tomo el �ltimo elemento para el an�lisis
	//cout<<"opcion1="<<opcion1<<" vs. opcion2= LLAMADA RECURSIVA"<<endl;
	opcion2=EncuentraMayorRecursivo(arreglo, longitud_arreglo-1); //mando a buscar (de manera recursiva) el mayor del resto del arreglo
	
	//cout<<endl<<"Longitud = "<<	longitud_arreglo<<endl;
	//cout<<"opcion1="<<opcion1<<" vs. opcion2="<<opcion2<<endl;
	//al volver de la llamada recursiva, comparo el �ltimo elemento del arreglo con el mayor del resto del arreglo
	if (opcion1<opcion2){
		//cout<<"Retorna = "<< opcion2<<endl;
		return opcion2;
	}
	else{
		//cout<<"Retorna = "<< opcion1<<endl;
		return opcion1;
	}
}


int main (){
	int arreglo[]={24,20,25,23,10};
	int longitud_arreglo=5;
	cout << "El maximo numero del arreglo es: " << EncuentraMayorRecursivo (arreglo, longitud_arreglo) <<endl;
	return 0;
}

