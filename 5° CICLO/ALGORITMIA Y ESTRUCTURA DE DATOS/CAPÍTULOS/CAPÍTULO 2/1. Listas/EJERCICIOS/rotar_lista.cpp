
#include <iostream>
using namespace std;
#include "Lista.h"
#include "funciones.h"


void rotateLeft(struct Lista & lista){
    Nodo* head = lista.cabeza;
    if(head == nullptr || head->siguiente == nullptr) return;
    Nodo* temp = head;
    while(temp->siguiente != nullptr) temp = temp->siguiente;
    temp->siguiente = head;
    head = head->siguiente;
    temp->siguiente->siguiente = nullptr;
    lista.cabeza = head;
}

void rotateRight(struct Lista & lista){
    Nodo* head = lista.cabeza;
    if(head == nullptr || head->siguiente == nullptr) return;
    Nodo* temp = head;
    while(temp->siguiente->siguiente != nullptr) temp = temp->siguiente;
    temp->siguiente->siguiente = head;
    head = temp->siguiente;
    temp->siguiente = nullptr;
    lista.cabeza = head;
}

int main3(int argc, char** argv) {
    struct Lista lista;
    construir(lista);
    
    insertarAlFinal(lista, 6);
    insertarAlFinal(lista, 8);
    insertarAlFinal(lista, 10);
    insertarAlFinal(lista, 3);
    imprime(lista);
    rotateRight(lista);
    imprime(lista);
    rotateRight(lista);
    imprime(lista);    
    
    return 0;
}

