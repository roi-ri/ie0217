#include "calcEstadyBusq.hpp"
using namespace std;

int sumarNumeros(int *numeros, int tamano){
    int suma = 0;
    for (int i  = 0; i < tamano; i++){
        suma += numeros[i];
    }
    return suma;
}
int maxNum(int *numeros, int tamano){
    int max = numeros[0];
    for (int i = 0 ; i < tamano; i++){
        if (numeros[i] > max){
            max = numeros[i];
        }
    }
    return max;

}

int minNum(int *numeros, int tamano){
    int min = numeros[0];
    for (int i = 0; i < tamano; i++){
        if (numeros[i] < min){
            min = numeros[i];
        }
    }
    return min;  
}
double prom(int *numeros, int tamano){
    int suma = 0;
    for (int i  = 0; i < tamano; i++){
        suma += numeros[i];
    }
    return static_cast<double>(suma) / tamano;
}

int buscNum(int *numeros, int tamano) {
    int numBusc;
    cout << "Ingrese el número a buscar: ";
    cin >> numBusc;

    for (int i = 0; i < tamano; i++) {
        if (numeros[i] == numBusc) {
            return i + 1;  // Retorna la posición (basada en 1)
        }
    }

    return -1;  // Retorna -1 si no encuentra el número
}

void showMenu(){
    cout << "Bienvenido al programa de cálculo de estadísticas y buscador de datos " << endl;
    cout << "1. Mostrar Estadísticas." << endl;
    cout << "2. Buscar un número." << endl; 
    cout << "3. Salir del programa." << endl;
}


