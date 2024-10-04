/**
 * @file Proyecto.cpp
 * @brief Implementación de la clase Proyecto.
 * 
 * Esta clase representa un proyecto que puede contener múltiples tareas. 
 * Permite agregar, eliminar y ordenar tareas, así como mostrar un resumen del proyecto.
 */

#include "Proyecto.hpp"
#include <iostream>
#include <stdexcept>

/**
 * @brief Constructor de la clase Proyecto.
 * 
 * Inicializa un proyecto con el nombre proporcionado.
 * 
 * @param nombre Nombre del proyecto.
 */
Proyecto::Proyecto(const std::string& nombre) : nombre(nombre) {}

/**
 * @brief Agrega una tarea al proyecto.
 * 
 * Añade una tarea al vector de tareas del proyecto.
 * 
 * @param tarea La tarea a agregar.
 */
void Proyecto::agregarTarea(const Tarea<int>& tarea) {
    tareas.push_back(tarea);
}

/**
 * @brief Elimina una tarea del proyecto.
 * 
 * Busca y elimina la tarea con el nombre proporcionado. Lanza una excepción si la tarea no se encuentra.
 * 
 * @param nombreTarea Nombre de la tarea a eliminar.
 * @throws std::runtime_error Si la tarea no se encuentra en el proyecto.
 */
void Proyecto::eliminarTarea(const std::string& nombreTarea) {
    auto it = std::remove_if(tareas.begin(), tareas.end(),
        [&](const Tarea<int>& tarea) { return tarea.getNombre() == nombreTarea; });
    if (it != tareas.end()) {
        tareas.erase(it, tareas.end());
    } else {
        throw std::runtime_error("Tarea no encontrada");
    }
}

/**
 * @brief Ordena las tareas del proyecto por costo.
 * 
 * Ordena las tareas en el vector según el costo de cada una en orden ascendente.
 */
void Proyecto::ordenarTareasPorCosto() {
    std::sort(tareas.begin(), tareas.end(),
        [](const Tarea<int>& a, const Tarea<int>& b) { return a.getCosto() < b.getCosto(); });
}

/**
 * @brief Ordena las tareas del proyecto por tiempo estimado.
 * 
 * Ordena las tareas en el vector según el tiempo estimado en orden descendente.
 */
void Proyecto::ordenarTareasPorTiempo() {
    std::sort(tareas.begin(), tareas.end(),
        [](const Tarea<int>& a, const Tarea<int>& b) { return a.getTiempoEstimado() > b.getTiempoEstimado(); });
}

/**
 * @brief Ordena las tareas del proyecto por prioridad.
 * 
 * Ordena las tareas en el vector según la prioridad en orden ascendente (1: Alta, 2: Media, 3: Baja).
 */
void Proyecto::ordenarTareasPorPrioridad() {
    std::sort(tareas.begin(), tareas.end(),
        [](const Tarea<int>& a, const Tarea<int>& b) { return a.getPrioridad() < b.getPrioridad(); });
}

/**
 * @brief Muestra un resumen del proyecto.
 * 
 * Imprime en la consola el nombre del proyecto, el total de tareas, el costo total y el tiempo estimado total.
 */
void Proyecto::mostrarResumen() const {
    double costoTotal = 0, tiempoTotal = 0;
    for (const auto& tarea : tareas) {
        costoTotal += tarea.getCosto();
        tiempoTotal += tarea.getTiempoEstimado();
    }
    std::cout << "Proyecto: " << nombre << "\n"
              << "Total de Tareas: " << tareas.size() << "\n"
              << "Costo Total: " << costoTotal << "\n"
              << "Tiempo Total Estimado: " << tiempoTotal << " días\n";
}
