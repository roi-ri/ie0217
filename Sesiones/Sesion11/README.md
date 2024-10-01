# Sesión # 11 IE0217.

# Bases de Datos y SQL

## ¿Qué es una base de datos?
### Bases de Datos y SQL

Una **base de datos** es un sistema organizado que permite almacenar y recuperar datos de manera eficiente. Las bases de datos se pueden clasificar en dos categorías principales: 

Las **bases de datos relacionales** almacenan datos en tablas, que están organizadas en filas (registros) y columnas (atributos). Estas tablas están relacionadas entre sí mediante claves, lo que permite establecer conexiones entre diferentes conjuntos de datos.

Por otro lado, las **bases de datos no relacionales** ofrecen una forma más flexible de almacenar información. Estos sistemas pueden utilizar formatos como documentos JSON, pares clave-valor o estructuras de grafos, lo que les permite adaptarse mejor a datos no estructurados o semi-estructurados.

### ¿Qué es SQL?

En cuanto a SQL, que significa **Structured Query Language** (Lenguaje de Consulta Estructurada), es el lenguaje estándar utilizado para interactuar con bases de datos relacionales. 

Los principales elementos de SQL incluyen:

- Una **tabla** es un conjunto de datos organizados en filas y columnas, donde se almacena la información.
- Una **fila** (también conocida como registro) representa una entrada específica dentro de una tabla.
- Una **columna** es un atributo o característica que describe los datos contenidos en la tabla.
- La **clave primaria** es un identificador único asignado a cada registro en una tabla, asegurando que no haya duplicados.
- La **clave externa** es un campo en una tabla que se refiere a la clave primaria de otra tabla, permitiendo establecer relaciones entre ellas.
- Un **índice** es una estructura que mejora la velocidad de búsqueda en una o más columnas, facilitando el acceso a los datos.

# Creación y Eliminación de Bases de Datos

| Comando              | Descripción                                                                                 | Ejemplo SQL                                                                                                       |
|----------------------|---------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------|
| **CREATE DATABASE**   | Crea una nueva base de datos en el sistema.                                                 | ```sql <br> CREATE DATABASE Tienda; <br> ```                                                                      |
| **DROP DATABASE**     | Elimina una base de datos existente.                                                        | ```sql <br> DROP DATABASE Tienda; <br> ```                                                                        |

---

# Creación y Eliminación de Tablas

| Comando              | Descripción                                                                                 | Ejemplo SQL                                                                                                       |
|----------------------|---------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------|
| **CREATE TABLE**      | Crea una nueva tabla dentro de una base de datos.                                           |CREATE TABLE Clientes ( <br> cliente_id INT PRIMARY KEY, <br> nombre VARCHAR(100), <br> email VARCHAR(100) <br> ); <br>  |
| **DROP TABLE**        | Elimina una tabla existente de la base de datos.                                            | DROP TABLE Clientes; <br>                                                                      |
| **ALTER TABLE**       | Modifica la estructura de una tabla existente (agregar, eliminar o modificar columnas).      |  ALTER TABLE Clientes <br> ADD telefono VARCHAR(15); <br>                                     |

### Ejemplo de creación de una tabla:

```sql
CREATE TABLE Usuarios (
  id INT PRIMARY KEY,
  nombre VARCHAR(100),
  correo VARCHAR(100)
);
```
# Operaciones CRUD en SQL

| Operación   | Descripción                                                  | Ejemplo SQL                                                                                               |
|-------------|--------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------|
| **CREATE**  | Se usa para crear una nueva tabla en la base de datos.        |  CREATE TABLE Clientes ( <br> cliente_id INT PRIMARY KEY, <br> nombre VARCHAR(100), <br> email VARCHAR(100) <br> ); <br>  |
| **READ**    | Se usa para consultar datos de una tabla. Puedes seleccionar todas o algunas columnas. |SELECT * FROM Clientes; <br> <br> SELECT nombre, email FROM Clientes WHERE cliente_id = 1; <br> |
| **UPDATE**  | Se usa para modificar datos de registros existentes en la tabla. | UPDATE Clientes <br> SET nombre = 'Carlos Pérez', email = 'carlos@gmail.com' <br> WHERE cliente_id = 1; <br> |
| **DELETE**  | Se usa para eliminar registros de una tabla.                 | DELETE FROM Clientes <br> WHERE cliente_id = 1; <br>                                        |


# Filtrado y Ordenación de Datos

