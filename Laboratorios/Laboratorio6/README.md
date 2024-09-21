# Laboratorio # 6 Estructuras Abstractas de datos y Algoritmos para Ingeniería IE0217.



## Profesor: Esteban Badilla Alvarado.
## Estudiante: Rodrigo Sánchez Araya, C37259.

## Compilación y Ejecución

Para compilar y ejecutar el proyecto, se le presentan los siguientes espacios:

1. Abra una terminal en el directorio del proyecto.
```cpp
  cd .\Laboratorios\Laboratorio6
```
2. Compile el código con el siguiente comando:

    ```bash
      make
    ```


3. Ejecuta el programa:

    ```bash
      make run 
    ```
4. Ejecuta el programa:

    ```bash
        #Si se desea ejecutar el file 2:
      ./bin/text_processor data/file2.txt
    ```
## Explicación del código

El programa realiza las siguientes tareas:

- Lectura de Archivo: Utiliza la clase FileReader para abrir y leer un archivo de texto especificado como argumento de línea de comandos. Cada línea del archivo se almacena en un contenedor (vector).

- Conteo de Líneas No Vacías: Procesa las líneas leídas utilizando la función processText, que aplica una función (lambda) para contar cuántas de esas líneas no están vacías.

- Búsqueda de Números: Utiliza expresiones regulares para buscar líneas que contienen números. El patrón de búsqueda es ``\\d+``, que coincide con uno o más dígitos.

- Reemplazo de Números: Reemplaza todos los números encontrados en las líneas con la etiqueta [Número] usando la función regexReplace.

- Manejo de Errores: Captura excepciones para manejar errores como la imposibilidad de abrir el archivo o problemas con las expresiones regulares.


## Imagenes sobre la ejecucion de los codigos

![Ejecución Laboratorio 6](/Pruebas/Lab6Ejec.jpeg)
