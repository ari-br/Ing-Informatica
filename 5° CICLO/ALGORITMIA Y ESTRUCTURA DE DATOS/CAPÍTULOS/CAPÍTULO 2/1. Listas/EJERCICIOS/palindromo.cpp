
#include <iostream>
using namespace std;
#include "Lista.h"
#include "funciones.h"


// Función recursiva auxiliar que compara nodos utilizando paso por referencia
bool esPalindromoRecursivo(struct Nodo*& izquierda, struct Nodo* derecha) {
    // Caso base: Si hemos llegado al final de la lista, retornamos true
    if (derecha == nullptr) {
        return true;
    }
    // Verificamos la parte recursiva para el nodo siguiente
    bool esPalindromoSublista = esPalindromoRecursivo(izquierda, derecha->siguiente);
    // Si la sublista ya no es palíndromo, retornamos false
    if (!esPalindromoSublista) {
        return false;
    }
    // Comparamos el valor del nodo actual (derecha) con el de izquierda
    bool esIgual = (izquierda->elemento == derecha->elemento);
    // Avanzamos el puntero de la izquierda hacia el siguiente nodo
    izquierda = izquierda->siguiente;

    return esIgual;
}

bool esPalindromoRecursivo(const struct Lista & lista){
    Nodo* head = lista.cabeza;
    return esPalindromoRecursivo(head, head);
}

// Función para invertir una lista enlazada iterativamente
Nodo* reverseList(Nodo* head) {
    Nodo* newHead = nullptr;
    Nodo* current = head;
    while (current) {
        Nodo* temp = current->siguiente;
        current->siguiente = newHead;
        newHead = current;
        current = temp;
    }
    return newHead;
}

// Función para verificar si una lista enlazada es un palíndromo
bool esPalindromo(struct Lista & lista) {
    Nodo* cabeza = lista.cabeza;
    if (cabeza == nullptr || cabeza->siguiente == nullptr) {
        return true; // Si está vacía o tiene solo un nodo, es palíndromo
    }
    // Usaremos los punteros lentos y rápidos para encontrar la mitad de la lista
    Nodo* lento = cabeza;
    Nodo* rapido = cabeza;
    Nodo* previoLento = nullptr;
    // Avanzamos hasta la mitad de la lista (puntero rápido se mueve al doble de velocidad)
    while (rapido != nullptr && rapido->siguiente != nullptr) {
        previoLento = lento;
        lento = lento->siguiente;
        rapido = rapido->siguiente->siguiente;
    }
    // Si la lista tiene un número impar de nodos, saltamos el nodo del medio
    if (rapido != nullptr) {
        lento = lento->siguiente;
    }
    // Invertimos la segunda mitad de la lista
    Nodo* mitadInvertida = reverseList(lento);
    // Comparamos la primera mitad con la segunda mitad invertida
    Nodo* primeraMitad = cabeza;
    Nodo* segundaMitad = mitadInvertida;
    bool esPal = true;
    while (segundaMitad != nullptr) {
        if (primeraMitad->elemento != segundaMitad->elemento) {
            esPal = false;
            break;
        }
        primeraMitad = primeraMitad->siguiente;
        segundaMitad = segundaMitad->siguiente;
    }
    // Restauramos la segunda mitad (opcional si se necesita mantener la lista original)
    reverseList(mitadInvertida);
    return esPal;
}


int main(int argc, char** argv) {
    struct Lista lista;
    construir(lista);
    
    insertarAlFinal(lista, 6);
    insertarAlFinal(lista, 8);
    insertarAlFinal(lista, 7);
    insertarAlFinal(lista, 7);
    insertarAlFinal(lista, 8);
    insertarAlFinal(lista, 6);
    imprime(lista);
    cout<<"Es palindromo:"<<esPalindromo(lista)<<endl;
    
    return 0;
}


