#include "BusquedaArbolBinario.hpp"
#include <iostream>
#include <algorithm>


using namespace std;

BusquedaBinaria::BusquedaBinaria() : root(nullptr) {}

void BusquedaBinaria::insert(int value) {
    root = insert(root, value);
}

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

void BusquedaBinaria::remove(int value) {
    root = remove(root, value);
}

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

Node* BusquedaBinaria::findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

void BusquedaBinaria::printInOrder() {
    printInorder(root);
    std::cout << std::endl;
}

void BusquedaBinaria::printInorder(Node* node) {
    if (node != nullptr) {
        printInorder(node->left);
        std::cout << node->data << " ";
        printInorder(node->right);
    }
}

int BusquedaBinaria::height() {
    return height(root);
}

int BusquedaBinaria::height(Node* node) {
    if (node == nullptr) return 0;
    return 1 + std::max(height(node->left), height(node->right));
}

bool BusquedaBinaria::isBalanced() {
    return isBalanced(root);
}

bool BusquedaBinaria::isBalanced(Node* node) {
    if (node == nullptr) return true;

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    return abs(leftHeight - rightHeight) <= 1 && isBalanced(node->left) && isBalanced(node->right);
}
