#ifndef ALBUM_H
#define ALBUM_H

#include <iostream>

class Album {
private:
    int id;
    std::string titulo;
    int anio;
    bool es_De_Estudio;
    int* canciones; // Arreglo dinámico de canciones (IDs)
    int cantidadCanciones; // Número actual de canciones
    int capacidad; // Capacidad del arreglo
    void redimensionar(int nuevaCapacidad); // Función para cambiar tamaño

public:
    Album(int id, std::string titulo, int anio, bool es_De_Estudio);
    ~Album(); // Destructor para liberar memoria
    void agregarCancion(int idCancion);
    bool eliminarCancion(int idCancion);
    void mostrarInfo();

    // Getters
    int getID() const;
    std::string getTitulo() const;
    int getAnio() const;
    bool getEsDeEstudio() const;
    int getCantidadCanciones() const;
    int getCapacidad() const;
    int* getCanciones() const;
};

#endif //ALBUM_H
