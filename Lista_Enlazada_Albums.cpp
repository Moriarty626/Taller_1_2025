#include "Lista_Enlazada_Albums.h"
#include <iostream>

using  std::cout;

// Constructor
lista_Enlazada_Albums::lista_Enlazada_Albums() {
    cabeza = nullptr;
}

// Destructor
lista_Enlazada_Albums::~lista_Enlazada_Albums() {
    nodoAlbum* actual = cabeza;
    while (actual) {
        nodoAlbum* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
}

// Insertar álbum de forma ordenada por ID
void lista_Enlazada_Albums::insertarOrdenado(Album& nuevoAlbum) {
    nodoAlbum* nuevoNodo = new nodoAlbum(nuevoAlbum);
    if (!cabeza || cabeza->album.getID() > nuevoAlbum.getID()) {
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
        return;
    }
    nodoAlbum* actual = cabeza;
    while (actual->siguiente && actual->siguiente->album.getID() < nuevoAlbum.getID()) {
        actual = actual->siguiente;
    }
    nuevoNodo->siguiente = actual->siguiente;
    actual->siguiente = nuevoNodo;
}

// Buscar álbum por ID
Album* lista_Enlazada_Albums::buscarAlbum(int id) {
    nodoAlbum* actual = cabeza;
    while (actual) {
        if (actual->album.getID() == id) {
            return &actual->album;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

// Eliminar álbum por título
bool lista_Enlazada_Albums::eliminarAlbum(std::string&& titulo) {
    if (!cabeza) return false;

    // Si el álbum a eliminar está en la cabeza
    if (cabeza->album.getTitulo() == titulo) {
        nodoAlbum* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        return true;
    }

    // Buscar el nodo a eliminar
    nodoAlbum* actual = cabeza;
    while (actual->siguiente && actual->siguiente->album.getTitulo() != titulo) {
        actual = actual->siguiente;
    }

    // Si se encontró el nodo
    if (actual->siguiente) {
        nodoAlbum* temp = actual->siguiente;
        actual->siguiente = actual->siguiente->siguiente;
        delete temp;
        return true;
    }

    return false; // No se encontró el álbum
}

// Mostrar todos los álbumes
void lista_Enlazada_Albums::mostrarListaAlbums() {
    nodoAlbum* actual = cabeza;
    while (actual) {
        actual->album.mostrarInfo();
        actual = actual->siguiente;
    }
}
