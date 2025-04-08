#include "Lista_Enlazada_Canciones.h"
#include <iostream>
using namespace std;

Lista_Enlazada_Canciones::Lista_Enlazada_Canciones() {
    cabeza = nullptr;
}

Lista_Enlazada_Canciones::~Lista_Enlazada_Canciones() {
    nodoCancion* actual = cabeza;
    while (actual != nullptr) {
        nodoCancion* temp = actual;
        actual = actual->siguiente;
        delete temp;
    }
}

void Lista_Enlazada_Canciones::insertarOrdenado(Cancion& nuevaCancion) {
    nodoCancion* nuevoNodo = new nodoCancion(nuevaCancion);

    // Si la lista está vacía o el nuevo nodo va antes de la cabeza
    if (!cabeza ||
        cabeza->cancion.getAlbumId() > nuevaCancion.getAlbumId() ||
        (cabeza->cancion.getAlbumId() == nuevaCancion.getAlbumId() && cabeza->cancion.getId() > nuevaCancion.getId())) {

        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
        return;
        }

    nodoCancion* actual = cabeza;
    while (actual->siguiente &&
          (actual->siguiente->cancion.getAlbumId() < nuevaCancion.getAlbumId() ||
          (actual->siguiente->cancion.getAlbumId() == nuevaCancion.getAlbumId() &&
           actual->siguiente->cancion.getId() < nuevaCancion.getId()))) {

        actual = actual->siguiente;
           }

    nuevoNodo->siguiente = actual->siguiente;
    actual->siguiente = nuevoNodo;
}

void Lista_Enlazada_Canciones::agregarCancion(Cancion& nuevaCancion) {
    nodoCancion* nuevo = new nodoCancion(nuevaCancion);

    if (cabeza == nullptr) {
        cabeza = nuevo;
    } else {
        nodoCancion* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}

Cancion* Lista_Enlazada_Canciones::buscarCancion(int id) {
    nodoCancion* actual = cabeza;
    while (actual != nullptr) {
        if (actual->cancion.getId() == id) {
            return &(actual->cancion);
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

bool Lista_Enlazada_Canciones::eliminarCancion(int id) {
    nodoCancion* actual = cabeza;
    nodoCancion* anterior = nullptr;

    while (actual != nullptr) {
        if (actual->cancion.getId() == id) {
            if (anterior == nullptr) {
                cabeza = actual->siguiente;
            } else {
                anterior->siguiente = actual->siguiente;
            }
            delete actual;
            return true;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    return false;
}

void Lista_Enlazada_Canciones::mostrarTodas() {
    nodoCancion* actual = cabeza;
    while (actual != nullptr) {
        actual->cancion.mostrarInfo();
        actual = actual->siguiente;
    }
}


