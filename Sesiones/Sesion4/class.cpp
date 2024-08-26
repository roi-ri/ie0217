#include <iostream> 
using namespace std;

class Molde{

    public:
    double largo;
    double ancho; 
    double altura; 

    Molde(){
        cout << "ESto se ejecuta en cada instanciacion" << endl;
        cout << "Iniciando un objeto de la clase Room" << endl; 

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
    Molde pared; 

    // Asignar calores al objeto pared
    pared.largo = 400.5;
    pared.ancho = 20.8;
    pared.altura = 315.2;

    //calcular y desplegar el area y volumen;

    cout << "Area = " << pared.calcularArea() << endl; 
    cout << "Volumen = " << pared.calcularVolumen() << endl;

    return 0;

}