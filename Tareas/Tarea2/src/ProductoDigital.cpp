#include"ProductoDigital.hpp"


ProductoDigital::ProductoDigital(const string &nombre, double precio, const string &id) : Producto(nombre, precio) , id(id){};

string ProductoDigital::getId() const{
    return id; 
}