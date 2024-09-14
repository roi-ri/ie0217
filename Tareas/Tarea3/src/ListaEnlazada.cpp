#include "ListaEnlazada.hpp"

ListaEnlazada::ListaEnlazada() : cabeza(nullptr) {}


/**
 * @brief Destructor de la lista enlazada.
 *
 * Libera la memoria ocupada por todos los nodos de la lista.
 */
ListaEnlazada::~ListaEnlazada() {
    while (cabeza != nullptr) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}
/**
 * @brief Inserta una canción al inicio de la lista.
 * @param cancion La canción a insertar en la lista.
 *
 * Crea un nuevo nodo con la canción proporcionada y lo inserta al inicio de la lista.
 */
void ListaEnlazada::insertarInicio(const Cancion& cancion) {
    Nodo* nuevoNodo = new Nodo(cancion);
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}
/**
 * @brief Inserta una canción al final de la lista.
 * @param cancion La canción a insertar en la lista.
 *
 * Crea un nuevo nodo con la canción proporcionada e itera por la lista para
 * insertarla al final. Si la lista está vacía, el nuevo nodo se convierte en la cabeza.
 */
void ListaEnlazada::insertarFinal(const Cancion& cancion) {
    Nodo* nuevoNodo = new Nodo(cancion);
    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
    } else {
        Nodo* temp = cabeza;
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}
/**
 * @brief Elimina una canción de la lista por su nombre.
 * @param nombre El nombre de la canción a eliminar.
 *
 * Busca la canción en la lista por su nombre. Si la encuentra, la elimina y libera su memoria.
 */
void ListaEnlazada::eliminar(const std::string& nombre) {
    if (cabeza == nullptr) return;

    if (cabeza->cancion.getNombre() == nombre) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        return;
    }

    Nodo* temp = cabeza;
    while (temp->siguiente != nullptr && temp->siguiente->cancion.getNombre() != nombre) {
        temp = temp->siguiente;
    }

    if (temp->siguiente != nullptr) {
        Nodo* nodoAEliminar = temp->siguiente;
        temp->siguiente = temp->siguiente->siguiente;
        delete nodoAEliminar;
    }
}
/**
 * @brief Modifica una canción existente en la lista.
 * @param nombre El nombre de la canción a modificar.
 * @param nuevaCancion La nueva canción que reemplazará a la existente.
 *
 * Busca la canción en la lista por su nombre y, si la encuentra, la reemplaza
 * con la nueva canción proporcionada.
 */
void ListaEnlazada::modificar(const std::string& nombre, const Cancion& nuevaCancion) {
    Nodo* temp = cabeza;
    while (temp != nullptr) {
        if (temp->cancion.getNombre() == nombre) {
            temp->cancion = nuevaCancion;
            return;
        }
        temp = temp->siguiente;
    }
}
/**
 * @brief Imprime la lista de canciones.
 *
 * Recorre la lista y muestra la información de cada canción en la consola.
 */
void ListaEnlazada::imprimir() const {
    Nodo* temp = cabeza;
    while (temp != nullptr) {
        std::cout << temp->cancion.getNombre() << " - " << temp->cancion.getArtista()
                  << " (" << temp->cancion.getDuracion() << " mins)" << std::endl;
        temp = temp->siguiente;
    }
}
/**
 * @brief Busca una canción en la lista por su nombre.
 * @param nombre El nombre de la canción a buscar.
 * @return Un puntero al nodo que contiene la canción, o nullptr si no se encuentra.
 *
 * Recorre la lista y devuelve un puntero al nodo que contiene la canción con el nombre dado.
 */
Nodo* ListaEnlazada::buscar(const std::string& nombre) const {
    Nodo* temp = cabeza;
    while (temp != nullptr) {
        if (temp->cancion.getNombre() == nombre) return temp;
        temp = temp->siguiente;
    }
    return nullptr;
}
