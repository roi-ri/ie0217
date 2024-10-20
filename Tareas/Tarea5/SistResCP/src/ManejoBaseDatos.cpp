#include "ManejoBaseDatos.hpp"

void IngresarProfesor(sqlite3*db){

    string nombre, escuela; 

    cout << "Ingrese el nombre del profesor:\n";
    getline(cin, nombre); 

    cout << "Ingrese el nombre de la escuela al que pertenece el profesor:\n";
    getline(cin, escuela); 

    const char *sql = "INSERT INTO PROFESOR (NOMBRE, ESCUELA) VALUES (?,?);";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, nombre.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, escuela.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_DONE){
        int idProfesor = sqlite3_last_insert_rowid(db);
        cout << "Profesor agregado con ID: " << idProfesor << endl; 
        } else {
        cerr << "Error al agregar al Profesor.\n";
        }
    }else {
        cerr << "Error en la preparacion de la consulta.\n";
    }
    sqlite3_finalize(stmt); 
}


void IngresarCurso(sqlite3*db){
    string nombreCurso; 
    int idProfesor; 

    cout << "Ingrese el nombre del curso:\n"; 
    getline(cin,nombreCurso); 

    cout << "Ingrese el ID del profesor que imparte dicho curso:\n";
    cin >> idProfesor; 


    const char *checkSql = "SELECT COUNT(*) FROM PROFESOR WHERE ID_PROFESOR = ?;";
    sqlite3_stmt *checkStmt; 

    if (sqlite3_prepare_v2(db, checkSql, -1, &checkStmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_int(checkStmt, 1, idProfesor);

        if (sqlite3_step(checkStmt) == SQLITE_ROW) {
            int count = sqlite3_column_int(checkStmt, 0);
            if (count == 0) {
                std::cerr << "Error: El ID del profesor " << idProfesor << " no existe." << std::endl;
                sqlite3_finalize(checkStmt);
                return;  // Salir de la función si el ID no existe
            }
        }
    } else {
        std::cerr << "Error en la preparación de la consulta de verificación." << std::endl;
        sqlite3_finalize(checkStmt);
        return;  // Salir de la función si hay un error
    }


    sqlite3_finalize(checkStmt);

    // Si llegamos aquí, el ID del profesor existe, proceder a insertar el curso
    const char *sql = "INSERT INTO CURSOS (NOMBRE_CURSO, ID_PROFESOR) VALUES (?, ?);";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, nombreCurso.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 2, idProfesor);

        if (sqlite3_step(stmt) == SQLITE_DONE) {
            std::cout << "Curso agregado: " << nombreCurso << std::endl;
        } else {
            std::cerr << "Error al insertar el curso." << std::endl;
        }
    } else {
        std::cerr << "Error en la preparación de la consulta de inserción." << std::endl;
    }

    sqlite3_finalize(stmt);
}

