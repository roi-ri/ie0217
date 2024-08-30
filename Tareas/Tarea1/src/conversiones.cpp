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
#include "conversiones.hpp"

using namespace std;


//funcion menu
void mostrarMenu(){
    cout << "Bienvenido al programa de conversión de datos\n\nFavor ingrese la opción del tipo de conversión que desea realizar:" << endl;
    cout << "1. Realizar una conversión de longitud." << endl;
    cout << "2. Realizar una conversión de peso." << endl;
    cout << "3. Realizar una conversión de temperatura." << endl; 
    cout << "4. Salir del programa." << endl;
};
// Esta funcion se va a utilizar cuando entrada == METROS
double convMetro(string &salida, double &numero){
    if (salida == "METROS"){
        cout << "No hay conversión que hacer, el dato es:" << numero << "m" << endl;
    } else if (salida == "KILOMETROS"){
        cout << "La conversión de metros a kilómetros da como resultado: " << (numero / 1000) << "Km" << endl;
    } else if (salida == "CENTIMETROS"){
        cout << "La conversión de metros a centímetro da como resultado: " << (numero * 100) << "cm" << endl;
    } else if (salida == "MILIMETROS"){
        cout << "La conversión de metros a milímetro da como resultado: " << (numero * 1000) << "mm" << endl;
    } else if (salida == "PULGADA"){
        cout << "La conversión de metros a pulgadas da como resultado: " << (numero * 39.37) << "in" << endl;
    } else if (salida == "MILLA"){
        cout << "La conversión de metros a millas da como resultado: " << (numero / 1609) << "Mil" << endl;
    };
};
// Esta funcion se utiliza cuando entrada == CENTIMETROS
double convCenti(string &salida, double &numero){
    if (salida == "CENTIMETROS"){
        cout << "No hay conversión que hacer, el dato es:" << numero << "cm" << endl;
    } else if (salida == "METROS"){
        cout << "La conversión de centîmetros a metros da como resultado: " << (numero / 100) << "m" << endl;
    } else if (salida == "KILOMETROS"){
        cout << "La conversión de centîmetros a kilónmetros da como resultado: " << (numero / 10000) << "km" << endl;
    } else if (salida == "MILIMETROS"){
        cout << "La conversión de centîmetros a milímetros da como resultado: " << (numero * 10) << "mm" << endl;
    } else if (salida == "PULGADA"){
        cout << "La conversión de centîmetros a pulgadas da como resultado: " << (numero / 2.54) << "in" << endl;
    } else if (salida == "MILLA"){
        cout << "La conversión de centîmetros a millas da como resultado: " << (numero / 160900) << "Mil" << endl;
    };
}
// Esta funcion se va a utilizar para entrada == KILOMETRO
double convKilom(string &salida, double &numero){
    if (salida == "KILOMETRO"){
        cout << "No hay conversión que hacer, el dato es:" << numero << "Km" << endl;
    } else if (salida == "METROS"){
        cout << "La conversión de kilómetros a metros da como resultado: " << (numero * 1000) << "m" << endl;
    } else if (salida == "CENTIMETROS"){
        cout << "La conversión de kilómetros a centímetros da como resultado: " << (numero * 100000) << "cm" << endl;
    } else if (salida == "MILIMETROS"){
        cout << "La conversión de kilómetros a milímetros da como resultado: " << (numero * 1000000) << "mm" << endl;
    } else if (salida == "PULGADA"){
        cout << "La conversión de kilómetros a pulgadas da como resultado: " << (numero * 39370) << "in" << endl;
    } else if (salida == "MILLA"){
        cout << "La conversión de kilómetros a millas da como resultado: " << (numero / 1.609) << "Mil" << endl;
    };
}
// Esta funcion se va a utilizar para entrada == MILIMETROS
double convMilim(string &salida, double &numero){
     if (salida == "MILIMETROS"){
        cout << "No hay conversión que hacer, el dato es:" << numero << "mm" << endl;
    } else if (salida == "METROS"){
        cout << "La conversión de milímetros a metros da como resultado: " << (numero / 1000) << "m" << endl;
    } else if (salida == "CENTIMETROS"){
        cout << "La conversión de milímetros a centímetros da como resultado: " << (numero / 10) << "cm" << endl;
    } else if (salida == "KILOMETRO"){
        cout << "La conversión de milímetros a kilómetros da como resultado: " << (numero / 1000000) << "km" << endl;
    } else if (salida == "PULGADA"){
        cout << "La conversión de milímetros a pulgadas da como resultado: " << (numero / 25.4) << "in" << endl;
    } else if (salida == "MILLA"){
        cout << "La conversión de milímetros a millas da como resultado: " << (numero / 1609000000) << "Mil" << endl;
    };
}
// Esta funcion se va a utilizar para entrada == PULGADA
double convPulga(string &salida, double &numero){
    if (salida == "PULGADA"){
        cout << "No hay conversión que hacer, el dato es:" << numero << "in" << endl;
    } else if (salida == "METROS"){
        cout << "La conversión de pulgadas a metros da como resultado: " << (numero / 39.37) << "m" << endl;
    } else if (salida == "CENTIMETROS"){
        cout << "La conversión de pulgadas a centímetros da como resultado: " << (numero * 2.54) << "cm" << endl;
    } else if (salida == "KILOMETRO"){
        cout << "La conversión de pulgadas a kilómetros da como resultado: " << (numero / 39370) << "km" << endl;
    } else if (salida == "PULGADA"){
        cout << "La conversión de pulgadas a milímetros da como resultado: " << (numero * 25.4) << "mm" << endl;
    } else if (salida == "MILLA"){
        cout << "La conversión de pulgadas a millas da como resultado: " << (numero / 63369) << "Mil" << endl;
    };
}
// Esta funcion se va a utilizar para entrada == MILLA
double convMill(string &salida, double &numero){
    if (salida == "MILLA"){
        cout << "No hay conversión que hacer, el dato es:" << numero << "Mil" << endl;
    } else if (salida == "METROS"){
        cout << "La conversión de millas a metros da como resultado: " << (numero * 1609) << "m" << endl;
    } else if (salida == "CENTIMETROS"){
        cout << "La conversión de millas a centímetros da como resultado: " << (numero * 160900) << "cm" << endl;
    } else if (salida == "KILOMETRO"){
        cout << "La conversión de millas a kilómetros da como resultado: " << (numero * 1.609) << "km" << endl;
    } else if (salida == "PULGADA"){
        cout << "La conversión de millas a milímetros da como resultado: " << (numero * 1609000000) << "mm" << endl;
    } else if (salida == "MILLA"){
        cout << "La conversión de millas a pulgadas da como resultado: " << (numero / 63360) << "in" << endl;
    };
}
// implementacion de funcion de longitud
double convLongitud(const converDatos &data){
    converDatos d;
    cout << "Ingrese una unidad de entrada: \nOpciones posibles (METROS, KILOMETROS, CENTIMETRO, MILIMETROS, PULGADA, MILLA): "; 
    cin >> d.unidadOrigen;
    cout << "Ingrese el número de la opción de salida:\nOpciones posibles (METROS, KILOMETROS, CENTIMETRO, MILIMETROS, PULGADA, MILLA): ";
    cin >> d.unidadSalida;
    cout << "Ingrese el número sobre el que desea realizar la conversión: "; 
    cin >> d.numeroConver;


    if (d.unidadOrigen == "METROS"){
        convMetro(d.unidadSalida, d.numeroConver);
    }else if (d.unidadOrigen == "KILOMETROS"){
        convKilom(d.unidadSalida, d.numeroConver);
    } else if (d.unidadOrigen == "CENTIMETROS"){
        convCenti(d.unidadSalida, d.numeroConver);
    } else if (d.unidadOrigen == "MILIMETROS"){
        convMilim(d.unidadSalida, d.numeroConver);
    } else if (d.unidadOrigen == "PULGADA"){
        convPulga(d.unidadSalida, d.numeroConver);
    } else if (d.unidadOrigen == "MILLA"){
        convMill(d.unidadSalida, d.numeroConver);
    }else {
        return 0;
    }

};

