# Laboratorio # 3 Estructuras Abstractas de datos y Algoritmos para Ingeniería IE0217.



## Profesor: Esteban Badilla Alvarado.
## Estudiante: Rodrigo Sánchez Araya, C37259.

### Gestión de Empleados en C++

Dentro de este laboratorio se realiza la implementación de nuevas formas de utilizar la POO (programación orientada a objetos o OOP por sus siglas en ingles).

Se realiza la introducción a lo que es una clase abstracta la cual se comprende que es una especie de plantilla que se va a utilizar para posteriormente montar las clases que se vana a utilizar dentro del programa, este tipo de clases abstractas cuentan con almenos una declaración virtual pura es decir esta va ir igualada a cero: 

```cpp
  virtual void mostrarInformacion() const = 0;
```

Ya no se va a poder crear ningun objeto basado en esta clase, quienes hereden de esta deben realizar su propia implementación.



### Archivos del Proyecto

1. **empleado.hpp** - Define la clase base `Empleado` con atributos y métodos comunes a todos los empleados. Incluye métodos virtuales puros para ser implementados en clases derivadas.
2. **empleado.cpp** - Implementa los métodos de la clase `Empleado`.
3. **EmpleadoMedioTiempo.hpp** - Define la clase derivada `EmpleadoMedioTiempo` que representa a un empleado a medio tiempo.
4. **empleadoMedioTiempo.cpp** - Implementa los métodos de la clase `EmpleadoMedioTiempo`.
5. **EmpleadoTiempoCompleto.hpp** - Define la clase derivada `EmpleadoTiempoCompleto` que representa a un empleado a tiempo completo.
6. **empleadoTiempoCompleto.cpp** - Implementa los métodos de la clase `EmpleadoTiempoCompleto`.
7. **mian.cpp** - Contiene la función `main()` que crea instancias de los empleados, las muestra en pantalla y luego libera la memoria.

## Compilación y Ejecución

Para compilar y ejecutar el proyecto, se le presentan los siguientes espacios:

1. Abra una terminal en el directorio del proyecto.
```cpp
  //puede que la ruta sea la siguiente:
  cd .\Laboratorios\Laboratorio3\src
```
2. Compile el código con el siguiente comando:

    ```bash
    g++ -o gestion_empleados.exe main.cpp Empleado.cpp EmpleadoMedioTiempo.cpp EmpleadoTiempoCompleto.cpp
    ```

3. Ejecuta el programa:

    ```bash
    ./gestion_empleados.exe
    ```

## Descripción de las Clases

- **Empleado**: Clase base que representa a un empleado con atributos comunes como nombre, ID y salario. Incluye métodos para obtener y modificar estos atributos. Tiene métodos virtuales para mostrar información y obtener el salario.
- **EmpleadoMedioTiempo**: Hereda de `Empleado` y añade atributos específicos para empleados a medio tiempo, como tarifa por hora y horas trabajadas. Sobrescribe el método `getSalario()` para calcular el salario basado en estos atributos.
- **EmpleadoTiempoCompleto**: Hereda de `Empleado` y añade atributos para empleados a tiempo completo, como bonificación y deducción. Sobrescribe el método `getSalario()` para calcular el salario ajustado por bonificación y deducción.

## Uso

El archivo `mian.cpp` contiene la función principal donde se crean instancias de `EmpleadoTiempoCompleto` y `EmpleadoMedioTiempo`, se almacenan en un vector y se muestra su información en pantalla. 


