#include <iostream>
using namespace std;

int main() {
    int* arr = new int[5];  // Asigna un arreglo de 5 enteros

    // Inicializa el arreglo
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }

    cout << "Valor dentro de limites: " << arr[4] << endl;

    delete[] arr;  // Libera la memoria asignada
    return 0;
}