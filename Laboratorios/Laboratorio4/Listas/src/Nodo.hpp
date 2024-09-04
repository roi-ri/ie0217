#ifndef NODO_HPP
#define NODO_HPP

struct Nodo {
    int dato;
    Nodo* siguiente;
    
    Nodo(int valor) : dato(valor), siguiente(nullptr) {} 
    // Se considera piblico por defecto, define una estructura que se llama nodo con un valor entero que se llama dato y que tiene un puntero que apunta a siguiente.

};

#endif



