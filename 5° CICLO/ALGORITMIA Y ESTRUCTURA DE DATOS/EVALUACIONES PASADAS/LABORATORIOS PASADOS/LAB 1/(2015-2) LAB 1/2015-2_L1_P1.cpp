/*
Implementar una función recursiva cuya cabecera sea la siguiente: triangulo(int a, int b). Esta función
deberá generar un patrón como el siguiente:
* * *
* * * *
* * * * *
* * * * *
* * * *
* * *
El patrón descrito anteriormente es generado por la llamada a triangulo(3,5).
Nota: a siempre debe ser menor o igual que b
*/
#include<iostream>
using namespace std;
void triangulo (int a, int b){
	//CASO BASE:
	if (a>b)
		return;
	else{
		//CASO RECURSIVO
		for (int i=0; i<a;i++)
			cout<<" * ";
		cout<<endl;
		
		triangulo (a+1,b);
		
		for (int i=0; i<a;i++)
			cout<<" * ";
		cout<<endl;
	}
}

int main(){
	triangulo (3,5);
	return 0;
}
