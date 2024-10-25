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

# Directorios
BINDIR = Ejecutables
SRCDIR_SISTPUB = SistPubRedSocial/src
SRCDIR_SISTRES = SistResCP/src
BUILDDIR_SISTPUB = SistPubRedSocial/build
BUILDDIR_SISTRES = SistResCP/build

# Archivos de origen para SistPubRedSocial
SRCS_SISTPUB = $(SRCDIR_SISTPUB)/Funciones.cpp $(SRCDIR_SISTPUB)/main.cpp $(SRCDIR_SISTPUB)/Publicaciones.cpp
# Archivos de origen para SistResCP
SRCS_SISTRES = $(SRCDIR_SISTRES)/DataBase.cpp $(SRCDIR_SISTRES)/ManejoBaseDatos.cpp $(SRCDIR_SISTRES)/main.cpp

# Archivos de encabezado 
HDRS_SISTPUB = $(SRCDIR_SISTPUB)/Funciones.hpp $(SRCDIR_SISTPUB)/Publicacion.hpp
HDRS_SISTRES = $(SRCDIR_SISTRES)/DataBase.hpp $(SRCDIR_SISTRES)/ManejoBaseDatos.hpp

# Compilador
CXX = g++
CXXFLAGS = -std=c++17

# Librerías y flags
MONGO_FLAGS = -I/usr/local/include/bsoncxx/v_noabi -I/usr/local/include/mongocxx/v_noabi -I/usr/local/include/bsoncxx/v_noabi/bsoncxx/third_party/mnmlstc -L/usr/local/lib -lbsoncxx -lmongocxx
SQLITE_FLAGS = -lsqlite3

# Objetivos
TARGET_PUBRED = $(BINDIR)/SistemaPubliRedSocial$(EXE_EXT)
TARGET_RESCP = $(BINDIR)/SistemaResenProfyCursos$(EXE_EXT)

# Reglas
all: $(BINDIR) $(TARGET_PUBRED) $(TARGET_RESCP)

# Crea el directorio para ejecutables si no existe
$(BINDIR):
	mkdir -p $(BINDIR)

$(TARGET_PUBRED): $(SRCS_SISTPUB)
	$(CXX) $(CXXFLAGS) $(SRCS_SISTPUB) $(MONGO_FLAGS) -o $@ -Wl,-rpath,/usr/local/lib

$(TARGET_RESCP): $(SRCS_SISTRES)
	$(CXX) $(CXXFLAGS) $(SRCS_SISTRES) $(SQLITE_FLAGS) -o $@ -Wl,-rpath,/usr/local/lib

run_pubred: $(TARGET_PUBRED)
	./$(TARGET_PUBRED)

run_rescp: $(TARGET_RESCP)
	./$(TARGET_RESCP)

clean:
	$(RM) $(TARGET_PUBRED) $(TARGET_RESCP)
