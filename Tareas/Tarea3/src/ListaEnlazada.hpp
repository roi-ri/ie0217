#ifndef LISTAENLAZADA_HPP
#define LISTAENLAZADA_HPP

#include "NodoC.hpp"
#include "Cancion.hpp" 
#include <iostream>



/**
 * @class ListaEnlazada
 * @brief Representa una lista enlazada simple para gestionar una colección de canciones.
 *
 * Esta clase implementa una lista enlazada simple donde cada nodo contiene una canción y un puntero al siguiente nodo. 
 * Permite realizar operaciones básicas como insertar, eliminar, modificar e imprimir canciones, 
 * así como buscar una canción en la lista.
 */
class ListaEnlazada {
private:
    Nodo* cabeza; /**< Puntero al primer nodo de la lista. */

public:
    /**
     * @brief Constructor por defecto de la lista enlazada.
     *
     * Inicializa una lista vacía con el puntero a la cabeza apuntando a nullptr.
     */
    ListaEnlazada();
     /**
     * @brief Destructor de la lista enlazada.
     *
     * Libera la memoria ocupada por los nodos de la lista.
     */
    ~ListaEnlazada();
/**
     * @brief Inserta una canción al inicio de la lista.
     * @param cancion La canción a insertar en la lista.
     */
    void insertarInicio(const Cancion& cancion);
       /**
     * @brief Inserta una canción al final de la lista.
     * @param cancion La canción a insertar en la lista.
     */
    void insertarFinal(const Cancion& cancion);
    /**
     * @brief Elimina una canción de la lista por su nombre.
     * @param nombre El nombre de la canción a eliminar.
     */
    void eliminar(const std::string& nombre);
    /**
     * @brief Modifica una canción existente en la lista.
     * @param nombre El nombre de la canción a modificar.
     * @param nuevaCancion La nueva canción que reemplazará a la existente.
     */
    void modificar(const std::string& nombre, const Cancion& nuevaCancion);
    /**
     * @brief Imprime la lista de canciones.
     *
     * Recorre la lista e imprime la información de cada canción en la consola.
     */
    void imprimir() const;
     /**
     * @brief Busca una canción en la lista por su nombre.
     * @param nombre El nombre de la canción a buscar.
     * @return Un puntero al nodo que contiene la canción, o nullptr si no se encuentra.
     */
    Nodo* buscar(const std::string& nombre) const;
};

#endif // LISTAENLAZADA_HPP
