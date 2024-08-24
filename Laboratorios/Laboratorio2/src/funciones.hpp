#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "libro.hpp"
//Firmas de las funciones
void agregarLibro(Libro libros[], int &cantidadLibros);
void mostrarLibros(Libro libros [], int cantidadLibros);
void buscarLibroPorISBN(Libro libros[], int cantidadLibros);
void buscarLibroPorTitulo(Libro libros [], int cantidadLibros);
void eliminarLibros(Libro libros [], int &cantidadLibros);

#endif //FUNCIONES_HPP