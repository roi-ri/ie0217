#include <iostream>
#include <mongocxx/client.hpp>
#include <bsoncxx/json.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>
#include "Publicacion.hpp"
#include "Funciones.hpp"

using namespace std; 

mongocxx::instance instance{};  ///< Crear la instancia de MongoDB una vez
mongocxx::client client{mongocxx::uri{"mongodb://localhost:27017"}};  ///< Conectar al servidor MongoDB
mongocxx::database db = client["social_network"];  ///< Conectar a la base de datos social_network
mongocxx::collection posts = db["posts"];  ///< Conectar a la colección posts

/**
 * @brief Muestra el menú de opciones del sistema.
 *
 * Este método imprime las opciones disponibles para el usuario en el sistema de publicaciones.
 */
void mostrarMenu() {
    cout << "=== Sistema de Publicaciones en Red Social ===\n";
    cout << "1. Insertar Publicación\n";
    cout << "2. Consultar Publicaciones\n";
    cout << "3. Consultar Publicaciones por Autor\n";
    cout << "4. Actualizar Contenido de una Publicación\n";
    cout << "5. Eliminar Publicación\n";
    cout << "6. Marcar Publicación como Destacada\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opción: ";
}

/**
 * @brief Función principal del sistema de publicaciones.
 *
 * Esta función gestiona el menú y las operaciones del sistema de publicaciones en red social.
 * Permite al usuario insertar, consultar, actualizar, eliminar y marcar publicaciones como destacadas.
 *
 * @return int Valor de retorno del programa (0 para una salida exitosa).
 */
int main() {
    auto collection = posts; 
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

        if (opcion == 1) {
            string autor, contenido, fecha;
            cout << "Autor: "; getline(cin, autor);
            cout << "Contenido: "; getline(cin, contenido);
            cout << "Fecha (YYYY-MM-DD): "; getline(cin, fecha);

            Publicacion p(autor, contenido, fecha);
            insertarPublicacion(collection, p);

        } else if (opcion == 2) {
            consultarPublicaciones(collection);

        } else if (opcion == 3) {
            string autor;
            cout << "Autor: "; getline(cin, autor);
            consultarPublicacionesPorAutor(collection, autor);

        } else if (opcion == 4) {
            string autor, fecha, nuevoContenido;
            cout << "Autor: "; getline(cin, autor);
            cout << "Fecha (YYYY-MM-DD): "; getline(cin, fecha);
            cout << "Nuevo Contenido: "; getline(cin, nuevoContenido);
            actualizarContenidoPublicacion(collection, autor, fecha, nuevoContenido);

        } else if (opcion == 5) {
            string autor, fecha;
            cout << "Autor: "; getline(cin, autor);
            cout << "Fecha (YYYY-MM-DD): "; getline(cin, fecha);
            eliminarPublicacion(collection, autor, fecha);

        } else if (opcion == 6) {
            string autor, fecha;
            bool destacado;
            cout << "Autor: "; getline(cin, autor);
            cout << "Fecha (YYYY-MM-DD): "; getline(cin, fecha);
            cout << "¿Marcar como destacado? (1 = Sí, 0 = No): ";
            cin >> destacado;
            marcarPublicacionDestacada(collection, autor, fecha, destacado);

        } else if (opcion != 0) {
            cout << "Opción no válida. Intente de nuevo.\n";
        }
        
        cout << "\n"; // Espacio entre operaciones
    } while (opcion != 0);

    cout << "Saliendo del sistema de publicaciones.\n";
    return 0;
}
