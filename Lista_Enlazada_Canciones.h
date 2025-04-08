#ifndef LISTA_ENLAZADA_CANCIONES_H
#define LISTA_ENLAZADA_CANCIONES_H

#include "Cancion.h"

class nodoCancion {
public:
    Cancion cancion;
    nodoCancion* siguiente;

    nodoCancion(const Cancion& cancion) : cancion(cancion), siguiente(nullptr) {}
};

class Lista_Enlazada_Canciones {
private:
    nodoCancion* cabeza;

public:
    Lista_Enlazada_Canciones();
    ~Lista_Enlazada_Canciones();
    void agregarCancion(Cancion& nuevaCancion);
    void insertarOrdenado(Cancion& nuevaCancion);
    Cancion* buscarCancion(int id);
    bool eliminarCancion(int id);
    void mostrarTodas();
};

#endif
