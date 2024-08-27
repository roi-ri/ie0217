#include <iostream>
#include "persona.hpp"

using namespace std; 

int main(){
   Persona p("Juean", 25);

    cout << "Nombre: " << p.getNombre() << endl;
    cout << "Edad: " << p.getEdad() << endl;
    p.setEdad(26);

    cout << "Nuema edad: " << p.getEdad() << endl;
   return 0;
}