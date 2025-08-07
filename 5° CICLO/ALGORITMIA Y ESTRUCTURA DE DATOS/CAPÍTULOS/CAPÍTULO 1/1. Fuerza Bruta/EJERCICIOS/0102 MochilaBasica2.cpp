#include <iostream>
#include <math.h>

#define N 5//por el problema son 5 objetos/paquete

using namespace std;

void cargaBinaria(int numero, int cromosoma[], int longitud_cromosoma){
	int i, aux;
	//"reinicio" mi cromosoma
	for (i=0; i<longitud_cromosoma; i++)
		cromosoma[i]=0;
		
	//la variable "numero" es la que pasaremos a binario en cromosoma[]
	//Mediante divisiones sucesivas
	i=0;
	while (numero>0){
		aux=numero%2;
		numero=numero/2;
		cromosoma[i]=aux;
		i++;
	}
}

int main(){
	
	int objetos[N]={1,2,1,12,4};//pesos de las cajas
	int cromosoma[N];//arreglo para los cromosomas
	int peso_mochila, //es el peso que iremos calculando para cada combinación
	combinaciones;//cantidad de combinaciones según el problema
	
	//La solución es: seleccionar las cajas que llenen toda la mochila
	int mejor_peso_mochila=0, mejor_combinacion=0;//variables para encontrar la solución
	
	int alcanzo_peso_maximo=0;//BANDERA para indicar si alcanzo el peso maximo
	
	int peso_maximo;//la LIMITANTE para la ASIGNACIÓN: peso máximo de la mochila
	
	cout<<"Capacidad de la mochila, PESO = ";
	cin >> peso_maximo;
	
	combinaciones=pow(2,N);//definimos la cantidad de combinaciones.
	
	//iniciamos el análisis de FUERZA BRUTA
	for (int i=1;i<combinaciones; i++){
		cargaBinaria(i,cromosoma,N);//convertimos la combinacion a binario
		peso_mochila=0; //"reinicio" la variable para calcular el peso de la combinación
		cout << "Cromosoma "<<i<<" :";
		for (int j=0;j<N;j++){
			cout<< cromosoma[j]<< " ";
			if (cromosoma[j]==1)//cada vez que encuentre "activado" el objeto/caja, sumo su peso		
				peso_mochila=peso_mochila+objetos[j];//acumulo el peso del objeto/caja	
		}
		cout<<endl;
		//una vez calculado el peso de la combinación, lo analizo con el peso_maximo
		if (peso_mochila<=peso_maximo && mejor_peso_mochila<=peso_mochila){
			//cuando el peso de la mochila es menor igual a mi Limitante Y
			//encontramos un nuevo mejor peso
			mejor_peso_mochila=peso_mochila;
			mejor_combinacion=i;
			if (peso_mochila==peso_maximo) alcanzo_peso_maximo=1;//ACTIVAMOS LA BANDERA
		}
		if (alcanzo_peso_maximo) break;//Si la bandera está ACTIVA, 
		//es decir se alcanzó el peso máximo, terminamos las iteraciones, "ya no hay nada mas que hacer"
	}
	
	//MOSTRAMOS LA SOLUCION
	cargaBinaria(mejor_combinacion,cromosoma,N);
	cout << "Solucion: " << mejor_combinacion<< " : ";
	for (int j=0; j<N;j++)
		if (cromosoma[j]==1)//cada vez que encuentre "activado" el objeto/caja
				cout << objetos[j]<< " ";
	cout<<endl;
	return 0;
}
