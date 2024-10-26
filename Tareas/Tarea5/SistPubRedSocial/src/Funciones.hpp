#ifndef FUNCIONES_HPP
#define FUNCIONES_HPP

#include "Publicaciones.hpp"
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/collection.hpp>
#include <mongocxx/uri.hpp>
#include <iostream>

/**
 * @brief Inserta una nueva publicación en la colección.
 *
 * Esta función toma una referencia a una colección y una publicación, y
 * la inserta en la colección especificada.
 *
 * @param collection Colección de MongoDB donde se insertará la publicación.
 * @param publicacion La publicación que se va a insertar.
 */
void insertarPublicacion(mongocxx::collection& collection, const Publicacion& publicacion);

/**
 * @brief Consulta todas las publicaciones en la colección.
 *
 * Esta función obtiene y muestra todas las publicaciones almacenadas
 * en la colección especificada.
 *
 * @param collection Colección de MongoDB de la que se consultarán las publicaciones.
 */
void consultarPublicaciones(mongocxx::collection& collection);

/**
 * @brief Consulta publicaciones por autor.
 *
 * Esta función busca y muestra todas las publicaciones realizadas por un autor específico.
 *
 * @param collection Colección de MongoDB de la que se consultarán las publicaciones.
 * @param autor El autor cuyas publicaciones se quieren consultar.
 */
void consultarPublicacionesPorAutor(mongocxx::collection& collection, const std::string& autor);

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
void actualizarContenidoPublicacion(mongocxx::collection& collection, const std::string& autor, const std::string& fecha, const std::string& nuevoContenido);

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
void eliminarPublicacion(mongocxx::collection& collection, const std::string& autor, const std::string& fecha);

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
void marcarPublicacionDestacada(mongocxx::collection& collection, const std::string& autor, const std::string& fecha, bool destacado);

// Variables globales de MongoDB
extern mongocxx::instance instance;  ///< Instancia de MongoDB
extern mongocxx::client client;       ///< Cliente de MongoDB
extern mongocxx::database db;         ///< Base de datos de MongoDB
extern mongocxx::collection posts;    ///< Colección de publicaciones de MongoDB

#endif // FUNCIONES_HPP