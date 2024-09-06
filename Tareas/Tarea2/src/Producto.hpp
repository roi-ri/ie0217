#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP 
#include<iostream>
#include<string>

using namespace std;


/**
 * @class Producto
 * @brief Representa un producto en la tienda.
 *
 * La clase `Producto` es una clase base que representa un producto general en la tienda.
 * Incluye atributos básicos como el nombre y el precio del producto, que son comunes
 * a todos los productos, tanto físicos como digitales.
 */
class Producto{ 
    protected: 
        /// Nombre del producto.
        string nombre; 
        /// Precio del producto.
        double precio;

    public:
        /**
         * @brief Constructor de la clase `Producto`.
         * @param nombre Nombre del producto.
         * @param precio Precio del producto.
         *
         * Este constructor inicializa un objeto `Producto` con el nombre y el precio proporcionados.
         */
        Producto(const string &nombre, double precio);
        /**
         * @brief Obtiene el nombre del producto.
         * @return El nombre del producto.
         *
         * Este método devuelve el nombre del producto almacenado en el objeto.
         */
        string getNombre() const;
        /**
         * @brief Obtiene el precio del producto.
         * @return El precio del producto.
         *
         * Este método devuelve el precio del producto almacenado en el objeto.
         */
        double getPrecio() const;
        


};

#endif //PRODUCTO_HPPß