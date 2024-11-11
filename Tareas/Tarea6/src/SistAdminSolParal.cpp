#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>
#include <random>
#include <semaphore> // C++20
#include <atomic>

const int BUFFER_SIZE = 10; // Tamaño del búfer compartido
const int NUM_CLIENTS = 50;  // Número de clientes
const int NUM_OPERATORS = 3; // Número de operadores
const int NUM_REQUESTS = 100; // Número total de solicitudes que se generarán

std::queue<int> buffer;           // Búfer compartido
std::mutex mtx;                   // Mutex para proteger el acceso al búfer
std::counting_semaphore<BUFFER_SIZE> empty_slots(BUFFER_SIZE); // Semáforo para espacios vacíos en el búfer
std::counting_semaphore<0> full_slots(0);                     // Semáforo para espacios llenos en el búfer

std::atomic<int> request_count(0);   // Contador de solicitudes generadas
std::atomic<bool> finished(false);   // Bandera para indicar si la generación de solicitudes ha terminado
std::atomic<long long> total_client_wait_time(0); // Tiempo de espera acumulado por clientes
std::atomic<long long> total_operator_wait_time(0); // Tiempo de espera acumulado por operadores

// Función del cliente (Productor)
void client(int id) {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> sleep_dist(50, 200); // Tiempos aleatorios para simular pausas

    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(sleep_dist(rng))); // Simula tiempo entre solicitudes

        // Mide el tiempo de espera
        auto wait_start = std::chrono::high_resolution_clock::now();
        empty_slots.acquire(); // Espera a que haya un espacio disponible en el búfer
        auto wait_end = std::chrono::high_resolution_clock::now();
        total_client_wait_time += std::chrono::duration_cast<std::chrono::milliseconds>(wait_end - wait_start).count();

        // Protege el acceso al búfer con lock_guard
        {
            std::lock_guard<std::mutex> lock(mtx);
            if (request_count >= NUM_REQUESTS) {
                finished = true;
                full_slots.release(); // Asegura que los operadores puedan salir si está terminado
                break;
            }

            // Genera y agrega una solicitud al búfer
            int request = request_count++;
            buffer.push(request);
            std::cout << "Cliente " << id << " generó solicitud: " << request << std::endl;
        }

        // Notifica a los operadores que hay una solicitud lista
        full_slots.release();
    }
}

// Función del operador (Consumidor)
void operator_worker(int id) {
    while (true) {
        // Mide el tiempo de espera
        auto wait_start = std::chrono::high_resolution_clock::now();
        full_slots.acquire(); // Espera a que haya una solicitud disponible
        auto wait_end = std::chrono::high_resolution_clock::now();
        total_operator_wait_time += std::chrono::duration_cast<std::chrono::milliseconds>(wait_end - wait_start).count();

        // Protege el acceso al búfer con lock_guard
        {
            std::lock_guard<std::mutex> lock(mtx);
            if (buffer.empty() && finished) {
                break; // Sale si no hay más solicitudes y la generación ha terminado
            }

            if (!buffer.empty()) { // Confirma que el búfer no está vacío antes de acceder
                // Procesa una solicitud del búfer
                int request = buffer.front();
                buffer.pop();
                std::cout << "Operador " << id << " procesó solicitud: " << request << std::endl;
            }
        }

        // Notifica a un cliente que hay un espacio libre
        empty_slots.release();

        // Simula tiempo de procesamiento de la solicitud
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

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
