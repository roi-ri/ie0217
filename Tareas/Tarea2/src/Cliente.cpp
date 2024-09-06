#include"Cliente.hpp" 

Cliente::Cliente(const string& nombre) : nombre(nombre) {};


void Cliente::agregarProducto(Producto* producto){
    carrito.push_back(producto);
}


double Cliente::calcularTotal() const {
    double total = 0.0;
    for (const auto& producto : carrito) {
        total += producto->getPrecio();
    }
    return total;
}

string Cliente::getNombre() const{
    return nombre; 
}