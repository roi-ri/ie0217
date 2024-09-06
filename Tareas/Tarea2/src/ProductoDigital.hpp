#ifndef PRODUCTODIGITAL_HPP
#define PRODUCTODIGITAL_HPP

#include"Producto.hpp"
/**
 * @class ProductoDigital
 * @brief Representa un producto digital en la tienda.
 *
 * La clase `ProductoDigital` hereda de `Producto` y añade un atributo adicional para la identificación
 * del producto digital. Representa productos que no tienen una forma física, como software o contenido
 * descargable.
 */
class ProductoDigital : public Producto {
    private: 
        /// Identificador único del producto digital.
        string id; 

    public: 
        /**
         * @brief Constructor de la clase `ProductoDigital`.
         * @param nombre Nombre del producto.
         * @param precio Precio del producto.
         * @param id Identificador único del producto digital.
         *
         * Este constructor inicializa un objeto `ProductoDigital` con el nombre, precio e identificador proporcionados.
         */
        ProductoDigital(const string &nombre, double precio, const string &id);
        /**
         * @brief Obtiene el identificador del producto digital.
         * @return El identificador del producto digital.
         *
         * Este método devuelve el identificador del producto digital almacenado en el objeto.
         */
        string getId() const; 
};

#endif //PRODUCTODIGITAL_HPP

