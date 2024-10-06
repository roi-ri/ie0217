#include<sqlite3.h>
#include <iostream>


using namespace std; 


//Funcion de callback para imprimir los resultados de las consultas
static int callback(void *data, int argc, char **argv, char **azColName){
    for (int i = 0; i < argc; i++){
        cout << azColName[i] << "=" << (argv[i] ? argv[i] : "NULL") << endl; 
    }
    return 0;   
}


int main(int argc, char*argv[]){
    sqlite3 *db;
    char *errMSG = 0;
    int rc;
    const char* data = "CallBack Function called";

    //Abre la base de datos, si no existe la va a crear
    rc = sqlite3_open("test_dp", &db);
    if(rc){
        cerr << "No se puede abrir la base de datos: " << sqlite3_errmsg(db) << endl;
        return (0);
    } else {
        cout << "Se abrio correctamente la base de datos" << endl;
    }

    // Crear tabla

    const char *sql = "CREATE TABLE COMPANY("
                      "ID INT PRIMARY KEY NOT NULL,"
                      "NAME TECT NOT NULL,"
                      "AGE INT NOT NULL,"
                      "ADDRESS CHAR(50),"
                      "SALARY REAL);";
    rc = sqlite3_exec(db, sql, callback, 0, &errMSG);
    if(rc != SQLITE_OK){
        cerr<<"SQL error: " << errMSG << endl;
        sqlite3_free(errMSG);
    }else{
        cout << "Tabla creada correctamente" << endl;
    }
    // Insertar datos en la tabla que se creó
    sql = "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "
          "VALUES (1, 'Paul', 32, 'California', 20000.00);"
          "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "
          "VALUES (2, 'Allen', 25, 'Texas', 15000.00);"
          "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "
          "VALUES (3, 'Teddy', 23, 'Norway', 20000.00);"
          "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "
          "VALUES (4, 'Mark', 25, 'Rich-Mond', 65000.00);" ; 

    rc = sqlite3_exec(db, sql, callback, 0, &errMSG);
    if (rc != SQLITE_OK){
        cerr << "SQL error: " << errMSG << endl; 
        sqlite3_free(errMSG);
    } else{
        cout << "Records created succesfully" << endl; 
    }

    //Selecciona datos de la tabla
    sql = "SELECT * from COMPANY";
    rc = sqlite3_exec(db, sql, callback, (void*)data, &errMSG);
    if (rc != SQLITE_OK){
        cerr << "SQL error: " << errMSG << endl; 
        sqlite3_free(errMSG);
    } else {
        cout << "Operation done succesfully" << endl; 
    }

    //Cierra la base de datos
    sqlite3_close(db);
    return 0; 
}

