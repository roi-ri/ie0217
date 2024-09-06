#include"ClienteRegular.hpp" 

ClienteRegular::ClienteRegular(const string& nombre) : Cliente(nombre) {}; 
/**
 * @brief Aplica el descuento al total de la compra para un cliente regular.
 * @return El total después de aplicar el descuento.
 *
 * En el caso de un `ClienteRegular`, no se aplica ningún descuento adicional. 
 * Por lo tanto, este método devuelve el total calculado sin modificaciones.
 */
double ClienteRegular::aplicarDescuento() const{
    return calcularTotal(); // NO tienen descuento
}