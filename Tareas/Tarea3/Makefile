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
TARGET1 = BusquedaArbol
TARGET2 = Canciones

SRCS1 = src$(PATHSEP)main.cpp \
        src$(PATHSEP)Node.cpp \
        src$(PATHSEP)BusquedaArbolBinario.cpp

SRCS2 = src$(PATHSEP)mainC.cpp \
        src$(PATHSEP)ListaEnlazada.cpp
# Definir los headers específicos para cada ejecutable
HEADERS1 = src$(PATHSEP)Node.hpp \
           src$(PATHSEP)BusquedaArbolBinario.hpp

HEADERS2 = src$(PATHSEP)NodoC.hpp \
           src$(PATHSEP)Cancion.hpp \
           src$(PATHSEP)ListaEnlazada.hpp

# Reglas para compilar ambos programas
all: $(TARGET1)$(EXE_EXT) $(TARGET2)$(EXE_EXT)

$(TARGET1)$(EXE_EXT): $(SRCS1) $(HEADERS1)
	$(CC) $(CFLAGS) -o $@ $(SRCS1)

$(TARGET2)$(EXE_EXT): $(SRCS2) $(HEADERS2)
	$(CC) $(CFLAGS) -o $@ $(SRCS2)

# Ejecutar los programas
run1: $(TARGET1)$(EXE_EXT)
	$(RUN) $(TARGET1)$(EXE_EXT)

run2: $(TARGET2)$(EXE_EXT)
	$(RUN) $(TARGET2)$(EXE_EXT)

# Limpiar los binarios
clean:
	$(RM) $(TARGET1)$(EXE_EXT) $(TARGET2)$(EXE_EXT)
