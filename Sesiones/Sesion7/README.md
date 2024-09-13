# Dentro de esta sección se presenta el apartado para la sesión # 7 del curso IE0217.


### Instrucciones para la ejecución de los programas

1. Navegue hasta el directorio donde se encuentra la sesión5  utilizando el comando `cd`

```bash
# en este caso puede que la ruta dea la siguiente:
cd /ie0217/Sesiones/Sesion7
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

1. Contenedores: estructuras que almacenan datos de manera organizada, como secuencialmente (vectores, listas), en pares clave-valor (mapas), o desordenadamente (unordered_map). Los adaptadores de contenedores, como pilas o colas, también se mencionan por proporcionar interfaces específicas.

2. Iteradores: objetos que permiten recorrer los elementos dentro de los contenedores. Hay varios tipos, como los iteradores de entrada, salida, bidireccionales, y de acceso aleatorio, cada uno con características específicas para navegar y manipular datos.

3. Algoritmos: funciones que operan sobre los contenedores para realizar tareas comunes como búsqueda, ordenamiento, manipulación y cálculos. Ejemplos incluyen sort para ordenar y find para buscar elementos.