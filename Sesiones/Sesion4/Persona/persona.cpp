#include "persona.hpp"

using namespace std; 

Persona::Persona(string name, int edad) {
    this->name = name;
    this->edad = edad;  
}

string Persona::getNombre() {
    return name; 
}

int Persona::getEdad() {
    return edad;
}   

void Persona::setEdad(int edad) {
    this->edad = edad;
}
