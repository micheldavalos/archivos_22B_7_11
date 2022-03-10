#ifndef VIDEOJUEGO_HPP
#define VIDEOJUEGO_HPP

#include <iostream>
using namespace std;

#include "personaje.hpp"
#include "arreglo.hpp"

class VideoJuego
{
private:
    Arreglo<Personaje> personajes;

public:
    VideoJuego(size_t tam); 
    VideoJuego(const VideoJuego& v);
    ~VideoJuego();
    VideoJuego& operator=(const VideoJuego& v);

    size_t size() { return personajes.size(); }
    size_t cap() { return personajes.max_size(); }
    size_t cap() const { return personajes.max_size(); }
    bool lleno() { return personajes.full(); }
    bool vacio() { return personajes.empty(); }

    void agregarInicio(const Personaje&);
    void agregarFinal(const Personaje&);
    void insertar(const Personaje&, size_t);

    void mostrar();
    Personaje& inicio() { return personajes.front(); }
    Personaje& ultimo() { return personajes.back(); }
    Personaje& getPersonaje(size_t pos) { return personajes.at(pos); }
    Personaje* buscar(const Personaje& p) { return personajes.find(p); }
    void ordenar(bool ascendente = true) { return personajes.sort(ascendente); }

    void respaldar_tabla();
    void respaldar_csv();
    void recuperar_csv();

    // Sobrecargas
    friend VideoJuego& operator<<(VideoJuego& vj, const Personaje& p)
    {
        vj.agregarFinal(p);

        return vj;
    }
};


#endif