#ifndef BUSQUEDAARBOLBINARIO_HPP
#define BUSQUEDAARBOLBINARIO_HPP
#include "Node.hpp"
/**
 * @class BusquedaBinaria
 * @brief Representa un árbol binario de búsqueda.
 * 
 * Esta clase implementa un árbol binario de búsqueda con operaciones para insertar, eliminar,
 * imprimir en orden, calcular la altura y verificar si el árbol está balanceado.
 */
class BusquedaBinaria {
public: 
    /**
     * @brief Constructor de la clase BusquedaBinaria.
     * 
     * Inicializa el árbol vacío.
     */
    BusquedaBinaria();
    /**
     * @brief Inserta un nuevo valor en el árbol.
     * @param value Valor a insertar.
     */
    void insert(int value);
    /**
     * @brief Elimina un valor del árbol.
     * @param value Valor a eliminar.
     */
    void remove(int value);
     /**
     * @brief Imprime los valores del árbol en orden.
     */
    void printInOrder(); 
     /**
     * @brief Calcula la altura del árbol.
     * @return Altura del árbol.
     */
    int height();
    /**
     * @brief Verifica si el árbol está balanceado.
     * @return `true` si el árbol está balanceado, `false` en caso contrario.
     */
    bool isBalanced();


private: 

    Node* root; ///< Raíz del árbol binario de búsqueda.
     /**
     * @brief Inserta un valor en el árbol de manera recursiva.
     * @param node Nodo actual.
     * @param value Valor a insertar.
     * @return Nodo raíz del subárbol actualizado.
     */
    Node* insert(Node* node, int value);
    /**
     * @brief Elimina un valor del árbol de manera recursiva.
     * @param node Nodo actual.
     * @param value Valor a eliminar.
     * @return Nodo raíz del subárbol actualizado.
     */
    Node* remove(Node* node, int value); 
    /**
     * @brief Encuentra el nodo con el valor mínimo en el subárbol dado.
     * @param node Nodo raíz del subárbol.
     * @return Nodo con el valor mínimo.
     */
    Node* findMin(Node* node);
    /**
     * @brief Imprime los valores del árbol en orden de manera recursiva.
     * @param node Nodo actual.
     */
    void printInorder(Node* node); 
    /**
     * @brief Calcula la altura del árbol de manera recursiva.
     * @param node Nodo actual.
     * @return Altura del subárbol con raíz en el nodo dado.
     */
    int height(Node* node);
    /**
     * @brief Verifica si el árbol está balanceado de manera recursiva.
     * @param node Nodo actual.
     * @return `true` si el subárbol con raíz en el nodo dado está balanceado, `false` en caso contrario.
     */

    bool isBalanced(Node* node); 

};

#endif //BUSQUEDAARBOLBINARIO_HPP
