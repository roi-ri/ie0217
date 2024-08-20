#include <iostream>

using namespace std;


int main(){
    // --> primera funcion 
    for (int i = 1; i <= 5; i++){
        cout << i << " ";
    }
    cout << "\n"; //se agrega para hacer la salida mas legible
    // salida de la forma: 1 2 3 4 5

    // --> Segunda funcion
    int num_array[] = {1,2,3,4,5,6,7,8,9,10};

    for (int n : num_array) {
        cout << n << " ";
    }
    cout << "\n";//se agrega para hacer la salida mas legible
    //Salida esperada: 1 2 3 4 5 6 7 8 9 10

    // --> Tercera funcion
    int i = 1; 

    //while loop from 1 to 5
    while (i <=5){
        cout << i << " ";
        i++;
    }
    // salida de la forma: 1 2 3 4 5
    cout << "\n";//se agrega para hacer la salida mas legible


    // -->  Cuarta funcion

    int j = 1;

    // do...while loop from 1 to 5

    do {
        cout << j << " ";
        j++;
    }

    while (j <= 5);

    // salida de la forma: 1 2 3 4 5
    cout << "\n";//se agrega para hacer la salida mas legible
    return 0;
}
