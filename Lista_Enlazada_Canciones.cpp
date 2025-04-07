//
// Created by mauri on 02-04-2025.
//

#include "Lista_Enlazada_Canciones.h"
#include "Cancion.h"
#include <iostream>

// Constructor
Lista_Enlazada_Canciones::Lista_Enlazada_Canciones() {
    capacidad = 5;
    cantidad = 0;
    canciones = (Cancion*) malloc(capacidad * sizeof(Cancion));

    if (!canciones) {
        std::cerr << "Error: No se pudo asignar memoria." << std::endl;
        exit(EXIT_FAILURE);
    }
}


// Destructor
Lista_Enlazada_Canciones::~Lista_Enlazada_Canciones() {
    free(canciones);  // Liberar la memoria asignada
}


// Método privado para redimensionar el arreglo dinámico
void Lista_Enlazada_Canciones::redimensionar(int nuevaCapacidad) {
    Cancion* nuevoArreglo = (Cancion*) realloc(canciones, nuevaCapacidad * sizeof(Cancion));

    if (!nuevoArreglo) {
        std::cerr << "Error: No se pudo redimensionar el arreglo." << std::endl;
        exit(EXIT_FAILURE);
    }

    canciones = nuevoArreglo;
    capacidad = nuevaCapacidad;
}

// Agregar una canción al arreglo dinámico
void Lista_Enlazada_Canciones::agregarCancion(const Cancion& nuevaCancion) {
    // Si el arreglo está lleno, duplicamos la capacidad
    if (cantidad == capacidad) {
        redimensionar(capacidad * 2);
    }

    // Copiar la nueva canción en el arreglo
    canciones[cantidad] = nuevaCancion;
    cantidad++;
}

// Eliminar una canción por ID y reducir tamaño si es necesario
bool Lista_Enlazada_Canciones::eliminarCancion(int id) {
    int indice = -1;

    // Buscar la canción en el arreglo
    for (int i = 0; i < cantidad; i++) {
        if (canciones[i].getId() == id) {
            indice = i;
            break;
        }
    }

    if (indice == -1) {
        return false;  // No se encontró la canción
    }

    // Mover los elementos hacia la izquierda para llenar el espacio vacío
    for (int i = indice; i < cantidad - 1; i++) {
        canciones[i] = canciones[i + 1];
    }

    cantidad--;

    // Reducir la capacidad si hay demasiado espacio desperdiciado
    if (cantidad < capacidad / 4 && capacidad > 5) {
        redimensionar(capacidad / 2);
    }

    return true;
}

// Buscar una canción por ID
Cancion* Lista_Enlazada_Canciones::buscarCancion(int id) {
    for (int i = 0; i < cantidad; i++) {
        if (canciones[i].getId() == id) {
            return &canciones[i];
        }
    }
    return nullptr;
}

// Ordenar canciones por número de reproducciones (Bubble Sort)
void Lista_Enlazada_Canciones::ordenarCanciones(bool ascendente) {
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            bool condicion = ascendente ? canciones[j].getReproducciones() > canciones[j + 1].getReproducciones()
                                        : canciones[j].getReproducciones() < canciones[j + 1].getReproducciones();
            if (condicion) {
                Cancion temp = canciones[j];
                canciones[j] = canciones[j + 1];
                canciones[j + 1] = temp;
            }
        }
    }
}

// Mostrar todas las canciones
void Lista_Enlazada_Canciones::mostrarCanciones() const {
    for (int i = 0; i < cantidad; i++) {
        canciones[i].mostrarInfo();
    }
}

// Mostrar la información de una canción específica por ID
void Lista_Enlazada_Canciones::mostrarInfoCancion(int id) const {
    for (int i = 0; i < cantidad; i++) {
        if (canciones[i].getId() == id) {
            canciones[i].mostrarInfo();
            return;
        }
    }
    std::cout << "Cancion con ID " << id << " no encontrada." << std::endl;
}
