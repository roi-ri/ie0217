#include"ProductoFisico.hpp"

ProductoFisico::ProductoFisico(const string &nombre, double precio, double peso) : Producto(nombre, precio) , peso(peso){};

double ProductoFisico::getPeso() const{
    return peso;
}

