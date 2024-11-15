# Agregar el ejecutable de pruebas
add_executable(run_tests test.cpp)

# Enlazar GoogleTest y la biblioteca de la calculadora
target_link_libraries(run_tests gtest gtest_main circ_lib)

# Agregar prueba a CMake
add_test(NAME CircuitTests COMMAND run_tests)