| Comando        | Descripción                                                  | Ejemplo SQL                                                                                     |
|----------------|--------------------------------------------------------------|-------------------------------------------------------------------------------------------------|
| **WHERE**      | Filtra los resultados basados en una condición específica.    | SELECT nombre, email <br> FROM Clientes <br> WHERE email LIKE '%gmail.com'; <br> |
| **ORDER BY**   | Ordena los resultados en orden ascendente o descendente.      | SELECT nombre, email <br> FROM Clientes <br> ORDER BY nombre ASC; <br>            |
| **LIMIT**      | Limita el número de registros devueltos por una consulta.     |   SELECT nombre, email <br> FROM Clientes <br> LIMIT 5; <br>                      |
| **OFFSET**     | Omite un número de registros antes de comenzar a devolverlos. |  SELECT nombre, email <br> FROM Clientes <br> LIMIT 5 OFFSET 10; <br>          |

---

# Joins en SQL

| Tipo de Join         | Descripción                                                                             | Ejemplo SQL                                                                                                      |
|----------------------|-----------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------|
| **INNER JOIN**        | Selecciona filas que tienen coincidencias en ambas tablas.                              | SELECT Usuarios.nombre, Ordenes.orden_id <br> FROM Usuarios <br> INNER JOIN Ordenes ON Usuarios.id = Ordenes.usuario_id; <br> |
| **LEFT JOIN**         | Selecciona todas las filas de la tabla izquierda, incluyendo coincidencias de la derecha.| SELECT Usuarios.nombre, Ordenes.orden_id <br> FROM Usuarios <br> LEFT JOIN Ordenes ON Usuarios.id = Ordenes.usuario_id; <br> |
| **RIGHT JOIN**        | Selecciona todas las filas de la tabla derecha, incluyendo coincidencias de la izquierda.|SELECT Usuarios.nombre, Ordenes.orden_id <br> FROM Usuarios <br> RIGHT JOIN Ordenes ON Usuarios.id = Ordenes.usuario_id; <br>  |
| **FULL OUTER JOIN**   | Selecciona todas las filas de ambas tablas, completando con `NULL` donde no haya coincidencias. | SELECT Usuarios.nombre, Ordenes.orden_id <br> FROM Usuarios <br> FULL OUTER JOIN Ordenes ON Usuarios.id = Ordenes.usuario_id; <br>  |

---

# Claves 

| Tipo de Clave        | Descripción                                                                                 | Ejemplo SQL                                                                                                       |
|----------------------|---------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------|
| **Clave primaria**    | Identifica de manera única cada registro en una tabla.                                       | CREATE TABLE Productos ( <br> producto_id INT PRIMARY KEY, <br> nombre VARCHAR(50) <br> ); <br>   |
| **Clave externa**     | Crea una relación entre dos tablas, haciendo referencia a una clave primaria en otra tabla.  | CREATE TABLE Ordenes ( <br> orden_id INT PRIMARY KEY, <br> producto_id INT, <br> FOREIGN KEY (producto_id) REFERENCES Productos(producto_id) <br> ); <br>  |

# Restricciones (Constraints) en SQL
| Restricción           | Descripción                                                                                 | Ejemplo SQL                                                                                                       |
|-----------------------|---------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------|
| **NOT NULL**          | La columna no puede contener valores `NULL`.                                                 | CREATE TABLE Usuarios ( <br> id INT PRIMARY KEY, <br> nombre VARCHAR(100) NOT NULL <br> ); <br>    |
| **UNIQUE**            | Garantiza que los valores de una columna sean únicos.                                        | CREATE TABLE Clientes ( <br> email VARCHAR(100) UNIQUE <br> ); <br>                          |
| **CHECK**             | Establece una condición que los datos deben cumplir.                                         | CREATE TABLE Empleados ( <br> salario DECIMAL(10, 2), <br> CHECK (salario > 0) <br> ); <br>       |
| **DEFAULT**           | Establece un valor predeterminado cuando no se proporciona uno.                              | CREATE TABLE Productos ( <br> stock INT DEFAULT 100 <br> ); <br>                                  |

---

# Copias de seguridad y restauración

| Comando              | Descripción                                                                                 | Ejemplo SQL                                                                                                       |
|----------------------|---------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------|
| **BACKUP DATABASE**   | Crea una copia de seguridad de la base de datos.                                            | BACKUP DATABASE Tienda <br> TO DISK = 'C:/backup/tienda.bak';                             |

---

# Seguridad: SQL Injection

| Concepto            | Descripción                                                                                  | Ejemplo SQL                                                                                                       |
|---------------------|----------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------|
| **SQL Injection**    | Técnica maliciosa que explota vulnerabilidades en la entrada de datos para ejecutar comandos SQL. | SELECT * FROM Usuarios WHERE nombre = '' OR '1' = '1'; <br>                                    |
