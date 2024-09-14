

<h1 style="text-align: center;">
    Tarea 3 <br><br>
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
cd ./ie0217/Tareas/Tarea3
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

# Parte Teórica - Tarea 3

**1. Explique cada sección del nivel de usuario de la memoria (Text, Heap, Stack, etc.). ¿Cuáles de estas secciones son de memoria dinámica?**


R/ Son 4 secciones: 

- Text: Almacena el código que se está ejecutando.

- Data: Almacena variables globales, separadas en inicializadas y no inicializadas.

- Stack: Almacena variables locales. 

- Heap: Memoria dinámica para que quien pragrama la asigne.



**2. Observe el siguiente fragmento de código:**
```cpp
#include<iostream>

int globalVar = 42; 

int main(){
    static int staticVar = 100; 
    int localVar = 10;
    int* dynamicVar = new int(5);

    delete dynamicVar;

    return 0;
}
```
**Considerando que existen cuatro variables en el código (globalVar, staticVar, localVar y dynamicVar), mencione en qué sección de la memoria se almacena cada variable y explique el porqué.**


R/ 
- La variable ``globalVar`` se almacena en data. Las variables globales permanecen en la memoria durante toda la ejecución del programa.

- La variable ``staticVar`` se almacena en data. las variables estáticas, aunque no sean globales, conservan su valor entre las llamadas a funciones y existen durante toda la ejecución del programa.

- La variable ``localVar`` se almacena en stack. Las variables locales se rean cuando se entra a una función se eleminan cuando se sale de esta.

- La variable ``dynamicVar`` se almacena en el heap. Esta región de memoria está reservada para la memoria dinámica.


**3. ¿Cuál es la diferencia entre memoria dinámica y memoria estática? Brinde un ejemplo de qué tipos de variables se almacenan en cada tipo.**


R/

| Característica           | Memoria Estática                                      | Memoria Dinámica                                   |
|--------------------------|------------------------------------------------------|---------------------------------------------------|
| **Asignación**           | Se asigna en tiempo de compilación.                  | Se asigna en tiempo de ejecución.                 |
| **Liberación**           | Automática cuando el programa termina.               | Manual, requiere ser liberada explícitamente.     |
| **Ubicación**            | Sección de datos (Data Segment).                     | Heap (montón).                                    |
| **Uso**                  | Variables globales, estáticas, constantes.           | Variables creadas dinámicamente.                  |
| **Ejemplo**              | `int globalVar = 10;`<br>`static int var = 20;`      | `int* dynamicVar = new int(30);`<br>`delete dynamicVar;` |

**4. ¿Cómo se accede a la memoria dinámica del heap? Brinde un ejemplo programado de cómo guardar un valor en una posición de memoria ubicada ahí.**


R/ Para acceder a la memoria dinámica del heap se utilizan funciones o palabras clase que permitan asignar y liberar memoria en tiempo de ejecución.

- Al utilizar ``new``, se obtiene un puntero que apunta a la dirección de memoria en el heap. Se puede acceder a la memoria a la que apunta el puntero utilizando el operador de desreferencia ``*``.


```cpp 
#include <iostream>
using namespace std;

int main() {
    // Asignación de memoria dinámica para un entero
    int* dynamicVar = new int;  // Se reserva espacio en el heap para un entero

    // Guardar un valor en la memoria dinámica
    *dynamicVar = 42;  // Se guarda el valor 42 en la dirección de memoria del heap

    // Imprimir el valor almacenado
    cout << "El valor en la memoria dinámica es: " << *dynamicVar << endl;

    // Liberar la memoria dinámica
    delete dynamicVar;  // Se libera la memoria para evitar fugas

    return 0;
}

```


**5. ¿Por qué es importante liberar la memoria asignada dinámicamente cuando ya no se esté utilizando?**


R/ Es importante para evitar las fugas de memoria; si al memoria no es liberada, el programa sigue reservando esa memoria incluso cuando ya no la necesita, lo cual lleva a las fugas de memoria, donde las partes de la memoria permanecen ocupadas innecesariamente, reduciendo la cantidas de memoria dispinible para otras operaciones. 



**6. ¿Para qué se utilizan las funciones malloc, calloc y realloc? ¿Qué parámetros recibe cada una?**


R/ La función ``malloc`` se utiliza para asignar un bloque de memoria en el heap pero no se encarga de limpiarlo. Recibe un solo parámetro que es el tamaño en bytes de la memoria a asignar.


La función ``calloc`` asigna un bloque de memoria al heap y se encarga de limpiarlo. 

- Parámetros: 
    - Número de elementos a asignar.
    - Tamaño de cada elemento.


