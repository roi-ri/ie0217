#ifndef LISTAENLAZADA_HPP
#define LISTAENLAZADA_HPP

#include "Nodo.hpp"
#include <iostream>

// Se va a definir la clase nodo, es la estructura base para las listas enlazadas con las que se esta trabajando
class ListaEnlazada {
private:
    //Puntero que apunta hacia el primer elemento de la lista llamado cabeza
    Nodo* cabeza;

public:
    // Constructor de la lista que inicializa a cabeza como un puntero nulo, esto para indicar que está vacio
    ListaEnlazada() : cabeza(nullptr) {}
    
    //destructor, va a limpiar la memoria asignada a los nodos de la lista
    ~ListaEnlazada() {
        //Se va a recorrer la lista siempre y cuando el elemento cabeza no esté vacio, esto para liberar la memoria asignada de cada nodo
        while (cabeza != nullptr) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
    //Funcion para insertar un nuevo valor a la lista
    void insertarInicio(int valor) {
        //Se crea un nodo con el valor proporcionado
        Nodo* nuevoNodo = new Nodo(valor);
        // Establece el siguiente nodo como la cabeza actual
        nuevoNodo->siguiente = cabeza;
        // Actualiza la cabeza que apunte al nuevo nodo
        cabeza = nuevoNodo;
    }
    // Funcion para insertar un nuevo valor al final de la lista
    void insertarFinal(int valor) {
        //Se crea un nuevo nodo con el valor proporcionado
        Nodo* nuevoNodo = new Nodo(valor);
        // Verifica si la lista está vacía, en caso de estarlo va a establecer que cabeza es el nuevo nodo
        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
        } else {
            //Si no, va a recorrer la lista hasta encontrar el último nodo
            Nodo* temp = cabeza;
            while (temp->siguiente != nullptr) {
                temp = temp->siguiente;
            }
            // Establece el que era el siguiente nodo del último como el nuevo nodo 
            temp->siguiente = nuevoNodo;
        }
    }
    // FUncion utilizada para eliminar un valor
    void eliminar(int valor) {
        //Si la lista se encuentra vacía se sale de la funcion
        if (cabeza == nullptr) return;
        // Si el nodo a eliminar es cabeza se actualiza y se libera la memoria del nodo
        if (cabeza->dato == valor) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            return;
        }
        // Recorre la lista mientras busca el nodo con el valor dado
        Nodo* temp = cabeza;
        while (temp->siguiente != nullptr && temp->siguiente->dato != valor) {
            temp = temp->siguiente;
        }
        //Si se encuentra el nodo se desliga de la lista y se libera la memoria 
        if (temp->siguiente != nullptr) {
            Nodo* nodoAEliminar = temp->siguiente;
            temp->siguiente = temp->siguiente->siguiente;
            delete nodoAEliminar;
        }
    }
    // Funcion para imprimir los valores de todos los nodos en la lista
    void imprimir() const {
        // Comienza desde la cabeza y recorre todos los nodos
        Nodo* temp = cabeza;
        while (temp != nullptr) {
            // Imprime el valor del nodo seguido por una flecha
            std::cout << temp->dato << " -> ";
            temp = temp->siguiente;
        }
        // Imprime "null" al final para indicar el final de la lista
        std::cout << "null" << std::endl;
    }

    // Función para buscar un valor en la lista, retorna true si el valor existe
    bool buscar(int valor) const {
        // Recorre la lista desde la cabeza
        Nodo* temp = cabeza;
        while (temp != nullptr) {
            // Si encuentra el valor, retorna true
            if (temp->dato == valor) return true;
            temp = temp->siguiente;
        }
        // Si no se encuentra el valor, retorna false
        return false;
    }
};

#endif