

<h1 style="text-align: center;">
    Tarea 2 <br><br>
    Estructuras de Datos y Algoritmos para Ingeniería
</h1>

<h3 style="text-align: center;">
    Profesor: Esteban Badilla Alvarado <br><br>
    Estudiante: Rodrigo Sánchez Araya, C37259
</h3>

## Instrucciones para ejecución de los programa: 

1. Ubicación: 
- Asegúrese de que el `MAKEFILE` se encuentre en el mismo directorio donde está la carpeta `src` que contiene los archivos fuente (`.cpp`) y cabeceras (`.hpp`).
- El `MAKEFILE` y la carpeta `src` deben estar en el mismo nivel dentro de una estructura de directorios.
2. Preparar el entorno:
**Para Windows** 
- Se debe tener un compilador compatible con `g++` intalado. 
- Abrir una ventada de comandos (cmd) o PowerShell.
**Para Linux**
- Asegúrese de tener instalado `g++` y `make`. En la mayoría de las distribuciones, puedes instalarlos con:
```bash
sudo apt-get install build-essential 
```
- Abrir la terminal.

3. Compilador de programas:

Navegue hasta el directorio donde se encuentra el `Makefile` utilizando el comando `cd`

```bash
# en este caso puede que la ruta dea la siguiente:
cd /ie0217/Tareas/Tarea2
```
- Una vez en el directorio ejecute el siguiente comando:

```bash
make
```
4. Ejecutar programas: 
- Después de la compilación, puede ejecutar todos los programas de la siguiente manera: 
```bash
make run 
```
5. Limpiar los archivos generados: 
- Para eliminar los ejecutables generados y limpiar el directorio, ejecute: 

```bash
make clean
```

## Parte teórica:

**1. ¿Qué es la programación orientada a objetos y cuáles son sus principios fundamentales?**

R/ Se basa en crear un modelo del problema de destino en un programa, es decir es como crear una especie de molde que se va a implementar a lo largo del código.

Los principios fundamentales son: 

- Herencia: Reutilización de código y especialización de objetos.
- Abstracción: Simplificación y claridad de conceptos.
- Polimorfismo: Flexibilidad y compatibilidad de objetos.
- Encapsulamiento: Protección de datos y ocultación de información.


**2. Mencione y explique al menos tres problemas clásicos de programación que POO es capaz de resolver.**
R/ 

| Problema que soluciona | Explicación |
| --------- | --------- |
| Complejidad de Software    | La OOP ayuda a organizar el código en piezas pequeñas y manejables, los objetos que se relacionan entre sí para formar un sistema complejo.    |
| Mantenimiento del Software    | La OOP ayuda a hacer cambios en el código de manera fácil, ya que, los objetos pueden ser modificados sin alterar el funcionamiento del sistema.    |
| Reutilización del Código    | La OOP permite reutilizar código existente, los objetos pueden ser creador y reutilizados en diferentes programas, ahorrando tiempo y esfuerzo.   |



**3. Describa el concepto de polimorfismo y brinde un ejemplo de su implementación en POO.**

R/ Es la capacidad que tienen los objetos de una clase en ofrecer respuestas distintas e independientes en funcion de los parámetros utilizados durante su invocación.
**4. Describa el concepto de abstracción y brinde un ejemplo de su implementación en POO.**
R/ Permite ocultar los detalles internos de implementación de un objeto y mostrar solo lo esencial y reelevante para su uso.

```cpp
#include <iostream>
using namespace std;

// Clase abstracta Figura
class Figura {
public:
    // Método abstracto para calcular el área
    virtual double calcularArea() const = 0;

    // Destructor virtual
    virtual ~Figura() {}
};

// Clase concreta que hereda de Figura: Rectangulo
class Rectangulo : public Figura {
private:
    double largo;
    double ancho;

public:
    // Constructor
    Rectangulo(double l, double a) : largo(l), ancho(a) {}

    // Implementación del método abstracto para calcular el área
    double calcularArea() const override {
        return largo * ancho;
    }
};

int main() {
    // Crear un objeto de tipo Rectangulo
    Rectangulo miRectangulo(5.0, 3.0);

    // Calcular y mostrar el área
    cout << "El área del rectángulo es: " << miRectangulo.calcularArea() << endl;

    return 0;
}


```

**5. Describa el concepto de encapsulamiento y brinde un ejemplo de su implementación en POO.**


R/ Se refiere al concepto de restringil el acceso directo a ciertos componentes de un objeto y permitir la manipulación de estos componentes únicamente a través de métodos definidos.

