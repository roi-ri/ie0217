#ifndef EMPLEADO_TIEMPO_COMPLETO_HPP
#define EMPLEADO_TIEMPO_COMPLETO_HPP

#include "empleado.hpp"


using namespace std;

class EmpleadoTiempoCompleto : public Empleado {
    private: 
        double bonificacion;
        double deduccion;


    public: 
    EmpleadoTiempoCompleto(const string &nombre, int id, double salario, double bonificacion, double deduccion);

    void setBonificacion(double bonificacion);

    void setDeduccion(double deduccion);

    double getSalario() const override; 

    void mostrarInformacion()  const override; // si o si tiene que aparecer en la clase heredada

};



#endif //EMPLEADO_TIEMPO_COMPLETO_HPP