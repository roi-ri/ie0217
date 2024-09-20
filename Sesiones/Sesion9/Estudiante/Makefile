#Nombre de salida del programa
TARGET = gestion_estudiantes.exe

#compilador 
CXXX =g++

#opciones de compilacion
CXXGFLAGS = -Wall -std+c++11

#lista de archivos fuente
SOURCES = main.cpp Estudiante.cpp

#Lista de archivos objeto generados a partir de los archivos fuente
OBJECTS = $(SOURCES: .cpp = .exe)

#Regla para compilar los archivos fuente en archivos objeto
%.exe: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

#REgla para copilar el programa apartir de los archivos objeto
$(TARGET) : $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Regla para limpiar los archivos generados
clean: 	
	del $(TARGET) $(OBJECTS)