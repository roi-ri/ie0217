#ifndef CANCION_HPP
#define CANCION_HPP

#include <string>
using namespace std; 

/**
 * @class Cancion
 * @brief Representa una canción con su nombre, artista y duración.
 */
class Cancion {
private:
   string nombre; ///< Nombre de la canción
   string artista; ///< Artista de la canción
    double duracion; ///< Duración de la canción en minutos

public:
    /**
     * @brief Constructor de la clase Cancion.
     * @param nombre Nombre de la canción.
     * @param artista Artista de la canción.
     * @param duracion Duración de la canción en minutos.
     */
    Cancion(const string& nombre, const string& artista, double duracion)
        : nombre(nombre), artista(artista), duracion(duracion) {}

    /**
     * @brief Obtiene el nombre de la canción.
     * @return El nombre de la canción.
     */
    string getNombre() const { return nombre; }
    /**
     * @brief Obtiene el artista de la canción.
     * @return El artista de la canción.
     */
    string getArtista() const { return artista; }
    /**
     * @brief Obtiene la duración de la canción.
     * @return La duración de la canción en minutos.
     */
    double getDuracion() const { return duracion; }
    /**
     * @brief Modifica el nombre de la canción.
     * @param nuevoNombre El nuevo nombre para la canción.
     */
    void setNombre(const string& nuevoNombre) { nombre = nuevoNombre; }
    /**
     * @brief Modifica el artista de la canción.
     * @param nuevoArtista El nuevo artista para la canción.
     */
    void setArtista(const string& nuevoArtista) { artista = nuevoArtista; }
    /**
     * @brief Modifica la duración de la canción.
     * @param nuevaDuracion La nueva duración de la canción en minutos.
     */
    void setDuracion(double nuevaDuracion) { duracion = nuevaDuracion; }
};

#endif


