#include"Sorting.hpp"



//dejar este aqui
// Función para medir tiempo de ejecución de un algoritmo de ordenamiento
template <typename Func>
long long measure_sort_time(Func sort_function, vector<int>& data) {
    auto start = chrono::high_resolution_clock::now();
    sort_function(data);
    auto end = chrono::high_resolution_clock::now();
    return chrono::duration_cast<chrono::milliseconds>(end - start).count();
}

int main() {
    // Definir tamaños de prueba 
    vector<size_t> sizes = {5000, 10000, 20000, 30000, 40000, 50000};

    // Comparación de tiempos de varios algoritmos de ordenamiento
    for (auto size : sizes) {
        // Generar un vector aleatorio para cada tamaño
        vector<int> data = generate_random_vector(size);

        // Medir tiempo de Bubble Sort
        vector<int> bubble_data = data; // Crear una copia del vector para no afectar otras pruebas
        long long bubble_time = measure_sort_time(bubble_sort, bubble_data); // Medir tiempo
        cout << "Bubble Sort - Tamaño: " << size << " - Tiempo: " << bubble_time << " ms\n";

        // Medir tiempo de Selection Sort
        vector<int> selection_data = data; // Crear una copia del vector
        long long selection_time = measure_sort_time(selection_sort, selection_data); // Medir tiempo
        cout << "Selection Sort - Tamaño: " << size << " - Tiempo: " << selection_time << " ms\n";

        // Medir tiempo de Insertion Sort
        vector<int> insertion_data = data; // Crear una copia del vector
        long long insertion_time = measure_sort_time(insertion_sort, insertion_data); // Medir tiempo
        cout << "Insertion Sort - Tamaño: " << size << " - Tiempo: " << insertion_time << " ms\n";

        // Medir tiempo de STL Sort (sort)
        vector<int> stl_data = data; // Crear una copia del vector
        long long stl_time = measure_sort_time([](vector<int>& arr) { sort(arr.begin(), arr.end()); }, stl_data); // Medir tiempo
        cout << "STL Sort - Tamaño: " << size << " - Tiempo: " << stl_time << " ms\n";

        // Separador entre pruebas
        cout << "---------------------------------------------\n";
    }

    return 0;
}