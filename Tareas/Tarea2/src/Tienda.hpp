#ifndef TIENDA_HPP
#define TIENDA_HPP
#include "Producto.hpp"
#include "Cliente.hpp"


class Tienda {
    private: 
        vector<Producto*> productosDisponibles; 
        vector<Cliente*> clientes; 

    public: 
        void agregarProducto(Producto* producto); 
        void agregarCliente(Cliente* cliente); 
        void procesarCompra(const string &nombreCLiente);
}; 


#endif // TIENDA_HPP