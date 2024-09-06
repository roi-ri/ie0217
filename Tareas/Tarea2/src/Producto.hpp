#ifndef PRODUCTO_HPP
#define PRODUCTO_HPP 
#include<iostream>
#include<string>

using namespace std;

class Producto{ 
    protected: //Estos elementos los pueden accesar las clases derivadas y la misma clase
        string nombre; 
        double precio;

    public:
        Producto(const string &nombre, double precio);

        void setNombre();
        string getNombre();
        void setPrecio();
        double getPrecio();


};

#endif //PRODUCTO_HPP