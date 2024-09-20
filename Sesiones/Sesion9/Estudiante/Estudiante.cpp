#include "Estudiante.hpp"
#include<iostream> 

Estudiante::Estudiante(const std::string& nombre, int edad) : nombre(nombre), edad(edad){} 

void Estudiante::mostrarDatos(){
    std::cout << "Nombre: " << nombre; 
    std::cout << ", edad: " << edad << std::endl;
}