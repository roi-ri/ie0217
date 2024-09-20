#include "libro.hpp" 
#include<iostream>

Libro::Libro(const std::string& titulo, const std::string& autor) : titulo(titulo), autor(autor){}

void Libro::mostrarInfo() const{
    std::cout << "Titulo: " << titulo << ", Autor: " << autor << std::endl; 
    
}
