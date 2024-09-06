#ifndef CLIENTEPREMIUM_HPP
#define CLIENTEPREMIUM_HPP

#include"Cliente.hpp"

/**
 * @class ClientePremium
 * @brief Representa un cliente premium en la tienda.
 *
 * La clase `ClientePremium` hereda de `Cliente` y representa un tipo específico de cliente
 * que tiene un descuento adicional sobre el precio de los productos. El descuento es un porcentaje
 * que se aplica al total de la compra.
 */

class ClientePremium : public Cliente {
    private:
        /// Porcentaje de descuento aplicado para clientes premium.
        double descuento; 

    public: 
        /**
         * @brief Constructor de la clase `ClientePremium`.
         * @param nombre Nombre del cliente.
         * @param descuento Porcentaje de descuento para el cliente premium.
         *
         * Este constructor inicializa un objeto `ClientePremium` con el nombre y el porcentaje de descuento proporcionados.
         * Llama al constructor de la clase base `Cliente` para inicializar el nombre del cliente.
         */
        ClientePremium(const string& nombre, double descuento);
        /**
         * @brief Aplica el descuento al total de la compra para un cliente premium.
         * @return El total después de aplicar el descuento.
         *
         * Este método aplica el descuento específico del cliente premium al total de la compra. 
         * El descuento se calcula como un porcentaje del total y se resta del total de la compra.
         */
        double aplicarDescuento() const override; 

};



#endif // CLIENTEPREMIUM_HPP


