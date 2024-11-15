cmake_minimum_required(VERSION 3.10)
project(CircuitProject)

# Agregar los archivos fuente del proyecto
set(SOURCES src/main.cpp src/Inventario.cpp src/Circuito.cpp)

# Si el objetivo es un ejecutable, usa add_executable en lugar de add_library
add_executable(circuit_project ${SOURCES})

# Incluir GoogleTest como subdirectorio
add_subdirectory(googletest)  # Esto debería apuntar a la carpeta de GoogleTest que clonamos

# Incluir directorios de GoogleTest
include_directories(googletest/googletest/include)

# Agregar GoogleTest y configurar las pruebas
enable_testing()

# Agregar el subdirectorio de pruebas
add_subdirectory(tests)
