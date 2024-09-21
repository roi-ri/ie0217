#ifndef FILEREADER_HPP
#define FILEREADER_HPP

#include <fstream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Exceptions.hpp"


// Clase FileReader:
// Esta clase se utiliza para leer líneas de un archivo y almacenarlas en un contenedor dado.
// El contenedor debe soportar el método push_back para agregar líneas.
// El constructor recibe la ruta del archivo que se va a leer.
template <typename Container>
class FileReader {
public:
    // Constructor que inicializa el objeto FileReader con la ruta del archivo.
    FileReader(const std::string& filePath) : filePath(filePath) {}
    // Método para leer el archivo y almacenar cada línea en el contenedor.
    // Si no se puede abrir el archivo, lanza una FileNotFoundException.
    void readFile(Container& container) {
        std::ifstream file(filePath);
        if (!file.is_open()) {
            throw FileNotFoundException("Error: No se pudo abrir el archivo " + filePath);
        }

        std::string line;
        while (std::getline(file, line)) {
            container.push_back(line);
        }

        file.close();
    }

private:
    std::string filePath;  // Ruta del archivo a leer.
};

#endif // FILEREADER_HPP