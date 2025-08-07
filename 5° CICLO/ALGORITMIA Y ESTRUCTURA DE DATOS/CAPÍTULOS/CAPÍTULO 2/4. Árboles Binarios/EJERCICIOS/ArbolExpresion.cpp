#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

struct NodoArbol {
    char valor;
    NodoArbol* izquierda;
    NodoArbol* derecha;
};

struct Arbol {
    NodoArbol* raiz;
    Arbol():raiz(nullptr){}
};

int precedencia(char operador) {
    if (operador == '+' || operador == '-') return 1;
    if (operador == '*' || operador == '/') return 2;
    return 0;
}

bool esOperador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

void plantarArbolBinario(Arbol &arbol, NodoArbol* subarbol_izq, char valor, NodoArbol* subarbol_der){
    arbol.raiz = new NodoArbol();
    arbol.raiz->valor = valor;
    arbol.raiz->izquierda = subarbol_izq;
    arbol.raiz->derecha = subarbol_der;
}

void apilar(stack<NodoArbol*> &pila, NodoArbol* nodo){
    pila.push(nodo);
}

NodoArbol* desapilar(stack<NodoArbol*> &pila){
    NodoArbol* nodo = pila.top(); 
    pila.pop();
    return nodo;
}

Arbol construirArbol(const string& postfija) {
    stack<NodoArbol*> pila;
    Arbol arbol;
    for (char ch : postfija) {
        if (esOperador(ch)) {
            NodoArbol* operador2 = desapilar(pila);
            NodoArbol* operador1 = desapilar(pila);
            plantarArbolBinario(arbol, operador1, ch, operador2);
            apilar(pila, arbol.raiz);
        } else if (isdigit(ch)) { // Asumimos expresiones matematicas con un solo dígito
            plantarArbolBinario(arbol, nullptr, ch, nullptr);
            apilar(pila, arbol.raiz);
        }
    }
    // El último elemento en la pila es la raíz del árbol de expresión
    arbol.raiz = desapilar(pila);
    return arbol;
}

void recorridoInorden(NodoArbol* nodo) {
    if (nodo != nullptr) {
        recorridoInorden(nodo->izquierda);
        cout << nodo->valor << " ";
        recorridoInorden(nodo->derecha);
    }
}

int evaluar(NodoArbol* nodo) {
    if (nodo == nullptr) {
        return 0;
    }

    // Si es una hoja, devolver su valor como entero
    if (nodo->izquierda == nullptr && nodo->derecha == nullptr) {
        return nodo->valor - '0';
    }

    // Evaluar recursivamente los subárboles izquierdo y derecho
    int valorIzquierda = evaluar(nodo->izquierda);
    int valorDerecha = evaluar(nodo->derecha);

    // Aplicar el operador en el nodo actual
    switch (nodo->valor) {
        case '+': return valorIzquierda + valorDerecha;
        case '-': return valorIzquierda - valorDerecha;
        case '*': return valorIzquierda * valorDerecha;
        case '/': return valorIzquierda / valorDerecha;
    }
    return 0;
}

int evaluarIterativo(NodoArbol* raiz) {
    if (!raiz) return 0;

    stack<NodoArbol*> nodos;
    stack<int> valores;
    NodoArbol* actual = raiz;
    NodoArbol* ultimoVisitado = nullptr;

    while (!nodos.empty() || actual != nullptr) {
        // Bajar por la izquierda
        while (actual != nullptr) {
            nodos.push(actual);
            actual = actual->izquierda;
        }

        NodoArbol* nodo = nodos.top();

        // Si el nodo no tiene hijo derecho o ya fue visitado
        if (nodo->derecha == nullptr || nodo->derecha == ultimoVisitado) {
            nodos.pop();

            // Si es un operando, convertir el valor a entero y apilarlo
            if (isdigit(nodo->valor)) {
                valores.push(nodo->valor - '0');
            } else { // Si es un operador, aplicar la operación
                int operandoDerecho = valores.top(); valores.pop();
                int operandoIzquierdo = valores.top(); valores.pop();

                int resultado = 0;
                switch (nodo->valor) {
                    case '+': resultado = operandoIzquierdo + operandoDerecho; break;
                    case '-': resultado = operandoIzquierdo - operandoDerecho; break;
                    case '*': resultado = operandoIzquierdo * operandoDerecho; break;
                    case '/': resultado = operandoIzquierdo / operandoDerecho; break;
                }
                valores.push(resultado);
            }

            // Marcar el nodo como visitado
            ultimoVisitado = nodo;
            actual = nullptr;
        } else {
            // Si tiene hijo derecho, procesarlo después del nodo izquierdo
            actual = nodo->derecha;
        }
    }
    return valores.top();
}


string convertirInfijoAPostfijo(const string& infijo) {
    stack<char> pila;
    string postfijo = "";

    for (char ch : infijo) {
        // Si es carácter vacio, continuar con el siguiente carácter
        if(ch == ' ') continue;
        // Si el carácter es un operando, añadirlo directamente a la salida
        else if (isalnum(ch)) {
            postfijo += ch;
        }
        // Si el carácter es un paréntesis de apertura, apilarlo
        else if (ch == '(') {
            pila.push(ch);
        }
        // Si el carácter es un paréntesis de cierre, vaciar la pila hasta el paréntesis de apertura
        else if (ch == ')') {
            while (!pila.empty() && pila.top() != '(') {
                postfijo += pila.top();
                pila.pop();
            }
            pila.pop(); // Descartar el paréntesis de apertura
        }
        // Si el carácter es un operador
        else {
            while (!pila.empty() && precedencia(pila.top()) >= precedencia(ch)) {
                postfijo += pila.top();
                pila.pop();
            }
            pila.push(ch);
        }
    }

    // Vaciar los operadores restantes en la pila
    while (!pila.empty()) {
        postfijo += pila.top();
        pila.pop();
    }

    return postfijo;
}


int main() {
    string expInfija = "(5-3) + 4*2";
    string expPostfija = convertirInfijoAPostfijo(expInfija);

    cout << "Expresion postfija: "<<expPostfija << endl;

    Arbol arbol = construirArbol(expPostfija);
    cout << "Recorrido inorden del árbol de expresión: ";
    recorridoInorden(arbol.raiz);
    cout << endl;

    int resultado = evaluar(arbol.raiz);
    cout << "Resultado de la expresión: " << resultado << endl;

    return 0;
}
