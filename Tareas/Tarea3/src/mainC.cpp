#include "ListaEnlazada.hpp"
#include "Cancion.hpp"
#include <iostream>
using namespace std; 


/**
 * @brief Función principal del programa.
 *
 * Este programa permite al usuario gestionar una lista de canciones. 
 * Ofrece opciones para insertar, eliminar, modificar e imprimir canciones en una lista enlazada.
 * La interacción con el usuario se realiza a través de un menú de opciones en la consola.
 *
 * @return Código de estado de salida del programa.
 */
int main() {
    ListaEnlazada lista; /**< Instancia de la lista enlazada que almacena canciones. */
    
    int opcion; /**< Opción seleccionada por el usuario. */

    string nombre, artista; /**< Nombre de la canción y Nombre del artista de la canción. */
    double duracion; /**< Duración de la canción en minutos. */

    do {
        cout << "\n1. Insertar una nueva canción\n";
        cout << "2. Eliminar una canción\n";
        cout << "3. Modificar una canción\n";
        cout << "4. Imprimir lista de canciones\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "Ingrese el nombre de la canción: ";
                cin.ignore();
                getline(cin, nombre);
                cout << "Ingrese el nombre del artista: ";
                getline(cin, artista);
                cout << "Ingrese la duración de la canción (en minutos): ";
                cin >> duracion;
                lista.insertarFinal(Cancion(nombre, artista, duracion));
                break;
            }
            case 2: {
                cout << "Ingrese el nombre de la canción a eliminar: ";
                cin.ignore();
                getline(cin, nombre);
                lista.eliminar(nombre);
                break;
            }
            case 3: {
                cout << "Ingrese el nombre de la canción a modificar: ";
                cin.ignore();
                getline(cin, nombre);
                Nodo* nodo = lista.buscar(nombre);
                if (nodo) {
                    cout << "Ingrese el nuevo nombre de la canción: ";
                    getline(cin, nombre);
                    cout << "Ingrese el nuevo nombre del artista: ";
                    getline(cin, artista);
                    cout << "Ingrese la nueva duración de la canción (en minutos): ";
                    cin >> duracion;
                    lista.modificar(nodo->cancion.getNombre(), Cancion(nombre, artista, duracion));
                } else {
                    cout << "Canción no encontrada.\n";
                }
                break;
            }
            case 4:
                lista.imprimir();
                break;
            case 5:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 5);

    return 0;
}
