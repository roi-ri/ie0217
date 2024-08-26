#include <iostream> 
using namespace std;

class Molde{

    public:
    double largo;
    double ancho; 
    double altura; 

    Molde(double largo_p, double ancho_p, double altura_p) : largo(largo_p), ancho(ancho_p), altura(altura_p) {}        
   //INcluyendo un Destructor
   ~Molde () {
    cout << "Saludos desde el destructor de la clase MOLDE" << endl; 
   }
   
    double calcularArea(){
    return largo * ancho;
    } 

    double calcularVolumen(){
        return largo * ancho * altura;
    }
};


int main(){

    //Instanciar un objeto llamado pared basado en la clase molde
    Molde pared(10.0, 20.0, 35.0); 

    //calcular y desplegar el area y volumen;

    cout << "Area = " << pared.calcularArea() << endl; 
    cout << "Volumen = " << pared.calcularVolumen() << endl;

    return 0;

}