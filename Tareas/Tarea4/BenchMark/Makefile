# Variables
CC = g++
CXXFLAGS = -Wall -std=c++11

# Detectar el sistema operativo
ifeq ($(OS),Windows_NT)
    EXE_EXT = .exe
    RM = del
    RUN = $(TARGET_BENCHMARK)$(EXE_EXT)
else ifeq ($(shell uname), Darwin)
    EXE_EXT =
    RM = rm -f
    RUN = ./$(TARGET_BENCHMARK)
else
    EXE_EXT =
    RM = rm -f
    RUN = ./$(TARGET_BENCHMARK)
endif

# Definir los ejecutables para los algoritmos de ordenamiento
TARGET_BUBBLE = bubble_sort_exec
TARGET_QUICK = quick_sort_exec
TARGET_SELECTION = selection_sort_exec
TARGET_BENCHMARK = sorting      # Programa de benchmarking

# Archivos fuente
SRCS = main.cpp \
       Sorting.cpp

# Objetivos principales
all: $(TARGET_BUBBLE) $(TARGET_QUICK) $(TARGET_SELECTION) $(TARGET_BENCHMARK)$(EXE_EXT)

# Regla para compilar el ejecutable de Bubble Sort
$(TARGET_BUBBLE): Sorting.o main.o
	$(CC) $(CXXFLAGS) -o $@ Sorting.o main.o -DBUBBLE

# Regla para compilar el ejecutable de Quick Sort
$(TARGET_QUICK): Sorting.o main.o
	$(CC) $(CXXFLAGS) -o $@ Sorting.o main.o -DQUICK

# Regla para compilar el ejecutable de Selection Sort
$(TARGET_SELECTION): Sorting.o main.o
	$(CC) $(CXXFLAGS) -o $@ Sorting.o main.o -DSELECTION

# Regla para compilar el programa de benchmarking
$(TARGET_BENCHMARK)$(EXE_EXT): $(SRCS)
	$(CC) $(CXXFLAGS) -o $@ $(SRCS)

# Compilación de los archivos .cpp a .o
Sorting.o: Sorting.cpp Sorting.hpp
	$(CC) $(CXXFLAGS) -c Sorting.cpp

main.o: main.cpp Sorting.hpp
	$(CC) $(CXXFLAGS) -c main.cpp

# Regla de limpieza
clean:
	$(RM) *.o $(TARGET_BUBBLE) $(TARGET_QUICK) $(TARGET_SELECTION) $(TARGET_BENCHMARK)$(EXE_EXT)

# Ejecutar el programa de benchmarking
run: $(TARGET_BENCHMARK)$(EXE_EXT)
	$(RUN) $(ARGS)

# Ejecutar benchmarks para tamaños específicos
run_benchmarks: $(TARGET_BENCHMARK)$(EXE_EXT)
	@echo "Ejecutando benchmarks para diferentes tamaños de vectores..."
	@for size in 5000 10000 50000 100000 200000 500000; do \
		for i in {1..10}; do \
			echo "Ejecución $$i para tamaño $$size:"; \
			$(RUN) $$size bubble; \
			$(RUN) $$size quick; \
			$(RUN) $$size selection; \
		done; \
	done

# Instrucciones de uso
help:
	@echo "Opciones de uso:"
	@echo "  make                  Compila todos los ejecutables."
	@echo "  make bubble_sort_exec Ejecuta el algoritmo Bubble Sort."
	@echo "  make quick_sort_exec  Ejecuta el algoritmo Quick Sort."
	@echo "  make selection_sort_exec Ejecuta el algoritmo Selection Sort."
	@echo "  make run ARGS='...'  Ejecuta el programa de benchmarking con los argumentos especificados."
	@echo "                        - Por ejemplo: make run ARGS='5000 bubble'"
	@echo "  make run_benchmarks   Ejecuta el programa de benchmarking 10 veces para los tamaños 5000, 10000, 50000, 100000, 200000, y 500000."
	@echo "  make clean            Limpia los archivos generados."
	@echo "  make help             Muestra esta ayuda."

# Instrucciones
.PHONY: all run run_benchmarks clean help
