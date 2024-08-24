#include <iostream> 
#include <cstring> 
#include "funciones.hpp"

using namespace std;

// La funcion agregar libros le pide al usuario ingresar el titulo del libro y lo almnacena como la 'caracteristica' titulo
// Lo hace igual con el autor, el ISBN y año de publicación
void agregarLibro(Libro libros[], int &cantidadLibros){

    cout << " Ingrese el titulo del libro: ";
    cin.ignore();
    cin.getline(libros[cantidadLibros].titulo, 100);

    cout << "Ingrese el autor del libro: "; 
    cin.getline(libros[cantidadLibros].autor, 100);


    cout << "Ingrese el ISBN del libro: "; 
    cin.getline(libros[cantidadLibros].ISBN, 13);


    cout << "Ingrese el año de publicación del libro: "; 
    cin >> libros[cantidadLibros].anioPublicacion;

    cantidadLibros++;


}

// En caso de que no se encuentren libros en la lista el programa va a imprimir en la salida el mensaje de que no hay libros 
// Si se llegaran a encontrar libros va a iterar sobre la cantidad de libros que hay y va a ir imprimiendo en consola los distintos atributos de cada libro.

void mostrarLibros(Libro libros [], int cantidadLibros){

    if (cantidadLibros == 0){

        cout << "No hay libros en la lista"<<endl; 

    } else { 
        for (int i = 0; i < cantidadLibros; i++){
            cout << i + 1 << "." << libros[i].titulo << " por: " << libros[i].autor << " (ISBN: " << libros[i].ISBN << " Año: " << libros[i].anioPublicacion << ")" << endl; 

        }
    }

}

// Se solicita al usiario ingresar el titulo del libro que desea buscar, seguidamente se va a iterar con un for la cantidad de libros comparando el titulo de cada uno con el titulo que dio el usuario
// En caso de que strcmp retorne cero, esto va a indicar que el titulo coincide, por ended se entra a la condición del if, indicando que el libro con tales especificaciones fue encontrado. en caso contrario da un mensaje de que no fue encontrado. 
void buscarLibroPorTitulo(Libro libros [], int cantidadLibros){

    char titulo [100];
    cout << "Ingrese el título del libro que desea buscar: ";
    cin.ignore();
    cin.getline(titulo, 100); 

    bool encontrado = false;

    for (int i = 0; i < cantidadLibros; i++){
        if (strcmp(libros[i].titulo, titulo) == 0){ // strcmp: Va a comparar dos strings y devuelve 0 si ambas cosas son exactamente iguales
            cout << "Libro encontrado; " << libros[i].titulo << ' por: ' << libros[i].autor << endl; 
            encontrado = true;
            break; 
        }
    }
    if (!encontrado) {

        cout << "El libro no ha sido encontrado. " << endl; 
    }
}
// Se solicita al usuario ingresar el ISBN del libro para poder realizar la busqueda mediante este. 
// Se va a seguir la misma logica de busqueda empleada en la funcion de buscar por nombnre pero esta vez se compara con el ISBN 
void buscarLibroPorISBN(Libro libros[], int cantidadLibros) {
    char ISBN[13];
    cout << "Ingrese el ISBN del libro que desea buscar: ";
    cin.ignore();
    cin.getline(ISBN, 13);
    bool encontrado = false;
    for (int i = 0; i < cantidadLibros; i++) {
        if (strcmp(libros[i].ISBN, ISBN) == 0) {
            cout << "Libro encontrado: " << libros[i].titulo << " por " << libros[i].autor << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "Libro no encontrado." << endl;
    }
}

//Para eliminar un libro, se utiliza la logica de burcar un libro ya sea por titulo o ISBN, en este caso, a la hora de hacer un match se van a empezar a copiar los libros posteriores con la finalidad de no dejar ese espacio en blanco del libro eliminado.
void eliminarLibros(Libro libros [], int &cantidadLibros){

    char ISBN[13]; 

    cout << "Ingrese el ISBN del libro que desea eliminar: "; 
    cin.ignore(); 
    cin.getline(ISBN, 13); 

    bool encontrado = false;

    for (int i = 0; i < cantidadLibros; i++){

        if (strcmp(libros[i].ISBN, ISBN) == 0){
            for (int j = i; j < cantidadLibros - 1; j++){
                libros[j] = libros[j + 1];
            }
            cantidadLibros = cantidadLibros - 1; 
            cout << "Libro eliminado: " << endl; 
            return; 
        }
    }
    cout << "Libro no encontrado: " << endl;
}
