#include "EmpleadoMedioTiempo.hpp"


using namespace std;

/*
Constructor de la clase EmpleadoMedioTiempo
Inicializa el nombre, ID, tarifa por hora y horas trabajadas del empleado de medio tiempo.
Parámetros:
nombre: El nombre del empleado.
tarifaPorHora: La tarifa por hora del empleado de medio tiempo.
horasTrabajadas: El número de horas trabajadas por el empleado.
id: El identificador del empleado.
*/
EmpleadoMedioTiempo::EmpleadoMedioTiempo(const string &nombre, int id, double tarifaPorHora, int horasTrabajadas) : Empleado(nombre, id, tarifaPorHora * horasTrabajadas), tarifaPorHora(tarifaPorHora), horasTrabajadas(horasTrabajadas){}

// Establece el número de horas trabajadas por el empleado.
void EmpleadoMedioTiempo::setHorasTrabajadas(int horas){
    this->horasTrabajadas = horas;
}

// Establece la tarifa por hora del empleado.
void EmpleadoMedioTiempo::setTarifaPorHora(double tarifa){
    this->tarifaPorHora = tarifa;
}
// Devuelve el salario del empleado de medio tiempo, calculado como la tarifa por hora multiplicada por las horas trabajadas.
double EmpleadoMedioTiempo::getSalario() const{
    return tarifaPorHora * horasTrabajadas;

}

/*
Muestra la información del empleado de medio tiempo, incluyendo el nombre, ID, salario, horas trabajadas y tarifa por hora.
Utiliza la sobrecarga del operador << para mostrar la información básica del empleado.
Retorno:
La información del empleado se imprime en la salida estándar.
*/


void EmpleadoMedioTiempo::mostrarInformacion() const{
    cout << *this << ", Horas Trabajadas: " << horasTrabajadas << "Tarifa por Hora: " << tarifaPorHora << endl; 


}
