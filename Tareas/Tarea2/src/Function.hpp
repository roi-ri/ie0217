#ifndef FUNCTION_HPP
#define FUNCTION_HPP
#include<iostream> 
#include "Tienda.hpp"
#include <string> 

/**
 * @struct Function
 * @brief Estructura que encapsula funcionalidades relacionadas con la gestión de la tienda.
 *
 * La estructura `Function` proporciona métodos para agregar productos, registrar clientes, 
 * agregar productos al carrito y procesar compras en la tienda.
 */
struct Function{
    /// Objeto de la clase `Tienda` que gestiona productos y clientes.
    Tienda tienda; 
    /**
     * @brief Agrega un producto a la tienda.
     *
     * Este método solicita la información del producto al usuario y lo añade a la tienda.
     */
    void agregarProducto();
    /**
     * @brief Registra un nuevo cliente en la tienda.
     *
     * Este método solicita la información del cliente al usuario y lo añade a la tienda.
     */
    void registrarCliente();
    /**
     * @brief Agrega un producto al carrito del cliente.
     *
     * Este método permite al usuario seleccionar un producto y añadirlo al carrito del cliente.
     */
    void agregarProductoAlCarrito();
    /**
     * @brief Procesa la compra realizada por un cliente.
     *
     * Este método calcula el total a pagar para el cliente y lo muestra en la consola.
     */
    void procesarCompra();
};



#endif //  FUNCTION_HPP
