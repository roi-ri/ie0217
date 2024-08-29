# Configuración del compilador y las banderas
CC = g++
CFLAGS = -Wall

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

# Definir el programa y sus fuentes
PROGRAMS = conversor
TARGETS = $(addsuffix $(EXE_EXT), $(PROGRAMS))

# Fuentes y encabezados
SRCS = src$(PATHSEP)conversiones.cpp src$(PATHSEP)main.cpp
HEADERS = src$(PATHSEP)conversiones.hpp

# Reglas para compilar el programa
all: $(TARGETS)

conversor$(EXE_EXT): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $(SRCS)

# Ejecutar el programa
run: $(TARGETS)
	$(RUN) $(TARGETS)

# Limpiar todos los programas
clean:
	$(RM) $(TARGETS)
