#include <iostream>

using namespace std;


int main(){

    // Manera implícita 
    //darle un valor entero a num_it

    int num_int = 9;

    //declarar una varuable de tipo double

    double num_double;

    //conversión implícita

    num_double = num_int;

    cout << "num_int = " << num_int << endl;
    cout << "num_double = " << num_double << endl;

    //conversion directa

    //inicializar variable tipo double

    double num_double1 = 3.56;
    cout << "num_double1 = " << num_double1 << endl;

    //C-style conversión de double a integer 

    int num_int1 = (int)num_double1;
    cout << "num_int1 = " << num_int1 << endl;

   //function style conversion de double a integer
    int num_int2 = int(num_double);
    cout << "num_int2 = " << num_int2 << endl;

  
    return 0; 

}