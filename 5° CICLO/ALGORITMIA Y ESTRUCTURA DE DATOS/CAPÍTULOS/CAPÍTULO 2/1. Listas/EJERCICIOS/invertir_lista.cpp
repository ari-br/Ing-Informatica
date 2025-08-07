
#include <iostream>
using namespace std;
#include "Lista.h"
#include "funciones.h"

void imprimeInvertido(struct Nodo* nodo){
    if(nodo == nullptr) return;
    imprimeInvertido(nodo->siguiente);
    cout<<nodo->elemento<<"->";
}

// Función para invertir una lista enlazada iterativamente
void reverseList(struct Lista &lista) {
    Nodo* newHead = nullptr;
    Nodo* current = head;
    while (current) {
        Nodo* temp = current->siguiente;
        current->siguiente = newHead;
        newHead = current;
        current = temp;
    }
    lista.cabeza = newHead;
}

// Función para invertir una lista enlazada recursivamente
Nodo* reverseRec(Nodo* head) {
    if(head == nullptr || head->siguiente == nullptr) return head;
    //invertir la cola de la lista
    Nodo* newHead = reverseRec(head->siguiente);
    //el ultimo de la lista invertida apunta al head
    head->siguiente->siguiente = head;
    //el head es el ultimo nodo
    head->siguiente = nullptr;
    return newHead; 
}

void reverseListRec(struct Lista &lista){
    lista.cabeza = reverseRec(lista.cabeza);
}

int main2(int argc, char** argv) {
    struct Lista lista;
    construir(lista);
    
    insertarAlFinal(lista, 6);
    insertarAlFinal(lista, 8);
    insertarAlFinal(lista, 10);
    insertarAlFinal(lista, 3);
    imprime(lista);
    reverseListRec(lista);
    imprime(lista);

    return 0;
}