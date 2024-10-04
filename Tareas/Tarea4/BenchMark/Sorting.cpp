/**
 * @file Sorting.cpp
 * @brief Implementación de varios algoritmos de ordenamiento y generación de vectores aleatorios.
 */

#include "Sorting.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>

/**
 * @brief Función para generar un vector con números aleatorios.
 * 
 * Genera un vector de tamaño especificado con números enteros aleatorios entre 0 y 100000.
 * 
 * @param size Tamaño del vector a generar.
 * @return std::vector<int> Vector de enteros aleatorios.
 */
std::vector<int> generate_random_vector(size_t size) {
    std::vector<int> data(size);
    std::srand(static_cast<unsigned int>(std::time(nullptr))); /**< Inicializa la semilla para generar números aleatorios */
    for (size_t i = 0; i < size; ++i) {
        data[i] = std::rand() % 100000; /**< Genera un número aleatorio entre 0 y 100000 */
    }
    return data;
}

/**
 * @brief Implementación del algoritmo Bubble Sort.
 * 
 * Ordena un vector de enteros en orden ascendente utilizando el algoritmo Bubble Sort.
 * 
 * @param data Vector de enteros a ordenar.
 */
void bubble_sort(std::vector<int>& data) {
    size_t n = data.size();
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]); /**< Intercambia los elementos si están en el orden incorrecto */
            }
        }
    }
}

/**
 * @brief Implementación del algoritmo Selection Sort.
 * 
 * Ordena un vector de enteros en orden ascendente utilizando el algoritmo Selection Sort.
 * 
 * @param data Vector de enteros a ordenar.
 */
void selection_sort(std::vector<int>& data) {
    size_t n = data.size();
    for (size_t i = 0; i < n - 1; ++i) {
        size_t min_idx = i; /**< Índice del elemento mínimo */
        for (size_t j = i + 1; j < n; ++j) {
            if (data[j] < data[min_idx]) {
                min_idx = j; /**< Actualiza el índice del elemento mínimo */
            }
        }
        std::swap(data[i], data[min_idx]); /**< Intercambia el elemento actual con el mínimo */
    }
}

/**
 * @brief Implementación del algoritmo Insertion Sort.
 * 
 * Ordena un vector de enteros en orden ascendente utilizando el algoritmo Insertion Sort.
 * 
 * @param data Vector de enteros a ordenar.
 */
void insertion_sort(std::vector<int>& data) {
    size_t n = data.size();
    for (size_t i = 1; i < n; ++i) {
        int key = data[i]; /**< Elemento actual a insertar en su lugar correcto */
        size_t j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j]; /**< Desplaza los elementos mayores al lugar siguiente */
            if (j == 0) break; /**< Evita el acceso a índices negativos */
            j--;
        }
        data[j + 1] = key; /**< Inserta el elemento en su lugar correcto */
    }
}

/**
 * @brief Implementación del algoritmo Quick Sort.
 * 
 * Ordena un vector de enteros en orden ascendente utilizando el algoritmo Quick Sort.
 * 
 * @param data Vector de enteros a ordenar.
 * @param low Índice inicial del subarreglo.
 * @param high Índice final del subarreglo.
 */
void quick_sort(std::vector<int>& data, int low, int high) {
    if (low < high) {
        int pivot = data[high]; /**< Selecciona el último elemento como pivote */
        int i = low - 1; /**< Índice del elemento más pequeño */

        // Particionar el arreglo
        for (int j = low; j < high; j++) {
            if (data[j] < pivot) {
                i++;
                std::swap(data[i], data[j]); /**< Intercambia los elementos si son menores que el pivote */
            }
        }
        std::swap(data[i + 1], data[high]); /**< Coloca el pivote en su posición correcta */
        int partition_index = i + 1;

        // Llamadas recursivas a Quick Sort para las dos particiones
        quick_sort(data, low, partition_index - 1);
        quick_sort(data, partition_index + 1, high);
    }
}
