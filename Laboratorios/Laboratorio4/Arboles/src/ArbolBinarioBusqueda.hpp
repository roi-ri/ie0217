#ifndef ARBOLBINARIOBUSQUEDA_HPP
#define ARBOLBINARIOBUSQUEDA_HPP

#include "NodoArbol.hpp"
#include <iostream>
#include <algorithm>

//Clase
class ArbolBinarioBusqueda {
private:
    NodoArbol* raiz;
    // Se inserta un nodo, son multiples objetos en memoria, cada nodo tiene tres eleemtos, valor - elemenmto izq - elelemto derecha. Direcciones de memoria
    void insertarNodo(NodoArbol*& nodo, int valor) {
        if (nodo == nullptr) {
            nodo = new NodoArbol(valor);
            // SI el numero es menor me voy a la izquierda
        } else if (valor < nodo->dato) {
            insertarNodo(nodo->izquierdo, valor);
        } else {
            // Si es mayor me voy a la derecha
            insertarNodo(nodo->derecho, valor);
        }
    }


    // Función recursiva para recorrer el arbol en preorden
    void preOrden(NodoArbol* nodo) const {
        if (nodo != nullptr) {
            // Procesa la raíz y despues recorre el subárbol izquierdo y derecho
            std::cout << nodo->dato << " ";
            preOrden(nodo->izquierdo);
            preOrden(nodo->derecho);
        }
    }
    // Recorrer el arbol en inorden
    void inOrden(NodoArbol* nodo) const {
        if (nodo != nullptr) {
            // Recorre el subarbol izquierdo, procesa la raíz y luego el subarbol derecho
            inOrden(nodo->izquierdo);
            std::cout << nodo->dato << " ";
            inOrden(nodo->derecho);
        }
    }
    //Funcion para recorrer el arbol en postorden
    void postOrden(NodoArbol* nodo) const {
        if (nodo != nullptr) {
            //recorre el subarbol izquierdo, luego el derecho y finalmente procesa la raíz
            postOrden(nodo->izquierdo);
            postOrden(nodo->derecho);
            std::cout << nodo->dato << " ";
        }
    }
    //Funcion para buscar un valor en el arbol
    bool buscarNodo(NodoArbol* nodo, int valor) const {
        if (nodo == nullptr) return false; // Si el nodo es nulo, no se encuentra el valor 
        if (nodo->dato == valor) return true; // Si el valor coincide con el dato del nodo, el valor fue encontrado
        if (valor < nodo->dato) return buscarNodo(nodo->izquierdo, valor); // SI el valor es menor, se busca en el subarbol izquierdo
        return buscarNodo(nodo->derecho, valor); // SI el valor es mayor va y lo busca en el subarbol derecho.
    }
    // Calcular altura del arbol
    int altura(NodoArbol* nodo) const {
        if (nodo == nullptr) return 0; // SI el nodo es nulo la altura es cero
        return 1 + std::max(altura(nodo->izquierdo), altura(nodo->derecho)); // Altura del nodo es 1 mas la altura del subarbol mas alto
    }
    // Funcion que berifica si el arbol esta balanceado
    bool estaBalanceado(NodoArbol* nodo) const {
        if (nodo == nullptr) return true; // un arbol vacio esta balanceado
        //Se va a calcular la altura de los subarboles izquierdo y dereho
        int alturaIzquierda = altura(nodo->izquierdo);
        int alturaDerecha = altura(nodo->derecho);
        // Un arbol esta balanceado si la diferencia de altura entre los subarboles es menor o igual a 1
        return std::abs(alturaIzquierda - alturaDerecha) <= 1 &&
               estaBalanceado(nodo->izquierdo) &&
               estaBalanceado(nodo->derecho);
    }

public:
    //Constructor que inicializa la raiz del arbol como nula
    ArbolBinarioBusqueda() : raiz(nullptr) {}
    // Insertar valor en el arbol
    void insertar(int valor) {
        insertarNodo(raiz, valor);
    }
    // Recorrer el arbol en preOrden
    void preOrden() const {
        preOrden(raiz);
        std::cout << std::endl;
    }
    //Recorrer el arbol en inOrden
    void inOrden() const {
        inOrden(raiz);
        std::cout << std::endl;
    }
    // Recorrer el arbol en postOrden
    void postOrden() const {
        postOrden(raiz);
        std::cout << std::endl;
    }
    //Buscar un valor dentro del arbol
    bool buscar(int valor) const {
        return buscarNodo(raiz, valor);
    }
    //Calcular la altura del arbol
    int altura() const {
        return altura(raiz);
    }
    // Verificar si el arbol esta balanceado o no
    bool estaBalanceado() const {
        return estaBalanceado(raiz);
    }
};

#endif
