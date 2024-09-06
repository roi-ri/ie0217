#include"ProductoDigital.hpp"

/**
 * @brief Constructor de la clase `ProductoDigital`.
 * @param nombre Nombre del producto.
 * @param precio Precio del producto.
 * @param id Identificador único del producto digital.
 *
 * Este constructor inicializa un objeto `ProductoDigital` con el nombre, precio e identificador proporcionados.
 * Llama al constructor de la clase base `Producto` para inicializar el nombre y el precio, 
 * y luego inicializa el identificador del producto digital.
 */
ProductoDigital::ProductoDigital(const string &nombre, double precio, const string &id) : Producto(nombre, precio) , id(id){};


/**
 * @brief Obtiene el identificador del producto digital.
 * @return El identificador del producto digital.
 *
 * Este método devuelve el identificador del producto digital almacenado en el objeto.
 */
string ProductoDigital::getId() const{
    return id; 
}