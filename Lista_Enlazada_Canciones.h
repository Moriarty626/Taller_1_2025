#ifndef LISTA_ENLAZADA_CANCIONES_H
#define LISTA_ENLAZADA_CANCIONES_H
#include "Cancion.h"

class Lista_Enlazada_Canciones {
private:
    Cancion* canciones;  // Puntero a un arreglo dinámico
    int cantidad;
    int capacidad;

    // Método privado para redimensionar el arreglo dinámico
    void redimensionar(int nuevaCapacidad);

public:
    // Constructor y destructor
    Lista_Enlazada_Canciones();
    ~Lista_Enlazada_Canciones();

    // Métodos principales
    void agregarCancion(const Cancion& nuevaCancion);
    bool eliminarCancion(int id);
    Cancion* buscarCancion(int id);
    void ordenarCanciones(bool ascendente);
    void mostrarCanciones() const;
    void mostrarInfoCancion(int id) const;
};

#endif // Lista_Enlazada_Canciones
