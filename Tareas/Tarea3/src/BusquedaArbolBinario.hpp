#ifndef BUSQUEDAARBOLBINARIO_HPP
#define BUSQUEDAARBOLBINARIO_HPP
#include "Node.hpp"

class BusquedaBinaria {
public: 
    BusquedaBinaria();
    void insert(int value);
    void remove(int value);
    void printInOrder(); 
    int height();
    bool isBalanced();

private: 
    Node* root; 
    Node* insert(Node* node, int value);
    Node* remove(Node* node, int value); 
    Node* findMin(Node* node);
    void printInorder(Node* node); 
    int height(Node* node);
    bool isBalanced(Node* node); 
};

#endif //BUSQUEDAARBOLBINARIO_HPP
