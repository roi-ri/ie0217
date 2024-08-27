#ifndef PERSONA_H
#define PERSONA_H

#include <string>

using namespace std;

class Persona {
    private: 
        string name;
        int edad; 


    public:  
        Persona(string nombre, int edad);
        string getNombre();
        int getEdad();
        void setEdad(int edad);

};

#endif // PERSONA_H