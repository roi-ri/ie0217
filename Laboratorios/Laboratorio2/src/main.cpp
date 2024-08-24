#include <iostream> 
#include "funciones.hpp"

using namespace std;
// Se establece MAX_LIBROS para mayor facilidad a futuro si fuera necesario recurrir al cambio de 100 a otro numero especifico
const int MAX_LIBROS = 100; 

 int main() {
    Libro libros[MAX_LIBROS]; 
    int cantidadLibros; 
    int opcion;
    //do-while para asegurar que se haga al menos una vez la impresión del menú
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

    }while(opcion != 6); // Si se selecciona opcion 6 se rompe el while y se sale del programa

    return 0; 
 }