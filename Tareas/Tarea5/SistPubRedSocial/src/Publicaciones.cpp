#include "Publicaciones.hpp"

void Publicacion::agregarComent(const std::string& usuario, const std::string& comentario, const std::string& fechaComentario) {
    /**
     * @brief Agrega un comentario a la publicación.
     *
     * Este método permite agregar un comentario a la lista de comentarios de la publicación.
     *
     * @param usuario Nombre del usuario que realiza el comentario.
     * @param comentario El contenido del comentario.
     * @param fechaComentario La fecha en que se realizó el comentario.
     */
    comentarios.emplace_back(usuario, comentario, fechaComentario);
}

void Publicacion::marcarDestacado(bool estado) {
    /**
     * @brief Marca la publicación como destacada o no.
     *
     * Este método permite cambiar el estado de la publicación a destacada.
     *
     * @param estado Valor booleano que indica si la publicación debe ser marcada como destacada (true) o no (false).
     */
    destacado = estado;
}

bsoncxx::document::value Publicacion::toBSON() const {
    /**
     * @brief Convierte la publicación a un documento BSON.
     *
     * Este método convierte la publicación a un formato BSON para ser almacenado en la base de datos.
     *
     * @return bsoncxx::document::value Documento BSON que representa la publicación.
     */
    bsoncxx::builder::stream::document document{};
    document << "autor" << autor
             << "contenido" << contenido   
             << "fecha" << fecha
             << "destacado" << destacado; 
            
    bsoncxx::builder::stream::array commentsArray;
    for (const auto& [usuario, comentario, fechaComentario] : comentarios) {
        bsoncxx::builder::stream::document commentDoc{};
        commentDoc << "usuario" << usuario << "comentario" << comentario << "fechaComentario" << fechaComentario;
        commentsArray << commentDoc; 
    }

    document << "comentarios" << commentsArray;
    return document.extract(); 
}
