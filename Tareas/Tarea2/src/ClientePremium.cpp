#include"ClientePremium.hpp" 

ClientePremium::ClientePremium(const string& nombre, double descuento) : Cliente(nombre), descuento(descuento){};
/**
 * @brief Aplica el descuento al total de la compra para un cliente premium.
 * @return El total después de aplicar el descuento.
 *
 * Este método aplica el descuento específico del cliente premium al total de la compra.
 * El descuento se calcula como un porcentaje del total, restando una proporción del total 
 * correspondiente al porcentaje de descuento. 
 */
double ClientePremium::aplicarDescuento() const {
    return calcularTotal() * (1- descuento / 100); 
}
