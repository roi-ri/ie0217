#ifndef REGEXUTILS_HPP
#define REGEXUTILS_HPP

#include <regex>
#include <string>
#include <vector>
#include <stdexcept>

// Función que busca lineas en donde se coincida con el patrón de la expresión regular.
// Recibe un vector de líneas y un patrón como argumentos.
// Devuelve un vector con las líneas que coinciden con el patrón.
// Si el patrón es inválido, lanza una RegexException.
std::vector<std::string> regexSearch(const std::vector<std::string>& lines, const std::string& pattern) {
    std::vector<std::string> matches;
    std::regex regexPattern;

    try {
        regexPattern = std::regex(pattern);
    } catch (const std::regex_error&) {
        throw RegexException("Error: Patrón de expresión regular inválido.");
    }

    for (const auto& line : lines) {
        if (std::regex_search(line, regexPattern)) {
            matches.push_back(line);
        }
    }

    return matches;
}
// Función para reemplazar partes de líneas en un vector según un patrón de expresión regular.
// Recibe un vector de líneas, un patrón y una cadena de reemplazo.
// Modifica las líneas directamente, reemplazando coincidencias con la cadena dada.
// Si el patrón es inválido, lanza una RegexException.
void regexReplace(std::vector<std::string>& lines, const std::string& pattern, const std::string& replacement) {
    std::regex regexPattern;

    try {
        regexPattern = std::regex(pattern);
    } catch (const std::regex_error&) {
        throw RegexException("Error: Patrón de expresión regular inválido.");
    }

    for (auto& line : lines) {
        line = std::regex_replace(line, regexPattern, replacement);
    }
}

#endif // REGEXUTILS_HPP