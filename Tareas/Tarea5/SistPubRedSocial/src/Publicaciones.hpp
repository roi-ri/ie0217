#ifndef PUBLICACION_HPP
#define PUBLICACION_HPP

#include <string>
#include <vector>
#include <tuple>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>

using namespace std; 

/**
 * @class Publicacion
 * @brief Clase que representa una publicación en el sistema.
 *
 * Esta clase maneja los detalles de una publicación, incluyendo el autor,
 * el contenido, la fecha y los comentarios asociados.
 */
class Publicacion {
public: 
    string autor; ///< Autor de la publicación
    string contenido; ///< Contenido de la publicación
    string fecha; ///< Fecha de la publicación
    bool destacado; ///< Estado de destacado de la publicación
    vector<tuple<string, string, string>> comentarios; ///< Comentarios de la publicación

    /**
     * @brief Constructor de la clase Publicacion.
     *
     * Este constructor inicializa los atributos de la publicación.
     *
     * @param autor Nombre del autor de la publicación.
     * @param contenido Contenido de la publicación.
     * @param fecha Fecha en que se realizó la publicación.
     */
    Publicacion(const string& autor, const string& contenido, const string& fecha) 
        : autor(autor), contenido(contenido), fecha(fecha), destacado(false) {}

    /**
     * @brief Agrega un comentario a la publicación.
     *
     * Este método permite agregar un comentario a la lista de comentarios de la publicación.
     *
     * @param usuario Nombre del usuario que realiza el comentario.
     * @param comentario El contenido del comentario.
     * @param fechaComentario La fecha en que se realizó el comentario.
     */
    void agregarComent(const string& usuario, const string& comentario, const string& fechaComentario);

    /**
     * @brief Marca la publicación como destacada o no.
     *
     * Este método permite cambiar el estado de la publicación a destacada.
     *
     * @param estado Valor booleano que indica si la publicación debe ser marcada como destacada (true) o no (false).
     */
    void marcarDestacado(bool estado);

    /**
     * @brief Convierte la publicación a un documento BSON.
     *
     * Este método convierte la publicación a un formato BSON para ser almacenado en la base de datos.
     *
     * @return bsoncxx::document::value Documento BSON que representa la publicación.
     */
    bsoncxx::document::value toBSON() const; 
};

#endif // PUBLICACION_HPP
