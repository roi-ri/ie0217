/**
 * @file Tarea.hpp
 * @brief Declaración de la clase Tarea.
 * 
 * La clase Tarea permite definir una tarea con atributos como nombre, costo, tiempo estimado, prioridad y recursos.
 * Utiliza plantillas para permitir la flexibilidad en el tipo de datos de los recursos.
 */

#ifndef TAREA_HPP
#define TAREA_HPP

#include <string>
#include <iostream>
#include <stdexcept> // Para std::invalid_argument

/**
 * @class Tarea
 * @brief Clase que representa una tarea dentro de un proyecto.
 * 
 * La clase Tarea encapsula los detalles de una tarea, como el nombre, costo, tiempo estimado, prioridad y recursos. 
 * Además, permite la gestión de los atributos con validaciones.
 * 
 * @tparam T Tipo de los recursos que la tarea requiere.
 */
template <typename T>
class Tarea {
private:
    std::string nombre; ///< Nombre de la tarea
    double costo; ///< Costo de la tarea
    double tiempo_estimado; ///< Tiempo estimado para completar la tarea
    int prioridad; ///< Prioridad de la tarea (1-Alta, 2-Media, 3-Baja)
    T recursos; ///< Recursos requeridos para la tarea

public:
    /**
     * @brief Constructor de la clase Tarea.
     * 
     * Inicializa una tarea con su nombre, costo, tiempo estimado, prioridad y recursos.
     * 
     * @param nombre Nombre de la tarea.
     * @param costo Costo de la tarea.
     * @param tiempo_estimado Tiempo estimado para completar la tarea.
     * @param prioridad Prioridad de la tarea (1-Alta, 2-Media, 3-Baja).
     * @param recursos Recursos necesarios para completar la tarea.
     * 
     * @throws std::invalid_argument Si el costo es negativo, el tiempo estimado es menor o igual a 0, 
     * o si la prioridad no está en el rango 1-3.
     */
    Tarea(const std::string& nombre, double costo, double tiempo_estimado, int prioridad, const T& recursos);

    // Getters
    
    /**
     * @brief Obtiene el nombre de la tarea.
     * @return Nombre de la tarea.
     */
    std::string getNombre() const;

    /**
     * @brief Obtiene el costo de la tarea.
     * @return Costo de la tarea.
     */
    double getCosto() const;

    /**
     * @brief Obtiene el tiempo estimado de la tarea.
     * @return Tiempo estimado en días.
     */
    double getTiempoEstimado() const;

    /**
     * @brief Obtiene la prioridad de la tarea.
     * @return Prioridad de la tarea (1-Alta, 2-Media, 3-Baja).
     */
    int getPrioridad() const;

    /**
     * @brief Obtiene los recursos de la tarea.
     * @return Recursos asociados a la tarea.
     */
    T getRecursos() const;

    // Setters
    
    /**
     * @brief Establece el nuevo costo de la tarea.
     * 
     * @param newCosto El nuevo costo de la tarea.
     * @throws std::invalid_argument Si el nuevo costo es negativo.
     */
    void setCosto(double newCosto);

    /**
     * @brief Establece el nuevo tiempo estimado de la tarea.
     * 
     * @param newTiempo El nuevo tiempo estimado de la tarea en días.
     * @throws std::invalid_argument Si el nuevo tiempo estimado es menor o igual a 0.
     */
    void setTiempoEstimado(double newTiempo);

    /**
     * @brief Establece la nueva prioridad de la tarea.
     * 
     * @param newPrioridad La nueva prioridad de la tarea (1-Alta, 2-Media, 3-Baja).
     * @throws std::invalid_argument Si la prioridad está fuera del rango 1-3.
     */
    void setPrioridad(int newPrioridad);

    /**
     * @brief Muestra la información de la tarea.
     * 
     * Imprime la información detallada de la tarea, incluyendo el nombre, costo, tiempo estimado y prioridad.
     */
    void mostrarInfo() const;
};

#endif // TAREA_HPP
