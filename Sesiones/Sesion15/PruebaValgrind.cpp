#include<iostream> 

using namespace std;

void funcion1(){
    int* p =new int[10]; //Se pierde memoria pq esta no está siendo liberada
    cout << p[0] << endl; // NO se inicializo esta memoria 

    int array[5];
    array[5] = 10; //Acceso a un elemento fuera de los limnites del array
}


int main(){
    funcion1();
    return 0; 
}