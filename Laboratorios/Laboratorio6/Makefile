# Variables
	# Compilador a utilizar (g++)
CXX = g++	
# Opciones de compilación: 
# -std=c++17 para el estándar C++17,
# -Wall para mostrar todas las advertencias,
# -Wextra para advertencias adicionales,
# -O2 para optimización del código.							
CXXFLAGS = -std=c++17 -Wall -Wextra -O2	


# Directorio donde están los archivos fuente.
SRCDIR = src
# Directorio donde se guardarán los archivos objeto.								
OBJDIR = obj
# Directorio donde se generará el ejecutable.
BINDIR = bin
# Nombre del ejecutable que se generará.
TARGET = $(BINDIR)\text_processor.exe


# Archivos fuente y objetos
# Busca todos los archivos .cpp en el directorio de fuentes.
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
# Convierte la lista de fuentes en una lista de objetos.
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Reglas

# Regla por defecto que construye el ejecutable.
all: $(TARGET)

# Regla para crear el ejecutable a partir de los objetos.
$(TARGET): $(OBJECTS)
# Crea el directorio de salida si no existe.
	@if not exist $(BINDIR) mkdir $(BINDIR)
	# Compila los objetos en el ejecutable.
	 # $@ es el objetivo (TARGET) y $^ son las dependencias (OBJECTS).
	$(CXX) $(CXXFLAGS) -o $@ $^

# Regla para compilar cada archivo fuente en un objeto.
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
# Crea el directorio de objetos si no existe.
	@if not exist $(OBJDIR) mkdir $(OBJDIR)
	# $< es el primer prerequisito (archivo fuente),
    # $@ es el objetivo (archivo objeto).
	$(CXX) $(CXXFLAGS) -c $< -o $@


# Regla para limpiar los archivos generados.
clean:
	# Elimina todos los archivos objeto en el directorio de objetos.
	del /Q $(OBJDIR)\*.o
	# Elimina el ejecutable.
	del /Q $(TARGET)

# Regla para ejecutar el programa.
run: $(TARGET)
# Ejecuta el programa con un archivo de datos como argumento.
	$(TARGET) data\file1.txt
	
# Define estas reglas como "no archivos" para evitar confusiones con nombres de archivos.
.PHONY: all clean run
