#include "BusquedaArbolBinario.hpp"
#include <iostream>
#include <algorithm>


using namespace std;
/**
 * @brief Constructor de la clase BusquedaBinaria.
 * 
 * Inicializa el árbol binario vacío.
 */
BusquedaBinaria::BusquedaBinaria() : root(nullptr) {}
/**
 * @brief Inserta un valor en el árbol binario de búsqueda.
 * @param value Valor a insertar.
 */
void BusquedaBinaria::insert(int value) {
    root = insert(root, value);
}
/**
 * @brief Inserta un valor en el árbol de manera recursiva.
 * @param node Nodo actual.
 * @param value Valor a insertar.
 * @return Nodo raíz del subárbol actualizado.
 */
Node* BusquedaBinaria::insert(Node* node, int value) {
    if (node == nullptr) {
        return new Node(value);
    }
    if (value < node->data) {
        node->left = insert(node->left, value);
    } else {
        node->right = insert(node->right, value);
    }
    return node;
}
/**
 * @brief Elimina un valor del árbol binario de búsqueda.
 * @param value Valor a eliminar.
 */
void BusquedaBinaria::remove(int value) {
    root = remove(root, value);
}
/**
 * @brief Elimina un valor del árbol de manera recursiva.
 * @param node Nodo actual.
 * @param value Valor a eliminar.
 * @return Nodo raíz del subárbol actualizado.
 */

Node* BusquedaBinaria::remove(Node* node, int value) {
    if (node == nullptr) return nullptr;

    if (value < node->data) {
        node->left = remove(node->left, value);
    } else if (value > node->data) {
        node->right = remove(node->right, value);
    } else {
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            return nullptr;
        } else if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        } else {
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
    }
    return node;
}
/**
 * @brief Encuentra el nodo con el valor mínimo en el subárbol dado.
 * @param node Nodo raíz del subárbol.
 * @return Nodo con el valor mínimo.
 */
Node* BusquedaBinaria::findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}
/**
 * @brief Imprime los valores del árbol en orden.
 */

void BusquedaBinaria::printInOrder() {
    printInorder(root);
    std::cout << std::endl;
}
/**
 * @brief Imprime los valores del árbol en orden de manera recursiva.
 * @param node Nodo actual.
 */
void BusquedaBinaria::printInorder(Node* node) {
    if (node != nullptr) {
        printInorder(node->left);
        std::cout << node->data << " ";
        printInorder(node->right);
    }
}
/**
 * @brief Calcula la altura del árbol.
 * @return Altura del árbol.
 */
int BusquedaBinaria::height() {
    return height(root);
}
/**
 * @brief Calcula la altura del árbol de manera recursiva.
 * @param node Nodo actual.
 * @return Altura del subárbol con raíz en el nodo dado.
 */
int BusquedaBinaria::height(Node* node) {
    if (node == nullptr) return 0;
    return 1 + std::max(height(node->left), height(node->right));
}

/**
 * @brief Verifica si el árbol está balanceado.
 * @return `true` si el árbol está balanceado, `false` en caso contrario.
 */
bool BusquedaBinaria::isBalanced() {
    return isBalanced(root);
}
/**
 * @brief Verifica si el árbol está balanceado de manera recursiva.
 * @param node Nodo actual.
 * @return `true` si el subárbol con raíz en el nodo dado está balanceado, `false` en caso contrario.
 */
bool BusquedaBinaria::isBalanced(Node* node) {
    if (node == nullptr) return true;

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    return abs(leftHeight - rightHeight) <= 1 && isBalanced(node->left) && isBalanced(node->right);
}
