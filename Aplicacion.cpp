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

void Aplicacion::cargarCancionesCSV(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
        return;
    }

    std::string linea;
    int numeroLinea = 0;

    while (std::getline(archivo, linea)) {
        numeroLinea++;

        if (linea.empty()) continue;  // Saltar líneas vacías

        std::stringstream ss(linea);
        std::string idStr, albumIdStr, titulo, reproduccionesStr, duracion;

        std::getline(ss, idStr, ';');
        std::getline(ss, albumIdStr, ';');
        std::getline(ss, titulo, ';');
        std::getline(ss, reproduccionesStr, ';');
        std::getline(ss, duracion, ';');

        try {
            int id = std::stoi(idStr);
            int albumId = std::stoi(albumIdStr);
            int reproducciones = std::stoi(reproduccionesStr);

            Cancion nuevaCancion(id, albumId, titulo, reproducciones, duracion);
            listaCanciones.insertarOrdenado(nuevaCancion);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error de conversion en la linea " << numeroLinea
                      << ": " << linea << std::endl;
            continue; // Salta esta línea
        } catch (const std::out_of_range& e) {
            std::cerr << "Numero fuera de rango en la linea " << numeroLinea
                      << ": " << linea << std::endl;
            continue;
        }
    }

    archivo.close();
}

void Aplicacion::cargarDatos() {
    cargarAlbumesCSV("D:/Taller_1_2025/albumes.csv");
    cargarCancionesCSV("D:/Taller_1_2025/canciones.csv");
    cout << "Datos cargados correctamente.\n";
}

void Aplicacion::ejecutar() {
    cargarDatos();
    mostrarMenu();
}

void Aplicacion::mostrarMenu() {
    int opcion;

    do {
        cout << "\n==== MENU PRINCIPAL ====\n";
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
                cout << "Ingrese el titulo del album: ";
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
