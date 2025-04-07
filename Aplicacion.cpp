#include "Aplicacion.h"
#include <fstream>
#include <sstream>
#include <iostream>
using std::cout;
using std::cin;

// Constructor
Aplicacion::Aplicacion() {}

void Aplicacion::cargarAlbumesCSV(const std::string &nombreArchivo) {
    std::ifstream archivo(nombreArchivo); // Abro el archivo en modo lectura
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo " << nombreArchivo << std::endl;
        return;
    }
    std::string linea;
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std:: string idStr, titulo, anioStr, esDeEstudioStr, cancionesStr;

        //Leer los valores separados por ;
        std::getline(ss, idStr, ';');
        std::getline(ss, titulo, ';');
        std::getline(ss, anioStr, ';');
        std::getline(ss, esDeEstudioStr, ';');
        std::getline(ss, cancionesStr, ';');

        // Convertir a tipos adecuados
        int id = std::stoi(idStr);
        int anio = std::stoi(anioStr);
        bool esDeEstudio =(esDeEstudioStr == "Si");

        // Crear album
        Album nuevoAlbum(id,titulo,anio,esDeEstudio);

        // Procesar canciones
        cancionesStr.erase(0, 1); // Eliminar '{'
        cancionesStr.pop_back();  // Eliminar '}'
        std::stringstream ssCanciones(cancionesStr);
        std::string idCancionStr;

        while (std::getline(ssCanciones, idCancionStr, ';')) {
                nuevoAlbum.agregarCancion(std::stoi(idCancionStr));
        }

        // insertar el album de la lista enlazada
        listaAlbumes.insertarOrdenado(nuevoAlbum);
    }
    archivo.close();
}

void Aplicacion::cargarCancionesCSV(const std::string &nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archovo " << nombreArchivo << std::endl;
        return;
    }
    std::string linea;
    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string idStr,albumIdStr,titulo,reproduccionesStr,duracion;

        // Leer los valores separados por ;
        std::getline(ss, idStr, ';');
        std::getline(ss, albumIdStr, ';');
        std::getline(ss, titulo, ';');
        std::getline(ss, reproduccionesStr, ';');
        std::getline(ss, duracion, ';');

        // Convertir a tipos adecuados
        int id = std::stoi(idStr);
        int album = std::stoi(albumIdStr);
        int reproducciones = std::stoi(reproduccionesStr);


        // Crear la cancion y agregarla al gestor
        Cancion nuevaCancion(id,album,titulo,reproducciones,duracion);
        gestorCanciones.agregarCancion(nuevaCancion);
    }
    archivo.close();
}


void Aplicacion::cargarDatos() {
    cargarAlbumesCSV("albumes.csv");
    cargarCancionesCSV("canciones.csv");
    std::cout << "Datos cargados correctamente.\n";
}

void Aplicacion::ejecutar() {
    cargarDatos();
    mostrarMenu();
}


void Aplicacion::mostrarMenu() {
    int opcion;
    do {
        cout << "\n==== MENÚ PRINCIPAL ====\n";
        cout << "1. Mostrar álbum\n";
        cout << "2. Búsqueda avanzada de canciones\n";
        cout << "3. Eliminar álbum\n";
        cout << "4. Trivia\n";
        cout << "5. Visualizar Álbumes (Opcional)\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                int id;
                cout << "Ingrese el ID del album deseado: \n";
                cin >> id;
                Album* album = listaAlbumes.buscarAlbum(id);
                    if (album) {
                        album ->mostrarInfo();
                    }else {
                        cout << "Album no encontrado :( \n";
                    }
                    break;
            case 2:
                cout << "Seguimos construyendo, vuelva pronto: \n";
                break;
            case 3:
                std::string titulo;
                cout << "Ingrese el titulo del album: \n";
                cin.ignore();
                std::getline(cin, titulo);
                    if (listaAlbumes.eliminarAlbum(album->getTitulo())) {
                        cout << "Album eliminado con exito :) \n";
                    }else {
                        cout << "Album no encontrado :( \n";
                    }
                break;
            case 4:
                cout << "Seguimos construyendo, vuelva pronto: \n";
                break;
            case 5:
                cout << "Seguimos construyendo, vuelva pronto: \n";
                break;
            case 6:
                cout << "Saliendo... \n";
                break;
            default:
                cout << "Opcion no valida! \n";
        }
    }while (opcion != 6);

}
