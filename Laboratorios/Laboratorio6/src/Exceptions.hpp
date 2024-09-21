#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <stdexcept>
#include <string>

// Clase para representar una excepción cuando un archivo no se encuentra.
class FileNotFoundException : public std::runtime_error {
public:
    // Constructor que recibe un mensaje de error.  
    explicit FileNotFoundException(const std::string& message)
        : std::runtime_error(message) {}
};

// Clase para representar una excepción relacionada con expresiones regulares.
class RegexException : public std::runtime_error {
public:
    // Constructor que recibe un mensaje de error.
    explicit RegexException(const std::string& message)
        : std::runtime_error(message) {}
};

#endif // EXCEPTIONS_HPP
