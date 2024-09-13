# Dentro de esta sección se presenta el apartado para la sesión # 6 del curso IE0217.


### Instrucciones para la ejecución de los programas

1. Navegue hasta el directorio donde se encuentra la sesión5  utilizando el comando `cd`

```bash
# en este caso puede que la ruta dea la siguiente:
cd /ie0217/Sesiones/Sesion6
```

2. Sírvace de ejecutar el programa que desee mediante el comando: 

```cpp
g++ -o nombre_ejecutable.exe nombre_del_programa.cpp

```
3. En caso de querer ejecutar los programas que se encuentran dentro de carpetas (Esto para tener orden con los archivos headers):

```cpp
g++ -o nombre_ejecutable.exe nombre_de_implementacion.cpp nombre_archivop_principal.cpp

```

## Resumen de la sesión: 

Dentro de esta sesión se aborda el estudio referente a 4 tipos de algoritmos de ordenamiento (Bubble, Insertion, Quick y Selection Sort).


- Bubble Sort: 
    - Compara pares de elementos que se encuentran uno al lado del otro y los intercambia si están en el orden incorrecto. Repite este proceso hasta que no haya más intercambios.
    - Complejidad: O(n^2) en el peor caso.
- Quick Sort: 
    - Selecciona un  **pivote**, divide el arreglo en dos subarreglos (menores y mayores que el pivote), y ordena recursivamente.
    - Complejidad: O(n log n ) en promedio, O(n^2) si se llega a escoger un mal pivote.
- Insertion Sort: 
    - Toma un elemento a la vez y lo inserta en su posición correcta en una lista ya ordenada.
    - Complejidad: O(n^2) en el peor caso. 
- Selection Sort: 
    - Encuentra el elemento mínimo de la lista y lo intercambia con el primer elemento no ordenado.
    - Complpejidad: O(n^2) siempre.

