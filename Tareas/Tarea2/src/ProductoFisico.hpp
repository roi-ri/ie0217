#ifndef PRODUCTOFISICO_HPP
#define PRODUCTOFISICO_HPP

#include"Producto.hpp"


/**
 * @class ProductoFisico
 * @brief Representa un producto físico en la tienda.
 *
 * La clase `ProductoFisico` hereda de `Producto` e incluye una propiedad adicional para el peso.
 * Representa productos que tienen una dimensión física y pueden requerir un manejo especial basado en su peso.
 */
class ProductoFisico : public Producto{
    private: 
        /// Peso del producto en kilogramos.
        double peso; 

    public: 
        /**
         * @brief Constructor de la clase `ProductoFisico`.
         * @param nombre Nombre del producto.
         * @param precio Precio del producto.
         * @param peso Peso del producto en kilogramos.
         *
         * Este constructor inicializa un objeto `ProductoFisico` con el nombre, precio y peso proporcionados.
         */
        ProductoFisico(const string& nombre, double precio, double peso); 
        /**
         * @brief Obtiene el peso del producto físico.
         * @return El peso del producto en kilogramos.
         *
         * Este método devuelve el peso del producto almacenado en el objeto.
         */
        double getPeso() const; 

};






#endif //  PRODUCTOFISICO_HPP