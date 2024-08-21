#include <iostream> 
using namespace std;

//funcion para intercambiar valores 

void swap(int &n1, int &n2){
    int temp; 
    temp = n1;
    n1 = n2;
    n2 = temp; 
}


void swap2(int* n1, int* n2){
    int temp; 
    temp = *n1;
    *n1 = *n2;
    *n2 = temp; 
}

int main(){
    //paso de dos parametros por referencia sin puntero
    int a =1, b=2;

    cout << "before swaping" << endl; 

    cout << "a = "<< a << endl; 

    cout << "b = "<< b << endl; 

    swap(a, b); 

    cout << "after swaping" << endl;

    //paso de datos con punteros

    int a = 1, b =2; 
    cout << "Antes de intercambiar"<<endl; 

    cout << 'a = ' << a << endl; 
    cout << 'b = ' << b << endl; 

    //llamar a la funcion pasandole los address de las variables

   // cout <<"&a = " , &a << endl; 
    // cout <<"&b = " , &b << endl; 

    swap2(&a, &b); 

    cout << "Despues de intercambiar"<<endl;
     cout << 'a = ' << a << endl; 
    cout << 'b = ' << b << endl;

    return 0;
    
    }