#include "BusquedaArbolBinario.hpp"
#include <iostream>
using namespace std; 

/**
 * @brief Función principal del programa de gestión de un árbol binario de búsqueda.
 *
 * Este programa permite al usuario gestionar un árbol binario de búsqueda. 
 * Ofrece un menú de opciones para insertar, eliminar nodos, imprimir el árbol,
 * calcular la altura del árbol y verificar si el árbol está balanceado.
 *
 * @return Código de estado de salida del programa.
 */
int main() {
    BusquedaBinaria tree; /**< Instancia del árbol binario de búsqueda. */



    int option, valor; /**< Opción seleccionada por el usuario y Valor para insertar o eliminar en el árbol. */

    do {
        cout << "Menú:\n";
        cout << "1. Insertar un nodo\n";
        cout << "2. Eliminar un nodo\n";
        cout << "3. Imprimir el árbol\n";
        cout << "4. Calcular la altura del árbol\n";
        cout << "5. Verificar si el árbol está balanceado\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "Ingrese un valor para insertar: ";
            cin >> valor;
            tree.insert(valor);
            break;
        case 2:
            cout << "Ingrese un valor para eliminar: ";
            cin >> valor;
            tree.remove(valor);
            break;
        case 3:
            cout << "Árbol en orden: ";
            tree.printInOrder();
            break;
        case 4:
            cout << "Altura del árbol: " << tree.height() << endl;
            break;
        case 5:
            if (tree.isBalanced()) {
                cout << "El árbol está balanceado.\n";
            } else {
                cout << "El árbol no está balanceado.\n";
            }
            break;
        case 6:
            cout << "Saliendo del programa...\n";
            break;
        }
    } while (option != 6);

    return 0;
}
