#include "ManejoBaseDatos.hpp"
#include "DataBase.hpp"
#include <iostream>
#include <sqlite3.h>

using namespace std;

/**
 * @brief Punto de entrada principal del programa.
 * 
 * Este programa gestiona una base de datos de reseñas de profesores y cursos.
 * Establece una conexión con la base de datos especificada y crea las tablas necesarias
 * si no existen. Presenta un menú de opciones al usuario para ingresar información,
 * buscar datos y salir del programa.
 * 
 * @return int Devuelve EXIT_SUCCESS si el programa se ejecuta correctamente,
 *              o EXIT_FAILURE si hay un error en la conexión a la base de datos.
 */
int main() {
    string dbName = "ResenasProfesoresyCursos.db";  ///< Nombre de la base de datos

    sqlite3* db = connectToDatabase(dbName);  ///< Conexión a la base de datos
    if (db == nullptr) {
        return EXIT_FAILURE;  ///< Salir si la conexión falla
    }

    // Crear las tablas si no existen
    createProfeTable(db);

    int exit = 0;  ///< Variable para controlar el menú
    while (exit != 10) {  ///< Ciclo principal del menú
        cout << "\n--- Menú Principal ---\n";
        cout << "1. Ingresar Profesor\n";
        cout << "2. Ingresar Curso\n";
        cout << "3. Ingresar Reseña\n";
        cout << "4. Buscar Profesor por Curso y Escuela\n";
        cout << "5. Mostrar Cursos y Promedios por Escuela\n";
        cout << "6. Buscar Reseñas no Revisadas\n";
        cout << "7. Buscar Top Profesores\n";
        cout << "8. Actualizar Estado de Reseñas\n";
        cout << "9. Eliminar Reseña\n";
        cout << "10. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> exit;  ///< Captura la opción seleccionada
        cin.ignore();  ///< Limpiar el buffer de entrada

        switch (exit) {  ///< Estructura de control para el menú
            case 1:
                IngresarProfesor(db);  ///< Llamada a la función para ingresar un profesor
                break;
            case 2:
                IngresarCurso(db);  ///< Llamada a la función para ingresar un curso
                break;
            case 3:
                IngresarResena(db);  ///< Llamada a la función para ingresar una reseña
                break;
            case 4:
                BuscarProfeCE(db);  ///< Llamada a la función para buscar un profesor por curso y escuela
                break;
            case 5:
                MostrarTopProfes(db);  ///< Llamada a la función para mostrar cursos y promedios por escuela
                break;
            case 6:
                EstadoRevisionRes(db);  ///< Llamada a la función para actualizar el estado de las reseñas
                break;
            case 7:
                BuscarTopProfe(db);  ///< Llamada a la función para buscar los top profesores
                break;
            case 8:
                ActualresenaNoRev(db);
            case 9: 
                EliminarResena(db);
            case 10:
                cout << "Saliendo del programa...\n";  ///< Mensaje de salida
                break;
                return 0;
            default:
                cout << "Opción no válida. Por favor, intente de nuevo.\n";  ///< Mensaje de error
        }
    }

    // Cerrar la base de datos
    sqlite3_close(db);  ///< Cierre de la conexión a la base de datos
    return EXIT_SUCCESS;  ///< Retorno exitoso
}
