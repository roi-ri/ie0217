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



