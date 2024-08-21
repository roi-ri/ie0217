#include <iostream>

using namespace std; 

/*

Dos funciones pueden tener el mismo nombre si el numero y/o tipos de argumentos pasados es diferente.

Conocidas como funciones sobrecargadas

*/


int test(){}
int test (int a){}
int test (double a) {}
int test (int a, double b) {}

//Codigo de error

int test(int a){}
// Daría error --> double test(int b){}


//Otro ejenmplo de sobrecarga de funciones: 

//funcion con float type parameter

float absolute(float var){
    if (var < 0.0)
    var = -var;
    return var;
}

//funcion con parametro int

int absolute (int var){
    if (var < 0)
    var = -var;
    return var;
}


int main(){
    //call function with int type parameter 
    cout << "Absolute value of -5 = " << absolute(-5) << endl;

    //call function with float type parameter

   // Tira error se esta sobrecargando la funcion--> cout << "Absolut alue of 5.5 = " << absolute(5.5) << endl;
    return 0;
}






