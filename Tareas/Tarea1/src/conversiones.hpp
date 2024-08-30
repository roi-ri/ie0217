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

/**
 * @brief Realiza la conversión de unidades de longitud basándose en los datos de entrada proporcionados.
 *
 * Esta función solicita al usuario la unidad de entrada, la unidad de salida y el número a convertir.
 * Luego, realiza la conversión utilizando la función correspondiente según la unidad de entrada.
 *
 * @param data Un struct de tipo `converDatos` que contiene la unidad de origen, la unidad de salida,
 *             y el número a convertir.
 *
 * @return El resultado de la conversión en la unidad de salida especificada.
 */
double convLongitud(const converDatos &data);
/**
 * @brief Realiza la conversión de unidades de longitud desde metros a otra unidad.
 *
 * Esta función toma como entrada un número en metros y lo convierte a la unidad de
 * longitud especificada por el usuario. Las posibles unidades de salida incluyen
 * kilómetros, centímetros, milímetros, pulgadas y millas.
 *
 * @param salida Una referencia al tipo de unidad de salida deseada.
 * @param numero El número en metros que se desea convertir.
 *
 * @return El resultado de la conversión en la unidad de salida especificada.
 */
double convMetro(string &salida, double &numero);
/**
 * @brief Realiza la conversión de unidades de longitud desde centímetros a otra unidad.
 *
 * Esta función toma como entrada un número en centímetros y lo convierte a la unidad de
 * longitud especificada por el usuario. Las posibles unidades de salida incluyen
 * metros, kilómetros, milímetros, pulgadas y millas.
 *
 * @param salida Una referencia al tipo de unidad de salida deseada.
 * @param numero El número en centímetros que se desea convertir.
 *
 * @return El resultado de la conversión en la unidad de salida especificada.
 */
double convCenti(string &salida, double &numero);
/**
 * @brief Realiza la conversión de unidades de longitud desde kilómetros a otra unidad.
 *
 * Esta función toma como entrada un número en kilómetros y lo convierte a la unidad de
 * longitud especificada por el usuario. Las posibles unidades de salida incluyen
 * metros, centímetros, milímetros, pulgadas y millas.
 *
 * @param salida Una referencia al tipo de unidad de salida deseada.
 * @param numero El número en kilómetros que se desea convertir.
 *
 * @return El resultado de la conversión en la unidad de salida especificada.
 */
double convKilom(string &salida, double &numero);
/**
 * @brief Realiza la conversión de unidades de longitud desde milímetros a otra unidad.
 *
 * Esta función toma como entrada un número en milímetros y lo convierte a la unidad de
 * longitud especificada por el usuario. Las posibles unidades de salida incluyen
 * metros, centímetros, kilómetros, pulgadas y millas.
 *
 * @param salida Una referencia al tipo de unidad de salida deseada.
 * @param numero El número en milímetros que se desea convertir.
 *
 * @return El resultado de la conversión en la unidad de salida especificada.
 */
double convMilim(string &salida, double &numero);
/**
 * @brief Realiza la conversión de unidades de longitud desde pulgadas a otra unidad.
 *
 * Esta función toma como entrada un número en pulgadas y lo convierte a la unidad de
 * longitud especificada por el usuario. Las posibles unidades de salida incluyen
 * metros, centímetros, kilómetros, milímetros y millas.
 *
 * @param salida Una referencia al tipo de unidad de salida deseada.
 * @param numero El número en pulgadas que se desea convertir.
 *
 * @return El resultado de la conversión en la unidad de salida especificada.
 */
double convPulga(string &salida, double &numero);
/**
 * @brief Realiza la conversión de unidades de longitud desde millas a otra unidad.
 *
 * Esta función toma como entrada un número en millas y lo convierte a la unidad de
 * longitud especificada por el usuario. Las posibles unidades de salida incluyen
 * metros, centímetros, kilómetros, milímetros y pulgadas.
 *
 * @param salida Una referencia al tipo de unidad de salida deseada.
 * @param numero El número en millas que se desea convertir.
 *
 * @return El resultado de la conversión en la unidad de salida especificada.
 */
double convMill(string &salida, double &numero);
/**
 * @brief Convierte un valor de peso de una unidad a otra.
 * 
 * @param data Estructura `converDatos` que contiene la unidad de origen, la unidad de salida, y el valor a convertir.
 * @return double El valor convertido en la unidad de salida.
 */
