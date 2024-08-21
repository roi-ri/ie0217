#include <iostream> 
 using namespace std;


 int main (){
    int var = 5; 


    //Declarar puntero variable

    int* pointVar;

    //Guardar la direccion de var

    pointVar = &var;


//Imprimir el valor de var 
    cout << "var = " , var;

// Print adrees de var
    cout << "Adress of var (&var) = " << &var << endl;

//Imprimir el puntero 

    cout << "pointVar = " , pointVar;

// Imprimir el contenido de la direccion de poinVar 

cout << "Content of the adress pointed to by pintVar (*pointVar) = " << *pointVar << endl;

return 0;

 }

 //Punteros y estructuras

 struct temp {
    int i;
    float f; 
 };

struct Distance {
    int feet;
    int inch;

};




 int main(){
    temp *ptr; 

 }

