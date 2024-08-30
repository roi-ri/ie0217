<h1 style="text-align: center;">
    Tarea 1 <br><br>
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
cd /ie0217/Tareas/Tarea1
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

**Notas adicionales**

- Si solo deseas compilar un programa específico sin ejecutar todos, se puede hacer:

```bash 
make # y nombre del programa
```
- Para ejecutar un programa específico después de la compilación se puede hacer: 
```bash
./nombreDelPrograma # En Linux 
nombreDelPrograma.exe  # En Windows
```


## Parte teórica

**1. ¿Cuáles son las diferencias entre los lenguajes compilados e interpretados? Brinde un ejemplo de cada uno.**
**R/** 
- Por lenguaje interpretado se entiende son los que convierten el lenjuage con el que se programa a medida de que se ejecuta el código, en este caso un ejemplo puede ser PHP o JavaScript.
- Por lenguaje compilado se entiende como lenguajes en los que se ocupa un paso extra para poder ejecutarlos, este consiste en que el programa va a crear un compilado del archivo con el código antes de ejecutarlo, en este caso un ejemplo puede ser C o C++.


**2. ¿Qué son los tipos de datos en C++? ¿Cuáles son sus clasificaciones? Brinde dos ejemplos de cada clasificación.**


**R/**  Los tipos de datos en C++ son elementos utilizados para definir algún tipo de información que una variable puede almacenar y establece la manera en que el compilador va a manejar la memoria para estos.

**Clasificaciones:**

Datos Básicos:

```cpp
//Numero decimal
float numberFloat = 3.141592
```

```cpp
//Numero entero
int valor = 10
```
Datos Derivados: 

```cpp
//Arrays
int numeros[5] = {1, 2, 3, 4, 5};
```
```cpp
// Referencias
int& ref = edad;
```
Datos definidos por el usuario y constantes: 

```cpp
// Struct 
struct Punto {
    float x; // Coordenada x del punto
    float y; // Coordenada y del punto
};
```

```cpp
enum Dias {Lunes, Martes, Miercoles, Jueves, Viernes};
```

```cpp
conts MAX_VALUE == 100; 
```

Datos volátiles y estáticos: 

```cpp
//la variable puede cambiar en cualquier momento fuera del control del programa.

volatile int contador;
```

```cpp
//Mantiene el valor por toda la vida del programa o funcion.
static int contador;
```
 

**3. Explique qué es un linker en el contexto de un lenguaje de programación compilado. ¿Cuál es su función principal y por qué es esencial en el proceso de compilación?**

**R/** En un lengiaje de programación compilado, el linker es una herramienta que actúa después de que el compilador ha convertido el código fuente en archivos de código objeto. El linker es el encargado de combinar diferentes archivos con código objeto en un único archivo, este traslada las secciones que empiezan en la dirección 0 asociando una dirección a cada definición de un símbolo y después haciendo referencia a esa dirección en cada referencia del símbolo.


**4. ¿Cuál es la diferencia entre usar el operador `=` y `==`? Brinde un ejemplo para cada uno.**
**R/** El operador '=' se utiliza para asignar valores.
```cpp
int x = 10;
int y = 80; 
//Se le asigna el numero 10 y 80 al termino 'x' y 'y' respectivamente
```

El operador '==' se utiliza para comparar dos elementos.
```cpp
#include <iostream>
int x = 10;
int y = 80; 
if (x == y){
    std::cout << 'El valor de x es igual que el de y.' << std::endl;
} else{
    std::cout << 'El valor de x es distinto al de y.' << std::endl; 

}

//Se comparan los valores de 'x' y 'y'
```

**5. Observe el siguiente código, indique qué imprime el programa en la iteración número 7 y 9 del ciclo, explique el porqué.**

    ```cpp
    #include <iostream>
    int main() {
        int sum = 0;
        int result = 0;

        for (int i=1; i<=10; ++i) {
            sum += i;
            result = sum * 3 + i;
            std::cout << result << std::endl;
        }

        return 0;
    }
    ```

**R/** Para la primera iteración se tiene que, sum = 0 + 1 y result = sum * 3 + i, con i = 1, por ende, result = 4. El sum += 1 se refiere a decir sum = sum + i entonces:  
- La segunda iteración, sum = 1 + 2 = 3 y result = sum * 3 + 2 = 11
- la tercera, sum = 3 + 3 = 6 y result = sum * 3 + 3 = 21
- La cuarta: sum =  6 + 4 = 10 y result = sum * 3 + 4 = 34
.
.
.
- La sétima: sum = 21 + 7 = 28 y result = sum * 3 + 7 = 91
- La novena: sum = 38 + 7 = 45 y result = sum * 3 + 9 = 144



**6. Explique el proceso de pasar argumentos a la función principal. ¿Cuál es el primer elemento de `argv[]`?**
**R/** A la hora de ejecutar el programa por medio de la terminal se le pueden pasar argumentos a la funcion principal, se requiere de una estructura en esta de la siguente manera:

```cpp
int main(int argc, char* argv[]) {
    // Lo que quiero que haga la funcion principal
}

```

- Con `int argc` para contar los argumentos que se le pasan a la funcion.
- Con `char* argv[]` es un arreglo de strings que contiene los argumentos

El primer elemento de `argv[]` sería el que se rige por el índice 0, en este caso, el nomnbre del programa.


**7. ¿Cuál es la diferencia entre declarar e inicializar una variable?**
**R/** A la hora de: 
- Declarar una variable lo que se está haciendo es "decirle" al compilador que reserve un cierto espacio de memoria para un tipo de dato que se le está indicando.

- Inicializar una variable lo que se hace es, que a la variable que ya fue declarada asignarle un valor.

**8. ¿Para qué sirven los modificadores en C++?**
**R/** Los modificadores sirven para alterar ciertas características de los datos básicos en C++, por ejemplo los modificadores de tamaño como `short` o `long`, también el `cosnt`.

**9. ¿Qué es la sobrecarga de funciones en C++ y cómo se utiliza?**
**R/**  La sobrecarga de funciones consiste en la definición de varias funciones con el mismo nombre pero que van tener distintos tipos de parámetros. El compilador es quien se encarga de ver cual función llamar en referencia a los parámetros que se le pasan a dicha función.

**10. ¿Cuál es la diferencia entre una variable local y una local estática?**
**R/** Una variable local se inicializa en cada una de las llamadas que se le haga a la función o lugar donde fuera definida a diferencia de la estática local que, solo se inicializa la primera vez dentro de la función o bloque donde fuera definida.<br>De la misma manera, una variable local solo permanece "viva" el tiempo de dure la ejecución del bloque en el que se encuentra mientras que la variable estática local se manetiene durante toda la ejecución del programa.



**11. ¿Qué es el type casting? ¿Cuáles existen? Brinde un ejemplo de cada uno.**
**R/** 

| **Nombre**                           | **Ejemplo**                         | **Uso típico**                                                  |
|--------------------------------------|-------------------------------------|-----------------------------------------------------------------|
| *Cast* tradicional de C              | `(int) float_var`                   | Combina `static_cast`, `const_cast` y `reinterpret_cast`        |
| `static_cast`                        | `static_cast(float_var)`            | Convertir tipos nativos o clases con constructor o operador de cast |
| `const_cast`                         | `const_cast(const_int_var)`         | Eliminar atributos de tipo como `const`                         |
| `reinterpret_cast`                   | `reinterpret_cast(void_pointer)`    | Pretender que un tipo (de puntero) es realmente otro            |
| `dynamic_cast`                       | `dynamic_cast(referencia_a_clase_base)` | Reinterpretar una clase base como una clase derivada        |
| **Constructor con un parámetro**     | `Clase(const OtroTipo& fuente)`     | Inicializar una instancia con otro tipo                         |
| **Operador de cast**                 | `operator int(void) const;`         | Convertir una instancia a otro tipo                             |


**12. ¿Cuál es la principal diferencia entre un bucle `do-while` y un bucle `while`?**
**R/**  En un bucle do-while, el bloque de código se ejecuta al menos una vez antes de verificar la condición en el while, ya que la condición se evalúa después de la primera ejecución. En cambio, en un bucle while, la condición se evalúa antes de que se ejecute el bloque de código, por lo que es posible que el bloque de código nunca se ejecute si la condición inicial es falsa.

**13. Explique por qué es útil y común dividir el código en archivos `.hpp`, `.cpp` y `main.cpp` en C++. Describa el propósito específico de cada tipo de archivo.**
**R/** Al dividir el código en archivos se hace más fácil la organización y el orden en un proyecto, así como el aumento en la eficiencia ya que, cada uno de estos tipos de archivos tiene un enfoque diferente como se comenta acontinuación:


- **Archivos encabezados o "headers" (`.hpp`):**
Dentro de este archivo se declaran las funciones, clases, estructuras y constantes que se van a usar en el programa.
- **Archivo de implementación(`.cpp`):**\
En este se implementan las funciones y métodos que fueron declaradso en el archivo de encabezado previamente creado.
- **Archivo principal (`main.cpp`):**
En este se va a dar el punto de entrada del programa. Dentro de este archivo se van a realizar los correspondientes llamados a las funciones, clases, estructuras y constantes declaradas en los anteriores archivos.



**14. ¿Qué hace la sentencia `goto` y por qué es considerada una mala práctica en la programación moderna? ¿Qué alternativas se pueden usar en su lugar?**
**R/** La sentencia goto permite que el flujo de ejecución del programa salte directamente a una línea específica del código, identificada por una etiqueta. Se le considera una mala práctica en porque interrumpe la secuencia del código, el uso de este puede generar confución a la hora de leer el programa. Como alternativas se encuentran los bucles para repetir secciones de código las cexes que sea necesario, Funciones, para poder hacer uso de ciertos bloques de código cuando sea necesario. 




**15. ¿Para qué se utiliza la directiva `#ifndef` y por qué es importante?**
**R/** La directiva #ifndef cuyo significado es "if not defined" o "si no está definido", se utiliza para comprobar si un símbolo o macro ha sido definido previamente en el código. Se usa comúnmente en combinación con #define y #endif para evitar la redefinición de archivos de encabezado o símbolos.



**16. ¿Qué es un puntero y para qué es útil? ¿Cómo se declara e inicializa?**
**R/** Un puntero es una variable que almacena la dirección de memoria de otra variable. Básicamente es un tipo de variable que apunta a la ubicación de otra variable en la memoria. 
```cpp
int* puntero; //Se declara el puntero
int variable = 99; 
int* puntero = &variable; //inicializa el puntero hacia la dirección de 'variable'
```



**17. ¿Cuál es la diferencia entre pasar parámetros por valor, por referencia y por puntero?**
**R/** Al pasar parámetros por valor se pasa una copia del valor, los cambios que se le hagan a lo interno del lugar de uso no afectan a la variable original.

Al pasar parámetors por referencia lo que se hace es que se envía una especia de alias de la variable original, los cambios dentro del bloque de código donde se está pasando sí afectan a la variable original.

Al pasar parámetors por puntero se para la dirección de memoria de este, los cambios que se hagan dentro del bloque de texto donde está siendo modificado si le afectan al valor original. 


**18. Cuando se usa un puntero para apuntar a un arreglo en C++, ¿a qué valor o dirección apunta inicialmente? Describa cómo sería la forma de acceder a todos los datos de ese arreglo mediante el puntero.**
**R/** Cuando se utiliza un puntero para apuntar a un arreglo en C++, el puntero inicialmente apunta a la dirección de memoria del primer elemento del arreglo. Dado que los elementos de un arreglo están almacenados en ubicaciones de memoria contiguas, puedes acceder a todos los elementos del arreglo mediante el puntero incrementando su valor. Es decir, al sumar un valor entero al puntero, este se desplazará a la siguiente dirección de memoria correspondiente al siguiente elemento del arreglo. Por ejemplo, si p es un puntero al primer elemento del arreglo, *(p + i) accederá al elemento en la posición i del arreglo.



**19. ¿En qué caso es conveniente usar el operador `->` en punteros y por qué es beneficioso?**
**R/**  Al utilizar -> con punteros, se accede a los miembros de una estructura o clase a través del puntero. Esto simplifica el código al evitar la necesidad de desreferenciar el puntero primero.



**20. ¿Cuál es la manera de implementar punteros dobles, triples, etc? Brinde un ejemplo de en qué caso sería beneficioso usar esta implementación.**
**R/** Un puntero doble o triple, entre otros son punteros los cuales almacenan la dirección de memoria hacia el puntero "antecesor".  Se puede ver como una seguidilla de punteros donde el primero apunta hacia una dirección de algún valor dentro del programa, el segundo apunta a esa dirección y así sucesivamente. 


| Tipo de Puntero | Definición                        | Uso Común                         | Ejemplo de Código                  |
|-----------------|----------------------------------|-----------------------------------|-----------------------------------|
| `T**`           | Puntero a un puntero a `T`         | Matrices dinámicas, paso de punteros | `int** matrix = new int*[rows];`   |
| `T***`          | Puntero a un puntero a un puntero a `T` | Estructuras de datos más complejas  | `int*** triplePtr;`                |

**Ejemplo para Puntero Doble (Matriz Dinámica):**
```cpp
int** matrix = new int*[rows];  // Array de punteros a int
for (int i = 0; i < rows; ++i) {
    matrix[i] = new int[cols];  // Cada fila es un array de int
}
```

**21. ¿Qué es el puntero `this` en C++?**
**R/** Es un puntero accesible solo dentro de las funciones miembro no estáticas de un tiplo slass, struct o union. Apunta hacia el objeto para el que se llama a la función miembro. Las funciones miembro estáticas no tienen un puntero `this`


**22. ¿Qué es un puntero `nullptr`?**
**R/** El puntero `nullptr` es una constante de puntero nulo explícita, tienen dos problemas y es que es imposible distinguir entre puntero nulo y un entero 0 para las funciones sobrecargadas.




**23. ¿Qué es una función prototipo?**
**R/** Es una declaración de una función que especifica su nombre, los tipos de sus parámetros y el tipo de valor que devuelve, sin embargo, no proporciona la implementación de esta.




**24. ¿Dónde y cómo se guardan las variables que se crean en C++? Explique la diferencia entre el almacenamiento de variables locales y globales.**
**R/** Las variables se almacenan en la memoria RAM y el espacio de memoria que ocupan (en bytes) depende de su tipo, además las variables locales se almacenan en pila (conocida como stack) y las variables locales se almacenan en la sección de datos (conocido como data segment de la memoria estática). Las variables locales existen únicamente en la instancia donde han sido declaradas, por ejemplo dentro de una función, algún loop y este tipo de estructuras, una vez que se sale de estas es imposible acceder a estas variables; mientras que las variables globales existen durante la ejecución completa del programa y son siempre accesibles en cualquier parte del código.




**25. ¿Investigue qué es un memory leak?**
**R/** Se le puede conocer como una fuga de memoria, es un error de software que ocurre cuando un bloque de memoria reservada no es liberada en un programa. Ocurre cuando las referencias a objetos que no son empleadas se mantienen de modo innecesario.



**26. ¿Qué es memoria dinámica?**
**R/** Es aquella que se utiliza para almacenar datos que se crean en el medio de la ejecucioón de un programa.




**27. ¿Qué es memoria estática?**
**R/** Es la memoria que se reserva en el momento de la compilación antes de comenzar a ejecutar el programa.