// quiero kilo, libra, gramo, tonelada, onza

// Conv si entrada == "KILO"
double convKilo(string &salida, double &numero){
    if (salida == "KILO"){
        cout << "No hay conversión que hacer, el dato es:" << numero << "kg" << endl;
    } else if (salida == "LIBRA"){
        cout << "La conversión de kilogramos a libras da como resultado: " << (numero * 2.205) << "lb" << endl;
    } else if (salida == "GRAMO"){
        cout << "La conversión de kilogramos a gramos da como resultado: " << (numero * 1000) << "g" << endl;
    } else if (salida == "TONELADA"){
        cout << "La conversión de kilogramos a toneladas da como resultado: " << (numero / 1000) << "Tm" << endl;
    } else if (salida == "ONZA"){
        cout << "La conversión de kilogramos a onzas da como resultado: " << (numero * 35.274) << "oz" << endl;
    }
};
// Si entrada == "LIBRA"
double convLibr(string &salida, double &numero){
    if (salida == "LIBRA"){
        cout << "No hay conversión que hacer, el dato es:" << numero << "lb" << endl;
    } else if (salida == "KILO"){
        cout << "La conversión de libras a kilogramos da como resultado: " << (numero / 2.205) << "kg" << endl;
    } else if (salida == "GRAMO"){
        cout << "La conversión de libras a gramos da como resultado: " << (numero * 453.6) << "g" << endl;
    } else if (salida == "TONELADA"){
        cout << "La conversión de libras a toneladas da como resultado: " << (numero / 2205) << "Tm" << endl;
    } else if (salida == "ONZA"){
        cout << "La conversión de libras a onzas da como resultado: " << (numero * 16) << "oz" << endl;
    }
};
// Si entrada == "GRAMO"
double convGram(string &salida, double &numero){
    if (salida == "GRAMO"){
        cout << "No hay conversión que hacer, el dato es:" << numero << "g" << endl;
    } else if (salida == "KILO"){
        cout << "La conversión de gramos a kilogramos da como resultado: " << (numero / 1000) << "kg" << endl;
    } else if (salida == "LIBRA"){
        cout << "La conversión de gramos a libras da como resultado: " << (numero / 453.6) << "lb" << endl;
    } else if (salida == "TONELADA"){
        cout << "La conversión de gramos a toneladas da como resultado: " << (numero / 1000000) << "Tm" << endl;
    } else if (salida == "ONZA"){
        cout << "La conversión de gramos a onzas da como resultado: " << (numero / 28.35) << "oz" << endl;
    }
};

