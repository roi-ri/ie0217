#include "DataBase.hpp"

char *errMSG = 0;
int rc; 


static int callback(void *data, int argc, char **argv, char **azColName){
      for (int i = 0; i < argc; i++){
        cout << azColName[i] << "=" << (argv[i] ? argv[i] : "NULL") << endl; 
    }
    return 0;   
}




sqlite3 *connecToDatabase(const string &dbName){
    sqlite3 *db;
    int result = sqlite3_open(dbName.c_str(), &db);
    if (result != SQLITE_OK)
    {
        cerr << "No se pudo conectar a la base de datos: " << sqlite3_errmsg(db) << endl;
        return nullptr;
    }
    cout << "La conexión con la base de datos ha sido exitosa.\n" << endl; 
    return db;
}


void createProfeTable(sqlite3* db){
    //Tabla Profesor
    const char *sql = "CREATE TABLE IF NOT EXISTS PROFESOR("
                      "ID_PROFESOR INT PRIMARY KEY AUTOINCREMENT,"
                      "NOMBRE CHAR(100),"
                      "ESCUELA CHAR(100);";          
    rc = sqlite3_exec(db, sql, callback, 0, &errMSG);
    if(rc != SQLITE_OK){
        cerr << "SQL error: " << &errMSG << endl;
        sqlite3_free(errMSG);
    }else{
        cout << "Tabla \"Profesor\" creada correctamente" << endl;
    }

    //Tabla Curso
    const char *sqlCursos = "CREATE TABLE IF NOT EXISTS CURSOS("
                            "ID_CURSO INTEGER PRIMARY KEY AUTOINCREMENT,"
                            "NOMBRE_CURSO TEXT,"
                            "ID_PROFESOR INTEGER,"
                            "FOREIGN KEY (ID_PROFESOR) REFERENCES PROFESOR(ID_PROFESOR) ON DELETE CASCADE);";      
    rc = sqlite3_exec(db, sql, callback, 0, &errMSG);
    if(rc != SQLITE_OK){
        cerr << "SQL error: " << &errMSG << endl;
        sqlite3_free(errMSG);
    }else{
        cout << "Tabla \"CURSOS\" creada correctamente" << endl;
    }

    //Tabla reseñas
    const char *sql = "CREATE TABLE IF NOT EXISTS RESENAS ("
                      "ID_RESENA INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "ID_PROFESOR INTEGER NOT NULL,"
                      "ID_CURSO INTEGER NOT NULL,"
                      "CALIFICACION INTEGER CHECK(CALIFICACION >= 1 AND CALIFICACION <= 5),"
                      "DIFICULTAD INTEGER CHECK(DIFICULTAD >= 1 AND DIFICULTAD <= 5),"
                      "COMENTARIO TEXT,"
                      "REVISADO INTEGER DEFAULT 0,"
                      "FOREIGN KEY (ID_PROFESOR) REFERENCES PROFESOR(ID_PROFESOR) ON DELETE CASCADE,"
                      "FOREIGN KEY (ID_CURSO) REFERENCES CURSOS(ID_CURSO) ON DELETE CASCADE);";

    rc = sqlite3_exec(db, sql, callback, 0, &errMSG);
    if(rc != SQLITE_OK){
        cerr << "SQL error: " << &errMSG << endl;
        sqlite3_free(errMSG);
    }else{
        cout << "Tabla \"RESEÑAS\" creada correctamente" << endl;
    }
}




