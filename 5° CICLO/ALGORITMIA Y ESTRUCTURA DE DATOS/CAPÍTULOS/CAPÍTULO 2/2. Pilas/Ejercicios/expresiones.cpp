#include <iostream>
#include "Pila.h"
using namespace std;
#include "funcionesPila.h"

void imprimir(char expresion[], int n){
    for(int i=0;i<n;i++)
        cout<<expresion[i]<<" ";
    cout<<endl;
}

bool esOperador(char op){
    return op == '+' or op == '-' or op == '*' or op == '/';
}

int aplicar(int op1, int op2, char op){
    if(op == '+') return op2 + op1;
    else if(op == '-') return op2 - op1;
    else if(op == '*') return op2 * op1;
    else if(op == '/') return op2 / op1;
}

int resolver(char expresion[], int n){
    struct Pila pila;
    construir(pila);    
    for(int i=0;i<n;i++){
        if(esOperador(expresion[i])) {
            int op1 = desapilar(pila);
            int op2 = desapilar(pila);
            int res = aplicar(op1, op2, expresion[i]);
            apilar(pila, res);
        } else { //operando
            apilar(pila, expresion[i] - '0');
        }
    }
    if(esPilaVacia(pila)){
        cout<<"Expresion incorrecta\n";
        return -1;
    }
    else {
        int res = desapilar(pila);
        return res;
    }
}

int main(int argc, char** argv) {    
    char expresion[5] = {'5','2','3','*','+'};
    imprimir(expresion, 5);
    int resultado = resolver(expresion, 5);
    cout<<"Resultado: "<<resultado<<endl;
    return 0;
}



