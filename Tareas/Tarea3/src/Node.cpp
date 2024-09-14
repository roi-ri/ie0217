#include "Node.hpp"
/**
 * @brief Constructor de la clase `Node`.
 * @param valor Valor entero que se almacenará en el nodo.
 *
 * Este constructor inicializa un nuevo nodo con el valor proporcionado
 * y establece los punteros `left` y `right` a `nullptr`.
 */
Node::Node(int valor){
    data = valor;
    left = nullptr;
    right = nullptr; 
};
