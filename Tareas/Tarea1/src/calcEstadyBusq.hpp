#include<iostream>
#include <cstdlib> // Se utiliza para poder utilizar la funcion atoi y convertir los string a numero


enum menu{
    MOSTRAR_ESTADISTICAS = 1,
    BUSCAR_ARREGLO,
    SALIR
};

int sumarNumeros(int *numeros, int tamano);
int maxNum(int *numeros, int tamano);
int minNum(int *numeros, int tamano);
double prom(int *numeros, int tamano);

int buscNum(int *numeros, int tamano);

void showMenu();

