#ifndef LISTA_ENLAZADA_ALBUMS_H
#define LISTA_ENLAZADA_ALBUMS_H

#include "Album.h"

class nodoAlbum {
public:
    Album album;
    nodoAlbum* siguiente;
    nodoAlbum(Album& album) : album(album), siguiente(nullptr) {}
};

class lista_Enlazada_Albums {
private:
    nodoAlbum* cabeza;

public:
    lista_Enlazada_Albums();
    ~lista_Enlazada_Albums();

    // metodos principales
    void insertarOrdenado(Album& nuevoAlbum);
    Album* buscarAlbum(int id);
    bool eliminarAlbum(std::string && titulo);
    void mostrarListaAlbums();

};
#endif //LISTA_ENLAZADA_ALBUMS_H
