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

#include "calcEstadyBusq.hpp"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    // Imprimir la manera de uso por si el usuario no sabe cómo ingresar los datos
    if (argc < 2) {
        cout << "Uso: " << argv[0] << " <numero1> <numero2> ... " << endl;
        return 1;
    }

    // Crear arreglo dinámico para almacenar los números
    int *numeros = new int[argc - 1]; 
    int tamano = argc - 1;

    for (int i = 1; i < argc; i++) {
        numeros[i-1] = atoi(argv[i]);
        // Validar que los números sean enteros (ya manejado por atoi)
    }

    int option;
    do {
        showMenu();
        cout << "Elija una opción: ";
        cin >> option;

        switch(option) {
            case MOSTRAR_ESTADISTICAS:
                cout << "La suma de los números es: " << sumarNumeros(numeros, tamano) << endl;
                cout << "El valor máximo es: " << maxNum(numeros, tamano) << endl;
                cout << "El valor mínimo es: " << minNum(numeros, tamano) << endl;
                cout << "El promedio es: " << prom(numeros, tamano) << endl;
                break;
            case BUSCAR_ARREGLO: {
                int posicion = buscNum(numeros, tamano);
                if (posicion != -1) {
                    cout << "El número fue encontrado en la posición: " << posicion << endl;
                } else {
                    cout << "El número no fue encontrado en el arreglo." << endl;
                }
                break;
            }
        }     
    } while(option != SALIR);

    // Liberar memoria dinámica
    delete[] numeros;

    return 0;
}