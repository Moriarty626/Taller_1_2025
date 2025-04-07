#include "Aplicacion.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "Cancion.h"
#include "Album.h"
#include "Lista_Enlazada_Canciones.h"
#include "Lista_Enlazada_Albums.h"

using std::cout;
using std::cin;
using std::cerr;
using std::string;

// Constructor
Aplicacion::Aplicacion() {}

void Aplicacion::cargarAlbumesCSV(const string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
        return;
    }

    string linea;
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        string idStr, titulo, anioStr, esDeEstudioStr, cancionesStr;

        std::getline(ss, idStr, ';');
        std::getline(ss, titulo, ';');
        std::getline(ss, anioStr, ';');
        std::getline(ss, esDeEstudioStr, ';');
        std::getline(ss, cancionesStr, ';');

        int id = std::stoi(idStr);
        int anio = std::stoi(anioStr);
        bool esDeEstudio = (esDeEstudioStr == "Si");

        Album nuevoAlbum(id, titulo, anio, esDeEstudio);

        cancionesStr.erase(0, 1);     // quitar '{'
        cancionesStr.pop_back();      // quitar '}'

        std::stringstream ssCanciones(cancionesStr);
        string idCancionStr;

        while (std::getline(ssCanciones, idCancionStr, ';')) {
            nuevoAlbum.agregarCancion(std::stoi(idCancionStr));
        }

        listaAlbumes.insertarOrdenado(nuevoAlbum);
    }

    archivo.close();
}

void Aplicacion::cargarCancionesCSV(const string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
        return;
    }

    string linea;
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        string idStr, albumIdStr, titulo, reproduccionesStr, duracion;

        std::getline(ss, idStr, ';');
        std::getline(ss, albumIdStr, ';');
        std::getline(ss, titulo, ';');
        std::getline(ss, reproduccionesStr, ';');
        std::getline(ss, duracion, ';');

        int id = std::stoi(idStr);
        int albumId = std::stoi(albumIdStr);
        int reproducciones = std::stoi(reproduccionesStr);

        Cancion nuevaCancion(id, albumId, titulo, reproducciones, duracion);
        // Aquí podrías insertarla en una lista si tienes una estructura como listaCanciones
    }

    archivo.close();
}

void Aplicacion::cargarDatos() {
    cargarAlbumesCSV("albumes.csv");
    cargarCancionesCSV("canciones.csv");
    cout << "Datos cargados correctamente.\n";
}

void Aplicacion::ejecutar() {
    cargarDatos();
    mostrarMenu();
}

void Aplicacion::mostrarMenu() {
    int opcion;

    do {
        cout << "\n==== MENÚ PRINCIPAL ====\n";
        cout << "1. Mostrar album\n";
        cout << "2. Busqueda avanzada de canciones\n";
        cout << "3. Eliminar album\n";
        cout << "4. Trivia\n";
        cout << "5. Visualizar Albumes (Opcional)\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: " << "\n";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int id;
                cout << "Ingrese el ID del album deseado: ";
                cin >> id;
                Album* album = listaAlbumes.buscarAlbum(id);
                if (album) {
                    album->mostrarInfo();
                } else {
                    cout << "Album no encontrado.\n";
                }
                break;
            }

            case 2: {
                cout << "Seguimos construyendo, vuelva pronto.\n";
                break;
            }

            case 3: {
                string titulo;
                cout << "Ingrese el titulo del álbum: ";
                cin.ignore();
                std::getline(cin, titulo);
                if (listaAlbumes.eliminarAlbum(std::move(titulo))) {
                    cout << "Album eliminado con exito.\n";
                } else {
                    cout << "Album no encontrado.\n";
                }
                break;
            }

            case 4:
            case 5:
                cout << "Seguimos construyendo, vuelva pronto.\n";
                break;

            case 6:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opción no válida.\n";
        }
    } while (opcion != 6);
}
