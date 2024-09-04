#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP

struct NodoArbol {
    int dato;
    NodoArbol* izquierdo; // Puntero de lado izquierdo
    NodoArbol* derecho; // Puntero de lado derecho

    NodoArbol(int valor) : dato(valor), izquierdo(nullptr), derecho(nullptr) {}
};

#endif


