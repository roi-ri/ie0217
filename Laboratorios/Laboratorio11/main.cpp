#include "Bts.hpp"
// Función principal
int main() {
    BinarySearchTree bst;

    // Insertar nodos en el árbol
  	// Agregar más valores acá
    bst.insert(20);
    bst.insert(10);
    bst.insert(30);
    bst.insert(5);
    bst.insert(15);
    bst.insert(12);
    bst.insert(18);

    // Imprimir el árbol
    cout << "Árbol en orden: ";
    bst.printInOrder();

    // Encontrar ancestro común más cercano
    try {
        int v1 = 12, v2 = 18;
        cout << "El ancestro común más cercano de " << v1 << " y " << v2 << " es: "
             << bst.findLowestCommonAncestor(v1, v2) << endl;

        v1 = 5; v2 = 30;
        cout << "El ancestro común más cercano de " << v1 << " y " << v2 << " es: "
             << bst.findLowestCommonAncestor(v1, v2) << endl;
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}