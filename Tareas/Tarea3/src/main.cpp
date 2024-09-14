#include "BusquedaArbolBinario.hpp"
#include <iostream>

int main() {
    BusquedaBinaria tree;



    int option, valor;

    do {
        std::cout << "Menú:\n";
        std::cout << "1. Insertar un nodo\n";
        std::cout << "2. Eliminar un nodo\n";
        std::cout << "3. Imprimir el árbol\n";
        std::cout << "4. Calcular la altura del árbol\n";
        std::cout << "5. Verificar si el árbol está balanceado\n";
        std::cout << "6. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> option;

        switch (option) {
        case 1:
            std::cout << "Ingrese un valor para insertar: ";
            std::cin >> valor;
            tree.insert(valor);
            break;
        case 2:
            std::cout << "Ingrese un valor para eliminar: ";
            std::cin >> valor;
            tree.remove(valor);
            break;
        case 3:
            std::cout << "Árbol en orden: ";
            tree.printInOrder();
            break;
        case 4:
            std::cout << "Altura del árbol: " << tree.height() << std::endl;
            break;
        case 5:
            if (tree.isBalanced()) {
                std::cout << "El árbol está balanceado.\n";
            } else {
                std::cout << "El árbol no está balanceado.\n";
            }
            break;
        case 6:
            std::cout << "Saliendo del programa...\n";
            break;
        }
    } while (option != 6);

    return 0;
}
