#include <iostream>  // especifica la libreria que se está utilizando

using namespace std; // Deja utilizar nombres para objetos y variables de forma standar

int main(){  //inicia la funcion main

    cout<< "Hola mundo estudiantes de IE0217!\n"; // cout es para imprimir una salida, acompañado de <<

    int var1 = 53;
    int var2 = 2;
    int var3 = 2;

    switch (var1){
        case 1: 
            std::cout<< "Case 1! \n";
            break;
        case 2: 
        case 3:
            cout<< "Case Final! \n";
            break;
        default:
            cout<< "Case Default! \n"; 
            break; 


    }

    return 0; 

}



