#ifndef APLICACION_H
#define APLICACION_H
using namespace std;
class Aplicacion {
private:
    lista_Enlazada_Albums listaAlbumes;  // Estructura para almacenar álbumes
    Lista_Enlazada_Canciones listaCanciones;  // Estructura para almacenar canciones

    void cargarAlbumesCSV(const std::string &nombreArchivo);
    void cargarCancionesCSV(const std::string &nombreArchivo);
    void mostrarMenu();  // Menú interactivo para el usuario

public:
    // Constructor
    Aplicacion();

    // Método para cargar datos desde archivos CSV
    void cargarDatos();

    // Método principal para ejecutar la aplicación
    void ejecutar();
};

#endif // APLICACION_H
