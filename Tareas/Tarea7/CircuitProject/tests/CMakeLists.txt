cmake_minimum_required(VERSION 3.10)
project(CircuitProject)

# Define the source files for the main executable
set(SOURCES src/main.cpp src/Inventario.cpp src/Circuito.cpp)

# Create the main executable
add_executable(circuit_project ${SOURCES})

# Link GoogleTest as a subdirectory
add_subdirectory(googletest)

# Include directories for GoogleTest
include_directories(googletest/googletest/include)

# Enable testing
enable_testing()

# Add the subdirectory for tests
add_subdirectory(tests)