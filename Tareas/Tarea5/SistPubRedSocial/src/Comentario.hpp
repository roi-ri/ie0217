// Comentario.hpp
#ifndef COMENTARIO_HPP
#define COMENTARIO_HPP

#include <string>

class Comentario {
public:
    Comentario(const std::string& autor, const std::string& contenido, const std::string& fecha)
        : autor(autor), contenido(contenido), fecha(fecha) {}

    std::string getAutor() const { return autor; }
    std::string getContenido() const { return contenido; }
    std::string getFecha() const { return fecha; }

private:
    std::string autor;
    std::string contenido;
    std::string fecha;
};

#endif // COMENTARIO_HPP
