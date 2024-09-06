#ifndef PRODUCTODIGITAL_HPP
#define PRODUCTODIGITAL_HPP

#include"Producto.hpp"

class ProductoDigital : public Producto {
    private: 
        string id; 

    public: 
        ProductoDigital(const string &nombre, double precio, const string &id);
        string getId() const; 
};

#endif //PRODUCTODIGITAL_HPP

