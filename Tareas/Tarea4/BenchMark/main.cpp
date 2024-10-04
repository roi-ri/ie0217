/**
 * @file main.cpp
 * @brief Programa para comparar el tiempo de ejecución de varios algoritmos de ordenamiento.
 *
 * Este programa genera vectores de tamaños predefinidos o especificados por el usuario
 * y mide el tiempo de ejecución de diferentes algoritmos de ordenamiento: Bubble Sort,
 * Selection Sort, Insertion Sort, Quick Sort, y el sort de la STL.
 */

#include "Sorting.hpp"
#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

/**
 * @brief Función para medir el tiempo de ejecución de un algoritmo de ordenamiento.
 * 
 * @tparam Func Tipo del algoritmo de ordenamiento (una función que ordene un vector).
 * @param sort_function Función de ordenamiento que se va a medir.
 * @param data Vector de enteros que se va a ordenar.
 * @return long long Tiempo de ejecución en milisegundos.
 */
template <typename Func>
long long measure_sort_time(Func sort_function, vector<int>& data) {
    auto start = chrono::high_resolution_clock::now(); /**< Marca el inicio del tiempo */
    sort_function(data); /**< Aplica la función de ordenamiento */
    auto end = chrono::high_resolution_clock::now(); /**< Marca el fin del tiempo */
    return chrono::duration_cast<chrono::milliseconds>(end - start).count(); /**< Devuelve el tiempo en milisegundos */
}

/**
 * @brief Función principal del programa.
 * 
 * Genera vectores de tamaños predefinidos o especificados por el usuario y mide
 * el tiempo de ejecución de varios algoritmos de ordenamiento.
 * 
 * @param argc Número de argumentos pasados por línea de comandos.
 * @param argv Arreglo de argumentos pasados por línea de comandos.
 * @return int Código de retorno del programa.
 */
int main(int argc, char* argv[]) {
    vector<size_t> sizes = {5000, 10000, 50000, 100000, 200000, 500000}; /**< Tamaños de vectores por defecto */

    // Si hay argumentos pasados por línea de comandos
    if (argc > 1) {
        sizes.clear();
        for (int i = 1; i < argc; ++i) {
            sizes.push_back(static_cast<size_t>(atoi(argv[i]))); /**< Convertir los argumentos a enteros */
        }
    }

    // Comparación de tiempos de varios algoritmos de ordenamiento
    for (auto size : sizes) {
        vector<int> data = generate_random_vector(size); /**< Generar un vector aleatorio */

        // Medir tiempo de Bubble Sort
        vector<int> bubble_data = data; /**< Copiar datos originales */
        long long bubble_time = measure_sort_time(bubble_sort, bubble_data); /**< Medir tiempo de ejecución */
        cout << "Bubble Sort - Tamaño: " << size << " - Tiempo: " << bubble_time << " ms\n";

        // Medir tiempo de Selection Sort
        vector<int> selection_data = data; /**< Copiar datos originales */
        long long selection_time = measure_sort_time(selection_sort, selection_data); /**< Medir tiempo de ejecución */
        cout << "Selection Sort - Tamaño: " << size << " - Tiempo: " << selection_time << " ms\n";

        // Medir tiempo de Insertion Sort
        vector<int> insertion_data = data; /**< Copiar datos originales */
        long long insertion_time = measure_sort_time(insertion_sort, insertion_data); /**< Medir tiempo de ejecución */
        cout << "Insertion Sort - Tamaño: " << size << " - Tiempo: " << insertion_time << " ms\n";

        // Medir tiempo de Quick Sort
        vector<int> quick_data = data; /**< Copiar datos originales */
        long long quick_time = measure_sort_time([](vector<int>& arr) { quick_sort(arr, 0, arr.size() - 1); }, quick_data);
        cout << "Quick Sort - Tamaño: " << size << " - Tiempo: " << quick_time << " ms\n";

        // Medir tiempo de STL Sort (sort)
        vector<int> stl_data = data; /**< Copiar datos originales */
        long long stl_time = measure_sort_time([](vector<int>& arr) { sort(arr.begin(), arr.end()); }, stl_data);
        cout << "STL Sort - Tamaño: " << size << " - Tiempo: " << stl_time << " ms\n";

        // Separador entre pruebas
        cout << "---------------------------------------------\n";
    }

    return 0;
}
