cmake_minimum_required(VERSION 3.30)
project(Taller_1_2025)

set(CMAKE_CXX_STANDARD 20)

add_executable(Taller_1_2025 main.cpp
        Aplicacion.h
        Aplicacion.cpp
        Album.h
        Album.cpp
        Cancion.h
        Cancion.cpp
        Lista_Enlazada_Albums.h
        Lista_Enlazada_Albums.cpp
        Lista_Enlazada_Canciones.h
        Lista_Enlazada_Canciones.cpp)