// Si entrada == '"TONELADA"
double convTonel(string &salida, double &numero){
    if (salida == "TONELADA"){
        cout << "No hay conversión que hacer, el dato es:" << numero << "Tm" << endl;
    } else if (salida == "KILO"){
        cout << "La conversión de toneladas a kilogramo da como resultado: " << (numero * 1000) << "kg" << endl;
    } else if (salida == "LIBRA"){
        cout << "La conversión de toneladas a libras da como resultado: " << (numero * 2205) << "lb" << endl;
    } else if (salida == "GRAMO"){
        cout << "La conversión de toneladas a gramos da como resultado: " << (numero * 1000000) << "g" << endl;
    } else if (salida == "ONZA"){
        cout << "La conversión de toneladas a onzas da como resultado: " << (numero * 35270) << "oz" << endl;
    }
};
// Si entrada == "ONZA"
double convOnz(string &salida, double &numero){
    if (salida == "ONZA"){
        cout << "No hay conversión que hacer, el dato es:" << numero << "oz" << endl;
    } else if (salida == "KILO"){
        cout << "La conversión de onzas a kilogramo da como resultado: " << (numero / 35.274) << "kg" << endl;
    } else if (salida == "LIBRA"){
        cout << "La conversión de onzas a libras da como resultado: " << (numero / 16) << "lb" << endl;
    } else if (salida == "GRAMO"){
        cout << "La conversión de onzas a gramos da como resultado: " << (numero * 28.35) << "g" << endl;
    } else if (salida == "TONELADA"){
        cout << "La conversión de onzas a toneladas da como resultado: " << (numero / 35270) << "Tm" << endl;
    }
};


