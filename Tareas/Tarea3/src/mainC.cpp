#include "ListaEnlazada.hpp"
#include "Cancion.hpp"
#include <iostream>

int main() {
    ListaEnlazada lista;
    
    int opcion;
    std::string nombre, artista;
    double duracion;

    do {
        std::cout << "\n1. Insertar una nueva canción\n";
        std::cout << "2. Eliminar una canción\n";
        std::cout << "3. Modificar una canción\n";
        std::cout << "4. Imprimir lista de canciones\n";
        std::cout << "5. Salir\n";
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::cout << "Ingrese el nombre de la canción: ";
                std::cin.ignore();
                std::getline(std::cin, nombre);
                std::cout << "Ingrese el nombre del artista: ";
                std::getline(std::cin, artista);
                std::cout << "Ingrese la duración de la canción (en minutos): ";
                std::cin >> duracion;
                lista.insertarFinal(Cancion(nombre, artista, duracion));
                break;
            }
            case 2: {
                std::cout << "Ingrese el nombre de la canción a eliminar: ";
                std::cin.ignore();
                std::getline(std::cin, nombre);
                lista.eliminar(nombre);
                break;
            }
            case 3: {
                std::cout << "Ingrese el nombre de la canción a modificar: ";
                std::cin.ignore();
                std::getline(std::cin, nombre);
                Nodo* nodo = lista.buscar(nombre);
                if (nodo) {
                    std::cout << "Ingrese el nuevo nombre de la canción: ";
                    std::getline(std::cin, nombre);
                    std::cout << "Ingrese el nuevo nombre del artista: ";
                    std::getline(std::cin, artista);
                    std::cout << "Ingrese la nueva duración de la canción (en minutos): ";
                    std::cin >> duracion;
                    lista.modificar(nodo->cancion.getNombre(), Cancion(nombre, artista, duracion));
                } else {
                    std::cout << "Canción no encontrada.\n";
                }
                break;
            }
            case 4:
                lista.imprimir();
                break;
            case 5:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opción inválida.\n";
        }
    } while (opcion != 5);

    return 0;
}
