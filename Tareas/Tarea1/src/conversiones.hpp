#ifndef CONVERCIONES_HPP
#define CONVERCIONES_HPP
#include <iostream>
#include <string>

using namespace std;

// Creacion del interior del enum menu
enum menu{
    CONVERTIR_LONGITUD = 1,
    CONVERTIR_PESO,
    CONVERTIR_TEMPERATURA,
    SALIR
};
// Definicion del struct datos
struct converDatos{
    string unidadOrigen;
    string unidadSalida;
    double numeroConver;
};
// Firmado de las funcoines usadas en el programa

void mostrarMenu();
double convLongitud(const converDatos &data);
double convMetro(string &salida, double &numero);
double convCenti(string &salida, double &numero);
double convKilom(string &salida, double &numero);
double convMilim(string &salida, double &numero);
double convPulga(string &salida, double &numero);
double convMill(string &salida, double &numero);
double convPeso(const converDatos &data);
double convTemperatura(const converDatos &data);
double convKilo(string &salida, double &numero);
double convLibr(string &salida, double &numero);
double convGram( string &salida, double &numero);
double convTonel( string &salida, double &numero);
double convOnz( string &salida, double &numero);
double convKel( string &salida, double &numero);
double convFar( string &salida, double &numero);
double convCel( string &salida, double &numero);
void showMenu();



#endif //CONVERCIONES_HPP
