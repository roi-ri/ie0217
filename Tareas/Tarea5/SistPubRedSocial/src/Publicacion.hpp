#ifndef PUBLICACION_HPP
#define PUBLICACION_HPP

#include <string>
#include <vector>
#include <tuple>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>

using namespace std; 



class Publicacion {
    public: 
        string autor; 
        string contenido; 
        string fecha; 
        bool destacada; 
        vector<tuple<string, string, string>> comentarios; 

        Publicacion(const string& autor, const strign& contenido, const string&  fecha) : autor (autor), contenido(contenido, fecha(fecha), destacada(false)){}

        void agregarComent(const string& usuarion, const strign& comentario, const string& fechaComentario);
        void marcarDestacado(bool estado);

        bsoncxx::document::value toBSON() const; 
}






#endif //PUBLICACION_HPP
