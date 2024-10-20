#ifndef DATABASE_HPP
#define DATABASE_HPP


#include<sqlite3.h>
#include <iostream>
#include <string>


using namespace std; 



void createTables(sqlite3* db);


void check_sqlite_error(int result_doe, const char* error_message); 

void closeDatabase(sqlite3* db); 

static int callback(void *data, int argc, char **argv, char **azColName);


#endif // DATABASE_HPP