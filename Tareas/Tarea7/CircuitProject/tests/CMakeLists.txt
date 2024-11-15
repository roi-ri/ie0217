# Add the test executable
add_executable(run_tests test.cpp)

# Link GoogleTest and the main library
target_link_libraries(run_tests gtest gtest_main circ_lib)

# Add the test to CMake
add_test(NAME CircuitTests COMMAND run_tests)