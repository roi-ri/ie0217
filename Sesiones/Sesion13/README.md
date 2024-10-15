# Dentro de esta sección se presenta el apartado para la sesión # 13 del curso IE0217.


### Instrucciones para la ejecución de los programas

1. Navegue hasta el directorio donde se encuentra la sesión13  utilizando el comando `cd`

```bash
# en este caso puede que la ruta dea la siguiente:
cd /ie0217/Sesiones/Sesion13
```

2. Para el archivo de expreciones regulares ejecute el siguiente comando: 

```bash
# Para MongoDB.cpp
g++ -std=c++17 -I/usr/local/include/bsoncxx/v_noabi -I/usr/local/include/mongocxx/v_noabi -I/usr/local/include/bsoncxx/v_noabi/bsoncxx/third_party/mnmlstc -L/usr/local/lib -lbsoncxx -lmongocxx -o main MongoDB.cpp


# Para AtlasConection: 
g++ -std=c++11 -o AtlasConnection AtlasConection.cpp \
-I/opt/homebrew/include/mongocxx/v_noabi \
-I/opt/homebrew/include/bsoncxx/v_noabi \
-I/opt/homebrew/Cellar/mongo-cxx-driver/3.10.2/include/bsoncxx/v_noabi/bsoncxx/third_party/mnmlstc \
-L/opt/homebrew/lib -lmongocxx -lbsoncxx

```

## Resumen de la sesion 13

### Bases de datos NoSQL


- Bases de datos clave-valor:

    - Almacenan datos como pares clave-valor.
    - Motores populares: Redis y DynamoDB.
    - Usos: Cachés, sesiones de usuario, almacenamiento de configuraciones.
    - Ventajas: Alto rendimiento y escalabilidad.

- Bases de datos column-family:

    - Agrupan datos en filas identificadas por claves (Row Key) y permiten un conjunto flexible de columnas.
    - Motores populares: Apache Cassandra y HBase.
    - Usos: Análisis de big data y almacenes de datos.
    - Ventajas: Alta escalabilidad y rendimiento.

- Bases de datos de grafos:

    - Almacenan datos como nodos (entidades) y aristas (relaciones).
    - Motores populares: Neo4j y OrientDB.
    - Usos: Redes sociales, motores de recomendación, análisis de redes.
    - Ventajas: Eficiencia en consultas de relaciones y escalabilidad.

- Bases de datos documentales:

    - Almacenan datos en documentos, generalmente en formato JSON o BSON.
    - Motores populares: MongoDB y CouchDB.
    - Usos: Aplicaciones web y almacenamiento de datos semiestructurados.
    - Ventajas: Flexibilidad de esquema y manejo de datos jerárquicos.


Se detalla MongoDB, incluyendo sus características como NoSQL, su orientación a documentos, su esquema flexible, alta disponibilidad y escalabilidad. Además, se cubre MongoDB Atlas, un servicio de base de datos en la nube que gestiona la configuración y operación de MongoDB.