#include "Sorting.hpp"
#include <algorithm>
#include <chrono> 
#include <random>
#include <vector>
//Este algoritmo compara pares adyacentes y los intercambia si estan en el orden incorrecto.
// Se repite el proceso hasta que no haya mas intercambio
void bubble_sort(vector<int>& arr){
    bool swapped;
    for (size_t i = 0; i < arr.size() - 1; i++) {
        swapped = false;
        for (size_t j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Si no se realizaron intercambios en la pasada, el arreglo ya está ordenado
        if (!swapped)
            break;
    }
}

//Este algoritmo encuentra el elemento mas pequeño en el arreglo desordenado y lo coloca en su posicion correctas
//repite el proceso para casa posicion en el arreglo

void selection_sort(vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; i++) {
        size_t min_index = i;
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Intercambia el elemento más pequeño encontrado con el primer elemento desordenado
        swap(arr[i], arr[min_index]);
    }
}


// Este algoritmo construye un arreglo ordenado de manera iterativa, tomando un elemento a la vez
// y colocándolo en su posición correcta en la parte ya ordenada del arreglo.
void insertion_sort(vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        int key = arr[i]; // Elemento a insertar en la parte ordenada
        int j = i - 1;

        // Desplaza elementos mayores que 'key' hacia la derecha
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        // Coloca 'key' en su posición correcta
        arr[j + 1] = key;
    }
}
// Genera un vector con números aleatorios en el rango de 1 a 10,000.
vector<int> generate_random_vector(size_t size) {
    vector<int> vec(size);
    random_device rd;
    mt19937 gen(rd()); // Generador de números aleatorios
    uniform_int_distribution<> dist(1, 10000); // Distribución uniforme entre 1 y 10,000

    // Llena el vector con números aleatorios
    for (size_t i = 0; i < size; ++i) {
        vec[i] = dist(gen);
    }
    return vec;
}