/*
 * MIT License
 * 
 * Copyright (c) 2024 [Rodrigo Sánchez, UNiversidad de Costa Rica]
 * 
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include<iostream>
#include <cstdlib> // Se utiliza para poder utilizar la funcion atoi y convertir los string a numero


enum menu{
    MOSTRAR_ESTADISTICAS = 1,
    BUSCAR_ARREGLO,
    SALIR
};


/**
 * @brief Suma todos los números en un arreglo.
 *
 * Esta función toma un puntero a un arreglo de enteros y su tamaño, 
 * y devuelve la suma de todos los elementos del arreglo.
 *
 * @param numeros Puntero al arreglo de enteros que contiene los números a sumar.
 * @param tamano Tamaño del arreglo de enteros.
 *
 * @return La suma de todos los números en el arreglo.
 */

int sumarNumeros(int *numeros, int tamano);


/**
 * @brief Encuentra el valor máximo en un arreglo de enteros.
 *
 * Esta función toma un puntero a un arreglo de enteros y su tamaño,
 * y devuelve el valor máximo encontrado en el arreglo.
 *
 * @param numeros Puntero al arreglo de enteros en el que se buscará el valor máximo.
 * @param tamano Tamaño del arreglo de enteros.
 *
 * @return El valor máximo en el arreglo de enteros.
 */

int maxNum(int *numeros, int tamano);

/**
 * @brief Encuentra el valor mínimo en un arreglo de enteros.
 *
 * Esta función toma un puntero a un arreglo de enteros y su tamaño,
 * y devuelve el valor mínimo encontrado en el arreglo.
 *
 * @param numeros Puntero al arreglo de enteros en el que se buscará el valor mínimo.
 * @param tamano Tamaño del arreglo de enteros.
 *
 * @return El valor mínimo en el arreglo de enteros.
 */

int minNum(int *numeros, int tamano);

/**
 * @brief Calcula el promedio de los números en un arreglo de enteros.
 *
 * Esta función toma un puntero a un arreglo de enteros y su tamaño,
 * calcula la suma de todos los elementos del arreglo, y luego devuelve
 * el promedio de los números. La suma se convierte a tipo `double` para
 * obtener un resultado más preciso en caso de que el promedio no sea un
 * número entero.
 *
 * @param numeros Puntero al arreglo de enteros del cual se calculará el promedio.
 * @param tamano Tamaño del arreglo de enteros.
 *
 * @return El promedio de los números en el arreglo, como un valor de tipo `double`.
 */

double prom(int *numeros, int tamano);

/**
 * @brief Busca un número en un arreglo de enteros.
 *
 * Esta función solicita al usuario que ingrese un número y lo busca en el arreglo
 * de enteros proporcionado. La función retorna la posición del número encontrado
 * (basada en 1), o -1 si el número no se encuentra en el arreglo.
 *
 * @param numeros Puntero al arreglo de enteros en el que se buscará el número.
 * @param tamano Tamaño del arreglo de enteros.
 *
 * @return La posición del número en el arreglo (basada en 1) si se encuentra,
 *         o -1 si el número no está en el arreglo.
 */

int buscNum(int *numeros, int tamano);

/**
 * @brief Muestra el menú principal del programa.
 *
 * Esta función imprime en la consola las opciones disponibles en el menú principal
 * del programa. Las opciones incluyen mostrar estadísticas, buscar un número, y 
 * salir del programa.
 */

void showMenu();

