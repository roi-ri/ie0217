#include "Bts.hpp"

// COnstructor de la clase Bts
BinarySearchTree::BinarySearchTree() : root(nullptr) {}



// Agrega un nuevo valor a un árbol, si el valor de raiz está es el nullprt se le asigna ese valor
// En caso de que ya se tenga un valor en la raiz, se verifica, si el valor es menor se asigna a la izquierda y si es mayor se asigna a la derecha. 
// esto ocurre con el elemento node->left y node->right.
TreeNode* BinarySearchTree::insert(TreeNode* node, int value){

    if (node == nullptr){
        return new TreeNode(value);
    }
    if (value < node->value){
        node->left = insert(node->left, value);

    } else if (value > node->value){
        node->right = insert(node->right, value);
    }
    return node; 
}

TreeNode* BinarySearchTree::findLCA(TreeNode* node, int v1, int v2) {
    if (node == nullptr) {
        return nullptr;
    }

    // Si ambos valores están a la izquierda
    if (v1 < node->value && v2 < node->value) {
        //Utiliza recursividad para navegar sobre el arbol para poder encontrar el LCA de v1 y v2
        // Se mantiene sobre el nodo izquierdo pq los valores v1 y v2 son menores que el del nodo.
        return findLCA(node->left, v1, v2); // devuelve el nodo izquierdo como LCA
    }

    // Si ambos valores están a la derecha
    if (v1 > node->value && v2 > node->value) {
        //Utiliza recursividad para navegar sobre el arbol para poder encontrar el LCA de v1 y v2
        // Se mantiene sobre el nodo derecho pq los valores v1 y v2 son mayores que el del nodo.
        return findLCA(node->right, v1, v2); // Devuelve el nodo derecho del LCA
    } 

    // Si están en ramas diferentes o uno de ellos es el nodo actual
    // Esto pq, se sabe que el LCA común va a ser en el momento en que un valor esté a la derecha y el otro a la izquierda, pq después de ese punto se pierde conexión entre si que no sea dicho nodo.
    return node;
}


// FUncion que lo que hace es que imprime el binary tree en orden transversal 
void BinarySearchTree::inOrderTransversal(TreeNode* node) {
    if (node == nullptr) return; // Si el valor del nodo es nullptr hace un return
    inOrderTransversal(node->left);
    cout << node->value << " ";
    inOrderTransversal(node->right);
}



bool BinarySearchTree::search(TreeNode* node, int value) {
    if (node == nullptr) return false; // Si el valor del nodo es nullptr hace un return false
    if (node->value == value) return true; //Si el valor del nodo es value retorna True
    if (value < node->value) return search(node->left, value); // SI el valor es menor al nodo va y busca al lado izquierdo
    return search(node->right, value); // Si el valor es mayor al del nodo va y busca a la derecha
}

int BinarySearchTree::findLowestCommonAncestor(int v1, int v2){
    // Se va y se hace la búsqueda de los valores para verificar que se encuentren en el árbol
    if (!search(root, v1) || !search (root, v2)){
        throw invalid_argument("Ambos Valores no existen en el árbol"); // SI el valor no se encuentra, se retorna un mensaje de error
    }
    TreeNode* lca = findLCA(root, v1, v2);
    if (lca == nullptr){
        throw runtime_error(" No se encontró el ancestro común.");
    }
    return lca -> value;
}

// IMprime wn orden el arbol llamando a la funcion de InOrderTransversal dandole de argumento el root.
void BinarySearchTree::printInOrder(){
    inOrderTransversal(root);
    cout<< endl; 
}

void BinarySearchTree::insert(int value) {
    //Funcino para agregar un valor al arbol
    // Se pasa como argumento el valor y dentro de search se hace la busqueda para ver hacia donde va ese valor (izquierda o derecha).
    root = insert(root, value);
}
