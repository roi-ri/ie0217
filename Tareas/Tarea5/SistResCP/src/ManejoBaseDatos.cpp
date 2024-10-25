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

void IngresarResena(sqlite3* db) {
    int idProfesor, idCurso, calificacion, dificultad;
    string comentario;

    cout << "Ingrese el ID del profesor:\n";
    cin >> idProfesor;
    cout << "Ingrese el ID del curso:\n";
    cin >> idCurso;
    cout << "Ingrese la calificación (1 a 5):\n";
    cin >> calificacion;
    cout << "Ingrese la dificultad (1 a 5):\n";
    cin >> dificultad;
    cin.ignore();  // Ignorar salto de línea después de la entrada numérica
    cout << "Ingrese el comentario (opcional):\n";
    getline(cin, comentario);

    // Verificar si el ID del profesor existe
    const char *checkProfesorSql = "SELECT COUNT(*) FROM PROFESOR WHERE ID_PROFESOR = ?;";
    sqlite3_stmt *checkProfesorStmt;

    if (sqlite3_prepare_v2(db, checkProfesorSql, -1, &checkProfesorStmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_int(checkProfesorStmt, 1, idProfesor);

        if (sqlite3_step(checkProfesorStmt) == SQLITE_ROW && sqlite3_column_int(checkProfesorStmt, 0) == 0) {
            cerr << "Error: El ID del profesor no existe.\n";
            sqlite3_finalize(checkProfesorStmt);
            return;
        }
    } else {
        cerr << "Error en la preparación de la consulta de verificación del profesor.\n";
        sqlite3_finalize(checkProfesorStmt);
        return;
    }
    sqlite3_finalize(checkProfesorStmt);

    // Verificar si el ID del curso existe
    const char *checkCursoSql = "SELECT COUNT(*) FROM CURSOS WHERE ID_CURSO = ?;";
    sqlite3_stmt *checkCursoStmt;

    if (sqlite3_prepare_v2(db, checkCursoSql, -1, &checkCursoStmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_int(checkCursoStmt, 1, idCurso);

        if (sqlite3_step(checkCursoStmt) == SQLITE_ROW && sqlite3_column_int(checkCursoStmt, 0) == 0) {
            cerr << "Error: El ID del curso no existe.\n";
            sqlite3_finalize(checkCursoStmt);
            return;
        }
    } else {
        cerr << "Error en la preparación de la consulta de verificación del curso.\n";
        sqlite3_finalize(checkCursoStmt);
        return;
    }
    sqlite3_finalize(checkCursoStmt);

    // Insertar reseña en la tabla RESENAS
    const char *sql = "INSERT INTO RESENAS (ID_PROFESOR, ID_CURSO, CALIFICACION, DIFICULTAD, COMENTARIO) VALUES (?, ?, ?, ?, ?);";
    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, idProfesor);
        sqlite3_bind_int(stmt, 2, idCurso);
        sqlite3_bind_int(stmt, 3, calificacion);
        sqlite3_bind_int(stmt, 4, dificultad);
        sqlite3_bind_text(stmt, 5, comentario.c_str(), -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_DONE) {
            cout << "Reseña agregada correctamente.\n";
        } else {
            cerr << "Error al insertar la reseña.\n";
        }
    } else {
        cerr << "Error en la preparación de la consulta de inserción de reseña.\n";
    }

    sqlite3_finalize(stmt);
}

void BuscarProfeCE(sqlite3*db){
    string nombreCurso, nombreEscuela; 

    cout << "Ingrese el nombre del curso: \n"; 
    getline(cin, nombreCurso); 

    cout << "Ingrese el nombre de la escuela a la que pertenece el profesor:\n"; 
    getline(cin,nombreEscuela); 

    const char *sql = "SELECT p.NOMBRE " 
                      "FROM PROFESOR.p "
                      "JOIN CURSOS C ON P.ID_PROFESOR = C.ID_PROFESOR "
                      "WHERE C.NOMBRE_CURSO = ? AND P.ESCUELA + ?; "; 

    sqlite3_stmt *stmt; 

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, nombreCurso.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, nombreEscuela.c_str(), -1, SQLITE_STATIC);

        bool found = false;
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const unsigned char *nombreProfesor = sqlite3_column_text(stmt, 0);
            cout << "Profesor encontrado: " << nombreProfesor << endl;
            found = true;
        }

        if (!found) {
            cout << "No se encontró ningún profesor para el curso y escuela especificados.\n";
        }
    } else {
        cerr << "Error en la preparación de la consulta.\n";
    }

    sqlite3_finalize(stmt);
}

void MostrarTopProfes(sqlite3*db){
string nombreEscuela;

    cout << "Ingrese el nombre de la escuela:\n";
    getline(cin, nombreEscuela);

    const char *sql = "SELECT C.NOMBRE_CURSO, "
                      "       AVG(R.CALIFICACION) AS Promedio_Calificacion, "
                      "       AVG(R.DIFICULTAD) AS Promedio_Dificultad "
                      "FROM CURSOS C "
                      "JOIN RESENAS R ON C.ID_CURSO = R.ID_CURSO "
                      "JOIN PROFESOR P ON P.ID_PROFESOR = C.ID_PROFESOR "
                      "WHERE P.ESCUELA = ? "
                      "GROUP BY C.NOMBRE_CURSO "
                      "ORDER BY Promedio_Calificacion DESC, Promedio_Dificultad ASC;";

    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, nombreEscuela.c_str(), -1, SQLITE_STATIC);

        bool found = false;
        cout << "Curso\t\tPromedio Calificación\tPromedio Dificultad\n";
        cout << "----------------------------------------------------------\n";

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const unsigned char *nombreCurso = sqlite3_column_text(stmt, 0);
            double promedioCalificacion = sqlite3_column_double(stmt, 1);
            double promedioDificultad = sqlite3_column_double(stmt, 2);

            cout << nombreCurso << "\t\t" << promedioCalificacion << "\t\t" << promedioDificultad << endl;
            found = true;
        }

        if (!found) {
            cout << "No se encontraron cursos para la escuela especificada.\n";
        }
    } else {
        cerr << "Error en la preparación de la consulta.\n";
    }

    sqlite3_finalize(stmt);   
}

