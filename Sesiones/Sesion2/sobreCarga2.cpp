#include <iostream>

using namespace std; 


//Funcion con 2 parametros

void display(int var1, double var2){
    cout << "Integer number: " << var1 << " ";
    cout << "and Double nomber: " << var2 << endl;

}

// funtion with double type single parameter

void display(double var){
    cout << "Integer number: " <<var << endl;

}

int main(){

    int a = 5;
    double b = 5.5;

    //call function with int typr parameter 


    display(a);

    display(b); 

    display(a, b);

}




/*
Ejemplos

invalido: 
void add(int a, int b =3, int c, int d);

invalido:

void add(int a, int b = 3, int c, int d = 4));


valido: 
void add(int a, int c, int b = 3, int d = 4);

codigo invalido: 

int main(){

display();
}

void display(char c = '*', int count = 5){


codigo 


}






*/