```cpp
#include <iostream>
#include <string>
using namespace std;

class Persona {
private:
    // Atributos encapsulados
    string nombre;
    int edad;

public:
    // Constructor
    Persona(string nom, int ed) : nombre(nom), edad(ed) {}

    // Métodos para obtener los valores de los atributos (getters)
    string getNombre() const {
        return nombre;
    }

    int getEdad() const {
        return edad;
    }

    // Métodos para establecer los valores de los atributos (setters)
    void setNombre(string nom) {
        nombre = nom;
    }

    void setEdad(int ed) {
        if (ed >= 0) {
            edad = ed;  // Solo permite valores no negativos
        } else {
            cout << "Edad no válida." << endl;
        }
    }
};

int main() {
    // Crear un objeto Persona
    Persona persona1("Juan", 25);

    // Acceder a los atributos a través de los métodos públicos
    cout << "Nombre: " << persona1.getNombre() << endl;
    cout << "Edad: " << persona1.getEdad() << endl;

    // Intentar modificar los atributos a través de los setters
    persona1.setNombre("Carlos");
    persona1.setEdad(30);

    // Mostrar los nuevos valores
    cout << "Nuevo nombre: " << persona1.getNombre() << endl;
    cout << "Nueva edad: " << persona1.getEdad() << endl;

    return 0;
}

```
**6. Defina los conceptos de clase, objeto, método y atributo de la programación orientada a objetos y brinde un ejemplo de la vida real (No de programación) que los describa intuitivamente.**



| Concepto  | Descripción   | Ejemplo |
| --------- | --------- | --------- |
| Clase     | Es una plantilla donde se definen los atributos y métodos predeterminados de un tipo de objeto. |Es el molde de las galletas que dispone las características que estas tendrán.|
| Objeto    | Instancia de una clase, adopta las disposiciones que tiene la clase   | Es la galleta que se va a crear con el molde |
| Método    | Algoritmo asociado a un objeto, son las acciones que puede realizar el objeto   | Son las acciones que se le aplican a la galleta como comerla.  |
| Atributo  | Tipo de dato asociado al objeto o a una clase, hace los datos visibles desde fuera del objeto y se define como sus características predeterminadas y este valor puede ser alterado por la ejecución de algún método.   | Cuando la galleta se muerda va a cambiar su forma y ahora va a tener un faltante donde fue mordida.|


**7. Mencione qué elementos tiene el "boilerplate" de una clase y explique cada uno.**


R/ El ``boilerplate`` se refiere a un conjunto de líneas de código que se utilizan de manera repetitiva y que generalmente no varían mucho.

Elementos: 

- Definición de clase: se debe agregar el elemto ``class`` y el nombre de la clase para así definir que se está creando una clase.
- Miembros de Datos: Variables de instancia donde los datos de cada objeto de la clase se mantendrán.
- Constructores: El constructor por defecto inicializa los objetos sin argumentos y el parametrizado lo hace mediante valores especificados.
- Destructor: Se encarga de liberar recursos cuando un objeto ya no los necesita.
- Métodos:
    - Públicos: Funciones que pueden ser llamadas desde fuera de la clase
    - Privados: Funciones que son accesibles solo dentro de la clase o sus derivadas
    - Protegido: FUnciones que son solo accesibles dentro de la misma clase.

**8. ¿Qué es el constructor de una clase? ¿Para qué sirve?**


R/ El constructor es un método de una clase que se llama automáticamente cuando se crea un objeto de esa clase. Se propósito es inicializar los miembros del objeto y realizar cualquier configuración que sea necesaria antes de que el objeto se utilice. 

**9. ¿Qué es instanciar un objeto en el contexto de POO? ¿Para qué sirve?**


R/ Crear una instancia concreta de una clase, es el proceso de crear un objeto a partir de una clase que actúa como plantilla, este objeto tendrá una copia propia de los atributos y métodos definidos en la clase.


**10. ¿Cuáles son las diferencias entre los especificadores de acceso públicos, privados y protegidos?**


R/ La diferencia entre los especificadores es principalmente a quién le dan permiso de acceder a un cierto atributo o método como se ilustra en el siguiente cuadro:


| Especificador | Misma clase | Clase deriva | Fuera de la clase|
|---------|---------|---------|---------|
| ``public`` | Si | Si | Si |
| ``private`` | Si | No | No |
| ``protected`` | Si | Si | No |

**11. ¿Qué es el destructor de una clase y para qué aplicaciones es conveniente usarlo?**


El destructor se utiliza para cerrar enlaces, se puedde interpretar como eliminar un puntero, es conveniente utilizarlo para que una vez que ya no se requiere alguna información esta sea desechada y no se siga almacenando y acaparando espacio en la memoria.

**12. Explique qué es la sobrecarga de operadores y proporcione un ejemplo de cómo se implementa en C++.**



R/ La sobrecarga de operadores consiste en la re-definición de cómo van a comportarse los operadores con los distintos elementos de las clases.


