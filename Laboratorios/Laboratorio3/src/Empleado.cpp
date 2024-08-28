#include "empleado.hpp"

using namespace std;

Empleado::Empleado(const string &nombre, int id, double salario) : nombre(nombre), id(id), salario(salario){}; // Igual que hacer el this->nombre, this->id, etc...
// Constructor de la clase empleado
// INicializa el nombre, ID y salario del empleado

void Empleado::setNombre(const string &nombre) {
    // Establece el nombre del empleado
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
/*
Compara el salario de dos empleados.
arámetros:
e1: Primer empleado a comparar.
e2: Segundo empleado a comparar.
Retorno: true si el salario del primer empleado es mayor que el del segundo, false en caso contrario.
*/
bool compararSalario(const Empleado &e1, const Empleado &e2){
   return e1.salario > e2.salario; 
}

/*
 Sobrecarga del operador de inserción << para la clase Empleado.
 Permite mostrar la información del empleado en un flujo de salida (como cout).
 Parámetros:
 os: El flujo de salida donde se insertará la información del empleado.
 empleado: El empleado cuya información se mostrará.
 Retorno:
 El flujo de salida actualizado.
*/
ostream &operator<<(ostream &os, const Empleado &empleado){
        os << "Nombre: " << empleado.nombre << ", ID: " << empleado.id << ", Salario: " << empleado.salario;
        return os;
};