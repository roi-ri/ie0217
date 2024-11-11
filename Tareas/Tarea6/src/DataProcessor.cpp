/**
 * @file main.cpp
 * @brief Clase para procesar datos con soporte para concurrencia y manejo seguro de memoria.
 * 
 * Este programa solicita al usuario el tamaño de los datos, los llena automáticamente, 
 * los procesa de forma concurrente y calcula estadísticas básicas como suma y promedio.
 */

#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

/**
 * @class DataProcessor
 * @brief Clase que maneja el procesamiento de datos con concurrencia.
 * 
 * La clase permite el manejo de un arreglo de datos, llenado, procesamiento concurrente
 * y cálculo de estadísticas básicas.
 */
class DataProcessor {
public:
    /**
     * @brief Constructor de la clase DataProcessor.
     * 
     * Inicializa el objeto con un tamaño especificado. Si el tamaño es inválido
     * o la asignación de memoria falla, se reporta un error.
     * 
     * @param size Tamaño del arreglo de datos.
     */
    DataProcessor(int size) : size(size) {
        if (size <= 0) {
            std::cout << "Error: tamano invalido\n";
            return;
        }
        try {
            data.resize(size);
        } catch (const std::bad_alloc& e) {
            std::cout << "Error: fallo de memoria\n";
        }
    }

    /**
     * @brief Llena el arreglo de datos con múltiplos de 10.
     */
    void populateData() {
        for (int i = 0; i < size; ++i) {
            data[i] = i * 10;
        }
    }

    /**
     * @brief Calcula la suma de todos los elementos del arreglo.
     * 
     * @return La suma de los elementos.
     */
    int calculateSum() {
        int sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += data[i];
        }
        return sum;
    }

    /**
     * @brief Calcula el promedio de los elementos del arreglo.
     * 
     * Previene la división por cero si el tamaño del arreglo es 0.
     * 
     * @return El promedio de los elementos o 0 si el tamaño es 0.
     */
    double calculateAverage() {
        if (size == 0) {
            std::cout << "Error: division por cero.";
            return 0;
        }
        return static_cast<double>(calculateSum()) / size;
    }

    /**
     * @brief Procesa los datos de forma concurrente utilizando dos hilos.
     * 
     * Cada hilo procesa una parte del arreglo.
     */
    void concurrentProcess() {
        std::thread t1(&DataProcessor::processDataPart, this, 0, size / 2);
        std::thread t2(&DataProcessor::processDataPart, this, size / 2, size);

        t1.join();
        t2.join();
    }

    /**
     * @brief Imprime los datos procesados en la consola.
     */
    void printData() {
        for (int i = 0; i < size; ++i) {
            std::cout << "Data[" << i << "] = " << data[i] << std::endl;
        }
    }

private:
    std::vector<int> data; ///< Arreglo de datos manejado automáticamente por std::vector.
    int size;              ///< Tamaño del arreglo.
    std::mutex mtx;        ///< Mutex para proteger el acceso concurrente a los datos.

    /**
     * @brief Procesa una parte del arreglo de datos.
     * 
     * Multiplica cada elemento en el rango [start, end) por 2.
     * 
     * @param start Índice de inicio del rango a procesar.
     * @param end Índice de fin del rango a procesar (exclusivo).
     */
    void processDataPart(int start, int end) {
        for (int i = start; i < end; ++i) {
            std::lock_guard<std::mutex> lock(mtx);
            data[i] *= 2;
        }
    }
};

/**
 * @brief Función principal.
 * 
 * Solicita al usuario el tamaño del arreglo, inicializa el objeto DataProcessor,
 * llena los datos, los procesa de forma concurrente y calcula el promedio.
 * 
 * @return int Código de salida del programa.
 */
int main() {
    int size;
    std::cout << "Enter size of data: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Error: size must be greater than 0\n";
        return 1;
    }

    DataProcessor* processor = new DataProcessor(size);

    processor->populateData();
    processor->concurrentProcess();
    std::cout << "Average: " << processor->calculateAverage() << std::endl;

    delete processor;
    return 0;
}
