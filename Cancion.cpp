#include "Cancion.h"
#include <iostream>

// Constructor por defecto
Cancion::Cancion() {
    id_cancion = 0;
    album_id = 0;
    titulo = "";
    reproducciones = 0;
    duracion = "0:00";
}

// Constructor con parámetros
Cancion::Cancion(int id_Cancion, int id_album, std::string titulo, int reproducciones, std::string duracion) {
    this->id_cancion = id_Cancion;
    this->album_id = id_album;
    this->titulo = titulo;
    this->reproducciones = reproducciones;
    this->duracion = duracion;
}

// Métodos getters
int Cancion::getId() const {
    return id_cancion;
}

int Cancion::getAlbumId() const{
    return album_id;
}

std::string Cancion::getTitulo() const {
    return titulo;
}

int Cancion::getReproducciones() const {
    return reproducciones;
}

std::string Cancion::getDuracion() const {
    return duracion;
}

// Verificar si el título coincide con el filtro
bool Cancion::coincideTitulo(const std::string &filtro) const {
    return titulo == filtro;
}

// Operador de comparación para ordenar canciones por ID
bool Cancion::operator<(const Cancion &otra) const {
    return id_cancion < otra.id_cancion;
}

// Método para mostrar información de la canción
void Cancion::mostrarInfo() const {
    std::cout << "ID: " << id_cancion << "\n";
    std::cout << "Título: " << titulo << "\n";
    std::cout << "Álbum ID: " << album_id << "\n";
    std::cout << "Reproducciones: " << reproducciones << "\n";
    std::cout << "Duración: " << duracion << "\n";
}
