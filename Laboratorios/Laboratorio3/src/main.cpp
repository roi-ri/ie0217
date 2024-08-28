#include <iostream>
#include <vector> 

#include "EmpleadoMedioTiempo.hpp"
#include "empleadoTiempoCompleto.hpp"


using namespace std;

int main() {

    // Vector que almacena punteros a objetos de tipo Empleado
    vector<Empleado*> empleados;
    // Agrega empleados de diferentes tipos al vector
    empleados.push_back(new EmpleadoTiempoCompleto("Alice", 1, 50000, 5000, 1000));
    empleados.push_back(new EmpleadoMedioTiempo("Bob", 2, 20, 120));
    empleados.push_back(new EmpleadoTiempoCompleto("Charlie", 3, 55000, 4000, 1500));
    empleados.push_back(new EmpleadoMedioTiempo("David", 4, 25, 100));
    empleados.push_back(new EmpleadoTiempoCompleto("Esteban", 10, 150000, 9000, 60000));

    // Recorre el vector e imprime la información de cada empleado
    for (const auto& empleado: empleados){
        empleado->mostrarInformacion();

    }

     // Libera la memoria asignada a cada objeto empleado
    for (const auto& empleado : empleados){

        delete empleado;
    }
    return 0; //Fin del programa
}
