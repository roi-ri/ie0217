project(CircuitProject)

# Add the source files for the main project
set(SOURCES src/main.cpp src/Inventario.cpp src/Circuito.cpp)

# Create the main executable
add_executable(circuit_project ${SOURCES})

# Add GoogleTest as a subdirectory
add_subdirectory(googletest)

# Link the executable to GoogleTest
target_link_libraries(circuit_project gtest gtest_main)

# Enable testing
enable_testing()

# Add the subdirectory for tests
add_subdirectory(tests)