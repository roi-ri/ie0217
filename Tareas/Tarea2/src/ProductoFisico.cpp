#include"ProductoFisico.hpp"

/**
 * @brief Constructor de la clase `ProductoFisico`.
 * @param nombre Nombre del producto.
 * @param precio Precio del producto.
 * @param peso Peso del producto en kilogramos.
 *
 * Este constructor inicializa un objeto `ProductoFisico` con el nombre, precio y peso proporcionados.
 * Llama al constructor de la clase base `Producto` para inicializar el nombre y precio, 
 * y luego inicializa el peso del producto físico.
 */
ProductoFisico::ProductoFisico(const string &nombre, double precio, double peso) : Producto(nombre, precio) , peso(peso){};

/**
 * @brief Obtiene el peso del producto físico.
 * @return El peso del producto en kilogramos.
 *
 * Este método devuelve el peso del producto almacenado en el objeto.
 */

double ProductoFisico::getPeso() const{
    return peso;
}

