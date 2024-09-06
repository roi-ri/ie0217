#ifndef CLIENTEREGULAR_HPP
#define CLIENTEREGULAR_HPP
#include"Cliente.hpp" 


/**
 * @class ClienteRegular
 * @brief Representa un cliente regular en la tienda.
 *
 * La clase `ClienteRegular` hereda de `Cliente` y representa un tipo específico de cliente
 * que no tiene descuentos adicionales sobre el precio de los productos.
 */
class ClienteRegular : public Cliente {
    
    public: 
        /**
         * @brief Constructor de la clase `ClienteRegular`.
         * @param nombre Nombre del cliente.
         *
         * Este constructor inicializa un objeto `ClienteRegular` con el nombre proporcionado.
         * Llama al constructor de la clase base `Cliente` para inicializar el nombre del cliente.
         */
        ClienteRegular(const string &nombre);
        /**
         * @brief Aplica el descuento al total de la compra.
         * @return El total después de aplicar el descuento.
         *
         * Este método aplica el descuento correspondiente para un cliente regular. En este caso,
         * no se aplica ningún descuento adicional y el total se calcula sin modificaciones.
         */
        double aplicarDescuento() const override; 


};

#endif // CLIENTEREGULAR_HPP

