#ifndef CANCION_H
#define CANCION_H

#include <string>

class Cancion {
private:
    int id_cancion;      // Identificador único de la canción
    int album_id;        // ID del álbum al que pertenece
    std::string titulo;  // Nombre de la canción
    int reproducciones;  // Número de reproducciones en Spotify
    std::string duracion; // Duración en formato "MM:SS"

public:
    Cancion();

    Cancion(int id_Cancion, int id_album, std::string titulo, int reproducciones, std::string duracion);

    // Getters
    int getId() const;
    int getAlbumId() const;
    std::string getTitulo() const;
    int getReproducciones() const;
    std::string getDuracion() const;

    // Método para verificar si un título coincide con el filtro
    bool coincideTitulo(const std::string &filtro) const;
    void mostrarInfo() const;
    // Sobrecarga de operadores
    bool operator<(const Cancion &otra) const; // Para ordenar por reproducciones

};



#endif //CANCION_H
