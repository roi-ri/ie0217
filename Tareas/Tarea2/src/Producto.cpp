#include"Producto.hpp"

using namespace std; 

/**
 * @brief Constructor de la clase `Producto`.
 * @param nombre Nombre del producto.
 * @param precio Precio del producto.
 *
 * Este constructor inicializa un objeto `Producto` con el nombre y precio proporcionados.
 */
Producto::Producto(const string &nombre, double precio) : nombre(nombre), precio(precio){};


string Producto::getNombre() const {
    return nombre;
}

double Producto::getPrecio() const{
    return precio; 
}