```cpp
#include <iostream>

class Vector2D {
public:
    // Constructor
    Vector2D(double x, double y) : x(x), y(y) {}

    // Sobrecarga del operador +
    Vector2D operator+(const Vector2D& otro) const {
        return Vector2D(x + otro.x, y + otro.y);
    }

    // Método para mostrar el vector
    void mostrar() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }

private:
    double x, y;
};

int main() {
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);

    // Uso del operador + sobrecargado
    Vector2D v3 = v1 + v2;

    v1.mostrar();  // Muestra: (1.0, 2.0)
    v2.mostrar();  // Muestra: (3.0, 4.0)
    v3.mostrar();  // Muestra: (4.0, 6.0)

    return 0;
}
```
**13. ¿Qué es la herencia en POO?**



R/ La herencia permite crear una nueva clase a partir de una clase existente. La clase derivada hereda las característias de la clase base y puede tener características adicionales propias.



**14. Mencione las diferencias entre la herencia pública, privada o protegida de una clase, qué sucede al heredar cada tipo.**



R/ 
- Herencia Pública: Los miembros públicos y protegidos de la clase base mantienen su visibilidad.
- Herencia Privada: Todos los miembros públicos y protegidos de la clase base se vuelven privados en la clase derivada.
- Herencia Protegida: Los miembros públicos de la clase se vuelven protegidos en la clase derivada, útil para cuano se quiere restringir el acceso a los miembros heredados.



**15. Observe el siguiente fragmento de código:**

```cpp
    #include <iostream>
    class Base {
    private:
        int primera;
    protected:
        int segunda;
    public:
        int tercera;
        Base() : primera(1), segunda(2), tercera(3) {}
    };

    class Derived : public Base {
    private:
        int cuarta;
    protected:
        int quinta;
    public:
        int sexta;
        Derived() : cuarta(4), quinta(5), sexta(6) {}
    };
```

Considerando que existen seis variables en el código (`primera`, `segunda`, `tercera`, `cuarta`, `quinta` y `sexta`), desde el `main` del programa:
- A cuáles de estas variables puede acceder un objeto instanciado de la clase `Base`, a cuáles no puede acceder y por qué.
- A cuáles de estas variables puede acceder un objeto instanciado de la clase `Derived`, a cuáles no puede acceder y por qué.


R/ La clase ``Base`` tiene acceso en el main a la variable ``tercera`` ya que esta se encuentra como pública, mientras que no puede acceder a ``primera`` porque esta es privada y no es accesible fuera de la clase y a ``segunda`` porque es protegida, solo accesible dentro de la clase ``Base`` y sus derivadas pero no fuera de estas.

La clase ``Derived`` por su lado, tiene como variables accesibles: ``tercera`` porque es pública en la clase base y sigue igual en la clase derivada, ``quinta`` es protegida en la clase base por lo que es accesible dentro de la calse derivada y ``sexta`` es pública en la clase por lo que es accesible dentro y fuera de la clase. En cambio, no son accesibles ``primera`` porque es privada de la clase base, ``segunda`` aunque es protegida en la clase base y accesible en la clase derivada, no es accesible directamente desde fuera de la clase derivada y ``cuarta`` es privada de la clase derivadaa por lo que no es accesible fuera de la clase derivada.



**16. ¿Qué es una clase amiga y para qué se usa? ¿Cuál es la manera de definirla?**


R/ La clase amiga puede acceder a los miembros privados y protegidos de la clase que le concede la amistad.

```cpp
#ifndef CLASEA_HPP
#define CLASEA_HPP

class ClaseB;  // Declaración adelantada

class ClaseA {
    friend class ClaseB;  // ClaseB es amiga de ClaseA

public:
    ClaseA(int valor) : dato(valor) {}

private:
    int dato;
};

#endif // CLASEA_HPP
```


**17. ¿Qué es una función amiga y para qué se usa? ¿Cuál es la manera de definirla?**



R/ Una función que se declara como amiga de una clase, lo que le otorga acceso a los miembros privados y protegidos de esa clase.


```cpp
#ifndef CAJA_HPP
#define CAJA_HPP

class Caja {
    friend void mostrarDimensiones(const Caja& c);  // Declaración de la función amiga

public:
    Caja(double l, double a, double p) : largo(l), ancho(a), profundo(p) {}

private:
    double largo;
    double ancho;
    double profundo;
};

#endif // CAJA_HPP
```

**18. Explique la importancia de los métodos virtuales en C++ y cómo se utilizan en la implementación de polimorfismo.**


R/ Los métodos virtuales son fundamentales para la implementación del polimorfismo, un concepto clave en la Programación Orientada a Objetos (POO). El polimorfismo permite que una llamada a un método pueda invocar diferentes implementaciones dependiendo del tipo del objeto que la recibe, incluso cuando se utiliza una referencia o puntero a una clase base.

