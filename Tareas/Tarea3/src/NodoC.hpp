#ifndef NODOC_HPP
#define NODOC_HPP

#include "Cancion.hpp"


/**
 * @struct Nodo
 * @brief Estructura que representa un nodo en una lista enlazada.
 *
 * Esta estructura es utilizada para almacenar un objeto de tipo `Cancion`
 * y un puntero al siguiente nodo en la lista enlazada.
 */
struct Nodo {
    /**
     * @var cancion
     * @brief La canción almacenada en el nodo.
     *
     * Este miembro contiene la instancia de la clase `Cancion` que está
     * asociada con el nodo.
     */
    Cancion cancion;
    /**
     * @var siguiente
     * @brief Puntero al siguiente nodo en la lista.
     *
     * Este puntero apunta al siguiente nodo en la lista enlazada. Si es `nullptr`,
     * significa que el nodo es el último en la lista.
     */
    Nodo* siguiente;
     /**
     * @brief Constructor de la estructura `Nodo`.
     * @param cancion La canción que se almacenará en el nodo.
     *
     * Inicializa el nodo con una canción y establece el puntero `siguiente`
     * a `nullptr`.
     */
    Nodo(const Cancion& cancion) : cancion(cancion), siguiente(nullptr) {}
};

#endif //NODOC_HPP
