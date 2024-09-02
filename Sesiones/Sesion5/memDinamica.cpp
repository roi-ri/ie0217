#include<iostream>
using namespace std;

int main(){
    // declarar variable puntero entero
    int* pointInt;

    // declarar variable puntero float
    float* pointFloat;

    // Alocar memoria dinamica
    pointInt = new int;
    pointFloat = new float;


    // Asignar valores a las variables
    *pointInt = 45;
    *pointFloat = 45.45f;

    // Mostrar los valores de las variables
    cout << "Valor de la variable int: " << *pointInt << endl;
    cout << "Valor de la variable float: " << *pointFloat << endl;

    // Liberar la memoria dinamica
    delete pointInt;
    delete pointFloat;

    return 0;
}