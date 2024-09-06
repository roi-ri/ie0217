#ifndef CLIENTE_HPP
#define CLIENTE_HPP
#include<iostream> 
#include<string> 
#include<vector> 
#include"Producto.hpp"
using namespace std; 



class Cliente {
    private: 
        string nombre; 
        vector<Producto*> carrito; 
    public: 
        Cliente(const string& nombre);
        void agregarProducto(Producto* producto);
        double calcularTotal() const; 
        virtual double aplicarDescuento() const; 



}; 






#endif // CLIENTE_HPP