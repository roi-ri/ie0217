/**
 * @file main.cpp
 * @brief Implementación de un sistema de productores y consumidores utilizando múltiples hilos en C++.
 * 
 * Este programa simula un sistema en el que varios clientes (productores) generan solicitudes que son 
 * procesadas por operadores (consumidores). Se utilizan semáforos y mutex para manejar el acceso a 
 * un búfer compartido y garantizar sincronización entre los hilos.
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>
#include <random>
#include <semaphore> // C++20
#include <atomic>

// Constantes globales
const int BUFFER_SIZE = 1;          ///< Tamaño del búfer compartido.
const int NUM_CLIENTS = 10;         ///< Número de hilos de clientes.
const int NUM_OPERATORS = 10;       ///< Número de hilos de operadores.
const int NUM_REQUESTS = 1000;      ///< Número total de solicitudes a generar.

// Variables compartidas
std::queue<int> buffer;             ///< Búfer compartido entre clientes y operadores.
std::mutex mtx;                     ///< Mutex para proteger el acceso al búfer.
std::counting_semaphore<BUFFER_SIZE> empty_slots(BUFFER_SIZE); ///< Semáforo para espacios vacíos en el búfer.
std::counting_semaphore<0> full_slots(0);                     ///< Semáforo para espacios llenos en el búfer.
std::atomic<int> request_count(0);  ///< Contador de solicitudes generadas.
std::atomic<bool> finished(false); ///< Bandera para indicar si se han generado todas las solicitudes.
std::atomic<long long> total_client_wait_time(0); ///< Tiempo de espera acumulado por los clientes.
std::atomic<long long> total_operator_wait_time(0); ///< Tiempo de espera acumulado por los operadores.

/**
 * @brief Función que simula el comportamiento de un cliente (productor).
 * 
 * Cada cliente genera solicitudes de manera aleatoria y las añade al búfer compartido.
 * 
 * @param id Identificador único del cliente.
 */
void client(int id) {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> sleep_dist(50, 200); ///< Distribución aleatoria para tiempos de espera.

    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(sleep_dist(rng))); // Simula tiempo entre solicitudes

        auto wait_start = std::chrono::high_resolution_clock::now();
        empty_slots.acquire(); // Espera a que haya espacio disponible en el búfer
        auto wait_end = std::chrono::high_resolution_clock::now();
        total_client_wait_time += std::chrono::duration_cast<std::chrono::milliseconds>(wait_end - wait_start).count();

        {
            std::lock_guard<std::mutex> lock(mtx);
            if (request_count >= NUM_REQUESTS) {
                finished = true;
                full_slots.release(); // Permite que los operadores terminen
                break;
            }

            int request = request_count++;
            buffer.push(request);
            std::cout << "Cliente " << id << " generó solicitud: " << request << std::endl;
        }

        full_slots.release(); // Notifica a los operadores que hay una solicitud lista
    }
}

/**
 * @brief Función que simula el comportamiento de un operador (consumidor).
 * 
 * Cada operador procesa solicitudes del búfer compartido.
 * 
 * @param id Identificador único del operador.
 */
void operator_worker(int id) {
    while (true) {
        auto wait_start = std::chrono::high_resolution_clock::now();
        full_slots.acquire(); // Espera a que haya solicitudes disponibles
        auto wait_end = std::chrono::high_resolution_clock::now();
        total_operator_wait_time += std::chrono::duration_cast<std::chrono::milliseconds>(wait_end - wait_start).count();

        {
            std::lock_guard<std::mutex> lock(mtx);
            if (buffer.empty() && finished) {
                break; // Termina si no hay más solicitudes y ya se han generado todas
            }

            if (!buffer.empty()) {
                int request = buffer.front();
                buffer.pop();
                std::cout << "Operador " << id << " procesó solicitud: " << request << std::endl;
            }
        }

        empty_slots.release(); // Notifica a los clientes que hay espacio libre
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simula tiempo de procesamiento
    }
}

/**
 * @brief Función principal del programa.
 * 
 * Crea y gestiona los hilos de clientes y operadores, además de mostrar métricas al finalizar.
 * 
 * @return int Código de retorno.
 */
int main() {
    std::thread clients[NUM_CLIENTS];
    std::thread operators[NUM_OPERATORS];

    // Inicializa los hilos de clientes
    for (int i = 0; i < NUM_CLIENTS; ++i) {
        clients[i] = std::thread(client, i + 1);
    }

    // Inicializa los hilos de operadores
    for (int i = 0; i < NUM_OPERATORS; ++i) {
        operators[i] = std::thread(operator_worker, i + 1);
    }

    // Espera a que todos los clientes terminen
    for (int i = 0; i < NUM_CLIENTS; ++i) {
        clients[i].join();
    }

    // Espera a que todos los operadores terminen
    for (int i = 0; i < NUM_OPERATORS; ++i) {
        operators[i].join();
    }

    // Reporte de métricas de rendimiento
    std::cout << "Sistema finalizado. Total de solicitudes generadas: " << request_count << std::endl;
    std::cout << "Tiempo promedio de espera de clientes: " 
              << (total_client_wait_time / NUM_CLIENTS) << " ms" << std::endl;
    std::cout << "Tiempo promedio de espera de operadores: " 
              << (total_operator_wait_time / NUM_OPERATORS) << " ms" << std::endl;

    return 0;
}
