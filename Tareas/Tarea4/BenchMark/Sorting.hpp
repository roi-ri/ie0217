/**
 * @file Sorting.hpp
 * @brief Declaración de funciones para algoritmos de ordenamiento y generación de vectores aleatorios.
 */

#ifndef SORTING_HPP
#define SORTING_HPP

#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>

/**
 * @brief Función que implementa el algoritmo Bubble Sort.
 * 
 * Ordena un vector de enteros en orden ascendente utilizando el algoritmo Bubble Sort.
 * 
 * @param data Vector de enteros a ordenar.
 */
void bubble_sort(std::vector<int>& data);

/**
 * @brief Función que implementa el algoritmo Selection Sort.
 * 
 * Ordena un vector de enteros en orden ascendente utilizando el algoritmo Selection Sort.
 * 
 * @param data Vector de enteros a ordenar.
 */
void selection_sort(std::vector<int>& data);

/**
 * @brief Función que implementa el algoritmo Insertion Sort.
 * 
 * Ordena un vector de enteros en orden ascendente utilizando el algoritmo Insertion Sort.
 * 
 * @param data Vector de enteros a ordenar.
 */
void insertion_sort(std::vector<int>& data);

/**
 * @brief Función que implementa el algoritmo Quick Sort.
 * 
 * Ordena un vector de enteros en orden ascendente utilizando el algoritmo Quick Sort.
 * 
 * @param data Vector de enteros a ordenar.
 * @param low Índice inicial del subarreglo a ordenar.
 * @param high Índice final del subarreglo a ordenar.
 */
void quick_sort(std::vector<int>& data, int low, int high);

/**
 * @brief Función para generar un vector con números aleatorios.
 * 
 * Genera un vector de tamaño especificado con números enteros aleatorios entre 0 y 100000.
 * 
 * @param size Tamaño del vector a generar.
 * @return std::vector<int> Vector de enteros aleatorios.
 */
std::vector<int> generate_random_vector(size_t size);

#endif // SORTING_HPP
