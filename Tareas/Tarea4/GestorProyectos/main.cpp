/**
 * @file main.cpp
 * @brief Simulador de Gestión de Proyectos.
 * 
 * Este programa permite gestionar proyectos y sus tareas. Los usuarios pueden agregar, eliminar
 * y ordenar tareas en proyectos, además de obtener un resumen de los proyectos creados.
 */

#include <iostream>
#include <map>
#include "Proyecto.hpp"
#include "Tarea.hpp"

/**
 * @brief Función principal del simulador de gestión de proyectos.
 * 
 * Muestra un menú interactivo para que el usuario gestione proyectos y tareas.
 * El programa permite agregar y eliminar proyectos, agregar y eliminar tareas,
 * ordenar tareas por costo, tiempo o prioridad, y mostrar un resumen de un proyecto.
 * 
 * @return int Devuelve 0 al finalizar el programa.
 */
int main() {
    std::map<std::string, Proyecto> proyectos; ///< Mapa que almacena los proyectos por su nombre.
    int opcion; ///< Opción seleccionada en el menú.

    do {
        // Menú principal
        std::cout << "Menú de Simulador de Gestión de Proyectos:\n";
        std::cout << "1. Agregar un nuevo proyecto\n";
        std::cout << "2. Agregar una tarea a un proyecto existente\n";
        std::cout << "3. Eliminar una tarea de un proyecto\n";
        std::cout << "4. Ordenar tareas por costo, tiempo o prioridad\n";
        std::cout << "5. Mostrar el resumen de un proyecto\n";
        std::cout << "6. Eliminar un proyecto\n";
        std::cout << "7. Salir\n";
        std::cout << "Seleccione una opción: ";

        // Captura de entrada
        std::cin >> opcion;

        // Verifica si la entrada es válida
        if (std::cin.fail()) {
            std::cin.clear(); // Limpiar el estado de error
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorar la entrada incorrecta
            std::cout << "Por favor, ingrese un número válido.\n";
            continue; // Regresar al inicio del bucle
        }

        try {
            std::string nombreProyecto; ///< Nombre del proyecto ingresado por el usuario.

            switch (opcion) {
                case 1: {
                    std::cout << "Ingrese el nombre del proyecto: ";
                    std::cin >> nombreProyecto;
                    proyectos[nombreProyecto] = Proyecto(nombreProyecto); ///< Agrega un nuevo proyecto al mapa.
                    std::cout << "Proyecto agregado.\n";
                    break;
                }
                case 2: {
                    std::string nombreTarea; ///< Nombre de la tarea ingresada.
                    double costo; ///< Costo de la tarea ingresada.
                    double tiempo; ///< Tiempo estimado de la tarea ingresada.
                    int prioridad; ///< Prioridad de la tarea ingresada (1-Alta, 2-Media, 3-Baja).
                    int recursos; ///< Recursos asignados a la tarea ingresada.

                    std::cout << "Ingrese el nombre del proyecto: ";
                    std::cin >> nombreProyecto;

                    if (proyectos.find(nombreProyecto) == proyectos.end()) {
                        throw std::runtime_error("Proyecto no encontrado");
                    }

                    std::cout << "Nombre de la tarea: ";
                    std::cin >> nombreTarea;
                    std::cout << "Costo de la tarea: ";
                    std::cin >> costo;
                    std::cout << "Tiempo estimado de la tarea (días): ";
                    std::cin >> tiempo;
                    std::cout << "Prioridad (1-Alta, 2-Media, 3-Baja): ";
                    std::cin >> prioridad;
                    std::cout << "Recursos: ";
                    std::cin >> recursos;

                    Tarea<int> tarea(nombreTarea, costo, tiempo, prioridad, recursos); ///< Crea una nueva tarea.
                    proyectos[nombreProyecto].agregarTarea(tarea); ///< Agrega la tarea al proyecto.
                    std::cout << "Tarea agregada.\n";
                    break;
                }
                case 3: {
                    std::string nombreTarea; ///< Nombre de la tarea a eliminar.
                    std::cout << "Ingrese el nombre del proyecto: ";
                    std::cin >> nombreProyecto;

                    if (proyectos.find(nombreProyecto) == proyectos.end()) {
                        throw std::runtime_error("Proyecto no encontrado");
                    }

                    std::cout << "Ingrese el nombre de la tarea: ";
                    std::cin >> nombreTarea;
                    proyectos[nombreProyecto].eliminarTarea(nombreTarea); ///< Elimina la tarea del proyecto.
                    std::cout << "Tarea eliminada.\n";
                    break;
                }
                case 4: {
                    std::cout << "Ingrese el nombre del proyecto: ";
                    std::cin >> nombreProyecto;

                    if (proyectos.find(nombreProyecto) == proyectos.end()) {
                        throw std::runtime_error("Proyecto no encontrado");
                    }

                    int criterio; ///< Criterio de ordenamiento (1-Costo, 2-Tiempo, 3-Prioridad).
                    std::cout << "1. Ordenar por costo\n2. Ordenar por tiempo\n3. Ordenar por prioridad\n";
                    std::cin >> criterio;

                    if (criterio == 1)
                        proyectos[nombreProyecto].ordenarTareasPorCosto(); ///< Ordena las tareas por costo.
                    else if (criterio == 2)
                        proyectos[nombreProyecto].ordenarTareasPorTiempo(); ///< Ordena las tareas por tiempo.
                    else if (criterio == 3)
                        proyectos[nombreProyecto].ordenarTareasPorPrioridad(); ///< Ordena las tareas por prioridad.
                    
                    std::cout << "Tareas ordenadas.\n";
                    break;
                }
                case 5: {
                    std::cout << "Ingrese el nombre del proyecto: ";
                    std::cin >> nombreProyecto;

                    if (proyectos.find(nombreProyecto) == proyectos.end()) {
                        throw std::runtime_error("Proyecto no encontrado");
                    }

                    proyectos[nombreProyecto].mostrarResumen(); ///< Muestra el resumen del proyecto.
                    break;
                }
                case 6: {
                    std::cout << "Ingrese el nombre del proyecto: ";
                    std::cin >> nombreProyecto;

                    if (proyectos.find(nombreProyecto) == proyectos.end()) {
                        throw std::runtime_error("Proyecto no encontrado");
                    }

                    proyectos.erase(nombreProyecto); ///< Elimina el proyecto del mapa.
                    std::cout << "Proyecto eliminado.\n";
                    break;
                }
                case 7:
                    std::cout << "Saliendo del programa.\n";
                    break;
                default:
                    std::cout << "Opción no válida. Intente de nuevo.\n";
                    break;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    } while (opcion != 7);

    return 0;
}
