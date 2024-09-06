#include"ClientePremium.hpp" 

ClientePremium::ClientePremium(const string& nombre, double descuento) : Cliente(nombre), descuento(descuento){};

double ClientePremium::aplicarDescuento() const {
    return calcularTotal() * (1- descuento / 100); 
}
