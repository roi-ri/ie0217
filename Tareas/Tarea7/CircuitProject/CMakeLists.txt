cmake_minimum_required(VERSION 3.10)

# Specify the project name
project(CircuitProject)

# Define the circ_lib library (if it's supposed to be a library)
add_library(circ_lib STATIC src/CircLib.cpp)  # Make sure the file exists or remove this line if not needed

# Define the source files for the main executable
set(SOURCES src/main.cpp src/Inventario.cpp src/Circuito.cpp)

# Create the main executable
add_executable(circuit_project ${SOURCES})

# Link the circ_lib library to the main executable
target_link_libraries(circuit_project circ_lib)

# Include GoogleTest as a subdirectory
add_subdirectory(googletest)

# Include directories for GoogleTest
include_directories(googletest/googletest/include)

# Enable testing
enable_testing()

# Add the subdirectory for tests
add_subdirectory(tests)