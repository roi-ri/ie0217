#include"ClienteRegular.hpp" 

ClienteRegular::ClienteRegular(const string& nombre) : Cliente(nombre) {}; 

double ClienteRegular::aplicarDescuento() const{
    return calcularTotal(); // NO tienen descuento
}