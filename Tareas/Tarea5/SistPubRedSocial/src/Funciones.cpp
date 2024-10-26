#include "Funciones.hpp"
#include <mongocxx/exception/exception.hpp>

/**
 * @brief Inserta una nueva publicación en la colección.
 *
 * Esta función construye un documento BSON a partir de la publicación
 * y lo inserta en la colección especificada. Maneja excepciones
 * en caso de errores durante la inserción.
 *
 * @param collection Colección de MongoDB donde se insertará la publicación.
 * @param publicacion La publicación que se va a insertar.
 */
void insertarPublicacion(mongocxx::collection& collection, const Publicacion& publicacion) {
    bsoncxx::builder::stream::document document{};
    document << "autor" << publicacion.autor
             << "contenido" << publicacion.contenido
             << "fecha" << publicacion.fecha;

    try {
        // Intentar insertar la publicación
        collection.insert_one(document.view());
    } catch (const mongocxx::exception& e) {
        std::cerr << "Error al insertar la publicación: " << e.what() << "\n";
    }
}

/**
 * @brief Consulta todas las publicaciones en la colección.
 *
 * Esta función obtiene y muestra todas las publicaciones almacenadas
 * en la colección especificada.
 *
 * @param collection Colección de MongoDB de la que se consultarán las publicaciones.
 */
void consultarPublicaciones(mongocxx::collection& collection) {
    auto cursor = collection.find({});
    for (auto&& doc : cursor) {
        std::cout << bsoncxx::to_json(doc) << std::endl;
    }
}

/**
 * @brief Consulta publicaciones por autor.
 *
 * Esta función busca y muestra todas las publicaciones realizadas por un autor específico.
 *
 * @param collection Colección de MongoDB de la que se consultarán las publicaciones.
 * @param autor El autor cuyas publicaciones se quieren consultar.
 */
void consultarPublicacionesPorAutor(mongocxx::collection& collection, const std::string& autor) {
    bsoncxx::builder::stream::document filter;
    filter << "autor" << autor;

    auto cursor = collection.find(filter.view());
    for (auto&& doc : cursor) {
        std::cout << bsoncxx::to_json(doc) << std::endl;
    }
}

/**
 * @brief Actualiza el contenido de una publicación existente.
 *
 * Esta función busca una publicación por autor y fecha, y actualiza su contenido
 * con el nuevo valor proporcionado.
 *
 * @param collection Colección de MongoDB donde se encuentra la publicación.
 * @param autor El autor de la publicación que se va a actualizar.
 * @param fecha La fecha de la publicación que se va a actualizar.
 * @param nuevoContenido El nuevo contenido que se establecerá en la publicación.
 */
void actualizarContenidoPublicacion(mongocxx::collection& collection, const std::string& autor, const std::string& fecha, const std::string& nuevoContenido) {
    bsoncxx::builder::stream::document filter;
    filter << "autor" << autor << "fecha" << fecha;

    bsoncxx::builder::stream::document update;
    update << "$set" << bsoncxx::builder::stream::open_document << "contenido" << nuevoContenido << bsoncxx::builder::stream::close_document;

    auto result = collection.update_one(filter.view(), update.view());
    if (result) {
        std::cout << "Publicación actualizada" << std::endl;
    } else {
        std::cerr << "Error al actualizar la publicación" << std::endl;
    }
}

/**
 * @brief Elimina una publicación de la colección.
 *
 * Esta función busca y elimina una publicación específica en la colección
 * según el autor y la fecha proporcionados.
 *
 * @param collection Colección de MongoDB de la que se eliminará la publicación.
 * @param autor El autor de la publicación que se va a eliminar.
 * @param fecha La fecha de la publicación que se va a eliminar.
 */
void eliminarPublicacion(mongocxx::collection& collection, const std::string& autor, const std::string& fecha) {
    bsoncxx::builder::stream::document filter;
    filter << "autor" << autor << "fecha" << fecha;

    auto result = collection.delete_one(filter.view());
    if (result && result->deleted_count() == 1) {
        std::cout << "Publicación eliminada" << std::endl;
    } else {
        std::cerr << "No se encontró la publicación o ocurrió un error" << std::endl;
    }
}

/**
 * @brief Marca una publicación como destacada o no destacada.
 *
 * Esta función actualiza el estado de destacado de una publicación según
 * el autor y la fecha proporcionados.
 *
 * @param collection Colección de MongoDB donde se encuentra la publicación.
 * @param autor El autor de la publicación que se va a marcar.
 * @param fecha La fecha de la publicación que se va a marcar.
 * @param destacado Estado de destacado a establecer (true o false).
 */
void marcarPublicacionDestacada(mongocxx::collection& collection, const std::string& autor, const std::string& fecha, bool destacado) {
    bsoncxx::builder::stream::document filter;
    filter << "autor" << autor << "fecha" << fecha;

    bsoncxx::builder::stream::document update;
    update << "$set" << bsoncxx::builder::stream::open_document << "destacado" << destacado << bsoncxx::builder::stream::close_document;

    auto result = collection.update_one(filter.view(), update.view());
    if (result) {
        std::cout << "Publicación marcada como destacado: " << destacado << std::endl;
    } else {
        std::cerr << "Error al actualizar la publicación" << std::endl;
    }
}