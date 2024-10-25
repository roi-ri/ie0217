#include "Publicacion.hpp"


void Publicacion::agregarComentario(const string& usuario, const string& comentario, const string& fechaComentario){
    comentarios.emplace_back(usuario, comentario, fechaComentario);
}

void Publicacion::marcaDestacada(bool estado){
    destacada = estado;
}

bsoncxx::document::value Publicacion::toBSON() const{
    bsoncxx::builder::stream::document document{};
    document << "autor" << autor
             << "contenido" << contenido   
             << "fecha" << fecha
             << "destacada" << destacada; 
            
    bsoncxx::builder::stream::array commentsArray;
    for (const auto& [usuario, comentario, fechaComentario] : comentarios){
        bsoncxx::builder::stream::document commentDoc{};
        commentDoc << "usuario" << usuario << "comentario" << comentario << "fechaComentario" << fechaComentario;
        commentsArray << commentDoc; 
    }

    document << "comentarios" << commentsArray;
    return document.extract(); 
}