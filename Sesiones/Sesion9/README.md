# Dentro de esta sección se presenta el apartado para la sesión # 9 del curso IE0217.


### Instrucciones para la ejecución de los programas

1. Navegue hasta el directorio donde se encuentra la sesión5  utilizando el comando `cd`

```bash
# en este caso puede que la ruta dea la siguiente:
cd /ie0217/Sesiones/Sesion9
```

2. Para el archivo de expreciones regulares ejecute el siguiente comando: 

```cpp
g++ -o expreciones.exe Regex.cpp

```
3. En caso de querer ejecutar los archivos de Estudiante o Bibliioteca:


```bash
# en este caso puede que la ruta dea la siguiente:
cd /ie0217/Sesiones/Sesion9/Estudiante

cd /ie0217/Sesiones/Sesion9/Biblioteca
```

```cpp
// En cualquiera de las rutas ejecute el archivo makefile para que se cree el debido ejecutable del programa
make 
```

4. Sirvase de ejecutar el archivo creado por el Makefile:
```bashh
./ nombre_ejecutable.exe
```

5. Recuerde eliminar los archivos binarios creados: 

```bash
make clean
```

## Resumen de la sesión: 

- Expresiones Regulares: Son patrones utilizados para buscar, validar y manipular cadenas de texto. Permiten realizar tareas como buscar coincidencias, hacer reemplazos y validar formatos. Algunos de los operadores más comunes son:

    - .: Coincide con cualquier carácter excepto un salto de línea.
    - *: Coincide con cero o más repeticiones del elemento anterior.
    - +: Coincide con una o más repeticiones del elemento anterior.
    - ?: Indica que el elemento anterior es opcional.
    - []: Define un conjunto de caracteres permitidos.
    - (): Agrupa elementos.
    - |: Alternancia entre opciones.
    - ^ y $: Indican el inicio y el final de una cadena, respectivamente.
- Makefiles: Son archivos que ayudan a gestionar la compilación de proyectos grandes, como programas en C o C++. Están organizados en reglas que definen cómo construir un objetivo (target) a partir de dependencias y comandos. Algunas características importantes son:

    - Targets: Son los resultados que deseas obtener (por ejemplo, un ejecutable).
    - Dependencias: Archivos necesarios para crear el target.
    - Comandos: Instrucciones para compilar o construir los targets.
    - Variables: Para almacenar valores reutilizables.
    - Phony Targets: Acciones que no generan archivos (ej. clean para eliminar archivos temporales).
    - Comentarios: Se indican con # y documentan el Makefile.