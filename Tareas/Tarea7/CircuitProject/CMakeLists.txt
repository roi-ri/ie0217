cmake_minimum_required(VERSION 3.10)
project(CircuitProject)

# Agregar los archivos fuente del proyecto
set(SOURCES src/main.cpp src/Inventario.cpp src/Circuito.cpp)

# Crear la biblioteca principal
add_library(circ_lib ${SOURCES})

# Incluir GoogleTest como subdirectorio
add_subdirectory(googletest)

# Incluir directorios de GoogleTest
include_directories(googletest/googletest/include)

# Configurar pruebas
enable_testing()
add_subdirectory(tests)
