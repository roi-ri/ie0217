#ifndef EMPLEADO_HPP
#define EMPLEADO_HPP

#include<iostream>
#include<string>
using namespace std;


class Empleado{
    protected: //desde la misma clase y desde clases derivadas
         string nombre;
         int id; 
         double salario;


    public:
        Empleado(const string &nombre, int id, double salario);

        virtual ~Empleado() = default; //Se debe utilizar una implementacion que el compilador ya tiene para esto de modo default

        void setNombre(const string &nombre);
        string getNombre() const; //Metodos que no van a modificar el estado del elemento como tal, no altera nada que caracterice las caracteristicas del objeto como tal


        void setId(int id);
        int getId() const;

        void setSalario(double salario);
        virtual double getSalario() const;

        friend bool compararSalario(const Empleado &e1, const Empleado &e2);

        friend ostream& operator<<(ostream &os, const Empleado &empleado); //sobre escribir el elemento << para que funcione a como se quiere a la hora de usarlo en la funcion


        virtual void mostrarInformacion() const = 0; //convierte a este metodo en un vitual puro "=0" no tiene implementacion en la clase base. SI o Si tiene que estar en la implementacion de las clases que lo hereden 

        //Ahora la clase se llama como clase abstracta --> al menos un metodo virtual puro
        // Yo no puedo crear ningun objeto basado en esta clase 
        //quienes hereden de esta clase deben de realizar su propia implementacion 
        //Una clase para que otra clase se cree basada en ella
};


#endif //EMPLEADO_HPP