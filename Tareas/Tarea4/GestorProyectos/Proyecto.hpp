/**
 * @file Proyecto.hpp
 * @brief Declaración de la clase Proyecto.
 * 
 * La clase Proyecto permite gestionar un conjunto de tareas, proporcionando métodos
 * para agregar, eliminar y ordenar tareas, así como para mostrar un resumen del proyecto.
 */

#ifndef PROYECTO_HPP
#define PROYECTO_HPP

#include <vector>
#include <string>
#include <algorithm>
#include "Tarea.hpp"

/**
 * @class Proyecto
 * @brief Clase que representa un proyecto que contiene tareas.
 * 
 * Un proyecto tiene un nombre y un conjunto de tareas asociadas. 
 * Permite la gestión de las tareas, incluyendo su ordenamiento y resumen.
 */
class Proyecto {
private:
    std::string nombre; ///< Nombre del proyecto
    std::vector<Tarea<int>> tareas; ///< Vector que contiene las tareas del proyecto

public:
    /**
     * @brief Constructor por defecto.
     * 
     * Inicializa un proyecto vacío.
     */
    Proyecto() = default;

    /**
     * @brief Constructor que recibe el nombre del proyecto.
     * 
     * Inicializa un proyecto con el nombre proporcionado.
     * 
     * @param nombre Nombre del proyecto.
     */
    Proyecto(const std::string& nombre);

    /**
     * @brief Agrega una tarea al proyecto.
     * 
     * Añade una nueva tarea al vector de tareas del proyecto.
     * 
     * @param tarea Tarea a agregar al proyecto.
     */
    void agregarTarea(const Tarea<int>& tarea);

    /**
     * @brief Elimina una tarea del proyecto.
     * 
     * Elimina una tarea del proyecto por su nombre. Si la tarea no se encuentra, lanza una excepción.
     * 
     * @param nombreTarea Nombre de la tarea a eliminar.
     * @throws std::runtime_error Si la tarea no se encuentra en el proyecto.
     */
    void eliminarTarea(const std::string& nombreTarea);

    /**
     * @brief Ordena las tareas por costo.
     * 
     * Ordena las tareas del proyecto en orden ascendente por su costo.
     */
    void ordenarTareasPorCosto();

    /**
     * @brief Ordena las tareas por tiempo estimado.
     * 
     * Ordena las tareas del proyecto en orden descendente por el tiempo estimado.
     */
    void ordenarTareasPorTiempo();

    /**
     * @brief Ordena las tareas por prioridad.
     * 
     * Ordena las tareas del proyecto en orden ascendente por prioridad.
     */
    void ordenarTareasPorPrioridad();

    /**
     * @brief Muestra un resumen del proyecto.
     * 
     * Imprime un resumen del proyecto en la consola, mostrando el nombre del proyecto,
     * el número total de tareas, el costo total y el tiempo total estimado.
     */
    void mostrarResumen() const;
};

#endif // PROYECTO_HPP
