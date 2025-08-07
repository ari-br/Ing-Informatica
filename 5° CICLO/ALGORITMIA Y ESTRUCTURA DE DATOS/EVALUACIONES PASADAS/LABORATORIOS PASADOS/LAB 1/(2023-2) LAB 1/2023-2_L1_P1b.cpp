#include <iostream>
#include <math.h>


using namespace std;

int main(){
	int filas=4, columnas=10;//dimensiones del matriz
	
	char matriz[filas][columnas]={
		{'H','C','H','B','Y','S','O','S','O','H'},
        {'S','C','S','S','Y','Q','O','S','Z','K'},
        {'O','P','N','Y','O','K','F','H','C','K'},
        {'O','B','N','I','Y','S','P','O','O','K'}
	};
	
	cout<< "La formula HSO se puede formarta en los siguientes puntos de la matriz: "<<endl;
	for (int i=0;i<filas; i++){
		for (int j=0;j<columnas; j++){
			//Verificamos si la celda que estoy recorriendo es H, S u O
			if (matriz[i][j]=='H' || matriz[i][j]=='S' || matriz[i][j]=='O'){//también puede ser con SWITCH...CASE
				//HACIA ARRIBA
				//verifico que no me "descarrilaré"
				if (i-2>=0){//si puedo recorrer sin salirme de la matriz, entonces verifico las letras que me faltan
					if(((matriz[i-1][j])=='H'||(matriz[i-1][j])=='S'||(matriz[i-1][j])=='O') && matriz[i-1][j]!=matriz[i][j]){
						if(((matriz[i-2][j])=='H'||(matriz[i-2][j])=='S'||(matriz[i-2][j])=='O') && matriz[i-2][j]!=matriz[i-1][j] && matriz[i-2][j]!=matriz[i][j])
							cout << i << "," << j << "    ";
					}
				}
				//HACIA ABAJO
				//verifico que no me "descarrilaré"
				if (i+2<filas){//si puedo recorrer sin salirme de la matriz, entonces verifico las letras que me faltan
					if(((matriz[i+1][j])=='H'||(matriz[i+1][j])=='S'||(matriz[i+1][j])=='O') && matriz[i+1][j]!=matriz[i][j]){
						if(((matriz[i+2][j])=='H'||(matriz[i+2][j])=='S'||(matriz[i+2][j])=='O') && matriz[i+2][j]!=matriz[i+1][j] && matriz[i+2][j]!=matriz[i][j])
							cout << i << "," << j << "    ";
					}
				}
				//HACIA DERECHA
				//verifico que no me "descarrilaré"
				if (j+2<columnas){//si puedo recorrer sin salirme de la matriz, entonces verifico las letras que me faltan
					if(((matriz[i][j+1])=='H'||(matriz[i][j+1])=='S'||(matriz[i][j+1])=='O') && matriz[i][j+1]!=matriz[i][j]){
						if(((matriz[i][j+2])=='H'||(matriz[i][j+2])=='S'||(matriz[i][j+2])=='O') && matriz[i][j+2]!=matriz[i][j+1] && matriz[i][j+2]!=matriz[i][j])
							cout << i << "," << j << "    ";
					}
				}
				//HACIA IZQUIERDA
				//verifico que no me "descarrilaré"
				if (j-2>=0){//si puedo recorrer sin salirme de la matriz, entonces verifico las letras que me faltan
					if(((matriz[i][j-1])=='H'||(matriz[i][j-1])=='S'||(matriz[i][j-1])=='O') && matriz[i][j-1]!=matriz[i][j]){
						if(((matriz[i][j-2])=='H'||(matriz[i][j-2])=='S'||(matriz[i][j-2])=='O') && matriz[i][j-2]!=matriz[i][j-1] && matriz[i][j-2]!=matriz[i][j])
							cout << i << "," << j << "    ";
					}
				}
			}
		}
	}
	return 0;
}
