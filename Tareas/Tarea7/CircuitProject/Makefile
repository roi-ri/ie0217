# Configuración del compilador y las banderas
CC = g++
CXX_STANDARD = c++14
CFLAGS = -Wall -std=$(CXX_STANDARD)

# Rutas para Google Test
GTEST_INCLUDE = /opt/homebrew/opt/googletest/include
GTEST_LIB = /opt/homebrew/opt/googletest/lib

# Archivos fuente y ejecutables
SRC_DIR = src
TEST_DIR = tests

MAIN_SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/Inventario.cpp $(SRC_DIR)/Circuito.cpp
TEST_SRCS = $(TEST_DIR)/test.cpp $(SRC_DIR)/Inventario.cpp $(SRC_DIR)/Circuito.cpp

MAIN_EXEC = CircuitProject
TEST_EXEC = TestProject

# Reglas
all: $(MAIN_EXEC) $(TEST_EXEC)

$(MAIN_EXEC): $(MAIN_SRCS)
	$(CC) $(CFLAGS) -o $@ $(MAIN_SRCS)

$(TEST_EXEC): $(TEST_SRCS)
	$(CC) $(CFLAGS) -I$(GTEST_INCLUDE) -L$(GTEST_LIB) -lgtest -lgtest_main -pthread -o $@ $(TEST_SRCS)

run: $(MAIN_EXEC)
	./$(MAIN_EXEC)

test: $(TEST_EXEC)
	./$(TEST_EXEC)

# Limpiar archivos generados
clean:
	rm -f $(MAIN_EXEC) $(TEST_EXEC)

.PHONY: all run test clean
