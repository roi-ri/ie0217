# Configuración del compilador y las banderas
CC = g++
CFLAGS = -Wall -std=c++11

# Detectar el sistema operativo
ifeq ($(OS),Windows_NT)
    EXE_EXT = .exe
    RM = del
    RUN = $(TARGET)
    PATHSEP = \\
else ifeq ($(shell uname), Darwin)
    EXE_EXT =
    RM = rm -f
    RUN = ./$(TARGET)
    PATHSEP = /
else
    EXE_EXT =
    RM = rm -f
    RUN = ./$(TARGET)
    PATHSEP = /
endif

# Definir los ejecutables y sus fuentes
    # Programa de benchmarking
TARGET = proyecto     # Programa del proyecto


# Archivos fuente para el programa del proyecto
SRC = $(PATHSEP)main.cpp \
        $(PATHSEP)Proyecto.cpp \
        $(PATHSEP)Tarea.cpp

# Definir los headers específicos para cada ejecutable
HEADERS2 = src$(PATHSEP)Proyecto.hpp \
           src$(PATHSEP)Tarea.hpp

# Reglas para compilar ambos programas
all: $(TARGET)$(EXE_EXT)


$(TARGET)$(EXE_EXT): $(SRC) $(HEADERS2)
	$(CC) $(CFLAGS) -o $@ $(SRC)

# Ejecutar los programas
run1: $(TARGET1)$(EXE_EXT)
	$(RUN) $(TARGET1)$(EXE_EXT)

run2: $(TARGET)$(EXE_EXT)
	$(RUN) $(TARGET)$(EXE_EXT)

# Limpiar los binarios
clean:
	$(RM)  $(TARGET)$(EXE_EXT)

.PHONY: all run1 run2 clean
