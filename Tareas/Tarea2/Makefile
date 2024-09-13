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

# Definir los programas y sus fuentes
TARGET = tienda_online
SRCS = src$(PATHSEP)main.cpp \
       src$(PATHSEP)Cliente.cpp \
       src$(PATHSEP)ClientePremium.cpp \
       src$(PATHSEP)ClienteRegular.cpp \
       src$(PATHSEP)Function.cpp \
       src$(PATHSEP)Tienda.cpp \
       src$(PATHSEP)ProductoDigital.cpp \
       src$(PATHSEP)ProductoFisico.cpp \
       src$(PATHSEP)Producto.cpp 
       
HEADERS = src$(PATHSEP)Cliente.hpp \
          src$(PATHSEP)ClientePremium.hpp \
          src$(PATHSEP)ClienteRegular.hpp \
          src$(PATHSEP)Function.hpp \
          src$(PATHSEP)Tienda.hpp \
          src$(PATHSEP)ProductoDigital.hpp \
          src$(PATHSEP)ProductoFisico.hpp \
          src$(PATHSEP)Producto.hpp 

# Regla para compilar el programa
all: $(TARGET)$(EXE_EXT)

$(TARGET)$(EXE_EXT): $(SRCS) $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $(SRCS)

# Ejecutar el programa
run: $(TARGET)$(EXE_EXT)
	$(RUN) $(TARGET)$(EXE_EXT)

# Limpiar los binarios
clean:
	$(RM) $(TARGET)$(EXE_EXT)
