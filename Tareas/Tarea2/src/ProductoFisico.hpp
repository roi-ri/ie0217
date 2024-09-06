#ifndef PRODUCTOFISICO_HPP
#define PRODUCTOFISICO_HPP

#include"Producto.hpp"

class ProductoFisico : public Producto{
    private: 
        double peso; 

    public: 
        ProductoFisico(const string& nombre, double precio, double peso); 
        double getPeso() const; 

};






#endif //  PRODUCTOFISICO_HPP