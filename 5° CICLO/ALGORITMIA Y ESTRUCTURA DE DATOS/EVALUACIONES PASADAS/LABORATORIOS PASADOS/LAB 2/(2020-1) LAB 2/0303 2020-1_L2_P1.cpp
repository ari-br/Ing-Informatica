#include<iostream>
#define MAX 10
using namespace std;

void CargaAlmacen(int x, int y, int n, int m, int almacen[][MAX]){
	int i;
	//CASO BASE: si se pasa los límites
	if (x>=n || y>=m)
		return;
	
	if (x==n-1){//escenario en la que el recorrido quedó con una fila
		for (i=y; i<m;i++)
			cout << almacen[x][i] << " ";
		return;
	}
	if (y==m-1){//escenario en la que el recorrido quedó con una columna
		for (i=x; i<n;i++)
			cout << almacen[i][y] << " ";
		return;
	}
	if (x==n-1 && y==m-1)//nos quedamos con una matriz 1x1
		cout<< almacen[x][y]<< " ";
		
	//RECORREMOS COMO REMOLINO
	for (i=y;i<m-1;i++)//recorremos DERECHA
		cout<< almacen[x][i]<< " ";
	for (i=x;i<n-1;i++)//recorremos ABAJO
		cout<< almacen[i][m-1]<< " ";
	for (i=m-1;i>y;i--)//recorremos IZQUIERDA
		cout<< almacen[n-1][i]<< " ";
	for (i=n-1;i>x;i--)//recorremos ARRIBA
		cout<< almacen[i][y]<< " ";
		
	CargaAlmacen(x+1,y+1,n-1,m-1,almacen);
	
}
int main (){
	int cont=1;
	int x=0,y=0,n=3,m=5;
	int almacen[MAX][MAX];
	
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			almacen[i][j]=cont++;
			
	CargaAlmacen(x,y,n,m,almacen);
	
	return 0;
}
