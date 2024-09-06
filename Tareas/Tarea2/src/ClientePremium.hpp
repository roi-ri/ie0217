#ifndef CLIENTEPREMIUM_HPP
#define CLIENTEPREMIUM_HPP

#include"Cliente.hpp"

class ClientePremium : public Cliente {
    private:
        double descuento; 

    public: 
        ClientePremium(const string& nombre, double descuento);
        double aplicarDescuento() const override; 

};



#endif // CLIENTEPREMIUM_HPP


