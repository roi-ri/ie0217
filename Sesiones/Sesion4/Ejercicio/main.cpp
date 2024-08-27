
#include<iostream>
#include "student.hpp"

using namespace std;


int main(){

    // Creo dos objetos estudiante con sus respectivos "marks"
    Student student1(88.0), student2(56.0);

    //llamo a la funcion calcular promedio y le paso los dos estudiantes antes creados
    calculateAverage(student1, student2); 
    
    
    return 0;

}