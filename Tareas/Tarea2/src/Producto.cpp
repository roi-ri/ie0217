#include"Producto.hpp"

using namespace std; 

//Constructo de la clase Producto inicializa el nombre y precio del producto
Producto::Producto(const string &nombre, double precio ) : nombre(nombre), precio(precio){};


string Producto::getNombre() const {
    return nombre;
}

double Producto::getPrecio() const{
    return precio; 
}

