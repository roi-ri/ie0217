#include "DataBase.hpp"

char *errMSG = nullptr; ///< Variable para almacenar mensajes de error de SQL.
int rc; ///< Variable para almacenar el resultado de la ejecución de comandos SQL.

/**
 * @brief Callback para la ejecución de consultas SQL.
 *
 * Esta función se llama para cada fila de resultados devuelta por una consulta
 * SQL ejecutada con sqlite3_exec. Imprime los nombres de las columnas y sus valores.
 *
 * @param data Puntero a datos de usuario (no se utiliza en esta implementación).
 * @param argc Número de columnas en la fila.
 * @param argv Valores de las columnas en la fila.
 * @param azColName Nombres de las columnas.
 * @return Siempre devuelve 0.
 */
static int callback(void *data, int argc, char **argv, char **azColName) {
    for (int i = 0; i < argc; i++) {
        cout << azColName[i] << "=" << (argv[i] ? argv[i] : "NULL") << endl; 
    }
    return 0;   
}

/**
 * @brief Conecta a una base de datos SQLite.
 *
 * Intenta abrir la base de datos especificada. Si la conexión es exitosa,
 * devuelve un puntero a la base de datos; de lo contrario, imprime un mensaje
 * de error y devuelve nullptr.
 *
 * @param dbName Nombre de la base de datos a la que se quiere conectar.
 * @return Puntero a sqlite3 si la conexión es exitosa, nullptr en caso contrario.
 */
sqlite3 *connectToDatabase(const string &dbName) {
    sqlite3 *db;
    int result = sqlite3_open(dbName.c_str(), &db);
    if (result != SQLITE_OK) {
        cerr << "No se pudo conectar a la base de datos: " << sqlite3_errmsg(db) << endl;
        return nullptr;
    }
    cout << "La conexión con la base de datos ha sido exitosa.\n" << endl; 
    return db;
}


bool checkTableExists(sqlite3* db, const string& tableName) {
    string query = "SELECT name FROM sqlite_master WHERE type='table' AND name='" + tableName + "';";
    sqlite3_stmt* stmt;

    rc = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    if (rc != SQLITE_OK) {
        cerr << "Error al preparar la consulta: " << sqlite3_errmsg(db) << endl;
        return false;
    }

    bool exists = sqlite3_step(stmt) == SQLITE_ROW; // Verifica si hay resultados

    sqlite3_finalize(stmt); // Libera la memoria del statement
    return exists;
}

/**
 * @brief Crea las tablas en la base de datos.
 *
 * Esta función crea las tablas "PROFESOR", "CURSOS" y "RESEÑAS" en la base
 * de datos si no existen. Cada tabla tiene sus respectivas columnas y
 * restricciones.
 *
 * @param db Puntero a la base de datos donde se crearán las tablas.
 */
void createProfeTable(sqlite3* db) {
    // Verifica si la tabla PROFESOR existe
    if (!checkTableExists(db, "PROFESOR")) {
        // Tabla Profesor
        const char *sqlProfe = "CREATE TABLE IF NOT EXISTS PROFESOR ("
                               "ID_PROFESOR INTEGER PRIMARY KEY AUTOINCREMENT,"
                               "NOMBRE CHAR(100),"
                               "ESCUELA CHAR(100));";          
        rc = sqlite3_exec(db, sqlProfe, callback, 0, &errMSG);
        if(rc != SQLITE_OK) {
            cerr << "SQL error: " << errMSG << endl; 
            sqlite3_free(errMSG);
        } else {
            cout << "Tabla \"Profesor\" creada correctamente" << endl;
        }
    } else {
        cout << "Tabla \"Profesor\" ya existe. Accediendo a ella." << endl;
    }

    // Verifica si la tabla CURSOS existe
    if (!checkTableExists(db, "CURSOS")) {
        // Tabla Curso
        const char *sqlCursos = "CREATE TABLE IF NOT EXISTS CURSOS ("
                                "ID_CURSO INTEGER PRIMARY KEY AUTOINCREMENT,"
                                "NOMBRE_CURSO TEXT,"
                                "ID_PROFESOR INTEGER,"
                                "FOREIGN KEY (ID_PROFESOR) REFERENCES PROFESOR(ID_PROFESOR) ON DELETE CASCADE);";      
        rc = sqlite3_exec(db, sqlCursos, callback, 0, &errMSG);
        if(rc != SQLITE_OK) {
            cerr << "SQL error: " << errMSG << endl; 
            sqlite3_free(errMSG);
        } else {
            cout << "Tabla \"CURSOS\" creada correctamente" << endl;
        }
    } else {
        cout << "Tabla \"CURSOS\" ya existe. Accediendo a ella." << endl;
    }

    // Verifica si la tabla Reseñas existe
    if (!checkTableExists(db, "RESENAS")) {
        // Tabla Reseñas
        const char *sqlResenas = "CREATE TABLE IF NOT EXISTS RESENAS ("
                                 "ID_RESENA INTEGER PRIMARY KEY AUTOINCREMENT,"
                                 "ID_PROFESOR INTEGER NOT NULL,"
                                 "ID_CURSO INTEGER NOT NULL,"
                                 "CALIFICACION INTEGER CHECK(CALIFICACION >= 1 AND CALIFICACION <= 5),"
                                 "DIFICULTAD INTEGER CHECK(DIFICULTAD >= 1 AND DIFICULTAD <= 5),"
                                 "COMENTARIO TEXT,"
                                 "REVISADO INTEGER DEFAULT 0,"
                                 "FOREIGN KEY (ID_PROFESOR) REFERENCES PROFESOR(ID_PROFESOR) ON DELETE CASCADE,"
                                 "FOREIGN KEY (ID_CURSO) REFERENCES CURSOS(ID_CURSO) ON DELETE CASCADE);";

        rc = sqlite3_exec(db, sqlResenas, callback, 0, &errMSG);
        if(rc != SQLITE_OK) {
            cerr << "SQL error: " << errMSG << endl;
            sqlite3_free(errMSG);
        } else {
            cout << "Tabla \"RESEÑAS\" creada correctamente" << endl;
        }
    } else {
        cout << "Tabla \"RESEÑAS\" ya existe. Accediendo a ella." << endl;
    }
}