#include <iostream> 
#include "funciones.hpp"

using namespace std;

const int MAX_LIBROS = 100; 

 int main() {
    Libro libros[MAX_LIBROS]; 
    int cantidadLibros;
    int opcion;

    do{
        cout << "\n Sistema de Gestión de Libros\n";
        cout << "1. Agregar un libro\n";
        cout << "2. Buscar un libro por título\n";
        cout << "3. Buscar libro por ISBN\n";
        cout << "4. Mostrar todos los libros\n";
        cout << "5. Eliminar un libro\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion; 
        switch (opcion){
            case 1:
                agregarLibro(libros, cantidadLibros);
                break;
            case 2:
                buscarLibroPorTitulo(libros, cantidadLibros);
                break;
            case 3:
                buscarLibroPorISBN(libros, cantidadLibros);
                break;
            case 4:
                mostrarLibros(libros, cantidadLibros);
                break;
            case 5:
                eliminarLibros(libros, cantidadLibros);
                break;
            case 6:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opción incorrecta, intente nuevamente.\n";
        }

    }while(opcion != 6); 

    return 0; 
 }