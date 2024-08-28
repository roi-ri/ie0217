#include "empleadoTiempoCompleto.hpp"
#include <iostream>

using namespace std;

EmpleadoTiempoCompleto::EmpleadoTiempoCompleto(const string &nombre, int id, double salario, double bonificacion, double deduccion) 
    : Empleado(nombre, id, salario), bonificacion(bonificacion), deduccion(deduccion) {}

void EmpleadoTiempoCompleto::setBonificacion(double boni) {
    this->bonificacion = boni;
}

void EmpleadoTiempoCompleto::setDeduccion(double dedu) {
    this->deduccion = dedu;
}

double EmpleadoTiempoCompleto::getSalario() const {
    return Empleado::getSalario() + bonificacion - deduccion;
}

void EmpleadoTiempoCompleto::mostrarInformacion() const {
    cout << "Nombre: " << nombre << ", ID: " << id << ", Salario: " << getSalario()
         << ", Bonificación: " << bonificacion << ", Deducción: " << deduccion << endl;
}
