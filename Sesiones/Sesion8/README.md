# Dentro de esta sección se presenta el apartado para la sesión # 8 del curso IE0217.


### Instrucciones para la ejecución de los programas

1. Navegue hasta el directorio donde se encuentra la sesión5  utilizando el comando `cd`

```bash
# en este caso puede que la ruta dea la siguiente:
cd /ie0217/Sesiones/Sesion8
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

- Templates: Permiten crear código genérico que puede trabajar con diferentes tipos de datos. Puedes escribir funciones o clases que funcionen con múltiples tipos sin tener que definirlas específicamente para cada uno. Los templates se definen con la palabra clave ``template`` seguida de parámetros de tipo, y pueden aplicarse tanto a funciones como a clases.



- Excepciones: Son eventos inesperados que ocurren durante la ejecución de un programa, como una división entre cero. En C++, las excepciones se manejan mediante bloques ``try``, ``catch``, y ``throw``. El bloque try contiene el código que podría generar una excepción, ``throw`` lanza la excepción, y ``catch`` maneja el error lanzado.
