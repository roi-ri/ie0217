# Define the circ_lib library
add_library(circ_lib STATIC src/CircLib.cpp)  # Adjust path if needed

# Add the main executable
add_executable(circuit_project ${SOURCES})

# Link circ_lib to the main project
target_link_libraries(circuit_project circ_lib)

# Incluir GoogleTest como subdirectorio
add_subdirectory(googletest)

# Incluir directorios de GoogleTest
include_directories(googletest/googletest/include)

# Enable testing
enable_testing()

# Add the subdirectory for tests
add_subdirectory(tests)