La función ``realloc`` cambia el tamaño de un bloque de memoria previamente asignado con malloc o calloc. 

Recibe como parámetros: un puntero a la memoria previamente asignada y el nuevo tamaño deseado en bytes.



**7. Mencione las diferencias entre el uso de free y delete. ¿En qué contexto se utilizaría cada uno?**


R/ 
| Característica          | `free`                                             | `delete`                                           |
|-------------------------|----------------------------------------------------|----------------------------------------------------|
| **Lenguaje**            | Utilizado en C y C++                               | Utilizado solo en C++                              |
| **Propósito**           | Libera la memoria asignada por `malloc`, `calloc` o `realloc` | Libera la memoria asignada por `new`               |
| **Inicialización de objetos** | No llama al destructor de los objetos | Llama automáticamente al destructor de los objetos |
| **Uso con tipos primitivos** | Se utiliza para liberar memoria de tipos de datos primitivos como `int`, `char`, etc. | Se utiliza tanto para tipos primitivos como para objetos de clases en C++ |
| **Sintaxis**            | `free(ptr);`                                       | `delete ptr;`                                      |
| **Contexto de uso**     | Cuando se ha utilizado `malloc`, `calloc` o `realloc` para asignar memoria en C o C++ | Cuando se ha utilizado `new` para asignar memoria en C++ |
| **Liberación de arrays** | No distingue entre memoria normal y arrays         | Usa `delete[]` para liberar arrays asignados con `new[]` |



**8. Explique la diferencia entre new y malloc en C++. ¿Cuándo debería utilizar uno sobre el otro?**


R/ 
| Característica         | `new`                                  | `malloc`                              |
|------------------------|----------------------------------------|--------------------------------------|
| **Propósito**          | Asignar memoria para objetos y llamar al constructor | Asignar solo memoria (sin inicialización) |
| **Inicialización**     | Inicializa el objeto llamando al constructor | No inicializa, solo asigna memoria   |
| **Destrucción**        | Usa `delete` (llama al destructor)      | Usa `free` (no llama a destructores)  |
| **Sintaxis**           | `int* p = new int(5);`                  | `int* p = (int*)malloc(sizeof(int));` |
| **Tipo de memoria**    | Gestiona la memoria de objetos y tipos | Solo memoria para tipos básicos       |
| **Seguridad y Mantenimiento** | Más seguro y fácil de mantener en C++ | Menos seguro y requiere manejo manual de tipos |




**9. Explique el concepto de punteros inteligentes (smart pointers) y proporcione ejemplos de su uso.**


R/ Un puntero inteligente es un tipo de puntero que gestiona automáticamente la memoria, ayudando a evitar problemas como fugas de memoria y errores de acceso. 


Ejemplo del uso: 

```cpp
#include <iostream>
#include <memory> // Necesario para std::unique_ptr

class MyClass {
public:
    MyClass() { std::cout << "MyClass creado\n"; }
    ~MyClass() { std::cout << "MyClass destruido\n"; }
};

int main() {
    // Crear un unique_ptr que maneja un objeto de MyClass
    std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>();

    // No es necesario eliminar manualmente el objeto; se libera automáticamente cuando el puntero sale del ámbito
    return 0;
}
```


**10. Mencione qué es un algoritmo y explique qué características básicas debería tener.**


R/ Los algoritmos son un conjunto de instrucciones bien definidas para resolver un problema en particular. Toma un conjunto de entradas y produce el resultado deseado. 

Entre las características que debería de tener: 


- La entrada y salida deben definirse con presición.

- Cada paso del algoritmo debe ser claro e inequívoco.

- Los algoritmos deberían ser más eficases entre muchas formas diferentes de resolver un problema.

- Deben incluir código informático. El algoritmo debe escribirse de tal manera que pueda usarse en diferentes lenguajes de programación.




**11. ¿Qué es la complejidad y eficiencia de un algoritmo? ¿De qué manera se miden?**



R/ La complejidad de un algoritmo se refiere a la cantidad de recursos necesarios para ejecutar el algoritmo, como el tiempo y la memoria. 


La eficiencia de un algoritmo hace referencia a la capacidad del algoritmo para utilizar de manera efectiva los recursos disponibles.



**12. ¿Cuál es la diferencia entre las estructuras de datos lineales y no lineales? Mencione dos ejemplos de cada una.**

R/ 

