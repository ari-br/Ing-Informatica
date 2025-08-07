#include <iostream>
#include <math.h>

#define N 6//por el problema son 6 articulos

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
	
	int objetos[N]={8,2,10,10,5,5};//pesos de los artículos
	int ganancias[N]={15,20,5,10,8,5};//ganancia de los artículos
	int cromosoma[N];//arreglo para los cromosomas
	int peso_mochila, //es el peso que iremos calculando para cada combinación
	ganancia_mochila, //es la ganancia que iremos calculando para cada combinación
	combinaciones;//cantidad de combinaciones según el problema
	
	//La solución es: seleccionar las cajas que llenen toda la mochila
	int mejor_peso_mochila=0, mejor_combinacion=0;//variables para encontrar la solución
	int mayor_ganancia=0;
	
	int alcanzo_peso_maximo=0;//BANDERA para indicar si alcanzo el peso maximo
	
	int peso_maximo;//la LIMITANTE para la ASIGNACIÓN: peso máximo de la mochila
	
	cout<<"Capacidad de la mochila de mano, PESO = ";
	cin >> peso_maximo;
	
	combinaciones=pow(2,N);//definimos la cantidad de combinaciones.
	
	//iniciamos el análisis de FUERZA BRUTA
	for (int i=1;i<combinaciones; i++){
		cargaBinaria(i,cromosoma,N);//convertimos la combinacion a binario
		peso_mochila=0; //"reinicio" la variable para calcular el peso de la combinación
		ganancia_mochila=0;
		//cout << "Cromosoma "<<i<<" :";
		for (int j=0;j<N;j++){
			//cout<< cromosoma[j]<< " ";
			if (cromosoma[j]==1){//cada vez que encuentre "activado" el artículo, sumo su peso y ganancia		
				peso_mochila=peso_mochila+objetos[j];//acumulo el peso del artículo	
				ganancia_mochila=ganancia_mochila+ganancias[j];//acumulo la ganancia del artículo
			}
		}
		//cout<<endl;
		//una vez calculado el peso de la combinación, lo analizo con el peso_maximo
		if (peso_mochila==peso_maximo && mejor_peso_mochila<=peso_mochila){
			if (mayor_ganancia<=ganancia_mochila){
				mejor_combinacion=i;
				mayor_ganancia=ganancia_mochila;
			}
				
			//cuando el peso de la mochila es menor igual a mi Limitante Y
			//encontramos un nuevo mejor peso
			//MOSTRAMOS LA SOLUCION
			cargaBinaria(i,cromosoma,N);
			cout << "Solucion: " << i<< " : ";
			//Mostraremos el cromosoma
			for (int j=0; j<N;j++) 
				cout << cromosoma[j]<< " ";
			cout<<endl;
			//Mostraremos los pesos utilizados
			for (int j=0; j<N;j++)
				if (cromosoma[j]==1)//cada vez que encuentre "activado" el objeto/caja
						cout << objetos[j]<< " ";
			cout<<endl;
			cout<<"Peso: "<<peso_mochila;
			cout<<endl;
			
			for (int j=0; j<N;j++)
				if (cromosoma[j]==1)//cada vez que encuentre "activado" el objeto/caja
						cout << ganancias[j]<< " ";
			cout<<endl;
			cout<<"Ganancia: "<<ganancia_mochila;
			cout<<endl<<endl;
		}
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
