#include "empleado.hpp"

using namespace std;

Empleado::Empleado(const string &nombre, int id, double salario) : nombre(nombre), id(id), salario(salario){}; // Igual que hacer el this->nombre, this->id, etc...

void Empleado::setNombre(const string &nombre) {
    this->nombre = nombre;
};

string Empleado::getNombre() const {
    return nombre;
    // Devuelve una copia de nombre (evita la modificación del nombre original)
};


void Empleado::setId(int id) {
    this->id = id;
};

int Empleado::getId() const {
    return id;
};

void Empleado::setSalario(double salario){
    this->salario = salario;
}

double Empleado::getSalario() const {
    return salario;
}


bool compararSalario(const Empleado &e1, const Empleado &e2){
   return e1.salario > e2.salario; 
}



ostream &operator<<(ostream &os, const Empleado &empleado){
        os << "Nombre: " << empleado.nombre << ", ID: " << empleado.id << ", Salario: " << empleado.salario;
        return os;
};