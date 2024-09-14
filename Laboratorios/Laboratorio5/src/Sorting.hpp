#ifndef SORTING_HPP
#define SORTING_HPP
#include<iostream> 
#include<vector> 

using namespace std; 

// Declarando los algoritmos de ordenamiento
void bubble_sort(vector<int> & arr);
void selection_sort(vector<int>& arr);
void insertion_sort(vector<int>& arr);

// Declaracion de la funcion para generar un vector de numeros aleatorios
vector<int> generate_random_vector(size_t size); 







#endif //SORTING_HPP
