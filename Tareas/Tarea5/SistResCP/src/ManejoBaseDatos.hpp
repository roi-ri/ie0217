#ifndef MANEJOBASEDATOS_HPP
#define MANEJOBASEDATOS_HPP


#include<sqlite3.h>
#include <iostream>
#include <string>

using namespace std; 

void IngresarProfesor(sqlite3*db);

void IngresarCurso(sqlite3*db);

void IngresarResena(sqlite3*db);

void BuscarProfeCE(sqlite3*db); 

void MostrarTopProfes(sqlite3*db); 

void BuscaresenaNoRev(sqlite3*db);

void ActualizarEstadoResena(sqlite3*db); 

void BuscarTopProfe(sqlite3*db); 

void EliminarResena(sqlite3*db);

void ConsultResenaPositiv(sqlite3*db); 






#endif // MANEJO  BASEDATOS_HPP