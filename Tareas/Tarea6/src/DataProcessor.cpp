#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

class DataProcessor {
public:
    // Constructor con manejo de excepciones para una posible asignación de memoria fallida
    DataProcessor(int size) : size(size) {
        if (size <= 0) {
            std::cout << "Error: tamano invalido\n"; // Asegura que el tamaño sea positivo
            return; // No se procede si el tamaño es inválido
        }
        try {
            data.resize(size);  // Usamos vector para manejar la memoria automáticamente
        } catch (const std::bad_alloc& e) {
            std::cout << "Error: fallo de memoria\n"; // Captura de error si la asignación de memoria falla
        }
    }

    // Método para llenar el arreglo con datos
    void populateData() {
        for (int i = 0; i < size; ++i) {
            data[i] = i * 10; // Llenado con múltiplos de 10
        }
    }

    // Método para calcular la suma de los datos
    int calculateSum() {
        int sum = 0;
        for (int i = 0; i < size; ++i) {
            sum += data[i]; // Suma de todos los elementos
        }
        return sum;
    }

    // Método para calcular el promedio
    double calculateAverage() {
        if (size == 0) {
            std::cout << "Error: division por cero."; // Prevención de división por cero
            return 0;
        } else {
            return static_cast<double>(calculateSum()) / size; // Promedio
        }
    }

    // Método que maneja la ejecución concurrente utilizando hilos
    void concurrentProcess() {
        std::thread t1(&DataProcessor::processDataPart, this, 0, size / 2); // Primer hilo trabaja en la mitad
        std::thread t2(&DataProcessor::processDataPart, this, size / 2, size); // Segundo hilo trabaja en la otra mitad

        t1.join(); // Espera a que termine el hilo 1
        t2.join(); // Espera a que termine el hilo 2
    }

    // Método para imprimir los datos procesados
    void printData() {
        for (int i = 0; i < size; ++i) {
            std::cout << "Data[" << i << "] = " << data[i] << std::endl; // Imprime cada dato
        }
    }

private:
    std::vector<int> data; // Usamos un vector para manejar la memoria automáticamente
    int size;
    std::mutex mtx; // Mutex para protección

    // Método que procesa una parte de los datos (sin necesidad de mutex, ya que no hay acceso concurrente)
    void processDataPart(int start, int end) {
        for (int i = start; i < end; ++i) {
            data[i] *= 2; // Multiplica cada valor por 2
        }
    }
};

int main() {
    int size;
    std::cout << "Enter size of data: ";
    std::cin >> size;

    // Validación de entrada
    if (size <= 0) {
        std::cout << "Error: size must be greater than 0\n"; // Valida que el tamaño sea mayor que 0
        return 1; // Termina el programa si el tamaño es inválido
    }

    DataProcessor* processor = new DataProcessor(size); // Crea el objeto de procesamiento de datos

    processor->populateData(); // Llena los datos
    processor->concurrentProcess(); // Procesa los datos en paralelo
    std::cout << "Average: " << processor->calculateAverage() << std::endl; // Calcula y muestra el promedio

    delete processor; // Elimina el objeto creado
    return 0;
}
