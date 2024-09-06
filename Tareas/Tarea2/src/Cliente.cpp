#include"Cliente.hpp" 

Cliente::Cliente(const string& nombre) : nombre(nombre) {};

/**
 * @brief Agrega un producto al carrito del cliente.
 * @param producto Puntero al objeto `Producto` que se desea agregar al carrito.
 *
 * Este método añade el puntero al objeto `Producto` al vector `carrito` del cliente.
 */
void Cliente::agregarProducto(Producto* producto){
    carrito.push_back(producto);
}

/**
 * @brief Calcula el total del carrito del cliente.
 * @return El total a pagar por los productos en el carrito.
 *
 * Este método recorre el vector `carrito` y suma el precio de cada producto para calcular el total.
 */
double Cliente::calcularTotal() const {
    double total = 0.0;
    for (const auto& producto : carrito) {
        total += producto->getPrecio();
    }
    return total;
}
/**
 * @brief Obtiene el nombre del cliente.
 * @return El nombre del cliente.
 *
 * Este método devuelve el nombre del cliente almacenado en el objeto.
 */
string Cliente::getNombre() const{
    return nombre; 
}

double Cliente::aplicarDescuento() const {
    return calcularTotal(); // Implementación por defecto, puede ser sobrescrita
}