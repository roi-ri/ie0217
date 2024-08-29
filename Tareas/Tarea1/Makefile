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

# Definir los programas y sus fuentes
PROGRAMS = conversor estadisticas
TARGETS = $(addsuffix $(EXE_EXT), $(PROGRAMS))

# Fuentes y encabezados
SRCS_CONVERSOR = src$(PATHSEP)main1.cpp src$(PATHSEP)conversiones.cpp
SRCS_ESTADISTICAS = src$(PATHSEP)main2.cpp src$(PATHSEP)calcEstadyBusq.cpp
HEADERS = src$(PATHSEP)conversiones.hpp src$(PATHSEP)calcEstadyBusq.hpp

# Reglas para compilar los programas
all: $(TARGETS)

conversor$(EXE_EXT): $(SRCS_CONVERSOR) $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $(SRCS_CONVERSOR)

estadisticas$(EXE_EXT): $(SRCS_ESTADISTICAS) $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $(SRCS_ESTADISTICAS)

# Ejecutar los programas
run-conversor: conversor$(EXE_EXT)
	$(RUN) conversor$(EXE_EXT)

run-estadisticas: estadisticas$(EXE_EXT)
	$(RUN) estadisticas$(EXE_EXT)

# Limpiar todos los programas
clean:
	$(RM) $(TARGETS)
