#include<iostream>
using namespace std;

//mapa que recorrerá el robot-sonda
int mapa[][6]={ {0,0,0,1,0,1},
				{0,0,1,0,0,0},
				{0,1,0,0,0,1},
				{1,0,0,0,0,0},
				{0,1,0,0,0,0},
				{0,0,0,0,1,0}};

int BuscaUnidades(int x, int y, int movX, int movY, int banderaX, int banderaY, int n, int m){
	int i;
	int contador=0; //inicializamos el contador para esta instancia
	
	//CASO BASE: cuando el recorrido llegó a un límite del tablero/mapa
	if (x>=n || y>=m || x<0 || y<0) //si llegué al límite abajo, derecha, arriba, izquierda
		return 0;//como ya se "descarriló" o pasó el límite del tablero, devuelve 0 unidades encontradas
	
	//CASO RECURSIVO
	if (banderaX==0 && banderaY==0)//En la primera vez cuento 
		contador=contador+mapa[x][y];//contamos si hay una unidad en donde inicia el robot
	
	if (banderaX==0){//Entra sólo la primera vez (porque se envía del programa principal (0,0) y si el movimiento no es en esta dirección
		for (i=x+1; i<n;i++)//contamos hacia ABAJO
			contador=contador+mapa[i][y];
		for (i=0; i<x;i++)//contamos hacia ARRIBA
			contador=contador+mapa[i][y];
	}
	if (banderaY==0){//Entra sólo la primera vez (porque se envía del programa principal (0,0) y si el movimiento no es en esta dirección
		for (i=y+1; i<m;i++)//contamos hacia la DERECHA
			contador=contador+mapa[x][i];
		for (i=0; i<y;i++)//contamos hacia IZQUIERDA
			contador=contador+mapa[x][i];
	}	
	
	contador=contador+ BuscaUnidades(x+movX,y+movY,movX,movY,movX,movY,n,m);
	return contador;
}
int main (){
	int contador_unidades=0;
	int n=6,m=6;//datos de entrada
	
	//3,2 posicion donde se coloca el robot (posicion inicial)
	//Para el movimiento utilizaremos: derecha (0,1), izquierda (0,-1), abajo (1,0), arriba (-1,0)
	//OJO!!! tenemos que tener cuidado de NO CONTAR doble/triple según el movimiento ingresado
	contador_unidades=BuscaUnidades(3,2,0,1,0,0,n,m);//parametros: pos_iniX,pos_iniY, movX, movY, banderaX,banderaY, limiteX, limiteY
	cout<<"Cantidad de unidades encontrada: "<<contador_unidades<<endl;
	
	return 0;
}