double convPeso(const converDatos &data);
/**
 * @brief Convierte un valor de temperatura de una unidad a otra.
 * 
 * @param data Estructura `converDatos` que contiene la unidad de origen, la unidad de salida, y el valor a convertir.
 * @return double El valor convertido en la unidad de salida.
 */
double convTemperatura(const converDatos &data);
/**
 * @brief Realiza la conversión de unidades de peso desde libras a otra unidad.
 *
 * Esta función toma como entrada un número en libras y lo convierte a la unidad de
 * peso especificada por el usuario. Las posibles unidades de salida incluyen
 * kilogramos, gramos, toneladas y onzas.
 *
 * @param salida Una referencia al tipo de unidad de salida deseada.
 * @param numero El número en libras que se desea convertir.
 *
 * @return El resultado de la conversión en la unidad de salida especificada.
 */

double convKilo(string &salida, double &numero);
/**
 * @brief Realiza la conversión de unidades de peso desde gramos a otra unidad.
 *
 * Esta función toma como entrada un número en gramos y lo convierte a la unidad de
 * peso especificada por el usuario. Las posibles unidades de salida incluyen
 * kilogramos, libras, toneladas y onzas.
 *
 * @param salida Una referencia al tipo de unidad de salida deseada.
 * @param numero El número en gramos que se desea convertir.
 *
 * @return El resultado de la conversión en la unidad de salida especificada.
 */
double convLibr(string &salida, double &numero);
/**
 * @brief Realiza la conversión de unidades de peso desde gramos a otra unidad.
 *
 * Esta función toma como entrada un número en gramos y lo convierte a la unidad de
 * peso especificada por el usuario. Las posibles unidades de salida incluyen
 * kilogramos, libras, toneladas y onzas.
 *
 * @param salida Una referencia al tipo de unidad de salida deseada.
 * @param numero El número en gramos que se desea convertir.
 *
 * @return El resultado de la conversión en la unidad de salida especificada.
 */
double convGram( string &salida, double &numero);
/**
 * @brief Realiza la conversión de unidades de peso desde toneladas a otra unidad.
 *
 * Esta función toma como entrada un número en toneladas y lo convierte a la unidad de
 * peso especificada por el usuario. Las posibles unidades de salida incluyen
 * kilogramos, libras, gramos y onzas.
 *
 * @param salida Una referencia al tipo de unidad de salida deseada.
 * @param numero El número en toneladas que se desea convertir.
 *
 * @return El resultado de la conversión en la unidad de salida especificada.
 */
double convTonel( string &salida, double &numero);
/**
 * @brief Realiza la conversión de unidades de peso desde onzas a otra unidad.
 *
 * Esta función toma como entrada un número en onzas y lo convierte a la unidad de
 * peso especificada por el usuario. Las posibles unidades de salida incluyen
 * kilogramos, libras, gramos y toneladas.
 *
 * @param salida Una referencia al tipo de unidad de salida deseada.
 * @param numero El número en onzas que se desea convertir.
 *
 * @return El resultado de la conversión en la unidad de salida especificada.
 */
double convOnz( string &salida, double &numero);

/**
 * @brief Convierte una temperatura desde Kelvin a otra unidad especificada.
 * 
 * @param salida La unidad de salida a la que se convertirá la temperatura.
 * @param numero El valor de la temperatura en Kelvin a convertir.
 * @return double El valor convertido en la unidad de salida especificada.
 */
double convKel( string &salida, double &numero);
/**
 * @brief Convierte una temperatura desde Fahrenheit a otra unidad especificada.
 * 
 * @param salida La unidad de salida a la que se convertirá la temperatura.
 * @param numero El valor de la temperatura en Fahrenheit a convertir.
 * @return double El valor convertido en la unidad de salida especificada.
 */
double convFar( string &salida, double &numero);
/**
 * @brief Convierte una temperatura desde Celsius a otra unidad especificada.
 * 
 * @param salida La unidad de salida a la que se convertirá la temperatura.
 * @param numero El valor de la temperatura en Celsius a convertir.
 * @return double El valor convertido en la unidad de salida especificada.
 */
double convCel( string &salida, double &numero);
/**
 * @brief Muestra el menú principal para la selección del tipo de conversión.
 *
 * Esta función imprime en la consola las opciones disponibles en el menú principal
 * para que el usuario seleccione el tipo de conversión que desea realizar. 
 * Las opciones incluyen conversión de longitud, peso, temperatura o salir del programa.
 */
void showMenu();



#endif //CONVERCIONES_HPP
