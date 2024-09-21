#include <iostream>
#include "FileReader.hpp"
#include "TextProcessor.hpp"
#include "RegexUtils.hpp"
#include "Exceptions.hpp"

// Función principal del programa.
// Recibe la ruta de un archivo de texto como argumento.
// Lee el archivo, cuenta las líneas no vacías, busca números y los reemplaza por una etiqueta.
int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <archivo_texto>" << std::endl;
        return 1; // Retorna 1 si no se proporciona el archivo correctamente.
    }

    std::string filePath = argv[1];// guarda la ruta del archivo.
    std::vector<std::string> lines;// Contenedor que almacena las líneas del archivo.

    try {
        // Crea un FileReader para leer el archivo especificado.
        FileReader<std::vector<std::string> >fileReader(filePath);
        fileReader.readFile(lines);
        
        std::cout << "Archivo leído correctamente. Total de líneas: " << lines.size() << std::endl;

        // Procesar el texto utilizando una lambda que cuenta las líneas
        int lineCount = 0;
        processText(lines, [&](const std::string& line) {
            if (!line.empty()) {
                lineCount++;
            }
        });
        std::cout << "Líneas no vacías: " << lineCount << std::endl;

        // Buscar un patrón con expresiones regulares
        std::string pattern = "\\d+";  // Busca cualquier número en las líneas
        std::vector<std::string> matchedLines = regexSearch(lines, pattern);
        std::cout << "Líneas que contienen números: " << matchedLines.size() << std::endl;

        // Reemplazar los números con una etiqueta
        regexReplace(lines, pattern, "[Número]");
        std::cout << "Números reemplazados en las líneas." << std::endl;

    } catch (const FileNotFoundException& e) {
        std::cerr << e.what() << std::endl; // Manejo de excepciones si el archivo no se encuentra.
        return 1;
    } catch (const RegexException& e) {
        std::cerr << e.what() << std::endl; // Maneja excepciones si hay un error en las expresiones regulares.
        return 1;
    }

    return 0; 
}
