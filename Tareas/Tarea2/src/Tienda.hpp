#ifndef TIENDA_HPP
#define TIENDA_HPP
#include "Producto.hpp"
#include "Cliente.hpp"

/**
 * @class Tienda
 * @brief Representa una tienda que gestiona productos y clientes.
 *
 * La clase `Tienda` permite agregar productos y clientes, y procesar compras realizadas por los clientes.
 */
class Tienda { 
     
    public: 
        /**
         * @brief Agrega un producto a la tienda.
         * @param producto Puntero al objeto `Producto` que se desea agregar.
        *
        * Este método almacena el puntero al objeto `Producto` en el vector de productos disponibles de la tienda.
        */
        void agregarProducto(Producto* producto); 
        /**
         * @brief Agrega un cliente a la tienda.
        * @param cliente Puntero al objeto `Cliente` que se desea agregar.
         *
         * Este método almacena el puntero al objeto `Cliente` en el vector de clientes de la tienda.
        */
        void agregarCliente(Cliente* cliente);  
         /**
        * @brief Procesa la compra realizada por un cliente.
        * @param nombreCliente Nombre del cliente que realiza la compra.
        *
         * Este método busca al cliente por su nombre y procesa la compra utilizando los productos disponibles en la tienda.
        */
        void procesarCompra(const string &nombreCLiente);

        /// Vector que contiene los productos disponibles en la tienda.    
        vector<Producto*> productosDisponibles; 
        

        /// Vector que contiene los clientes de la tienda.
        vector<Cliente*> clientes; 
}; 


#endif // TIENDA_HPP