#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>
#include <barrier>

// Mutex para proteger la salida en la terminal
// solo un hilo a la vez pueda imprimir en la consula.
// los mensajes no se van a mezclar.
std::mutex console_mutex;



// Barrera para sincronizar las tareas
// Lo que permite es sincronizar tres tareas. 
// Cada tarea se detiene hasta que todas las demas hayan llegado. 
// Solo cuando todas llegan, continua. 
std::barrier sync_point(3);


// Función que simula una tarea del sistema
//Recibe como parametro el id de la tarea para distinguir entre los hilos
void perform_task(int id) {
    {
        // Bloqueo para asegurar que la salida no se mezcle
        // Para bloquear el mutex y que solo un hilo imprima en la consola a la vez
        std::lock_guard<std::mutex> lock(console_mutex);
        // Muestra un mensaje indicando que la tarea está comenzando a trabajar. 
        std::cout << "Tarea " << id << " está realizando trabajo inicial...\n";
    }

    // Simula trabajo con un retardo
    // establece x milisegundos para simular que se está trabjando en dicha tarea por ese x tiempo. 
    std::this_thread::sleep_for(std::chrono::milliseconds(100 * id));

    {
        // Bloqueo para asegurar que la salida no se mezcle
        // Para bloquear el mutex y que solo un hilo imprima en la consola a la vez
        std::lock_guard<std::mutex> lock(console_mutex);
        std::cout << "Tarea " << id << " alcanzó el punto de sincronización.\n";
    }

    // Sincronización en la barrera
    // Las tareas se sincronizan. 
    // Dice que si la tarea llegó al punto de barrera y espera a que las demás la alcancen. 
    // Cuando las otras lleguen, esta continua. 
    sync_point.arrive_and_wait();

    {
        // Bloqueo para asegurar que la salida no se mezcle
        // Cuando las tareas pasan la barrera, continúa con el "trabajo final"
        std::lock_guard<std::mutex> lock(console_mutex);
        std::cout << "Tarea " << id << " continúa con el trabajo final.\n";
    }

    // Simula trabajo adicional con un retardo
    // Simula trabajo adicioal por otro y tiempo. 
    std::this_thread::sleep_for(std::chrono::milliseconds(50 * id));

    {
        // Bloqueo para asegurar que la salida no se mezcle
        std::lock_guard<std::mutex> lock(console_mutex);
        // Imprime que la tarea ya termino ggs. 
        std::cout << "Tarea " << id << " ha completado el trabajo.\n";
    }
}

int main() {
    // Establece el numero de tareas a 3 -> tamaño de barrera. 
    const int NUM_TASKS = 3; // Número de tareas a ejecutar

    // Crea y lanza los hilos para ejecutar las tareas
    // Se hace uno para cada tarea. 
    // Los hilos ejecutan la funcion "perform_task" y recibe un id (1, 2 o 3). 
    std::vector<std::thread> threads;
    for (int i = 1; i <= NUM_TASKS; ++i) {
        threads.push_back(std::thread(perform_task, i));
    }

    // Espera a que todas las tareas terminen
    // se utiliza para esperar a que cada hilo termie su ejecución antes de continuar. 
    // El programa no termina hasta que todos los hilos termiaran su tarea. 
    for (auto& th : threads) { // Se accede a cada hilo por referencia
        th.join(); 
    }
    // ggs terminamos el pograma 
    std::cout << "Todas las tareas han completado su ejecución.\n";
    // Salir 
    return 0;
}

