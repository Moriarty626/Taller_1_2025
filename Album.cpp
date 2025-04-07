#include "Album.h"

// Constructor
Album::Album(int id, std::string titulo, int anio, bool es_De_Estudio) {
    this->id = id;
    this->titulo = titulo;
    this->anio = anio;
    this->es_De_Estudio = es_De_Estudio;

    this->capacidad = 2; // Capacidad inicial para 2 canciones
    this->cantidadCanciones = 0;
    this->canciones = (int*)malloc(capacidad * sizeof(int)); // Reservamos memoria
}

// Destructor
Album::~Album() {
    free(canciones); // Liberar memoria al destruir el objeto
}

// Getters
int Album::getID() const {
    return id;
}

std::string Album::getTitulo() const {
    return titulo;
}

int Album::getAnio() const {
    return anio;
}

bool Album::getEsDeEstudio() const {
    return es_De_Estudio;
}

int Album::getCantidadCanciones() const {
    return cantidadCanciones;
}

int Album::getCapacidad() const {
    return capacidad;
}

int* Album::getCanciones() const {
    return canciones;
}

// Redimensionar el arreglo dinámico cuando sea necesario
void Album::redimensionar(int nuevaCapacidad) {
    int* nuevoArreglo = (int*)realloc(canciones, nuevaCapacidad * sizeof(int));
    if (nuevoArreglo != nullptr) {
        canciones = nuevoArreglo;
        capacidad = nuevaCapacidad;
    } else {
        std::cerr << "Error: No se pudo asignar más memoria." << std::endl;
    }
}

// Agregar una canción
void Album::agregarCancion(int idCancion) {
    if (cantidadCanciones == capacidad) {
        redimensionar(capacidad * 2); // Duplicar capacidad si se llena
    }
    canciones[cantidadCanciones++] = idCancion;
}

// Eliminar una canción por ID
bool Album::eliminarCancion(int idCancion) {
    for (int i = 0; i < cantidadCanciones; i++) {
        if (canciones[i] == idCancion) {
            for (int j = i; j < cantidadCanciones - 1; j++) {
                canciones[j] = canciones[j + 1]; // Desplazamos los elementos
            }
            cantidadCanciones--;

            // Reducir tamaño si ocupamos menos de la mitad del arreglo
            if (cantidadCanciones < capacidad / 2 && capacidad > 2) {
                redimensionar(capacidad / 2);
            }

            return true;
        }
    }
    return false; // Canción no encontrada
}

// Mostrar información del álbum
void Album::mostrarInfo() {
    std::cout << "---------------------------" << std::endl;
    std::cout << "Album: " << titulo << std::endl;
    std::cout << "Anio de lanzamiento: " << anio << std::endl;
    std::cout << "Canciones en el album:" << std::endl;

    if (cantidadCanciones == 0) {
        std::cout << "   (No hay canciones en este album)" << std::endl;
    } else {
        for (int i = 0; i < cantidadCanciones; i++) {
            std::cout << "   " << i + 1 << ". ID: " << canciones[i] << std::endl;
        }
    }
    std::cout << "---------------------------" << std::endl;
}
