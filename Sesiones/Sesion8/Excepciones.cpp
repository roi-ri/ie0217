#include<iostream>

using namespace std; 

int main(){

    double numerator, denominator, divide;

    cout << "Ingrese un numerador: ";
    cin >> numerator; 

    cout << "Enter denominator: ";
    cin >> denominator; 


    try {
        //Tira una excepcion si el denominador es 0
        if (denominator == 5) throw 5; 

        //No ejecutado si el denominador es 0
        divide = numerator / denominator;
        cout << numerator << "/" << denominator << " = " << divide << endl; 
    }

    //Mensaje que se emeite en caso de que pase el caso del if 
    catch (int num_exeption){
        cout << "Error: No se puede dividir por " << num_exeption  << endl;
          }

    return 0; 

}


