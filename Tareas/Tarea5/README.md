<h1 style="text-align: center;">
    Tarea 4 <br><br>
    Estructuras de Datos y Algoritmos para Ingeniería
</h1>

<h3 style="text-align: center;">
    Profesor: Esteban Badilla Alvarado <br><br>
    Estudiante: Rodrigo Sánchez Araya, C37259
</h3>

## Instrucciones para Ejecución de los Programas




## Parte Teórica

1. **Explique la diferencia entre bases de datos relacionales y no relacionales en términos de estructura de datos, casos de uso y escalabilidad.**  
  **R/** Las bases de datos **relacionales** utilizan una estructura tabular con tablas relacionadas entre sí, son ideales para aplicaciones con transacciones complejas y requieren consistencia. Las **no relacionales** (NoSQL) usan estructuras flexibles (como documentos o pares clave-valor), son escalables horizontalmente y adecuadas para grandes volúmenes de datos no estructurados.

2. **¿Qué es SQL y cuál es su importancia en la gestión de bases de datos relacionales? Mencione algunos ejemplos de operaciones comunes que se pueden realizar con SQL.**  
   **R/** SQL (Structured Query Language) es un lenguaje de consulta estructurado esencial para administrar y manipular bases de datos relacionales. Operaciones comunes incluyen `SELECT` para recuperar datos, `INSERT` para agregar nuevos registros, `UPDATE` para modificar datos existentes, y `DELETE` para eliminar registros.

3. **Mencione y explique los componentes de una tabla de bases de datos SQL.**  
  **R/** Los componentes de una tabla SQL incluyen **filas** (cada registro individual), **columnas** (atributos de los registros), **clave primaria** (identificador único), y **claves foráneas** (vinculan tablas relacionadas).

4. **Explique en qué consisten las operaciones CRUD y cómo se implementan en bases de datos relacionales y no relacionales.**  
   **R/** CRUD se refiere a las operaciones de **Crear (Create)**, **Leer (Read)**, **Actualizar (Update)** y **Eliminar (Delete)** datos. En bases de datos relacionales se implementan mediante comandos SQL; en NoSQL, se utilizan métodos específicos del sistema, como operaciones en documentos o pares clave-valor.

5. **Mencione y explique tres comandos SQL básicos, indicando un ejemplo práctico de cómo y cuándo se utilizan.**  
**R/** 
   - `SELECT`: Recupera datos de una tabla. Ejemplo: `SELECT * FROM usuarios;`
   - `INSERT`: Agrega nuevos datos. Ejemplo: `INSERT INTO usuarios (nombre) VALUES ('Carlos');`
   - `DELETE`: Elimina registros. Ejemplo: `DELETE FROM usuarios WHERE id=1;`

6. **Mencione y explique tres comandos SQL de nivel intermedio o avanzado y su importancia en la manipulación de datos.**  
**R/**
   - `JOIN`: Permite combinar datos de varias tablas relacionadas.
   - `GROUP BY`: Agrupa resultados en categorías, útil para estadísticas.
   - `HAVING`: Filtra datos después de usar `GROUP BY`.

7. **Explique qué es un JOIN en SQL y describa al menos tres tipos de JOIN (INNER, LEFT, RIGHT). Mencione cuándo y por qué usar cada uno.**  
**R/**
   `JOIN` es una operación que combina datos de múltiples tablas. `INNER JOIN` muestra registros coincidentes; `LEFT JOIN` mantiene todos los registros de la tabla izquierda; `RIGHT JOIN` muestra todos los registros de la derecha.

8. **Dada la tabla Productos, realiza una consulta para obtener los nombres y precios de los productos de la categoría "Electrónica" o "Deportes", que están en stock y cuyo precio sea menor a 300. Además, utiliza un alias para que el campo precio se muestre como costo, y ordena los resultados de menor a mayor precio.**  
**R/**
   ```sql
   SELECT nombre, precio AS costo
   FROM productos
   WHERE categoria IN ('Electrónica', 'Deportes') AND en_stock = true AND precio < 300
   ORDER BY costo ASC;
   ```

9. **¿Cómo podrías seleccionar los nombres de los productos que tienen el color "azul" en su información de detalles (detalles_color) y que pesen menos de 1 kg (detalles_peso)? Ordena los resultados en orden alfabético por nombre.**
**R/**
```sql
SELECT nombre
FROM productos
WHERE detalles_color = 'Azul' AND detalles_peso < 1
ORDER BY nombre ASC;
```

10. **Dada la tabla Productos, realiza una consulta para obtener el precio promedio de todos los productos en la categoría "Hogar" que están disponibles en inventario.**
**R/**
```sql
SELECT AVG(precio) AS precio_prom
FROM productos
WHERE categoria = 'Hogar' AND en_stock = true;
```

11. **¿En qué consiste un ataque de SQL Injection y cómo puede afectar a una base de datos? Menciona al menos tres prácticas recomendadas para prevenir este tipo de ataques en una aplicación que utiliza consultas SQL.**

**R/** SQL Injection ocurre cuando un atacante inserta código SQL malicioso en una consulta, permitiéndole acceder, modificar o eliminar datos no autorizados. Para prevenirlo:

- Utilizar consultas preparadas y parámetros.
- Validar y sanitizar las entradas del usuario.
- Restringir permisos de acceso a la base de datos.

12. **Explique el rol de un servidor y un cliente en un sistema de gestión de bases de datos (DBMS). ¿Cómo interactúan ambos en una arquitectura cliente-servidor y qué características tienen?**

**R/** En un DBMS, el servidor aloja la base de datos y responde a las solicitudes, mientras que el cliente realiza consultas y recibe datos. En una arquitectura cliente-servidor, los clientes envían solicitudes al servidor de base de datos, que procesa y devuelve los resultados.

13.**¿Qué es un motor de bases de datos? Mencione tres ejemplos.**

**R/** Un motor de base de datos es el software que permite crear, leer, actualizar y eliminar datos en una base de datos. Ejemplos incluyen MySQL, PostgreSQL y SQLite.

14. **Explique en qué situaciones es conveniente usar MySQL, considerando el tamaño de la base de datos, el tipo de datos y el tipo de aplicación.**

**R/** MySQL es conveniente para aplicaciones web, bases de datos de tamaño mediano a grande que requieren alta disponibilidad, y estructuras de datos bien definidas. Es popular en aplicaciones LAMP (Linux, Apache, MySQL, PHP) debido a su escalabilidad y soporte para transacciones.

15. **¿Qué características de una base de datos hacen conveniente el uso de SQLite?**
**R/** SQLite es ideal para aplicaciones móviles o embebidas, ya que es ligera, requiere poca configuración, y almacena datos en un solo archivo. No requiere servidor, lo cual es ventajoso para aplicaciones con bajo volumen de datos y uso individual.

16. **Explique cada uno de los tipos de bases de datos NoSQL vistos en clase (clave-valor, familia de columnas, grafos y documentales). Mencione un beneficio específico del uso de cada uno y proporcione un ejemplo de comando o consulta.**

**R/** 

- Clave-Valor: Almacena pares clave-valor, ideal para sesiones de usuario. Ejemplo: ``GET usuario:123``.
- Familia de Columnas: Usa columnas dinámicas, ideal para análisis masivos. Ejemplo: ``SELECT columna1 FROM tabla``.
- Grafos: Conecta nodos y relaciones, ideal para redes sociales. Ejemplo: ``MATCH (n) RETURN n``.
- Documentales: Almacena documentos JSON, ideal para datos heterogéneos. Ejemplo: db.collection.find({"campo": "valor"}).

17. **¿Qué es una colección en MongoDB? ¿Cuál es la diferencia que tiene con respecto a una tabla?**
**R/** En MongoDB, una colección es un conjunto de documentos almacenados, similar a una tabla en bases de datos relacionales. Sin embargo, los documentos dentro de una colección no tienen una estructura fija, a diferencia de las filas de una tabla.

18. **¿Cuáles son las principales diferencias en el rendimiento y escalabilidad entre bases de datos SQL y NoSQL?**
**R/** Las bases de datos SQL suelen escalar verticalmente y priorizan la consistencia y transacciones ACID, mientras que las NoSQL escalan horizontalmente y priorizan flexibilidad y velocidad, siendo más adecuadas para aplicaciones distribuidas y de gran volumen de datos.


## Sistema de Reseñas de Cursos y Profesores

### Filtrado por curso y escuela
### Consulta y Ordenamiento por Calificación y Dificultad

### Búsqueda de Reseñas no Revisadas

### Actualización de Estado de Reseñas

### Consulta con Filtración Compleja y Alias

### Consulta para Eliminar Reseñas





## Sistema de Publicaciones en Red Social

### Insertar una Publicación

### Consultar Publicaciones
#### Consultar todas las publicaciones
#### Consultar publicaciones por autor
#### Ordenr Publicaciones por fecha

### Agregar Comentario a una Publicación

### Actualizar Contenido de una Publicación

### Eliminar una Publicación

### Marcar Publicación como Destacada