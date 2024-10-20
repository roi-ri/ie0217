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

void BuscarresenaNoRev(sqlite3*db);

void ActualizarEstadoResena(sqlite3*db); 

void BuscarTopProfe(sqlite3*db); 

void EliminarResena(sqlite3*db);

void ImprimirTablas(sqlite3*db); 
// quiero mostrar de alguna manera los datos que se tienen en la base de datos para asi poder ver ids







#endif // MANEJO  BASEDATOS_HPP