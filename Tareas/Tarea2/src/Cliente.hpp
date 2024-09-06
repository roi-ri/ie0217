#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include<iostream> 
#include<string> 
#include<vector> 
#include"Producto.hpp"
using namespace std; 


/**
 * @class Cliente
 * @brief Representa a un cliente en la tienda.
 *
 * La clase `Cliente` almacena información sobre un cliente, incluyendo su nombre y los productos en su carrito.
 * También proporciona métodos para agregar productos al carrito, calcular el total del carrito, 
 * y aplicar descuentos (para clases derivadas).
 */
class Cliente {
    private: 
        /// Nombre del cliente.
        string nombre; 
        /// Vector que almacena los productos en el carrito del cliente.
        vector<Producto*> carrito; 
    public: 
        /**
          * @brief Constructor de la clase `Cliente`.
         * @param nombre Nombre del cliente.
         *
         * Este constructor inicializa un objeto `Cliente` con el nombre proporcionado.
         */
        Cliente(const string& nombre);
        /**
         * @brief Agrega un producto al carrito del cliente.
         * @param producto Puntero al objeto `Producto` que se desea agregar al carrito.
         *
         * Este método añade el puntero al objeto `Producto` al vector `carrito` del cliente.
         */
        void agregarProducto(Producto* producto);
        /**
         * @brief Calcula el total del carrito del cliente.
         * @return El total a pagar por los productos en el carrito.
         *
         * Este método recorre el vector `carrito` y suma el precio de cada producto para calcular el total.
         */
        double calcularTotal() const; 
        /**
         * @brief Aplica un descuento a la compra del cliente.
         * @return El monto con descuento aplicado.
         *
         * Este método es virtual y debe ser sobrecargado en las clases derivadas para aplicar descuentos específicos.
         */
        virtual double aplicarDescuento() const;
         /**
         * @brief Obtiene el nombre del cliente.
         * @return El nombre del cliente.
         *
         * Este método devuelve el nombre del cliente almacenado en el objeto.
         */
        string getNombre() const; 
        

}; 






#endif // CLIENTE_HPP