void ActualizarEstadoResena(sqlite3*db){
    const char *sql = "SELECT P.NOMBRE AS Profesor, "
                      "       C.NOMBRE_CURSO AS Curso, "
                      "       R.COMENTARIO AS Comentario "
                      "FROM RESENAS R "
                      "JOIN PROFESOR P ON R.ID_PROFESOR = P.ID_PROFESOR "
                      "JOIN CURSOS C ON R.ID_CURSO = C.ID_CURSO "
                      "WHERE R.REVISADO = 0;";

    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        bool found = false;
        cout << "Profesor\tCurso\t\tComentario\n";
        cout << "-------------------------------------------\n";

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const unsigned char *nombreProfesor = sqlite3_column_text(stmt, 0);
            const unsigned char *nombreCurso = sqlite3_column_text(stmt, 1);
            const unsigned char *comentario = sqlite3_column_text(stmt, 2);

            cout << nombreProfesor << "\t" << nombreCurso << "\t" << comentario << endl;
            found = true;
        }

        if (!found) {
            cout << "No hay reseñas pendientes de revisión.\n";
        }
    } else {
        cerr << "Error en la preparación de la consulta.\n";
    }

    sqlite3_finalize(stmt);
    
}

void BuscarTopProfe(sqlite3*db){
    const char *sql = "SELECT P.NOMBRE AS Profesor, "
                      "       P.ESCUELA AS Escuela, "
                      "       AVG(R.CALIFICACION) AS Promedio_Calificacion "
                      "FROM PROFESOR P "
                      "JOIN CURSOS C ON P.ID_PROFESOR = C.ID_PROFESOR "
                      "JOIN RESENAS R ON C.ID_CURSO = R.ID_CURSO "
                      "GROUP BY P.ID_PROFESOR "
                      "ORDER BY Promedio_Calificacion DESC;";

    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        cout << "Profesor\tEscuela\t\tPromedio Calificación\n";
        cout << "--------------------------------------------------\n";
        bool found = false;

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const unsigned char *nombreProfesor = sqlite3_column_text(stmt, 0);
            const unsigned char *escuela = sqlite3_column_text(stmt, 1);
            double promedioCalificacion = sqlite3_column_double(stmt, 2);

            cout << nombreProfesor << "\t" << escuela << "\t" << promedioCalificacion << endl;
            found = true;
        }

        if (!found) {
            cout << "No se encontraron profesores con calificaciones.\n";
        }
    } else {
        cerr << "Error en la preparación de la consulta.\n";
    }

    sqlite3_finalize(stmt);   
}

void EliminarResena(sqlite3*db){
int idResena; // Variable para almacenar el ID de la reseña
    cout << "Introduce el ID de la reseña a eliminar: ";
    cin >> idResena; // Solicita al usuario el ID de la reseña

    const char *sql = "DELETE FROM RESENAS WHERE ID_RESENA = ?;";
    sqlite3_stmt *stmt;

    // Prepara la consulta
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, idResena); // Vincula el ID a la consulta

        // Ejecuta la consulta
        if (sqlite3_step(stmt) == SQLITE_DONE) {
            cout << "Reseña con ID " << idResena << " eliminada correctamente.\n";
        } else {
            cerr << "Error al eliminar la reseña.\n";
        }
    } else {
        cerr << "Error en la preparación de la consulta de eliminación.\n";
    }

    // Finaliza el uso de la declaración
    sqlite3_finalize(stmt);    
}

void ConsultResenaPositiv(sqlite3*db){
    const char *sql = "SELECT P.NOMBRE AS Profesor, "
                      "       C.NOMBRE_CURSO AS Curso, "
                      "       R.COMENTARIO AS Comentario, "
                      "       R.CALIFICACION AS 'Calificación', "
                      "       R.DIFICULTAD AS 'Dificultad' "
                      "FROM RESENAS R "
                      "JOIN PROFESOR P ON R.ID_PROFESOR = P.ID_PROFESOR "
                      "JOIN CURSOS C ON R.ID_CURSO = C.ID_CURSO "
                      "WHERE R.CALIFICACION >= 4 AND R.DIFICULTAD < 3;";

    sqlite3_stmt *stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        cout << "Profesor\tCurso\t\tComentario\t\tCalificación\tDificultad\n";
        cout << "--------------------------------------------------------------------------\n";
        bool found = false;

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            const unsigned char *nombreProfesor = sqlite3_column_text(stmt, 0);
            const unsigned char *nombreCurso = sqlite3_column_text(stmt, 1);
            const unsigned char *comentario = sqlite3_column_text(stmt, 2);
            int calificacion = sqlite3_column_int(stmt, 3);
            int dificultad = sqlite3_column_int(stmt, 4);

            cout << nombreProfesor << "\t" << nombreCurso << "\t" << comentario 
                 << "\t" << calificacion << "\t\t" << dificultad << endl;
            found = true;
        }

        if (!found) {
            cout << "No se encontraron reseñas con calificación >= 4 y dificultad < 3.\n";
        }
    } else {
        cerr << "Error en la preparación de la consulta.\n";
    }

    sqlite3_finalize(stmt);
}

