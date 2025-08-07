#include<iostream>
#define MAX 10
using namespace std;

int Robot (int x, int y, int n, int m, int tablero[][MAX]){
	int abajo=-999999, derecha=-999999, total;
	//CASO BASE: cuando nos queda una sóla celda (1x1)
	if (x==n-1 && y==m-1)
		return tablero[x][y];//devuelvo el mismo valor de la celda
	
	//CASO RECURSIVO:
	if (x+1<n)//si puedo ir hacia la derecha
		derecha=Robot(x+1,y,n,m,tablero);//llamo recursivamente para conocer el mejor resultado si voy hacia la derecha
	if (y+1<m)//si puedo ir hacia abajo
		abajo=Robot(x,y+1,n,m,tablero);//llamo recursivamente para conocer el mejor resultado si voy hacia abajo
	//en este punto, ya se ha tomado el caso base y empezamos a retornar los llamadas recursivas
	if (derecha<abajo)
		total=tablero[x][y]+abajo;//acumulamos lo que devolvió ir hacia abajo
	else
		total=tablero[x][y]+derecha;//acumulamos lo que devolvió ir hacia la derecha
	
	return total;
}

int main (){
	int n=2,m=2;
	int tablero[MAX][MAX]={{3,5},{-2,4}};
	cout << Robot(0,0,n,m,tablero)<<endl;
	return 0;
}