// IMplementacion de la funcion principal para la conversion de peso
double convPeso(const converDatos &data){
    converDatos d;
    cout << "Ingrese una unidad de entrada: \nOpciones posibles (KILOGRAMO, LIBRA, GRAMO, TONELADA, ONZA): "; 
    cin >> d.unidadOrigen;
    cout << "Ingrese el número de la opción de salida:\nOpciones posibles (KILOGRAMO, LIBRA, GRAMO, TONELADA, ONZA): ";
    cin >> d.unidadSalida;;
    cout << "Ingrese el número sobre el que desea realizar la conversión: "; 
    cin >> d.numeroConver;


    if (d.unidadOrigen == "KILOGRAMO"){
        convKilo( d.unidadSalida, d.numeroConver);
    }else if (d.unidadOrigen == "LIBRA"){
        convLibr( d.unidadSalida, d.numeroConver);
    } else if (d.unidadOrigen == "GRAMO"){
        convGram( d.unidadSalida, d.numeroConver);
    } else if (d.unidadOrigen == "TONELADA"){
        convTonel( d.unidadSalida, d.numeroConver);
    } else if (d.unidadOrigen == "ONZA"){
        convOnz( d.unidadSalida, d.numeroConver);
    }else {
        return 0;
    }
};

// Implementacion de la funcion de convertir temperatura
double convTemperatura(const converDatos &data){
    converDatos d;
    cout << "Ingrese una unidad de entrada: \nOpciones posibles (CELSIUS, FAHRENHEIT, KELVIN): "; 
    cin >> d.unidadOrigen;
    cout << "Ingrese el número de la opción de salida:\nOpciones posibles (CELSIUS, FAHRENHEIT, KELVIN): ";
    cin >> d.unidadSalida;
    cout << "Ingrese el número sobre el que desea realizar la conversión: "; 
    cin >> d.numeroConver;


    if (d.unidadOrigen == "CELSIUS"){
        convCel(d.unidadSalida, d.numeroConver);
    }else if (d.unidadOrigen == "FAHRENHEIT"){
        convFar(d.unidadSalida, d.numeroConver);
    } else if (d.unidadOrigen == "KELVIN"){
        convKel(d.unidadSalida, d.numeroConver);
    } 
    return 0;

};
// Si entrada == "KELVIN"
double convKel( string &salida, double &numero){
    if (salida == "KELVIN"){
        cout << "No hay conversión que hacer, el dato es:" << numero << "K" << endl;
    } else if (salida == "CELSIUS"){
        cout << "La conversión de kelvin a celcius da como resultado: " << (numero - 273.15) << "°C" << endl;
    } else if (salida == "FAHRENHEIT"){
        cout << "La conversión de kelvin a fahrenheit da como resultado: " << ((numero - 273.25)*9/5 + 32) << "°F" << endl;
    }
};


double convFar( string &salida, double &numero){
    if (salida == "CELSIUS"){
        cout << "No hay conversión que hacer, el dato es:" << numero << "°C" << endl;
    } else if (salida == "KELVIN"){
        cout << "La conversión de CELSIUS a kelvin da como resultado: " << (numero + 273.15) << "K" << endl;
    } else if (salida == "FAHRENHEIT"){
        cout << "La conversión de CELSIUS a fahrenheit da como resultado: " << ((numero*(9/5) + 32)) << "°F" << endl;
    }

};


double convCel( string &salida, double &numero){
    if (salida == "FAHRENHEIT"){
        cout << "No hay conversión que hacer, el dato es:" << numero << "°F" << endl;
    } else if (salida == "KELVIN"){
        cout << "La conversión de fahrenheit a kelvin da como resultado: " << ((numero -32)*5/9 + 273.15) << "K" << endl;
    } else if (salida == "fahrenheit"){
        cout << "La conversión de CELSIUS a CELSIUS da como resultado: " << ((numero -32)*(5/9)) << "°C" << endl;
    }
};



// Temas del menu

void showMenu(){
    cout << "Bienvenido al programa conversor de unidades, seleccione el tipo de conversión que desea realizar: " << endl;
    cout << "1. Conversión de longitud." << endl; 
    cout << "2. Conversión de peso." << endl;
    cout << "3. Conversión de temperatura" << endl;
    cout << "4. Salir." << endl;

};