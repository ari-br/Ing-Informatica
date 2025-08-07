#include <iostream>
#include <math.h>


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
	int peso_maximo=100;//la LIMITANTE para la ASIGNACIÓN: peso máximo de la mochila
	int n=4;

	int pesos[n*n]={20,20,20,20,10,30,10,30,10,10,10,10,15,15,15,15};
	int valores[n*n]={10,10,10,50,80,10,10,20,20,20,20,20,50,50,50,50};
	int cromosoma[n*n];//arreglo para los cromosomas
	int peso_mochila, //es el peso que iremos calculando para cada combinación
	valor_mochila,//es el valor que iremos calculando para cada combinación
	combinaciones;//cantidad de combinaciones según el problema
	
	//La solución es: seleccionar las cajas que llenen toda la mochila
	int mejor_peso_mochila=0, mejor_combinacion=0, mejor_valor_mochila=0;//variables para encontrar la solución
	
	combinaciones=pow(2,n*n);//definimos la cantidad de combinaciones.
	
	//iniciamos el análisis de FUERZA BRUTA
	for (int i=1;i<combinaciones; i++){
		cargaBinaria(i,cromosoma,n*n);//convertimos la combinacion a binario
		peso_mochila=0; //"reinicio" la variable para calcular el peso de la combinación
		valor_mochila=0; //"reinicio" la variable para calcular el valor de la combinación
		for (int j=0;j<n*n;j++)
			if (cromosoma[j]==1){//cada vez que encuentre "activado" el objeto/caja, sumo su peso
				peso_mochila=peso_mochila+pesos[j];//acumulo el peso del objeto/caja
				valor_mochila=valor_mochila+valores[j];//acumulo el valor del objeto/caja
			}
		//una vez calculado el peso de la combinación, lo analizo con el peso_maximo
		if (peso_mochila<=peso_maximo && mejor_peso_mochila<=peso_mochila && mejor_valor_mochila<=valor_mochila){
			//============================ OJO!!!! TAREA: revisar la segunda condicional si es que se puede prescindir o no
			//cuando el peso de la mochila es menor igual a mi Limitante Y
			//encontramos un nuevo mejor peso
			mejor_peso_mochila=peso_mochila;
			mejor_combinacion=i;
			mejor_valor_mochila=valor_mochila;
		}
	}
	
	//MOSTRAMOS LA SOLUCION
	cargaBinaria(mejor_combinacion,cromosoma,n*n);
	cout << "Valor maximo: "<<mejor_valor_mochila<<endl;
	
	cout << "PESOS (Toneladas)"<<endl;
	for (int j=0; j<n*n;j++){
		if (cromosoma[j]==1)//cada vez que encuentre "activado" el objeto/caja
			cout << pesos[j]<< " ";
		else
			cout<< "00 ";//si no está "activado" el objeto/caja, muestro 00
			
		//voy a dar un salto de línea cada vez que termine de recorrer una línea de la matriz
		if ((j+1)%n==0) cout<<endl;
	}
	cout<<endl;
	
	cout << "VALORES (Miles de $)"<<endl;
	for (int j=0; j<n*n;j++){
		if (cromosoma[j]==1)//cada vez que encuentre "activado" el objeto/caja
			cout << valores[j]<< " ";
		else
			cout<< "00 ";
		//voy a dar un salto de línea cada vez que termine de recorrer una línea de la matriz
		if ((j+1)%n==0) cout<<endl;
	}
	cout<<endl;
	return 0;
}
