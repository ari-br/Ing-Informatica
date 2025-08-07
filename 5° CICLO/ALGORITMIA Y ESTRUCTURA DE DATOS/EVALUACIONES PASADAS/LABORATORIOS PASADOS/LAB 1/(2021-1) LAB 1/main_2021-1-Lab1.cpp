#include <iostream>
#include <cmath>

#define N 10
using namespace std;

void cargaBin(int n,int cromosoma[N],int size){
	int i;
	for (i=0; i<size; i++){
		cromosoma[i] = 0;
	}
	i = 0;
	while (n>0){
		cromosoma[i++] = n%2;
		n = n/2;
	}
}

int main(){
	int n = 4;
	int bahias[3][4] = {{2,5,6,10},
						{7,8,15,3},
						{11,9,6,4}};
	int m = 5;
	int c = 20;
	int solucion = -1, peso, cantProductos;
	int combinaciones = pow(2,n);
	int cromo1[N], cromo2[N], cromo3[N];
	/*Combinaciones bahia1*/
	for (int i=0; i<combinaciones; i++){
		cargaBin(i,cromo1,n);
		/*Combinaciones bahia2*/
		for (int j=0; j<combinaciones; j++){
			cargaBin(j,cromo2,n);
			/*Combinaciones bahia3*/
			for (int k=0; k<combinaciones; k++){
				cargaBin(k,cromo3,n);
				/*Aqui vamos a verificar si esta combinacion de 3 bahias cumple con la condicion*/
				peso = 0;
				cantProductos = 0;
				for (int l=0; l<n; l++){
					if (cromo1[l]==1){
						peso = peso + bahias[0][l];
						cantProductos++;
					}
				}
				for (int l=0; l<n; l++){
					if (cromo2[l]==1){
						peso = peso + bahias[1][l];
						cantProductos++;
					}
				}
				for (int l=0; l<n; l++){
					if (cromo3[l]==1){
						peso = peso + bahias[2][l];
						cantProductos++;
					}
				}
				if (peso==c && cantProductos==m){
					solucion = 1;
					/*Imprimo la solucion*/
					cout << "Bahia 1: ";
					for (int l=0; l<n; l++){
						if (cromo1[l]==1){
							cout << bahias[0][l] << " ";
						}
					}
					cout << "Bahia 2: ";
					for (int l=0; l<n; l++){
						if (cromo2[l]==1){
							cout << bahias[1][l] << " ";
						}
					}
					cout << "Bahia 3: ";
					for (int l=0; l<n; l++){
						if (cromo3[l]==1){
							cout << bahias[2][l] << " ";
						}
					}
					cout << endl;
//Para la parte c se comenta esta linea, para la parte b descomentar esta linea
//					break; 
				}
			}
/*			if (solucion==1){
				break;
			}*/
		}
/*		if (solucion==1){
			break;
		}*/
	}
	if (solucion==-1){
		cout << "No hay respuesta valida";
	}
	return 0;
}