| Característica           | Estructuras Lineales                                  | Estructuras No Lineales                            |
|--------------------------|-------------------------------------------------------|----------------------------------------------------|
| **Definición**           | Los elementos están organizados en una secuencia lineal. | Los elementos no siguen una secuencia lineal.     |
| **Ejemplos**            | Arreglos, listas enlazadas, pilas, colas               | Árboles, grafos                                    |
| **Acceso a Elementos**  | Acceso secuencial y directo (por índice o puntero).   | Acceso no secuencial; puede requerir traversal.    |
| **Estructura**          | Cada elemento tiene un único predecesor y sucesor (excepto el primero y el último). | Los elementos pueden tener múltiples relaciones (como nodos en un árbol o vértices en un grafo). |
| **Ejemplo de Aplicación** | Implementación de algoritmos de búsqueda o almacenamiento simple. | Modelado de relaciones complejas, como redes sociales o jerarquías. |
| **Uso de Memoria**      | Generalmente se utiliza memoria de manera continua.   | Puede utilizar memoria no contigua y más flexible.|
| **Eficiencia en Operaciones** | Operaciones de inserción y eliminación pueden ser costosas en arreglos pero eficientes en listas enlazadas. | Las operaciones pueden ser más complejas pero pueden ofrecer más flexibilidad. |
| **Ejemplo de Implementación** | - Arreglos: `int arr[5] = {1, 2, 3, 4, 5};`<br> - Listas enlazadas: `struct Node { int data; Node* next; };` | - Árboles binarios: `struct TreeNode { int data; TreeNode* left; TreeNode* right; };`<br> - Grafos: `std::vector<std::vector<int>> graph;` |





**13. Explique cómo funciona la estructura Stack.**


R/ Es una estructura de datos lineal que sigue el principio de, el primero en entrar es el primero en salir, (LIFO). El último elemento insertado dentro de la pila se elimina primero. 


**14. Explique cómo funciona la estructura Queue.**


R/ La estructura de datos Queue sigue la misma filosofía operacional que el stack donde el primero en entrar es el primero en salir. 



**15. Explique cómo funciona la estructura Lista Enlazada.**


R/ Una lista enlazada es una estructura de datos donde los elementos (nodos) están conectados en una secuencia. Cada nodo tiene un dato y un puntero al siguiente nodo. La lista comienza con un nodo llamado cabeza. Puedes insertar o eliminar nodos ajustando los punteros. Existen variantes como listas simples, dobles (con punteros al nodo anterior) y circulares (donde el último nodo apunta al primero).


**16. Explique cómo funciona la estructura Árbol. ¿Qué características presenta esta estructura?**


R/ Un árbol es una estructura de datos jerárquica con nodos organizados en niveles.

- Raíz: El nodo principal del árbol.
- Nodos: Cada nodo tiene un valor y puede tener nodos hijos.
- Hijos: Los nodos directamente conectados a otro nodo (llamado padre).
- Hojas: Nodos sin hijos.
Características:

- Jerárquico: Cada nodo puede tener varios hijos, pero solo un padre.
- Conexiones: No hay ciclos; se forma una estructura acíclica.
- Niveles: Los nodos están organizados en niveles desde la raíz hacia abajo.



**17. Explique los tipos de recorridos que se le pueden aplicar a un árbol.**


R/

| Tipo de Recorrido       | Orden de Visita                   | Descripción                                      | Uso Principal                                      |
|-------------------------|-----------------------------------|--------------------------------------------------|----------------------------------------------------|
| **Preorden**            | Nodo → Hijos Izquierdo → Hijos Derecho | Visita el nodo antes de sus hijos.              | Útil para copiar el árbol.                        |
| **Inorden**             | Hijos Izquierdo → Nodo → Hijos Derecho | Visita el nodo entre sus hijos izquierdo y derecho. | Da los valores en orden ascendente en un árbol binario de búsqueda. |
| **Postorden**           | Hijos Izquierdo → Hijos Derecho → Nodo | Visita los nodos hijos antes del nodo actual.   | Útil para liberar memoria (destruir el árbol).    |
| **Por Niveles** (o en Ancho) | Nodos por nivel, de arriba hacia abajo y de izquierda a derecha | Visita los nodos nivel por nivel.                | Útil para encontrar el camino más corto en un árbol. |



**18. ¿Cuál es la diferencia entre un árbol y un árbol binario? Mencione y explique tres tipos de árboles binarios.**

R/ 
 | Característica           | Árbol                                   | Árbol Binario                            |
|--------------------------|-----------------------------------------|------------------------------------------|
| **Número de Hijos**      | Un nodo puede tener múltiples hijos.    | Cada nodo tiene como máximo dos hijos (izquierdo y derecho). |
| **Estructura**           | Más general, sin restricciones específicas. | Estructura específica con dos hijos por nodo. |
| **Ejemplo de Uso**       | Representar jerarquías generales.       | Implementación de estructuras como árboles de búsqueda. |


