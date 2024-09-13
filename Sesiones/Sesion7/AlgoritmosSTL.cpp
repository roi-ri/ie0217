// Ejemplo de algoritmo de ordenación
#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>       // std::vector

// Función de comparación
bool myfunction (int i, int j) { 
    return (i < j); 
}

// Clase con un operador de comparación personalizado
struct myclass {
    bool operator() (int i, int j) { 
        return (i < j); 
    }
} myobject;

int main () {
    // Inicializando un array de enteros
    int myints[] = {32, 71, 12, 45, 26, 80, 53, 33};
    std::vector<int> myvector (myints, myints + 8);  // Crear vector con los elementos del array

    // Usando la comparación por defecto (operador <)
    std::sort(myvector.begin(), myvector.begin() + 4);   // Ordenar los primeros 4 elementos

    // Usando una función como criterio de comparación
    std::sort(myvector.begin() + 4, myvector.end(), myfunction);   // Ordenar el resto de los elementos

    // Usando un objeto como criterio de comparación
    std::sort(myvector.begin(), myvector.end(), myobject);   // Ordenar todo el vector

    // Mostrar el contenido del vector ordenado
    std::cout << "myvector contiene:";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    return 0;
}

